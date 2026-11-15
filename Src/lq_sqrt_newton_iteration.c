#include "lq_sqrt_newton_iteration.h"
#include "lq_error.h"
#include "lq_mode.h"
#include "lq_type.h"
/**@file      lq_ti_q_format_to_float.c
* @brief      LittleQmath的ti算法的q格式转浮点格式
* @details    采用指数偏移方式将Q格式转换为浮点
* @author     尹冠华
* @date        2024-6-27
* @version     V2.0
* @copyright    Copyright (c ) 2018-2024  黑龙江大学A8楼514
**********************************************************************************
* @attention
* 硬件平台:兼容任何只要使用C语言编程的处理器 \n
* @par 修改日志:
* <table>
* <tr><th>Date        <th>Version  <th>Author    <th>Description
* <tr><td>2024/03/28  <td>1.0      <td>尹冠华    <td>创建初始版本
* <tr><td>2024/06/27  <td>2.0      <td>尹冠华    <td>重新架构
* </table>
*
**********************************************************************************
*/

#if LQ_SQRT_NEWTON_ITERATION_LOADING_MODE==0
/**@brief LQ_INT8_Q7 开根 牛顿迭代法
* @details 采用牛顿迭代法进行开跟，相邻两次估计之差小于Error_Range时提前结束
* @param[in] LQ_INT8_Q7     A              输入Q格式数
* @param[in] LQ_INT8_Q7     Error_Range    迭代误差范围
* @param[in] LQ_ERROR*      Lq_Error         错误变量
* @return    sqrtA的值
* @exception NSExceptio: LQ_INT8_Q7_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE 错误:输入数值是负数\n
*                        LQ_INT8_Q7_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW  错误:精度范围太低，无差异性
* @par       计算sqrt(A)的值
* @code
*    LQ_INT8_Q7_SQRT_NEWTON_ITERATION(A, Error_Range, &lq_error);
* @endcode
* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
*/
LQ_INT8_Q LQ_INT8_Q7_SQRT_NEWTON_ITERATION(LQ_INT8_Q7 A, LQ_INT8_Q7 Error_Range, LQ_ERROR* Lq_Error)
{
    LQ_UI_32BIT LQ_Sqrt_Value;
    if (A < 0)
    {
        (*Lq_Error) = LQ_INT8_Q7_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE;
        return 0;
    }
    if (Error_Range <= 0)
    {
        (*Lq_Error) = LQ_INT8_Q7_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW;
        return 0;
    }
    LQ_Sqrt_Value = LQ_SQRT_U32_ROOT(((LQ_UI_32BIT)A) << 7, (LQ_UI_32BIT)Error_Range);
    return (LQ_INT8_Q)LQ_Sqrt_Value;
}
/**@brief LQ_INT8_Q6 开根 牛顿迭代法
* @details 采用牛顿迭代法进行开跟，相邻两次估计之差小于Error_Range时提前结束
* @param[in] LQ_INT8_Q6     A              输入Q格式数
* @param[in] LQ_INT8_Q6     Error_Range    迭代误差范围
* @param[in] LQ_ERROR*      Lq_Error         错误变量
* @return    sqrtA的值
* @exception NSExceptio: LQ_INT8_Q6_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE 错误:输入数值是负数\n
*                        LQ_INT8_Q6_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW  错误:精度范围太低，无差异性
* @par       计算sqrt(A)的值
* @code
*    LQ_INT8_Q6_SQRT_NEWTON_ITERATION(A, Error_Range, &lq_error);
* @endcode
* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
*/
LQ_INT8_Q LQ_INT8_Q6_SQRT_NEWTON_ITERATION(LQ_INT8_Q6 A, LQ_INT8_Q6 Error_Range, LQ_ERROR* Lq_Error)
{
    LQ_UI_32BIT LQ_Sqrt_Value;
    if (A < 0)
    {
        (*Lq_Error) = LQ_INT8_Q6_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE;
        return 0;
    }
    if (Error_Range <= 0)
    {
        (*Lq_Error) = LQ_INT8_Q6_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW;
        return 0;
    }
    LQ_Sqrt_Value = LQ_SQRT_U32_ROOT(((LQ_UI_32BIT)A) << 6, (LQ_UI_32BIT)Error_Range);
    return (LQ_INT8_Q)LQ_Sqrt_Value;
}
/**@brief LQ_INT8_Q5 开根 牛顿迭代法
* @details 采用牛顿迭代法进行开跟，相邻两次估计之差小于Error_Range时提前结束
* @param[in] LQ_INT8_Q5     A              输入Q格式数
* @param[in] LQ_INT8_Q5     Error_Range    迭代误差范围
* @param[in] LQ_ERROR*      Lq_Error         错误变量
* @return    sqrtA的值
* @exception NSExceptio: LQ_INT8_Q5_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE 错误:输入数值是负数\n
*                        LQ_INT8_Q5_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW  错误:精度范围太低，无差异性
* @par       计算sqrt(A)的值
* @code
*    LQ_INT8_Q5_SQRT_NEWTON_ITERATION(A, Error_Range, &lq_error);
* @endcode
* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
*/
LQ_INT8_Q LQ_INT8_Q5_SQRT_NEWTON_ITERATION(LQ_INT8_Q5 A, LQ_INT8_Q5 Error_Range, LQ_ERROR* Lq_Error)
{
    LQ_UI_32BIT LQ_Sqrt_Value;
    if (A < 0)
    {
        (*Lq_Error) = LQ_INT8_Q5_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE;
        return 0;
    }
    if (Error_Range <= 0)
    {
        (*Lq_Error) = LQ_INT8_Q5_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW;
        return 0;
    }
    LQ_Sqrt_Value = LQ_SQRT_U32_ROOT(((LQ_UI_32BIT)A) << 5, (LQ_UI_32BIT)Error_Range);
    return (LQ_INT8_Q)LQ_Sqrt_Value;
}
/**@brief LQ_INT8_Q4 开根 牛顿迭代法
* @details 采用牛顿迭代法进行开跟，相邻两次估计之差小于Error_Range时提前结束
* @param[in] LQ_INT8_Q4     A              输入Q格式数
* @param[in] LQ_INT8_Q4     Error_Range    迭代误差范围
* @param[in] LQ_ERROR*      Lq_Error         错误变量
* @return    sqrtA的值
* @exception NSExceptio: LQ_INT8_Q4_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE 错误:输入数值是负数\n
*                        LQ_INT8_Q4_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW  错误:精度范围太低，无差异性
* @par       计算sqrt(A)的值
* @code
*    LQ_INT8_Q4_SQRT_NEWTON_ITERATION(A, Error_Range, &lq_error);
* @endcode
* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
*/
LQ_INT8_Q LQ_INT8_Q4_SQRT_NEWTON_ITERATION(LQ_INT8_Q4 A, LQ_INT8_Q4 Error_Range, LQ_ERROR* Lq_Error)
{
    LQ_UI_32BIT LQ_Sqrt_Value;
    if (A < 0)
    {
        (*Lq_Error) = LQ_INT8_Q4_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE;
        return 0;
    }
    if (Error_Range <= 0)
    {
        (*Lq_Error) = LQ_INT8_Q4_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW;
        return 0;
    }
    LQ_Sqrt_Value = LQ_SQRT_U32_ROOT(((LQ_UI_32BIT)A) << 4, (LQ_UI_32BIT)Error_Range);
    return (LQ_INT8_Q)LQ_Sqrt_Value;
}
/**@brief LQ_INT8_Q3 开根 牛顿迭代法
* @details 采用牛顿迭代法进行开跟，相邻两次估计之差小于Error_Range时提前结束
* @param[in] LQ_INT8_Q3     A              输入Q格式数
* @param[in] LQ_INT8_Q3     Error_Range    迭代误差范围
* @param[in] LQ_ERROR*      Lq_Error         错误变量
* @return    sqrtA的值
* @exception NSExceptio: LQ_INT8_Q3_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE 错误:输入数值是负数\n
*                        LQ_INT8_Q3_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW  错误:精度范围太低，无差异性
* @par       计算sqrt(A)的值
* @code
*    LQ_INT8_Q3_SQRT_NEWTON_ITERATION(A, Error_Range, &lq_error);
* @endcode
* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
*/
LQ_INT8_Q LQ_INT8_Q3_SQRT_NEWTON_ITERATION(LQ_INT8_Q3 A, LQ_INT8_Q3 Error_Range, LQ_ERROR* Lq_Error)
{
    LQ_UI_32BIT LQ_Sqrt_Value;
    if (A < 0)
    {
        (*Lq_Error) = LQ_INT8_Q3_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE;
        return 0;
    }
    if (Error_Range <= 0)
    {
        (*Lq_Error) = LQ_INT8_Q3_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW;
        return 0;
    }
    LQ_Sqrt_Value = LQ_SQRT_U32_ROOT(((LQ_UI_32BIT)A) << 3, (LQ_UI_32BIT)Error_Range);
    return (LQ_INT8_Q)LQ_Sqrt_Value;
}
/**@brief LQ_INT8_Q2 开根 牛顿迭代法
* @details 采用牛顿迭代法进行开跟，相邻两次估计之差小于Error_Range时提前结束
* @param[in] LQ_INT8_Q2     A              输入Q格式数
* @param[in] LQ_INT8_Q2     Error_Range    迭代误差范围
* @param[in] LQ_ERROR*      Lq_Error         错误变量
* @return    sqrtA的值
* @exception NSExceptio: LQ_INT8_Q2_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE 错误:输入数值是负数\n
*                        LQ_INT8_Q2_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW  错误:精度范围太低，无差异性
* @par       计算sqrt(A)的值
* @code
*    LQ_INT8_Q2_SQRT_NEWTON_ITERATION(A, Error_Range, &lq_error);
* @endcode
* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
*/
LQ_INT8_Q LQ_INT8_Q2_SQRT_NEWTON_ITERATION(LQ_INT8_Q2 A, LQ_INT8_Q2 Error_Range, LQ_ERROR* Lq_Error)
{
    LQ_UI_32BIT LQ_Sqrt_Value;
    if (A < 0)
    {
        (*Lq_Error) = LQ_INT8_Q2_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE;
        return 0;
    }
    if (Error_Range <= 0)
    {
        (*Lq_Error) = LQ_INT8_Q2_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW;
        return 0;
    }
    LQ_Sqrt_Value = LQ_SQRT_U32_ROOT(((LQ_UI_32BIT)A) << 2, (LQ_UI_32BIT)Error_Range);
    return (LQ_INT8_Q)LQ_Sqrt_Value;
}
/**@brief LQ_INT8_Q1 开根 牛顿迭代法
* @details 采用牛顿迭代法进行开跟，相邻两次估计之差小于Error_Range时提前结束
* @param[in] LQ_INT8_Q1     A              输入Q格式数
* @param[in] LQ_INT8_Q1     Error_Range    迭代误差范围
* @param[in] LQ_ERROR*      Lq_Error         错误变量
* @return    sqrtA的值
* @exception NSExceptio: LQ_INT8_Q1_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE 错误:输入数值是负数\n
*                        LQ_INT8_Q1_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW  错误:精度范围太低，无差异性
* @par       计算sqrt(A)的值
* @code
*    LQ_INT8_Q1_SQRT_NEWTON_ITERATION(A, Error_Range, &lq_error);
* @endcode
* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
*/
LQ_INT8_Q LQ_INT8_Q1_SQRT_NEWTON_ITERATION(LQ_INT8_Q1 A, LQ_INT8_Q1 Error_Range, LQ_ERROR* Lq_Error)
{
    LQ_UI_32BIT LQ_Sqrt_Value;
    if (A < 0)
    {
        (*Lq_Error) = LQ_INT8_Q1_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE;
        return 0;
    }
    if (Error_Range <= 0)
    {
        (*Lq_Error) = LQ_INT8_Q1_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW;
        return 0;
    }
    LQ_Sqrt_Value = LQ_SQRT_U32_ROOT(((LQ_UI_32BIT)A) << 1, (LQ_UI_32BIT)Error_Range);
    return (LQ_INT8_Q)LQ_Sqrt_Value;
}
/**@brief LQ_UINT8_UQ8 开根 牛顿迭代法
* @details 采用牛顿迭代法进行开跟，相邻两次估计之差小于Error_Range时提前结束
* @param[in] LQ_UINT8_UQ8     A              输入UQ格式数
* @param[in] LQ_UINT8_UQ8     Error_Range    迭代误差范围
* @param[in] LQ_ERROR*      Lq_Error         错误变量
* @return    sqrtA的值
* @exception NSExceptio: LQ_UINT8_UQ8_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE 错误:输入数值是负数\n
*                        LQ_UINT8_UQ8_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW  错误:精度范围太低，无差异性
* @par       计算sqrt(A)的值
* @code
*    LQ_UINT8_UQ8_SQRT_NEWTON_ITERATION(A, Error_Range, &lq_error);
* @endcode
* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
*/
LQ_UINT8_UQ LQ_UINT8_UQ8_SQRT_NEWTON_ITERATION(LQ_UINT8_UQ8 A, LQ_UINT8_UQ8 Error_Range, LQ_ERROR* Lq_Error)
{
    LQ_UI_32BIT LQ_Sqrt_Value;
    if (Error_Range == 0)
    {
        (*Lq_Error) = LQ_UINT8_UQ8_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW;
        return 0;
    }
    LQ_Sqrt_Value = LQ_SQRT_U32_ROOT(((LQ_UI_32BIT)A) << 8, (LQ_UI_32BIT)Error_Range);
    return (LQ_UINT8_UQ)LQ_Sqrt_Value;
}
/**@brief LQ_UINT8_UQ7 开根 牛顿迭代法
* @details 采用牛顿迭代法进行开跟，相邻两次估计之差小于Error_Range时提前结束
* @param[in] LQ_UINT8_UQ7     A              输入UQ格式数
* @param[in] LQ_UINT8_UQ7     Error_Range    迭代误差范围
* @param[in] LQ_ERROR*      Lq_Error         错误变量
* @return    sqrtA的值
* @exception NSExceptio: LQ_UINT8_UQ7_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE 错误:输入数值是负数\n
*                        LQ_UINT8_UQ7_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW  错误:精度范围太低，无差异性
* @par       计算sqrt(A)的值
* @code
*    LQ_UINT8_UQ7_SQRT_NEWTON_ITERATION(A, Error_Range, &lq_error);
* @endcode
* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
*/
LQ_UINT8_UQ LQ_UINT8_UQ7_SQRT_NEWTON_ITERATION(LQ_UINT8_UQ7 A, LQ_UINT8_UQ7 Error_Range, LQ_ERROR* Lq_Error)
{
    LQ_UI_32BIT LQ_Sqrt_Value;
    if (Error_Range == 0)
    {
        (*Lq_Error) = LQ_UINT8_UQ7_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW;
        return 0;
    }
    LQ_Sqrt_Value = LQ_SQRT_U32_ROOT(((LQ_UI_32BIT)A) << 7, (LQ_UI_32BIT)Error_Range);
    return (LQ_UINT8_UQ)LQ_Sqrt_Value;
}
/**@brief LQ_UINT8_UQ6 开根 牛顿迭代法
* @details 采用牛顿迭代法进行开跟，相邻两次估计之差小于Error_Range时提前结束
* @param[in] LQ_UINT8_UQ6     A              输入UQ格式数
* @param[in] LQ_UINT8_UQ6     Error_Range    迭代误差范围
* @param[in] LQ_ERROR*      Lq_Error         错误变量
* @return    sqrtA的值
* @exception NSExceptio: LQ_UINT8_UQ6_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE 错误:输入数值是负数\n
*                        LQ_UINT8_UQ6_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW  错误:精度范围太低，无差异性
* @par       计算sqrt(A)的值
* @code
*    LQ_UINT8_UQ6_SQRT_NEWTON_ITERATION(A, Error_Range, &lq_error);
* @endcode
* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
*/
LQ_UINT8_UQ LQ_UINT8_UQ6_SQRT_NEWTON_ITERATION(LQ_UINT8_UQ6 A, LQ_UINT8_UQ6 Error_Range, LQ_ERROR* Lq_Error)
{
    LQ_UI_32BIT LQ_Sqrt_Value;
    if (Error_Range == 0)
    {
        (*Lq_Error) = LQ_UINT8_UQ6_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW;
        return 0;
    }
    LQ_Sqrt_Value = LQ_SQRT_U32_ROOT(((LQ_UI_32BIT)A) << 6, (LQ_UI_32BIT)Error_Range);
    return (LQ_UINT8_UQ)LQ_Sqrt_Value;
}
/**@brief LQ_UINT8_UQ5 开根 牛顿迭代法
* @details 采用牛顿迭代法进行开跟，相邻两次估计之差小于Error_Range时提前结束
* @param[in] LQ_UINT8_UQ5     A              输入UQ格式数
* @param[in] LQ_UINT8_UQ5     Error_Range    迭代误差范围
* @param[in] LQ_ERROR*      Lq_Error         错误变量
* @return    sqrtA的值
* @exception NSExceptio: LQ_UINT8_UQ5_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE 错误:输入数值是负数\n
*                        LQ_UINT8_UQ5_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW  错误:精度范围太低，无差异性
* @par       计算sqrt(A)的值
* @code
*    LQ_UINT8_UQ5_SQRT_NEWTON_ITERATION(A, Error_Range, &lq_error);
* @endcode
* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
*/
LQ_UINT8_UQ LQ_UINT8_UQ5_SQRT_NEWTON_ITERATION(LQ_UINT8_UQ5 A, LQ_UINT8_UQ5 Error_Range, LQ_ERROR* Lq_Error)
{
    LQ_UI_32BIT LQ_Sqrt_Value;
    if (Error_Range == 0)
    {
        (*Lq_Error) = LQ_UINT8_UQ5_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW;
        return 0;
    }
    LQ_Sqrt_Value = LQ_SQRT_U32_ROOT(((LQ_UI_32BIT)A) << 5, (LQ_UI_32BIT)Error_Range);
    return (LQ_UINT8_UQ)LQ_Sqrt_Value;
}
/**@brief LQ_UINT8_UQ4 开根 牛顿迭代法
* @details 采用牛顿迭代法进行开跟，相邻两次估计之差小于Error_Range时提前结束
* @param[in] LQ_UINT8_UQ4     A              输入UQ格式数
* @param[in] LQ_UINT8_UQ4     Error_Range    迭代误差范围
* @param[in] LQ_ERROR*      Lq_Error         错误变量
* @return    sqrtA的值
* @exception NSExceptio: LQ_UINT8_UQ4_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE 错误:输入数值是负数\n
*                        LQ_UINT8_UQ4_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW  错误:精度范围太低，无差异性
* @par       计算sqrt(A)的值
* @code
*    LQ_UINT8_UQ4_SQRT_NEWTON_ITERATION(A, Error_Range, &lq_error);
* @endcode
* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
*/
LQ_UINT8_UQ LQ_UINT8_UQ4_SQRT_NEWTON_ITERATION(LQ_UINT8_UQ4 A, LQ_UINT8_UQ4 Error_Range, LQ_ERROR* Lq_Error)
{
    LQ_UI_32BIT LQ_Sqrt_Value;
    if (Error_Range == 0)
    {
        (*Lq_Error) = LQ_UINT8_UQ4_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW;
        return 0;
    }
    LQ_Sqrt_Value = LQ_SQRT_U32_ROOT(((LQ_UI_32BIT)A) << 4, (LQ_UI_32BIT)Error_Range);
    return (LQ_UINT8_UQ)LQ_Sqrt_Value;
}
/**@brief LQ_UINT8_UQ3 开根 牛顿迭代法
* @details 采用牛顿迭代法进行开跟，相邻两次估计之差小于Error_Range时提前结束
* @param[in] LQ_UINT8_UQ3     A              输入UQ格式数
* @param[in] LQ_UINT8_UQ3     Error_Range    迭代误差范围
* @param[in] LQ_ERROR*      Lq_Error         错误变量
* @return    sqrtA的值
* @exception NSExceptio: LQ_UINT8_UQ3_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE 错误:输入数值是负数\n
*                        LQ_UINT8_UQ3_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW  错误:精度范围太低，无差异性
* @par       计算sqrt(A)的值
* @code
*    LQ_UINT8_UQ3_SQRT_NEWTON_ITERATION(A, Error_Range, &lq_error);
* @endcode
* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
*/
LQ_UINT8_UQ LQ_UINT8_UQ3_SQRT_NEWTON_ITERATION(LQ_UINT8_UQ3 A, LQ_UINT8_UQ3 Error_Range, LQ_ERROR* Lq_Error)
{
    LQ_UI_32BIT LQ_Sqrt_Value;
    if (Error_Range == 0)
    {
        (*Lq_Error) = LQ_UINT8_UQ3_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW;
        return 0;
    }
    LQ_Sqrt_Value = LQ_SQRT_U32_ROOT(((LQ_UI_32BIT)A) << 3, (LQ_UI_32BIT)Error_Range);
    return (LQ_UINT8_UQ)LQ_Sqrt_Value;
}
/**@brief LQ_UINT8_UQ2 开根 牛顿迭代法
* @details 采用牛顿迭代法进行开跟，相邻两次估计之差小于Error_Range时提前结束
* @param[in] LQ_UINT8_UQ2     A              输入UQ格式数
* @param[in] LQ_UINT8_UQ2     Error_Range    迭代误差范围
* @param[in] LQ_ERROR*      Lq_Error         错误变量
* @return    sqrtA的值
* @exception NSExceptio: LQ_UINT8_UQ2_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE 错误:输入数值是负数\n
*                        LQ_UINT8_UQ2_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW  错误:精度范围太低，无差异性
* @par       计算sqrt(A)的值
* @code
*    LQ_UINT8_UQ2_SQRT_NEWTON_ITERATION(A, Error_Range, &lq_error);
* @endcode
* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
*/
LQ_UINT8_UQ LQ_UINT8_UQ2_SQRT_NEWTON_ITERATION(LQ_UINT8_UQ2 A, LQ_UINT8_UQ2 Error_Range, LQ_ERROR* Lq_Error)
{
    LQ_UI_32BIT LQ_Sqrt_Value;
    if (Error_Range == 0)
    {
        (*Lq_Error) = LQ_UINT8_UQ2_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW;
        return 0;
    }
    LQ_Sqrt_Value = LQ_SQRT_U32_ROOT(((LQ_UI_32BIT)A) << 2, (LQ_UI_32BIT)Error_Range);
    return (LQ_UINT8_UQ)LQ_Sqrt_Value;
}
/**@brief LQ_UINT8_UQ1 开根 牛顿迭代法
* @details 采用牛顿迭代法进行开跟，相邻两次估计之差小于Error_Range时提前结束
* @param[in] LQ_UINT8_UQ1     A              输入UQ格式数
* @param[in] LQ_UINT8_UQ1     Error_Range    迭代误差范围
* @param[in] LQ_ERROR*      Lq_Error         错误变量
* @return    sqrtA的值
* @exception NSExceptio: LQ_UINT8_UQ1_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE 错误:输入数值是负数\n
*                        LQ_UINT8_UQ1_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW  错误:精度范围太低，无差异性
* @par       计算sqrt(A)的值
* @code
*    LQ_UINT8_UQ1_SQRT_NEWTON_ITERATION(A, Error_Range, &lq_error);
* @endcode
* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
*/
LQ_UINT8_UQ LQ_UINT8_UQ1_SQRT_NEWTON_ITERATION(LQ_UINT8_UQ1 A, LQ_UINT8_UQ1 Error_Range, LQ_ERROR* Lq_Error)
{
    LQ_UI_32BIT LQ_Sqrt_Value;
    if (Error_Range == 0)
    {
        (*Lq_Error) = LQ_UINT8_UQ1_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW;
        return 0;
    }
    LQ_Sqrt_Value = LQ_SQRT_U32_ROOT(((LQ_UI_32BIT)A) << 1, (LQ_UI_32BIT)Error_Range);
    return (LQ_UINT8_UQ)LQ_Sqrt_Value;
}
/**@brief LQ_INT16_Q15 开根 牛顿迭代法
* @details 采用牛顿迭代法进行开跟，相邻两次估计之差小于Error_Range时提前结束
* @param[in] LQ_INT16_Q15     A              输入Q格式数
* @param[in] LQ_INT16_Q15     Error_Range    迭代误差范围
* @param[in] LQ_ERROR*      Lq_Error         错误变量
* @return    sqrtA的值
* @exception NSExceptio: LQ_INT16_Q15_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE 错误:输入数值是负数\n
*                        LQ_INT16_Q15_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW  错误:精度范围太低，无差异性
* @par       计算sqrt(A)的值
* @code
*    LQ_INT16_Q15_SQRT_NEWTON_ITERATION(A, Error_Range, &lq_error);
* @endcode
* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
*/
LQ_INT16_Q LQ_INT16_Q15_SQRT_NEWTON_ITERATION(LQ_INT16_Q15 A, LQ_INT16_Q15 Error_Range, LQ_ERROR* Lq_Error)
{
    LQ_UI_32BIT LQ_Sqrt_Value;
    if (A < 0)
    {
        (*Lq_Error) = LQ_INT16_Q15_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE;
        return 0;
    }
    if (Error_Range <= 0)
    {
        (*Lq_Error) = LQ_INT16_Q15_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW;
        return 0;
    }
    LQ_Sqrt_Value = LQ_SQRT_U32_ROOT(((LQ_UI_32BIT)A) << 15, (LQ_UI_32BIT)Error_Range);
    return (LQ_INT16_Q)LQ_Sqrt_Value;
}
/**@brief LQ_INT16_Q14 开根 牛顿迭代法
* @details 采用牛顿迭代法进行开跟，相邻两次估计之差小于Error_Range时提前结束
* @param[in] LQ_INT16_Q14     A              输入Q格式数
* @param[in] LQ_INT16_Q14     Error_Range    迭代误差范围
* @param[in] LQ_ERROR*      Lq_Error         错误变量
* @return    sqrtA的值
* @exception NSExceptio: LQ_INT16_Q14_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE 错误:输入数值是负数\n
*                        LQ_INT16_Q14_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW  错误:精度范围太低，无差异性
* @par       计算sqrt(A)的值
* @code
*    LQ_INT16_Q14_SQRT_NEWTON_ITERATION(A, Error_Range, &lq_error);
* @endcode
* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
*/
LQ_INT16_Q LQ_INT16_Q14_SQRT_NEWTON_ITERATION(LQ_INT16_Q14 A, LQ_INT16_Q14 Error_Range, LQ_ERROR* Lq_Error)
{
    LQ_UI_32BIT LQ_Sqrt_Value;
    if (A < 0)
    {
        (*Lq_Error) = LQ_INT16_Q14_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE;
        return 0;
    }
    if (Error_Range <= 0)
    {
        (*Lq_Error) = LQ_INT16_Q14_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW;
        return 0;
    }
    LQ_Sqrt_Value = LQ_SQRT_U32_ROOT(((LQ_UI_32BIT)A) << 14, (LQ_UI_32BIT)Error_Range);
    return (LQ_INT16_Q)LQ_Sqrt_Value;
}
/**@brief LQ_INT16_Q13 开根 牛顿迭代法
* @details 采用牛顿迭代法进行开跟，相邻两次估计之差小于Error_Range时提前结束
* @param[in] LQ_INT16_Q13     A              输入Q格式数
* @param[in] LQ_INT16_Q13     Error_Range    迭代误差范围
* @param[in] LQ_ERROR*      Lq_Error         错误变量
* @return    sqrtA的值
* @exception NSExceptio: LQ_INT16_Q13_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE 错误:输入数值是负数\n
*                        LQ_INT16_Q13_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW  错误:精度范围太低，无差异性
* @par       计算sqrt(A)的值
* @code
*    LQ_INT16_Q13_SQRT_NEWTON_ITERATION(A, Error_Range, &lq_error);
* @endcode
* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
*/
LQ_INT16_Q LQ_INT16_Q13_SQRT_NEWTON_ITERATION(LQ_INT16_Q13 A, LQ_INT16_Q13 Error_Range, LQ_ERROR* Lq_Error)
{
    LQ_UI_32BIT LQ_Sqrt_Value;
    if (A < 0)
    {
        (*Lq_Error) = LQ_INT16_Q13_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE;
        return 0;
    }
    if (Error_Range <= 0)
    {
        (*Lq_Error) = LQ_INT16_Q13_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW;
        return 0;
    }
    LQ_Sqrt_Value = LQ_SQRT_U32_ROOT(((LQ_UI_32BIT)A) << 13, (LQ_UI_32BIT)Error_Range);
    return (LQ_INT16_Q)LQ_Sqrt_Value;
}
/**@brief LQ_INT16_Q12 开根 牛顿迭代法
* @details 采用牛顿迭代法进行开跟，相邻两次估计之差小于Error_Range时提前结束
* @param[in] LQ_INT16_Q12     A              输入Q格式数
* @param[in] LQ_INT16_Q12     Error_Range    迭代误差范围
* @param[in] LQ_ERROR*      Lq_Error         错误变量
* @return    sqrtA的值
* @exception NSExceptio: LQ_INT16_Q12_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE 错误:输入数值是负数\n
*                        LQ_INT16_Q12_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW  错误:精度范围太低，无差异性
* @par       计算sqrt(A)的值
* @code
*    LQ_INT16_Q12_SQRT_NEWTON_ITERATION(A, Error_Range, &lq_error);
* @endcode
* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
*/
LQ_INT16_Q LQ_INT16_Q12_SQRT_NEWTON_ITERATION(LQ_INT16_Q12 A, LQ_INT16_Q12 Error_Range, LQ_ERROR* Lq_Error)
{
    LQ_UI_32BIT LQ_Sqrt_Value;
    if (A < 0)
    {
        (*Lq_Error) = LQ_INT16_Q12_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE;
        return 0;
    }
    if (Error_Range <= 0)
    {
        (*Lq_Error) = LQ_INT16_Q12_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW;
        return 0;
    }
    LQ_Sqrt_Value = LQ_SQRT_U32_ROOT(((LQ_UI_32BIT)A) << 12, (LQ_UI_32BIT)Error_Range);
    return (LQ_INT16_Q)LQ_Sqrt_Value;
}
/**@brief LQ_INT16_Q11 开根 牛顿迭代法
* @details 采用牛顿迭代法进行开跟，相邻两次估计之差小于Error_Range时提前结束
* @param[in] LQ_INT16_Q11     A              输入Q格式数
* @param[in] LQ_INT16_Q11     Error_Range    迭代误差范围
* @param[in] LQ_ERROR*      Lq_Error         错误变量
* @return    sqrtA的值
* @exception NSExceptio: LQ_INT16_Q11_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE 错误:输入数值是负数\n
*                        LQ_INT16_Q11_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW  错误:精度范围太低，无差异性
* @par       计算sqrt(A)的值
* @code
*    LQ_INT16_Q11_SQRT_NEWTON_ITERATION(A, Error_Range, &lq_error);
* @endcode
* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
*/
LQ_INT16_Q LQ_INT16_Q11_SQRT_NEWTON_ITERATION(LQ_INT16_Q11 A, LQ_INT16_Q11 Error_Range, LQ_ERROR* Lq_Error)
{
    LQ_UI_32BIT LQ_Sqrt_Value;
    if (A < 0)
    {
        (*Lq_Error) = LQ_INT16_Q11_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE;
        return 0;
    }
    if (Error_Range <= 0)
    {
        (*Lq_Error) = LQ_INT16_Q11_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW;
        return 0;
    }
    LQ_Sqrt_Value = LQ_SQRT_U32_ROOT(((LQ_UI_32BIT)A) << 11, (LQ_UI_32BIT)Error_Range);
    return (LQ_INT16_Q)LQ_Sqrt_Value;
}
/**@brief LQ_INT16_Q10 开根 牛顿迭代法
* @details 采用牛顿迭代法进行开跟，相邻两次估计之差小于Error_Range时提前结束
* @param[in] LQ_INT16_Q10     A              输入Q格式数
* @param[in] LQ_INT16_Q10     Error_Range    迭代误差范围
* @param[in] LQ_ERROR*      Lq_Error         错误变量
* @return    sqrtA的值
* @exception NSExceptio: LQ_INT16_Q10_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE 错误:输入数值是负数\n
*                        LQ_INT16_Q10_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW  错误:精度范围太低，无差异性
* @par       计算sqrt(A)的值
* @code
*    LQ_INT16_Q10_SQRT_NEWTON_ITERATION(A, Error_Range, &lq_error);
* @endcode
* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
*/
LQ_INT16_Q LQ_INT16_Q10_SQRT_NEWTON_ITERATION(LQ_INT16_Q10 A, LQ_INT16_Q10 Error_Range, LQ_ERROR* Lq_Error)
{
    LQ_UI_32BIT LQ_Sqrt_Value;
    if (A < 0)
    {
        (*Lq_Error) = LQ_INT16_Q10_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE;
        return 0;
    }
    if (Error_Range <= 0)
    {
        (*Lq_Error) = LQ_INT16_Q10_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW;
        return 0;
    }
    LQ_Sqrt_Value = LQ_SQRT_U32_ROOT(((LQ_UI_32BIT)A) << 10, (LQ_UI_32BIT)Error_Range);
    return (LQ_INT16_Q)LQ_Sqrt_Value;
}
/**@brief LQ_INT16_Q9 开根 牛顿迭代法
* @details 采用牛顿迭代法进行开跟，相邻两次估计之差小于Error_Range时提前结束
* @param[in] LQ_INT16_Q9     A              输入Q格式数
* @param[in] LQ_INT16_Q9     Error_Range    迭代误差范围
* @param[in] LQ_ERROR*      Lq_Error         错误变量
* @return    sqrtA的值
* @exception NSExceptio: LQ_INT16_Q9_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE 错误:输入数值是负数\n
*                        LQ_INT16_Q9_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW  错误:精度范围太低，无差异性
* @par       计算sqrt(A)的值
* @code
*    LQ_INT16_Q9_SQRT_NEWTON_ITERATION(A, Error_Range, &lq_error);
* @endcode
* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
*/
LQ_INT16_Q LQ_INT16_Q9_SQRT_NEWTON_ITERATION(LQ_INT16_Q9 A, LQ_INT16_Q9 Error_Range, LQ_ERROR* Lq_Error)
{
    LQ_UI_32BIT LQ_Sqrt_Value;
    if (A < 0)
    {
        (*Lq_Error) = LQ_INT16_Q9_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE;
        return 0;
    }
    if (Error_Range <= 0)
    {
        (*Lq_Error) = LQ_INT16_Q9_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW;
        return 0;
    }
    LQ_Sqrt_Value = LQ_SQRT_U32_ROOT(((LQ_UI_32BIT)A) << 9, (LQ_UI_32BIT)Error_Range);
    return (LQ_INT16_Q)LQ_Sqrt_Value;
}
/**@brief LQ_INT16_Q8 开根 牛顿迭代法
* @details 采用牛顿迭代法进行开跟，相邻两次估计之差小于Error_Range时提前结束
* @param[in] LQ_INT16_Q8     A              输入Q格式数
* @param[in] LQ_INT16_Q8     Error_Range    迭代误差范围
* @param[in] LQ_ERROR*      Lq_Error         错误变量
* @return    sqrtA的值
* @exception NSExceptio: LQ_INT16_Q8_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE 错误:输入数值是负数\n
*                        LQ_INT16_Q8_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW  错误:精度范围太低，无差异性
* @par       计算sqrt(A)的值
* @code
*    LQ_INT16_Q8_SQRT_NEWTON_ITERATION(A, Error_Range, &lq_error);
* @endcode
* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
*/
LQ_INT16_Q LQ_INT16_Q8_SQRT_NEWTON_ITERATION(LQ_INT16_Q8 A, LQ_INT16_Q8 Error_Range, LQ_ERROR* Lq_Error)
{
    LQ_UI_32BIT LQ_Sqrt_Value;
    if (A < 0)
    {
        (*Lq_Error) = LQ_INT16_Q8_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE;
        return 0;
    }
    if (Error_Range <= 0)
    {
        (*Lq_Error) = LQ_INT16_Q8_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW;
        return 0;
    }
    LQ_Sqrt_Value = LQ_SQRT_U32_ROOT(((LQ_UI_32BIT)A) << 8, (LQ_UI_32BIT)Error_Range);
    return (LQ_INT16_Q)LQ_Sqrt_Value;
}
/**@brief LQ_INT16_Q7 开根 牛顿迭代法
* @details 采用牛顿迭代法进行开跟，相邻两次估计之差小于Error_Range时提前结束
* @param[in] LQ_INT16_Q7     A              输入Q格式数
* @param[in] LQ_INT16_Q7     Error_Range    迭代误差范围
* @param[in] LQ_ERROR*      Lq_Error         错误变量
* @return    sqrtA的值
* @exception NSExceptio: LQ_INT16_Q7_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE 错误:输入数值是负数\n
*                        LQ_INT16_Q7_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW  错误:精度范围太低，无差异性
* @par       计算sqrt(A)的值
* @code
*    LQ_INT16_Q7_SQRT_NEWTON_ITERATION(A, Error_Range, &lq_error);
* @endcode
* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
*/
LQ_INT16_Q LQ_INT16_Q7_SQRT_NEWTON_ITERATION(LQ_INT16_Q7 A, LQ_INT16_Q7 Error_Range, LQ_ERROR* Lq_Error)
{
    LQ_UI_32BIT LQ_Sqrt_Value;
    if (A < 0)
    {
        (*Lq_Error) = LQ_INT16_Q7_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE;
        return 0;
    }
    if (Error_Range <= 0)
    {
        (*Lq_Error) = LQ_INT16_Q7_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW;
        return 0;
    }
    LQ_Sqrt_Value = LQ_SQRT_U32_ROOT(((LQ_UI_32BIT)A) << 7, (LQ_UI_32BIT)Error_Range);
    return (LQ_INT16_Q)LQ_Sqrt_Value;
}
/**@brief LQ_INT16_Q6 开根 牛顿迭代法
* @details 采用牛顿迭代法进行开跟，相邻两次估计之差小于Error_Range时提前结束
* @param[in] LQ_INT16_Q6     A              输入Q格式数
* @param[in] LQ_INT16_Q6     Error_Range    迭代误差范围
* @param[in] LQ_ERROR*      Lq_Error         错误变量
* @return    sqrtA的值
* @exception NSExceptio: LQ_INT16_Q6_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE 错误:输入数值是负数\n
*                        LQ_INT16_Q6_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW  错误:精度范围太低，无差异性
* @par       计算sqrt(A)的值
* @code
*    LQ_INT16_Q6_SQRT_NEWTON_ITERATION(A, Error_Range, &lq_error);
* @endcode
* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
*/
LQ_INT16_Q LQ_INT16_Q6_SQRT_NEWTON_ITERATION(LQ_INT16_Q6 A, LQ_INT16_Q6 Error_Range, LQ_ERROR* Lq_Error)
{
    LQ_UI_32BIT LQ_Sqrt_Value;
    if (A < 0)
    {
        (*Lq_Error) = LQ_INT16_Q6_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE;
        return 0;
    }
    if (Error_Range <= 0)
    {
        (*Lq_Error) = LQ_INT16_Q6_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW;
        return 0;
    }
    LQ_Sqrt_Value = LQ_SQRT_U32_ROOT(((LQ_UI_32BIT)A) << 6, (LQ_UI_32BIT)Error_Range);
    return (LQ_INT16_Q)LQ_Sqrt_Value;
}
/**@brief LQ_INT16_Q5 开根 牛顿迭代法
* @details 采用牛顿迭代法进行开跟，相邻两次估计之差小于Error_Range时提前结束
* @param[in] LQ_INT16_Q5     A              输入Q格式数
* @param[in] LQ_INT16_Q5     Error_Range    迭代误差范围
* @param[in] LQ_ERROR*      Lq_Error         错误变量
* @return    sqrtA的值
* @exception NSExceptio: LQ_INT16_Q5_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE 错误:输入数值是负数\n
*                        LQ_INT16_Q5_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW  错误:精度范围太低，无差异性
* @par       计算sqrt(A)的值
* @code
*    LQ_INT16_Q5_SQRT_NEWTON_ITERATION(A, Error_Range, &lq_error);
* @endcode
* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
*/
LQ_INT16_Q LQ_INT16_Q5_SQRT_NEWTON_ITERATION(LQ_INT16_Q5 A, LQ_INT16_Q5 Error_Range, LQ_ERROR* Lq_Error)
{
    LQ_UI_32BIT LQ_Sqrt_Value;
    if (A < 0)
    {
        (*Lq_Error) = LQ_INT16_Q5_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE;
        return 0;
    }
    if (Error_Range <= 0)
    {
        (*Lq_Error) = LQ_INT16_Q5_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW;
        return 0;
    }
    LQ_Sqrt_Value = LQ_SQRT_U32_ROOT(((LQ_UI_32BIT)A) << 5, (LQ_UI_32BIT)Error_Range);
    return (LQ_INT16_Q)LQ_Sqrt_Value;
}
/**@brief LQ_INT16_Q4 开根 牛顿迭代法
* @details 采用牛顿迭代法进行开跟，相邻两次估计之差小于Error_Range时提前结束
* @param[in] LQ_INT16_Q4     A              输入Q格式数
* @param[in] LQ_INT16_Q4     Error_Range    迭代误差范围
* @param[in] LQ_ERROR*      Lq_Error         错误变量
* @return    sqrtA的值
* @exception NSExceptio: LQ_INT16_Q4_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE 错误:输入数值是负数\n
*                        LQ_INT16_Q4_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW  错误:精度范围太低，无差异性
* @par       计算sqrt(A)的值
* @code
*    LQ_INT16_Q4_SQRT_NEWTON_ITERATION(A, Error_Range, &lq_error);
* @endcode
* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
*/
LQ_INT16_Q LQ_INT16_Q4_SQRT_NEWTON_ITERATION(LQ_INT16_Q4 A, LQ_INT16_Q4 Error_Range, LQ_ERROR* Lq_Error)
{
    LQ_UI_32BIT LQ_Sqrt_Value;
    if (A < 0)
    {
        (*Lq_Error) = LQ_INT16_Q4_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE;
        return 0;
    }
    if (Error_Range <= 0)
    {
        (*Lq_Error) = LQ_INT16_Q4_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW;
        return 0;
    }
    LQ_Sqrt_Value = LQ_SQRT_U32_ROOT(((LQ_UI_32BIT)A) << 4, (LQ_UI_32BIT)Error_Range);
    return (LQ_INT16_Q)LQ_Sqrt_Value;
}
/**@brief LQ_INT16_Q3 开根 牛顿迭代法
* @details 采用牛顿迭代法进行开跟，相邻两次估计之差小于Error_Range时提前结束
* @param[in] LQ_INT16_Q3     A              输入Q格式数
* @param[in] LQ_INT16_Q3     Error_Range    迭代误差范围
* @param[in] LQ_ERROR*      Lq_Error         错误变量
* @return    sqrtA的值
* @exception NSExceptio: LQ_INT16_Q3_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE 错误:输入数值是负数\n
*                        LQ_INT16_Q3_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW  错误:精度范围太低，无差异性
* @par       计算sqrt(A)的值
* @code
*    LQ_INT16_Q3_SQRT_NEWTON_ITERATION(A, Error_Range, &lq_error);
* @endcode
* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
*/
LQ_INT16_Q LQ_INT16_Q3_SQRT_NEWTON_ITERATION(LQ_INT16_Q3 A, LQ_INT16_Q3 Error_Range, LQ_ERROR* Lq_Error)
{
    LQ_UI_32BIT LQ_Sqrt_Value;
    if (A < 0)
    {
        (*Lq_Error) = LQ_INT16_Q3_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE;
        return 0;
    }
    if (Error_Range <= 0)
    {
        (*Lq_Error) = LQ_INT16_Q3_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW;
        return 0;
    }
    LQ_Sqrt_Value = LQ_SQRT_U32_ROOT(((LQ_UI_32BIT)A) << 3, (LQ_UI_32BIT)Error_Range);
    return (LQ_INT16_Q)LQ_Sqrt_Value;
}
/**@brief LQ_INT16_Q2 开根 牛顿迭代法
* @details 采用牛顿迭代法进行开跟，相邻两次估计之差小于Error_Range时提前结束
* @param[in] LQ_INT16_Q2     A              输入Q格式数
* @param[in] LQ_INT16_Q2     Error_Range    迭代误差范围
* @param[in] LQ_ERROR*      Lq_Error         错误变量
* @return    sqrtA的值
* @exception NSExceptio: LQ_INT16_Q2_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE 错误:输入数值是负数\n
*                        LQ_INT16_Q2_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW  错误:精度范围太低，无差异性
* @par       计算sqrt(A)的值
* @code
*    LQ_INT16_Q2_SQRT_NEWTON_ITERATION(A, Error_Range, &lq_error);
* @endcode
* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
*/
LQ_INT16_Q LQ_INT16_Q2_SQRT_NEWTON_ITERATION(LQ_INT16_Q2 A, LQ_INT16_Q2 Error_Range, LQ_ERROR* Lq_Error)
{
    LQ_UI_32BIT LQ_Sqrt_Value;
    if (A < 0)
    {
        (*Lq_Error) = LQ_INT16_Q2_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE;
        return 0;
    }
    if (Error_Range <= 0)
    {
        (*Lq_Error) = LQ_INT16_Q2_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW;
        return 0;
    }
    LQ_Sqrt_Value = LQ_SQRT_U32_ROOT(((LQ_UI_32BIT)A) << 2, (LQ_UI_32BIT)Error_Range);
    return (LQ_INT16_Q)LQ_Sqrt_Value;
}
/**@brief LQ_INT16_Q1 开根 牛顿迭代法
* @details 采用牛顿迭代法进行开跟，相邻两次估计之差小于Error_Range时提前结束
* @param[in] LQ_INT16_Q1     A              输入Q格式数
* @param[in] LQ_INT16_Q1     Error_Range    迭代误差范围
* @param[in] LQ_ERROR*      Lq_Error         错误变量
* @return    sqrtA的值
* @exception NSExceptio: LQ_INT16_Q1_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE 错误:输入数值是负数\n
*                        LQ_INT16_Q1_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW  错误:精度范围太低，无差异性
* @par       计算sqrt(A)的值
* @code
*    LQ_INT16_Q1_SQRT_NEWTON_ITERATION(A, Error_Range, &lq_error);
* @endcode
* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
*/
LQ_INT16_Q LQ_INT16_Q1_SQRT_NEWTON_ITERATION(LQ_INT16_Q1 A, LQ_INT16_Q1 Error_Range, LQ_ERROR* Lq_Error)
{
    LQ_UI_32BIT LQ_Sqrt_Value;
    if (A < 0)
    {
        (*Lq_Error) = LQ_INT16_Q1_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE;
        return 0;
    }
    if (Error_Range <= 0)
    {
        (*Lq_Error) = LQ_INT16_Q1_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW;
        return 0;
    }
    LQ_Sqrt_Value = LQ_SQRT_U32_ROOT(((LQ_UI_32BIT)A) << 1, (LQ_UI_32BIT)Error_Range);
    return (LQ_INT16_Q)LQ_Sqrt_Value;
}
/**@brief LQ_UINT16_UQ16 开根 牛顿迭代法
* @details 采用牛顿迭代法进行开跟，相邻两次估计之差小于Error_Range时提前结束
* @param[in] LQ_UINT16_UQ16     A              输入UQ格式数
* @param[in] LQ_UINT16_UQ16     Error_Range    迭代误差范围
* @param[in] LQ_ERROR*      Lq_Error         错误变量
* @return    sqrtA的值
* @exception NSExceptio: LQ_UINT16_UQ16_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE 错误:输入数值是负数\n
*                        LQ_UINT16_UQ16_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW  错误:精度范围太低，无差异性
* @par       计算sqrt(A)的值
* @code
*    LQ_UINT16_UQ16_SQRT_NEWTON_ITERATION(A, Error_Range, &lq_error);
* @endcode
* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
*/
LQ_UINT16_UQ LQ_UINT16_UQ16_SQRT_NEWTON_ITERATION(LQ_UINT16_UQ16 A, LQ_UINT16_UQ16 Error_Range, LQ_ERROR* Lq_Error)
{
    LQ_UI_32BIT LQ_Sqrt_Value;
    if (Error_Range == 0)
    {
        (*Lq_Error) = LQ_UINT16_UQ16_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW;
        return 0;
    }
    LQ_Sqrt_Value = LQ_SQRT_U32_ROOT(((LQ_UI_32BIT)A) << 16, (LQ_UI_32BIT)Error_Range);
    return (LQ_UINT16_UQ)LQ_Sqrt_Value;
}
/**@brief LQ_UINT16_UQ15 开根 牛顿迭代法
* @details 采用牛顿迭代法进行开跟，相邻两次估计之差小于Error_Range时提前结束
* @param[in] LQ_UINT16_UQ15     A              输入UQ格式数
* @param[in] LQ_UINT16_UQ15     Error_Range    迭代误差范围
* @param[in] LQ_ERROR*      Lq_Error         错误变量
* @return    sqrtA的值
* @exception NSExceptio: LQ_UINT16_UQ15_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE 错误:输入数值是负数\n
*                        LQ_UINT16_UQ15_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW  错误:精度范围太低，无差异性
* @par       计算sqrt(A)的值
* @code
*    LQ_UINT16_UQ15_SQRT_NEWTON_ITERATION(A, Error_Range, &lq_error);
* @endcode
* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
*/
LQ_UINT16_UQ LQ_UINT16_UQ15_SQRT_NEWTON_ITERATION(LQ_UINT16_UQ15 A, LQ_UINT16_UQ15 Error_Range, LQ_ERROR* Lq_Error)
{
    LQ_UI_32BIT LQ_Sqrt_Value;
    if (Error_Range == 0)
    {
        (*Lq_Error) = LQ_UINT16_UQ15_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW;
        return 0;
    }
    LQ_Sqrt_Value = LQ_SQRT_U32_ROOT(((LQ_UI_32BIT)A) << 15, (LQ_UI_32BIT)Error_Range);
    return (LQ_UINT16_UQ)LQ_Sqrt_Value;
}
/**@brief LQ_UINT16_UQ14 开根 牛顿迭代法
* @details 采用牛顿迭代法进行开跟，相邻两次估计之差小于Error_Range时提前结束
* @param[in] LQ_UINT16_UQ14     A              输入UQ格式数
* @param[in] LQ_UINT16_UQ14     Error_Range    迭代误差范围
* @param[in] LQ_ERROR*      Lq_Error         错误变量
* @return    sqrtA的值
* @exception NSExceptio: LQ_UINT16_UQ14_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE 错误:输入数值是负数\n
*                        LQ_UINT16_UQ14_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW  错误:精度范围太低，无差异性
* @par       计算sqrt(A)的值
* @code
*    LQ_UINT16_UQ14_SQRT_NEWTON_ITERATION(A, Error_Range, &lq_error);
* @endcode
* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
*/
LQ_UINT16_UQ LQ_UINT16_UQ14_SQRT_NEWTON_ITERATION(LQ_UINT16_UQ14 A, LQ_UINT16_UQ14 Error_Range, LQ_ERROR* Lq_Error)
{
    LQ_UI_32BIT LQ_Sqrt_Value;
    if (Error_Range == 0)
    {
        (*Lq_Error) = LQ_UINT16_UQ14_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW;
        return 0;
    }
    LQ_Sqrt_Value = LQ_SQRT_U32_ROOT(((LQ_UI_32BIT)A) << 14, (LQ_UI_32BIT)Error_Range);
    return (LQ_UINT16_UQ)LQ_Sqrt_Value;
}
/**@brief LQ_UINT16_UQ13 开根 牛顿迭代法
* @details 采用牛顿迭代法进行开跟，相邻两次估计之差小于Error_Range时提前结束
* @param[in] LQ_UINT16_UQ13     A              输入UQ格式数
* @param[in] LQ_UINT16_UQ13     Error_Range    迭代误差范围
* @param[in] LQ_ERROR*      Lq_Error         错误变量
* @return    sqrtA的值
* @exception NSExceptio: LQ_UINT16_UQ13_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE 错误:输入数值是负数\n
*                        LQ_UINT16_UQ13_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW  错误:精度范围太低，无差异性
* @par       计算sqrt(A)的值
* @code
*    LQ_UINT16_UQ13_SQRT_NEWTON_ITERATION(A, Error_Range, &lq_error);
* @endcode
* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
*/
LQ_UINT16_UQ LQ_UINT16_UQ13_SQRT_NEWTON_ITERATION(LQ_UINT16_UQ13 A, LQ_UINT16_UQ13 Error_Range, LQ_ERROR* Lq_Error)
{
    LQ_UI_32BIT LQ_Sqrt_Value;
    if (Error_Range == 0)
    {
        (*Lq_Error) = LQ_UINT16_UQ13_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW;
        return 0;
    }
    LQ_Sqrt_Value = LQ_SQRT_U32_ROOT(((LQ_UI_32BIT)A) << 13, (LQ_UI_32BIT)Error_Range);
    return (LQ_UINT16_UQ)LQ_Sqrt_Value;
}
/**@brief LQ_UINT16_UQ12 开根 牛顿迭代法
* @details 采用牛顿迭代法进行开跟，相邻两次估计之差小于Error_Range时提前结束
* @param[in] LQ_UINT16_UQ12     A              输入UQ格式数
* @param[in] LQ_UINT16_UQ12     Error_Range    迭代误差范围
* @param[in] LQ_ERROR*      Lq_Error         错误变量
* @return    sqrtA的值
* @exception NSExceptio: LQ_UINT16_UQ12_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE 错误:输入数值是负数\n
*                        LQ_UINT16_UQ12_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW  错误:精度范围太低，无差异性
* @par       计算sqrt(A)的值
* @code
*    LQ_UINT16_UQ12_SQRT_NEWTON_ITERATION(A, Error_Range, &lq_error);
* @endcode
* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
*/
LQ_UINT16_UQ LQ_UINT16_UQ12_SQRT_NEWTON_ITERATION(LQ_UINT16_UQ12 A, LQ_UINT16_UQ12 Error_Range, LQ_ERROR* Lq_Error)
{
    LQ_UI_32BIT LQ_Sqrt_Value;
    if (Error_Range == 0)
    {
        (*Lq_Error) = LQ_UINT16_UQ12_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW;
        return 0;
    }
    LQ_Sqrt_Value = LQ_SQRT_U32_ROOT(((LQ_UI_32BIT)A) << 12, (LQ_UI_32BIT)Error_Range);
    return (LQ_UINT16_UQ)LQ_Sqrt_Value;
}
/**@brief LQ_UINT16_UQ11 开根 牛顿迭代法
* @details 采用牛顿迭代法进行开跟，相邻两次估计之差小于Error_Range时提前结束
* @param[in] LQ_UINT16_UQ11     A              输入UQ格式数
* @param[in] LQ_UINT16_UQ11     Error_Range    迭代误差范围
* @param[in] LQ_ERROR*      Lq_Error         错误变量
* @return    sqrtA的值
* @exception NSExceptio: LQ_UINT16_UQ11_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE 错误:输入数值是负数\n
*                        LQ_UINT16_UQ11_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW  错误:精度范围太低，无差异性
* @par       计算sqrt(A)的值
* @code
*    LQ_UINT16_UQ11_SQRT_NEWTON_ITERATION(A, Error_Range, &lq_error);
* @endcode
* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
*/
LQ_UINT16_UQ LQ_UINT16_UQ11_SQRT_NEWTON_ITERATION(LQ_UINT16_UQ11 A, LQ_UINT16_UQ11 Error_Range, LQ_ERROR* Lq_Error)
{
    LQ_UI_32BIT LQ_Sqrt_Value;
    if (Error_Range == 0)
    {
        (*Lq_Error) = LQ_UINT16_UQ11_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW;
        return 0;
    }
    LQ_Sqrt_Value = LQ_SQRT_U32_ROOT(((LQ_UI_32BIT)A) << 11, (LQ_UI_32BIT)Error_Range);
    return (LQ_UINT16_UQ)LQ_Sqrt_Value;
}
/**@brief LQ_UINT16_UQ10 开根 牛顿迭代法
* @details 采用牛顿迭代法进行开跟，相邻两次估计之差小于Error_Range时提前结束
* @param[in] LQ_UINT16_UQ10     A              输入UQ格式数
* @param[in] LQ_UINT16_UQ10     Error_Range    迭代误差范围
* @param[in] LQ_ERROR*      Lq_Error         错误变量
* @return    sqrtA的值
* @exception NSExceptio: LQ_UINT16_UQ10_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE 错误:输入数值是负数\n
*                        LQ_UINT16_UQ10_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW  错误:精度范围太低，无差异性
* @par       计算sqrt(A)的值
* @code
*    LQ_UINT16_UQ10_SQRT_NEWTON_ITERATION(A, Error_Range, &lq_error);
* @endcode
* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
*/
LQ_UINT16_UQ LQ_UINT16_UQ10_SQRT_NEWTON_ITERATION(LQ_UINT16_UQ10 A, LQ_UINT16_UQ10 Error_Range, LQ_ERROR* Lq_Error)
{
    LQ_UI_32BIT LQ_Sqrt_Value;
    if (Error_Range == 0)
    {
        (*Lq_Error) = LQ_UINT16_UQ10_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW;
        return 0;
    }
    LQ_Sqrt_Value = LQ_SQRT_U32_ROOT(((LQ_UI_32BIT)A) << 10, (LQ_UI_32BIT)Error_Range);
    return (LQ_UINT16_UQ)LQ_Sqrt_Value;
}
/**@brief LQ_UINT16_UQ9 开根 牛顿迭代法
* @details 采用牛顿迭代法进行开跟，相邻两次估计之差小于Error_Range时提前结束
* @param[in] LQ_UINT16_UQ9     A              输入UQ格式数
* @param[in] LQ_UINT16_UQ9     Error_Range    迭代误差范围
* @param[in] LQ_ERROR*      Lq_Error         错误变量
* @return    sqrtA的值
* @exception NSExceptio: LQ_UINT16_UQ9_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE 错误:输入数值是负数\n
*                        LQ_UINT16_UQ9_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW  错误:精度范围太低，无差异性
* @par       计算sqrt(A)的值
* @code
*    LQ_UINT16_UQ9_SQRT_NEWTON_ITERATION(A, Error_Range, &lq_error);
* @endcode
* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
*/
LQ_UINT16_UQ LQ_UINT16_UQ9_SQRT_NEWTON_ITERATION(LQ_UINT16_UQ9 A, LQ_UINT16_UQ9 Error_Range, LQ_ERROR* Lq_Error)
{
    LQ_UI_32BIT LQ_Sqrt_Value;
    if (Error_Range == 0)
    {
        (*Lq_Error) = LQ_UINT16_UQ9_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW;
        return 0;
    }
    LQ_Sqrt_Value = LQ_SQRT_U32_ROOT(((LQ_UI_32BIT)A) << 9, (LQ_UI_32BIT)Error_Range);
    return (LQ_UINT16_UQ)LQ_Sqrt_Value;
}
/**@brief LQ_UINT16_UQ8 开根 牛顿迭代法
* @details 采用牛顿迭代法进行开跟，相邻两次估计之差小于Error_Range时提前结束
* @param[in] LQ_UINT16_UQ8     A              输入UQ格式数
* @param[in] LQ_UINT16_UQ8     Error_Range    迭代误差范围
* @param[in] LQ_ERROR*      Lq_Error         错误变量
* @return    sqrtA的值
* @exception NSExceptio: LQ_UINT16_UQ8_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE 错误:输入数值是负数\n
*                        LQ_UINT16_UQ8_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW  错误:精度范围太低，无差异性
* @par       计算sqrt(A)的值
* @code
*    LQ_UINT16_UQ8_SQRT_NEWTON_ITERATION(A, Error_Range, &lq_error);
* @endcode
* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
*/
LQ_UINT16_UQ LQ_UINT16_UQ8_SQRT_NEWTON_ITERATION(LQ_UINT16_UQ8 A, LQ_UINT16_UQ8 Error_Range, LQ_ERROR* Lq_Error)
{
    LQ_UI_32BIT LQ_Sqrt_Value;
    if (Error_Range == 0)
    {
        (*Lq_Error) = LQ_UINT16_UQ8_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW;
        return 0;
    }
    LQ_Sqrt_Value = LQ_SQRT_U32_ROOT(((LQ_UI_32BIT)A) << 8, (LQ_UI_32BIT)Error_Range);
    return (LQ_UINT16_UQ)LQ_Sqrt_Value;
}
/**@brief LQ_UINT16_UQ7 开根 牛顿迭代法
* @details 采用牛顿迭代法进行开跟，相邻两次估计之差小于Error_Range时提前结束
* @param[in] LQ_UINT16_UQ7     A              输入UQ格式数
* @param[in] LQ_UINT16_UQ7     Error_Range    迭代误差范围
* @param[in] LQ_ERROR*      Lq_Error         错误变量
* @return    sqrtA的值
* @exception NSExceptio: LQ_UINT16_UQ7_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE 错误:输入数值是负数\n
*                        LQ_UINT16_UQ7_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW  错误:精度范围太低，无差异性
* @par       计算sqrt(A)的值
* @code
*    LQ_UINT16_UQ7_SQRT_NEWTON_ITERATION(A, Error_Range, &lq_error);
* @endcode
* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
*/
LQ_UINT16_UQ LQ_UINT16_UQ7_SQRT_NEWTON_ITERATION(LQ_UINT16_UQ7 A, LQ_UINT16_UQ7 Error_Range, LQ_ERROR* Lq_Error)
{
    LQ_UI_32BIT LQ_Sqrt_Value;
    if (Error_Range == 0)
    {
        (*Lq_Error) = LQ_UINT16_UQ7_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW;
        return 0;
    }
    LQ_Sqrt_Value = LQ_SQRT_U32_ROOT(((LQ_UI_32BIT)A) << 7, (LQ_UI_32BIT)Error_Range);
    return (LQ_UINT16_UQ)LQ_Sqrt_Value;
}
/**@brief LQ_UINT16_UQ6 开根 牛顿迭代法
* @details 采用牛顿迭代法进行开跟，相邻两次估计之差小于Error_Range时提前结束
* @param[in] LQ_UINT16_UQ6     A              输入UQ格式数
* @param[in] LQ_UINT16_UQ6     Error_Range    迭代误差范围
* @param[in] LQ_ERROR*      Lq_Error         错误变量
* @return    sqrtA的值
* @exception NSExceptio: LQ_UINT16_UQ6_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE 错误:输入数值是负数\n
*                        LQ_UINT16_UQ6_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW  错误:精度范围太低，无差异性
* @par       计算sqrt(A)的值
* @code
*    LQ_UINT16_UQ6_SQRT_NEWTON_ITERATION(A, Error_Range, &lq_error);
* @endcode
* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
*/
LQ_UINT16_UQ LQ_UINT16_UQ6_SQRT_NEWTON_ITERATION(LQ_UINT16_UQ6 A, LQ_UINT16_UQ6 Error_Range, LQ_ERROR* Lq_Error)
{
    LQ_UI_32BIT LQ_Sqrt_Value;
    if (Error_Range == 0)
    {
        (*Lq_Error) = LQ_UINT16_UQ6_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW;
        return 0;
    }
    LQ_Sqrt_Value = LQ_SQRT_U32_ROOT(((LQ_UI_32BIT)A) << 6, (LQ_UI_32BIT)Error_Range);
    return (LQ_UINT16_UQ)LQ_Sqrt_Value;
}
/**@brief LQ_UINT16_UQ5 开根 牛顿迭代法
* @details 采用牛顿迭代法进行开跟，相邻两次估计之差小于Error_Range时提前结束
* @param[in] LQ_UINT16_UQ5     A              输入UQ格式数
* @param[in] LQ_UINT16_UQ5     Error_Range    迭代误差范围
* @param[in] LQ_ERROR*      Lq_Error         错误变量
* @return    sqrtA的值
* @exception NSExceptio: LQ_UINT16_UQ5_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE 错误:输入数值是负数\n
*                        LQ_UINT16_UQ5_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW  错误:精度范围太低，无差异性
* @par       计算sqrt(A)的值
* @code
*    LQ_UINT16_UQ5_SQRT_NEWTON_ITERATION(A, Error_Range, &lq_error);
* @endcode
* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
*/
LQ_UINT16_UQ LQ_UINT16_UQ5_SQRT_NEWTON_ITERATION(LQ_UINT16_UQ5 A, LQ_UINT16_UQ5 Error_Range, LQ_ERROR* Lq_Error)
{
    LQ_UI_32BIT LQ_Sqrt_Value;
    if (Error_Range == 0)
    {
        (*Lq_Error) = LQ_UINT16_UQ5_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW;
        return 0;
    }
    LQ_Sqrt_Value = LQ_SQRT_U32_ROOT(((LQ_UI_32BIT)A) << 5, (LQ_UI_32BIT)Error_Range);
    return (LQ_UINT16_UQ)LQ_Sqrt_Value;
}
/**@brief LQ_UINT16_UQ4 开根 牛顿迭代法
* @details 采用牛顿迭代法进行开跟，相邻两次估计之差小于Error_Range时提前结束
* @param[in] LQ_UINT16_UQ4     A              输入UQ格式数
* @param[in] LQ_UINT16_UQ4     Error_Range    迭代误差范围
* @param[in] LQ_ERROR*      Lq_Error         错误变量
* @return    sqrtA的值
* @exception NSExceptio: LQ_UINT16_UQ4_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE 错误:输入数值是负数\n
*                        LQ_UINT16_UQ4_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW  错误:精度范围太低，无差异性
* @par       计算sqrt(A)的值
* @code
*    LQ_UINT16_UQ4_SQRT_NEWTON_ITERATION(A, Error_Range, &lq_error);
* @endcode
* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
*/
LQ_UINT16_UQ LQ_UINT16_UQ4_SQRT_NEWTON_ITERATION(LQ_UINT16_UQ4 A, LQ_UINT16_UQ4 Error_Range, LQ_ERROR* Lq_Error)
{
    LQ_UI_32BIT LQ_Sqrt_Value;
    if (Error_Range == 0)
    {
        (*Lq_Error) = LQ_UINT16_UQ4_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW;
        return 0;
    }
    LQ_Sqrt_Value = LQ_SQRT_U32_ROOT(((LQ_UI_32BIT)A) << 4, (LQ_UI_32BIT)Error_Range);
    return (LQ_UINT16_UQ)LQ_Sqrt_Value;
}
/**@brief LQ_UINT16_UQ3 开根 牛顿迭代法
* @details 采用牛顿迭代法进行开跟，相邻两次估计之差小于Error_Range时提前结束
* @param[in] LQ_UINT16_UQ3     A              输入UQ格式数
* @param[in] LQ_UINT16_UQ3     Error_Range    迭代误差范围
* @param[in] LQ_ERROR*      Lq_Error         错误变量
* @return    sqrtA的值
* @exception NSExceptio: LQ_UINT16_UQ3_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE 错误:输入数值是负数\n
*                        LQ_UINT16_UQ3_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW  错误:精度范围太低，无差异性
* @par       计算sqrt(A)的值
* @code
*    LQ_UINT16_UQ3_SQRT_NEWTON_ITERATION(A, Error_Range, &lq_error);
* @endcode
* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
*/
LQ_UINT16_UQ LQ_UINT16_UQ3_SQRT_NEWTON_ITERATION(LQ_UINT16_UQ3 A, LQ_UINT16_UQ3 Error_Range, LQ_ERROR* Lq_Error)
{
    LQ_UI_32BIT LQ_Sqrt_Value;
    if (Error_Range == 0)
    {
        (*Lq_Error) = LQ_UINT16_UQ3_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW;
        return 0;
    }
    LQ_Sqrt_Value = LQ_SQRT_U32_ROOT(((LQ_UI_32BIT)A) << 3, (LQ_UI_32BIT)Error_Range);
    return (LQ_UINT16_UQ)LQ_Sqrt_Value;
}
/**@brief LQ_UINT16_UQ2 开根 牛顿迭代法
* @details 采用牛顿迭代法进行开跟，相邻两次估计之差小于Error_Range时提前结束
* @param[in] LQ_UINT16_UQ2     A              输入UQ格式数
* @param[in] LQ_UINT16_UQ2     Error_Range    迭代误差范围
* @param[in] LQ_ERROR*      Lq_Error         错误变量
* @return    sqrtA的值
* @exception NSExceptio: LQ_UINT16_UQ2_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE 错误:输入数值是负数\n
*                        LQ_UINT16_UQ2_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW  错误:精度范围太低，无差异性
* @par       计算sqrt(A)的值
* @code
*    LQ_UINT16_UQ2_SQRT_NEWTON_ITERATION(A, Error_Range, &lq_error);
* @endcode
* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
*/
LQ_UINT16_UQ LQ_UINT16_UQ2_SQRT_NEWTON_ITERATION(LQ_UINT16_UQ2 A, LQ_UINT16_UQ2 Error_Range, LQ_ERROR* Lq_Error)
{
    LQ_UI_32BIT LQ_Sqrt_Value;
    if (Error_Range == 0)
    {
        (*Lq_Error) = LQ_UINT16_UQ2_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW;
        return 0;
    }
    LQ_Sqrt_Value = LQ_SQRT_U32_ROOT(((LQ_UI_32BIT)A) << 2, (LQ_UI_32BIT)Error_Range);
    return (LQ_UINT16_UQ)LQ_Sqrt_Value;
}
/**@brief LQ_UINT16_UQ1 开根 牛顿迭代法
* @details 采用牛顿迭代法进行开跟，相邻两次估计之差小于Error_Range时提前结束
* @param[in] LQ_UINT16_UQ1     A              输入UQ格式数
* @param[in] LQ_UINT16_UQ1     Error_Range    迭代误差范围
* @param[in] LQ_ERROR*      Lq_Error         错误变量
* @return    sqrtA的值
* @exception NSExceptio: LQ_UINT16_UQ1_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE 错误:输入数值是负数\n
*                        LQ_UINT16_UQ1_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW  错误:精度范围太低，无差异性
* @par       计算sqrt(A)的值
* @code
*    LQ_UINT16_UQ1_SQRT_NEWTON_ITERATION(A, Error_Range, &lq_error);
* @endcode
* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
*/
LQ_UINT16_UQ LQ_UINT16_UQ1_SQRT_NEWTON_ITERATION(LQ_UINT16_UQ1 A, LQ_UINT16_UQ1 Error_Range, LQ_ERROR* Lq_Error)
{
    LQ_UI_32BIT LQ_Sqrt_Value;
    if (Error_Range == 0)
    {
        (*Lq_Error) = LQ_UINT16_UQ1_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW;
        return 0;
    }
    LQ_Sqrt_Value = LQ_SQRT_U32_ROOT(((LQ_UI_32BIT)A) << 1, (LQ_UI_32BIT)Error_Range);
    return (LQ_UINT16_UQ)LQ_Sqrt_Value;
}
/**@brief LQ_INT32_Q31 开根 牛顿迭代法
* @details 采用牛顿迭代法进行开跟，相邻两次估计之差小于Error_Range时提前结束
* @param[in] LQ_INT32_Q31     A              输入Q格式数
* @param[in] LQ_INT32_Q31     Error_Range    迭代误差范围
* @param[in] LQ_ERROR*      Lq_Error         错误变量
* @return    sqrtA的值
* @exception NSExceptio: LQ_INT32_Q31_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE 错误:输入数值是负数\n
*                        LQ_INT32_Q31_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW  错误:精度范围太低，无差异性
* @par       计算sqrt(A)的值
* @code
*    LQ_INT32_Q31_SQRT_NEWTON_ITERATION(A, Error_Range, &lq_error);
* @endcode
* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
*/
LQ_INT32_Q LQ_INT32_Q31_SQRT_NEWTON_ITERATION(LQ_INT32_Q31 A, LQ_INT32_Q31 Error_Range, LQ_ERROR* Lq_Error)
{
    LQ_UI_64BIT LQ_Sqrt_Value;
    if (A < 0)
    {
        (*Lq_Error) = LQ_INT32_Q31_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE;
        return 0;
    }
    if (Error_Range <= 0)
    {
        (*Lq_Error) = LQ_INT32_Q31_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW;
        return 0;
    }
    LQ_Sqrt_Value = LQ_SQRT_U64_ROOT(((LQ_UI_64BIT)A) << 31, (LQ_UI_64BIT)Error_Range);
    return (LQ_INT32_Q)LQ_Sqrt_Value;
}
/**@brief LQ_INT32_Q30 开根 牛顿迭代法
* @details 采用牛顿迭代法进行开跟，相邻两次估计之差小于Error_Range时提前结束
* @param[in] LQ_INT32_Q30     A              输入Q格式数
* @param[in] LQ_INT32_Q30     Error_Range    迭代误差范围
* @param[in] LQ_ERROR*      Lq_Error         错误变量
* @return    sqrtA的值
* @exception NSExceptio: LQ_INT32_Q30_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE 错误:输入数值是负数\n
*                        LQ_INT32_Q30_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW  错误:精度范围太低，无差异性
* @par       计算sqrt(A)的值
* @code
*    LQ_INT32_Q30_SQRT_NEWTON_ITERATION(A, Error_Range, &lq_error);
* @endcode
* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
*/
LQ_INT32_Q LQ_INT32_Q30_SQRT_NEWTON_ITERATION(LQ_INT32_Q30 A, LQ_INT32_Q30 Error_Range, LQ_ERROR* Lq_Error)
{
    LQ_UI_64BIT LQ_Sqrt_Value;
    if (A < 0)
    {
        (*Lq_Error) = LQ_INT32_Q30_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE;
        return 0;
    }
    if (Error_Range <= 0)
    {
        (*Lq_Error) = LQ_INT32_Q30_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW;
        return 0;
    }
    LQ_Sqrt_Value = LQ_SQRT_U64_ROOT(((LQ_UI_64BIT)A) << 30, (LQ_UI_64BIT)Error_Range);
    return (LQ_INT32_Q)LQ_Sqrt_Value;
}
/**@brief LQ_INT32_Q29 开根 牛顿迭代法
* @details 采用牛顿迭代法进行开跟，相邻两次估计之差小于Error_Range时提前结束
* @param[in] LQ_INT32_Q29     A              输入Q格式数
* @param[in] LQ_INT32_Q29     Error_Range    迭代误差范围
* @param[in] LQ_ERROR*      Lq_Error         错误变量
* @return    sqrtA的值
* @exception NSExceptio: LQ_INT32_Q29_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE 错误:输入数值是负数\n
*                        LQ_INT32_Q29_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW  错误:精度范围太低，无差异性
* @par       计算sqrt(A)的值
* @code
*    LQ_INT32_Q29_SQRT_NEWTON_ITERATION(A, Error_Range, &lq_error);
* @endcode
* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
*/
LQ_INT32_Q LQ_INT32_Q29_SQRT_NEWTON_ITERATION(LQ_INT32_Q29 A, LQ_INT32_Q29 Error_Range, LQ_ERROR* Lq_Error)
{
    LQ_UI_64BIT LQ_Sqrt_Value;
    if (A < 0)
    {
        (*Lq_Error) = LQ_INT32_Q29_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE;
        return 0;
    }
    if (Error_Range <= 0)
    {
        (*Lq_Error) = LQ_INT32_Q29_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW;
        return 0;
    }
    LQ_Sqrt_Value = LQ_SQRT_U64_ROOT(((LQ_UI_64BIT)A) << 29, (LQ_UI_64BIT)Error_Range);
    return (LQ_INT32_Q)LQ_Sqrt_Value;
}
/**@brief LQ_INT32_Q28 开根 牛顿迭代法
* @details 采用牛顿迭代法进行开跟，相邻两次估计之差小于Error_Range时提前结束
* @param[in] LQ_INT32_Q28     A              输入Q格式数
* @param[in] LQ_INT32_Q28     Error_Range    迭代误差范围
* @param[in] LQ_ERROR*      Lq_Error         错误变量
* @return    sqrtA的值
* @exception NSExceptio: LQ_INT32_Q28_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE 错误:输入数值是负数\n
*                        LQ_INT32_Q28_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW  错误:精度范围太低，无差异性
* @par       计算sqrt(A)的值
* @code
*    LQ_INT32_Q28_SQRT_NEWTON_ITERATION(A, Error_Range, &lq_error);
* @endcode
* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
*/
LQ_INT32_Q LQ_INT32_Q28_SQRT_NEWTON_ITERATION(LQ_INT32_Q28 A, LQ_INT32_Q28 Error_Range, LQ_ERROR* Lq_Error)
{
    LQ_UI_64BIT LQ_Sqrt_Value;
    if (A < 0)
    {
        (*Lq_Error) = LQ_INT32_Q28_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE;
        return 0;
    }
    if (Error_Range <= 0)
    {
        (*Lq_Error) = LQ_INT32_Q28_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW;
        return 0;
    }
    LQ_Sqrt_Value = LQ_SQRT_U64_ROOT(((LQ_UI_64BIT)A) << 28, (LQ_UI_64BIT)Error_Range);
    return (LQ_INT32_Q)LQ_Sqrt_Value;
}
/**@brief LQ_INT32_Q27 开根 牛顿迭代法
* @details 采用牛顿迭代法进行开跟，相邻两次估计之差小于Error_Range时提前结束
* @param[in] LQ_INT32_Q27     A              输入Q格式数
* @param[in] LQ_INT32_Q27     Error_Range    迭代误差范围
* @param[in] LQ_ERROR*      Lq_Error         错误变量
* @return    sqrtA的值
* @exception NSExceptio: LQ_INT32_Q27_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE 错误:输入数值是负数\n
*                        LQ_INT32_Q27_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW  错误:精度范围太低，无差异性
* @par       计算sqrt(A)的值
* @code
*    LQ_INT32_Q27_SQRT_NEWTON_ITERATION(A, Error_Range, &lq_error);
* @endcode
* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
*/
LQ_INT32_Q LQ_INT32_Q27_SQRT_NEWTON_ITERATION(LQ_INT32_Q27 A, LQ_INT32_Q27 Error_Range, LQ_ERROR* Lq_Error)
{
    LQ_UI_64BIT LQ_Sqrt_Value;
    if (A < 0)
    {
        (*Lq_Error) = LQ_INT32_Q27_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE;
        return 0;
    }
    if (Error_Range <= 0)
    {
        (*Lq_Error) = LQ_INT32_Q27_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW;
        return 0;
    }
    LQ_Sqrt_Value = LQ_SQRT_U64_ROOT(((LQ_UI_64BIT)A) << 27, (LQ_UI_64BIT)Error_Range);
    return (LQ_INT32_Q)LQ_Sqrt_Value;
}
/**@brief LQ_INT32_Q26 开根 牛顿迭代法
* @details 采用牛顿迭代法进行开跟，相邻两次估计之差小于Error_Range时提前结束
* @param[in] LQ_INT32_Q26     A              输入Q格式数
* @param[in] LQ_INT32_Q26     Error_Range    迭代误差范围
* @param[in] LQ_ERROR*      Lq_Error         错误变量
* @return    sqrtA的值
* @exception NSExceptio: LQ_INT32_Q26_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE 错误:输入数值是负数\n
*                        LQ_INT32_Q26_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW  错误:精度范围太低，无差异性
* @par       计算sqrt(A)的值
* @code
*    LQ_INT32_Q26_SQRT_NEWTON_ITERATION(A, Error_Range, &lq_error);
* @endcode
* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
*/
LQ_INT32_Q LQ_INT32_Q26_SQRT_NEWTON_ITERATION(LQ_INT32_Q26 A, LQ_INT32_Q26 Error_Range, LQ_ERROR* Lq_Error)
{
    LQ_UI_64BIT LQ_Sqrt_Value;
    if (A < 0)
    {
        (*Lq_Error) = LQ_INT32_Q26_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE;
        return 0;
    }
    if (Error_Range <= 0)
    {
        (*Lq_Error) = LQ_INT32_Q26_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW;
        return 0;
    }
    LQ_Sqrt_Value = LQ_SQRT_U64_ROOT(((LQ_UI_64BIT)A) << 26, (LQ_UI_64BIT)Error_Range);
    return (LQ_INT32_Q)LQ_Sqrt_Value;
}
/**@brief LQ_INT32_Q25 开根 牛顿迭代法
* @details 采用牛顿迭代法进行开跟，相邻两次估计之差小于Error_Range时提前结束
* @param[in] LQ_INT32_Q25     A              输入Q格式数
* @param[in] LQ_INT32_Q25     Error_Range    迭代误差范围
* @param[in] LQ_ERROR*      Lq_Error         错误变量
* @return    sqrtA的值
* @exception NSExceptio: LQ_INT32_Q25_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE 错误:输入数值是负数\n
*                        LQ_INT32_Q25_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW  错误:精度范围太低，无差异性
* @par       计算sqrt(A)的值
* @code
*    LQ_INT32_Q25_SQRT_NEWTON_ITERATION(A, Error_Range, &lq_error);
* @endcode
* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
*/
LQ_INT32_Q LQ_INT32_Q25_SQRT_NEWTON_ITERATION(LQ_INT32_Q25 A, LQ_INT32_Q25 Error_Range, LQ_ERROR* Lq_Error)
{
    LQ_UI_64BIT LQ_Sqrt_Value;
    if (A < 0)
    {
        (*Lq_Error) = LQ_INT32_Q25_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE;
        return 0;
    }
    if (Error_Range <= 0)
    {
        (*Lq_Error) = LQ_INT32_Q25_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW;
        return 0;
    }
    LQ_Sqrt_Value = LQ_SQRT_U64_ROOT(((LQ_UI_64BIT)A) << 25, (LQ_UI_64BIT)Error_Range);
    return (LQ_INT32_Q)LQ_Sqrt_Value;
}
/**@brief LQ_INT32_Q24 开根 牛顿迭代法
* @details 采用牛顿迭代法进行开跟，相邻两次估计之差小于Error_Range时提前结束
* @param[in] LQ_INT32_Q24     A              输入Q格式数
* @param[in] LQ_INT32_Q24     Error_Range    迭代误差范围
* @param[in] LQ_ERROR*      Lq_Error         错误变量
* @return    sqrtA的值
* @exception NSExceptio: LQ_INT32_Q24_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE 错误:输入数值是负数\n
*                        LQ_INT32_Q24_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW  错误:精度范围太低，无差异性
* @par       计算sqrt(A)的值
* @code
*    LQ_INT32_Q24_SQRT_NEWTON_ITERATION(A, Error_Range, &lq_error);
* @endcode
* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
*/
LQ_INT32_Q LQ_INT32_Q24_SQRT_NEWTON_ITERATION(LQ_INT32_Q24 A, LQ_INT32_Q24 Error_Range, LQ_ERROR* Lq_Error)
{
    LQ_UI_64BIT LQ_Sqrt_Value;
    if (A < 0)
    {
        (*Lq_Error) = LQ_INT32_Q24_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE;
        return 0;
    }
    if (Error_Range <= 0)
    {
        (*Lq_Error) = LQ_INT32_Q24_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW;
        return 0;
    }
    LQ_Sqrt_Value = LQ_SQRT_U64_ROOT(((LQ_UI_64BIT)A) << 24, (LQ_UI_64BIT)Error_Range);
    return (LQ_INT32_Q)LQ_Sqrt_Value;
}
/**@brief LQ_INT32_Q23 开根 牛顿迭代法
* @details 采用牛顿迭代法进行开跟，相邻两次估计之差小于Error_Range时提前结束
* @param[in] LQ_INT32_Q23     A              输入Q格式数
* @param[in] LQ_INT32_Q23     Error_Range    迭代误差范围
* @param[in] LQ_ERROR*      Lq_Error         错误变量
* @return    sqrtA的值
* @exception NSExceptio: LQ_INT32_Q23_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE 错误:输入数值是负数\n
*                        LQ_INT32_Q23_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW  错误:精度范围太低，无差异性
* @par       计算sqrt(A)的值
* @code
*    LQ_INT32_Q23_SQRT_NEWTON_ITERATION(A, Error_Range, &lq_error);
* @endcode
* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
*/
LQ_INT32_Q LQ_INT32_Q23_SQRT_NEWTON_ITERATION(LQ_INT32_Q23 A, LQ_INT32_Q23 Error_Range, LQ_ERROR* Lq_Error)
{
    LQ_UI_64BIT LQ_Sqrt_Value;
    if (A < 0)
    {
        (*Lq_Error) = LQ_INT32_Q23_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE;
        return 0;
    }
    if (Error_Range <= 0)
    {
        (*Lq_Error) = LQ_INT32_Q23_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW;
        return 0;
    }
    LQ_Sqrt_Value = LQ_SQRT_U64_ROOT(((LQ_UI_64BIT)A) << 23, (LQ_UI_64BIT)Error_Range);
    return (LQ_INT32_Q)LQ_Sqrt_Value;
}
/**@brief LQ_INT32_Q22 开根 牛顿迭代法
* @details 采用牛顿迭代法进行开跟，相邻两次估计之差小于Error_Range时提前结束
* @param[in] LQ_INT32_Q22     A              输入Q格式数
* @param[in] LQ_INT32_Q22     Error_Range    迭代误差范围
* @param[in] LQ_ERROR*      Lq_Error         错误变量
* @return    sqrtA的值
* @exception NSExceptio: LQ_INT32_Q22_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE 错误:输入数值是负数\n
*                        LQ_INT32_Q22_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW  错误:精度范围太低，无差异性
* @par       计算sqrt(A)的值
* @code
*    LQ_INT32_Q22_SQRT_NEWTON_ITERATION(A, Error_Range, &lq_error);
* @endcode
* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
*/
LQ_INT32_Q LQ_INT32_Q22_SQRT_NEWTON_ITERATION(LQ_INT32_Q22 A, LQ_INT32_Q22 Error_Range, LQ_ERROR* Lq_Error)
{
    LQ_UI_64BIT LQ_Sqrt_Value;
    if (A < 0)
    {
        (*Lq_Error) = LQ_INT32_Q22_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE;
        return 0;
    }
    if (Error_Range <= 0)
    {
        (*Lq_Error) = LQ_INT32_Q22_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW;
        return 0;
    }
    LQ_Sqrt_Value = LQ_SQRT_U64_ROOT(((LQ_UI_64BIT)A) << 22, (LQ_UI_64BIT)Error_Range);
    return (LQ_INT32_Q)LQ_Sqrt_Value;
}
/**@brief LQ_INT32_Q21 开根 牛顿迭代法
* @details 采用牛顿迭代法进行开跟，相邻两次估计之差小于Error_Range时提前结束
* @param[in] LQ_INT32_Q21     A              输入Q格式数
* @param[in] LQ_INT32_Q21     Error_Range    迭代误差范围
* @param[in] LQ_ERROR*      Lq_Error         错误变量
* @return    sqrtA的值
* @exception NSExceptio: LQ_INT32_Q21_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE 错误:输入数值是负数\n
*                        LQ_INT32_Q21_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW  错误:精度范围太低，无差异性
* @par       计算sqrt(A)的值
* @code
*    LQ_INT32_Q21_SQRT_NEWTON_ITERATION(A, Error_Range, &lq_error);
* @endcode
* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
*/
LQ_INT32_Q LQ_INT32_Q21_SQRT_NEWTON_ITERATION(LQ_INT32_Q21 A, LQ_INT32_Q21 Error_Range, LQ_ERROR* Lq_Error)
{
    LQ_UI_64BIT LQ_Sqrt_Value;
    if (A < 0)
    {
        (*Lq_Error) = LQ_INT32_Q21_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE;
        return 0;
    }
    if (Error_Range <= 0)
    {
        (*Lq_Error) = LQ_INT32_Q21_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW;
        return 0;
    }
    LQ_Sqrt_Value = LQ_SQRT_U64_ROOT(((LQ_UI_64BIT)A) << 21, (LQ_UI_64BIT)Error_Range);
    return (LQ_INT32_Q)LQ_Sqrt_Value;
}
/**@brief LQ_INT32_Q20 开根 牛顿迭代法
* @details 采用牛顿迭代法进行开跟，相邻两次估计之差小于Error_Range时提前结束
* @param[in] LQ_INT32_Q20     A              输入Q格式数
* @param[in] LQ_INT32_Q20     Error_Range    迭代误差范围
* @param[in] LQ_ERROR*      Lq_Error         错误变量
* @return    sqrtA的值
* @exception NSExceptio: LQ_INT32_Q20_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE 错误:输入数值是负数\n
*                        LQ_INT32_Q20_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW  错误:精度范围太低，无差异性
* @par       计算sqrt(A)的值
* @code
*    LQ_INT32_Q20_SQRT_NEWTON_ITERATION(A, Error_Range, &lq_error);
* @endcode
* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
*/
LQ_INT32_Q LQ_INT32_Q20_SQRT_NEWTON_ITERATION(LQ_INT32_Q20 A, LQ_INT32_Q20 Error_Range, LQ_ERROR* Lq_Error)
{
    LQ_UI_64BIT LQ_Sqrt_Value;
    if (A < 0)
    {
        (*Lq_Error) = LQ_INT32_Q20_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE;
        return 0;
    }
    if (Error_Range <= 0)
    {
        (*Lq_Error) = LQ_INT32_Q20_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW;
        return 0;
    }
    LQ_Sqrt_Value = LQ_SQRT_U64_ROOT(((LQ_UI_64BIT)A) << 20, (LQ_UI_64BIT)Error_Range);
    return (LQ_INT32_Q)LQ_Sqrt_Value;
}
/**@brief LQ_INT32_Q19 开根 牛顿迭代法
* @details 采用牛顿迭代法进行开跟，相邻两次估计之差小于Error_Range时提前结束
* @param[in] LQ_INT32_Q19     A              输入Q格式数
* @param[in] LQ_INT32_Q19     Error_Range    迭代误差范围
* @param[in] LQ_ERROR*      Lq_Error         错误变量
* @return    sqrtA的值
* @exception NSExceptio: LQ_INT32_Q19_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE 错误:输入数值是负数\n
*                        LQ_INT32_Q19_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW  错误:精度范围太低，无差异性
* @par       计算sqrt(A)的值
* @code
*    LQ_INT32_Q19_SQRT_NEWTON_ITERATION(A, Error_Range, &lq_error);
* @endcode
* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
*/
LQ_INT32_Q LQ_INT32_Q19_SQRT_NEWTON_ITERATION(LQ_INT32_Q19 A, LQ_INT32_Q19 Error_Range, LQ_ERROR* Lq_Error)
{
    LQ_UI_64BIT LQ_Sqrt_Value;
    if (A < 0)
    {
        (*Lq_Error) = LQ_INT32_Q19_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE;
        return 0;
    }
    if (Error_Range <= 0)
    {
        (*Lq_Error) = LQ_INT32_Q19_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW;
        return 0;
    }
    LQ_Sqrt_Value = LQ_SQRT_U64_ROOT(((LQ_UI_64BIT)A) << 19, (LQ_UI_64BIT)Error_Range);
    return (LQ_INT32_Q)LQ_Sqrt_Value;
}
/**@brief LQ_INT32_Q18 开根 牛顿迭代法
* @details 采用牛顿迭代法进行开跟，相邻两次估计之差小于Error_Range时提前结束
* @param[in] LQ_INT32_Q18     A              输入Q格式数
* @param[in] LQ_INT32_Q18     Error_Range    迭代误差范围
* @param[in] LQ_ERROR*      Lq_Error         错误变量
* @return    sqrtA的值
* @exception NSExceptio: LQ_INT32_Q18_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE 错误:输入数值是负数\n
*                        LQ_INT32_Q18_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW  错误:精度范围太低，无差异性
* @par       计算sqrt(A)的值
* @code
*    LQ_INT32_Q18_SQRT_NEWTON_ITERATION(A, Error_Range, &lq_error);
* @endcode
* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
*/
LQ_INT32_Q LQ_INT32_Q18_SQRT_NEWTON_ITERATION(LQ_INT32_Q18 A, LQ_INT32_Q18 Error_Range, LQ_ERROR* Lq_Error)
{
    LQ_UI_64BIT LQ_Sqrt_Value;
    if (A < 0)
    {
        (*Lq_Error) = LQ_INT32_Q18_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE;
        return 0;
    }
    if (Error_Range <= 0)
    {
        (*Lq_Error) = LQ_INT32_Q18_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW;
        return 0;
    }
    LQ_Sqrt_Value = LQ_SQRT_U64_ROOT(((LQ_UI_64BIT)A) << 18, (LQ_UI_64BIT)Error_Range);
    return (LQ_INT32_Q)LQ_Sqrt_Value;
}
/**@brief LQ_INT32_Q17 开根 牛顿迭代法
* @details 采用牛顿迭代法进行开跟，相邻两次估计之差小于Error_Range时提前结束
* @param[in] LQ_INT32_Q17     A              输入Q格式数
* @param[in] LQ_INT32_Q17     Error_Range    迭代误差范围
* @param[in] LQ_ERROR*      Lq_Error         错误变量
* @return    sqrtA的值
* @exception NSExceptio: LQ_INT32_Q17_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE 错误:输入数值是负数\n
*                        LQ_INT32_Q17_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW  错误:精度范围太低，无差异性
* @par       计算sqrt(A)的值
* @code
*    LQ_INT32_Q17_SQRT_NEWTON_ITERATION(A, Error_Range, &lq_error);
* @endcode
* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
*/
LQ_INT32_Q LQ_INT32_Q17_SQRT_NEWTON_ITERATION(LQ_INT32_Q17 A, LQ_INT32_Q17 Error_Range, LQ_ERROR* Lq_Error)
{
    LQ_UI_64BIT LQ_Sqrt_Value;
    if (A < 0)
    {
        (*Lq_Error) = LQ_INT32_Q17_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE;
        return 0;
    }
    if (Error_Range <= 0)
    {
        (*Lq_Error) = LQ_INT32_Q17_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW;
        return 0;
    }
    LQ_Sqrt_Value = LQ_SQRT_U64_ROOT(((LQ_UI_64BIT)A) << 17, (LQ_UI_64BIT)Error_Range);
    return (LQ_INT32_Q)LQ_Sqrt_Value;
}
/**@brief LQ_INT32_Q16 开根 牛顿迭代法
* @details 采用牛顿迭代法进行开跟，相邻两次估计之差小于Error_Range时提前结束
* @param[in] LQ_INT32_Q16     A              输入Q格式数
* @param[in] LQ_INT32_Q16     Error_Range    迭代误差范围
* @param[in] LQ_ERROR*      Lq_Error         错误变量
* @return    sqrtA的值
* @exception NSExceptio: LQ_INT32_Q16_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE 错误:输入数值是负数\n
*                        LQ_INT32_Q16_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW  错误:精度范围太低，无差异性
* @par       计算sqrt(A)的值
* @code
*    LQ_INT32_Q16_SQRT_NEWTON_ITERATION(A, Error_Range, &lq_error);
* @endcode
* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
*/
LQ_INT32_Q LQ_INT32_Q16_SQRT_NEWTON_ITERATION(LQ_INT32_Q16 A, LQ_INT32_Q16 Error_Range, LQ_ERROR* Lq_Error)
{
    LQ_UI_64BIT LQ_Sqrt_Value;
    if (A < 0)
    {
        (*Lq_Error) = LQ_INT32_Q16_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE;
        return 0;
    }
    if (Error_Range <= 0)
    {
        (*Lq_Error) = LQ_INT32_Q16_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW;
        return 0;
    }
    LQ_Sqrt_Value = LQ_SQRT_U64_ROOT(((LQ_UI_64BIT)A) << 16, (LQ_UI_64BIT)Error_Range);
    return (LQ_INT32_Q)LQ_Sqrt_Value;
}
/**@brief LQ_INT32_Q15 开根 牛顿迭代法
* @details 采用牛顿迭代法进行开跟，相邻两次估计之差小于Error_Range时提前结束
* @param[in] LQ_INT32_Q15     A              输入Q格式数
* @param[in] LQ_INT32_Q15     Error_Range    迭代误差范围
* @param[in] LQ_ERROR*      Lq_Error         错误变量
* @return    sqrtA的值
* @exception NSExceptio: LQ_INT32_Q15_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE 错误:输入数值是负数\n
*                        LQ_INT32_Q15_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW  错误:精度范围太低，无差异性
* @par       计算sqrt(A)的值
* @code
*    LQ_INT32_Q15_SQRT_NEWTON_ITERATION(A, Error_Range, &lq_error);
* @endcode
* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
*/
LQ_INT32_Q LQ_INT32_Q15_SQRT_NEWTON_ITERATION(LQ_INT32_Q15 A, LQ_INT32_Q15 Error_Range, LQ_ERROR* Lq_Error)
{
    LQ_UI_64BIT LQ_Sqrt_Value;
    if (A < 0)
    {
        (*Lq_Error) = LQ_INT32_Q15_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE;
        return 0;
    }
    if (Error_Range <= 0)
    {
        (*Lq_Error) = LQ_INT32_Q15_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW;
        return 0;
    }
    LQ_Sqrt_Value = LQ_SQRT_U64_ROOT(((LQ_UI_64BIT)A) << 15, (LQ_UI_64BIT)Error_Range);
    return (LQ_INT32_Q)LQ_Sqrt_Value;
}
/**@brief LQ_INT32_Q14 开根 牛顿迭代法
* @details 采用牛顿迭代法进行开跟，相邻两次估计之差小于Error_Range时提前结束
* @param[in] LQ_INT32_Q14     A              输入Q格式数
* @param[in] LQ_INT32_Q14     Error_Range    迭代误差范围
* @param[in] LQ_ERROR*      Lq_Error         错误变量
* @return    sqrtA的值
* @exception NSExceptio: LQ_INT32_Q14_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE 错误:输入数值是负数\n
*                        LQ_INT32_Q14_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW  错误:精度范围太低，无差异性
* @par       计算sqrt(A)的值
* @code
*    LQ_INT32_Q14_SQRT_NEWTON_ITERATION(A, Error_Range, &lq_error);
* @endcode
* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
*/
LQ_INT32_Q LQ_INT32_Q14_SQRT_NEWTON_ITERATION(LQ_INT32_Q14 A, LQ_INT32_Q14 Error_Range, LQ_ERROR* Lq_Error)
{
    LQ_UI_64BIT LQ_Sqrt_Value;
    if (A < 0)
    {
        (*Lq_Error) = LQ_INT32_Q14_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE;
        return 0;
    }
    if (Error_Range <= 0)
    {
        (*Lq_Error) = LQ_INT32_Q14_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW;
        return 0;
    }
    LQ_Sqrt_Value = LQ_SQRT_U64_ROOT(((LQ_UI_64BIT)A) << 14, (LQ_UI_64BIT)Error_Range);
    return (LQ_INT32_Q)LQ_Sqrt_Value;
}
/**@brief LQ_INT32_Q13 开根 牛顿迭代法
* @details 采用牛顿迭代法进行开跟，相邻两次估计之差小于Error_Range时提前结束
* @param[in] LQ_INT32_Q13     A              输入Q格式数
* @param[in] LQ_INT32_Q13     Error_Range    迭代误差范围
* @param[in] LQ_ERROR*      Lq_Error         错误变量
* @return    sqrtA的值
* @exception NSExceptio: LQ_INT32_Q13_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE 错误:输入数值是负数\n
*                        LQ_INT32_Q13_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW  错误:精度范围太低，无差异性
* @par       计算sqrt(A)的值
* @code
*    LQ_INT32_Q13_SQRT_NEWTON_ITERATION(A, Error_Range, &lq_error);
* @endcode
* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
*/
LQ_INT32_Q LQ_INT32_Q13_SQRT_NEWTON_ITERATION(LQ_INT32_Q13 A, LQ_INT32_Q13 Error_Range, LQ_ERROR* Lq_Error)
{
    LQ_UI_64BIT LQ_Sqrt_Value;
    if (A < 0)
    {
        (*Lq_Error) = LQ_INT32_Q13_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE;
        return 0;
    }
    if (Error_Range <= 0)
    {
        (*Lq_Error) = LQ_INT32_Q13_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW;
        return 0;
    }
    LQ_Sqrt_Value = LQ_SQRT_U64_ROOT(((LQ_UI_64BIT)A) << 13, (LQ_UI_64BIT)Error_Range);
    return (LQ_INT32_Q)LQ_Sqrt_Value;
}
/**@brief LQ_INT32_Q12 开根 牛顿迭代法
* @details 采用牛顿迭代法进行开跟，相邻两次估计之差小于Error_Range时提前结束
* @param[in] LQ_INT32_Q12     A              输入Q格式数
* @param[in] LQ_INT32_Q12     Error_Range    迭代误差范围
* @param[in] LQ_ERROR*      Lq_Error         错误变量
* @return    sqrtA的值
* @exception NSExceptio: LQ_INT32_Q12_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE 错误:输入数值是负数\n
*                        LQ_INT32_Q12_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW  错误:精度范围太低，无差异性
* @par       计算sqrt(A)的值
* @code
*    LQ_INT32_Q12_SQRT_NEWTON_ITERATION(A, Error_Range, &lq_error);
* @endcode
* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
*/
LQ_INT32_Q LQ_INT32_Q12_SQRT_NEWTON_ITERATION(LQ_INT32_Q12 A, LQ_INT32_Q12 Error_Range, LQ_ERROR* Lq_Error)
{
    LQ_UI_64BIT LQ_Sqrt_Value;
    if (A < 0)
    {
        (*Lq_Error) = LQ_INT32_Q12_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE;
        return 0;
    }
    if (Error_Range <= 0)
    {
        (*Lq_Error) = LQ_INT32_Q12_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW;
        return 0;
    }
    LQ_Sqrt_Value = LQ_SQRT_U64_ROOT(((LQ_UI_64BIT)A) << 12, (LQ_UI_64BIT)Error_Range);
    return (LQ_INT32_Q)LQ_Sqrt_Value;
}
/**@brief LQ_INT32_Q11 开根 牛顿迭代法
* @details 采用牛顿迭代法进行开跟，相邻两次估计之差小于Error_Range时提前结束
* @param[in] LQ_INT32_Q11     A              输入Q格式数
* @param[in] LQ_INT32_Q11     Error_Range    迭代误差范围
* @param[in] LQ_ERROR*      Lq_Error         错误变量
* @return    sqrtA的值
* @exception NSExceptio: LQ_INT32_Q11_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE 错误:输入数值是负数\n
*                        LQ_INT32_Q11_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW  错误:精度范围太低，无差异性
* @par       计算sqrt(A)的值
* @code
*    LQ_INT32_Q11_SQRT_NEWTON_ITERATION(A, Error_Range, &lq_error);
* @endcode
* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
*/
LQ_INT32_Q LQ_INT32_Q11_SQRT_NEWTON_ITERATION(LQ_INT32_Q11 A, LQ_INT32_Q11 Error_Range, LQ_ERROR* Lq_Error)
{
    LQ_UI_64BIT LQ_Sqrt_Value;
    if (A < 0)
    {
        (*Lq_Error) = LQ_INT32_Q11_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE;
        return 0;
    }
    if (Error_Range <= 0)
    {
        (*Lq_Error) = LQ_INT32_Q11_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW;
        return 0;
    }
    LQ_Sqrt_Value = LQ_SQRT_U64_ROOT(((LQ_UI_64BIT)A) << 11, (LQ_UI_64BIT)Error_Range);
    return (LQ_INT32_Q)LQ_Sqrt_Value;
}
/**@brief LQ_INT32_Q10 开根 牛顿迭代法
* @details 采用牛顿迭代法进行开跟，相邻两次估计之差小于Error_Range时提前结束
* @param[in] LQ_INT32_Q10     A              输入Q格式数
* @param[in] LQ_INT32_Q10     Error_Range    迭代误差范围
* @param[in] LQ_ERROR*      Lq_Error         错误变量
* @return    sqrtA的值
* @exception NSExceptio: LQ_INT32_Q10_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE 错误:输入数值是负数\n
*                        LQ_INT32_Q10_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW  错误:精度范围太低，无差异性
* @par       计算sqrt(A)的值
* @code
*    LQ_INT32_Q10_SQRT_NEWTON_ITERATION(A, Error_Range, &lq_error);
* @endcode
* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
*/
LQ_INT32_Q LQ_INT32_Q10_SQRT_NEWTON_ITERATION(LQ_INT32_Q10 A, LQ_INT32_Q10 Error_Range, LQ_ERROR* Lq_Error)
{
    LQ_UI_64BIT LQ_Sqrt_Value;
    if (A < 0)
    {
        (*Lq_Error) = LQ_INT32_Q10_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE;
        return 0;
    }
    if (Error_Range <= 0)
    {
        (*Lq_Error) = LQ_INT32_Q10_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW;
        return 0;
    }
    LQ_Sqrt_Value = LQ_SQRT_U64_ROOT(((LQ_UI_64BIT)A) << 10, (LQ_UI_64BIT)Error_Range);
    return (LQ_INT32_Q)LQ_Sqrt_Value;
}
/**@brief LQ_INT32_Q9 开根 牛顿迭代法
* @details 采用牛顿迭代法进行开跟，相邻两次估计之差小于Error_Range时提前结束
* @param[in] LQ_INT32_Q9     A              输入Q格式数
* @param[in] LQ_INT32_Q9     Error_Range    迭代误差范围
* @param[in] LQ_ERROR*      Lq_Error         错误变量
* @return    sqrtA的值
* @exception NSExceptio: LQ_INT32_Q9_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE 错误:输入数值是负数\n
*                        LQ_INT32_Q9_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW  错误:精度范围太低，无差异性
* @par       计算sqrt(A)的值
* @code
*    LQ_INT32_Q9_SQRT_NEWTON_ITERATION(A, Error_Range, &lq_error);
* @endcode
* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
*/
LQ_INT32_Q LQ_INT32_Q9_SQRT_NEWTON_ITERATION(LQ_INT32_Q9 A, LQ_INT32_Q9 Error_Range, LQ_ERROR* Lq_Error)
{
    LQ_UI_64BIT LQ_Sqrt_Value;
    if (A < 0)
    {
        (*Lq_Error) = LQ_INT32_Q9_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE;
        return 0;
    }
    if (Error_Range <= 0)
    {
        (*Lq_Error) = LQ_INT32_Q9_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW;
        return 0;
    }
    LQ_Sqrt_Value = LQ_SQRT_U64_ROOT(((LQ_UI_64BIT)A) << 9, (LQ_UI_64BIT)Error_Range);
    return (LQ_INT32_Q)LQ_Sqrt_Value;
}
/**@brief LQ_INT32_Q8 开根 牛顿迭代法
* @details 采用牛顿迭代法进行开跟，相邻两次估计之差小于Error_Range时提前结束
* @param[in] LQ_INT32_Q8     A              输入Q格式数
* @param[in] LQ_INT32_Q8     Error_Range    迭代误差范围
* @param[in] LQ_ERROR*      Lq_Error         错误变量
* @return    sqrtA的值
* @exception NSExceptio: LQ_INT32_Q8_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE 错误:输入数值是负数\n
*                        LQ_INT32_Q8_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW  错误:精度范围太低，无差异性
* @par       计算sqrt(A)的值
* @code
*    LQ_INT32_Q8_SQRT_NEWTON_ITERATION(A, Error_Range, &lq_error);
* @endcode
* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
*/
LQ_INT32_Q LQ_INT32_Q8_SQRT_NEWTON_ITERATION(LQ_INT32_Q8 A, LQ_INT32_Q8 Error_Range, LQ_ERROR* Lq_Error)
{
    LQ_UI_64BIT LQ_Sqrt_Value;
    if (A < 0)
    {
        (*Lq_Error) = LQ_INT32_Q8_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE;
        return 0;
    }
    if (Error_Range <= 0)
    {
        (*Lq_Error) = LQ_INT32_Q8_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW;
        return 0;
    }
    LQ_Sqrt_Value = LQ_SQRT_U64_ROOT(((LQ_UI_64BIT)A) << 8, (LQ_UI_64BIT)Error_Range);
    return (LQ_INT32_Q)LQ_Sqrt_Value;
}
/**@brief LQ_INT32_Q7 开根 牛顿迭代法
* @details 采用牛顿迭代法进行开跟，相邻两次估计之差小于Error_Range时提前结束
* @param[in] LQ_INT32_Q7     A              输入Q格式数
* @param[in] LQ_INT32_Q7     Error_Range    迭代误差范围
* @param[in] LQ_ERROR*      Lq_Error         错误变量
* @return    sqrtA的值
* @exception NSExceptio: LQ_INT32_Q7_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE 错误:输入数值是负数\n
*                        LQ_INT32_Q7_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW  错误:精度范围太低，无差异性
* @par       计算sqrt(A)的值
* @code
*    LQ_INT32_Q7_SQRT_NEWTON_ITERATION(A, Error_Range, &lq_error);
* @endcode
* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
*/
LQ_INT32_Q LQ_INT32_Q7_SQRT_NEWTON_ITERATION(LQ_INT32_Q7 A, LQ_INT32_Q7 Error_Range, LQ_ERROR* Lq_Error)
{
    LQ_UI_64BIT LQ_Sqrt_Value;
    if (A < 0)
    {
        (*Lq_Error) = LQ_INT32_Q7_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE;
        return 0;
    }
    if (Error_Range <= 0)
    {
        (*Lq_Error) = LQ_INT32_Q7_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW;
        return 0;
    }
    LQ_Sqrt_Value = LQ_SQRT_U64_ROOT(((LQ_UI_64BIT)A) << 7, (LQ_UI_64BIT)Error_Range);
    return (LQ_INT32_Q)LQ_Sqrt_Value;
}
/**@brief LQ_INT32_Q6 开根 牛顿迭代法
* @details 采用牛顿迭代法进行开跟，相邻两次估计之差小于Error_Range时提前结束
* @param[in] LQ_INT32_Q6     A              输入Q格式数
* @param[in] LQ_INT32_Q6     Error_Range    迭代误差范围
* @param[in] LQ_ERROR*      Lq_Error         错误变量
* @return    sqrtA的值
* @exception NSExceptio: LQ_INT32_Q6_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE 错误:输入数值是负数\n
*                        LQ_INT32_Q6_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW  错误:精度范围太低，无差异性
* @par       计算sqrt(A)的值
* @code
*    LQ_INT32_Q6_SQRT_NEWTON_ITERATION(A, Error_Range, &lq_error);
* @endcode
* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
*/
LQ_INT32_Q LQ_INT32_Q6_SQRT_NEWTON_ITERATION(LQ_INT32_Q6 A, LQ_INT32_Q6 Error_Range, LQ_ERROR* Lq_Error)
{
    LQ_UI_64BIT LQ_Sqrt_Value;
    if (A < 0)
    {
        (*Lq_Error) = LQ_INT32_Q6_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE;
        return 0;
    }
    if (Error_Range <= 0)
    {
        (*Lq_Error) = LQ_INT32_Q6_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW;
        return 0;
    }
    LQ_Sqrt_Value = LQ_SQRT_U64_ROOT(((LQ_UI_64BIT)A) << 6, (LQ_UI_64BIT)Error_Range);
    return (LQ_INT32_Q)LQ_Sqrt_Value;
}
/**@brief LQ_INT32_Q5 开根 牛顿迭代法
* @details 采用牛顿迭代法进行开跟，相邻两次估计之差小于Error_Range时提前结束
* @param[in] LQ_INT32_Q5     A              输入Q格式数
* @param[in] LQ_INT32_Q5     Error_Range    迭代误差范围
* @param[in] LQ_ERROR*      Lq_Error         错误变量
* @return    sqrtA的值
* @exception NSExceptio: LQ_INT32_Q5_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE 错误:输入数值是负数\n
*                        LQ_INT32_Q5_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW  错误:精度范围太低，无差异性
* @par       计算sqrt(A)的值
* @code
*    LQ_INT32_Q5_SQRT_NEWTON_ITERATION(A, Error_Range, &lq_error);
* @endcode
* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
*/
LQ_INT32_Q LQ_INT32_Q5_SQRT_NEWTON_ITERATION(LQ_INT32_Q5 A, LQ_INT32_Q5 Error_Range, LQ_ERROR* Lq_Error)
{
    LQ_UI_64BIT LQ_Sqrt_Value;
    if (A < 0)
    {
        (*Lq_Error) = LQ_INT32_Q5_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE;
        return 0;
    }
    if (Error_Range <= 0)
    {
        (*Lq_Error) = LQ_INT32_Q5_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW;
        return 0;
    }
    LQ_Sqrt_Value = LQ_SQRT_U64_ROOT(((LQ_UI_64BIT)A) << 5, (LQ_UI_64BIT)Error_Range);
    return (LQ_INT32_Q)LQ_Sqrt_Value;
}
/**@brief LQ_INT32_Q4 开根 牛顿迭代法
* @details 采用牛顿迭代法进行开跟，相邻两次估计之差小于Error_Range时提前结束
* @param[in] LQ_INT32_Q4     A              输入Q格式数
* @param[in] LQ_INT32_Q4     Error_Range    迭代误差范围
* @param[in] LQ_ERROR*      Lq_Error         错误变量
* @return    sqrtA的值
* @exception NSExceptio: LQ_INT32_Q4_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE 错误:输入数值是负数\n
*                        LQ_INT32_Q4_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW  错误:精度范围太低，无差异性
* @par       计算sqrt(A)的值
* @code
*    LQ_INT32_Q4_SQRT_NEWTON_ITERATION(A, Error_Range, &lq_error);
* @endcode
* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
*/
LQ_INT32_Q LQ_INT32_Q4_SQRT_NEWTON_ITERATION(LQ_INT32_Q4 A, LQ_INT32_Q4 Error_Range, LQ_ERROR* Lq_Error)
{
    LQ_UI_64BIT LQ_Sqrt_Value;
    if (A < 0)
    {
        (*Lq_Error) = LQ_INT32_Q4_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE;
        return 0;
    }
    if (Error_Range <= 0)
    {
        (*Lq_Error) = LQ_INT32_Q4_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW;
        return 0;
    }
    LQ_Sqrt_Value = LQ_SQRT_U64_ROOT(((LQ_UI_64BIT)A) << 4, (LQ_UI_64BIT)Error_Range);
    return (LQ_INT32_Q)LQ_Sqrt_Value;
}
/**@brief LQ_INT32_Q3 开根 牛顿迭代法
* @details 采用牛顿迭代法进行开跟，相邻两次估计之差小于Error_Range时提前结束
* @param[in] LQ_INT32_Q3     A              输入Q格式数
* @param[in] LQ_INT32_Q3     Error_Range    迭代误差范围
* @param[in] LQ_ERROR*      Lq_Error         错误变量
* @return    sqrtA的值
* @exception NSExceptio: LQ_INT32_Q3_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE 错误:输入数值是负数\n
*                        LQ_INT32_Q3_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW  错误:精度范围太低，无差异性
* @par       计算sqrt(A)的值
* @code
*    LQ_INT32_Q3_SQRT_NEWTON_ITERATION(A, Error_Range, &lq_error);
* @endcode
* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
*/
LQ_INT32_Q LQ_INT32_Q3_SQRT_NEWTON_ITERATION(LQ_INT32_Q3 A, LQ_INT32_Q3 Error_Range, LQ_ERROR* Lq_Error)
{
    LQ_UI_64BIT LQ_Sqrt_Value;
    if (A < 0)
    {
        (*Lq_Error) = LQ_INT32_Q3_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE;
        return 0;
    }
    if (Error_Range <= 0)
    {
        (*Lq_Error) = LQ_INT32_Q3_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW;
        return 0;
    }
    LQ_Sqrt_Value = LQ_SQRT_U64_ROOT(((LQ_UI_64BIT)A) << 3, (LQ_UI_64BIT)Error_Range);
    return (LQ_INT32_Q)LQ_Sqrt_Value;
}
/**@brief LQ_INT32_Q2 开根 牛顿迭代法
* @details 采用牛顿迭代法进行开跟，相邻两次估计之差小于Error_Range时提前结束
* @param[in] LQ_INT32_Q2     A              输入Q格式数
* @param[in] LQ_INT32_Q2     Error_Range    迭代误差范围
* @param[in] LQ_ERROR*      Lq_Error         错误变量
* @return    sqrtA的值
* @exception NSExceptio: LQ_INT32_Q2_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE 错误:输入数值是负数\n
*                        LQ_INT32_Q2_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW  错误:精度范围太低，无差异性
* @par       计算sqrt(A)的值
* @code
*    LQ_INT32_Q2_SQRT_NEWTON_ITERATION(A, Error_Range, &lq_error);
* @endcode
* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
*/
LQ_INT32_Q LQ_INT32_Q2_SQRT_NEWTON_ITERATION(LQ_INT32_Q2 A, LQ_INT32_Q2 Error_Range, LQ_ERROR* Lq_Error)
{
    LQ_UI_64BIT LQ_Sqrt_Value;
    if (A < 0)
    {
        (*Lq_Error) = LQ_INT32_Q2_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE;
        return 0;
    }
    if (Error_Range <= 0)
    {
        (*Lq_Error) = LQ_INT32_Q2_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW;
        return 0;
    }
    LQ_Sqrt_Value = LQ_SQRT_U64_ROOT(((LQ_UI_64BIT)A) << 2, (LQ_UI_64BIT)Error_Range);
    return (LQ_INT32_Q)LQ_Sqrt_Value;
}
/**@brief LQ_INT32_Q1 开根 牛顿迭代法
* @details 采用牛顿迭代法进行开跟，相邻两次估计之差小于Error_Range时提前结束
* @param[in] LQ_INT32_Q1     A              输入Q格式数
* @param[in] LQ_INT32_Q1     Error_Range    迭代误差范围
* @param[in] LQ_ERROR*      Lq_Error         错误变量
* @return    sqrtA的值
* @exception NSExceptio: LQ_INT32_Q1_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE 错误:输入数值是负数\n
*                        LQ_INT32_Q1_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW  错误:精度范围太低，无差异性
* @par       计算sqrt(A)的值
* @code
*    LQ_INT32_Q1_SQRT_NEWTON_ITERATION(A, Error_Range, &lq_error);
* @endcode
* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
*/
LQ_INT32_Q LQ_INT32_Q1_SQRT_NEWTON_ITERATION(LQ_INT32_Q1 A, LQ_INT32_Q1 Error_Range, LQ_ERROR* Lq_Error)
{
    LQ_UI_64BIT LQ_Sqrt_Value;
    if (A < 0)
    {
        (*Lq_Error) = LQ_INT32_Q1_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE;
        return 0;
    }
    if (Error_Range <= 0)
    {
        (*Lq_Error) = LQ_INT32_Q1_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW;
        return 0;
    }
    LQ_Sqrt_Value = LQ_SQRT_U64_ROOT(((LQ_UI_64BIT)A) << 1, (LQ_UI_64BIT)Error_Range);
    return (LQ_INT32_Q)LQ_Sqrt_Value;
}
/**@brief LQ_UINT32_UQ32 开根 牛顿迭代法
* @details 采用牛顿迭代法进行开跟，相邻两次估计之差小于Error_Range时提前结束
* @param[in] LQ_UINT32_UQ32     A              输入UQ格式数
* @param[in] LQ_UINT32_UQ32     Error_Range    迭代误差范围
* @param[in] LQ_ERROR*      Lq_Error         错误变量
* @return    sqrtA的值
* @exception NSExceptio: LQ_UINT32_UQ32_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE 错误:输入数值是负数\n
*                        LQ_UINT32_UQ32_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW  错误:精度范围太低，无差异性
* @par       计算sqrt(A)的值
* @code
*    LQ_UINT32_UQ32_SQRT_NEWTON_ITERATION(A, Error_Range, &lq_error);
* @endcode
* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
*/
LQ_UINT32_UQ LQ_UINT32_UQ32_SQRT_NEWTON_ITERATION(LQ_UINT32_UQ32 A, LQ_UINT32_UQ32 Error_Range, LQ_ERROR* Lq_Error)
{
    LQ_UI_64BIT LQ_Sqrt_Value;
    if (Error_Range == 0)
    {
        (*Lq_Error) = LQ_UINT32_UQ32_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW;
        return 0;
    }
    LQ_Sqrt_Value = LQ_SQRT_U64_ROOT(((LQ_UI_64BIT)A) << 32, (LQ_UI_64BIT)Error_Range);
    return (LQ_UINT32_UQ)LQ_Sqrt_Value;
}
/**@brief LQ_UINT32_UQ31 开根 牛顿迭代法
* @details 采用牛顿迭代法进行开跟，相邻两次估计之差小于Error_Range时提前结束
* @param[in] LQ_UINT32_UQ31     A              输入UQ格式数
* @param[in] LQ_UINT32_UQ31     Error_Range    迭代误差范围
* @param[in] LQ_ERROR*      Lq_Error         错误变量
* @return    sqrtA的值
* @exception NSExceptio: LQ_UINT32_UQ31_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE 错误:输入数值是负数\n
*                        LQ_UINT32_UQ31_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW  错误:精度范围太低，无差异性
* @par       计算sqrt(A)的值
* @code
*    LQ_UINT32_UQ31_SQRT_NEWTON_ITERATION(A, Error_Range, &lq_error);
* @endcode
* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
*/
LQ_UINT32_UQ LQ_UINT32_UQ31_SQRT_NEWTON_ITERATION(LQ_UINT32_UQ31 A, LQ_UINT32_UQ31 Error_Range, LQ_ERROR* Lq_Error)
{
    LQ_UI_64BIT LQ_Sqrt_Value;
    if (Error_Range == 0)
    {
        (*Lq_Error) = LQ_UINT32_UQ31_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW;
        return 0;
    }
    LQ_Sqrt_Value = LQ_SQRT_U64_ROOT(((LQ_UI_64BIT)A) << 31, (LQ_UI_64BIT)Error_Range);
    return (LQ_UINT32_UQ)LQ_Sqrt_Value;
}
/**@brief LQ_UINT32_UQ30 开根 牛顿迭代法
* @details 采用牛顿迭代法进行开跟，相邻两次估计之差小于Error_Range时提前结束
* @param[in] LQ_UINT32_UQ30     A              输入UQ格式数
* @param[in] LQ_UINT32_UQ30     Error_Range    迭代误差范围
* @param[in] LQ_ERROR*      Lq_Error         错误变量
* @return    sqrtA的值
* @exception NSExceptio: LQ_UINT32_UQ30_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE 错误:输入数值是负数\n
*                        LQ_UINT32_UQ30_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW  错误:精度范围太低，无差异性
* @par       计算sqrt(A)的值
* @code
*    LQ_UINT32_UQ30_SQRT_NEWTON_ITERATION(A, Error_Range, &lq_error);
* @endcode
* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
*/
LQ_UINT32_UQ LQ_UINT32_UQ30_SQRT_NEWTON_ITERATION(LQ_UINT32_UQ30 A, LQ_UINT32_UQ30 Error_Range, LQ_ERROR* Lq_Error)
{
    LQ_UI_64BIT LQ_Sqrt_Value;
    if (Error_Range == 0)
    {
        (*Lq_Error) = LQ_UINT32_UQ30_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW;
        return 0;
    }
    LQ_Sqrt_Value = LQ_SQRT_U64_ROOT(((LQ_UI_64BIT)A) << 30, (LQ_UI_64BIT)Error_Range);
    return (LQ_UINT32_UQ)LQ_Sqrt_Value;
}
/**@brief LQ_UINT32_UQ29 开根 牛顿迭代法
* @details 采用牛顿迭代法进行开跟，相邻两次估计之差小于Error_Range时提前结束
* @param[in] LQ_UINT32_UQ29     A              输入UQ格式数
* @param[in] LQ_UINT32_UQ29     Error_Range    迭代误差范围
* @param[in] LQ_ERROR*      Lq_Error         错误变量
* @return    sqrtA的值
* @exception NSExceptio: LQ_UINT32_UQ29_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE 错误:输入数值是负数\n
*                        LQ_UINT32_UQ29_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW  错误:精度范围太低，无差异性
* @par       计算sqrt(A)的值
* @code
*    LQ_UINT32_UQ29_SQRT_NEWTON_ITERATION(A, Error_Range, &lq_error);
* @endcode
* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
*/
LQ_UINT32_UQ LQ_UINT32_UQ29_SQRT_NEWTON_ITERATION(LQ_UINT32_UQ29 A, LQ_UINT32_UQ29 Error_Range, LQ_ERROR* Lq_Error)
{
    LQ_UI_64BIT LQ_Sqrt_Value;
    if (Error_Range == 0)
    {
        (*Lq_Error) = LQ_UINT32_UQ29_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW;
        return 0;
    }
    LQ_Sqrt_Value = LQ_SQRT_U64_ROOT(((LQ_UI_64BIT)A) << 29, (LQ_UI_64BIT)Error_Range);
    return (LQ_UINT32_UQ)LQ_Sqrt_Value;
}
/**@brief LQ_UINT32_UQ28 开根 牛顿迭代法
* @details 采用牛顿迭代法进行开跟，相邻两次估计之差小于Error_Range时提前结束
* @param[in] LQ_UINT32_UQ28     A              输入UQ格式数
* @param[in] LQ_UINT32_UQ28     Error_Range    迭代误差范围
* @param[in] LQ_ERROR*      Lq_Error         错误变量
* @return    sqrtA的值
* @exception NSExceptio: LQ_UINT32_UQ28_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE 错误:输入数值是负数\n
*                        LQ_UINT32_UQ28_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW  错误:精度范围太低，无差异性
* @par       计算sqrt(A)的值
* @code
*    LQ_UINT32_UQ28_SQRT_NEWTON_ITERATION(A, Error_Range, &lq_error);
* @endcode
* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
*/
LQ_UINT32_UQ LQ_UINT32_UQ28_SQRT_NEWTON_ITERATION(LQ_UINT32_UQ28 A, LQ_UINT32_UQ28 Error_Range, LQ_ERROR* Lq_Error)
{
    LQ_UI_64BIT LQ_Sqrt_Value;
    if (Error_Range == 0)
    {
        (*Lq_Error) = LQ_UINT32_UQ28_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW;
        return 0;
    }
    LQ_Sqrt_Value = LQ_SQRT_U64_ROOT(((LQ_UI_64BIT)A) << 28, (LQ_UI_64BIT)Error_Range);
    return (LQ_UINT32_UQ)LQ_Sqrt_Value;
}
/**@brief LQ_UINT32_UQ27 开根 牛顿迭代法
* @details 采用牛顿迭代法进行开跟，相邻两次估计之差小于Error_Range时提前结束
* @param[in] LQ_UINT32_UQ27     A              输入UQ格式数
* @param[in] LQ_UINT32_UQ27     Error_Range    迭代误差范围
* @param[in] LQ_ERROR*      Lq_Error         错误变量
* @return    sqrtA的值
* @exception NSExceptio: LQ_UINT32_UQ27_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE 错误:输入数值是负数\n
*                        LQ_UINT32_UQ27_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW  错误:精度范围太低，无差异性
* @par       计算sqrt(A)的值
* @code
*    LQ_UINT32_UQ27_SQRT_NEWTON_ITERATION(A, Error_Range, &lq_error);
* @endcode
* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
*/
LQ_UINT32_UQ LQ_UINT32_UQ27_SQRT_NEWTON_ITERATION(LQ_UINT32_UQ27 A, LQ_UINT32_UQ27 Error_Range, LQ_ERROR* Lq_Error)
{
    LQ_UI_64BIT LQ_Sqrt_Value;
    if (Error_Range == 0)
    {
        (*Lq_Error) = LQ_UINT32_UQ27_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW;
        return 0;
    }
    LQ_Sqrt_Value = LQ_SQRT_U64_ROOT(((LQ_UI_64BIT)A) << 27, (LQ_UI_64BIT)Error_Range);
    return (LQ_UINT32_UQ)LQ_Sqrt_Value;
}
/**@brief LQ_UINT32_UQ26 开根 牛顿迭代法
* @details 采用牛顿迭代法进行开跟，相邻两次估计之差小于Error_Range时提前结束
* @param[in] LQ_UINT32_UQ26     A              输入UQ格式数
* @param[in] LQ_UINT32_UQ26     Error_Range    迭代误差范围
* @param[in] LQ_ERROR*      Lq_Error         错误变量
* @return    sqrtA的值
* @exception NSExceptio: LQ_UINT32_UQ26_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE 错误:输入数值是负数\n
*                        LQ_UINT32_UQ26_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW  错误:精度范围太低，无差异性
* @par       计算sqrt(A)的值
* @code
*    LQ_UINT32_UQ26_SQRT_NEWTON_ITERATION(A, Error_Range, &lq_error);
* @endcode
* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
*/
LQ_UINT32_UQ LQ_UINT32_UQ26_SQRT_NEWTON_ITERATION(LQ_UINT32_UQ26 A, LQ_UINT32_UQ26 Error_Range, LQ_ERROR* Lq_Error)
{
    LQ_UI_64BIT LQ_Sqrt_Value;
    if (Error_Range == 0)
    {
        (*Lq_Error) = LQ_UINT32_UQ26_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW;
        return 0;
    }
    LQ_Sqrt_Value = LQ_SQRT_U64_ROOT(((LQ_UI_64BIT)A) << 26, (LQ_UI_64BIT)Error_Range);
    return (LQ_UINT32_UQ)LQ_Sqrt_Value;
}
/**@brief LQ_UINT32_UQ25 开根 牛顿迭代法
* @details 采用牛顿迭代法进行开跟，相邻两次估计之差小于Error_Range时提前结束
* @param[in] LQ_UINT32_UQ25     A              输入UQ格式数
* @param[in] LQ_UINT32_UQ25     Error_Range    迭代误差范围
* @param[in] LQ_ERROR*      Lq_Error         错误变量
* @return    sqrtA的值
* @exception NSExceptio: LQ_UINT32_UQ25_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE 错误:输入数值是负数\n
*                        LQ_UINT32_UQ25_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW  错误:精度范围太低，无差异性
* @par       计算sqrt(A)的值
* @code
*    LQ_UINT32_UQ25_SQRT_NEWTON_ITERATION(A, Error_Range, &lq_error);
* @endcode
* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
*/
LQ_UINT32_UQ LQ_UINT32_UQ25_SQRT_NEWTON_ITERATION(LQ_UINT32_UQ25 A, LQ_UINT32_UQ25 Error_Range, LQ_ERROR* Lq_Error)
{
    LQ_UI_64BIT LQ_Sqrt_Value;
    if (Error_Range == 0)
    {
        (*Lq_Error) = LQ_UINT32_UQ25_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW;
        return 0;
    }
    LQ_Sqrt_Value = LQ_SQRT_U64_ROOT(((LQ_UI_64BIT)A) << 25, (LQ_UI_64BIT)Error_Range);
    return (LQ_UINT32_UQ)LQ_Sqrt_Value;
}
/**@brief LQ_UINT32_UQ24 开根 牛顿迭代法
* @details 采用牛顿迭代法进行开跟，相邻两次估计之差小于Error_Range时提前结束
* @param[in] LQ_UINT32_UQ24     A              输入UQ格式数
* @param[in] LQ_UINT32_UQ24     Error_Range    迭代误差范围
* @param[in] LQ_ERROR*      Lq_Error         错误变量
* @return    sqrtA的值
* @exception NSExceptio: LQ_UINT32_UQ24_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE 错误:输入数值是负数\n
*                        LQ_UINT32_UQ24_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW  错误:精度范围太低，无差异性
* @par       计算sqrt(A)的值
* @code
*    LQ_UINT32_UQ24_SQRT_NEWTON_ITERATION(A, Error_Range, &lq_error);
* @endcode
* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
*/
LQ_UINT32_UQ LQ_UINT32_UQ24_SQRT_NEWTON_ITERATION(LQ_UINT32_UQ24 A, LQ_UINT32_UQ24 Error_Range, LQ_ERROR* Lq_Error)
{
    LQ_UI_64BIT LQ_Sqrt_Value;
    if (Error_Range == 0)
    {
        (*Lq_Error) = LQ_UINT32_UQ24_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW;
        return 0;
    }
    LQ_Sqrt_Value = LQ_SQRT_U64_ROOT(((LQ_UI_64BIT)A) << 24, (LQ_UI_64BIT)Error_Range);
    return (LQ_UINT32_UQ)LQ_Sqrt_Value;
}
/**@brief LQ_UINT32_UQ23 开根 牛顿迭代法
* @details 采用牛顿迭代法进行开跟，相邻两次估计之差小于Error_Range时提前结束
* @param[in] LQ_UINT32_UQ23     A              输入UQ格式数
* @param[in] LQ_UINT32_UQ23     Error_Range    迭代误差范围
* @param[in] LQ_ERROR*      Lq_Error         错误变量
* @return    sqrtA的值
* @exception NSExceptio: LQ_UINT32_UQ23_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE 错误:输入数值是负数\n
*                        LQ_UINT32_UQ23_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW  错误:精度范围太低，无差异性
* @par       计算sqrt(A)的值
* @code
*    LQ_UINT32_UQ23_SQRT_NEWTON_ITERATION(A, Error_Range, &lq_error);
* @endcode
* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
*/
LQ_UINT32_UQ LQ_UINT32_UQ23_SQRT_NEWTON_ITERATION(LQ_UINT32_UQ23 A, LQ_UINT32_UQ23 Error_Range, LQ_ERROR* Lq_Error)
{
    LQ_UI_64BIT LQ_Sqrt_Value;
    if (Error_Range == 0)
    {
        (*Lq_Error) = LQ_UINT32_UQ23_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW;
        return 0;
    }
    LQ_Sqrt_Value = LQ_SQRT_U64_ROOT(((LQ_UI_64BIT)A) << 23, (LQ_UI_64BIT)Error_Range);
    return (LQ_UINT32_UQ)LQ_Sqrt_Value;
}
/**@brief LQ_UINT32_UQ22 开根 牛顿迭代法
* @details 采用牛顿迭代法进行开跟，相邻两次估计之差小于Error_Range时提前结束
* @param[in] LQ_UINT32_UQ22     A              输入UQ格式数
* @param[in] LQ_UINT32_UQ22     Error_Range    迭代误差范围
* @param[in] LQ_ERROR*      Lq_Error         错误变量
* @return    sqrtA的值
* @exception NSExceptio: LQ_UINT32_UQ22_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE 错误:输入数值是负数\n
*                        LQ_UINT32_UQ22_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW  错误:精度范围太低，无差异性
* @par       计算sqrt(A)的值
* @code
*    LQ_UINT32_UQ22_SQRT_NEWTON_ITERATION(A, Error_Range, &lq_error);
* @endcode
* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
*/
LQ_UINT32_UQ LQ_UINT32_UQ22_SQRT_NEWTON_ITERATION(LQ_UINT32_UQ22 A, LQ_UINT32_UQ22 Error_Range, LQ_ERROR* Lq_Error)
{
    LQ_UI_64BIT LQ_Sqrt_Value;
    if (Error_Range == 0)
    {
        (*Lq_Error) = LQ_UINT32_UQ22_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW;
        return 0;
    }
    LQ_Sqrt_Value = LQ_SQRT_U64_ROOT(((LQ_UI_64BIT)A) << 22, (LQ_UI_64BIT)Error_Range);
    return (LQ_UINT32_UQ)LQ_Sqrt_Value;
}
/**@brief LQ_UINT32_UQ21 开根 牛顿迭代法
* @details 采用牛顿迭代法进行开跟，相邻两次估计之差小于Error_Range时提前结束
* @param[in] LQ_UINT32_UQ21     A              输入UQ格式数
* @param[in] LQ_UINT32_UQ21     Error_Range    迭代误差范围
* @param[in] LQ_ERROR*      Lq_Error         错误变量
* @return    sqrtA的值
* @exception NSExceptio: LQ_UINT32_UQ21_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE 错误:输入数值是负数\n
*                        LQ_UINT32_UQ21_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW  错误:精度范围太低，无差异性
* @par       计算sqrt(A)的值
* @code
*    LQ_UINT32_UQ21_SQRT_NEWTON_ITERATION(A, Error_Range, &lq_error);
* @endcode
* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
*/
LQ_UINT32_UQ LQ_UINT32_UQ21_SQRT_NEWTON_ITERATION(LQ_UINT32_UQ21 A, LQ_UINT32_UQ21 Error_Range, LQ_ERROR* Lq_Error)
{
    LQ_UI_64BIT LQ_Sqrt_Value;
    if (Error_Range == 0)
    {
        (*Lq_Error) = LQ_UINT32_UQ21_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW;
        return 0;
    }
    LQ_Sqrt_Value = LQ_SQRT_U64_ROOT(((LQ_UI_64BIT)A) << 21, (LQ_UI_64BIT)Error_Range);
    return (LQ_UINT32_UQ)LQ_Sqrt_Value;
}
/**@brief LQ_UINT32_UQ20 开根 牛顿迭代法
* @details 采用牛顿迭代法进行开跟，相邻两次估计之差小于Error_Range时提前结束
* @param[in] LQ_UINT32_UQ20     A              输入UQ格式数
* @param[in] LQ_UINT32_UQ20     Error_Range    迭代误差范围
* @param[in] LQ_ERROR*      Lq_Error         错误变量
* @return    sqrtA的值
* @exception NSExceptio: LQ_UINT32_UQ20_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE 错误:输入数值是负数\n
*                        LQ_UINT32_UQ20_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW  错误:精度范围太低，无差异性
* @par       计算sqrt(A)的值
* @code
*    LQ_UINT32_UQ20_SQRT_NEWTON_ITERATION(A, Error_Range, &lq_error);
* @endcode
* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
*/
LQ_UINT32_UQ LQ_UINT32_UQ20_SQRT_NEWTON_ITERATION(LQ_UINT32_UQ20 A, LQ_UINT32_UQ20 Error_Range, LQ_ERROR* Lq_Error)
{
    LQ_UI_64BIT LQ_Sqrt_Value;
    if (Error_Range == 0)
    {
        (*Lq_Error) = LQ_UINT32_UQ20_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW;
        return 0;
    }
    LQ_Sqrt_Value = LQ_SQRT_U64_ROOT(((LQ_UI_64BIT)A) << 20, (LQ_UI_64BIT)Error_Range);
    return (LQ_UINT32_UQ)LQ_Sqrt_Value;
}
/**@brief LQ_UINT32_UQ19 开根 牛顿迭代法
* @details 采用牛顿迭代法进行开跟，相邻两次估计之差小于Error_Range时提前结束
* @param[in] LQ_UINT32_UQ19     A              输入UQ格式数
* @param[in] LQ_UINT32_UQ19     Error_Range    迭代误差范围
* @param[in] LQ_ERROR*      Lq_Error         错误变量
* @return    sqrtA的值
* @exception NSExceptio: LQ_UINT32_UQ19_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE 错误:输入数值是负数\n
*                        LQ_UINT32_UQ19_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW  错误:精度范围太低，无差异性
* @par       计算sqrt(A)的值
* @code
*    LQ_UINT32_UQ19_SQRT_NEWTON_ITERATION(A, Error_Range, &lq_error);
* @endcode
* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
*/
LQ_UINT32_UQ LQ_UINT32_UQ19_SQRT_NEWTON_ITERATION(LQ_UINT32_UQ19 A, LQ_UINT32_UQ19 Error_Range, LQ_ERROR* Lq_Error)
{
    LQ_UI_64BIT LQ_Sqrt_Value;
    if (Error_Range == 0)
    {
        (*Lq_Error) = LQ_UINT32_UQ19_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW;
        return 0;
    }
    LQ_Sqrt_Value = LQ_SQRT_U64_ROOT(((LQ_UI_64BIT)A) << 19, (LQ_UI_64BIT)Error_Range);
    return (LQ_UINT32_UQ)LQ_Sqrt_Value;
}
/**@brief LQ_UINT32_UQ18 开根 牛顿迭代法
* @details 采用牛顿迭代法进行开跟，相邻两次估计之差小于Error_Range时提前结束
* @param[in] LQ_UINT32_UQ18     A              输入UQ格式数
* @param[in] LQ_UINT32_UQ18     Error_Range    迭代误差范围
* @param[in] LQ_ERROR*      Lq_Error         错误变量
* @return    sqrtA的值
* @exception NSExceptio: LQ_UINT32_UQ18_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE 错误:输入数值是负数\n
*                        LQ_UINT32_UQ18_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW  错误:精度范围太低，无差异性
* @par       计算sqrt(A)的值
* @code
*    LQ_UINT32_UQ18_SQRT_NEWTON_ITERATION(A, Error_Range, &lq_error);
* @endcode
* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
*/
LQ_UINT32_UQ LQ_UINT32_UQ18_SQRT_NEWTON_ITERATION(LQ_UINT32_UQ18 A, LQ_UINT32_UQ18 Error_Range, LQ_ERROR* Lq_Error)
{
    LQ_UI_64BIT LQ_Sqrt_Value;
    if (Error_Range == 0)
    {
        (*Lq_Error) = LQ_UINT32_UQ18_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW;
        return 0;
    }
    LQ_Sqrt_Value = LQ_SQRT_U64_ROOT(((LQ_UI_64BIT)A) << 18, (LQ_UI_64BIT)Error_Range);
    return (LQ_UINT32_UQ)LQ_Sqrt_Value;
}
/**@brief LQ_UINT32_UQ17 开根 牛顿迭代法
* @details 采用牛顿迭代法进行开跟，相邻两次估计之差小于Error_Range时提前结束
* @param[in] LQ_UINT32_UQ17     A              输入UQ格式数
* @param[in] LQ_UINT32_UQ17     Error_Range    迭代误差范围
* @param[in] LQ_ERROR*      Lq_Error         错误变量
* @return    sqrtA的值
* @exception NSExceptio: LQ_UINT32_UQ17_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE 错误:输入数值是负数\n
*                        LQ_UINT32_UQ17_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW  错误:精度范围太低，无差异性
* @par       计算sqrt(A)的值
* @code
*    LQ_UINT32_UQ17_SQRT_NEWTON_ITERATION(A, Error_Range, &lq_error);
* @endcode
* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
*/
LQ_UINT32_UQ LQ_UINT32_UQ17_SQRT_NEWTON_ITERATION(LQ_UINT32_UQ17 A, LQ_UINT32_UQ17 Error_Range, LQ_ERROR* Lq_Error)
{
    LQ_UI_64BIT LQ_Sqrt_Value;
    if (Error_Range == 0)
    {
        (*Lq_Error) = LQ_UINT32_UQ17_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW;
        return 0;
    }
    LQ_Sqrt_Value = LQ_SQRT_U64_ROOT(((LQ_UI_64BIT)A) << 17, (LQ_UI_64BIT)Error_Range);
    return (LQ_UINT32_UQ)LQ_Sqrt_Value;
}
/**@brief LQ_UINT32_UQ16 开根 牛顿迭代法
* @details 采用牛顿迭代法进行开跟，相邻两次估计之差小于Error_Range时提前结束
* @param[in] LQ_UINT32_UQ16     A              输入UQ格式数
* @param[in] LQ_UINT32_UQ16     Error_Range    迭代误差范围
* @param[in] LQ_ERROR*      Lq_Error         错误变量
* @return    sqrtA的值
* @exception NSExceptio: LQ_UINT32_UQ16_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE 错误:输入数值是负数\n
*                        LQ_UINT32_UQ16_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW  错误:精度范围太低，无差异性
* @par       计算sqrt(A)的值
* @code
*    LQ_UINT32_UQ16_SQRT_NEWTON_ITERATION(A, Error_Range, &lq_error);
* @endcode
* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
*/
LQ_UINT32_UQ LQ_UINT32_UQ16_SQRT_NEWTON_ITERATION(LQ_UINT32_UQ16 A, LQ_UINT32_UQ16 Error_Range, LQ_ERROR* Lq_Error)
{
    LQ_UI_64BIT LQ_Sqrt_Value;
    if (Error_Range == 0)
    {
        (*Lq_Error) = LQ_UINT32_UQ16_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW;
        return 0;
    }
    LQ_Sqrt_Value = LQ_SQRT_U64_ROOT(((LQ_UI_64BIT)A) << 16, (LQ_UI_64BIT)Error_Range);
    return (LQ_UINT32_UQ)LQ_Sqrt_Value;
}
/**@brief LQ_UINT32_UQ15 开根 牛顿迭代法
* @details 采用牛顿迭代法进行开跟，相邻两次估计之差小于Error_Range时提前结束
* @param[in] LQ_UINT32_UQ15     A              输入UQ格式数
* @param[in] LQ_UINT32_UQ15     Error_Range    迭代误差范围
* @param[in] LQ_ERROR*      Lq_Error         错误变量
* @return    sqrtA的值
* @exception NSExceptio: LQ_UINT32_UQ15_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE 错误:输入数值是负数\n
*                        LQ_UINT32_UQ15_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW  错误:精度范围太低，无差异性
* @par       计算sqrt(A)的值
* @code
*    LQ_UINT32_UQ15_SQRT_NEWTON_ITERATION(A, Error_Range, &lq_error);
* @endcode
* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
*/
LQ_UINT32_UQ LQ_UINT32_UQ15_SQRT_NEWTON_ITERATION(LQ_UINT32_UQ15 A, LQ_UINT32_UQ15 Error_Range, LQ_ERROR* Lq_Error)
{
    LQ_UI_64BIT LQ_Sqrt_Value;
    if (Error_Range == 0)
    {
        (*Lq_Error) = LQ_UINT32_UQ15_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW;
        return 0;
    }
    LQ_Sqrt_Value = LQ_SQRT_U64_ROOT(((LQ_UI_64BIT)A) << 15, (LQ_UI_64BIT)Error_Range);
    return (LQ_UINT32_UQ)LQ_Sqrt_Value;
}
/**@brief LQ_UINT32_UQ14 开根 牛顿迭代法
* @details 采用牛顿迭代法进行开跟，相邻两次估计之差小于Error_Range时提前结束
* @param[in] LQ_UINT32_UQ14     A              输入UQ格式数
* @param[in] LQ_UINT32_UQ14     Error_Range    迭代误差范围
* @param[in] LQ_ERROR*      Lq_Error         错误变量
* @return    sqrtA的值
* @exception NSExceptio: LQ_UINT32_UQ14_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE 错误:输入数值是负数\n
*                        LQ_UINT32_UQ14_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW  错误:精度范围太低，无差异性
* @par       计算sqrt(A)的值
* @code
*    LQ_UINT32_UQ14_SQRT_NEWTON_ITERATION(A, Error_Range, &lq_error);
* @endcode
* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
*/
LQ_UINT32_UQ LQ_UINT32_UQ14_SQRT_NEWTON_ITERATION(LQ_UINT32_UQ14 A, LQ_UINT32_UQ14 Error_Range, LQ_ERROR* Lq_Error)
{
    LQ_UI_64BIT LQ_Sqrt_Value;
    if (Error_Range == 0)
    {
        (*Lq_Error) = LQ_UINT32_UQ14_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW;
        return 0;
    }
    LQ_Sqrt_Value = LQ_SQRT_U64_ROOT(((LQ_UI_64BIT)A) << 14, (LQ_UI_64BIT)Error_Range);
    return (LQ_UINT32_UQ)LQ_Sqrt_Value;
}
/**@brief LQ_UINT32_UQ13 开根 牛顿迭代法
* @details 采用牛顿迭代法进行开跟，相邻两次估计之差小于Error_Range时提前结束
* @param[in] LQ_UINT32_UQ13     A              输入UQ格式数
* @param[in] LQ_UINT32_UQ13     Error_Range    迭代误差范围
* @param[in] LQ_ERROR*      Lq_Error         错误变量
* @return    sqrtA的值
* @exception NSExceptio: LQ_UINT32_UQ13_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE 错误:输入数值是负数\n
*                        LQ_UINT32_UQ13_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW  错误:精度范围太低，无差异性
* @par       计算sqrt(A)的值
* @code
*    LQ_UINT32_UQ13_SQRT_NEWTON_ITERATION(A, Error_Range, &lq_error);
* @endcode
* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
*/
LQ_UINT32_UQ LQ_UINT32_UQ13_SQRT_NEWTON_ITERATION(LQ_UINT32_UQ13 A, LQ_UINT32_UQ13 Error_Range, LQ_ERROR* Lq_Error)
{
    LQ_UI_64BIT LQ_Sqrt_Value;
    if (Error_Range == 0)
    {
        (*Lq_Error) = LQ_UINT32_UQ13_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW;
        return 0;
    }
    LQ_Sqrt_Value = LQ_SQRT_U64_ROOT(((LQ_UI_64BIT)A) << 13, (LQ_UI_64BIT)Error_Range);
    return (LQ_UINT32_UQ)LQ_Sqrt_Value;
}
/**@brief LQ_UINT32_UQ12 开根 牛顿迭代法
* @details 采用牛顿迭代法进行开跟，相邻两次估计之差小于Error_Range时提前结束
* @param[in] LQ_UINT32_UQ12     A              输入UQ格式数
* @param[in] LQ_UINT32_UQ12     Error_Range    迭代误差范围
* @param[in] LQ_ERROR*      Lq_Error         错误变量
* @return    sqrtA的值
* @exception NSExceptio: LQ_UINT32_UQ12_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE 错误:输入数值是负数\n
*                        LQ_UINT32_UQ12_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW  错误:精度范围太低，无差异性
* @par       计算sqrt(A)的值
* @code
*    LQ_UINT32_UQ12_SQRT_NEWTON_ITERATION(A, Error_Range, &lq_error);
* @endcode
* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
*/
LQ_UINT32_UQ LQ_UINT32_UQ12_SQRT_NEWTON_ITERATION(LQ_UINT32_UQ12 A, LQ_UINT32_UQ12 Error_Range, LQ_ERROR* Lq_Error)
{
    LQ_UI_64BIT LQ_Sqrt_Value;
    if (Error_Range == 0)
    {
        (*Lq_Error) = LQ_UINT32_UQ12_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW;
        return 0;
    }
    LQ_Sqrt_Value = LQ_SQRT_U64_ROOT(((LQ_UI_64BIT)A) << 12, (LQ_UI_64BIT)Error_Range);
    return (LQ_UINT32_UQ)LQ_Sqrt_Value;
}
/**@brief LQ_UINT32_UQ11 开根 牛顿迭代法
* @details 采用牛顿迭代法进行开跟，相邻两次估计之差小于Error_Range时提前结束
* @param[in] LQ_UINT32_UQ11     A              输入UQ格式数
* @param[in] LQ_UINT32_UQ11     Error_Range    迭代误差范围
* @param[in] LQ_ERROR*      Lq_Error         错误变量
* @return    sqrtA的值
* @exception NSExceptio: LQ_UINT32_UQ11_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE 错误:输入数值是负数\n
*                        LQ_UINT32_UQ11_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW  错误:精度范围太低，无差异性
* @par       计算sqrt(A)的值
* @code
*    LQ_UINT32_UQ11_SQRT_NEWTON_ITERATION(A, Error_Range, &lq_error);
* @endcode
* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
*/
LQ_UINT32_UQ LQ_UINT32_UQ11_SQRT_NEWTON_ITERATION(LQ_UINT32_UQ11 A, LQ_UINT32_UQ11 Error_Range, LQ_ERROR* Lq_Error)
{
    LQ_UI_64BIT LQ_Sqrt_Value;
    if (Error_Range == 0)
    {
        (*Lq_Error) = LQ_UINT32_UQ11_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW;
        return 0;
    }
    LQ_Sqrt_Value = LQ_SQRT_U64_ROOT(((LQ_UI_64BIT)A) << 11, (LQ_UI_64BIT)Error_Range);
    return (LQ_UINT32_UQ)LQ_Sqrt_Value;
}
/**@brief LQ_UINT32_UQ10 开根 牛顿迭代法
* @details 采用牛顿迭代法进行开跟，相邻两次估计之差小于Error_Range时提前结束
* @param[in] LQ_UINT32_UQ10     A              输入UQ格式数
* @param[in] LQ_UINT32_UQ10     Error_Range    迭代误差范围
* @param[in] LQ_ERROR*      Lq_Error         错误变量
* @return    sqrtA的值
* @exception NSExceptio: LQ_UINT32_UQ10_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE 错误:输入数值是负数\n
*                        LQ_UINT32_UQ10_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW  错误:精度范围太低，无差异性
* @par       计算sqrt(A)的值
* @code
*    LQ_UINT32_UQ10_SQRT_NEWTON_ITERATION(A, Error_Range, &lq_error);
* @endcode
* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
*/
LQ_UINT32_UQ LQ_UINT32_UQ10_SQRT_NEWTON_ITERATION(LQ_UINT32_UQ10 A, LQ_UINT32_UQ10 Error_Range, LQ_ERROR* Lq_Error)
{
    LQ_UI_64BIT LQ_Sqrt_Value;
    if (Error_Range == 0)
    {
        (*Lq_Error) = LQ_UINT32_UQ10_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW;
        return 0;
    }
    LQ_Sqrt_Value = LQ_SQRT_U64_ROOT(((LQ_UI_64BIT)A) << 10, (LQ_UI_64BIT)Error_Range);
    return (LQ_UINT32_UQ)LQ_Sqrt_Value;
}
/**@brief LQ_UINT32_UQ9 开根 牛顿迭代法
* @details 采用牛顿迭代法进行开跟，相邻两次估计之差小于Error_Range时提前结束
* @param[in] LQ_UINT32_UQ9     A              输入UQ格式数
* @param[in] LQ_UINT32_UQ9     Error_Range    迭代误差范围
* @param[in] LQ_ERROR*      Lq_Error         错误变量
* @return    sqrtA的值
* @exception NSExceptio: LQ_UINT32_UQ9_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE 错误:输入数值是负数\n
*                        LQ_UINT32_UQ9_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW  错误:精度范围太低，无差异性
* @par       计算sqrt(A)的值
* @code
*    LQ_UINT32_UQ9_SQRT_NEWTON_ITERATION(A, Error_Range, &lq_error);
* @endcode
* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
*/
LQ_UINT32_UQ LQ_UINT32_UQ9_SQRT_NEWTON_ITERATION(LQ_UINT32_UQ9 A, LQ_UINT32_UQ9 Error_Range, LQ_ERROR* Lq_Error)
{
    LQ_UI_64BIT LQ_Sqrt_Value;
    if (Error_Range == 0)
    {
        (*Lq_Error) = LQ_UINT32_UQ9_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW;
        return 0;
    }
    LQ_Sqrt_Value = LQ_SQRT_U64_ROOT(((LQ_UI_64BIT)A) << 9, (LQ_UI_64BIT)Error_Range);
    return (LQ_UINT32_UQ)LQ_Sqrt_Value;
}
/**@brief LQ_UINT32_UQ8 开根 牛顿迭代法
* @details 采用牛顿迭代法进行开跟，相邻两次估计之差小于Error_Range时提前结束
* @param[in] LQ_UINT32_UQ8     A              输入UQ格式数
* @param[in] LQ_UINT32_UQ8     Error_Range    迭代误差范围
* @param[in] LQ_ERROR*      Lq_Error         错误变量
* @return    sqrtA的值
* @exception NSExceptio: LQ_UINT32_UQ8_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE 错误:输入数值是负数\n
*                        LQ_UINT32_UQ8_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW  错误:精度范围太低，无差异性
* @par       计算sqrt(A)的值
* @code
*    LQ_UINT32_UQ8_SQRT_NEWTON_ITERATION(A, Error_Range, &lq_error);
* @endcode
* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
*/
LQ_UINT32_UQ LQ_UINT32_UQ8_SQRT_NEWTON_ITERATION(LQ_UINT32_UQ8 A, LQ_UINT32_UQ8 Error_Range, LQ_ERROR* Lq_Error)
{
    LQ_UI_64BIT LQ_Sqrt_Value;
    if (Error_Range == 0)
    {
        (*Lq_Error) = LQ_UINT32_UQ8_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW;
        return 0;
    }
    LQ_Sqrt_Value = LQ_SQRT_U64_ROOT(((LQ_UI_64BIT)A) << 8, (LQ_UI_64BIT)Error_Range);
    return (LQ_UINT32_UQ)LQ_Sqrt_Value;
}
/**@brief LQ_UINT32_UQ7 开根 牛顿迭代法
* @details 采用牛顿迭代法进行开跟，相邻两次估计之差小于Error_Range时提前结束
* @param[in] LQ_UINT32_UQ7     A              输入UQ格式数
* @param[in] LQ_UINT32_UQ7     Error_Range    迭代误差范围
* @param[in] LQ_ERROR*      Lq_Error         错误变量
* @return    sqrtA的值
* @exception NSExceptio: LQ_UINT32_UQ7_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE 错误:输入数值是负数\n
*                        LQ_UINT32_UQ7_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW  错误:精度范围太低，无差异性
* @par       计算sqrt(A)的值
* @code
*    LQ_UINT32_UQ7_SQRT_NEWTON_ITERATION(A, Error_Range, &lq_error);
* @endcode
* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
*/
LQ_UINT32_UQ LQ_UINT32_UQ7_SQRT_NEWTON_ITERATION(LQ_UINT32_UQ7 A, LQ_UINT32_UQ7 Error_Range, LQ_ERROR* Lq_Error)
{
    LQ_UI_64BIT LQ_Sqrt_Value;
    if (Error_Range == 0)
    {
        (*Lq_Error) = LQ_UINT32_UQ7_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW;
        return 0;
    }
    LQ_Sqrt_Value = LQ_SQRT_U64_ROOT(((LQ_UI_64BIT)A) << 7, (LQ_UI_64BIT)Error_Range);
    return (LQ_UINT32_UQ)LQ_Sqrt_Value;
}
/**@brief LQ_UINT32_UQ6 开根 牛顿迭代法
* @details 采用牛顿迭代法进行开跟，相邻两次估计之差小于Error_Range时提前结束
* @param[in] LQ_UINT32_UQ6     A              输入UQ格式数
* @param[in] LQ_UINT32_UQ6     Error_Range    迭代误差范围
* @param[in] LQ_ERROR*      Lq_Error         错误变量
* @return    sqrtA的值
* @exception NSExceptio: LQ_UINT32_UQ6_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE 错误:输入数值是负数\n
*                        LQ_UINT32_UQ6_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW  错误:精度范围太低，无差异性
* @par       计算sqrt(A)的值
* @code
*    LQ_UINT32_UQ6_SQRT_NEWTON_ITERATION(A, Error_Range, &lq_error);
* @endcode
* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
*/
LQ_UINT32_UQ LQ_UINT32_UQ6_SQRT_NEWTON_ITERATION(LQ_UINT32_UQ6 A, LQ_UINT32_UQ6 Error_Range, LQ_ERROR* Lq_Error)
{
    LQ_UI_64BIT LQ_Sqrt_Value;
    if (Error_Range == 0)
    {
        (*Lq_Error) = LQ_UINT32_UQ6_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW;
        return 0;
    }
    LQ_Sqrt_Value = LQ_SQRT_U64_ROOT(((LQ_UI_64BIT)A) << 6, (LQ_UI_64BIT)Error_Range);
    return (LQ_UINT32_UQ)LQ_Sqrt_Value;
}
/**@brief LQ_UINT32_UQ5 开根 牛顿迭代法
* @details 采用牛顿迭代法进行开跟，相邻两次估计之差小于Error_Range时提前结束
* @param[in] LQ_UINT32_UQ5     A              输入UQ格式数
* @param[in] LQ_UINT32_UQ5     Error_Range    迭代误差范围
* @param[in] LQ_ERROR*      Lq_Error         错误变量
* @return    sqrtA的值
* @exception NSExceptio: LQ_UINT32_UQ5_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE 错误:输入数值是负数\n
*                        LQ_UINT32_UQ5_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW  错误:精度范围太低，无差异性
* @par       计算sqrt(A)的值
* @code
*    LQ_UINT32_UQ5_SQRT_NEWTON_ITERATION(A, Error_Range, &lq_error);
* @endcode
* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
*/
LQ_UINT32_UQ LQ_UINT32_UQ5_SQRT_NEWTON_ITERATION(LQ_UINT32_UQ5 A, LQ_UINT32_UQ5 Error_Range, LQ_ERROR* Lq_Error)
{
    LQ_UI_64BIT LQ_Sqrt_Value;
    if (Error_Range == 0)
    {
        (*Lq_Error) = LQ_UINT32_UQ5_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW;
        return 0;
    }
    LQ_Sqrt_Value = LQ_SQRT_U64_ROOT(((LQ_UI_64BIT)A) << 5, (LQ_UI_64BIT)Error_Range);
    return (LQ_UINT32_UQ)LQ_Sqrt_Value;
}
/**@brief LQ_UINT32_UQ4 开根 牛顿迭代法
* @details 采用牛顿迭代法进行开跟，相邻两次估计之差小于Error_Range时提前结束
* @param[in] LQ_UINT32_UQ4     A              输入UQ格式数
* @param[in] LQ_UINT32_UQ4     Error_Range    迭代误差范围
* @param[in] LQ_ERROR*      Lq_Error         错误变量
* @return    sqrtA的值
* @exception NSExceptio: LQ_UINT32_UQ4_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE 错误:输入数值是负数\n
*                        LQ_UINT32_UQ4_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW  错误:精度范围太低，无差异性
* @par       计算sqrt(A)的值
* @code
*    LQ_UINT32_UQ4_SQRT_NEWTON_ITERATION(A, Error_Range, &lq_error);
* @endcode
* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
*/
LQ_UINT32_UQ LQ_UINT32_UQ4_SQRT_NEWTON_ITERATION(LQ_UINT32_UQ4 A, LQ_UINT32_UQ4 Error_Range, LQ_ERROR* Lq_Error)
{
    LQ_UI_64BIT LQ_Sqrt_Value;
    if (Error_Range == 0)
    {
        (*Lq_Error) = LQ_UINT32_UQ4_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW;
        return 0;
    }
    LQ_Sqrt_Value = LQ_SQRT_U64_ROOT(((LQ_UI_64BIT)A) << 4, (LQ_UI_64BIT)Error_Range);
    return (LQ_UINT32_UQ)LQ_Sqrt_Value;
}
/**@brief LQ_UINT32_UQ3 开根 牛顿迭代法
* @details 采用牛顿迭代法进行开跟，相邻两次估计之差小于Error_Range时提前结束
* @param[in] LQ_UINT32_UQ3     A              输入UQ格式数
* @param[in] LQ_UINT32_UQ3     Error_Range    迭代误差范围
* @param[in] LQ_ERROR*      Lq_Error         错误变量
* @return    sqrtA的值
* @exception NSExceptio: LQ_UINT32_UQ3_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE 错误:输入数值是负数\n
*                        LQ_UINT32_UQ3_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW  错误:精度范围太低，无差异性
* @par       计算sqrt(A)的值
* @code
*    LQ_UINT32_UQ3_SQRT_NEWTON_ITERATION(A, Error_Range, &lq_error);
* @endcode
* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
*/
LQ_UINT32_UQ LQ_UINT32_UQ3_SQRT_NEWTON_ITERATION(LQ_UINT32_UQ3 A, LQ_UINT32_UQ3 Error_Range, LQ_ERROR* Lq_Error)
{
    LQ_UI_64BIT LQ_Sqrt_Value;
    if (Error_Range == 0)
    {
        (*Lq_Error) = LQ_UINT32_UQ3_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW;
        return 0;
    }
    LQ_Sqrt_Value = LQ_SQRT_U64_ROOT(((LQ_UI_64BIT)A) << 3, (LQ_UI_64BIT)Error_Range);
    return (LQ_UINT32_UQ)LQ_Sqrt_Value;
}
/**@brief LQ_UINT32_UQ2 开根 牛顿迭代法
* @details 采用牛顿迭代法进行开跟，相邻两次估计之差小于Error_Range时提前结束
* @param[in] LQ_UINT32_UQ2     A              输入UQ格式数
* @param[in] LQ_UINT32_UQ2     Error_Range    迭代误差范围
* @param[in] LQ_ERROR*      Lq_Error         错误变量
* @return    sqrtA的值
* @exception NSExceptio: LQ_UINT32_UQ2_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE 错误:输入数值是负数\n
*                        LQ_UINT32_UQ2_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW  错误:精度范围太低，无差异性
* @par       计算sqrt(A)的值
* @code
*    LQ_UINT32_UQ2_SQRT_NEWTON_ITERATION(A, Error_Range, &lq_error);
* @endcode
* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
*/
LQ_UINT32_UQ LQ_UINT32_UQ2_SQRT_NEWTON_ITERATION(LQ_UINT32_UQ2 A, LQ_UINT32_UQ2 Error_Range, LQ_ERROR* Lq_Error)
{
    LQ_UI_64BIT LQ_Sqrt_Value;
    if (Error_Range == 0)
    {
        (*Lq_Error) = LQ_UINT32_UQ2_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW;
        return 0;
    }
    LQ_Sqrt_Value = LQ_SQRT_U64_ROOT(((LQ_UI_64BIT)A) << 2, (LQ_UI_64BIT)Error_Range);
    return (LQ_UINT32_UQ)LQ_Sqrt_Value;
}
/**@brief LQ_UINT32_UQ1 开根 牛顿迭代法
* @details 采用牛顿迭代法进行开跟，相邻两次估计之差小于Error_Range时提前结束
* @param[in] LQ_UINT32_UQ1     A              输入UQ格式数
* @param[in] LQ_UINT32_UQ1     Error_Range    迭代误差范围
* @param[in] LQ_ERROR*      Lq_Error         错误变量
* @return    sqrtA的值
* @exception NSExceptio: LQ_UINT32_UQ1_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE 错误:输入数值是负数\n
*                        LQ_UINT32_UQ1_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW  错误:精度范围太低，无差异性
* @par       计算sqrt(A)的值
* @code
*    LQ_UINT32_UQ1_SQRT_NEWTON_ITERATION(A, Error_Range, &lq_error);
* @endcode
* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
*/
LQ_UINT32_UQ LQ_UINT32_UQ1_SQRT_NEWTON_ITERATION(LQ_UINT32_UQ1 A, LQ_UINT32_UQ1 Error_Range, LQ_ERROR* Lq_Error)
{
    LQ_UI_64BIT LQ_Sqrt_Value;
    if (Error_Range == 0)
    {
        (*Lq_Error) = LQ_UINT32_UQ1_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW;
        return 0;
    }
    LQ_Sqrt_Value = LQ_SQRT_U64_ROOT(((LQ_UI_64BIT)A) << 1, (LQ_UI_64BIT)Error_Range);
    return (LQ_UINT32_UQ)LQ_Sqrt_Value;
}


