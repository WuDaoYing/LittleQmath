#ifndef __LQ_SQRT_BITWISE_ROOT_H__
#define __LQ_SQRT_BITWISE_ROOT_H__

#include "lq_error.h"
#include "lq_mode.h"
#include "lq_type.h"
/**@file      lq_sqrt_bitwise_root.h
* @brief      LittleQmath的无符号整数开方内核
* @details    提供牛顿迭代与无除法逐位试探两个内核:
*             牛顿迭代:CLZ估种子、首步移位代替除法、误差小于Error_Range提前结束,有硬件除法时更快;
*             逐位试探:恢复余数法,只用移位、加法、比较,恒返回精确向下取整,适合Cortex-M0/M0+/M1;
*             由lq_mode.h的LQ_SQRT_NODIV_ENABLE选择,ARMv6-M自动启用逐位。
* @author     尹冠华
* @date        2026-11-14
* @version    V2.1
* @copyright    Copyright (c ) 2018-2024  黑龙江大学A8楼514
**********************************************************************************
* @attention
* 硬件平台:兼容任何只要使用C语言编程的处理器,逐位内核适合无硬件除法的Cortex-M0/M0+/M1 
* @par 修改日志:
* <table>
* <tr><th>Date        <th>Version  <th>Author    <th>Description
* <tr><td>2026/11/14  <td>2.0      <td>尹冠华    <td>新增无除法逐位开方
* <tr><td>2026/11/14  <td>2.1      <td>尹冠华    <td>牛顿迭代内核由lq_type.h迁入
* </table>
*
**********************************************************************************
*/

#if LQ_SQRT_BITWISE_ROOT_LOADING_MODE == 1
#if !defined(LQ_SQRT_NODIV_ENABLE) || (LQ_SQRT_NODIV_ENABLE == 0)
/* 无除法构建(M0/M0+)整段不编译,避免引入 64 位除法 */
/**@brief 64位无符号整数开方
* @details 用CLZ定位最高位估种子;首步牛顿迭代的除数恰为2的幂,改用移位代替除法;
*          相邻两次估计之差小于Error_Range时提前结束迭代,Error_Range为1时即精确开方;
*          被开方数小于2^32时全程使用32位除法,避免64位软件除法。
* @param[in] LQ_UI_64BIT value        被开方数
* @param[in] LQ_UI_64BIT Error_Range  迭代误差范围,不小于1;1表示精确到最低位
* @return    sqrt(value)的估计值,与精确值之差小于Error_Range
*/
LQ_INLINE LQ_UI_64BIT LQ_SQRT_U64_NEWTON(LQ_UI_64BIT value, LQ_UI_64BIT Error_Range)
{
    LQ_UI_64BIT root;
    LQ_UI_64BIT next;
    LQ_UI_64BIT v;
    LQ_UI_8BIT exponent = 0;
    LQ_UI_8BIT shift;
    if (value == 0)
    {
        return 0;
    }
    v = value;
    if (v >> 32)
    {
        v >>= 32;
        exponent += 32;
    }
    if (v >> 16)
    {
        v >>= 16;
        exponent += 16;
    }
    if (v >> 8)
    {
        v >>= 8;
        exponent += 8;
    }
    if (v >> 4)
    {
        v >>= 4;
        exponent += 4;
    }
    if (v >> 2)
    {
        v >>= 2;
        exponent += 2;
    }
    if (v >> 1)
    {
        exponent += 1;
    }
    shift = (LQ_UI_8BIT)((exponent + 2) >> 1);
    if (value < (((LQ_UI_64BIT)1) << 32))
    {
        LQ_UI_32BIT root32 = ((LQ_UI_32BIT)1) << shift;
        LQ_UI_32BIT next32;
        LQ_UI_32BIT v32 = (LQ_UI_32BIT)value;
        root32 = (root32 + (v32 >> shift)) >> 1;
        for (;;)
        {
            next32 = (root32 + (v32 / root32)) >> 1;
            if (next32 >= root32)
            {
                return (LQ_UI_64BIT)root32;
            }
            if ((root32 - next32) < ((LQ_UI_32BIT)Error_Range))
            {
                return (LQ_UI_64BIT)next32;
            }
            root32 = next32;
        }
    }
    root = ((LQ_UI_64BIT)1) << shift;
    root = (root + (value >> shift)) >> 1;
    for (;;)
    {
        next = (root + (value / root)) >> 1;
        if (next >= root)
        {
            break;
        }
        if ((root - next) < Error_Range)
        {
            root = next;
            break;
        }
        root = next;
    }
    return root;
}