/**@brief LQ_INT8_Q 开根 牛顿迭代法
* @details 采用牛顿迭代法进行开跟，相邻两次估计之差小于Error_Range时提前结束
* @param[in] LQ_INT8_Q     A              输入Q格式数
* @param[in] LQ_UI_8BIT     Q_A            Q格式小数位数,不得超过7
* @param[in] LQ_INT8_Q     Error_Range    迭代误差范围
* @param[in] LQ_ERROR*      Lq_Error         错误变量
* @return    sqrtA的值,Q_A格式
* @exception NSExceptio: LQ_INT8_Q_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE 错误:输入数值是负数\n
*                        LQ_INT8_Q_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW  错误:精度范围太低或Q_A超过7
* @par       计算sqrt(A*2^Q_A)的值
* @code
*    LQ_INT8_Q_SQRT_NEWTON_ITERATION(A, Q_A, Error_Range, &lq_error);
* @endcode
* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
*/
LQ_INT8_Q LQ_INT8_Q_SQRT_NEWTON_ITERATION(LQ_INT8_Q A, LQ_UI_8BIT Q_A, LQ_INT8_Q Error_Range, LQ_ERROR* Lq_Error)
{
    LQ_UI_32BIT LQ_Sqrt_Value;
    if (A < 0)
    {
        (*Lq_Error) = LQ_INT8_Q_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE;
        return 0;
    }
    if ((Q_A > 7) || (Error_Range <= 0))
    {
        (*Lq_Error) = LQ_INT8_Q_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW;
        return 0;
    }
    LQ_Sqrt_Value = LQ_SQRT_U32_ROOT(((LQ_UI_32BIT)A) << Q_A, (LQ_UI_32BIT)Error_Range);
    return (LQ_INT8_Q)LQ_Sqrt_Value;
}

/**@brief LQ_UINT8_UQ 开根 牛顿迭代法
* @details 采用牛顿迭代法进行开跟，相邻两次估计之差小于Error_Range时提前结束
* @param[in] LQ_UINT8_UQ     A              输入Q格式数
* @param[in] LQ_UI_8BIT     Q_A            Q格式小数位数,不得超过8
* @param[in] LQ_UINT8_UQ     Error_Range    迭代误差范围
* @param[in] LQ_ERROR*      Lq_Error         错误变量
* @return    sqrtA的值,Q_A格式
* @exception NSExceptio: LQ_UINT8_UQ_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW  错误:精度范围太低或Q_A超过8
* @par       计算sqrt(A*2^Q_A)的值
* @code
*    LQ_UINT8_UQ_SQRT_NEWTON_ITERATION(A, Q_A, Error_Range, &lq_error);
* @endcode
* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
*/
LQ_UINT8_UQ LQ_UINT8_UQ_SQRT_NEWTON_ITERATION(LQ_UINT8_UQ A, LQ_UI_8BIT Q_A, LQ_UINT8_UQ Error_Range, LQ_ERROR* Lq_Error)
{
    LQ_UI_32BIT LQ_Sqrt_Value;
    if ((Q_A > 8) || (Error_Range == 0))
    {
        (*Lq_Error) = LQ_UINT8_UQ_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW;
        return 0;
    }
    LQ_Sqrt_Value = LQ_SQRT_U32_ROOT(((LQ_UI_32BIT)A) << Q_A, (LQ_UI_32BIT)Error_Range);
    return (LQ_UINT8_UQ)LQ_Sqrt_Value;
}