/**@brief 32位无符号整数开方
* @details 用CLZ定位最高位估种子;首步牛顿迭代的除数恰为2的幂,改用移位代替除法;
*          相邻两次估计之差小于Error_Range时提前结束迭代,Error_Range为1时即精确开方;
*          被开方数不超过32位,全程使用32位除法,避免64位软件除法。
* @param[in] LQ_UI_32BIT value        被开方数
* @param[in] LQ_UI_32BIT Error_Range  迭代误差范围,不小于1;1表示精确到最低位
* @return    sqrt(value)的估计值,与精确值之差小于Error_Range
*/
LQ_INLINE LQ_UI_32BIT LQ_SQRT_U32_NEWTON(LQ_UI_32BIT value, LQ_UI_32BIT Error_Range)
{
    LQ_UI_32BIT root;
    LQ_UI_32BIT next;
    LQ_UI_32BIT v;
    LQ_UI_8BIT exponent = 0;
    LQ_UI_8BIT shift;
    if (value == 0)
    {
        return 0;
    }
    v = value;
    if (v >> 16)
    {
        v >>= 16;
        exponent += 16;
    }
    if (v >> 8)
    {
        v >>= 8;
        exponent += 8;
    }
    if (v >> 4)
    {
        v >>= 4;
        exponent += 4;
    }
    if (v >> 2)
    {
        v >>= 2;
        exponent += 2;
    }
    if (v >> 1)
    {
        exponent += 1;
    }
    shift = (LQ_UI_8BIT)((exponent + 2) >> 1);
    root = ((LQ_UI_32BIT)1) << shift;
    root = (root + (value >> shift)) >> 1;
    for (;;)
    {
        next = (root + (value / root)) >> 1;
        if (next >= root)
        {
            break;
        }
        if ((root - next) < Error_Range)
        {
            root = next;
            break;
        }
        root = next;
    }
    return root;
}
#endif
/**@brief 64位无符号整数开方(无除法逐位试探法)
* @details 从最高4次幂起逐位试探,够减则置位并相减,仅移位、加法、比较;不做提前结束,
*          始终返回精确向下取整结果,任意Error_Range不小于1均满足误差契约。
* @param[in] LQ_UI_64BIT value        被开方数
* @param[in] LQ_UI_64BIT Error_Range  误差范围,不小于1;逐位法结果精确,该参数只作契约下界
* @return    sqrt(value)的精确向下取整值
* @par       计算sqrt(value)的值
* @code
*    LQ_SQRT_U64_BITWISE(value, Error_Range);
* @endcode
* @attention   用户权限:用户可调用
*              用户更改权限:用户无需更改
*/
LQ_INLINE LQ_UI_64BIT LQ_SQRT_U64_BITWISE(LQ_UI_64BIT value, LQ_UI_64BIT Error_Range)
{
    (void)Error_Range;
    LQ_UI_64BIT root = 0;
    LQ_UI_64BIT bit = ((LQ_UI_64BIT)1) << 62;
    while (bit > value)
    {
        bit >>= 2;
    }
    while (bit != 0)
    {
        if (value >= (root + bit))
        {
            value -= (root + bit);
            root = (root >> 1) + bit;
        }
        else
        {
            root >>= 1;
        }
        bit >>= 2;
    }
    return root;
}
/**@brief 32位无符号整数开方(无除法逐位试探法)
* @details 从最高4次幂起逐位试探,够减则置位并相减,仅移位、加法、比较;不做提前结束,
*          始终返回精确向下取整结果,任意Error_Range不小于1均满足误差契约。
* @param[in] LQ_UI_32BIT value        被开方数
* @param[in] LQ_UI_32BIT Error_Range  误差范围,不小于1;逐位法结果精确,该参数只作契约下界
* @return    sqrt(value)的精确向下取整值
* @par       计算sqrt(value)的值
* @code
*    LQ_SQRT_U32_BITWISE(value, Error_Range);
* @endcode
* @attention   用户权限:用户可调用
*              用户更改权限:用户无需更改
*/
LQ_INLINE LQ_UI_32BIT LQ_SQRT_U32_BITWISE(LQ_UI_32BIT value, LQ_UI_32BIT Error_Range)
{
    (void)Error_Range;
    LQ_UI_32BIT root = 0;
    LQ_UI_32BIT bit = ((LQ_UI_32BIT)1) << 30;
    while (bit > value)
    {
        bit >>= 2;
    }
    while (bit != 0)
    {
        if (value >= (root + bit))
        {
            value -= (root + bit);
            root = (root >> 1) + bit;
        }
        else
        {
            root >>= 1;
        }
        bit >>= 2;
    }
    return root;
}
#elif LQ_SQRT_BITWISE_ROOT_LOADING_MODE == 0
#if !defined(LQ_SQRT_NODIV_ENABLE) || (LQ_SQRT_NODIV_ENABLE == 0)
/* 无除法构建(M0/M0+)整段不编译,避免引入 64 位除法 */
LQ_UI_64BIT LQ_SQRT_U64_NEWTON(LQ_UI_64BIT value, LQ_UI_64BIT Error_Range);
LQ_UI_32BIT LQ_SQRT_U32_NEWTON(LQ_UI_32BIT value, LQ_UI_32BIT Error_Range);
#endif
LQ_UI_64BIT LQ_SQRT_U64_BITWISE(LQ_UI_64BIT value, LQ_UI_64BIT Error_Range);
LQ_UI_32BIT LQ_SQRT_U32_BITWISE(LQ_UI_32BIT value, LQ_UI_32BIT Error_Range);
#endif

//!<开方实现选择:LQ_SQRT_NODIV_ENABLE为1时使用无除法逐位法,否则使用牛顿迭代
#if defined(LQ_SQRT_NODIV_ENABLE) && (LQ_SQRT_NODIV_ENABLE == 1)
#define LQ_SQRT_U32_ROOT(value, Error_Range)  LQ_SQRT_U32_BITWISE((value), (Error_Range))
#define LQ_SQRT_U64_ROOT(value, Error_Range)  LQ_SQRT_U64_BITWISE((value), (Error_Range))
#else
#define LQ_SQRT_U32_ROOT(value, Error_Range)  LQ_SQRT_U32_NEWTON((value), (Error_Range))
#define LQ_SQRT_U64_ROOT(value, Error_Range)  LQ_SQRT_U64_NEWTON((value), (Error_Range))
#endif

#endif