/**@brief LQ_INT16_Q 开根 牛顿迭代法
* @details 采用牛顿迭代法进行开跟，相邻两次估计之差小于Error_Range时提前结束
* @param[in] LQ_INT16_Q     A              输入Q格式数
* @param[in] LQ_UI_8BIT     Q_A            Q格式小数位数,不得超过15
* @param[in] LQ_INT16_Q     Error_Range    迭代误差范围
* @param[in] LQ_ERROR*      Lq_Error         错误变量
* @return    sqrtA的值,Q_A格式
* @exception NSExceptio: LQ_INT16_Q_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE 错误:输入数值是负数\n
*                        LQ_INT16_Q_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW  错误:精度范围太低或Q_A超过15
* @par       计算sqrt(A*2^Q_A)的值
* @code
*    LQ_INT16_Q_SQRT_NEWTON_ITERATION(A, Q_A, Error_Range, &lq_error);
* @endcode
* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
*/
LQ_INT16_Q LQ_INT16_Q_SQRT_NEWTON_ITERATION(LQ_INT16_Q A, LQ_UI_8BIT Q_A, LQ_INT16_Q Error_Range, LQ_ERROR* Lq_Error)
{
    LQ_UI_32BIT LQ_Sqrt_Value;
    if (A < 0)
    {
        (*Lq_Error) = LQ_INT16_Q_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE;
        return 0;
    }
    if ((Q_A > 15) || (Error_Range <= 0))
    {
        (*Lq_Error) = LQ_INT16_Q_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW;
        return 0;
    }
    LQ_Sqrt_Value = LQ_SQRT_U32_ROOT(((LQ_UI_32BIT)A) << Q_A, (LQ_UI_32BIT)Error_Range);
    return (LQ_INT16_Q)LQ_Sqrt_Value;
}

/**@brief LQ_UINT16_UQ 开根 牛顿迭代法
* @details 采用牛顿迭代法进行开跟，相邻两次估计之差小于Error_Range时提前结束
* @param[in] LQ_UINT16_UQ     A              输入Q格式数
* @param[in] LQ_UI_8BIT     Q_A            Q格式小数位数,不得超过16
* @param[in] LQ_UINT16_UQ     Error_Range    迭代误差范围
* @param[in] LQ_ERROR*      Lq_Error         错误变量
* @return    sqrtA的值,Q_A格式
* @exception NSExceptio: LQ_UINT16_UQ_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW  错误:精度范围太低或Q_A超过16
* @par       计算sqrt(A*2^Q_A)的值
* @code
*    LQ_UINT16_UQ_SQRT_NEWTON_ITERATION(A, Q_A, Error_Range, &lq_error);
* @endcode
* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
*/
LQ_UINT16_UQ LQ_UINT16_UQ_SQRT_NEWTON_ITERATION(LQ_UINT16_UQ A, LQ_UI_8BIT Q_A, LQ_UINT16_UQ Error_Range, LQ_ERROR* Lq_Error)
{
    LQ_UI_32BIT LQ_Sqrt_Value;
    if ((Q_A > 16) || (Error_Range == 0))
    {
        (*Lq_Error) = LQ_UINT16_UQ_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW;
        return 0;
    }
    LQ_Sqrt_Value = LQ_SQRT_U32_ROOT(((LQ_UI_32BIT)A) << Q_A, (LQ_UI_32BIT)Error_Range);
    return (LQ_UINT16_UQ)LQ_Sqrt_Value;
}
/**@brief LQ_INT32_Q 开根 牛顿迭代法
* @details 采用牛顿迭代法进行开跟，相邻两次估计之差小于Error_Range时提前结束
* @param[in] LQ_INT32_Q     A              输入Q格式数
* @param[in] LQ_UI_8BIT     Q_A            Q格式小数位数,不得超过31
* @param[in] LQ_INT32_Q     Error_Range    迭代误差范围
* @param[in] LQ_ERROR*      Lq_Error         错误变量
* @return    sqrtA的值,Q_A格式
* @exception NSExceptio: LQ_INT32_Q_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE 错误:输入数值是负数\n
*                        LQ_INT32_Q_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW  错误:精度范围太低或Q_A超过31
* @par       计算sqrt(A*2^Q_A)的值
* @code
*    LQ_INT32_Q_SQRT_NEWTON_ITERATION(A, Q_A, Error_Range, &lq_error);
* @endcode
* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
*/
LQ_INT32_Q LQ_INT32_Q_SQRT_NEWTON_ITERATION(LQ_INT32_Q A, LQ_UI_8BIT Q_A, LQ_INT32_Q Error_Range, LQ_ERROR* Lq_Error)
{
    LQ_UI_64BIT LQ_Sqrt_Value;
    if (A < 0)
    {
        (*Lq_Error) = LQ_INT32_Q_SQRT_NEWTON_ITERATION_INPUT_VALUE_IS_NEGATIVE;
        return 0;
    }
    if ((Q_A > 31) || (Error_Range <= 0))
    {
        (*Lq_Error) = LQ_INT32_Q_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW;
        return 0;
    }
    LQ_Sqrt_Value = LQ_SQRT_U64_ROOT(((LQ_UI_64BIT)A) << Q_A, (LQ_UI_64BIT)Error_Range);
    return (LQ_INT32_Q)LQ_Sqrt_Value;
}
/**@brief LQ_UINT32_UQ 开根 牛顿迭代法
* @details 采用牛顿迭代法进行开跟，相邻两次估计之差小于Error_Range时提前结束
* @param[in] LQ_UINT32_UQ     A              输入Q格式数
* @param[in] LQ_UI_8BIT     Q_A            Q格式小数位数,不得超过32
* @param[in] LQ_UINT32_UQ     Error_Range    迭代误差范围
* @param[in] LQ_ERROR*      Lq_Error         错误变量
* @return    sqrtA的值,Q_A格式
* @exception NSExceptio: LQ_UINT32_UQ_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW  错误:精度范围太低或Q_A超过32
* @par       计算sqrt(A*2^Q_A)的值
* @code
*    LQ_UINT32_UQ_SQRT_NEWTON_ITERATION(A, Q_A, Error_Range, &lq_error);
* @endcode
* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
*/
LQ_UINT32_UQ LQ_UINT32_UQ_SQRT_NEWTON_ITERATION(LQ_UINT32_UQ A, LQ_UI_8BIT Q_A, LQ_UINT32_UQ Error_Range, LQ_ERROR* Lq_Error)
{
    LQ_UI_64BIT LQ_Sqrt_Value;
    if ((Q_A > 32) || (Error_Range == 0))
    {
        (*Lq_Error) = LQ_UINT32_UQ_SQRT_NEWTON_ITERATION_THE_RANGE_IS_TOO_LOW;
        return 0;
    }
    LQ_Sqrt_Value = LQ_SQRT_U64_ROOT(((LQ_UI_64BIT)A) << Q_A, (LQ_UI_64BIT)Error_Range);
    return (LQ_UINT32_UQ)LQ_Sqrt_Value;
}
#endif
