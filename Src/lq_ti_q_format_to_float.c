#include "lq_ti_q_format_to_float.h"
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
#if LQ_TI_Q_FORMAT_TO_FLOAT_LOADING_MODE == 0
/**@brief (TI方法)INT8类型Q7格式转浮点
* @details 采用估算位+指数位+符号位三位结合，能提高精度
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为浮点数
* @code*    LQ_TI_INT8_Q7_TO_FLOAT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_INT8_Q7_TO_FLOAT  TI方式INT8的Q7转化浮点类型\n
*     LQ_TI_INT8_Q6_TO_FLOAT  TI方式INT8的Q6转化浮点类型\n
*     LQ_TI_INT8_Q5_TO_FLOAT  TI方式INT8的Q5转化浮点类型\n
*     LQ_TI_INT8_Q4_TO_FLOAT  TI方式INT8的Q4转化浮点类型\n
*     LQ_TI_INT8_Q3_TO_FLOAT  TI方式INT8的Q3转化浮点类型\n
*     LQ_TI_INT8_Q2_TO_FLOAT  TI方式INT8的Q2转化浮点类型\n
*     LQ_TI_INT8_Q1_TO_FLOAT  TI方式INT8的Q1转化浮点类型\n
*/
LQ_F_32BIT LQ_TI_INT8_Q7_TO_FLOAT(LQ_I_32BIT A, LQ_ERROR* lq_error)
{
    LQ_UI_16BIT ui16Exp;
    LQ_UI_32BIT uiq23Result;
    LQ_UI_32BIT uiq31Input;
    //!< 初始化指数部分偏移量
    ui16Exp = 19328;
    //!< 保存符号位
    if (A < 0)
    {
        ui16Exp |= 0x8000;
        uiq31Input = (LQ_UI_32BIT)(-(LQ_I_64BIT)A);
    }
    else if (A == 0)
    {
        return (0);
    }
    else
    {
        uiq31Input = A;
    }
    LQ_TI_Q2F_NORMALIZE(uiq31Input, ui16Exp);
    /*对uiq31结果进行四舍五入并切换到uiq23*/
    uiq23Result = (LQ_UI_32BIT)(((LQ_UI_64BIT)uiq31Input + 0x0080u) >> 8);
    if (uiq23Result >= 0x01000000u)
    {
        uiq23Result = 0;
        ui16Exp += 0x0080;
    }
    /*删除尾数的隐含MSB位 */
    uiq23Result &= ~0x00800000;
    /*
    *将构造的指数和符号位添加到尾数。我们必须使用
    *四舍五入会导致尾数溢出的情况下的加法。
    *当这种情况发生时，尾数结果为2，其中MSB为零
    *exp的LSB被设置为1。在指数上加一就是
    *尾数为2的正确处理。不需要缩放
    *尾数，因为在这种情况下它总是等于零。
   */
    uiq23Result += (LQ_UI_32BIT)ui16Exp << 16;
    return LQ_TI_UINT32_BITS_TO_FLOAT(uiq23Result);
}
/**@brief (TI方法)INT8类型Q6格式转浮点
* @details 采用估算位+指数位+符号位三位结合，能提高精度
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为浮点数
* @code*    LQ_TI_INT8_Q6_TO_FLOAT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_INT8_Q7_TO_FLOAT  TI方式INT8的Q7转化浮点类型\n
*     LQ_TI_INT8_Q6_TO_FLOAT  TI方式INT8的Q6转化浮点类型\n
*     LQ_TI_INT8_Q5_TO_FLOAT  TI方式INT8的Q5转化浮点类型\n
*     LQ_TI_INT8_Q4_TO_FLOAT  TI方式INT8的Q4转化浮点类型\n
*     LQ_TI_INT8_Q3_TO_FLOAT  TI方式INT8的Q3转化浮点类型\n
*     LQ_TI_INT8_Q2_TO_FLOAT  TI方式INT8的Q2转化浮点类型\n
*     LQ_TI_INT8_Q1_TO_FLOAT  TI方式INT8的Q1转化浮点类型\n
*/
LQ_F_32BIT LQ_TI_INT8_Q6_TO_FLOAT(LQ_I_32BIT A, LQ_ERROR* lq_error)
{
    LQ_UI_16BIT ui16Exp;
    LQ_UI_32BIT uiq23Result;
    LQ_UI_32BIT uiq31Input;
    //!< 初始化指数部分偏移量
    ui16Exp = 19456;
    //!< 保存符号位
    if (A < 0)
    {
        ui16Exp |= 0x8000;
        uiq31Input = (LQ_UI_32BIT)(-(LQ_I_64BIT)A);
    }
    else if (A == 0)
    {
        return (0);
    }
    else
    {
        uiq31Input = A;
    }
    LQ_TI_Q2F_NORMALIZE(uiq31Input, ui16Exp);
    /*对uiq31结果进行四舍五入并切换到uiq23*/
    uiq23Result = (LQ_UI_32BIT)(((LQ_UI_64BIT)uiq31Input + 0x0080u) >> 8);
    if (uiq23Result >= 0x01000000u)
    {
        uiq23Result = 0;
        ui16Exp += 0x0080;
    }
    /*删除尾数的隐含MSB位 */
    uiq23Result &= ~0x00800000;
    /*
    *将构造的指数和符号位添加到尾数。我们必须使用
    *四舍五入会导致尾数溢出的情况下的加法。
    *当这种情况发生时，尾数结果为2，其中MSB为零
    *exp的LSB被设置为1。在指数上加一就是
    *尾数为2的正确处理。不需要缩放
    *尾数，因为在这种情况下它总是等于零。
   */
    uiq23Result += (LQ_UI_32BIT)ui16Exp << 16;
    return LQ_TI_UINT32_BITS_TO_FLOAT(uiq23Result);
}
/**@brief (TI方法)INT8类型Q5格式转浮点
* @details 采用估算位+指数位+符号位三位结合，能提高精度
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为浮点数
* @code*    LQ_TI_INT8_Q5_TO_FLOAT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_INT8_Q7_TO_FLOAT  TI方式INT8的Q7转化浮点类型\n
*     LQ_TI_INT8_Q6_TO_FLOAT  TI方式INT8的Q6转化浮点类型\n
*     LQ_TI_INT8_Q5_TO_FLOAT  TI方式INT8的Q5转化浮点类型\n
*     LQ_TI_INT8_Q4_TO_FLOAT  TI方式INT8的Q4转化浮点类型\n
*     LQ_TI_INT8_Q3_TO_FLOAT  TI方式INT8的Q3转化浮点类型\n
*     LQ_TI_INT8_Q2_TO_FLOAT  TI方式INT8的Q2转化浮点类型\n
*     LQ_TI_INT8_Q1_TO_FLOAT  TI方式INT8的Q1转化浮点类型\n
*/
LQ_F_32BIT LQ_TI_INT8_Q5_TO_FLOAT(LQ_I_32BIT A, LQ_ERROR* lq_error)
{
    LQ_UI_16BIT ui16Exp;
    LQ_UI_32BIT uiq23Result;
    LQ_UI_32BIT uiq31Input;
    //!< 初始化指数部分偏移量
    ui16Exp = 19584;
    //!< 保存符号位
    if (A < 0)
    {
        ui16Exp |= 0x8000;
        uiq31Input = (LQ_UI_32BIT)(-(LQ_I_64BIT)A);
    }
    else if (A == 0)
    {
        return (0);
    }
    else
    {
        uiq31Input = A;
    }
    LQ_TI_Q2F_NORMALIZE(uiq31Input, ui16Exp);
    /*对uiq31结果进行四舍五入并切换到uiq23*/
    uiq23Result = (LQ_UI_32BIT)(((LQ_UI_64BIT)uiq31Input + 0x0080u) >> 8);
    if (uiq23Result >= 0x01000000u)
    {
        uiq23Result = 0;
        ui16Exp += 0x0080;
    }
    /*删除尾数的隐含MSB位 */
    uiq23Result &= ~0x00800000;
    /*
    *将构造的指数和符号位添加到尾数。我们必须使用
    *四舍五入会导致尾数溢出的情况下的加法。
    *当这种情况发生时，尾数结果为2，其中MSB为零
    *exp的LSB被设置为1。在指数上加一就是
    *尾数为2的正确处理。不需要缩放
    *尾数，因为在这种情况下它总是等于零。
   */
    uiq23Result += (LQ_UI_32BIT)ui16Exp << 16;
    return LQ_TI_UINT32_BITS_TO_FLOAT(uiq23Result);
}
/**@brief (TI方法)INT8类型Q4格式转浮点
* @details 采用估算位+指数位+符号位三位结合，能提高精度
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为浮点数
* @code*    LQ_TI_INT8_Q4_TO_FLOAT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_INT8_Q7_TO_FLOAT  TI方式INT8的Q7转化浮点类型\n
*     LQ_TI_INT8_Q6_TO_FLOAT  TI方式INT8的Q6转化浮点类型\n
*     LQ_TI_INT8_Q5_TO_FLOAT  TI方式INT8的Q5转化浮点类型\n
*     LQ_TI_INT8_Q4_TO_FLOAT  TI方式INT8的Q4转化浮点类型\n
*     LQ_TI_INT8_Q3_TO_FLOAT  TI方式INT8的Q3转化浮点类型\n
*     LQ_TI_INT8_Q2_TO_FLOAT  TI方式INT8的Q2转化浮点类型\n
*     LQ_TI_INT8_Q1_TO_FLOAT  TI方式INT8的Q1转化浮点类型\n
*/
LQ_F_32BIT LQ_TI_INT8_Q4_TO_FLOAT(LQ_I_32BIT A, LQ_ERROR* lq_error)
{
    LQ_UI_16BIT ui16Exp;
    LQ_UI_32BIT uiq23Result;
    LQ_UI_32BIT uiq31Input;
    //!< 初始化指数部分偏移量
    ui16Exp = 19712;
    //!< 保存符号位
    if (A < 0)
    {
        ui16Exp |= 0x8000;
        uiq31Input = (LQ_UI_32BIT)(-(LQ_I_64BIT)A);
    }
    else if (A == 0)
    {
        return (0);
    }
    else
    {
        uiq31Input = A;
    }
    LQ_TI_Q2F_NORMALIZE(uiq31Input, ui16Exp);
    /*对uiq31结果进行四舍五入并切换到uiq23*/
    uiq23Result = (LQ_UI_32BIT)(((LQ_UI_64BIT)uiq31Input + 0x0080u) >> 8);
    if (uiq23Result >= 0x01000000u)
    {
        uiq23Result = 0;
        ui16Exp += 0x0080;
    }
    /*删除尾数的隐含MSB位 */
    uiq23Result &= ~0x00800000;
    /*
    *将构造的指数和符号位添加到尾数。我们必须使用
    *四舍五入会导致尾数溢出的情况下的加法。
    *当这种情况发生时，尾数结果为2，其中MSB为零
    *exp的LSB被设置为1。在指数上加一就是
    *尾数为2的正确处理。不需要缩放
    *尾数，因为在这种情况下它总是等于零。
   */
    uiq23Result += (LQ_UI_32BIT)ui16Exp << 16;
    return LQ_TI_UINT32_BITS_TO_FLOAT(uiq23Result);
}
/**@brief (TI方法)INT8类型Q3格式转浮点
* @details 采用估算位+指数位+符号位三位结合，能提高精度
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为浮点数
* @code*    LQ_TI_INT8_Q3_TO_FLOAT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_INT8_Q7_TO_FLOAT  TI方式INT8的Q7转化浮点类型\n
*     LQ_TI_INT8_Q6_TO_FLOAT  TI方式INT8的Q6转化浮点类型\n
*     LQ_TI_INT8_Q5_TO_FLOAT  TI方式INT8的Q5转化浮点类型\n
*     LQ_TI_INT8_Q4_TO_FLOAT  TI方式INT8的Q4转化浮点类型\n
*     LQ_TI_INT8_Q3_TO_FLOAT  TI方式INT8的Q3转化浮点类型\n
*     LQ_TI_INT8_Q2_TO_FLOAT  TI方式INT8的Q2转化浮点类型\n
*     LQ_TI_INT8_Q1_TO_FLOAT  TI方式INT8的Q1转化浮点类型\n
*/
LQ_F_32BIT LQ_TI_INT8_Q3_TO_FLOAT(LQ_I_32BIT A, LQ_ERROR* lq_error)
{
    LQ_UI_16BIT ui16Exp;
    LQ_UI_32BIT uiq23Result;
    LQ_UI_32BIT uiq31Input;
    //!< 初始化指数部分偏移量
    ui16Exp = 19840;
    //!< 保存符号位
    if (A < 0)
    {
        ui16Exp |= 0x8000;
        uiq31Input = (LQ_UI_32BIT)(-(LQ_I_64BIT)A);
    }
    else if (A == 0)
    {
        return (0);
    }
    else
    {
        uiq31Input = A;
    }
    LQ_TI_Q2F_NORMALIZE(uiq31Input, ui16Exp);
    /*对uiq31结果进行四舍五入并切换到uiq23*/
    uiq23Result = (LQ_UI_32BIT)(((LQ_UI_64BIT)uiq31Input + 0x0080u) >> 8);
    if (uiq23Result >= 0x01000000u)
    {
        uiq23Result = 0;
        ui16Exp += 0x0080;
    }
    /*删除尾数的隐含MSB位 */
    uiq23Result &= ~0x00800000;
    /*
    *将构造的指数和符号位添加到尾数。我们必须使用
    *四舍五入会导致尾数溢出的情况下的加法。
    *当这种情况发生时，尾数结果为2，其中MSB为零
    *exp的LSB被设置为1。在指数上加一就是
    *尾数为2的正确处理。不需要缩放
    *尾数，因为在这种情况下它总是等于零。
   */
    uiq23Result += (LQ_UI_32BIT)ui16Exp << 16;
    return LQ_TI_UINT32_BITS_TO_FLOAT(uiq23Result);
}
/**@brief (TI方法)INT8类型Q2格式转浮点
* @details 采用估算位+指数位+符号位三位结合，能提高精度
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为浮点数
* @code*    LQ_TI_INT8_Q2_TO_FLOAT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_INT8_Q7_TO_FLOAT  TI方式INT8的Q7转化浮点类型\n
*     LQ_TI_INT8_Q6_TO_FLOAT  TI方式INT8的Q6转化浮点类型\n
*     LQ_TI_INT8_Q5_TO_FLOAT  TI方式INT8的Q5转化浮点类型\n
*     LQ_TI_INT8_Q4_TO_FLOAT  TI方式INT8的Q4转化浮点类型\n
*     LQ_TI_INT8_Q3_TO_FLOAT  TI方式INT8的Q3转化浮点类型\n
*     LQ_TI_INT8_Q2_TO_FLOAT  TI方式INT8的Q2转化浮点类型\n
*     LQ_TI_INT8_Q1_TO_FLOAT  TI方式INT8的Q1转化浮点类型\n
*/
LQ_F_32BIT LQ_TI_INT8_Q2_TO_FLOAT(LQ_I_32BIT A, LQ_ERROR* lq_error)
{
    LQ_UI_16BIT ui16Exp;
    LQ_UI_32BIT uiq23Result;
    LQ_UI_32BIT uiq31Input;
    //!< 初始化指数部分偏移量
    ui16Exp = 19968;
    //!< 保存符号位
    if (A < 0)
    {
        ui16Exp |= 0x8000;
        uiq31Input = (LQ_UI_32BIT)(-(LQ_I_64BIT)A);
    }
    else if (A == 0)
    {
        return (0);
    }
    else
    {
        uiq31Input = A;
    }
    LQ_TI_Q2F_NORMALIZE(uiq31Input, ui16Exp);
    /*对uiq31结果进行四舍五入并切换到uiq23*/
    uiq23Result = (LQ_UI_32BIT)(((LQ_UI_64BIT)uiq31Input + 0x0080u) >> 8);
    if (uiq23Result >= 0x01000000u)
    {
        uiq23Result = 0;
        ui16Exp += 0x0080;
    }
    /*删除尾数的隐含MSB位 */
    uiq23Result &= ~0x00800000;
    /*
    *将构造的指数和符号位添加到尾数。我们必须使用
    *四舍五入会导致尾数溢出的情况下的加法。
    *当这种情况发生时，尾数结果为2，其中MSB为零
    *exp的LSB被设置为1。在指数上加一就是
    *尾数为2的正确处理。不需要缩放
    *尾数，因为在这种情况下它总是等于零。
   */
    uiq23Result += (LQ_UI_32BIT)ui16Exp << 16;
    return LQ_TI_UINT32_BITS_TO_FLOAT(uiq23Result);
}
/**@brief (TI方法)INT8类型Q1格式转浮点
* @details 采用估算位+指数位+符号位三位结合，能提高精度
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为浮点数
* @code*    LQ_TI_INT8_Q1_TO_FLOAT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_INT8_Q7_TO_FLOAT  TI方式INT8的Q7转化浮点类型\n
*     LQ_TI_INT8_Q6_TO_FLOAT  TI方式INT8的Q6转化浮点类型\n
*     LQ_TI_INT8_Q5_TO_FLOAT  TI方式INT8的Q5转化浮点类型\n
*     LQ_TI_INT8_Q4_TO_FLOAT  TI方式INT8的Q4转化浮点类型\n
*     LQ_TI_INT8_Q3_TO_FLOAT  TI方式INT8的Q3转化浮点类型\n
*     LQ_TI_INT8_Q2_TO_FLOAT  TI方式INT8的Q2转化浮点类型\n
*     LQ_TI_INT8_Q1_TO_FLOAT  TI方式INT8的Q1转化浮点类型\n
*/
LQ_F_32BIT LQ_TI_INT8_Q1_TO_FLOAT(LQ_I_32BIT A, LQ_ERROR* lq_error)
{
    LQ_UI_16BIT ui16Exp;
    LQ_UI_32BIT uiq23Result;
    LQ_UI_32BIT uiq31Input;
    //!< 初始化指数部分偏移量
    ui16Exp = 20096;
    //!< 保存符号位
    if (A < 0)
    {
        ui16Exp |= 0x8000;
        uiq31Input = (LQ_UI_32BIT)(-(LQ_I_64BIT)A);
    }
    else if (A == 0)
    {
        return (0);
    }
    else
    {
        uiq31Input = A;
    }
    LQ_TI_Q2F_NORMALIZE(uiq31Input, ui16Exp);
    /*对uiq31结果进行四舍五入并切换到uiq23*/
    uiq23Result = (LQ_UI_32BIT)(((LQ_UI_64BIT)uiq31Input + 0x0080u) >> 8);
    if (uiq23Result >= 0x01000000u)
    {
        uiq23Result = 0;
        ui16Exp += 0x0080;
    }
    /*删除尾数的隐含MSB位 */
    uiq23Result &= ~0x00800000;
    /*
    *将构造的指数和符号位添加到尾数。我们必须使用
    *四舍五入会导致尾数溢出的情况下的加法。
    *当这种情况发生时，尾数结果为2，其中MSB为零
    *exp的LSB被设置为1。在指数上加一就是
    *尾数为2的正确处理。不需要缩放
    *尾数，因为在这种情况下它总是等于零。
   */
    uiq23Result += (LQ_UI_32BIT)ui16Exp << 16;
    return LQ_TI_UINT32_BITS_TO_FLOAT(uiq23Result);
}
/**@brief (TI方法)UINT8类型UQ8格式转浮点
* @details 采用估算位+指数位+符号位三位结合，能提高精度
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为浮点数
* @code*    LQ_TI_UINT8_UQ8_TO_FLOAT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_UINT8_UQ8_TO_FLOAT  TI方式UINT8的UQ8转化浮点类型\n
*     LQ_TI_UINT8_UQ7_TO_FLOAT  TI方式UINT8的UQ7转化浮点类型\n
*     LQ_TI_UINT8_UQ6_TO_FLOAT  TI方式UINT8的UQ6转化浮点类型\n
*     LQ_TI_UINT8_UQ5_TO_FLOAT  TI方式UINT8的UQ5转化浮点类型\n
*     LQ_TI_UINT8_UQ4_TO_FLOAT  TI方式UINT8的UQ4转化浮点类型\n
*     LQ_TI_UINT8_UQ3_TO_FLOAT  TI方式UINT8的UQ3转化浮点类型\n
*     LQ_TI_UINT8_UQ2_TO_FLOAT  TI方式UINT8的UQ2转化浮点类型\n
*     LQ_TI_UINT8_UQ1_TO_FLOAT  TI方式UINT8的UQ1转化浮点类型\n
*/
LQ_F_32BIT LQ_TI_UINT8_UQ8_TO_FLOAT(LQ_I_32BIT A, LQ_ERROR* lq_error)
{
    LQ_UI_16BIT ui16Exp;
    LQ_UI_32BIT uiq23Result;
    LQ_UI_32BIT uiq31Input;
    //!< 初始化指数部分偏移量
    ui16Exp = 19200;
    //!< 保存符号位
    if (A < 0)
    {
        ui16Exp |= 0x8000;
        uiq31Input = (LQ_UI_32BIT)(-(LQ_I_64BIT)A);
    }
    else if (A == 0)
    {
        return (0);
    }
    else
    {
        uiq31Input = A;
    }
    LQ_TI_Q2F_NORMALIZE(uiq31Input, ui16Exp);
    /*对uiq31结果进行四舍五入并切换到uiq23*/
    uiq23Result = (LQ_UI_32BIT)(((LQ_UI_64BIT)uiq31Input + 0x0080u) >> 8);
    if (uiq23Result >= 0x01000000u)
    {
        uiq23Result = 0;
        ui16Exp += 0x0080;
    }
    /*删除尾数的隐含MSB位 */
    uiq23Result &= ~0x00800000;
    /*
    *将构造的指数和符号位添加到尾数。我们必须使用
    *四舍五入会导致尾数溢出的情况下的加法。
    *当这种情况发生时，尾数结果为2，其中MSB为零
    *exp的LSB被设置为1。在指数上加一就是
    *尾数为2的正确处理。不需要缩放
    *尾数，因为在这种情况下它总是等于零。
   */
    uiq23Result += (LQ_UI_32BIT)ui16Exp << 16;
    return LQ_TI_UINT32_BITS_TO_FLOAT(uiq23Result);
}
/**@brief (TI方法)UINT8类型UQ7格式转浮点
* @details 采用估算位+指数位+符号位三位结合，能提高精度
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为浮点数
* @code*    LQ_TI_UINT8_UQ7_TO_FLOAT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_UINT8_UQ8_TO_FLOAT  TI方式UINT8的UQ8转化浮点类型\n
*     LQ_TI_UINT8_UQ7_TO_FLOAT  TI方式UINT8的UQ7转化浮点类型\n
*     LQ_TI_UINT8_UQ6_TO_FLOAT  TI方式UINT8的UQ6转化浮点类型\n
*     LQ_TI_UINT8_UQ5_TO_FLOAT  TI方式UINT8的UQ5转化浮点类型\n
*     LQ_TI_UINT8_UQ4_TO_FLOAT  TI方式UINT8的UQ4转化浮点类型\n
*     LQ_TI_UINT8_UQ3_TO_FLOAT  TI方式UINT8的UQ3转化浮点类型\n
*     LQ_TI_UINT8_UQ2_TO_FLOAT  TI方式UINT8的UQ2转化浮点类型\n
*     LQ_TI_UINT8_UQ1_TO_FLOAT  TI方式UINT8的UQ1转化浮点类型\n
*/
LQ_F_32BIT LQ_TI_UINT8_UQ7_TO_FLOAT(LQ_I_32BIT A, LQ_ERROR* lq_error)
{
    LQ_UI_16BIT ui16Exp;
    LQ_UI_32BIT uiq23Result;
    LQ_UI_32BIT uiq31Input;
    //!< 初始化指数部分偏移量
    ui16Exp = 19328;
    //!< 保存符号位
    if (A < 0)
    {
        ui16Exp |= 0x8000;
        uiq31Input = (LQ_UI_32BIT)(-(LQ_I_64BIT)A);
    }
    else if (A == 0)
    {
        return (0);
    }
    else
    {
        uiq31Input = A;
    }
    LQ_TI_Q2F_NORMALIZE(uiq31Input, ui16Exp);
    /*对uiq31结果进行四舍五入并切换到uiq23*/
    uiq23Result = (LQ_UI_32BIT)(((LQ_UI_64BIT)uiq31Input + 0x0080u) >> 8);
    if (uiq23Result >= 0x01000000u)
    {
        uiq23Result = 0;
        ui16Exp += 0x0080;
    }
    /*删除尾数的隐含MSB位 */
    uiq23Result &= ~0x00800000;
    /*
    *将构造的指数和符号位添加到尾数。我们必须使用
    *四舍五入会导致尾数溢出的情况下的加法。
    *当这种情况发生时，尾数结果为2，其中MSB为零
    *exp的LSB被设置为1。在指数上加一就是
    *尾数为2的正确处理。不需要缩放
    *尾数，因为在这种情况下它总是等于零。
   */
    uiq23Result += (LQ_UI_32BIT)ui16Exp << 16;
    return LQ_TI_UINT32_BITS_TO_FLOAT(uiq23Result);
}
/**@brief (TI方法)UINT8类型UQ6格式转浮点
* @details 采用估算位+指数位+符号位三位结合，能提高精度
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为浮点数
* @code*    LQ_TI_UINT8_UQ6_TO_FLOAT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_UINT8_UQ8_TO_FLOAT  TI方式UINT8的UQ8转化浮点类型\n
*     LQ_TI_UINT8_UQ7_TO_FLOAT  TI方式UINT8的UQ7转化浮点类型\n
*     LQ_TI_UINT8_UQ6_TO_FLOAT  TI方式UINT8的UQ6转化浮点类型\n
*     LQ_TI_UINT8_UQ5_TO_FLOAT  TI方式UINT8的UQ5转化浮点类型\n
*     LQ_TI_UINT8_UQ4_TO_FLOAT  TI方式UINT8的UQ4转化浮点类型\n
*     LQ_TI_UINT8_UQ3_TO_FLOAT  TI方式UINT8的UQ3转化浮点类型\n
*     LQ_TI_UINT8_UQ2_TO_FLOAT  TI方式UINT8的UQ2转化浮点类型\n
*     LQ_TI_UINT8_UQ1_TO_FLOAT  TI方式UINT8的UQ1转化浮点类型\n
*/
LQ_F_32BIT LQ_TI_UINT8_UQ6_TO_FLOAT(LQ_I_32BIT A, LQ_ERROR* lq_error)
{
    LQ_UI_16BIT ui16Exp;
    LQ_UI_32BIT uiq23Result;
    LQ_UI_32BIT uiq31Input;
    //!< 初始化指数部分偏移量
    ui16Exp = 19456;
    //!< 保存符号位
    if (A < 0)
    {
        ui16Exp |= 0x8000;
        uiq31Input = (LQ_UI_32BIT)(-(LQ_I_64BIT)A);
    }
    else if (A == 0)
    {
        return (0);
    }
    else
    {
        uiq31Input = A;
    }
    LQ_TI_Q2F_NORMALIZE(uiq31Input, ui16Exp);
    /*对uiq31结果进行四舍五入并切换到uiq23*/
    uiq23Result = (LQ_UI_32BIT)(((LQ_UI_64BIT)uiq31Input + 0x0080u) >> 8);
    if (uiq23Result >= 0x01000000u)
    {
        uiq23Result = 0;
        ui16Exp += 0x0080;
    }
    /*删除尾数的隐含MSB位 */
    uiq23Result &= ~0x00800000;
    /*
    *将构造的指数和符号位添加到尾数。我们必须使用
    *四舍五入会导致尾数溢出的情况下的加法。
    *当这种情况发生时，尾数结果为2，其中MSB为零
    *exp的LSB被设置为1。在指数上加一就是
    *尾数为2的正确处理。不需要缩放
    *尾数，因为在这种情况下它总是等于零。
   */
    uiq23Result += (LQ_UI_32BIT)ui16Exp << 16;
    return LQ_TI_UINT32_BITS_TO_FLOAT(uiq23Result);
}
/**@brief (TI方法)UINT8类型UQ5格式转浮点
* @details 采用估算位+指数位+符号位三位结合，能提高精度
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为浮点数
* @code*    LQ_TI_UINT8_UQ5_TO_FLOAT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_UINT8_UQ8_TO_FLOAT  TI方式UINT8的UQ8转化浮点类型\n
*     LQ_TI_UINT8_UQ7_TO_FLOAT  TI方式UINT8的UQ7转化浮点类型\n
*     LQ_TI_UINT8_UQ6_TO_FLOAT  TI方式UINT8的UQ6转化浮点类型\n
*     LQ_TI_UINT8_UQ5_TO_FLOAT  TI方式UINT8的UQ5转化浮点类型\n
*     LQ_TI_UINT8_UQ4_TO_FLOAT  TI方式UINT8的UQ4转化浮点类型\n
*     LQ_TI_UINT8_UQ3_TO_FLOAT  TI方式UINT8的UQ3转化浮点类型\n
*     LQ_TI_UINT8_UQ2_TO_FLOAT  TI方式UINT8的UQ2转化浮点类型\n
*     LQ_TI_UINT8_UQ1_TO_FLOAT  TI方式UINT8的UQ1转化浮点类型\n
*/
LQ_F_32BIT LQ_TI_UINT8_UQ5_TO_FLOAT(LQ_I_32BIT A, LQ_ERROR* lq_error)
{
    LQ_UI_16BIT ui16Exp;
    LQ_UI_32BIT uiq23Result;
    LQ_UI_32BIT uiq31Input;
    //!< 初始化指数部分偏移量
    ui16Exp = 19584;
    //!< 保存符号位
    if (A < 0)
    {
        ui16Exp |= 0x8000;
        uiq31Input = (LQ_UI_32BIT)(-(LQ_I_64BIT)A);
    }
    else if (A == 0)
    {
        return (0);
    }
    else
    {
        uiq31Input = A;
    }
    LQ_TI_Q2F_NORMALIZE(uiq31Input, ui16Exp);
    /*对uiq31结果进行四舍五入并切换到uiq23*/
    uiq23Result = (LQ_UI_32BIT)(((LQ_UI_64BIT)uiq31Input + 0x0080u) >> 8);
    if (uiq23Result >= 0x01000000u)
    {
        uiq23Result = 0;
        ui16Exp += 0x0080;
    }
    /*删除尾数的隐含MSB位 */
    uiq23Result &= ~0x00800000;
    /*
    *将构造的指数和符号位添加到尾数。我们必须使用
    *四舍五入会导致尾数溢出的情况下的加法。
    *当这种情况发生时，尾数结果为2，其中MSB为零
    *exp的LSB被设置为1。在指数上加一就是
    *尾数为2的正确处理。不需要缩放
    *尾数，因为在这种情况下它总是等于零。
   */
    uiq23Result += (LQ_UI_32BIT)ui16Exp << 16;
    return LQ_TI_UINT32_BITS_TO_FLOAT(uiq23Result);
}
/**@brief (TI方法)UINT8类型UQ4格式转浮点
* @details 采用估算位+指数位+符号位三位结合，能提高精度
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为浮点数
* @code*    LQ_TI_UINT8_UQ4_TO_FLOAT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_UINT8_UQ8_TO_FLOAT  TI方式UINT8的UQ8转化浮点类型\n
*     LQ_TI_UINT8_UQ7_TO_FLOAT  TI方式UINT8的UQ7转化浮点类型\n
*     LQ_TI_UINT8_UQ6_TO_FLOAT  TI方式UINT8的UQ6转化浮点类型\n
*     LQ_TI_UINT8_UQ5_TO_FLOAT  TI方式UINT8的UQ5转化浮点类型\n
*     LQ_TI_UINT8_UQ4_TO_FLOAT  TI方式UINT8的UQ4转化浮点类型\n
*     LQ_TI_UINT8_UQ3_TO_FLOAT  TI方式UINT8的UQ3转化浮点类型\n
*     LQ_TI_UINT8_UQ2_TO_FLOAT  TI方式UINT8的UQ2转化浮点类型\n
*     LQ_TI_UINT8_UQ1_TO_FLOAT  TI方式UINT8的UQ1转化浮点类型\n
*/
LQ_F_32BIT LQ_TI_UINT8_UQ4_TO_FLOAT(LQ_I_32BIT A, LQ_ERROR* lq_error)
{
    LQ_UI_16BIT ui16Exp;
    LQ_UI_32BIT uiq23Result;
    LQ_UI_32BIT uiq31Input;
    //!< 初始化指数部分偏移量
    ui16Exp = 19712;
    //!< 保存符号位
    if (A < 0)
    {
        ui16Exp |= 0x8000;
        uiq31Input = (LQ_UI_32BIT)(-(LQ_I_64BIT)A);
    }
    else if (A == 0)
    {
        return (0);
    }
    else
    {
        uiq31Input = A;
    }
    LQ_TI_Q2F_NORMALIZE(uiq31Input, ui16Exp);
    /*对uiq31结果进行四舍五入并切换到uiq23*/
    uiq23Result = (LQ_UI_32BIT)(((LQ_UI_64BIT)uiq31Input + 0x0080u) >> 8);
    if (uiq23Result >= 0x01000000u)
    {
        uiq23Result = 0;
        ui16Exp += 0x0080;
    }
    /*删除尾数的隐含MSB位 */
    uiq23Result &= ~0x00800000;
    /*
    *将构造的指数和符号位添加到尾数。我们必须使用
    *四舍五入会导致尾数溢出的情况下的加法。
    *当这种情况发生时，尾数结果为2，其中MSB为零
    *exp的LSB被设置为1。在指数上加一就是
    *尾数为2的正确处理。不需要缩放
    *尾数，因为在这种情况下它总是等于零。
   */
    uiq23Result += (LQ_UI_32BIT)ui16Exp << 16;
    return LQ_TI_UINT32_BITS_TO_FLOAT(uiq23Result);
}
/**@brief (TI方法)UINT8类型UQ3格式转浮点
* @details 采用估算位+指数位+符号位三位结合，能提高精度
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为浮点数
* @code*    LQ_TI_UINT8_UQ3_TO_FLOAT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_UINT8_UQ8_TO_FLOAT  TI方式UINT8的UQ8转化浮点类型\n
*     LQ_TI_UINT8_UQ7_TO_FLOAT  TI方式UINT8的UQ7转化浮点类型\n
*     LQ_TI_UINT8_UQ6_TO_FLOAT  TI方式UINT8的UQ6转化浮点类型\n
*     LQ_TI_UINT8_UQ5_TO_FLOAT  TI方式UINT8的UQ5转化浮点类型\n
*     LQ_TI_UINT8_UQ4_TO_FLOAT  TI方式UINT8的UQ4转化浮点类型\n
*     LQ_TI_UINT8_UQ3_TO_FLOAT  TI方式UINT8的UQ3转化浮点类型\n
*     LQ_TI_UINT8_UQ2_TO_FLOAT  TI方式UINT8的UQ2转化浮点类型\n
*     LQ_TI_UINT8_UQ1_TO_FLOAT  TI方式UINT8的UQ1转化浮点类型\n
*/
LQ_F_32BIT LQ_TI_UINT8_UQ3_TO_FLOAT(LQ_I_32BIT A, LQ_ERROR* lq_error)
{
    LQ_UI_16BIT ui16Exp;
    LQ_UI_32BIT uiq23Result;
    LQ_UI_32BIT uiq31Input;
    //!< 初始化指数部分偏移量
    ui16Exp = 19840;
    //!< 保存符号位
    if (A < 0)
    {
        ui16Exp |= 0x8000;
        uiq31Input = (LQ_UI_32BIT)(-(LQ_I_64BIT)A);
    }
    else if (A == 0)
    {
        return (0);
    }
    else
    {
        uiq31Input = A;
    }
    LQ_TI_Q2F_NORMALIZE(uiq31Input, ui16Exp);
    /*对uiq31结果进行四舍五入并切换到uiq23*/
    uiq23Result = (LQ_UI_32BIT)(((LQ_UI_64BIT)uiq31Input + 0x0080u) >> 8);
    if (uiq23Result >= 0x01000000u)
    {
        uiq23Result = 0;
        ui16Exp += 0x0080;
    }
    /*删除尾数的隐含MSB位 */
    uiq23Result &= ~0x00800000;
    /*
    *将构造的指数和符号位添加到尾数。我们必须使用
    *四舍五入会导致尾数溢出的情况下的加法。
    *当这种情况发生时，尾数结果为2，其中MSB为零
    *exp的LSB被设置为1。在指数上加一就是
    *尾数为2的正确处理。不需要缩放
    *尾数，因为在这种情况下它总是等于零。
   */
    uiq23Result += (LQ_UI_32BIT)ui16Exp << 16;
    return LQ_TI_UINT32_BITS_TO_FLOAT(uiq23Result);
}
/**@brief (TI方法)UINT8类型UQ2格式转浮点
* @details 采用估算位+指数位+符号位三位结合，能提高精度
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为浮点数
* @code*    LQ_TI_UINT8_UQ2_TO_FLOAT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_UINT8_UQ8_TO_FLOAT  TI方式UINT8的UQ8转化浮点类型\n
*     LQ_TI_UINT8_UQ7_TO_FLOAT  TI方式UINT8的UQ7转化浮点类型\n
*     LQ_TI_UINT8_UQ6_TO_FLOAT  TI方式UINT8的UQ6转化浮点类型\n
*     LQ_TI_UINT8_UQ5_TO_FLOAT  TI方式UINT8的UQ5转化浮点类型\n
*     LQ_TI_UINT8_UQ4_TO_FLOAT  TI方式UINT8的UQ4转化浮点类型\n
*     LQ_TI_UINT8_UQ3_TO_FLOAT  TI方式UINT8的UQ3转化浮点类型\n
*     LQ_TI_UINT8_UQ2_TO_FLOAT  TI方式UINT8的UQ2转化浮点类型\n
*     LQ_TI_UINT8_UQ1_TO_FLOAT  TI方式UINT8的UQ1转化浮点类型\n
*/
LQ_F_32BIT LQ_TI_UINT8_UQ2_TO_FLOAT(LQ_I_32BIT A, LQ_ERROR* lq_error)
{
    LQ_UI_16BIT ui16Exp;
    LQ_UI_32BIT uiq23Result;
    LQ_UI_32BIT uiq31Input;
    //!< 初始化指数部分偏移量
    ui16Exp = 19968;
    //!< 保存符号位
    if (A < 0)
    {
        ui16Exp |= 0x8000;
        uiq31Input = (LQ_UI_32BIT)(-(LQ_I_64BIT)A);
    }
    else if (A == 0)
    {
        return (0);
    }
    else
    {
        uiq31Input = A;
    }
    LQ_TI_Q2F_NORMALIZE(uiq31Input, ui16Exp);
    /*对uiq31结果进行四舍五入并切换到uiq23*/
    uiq23Result = (LQ_UI_32BIT)(((LQ_UI_64BIT)uiq31Input + 0x0080u) >> 8);
    if (uiq23Result >= 0x01000000u)
    {
        uiq23Result = 0;
        ui16Exp += 0x0080;
    }
    /*删除尾数的隐含MSB位 */
    uiq23Result &= ~0x00800000;
    /*
    *将构造的指数和符号位添加到尾数。我们必须使用
    *四舍五入会导致尾数溢出的情况下的加法。
    *当这种情况发生时，尾数结果为2，其中MSB为零
    *exp的LSB被设置为1。在指数上加一就是
    *尾数为2的正确处理。不需要缩放
    *尾数，因为在这种情况下它总是等于零。
   */
    uiq23Result += (LQ_UI_32BIT)ui16Exp << 16;
    return LQ_TI_UINT32_BITS_TO_FLOAT(uiq23Result);
}
/**@brief (TI方法)UINT8类型UQ1格式转浮点
* @details 采用估算位+指数位+符号位三位结合，能提高精度
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为浮点数
* @code*    LQ_TI_UINT8_UQ1_TO_FLOAT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_UINT8_UQ8_TO_FLOAT  TI方式UINT8的UQ8转化浮点类型\n
*     LQ_TI_UINT8_UQ7_TO_FLOAT  TI方式UINT8的UQ7转化浮点类型\n
*     LQ_TI_UINT8_UQ6_TO_FLOAT  TI方式UINT8的UQ6转化浮点类型\n
*     LQ_TI_UINT8_UQ5_TO_FLOAT  TI方式UINT8的UQ5转化浮点类型\n
*     LQ_TI_UINT8_UQ4_TO_FLOAT  TI方式UINT8的UQ4转化浮点类型\n
*     LQ_TI_UINT8_UQ3_TO_FLOAT  TI方式UINT8的UQ3转化浮点类型\n
*     LQ_TI_UINT8_UQ2_TO_FLOAT  TI方式UINT8的UQ2转化浮点类型\n
*     LQ_TI_UINT8_UQ1_TO_FLOAT  TI方式UINT8的UQ1转化浮点类型\n
*/
LQ_F_32BIT LQ_TI_UINT8_UQ1_TO_FLOAT(LQ_I_32BIT A, LQ_ERROR* lq_error)
{
    LQ_UI_16BIT ui16Exp;
    LQ_UI_32BIT uiq23Result;
    LQ_UI_32BIT uiq31Input;
    //!< 初始化指数部分偏移量
    ui16Exp = 20096;
    //!< 保存符号位
    if (A < 0)
    {
        ui16Exp |= 0x8000;
        uiq31Input = (LQ_UI_32BIT)(-(LQ_I_64BIT)A);
    }
    else if (A == 0)
    {
        return (0);
    }
    else
    {
        uiq31Input = A;
    }
    LQ_TI_Q2F_NORMALIZE(uiq31Input, ui16Exp);
    /*对uiq31结果进行四舍五入并切换到uiq23*/
    uiq23Result = (LQ_UI_32BIT)(((LQ_UI_64BIT)uiq31Input + 0x0080u) >> 8);
    if (uiq23Result >= 0x01000000u)
    {
        uiq23Result = 0;
        ui16Exp += 0x0080;
    }
    /*删除尾数的隐含MSB位 */
    uiq23Result &= ~0x00800000;
    /*
    *将构造的指数和符号位添加到尾数。我们必须使用
    *四舍五入会导致尾数溢出的情况下的加法。
    *当这种情况发生时，尾数结果为2，其中MSB为零
    *exp的LSB被设置为1。在指数上加一就是
    *尾数为2的正确处理。不需要缩放
    *尾数，因为在这种情况下它总是等于零。
   */
    uiq23Result += (LQ_UI_32BIT)ui16Exp << 16;
    return LQ_TI_UINT32_BITS_TO_FLOAT(uiq23Result);
}
/**@brief (TI方法)INT16类型Q15格式转浮点
* @details 采用估算位+指数位+符号位三位结合，能提高精度
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为浮点数
* @code*    LQ_TI_INT16_Q15_TO_FLOAT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_INT16_Q15_TO_FLOAT  TI方式INT16的Q15转化浮点类型\n
*     LQ_TI_INT16_Q14_TO_FLOAT  TI方式INT16的Q14转化浮点类型\n
*     LQ_TI_INT16_Q13_TO_FLOAT  TI方式INT16的Q13转化浮点类型\n
*     LQ_TI_INT16_Q12_TO_FLOAT  TI方式INT16的Q12转化浮点类型\n
*     LQ_TI_INT16_Q11_TO_FLOAT  TI方式INT16的Q11转化浮点类型\n
*     LQ_TI_INT16_Q10_TO_FLOAT  TI方式INT16的Q10转化浮点类型\n
*     LQ_TI_INT16_Q9_TO_FLOAT  TI方式INT16的Q9转化浮点类型\n
*     LQ_TI_INT16_Q8_TO_FLOAT  TI方式INT16的Q8转化浮点类型\n
*     LQ_TI_INT16_Q7_TO_FLOAT  TI方式INT16的Q7转化浮点类型\n
*     LQ_TI_INT16_Q6_TO_FLOAT  TI方式INT16的Q6转化浮点类型\n
*     LQ_TI_INT16_Q5_TO_FLOAT  TI方式INT16的Q5转化浮点类型\n
*     LQ_TI_INT16_Q4_TO_FLOAT  TI方式INT16的Q4转化浮点类型\n
*     LQ_TI_INT16_Q3_TO_FLOAT  TI方式INT16的Q3转化浮点类型\n
*     LQ_TI_INT16_Q2_TO_FLOAT  TI方式INT16的Q2转化浮点类型\n
*     LQ_TI_INT16_Q1_TO_FLOAT  TI方式INT16的Q1转化浮点类型\n
*/
LQ_F_32BIT LQ_TI_INT16_Q15_TO_FLOAT(LQ_I_32BIT A, LQ_ERROR* lq_error)
{
    LQ_UI_16BIT ui16Exp;
    LQ_UI_32BIT uiq23Result;
    LQ_UI_32BIT uiq31Input;
    //!< 初始化指数部分偏移量
    ui16Exp = 18304;
    //!< 保存符号位
    if (A < 0)
    {
        ui16Exp |= 0x8000;
        uiq31Input = (LQ_UI_32BIT)(-(LQ_I_64BIT)A);
    }
    else if (A == 0)
    {
        return (0);
    }
    else
    {
        uiq31Input = A;
    }
    LQ_TI_Q2F_NORMALIZE(uiq31Input, ui16Exp);
    /*对uiq31结果进行四舍五入并切换到uiq23*/
    uiq23Result = (LQ_UI_32BIT)(((LQ_UI_64BIT)uiq31Input + 0x0080u) >> 8);
    if (uiq23Result >= 0x01000000u)
    {
        uiq23Result = 0;
        ui16Exp += 0x0080;
    }
    /*删除尾数的隐含MSB位 */
    uiq23Result &= ~0x00800000;
    /*
    *将构造的指数和符号位添加到尾数。我们必须使用
    *四舍五入会导致尾数溢出的情况下的加法。
    *当这种情况发生时，尾数结果为2，其中MSB为零
    *exp的LSB被设置为1。在指数上加一就是
    *尾数为2的正确处理。不需要缩放
    *尾数，因为在这种情况下它总是等于零。
   */
    uiq23Result += (LQ_UI_32BIT)ui16Exp << 16;
    return LQ_TI_UINT32_BITS_TO_FLOAT(uiq23Result);
}
/**@brief (TI方法)INT16类型Q14格式转浮点
* @details 采用估算位+指数位+符号位三位结合，能提高精度
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为浮点数
* @code*    LQ_TI_INT16_Q14_TO_FLOAT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_INT16_Q15_TO_FLOAT  TI方式INT16的Q15转化浮点类型\n
*     LQ_TI_INT16_Q14_TO_FLOAT  TI方式INT16的Q14转化浮点类型\n
*     LQ_TI_INT16_Q13_TO_FLOAT  TI方式INT16的Q13转化浮点类型\n
*     LQ_TI_INT16_Q12_TO_FLOAT  TI方式INT16的Q12转化浮点类型\n
*     LQ_TI_INT16_Q11_TO_FLOAT  TI方式INT16的Q11转化浮点类型\n
*     LQ_TI_INT16_Q10_TO_FLOAT  TI方式INT16的Q10转化浮点类型\n
*     LQ_TI_INT16_Q9_TO_FLOAT  TI方式INT16的Q9转化浮点类型\n
*     LQ_TI_INT16_Q8_TO_FLOAT  TI方式INT16的Q8转化浮点类型\n
*     LQ_TI_INT16_Q7_TO_FLOAT  TI方式INT16的Q7转化浮点类型\n
*     LQ_TI_INT16_Q6_TO_FLOAT  TI方式INT16的Q6转化浮点类型\n
*     LQ_TI_INT16_Q5_TO_FLOAT  TI方式INT16的Q5转化浮点类型\n
*     LQ_TI_INT16_Q4_TO_FLOAT  TI方式INT16的Q4转化浮点类型\n
*     LQ_TI_INT16_Q3_TO_FLOAT  TI方式INT16的Q3转化浮点类型\n
*     LQ_TI_INT16_Q2_TO_FLOAT  TI方式INT16的Q2转化浮点类型\n
*     LQ_TI_INT16_Q1_TO_FLOAT  TI方式INT16的Q1转化浮点类型\n
*/
LQ_F_32BIT LQ_TI_INT16_Q14_TO_FLOAT(LQ_I_32BIT A, LQ_ERROR* lq_error)
{
    LQ_UI_16BIT ui16Exp;
    LQ_UI_32BIT uiq23Result;
    LQ_UI_32BIT uiq31Input;
    //!< 初始化指数部分偏移量
    ui16Exp = 18432;
    //!< 保存符号位
    if (A < 0)
    {
        ui16Exp |= 0x8000;
        uiq31Input = (LQ_UI_32BIT)(-(LQ_I_64BIT)A);
    }
    else if (A == 0)
    {
        return (0);
    }
    else
    {
        uiq31Input = A;
    }
    LQ_TI_Q2F_NORMALIZE(uiq31Input, ui16Exp);
    /*对uiq31结果进行四舍五入并切换到uiq23*/
    uiq23Result = (LQ_UI_32BIT)(((LQ_UI_64BIT)uiq31Input + 0x0080u) >> 8);
    if (uiq23Result >= 0x01000000u)
    {
        uiq23Result = 0;
        ui16Exp += 0x0080;
    }
    /*删除尾数的隐含MSB位 */
    uiq23Result &= ~0x00800000;
    /*
    *将构造的指数和符号位添加到尾数。我们必须使用
    *四舍五入会导致尾数溢出的情况下的加法。
    *当这种情况发生时，尾数结果为2，其中MSB为零
    *exp的LSB被设置为1。在指数上加一就是
    *尾数为2的正确处理。不需要缩放
    *尾数，因为在这种情况下它总是等于零。
   */
    uiq23Result += (LQ_UI_32BIT)ui16Exp << 16;
    return LQ_TI_UINT32_BITS_TO_FLOAT(uiq23Result);
}
/**@brief (TI方法)INT16类型Q13格式转浮点
* @details 采用估算位+指数位+符号位三位结合，能提高精度
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为浮点数
* @code*    LQ_TI_INT16_Q13_TO_FLOAT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_INT16_Q15_TO_FLOAT  TI方式INT16的Q15转化浮点类型\n
*     LQ_TI_INT16_Q14_TO_FLOAT  TI方式INT16的Q14转化浮点类型\n
*     LQ_TI_INT16_Q13_TO_FLOAT  TI方式INT16的Q13转化浮点类型\n
*     LQ_TI_INT16_Q12_TO_FLOAT  TI方式INT16的Q12转化浮点类型\n
*     LQ_TI_INT16_Q11_TO_FLOAT  TI方式INT16的Q11转化浮点类型\n
*     LQ_TI_INT16_Q10_TO_FLOAT  TI方式INT16的Q10转化浮点类型\n
*     LQ_TI_INT16_Q9_TO_FLOAT  TI方式INT16的Q9转化浮点类型\n
*     LQ_TI_INT16_Q8_TO_FLOAT  TI方式INT16的Q8转化浮点类型\n
*     LQ_TI_INT16_Q7_TO_FLOAT  TI方式INT16的Q7转化浮点类型\n
*     LQ_TI_INT16_Q6_TO_FLOAT  TI方式INT16的Q6转化浮点类型\n
*     LQ_TI_INT16_Q5_TO_FLOAT  TI方式INT16的Q5转化浮点类型\n
*     LQ_TI_INT16_Q4_TO_FLOAT  TI方式INT16的Q4转化浮点类型\n
*     LQ_TI_INT16_Q3_TO_FLOAT  TI方式INT16的Q3转化浮点类型\n
*     LQ_TI_INT16_Q2_TO_FLOAT  TI方式INT16的Q2转化浮点类型\n
*     LQ_TI_INT16_Q1_TO_FLOAT  TI方式INT16的Q1转化浮点类型\n
*/
LQ_F_32BIT LQ_TI_INT16_Q13_TO_FLOAT(LQ_I_32BIT A, LQ_ERROR* lq_error)
{
    LQ_UI_16BIT ui16Exp;
    LQ_UI_32BIT uiq23Result;
    LQ_UI_32BIT uiq31Input;
    //!< 初始化指数部分偏移量
    ui16Exp = 18560;
    //!< 保存符号位
    if (A < 0)
    {
        ui16Exp |= 0x8000;
        uiq31Input = (LQ_UI_32BIT)(-(LQ_I_64BIT)A);
    }
    else if (A == 0)
    {
        return (0);
    }
    else
    {
        uiq31Input = A;
    }
    LQ_TI_Q2F_NORMALIZE(uiq31Input, ui16Exp);
    /*对uiq31结果进行四舍五入并切换到uiq23*/
    uiq23Result = (LQ_UI_32BIT)(((LQ_UI_64BIT)uiq31Input + 0x0080u) >> 8);
    if (uiq23Result >= 0x01000000u)
    {
        uiq23Result = 0;
        ui16Exp += 0x0080;
    }
    /*删除尾数的隐含MSB位 */
    uiq23Result &= ~0x00800000;
    /*
    *将构造的指数和符号位添加到尾数。我们必须使用
    *四舍五入会导致尾数溢出的情况下的加法。
    *当这种情况发生时，尾数结果为2，其中MSB为零
    *exp的LSB被设置为1。在指数上加一就是
    *尾数为2的正确处理。不需要缩放
    *尾数，因为在这种情况下它总是等于零。
   */
    uiq23Result += (LQ_UI_32BIT)ui16Exp << 16;
    return LQ_TI_UINT32_BITS_TO_FLOAT(uiq23Result);
}
/**@brief (TI方法)INT16类型Q12格式转浮点
* @details 采用估算位+指数位+符号位三位结合，能提高精度
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为浮点数
* @code*    LQ_TI_INT16_Q12_TO_FLOAT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_INT16_Q15_TO_FLOAT  TI方式INT16的Q15转化浮点类型\n
*     LQ_TI_INT16_Q14_TO_FLOAT  TI方式INT16的Q14转化浮点类型\n
*     LQ_TI_INT16_Q13_TO_FLOAT  TI方式INT16的Q13转化浮点类型\n
*     LQ_TI_INT16_Q12_TO_FLOAT  TI方式INT16的Q12转化浮点类型\n
*     LQ_TI_INT16_Q11_TO_FLOAT  TI方式INT16的Q11转化浮点类型\n
*     LQ_TI_INT16_Q10_TO_FLOAT  TI方式INT16的Q10转化浮点类型\n
*     LQ_TI_INT16_Q9_TO_FLOAT  TI方式INT16的Q9转化浮点类型\n
*     LQ_TI_INT16_Q8_TO_FLOAT  TI方式INT16的Q8转化浮点类型\n
*     LQ_TI_INT16_Q7_TO_FLOAT  TI方式INT16的Q7转化浮点类型\n
*     LQ_TI_INT16_Q6_TO_FLOAT  TI方式INT16的Q6转化浮点类型\n
*     LQ_TI_INT16_Q5_TO_FLOAT  TI方式INT16的Q5转化浮点类型\n
*     LQ_TI_INT16_Q4_TO_FLOAT  TI方式INT16的Q4转化浮点类型\n
*     LQ_TI_INT16_Q3_TO_FLOAT  TI方式INT16的Q3转化浮点类型\n
*     LQ_TI_INT16_Q2_TO_FLOAT  TI方式INT16的Q2转化浮点类型\n
*     LQ_TI_INT16_Q1_TO_FLOAT  TI方式INT16的Q1转化浮点类型\n
*/
LQ_F_32BIT LQ_TI_INT16_Q12_TO_FLOAT(LQ_I_32BIT A, LQ_ERROR* lq_error)
{
    LQ_UI_16BIT ui16Exp;
    LQ_UI_32BIT uiq23Result;
    LQ_UI_32BIT uiq31Input;
    //!< 初始化指数部分偏移量
    ui16Exp = 18688;
    //!< 保存符号位
    if (A < 0)
    {
        ui16Exp |= 0x8000;
        uiq31Input = (LQ_UI_32BIT)(-(LQ_I_64BIT)A);
    }
    else if (A == 0)
    {
        return (0);
    }
    else
    {
        uiq31Input = A;
    }
    LQ_TI_Q2F_NORMALIZE(uiq31Input, ui16Exp);
    /*对uiq31结果进行四舍五入并切换到uiq23*/
    uiq23Result = (LQ_UI_32BIT)(((LQ_UI_64BIT)uiq31Input + 0x0080u) >> 8);
    if (uiq23Result >= 0x01000000u)
    {
        uiq23Result = 0;
        ui16Exp += 0x0080;
    }
    /*删除尾数的隐含MSB位 */
    uiq23Result &= ~0x00800000;
    /*
    *将构造的指数和符号位添加到尾数。我们必须使用
    *四舍五入会导致尾数溢出的情况下的加法。
    *当这种情况发生时，尾数结果为2，其中MSB为零
    *exp的LSB被设置为1。在指数上加一就是
    *尾数为2的正确处理。不需要缩放
    *尾数，因为在这种情况下它总是等于零。
   */
    uiq23Result += (LQ_UI_32BIT)ui16Exp << 16;
    return LQ_TI_UINT32_BITS_TO_FLOAT(uiq23Result);
}
/**@brief (TI方法)INT16类型Q11格式转浮点
* @details 采用估算位+指数位+符号位三位结合，能提高精度
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为浮点数
* @code*    LQ_TI_INT16_Q11_TO_FLOAT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_INT16_Q15_TO_FLOAT  TI方式INT16的Q15转化浮点类型\n
*     LQ_TI_INT16_Q14_TO_FLOAT  TI方式INT16的Q14转化浮点类型\n
*     LQ_TI_INT16_Q13_TO_FLOAT  TI方式INT16的Q13转化浮点类型\n
*     LQ_TI_INT16_Q12_TO_FLOAT  TI方式INT16的Q12转化浮点类型\n
*     LQ_TI_INT16_Q11_TO_FLOAT  TI方式INT16的Q11转化浮点类型\n
*     LQ_TI_INT16_Q10_TO_FLOAT  TI方式INT16的Q10转化浮点类型\n
*     LQ_TI_INT16_Q9_TO_FLOAT  TI方式INT16的Q9转化浮点类型\n
*     LQ_TI_INT16_Q8_TO_FLOAT  TI方式INT16的Q8转化浮点类型\n
*     LQ_TI_INT16_Q7_TO_FLOAT  TI方式INT16的Q7转化浮点类型\n
*     LQ_TI_INT16_Q6_TO_FLOAT  TI方式INT16的Q6转化浮点类型\n
*     LQ_TI_INT16_Q5_TO_FLOAT  TI方式INT16的Q5转化浮点类型\n
*     LQ_TI_INT16_Q4_TO_FLOAT  TI方式INT16的Q4转化浮点类型\n
*     LQ_TI_INT16_Q3_TO_FLOAT  TI方式INT16的Q3转化浮点类型\n
*     LQ_TI_INT16_Q2_TO_FLOAT  TI方式INT16的Q2转化浮点类型\n
*     LQ_TI_INT16_Q1_TO_FLOAT  TI方式INT16的Q1转化浮点类型\n
*/
LQ_F_32BIT LQ_TI_INT16_Q11_TO_FLOAT(LQ_I_32BIT A, LQ_ERROR* lq_error)
{
    LQ_UI_16BIT ui16Exp;
    LQ_UI_32BIT uiq23Result;
    LQ_UI_32BIT uiq31Input;
    //!< 初始化指数部分偏移量
    ui16Exp = 18816;
    //!< 保存符号位
    if (A < 0)
    {
        ui16Exp |= 0x8000;
        uiq31Input = (LQ_UI_32BIT)(-(LQ_I_64BIT)A);
    }
    else if (A == 0)
    {
        return (0);
    }
    else
    {
        uiq31Input = A;
    }
    LQ_TI_Q2F_NORMALIZE(uiq31Input, ui16Exp);
    /*对uiq31结果进行四舍五入并切换到uiq23*/
    uiq23Result = (LQ_UI_32BIT)(((LQ_UI_64BIT)uiq31Input + 0x0080u) >> 8);
    if (uiq23Result >= 0x01000000u)
    {
        uiq23Result = 0;
        ui16Exp += 0x0080;
    }
    /*删除尾数的隐含MSB位 */
    uiq23Result &= ~0x00800000;
    /*
    *将构造的指数和符号位添加到尾数。我们必须使用
    *四舍五入会导致尾数溢出的情况下的加法。
    *当这种情况发生时，尾数结果为2，其中MSB为零
    *exp的LSB被设置为1。在指数上加一就是
    *尾数为2的正确处理。不需要缩放
    *尾数，因为在这种情况下它总是等于零。
   */
    uiq23Result += (LQ_UI_32BIT)ui16Exp << 16;
    return LQ_TI_UINT32_BITS_TO_FLOAT(uiq23Result);
}
/**@brief (TI方法)INT16类型Q10格式转浮点
* @details 采用估算位+指数位+符号位三位结合，能提高精度
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为浮点数
* @code*    LQ_TI_INT16_Q10_TO_FLOAT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_INT16_Q15_TO_FLOAT  TI方式INT16的Q15转化浮点类型\n
*     LQ_TI_INT16_Q14_TO_FLOAT  TI方式INT16的Q14转化浮点类型\n
*     LQ_TI_INT16_Q13_TO_FLOAT  TI方式INT16的Q13转化浮点类型\n
*     LQ_TI_INT16_Q12_TO_FLOAT  TI方式INT16的Q12转化浮点类型\n
*     LQ_TI_INT16_Q11_TO_FLOAT  TI方式INT16的Q11转化浮点类型\n
*     LQ_TI_INT16_Q10_TO_FLOAT  TI方式INT16的Q10转化浮点类型\n
*     LQ_TI_INT16_Q9_TO_FLOAT  TI方式INT16的Q9转化浮点类型\n
*     LQ_TI_INT16_Q8_TO_FLOAT  TI方式INT16的Q8转化浮点类型\n
*     LQ_TI_INT16_Q7_TO_FLOAT  TI方式INT16的Q7转化浮点类型\n
*     LQ_TI_INT16_Q6_TO_FLOAT  TI方式INT16的Q6转化浮点类型\n
*     LQ_TI_INT16_Q5_TO_FLOAT  TI方式INT16的Q5转化浮点类型\n
*     LQ_TI_INT16_Q4_TO_FLOAT  TI方式INT16的Q4转化浮点类型\n
*     LQ_TI_INT16_Q3_TO_FLOAT  TI方式INT16的Q3转化浮点类型\n
*     LQ_TI_INT16_Q2_TO_FLOAT  TI方式INT16的Q2转化浮点类型\n
*     LQ_TI_INT16_Q1_TO_FLOAT  TI方式INT16的Q1转化浮点类型\n
*/
LQ_F_32BIT LQ_TI_INT16_Q10_TO_FLOAT(LQ_I_32BIT A, LQ_ERROR* lq_error)
{
    LQ_UI_16BIT ui16Exp;
    LQ_UI_32BIT uiq23Result;
    LQ_UI_32BIT uiq31Input;
    //!< 初始化指数部分偏移量
    ui16Exp = 18944;
    //!< 保存符号位
    if (A < 0)
    {
        ui16Exp |= 0x8000;
        uiq31Input = (LQ_UI_32BIT)(-(LQ_I_64BIT)A);
    }
    else if (A == 0)
    {
        return (0);
    }
    else
    {
        uiq31Input = A;
    }
    LQ_TI_Q2F_NORMALIZE(uiq31Input, ui16Exp);
    /*对uiq31结果进行四舍五入并切换到uiq23*/
    uiq23Result = (LQ_UI_32BIT)(((LQ_UI_64BIT)uiq31Input + 0x0080u) >> 8);
    if (uiq23Result >= 0x01000000u)
    {
        uiq23Result = 0;
        ui16Exp += 0x0080;
    }
    /*删除尾数的隐含MSB位 */
    uiq23Result &= ~0x00800000;
    /*
    *将构造的指数和符号位添加到尾数。我们必须使用
    *四舍五入会导致尾数溢出的情况下的加法。
    *当这种情况发生时，尾数结果为2，其中MSB为零
    *exp的LSB被设置为1。在指数上加一就是
    *尾数为2的正确处理。不需要缩放
    *尾数，因为在这种情况下它总是等于零。
   */
    uiq23Result += (LQ_UI_32BIT)ui16Exp << 16;
    return LQ_TI_UINT32_BITS_TO_FLOAT(uiq23Result);
}
/**@brief (TI方法)INT16类型Q9格式转浮点
* @details 采用估算位+指数位+符号位三位结合，能提高精度
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为浮点数
* @code*    LQ_TI_INT16_Q9_TO_FLOAT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_INT16_Q15_TO_FLOAT  TI方式INT16的Q15转化浮点类型\n
*     LQ_TI_INT16_Q14_TO_FLOAT  TI方式INT16的Q14转化浮点类型\n
*     LQ_TI_INT16_Q13_TO_FLOAT  TI方式INT16的Q13转化浮点类型\n
*     LQ_TI_INT16_Q12_TO_FLOAT  TI方式INT16的Q12转化浮点类型\n
*     LQ_TI_INT16_Q11_TO_FLOAT  TI方式INT16的Q11转化浮点类型\n
*     LQ_TI_INT16_Q10_TO_FLOAT  TI方式INT16的Q10转化浮点类型\n
*     LQ_TI_INT16_Q9_TO_FLOAT  TI方式INT16的Q9转化浮点类型\n
*     LQ_TI_INT16_Q8_TO_FLOAT  TI方式INT16的Q8转化浮点类型\n
*     LQ_TI_INT16_Q7_TO_FLOAT  TI方式INT16的Q7转化浮点类型\n
*     LQ_TI_INT16_Q6_TO_FLOAT  TI方式INT16的Q6转化浮点类型\n
*     LQ_TI_INT16_Q5_TO_FLOAT  TI方式INT16的Q5转化浮点类型\n
*     LQ_TI_INT16_Q4_TO_FLOAT  TI方式INT16的Q4转化浮点类型\n
*     LQ_TI_INT16_Q3_TO_FLOAT  TI方式INT16的Q3转化浮点类型\n
*     LQ_TI_INT16_Q2_TO_FLOAT  TI方式INT16的Q2转化浮点类型\n
*     LQ_TI_INT16_Q1_TO_FLOAT  TI方式INT16的Q1转化浮点类型\n
*/
LQ_F_32BIT LQ_TI_INT16_Q9_TO_FLOAT(LQ_I_32BIT A, LQ_ERROR* lq_error)
{
    LQ_UI_16BIT ui16Exp;
    LQ_UI_32BIT uiq23Result;
    LQ_UI_32BIT uiq31Input;
    //!< 初始化指数部分偏移量
    ui16Exp = 19072;
    //!< 保存符号位
    if (A < 0)
    {
        ui16Exp |= 0x8000;
        uiq31Input = (LQ_UI_32BIT)(-(LQ_I_64BIT)A);
    }
    else if (A == 0)
    {
        return (0);
    }
    else
    {
        uiq31Input = A;
    }
    LQ_TI_Q2F_NORMALIZE(uiq31Input, ui16Exp);
    /*对uiq31结果进行四舍五入并切换到uiq23*/
    uiq23Result = (LQ_UI_32BIT)(((LQ_UI_64BIT)uiq31Input + 0x0080u) >> 8);
    if (uiq23Result >= 0x01000000u)
    {
        uiq23Result = 0;
        ui16Exp += 0x0080;
    }
    /*删除尾数的隐含MSB位 */
    uiq23Result &= ~0x00800000;
    /*
    *将构造的指数和符号位添加到尾数。我们必须使用
    *四舍五入会导致尾数溢出的情况下的加法。
    *当这种情况发生时，尾数结果为2，其中MSB为零
    *exp的LSB被设置为1。在指数上加一就是
    *尾数为2的正确处理。不需要缩放
    *尾数，因为在这种情况下它总是等于零。
   */
    uiq23Result += (LQ_UI_32BIT)ui16Exp << 16;
    return LQ_TI_UINT32_BITS_TO_FLOAT(uiq23Result);
}
/**@brief (TI方法)INT16类型Q8格式转浮点
* @details 采用估算位+指数位+符号位三位结合，能提高精度
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为浮点数
* @code*    LQ_TI_INT16_Q8_TO_FLOAT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_INT16_Q15_TO_FLOAT  TI方式INT16的Q15转化浮点类型\n
*     LQ_TI_INT16_Q14_TO_FLOAT  TI方式INT16的Q14转化浮点类型\n
*     LQ_TI_INT16_Q13_TO_FLOAT  TI方式INT16的Q13转化浮点类型\n
*     LQ_TI_INT16_Q12_TO_FLOAT  TI方式INT16的Q12转化浮点类型\n
*     LQ_TI_INT16_Q11_TO_FLOAT  TI方式INT16的Q11转化浮点类型\n
*     LQ_TI_INT16_Q10_TO_FLOAT  TI方式INT16的Q10转化浮点类型\n
*     LQ_TI_INT16_Q9_TO_FLOAT  TI方式INT16的Q9转化浮点类型\n
*     LQ_TI_INT16_Q8_TO_FLOAT  TI方式INT16的Q8转化浮点类型\n
*     LQ_TI_INT16_Q7_TO_FLOAT  TI方式INT16的Q7转化浮点类型\n
*     LQ_TI_INT16_Q6_TO_FLOAT  TI方式INT16的Q6转化浮点类型\n
*     LQ_TI_INT16_Q5_TO_FLOAT  TI方式INT16的Q5转化浮点类型\n
*     LQ_TI_INT16_Q4_TO_FLOAT  TI方式INT16的Q4转化浮点类型\n
*     LQ_TI_INT16_Q3_TO_FLOAT  TI方式INT16的Q3转化浮点类型\n
*     LQ_TI_INT16_Q2_TO_FLOAT  TI方式INT16的Q2转化浮点类型\n
*     LQ_TI_INT16_Q1_TO_FLOAT  TI方式INT16的Q1转化浮点类型\n
*/
LQ_F_32BIT LQ_TI_INT16_Q8_TO_FLOAT(LQ_I_32BIT A, LQ_ERROR* lq_error)
{
    LQ_UI_16BIT ui16Exp;
    LQ_UI_32BIT uiq23Result;
    LQ_UI_32BIT uiq31Input;
    //!< 初始化指数部分偏移量
    ui16Exp = 19200;
    //!< 保存符号位
    if (A < 0)
    {
        ui16Exp |= 0x8000;
        uiq31Input = (LQ_UI_32BIT)(-(LQ_I_64BIT)A);
    }
    else if (A == 0)
    {
        return (0);
    }
    else
    {
        uiq31Input = A;
    }
    LQ_TI_Q2F_NORMALIZE(uiq31Input, ui16Exp);
    /*对uiq31结果进行四舍五入并切换到uiq23*/
    uiq23Result = (LQ_UI_32BIT)(((LQ_UI_64BIT)uiq31Input + 0x0080u) >> 8);
    if (uiq23Result >= 0x01000000u)
    {
        uiq23Result = 0;
        ui16Exp += 0x0080;
    }
    /*删除尾数的隐含MSB位 */
    uiq23Result &= ~0x00800000;
    /*
    *将构造的指数和符号位添加到尾数。我们必须使用
    *四舍五入会导致尾数溢出的情况下的加法。
    *当这种情况发生时，尾数结果为2，其中MSB为零
    *exp的LSB被设置为1。在指数上加一就是
    *尾数为2的正确处理。不需要缩放
    *尾数，因为在这种情况下它总是等于零。
   */
    uiq23Result += (LQ_UI_32BIT)ui16Exp << 16;
    return LQ_TI_UINT32_BITS_TO_FLOAT(uiq23Result);
}
/**@brief (TI方法)INT16类型Q7格式转浮点
* @details 采用估算位+指数位+符号位三位结合，能提高精度
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为浮点数
* @code*    LQ_TI_INT16_Q7_TO_FLOAT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_INT16_Q15_TO_FLOAT  TI方式INT16的Q15转化浮点类型\n
*     LQ_TI_INT16_Q14_TO_FLOAT  TI方式INT16的Q14转化浮点类型\n
*     LQ_TI_INT16_Q13_TO_FLOAT  TI方式INT16的Q13转化浮点类型\n
*     LQ_TI_INT16_Q12_TO_FLOAT  TI方式INT16的Q12转化浮点类型\n
*     LQ_TI_INT16_Q11_TO_FLOAT  TI方式INT16的Q11转化浮点类型\n
*     LQ_TI_INT16_Q10_TO_FLOAT  TI方式INT16的Q10转化浮点类型\n
*     LQ_TI_INT16_Q9_TO_FLOAT  TI方式INT16的Q9转化浮点类型\n
*     LQ_TI_INT16_Q8_TO_FLOAT  TI方式INT16的Q8转化浮点类型\n
*     LQ_TI_INT16_Q7_TO_FLOAT  TI方式INT16的Q7转化浮点类型\n
*     LQ_TI_INT16_Q6_TO_FLOAT  TI方式INT16的Q6转化浮点类型\n
*     LQ_TI_INT16_Q5_TO_FLOAT  TI方式INT16的Q5转化浮点类型\n
*     LQ_TI_INT16_Q4_TO_FLOAT  TI方式INT16的Q4转化浮点类型\n
*     LQ_TI_INT16_Q3_TO_FLOAT  TI方式INT16的Q3转化浮点类型\n
*     LQ_TI_INT16_Q2_TO_FLOAT  TI方式INT16的Q2转化浮点类型\n
*     LQ_TI_INT16_Q1_TO_FLOAT  TI方式INT16的Q1转化浮点类型\n
*/
LQ_F_32BIT LQ_TI_INT16_Q7_TO_FLOAT(LQ_I_32BIT A, LQ_ERROR* lq_error)
{
    LQ_UI_16BIT ui16Exp;
    LQ_UI_32BIT uiq23Result;
    LQ_UI_32BIT uiq31Input;
    //!< 初始化指数部分偏移量
    ui16Exp = 19328;
    //!< 保存符号位
    if (A < 0)
    {
        ui16Exp |= 0x8000;
        uiq31Input = (LQ_UI_32BIT)(-(LQ_I_64BIT)A);
    }
    else if (A == 0)
    {
        return (0);
    }
    else
    {
        uiq31Input = A;
    }
    LQ_TI_Q2F_NORMALIZE(uiq31Input, ui16Exp);
    /*对uiq31结果进行四舍五入并切换到uiq23*/
    uiq23Result = (LQ_UI_32BIT)(((LQ_UI_64BIT)uiq31Input + 0x0080u) >> 8);
    if (uiq23Result >= 0x01000000u)
    {
        uiq23Result = 0;
        ui16Exp += 0x0080;
    }
    /*删除尾数的隐含MSB位 */
    uiq23Result &= ~0x00800000;
    /*
    *将构造的指数和符号位添加到尾数。我们必须使用
    *四舍五入会导致尾数溢出的情况下的加法。
    *当这种情况发生时，尾数结果为2，其中MSB为零
    *exp的LSB被设置为1。在指数上加一就是
    *尾数为2的正确处理。不需要缩放
    *尾数，因为在这种情况下它总是等于零。
   */
    uiq23Result += (LQ_UI_32BIT)ui16Exp << 16;
    return LQ_TI_UINT32_BITS_TO_FLOAT(uiq23Result);
}
/**@brief (TI方法)INT16类型Q6格式转浮点
* @details 采用估算位+指数位+符号位三位结合，能提高精度
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为浮点数
* @code*    LQ_TI_INT16_Q6_TO_FLOAT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_INT16_Q15_TO_FLOAT  TI方式INT16的Q15转化浮点类型\n
*     LQ_TI_INT16_Q14_TO_FLOAT  TI方式INT16的Q14转化浮点类型\n
*     LQ_TI_INT16_Q13_TO_FLOAT  TI方式INT16的Q13转化浮点类型\n
*     LQ_TI_INT16_Q12_TO_FLOAT  TI方式INT16的Q12转化浮点类型\n
*     LQ_TI_INT16_Q11_TO_FLOAT  TI方式INT16的Q11转化浮点类型\n
*     LQ_TI_INT16_Q10_TO_FLOAT  TI方式INT16的Q10转化浮点类型\n
*     LQ_TI_INT16_Q9_TO_FLOAT  TI方式INT16的Q9转化浮点类型\n
*     LQ_TI_INT16_Q8_TO_FLOAT  TI方式INT16的Q8转化浮点类型\n
*     LQ_TI_INT16_Q7_TO_FLOAT  TI方式INT16的Q7转化浮点类型\n
*     LQ_TI_INT16_Q6_TO_FLOAT  TI方式INT16的Q6转化浮点类型\n
*     LQ_TI_INT16_Q5_TO_FLOAT  TI方式INT16的Q5转化浮点类型\n
*     LQ_TI_INT16_Q4_TO_FLOAT  TI方式INT16的Q4转化浮点类型\n
*     LQ_TI_INT16_Q3_TO_FLOAT  TI方式INT16的Q3转化浮点类型\n
*     LQ_TI_INT16_Q2_TO_FLOAT  TI方式INT16的Q2转化浮点类型\n
*     LQ_TI_INT16_Q1_TO_FLOAT  TI方式INT16的Q1转化浮点类型\n
*/
LQ_F_32BIT LQ_TI_INT16_Q6_TO_FLOAT(LQ_I_32BIT A, LQ_ERROR* lq_error)
{
    LQ_UI_16BIT ui16Exp;
    LQ_UI_32BIT uiq23Result;
    LQ_UI_32BIT uiq31Input;
    //!< 初始化指数部分偏移量
    ui16Exp = 19456;
    //!< 保存符号位
    if (A < 0)
    {
        ui16Exp |= 0x8000;
        uiq31Input = (LQ_UI_32BIT)(-(LQ_I_64BIT)A);
    }
    else if (A == 0)
    {
        return (0);
    }
    else
    {
        uiq31Input = A;
    }
    LQ_TI_Q2F_NORMALIZE(uiq31Input, ui16Exp);
    /*对uiq31结果进行四舍五入并切换到uiq23*/
    uiq23Result = (LQ_UI_32BIT)(((LQ_UI_64BIT)uiq31Input + 0x0080u) >> 8);
    if (uiq23Result >= 0x01000000u)
    {
        uiq23Result = 0;
        ui16Exp += 0x0080;
    }
    /*删除尾数的隐含MSB位 */
    uiq23Result &= ~0x00800000;
    /*
    *将构造的指数和符号位添加到尾数。我们必须使用
    *四舍五入会导致尾数溢出的情况下的加法。
    *当这种情况发生时，尾数结果为2，其中MSB为零
    *exp的LSB被设置为1。在指数上加一就是
    *尾数为2的正确处理。不需要缩放
    *尾数，因为在这种情况下它总是等于零。
   */
    uiq23Result += (LQ_UI_32BIT)ui16Exp << 16;
    return LQ_TI_UINT32_BITS_TO_FLOAT(uiq23Result);
}
/**@brief (TI方法)INT16类型Q5格式转浮点
* @details 采用估算位+指数位+符号位三位结合，能提高精度
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为浮点数
* @code*    LQ_TI_INT16_Q5_TO_FLOAT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_INT16_Q15_TO_FLOAT  TI方式INT16的Q15转化浮点类型\n
*     LQ_TI_INT16_Q14_TO_FLOAT  TI方式INT16的Q14转化浮点类型\n
*     LQ_TI_INT16_Q13_TO_FLOAT  TI方式INT16的Q13转化浮点类型\n
*     LQ_TI_INT16_Q12_TO_FLOAT  TI方式INT16的Q12转化浮点类型\n
*     LQ_TI_INT16_Q11_TO_FLOAT  TI方式INT16的Q11转化浮点类型\n
*     LQ_TI_INT16_Q10_TO_FLOAT  TI方式INT16的Q10转化浮点类型\n
*     LQ_TI_INT16_Q9_TO_FLOAT  TI方式INT16的Q9转化浮点类型\n
*     LQ_TI_INT16_Q8_TO_FLOAT  TI方式INT16的Q8转化浮点类型\n
*     LQ_TI_INT16_Q7_TO_FLOAT  TI方式INT16的Q7转化浮点类型\n
*     LQ_TI_INT16_Q6_TO_FLOAT  TI方式INT16的Q6转化浮点类型\n
*     LQ_TI_INT16_Q5_TO_FLOAT  TI方式INT16的Q5转化浮点类型\n
*     LQ_TI_INT16_Q4_TO_FLOAT  TI方式INT16的Q4转化浮点类型\n
*     LQ_TI_INT16_Q3_TO_FLOAT  TI方式INT16的Q3转化浮点类型\n
*     LQ_TI_INT16_Q2_TO_FLOAT  TI方式INT16的Q2转化浮点类型\n
*     LQ_TI_INT16_Q1_TO_FLOAT  TI方式INT16的Q1转化浮点类型\n
*/
LQ_F_32BIT LQ_TI_INT16_Q5_TO_FLOAT(LQ_I_32BIT A, LQ_ERROR* lq_error)
{
    LQ_UI_16BIT ui16Exp;
    LQ_UI_32BIT uiq23Result;
    LQ_UI_32BIT uiq31Input;
    //!< 初始化指数部分偏移量
    ui16Exp = 19584;
    //!< 保存符号位
    if (A < 0)
    {
        ui16Exp |= 0x8000;
        uiq31Input = (LQ_UI_32BIT)(-(LQ_I_64BIT)A);
    }
    else if (A == 0)
    {
        return (0);
    }
    else
    {
        uiq31Input = A;
    }
    LQ_TI_Q2F_NORMALIZE(uiq31Input, ui16Exp);
    /*对uiq31结果进行四舍五入并切换到uiq23*/
    uiq23Result = (LQ_UI_32BIT)(((LQ_UI_64BIT)uiq31Input + 0x0080u) >> 8);
    if (uiq23Result >= 0x01000000u)
    {
        uiq23Result = 0;
        ui16Exp += 0x0080;
    }
    /*删除尾数的隐含MSB位 */
    uiq23Result &= ~0x00800000;
    /*
    *将构造的指数和符号位添加到尾数。我们必须使用
    *四舍五入会导致尾数溢出的情况下的加法。
    *当这种情况发生时，尾数结果为2，其中MSB为零
    *exp的LSB被设置为1。在指数上加一就是
    *尾数为2的正确处理。不需要缩放
    *尾数，因为在这种情况下它总是等于零。
   */
    uiq23Result += (LQ_UI_32BIT)ui16Exp << 16;
    return LQ_TI_UINT32_BITS_TO_FLOAT(uiq23Result);
}
/**@brief (TI方法)INT16类型Q4格式转浮点
* @details 采用估算位+指数位+符号位三位结合，能提高精度
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为浮点数
* @code*    LQ_TI_INT16_Q4_TO_FLOAT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_INT16_Q15_TO_FLOAT  TI方式INT16的Q15转化浮点类型\n
*     LQ_TI_INT16_Q14_TO_FLOAT  TI方式INT16的Q14转化浮点类型\n
*     LQ_TI_INT16_Q13_TO_FLOAT  TI方式INT16的Q13转化浮点类型\n
*     LQ_TI_INT16_Q12_TO_FLOAT  TI方式INT16的Q12转化浮点类型\n
*     LQ_TI_INT16_Q11_TO_FLOAT  TI方式INT16的Q11转化浮点类型\n
*     LQ_TI_INT16_Q10_TO_FLOAT  TI方式INT16的Q10转化浮点类型\n
*     LQ_TI_INT16_Q9_TO_FLOAT  TI方式INT16的Q9转化浮点类型\n
*     LQ_TI_INT16_Q8_TO_FLOAT  TI方式INT16的Q8转化浮点类型\n
*     LQ_TI_INT16_Q7_TO_FLOAT  TI方式INT16的Q7转化浮点类型\n
*     LQ_TI_INT16_Q6_TO_FLOAT  TI方式INT16的Q6转化浮点类型\n
*     LQ_TI_INT16_Q5_TO_FLOAT  TI方式INT16的Q5转化浮点类型\n
*     LQ_TI_INT16_Q4_TO_FLOAT  TI方式INT16的Q4转化浮点类型\n
*     LQ_TI_INT16_Q3_TO_FLOAT  TI方式INT16的Q3转化浮点类型\n
*     LQ_TI_INT16_Q2_TO_FLOAT  TI方式INT16的Q2转化浮点类型\n
*     LQ_TI_INT16_Q1_TO_FLOAT  TI方式INT16的Q1转化浮点类型\n
*/
LQ_F_32BIT LQ_TI_INT16_Q4_TO_FLOAT(LQ_I_32BIT A, LQ_ERROR* lq_error)
{
    LQ_UI_16BIT ui16Exp;
    LQ_UI_32BIT uiq23Result;
    LQ_UI_32BIT uiq31Input;
    //!< 初始化指数部分偏移量
    ui16Exp = 19712;
    //!< 保存符号位
    if (A < 0)
    {
        ui16Exp |= 0x8000;
        uiq31Input = (LQ_UI_32BIT)(-(LQ_I_64BIT)A);
    }
    else if (A == 0)
    {
        return (0);
    }
    else
    {
        uiq31Input = A;
    }
    LQ_TI_Q2F_NORMALIZE(uiq31Input, ui16Exp);
    /*对uiq31结果进行四舍五入并切换到uiq23*/
    uiq23Result = (LQ_UI_32BIT)(((LQ_UI_64BIT)uiq31Input + 0x0080u) >> 8);
    if (uiq23Result >= 0x01000000u)
    {
        uiq23Result = 0;
        ui16Exp += 0x0080;
    }
    /*删除尾数的隐含MSB位 */
    uiq23Result &= ~0x00800000;
    /*
    *将构造的指数和符号位添加到尾数。我们必须使用
    *四舍五入会导致尾数溢出的情况下的加法。
    *当这种情况发生时，尾数结果为2，其中MSB为零
    *exp的LSB被设置为1。在指数上加一就是
    *尾数为2的正确处理。不需要缩放
    *尾数，因为在这种情况下它总是等于零。
   */
    uiq23Result += (LQ_UI_32BIT)ui16Exp << 16;
    return LQ_TI_UINT32_BITS_TO_FLOAT(uiq23Result);
}
/**@brief (TI方法)INT16类型Q3格式转浮点
* @details 采用估算位+指数位+符号位三位结合，能提高精度
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为浮点数
* @code*    LQ_TI_INT16_Q3_TO_FLOAT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_INT16_Q15_TO_FLOAT  TI方式INT16的Q15转化浮点类型\n
*     LQ_TI_INT16_Q14_TO_FLOAT  TI方式INT16的Q14转化浮点类型\n
*     LQ_TI_INT16_Q13_TO_FLOAT  TI方式INT16的Q13转化浮点类型\n
*     LQ_TI_INT16_Q12_TO_FLOAT  TI方式INT16的Q12转化浮点类型\n
*     LQ_TI_INT16_Q11_TO_FLOAT  TI方式INT16的Q11转化浮点类型\n
*     LQ_TI_INT16_Q10_TO_FLOAT  TI方式INT16的Q10转化浮点类型\n
*     LQ_TI_INT16_Q9_TO_FLOAT  TI方式INT16的Q9转化浮点类型\n
*     LQ_TI_INT16_Q8_TO_FLOAT  TI方式INT16的Q8转化浮点类型\n
*     LQ_TI_INT16_Q7_TO_FLOAT  TI方式INT16的Q7转化浮点类型\n
*     LQ_TI_INT16_Q6_TO_FLOAT  TI方式INT16的Q6转化浮点类型\n
*     LQ_TI_INT16_Q5_TO_FLOAT  TI方式INT16的Q5转化浮点类型\n
*     LQ_TI_INT16_Q4_TO_FLOAT  TI方式INT16的Q4转化浮点类型\n
*     LQ_TI_INT16_Q3_TO_FLOAT  TI方式INT16的Q3转化浮点类型\n
*     LQ_TI_INT16_Q2_TO_FLOAT  TI方式INT16的Q2转化浮点类型\n
*     LQ_TI_INT16_Q1_TO_FLOAT  TI方式INT16的Q1转化浮点类型\n
*/
LQ_F_32BIT LQ_TI_INT16_Q3_TO_FLOAT(LQ_I_32BIT A, LQ_ERROR* lq_error)
{
    LQ_UI_16BIT ui16Exp;
    LQ_UI_32BIT uiq23Result;
    LQ_UI_32BIT uiq31Input;
    //!< 初始化指数部分偏移量
    ui16Exp = 19840;
    //!< 保存符号位
    if (A < 0)
    {
        ui16Exp |= 0x8000;
        uiq31Input = (LQ_UI_32BIT)(-(LQ_I_64BIT)A);
    }
    else if (A == 0)
    {
        return (0);
    }
    else
    {
        uiq31Input = A;
    }
    LQ_TI_Q2F_NORMALIZE(uiq31Input, ui16Exp);
    /*对uiq31结果进行四舍五入并切换到uiq23*/
    uiq23Result = (LQ_UI_32BIT)(((LQ_UI_64BIT)uiq31Input + 0x0080u) >> 8);
    if (uiq23Result >= 0x01000000u)
    {
        uiq23Result = 0;
        ui16Exp += 0x0080;
    }
    /*删除尾数的隐含MSB位 */
    uiq23Result &= ~0x00800000;
    /*
    *将构造的指数和符号位添加到尾数。我们必须使用
    *四舍五入会导致尾数溢出的情况下的加法。
    *当这种情况发生时，尾数结果为2，其中MSB为零
    *exp的LSB被设置为1。在指数上加一就是
    *尾数为2的正确处理。不需要缩放
    *尾数，因为在这种情况下它总是等于零。
   */
    uiq23Result += (LQ_UI_32BIT)ui16Exp << 16;
    return LQ_TI_UINT32_BITS_TO_FLOAT(uiq23Result);
}
/**@brief (TI方法)INT16类型Q2格式转浮点
* @details 采用估算位+指数位+符号位三位结合，能提高精度
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为浮点数
* @code*    LQ_TI_INT16_Q2_TO_FLOAT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_INT16_Q15_TO_FLOAT  TI方式INT16的Q15转化浮点类型\n
*     LQ_TI_INT16_Q14_TO_FLOAT  TI方式INT16的Q14转化浮点类型\n
*     LQ_TI_INT16_Q13_TO_FLOAT  TI方式INT16的Q13转化浮点类型\n
*     LQ_TI_INT16_Q12_TO_FLOAT  TI方式INT16的Q12转化浮点类型\n
*     LQ_TI_INT16_Q11_TO_FLOAT  TI方式INT16的Q11转化浮点类型\n
*     LQ_TI_INT16_Q10_TO_FLOAT  TI方式INT16的Q10转化浮点类型\n
*     LQ_TI_INT16_Q9_TO_FLOAT  TI方式INT16的Q9转化浮点类型\n
*     LQ_TI_INT16_Q8_TO_FLOAT  TI方式INT16的Q8转化浮点类型\n
*     LQ_TI_INT16_Q7_TO_FLOAT  TI方式INT16的Q7转化浮点类型\n
*     LQ_TI_INT16_Q6_TO_FLOAT  TI方式INT16的Q6转化浮点类型\n
*     LQ_TI_INT16_Q5_TO_FLOAT  TI方式INT16的Q5转化浮点类型\n
*     LQ_TI_INT16_Q4_TO_FLOAT  TI方式INT16的Q4转化浮点类型\n
*     LQ_TI_INT16_Q3_TO_FLOAT  TI方式INT16的Q3转化浮点类型\n
*     LQ_TI_INT16_Q2_TO_FLOAT  TI方式INT16的Q2转化浮点类型\n
*     LQ_TI_INT16_Q1_TO_FLOAT  TI方式INT16的Q1转化浮点类型\n
*/
LQ_F_32BIT LQ_TI_INT16_Q2_TO_FLOAT(LQ_I_32BIT A, LQ_ERROR* lq_error)
{
    LQ_UI_16BIT ui16Exp;
    LQ_UI_32BIT uiq23Result;
    LQ_UI_32BIT uiq31Input;
    //!< 初始化指数部分偏移量
    ui16Exp = 19968;
    //!< 保存符号位
    if (A < 0)
    {
        ui16Exp |= 0x8000;
        uiq31Input = (LQ_UI_32BIT)(-(LQ_I_64BIT)A);
    }
    else if (A == 0)
    {
        return (0);
    }
    else
    {
        uiq31Input = A;
    }
    LQ_TI_Q2F_NORMALIZE(uiq31Input, ui16Exp);
    /*对uiq31结果进行四舍五入并切换到uiq23*/
    uiq23Result = (LQ_UI_32BIT)(((LQ_UI_64BIT)uiq31Input + 0x0080u) >> 8);
    if (uiq23Result >= 0x01000000u)
    {
        uiq23Result = 0;
        ui16Exp += 0x0080;
    }
    /*删除尾数的隐含MSB位 */
    uiq23Result &= ~0x00800000;
    /*
    *将构造的指数和符号位添加到尾数。我们必须使用
    *四舍五入会导致尾数溢出的情况下的加法。
    *当这种情况发生时，尾数结果为2，其中MSB为零
    *exp的LSB被设置为1。在指数上加一就是
    *尾数为2的正确处理。不需要缩放
    *尾数，因为在这种情况下它总是等于零。
   */
    uiq23Result += (LQ_UI_32BIT)ui16Exp << 16;
    return LQ_TI_UINT32_BITS_TO_FLOAT(uiq23Result);
}
/**@brief (TI方法)INT16类型Q1格式转浮点
* @details 采用估算位+指数位+符号位三位结合，能提高精度
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为浮点数
* @code*    LQ_TI_INT16_Q1_TO_FLOAT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_INT16_Q15_TO_FLOAT  TI方式INT16的Q15转化浮点类型\n
*     LQ_TI_INT16_Q14_TO_FLOAT  TI方式INT16的Q14转化浮点类型\n
*     LQ_TI_INT16_Q13_TO_FLOAT  TI方式INT16的Q13转化浮点类型\n
*     LQ_TI_INT16_Q12_TO_FLOAT  TI方式INT16的Q12转化浮点类型\n
*     LQ_TI_INT16_Q11_TO_FLOAT  TI方式INT16的Q11转化浮点类型\n
*     LQ_TI_INT16_Q10_TO_FLOAT  TI方式INT16的Q10转化浮点类型\n
*     LQ_TI_INT16_Q9_TO_FLOAT  TI方式INT16的Q9转化浮点类型\n
*     LQ_TI_INT16_Q8_TO_FLOAT  TI方式INT16的Q8转化浮点类型\n
*     LQ_TI_INT16_Q7_TO_FLOAT  TI方式INT16的Q7转化浮点类型\n
*     LQ_TI_INT16_Q6_TO_FLOAT  TI方式INT16的Q6转化浮点类型\n
*     LQ_TI_INT16_Q5_TO_FLOAT  TI方式INT16的Q5转化浮点类型\n
*     LQ_TI_INT16_Q4_TO_FLOAT  TI方式INT16的Q4转化浮点类型\n
*     LQ_TI_INT16_Q3_TO_FLOAT  TI方式INT16的Q3转化浮点类型\n
*     LQ_TI_INT16_Q2_TO_FLOAT  TI方式INT16的Q2转化浮点类型\n
*     LQ_TI_INT16_Q1_TO_FLOAT  TI方式INT16的Q1转化浮点类型\n
*/
LQ_F_32BIT LQ_TI_INT16_Q1_TO_FLOAT(LQ_I_32BIT A, LQ_ERROR* lq_error)
{
    LQ_UI_16BIT ui16Exp;
    LQ_UI_32BIT uiq23Result;
    LQ_UI_32BIT uiq31Input;
    //!< 初始化指数部分偏移量
    ui16Exp = 20096;
    //!< 保存符号位
    if (A < 0)
    {
        ui16Exp |= 0x8000;
        uiq31Input = (LQ_UI_32BIT)(-(LQ_I_64BIT)A);
    }
    else if (A == 0)
    {
        return (0);
    }
    else
    {
        uiq31Input = A;
    }
    LQ_TI_Q2F_NORMALIZE(uiq31Input, ui16Exp);
    /*对uiq31结果进行四舍五入并切换到uiq23*/
    uiq23Result = (LQ_UI_32BIT)(((LQ_UI_64BIT)uiq31Input + 0x0080u) >> 8);
    if (uiq23Result >= 0x01000000u)
    {
        uiq23Result = 0;
        ui16Exp += 0x0080;
    }
    /*删除尾数的隐含MSB位 */
    uiq23Result &= ~0x00800000;
    /*
    *将构造的指数和符号位添加到尾数。我们必须使用
    *四舍五入会导致尾数溢出的情况下的加法。
    *当这种情况发生时，尾数结果为2，其中MSB为零
    *exp的LSB被设置为1。在指数上加一就是
    *尾数为2的正确处理。不需要缩放
    *尾数，因为在这种情况下它总是等于零。
   */
    uiq23Result += (LQ_UI_32BIT)ui16Exp << 16;
    return LQ_TI_UINT32_BITS_TO_FLOAT(uiq23Result);
}
/**@brief (TI方法)UINT16类型UQ16格式转浮点
* @details 采用估算位+指数位+符号位三位结合，能提高精度
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为浮点数
* @code*    LQ_TI_UINT16_UQ16_TO_FLOAT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_UINT16_UQ16_TO_FLOAT  TI方式UINT16的UQ16转化浮点类型\n
*     LQ_TI_UINT16_UQ15_TO_FLOAT  TI方式UINT16的UQ15转化浮点类型\n
*     LQ_TI_UINT16_UQ14_TO_FLOAT  TI方式UINT16的UQ14转化浮点类型\n
*     LQ_TI_UINT16_UQ13_TO_FLOAT  TI方式UINT16的UQ13转化浮点类型\n
*     LQ_TI_UINT16_UQ12_TO_FLOAT  TI方式UINT16的UQ12转化浮点类型\n
*     LQ_TI_UINT16_UQ11_TO_FLOAT  TI方式UINT16的UQ11转化浮点类型\n
*     LQ_TI_UINT16_UQ10_TO_FLOAT  TI方式UINT16的UQ10转化浮点类型\n
*     LQ_TI_UINT16_UQ9_TO_FLOAT  TI方式UINT16的UQ9转化浮点类型\n
*     LQ_TI_UINT16_UQ8_TO_FLOAT  TI方式UINT16的UQ8转化浮点类型\n
*     LQ_TI_UINT16_UQ7_TO_FLOAT  TI方式UINT16的UQ7转化浮点类型\n
*     LQ_TI_UINT16_UQ6_TO_FLOAT  TI方式UINT16的UQ6转化浮点类型\n
*     LQ_TI_UINT16_UQ5_TO_FLOAT  TI方式UINT16的UQ5转化浮点类型\n
*     LQ_TI_UINT16_UQ4_TO_FLOAT  TI方式UINT16的UQ4转化浮点类型\n
*     LQ_TI_UINT16_UQ3_TO_FLOAT  TI方式UINT16的UQ3转化浮点类型\n
*     LQ_TI_UINT16_UQ2_TO_FLOAT  TI方式UINT16的UQ2转化浮点类型\n
*     LQ_TI_UINT16_UQ1_TO_FLOAT  TI方式UINT16的UQ1转化浮点类型\n
*/
LQ_F_32BIT LQ_TI_UINT16_UQ16_TO_FLOAT(LQ_I_32BIT A, LQ_ERROR* lq_error)
{
    LQ_UI_16BIT ui16Exp;
    LQ_UI_32BIT uiq23Result;
    LQ_UI_32BIT uiq31Input;
    //!< 初始化指数部分偏移量
    ui16Exp = 18176;
    //!< 保存符号位
    if (A < 0)
    {
        ui16Exp |= 0x8000;
        uiq31Input = (LQ_UI_32BIT)(-(LQ_I_64BIT)A);
    }
    else if (A == 0)
    {
        return (0);
    }
    else
    {
        uiq31Input = A;
    }
    LQ_TI_Q2F_NORMALIZE(uiq31Input, ui16Exp);
    /*对uiq31结果进行四舍五入并切换到uiq23*/
    uiq23Result = (LQ_UI_32BIT)(((LQ_UI_64BIT)uiq31Input + 0x0080u) >> 8);
    if (uiq23Result >= 0x01000000u)
    {
        uiq23Result = 0;
        ui16Exp += 0x0080;
    }
    /*删除尾数的隐含MSB位 */
    uiq23Result &= ~0x00800000;
    /*
    *将构造的指数和符号位添加到尾数。我们必须使用
    *四舍五入会导致尾数溢出的情况下的加法。
    *当这种情况发生时，尾数结果为2，其中MSB为零
    *exp的LSB被设置为1。在指数上加一就是
    *尾数为2的正确处理。不需要缩放
    *尾数，因为在这种情况下它总是等于零。
   */
    uiq23Result += (LQ_UI_32BIT)ui16Exp << 16;
    return LQ_TI_UINT32_BITS_TO_FLOAT(uiq23Result);
}
/**@brief (TI方法)UINT16类型UQ15格式转浮点
* @details 采用估算位+指数位+符号位三位结合，能提高精度
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为浮点数
* @code*    LQ_TI_UINT16_UQ15_TO_FLOAT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_UINT16_UQ16_TO_FLOAT  TI方式UINT16的UQ16转化浮点类型\n
*     LQ_TI_UINT16_UQ15_TO_FLOAT  TI方式UINT16的UQ15转化浮点类型\n
*     LQ_TI_UINT16_UQ14_TO_FLOAT  TI方式UINT16的UQ14转化浮点类型\n
*     LQ_TI_UINT16_UQ13_TO_FLOAT  TI方式UINT16的UQ13转化浮点类型\n
*     LQ_TI_UINT16_UQ12_TO_FLOAT  TI方式UINT16的UQ12转化浮点类型\n
*     LQ_TI_UINT16_UQ11_TO_FLOAT  TI方式UINT16的UQ11转化浮点类型\n
*     LQ_TI_UINT16_UQ10_TO_FLOAT  TI方式UINT16的UQ10转化浮点类型\n
*     LQ_TI_UINT16_UQ9_TO_FLOAT  TI方式UINT16的UQ9转化浮点类型\n
*     LQ_TI_UINT16_UQ8_TO_FLOAT  TI方式UINT16的UQ8转化浮点类型\n
*     LQ_TI_UINT16_UQ7_TO_FLOAT  TI方式UINT16的UQ7转化浮点类型\n
*     LQ_TI_UINT16_UQ6_TO_FLOAT  TI方式UINT16的UQ6转化浮点类型\n
*     LQ_TI_UINT16_UQ5_TO_FLOAT  TI方式UINT16的UQ5转化浮点类型\n
*     LQ_TI_UINT16_UQ4_TO_FLOAT  TI方式UINT16的UQ4转化浮点类型\n
*     LQ_TI_UINT16_UQ3_TO_FLOAT  TI方式UINT16的UQ3转化浮点类型\n
*     LQ_TI_UINT16_UQ2_TO_FLOAT  TI方式UINT16的UQ2转化浮点类型\n
*     LQ_TI_UINT16_UQ1_TO_FLOAT  TI方式UINT16的UQ1转化浮点类型\n
*/
LQ_F_32BIT LQ_TI_UINT16_UQ15_TO_FLOAT(LQ_I_32BIT A, LQ_ERROR* lq_error)
{
    LQ_UI_16BIT ui16Exp;
    LQ_UI_32BIT uiq23Result;
    LQ_UI_32BIT uiq31Input;
    //!< 初始化指数部分偏移量
    ui16Exp = 18304;
    //!< 保存符号位
    if (A < 0)
    {
        ui16Exp |= 0x8000;
        uiq31Input = (LQ_UI_32BIT)(-(LQ_I_64BIT)A);
    }
    else if (A == 0)
    {
        return (0);
    }
    else
    {
        uiq31Input = A;
    }
    LQ_TI_Q2F_NORMALIZE(uiq31Input, ui16Exp);
    /*对uiq31结果进行四舍五入并切换到uiq23*/
    uiq23Result = (LQ_UI_32BIT)(((LQ_UI_64BIT)uiq31Input + 0x0080u) >> 8);
    if (uiq23Result >= 0x01000000u)
    {
        uiq23Result = 0;
        ui16Exp += 0x0080;
    }
    /*删除尾数的隐含MSB位 */
    uiq23Result &= ~0x00800000;
    /*
    *将构造的指数和符号位添加到尾数。我们必须使用
    *四舍五入会导致尾数溢出的情况下的加法。
    *当这种情况发生时，尾数结果为2，其中MSB为零
    *exp的LSB被设置为1。在指数上加一就是
    *尾数为2的正确处理。不需要缩放
    *尾数，因为在这种情况下它总是等于零。
   */
    uiq23Result += (LQ_UI_32BIT)ui16Exp << 16;
    return LQ_TI_UINT32_BITS_TO_FLOAT(uiq23Result);
}
/**@brief (TI方法)UINT16类型UQ14格式转浮点
* @details 采用估算位+指数位+符号位三位结合，能提高精度
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为浮点数
* @code*    LQ_TI_UINT16_UQ14_TO_FLOAT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_UINT16_UQ16_TO_FLOAT  TI方式UINT16的UQ16转化浮点类型\n
*     LQ_TI_UINT16_UQ15_TO_FLOAT  TI方式UINT16的UQ15转化浮点类型\n
*     LQ_TI_UINT16_UQ14_TO_FLOAT  TI方式UINT16的UQ14转化浮点类型\n
*     LQ_TI_UINT16_UQ13_TO_FLOAT  TI方式UINT16的UQ13转化浮点类型\n
*     LQ_TI_UINT16_UQ12_TO_FLOAT  TI方式UINT16的UQ12转化浮点类型\n
*     LQ_TI_UINT16_UQ11_TO_FLOAT  TI方式UINT16的UQ11转化浮点类型\n
*     LQ_TI_UINT16_UQ10_TO_FLOAT  TI方式UINT16的UQ10转化浮点类型\n
*     LQ_TI_UINT16_UQ9_TO_FLOAT  TI方式UINT16的UQ9转化浮点类型\n
*     LQ_TI_UINT16_UQ8_TO_FLOAT  TI方式UINT16的UQ8转化浮点类型\n
*     LQ_TI_UINT16_UQ7_TO_FLOAT  TI方式UINT16的UQ7转化浮点类型\n
*     LQ_TI_UINT16_UQ6_TO_FLOAT  TI方式UINT16的UQ6转化浮点类型\n
*     LQ_TI_UINT16_UQ5_TO_FLOAT  TI方式UINT16的UQ5转化浮点类型\n
*     LQ_TI_UINT16_UQ4_TO_FLOAT  TI方式UINT16的UQ4转化浮点类型\n
*     LQ_TI_UINT16_UQ3_TO_FLOAT  TI方式UINT16的UQ3转化浮点类型\n
*     LQ_TI_UINT16_UQ2_TO_FLOAT  TI方式UINT16的UQ2转化浮点类型\n
*     LQ_TI_UINT16_UQ1_TO_FLOAT  TI方式UINT16的UQ1转化浮点类型\n
*/
LQ_F_32BIT LQ_TI_UINT16_UQ14_TO_FLOAT(LQ_I_32BIT A, LQ_ERROR* lq_error)
{
    LQ_UI_16BIT ui16Exp;
    LQ_UI_32BIT uiq23Result;
    LQ_UI_32BIT uiq31Input;
    //!< 初始化指数部分偏移量
    ui16Exp = 18432;
    //!< 保存符号位
    if (A < 0)
    {
        ui16Exp |= 0x8000;
        uiq31Input = (LQ_UI_32BIT)(-(LQ_I_64BIT)A);
    }
    else if (A == 0)
    {
        return (0);
    }
    else
    {
        uiq31Input = A;
    }
    LQ_TI_Q2F_NORMALIZE(uiq31Input, ui16Exp);
    /*对uiq31结果进行四舍五入并切换到uiq23*/
    uiq23Result = (LQ_UI_32BIT)(((LQ_UI_64BIT)uiq31Input + 0x0080u) >> 8);
    if (uiq23Result >= 0x01000000u)
    {
        uiq23Result = 0;
        ui16Exp += 0x0080;
    }
    /*删除尾数的隐含MSB位 */
    uiq23Result &= ~0x00800000;
    /*
    *将构造的指数和符号位添加到尾数。我们必须使用
    *四舍五入会导致尾数溢出的情况下的加法。
    *当这种情况发生时，尾数结果为2，其中MSB为零
    *exp的LSB被设置为1。在指数上加一就是
    *尾数为2的正确处理。不需要缩放
    *尾数，因为在这种情况下它总是等于零。
   */
    uiq23Result += (LQ_UI_32BIT)ui16Exp << 16;
    return LQ_TI_UINT32_BITS_TO_FLOAT(uiq23Result);
}
/**@brief (TI方法)UINT16类型UQ13格式转浮点
* @details 采用估算位+指数位+符号位三位结合，能提高精度
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为浮点数
* @code*    LQ_TI_UINT16_UQ13_TO_FLOAT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_UINT16_UQ16_TO_FLOAT  TI方式UINT16的UQ16转化浮点类型\n
*     LQ_TI_UINT16_UQ15_TO_FLOAT  TI方式UINT16的UQ15转化浮点类型\n
*     LQ_TI_UINT16_UQ14_TO_FLOAT  TI方式UINT16的UQ14转化浮点类型\n
*     LQ_TI_UINT16_UQ13_TO_FLOAT  TI方式UINT16的UQ13转化浮点类型\n
*     LQ_TI_UINT16_UQ12_TO_FLOAT  TI方式UINT16的UQ12转化浮点类型\n
*     LQ_TI_UINT16_UQ11_TO_FLOAT  TI方式UINT16的UQ11转化浮点类型\n
*     LQ_TI_UINT16_UQ10_TO_FLOAT  TI方式UINT16的UQ10转化浮点类型\n
*     LQ_TI_UINT16_UQ9_TO_FLOAT  TI方式UINT16的UQ9转化浮点类型\n
*     LQ_TI_UINT16_UQ8_TO_FLOAT  TI方式UINT16的UQ8转化浮点类型\n
*     LQ_TI_UINT16_UQ7_TO_FLOAT  TI方式UINT16的UQ7转化浮点类型\n
*     LQ_TI_UINT16_UQ6_TO_FLOAT  TI方式UINT16的UQ6转化浮点类型\n
*     LQ_TI_UINT16_UQ5_TO_FLOAT  TI方式UINT16的UQ5转化浮点类型\n
*     LQ_TI_UINT16_UQ4_TO_FLOAT  TI方式UINT16的UQ4转化浮点类型\n
*     LQ_TI_UINT16_UQ3_TO_FLOAT  TI方式UINT16的UQ3转化浮点类型\n
*     LQ_TI_UINT16_UQ2_TO_FLOAT  TI方式UINT16的UQ2转化浮点类型\n
*     LQ_TI_UINT16_UQ1_TO_FLOAT  TI方式UINT16的UQ1转化浮点类型\n
*/
LQ_F_32BIT LQ_TI_UINT16_UQ13_TO_FLOAT(LQ_I_32BIT A, LQ_ERROR* lq_error)
{
    LQ_UI_16BIT ui16Exp;
    LQ_UI_32BIT uiq23Result;
    LQ_UI_32BIT uiq31Input;
    //!< 初始化指数部分偏移量
    ui16Exp = 18560;
    //!< 保存符号位
    if (A < 0)
    {
        ui16Exp |= 0x8000;
        uiq31Input = (LQ_UI_32BIT)(-(LQ_I_64BIT)A);
    }
    else if (A == 0)
    {
        return (0);
    }
    else
    {
        uiq31Input = A;
    }
    LQ_TI_Q2F_NORMALIZE(uiq31Input, ui16Exp);
    /*对uiq31结果进行四舍五入并切换到uiq23*/
    uiq23Result = (LQ_UI_32BIT)(((LQ_UI_64BIT)uiq31Input + 0x0080u) >> 8);
    if (uiq23Result >= 0x01000000u)
    {
        uiq23Result = 0;
        ui16Exp += 0x0080;
    }
    /*删除尾数的隐含MSB位 */
    uiq23Result &= ~0x00800000;
    /*
    *将构造的指数和符号位添加到尾数。我们必须使用
    *四舍五入会导致尾数溢出的情况下的加法。
    *当这种情况发生时，尾数结果为2，其中MSB为零
    *exp的LSB被设置为1。在指数上加一就是
    *尾数为2的正确处理。不需要缩放
    *尾数，因为在这种情况下它总是等于零。
   */
    uiq23Result += (LQ_UI_32BIT)ui16Exp << 16;
    return LQ_TI_UINT32_BITS_TO_FLOAT(uiq23Result);
}
/**@brief (TI方法)UINT16类型UQ12格式转浮点
* @details 采用估算位+指数位+符号位三位结合，能提高精度
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为浮点数
* @code*    LQ_TI_UINT16_UQ12_TO_FLOAT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_UINT16_UQ16_TO_FLOAT  TI方式UINT16的UQ16转化浮点类型\n
*     LQ_TI_UINT16_UQ15_TO_FLOAT  TI方式UINT16的UQ15转化浮点类型\n
*     LQ_TI_UINT16_UQ14_TO_FLOAT  TI方式UINT16的UQ14转化浮点类型\n
*     LQ_TI_UINT16_UQ13_TO_FLOAT  TI方式UINT16的UQ13转化浮点类型\n
*     LQ_TI_UINT16_UQ12_TO_FLOAT  TI方式UINT16的UQ12转化浮点类型\n
*     LQ_TI_UINT16_UQ11_TO_FLOAT  TI方式UINT16的UQ11转化浮点类型\n
*     LQ_TI_UINT16_UQ10_TO_FLOAT  TI方式UINT16的UQ10转化浮点类型\n
*     LQ_TI_UINT16_UQ9_TO_FLOAT  TI方式UINT16的UQ9转化浮点类型\n
*     LQ_TI_UINT16_UQ8_TO_FLOAT  TI方式UINT16的UQ8转化浮点类型\n
*     LQ_TI_UINT16_UQ7_TO_FLOAT  TI方式UINT16的UQ7转化浮点类型\n
*     LQ_TI_UINT16_UQ6_TO_FLOAT  TI方式UINT16的UQ6转化浮点类型\n
*     LQ_TI_UINT16_UQ5_TO_FLOAT  TI方式UINT16的UQ5转化浮点类型\n
*     LQ_TI_UINT16_UQ4_TO_FLOAT  TI方式UINT16的UQ4转化浮点类型\n
*     LQ_TI_UINT16_UQ3_TO_FLOAT  TI方式UINT16的UQ3转化浮点类型\n
*     LQ_TI_UINT16_UQ2_TO_FLOAT  TI方式UINT16的UQ2转化浮点类型\n
*     LQ_TI_UINT16_UQ1_TO_FLOAT  TI方式UINT16的UQ1转化浮点类型\n
*/
LQ_F_32BIT LQ_TI_UINT16_UQ12_TO_FLOAT(LQ_I_32BIT A, LQ_ERROR* lq_error)
{
    LQ_UI_16BIT ui16Exp;
    LQ_UI_32BIT uiq23Result;
    LQ_UI_32BIT uiq31Input;
    //!< 初始化指数部分偏移量
    ui16Exp = 18688;
    //!< 保存符号位
    if (A < 0)
    {
        ui16Exp |= 0x8000;
        uiq31Input = (LQ_UI_32BIT)(-(LQ_I_64BIT)A);
    }
    else if (A == 0)
    {
        return (0);
    }
    else
    {
        uiq31Input = A;
    }
    LQ_TI_Q2F_NORMALIZE(uiq31Input, ui16Exp);
    /*对uiq31结果进行四舍五入并切换到uiq23*/
    uiq23Result = (LQ_UI_32BIT)(((LQ_UI_64BIT)uiq31Input + 0x0080u) >> 8);
    if (uiq23Result >= 0x01000000u)
    {
        uiq23Result = 0;
        ui16Exp += 0x0080;
    }
    /*删除尾数的隐含MSB位 */
    uiq23Result &= ~0x00800000;
    /*
    *将构造的指数和符号位添加到尾数。我们必须使用
    *四舍五入会导致尾数溢出的情况下的加法。
    *当这种情况发生时，尾数结果为2，其中MSB为零
    *exp的LSB被设置为1。在指数上加一就是
    *尾数为2的正确处理。不需要缩放
    *尾数，因为在这种情况下它总是等于零。
   */
    uiq23Result += (LQ_UI_32BIT)ui16Exp << 16;
    return LQ_TI_UINT32_BITS_TO_FLOAT(uiq23Result);
}
/**@brief (TI方法)UINT16类型UQ11格式转浮点
* @details 采用估算位+指数位+符号位三位结合，能提高精度
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为浮点数
* @code*    LQ_TI_UINT16_UQ11_TO_FLOAT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_UINT16_UQ16_TO_FLOAT  TI方式UINT16的UQ16转化浮点类型\n
*     LQ_TI_UINT16_UQ15_TO_FLOAT  TI方式UINT16的UQ15转化浮点类型\n
*     LQ_TI_UINT16_UQ14_TO_FLOAT  TI方式UINT16的UQ14转化浮点类型\n
*     LQ_TI_UINT16_UQ13_TO_FLOAT  TI方式UINT16的UQ13转化浮点类型\n
*     LQ_TI_UINT16_UQ12_TO_FLOAT  TI方式UINT16的UQ12转化浮点类型\n
*     LQ_TI_UINT16_UQ11_TO_FLOAT  TI方式UINT16的UQ11转化浮点类型\n
*     LQ_TI_UINT16_UQ10_TO_FLOAT  TI方式UINT16的UQ10转化浮点类型\n
*     LQ_TI_UINT16_UQ9_TO_FLOAT  TI方式UINT16的UQ9转化浮点类型\n
*     LQ_TI_UINT16_UQ8_TO_FLOAT  TI方式UINT16的UQ8转化浮点类型\n
*     LQ_TI_UINT16_UQ7_TO_FLOAT  TI方式UINT16的UQ7转化浮点类型\n
*     LQ_TI_UINT16_UQ6_TO_FLOAT  TI方式UINT16的UQ6转化浮点类型\n
*     LQ_TI_UINT16_UQ5_TO_FLOAT  TI方式UINT16的UQ5转化浮点类型\n
*     LQ_TI_UINT16_UQ4_TO_FLOAT  TI方式UINT16的UQ4转化浮点类型\n
*     LQ_TI_UINT16_UQ3_TO_FLOAT  TI方式UINT16的UQ3转化浮点类型\n
*     LQ_TI_UINT16_UQ2_TO_FLOAT  TI方式UINT16的UQ2转化浮点类型\n
*     LQ_TI_UINT16_UQ1_TO_FLOAT  TI方式UINT16的UQ1转化浮点类型\n
*/
LQ_F_32BIT LQ_TI_UINT16_UQ11_TO_FLOAT(LQ_I_32BIT A, LQ_ERROR* lq_error)
{
    LQ_UI_16BIT ui16Exp;
    LQ_UI_32BIT uiq23Result;
    LQ_UI_32BIT uiq31Input;
    //!< 初始化指数部分偏移量
    ui16Exp = 18816;
    //!< 保存符号位
    if (A < 0)
    {
        ui16Exp |= 0x8000;
        uiq31Input = (LQ_UI_32BIT)(-(LQ_I_64BIT)A);
    }
    else if (A == 0)
    {
        return (0);
    }
    else
    {
        uiq31Input = A;
    }
    LQ_TI_Q2F_NORMALIZE(uiq31Input, ui16Exp);
    /*对uiq31结果进行四舍五入并切换到uiq23*/
    uiq23Result = (LQ_UI_32BIT)(((LQ_UI_64BIT)uiq31Input + 0x0080u) >> 8);
    if (uiq23Result >= 0x01000000u)
    {
        uiq23Result = 0;
        ui16Exp += 0x0080;
    }
    /*删除尾数的隐含MSB位 */
    uiq23Result &= ~0x00800000;
    /*
    *将构造的指数和符号位添加到尾数。我们必须使用
    *四舍五入会导致尾数溢出的情况下的加法。
    *当这种情况发生时，尾数结果为2，其中MSB为零
    *exp的LSB被设置为1。在指数上加一就是
    *尾数为2的正确处理。不需要缩放
    *尾数，因为在这种情况下它总是等于零。
   */
    uiq23Result += (LQ_UI_32BIT)ui16Exp << 16;
    return LQ_TI_UINT32_BITS_TO_FLOAT(uiq23Result);
}
/**@brief (TI方法)UINT16类型UQ10格式转浮点
* @details 采用估算位+指数位+符号位三位结合，能提高精度
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为浮点数
* @code*    LQ_TI_UINT16_UQ10_TO_FLOAT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_UINT16_UQ16_TO_FLOAT  TI方式UINT16的UQ16转化浮点类型\n
*     LQ_TI_UINT16_UQ15_TO_FLOAT  TI方式UINT16的UQ15转化浮点类型\n
*     LQ_TI_UINT16_UQ14_TO_FLOAT  TI方式UINT16的UQ14转化浮点类型\n
*     LQ_TI_UINT16_UQ13_TO_FLOAT  TI方式UINT16的UQ13转化浮点类型\n
*     LQ_TI_UINT16_UQ12_TO_FLOAT  TI方式UINT16的UQ12转化浮点类型\n
*     LQ_TI_UINT16_UQ11_TO_FLOAT  TI方式UINT16的UQ11转化浮点类型\n
*     LQ_TI_UINT16_UQ10_TO_FLOAT  TI方式UINT16的UQ10转化浮点类型\n
*     LQ_TI_UINT16_UQ9_TO_FLOAT  TI方式UINT16的UQ9转化浮点类型\n
*     LQ_TI_UINT16_UQ8_TO_FLOAT  TI方式UINT16的UQ8转化浮点类型\n
*     LQ_TI_UINT16_UQ7_TO_FLOAT  TI方式UINT16的UQ7转化浮点类型\n
*     LQ_TI_UINT16_UQ6_TO_FLOAT  TI方式UINT16的UQ6转化浮点类型\n
*     LQ_TI_UINT16_UQ5_TO_FLOAT  TI方式UINT16的UQ5转化浮点类型\n
*     LQ_TI_UINT16_UQ4_TO_FLOAT  TI方式UINT16的UQ4转化浮点类型\n
*     LQ_TI_UINT16_UQ3_TO_FLOAT  TI方式UINT16的UQ3转化浮点类型\n
*     LQ_TI_UINT16_UQ2_TO_FLOAT  TI方式UINT16的UQ2转化浮点类型\n
*     LQ_TI_UINT16_UQ1_TO_FLOAT  TI方式UINT16的UQ1转化浮点类型\n
*/
LQ_F_32BIT LQ_TI_UINT16_UQ10_TO_FLOAT(LQ_I_32BIT A, LQ_ERROR* lq_error)
{
    LQ_UI_16BIT ui16Exp;
    LQ_UI_32BIT uiq23Result;
    LQ_UI_32BIT uiq31Input;
    //!< 初始化指数部分偏移量
    ui16Exp = 18944;
    //!< 保存符号位
    if (A < 0)
    {
        ui16Exp |= 0x8000;
        uiq31Input = (LQ_UI_32BIT)(-(LQ_I_64BIT)A);
    }
    else if (A == 0)
    {
        return (0);
    }
    else
    {
        uiq31Input = A;
    }
    LQ_TI_Q2F_NORMALIZE(uiq31Input, ui16Exp);
    /*对uiq31结果进行四舍五入并切换到uiq23*/
    uiq23Result = (LQ_UI_32BIT)(((LQ_UI_64BIT)uiq31Input + 0x0080u) >> 8);
    if (uiq23Result >= 0x01000000u)
    {
        uiq23Result = 0;
        ui16Exp += 0x0080;
    }
    /*删除尾数的隐含MSB位 */
    uiq23Result &= ~0x00800000;
    /*
    *将构造的指数和符号位添加到尾数。我们必须使用
    *四舍五入会导致尾数溢出的情况下的加法。
    *当这种情况发生时，尾数结果为2，其中MSB为零
    *exp的LSB被设置为1。在指数上加一就是
    *尾数为2的正确处理。不需要缩放
    *尾数，因为在这种情况下它总是等于零。
   */
    uiq23Result += (LQ_UI_32BIT)ui16Exp << 16;
    return LQ_TI_UINT32_BITS_TO_FLOAT(uiq23Result);
}
/**@brief (TI方法)UINT16类型UQ9格式转浮点
* @details 采用估算位+指数位+符号位三位结合，能提高精度
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为浮点数
* @code*    LQ_TI_UINT16_UQ9_TO_FLOAT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_UINT16_UQ16_TO_FLOAT  TI方式UINT16的UQ16转化浮点类型\n
*     LQ_TI_UINT16_UQ15_TO_FLOAT  TI方式UINT16的UQ15转化浮点类型\n
*     LQ_TI_UINT16_UQ14_TO_FLOAT  TI方式UINT16的UQ14转化浮点类型\n
*     LQ_TI_UINT16_UQ13_TO_FLOAT  TI方式UINT16的UQ13转化浮点类型\n
*     LQ_TI_UINT16_UQ12_TO_FLOAT  TI方式UINT16的UQ12转化浮点类型\n
*     LQ_TI_UINT16_UQ11_TO_FLOAT  TI方式UINT16的UQ11转化浮点类型\n
*     LQ_TI_UINT16_UQ10_TO_FLOAT  TI方式UINT16的UQ10转化浮点类型\n
*     LQ_TI_UINT16_UQ9_TO_FLOAT  TI方式UINT16的UQ9转化浮点类型\n
*     LQ_TI_UINT16_UQ8_TO_FLOAT  TI方式UINT16的UQ8转化浮点类型\n
*     LQ_TI_UINT16_UQ7_TO_FLOAT  TI方式UINT16的UQ7转化浮点类型\n
*     LQ_TI_UINT16_UQ6_TO_FLOAT  TI方式UINT16的UQ6转化浮点类型\n
*     LQ_TI_UINT16_UQ5_TO_FLOAT  TI方式UINT16的UQ5转化浮点类型\n
*     LQ_TI_UINT16_UQ4_TO_FLOAT  TI方式UINT16的UQ4转化浮点类型\n
*     LQ_TI_UINT16_UQ3_TO_FLOAT  TI方式UINT16的UQ3转化浮点类型\n
*     LQ_TI_UINT16_UQ2_TO_FLOAT  TI方式UINT16的UQ2转化浮点类型\n
*     LQ_TI_UINT16_UQ1_TO_FLOAT  TI方式UINT16的UQ1转化浮点类型\n
*/
LQ_F_32BIT LQ_TI_UINT16_UQ9_TO_FLOAT(LQ_I_32BIT A, LQ_ERROR* lq_error)
{
    LQ_UI_16BIT ui16Exp;
    LQ_UI_32BIT uiq23Result;
    LQ_UI_32BIT uiq31Input;
    //!< 初始化指数部分偏移量
    ui16Exp = 19072;
    //!< 保存符号位
    if (A < 0)
    {
        ui16Exp |= 0x8000;
        uiq31Input = (LQ_UI_32BIT)(-(LQ_I_64BIT)A);
    }
    else if (A == 0)
    {
        return (0);
    }
    else
    {
        uiq31Input = A;
    }
    LQ_TI_Q2F_NORMALIZE(uiq31Input, ui16Exp);
    /*对uiq31结果进行四舍五入并切换到uiq23*/
    uiq23Result = (LQ_UI_32BIT)(((LQ_UI_64BIT)uiq31Input + 0x0080u) >> 8);
    if (uiq23Result >= 0x01000000u)
    {
        uiq23Result = 0;
        ui16Exp += 0x0080;
    }
    /*删除尾数的隐含MSB位 */
    uiq23Result &= ~0x00800000;
    /*
    *将构造的指数和符号位添加到尾数。我们必须使用
    *四舍五入会导致尾数溢出的情况下的加法。
    *当这种情况发生时，尾数结果为2，其中MSB为零
    *exp的LSB被设置为1。在指数上加一就是
    *尾数为2的正确处理。不需要缩放
    *尾数，因为在这种情况下它总是等于零。
   */
    uiq23Result += (LQ_UI_32BIT)ui16Exp << 16;
    return LQ_TI_UINT32_BITS_TO_FLOAT(uiq23Result);
}
/**@brief (TI方法)UINT16类型UQ8格式转浮点
* @details 采用估算位+指数位+符号位三位结合，能提高精度
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为浮点数
* @code*    LQ_TI_UINT16_UQ8_TO_FLOAT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_UINT16_UQ16_TO_FLOAT  TI方式UINT16的UQ16转化浮点类型\n
*     LQ_TI_UINT16_UQ15_TO_FLOAT  TI方式UINT16的UQ15转化浮点类型\n
*     LQ_TI_UINT16_UQ14_TO_FLOAT  TI方式UINT16的UQ14转化浮点类型\n
*     LQ_TI_UINT16_UQ13_TO_FLOAT  TI方式UINT16的UQ13转化浮点类型\n
*     LQ_TI_UINT16_UQ12_TO_FLOAT  TI方式UINT16的UQ12转化浮点类型\n
*     LQ_TI_UINT16_UQ11_TO_FLOAT  TI方式UINT16的UQ11转化浮点类型\n
*     LQ_TI_UINT16_UQ10_TO_FLOAT  TI方式UINT16的UQ10转化浮点类型\n
*     LQ_TI_UINT16_UQ9_TO_FLOAT  TI方式UINT16的UQ9转化浮点类型\n
*     LQ_TI_UINT16_UQ8_TO_FLOAT  TI方式UINT16的UQ8转化浮点类型\n
*     LQ_TI_UINT16_UQ7_TO_FLOAT  TI方式UINT16的UQ7转化浮点类型\n
*     LQ_TI_UINT16_UQ6_TO_FLOAT  TI方式UINT16的UQ6转化浮点类型\n
*     LQ_TI_UINT16_UQ5_TO_FLOAT  TI方式UINT16的UQ5转化浮点类型\n
*     LQ_TI_UINT16_UQ4_TO_FLOAT  TI方式UINT16的UQ4转化浮点类型\n
*     LQ_TI_UINT16_UQ3_TO_FLOAT  TI方式UINT16的UQ3转化浮点类型\n
*     LQ_TI_UINT16_UQ2_TO_FLOAT  TI方式UINT16的UQ2转化浮点类型\n
*     LQ_TI_UINT16_UQ1_TO_FLOAT  TI方式UINT16的UQ1转化浮点类型\n
*/
LQ_F_32BIT LQ_TI_UINT16_UQ8_TO_FLOAT(LQ_I_32BIT A, LQ_ERROR* lq_error)
{
    LQ_UI_16BIT ui16Exp;
    LQ_UI_32BIT uiq23Result;
    LQ_UI_32BIT uiq31Input;
    //!< 初始化指数部分偏移量
    ui16Exp = 19200;
    //!< 保存符号位
    if (A < 0)
    {
        ui16Exp |= 0x8000;
        uiq31Input = (LQ_UI_32BIT)(-(LQ_I_64BIT)A);
    }
    else if (A == 0)
    {
        return (0);
    }
    else
    {
        uiq31Input = A;
    }
    LQ_TI_Q2F_NORMALIZE(uiq31Input, ui16Exp);
    /*对uiq31结果进行四舍五入并切换到uiq23*/
    uiq23Result = (LQ_UI_32BIT)(((LQ_UI_64BIT)uiq31Input + 0x0080u) >> 8);
    if (uiq23Result >= 0x01000000u)
    {
        uiq23Result = 0;
        ui16Exp += 0x0080;
    }
    /*删除尾数的隐含MSB位 */
    uiq23Result &= ~0x00800000;
    /*
    *将构造的指数和符号位添加到尾数。我们必须使用
    *四舍五入会导致尾数溢出的情况下的加法。
    *当这种情况发生时，尾数结果为2，其中MSB为零
    *exp的LSB被设置为1。在指数上加一就是
    *尾数为2的正确处理。不需要缩放
    *尾数，因为在这种情况下它总是等于零。
   */
    uiq23Result += (LQ_UI_32BIT)ui16Exp << 16;
    return LQ_TI_UINT32_BITS_TO_FLOAT(uiq23Result);
}
/**@brief (TI方法)UINT16类型UQ7格式转浮点
* @details 采用估算位+指数位+符号位三位结合，能提高精度
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为浮点数
* @code*    LQ_TI_UINT16_UQ7_TO_FLOAT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_UINT16_UQ16_TO_FLOAT  TI方式UINT16的UQ16转化浮点类型\n
*     LQ_TI_UINT16_UQ15_TO_FLOAT  TI方式UINT16的UQ15转化浮点类型\n
*     LQ_TI_UINT16_UQ14_TO_FLOAT  TI方式UINT16的UQ14转化浮点类型\n
*     LQ_TI_UINT16_UQ13_TO_FLOAT  TI方式UINT16的UQ13转化浮点类型\n
*     LQ_TI_UINT16_UQ12_TO_FLOAT  TI方式UINT16的UQ12转化浮点类型\n
*     LQ_TI_UINT16_UQ11_TO_FLOAT  TI方式UINT16的UQ11转化浮点类型\n
*     LQ_TI_UINT16_UQ10_TO_FLOAT  TI方式UINT16的UQ10转化浮点类型\n
*     LQ_TI_UINT16_UQ9_TO_FLOAT  TI方式UINT16的UQ9转化浮点类型\n
*     LQ_TI_UINT16_UQ8_TO_FLOAT  TI方式UINT16的UQ8转化浮点类型\n
*     LQ_TI_UINT16_UQ7_TO_FLOAT  TI方式UINT16的UQ7转化浮点类型\n
*     LQ_TI_UINT16_UQ6_TO_FLOAT  TI方式UINT16的UQ6转化浮点类型\n
*     LQ_TI_UINT16_UQ5_TO_FLOAT  TI方式UINT16的UQ5转化浮点类型\n
*     LQ_TI_UINT16_UQ4_TO_FLOAT  TI方式UINT16的UQ4转化浮点类型\n
*     LQ_TI_UINT16_UQ3_TO_FLOAT  TI方式UINT16的UQ3转化浮点类型\n
*     LQ_TI_UINT16_UQ2_TO_FLOAT  TI方式UINT16的UQ2转化浮点类型\n
*     LQ_TI_UINT16_UQ1_TO_FLOAT  TI方式UINT16的UQ1转化浮点类型\n
*/
LQ_F_32BIT LQ_TI_UINT16_UQ7_TO_FLOAT(LQ_I_32BIT A, LQ_ERROR* lq_error)
{
    LQ_UI_16BIT ui16Exp;
    LQ_UI_32BIT uiq23Result;
    LQ_UI_32BIT uiq31Input;
    //!< 初始化指数部分偏移量
    ui16Exp = 19328;
    //!< 保存符号位
    if (A < 0)
    {
        ui16Exp |= 0x8000;
        uiq31Input = (LQ_UI_32BIT)(-(LQ_I_64BIT)A);
    }
    else if (A == 0)
    {
        return (0);
    }
    else
    {
        uiq31Input = A;
    }
    LQ_TI_Q2F_NORMALIZE(uiq31Input, ui16Exp);
    /*对uiq31结果进行四舍五入并切换到uiq23*/
    uiq23Result = (LQ_UI_32BIT)(((LQ_UI_64BIT)uiq31Input + 0x0080u) >> 8);
    if (uiq23Result >= 0x01000000u)
    {
        uiq23Result = 0;
        ui16Exp += 0x0080;
    }
    /*删除尾数的隐含MSB位 */
    uiq23Result &= ~0x00800000;
    /*
    *将构造的指数和符号位添加到尾数。我们必须使用
    *四舍五入会导致尾数溢出的情况下的加法。
    *当这种情况发生时，尾数结果为2，其中MSB为零
    *exp的LSB被设置为1。在指数上加一就是
    *尾数为2的正确处理。不需要缩放
    *尾数，因为在这种情况下它总是等于零。
   */
    uiq23Result += (LQ_UI_32BIT)ui16Exp << 16;
    return LQ_TI_UINT32_BITS_TO_FLOAT(uiq23Result);
}
/**@brief (TI方法)UINT16类型UQ6格式转浮点
* @details 采用估算位+指数位+符号位三位结合，能提高精度
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为浮点数
* @code*    LQ_TI_UINT16_UQ6_TO_FLOAT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_UINT16_UQ16_TO_FLOAT  TI方式UINT16的UQ16转化浮点类型\n
*     LQ_TI_UINT16_UQ15_TO_FLOAT  TI方式UINT16的UQ15转化浮点类型\n
*     LQ_TI_UINT16_UQ14_TO_FLOAT  TI方式UINT16的UQ14转化浮点类型\n
*     LQ_TI_UINT16_UQ13_TO_FLOAT  TI方式UINT16的UQ13转化浮点类型\n
*     LQ_TI_UINT16_UQ12_TO_FLOAT  TI方式UINT16的UQ12转化浮点类型\n
*     LQ_TI_UINT16_UQ11_TO_FLOAT  TI方式UINT16的UQ11转化浮点类型\n
*     LQ_TI_UINT16_UQ10_TO_FLOAT  TI方式UINT16的UQ10转化浮点类型\n
*     LQ_TI_UINT16_UQ9_TO_FLOAT  TI方式UINT16的UQ9转化浮点类型\n
*     LQ_TI_UINT16_UQ8_TO_FLOAT  TI方式UINT16的UQ8转化浮点类型\n
*     LQ_TI_UINT16_UQ7_TO_FLOAT  TI方式UINT16的UQ7转化浮点类型\n
*     LQ_TI_UINT16_UQ6_TO_FLOAT  TI方式UINT16的UQ6转化浮点类型\n
*     LQ_TI_UINT16_UQ5_TO_FLOAT  TI方式UINT16的UQ5转化浮点类型\n
*     LQ_TI_UINT16_UQ4_TO_FLOAT  TI方式UINT16的UQ4转化浮点类型\n
*     LQ_TI_UINT16_UQ3_TO_FLOAT  TI方式UINT16的UQ3转化浮点类型\n
*     LQ_TI_UINT16_UQ2_TO_FLOAT  TI方式UINT16的UQ2转化浮点类型\n
*     LQ_TI_UINT16_UQ1_TO_FLOAT  TI方式UINT16的UQ1转化浮点类型\n
*/
LQ_F_32BIT LQ_TI_UINT16_UQ6_TO_FLOAT(LQ_I_32BIT A, LQ_ERROR* lq_error)
{
    LQ_UI_16BIT ui16Exp;
    LQ_UI_32BIT uiq23Result;
    LQ_UI_32BIT uiq31Input;
    //!< 初始化指数部分偏移量
    ui16Exp = 19456;
    //!< 保存符号位
    if (A < 0)
    {
        ui16Exp |= 0x8000;
        uiq31Input = (LQ_UI_32BIT)(-(LQ_I_64BIT)A);
    }
    else if (A == 0)
    {
        return (0);
    }
    else
    {
        uiq31Input = A;
    }
    LQ_TI_Q2F_NORMALIZE(uiq31Input, ui16Exp);
    /*对uiq31结果进行四舍五入并切换到uiq23*/
    uiq23Result = (LQ_UI_32BIT)(((LQ_UI_64BIT)uiq31Input + 0x0080u) >> 8);
    if (uiq23Result >= 0x01000000u)
    {
        uiq23Result = 0;
        ui16Exp += 0x0080;
    }
    /*删除尾数的隐含MSB位 */
    uiq23Result &= ~0x00800000;
    /*
    *将构造的指数和符号位添加到尾数。我们必须使用
    *四舍五入会导致尾数溢出的情况下的加法。
    *当这种情况发生时，尾数结果为2，其中MSB为零
    *exp的LSB被设置为1。在指数上加一就是
    *尾数为2的正确处理。不需要缩放
    *尾数，因为在这种情况下它总是等于零。
   */
    uiq23Result += (LQ_UI_32BIT)ui16Exp << 16;
    return LQ_TI_UINT32_BITS_TO_FLOAT(uiq23Result);
}
/**@brief (TI方法)UINT16类型UQ5格式转浮点
* @details 采用估算位+指数位+符号位三位结合，能提高精度
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为浮点数
* @code*    LQ_TI_UINT16_UQ5_TO_FLOAT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_UINT16_UQ16_TO_FLOAT  TI方式UINT16的UQ16转化浮点类型\n
*     LQ_TI_UINT16_UQ15_TO_FLOAT  TI方式UINT16的UQ15转化浮点类型\n
*     LQ_TI_UINT16_UQ14_TO_FLOAT  TI方式UINT16的UQ14转化浮点类型\n
*     LQ_TI_UINT16_UQ13_TO_FLOAT  TI方式UINT16的UQ13转化浮点类型\n
*     LQ_TI_UINT16_UQ12_TO_FLOAT  TI方式UINT16的UQ12转化浮点类型\n
*     LQ_TI_UINT16_UQ11_TO_FLOAT  TI方式UINT16的UQ11转化浮点类型\n
*     LQ_TI_UINT16_UQ10_TO_FLOAT  TI方式UINT16的UQ10转化浮点类型\n
*     LQ_TI_UINT16_UQ9_TO_FLOAT  TI方式UINT16的UQ9转化浮点类型\n
*     LQ_TI_UINT16_UQ8_TO_FLOAT  TI方式UINT16的UQ8转化浮点类型\n
*     LQ_TI_UINT16_UQ7_TO_FLOAT  TI方式UINT16的UQ7转化浮点类型\n
*     LQ_TI_UINT16_UQ6_TO_FLOAT  TI方式UINT16的UQ6转化浮点类型\n
*     LQ_TI_UINT16_UQ5_TO_FLOAT  TI方式UINT16的UQ5转化浮点类型\n
*     LQ_TI_UINT16_UQ4_TO_FLOAT  TI方式UINT16的UQ4转化浮点类型\n
*     LQ_TI_UINT16_UQ3_TO_FLOAT  TI方式UINT16的UQ3转化浮点类型\n
*     LQ_TI_UINT16_UQ2_TO_FLOAT  TI方式UINT16的UQ2转化浮点类型\n
*     LQ_TI_UINT16_UQ1_TO_FLOAT  TI方式UINT16的UQ1转化浮点类型\n
*/
LQ_F_32BIT LQ_TI_UINT16_UQ5_TO_FLOAT(LQ_I_32BIT A, LQ_ERROR* lq_error)
{
    LQ_UI_16BIT ui16Exp;
    LQ_UI_32BIT uiq23Result;
    LQ_UI_32BIT uiq31Input;
    //!< 初始化指数部分偏移量
    ui16Exp = 19584;
    //!< 保存符号位
    if (A < 0)
    {
        ui16Exp |= 0x8000;
        uiq31Input = (LQ_UI_32BIT)(-(LQ_I_64BIT)A);
    }
    else if (A == 0)
    {
        return (0);
    }
    else
    {
        uiq31Input = A;
    }
    LQ_TI_Q2F_NORMALIZE(uiq31Input, ui16Exp);
    /*对uiq31结果进行四舍五入并切换到uiq23*/
    uiq23Result = (LQ_UI_32BIT)(((LQ_UI_64BIT)uiq31Input + 0x0080u) >> 8);
    if (uiq23Result >= 0x01000000u)
    {
        uiq23Result = 0;
        ui16Exp += 0x0080;
    }
    /*删除尾数的隐含MSB位 */
    uiq23Result &= ~0x00800000;
    /*
    *将构造的指数和符号位添加到尾数。我们必须使用
    *四舍五入会导致尾数溢出的情况下的加法。
    *当这种情况发生时，尾数结果为2，其中MSB为零
    *exp的LSB被设置为1。在指数上加一就是
    *尾数为2的正确处理。不需要缩放
    *尾数，因为在这种情况下它总是等于零。
   */
    uiq23Result += (LQ_UI_32BIT)ui16Exp << 16;
    return LQ_TI_UINT32_BITS_TO_FLOAT(uiq23Result);
}
/**@brief (TI方法)UINT16类型UQ4格式转浮点
* @details 采用估算位+指数位+符号位三位结合，能提高精度
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为浮点数
* @code*    LQ_TI_UINT16_UQ4_TO_FLOAT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_UINT16_UQ16_TO_FLOAT  TI方式UINT16的UQ16转化浮点类型\n
*     LQ_TI_UINT16_UQ15_TO_FLOAT  TI方式UINT16的UQ15转化浮点类型\n
*     LQ_TI_UINT16_UQ14_TO_FLOAT  TI方式UINT16的UQ14转化浮点类型\n
*     LQ_TI_UINT16_UQ13_TO_FLOAT  TI方式UINT16的UQ13转化浮点类型\n
*     LQ_TI_UINT16_UQ12_TO_FLOAT  TI方式UINT16的UQ12转化浮点类型\n
*     LQ_TI_UINT16_UQ11_TO_FLOAT  TI方式UINT16的UQ11转化浮点类型\n
*     LQ_TI_UINT16_UQ10_TO_FLOAT  TI方式UINT16的UQ10转化浮点类型\n
*     LQ_TI_UINT16_UQ9_TO_FLOAT  TI方式UINT16的UQ9转化浮点类型\n
*     LQ_TI_UINT16_UQ8_TO_FLOAT  TI方式UINT16的UQ8转化浮点类型\n
*     LQ_TI_UINT16_UQ7_TO_FLOAT  TI方式UINT16的UQ7转化浮点类型\n
*     LQ_TI_UINT16_UQ6_TO_FLOAT  TI方式UINT16的UQ6转化浮点类型\n
*     LQ_TI_UINT16_UQ5_TO_FLOAT  TI方式UINT16的UQ5转化浮点类型\n
*     LQ_TI_UINT16_UQ4_TO_FLOAT  TI方式UINT16的UQ4转化浮点类型\n
*     LQ_TI_UINT16_UQ3_TO_FLOAT  TI方式UINT16的UQ3转化浮点类型\n
*     LQ_TI_UINT16_UQ2_TO_FLOAT  TI方式UINT16的UQ2转化浮点类型\n
*     LQ_TI_UINT16_UQ1_TO_FLOAT  TI方式UINT16的UQ1转化浮点类型\n
*/
LQ_F_32BIT LQ_TI_UINT16_UQ4_TO_FLOAT(LQ_I_32BIT A, LQ_ERROR* lq_error)
{
    LQ_UI_16BIT ui16Exp;
    LQ_UI_32BIT uiq23Result;
    LQ_UI_32BIT uiq31Input;
    //!< 初始化指数部分偏移量
    ui16Exp = 19712;
    //!< 保存符号位
    if (A < 0)
    {
        ui16Exp |= 0x8000;
        uiq31Input = (LQ_UI_32BIT)(-(LQ_I_64BIT)A);
    }
    else if (A == 0)
    {
        return (0);
    }
    else
    {
        uiq31Input = A;
    }
    LQ_TI_Q2F_NORMALIZE(uiq31Input, ui16Exp);
    /*对uiq31结果进行四舍五入并切换到uiq23*/
    uiq23Result = (LQ_UI_32BIT)(((LQ_UI_64BIT)uiq31Input + 0x0080u) >> 8);
    if (uiq23Result >= 0x01000000u)
    {
        uiq23Result = 0;
        ui16Exp += 0x0080;
    }
    /*删除尾数的隐含MSB位 */
    uiq23Result &= ~0x00800000;
    /*
    *将构造的指数和符号位添加到尾数。我们必须使用
    *四舍五入会导致尾数溢出的情况下的加法。
    *当这种情况发生时，尾数结果为2，其中MSB为零
    *exp的LSB被设置为1。在指数上加一就是
    *尾数为2的正确处理。不需要缩放
    *尾数，因为在这种情况下它总是等于零。
   */
    uiq23Result += (LQ_UI_32BIT)ui16Exp << 16;
    return LQ_TI_UINT32_BITS_TO_FLOAT(uiq23Result);
}
/**@brief (TI方法)UINT16类型UQ3格式转浮点
* @details 采用估算位+指数位+符号位三位结合，能提高精度
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为浮点数
* @code*    LQ_TI_UINT16_UQ3_TO_FLOAT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_UINT16_UQ16_TO_FLOAT  TI方式UINT16的UQ16转化浮点类型\n
*     LQ_TI_UINT16_UQ15_TO_FLOAT  TI方式UINT16的UQ15转化浮点类型\n
*     LQ_TI_UINT16_UQ14_TO_FLOAT  TI方式UINT16的UQ14转化浮点类型\n
*     LQ_TI_UINT16_UQ13_TO_FLOAT  TI方式UINT16的UQ13转化浮点类型\n
*     LQ_TI_UINT16_UQ12_TO_FLOAT  TI方式UINT16的UQ12转化浮点类型\n
*     LQ_TI_UINT16_UQ11_TO_FLOAT  TI方式UINT16的UQ11转化浮点类型\n
*     LQ_TI_UINT16_UQ10_TO_FLOAT  TI方式UINT16的UQ10转化浮点类型\n
*     LQ_TI_UINT16_UQ9_TO_FLOAT  TI方式UINT16的UQ9转化浮点类型\n
*     LQ_TI_UINT16_UQ8_TO_FLOAT  TI方式UINT16的UQ8转化浮点类型\n
*     LQ_TI_UINT16_UQ7_TO_FLOAT  TI方式UINT16的UQ7转化浮点类型\n
*     LQ_TI_UINT16_UQ6_TO_FLOAT  TI方式UINT16的UQ6转化浮点类型\n
*     LQ_TI_UINT16_UQ5_TO_FLOAT  TI方式UINT16的UQ5转化浮点类型\n
*     LQ_TI_UINT16_UQ4_TO_FLOAT  TI方式UINT16的UQ4转化浮点类型\n
*     LQ_TI_UINT16_UQ3_TO_FLOAT  TI方式UINT16的UQ3转化浮点类型\n
*     LQ_TI_UINT16_UQ2_TO_FLOAT  TI方式UINT16的UQ2转化浮点类型\n
*     LQ_TI_UINT16_UQ1_TO_FLOAT  TI方式UINT16的UQ1转化浮点类型\n
*/
LQ_F_32BIT LQ_TI_UINT16_UQ3_TO_FLOAT(LQ_I_32BIT A, LQ_ERROR* lq_error)
{
    LQ_UI_16BIT ui16Exp;
    LQ_UI_32BIT uiq23Result;
    LQ_UI_32BIT uiq31Input;
    //!< 初始化指数部分偏移量
    ui16Exp = 19840;
    //!< 保存符号位
    if (A < 0)
    {
        ui16Exp |= 0x8000;
        uiq31Input = (LQ_UI_32BIT)(-(LQ_I_64BIT)A);
    }
    else if (A == 0)
    {
        return (0);
    }
    else
    {
        uiq31Input = A;
    }
    LQ_TI_Q2F_NORMALIZE(uiq31Input, ui16Exp);
    /*对uiq31结果进行四舍五入并切换到uiq23*/
    uiq23Result = (LQ_UI_32BIT)(((LQ_UI_64BIT)uiq31Input + 0x0080u) >> 8);
    if (uiq23Result >= 0x01000000u)
    {
        uiq23Result = 0;
        ui16Exp += 0x0080;
    }
    /*删除尾数的隐含MSB位 */
    uiq23Result &= ~0x00800000;
    /*
    *将构造的指数和符号位添加到尾数。我们必须使用
    *四舍五入会导致尾数溢出的情况下的加法。
    *当这种情况发生时，尾数结果为2，其中MSB为零
    *exp的LSB被设置为1。在指数上加一就是
    *尾数为2的正确处理。不需要缩放
    *尾数，因为在这种情况下它总是等于零。
   */
    uiq23Result += (LQ_UI_32BIT)ui16Exp << 16;
    return LQ_TI_UINT32_BITS_TO_FLOAT(uiq23Result);
}
/**@brief (TI方法)UINT16类型UQ2格式转浮点
* @details 采用估算位+指数位+符号位三位结合，能提高精度
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为浮点数
* @code*    LQ_TI_UINT16_UQ2_TO_FLOAT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_UINT16_UQ16_TO_FLOAT  TI方式UINT16的UQ16转化浮点类型\n
*     LQ_TI_UINT16_UQ15_TO_FLOAT  TI方式UINT16的UQ15转化浮点类型\n
*     LQ_TI_UINT16_UQ14_TO_FLOAT  TI方式UINT16的UQ14转化浮点类型\n
*     LQ_TI_UINT16_UQ13_TO_FLOAT  TI方式UINT16的UQ13转化浮点类型\n
*     LQ_TI_UINT16_UQ12_TO_FLOAT  TI方式UINT16的UQ12转化浮点类型\n
*     LQ_TI_UINT16_UQ11_TO_FLOAT  TI方式UINT16的UQ11转化浮点类型\n
*     LQ_TI_UINT16_UQ10_TO_FLOAT  TI方式UINT16的UQ10转化浮点类型\n
*     LQ_TI_UINT16_UQ9_TO_FLOAT  TI方式UINT16的UQ9转化浮点类型\n
*     LQ_TI_UINT16_UQ8_TO_FLOAT  TI方式UINT16的UQ8转化浮点类型\n
*     LQ_TI_UINT16_UQ7_TO_FLOAT  TI方式UINT16的UQ7转化浮点类型\n
*     LQ_TI_UINT16_UQ6_TO_FLOAT  TI方式UINT16的UQ6转化浮点类型\n
*     LQ_TI_UINT16_UQ5_TO_FLOAT  TI方式UINT16的UQ5转化浮点类型\n
*     LQ_TI_UINT16_UQ4_TO_FLOAT  TI方式UINT16的UQ4转化浮点类型\n
*     LQ_TI_UINT16_UQ3_TO_FLOAT  TI方式UINT16的UQ3转化浮点类型\n
*     LQ_TI_UINT16_UQ2_TO_FLOAT  TI方式UINT16的UQ2转化浮点类型\n
*     LQ_TI_UINT16_UQ1_TO_FLOAT  TI方式UINT16的UQ1转化浮点类型\n
*/
LQ_F_32BIT LQ_TI_UINT16_UQ2_TO_FLOAT(LQ_I_32BIT A, LQ_ERROR* lq_error)
{
    LQ_UI_16BIT ui16Exp;
    LQ_UI_32BIT uiq23Result;
    LQ_UI_32BIT uiq31Input;
    //!< 初始化指数部分偏移量
    ui16Exp = 19968;
    //!< 保存符号位
    if (A < 0)
    {
        ui16Exp |= 0x8000;
        uiq31Input = (LQ_UI_32BIT)(-(LQ_I_64BIT)A);
    }
    else if (A == 0)
    {
        return (0);
    }
    else
    {
        uiq31Input = A;
    }
    LQ_TI_Q2F_NORMALIZE(uiq31Input, ui16Exp);
    /*对uiq31结果进行四舍五入并切换到uiq23*/
    uiq23Result = (LQ_UI_32BIT)(((LQ_UI_64BIT)uiq31Input + 0x0080u) >> 8);
    if (uiq23Result >= 0x01000000u)
    {
        uiq23Result = 0;
        ui16Exp += 0x0080;
    }
    /*删除尾数的隐含MSB位 */
    uiq23Result &= ~0x00800000;
    /*
    *将构造的指数和符号位添加到尾数。我们必须使用
    *四舍五入会导致尾数溢出的情况下的加法。
    *当这种情况发生时，尾数结果为2，其中MSB为零
    *exp的LSB被设置为1。在指数上加一就是
    *尾数为2的正确处理。不需要缩放
    *尾数，因为在这种情况下它总是等于零。
   */
    uiq23Result += (LQ_UI_32BIT)ui16Exp << 16;
    return LQ_TI_UINT32_BITS_TO_FLOAT(uiq23Result);
}
/**@brief (TI方法)UINT16类型UQ1格式转浮点
* @details 采用估算位+指数位+符号位三位结合，能提高精度
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为浮点数
* @code*    LQ_TI_UINT16_UQ1_TO_FLOAT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_UINT16_UQ16_TO_FLOAT  TI方式UINT16的UQ16转化浮点类型\n
*     LQ_TI_UINT16_UQ15_TO_FLOAT  TI方式UINT16的UQ15转化浮点类型\n
*     LQ_TI_UINT16_UQ14_TO_FLOAT  TI方式UINT16的UQ14转化浮点类型\n
*     LQ_TI_UINT16_UQ13_TO_FLOAT  TI方式UINT16的UQ13转化浮点类型\n
*     LQ_TI_UINT16_UQ12_TO_FLOAT  TI方式UINT16的UQ12转化浮点类型\n
*     LQ_TI_UINT16_UQ11_TO_FLOAT  TI方式UINT16的UQ11转化浮点类型\n
*     LQ_TI_UINT16_UQ10_TO_FLOAT  TI方式UINT16的UQ10转化浮点类型\n
*     LQ_TI_UINT16_UQ9_TO_FLOAT  TI方式UINT16的UQ9转化浮点类型\n
*     LQ_TI_UINT16_UQ8_TO_FLOAT  TI方式UINT16的UQ8转化浮点类型\n
*     LQ_TI_UINT16_UQ7_TO_FLOAT  TI方式UINT16的UQ7转化浮点类型\n
*     LQ_TI_UINT16_UQ6_TO_FLOAT  TI方式UINT16的UQ6转化浮点类型\n
*     LQ_TI_UINT16_UQ5_TO_FLOAT  TI方式UINT16的UQ5转化浮点类型\n
*     LQ_TI_UINT16_UQ4_TO_FLOAT  TI方式UINT16的UQ4转化浮点类型\n
*     LQ_TI_UINT16_UQ3_TO_FLOAT  TI方式UINT16的UQ3转化浮点类型\n
*     LQ_TI_UINT16_UQ2_TO_FLOAT  TI方式UINT16的UQ2转化浮点类型\n
*     LQ_TI_UINT16_UQ1_TO_FLOAT  TI方式UINT16的UQ1转化浮点类型\n
*/
LQ_F_32BIT LQ_TI_UINT16_UQ1_TO_FLOAT(LQ_I_32BIT A, LQ_ERROR* lq_error)
{
    LQ_UI_16BIT ui16Exp;
    LQ_UI_32BIT uiq23Result;
    LQ_UI_32BIT uiq31Input;
    //!< 初始化指数部分偏移量
    ui16Exp = 20096;
    //!< 保存符号位
    if (A < 0)
    {
        ui16Exp |= 0x8000;
        uiq31Input = (LQ_UI_32BIT)(-(LQ_I_64BIT)A);
    }
    else if (A == 0)
    {
        return (0);
    }
    else
    {
        uiq31Input = A;
    }
    LQ_TI_Q2F_NORMALIZE(uiq31Input, ui16Exp);
    /*对uiq31结果进行四舍五入并切换到uiq23*/
    uiq23Result = (LQ_UI_32BIT)(((LQ_UI_64BIT)uiq31Input + 0x0080u) >> 8);
    if (uiq23Result >= 0x01000000u)
    {
        uiq23Result = 0;
        ui16Exp += 0x0080;
    }
    /*删除尾数的隐含MSB位 */
    uiq23Result &= ~0x00800000;
    /*
    *将构造的指数和符号位添加到尾数。我们必须使用
    *四舍五入会导致尾数溢出的情况下的加法。
    *当这种情况发生时，尾数结果为2，其中MSB为零
    *exp的LSB被设置为1。在指数上加一就是
    *尾数为2的正确处理。不需要缩放
    *尾数，因为在这种情况下它总是等于零。
   */
    uiq23Result += (LQ_UI_32BIT)ui16Exp << 16;
    return LQ_TI_UINT32_BITS_TO_FLOAT(uiq23Result);
}
/**@brief (TI方法)INT32类型Q31格式转浮点
* @details 采用估算位+指数位+符号位三位结合，能提高精度
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为浮点数
* @code*    LQ_TI_INT32_Q31_TO_FLOAT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_INT32_Q31_TO_FLOAT  TI方式INT32的Q31转化浮点类型\n
*     LQ_TI_INT32_Q30_TO_FLOAT  TI方式INT32的Q30转化浮点类型\n
*     LQ_TI_INT32_Q29_TO_FLOAT  TI方式INT32的Q29转化浮点类型\n
*     LQ_TI_INT32_Q28_TO_FLOAT  TI方式INT32的Q28转化浮点类型\n
*     LQ_TI_INT32_Q27_TO_FLOAT  TI方式INT32的Q27转化浮点类型\n
*     LQ_TI_INT32_Q26_TO_FLOAT  TI方式INT32的Q26转化浮点类型\n
*     LQ_TI_INT32_Q25_TO_FLOAT  TI方式INT32的Q25转化浮点类型\n
*     LQ_TI_INT32_Q24_TO_FLOAT  TI方式INT32的Q24转化浮点类型\n
*     LQ_TI_INT32_Q23_TO_FLOAT  TI方式INT32的Q23转化浮点类型\n
*     LQ_TI_INT32_Q22_TO_FLOAT  TI方式INT32的Q22转化浮点类型\n
*     LQ_TI_INT32_Q21_TO_FLOAT  TI方式INT32的Q21转化浮点类型\n
*     LQ_TI_INT32_Q20_TO_FLOAT  TI方式INT32的Q20转化浮点类型\n
*     LQ_TI_INT32_Q19_TO_FLOAT  TI方式INT32的Q19转化浮点类型\n
*     LQ_TI_INT32_Q18_TO_FLOAT  TI方式INT32的Q18转化浮点类型\n
*     LQ_TI_INT32_Q17_TO_FLOAT  TI方式INT32的Q17转化浮点类型\n
*     LQ_TI_INT32_Q16_TO_FLOAT  TI方式INT32的Q16转化浮点类型\n
*     LQ_TI_INT32_Q15_TO_FLOAT  TI方式INT32的Q15转化浮点类型\n
*     LQ_TI_INT32_Q14_TO_FLOAT  TI方式INT32的Q14转化浮点类型\n
*     LQ_TI_INT32_Q13_TO_FLOAT  TI方式INT32的Q13转化浮点类型\n
*     LQ_TI_INT32_Q12_TO_FLOAT  TI方式INT32的Q12转化浮点类型\n
*     LQ_TI_INT32_Q11_TO_FLOAT  TI方式INT32的Q11转化浮点类型\n
*     LQ_TI_INT32_Q10_TO_FLOAT  TI方式INT32的Q10转化浮点类型\n
*     LQ_TI_INT32_Q9_TO_FLOAT  TI方式INT32的Q9转化浮点类型\n
*     LQ_TI_INT32_Q8_TO_FLOAT  TI方式INT32的Q8转化浮点类型\n
*     LQ_TI_INT32_Q7_TO_FLOAT  TI方式INT32的Q7转化浮点类型\n
*     LQ_TI_INT32_Q6_TO_FLOAT  TI方式INT32的Q6转化浮点类型\n
*     LQ_TI_INT32_Q5_TO_FLOAT  TI方式INT32的Q5转化浮点类型\n
*     LQ_TI_INT32_Q4_TO_FLOAT  TI方式INT32的Q4转化浮点类型\n
*     LQ_TI_INT32_Q3_TO_FLOAT  TI方式INT32的Q3转化浮点类型\n
*     LQ_TI_INT32_Q2_TO_FLOAT  TI方式INT32的Q2转化浮点类型\n
*     LQ_TI_INT32_Q1_TO_FLOAT  TI方式INT32的Q1转化浮点类型\n
*/
LQ_F_32BIT LQ_TI_INT32_Q31_TO_FLOAT(LQ_I_32BIT A, LQ_ERROR* lq_error)
{
    LQ_UI_16BIT ui16Exp;
    LQ_UI_32BIT uiq23Result;
    LQ_UI_32BIT uiq31Input;
    //!< 初始化指数部分偏移量
    ui16Exp = 16256;
    //!< 保存符号位
    if (A < 0)
    {
        ui16Exp |= 0x8000;
        uiq31Input = (LQ_UI_32BIT)(-(LQ_I_64BIT)A);
    }
    else if (A == 0)
    {
        return (0);
    }
    else
    {
        uiq31Input = A;
    }
    LQ_TI_Q2F_NORMALIZE(uiq31Input, ui16Exp);
    /*对uiq31结果进行四舍五入并切换到uiq23*/
    uiq23Result = (LQ_UI_32BIT)(((LQ_UI_64BIT)uiq31Input + 0x0080u) >> 8);
    if (uiq23Result >= 0x01000000u)
    {
        uiq23Result = 0;
        ui16Exp += 0x0080;
    }
    /*删除尾数的隐含MSB位 */
    uiq23Result &= ~0x00800000;
    /*
    *将构造的指数和符号位添加到尾数。我们必须使用
    *四舍五入会导致尾数溢出的情况下的加法。
    *当这种情况发生时，尾数结果为2，其中MSB为零
    *exp的LSB被设置为1。在指数上加一就是
    *尾数为2的正确处理。不需要缩放
    *尾数，因为在这种情况下它总是等于零。
   */
    uiq23Result += (LQ_UI_32BIT)ui16Exp << 16;
    return LQ_TI_UINT32_BITS_TO_FLOAT(uiq23Result);
}
/**@brief (TI方法)INT32类型Q30格式转浮点
* @details 采用估算位+指数位+符号位三位结合，能提高精度
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为浮点数
* @code*    LQ_TI_INT32_Q30_TO_FLOAT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_INT32_Q31_TO_FLOAT  TI方式INT32的Q31转化浮点类型\n
*     LQ_TI_INT32_Q30_TO_FLOAT  TI方式INT32的Q30转化浮点类型\n
*     LQ_TI_INT32_Q29_TO_FLOAT  TI方式INT32的Q29转化浮点类型\n
*     LQ_TI_INT32_Q28_TO_FLOAT  TI方式INT32的Q28转化浮点类型\n
*     LQ_TI_INT32_Q27_TO_FLOAT  TI方式INT32的Q27转化浮点类型\n
*     LQ_TI_INT32_Q26_TO_FLOAT  TI方式INT32的Q26转化浮点类型\n
*     LQ_TI_INT32_Q25_TO_FLOAT  TI方式INT32的Q25转化浮点类型\n
*     LQ_TI_INT32_Q24_TO_FLOAT  TI方式INT32的Q24转化浮点类型\n
*     LQ_TI_INT32_Q23_TO_FLOAT  TI方式INT32的Q23转化浮点类型\n
*     LQ_TI_INT32_Q22_TO_FLOAT  TI方式INT32的Q22转化浮点类型\n
*     LQ_TI_INT32_Q21_TO_FLOAT  TI方式INT32的Q21转化浮点类型\n
*     LQ_TI_INT32_Q20_TO_FLOAT  TI方式INT32的Q20转化浮点类型\n
*     LQ_TI_INT32_Q19_TO_FLOAT  TI方式INT32的Q19转化浮点类型\n
*     LQ_TI_INT32_Q18_TO_FLOAT  TI方式INT32的Q18转化浮点类型\n
*     LQ_TI_INT32_Q17_TO_FLOAT  TI方式INT32的Q17转化浮点类型\n
*     LQ_TI_INT32_Q16_TO_FLOAT  TI方式INT32的Q16转化浮点类型\n
*     LQ_TI_INT32_Q15_TO_FLOAT  TI方式INT32的Q15转化浮点类型\n
*     LQ_TI_INT32_Q14_TO_FLOAT  TI方式INT32的Q14转化浮点类型\n
*     LQ_TI_INT32_Q13_TO_FLOAT  TI方式INT32的Q13转化浮点类型\n
*     LQ_TI_INT32_Q12_TO_FLOAT  TI方式INT32的Q12转化浮点类型\n
*     LQ_TI_INT32_Q11_TO_FLOAT  TI方式INT32的Q11转化浮点类型\n
*     LQ_TI_INT32_Q10_TO_FLOAT  TI方式INT32的Q10转化浮点类型\n
*     LQ_TI_INT32_Q9_TO_FLOAT  TI方式INT32的Q9转化浮点类型\n
*     LQ_TI_INT32_Q8_TO_FLOAT  TI方式INT32的Q8转化浮点类型\n
*     LQ_TI_INT32_Q7_TO_FLOAT  TI方式INT32的Q7转化浮点类型\n
*     LQ_TI_INT32_Q6_TO_FLOAT  TI方式INT32的Q6转化浮点类型\n
*     LQ_TI_INT32_Q5_TO_FLOAT  TI方式INT32的Q5转化浮点类型\n
*     LQ_TI_INT32_Q4_TO_FLOAT  TI方式INT32的Q4转化浮点类型\n
*     LQ_TI_INT32_Q3_TO_FLOAT  TI方式INT32的Q3转化浮点类型\n
*     LQ_TI_INT32_Q2_TO_FLOAT  TI方式INT32的Q2转化浮点类型\n
*     LQ_TI_INT32_Q1_TO_FLOAT  TI方式INT32的Q1转化浮点类型\n
*/
LQ_F_32BIT LQ_TI_INT32_Q30_TO_FLOAT(LQ_I_32BIT A, LQ_ERROR* lq_error)
{
    LQ_UI_16BIT ui16Exp;
    LQ_UI_32BIT uiq23Result;
    LQ_UI_32BIT uiq31Input;
    //!< 初始化指数部分偏移量
    ui16Exp = 16384;
    //!< 保存符号位
    if (A < 0)
    {
        ui16Exp |= 0x8000;
        uiq31Input = (LQ_UI_32BIT)(-(LQ_I_64BIT)A);
    }
    else if (A == 0)
    {
        return (0);
    }
    else
    {
        uiq31Input = A;
    }
    LQ_TI_Q2F_NORMALIZE(uiq31Input, ui16Exp);
    /*对uiq31结果进行四舍五入并切换到uiq23*/
    uiq23Result = (LQ_UI_32BIT)(((LQ_UI_64BIT)uiq31Input + 0x0080u) >> 8);
    if (uiq23Result >= 0x01000000u)
    {
        uiq23Result = 0;
        ui16Exp += 0x0080;
    }
    /*删除尾数的隐含MSB位 */
    uiq23Result &= ~0x00800000;
    /*
    *将构造的指数和符号位添加到尾数。我们必须使用
    *四舍五入会导致尾数溢出的情况下的加法。
    *当这种情况发生时，尾数结果为2，其中MSB为零
    *exp的LSB被设置为1。在指数上加一就是
    *尾数为2的正确处理。不需要缩放
    *尾数，因为在这种情况下它总是等于零。
   */
    uiq23Result += (LQ_UI_32BIT)ui16Exp << 16;
    return LQ_TI_UINT32_BITS_TO_FLOAT(uiq23Result);
}
/**@brief (TI方法)INT32类型Q29格式转浮点
* @details 采用估算位+指数位+符号位三位结合，能提高精度
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为浮点数
* @code*    LQ_TI_INT32_Q29_TO_FLOAT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_INT32_Q31_TO_FLOAT  TI方式INT32的Q31转化浮点类型\n
*     LQ_TI_INT32_Q30_TO_FLOAT  TI方式INT32的Q30转化浮点类型\n
*     LQ_TI_INT32_Q29_TO_FLOAT  TI方式INT32的Q29转化浮点类型\n
*     LQ_TI_INT32_Q28_TO_FLOAT  TI方式INT32的Q28转化浮点类型\n
*     LQ_TI_INT32_Q27_TO_FLOAT  TI方式INT32的Q27转化浮点类型\n
*     LQ_TI_INT32_Q26_TO_FLOAT  TI方式INT32的Q26转化浮点类型\n
*     LQ_TI_INT32_Q25_TO_FLOAT  TI方式INT32的Q25转化浮点类型\n
*     LQ_TI_INT32_Q24_TO_FLOAT  TI方式INT32的Q24转化浮点类型\n
*     LQ_TI_INT32_Q23_TO_FLOAT  TI方式INT32的Q23转化浮点类型\n
*     LQ_TI_INT32_Q22_TO_FLOAT  TI方式INT32的Q22转化浮点类型\n
*     LQ_TI_INT32_Q21_TO_FLOAT  TI方式INT32的Q21转化浮点类型\n
*     LQ_TI_INT32_Q20_TO_FLOAT  TI方式INT32的Q20转化浮点类型\n
*     LQ_TI_INT32_Q19_TO_FLOAT  TI方式INT32的Q19转化浮点类型\n
*     LQ_TI_INT32_Q18_TO_FLOAT  TI方式INT32的Q18转化浮点类型\n
*     LQ_TI_INT32_Q17_TO_FLOAT  TI方式INT32的Q17转化浮点类型\n
*     LQ_TI_INT32_Q16_TO_FLOAT  TI方式INT32的Q16转化浮点类型\n
*     LQ_TI_INT32_Q15_TO_FLOAT  TI方式INT32的Q15转化浮点类型\n
*     LQ_TI_INT32_Q14_TO_FLOAT  TI方式INT32的Q14转化浮点类型\n
*     LQ_TI_INT32_Q13_TO_FLOAT  TI方式INT32的Q13转化浮点类型\n
*     LQ_TI_INT32_Q12_TO_FLOAT  TI方式INT32的Q12转化浮点类型\n
*     LQ_TI_INT32_Q11_TO_FLOAT  TI方式INT32的Q11转化浮点类型\n
*     LQ_TI_INT32_Q10_TO_FLOAT  TI方式INT32的Q10转化浮点类型\n
*     LQ_TI_INT32_Q9_TO_FLOAT  TI方式INT32的Q9转化浮点类型\n
*     LQ_TI_INT32_Q8_TO_FLOAT  TI方式INT32的Q8转化浮点类型\n
*     LQ_TI_INT32_Q7_TO_FLOAT  TI方式INT32的Q7转化浮点类型\n
*     LQ_TI_INT32_Q6_TO_FLOAT  TI方式INT32的Q6转化浮点类型\n
*     LQ_TI_INT32_Q5_TO_FLOAT  TI方式INT32的Q5转化浮点类型\n
*     LQ_TI_INT32_Q4_TO_FLOAT  TI方式INT32的Q4转化浮点类型\n
*     LQ_TI_INT32_Q3_TO_FLOAT  TI方式INT32的Q3转化浮点类型\n
*     LQ_TI_INT32_Q2_TO_FLOAT  TI方式INT32的Q2转化浮点类型\n
*     LQ_TI_INT32_Q1_TO_FLOAT  TI方式INT32的Q1转化浮点类型\n
*/
LQ_F_32BIT LQ_TI_INT32_Q29_TO_FLOAT(LQ_I_32BIT A, LQ_ERROR* lq_error)
{
    LQ_UI_16BIT ui16Exp;
    LQ_UI_32BIT uiq23Result;
    LQ_UI_32BIT uiq31Input;
    //!< 初始化指数部分偏移量
    ui16Exp = 16512;
    //!< 保存符号位
    if (A < 0)
    {
        ui16Exp |= 0x8000;
        uiq31Input = (LQ_UI_32BIT)(-(LQ_I_64BIT)A);
    }
    else if (A == 0)
    {
        return (0);
    }
    else
    {
        uiq31Input = A;
    }
    LQ_TI_Q2F_NORMALIZE(uiq31Input, ui16Exp);
    /*对uiq31结果进行四舍五入并切换到uiq23*/
    uiq23Result = (LQ_UI_32BIT)(((LQ_UI_64BIT)uiq31Input + 0x0080u) >> 8);
    if (uiq23Result >= 0x01000000u)
    {
        uiq23Result = 0;
        ui16Exp += 0x0080;
    }
    /*删除尾数的隐含MSB位 */
    uiq23Result &= ~0x00800000;
    /*
    *将构造的指数和符号位添加到尾数。我们必须使用
    *四舍五入会导致尾数溢出的情况下的加法。
    *当这种情况发生时，尾数结果为2，其中MSB为零
    *exp的LSB被设置为1。在指数上加一就是
    *尾数为2的正确处理。不需要缩放
    *尾数，因为在这种情况下它总是等于零。
   */
    uiq23Result += (LQ_UI_32BIT)ui16Exp << 16;
    return LQ_TI_UINT32_BITS_TO_FLOAT(uiq23Result);
}
/**@brief (TI方法)INT32类型Q28格式转浮点
* @details 采用估算位+指数位+符号位三位结合，能提高精度
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为浮点数
* @code*    LQ_TI_INT32_Q28_TO_FLOAT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_INT32_Q31_TO_FLOAT  TI方式INT32的Q31转化浮点类型\n
*     LQ_TI_INT32_Q30_TO_FLOAT  TI方式INT32的Q30转化浮点类型\n
*     LQ_TI_INT32_Q29_TO_FLOAT  TI方式INT32的Q29转化浮点类型\n
*     LQ_TI_INT32_Q28_TO_FLOAT  TI方式INT32的Q28转化浮点类型\n
*     LQ_TI_INT32_Q27_TO_FLOAT  TI方式INT32的Q27转化浮点类型\n
*     LQ_TI_INT32_Q26_TO_FLOAT  TI方式INT32的Q26转化浮点类型\n
*     LQ_TI_INT32_Q25_TO_FLOAT  TI方式INT32的Q25转化浮点类型\n
*     LQ_TI_INT32_Q24_TO_FLOAT  TI方式INT32的Q24转化浮点类型\n
*     LQ_TI_INT32_Q23_TO_FLOAT  TI方式INT32的Q23转化浮点类型\n
*     LQ_TI_INT32_Q22_TO_FLOAT  TI方式INT32的Q22转化浮点类型\n
*     LQ_TI_INT32_Q21_TO_FLOAT  TI方式INT32的Q21转化浮点类型\n
*     LQ_TI_INT32_Q20_TO_FLOAT  TI方式INT32的Q20转化浮点类型\n
*     LQ_TI_INT32_Q19_TO_FLOAT  TI方式INT32的Q19转化浮点类型\n
*     LQ_TI_INT32_Q18_TO_FLOAT  TI方式INT32的Q18转化浮点类型\n
*     LQ_TI_INT32_Q17_TO_FLOAT  TI方式INT32的Q17转化浮点类型\n
*     LQ_TI_INT32_Q16_TO_FLOAT  TI方式INT32的Q16转化浮点类型\n
*     LQ_TI_INT32_Q15_TO_FLOAT  TI方式INT32的Q15转化浮点类型\n
*     LQ_TI_INT32_Q14_TO_FLOAT  TI方式INT32的Q14转化浮点类型\n
*     LQ_TI_INT32_Q13_TO_FLOAT  TI方式INT32的Q13转化浮点类型\n
*     LQ_TI_INT32_Q12_TO_FLOAT  TI方式INT32的Q12转化浮点类型\n
*     LQ_TI_INT32_Q11_TO_FLOAT  TI方式INT32的Q11转化浮点类型\n
*     LQ_TI_INT32_Q10_TO_FLOAT  TI方式INT32的Q10转化浮点类型\n
*     LQ_TI_INT32_Q9_TO_FLOAT  TI方式INT32的Q9转化浮点类型\n
*     LQ_TI_INT32_Q8_TO_FLOAT  TI方式INT32的Q8转化浮点类型\n
*     LQ_TI_INT32_Q7_TO_FLOAT  TI方式INT32的Q7转化浮点类型\n
*     LQ_TI_INT32_Q6_TO_FLOAT  TI方式INT32的Q6转化浮点类型\n
*     LQ_TI_INT32_Q5_TO_FLOAT  TI方式INT32的Q5转化浮点类型\n
*     LQ_TI_INT32_Q4_TO_FLOAT  TI方式INT32的Q4转化浮点类型\n
*     LQ_TI_INT32_Q3_TO_FLOAT  TI方式INT32的Q3转化浮点类型\n
*     LQ_TI_INT32_Q2_TO_FLOAT  TI方式INT32的Q2转化浮点类型\n
*     LQ_TI_INT32_Q1_TO_FLOAT  TI方式INT32的Q1转化浮点类型\n
*/
LQ_F_32BIT LQ_TI_INT32_Q28_TO_FLOAT(LQ_I_32BIT A, LQ_ERROR* lq_error)
{
    LQ_UI_16BIT ui16Exp;
    LQ_UI_32BIT uiq23Result;
    LQ_UI_32BIT uiq31Input;
    //!< 初始化指数部分偏移量
    ui16Exp = 16640;
    //!< 保存符号位
    if (A < 0)
    {
        ui16Exp |= 0x8000;
        uiq31Input = (LQ_UI_32BIT)(-(LQ_I_64BIT)A);
    }
    else if (A == 0)
    {
        return (0);
    }
    else
    {
        uiq31Input = A;
    }
    LQ_TI_Q2F_NORMALIZE(uiq31Input, ui16Exp);
    /*对uiq31结果进行四舍五入并切换到uiq23*/
    uiq23Result = (LQ_UI_32BIT)(((LQ_UI_64BIT)uiq31Input + 0x0080u) >> 8);
    if (uiq23Result >= 0x01000000u)
    {
        uiq23Result = 0;
        ui16Exp += 0x0080;
    }
    /*删除尾数的隐含MSB位 */
    uiq23Result &= ~0x00800000;
    /*
    *将构造的指数和符号位添加到尾数。我们必须使用
    *四舍五入会导致尾数溢出的情况下的加法。
    *当这种情况发生时，尾数结果为2，其中MSB为零
    *exp的LSB被设置为1。在指数上加一就是
    *尾数为2的正确处理。不需要缩放
    *尾数，因为在这种情况下它总是等于零。
   */
    uiq23Result += (LQ_UI_32BIT)ui16Exp << 16;
    return LQ_TI_UINT32_BITS_TO_FLOAT(uiq23Result);
}
/**@brief (TI方法)INT32类型Q27格式转浮点
* @details 采用估算位+指数位+符号位三位结合，能提高精度
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为浮点数
* @code*    LQ_TI_INT32_Q27_TO_FLOAT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_INT32_Q31_TO_FLOAT  TI方式INT32的Q31转化浮点类型\n
*     LQ_TI_INT32_Q30_TO_FLOAT  TI方式INT32的Q30转化浮点类型\n
*     LQ_TI_INT32_Q29_TO_FLOAT  TI方式INT32的Q29转化浮点类型\n
*     LQ_TI_INT32_Q28_TO_FLOAT  TI方式INT32的Q28转化浮点类型\n
*     LQ_TI_INT32_Q27_TO_FLOAT  TI方式INT32的Q27转化浮点类型\n
*     LQ_TI_INT32_Q26_TO_FLOAT  TI方式INT32的Q26转化浮点类型\n
*     LQ_TI_INT32_Q25_TO_FLOAT  TI方式INT32的Q25转化浮点类型\n
*     LQ_TI_INT32_Q24_TO_FLOAT  TI方式INT32的Q24转化浮点类型\n
*     LQ_TI_INT32_Q23_TO_FLOAT  TI方式INT32的Q23转化浮点类型\n
*     LQ_TI_INT32_Q22_TO_FLOAT  TI方式INT32的Q22转化浮点类型\n
*     LQ_TI_INT32_Q21_TO_FLOAT  TI方式INT32的Q21转化浮点类型\n
*     LQ_TI_INT32_Q20_TO_FLOAT  TI方式INT32的Q20转化浮点类型\n
*     LQ_TI_INT32_Q19_TO_FLOAT  TI方式INT32的Q19转化浮点类型\n
*     LQ_TI_INT32_Q18_TO_FLOAT  TI方式INT32的Q18转化浮点类型\n
*     LQ_TI_INT32_Q17_TO_FLOAT  TI方式INT32的Q17转化浮点类型\n
*     LQ_TI_INT32_Q16_TO_FLOAT  TI方式INT32的Q16转化浮点类型\n
*     LQ_TI_INT32_Q15_TO_FLOAT  TI方式INT32的Q15转化浮点类型\n
*     LQ_TI_INT32_Q14_TO_FLOAT  TI方式INT32的Q14转化浮点类型\n
*     LQ_TI_INT32_Q13_TO_FLOAT  TI方式INT32的Q13转化浮点类型\n
*     LQ_TI_INT32_Q12_TO_FLOAT  TI方式INT32的Q12转化浮点类型\n
*     LQ_TI_INT32_Q11_TO_FLOAT  TI方式INT32的Q11转化浮点类型\n
*     LQ_TI_INT32_Q10_TO_FLOAT  TI方式INT32的Q10转化浮点类型\n
*     LQ_TI_INT32_Q9_TO_FLOAT  TI方式INT32的Q9转化浮点类型\n
*     LQ_TI_INT32_Q8_TO_FLOAT  TI方式INT32的Q8转化浮点类型\n
*     LQ_TI_INT32_Q7_TO_FLOAT  TI方式INT32的Q7转化浮点类型\n
*     LQ_TI_INT32_Q6_TO_FLOAT  TI方式INT32的Q6转化浮点类型\n
*     LQ_TI_INT32_Q5_TO_FLOAT  TI方式INT32的Q5转化浮点类型\n
*     LQ_TI_INT32_Q4_TO_FLOAT  TI方式INT32的Q4转化浮点类型\n
*     LQ_TI_INT32_Q3_TO_FLOAT  TI方式INT32的Q3转化浮点类型\n
*     LQ_TI_INT32_Q2_TO_FLOAT  TI方式INT32的Q2转化浮点类型\n
*     LQ_TI_INT32_Q1_TO_FLOAT  TI方式INT32的Q1转化浮点类型\n
*/
LQ_F_32BIT LQ_TI_INT32_Q27_TO_FLOAT(LQ_I_32BIT A, LQ_ERROR* lq_error)
{
    LQ_UI_16BIT ui16Exp;
    LQ_UI_32BIT uiq23Result;
    LQ_UI_32BIT uiq31Input;
    //!< 初始化指数部分偏移量
    ui16Exp = 16768;
    //!< 保存符号位
    if (A < 0)
    {
        ui16Exp |= 0x8000;
        uiq31Input = (LQ_UI_32BIT)(-(LQ_I_64BIT)A);
    }
    else if (A == 0)
    {
        return (0);
    }
    else
    {
        uiq31Input = A;
    }
    LQ_TI_Q2F_NORMALIZE(uiq31Input, ui16Exp);
    /*对uiq31结果进行四舍五入并切换到uiq23*/
    uiq23Result = (LQ_UI_32BIT)(((LQ_UI_64BIT)uiq31Input + 0x0080u) >> 8);
    if (uiq23Result >= 0x01000000u)
    {
        uiq23Result = 0;
        ui16Exp += 0x0080;
    }
    /*删除尾数的隐含MSB位 */
    uiq23Result &= ~0x00800000;
    /*
    *将构造的指数和符号位添加到尾数。我们必须使用
    *四舍五入会导致尾数溢出的情况下的加法。
    *当这种情况发生时，尾数结果为2，其中MSB为零
    *exp的LSB被设置为1。在指数上加一就是
    *尾数为2的正确处理。不需要缩放
    *尾数，因为在这种情况下它总是等于零。
   */
    uiq23Result += (LQ_UI_32BIT)ui16Exp << 16;
    return LQ_TI_UINT32_BITS_TO_FLOAT(uiq23Result);
}
/**@brief (TI方法)INT32类型Q26格式转浮点
* @details 采用估算位+指数位+符号位三位结合，能提高精度
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为浮点数
* @code*    LQ_TI_INT32_Q26_TO_FLOAT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_INT32_Q31_TO_FLOAT  TI方式INT32的Q31转化浮点类型\n
*     LQ_TI_INT32_Q30_TO_FLOAT  TI方式INT32的Q30转化浮点类型\n
*     LQ_TI_INT32_Q29_TO_FLOAT  TI方式INT32的Q29转化浮点类型\n
*     LQ_TI_INT32_Q28_TO_FLOAT  TI方式INT32的Q28转化浮点类型\n
*     LQ_TI_INT32_Q27_TO_FLOAT  TI方式INT32的Q27转化浮点类型\n
*     LQ_TI_INT32_Q26_TO_FLOAT  TI方式INT32的Q26转化浮点类型\n
*     LQ_TI_INT32_Q25_TO_FLOAT  TI方式INT32的Q25转化浮点类型\n
*     LQ_TI_INT32_Q24_TO_FLOAT  TI方式INT32的Q24转化浮点类型\n
*     LQ_TI_INT32_Q23_TO_FLOAT  TI方式INT32的Q23转化浮点类型\n
*     LQ_TI_INT32_Q22_TO_FLOAT  TI方式INT32的Q22转化浮点类型\n
*     LQ_TI_INT32_Q21_TO_FLOAT  TI方式INT32的Q21转化浮点类型\n
*     LQ_TI_INT32_Q20_TO_FLOAT  TI方式INT32的Q20转化浮点类型\n
*     LQ_TI_INT32_Q19_TO_FLOAT  TI方式INT32的Q19转化浮点类型\n
*     LQ_TI_INT32_Q18_TO_FLOAT  TI方式INT32的Q18转化浮点类型\n
*     LQ_TI_INT32_Q17_TO_FLOAT  TI方式INT32的Q17转化浮点类型\n
*     LQ_TI_INT32_Q16_TO_FLOAT  TI方式INT32的Q16转化浮点类型\n
*     LQ_TI_INT32_Q15_TO_FLOAT  TI方式INT32的Q15转化浮点类型\n
*     LQ_TI_INT32_Q14_TO_FLOAT  TI方式INT32的Q14转化浮点类型\n
*     LQ_TI_INT32_Q13_TO_FLOAT  TI方式INT32的Q13转化浮点类型\n
*     LQ_TI_INT32_Q12_TO_FLOAT  TI方式INT32的Q12转化浮点类型\n
*     LQ_TI_INT32_Q11_TO_FLOAT  TI方式INT32的Q11转化浮点类型\n
*     LQ_TI_INT32_Q10_TO_FLOAT  TI方式INT32的Q10转化浮点类型\n
*     LQ_TI_INT32_Q9_TO_FLOAT  TI方式INT32的Q9转化浮点类型\n
*     LQ_TI_INT32_Q8_TO_FLOAT  TI方式INT32的Q8转化浮点类型\n
*     LQ_TI_INT32_Q7_TO_FLOAT  TI方式INT32的Q7转化浮点类型\n
*     LQ_TI_INT32_Q6_TO_FLOAT  TI方式INT32的Q6转化浮点类型\n
*     LQ_TI_INT32_Q5_TO_FLOAT  TI方式INT32的Q5转化浮点类型\n
*     LQ_TI_INT32_Q4_TO_FLOAT  TI方式INT32的Q4转化浮点类型\n
*     LQ_TI_INT32_Q3_TO_FLOAT  TI方式INT32的Q3转化浮点类型\n
*     LQ_TI_INT32_Q2_TO_FLOAT  TI方式INT32的Q2转化浮点类型\n
*     LQ_TI_INT32_Q1_TO_FLOAT  TI方式INT32的Q1转化浮点类型\n
*/
LQ_F_32BIT LQ_TI_INT32_Q26_TO_FLOAT(LQ_I_32BIT A, LQ_ERROR* lq_error)
{
    LQ_UI_16BIT ui16Exp;
    LQ_UI_32BIT uiq23Result;
    LQ_UI_32BIT uiq31Input;
    //!< 初始化指数部分偏移量
    ui16Exp = 16896;
    //!< 保存符号位
    if (A < 0)
    {
        ui16Exp |= 0x8000;
        uiq31Input = (LQ_UI_32BIT)(-(LQ_I_64BIT)A);
    }
    else if (A == 0)
    {
        return (0);
    }
    else
    {
        uiq31Input = A;
    }
    LQ_TI_Q2F_NORMALIZE(uiq31Input, ui16Exp);
    /*对uiq31结果进行四舍五入并切换到uiq23*/
    uiq23Result = (LQ_UI_32BIT)(((LQ_UI_64BIT)uiq31Input + 0x0080u) >> 8);
    if (uiq23Result >= 0x01000000u)
    {
        uiq23Result = 0;
        ui16Exp += 0x0080;
    }
    /*删除尾数的隐含MSB位 */
    uiq23Result &= ~0x00800000;
    /*
    *将构造的指数和符号位添加到尾数。我们必须使用
    *四舍五入会导致尾数溢出的情况下的加法。
    *当这种情况发生时，尾数结果为2，其中MSB为零
    *exp的LSB被设置为1。在指数上加一就是
    *尾数为2的正确处理。不需要缩放
    *尾数，因为在这种情况下它总是等于零。
   */
    uiq23Result += (LQ_UI_32BIT)ui16Exp << 16;
    return LQ_TI_UINT32_BITS_TO_FLOAT(uiq23Result);
}
/**@brief (TI方法)INT32类型Q25格式转浮点
* @details 采用估算位+指数位+符号位三位结合，能提高精度
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为浮点数
* @code*    LQ_TI_INT32_Q25_TO_FLOAT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_INT32_Q31_TO_FLOAT  TI方式INT32的Q31转化浮点类型\n
*     LQ_TI_INT32_Q30_TO_FLOAT  TI方式INT32的Q30转化浮点类型\n
*     LQ_TI_INT32_Q29_TO_FLOAT  TI方式INT32的Q29转化浮点类型\n
*     LQ_TI_INT32_Q28_TO_FLOAT  TI方式INT32的Q28转化浮点类型\n
*     LQ_TI_INT32_Q27_TO_FLOAT  TI方式INT32的Q27转化浮点类型\n
*     LQ_TI_INT32_Q26_TO_FLOAT  TI方式INT32的Q26转化浮点类型\n
*     LQ_TI_INT32_Q25_TO_FLOAT  TI方式INT32的Q25转化浮点类型\n
*     LQ_TI_INT32_Q24_TO_FLOAT  TI方式INT32的Q24转化浮点类型\n
*     LQ_TI_INT32_Q23_TO_FLOAT  TI方式INT32的Q23转化浮点类型\n
*     LQ_TI_INT32_Q22_TO_FLOAT  TI方式INT32的Q22转化浮点类型\n
*     LQ_TI_INT32_Q21_TO_FLOAT  TI方式INT32的Q21转化浮点类型\n
*     LQ_TI_INT32_Q20_TO_FLOAT  TI方式INT32的Q20转化浮点类型\n
*     LQ_TI_INT32_Q19_TO_FLOAT  TI方式INT32的Q19转化浮点类型\n
*     LQ_TI_INT32_Q18_TO_FLOAT  TI方式INT32的Q18转化浮点类型\n
*     LQ_TI_INT32_Q17_TO_FLOAT  TI方式INT32的Q17转化浮点类型\n
*     LQ_TI_INT32_Q16_TO_FLOAT  TI方式INT32的Q16转化浮点类型\n
*     LQ_TI_INT32_Q15_TO_FLOAT  TI方式INT32的Q15转化浮点类型\n
*     LQ_TI_INT32_Q14_TO_FLOAT  TI方式INT32的Q14转化浮点类型\n
*     LQ_TI_INT32_Q13_TO_FLOAT  TI方式INT32的Q13转化浮点类型\n
*     LQ_TI_INT32_Q12_TO_FLOAT  TI方式INT32的Q12转化浮点类型\n
*     LQ_TI_INT32_Q11_TO_FLOAT  TI方式INT32的Q11转化浮点类型\n
*     LQ_TI_INT32_Q10_TO_FLOAT  TI方式INT32的Q10转化浮点类型\n
*     LQ_TI_INT32_Q9_TO_FLOAT  TI方式INT32的Q9转化浮点类型\n
*     LQ_TI_INT32_Q8_TO_FLOAT  TI方式INT32的Q8转化浮点类型\n
*     LQ_TI_INT32_Q7_TO_FLOAT  TI方式INT32的Q7转化浮点类型\n
*     LQ_TI_INT32_Q6_TO_FLOAT  TI方式INT32的Q6转化浮点类型\n
*     LQ_TI_INT32_Q5_TO_FLOAT  TI方式INT32的Q5转化浮点类型\n
*     LQ_TI_INT32_Q4_TO_FLOAT  TI方式INT32的Q4转化浮点类型\n
*     LQ_TI_INT32_Q3_TO_FLOAT  TI方式INT32的Q3转化浮点类型\n
*     LQ_TI_INT32_Q2_TO_FLOAT  TI方式INT32的Q2转化浮点类型\n
*     LQ_TI_INT32_Q1_TO_FLOAT  TI方式INT32的Q1转化浮点类型\n
*/
LQ_F_32BIT LQ_TI_INT32_Q25_TO_FLOAT(LQ_I_32BIT A, LQ_ERROR* lq_error)
{
    LQ_UI_16BIT ui16Exp;
    LQ_UI_32BIT uiq23Result;
    LQ_UI_32BIT uiq31Input;
    //!< 初始化指数部分偏移量
    ui16Exp = 17024;
    //!< 保存符号位
    if (A < 0)
    {
        ui16Exp |= 0x8000;
        uiq31Input = (LQ_UI_32BIT)(-(LQ_I_64BIT)A);
    }
    else if (A == 0)
    {
        return (0);
    }
    else
    {
        uiq31Input = A;
    }
    LQ_TI_Q2F_NORMALIZE(uiq31Input, ui16Exp);
    /*对uiq31结果进行四舍五入并切换到uiq23*/
    uiq23Result = (LQ_UI_32BIT)(((LQ_UI_64BIT)uiq31Input + 0x0080u) >> 8);
    if (uiq23Result >= 0x01000000u)
    {
        uiq23Result = 0;
        ui16Exp += 0x0080;
    }
    /*删除尾数的隐含MSB位 */
    uiq23Result &= ~0x00800000;
    /*
    *将构造的指数和符号位添加到尾数。我们必须使用
    *四舍五入会导致尾数溢出的情况下的加法。
    *当这种情况发生时，尾数结果为2，其中MSB为零
    *exp的LSB被设置为1。在指数上加一就是
    *尾数为2的正确处理。不需要缩放
    *尾数，因为在这种情况下它总是等于零。
   */
    uiq23Result += (LQ_UI_32BIT)ui16Exp << 16;
    return LQ_TI_UINT32_BITS_TO_FLOAT(uiq23Result);
}
/**@brief (TI方法)INT32类型Q24格式转浮点
* @details 采用估算位+指数位+符号位三位结合，能提高精度
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为浮点数
* @code*    LQ_TI_INT32_Q24_TO_FLOAT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_INT32_Q31_TO_FLOAT  TI方式INT32的Q31转化浮点类型\n
*     LQ_TI_INT32_Q30_TO_FLOAT  TI方式INT32的Q30转化浮点类型\n
*     LQ_TI_INT32_Q29_TO_FLOAT  TI方式INT32的Q29转化浮点类型\n
*     LQ_TI_INT32_Q28_TO_FLOAT  TI方式INT32的Q28转化浮点类型\n
*     LQ_TI_INT32_Q27_TO_FLOAT  TI方式INT32的Q27转化浮点类型\n
*     LQ_TI_INT32_Q26_TO_FLOAT  TI方式INT32的Q26转化浮点类型\n
*     LQ_TI_INT32_Q25_TO_FLOAT  TI方式INT32的Q25转化浮点类型\n
*     LQ_TI_INT32_Q24_TO_FLOAT  TI方式INT32的Q24转化浮点类型\n
*     LQ_TI_INT32_Q23_TO_FLOAT  TI方式INT32的Q23转化浮点类型\n
*     LQ_TI_INT32_Q22_TO_FLOAT  TI方式INT32的Q22转化浮点类型\n
*     LQ_TI_INT32_Q21_TO_FLOAT  TI方式INT32的Q21转化浮点类型\n
*     LQ_TI_INT32_Q20_TO_FLOAT  TI方式INT32的Q20转化浮点类型\n
*     LQ_TI_INT32_Q19_TO_FLOAT  TI方式INT32的Q19转化浮点类型\n
*     LQ_TI_INT32_Q18_TO_FLOAT  TI方式INT32的Q18转化浮点类型\n
*     LQ_TI_INT32_Q17_TO_FLOAT  TI方式INT32的Q17转化浮点类型\n
*     LQ_TI_INT32_Q16_TO_FLOAT  TI方式INT32的Q16转化浮点类型\n
*     LQ_TI_INT32_Q15_TO_FLOAT  TI方式INT32的Q15转化浮点类型\n
*     LQ_TI_INT32_Q14_TO_FLOAT  TI方式INT32的Q14转化浮点类型\n
*     LQ_TI_INT32_Q13_TO_FLOAT  TI方式INT32的Q13转化浮点类型\n
*     LQ_TI_INT32_Q12_TO_FLOAT  TI方式INT32的Q12转化浮点类型\n
*     LQ_TI_INT32_Q11_TO_FLOAT  TI方式INT32的Q11转化浮点类型\n
*     LQ_TI_INT32_Q10_TO_FLOAT  TI方式INT32的Q10转化浮点类型\n
*     LQ_TI_INT32_Q9_TO_FLOAT  TI方式INT32的Q9转化浮点类型\n
*     LQ_TI_INT32_Q8_TO_FLOAT  TI方式INT32的Q8转化浮点类型\n
*     LQ_TI_INT32_Q7_TO_FLOAT  TI方式INT32的Q7转化浮点类型\n
*     LQ_TI_INT32_Q6_TO_FLOAT  TI方式INT32的Q6转化浮点类型\n
*     LQ_TI_INT32_Q5_TO_FLOAT  TI方式INT32的Q5转化浮点类型\n
*     LQ_TI_INT32_Q4_TO_FLOAT  TI方式INT32的Q4转化浮点类型\n
*     LQ_TI_INT32_Q3_TO_FLOAT  TI方式INT32的Q3转化浮点类型\n
*     LQ_TI_INT32_Q2_TO_FLOAT  TI方式INT32的Q2转化浮点类型\n
*     LQ_TI_INT32_Q1_TO_FLOAT  TI方式INT32的Q1转化浮点类型\n
*/
LQ_F_32BIT LQ_TI_INT32_Q24_TO_FLOAT(LQ_I_32BIT A, LQ_ERROR* lq_error)
{
    LQ_UI_16BIT ui16Exp;
    LQ_UI_32BIT uiq23Result;
    LQ_UI_32BIT uiq31Input;
    //!< 初始化指数部分偏移量
    ui16Exp = 17152;
    //!< 保存符号位
    if (A < 0)
    {
        ui16Exp |= 0x8000;
        uiq31Input = (LQ_UI_32BIT)(-(LQ_I_64BIT)A);
    }
    else if (A == 0)
    {
        return (0);
    }
    else
    {
        uiq31Input = A;
    }
    LQ_TI_Q2F_NORMALIZE(uiq31Input, ui16Exp);
    /*对uiq31结果进行四舍五入并切换到uiq23*/
    uiq23Result = (LQ_UI_32BIT)(((LQ_UI_64BIT)uiq31Input + 0x0080u) >> 8);
    if (uiq23Result >= 0x01000000u)
    {
        uiq23Result = 0;
        ui16Exp += 0x0080;
    }
    /*删除尾数的隐含MSB位 */
    uiq23Result &= ~0x00800000;
    /*
    *将构造的指数和符号位添加到尾数。我们必须使用
    *四舍五入会导致尾数溢出的情况下的加法。
    *当这种情况发生时，尾数结果为2，其中MSB为零
    *exp的LSB被设置为1。在指数上加一就是
    *尾数为2的正确处理。不需要缩放
    *尾数，因为在这种情况下它总是等于零。
   */
    uiq23Result += (LQ_UI_32BIT)ui16Exp << 16;
    return LQ_TI_UINT32_BITS_TO_FLOAT(uiq23Result);
}
/**@brief (TI方法)INT32类型Q23格式转浮点
* @details 采用估算位+指数位+符号位三位结合，能提高精度
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为浮点数
* @code*    LQ_TI_INT32_Q23_TO_FLOAT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_INT32_Q31_TO_FLOAT  TI方式INT32的Q31转化浮点类型\n
*     LQ_TI_INT32_Q30_TO_FLOAT  TI方式INT32的Q30转化浮点类型\n
*     LQ_TI_INT32_Q29_TO_FLOAT  TI方式INT32的Q29转化浮点类型\n
*     LQ_TI_INT32_Q28_TO_FLOAT  TI方式INT32的Q28转化浮点类型\n
*     LQ_TI_INT32_Q27_TO_FLOAT  TI方式INT32的Q27转化浮点类型\n
*     LQ_TI_INT32_Q26_TO_FLOAT  TI方式INT32的Q26转化浮点类型\n
*     LQ_TI_INT32_Q25_TO_FLOAT  TI方式INT32的Q25转化浮点类型\n
*     LQ_TI_INT32_Q24_TO_FLOAT  TI方式INT32的Q24转化浮点类型\n
*     LQ_TI_INT32_Q23_TO_FLOAT  TI方式INT32的Q23转化浮点类型\n
*     LQ_TI_INT32_Q22_TO_FLOAT  TI方式INT32的Q22转化浮点类型\n
*     LQ_TI_INT32_Q21_TO_FLOAT  TI方式INT32的Q21转化浮点类型\n
*     LQ_TI_INT32_Q20_TO_FLOAT  TI方式INT32的Q20转化浮点类型\n
*     LQ_TI_INT32_Q19_TO_FLOAT  TI方式INT32的Q19转化浮点类型\n
*     LQ_TI_INT32_Q18_TO_FLOAT  TI方式INT32的Q18转化浮点类型\n
*     LQ_TI_INT32_Q17_TO_FLOAT  TI方式INT32的Q17转化浮点类型\n
*     LQ_TI_INT32_Q16_TO_FLOAT  TI方式INT32的Q16转化浮点类型\n
*     LQ_TI_INT32_Q15_TO_FLOAT  TI方式INT32的Q15转化浮点类型\n
*     LQ_TI_INT32_Q14_TO_FLOAT  TI方式INT32的Q14转化浮点类型\n
*     LQ_TI_INT32_Q13_TO_FLOAT  TI方式INT32的Q13转化浮点类型\n
*     LQ_TI_INT32_Q12_TO_FLOAT  TI方式INT32的Q12转化浮点类型\n
*     LQ_TI_INT32_Q11_TO_FLOAT  TI方式INT32的Q11转化浮点类型\n
*     LQ_TI_INT32_Q10_TO_FLOAT  TI方式INT32的Q10转化浮点类型\n
*     LQ_TI_INT32_Q9_TO_FLOAT  TI方式INT32的Q9转化浮点类型\n
*     LQ_TI_INT32_Q8_TO_FLOAT  TI方式INT32的Q8转化浮点类型\n
*     LQ_TI_INT32_Q7_TO_FLOAT  TI方式INT32的Q7转化浮点类型\n
*     LQ_TI_INT32_Q6_TO_FLOAT  TI方式INT32的Q6转化浮点类型\n
*     LQ_TI_INT32_Q5_TO_FLOAT  TI方式INT32的Q5转化浮点类型\n
*     LQ_TI_INT32_Q4_TO_FLOAT  TI方式INT32的Q4转化浮点类型\n
*     LQ_TI_INT32_Q3_TO_FLOAT  TI方式INT32的Q3转化浮点类型\n
*     LQ_TI_INT32_Q2_TO_FLOAT  TI方式INT32的Q2转化浮点类型\n
*     LQ_TI_INT32_Q1_TO_FLOAT  TI方式INT32的Q1转化浮点类型\n
*/
LQ_F_32BIT LQ_TI_INT32_Q23_TO_FLOAT(LQ_I_32BIT A, LQ_ERROR* lq_error)
{
    LQ_UI_16BIT ui16Exp;
    LQ_UI_32BIT uiq23Result;
    LQ_UI_32BIT uiq31Input;
    //!< 初始化指数部分偏移量
    ui16Exp = 17280;
    //!< 保存符号位
    if (A < 0)
    {
        ui16Exp |= 0x8000;
        uiq31Input = (LQ_UI_32BIT)(-(LQ_I_64BIT)A);
    }
    else if (A == 0)
    {
        return (0);
    }
    else
    {
        uiq31Input = A;
    }
    LQ_TI_Q2F_NORMALIZE(uiq31Input, ui16Exp);
    /*对uiq31结果进行四舍五入并切换到uiq23*/
    uiq23Result = (LQ_UI_32BIT)(((LQ_UI_64BIT)uiq31Input + 0x0080u) >> 8);
    if (uiq23Result >= 0x01000000u)
    {
        uiq23Result = 0;
        ui16Exp += 0x0080;
    }
    /*删除尾数的隐含MSB位 */
    uiq23Result &= ~0x00800000;
    /*
    *将构造的指数和符号位添加到尾数。我们必须使用
    *四舍五入会导致尾数溢出的情况下的加法。
    *当这种情况发生时，尾数结果为2，其中MSB为零
    *exp的LSB被设置为1。在指数上加一就是
    *尾数为2的正确处理。不需要缩放
    *尾数，因为在这种情况下它总是等于零。
   */
    uiq23Result += (LQ_UI_32BIT)ui16Exp << 16;
    return LQ_TI_UINT32_BITS_TO_FLOAT(uiq23Result);
}
/**@brief (TI方法)INT32类型Q22格式转浮点
* @details 采用估算位+指数位+符号位三位结合，能提高精度
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为浮点数
* @code*    LQ_TI_INT32_Q22_TO_FLOAT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_INT32_Q31_TO_FLOAT  TI方式INT32的Q31转化浮点类型\n
*     LQ_TI_INT32_Q30_TO_FLOAT  TI方式INT32的Q30转化浮点类型\n
*     LQ_TI_INT32_Q29_TO_FLOAT  TI方式INT32的Q29转化浮点类型\n
*     LQ_TI_INT32_Q28_TO_FLOAT  TI方式INT32的Q28转化浮点类型\n
*     LQ_TI_INT32_Q27_TO_FLOAT  TI方式INT32的Q27转化浮点类型\n
*     LQ_TI_INT32_Q26_TO_FLOAT  TI方式INT32的Q26转化浮点类型\n
*     LQ_TI_INT32_Q25_TO_FLOAT  TI方式INT32的Q25转化浮点类型\n
*     LQ_TI_INT32_Q24_TO_FLOAT  TI方式INT32的Q24转化浮点类型\n
*     LQ_TI_INT32_Q23_TO_FLOAT  TI方式INT32的Q23转化浮点类型\n
*     LQ_TI_INT32_Q22_TO_FLOAT  TI方式INT32的Q22转化浮点类型\n
*     LQ_TI_INT32_Q21_TO_FLOAT  TI方式INT32的Q21转化浮点类型\n
*     LQ_TI_INT32_Q20_TO_FLOAT  TI方式INT32的Q20转化浮点类型\n
*     LQ_TI_INT32_Q19_TO_FLOAT  TI方式INT32的Q19转化浮点类型\n
*     LQ_TI_INT32_Q18_TO_FLOAT  TI方式INT32的Q18转化浮点类型\n
*     LQ_TI_INT32_Q17_TO_FLOAT  TI方式INT32的Q17转化浮点类型\n
*     LQ_TI_INT32_Q16_TO_FLOAT  TI方式INT32的Q16转化浮点类型\n
*     LQ_TI_INT32_Q15_TO_FLOAT  TI方式INT32的Q15转化浮点类型\n
*     LQ_TI_INT32_Q14_TO_FLOAT  TI方式INT32的Q14转化浮点类型\n
*     LQ_TI_INT32_Q13_TO_FLOAT  TI方式INT32的Q13转化浮点类型\n
*     LQ_TI_INT32_Q12_TO_FLOAT  TI方式INT32的Q12转化浮点类型\n
*     LQ_TI_INT32_Q11_TO_FLOAT  TI方式INT32的Q11转化浮点类型\n
*     LQ_TI_INT32_Q10_TO_FLOAT  TI方式INT32的Q10转化浮点类型\n
*     LQ_TI_INT32_Q9_TO_FLOAT  TI方式INT32的Q9转化浮点类型\n
*     LQ_TI_INT32_Q8_TO_FLOAT  TI方式INT32的Q8转化浮点类型\n
*     LQ_TI_INT32_Q7_TO_FLOAT  TI方式INT32的Q7转化浮点类型\n
*     LQ_TI_INT32_Q6_TO_FLOAT  TI方式INT32的Q6转化浮点类型\n
*     LQ_TI_INT32_Q5_TO_FLOAT  TI方式INT32的Q5转化浮点类型\n
*     LQ_TI_INT32_Q4_TO_FLOAT  TI方式INT32的Q4转化浮点类型\n
*     LQ_TI_INT32_Q3_TO_FLOAT  TI方式INT32的Q3转化浮点类型\n
*     LQ_TI_INT32_Q2_TO_FLOAT  TI方式INT32的Q2转化浮点类型\n
*     LQ_TI_INT32_Q1_TO_FLOAT  TI方式INT32的Q1转化浮点类型\n
*/
LQ_F_32BIT LQ_TI_INT32_Q22_TO_FLOAT(LQ_I_32BIT A, LQ_ERROR* lq_error)
{
    LQ_UI_16BIT ui16Exp;
    LQ_UI_32BIT uiq23Result;
    LQ_UI_32BIT uiq31Input;
    //!< 初始化指数部分偏移量
    ui16Exp = 17408;
    //!< 保存符号位
    if (A < 0)
    {
        ui16Exp |= 0x8000;
        uiq31Input = (LQ_UI_32BIT)(-(LQ_I_64BIT)A);
    }
    else if (A == 0)
    {
        return (0);
    }
    else
    {
        uiq31Input = A;
    }
    LQ_TI_Q2F_NORMALIZE(uiq31Input, ui16Exp);
    /*对uiq31结果进行四舍五入并切换到uiq23*/
    uiq23Result = (LQ_UI_32BIT)(((LQ_UI_64BIT)uiq31Input + 0x0080u) >> 8);
    if (uiq23Result >= 0x01000000u)
    {
        uiq23Result = 0;
        ui16Exp += 0x0080;
    }
    /*删除尾数的隐含MSB位 */
    uiq23Result &= ~0x00800000;
    /*
    *将构造的指数和符号位添加到尾数。我们必须使用
    *四舍五入会导致尾数溢出的情况下的加法。
    *当这种情况发生时，尾数结果为2，其中MSB为零
    *exp的LSB被设置为1。在指数上加一就是
    *尾数为2的正确处理。不需要缩放
    *尾数，因为在这种情况下它总是等于零。
   */
    uiq23Result += (LQ_UI_32BIT)ui16Exp << 16;
    return LQ_TI_UINT32_BITS_TO_FLOAT(uiq23Result);
}
/**@brief (TI方法)INT32类型Q21格式转浮点
* @details 采用估算位+指数位+符号位三位结合，能提高精度
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为浮点数
* @code*    LQ_TI_INT32_Q21_TO_FLOAT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_INT32_Q31_TO_FLOAT  TI方式INT32的Q31转化浮点类型\n
*     LQ_TI_INT32_Q30_TO_FLOAT  TI方式INT32的Q30转化浮点类型\n
*     LQ_TI_INT32_Q29_TO_FLOAT  TI方式INT32的Q29转化浮点类型\n
*     LQ_TI_INT32_Q28_TO_FLOAT  TI方式INT32的Q28转化浮点类型\n
*     LQ_TI_INT32_Q27_TO_FLOAT  TI方式INT32的Q27转化浮点类型\n
*     LQ_TI_INT32_Q26_TO_FLOAT  TI方式INT32的Q26转化浮点类型\n
*     LQ_TI_INT32_Q25_TO_FLOAT  TI方式INT32的Q25转化浮点类型\n
*     LQ_TI_INT32_Q24_TO_FLOAT  TI方式INT32的Q24转化浮点类型\n
*     LQ_TI_INT32_Q23_TO_FLOAT  TI方式INT32的Q23转化浮点类型\n
*     LQ_TI_INT32_Q22_TO_FLOAT  TI方式INT32的Q22转化浮点类型\n
*     LQ_TI_INT32_Q21_TO_FLOAT  TI方式INT32的Q21转化浮点类型\n
*     LQ_TI_INT32_Q20_TO_FLOAT  TI方式INT32的Q20转化浮点类型\n
*     LQ_TI_INT32_Q19_TO_FLOAT  TI方式INT32的Q19转化浮点类型\n
*     LQ_TI_INT32_Q18_TO_FLOAT  TI方式INT32的Q18转化浮点类型\n
*     LQ_TI_INT32_Q17_TO_FLOAT  TI方式INT32的Q17转化浮点类型\n
*     LQ_TI_INT32_Q16_TO_FLOAT  TI方式INT32的Q16转化浮点类型\n
*     LQ_TI_INT32_Q15_TO_FLOAT  TI方式INT32的Q15转化浮点类型\n
*     LQ_TI_INT32_Q14_TO_FLOAT  TI方式INT32的Q14转化浮点类型\n
*     LQ_TI_INT32_Q13_TO_FLOAT  TI方式INT32的Q13转化浮点类型\n
*     LQ_TI_INT32_Q12_TO_FLOAT  TI方式INT32的Q12转化浮点类型\n
*     LQ_TI_INT32_Q11_TO_FLOAT  TI方式INT32的Q11转化浮点类型\n
*     LQ_TI_INT32_Q10_TO_FLOAT  TI方式INT32的Q10转化浮点类型\n
*     LQ_TI_INT32_Q9_TO_FLOAT  TI方式INT32的Q9转化浮点类型\n
*     LQ_TI_INT32_Q8_TO_FLOAT  TI方式INT32的Q8转化浮点类型\n
*     LQ_TI_INT32_Q7_TO_FLOAT  TI方式INT32的Q7转化浮点类型\n
*     LQ_TI_INT32_Q6_TO_FLOAT  TI方式INT32的Q6转化浮点类型\n
*     LQ_TI_INT32_Q5_TO_FLOAT  TI方式INT32的Q5转化浮点类型\n
*     LQ_TI_INT32_Q4_TO_FLOAT  TI方式INT32的Q4转化浮点类型\n
*     LQ_TI_INT32_Q3_TO_FLOAT  TI方式INT32的Q3转化浮点类型\n
*     LQ_TI_INT32_Q2_TO_FLOAT  TI方式INT32的Q2转化浮点类型\n
*     LQ_TI_INT32_Q1_TO_FLOAT  TI方式INT32的Q1转化浮点类型\n
*/
LQ_F_32BIT LQ_TI_INT32_Q21_TO_FLOAT(LQ_I_32BIT A, LQ_ERROR* lq_error)
{
    LQ_UI_16BIT ui16Exp;
    LQ_UI_32BIT uiq23Result;
    LQ_UI_32BIT uiq31Input;
    //!< 初始化指数部分偏移量
    ui16Exp = 17536;
    //!< 保存符号位
    if (A < 0)
    {
        ui16Exp |= 0x8000;
        uiq31Input = (LQ_UI_32BIT)(-(LQ_I_64BIT)A);
    }
    else if (A == 0)
    {
        return (0);
    }
    else
    {
        uiq31Input = A;
    }
    LQ_TI_Q2F_NORMALIZE(uiq31Input, ui16Exp);
    /*对uiq31结果进行四舍五入并切换到uiq23*/
    uiq23Result = (LQ_UI_32BIT)(((LQ_UI_64BIT)uiq31Input + 0x0080u) >> 8);
    if (uiq23Result >= 0x01000000u)
    {
        uiq23Result = 0;
        ui16Exp += 0x0080;
    }
    /*删除尾数的隐含MSB位 */
    uiq23Result &= ~0x00800000;
    /*
    *将构造的指数和符号位添加到尾数。我们必须使用
    *四舍五入会导致尾数溢出的情况下的加法。
    *当这种情况发生时，尾数结果为2，其中MSB为零
    *exp的LSB被设置为1。在指数上加一就是
    *尾数为2的正确处理。不需要缩放
    *尾数，因为在这种情况下它总是等于零。
   */
    uiq23Result += (LQ_UI_32BIT)ui16Exp << 16;
    return LQ_TI_UINT32_BITS_TO_FLOAT(uiq23Result);
}
/**@brief (TI方法)INT32类型Q20格式转浮点
* @details 采用估算位+指数位+符号位三位结合，能提高精度
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为浮点数
* @code*    LQ_TI_INT32_Q20_TO_FLOAT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_INT32_Q31_TO_FLOAT  TI方式INT32的Q31转化浮点类型\n
*     LQ_TI_INT32_Q30_TO_FLOAT  TI方式INT32的Q30转化浮点类型\n
*     LQ_TI_INT32_Q29_TO_FLOAT  TI方式INT32的Q29转化浮点类型\n
*     LQ_TI_INT32_Q28_TO_FLOAT  TI方式INT32的Q28转化浮点类型\n
*     LQ_TI_INT32_Q27_TO_FLOAT  TI方式INT32的Q27转化浮点类型\n
*     LQ_TI_INT32_Q26_TO_FLOAT  TI方式INT32的Q26转化浮点类型\n
*     LQ_TI_INT32_Q25_TO_FLOAT  TI方式INT32的Q25转化浮点类型\n
*     LQ_TI_INT32_Q24_TO_FLOAT  TI方式INT32的Q24转化浮点类型\n
*     LQ_TI_INT32_Q23_TO_FLOAT  TI方式INT32的Q23转化浮点类型\n
*     LQ_TI_INT32_Q22_TO_FLOAT  TI方式INT32的Q22转化浮点类型\n
*     LQ_TI_INT32_Q21_TO_FLOAT  TI方式INT32的Q21转化浮点类型\n
*     LQ_TI_INT32_Q20_TO_FLOAT  TI方式INT32的Q20转化浮点类型\n
*     LQ_TI_INT32_Q19_TO_FLOAT  TI方式INT32的Q19转化浮点类型\n
*     LQ_TI_INT32_Q18_TO_FLOAT  TI方式INT32的Q18转化浮点类型\n
*     LQ_TI_INT32_Q17_TO_FLOAT  TI方式INT32的Q17转化浮点类型\n
*     LQ_TI_INT32_Q16_TO_FLOAT  TI方式INT32的Q16转化浮点类型\n
*     LQ_TI_INT32_Q15_TO_FLOAT  TI方式INT32的Q15转化浮点类型\n
*     LQ_TI_INT32_Q14_TO_FLOAT  TI方式INT32的Q14转化浮点类型\n
*     LQ_TI_INT32_Q13_TO_FLOAT  TI方式INT32的Q13转化浮点类型\n
*     LQ_TI_INT32_Q12_TO_FLOAT  TI方式INT32的Q12转化浮点类型\n
*     LQ_TI_INT32_Q11_TO_FLOAT  TI方式INT32的Q11转化浮点类型\n
*     LQ_TI_INT32_Q10_TO_FLOAT  TI方式INT32的Q10转化浮点类型\n
*     LQ_TI_INT32_Q9_TO_FLOAT  TI方式INT32的Q9转化浮点类型\n
*     LQ_TI_INT32_Q8_TO_FLOAT  TI方式INT32的Q8转化浮点类型\n
*     LQ_TI_INT32_Q7_TO_FLOAT  TI方式INT32的Q7转化浮点类型\n
*     LQ_TI_INT32_Q6_TO_FLOAT  TI方式INT32的Q6转化浮点类型\n
*     LQ_TI_INT32_Q5_TO_FLOAT  TI方式INT32的Q5转化浮点类型\n
*     LQ_TI_INT32_Q4_TO_FLOAT  TI方式INT32的Q4转化浮点类型\n
*     LQ_TI_INT32_Q3_TO_FLOAT  TI方式INT32的Q3转化浮点类型\n
*     LQ_TI_INT32_Q2_TO_FLOAT  TI方式INT32的Q2转化浮点类型\n
*     LQ_TI_INT32_Q1_TO_FLOAT  TI方式INT32的Q1转化浮点类型\n
*/
LQ_F_32BIT LQ_TI_INT32_Q20_TO_FLOAT(LQ_I_32BIT A, LQ_ERROR* lq_error)
{
    LQ_UI_16BIT ui16Exp;
    LQ_UI_32BIT uiq23Result;
    LQ_UI_32BIT uiq31Input;
    //!< 初始化指数部分偏移量
    ui16Exp = 17664;
    //!< 保存符号位
    if (A < 0)
    {
        ui16Exp |= 0x8000;
        uiq31Input = (LQ_UI_32BIT)(-(LQ_I_64BIT)A);
    }
    else if (A == 0)
    {
        return (0);
    }
    else
    {
        uiq31Input = A;
    }
    LQ_TI_Q2F_NORMALIZE(uiq31Input, ui16Exp);
    /*对uiq31结果进行四舍五入并切换到uiq23*/
    uiq23Result = (LQ_UI_32BIT)(((LQ_UI_64BIT)uiq31Input + 0x0080u) >> 8);
    if (uiq23Result >= 0x01000000u)
    {
        uiq23Result = 0;
        ui16Exp += 0x0080;
    }
    /*删除尾数的隐含MSB位 */
    uiq23Result &= ~0x00800000;
    /*
    *将构造的指数和符号位添加到尾数。我们必须使用
    *四舍五入会导致尾数溢出的情况下的加法。
    *当这种情况发生时，尾数结果为2，其中MSB为零
    *exp的LSB被设置为1。在指数上加一就是
    *尾数为2的正确处理。不需要缩放
    *尾数，因为在这种情况下它总是等于零。
   */
    uiq23Result += (LQ_UI_32BIT)ui16Exp << 16;
    return LQ_TI_UINT32_BITS_TO_FLOAT(uiq23Result);
}
/**@brief (TI方法)INT32类型Q19格式转浮点
* @details 采用估算位+指数位+符号位三位结合，能提高精度
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为浮点数
* @code*    LQ_TI_INT32_Q19_TO_FLOAT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_INT32_Q31_TO_FLOAT  TI方式INT32的Q31转化浮点类型\n
*     LQ_TI_INT32_Q30_TO_FLOAT  TI方式INT32的Q30转化浮点类型\n
*     LQ_TI_INT32_Q29_TO_FLOAT  TI方式INT32的Q29转化浮点类型\n
*     LQ_TI_INT32_Q28_TO_FLOAT  TI方式INT32的Q28转化浮点类型\n
*     LQ_TI_INT32_Q27_TO_FLOAT  TI方式INT32的Q27转化浮点类型\n
*     LQ_TI_INT32_Q26_TO_FLOAT  TI方式INT32的Q26转化浮点类型\n
*     LQ_TI_INT32_Q25_TO_FLOAT  TI方式INT32的Q25转化浮点类型\n
*     LQ_TI_INT32_Q24_TO_FLOAT  TI方式INT32的Q24转化浮点类型\n
*     LQ_TI_INT32_Q23_TO_FLOAT  TI方式INT32的Q23转化浮点类型\n
*     LQ_TI_INT32_Q22_TO_FLOAT  TI方式INT32的Q22转化浮点类型\n
*     LQ_TI_INT32_Q21_TO_FLOAT  TI方式INT32的Q21转化浮点类型\n
*     LQ_TI_INT32_Q20_TO_FLOAT  TI方式INT32的Q20转化浮点类型\n
*     LQ_TI_INT32_Q19_TO_FLOAT  TI方式INT32的Q19转化浮点类型\n
*     LQ_TI_INT32_Q18_TO_FLOAT  TI方式INT32的Q18转化浮点类型\n
*     LQ_TI_INT32_Q17_TO_FLOAT  TI方式INT32的Q17转化浮点类型\n
*     LQ_TI_INT32_Q16_TO_FLOAT  TI方式INT32的Q16转化浮点类型\n
*     LQ_TI_INT32_Q15_TO_FLOAT  TI方式INT32的Q15转化浮点类型\n
*     LQ_TI_INT32_Q14_TO_FLOAT  TI方式INT32的Q14转化浮点类型\n
*     LQ_TI_INT32_Q13_TO_FLOAT  TI方式INT32的Q13转化浮点类型\n
*     LQ_TI_INT32_Q12_TO_FLOAT  TI方式INT32的Q12转化浮点类型\n
*     LQ_TI_INT32_Q11_TO_FLOAT  TI方式INT32的Q11转化浮点类型\n
*     LQ_TI_INT32_Q10_TO_FLOAT  TI方式INT32的Q10转化浮点类型\n
*     LQ_TI_INT32_Q9_TO_FLOAT  TI方式INT32的Q9转化浮点类型\n
*     LQ_TI_INT32_Q8_TO_FLOAT  TI方式INT32的Q8转化浮点类型\n
*     LQ_TI_INT32_Q7_TO_FLOAT  TI方式INT32的Q7转化浮点类型\n
*     LQ_TI_INT32_Q6_TO_FLOAT  TI方式INT32的Q6转化浮点类型\n
*     LQ_TI_INT32_Q5_TO_FLOAT  TI方式INT32的Q5转化浮点类型\n
*     LQ_TI_INT32_Q4_TO_FLOAT  TI方式INT32的Q4转化浮点类型\n
*     LQ_TI_INT32_Q3_TO_FLOAT  TI方式INT32的Q3转化浮点类型\n
*     LQ_TI_INT32_Q2_TO_FLOAT  TI方式INT32的Q2转化浮点类型\n
*     LQ_TI_INT32_Q1_TO_FLOAT  TI方式INT32的Q1转化浮点类型\n
*/
LQ_F_32BIT LQ_TI_INT32_Q19_TO_FLOAT(LQ_I_32BIT A, LQ_ERROR* lq_error)
{
    LQ_UI_16BIT ui16Exp;
    LQ_UI_32BIT uiq23Result;
    LQ_UI_32BIT uiq31Input;
    //!< 初始化指数部分偏移量
    ui16Exp = 17792;
    //!< 保存符号位
    if (A < 0)
    {
        ui16Exp |= 0x8000;
        uiq31Input = (LQ_UI_32BIT)(-(LQ_I_64BIT)A);
    }
    else if (A == 0)
    {
        return (0);
    }
    else
    {
        uiq31Input = A;
    }
    LQ_TI_Q2F_NORMALIZE(uiq31Input, ui16Exp);
    /*对uiq31结果进行四舍五入并切换到uiq23*/
    uiq23Result = (LQ_UI_32BIT)(((LQ_UI_64BIT)uiq31Input + 0x0080u) >> 8);
    if (uiq23Result >= 0x01000000u)
    {
        uiq23Result = 0;
        ui16Exp += 0x0080;
    }
    /*删除尾数的隐含MSB位 */
    uiq23Result &= ~0x00800000;
    /*
    *将构造的指数和符号位添加到尾数。我们必须使用
    *四舍五入会导致尾数溢出的情况下的加法。
    *当这种情况发生时，尾数结果为2，其中MSB为零
    *exp的LSB被设置为1。在指数上加一就是
    *尾数为2的正确处理。不需要缩放
    *尾数，因为在这种情况下它总是等于零。
   */
    uiq23Result += (LQ_UI_32BIT)ui16Exp << 16;
    return LQ_TI_UINT32_BITS_TO_FLOAT(uiq23Result);
}
/**@brief (TI方法)INT32类型Q18格式转浮点
* @details 采用估算位+指数位+符号位三位结合，能提高精度
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为浮点数
* @code*    LQ_TI_INT32_Q18_TO_FLOAT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_INT32_Q31_TO_FLOAT  TI方式INT32的Q31转化浮点类型\n
*     LQ_TI_INT32_Q30_TO_FLOAT  TI方式INT32的Q30转化浮点类型\n
*     LQ_TI_INT32_Q29_TO_FLOAT  TI方式INT32的Q29转化浮点类型\n
*     LQ_TI_INT32_Q28_TO_FLOAT  TI方式INT32的Q28转化浮点类型\n
*     LQ_TI_INT32_Q27_TO_FLOAT  TI方式INT32的Q27转化浮点类型\n
*     LQ_TI_INT32_Q26_TO_FLOAT  TI方式INT32的Q26转化浮点类型\n
*     LQ_TI_INT32_Q25_TO_FLOAT  TI方式INT32的Q25转化浮点类型\n
*     LQ_TI_INT32_Q24_TO_FLOAT  TI方式INT32的Q24转化浮点类型\n
*     LQ_TI_INT32_Q23_TO_FLOAT  TI方式INT32的Q23转化浮点类型\n
*     LQ_TI_INT32_Q22_TO_FLOAT  TI方式INT32的Q22转化浮点类型\n
*     LQ_TI_INT32_Q21_TO_FLOAT  TI方式INT32的Q21转化浮点类型\n
*     LQ_TI_INT32_Q20_TO_FLOAT  TI方式INT32的Q20转化浮点类型\n
*     LQ_TI_INT32_Q19_TO_FLOAT  TI方式INT32的Q19转化浮点类型\n
*     LQ_TI_INT32_Q18_TO_FLOAT  TI方式INT32的Q18转化浮点类型\n
*     LQ_TI_INT32_Q17_TO_FLOAT  TI方式INT32的Q17转化浮点类型\n
*     LQ_TI_INT32_Q16_TO_FLOAT  TI方式INT32的Q16转化浮点类型\n
*     LQ_TI_INT32_Q15_TO_FLOAT  TI方式INT32的Q15转化浮点类型\n
*     LQ_TI_INT32_Q14_TO_FLOAT  TI方式INT32的Q14转化浮点类型\n
*     LQ_TI_INT32_Q13_TO_FLOAT  TI方式INT32的Q13转化浮点类型\n
*     LQ_TI_INT32_Q12_TO_FLOAT  TI方式INT32的Q12转化浮点类型\n
*     LQ_TI_INT32_Q11_TO_FLOAT  TI方式INT32的Q11转化浮点类型\n
*     LQ_TI_INT32_Q10_TO_FLOAT  TI方式INT32的Q10转化浮点类型\n
*     LQ_TI_INT32_Q9_TO_FLOAT  TI方式INT32的Q9转化浮点类型\n
*     LQ_TI_INT32_Q8_TO_FLOAT  TI方式INT32的Q8转化浮点类型\n
*     LQ_TI_INT32_Q7_TO_FLOAT  TI方式INT32的Q7转化浮点类型\n
*     LQ_TI_INT32_Q6_TO_FLOAT  TI方式INT32的Q6转化浮点类型\n
*     LQ_TI_INT32_Q5_TO_FLOAT  TI方式INT32的Q5转化浮点类型\n
*     LQ_TI_INT32_Q4_TO_FLOAT  TI方式INT32的Q4转化浮点类型\n
*     LQ_TI_INT32_Q3_TO_FLOAT  TI方式INT32的Q3转化浮点类型\n
*     LQ_TI_INT32_Q2_TO_FLOAT  TI方式INT32的Q2转化浮点类型\n
*     LQ_TI_INT32_Q1_TO_FLOAT  TI方式INT32的Q1转化浮点类型\n
*/
LQ_F_32BIT LQ_TI_INT32_Q18_TO_FLOAT(LQ_I_32BIT A, LQ_ERROR* lq_error)
{
    LQ_UI_16BIT ui16Exp;
    LQ_UI_32BIT uiq23Result;
    LQ_UI_32BIT uiq31Input;
    //!< 初始化指数部分偏移量
    ui16Exp = 17920;
    //!< 保存符号位
    if (A < 0)
    {
        ui16Exp |= 0x8000;
        uiq31Input = (LQ_UI_32BIT)(-(LQ_I_64BIT)A);
    }
    else if (A == 0)
    {
        return (0);
    }
    else
    {
        uiq31Input = A;
    }
    LQ_TI_Q2F_NORMALIZE(uiq31Input, ui16Exp);
    /*对uiq31结果进行四舍五入并切换到uiq23*/
    uiq23Result = (LQ_UI_32BIT)(((LQ_UI_64BIT)uiq31Input + 0x0080u) >> 8);
    if (uiq23Result >= 0x01000000u)
    {
        uiq23Result = 0;
        ui16Exp += 0x0080;
    }
    /*删除尾数的隐含MSB位 */
    uiq23Result &= ~0x00800000;
    /*
    *将构造的指数和符号位添加到尾数。我们必须使用
    *四舍五入会导致尾数溢出的情况下的加法。
    *当这种情况发生时，尾数结果为2，其中MSB为零
    *exp的LSB被设置为1。在指数上加一就是
    *尾数为2的正确处理。不需要缩放
    *尾数，因为在这种情况下它总是等于零。
   */
    uiq23Result += (LQ_UI_32BIT)ui16Exp << 16;
    return LQ_TI_UINT32_BITS_TO_FLOAT(uiq23Result);
}
/**@brief (TI方法)INT32类型Q17格式转浮点
* @details 采用估算位+指数位+符号位三位结合，能提高精度
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为浮点数
* @code*    LQ_TI_INT32_Q17_TO_FLOAT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_INT32_Q31_TO_FLOAT  TI方式INT32的Q31转化浮点类型\n
*     LQ_TI_INT32_Q30_TO_FLOAT  TI方式INT32的Q30转化浮点类型\n
*     LQ_TI_INT32_Q29_TO_FLOAT  TI方式INT32的Q29转化浮点类型\n
*     LQ_TI_INT32_Q28_TO_FLOAT  TI方式INT32的Q28转化浮点类型\n
*     LQ_TI_INT32_Q27_TO_FLOAT  TI方式INT32的Q27转化浮点类型\n
*     LQ_TI_INT32_Q26_TO_FLOAT  TI方式INT32的Q26转化浮点类型\n
*     LQ_TI_INT32_Q25_TO_FLOAT  TI方式INT32的Q25转化浮点类型\n
*     LQ_TI_INT32_Q24_TO_FLOAT  TI方式INT32的Q24转化浮点类型\n
*     LQ_TI_INT32_Q23_TO_FLOAT  TI方式INT32的Q23转化浮点类型\n
*     LQ_TI_INT32_Q22_TO_FLOAT  TI方式INT32的Q22转化浮点类型\n
*     LQ_TI_INT32_Q21_TO_FLOAT  TI方式INT32的Q21转化浮点类型\n
*     LQ_TI_INT32_Q20_TO_FLOAT  TI方式INT32的Q20转化浮点类型\n
*     LQ_TI_INT32_Q19_TO_FLOAT  TI方式INT32的Q19转化浮点类型\n
*     LQ_TI_INT32_Q18_TO_FLOAT  TI方式INT32的Q18转化浮点类型\n
*     LQ_TI_INT32_Q17_TO_FLOAT  TI方式INT32的Q17转化浮点类型\n
*     LQ_TI_INT32_Q16_TO_FLOAT  TI方式INT32的Q16转化浮点类型\n
*     LQ_TI_INT32_Q15_TO_FLOAT  TI方式INT32的Q15转化浮点类型\n
*     LQ_TI_INT32_Q14_TO_FLOAT  TI方式INT32的Q14转化浮点类型\n
*     LQ_TI_INT32_Q13_TO_FLOAT  TI方式INT32的Q13转化浮点类型\n
*     LQ_TI_INT32_Q12_TO_FLOAT  TI方式INT32的Q12转化浮点类型\n
*     LQ_TI_INT32_Q11_TO_FLOAT  TI方式INT32的Q11转化浮点类型\n
*     LQ_TI_INT32_Q10_TO_FLOAT  TI方式INT32的Q10转化浮点类型\n
*     LQ_TI_INT32_Q9_TO_FLOAT  TI方式INT32的Q9转化浮点类型\n
*     LQ_TI_INT32_Q8_TO_FLOAT  TI方式INT32的Q8转化浮点类型\n
*     LQ_TI_INT32_Q7_TO_FLOAT  TI方式INT32的Q7转化浮点类型\n
*     LQ_TI_INT32_Q6_TO_FLOAT  TI方式INT32的Q6转化浮点类型\n
*     LQ_TI_INT32_Q5_TO_FLOAT  TI方式INT32的Q5转化浮点类型\n
*     LQ_TI_INT32_Q4_TO_FLOAT  TI方式INT32的Q4转化浮点类型\n
*     LQ_TI_INT32_Q3_TO_FLOAT  TI方式INT32的Q3转化浮点类型\n
*     LQ_TI_INT32_Q2_TO_FLOAT  TI方式INT32的Q2转化浮点类型\n
*     LQ_TI_INT32_Q1_TO_FLOAT  TI方式INT32的Q1转化浮点类型\n
*/
LQ_F_32BIT LQ_TI_INT32_Q17_TO_FLOAT(LQ_I_32BIT A, LQ_ERROR* lq_error)
{
    LQ_UI_16BIT ui16Exp;
    LQ_UI_32BIT uiq23Result;
    LQ_UI_32BIT uiq31Input;
    //!< 初始化指数部分偏移量
    ui16Exp = 18048;
    //!< 保存符号位
    if (A < 0)
    {
        ui16Exp |= 0x8000;
        uiq31Input = (LQ_UI_32BIT)(-(LQ_I_64BIT)A);
    }
    else if (A == 0)
    {
        return (0);
    }
    else
    {
        uiq31Input = A;
    }
    LQ_TI_Q2F_NORMALIZE(uiq31Input, ui16Exp);
    /*对uiq31结果进行四舍五入并切换到uiq23*/
    uiq23Result = (LQ_UI_32BIT)(((LQ_UI_64BIT)uiq31Input + 0x0080u) >> 8);
    if (uiq23Result >= 0x01000000u)
    {
        uiq23Result = 0;
        ui16Exp += 0x0080;
    }
    /*删除尾数的隐含MSB位 */
    uiq23Result &= ~0x00800000;
    /*
    *将构造的指数和符号位添加到尾数。我们必须使用
    *四舍五入会导致尾数溢出的情况下的加法。
    *当这种情况发生时，尾数结果为2，其中MSB为零
    *exp的LSB被设置为1。在指数上加一就是
    *尾数为2的正确处理。不需要缩放
    *尾数，因为在这种情况下它总是等于零。
   */
    uiq23Result += (LQ_UI_32BIT)ui16Exp << 16;
    return LQ_TI_UINT32_BITS_TO_FLOAT(uiq23Result);
}
/**@brief (TI方法)INT32类型Q16格式转浮点
* @details 采用估算位+指数位+符号位三位结合，能提高精度
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为浮点数
* @code*    LQ_TI_INT32_Q16_TO_FLOAT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_INT32_Q31_TO_FLOAT  TI方式INT32的Q31转化浮点类型\n
*     LQ_TI_INT32_Q30_TO_FLOAT  TI方式INT32的Q30转化浮点类型\n
*     LQ_TI_INT32_Q29_TO_FLOAT  TI方式INT32的Q29转化浮点类型\n
*     LQ_TI_INT32_Q28_TO_FLOAT  TI方式INT32的Q28转化浮点类型\n
*     LQ_TI_INT32_Q27_TO_FLOAT  TI方式INT32的Q27转化浮点类型\n
*     LQ_TI_INT32_Q26_TO_FLOAT  TI方式INT32的Q26转化浮点类型\n
*     LQ_TI_INT32_Q25_TO_FLOAT  TI方式INT32的Q25转化浮点类型\n
*     LQ_TI_INT32_Q24_TO_FLOAT  TI方式INT32的Q24转化浮点类型\n
*     LQ_TI_INT32_Q23_TO_FLOAT  TI方式INT32的Q23转化浮点类型\n
*     LQ_TI_INT32_Q22_TO_FLOAT  TI方式INT32的Q22转化浮点类型\n
*     LQ_TI_INT32_Q21_TO_FLOAT  TI方式INT32的Q21转化浮点类型\n
*     LQ_TI_INT32_Q20_TO_FLOAT  TI方式INT32的Q20转化浮点类型\n
*     LQ_TI_INT32_Q19_TO_FLOAT  TI方式INT32的Q19转化浮点类型\n
*     LQ_TI_INT32_Q18_TO_FLOAT  TI方式INT32的Q18转化浮点类型\n
*     LQ_TI_INT32_Q17_TO_FLOAT  TI方式INT32的Q17转化浮点类型\n
*     LQ_TI_INT32_Q16_TO_FLOAT  TI方式INT32的Q16转化浮点类型\n
*     LQ_TI_INT32_Q15_TO_FLOAT  TI方式INT32的Q15转化浮点类型\n
*     LQ_TI_INT32_Q14_TO_FLOAT  TI方式INT32的Q14转化浮点类型\n
*     LQ_TI_INT32_Q13_TO_FLOAT  TI方式INT32的Q13转化浮点类型\n
*     LQ_TI_INT32_Q12_TO_FLOAT  TI方式INT32的Q12转化浮点类型\n
*     LQ_TI_INT32_Q11_TO_FLOAT  TI方式INT32的Q11转化浮点类型\n
*     LQ_TI_INT32_Q10_TO_FLOAT  TI方式INT32的Q10转化浮点类型\n
*     LQ_TI_INT32_Q9_TO_FLOAT  TI方式INT32的Q9转化浮点类型\n
*     LQ_TI_INT32_Q8_TO_FLOAT  TI方式INT32的Q8转化浮点类型\n
*     LQ_TI_INT32_Q7_TO_FLOAT  TI方式INT32的Q7转化浮点类型\n
*     LQ_TI_INT32_Q6_TO_FLOAT  TI方式INT32的Q6转化浮点类型\n
*     LQ_TI_INT32_Q5_TO_FLOAT  TI方式INT32的Q5转化浮点类型\n
*     LQ_TI_INT32_Q4_TO_FLOAT  TI方式INT32的Q4转化浮点类型\n
*     LQ_TI_INT32_Q3_TO_FLOAT  TI方式INT32的Q3转化浮点类型\n
*     LQ_TI_INT32_Q2_TO_FLOAT  TI方式INT32的Q2转化浮点类型\n
*     LQ_TI_INT32_Q1_TO_FLOAT  TI方式INT32的Q1转化浮点类型\n
*/
LQ_F_32BIT LQ_TI_INT32_Q16_TO_FLOAT(LQ_I_32BIT A, LQ_ERROR* lq_error)
{
    LQ_UI_16BIT ui16Exp;
    LQ_UI_32BIT uiq23Result;
    LQ_UI_32BIT uiq31Input;
    //!< 初始化指数部分偏移量
    ui16Exp = 18176;
    //!< 保存符号位
    if (A < 0)
    {
        ui16Exp |= 0x8000;
        uiq31Input = (LQ_UI_32BIT)(-(LQ_I_64BIT)A);
    }
    else if (A == 0)
    {
        return (0);
    }
    else
    {
        uiq31Input = A;
    }
    LQ_TI_Q2F_NORMALIZE(uiq31Input, ui16Exp);
    /*对uiq31结果进行四舍五入并切换到uiq23*/
    uiq23Result = (LQ_UI_32BIT)(((LQ_UI_64BIT)uiq31Input + 0x0080u) >> 8);
    if (uiq23Result >= 0x01000000u)
    {
        uiq23Result = 0;
        ui16Exp += 0x0080;
    }
    /*删除尾数的隐含MSB位 */
    uiq23Result &= ~0x00800000;
    /*
    *将构造的指数和符号位添加到尾数。我们必须使用
    *四舍五入会导致尾数溢出的情况下的加法。
    *当这种情况发生时，尾数结果为2，其中MSB为零
    *exp的LSB被设置为1。在指数上加一就是
    *尾数为2的正确处理。不需要缩放
    *尾数，因为在这种情况下它总是等于零。
   */
    uiq23Result += (LQ_UI_32BIT)ui16Exp << 16;
    return LQ_TI_UINT32_BITS_TO_FLOAT(uiq23Result);
}
/**@brief (TI方法)INT32类型Q15格式转浮点
* @details 采用估算位+指数位+符号位三位结合，能提高精度
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为浮点数
* @code*    LQ_TI_INT32_Q15_TO_FLOAT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_INT32_Q31_TO_FLOAT  TI方式INT32的Q31转化浮点类型\n
*     LQ_TI_INT32_Q30_TO_FLOAT  TI方式INT32的Q30转化浮点类型\n
*     LQ_TI_INT32_Q29_TO_FLOAT  TI方式INT32的Q29转化浮点类型\n
*     LQ_TI_INT32_Q28_TO_FLOAT  TI方式INT32的Q28转化浮点类型\n
*     LQ_TI_INT32_Q27_TO_FLOAT  TI方式INT32的Q27转化浮点类型\n
*     LQ_TI_INT32_Q26_TO_FLOAT  TI方式INT32的Q26转化浮点类型\n
*     LQ_TI_INT32_Q25_TO_FLOAT  TI方式INT32的Q25转化浮点类型\n
*     LQ_TI_INT32_Q24_TO_FLOAT  TI方式INT32的Q24转化浮点类型\n
*     LQ_TI_INT32_Q23_TO_FLOAT  TI方式INT32的Q23转化浮点类型\n
*     LQ_TI_INT32_Q22_TO_FLOAT  TI方式INT32的Q22转化浮点类型\n
*     LQ_TI_INT32_Q21_TO_FLOAT  TI方式INT32的Q21转化浮点类型\n
*     LQ_TI_INT32_Q20_TO_FLOAT  TI方式INT32的Q20转化浮点类型\n
*     LQ_TI_INT32_Q19_TO_FLOAT  TI方式INT32的Q19转化浮点类型\n
*     LQ_TI_INT32_Q18_TO_FLOAT  TI方式INT32的Q18转化浮点类型\n
*     LQ_TI_INT32_Q17_TO_FLOAT  TI方式INT32的Q17转化浮点类型\n
*     LQ_TI_INT32_Q16_TO_FLOAT  TI方式INT32的Q16转化浮点类型\n
*     LQ_TI_INT32_Q15_TO_FLOAT  TI方式INT32的Q15转化浮点类型\n
*     LQ_TI_INT32_Q14_TO_FLOAT  TI方式INT32的Q14转化浮点类型\n
*     LQ_TI_INT32_Q13_TO_FLOAT  TI方式INT32的Q13转化浮点类型\n
*     LQ_TI_INT32_Q12_TO_FLOAT  TI方式INT32的Q12转化浮点类型\n
*     LQ_TI_INT32_Q11_TO_FLOAT  TI方式INT32的Q11转化浮点类型\n
*     LQ_TI_INT32_Q10_TO_FLOAT  TI方式INT32的Q10转化浮点类型\n
*     LQ_TI_INT32_Q9_TO_FLOAT  TI方式INT32的Q9转化浮点类型\n
*     LQ_TI_INT32_Q8_TO_FLOAT  TI方式INT32的Q8转化浮点类型\n
*     LQ_TI_INT32_Q7_TO_FLOAT  TI方式INT32的Q7转化浮点类型\n
*     LQ_TI_INT32_Q6_TO_FLOAT  TI方式INT32的Q6转化浮点类型\n
*     LQ_TI_INT32_Q5_TO_FLOAT  TI方式INT32的Q5转化浮点类型\n
*     LQ_TI_INT32_Q4_TO_FLOAT  TI方式INT32的Q4转化浮点类型\n
*     LQ_TI_INT32_Q3_TO_FLOAT  TI方式INT32的Q3转化浮点类型\n
*     LQ_TI_INT32_Q2_TO_FLOAT  TI方式INT32的Q2转化浮点类型\n
*     LQ_TI_INT32_Q1_TO_FLOAT  TI方式INT32的Q1转化浮点类型\n
*/
LQ_F_32BIT LQ_TI_INT32_Q15_TO_FLOAT(LQ_I_32BIT A, LQ_ERROR* lq_error)
{
    LQ_UI_16BIT ui16Exp;
    LQ_UI_32BIT uiq23Result;
    LQ_UI_32BIT uiq31Input;
    //!< 初始化指数部分偏移量
    ui16Exp = 18304;
    //!< 保存符号位
    if (A < 0)
    {
        ui16Exp |= 0x8000;
        uiq31Input = (LQ_UI_32BIT)(-(LQ_I_64BIT)A);
    }
    else if (A == 0)
    {
        return (0);
    }
    else
    {
        uiq31Input = A;
    }
    LQ_TI_Q2F_NORMALIZE(uiq31Input, ui16Exp);
    /*对uiq31结果进行四舍五入并切换到uiq23*/
    uiq23Result = (LQ_UI_32BIT)(((LQ_UI_64BIT)uiq31Input + 0x0080u) >> 8);
    if (uiq23Result >= 0x01000000u)
    {
        uiq23Result = 0;
        ui16Exp += 0x0080;
    }
    /*删除尾数的隐含MSB位 */
    uiq23Result &= ~0x00800000;
    /*
    *将构造的指数和符号位添加到尾数。我们必须使用
    *四舍五入会导致尾数溢出的情况下的加法。
    *当这种情况发生时，尾数结果为2，其中MSB为零
    *exp的LSB被设置为1。在指数上加一就是
    *尾数为2的正确处理。不需要缩放
    *尾数，因为在这种情况下它总是等于零。
   */
    uiq23Result += (LQ_UI_32BIT)ui16Exp << 16;
    return LQ_TI_UINT32_BITS_TO_FLOAT(uiq23Result);
}
/**@brief (TI方法)INT32类型Q14格式转浮点
* @details 采用估算位+指数位+符号位三位结合，能提高精度
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为浮点数
* @code*    LQ_TI_INT32_Q14_TO_FLOAT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_INT32_Q31_TO_FLOAT  TI方式INT32的Q31转化浮点类型\n
*     LQ_TI_INT32_Q30_TO_FLOAT  TI方式INT32的Q30转化浮点类型\n
*     LQ_TI_INT32_Q29_TO_FLOAT  TI方式INT32的Q29转化浮点类型\n
*     LQ_TI_INT32_Q28_TO_FLOAT  TI方式INT32的Q28转化浮点类型\n
*     LQ_TI_INT32_Q27_TO_FLOAT  TI方式INT32的Q27转化浮点类型\n
*     LQ_TI_INT32_Q26_TO_FLOAT  TI方式INT32的Q26转化浮点类型\n
*     LQ_TI_INT32_Q25_TO_FLOAT  TI方式INT32的Q25转化浮点类型\n
*     LQ_TI_INT32_Q24_TO_FLOAT  TI方式INT32的Q24转化浮点类型\n
*     LQ_TI_INT32_Q23_TO_FLOAT  TI方式INT32的Q23转化浮点类型\n
*     LQ_TI_INT32_Q22_TO_FLOAT  TI方式INT32的Q22转化浮点类型\n
*     LQ_TI_INT32_Q21_TO_FLOAT  TI方式INT32的Q21转化浮点类型\n
*     LQ_TI_INT32_Q20_TO_FLOAT  TI方式INT32的Q20转化浮点类型\n
*     LQ_TI_INT32_Q19_TO_FLOAT  TI方式INT32的Q19转化浮点类型\n
*     LQ_TI_INT32_Q18_TO_FLOAT  TI方式INT32的Q18转化浮点类型\n
*     LQ_TI_INT32_Q17_TO_FLOAT  TI方式INT32的Q17转化浮点类型\n
*     LQ_TI_INT32_Q16_TO_FLOAT  TI方式INT32的Q16转化浮点类型\n
*     LQ_TI_INT32_Q15_TO_FLOAT  TI方式INT32的Q15转化浮点类型\n
*     LQ_TI_INT32_Q14_TO_FLOAT  TI方式INT32的Q14转化浮点类型\n
*     LQ_TI_INT32_Q13_TO_FLOAT  TI方式INT32的Q13转化浮点类型\n
*     LQ_TI_INT32_Q12_TO_FLOAT  TI方式INT32的Q12转化浮点类型\n
*     LQ_TI_INT32_Q11_TO_FLOAT  TI方式INT32的Q11转化浮点类型\n
*     LQ_TI_INT32_Q10_TO_FLOAT  TI方式INT32的Q10转化浮点类型\n
*     LQ_TI_INT32_Q9_TO_FLOAT  TI方式INT32的Q9转化浮点类型\n
*     LQ_TI_INT32_Q8_TO_FLOAT  TI方式INT32的Q8转化浮点类型\n
*     LQ_TI_INT32_Q7_TO_FLOAT  TI方式INT32的Q7转化浮点类型\n
*     LQ_TI_INT32_Q6_TO_FLOAT  TI方式INT32的Q6转化浮点类型\n
*     LQ_TI_INT32_Q5_TO_FLOAT  TI方式INT32的Q5转化浮点类型\n
*     LQ_TI_INT32_Q4_TO_FLOAT  TI方式INT32的Q4转化浮点类型\n
*     LQ_TI_INT32_Q3_TO_FLOAT  TI方式INT32的Q3转化浮点类型\n
*     LQ_TI_INT32_Q2_TO_FLOAT  TI方式INT32的Q2转化浮点类型\n
*     LQ_TI_INT32_Q1_TO_FLOAT  TI方式INT32的Q1转化浮点类型\n
*/
LQ_F_32BIT LQ_TI_INT32_Q14_TO_FLOAT(LQ_I_32BIT A, LQ_ERROR* lq_error)
{
    LQ_UI_16BIT ui16Exp;
    LQ_UI_32BIT uiq23Result;
    LQ_UI_32BIT uiq31Input;
    //!< 初始化指数部分偏移量
    ui16Exp = 18432;
    //!< 保存符号位
    if (A < 0)
    {
        ui16Exp |= 0x8000;
        uiq31Input = (LQ_UI_32BIT)(-(LQ_I_64BIT)A);
    }
    else if (A == 0)
    {
        return (0);
    }
    else
    {
        uiq31Input = A;
    }
    LQ_TI_Q2F_NORMALIZE(uiq31Input, ui16Exp);
    /*对uiq31结果进行四舍五入并切换到uiq23*/
    uiq23Result = (LQ_UI_32BIT)(((LQ_UI_64BIT)uiq31Input + 0x0080u) >> 8);
    if (uiq23Result >= 0x01000000u)
    {
        uiq23Result = 0;
        ui16Exp += 0x0080;
    }
    /*删除尾数的隐含MSB位 */
    uiq23Result &= ~0x00800000;
    /*
    *将构造的指数和符号位添加到尾数。我们必须使用
    *四舍五入会导致尾数溢出的情况下的加法。
    *当这种情况发生时，尾数结果为2，其中MSB为零
    *exp的LSB被设置为1。在指数上加一就是
    *尾数为2的正确处理。不需要缩放
    *尾数，因为在这种情况下它总是等于零。
   */
    uiq23Result += (LQ_UI_32BIT)ui16Exp << 16;
    return LQ_TI_UINT32_BITS_TO_FLOAT(uiq23Result);
}
/**@brief (TI方法)INT32类型Q13格式转浮点
* @details 采用估算位+指数位+符号位三位结合，能提高精度
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为浮点数
* @code*    LQ_TI_INT32_Q13_TO_FLOAT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_INT32_Q31_TO_FLOAT  TI方式INT32的Q31转化浮点类型\n
*     LQ_TI_INT32_Q30_TO_FLOAT  TI方式INT32的Q30转化浮点类型\n
*     LQ_TI_INT32_Q29_TO_FLOAT  TI方式INT32的Q29转化浮点类型\n
*     LQ_TI_INT32_Q28_TO_FLOAT  TI方式INT32的Q28转化浮点类型\n
*     LQ_TI_INT32_Q27_TO_FLOAT  TI方式INT32的Q27转化浮点类型\n
*     LQ_TI_INT32_Q26_TO_FLOAT  TI方式INT32的Q26转化浮点类型\n
*     LQ_TI_INT32_Q25_TO_FLOAT  TI方式INT32的Q25转化浮点类型\n
*     LQ_TI_INT32_Q24_TO_FLOAT  TI方式INT32的Q24转化浮点类型\n
*     LQ_TI_INT32_Q23_TO_FLOAT  TI方式INT32的Q23转化浮点类型\n
*     LQ_TI_INT32_Q22_TO_FLOAT  TI方式INT32的Q22转化浮点类型\n
*     LQ_TI_INT32_Q21_TO_FLOAT  TI方式INT32的Q21转化浮点类型\n
*     LQ_TI_INT32_Q20_TO_FLOAT  TI方式INT32的Q20转化浮点类型\n
*     LQ_TI_INT32_Q19_TO_FLOAT  TI方式INT32的Q19转化浮点类型\n
*     LQ_TI_INT32_Q18_TO_FLOAT  TI方式INT32的Q18转化浮点类型\n
*     LQ_TI_INT32_Q17_TO_FLOAT  TI方式INT32的Q17转化浮点类型\n
*     LQ_TI_INT32_Q16_TO_FLOAT  TI方式INT32的Q16转化浮点类型\n
*     LQ_TI_INT32_Q15_TO_FLOAT  TI方式INT32的Q15转化浮点类型\n
*     LQ_TI_INT32_Q14_TO_FLOAT  TI方式INT32的Q14转化浮点类型\n
*     LQ_TI_INT32_Q13_TO_FLOAT  TI方式INT32的Q13转化浮点类型\n
*     LQ_TI_INT32_Q12_TO_FLOAT  TI方式INT32的Q12转化浮点类型\n
*     LQ_TI_INT32_Q11_TO_FLOAT  TI方式INT32的Q11转化浮点类型\n
*     LQ_TI_INT32_Q10_TO_FLOAT  TI方式INT32的Q10转化浮点类型\n
*     LQ_TI_INT32_Q9_TO_FLOAT  TI方式INT32的Q9转化浮点类型\n
*     LQ_TI_INT32_Q8_TO_FLOAT  TI方式INT32的Q8转化浮点类型\n
*     LQ_TI_INT32_Q7_TO_FLOAT  TI方式INT32的Q7转化浮点类型\n
*     LQ_TI_INT32_Q6_TO_FLOAT  TI方式INT32的Q6转化浮点类型\n
*     LQ_TI_INT32_Q5_TO_FLOAT  TI方式INT32的Q5转化浮点类型\n
*     LQ_TI_INT32_Q4_TO_FLOAT  TI方式INT32的Q4转化浮点类型\n
*     LQ_TI_INT32_Q3_TO_FLOAT  TI方式INT32的Q3转化浮点类型\n
*     LQ_TI_INT32_Q2_TO_FLOAT  TI方式INT32的Q2转化浮点类型\n
*     LQ_TI_INT32_Q1_TO_FLOAT  TI方式INT32的Q1转化浮点类型\n
*/
LQ_F_32BIT LQ_TI_INT32_Q13_TO_FLOAT(LQ_I_32BIT A, LQ_ERROR* lq_error)
{
    LQ_UI_16BIT ui16Exp;
    LQ_UI_32BIT uiq23Result;
    LQ_UI_32BIT uiq31Input;
    //!< 初始化指数部分偏移量
    ui16Exp = 18560;
    //!< 保存符号位
    if (A < 0)
    {
        ui16Exp |= 0x8000;
        uiq31Input = (LQ_UI_32BIT)(-(LQ_I_64BIT)A);
    }
    else if (A == 0)
    {
        return (0);
    }
    else
    {
        uiq31Input = A;
    }
    LQ_TI_Q2F_NORMALIZE(uiq31Input, ui16Exp);
    /*对uiq31结果进行四舍五入并切换到uiq23*/
    uiq23Result = (LQ_UI_32BIT)(((LQ_UI_64BIT)uiq31Input + 0x0080u) >> 8);
    if (uiq23Result >= 0x01000000u)
    {
        uiq23Result = 0;
        ui16Exp += 0x0080;
    }
    /*删除尾数的隐含MSB位 */
    uiq23Result &= ~0x00800000;
    /*
    *将构造的指数和符号位添加到尾数。我们必须使用
    *四舍五入会导致尾数溢出的情况下的加法。
    *当这种情况发生时，尾数结果为2，其中MSB为零
    *exp的LSB被设置为1。在指数上加一就是
    *尾数为2的正确处理。不需要缩放
    *尾数，因为在这种情况下它总是等于零。
   */
    uiq23Result += (LQ_UI_32BIT)ui16Exp << 16;
    return LQ_TI_UINT32_BITS_TO_FLOAT(uiq23Result);
}
/**@brief (TI方法)INT32类型Q12格式转浮点
* @details 采用估算位+指数位+符号位三位结合，能提高精度
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为浮点数
* @code*    LQ_TI_INT32_Q12_TO_FLOAT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_INT32_Q31_TO_FLOAT  TI方式INT32的Q31转化浮点类型\n
*     LQ_TI_INT32_Q30_TO_FLOAT  TI方式INT32的Q30转化浮点类型\n
*     LQ_TI_INT32_Q29_TO_FLOAT  TI方式INT32的Q29转化浮点类型\n
*     LQ_TI_INT32_Q28_TO_FLOAT  TI方式INT32的Q28转化浮点类型\n
*     LQ_TI_INT32_Q27_TO_FLOAT  TI方式INT32的Q27转化浮点类型\n
*     LQ_TI_INT32_Q26_TO_FLOAT  TI方式INT32的Q26转化浮点类型\n
*     LQ_TI_INT32_Q25_TO_FLOAT  TI方式INT32的Q25转化浮点类型\n
*     LQ_TI_INT32_Q24_TO_FLOAT  TI方式INT32的Q24转化浮点类型\n
*     LQ_TI_INT32_Q23_TO_FLOAT  TI方式INT32的Q23转化浮点类型\n
*     LQ_TI_INT32_Q22_TO_FLOAT  TI方式INT32的Q22转化浮点类型\n
*     LQ_TI_INT32_Q21_TO_FLOAT  TI方式INT32的Q21转化浮点类型\n
*     LQ_TI_INT32_Q20_TO_FLOAT  TI方式INT32的Q20转化浮点类型\n
*     LQ_TI_INT32_Q19_TO_FLOAT  TI方式INT32的Q19转化浮点类型\n
*     LQ_TI_INT32_Q18_TO_FLOAT  TI方式INT32的Q18转化浮点类型\n
*     LQ_TI_INT32_Q17_TO_FLOAT  TI方式INT32的Q17转化浮点类型\n
*     LQ_TI_INT32_Q16_TO_FLOAT  TI方式INT32的Q16转化浮点类型\n
*     LQ_TI_INT32_Q15_TO_FLOAT  TI方式INT32的Q15转化浮点类型\n
*     LQ_TI_INT32_Q14_TO_FLOAT  TI方式INT32的Q14转化浮点类型\n
*     LQ_TI_INT32_Q13_TO_FLOAT  TI方式INT32的Q13转化浮点类型\n
*     LQ_TI_INT32_Q12_TO_FLOAT  TI方式INT32的Q12转化浮点类型\n
*     LQ_TI_INT32_Q11_TO_FLOAT  TI方式INT32的Q11转化浮点类型\n
*     LQ_TI_INT32_Q10_TO_FLOAT  TI方式INT32的Q10转化浮点类型\n
*     LQ_TI_INT32_Q9_TO_FLOAT  TI方式INT32的Q9转化浮点类型\n
*     LQ_TI_INT32_Q8_TO_FLOAT  TI方式INT32的Q8转化浮点类型\n
*     LQ_TI_INT32_Q7_TO_FLOAT  TI方式INT32的Q7转化浮点类型\n
*     LQ_TI_INT32_Q6_TO_FLOAT  TI方式INT32的Q6转化浮点类型\n
*     LQ_TI_INT32_Q5_TO_FLOAT  TI方式INT32的Q5转化浮点类型\n
*     LQ_TI_INT32_Q4_TO_FLOAT  TI方式INT32的Q4转化浮点类型\n
*     LQ_TI_INT32_Q3_TO_FLOAT  TI方式INT32的Q3转化浮点类型\n
*     LQ_TI_INT32_Q2_TO_FLOAT  TI方式INT32的Q2转化浮点类型\n
*     LQ_TI_INT32_Q1_TO_FLOAT  TI方式INT32的Q1转化浮点类型\n
*/
LQ_F_32BIT LQ_TI_INT32_Q12_TO_FLOAT(LQ_I_32BIT A, LQ_ERROR* lq_error)
{
    LQ_UI_16BIT ui16Exp;
    LQ_UI_32BIT uiq23Result;
    LQ_UI_32BIT uiq31Input;
    //!< 初始化指数部分偏移量
    ui16Exp = 18688;
    //!< 保存符号位
    if (A < 0)
    {
        ui16Exp |= 0x8000;
        uiq31Input = (LQ_UI_32BIT)(-(LQ_I_64BIT)A);
    }
    else if (A == 0)
    {
        return (0);
    }
    else
    {
        uiq31Input = A;
    }
    LQ_TI_Q2F_NORMALIZE(uiq31Input, ui16Exp);
    /*对uiq31结果进行四舍五入并切换到uiq23*/
    uiq23Result = (LQ_UI_32BIT)(((LQ_UI_64BIT)uiq31Input + 0x0080u) >> 8);
    if (uiq23Result >= 0x01000000u)
    {
        uiq23Result = 0;
        ui16Exp += 0x0080;
    }
    /*删除尾数的隐含MSB位 */
    uiq23Result &= ~0x00800000;
    /*
    *将构造的指数和符号位添加到尾数。我们必须使用
    *四舍五入会导致尾数溢出的情况下的加法。
    *当这种情况发生时，尾数结果为2，其中MSB为零
    *exp的LSB被设置为1。在指数上加一就是
    *尾数为2的正确处理。不需要缩放
    *尾数，因为在这种情况下它总是等于零。
   */
    uiq23Result += (LQ_UI_32BIT)ui16Exp << 16;
    return LQ_TI_UINT32_BITS_TO_FLOAT(uiq23Result);
}
/**@brief (TI方法)INT32类型Q11格式转浮点
* @details 采用估算位+指数位+符号位三位结合，能提高精度
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为浮点数
* @code*    LQ_TI_INT32_Q11_TO_FLOAT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_INT32_Q31_TO_FLOAT  TI方式INT32的Q31转化浮点类型\n
*     LQ_TI_INT32_Q30_TO_FLOAT  TI方式INT32的Q30转化浮点类型\n
*     LQ_TI_INT32_Q29_TO_FLOAT  TI方式INT32的Q29转化浮点类型\n
*     LQ_TI_INT32_Q28_TO_FLOAT  TI方式INT32的Q28转化浮点类型\n
*     LQ_TI_INT32_Q27_TO_FLOAT  TI方式INT32的Q27转化浮点类型\n
*     LQ_TI_INT32_Q26_TO_FLOAT  TI方式INT32的Q26转化浮点类型\n
*     LQ_TI_INT32_Q25_TO_FLOAT  TI方式INT32的Q25转化浮点类型\n
*     LQ_TI_INT32_Q24_TO_FLOAT  TI方式INT32的Q24转化浮点类型\n
*     LQ_TI_INT32_Q23_TO_FLOAT  TI方式INT32的Q23转化浮点类型\n
*     LQ_TI_INT32_Q22_TO_FLOAT  TI方式INT32的Q22转化浮点类型\n
*     LQ_TI_INT32_Q21_TO_FLOAT  TI方式INT32的Q21转化浮点类型\n
*     LQ_TI_INT32_Q20_TO_FLOAT  TI方式INT32的Q20转化浮点类型\n
*     LQ_TI_INT32_Q19_TO_FLOAT  TI方式INT32的Q19转化浮点类型\n
*     LQ_TI_INT32_Q18_TO_FLOAT  TI方式INT32的Q18转化浮点类型\n
*     LQ_TI_INT32_Q17_TO_FLOAT  TI方式INT32的Q17转化浮点类型\n
*     LQ_TI_INT32_Q16_TO_FLOAT  TI方式INT32的Q16转化浮点类型\n
*     LQ_TI_INT32_Q15_TO_FLOAT  TI方式INT32的Q15转化浮点类型\n
*     LQ_TI_INT32_Q14_TO_FLOAT  TI方式INT32的Q14转化浮点类型\n
*     LQ_TI_INT32_Q13_TO_FLOAT  TI方式INT32的Q13转化浮点类型\n
*     LQ_TI_INT32_Q12_TO_FLOAT  TI方式INT32的Q12转化浮点类型\n
*     LQ_TI_INT32_Q11_TO_FLOAT  TI方式INT32的Q11转化浮点类型\n
*     LQ_TI_INT32_Q10_TO_FLOAT  TI方式INT32的Q10转化浮点类型\n
*     LQ_TI_INT32_Q9_TO_FLOAT  TI方式INT32的Q9转化浮点类型\n
*     LQ_TI_INT32_Q8_TO_FLOAT  TI方式INT32的Q8转化浮点类型\n
*     LQ_TI_INT32_Q7_TO_FLOAT  TI方式INT32的Q7转化浮点类型\n
*     LQ_TI_INT32_Q6_TO_FLOAT  TI方式INT32的Q6转化浮点类型\n
*     LQ_TI_INT32_Q5_TO_FLOAT  TI方式INT32的Q5转化浮点类型\n
*     LQ_TI_INT32_Q4_TO_FLOAT  TI方式INT32的Q4转化浮点类型\n
*     LQ_TI_INT32_Q3_TO_FLOAT  TI方式INT32的Q3转化浮点类型\n
*     LQ_TI_INT32_Q2_TO_FLOAT  TI方式INT32的Q2转化浮点类型\n
*     LQ_TI_INT32_Q1_TO_FLOAT  TI方式INT32的Q1转化浮点类型\n
*/
LQ_F_32BIT LQ_TI_INT32_Q11_TO_FLOAT(LQ_I_32BIT A, LQ_ERROR* lq_error)
{
    LQ_UI_16BIT ui16Exp;
    LQ_UI_32BIT uiq23Result;
    LQ_UI_32BIT uiq31Input;
    //!< 初始化指数部分偏移量
    ui16Exp = 18816;
    //!< 保存符号位
    if (A < 0)
    {
        ui16Exp |= 0x8000;
        uiq31Input = (LQ_UI_32BIT)(-(LQ_I_64BIT)A);
    }
    else if (A == 0)
    {
        return (0);
    }
    else
    {
        uiq31Input = A;
    }
    LQ_TI_Q2F_NORMALIZE(uiq31Input, ui16Exp);
    /*对uiq31结果进行四舍五入并切换到uiq23*/
    uiq23Result = (LQ_UI_32BIT)(((LQ_UI_64BIT)uiq31Input + 0x0080u) >> 8);
    if (uiq23Result >= 0x01000000u)
    {
        uiq23Result = 0;
        ui16Exp += 0x0080;
    }
    /*删除尾数的隐含MSB位 */
    uiq23Result &= ~0x00800000;
    /*
    *将构造的指数和符号位添加到尾数。我们必须使用
    *四舍五入会导致尾数溢出的情况下的加法。
    *当这种情况发生时，尾数结果为2，其中MSB为零
    *exp的LSB被设置为1。在指数上加一就是
    *尾数为2的正确处理。不需要缩放
    *尾数，因为在这种情况下它总是等于零。
   */
    uiq23Result += (LQ_UI_32BIT)ui16Exp << 16;
    return LQ_TI_UINT32_BITS_TO_FLOAT(uiq23Result);
}
/**@brief (TI方法)INT32类型Q10格式转浮点
* @details 采用估算位+指数位+符号位三位结合，能提高精度
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为浮点数
* @code*    LQ_TI_INT32_Q10_TO_FLOAT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_INT32_Q31_TO_FLOAT  TI方式INT32的Q31转化浮点类型\n
*     LQ_TI_INT32_Q30_TO_FLOAT  TI方式INT32的Q30转化浮点类型\n
*     LQ_TI_INT32_Q29_TO_FLOAT  TI方式INT32的Q29转化浮点类型\n
*     LQ_TI_INT32_Q28_TO_FLOAT  TI方式INT32的Q28转化浮点类型\n
*     LQ_TI_INT32_Q27_TO_FLOAT  TI方式INT32的Q27转化浮点类型\n
*     LQ_TI_INT32_Q26_TO_FLOAT  TI方式INT32的Q26转化浮点类型\n
*     LQ_TI_INT32_Q25_TO_FLOAT  TI方式INT32的Q25转化浮点类型\n
*     LQ_TI_INT32_Q24_TO_FLOAT  TI方式INT32的Q24转化浮点类型\n
*     LQ_TI_INT32_Q23_TO_FLOAT  TI方式INT32的Q23转化浮点类型\n
*     LQ_TI_INT32_Q22_TO_FLOAT  TI方式INT32的Q22转化浮点类型\n
*     LQ_TI_INT32_Q21_TO_FLOAT  TI方式INT32的Q21转化浮点类型\n
*     LQ_TI_INT32_Q20_TO_FLOAT  TI方式INT32的Q20转化浮点类型\n
*     LQ_TI_INT32_Q19_TO_FLOAT  TI方式INT32的Q19转化浮点类型\n
*     LQ_TI_INT32_Q18_TO_FLOAT  TI方式INT32的Q18转化浮点类型\n
*     LQ_TI_INT32_Q17_TO_FLOAT  TI方式INT32的Q17转化浮点类型\n
*     LQ_TI_INT32_Q16_TO_FLOAT  TI方式INT32的Q16转化浮点类型\n
*     LQ_TI_INT32_Q15_TO_FLOAT  TI方式INT32的Q15转化浮点类型\n
*     LQ_TI_INT32_Q14_TO_FLOAT  TI方式INT32的Q14转化浮点类型\n
*     LQ_TI_INT32_Q13_TO_FLOAT  TI方式INT32的Q13转化浮点类型\n
*     LQ_TI_INT32_Q12_TO_FLOAT  TI方式INT32的Q12转化浮点类型\n
*     LQ_TI_INT32_Q11_TO_FLOAT  TI方式INT32的Q11转化浮点类型\n
*     LQ_TI_INT32_Q10_TO_FLOAT  TI方式INT32的Q10转化浮点类型\n
*     LQ_TI_INT32_Q9_TO_FLOAT  TI方式INT32的Q9转化浮点类型\n
*     LQ_TI_INT32_Q8_TO_FLOAT  TI方式INT32的Q8转化浮点类型\n
*     LQ_TI_INT32_Q7_TO_FLOAT  TI方式INT32的Q7转化浮点类型\n
*     LQ_TI_INT32_Q6_TO_FLOAT  TI方式INT32的Q6转化浮点类型\n
*     LQ_TI_INT32_Q5_TO_FLOAT  TI方式INT32的Q5转化浮点类型\n
*     LQ_TI_INT32_Q4_TO_FLOAT  TI方式INT32的Q4转化浮点类型\n
*     LQ_TI_INT32_Q3_TO_FLOAT  TI方式INT32的Q3转化浮点类型\n
*     LQ_TI_INT32_Q2_TO_FLOAT  TI方式INT32的Q2转化浮点类型\n
*     LQ_TI_INT32_Q1_TO_FLOAT  TI方式INT32的Q1转化浮点类型\n
*/
LQ_F_32BIT LQ_TI_INT32_Q10_TO_FLOAT(LQ_I_32BIT A, LQ_ERROR* lq_error)
{
    LQ_UI_16BIT ui16Exp;
    LQ_UI_32BIT uiq23Result;
    LQ_UI_32BIT uiq31Input;
    //!< 初始化指数部分偏移量
    ui16Exp = 18944;
    //!< 保存符号位
    if (A < 0)
    {
        ui16Exp |= 0x8000;
        uiq31Input = (LQ_UI_32BIT)(-(LQ_I_64BIT)A);
    }
    else if (A == 0)
    {
        return (0);
    }
    else
    {
        uiq31Input = A;
    }
    LQ_TI_Q2F_NORMALIZE(uiq31Input, ui16Exp);
    /*对uiq31结果进行四舍五入并切换到uiq23*/
    uiq23Result = (LQ_UI_32BIT)(((LQ_UI_64BIT)uiq31Input + 0x0080u) >> 8);
    if (uiq23Result >= 0x01000000u)
    {
        uiq23Result = 0;
        ui16Exp += 0x0080;
    }
    /*删除尾数的隐含MSB位 */
    uiq23Result &= ~0x00800000;
    /*
    *将构造的指数和符号位添加到尾数。我们必须使用
    *四舍五入会导致尾数溢出的情况下的加法。
    *当这种情况发生时，尾数结果为2，其中MSB为零
    *exp的LSB被设置为1。在指数上加一就是
    *尾数为2的正确处理。不需要缩放
    *尾数，因为在这种情况下它总是等于零。
   */
    uiq23Result += (LQ_UI_32BIT)ui16Exp << 16;
    return LQ_TI_UINT32_BITS_TO_FLOAT(uiq23Result);
}
/**@brief (TI方法)INT32类型Q9格式转浮点
* @details 采用估算位+指数位+符号位三位结合，能提高精度
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为浮点数
* @code*    LQ_TI_INT32_Q9_TO_FLOAT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_INT32_Q31_TO_FLOAT  TI方式INT32的Q31转化浮点类型\n
*     LQ_TI_INT32_Q30_TO_FLOAT  TI方式INT32的Q30转化浮点类型\n
*     LQ_TI_INT32_Q29_TO_FLOAT  TI方式INT32的Q29转化浮点类型\n
*     LQ_TI_INT32_Q28_TO_FLOAT  TI方式INT32的Q28转化浮点类型\n
*     LQ_TI_INT32_Q27_TO_FLOAT  TI方式INT32的Q27转化浮点类型\n
*     LQ_TI_INT32_Q26_TO_FLOAT  TI方式INT32的Q26转化浮点类型\n
*     LQ_TI_INT32_Q25_TO_FLOAT  TI方式INT32的Q25转化浮点类型\n
*     LQ_TI_INT32_Q24_TO_FLOAT  TI方式INT32的Q24转化浮点类型\n
*     LQ_TI_INT32_Q23_TO_FLOAT  TI方式INT32的Q23转化浮点类型\n
*     LQ_TI_INT32_Q22_TO_FLOAT  TI方式INT32的Q22转化浮点类型\n
*     LQ_TI_INT32_Q21_TO_FLOAT  TI方式INT32的Q21转化浮点类型\n
*     LQ_TI_INT32_Q20_TO_FLOAT  TI方式INT32的Q20转化浮点类型\n
*     LQ_TI_INT32_Q19_TO_FLOAT  TI方式INT32的Q19转化浮点类型\n
*     LQ_TI_INT32_Q18_TO_FLOAT  TI方式INT32的Q18转化浮点类型\n
*     LQ_TI_INT32_Q17_TO_FLOAT  TI方式INT32的Q17转化浮点类型\n
*     LQ_TI_INT32_Q16_TO_FLOAT  TI方式INT32的Q16转化浮点类型\n
*     LQ_TI_INT32_Q15_TO_FLOAT  TI方式INT32的Q15转化浮点类型\n
*     LQ_TI_INT32_Q14_TO_FLOAT  TI方式INT32的Q14转化浮点类型\n
*     LQ_TI_INT32_Q13_TO_FLOAT  TI方式INT32的Q13转化浮点类型\n
*     LQ_TI_INT32_Q12_TO_FLOAT  TI方式INT32的Q12转化浮点类型\n
*     LQ_TI_INT32_Q11_TO_FLOAT  TI方式INT32的Q11转化浮点类型\n
*     LQ_TI_INT32_Q10_TO_FLOAT  TI方式INT32的Q10转化浮点类型\n
*     LQ_TI_INT32_Q9_TO_FLOAT  TI方式INT32的Q9转化浮点类型\n
*     LQ_TI_INT32_Q8_TO_FLOAT  TI方式INT32的Q8转化浮点类型\n
*     LQ_TI_INT32_Q7_TO_FLOAT  TI方式INT32的Q7转化浮点类型\n
*     LQ_TI_INT32_Q6_TO_FLOAT  TI方式INT32的Q6转化浮点类型\n
*     LQ_TI_INT32_Q5_TO_FLOAT  TI方式INT32的Q5转化浮点类型\n
*     LQ_TI_INT32_Q4_TO_FLOAT  TI方式INT32的Q4转化浮点类型\n
*     LQ_TI_INT32_Q3_TO_FLOAT  TI方式INT32的Q3转化浮点类型\n
*     LQ_TI_INT32_Q2_TO_FLOAT  TI方式INT32的Q2转化浮点类型\n
*     LQ_TI_INT32_Q1_TO_FLOAT  TI方式INT32的Q1转化浮点类型\n
*/
LQ_F_32BIT LQ_TI_INT32_Q9_TO_FLOAT(LQ_I_32BIT A, LQ_ERROR* lq_error)
{
    LQ_UI_16BIT ui16Exp;
    LQ_UI_32BIT uiq23Result;
    LQ_UI_32BIT uiq31Input;
    //!< 初始化指数部分偏移量
    ui16Exp = 19072;
    //!< 保存符号位
    if (A < 0)
    {
        ui16Exp |= 0x8000;
        uiq31Input = (LQ_UI_32BIT)(-(LQ_I_64BIT)A);
    }
    else if (A == 0)
    {
        return (0);
    }
    else
    {
        uiq31Input = A;
    }
    LQ_TI_Q2F_NORMALIZE(uiq31Input, ui16Exp);
    /*对uiq31结果进行四舍五入并切换到uiq23*/
    uiq23Result = (LQ_UI_32BIT)(((LQ_UI_64BIT)uiq31Input + 0x0080u) >> 8);
    if (uiq23Result >= 0x01000000u)
    {
        uiq23Result = 0;
        ui16Exp += 0x0080;
    }
    /*删除尾数的隐含MSB位 */
    uiq23Result &= ~0x00800000;
    /*
    *将构造的指数和符号位添加到尾数。我们必须使用
    *四舍五入会导致尾数溢出的情况下的加法。
    *当这种情况发生时，尾数结果为2，其中MSB为零
    *exp的LSB被设置为1。在指数上加一就是
    *尾数为2的正确处理。不需要缩放
    *尾数，因为在这种情况下它总是等于零。
   */
    uiq23Result += (LQ_UI_32BIT)ui16Exp << 16;
    return LQ_TI_UINT32_BITS_TO_FLOAT(uiq23Result);
}
/**@brief (TI方法)INT32类型Q8格式转浮点
* @details 采用估算位+指数位+符号位三位结合，能提高精度
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为浮点数
* @code*    LQ_TI_INT32_Q8_TO_FLOAT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_INT32_Q31_TO_FLOAT  TI方式INT32的Q31转化浮点类型\n
*     LQ_TI_INT32_Q30_TO_FLOAT  TI方式INT32的Q30转化浮点类型\n
*     LQ_TI_INT32_Q29_TO_FLOAT  TI方式INT32的Q29转化浮点类型\n
*     LQ_TI_INT32_Q28_TO_FLOAT  TI方式INT32的Q28转化浮点类型\n
*     LQ_TI_INT32_Q27_TO_FLOAT  TI方式INT32的Q27转化浮点类型\n
*     LQ_TI_INT32_Q26_TO_FLOAT  TI方式INT32的Q26转化浮点类型\n
*     LQ_TI_INT32_Q25_TO_FLOAT  TI方式INT32的Q25转化浮点类型\n
*     LQ_TI_INT32_Q24_TO_FLOAT  TI方式INT32的Q24转化浮点类型\n
*     LQ_TI_INT32_Q23_TO_FLOAT  TI方式INT32的Q23转化浮点类型\n
*     LQ_TI_INT32_Q22_TO_FLOAT  TI方式INT32的Q22转化浮点类型\n
*     LQ_TI_INT32_Q21_TO_FLOAT  TI方式INT32的Q21转化浮点类型\n
*     LQ_TI_INT32_Q20_TO_FLOAT  TI方式INT32的Q20转化浮点类型\n
*     LQ_TI_INT32_Q19_TO_FLOAT  TI方式INT32的Q19转化浮点类型\n
*     LQ_TI_INT32_Q18_TO_FLOAT  TI方式INT32的Q18转化浮点类型\n
*     LQ_TI_INT32_Q17_TO_FLOAT  TI方式INT32的Q17转化浮点类型\n
*     LQ_TI_INT32_Q16_TO_FLOAT  TI方式INT32的Q16转化浮点类型\n
*     LQ_TI_INT32_Q15_TO_FLOAT  TI方式INT32的Q15转化浮点类型\n
*     LQ_TI_INT32_Q14_TO_FLOAT  TI方式INT32的Q14转化浮点类型\n
*     LQ_TI_INT32_Q13_TO_FLOAT  TI方式INT32的Q13转化浮点类型\n
*     LQ_TI_INT32_Q12_TO_FLOAT  TI方式INT32的Q12转化浮点类型\n
*     LQ_TI_INT32_Q11_TO_FLOAT  TI方式INT32的Q11转化浮点类型\n
*     LQ_TI_INT32_Q10_TO_FLOAT  TI方式INT32的Q10转化浮点类型\n
*     LQ_TI_INT32_Q9_TO_FLOAT  TI方式INT32的Q9转化浮点类型\n
*     LQ_TI_INT32_Q8_TO_FLOAT  TI方式INT32的Q8转化浮点类型\n
*     LQ_TI_INT32_Q7_TO_FLOAT  TI方式INT32的Q7转化浮点类型\n
*     LQ_TI_INT32_Q6_TO_FLOAT  TI方式INT32的Q6转化浮点类型\n
*     LQ_TI_INT32_Q5_TO_FLOAT  TI方式INT32的Q5转化浮点类型\n
*     LQ_TI_INT32_Q4_TO_FLOAT  TI方式INT32的Q4转化浮点类型\n
*     LQ_TI_INT32_Q3_TO_FLOAT  TI方式INT32的Q3转化浮点类型\n
*     LQ_TI_INT32_Q2_TO_FLOAT  TI方式INT32的Q2转化浮点类型\n
*     LQ_TI_INT32_Q1_TO_FLOAT  TI方式INT32的Q1转化浮点类型\n
*/
LQ_F_32BIT LQ_TI_INT32_Q8_TO_FLOAT(LQ_I_32BIT A, LQ_ERROR* lq_error)
{
    LQ_UI_16BIT ui16Exp;
    LQ_UI_32BIT uiq23Result;
    LQ_UI_32BIT uiq31Input;
    //!< 初始化指数部分偏移量
    ui16Exp = 19200;
    //!< 保存符号位
    if (A < 0)
    {
        ui16Exp |= 0x8000;
        uiq31Input = (LQ_UI_32BIT)(-(LQ_I_64BIT)A);
    }
    else if (A == 0)
    {
        return (0);
    }
    else
    {
        uiq31Input = A;
    }
    LQ_TI_Q2F_NORMALIZE(uiq31Input, ui16Exp);
    /*对uiq31结果进行四舍五入并切换到uiq23*/
    uiq23Result = (LQ_UI_32BIT)(((LQ_UI_64BIT)uiq31Input + 0x0080u) >> 8);
    if (uiq23Result >= 0x01000000u)
    {
        uiq23Result = 0;
        ui16Exp += 0x0080;
    }
    /*删除尾数的隐含MSB位 */
    uiq23Result &= ~0x00800000;
    /*
    *将构造的指数和符号位添加到尾数。我们必须使用
    *四舍五入会导致尾数溢出的情况下的加法。
    *当这种情况发生时，尾数结果为2，其中MSB为零
    *exp的LSB被设置为1。在指数上加一就是
    *尾数为2的正确处理。不需要缩放
    *尾数，因为在这种情况下它总是等于零。
   */
    uiq23Result += (LQ_UI_32BIT)ui16Exp << 16;
    return LQ_TI_UINT32_BITS_TO_FLOAT(uiq23Result);
}
/**@brief (TI方法)INT32类型Q7格式转浮点
* @details 采用估算位+指数位+符号位三位结合，能提高精度
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为浮点数
* @code*    LQ_TI_INT32_Q7_TO_FLOAT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_INT32_Q31_TO_FLOAT  TI方式INT32的Q31转化浮点类型\n
*     LQ_TI_INT32_Q30_TO_FLOAT  TI方式INT32的Q30转化浮点类型\n
*     LQ_TI_INT32_Q29_TO_FLOAT  TI方式INT32的Q29转化浮点类型\n
*     LQ_TI_INT32_Q28_TO_FLOAT  TI方式INT32的Q28转化浮点类型\n
*     LQ_TI_INT32_Q27_TO_FLOAT  TI方式INT32的Q27转化浮点类型\n
*     LQ_TI_INT32_Q26_TO_FLOAT  TI方式INT32的Q26转化浮点类型\n
*     LQ_TI_INT32_Q25_TO_FLOAT  TI方式INT32的Q25转化浮点类型\n
*     LQ_TI_INT32_Q24_TO_FLOAT  TI方式INT32的Q24转化浮点类型\n
*     LQ_TI_INT32_Q23_TO_FLOAT  TI方式INT32的Q23转化浮点类型\n
*     LQ_TI_INT32_Q22_TO_FLOAT  TI方式INT32的Q22转化浮点类型\n
*     LQ_TI_INT32_Q21_TO_FLOAT  TI方式INT32的Q21转化浮点类型\n
*     LQ_TI_INT32_Q20_TO_FLOAT  TI方式INT32的Q20转化浮点类型\n
*     LQ_TI_INT32_Q19_TO_FLOAT  TI方式INT32的Q19转化浮点类型\n
*     LQ_TI_INT32_Q18_TO_FLOAT  TI方式INT32的Q18转化浮点类型\n
*     LQ_TI_INT32_Q17_TO_FLOAT  TI方式INT32的Q17转化浮点类型\n
*     LQ_TI_INT32_Q16_TO_FLOAT  TI方式INT32的Q16转化浮点类型\n
*     LQ_TI_INT32_Q15_TO_FLOAT  TI方式INT32的Q15转化浮点类型\n
*     LQ_TI_INT32_Q14_TO_FLOAT  TI方式INT32的Q14转化浮点类型\n
*     LQ_TI_INT32_Q13_TO_FLOAT  TI方式INT32的Q13转化浮点类型\n
*     LQ_TI_INT32_Q12_TO_FLOAT  TI方式INT32的Q12转化浮点类型\n
*     LQ_TI_INT32_Q11_TO_FLOAT  TI方式INT32的Q11转化浮点类型\n
*     LQ_TI_INT32_Q10_TO_FLOAT  TI方式INT32的Q10转化浮点类型\n
*     LQ_TI_INT32_Q9_TO_FLOAT  TI方式INT32的Q9转化浮点类型\n
*     LQ_TI_INT32_Q8_TO_FLOAT  TI方式INT32的Q8转化浮点类型\n
*     LQ_TI_INT32_Q7_TO_FLOAT  TI方式INT32的Q7转化浮点类型\n
*     LQ_TI_INT32_Q6_TO_FLOAT  TI方式INT32的Q6转化浮点类型\n
*     LQ_TI_INT32_Q5_TO_FLOAT  TI方式INT32的Q5转化浮点类型\n
*     LQ_TI_INT32_Q4_TO_FLOAT  TI方式INT32的Q4转化浮点类型\n
*     LQ_TI_INT32_Q3_TO_FLOAT  TI方式INT32的Q3转化浮点类型\n
*     LQ_TI_INT32_Q2_TO_FLOAT  TI方式INT32的Q2转化浮点类型\n
*     LQ_TI_INT32_Q1_TO_FLOAT  TI方式INT32的Q1转化浮点类型\n
*/
LQ_F_32BIT LQ_TI_INT32_Q7_TO_FLOAT(LQ_I_32BIT A, LQ_ERROR* lq_error)
{
    LQ_UI_16BIT ui16Exp;
    LQ_UI_32BIT uiq23Result;
    LQ_UI_32BIT uiq31Input;
    //!< 初始化指数部分偏移量
    ui16Exp = 19328;
    //!< 保存符号位
    if (A < 0)
    {
        ui16Exp |= 0x8000;
        uiq31Input = (LQ_UI_32BIT)(-(LQ_I_64BIT)A);
    }
    else if (A == 0)
    {
        return (0);
    }
    else
    {
        uiq31Input = A;
    }
    LQ_TI_Q2F_NORMALIZE(uiq31Input, ui16Exp);
    /*对uiq31结果进行四舍五入并切换到uiq23*/
    uiq23Result = (LQ_UI_32BIT)(((LQ_UI_64BIT)uiq31Input + 0x0080u) >> 8);
    if (uiq23Result >= 0x01000000u)
    {
        uiq23Result = 0;
        ui16Exp += 0x0080;
    }
    /*删除尾数的隐含MSB位 */
    uiq23Result &= ~0x00800000;
    /*
    *将构造的指数和符号位添加到尾数。我们必须使用
    *四舍五入会导致尾数溢出的情况下的加法。
    *当这种情况发生时，尾数结果为2，其中MSB为零
    *exp的LSB被设置为1。在指数上加一就是
    *尾数为2的正确处理。不需要缩放
    *尾数，因为在这种情况下它总是等于零。
   */
    uiq23Result += (LQ_UI_32BIT)ui16Exp << 16;
    return LQ_TI_UINT32_BITS_TO_FLOAT(uiq23Result);
}
/**@brief (TI方法)INT32类型Q6格式转浮点
* @details 采用估算位+指数位+符号位三位结合，能提高精度
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为浮点数
* @code*    LQ_TI_INT32_Q6_TO_FLOAT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_INT32_Q31_TO_FLOAT  TI方式INT32的Q31转化浮点类型\n
*     LQ_TI_INT32_Q30_TO_FLOAT  TI方式INT32的Q30转化浮点类型\n
*     LQ_TI_INT32_Q29_TO_FLOAT  TI方式INT32的Q29转化浮点类型\n
*     LQ_TI_INT32_Q28_TO_FLOAT  TI方式INT32的Q28转化浮点类型\n
*     LQ_TI_INT32_Q27_TO_FLOAT  TI方式INT32的Q27转化浮点类型\n
*     LQ_TI_INT32_Q26_TO_FLOAT  TI方式INT32的Q26转化浮点类型\n
*     LQ_TI_INT32_Q25_TO_FLOAT  TI方式INT32的Q25转化浮点类型\n
*     LQ_TI_INT32_Q24_TO_FLOAT  TI方式INT32的Q24转化浮点类型\n
*     LQ_TI_INT32_Q23_TO_FLOAT  TI方式INT32的Q23转化浮点类型\n
*     LQ_TI_INT32_Q22_TO_FLOAT  TI方式INT32的Q22转化浮点类型\n
*     LQ_TI_INT32_Q21_TO_FLOAT  TI方式INT32的Q21转化浮点类型\n
*     LQ_TI_INT32_Q20_TO_FLOAT  TI方式INT32的Q20转化浮点类型\n
*     LQ_TI_INT32_Q19_TO_FLOAT  TI方式INT32的Q19转化浮点类型\n
*     LQ_TI_INT32_Q18_TO_FLOAT  TI方式INT32的Q18转化浮点类型\n
*     LQ_TI_INT32_Q17_TO_FLOAT  TI方式INT32的Q17转化浮点类型\n
*     LQ_TI_INT32_Q16_TO_FLOAT  TI方式INT32的Q16转化浮点类型\n
*     LQ_TI_INT32_Q15_TO_FLOAT  TI方式INT32的Q15转化浮点类型\n
*     LQ_TI_INT32_Q14_TO_FLOAT  TI方式INT32的Q14转化浮点类型\n
*     LQ_TI_INT32_Q13_TO_FLOAT  TI方式INT32的Q13转化浮点类型\n
*     LQ_TI_INT32_Q12_TO_FLOAT  TI方式INT32的Q12转化浮点类型\n
*     LQ_TI_INT32_Q11_TO_FLOAT  TI方式INT32的Q11转化浮点类型\n
*     LQ_TI_INT32_Q10_TO_FLOAT  TI方式INT32的Q10转化浮点类型\n
*     LQ_TI_INT32_Q9_TO_FLOAT  TI方式INT32的Q9转化浮点类型\n
*     LQ_TI_INT32_Q8_TO_FLOAT  TI方式INT32的Q8转化浮点类型\n
*     LQ_TI_INT32_Q7_TO_FLOAT  TI方式INT32的Q7转化浮点类型\n
*     LQ_TI_INT32_Q6_TO_FLOAT  TI方式INT32的Q6转化浮点类型\n
*     LQ_TI_INT32_Q5_TO_FLOAT  TI方式INT32的Q5转化浮点类型\n
*     LQ_TI_INT32_Q4_TO_FLOAT  TI方式INT32的Q4转化浮点类型\n
*     LQ_TI_INT32_Q3_TO_FLOAT  TI方式INT32的Q3转化浮点类型\n
*     LQ_TI_INT32_Q2_TO_FLOAT  TI方式INT32的Q2转化浮点类型\n
*     LQ_TI_INT32_Q1_TO_FLOAT  TI方式INT32的Q1转化浮点类型\n
*/
LQ_F_32BIT LQ_TI_INT32_Q6_TO_FLOAT(LQ_I_32BIT A, LQ_ERROR* lq_error)
{
    LQ_UI_16BIT ui16Exp;
    LQ_UI_32BIT uiq23Result;
    LQ_UI_32BIT uiq31Input;
    //!< 初始化指数部分偏移量
    ui16Exp = 19456;
    //!< 保存符号位
    if (A < 0)
    {
        ui16Exp |= 0x8000;
        uiq31Input = (LQ_UI_32BIT)(-(LQ_I_64BIT)A);
    }
    else if (A == 0)
    {
        return (0);
    }
    else
    {
        uiq31Input = A;
    }
    LQ_TI_Q2F_NORMALIZE(uiq31Input, ui16Exp);
    /*对uiq31结果进行四舍五入并切换到uiq23*/
    uiq23Result = (LQ_UI_32BIT)(((LQ_UI_64BIT)uiq31Input + 0x0080u) >> 8);
    if (uiq23Result >= 0x01000000u)
    {
        uiq23Result = 0;
        ui16Exp += 0x0080;
    }
    /*删除尾数的隐含MSB位 */
    uiq23Result &= ~0x00800000;
    /*
    *将构造的指数和符号位添加到尾数。我们必须使用
    *四舍五入会导致尾数溢出的情况下的加法。
    *当这种情况发生时，尾数结果为2，其中MSB为零
    *exp的LSB被设置为1。在指数上加一就是
    *尾数为2的正确处理。不需要缩放
    *尾数，因为在这种情况下它总是等于零。
   */
    uiq23Result += (LQ_UI_32BIT)ui16Exp << 16;
    return LQ_TI_UINT32_BITS_TO_FLOAT(uiq23Result);
}
/**@brief (TI方法)INT32类型Q5格式转浮点
* @details 采用估算位+指数位+符号位三位结合，能提高精度
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为浮点数
* @code*    LQ_TI_INT32_Q5_TO_FLOAT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_INT32_Q31_TO_FLOAT  TI方式INT32的Q31转化浮点类型\n
*     LQ_TI_INT32_Q30_TO_FLOAT  TI方式INT32的Q30转化浮点类型\n
*     LQ_TI_INT32_Q29_TO_FLOAT  TI方式INT32的Q29转化浮点类型\n
*     LQ_TI_INT32_Q28_TO_FLOAT  TI方式INT32的Q28转化浮点类型\n
*     LQ_TI_INT32_Q27_TO_FLOAT  TI方式INT32的Q27转化浮点类型\n
*     LQ_TI_INT32_Q26_TO_FLOAT  TI方式INT32的Q26转化浮点类型\n
*     LQ_TI_INT32_Q25_TO_FLOAT  TI方式INT32的Q25转化浮点类型\n
*     LQ_TI_INT32_Q24_TO_FLOAT  TI方式INT32的Q24转化浮点类型\n
*     LQ_TI_INT32_Q23_TO_FLOAT  TI方式INT32的Q23转化浮点类型\n
*     LQ_TI_INT32_Q22_TO_FLOAT  TI方式INT32的Q22转化浮点类型\n
*     LQ_TI_INT32_Q21_TO_FLOAT  TI方式INT32的Q21转化浮点类型\n
*     LQ_TI_INT32_Q20_TO_FLOAT  TI方式INT32的Q20转化浮点类型\n
*     LQ_TI_INT32_Q19_TO_FLOAT  TI方式INT32的Q19转化浮点类型\n
*     LQ_TI_INT32_Q18_TO_FLOAT  TI方式INT32的Q18转化浮点类型\n
*     LQ_TI_INT32_Q17_TO_FLOAT  TI方式INT32的Q17转化浮点类型\n
*     LQ_TI_INT32_Q16_TO_FLOAT  TI方式INT32的Q16转化浮点类型\n
*     LQ_TI_INT32_Q15_TO_FLOAT  TI方式INT32的Q15转化浮点类型\n
*     LQ_TI_INT32_Q14_TO_FLOAT  TI方式INT32的Q14转化浮点类型\n
*     LQ_TI_INT32_Q13_TO_FLOAT  TI方式INT32的Q13转化浮点类型\n
*     LQ_TI_INT32_Q12_TO_FLOAT  TI方式INT32的Q12转化浮点类型\n
*     LQ_TI_INT32_Q11_TO_FLOAT  TI方式INT32的Q11转化浮点类型\n
*     LQ_TI_INT32_Q10_TO_FLOAT  TI方式INT32的Q10转化浮点类型\n
*     LQ_TI_INT32_Q9_TO_FLOAT  TI方式INT32的Q9转化浮点类型\n
*     LQ_TI_INT32_Q8_TO_FLOAT  TI方式INT32的Q8转化浮点类型\n
*     LQ_TI_INT32_Q7_TO_FLOAT  TI方式INT32的Q7转化浮点类型\n
*     LQ_TI_INT32_Q6_TO_FLOAT  TI方式INT32的Q6转化浮点类型\n
*     LQ_TI_INT32_Q5_TO_FLOAT  TI方式INT32的Q5转化浮点类型\n
*     LQ_TI_INT32_Q4_TO_FLOAT  TI方式INT32的Q4转化浮点类型\n
*     LQ_TI_INT32_Q3_TO_FLOAT  TI方式INT32的Q3转化浮点类型\n
*     LQ_TI_INT32_Q2_TO_FLOAT  TI方式INT32的Q2转化浮点类型\n
*     LQ_TI_INT32_Q1_TO_FLOAT  TI方式INT32的Q1转化浮点类型\n
*/
LQ_F_32BIT LQ_TI_INT32_Q5_TO_FLOAT(LQ_I_32BIT A, LQ_ERROR* lq_error)
{
    LQ_UI_16BIT ui16Exp;
    LQ_UI_32BIT uiq23Result;
    LQ_UI_32BIT uiq31Input;
    //!< 初始化指数部分偏移量
    ui16Exp = 19584;
    //!< 保存符号位
    if (A < 0)
    {
        ui16Exp |= 0x8000;
        uiq31Input = (LQ_UI_32BIT)(-(LQ_I_64BIT)A);
    }
    else if (A == 0)
    {
        return (0);
    }
    else
    {
        uiq31Input = A;
    }
    LQ_TI_Q2F_NORMALIZE(uiq31Input, ui16Exp);
    /*对uiq31结果进行四舍五入并切换到uiq23*/
    uiq23Result = (LQ_UI_32BIT)(((LQ_UI_64BIT)uiq31Input + 0x0080u) >> 8);
    if (uiq23Result >= 0x01000000u)
    {
        uiq23Result = 0;
        ui16Exp += 0x0080;
    }
    /*删除尾数的隐含MSB位 */
    uiq23Result &= ~0x00800000;
    /*
    *将构造的指数和符号位添加到尾数。我们必须使用
    *四舍五入会导致尾数溢出的情况下的加法。
    *当这种情况发生时，尾数结果为2，其中MSB为零
    *exp的LSB被设置为1。在指数上加一就是
    *尾数为2的正确处理。不需要缩放
    *尾数，因为在这种情况下它总是等于零。
   */
    uiq23Result += (LQ_UI_32BIT)ui16Exp << 16;
    return LQ_TI_UINT32_BITS_TO_FLOAT(uiq23Result);
}
/**@brief (TI方法)INT32类型Q4格式转浮点
* @details 采用估算位+指数位+符号位三位结合，能提高精度
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为浮点数
* @code*    LQ_TI_INT32_Q4_TO_FLOAT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_INT32_Q31_TO_FLOAT  TI方式INT32的Q31转化浮点类型\n
*     LQ_TI_INT32_Q30_TO_FLOAT  TI方式INT32的Q30转化浮点类型\n
*     LQ_TI_INT32_Q29_TO_FLOAT  TI方式INT32的Q29转化浮点类型\n
*     LQ_TI_INT32_Q28_TO_FLOAT  TI方式INT32的Q28转化浮点类型\n
*     LQ_TI_INT32_Q27_TO_FLOAT  TI方式INT32的Q27转化浮点类型\n
*     LQ_TI_INT32_Q26_TO_FLOAT  TI方式INT32的Q26转化浮点类型\n
*     LQ_TI_INT32_Q25_TO_FLOAT  TI方式INT32的Q25转化浮点类型\n
*     LQ_TI_INT32_Q24_TO_FLOAT  TI方式INT32的Q24转化浮点类型\n
*     LQ_TI_INT32_Q23_TO_FLOAT  TI方式INT32的Q23转化浮点类型\n
*     LQ_TI_INT32_Q22_TO_FLOAT  TI方式INT32的Q22转化浮点类型\n
*     LQ_TI_INT32_Q21_TO_FLOAT  TI方式INT32的Q21转化浮点类型\n
*     LQ_TI_INT32_Q20_TO_FLOAT  TI方式INT32的Q20转化浮点类型\n
*     LQ_TI_INT32_Q19_TO_FLOAT  TI方式INT32的Q19转化浮点类型\n
*     LQ_TI_INT32_Q18_TO_FLOAT  TI方式INT32的Q18转化浮点类型\n
*     LQ_TI_INT32_Q17_TO_FLOAT  TI方式INT32的Q17转化浮点类型\n
*     LQ_TI_INT32_Q16_TO_FLOAT  TI方式INT32的Q16转化浮点类型\n
*     LQ_TI_INT32_Q15_TO_FLOAT  TI方式INT32的Q15转化浮点类型\n
*     LQ_TI_INT32_Q14_TO_FLOAT  TI方式INT32的Q14转化浮点类型\n
*     LQ_TI_INT32_Q13_TO_FLOAT  TI方式INT32的Q13转化浮点类型\n
*     LQ_TI_INT32_Q12_TO_FLOAT  TI方式INT32的Q12转化浮点类型\n
*     LQ_TI_INT32_Q11_TO_FLOAT  TI方式INT32的Q11转化浮点类型\n
*     LQ_TI_INT32_Q10_TO_FLOAT  TI方式INT32的Q10转化浮点类型\n
*     LQ_TI_INT32_Q9_TO_FLOAT  TI方式INT32的Q9转化浮点类型\n
*     LQ_TI_INT32_Q8_TO_FLOAT  TI方式INT32的Q8转化浮点类型\n
*     LQ_TI_INT32_Q7_TO_FLOAT  TI方式INT32的Q7转化浮点类型\n
*     LQ_TI_INT32_Q6_TO_FLOAT  TI方式INT32的Q6转化浮点类型\n
*     LQ_TI_INT32_Q5_TO_FLOAT  TI方式INT32的Q5转化浮点类型\n
*     LQ_TI_INT32_Q4_TO_FLOAT  TI方式INT32的Q4转化浮点类型\n
*     LQ_TI_INT32_Q3_TO_FLOAT  TI方式INT32的Q3转化浮点类型\n
*     LQ_TI_INT32_Q2_TO_FLOAT  TI方式INT32的Q2转化浮点类型\n
*     LQ_TI_INT32_Q1_TO_FLOAT  TI方式INT32的Q1转化浮点类型\n
*/
LQ_F_32BIT LQ_TI_INT32_Q4_TO_FLOAT(LQ_I_32BIT A, LQ_ERROR* lq_error)
{
    LQ_UI_16BIT ui16Exp;
    LQ_UI_32BIT uiq23Result;
    LQ_UI_32BIT uiq31Input;
    //!< 初始化指数部分偏移量
    ui16Exp = 19712;
    //!< 保存符号位
    if (A < 0)
    {
        ui16Exp |= 0x8000;
        uiq31Input = (LQ_UI_32BIT)(-(LQ_I_64BIT)A);
    }
    else if (A == 0)
    {
        return (0);
    }
    else
    {
        uiq31Input = A;
    }
    LQ_TI_Q2F_NORMALIZE(uiq31Input, ui16Exp);
    /*对uiq31结果进行四舍五入并切换到uiq23*/
    uiq23Result = (LQ_UI_32BIT)(((LQ_UI_64BIT)uiq31Input + 0x0080u) >> 8);
    if (uiq23Result >= 0x01000000u)
    {
        uiq23Result = 0;
        ui16Exp += 0x0080;
    }
    /*删除尾数的隐含MSB位 */
    uiq23Result &= ~0x00800000;
    /*
    *将构造的指数和符号位添加到尾数。我们必须使用
    *四舍五入会导致尾数溢出的情况下的加法。
    *当这种情况发生时，尾数结果为2，其中MSB为零
    *exp的LSB被设置为1。在指数上加一就是
    *尾数为2的正确处理。不需要缩放
    *尾数，因为在这种情况下它总是等于零。
   */
    uiq23Result += (LQ_UI_32BIT)ui16Exp << 16;
    return LQ_TI_UINT32_BITS_TO_FLOAT(uiq23Result);
}
/**@brief (TI方法)INT32类型Q3格式转浮点
* @details 采用估算位+指数位+符号位三位结合，能提高精度
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为浮点数
* @code*    LQ_TI_INT32_Q3_TO_FLOAT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_INT32_Q31_TO_FLOAT  TI方式INT32的Q31转化浮点类型\n
*     LQ_TI_INT32_Q30_TO_FLOAT  TI方式INT32的Q30转化浮点类型\n
*     LQ_TI_INT32_Q29_TO_FLOAT  TI方式INT32的Q29转化浮点类型\n
*     LQ_TI_INT32_Q28_TO_FLOAT  TI方式INT32的Q28转化浮点类型\n
*     LQ_TI_INT32_Q27_TO_FLOAT  TI方式INT32的Q27转化浮点类型\n
*     LQ_TI_INT32_Q26_TO_FLOAT  TI方式INT32的Q26转化浮点类型\n
*     LQ_TI_INT32_Q25_TO_FLOAT  TI方式INT32的Q25转化浮点类型\n
*     LQ_TI_INT32_Q24_TO_FLOAT  TI方式INT32的Q24转化浮点类型\n
*     LQ_TI_INT32_Q23_TO_FLOAT  TI方式INT32的Q23转化浮点类型\n
*     LQ_TI_INT32_Q22_TO_FLOAT  TI方式INT32的Q22转化浮点类型\n
*     LQ_TI_INT32_Q21_TO_FLOAT  TI方式INT32的Q21转化浮点类型\n
*     LQ_TI_INT32_Q20_TO_FLOAT  TI方式INT32的Q20转化浮点类型\n
*     LQ_TI_INT32_Q19_TO_FLOAT  TI方式INT32的Q19转化浮点类型\n
*     LQ_TI_INT32_Q18_TO_FLOAT  TI方式INT32的Q18转化浮点类型\n
*     LQ_TI_INT32_Q17_TO_FLOAT  TI方式INT32的Q17转化浮点类型\n
*     LQ_TI_INT32_Q16_TO_FLOAT  TI方式INT32的Q16转化浮点类型\n
*     LQ_TI_INT32_Q15_TO_FLOAT  TI方式INT32的Q15转化浮点类型\n
*     LQ_TI_INT32_Q14_TO_FLOAT  TI方式INT32的Q14转化浮点类型\n
*     LQ_TI_INT32_Q13_TO_FLOAT  TI方式INT32的Q13转化浮点类型\n
*     LQ_TI_INT32_Q12_TO_FLOAT  TI方式INT32的Q12转化浮点类型\n
*     LQ_TI_INT32_Q11_TO_FLOAT  TI方式INT32的Q11转化浮点类型\n
*     LQ_TI_INT32_Q10_TO_FLOAT  TI方式INT32的Q10转化浮点类型\n
*     LQ_TI_INT32_Q9_TO_FLOAT  TI方式INT32的Q9转化浮点类型\n
*     LQ_TI_INT32_Q8_TO_FLOAT  TI方式INT32的Q8转化浮点类型\n
*     LQ_TI_INT32_Q7_TO_FLOAT  TI方式INT32的Q7转化浮点类型\n
*     LQ_TI_INT32_Q6_TO_FLOAT  TI方式INT32的Q6转化浮点类型\n
*     LQ_TI_INT32_Q5_TO_FLOAT  TI方式INT32的Q5转化浮点类型\n
*     LQ_TI_INT32_Q4_TO_FLOAT  TI方式INT32的Q4转化浮点类型\n
*     LQ_TI_INT32_Q3_TO_FLOAT  TI方式INT32的Q3转化浮点类型\n
*     LQ_TI_INT32_Q2_TO_FLOAT  TI方式INT32的Q2转化浮点类型\n
*     LQ_TI_INT32_Q1_TO_FLOAT  TI方式INT32的Q1转化浮点类型\n
*/
LQ_F_32BIT LQ_TI_INT32_Q3_TO_FLOAT(LQ_I_32BIT A, LQ_ERROR* lq_error)
{
    LQ_UI_16BIT ui16Exp;
    LQ_UI_32BIT uiq23Result;
    LQ_UI_32BIT uiq31Input;
    //!< 初始化指数部分偏移量
    ui16Exp = 19840;
    //!< 保存符号位
    if (A < 0)
    {
        ui16Exp |= 0x8000;
        uiq31Input = (LQ_UI_32BIT)(-(LQ_I_64BIT)A);
    }
    else if (A == 0)
    {
        return (0);
    }
    else
    {
        uiq31Input = A;
    }
    LQ_TI_Q2F_NORMALIZE(uiq31Input, ui16Exp);
    /*对uiq31结果进行四舍五入并切换到uiq23*/
    uiq23Result = (LQ_UI_32BIT)(((LQ_UI_64BIT)uiq31Input + 0x0080u) >> 8);
    if (uiq23Result >= 0x01000000u)
    {
        uiq23Result = 0;
        ui16Exp += 0x0080;
    }
    /*删除尾数的隐含MSB位 */
    uiq23Result &= ~0x00800000;
    /*
    *将构造的指数和符号位添加到尾数。我们必须使用
    *四舍五入会导致尾数溢出的情况下的加法。
    *当这种情况发生时，尾数结果为2，其中MSB为零
    *exp的LSB被设置为1。在指数上加一就是
    *尾数为2的正确处理。不需要缩放
    *尾数，因为在这种情况下它总是等于零。
   */
    uiq23Result += (LQ_UI_32BIT)ui16Exp << 16;
    return LQ_TI_UINT32_BITS_TO_FLOAT(uiq23Result);
}
/**@brief (TI方法)INT32类型Q2格式转浮点
* @details 采用估算位+指数位+符号位三位结合，能提高精度
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为浮点数
* @code*    LQ_TI_INT32_Q2_TO_FLOAT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_INT32_Q31_TO_FLOAT  TI方式INT32的Q31转化浮点类型\n
*     LQ_TI_INT32_Q30_TO_FLOAT  TI方式INT32的Q30转化浮点类型\n
*     LQ_TI_INT32_Q29_TO_FLOAT  TI方式INT32的Q29转化浮点类型\n
*     LQ_TI_INT32_Q28_TO_FLOAT  TI方式INT32的Q28转化浮点类型\n
*     LQ_TI_INT32_Q27_TO_FLOAT  TI方式INT32的Q27转化浮点类型\n
*     LQ_TI_INT32_Q26_TO_FLOAT  TI方式INT32的Q26转化浮点类型\n
*     LQ_TI_INT32_Q25_TO_FLOAT  TI方式INT32的Q25转化浮点类型\n
*     LQ_TI_INT32_Q24_TO_FLOAT  TI方式INT32的Q24转化浮点类型\n
*     LQ_TI_INT32_Q23_TO_FLOAT  TI方式INT32的Q23转化浮点类型\n
*     LQ_TI_INT32_Q22_TO_FLOAT  TI方式INT32的Q22转化浮点类型\n
*     LQ_TI_INT32_Q21_TO_FLOAT  TI方式INT32的Q21转化浮点类型\n
*     LQ_TI_INT32_Q20_TO_FLOAT  TI方式INT32的Q20转化浮点类型\n
*     LQ_TI_INT32_Q19_TO_FLOAT  TI方式INT32的Q19转化浮点类型\n
*     LQ_TI_INT32_Q18_TO_FLOAT  TI方式INT32的Q18转化浮点类型\n
*     LQ_TI_INT32_Q17_TO_FLOAT  TI方式INT32的Q17转化浮点类型\n
*     LQ_TI_INT32_Q16_TO_FLOAT  TI方式INT32的Q16转化浮点类型\n
*     LQ_TI_INT32_Q15_TO_FLOAT  TI方式INT32的Q15转化浮点类型\n
*     LQ_TI_INT32_Q14_TO_FLOAT  TI方式INT32的Q14转化浮点类型\n
*     LQ_TI_INT32_Q13_TO_FLOAT  TI方式INT32的Q13转化浮点类型\n
*     LQ_TI_INT32_Q12_TO_FLOAT  TI方式INT32的Q12转化浮点类型\n
*     LQ_TI_INT32_Q11_TO_FLOAT  TI方式INT32的Q11转化浮点类型\n
*     LQ_TI_INT32_Q10_TO_FLOAT  TI方式INT32的Q10转化浮点类型\n
*     LQ_TI_INT32_Q9_TO_FLOAT  TI方式INT32的Q9转化浮点类型\n
*     LQ_TI_INT32_Q8_TO_FLOAT  TI方式INT32的Q8转化浮点类型\n
*     LQ_TI_INT32_Q7_TO_FLOAT  TI方式INT32的Q7转化浮点类型\n
*     LQ_TI_INT32_Q6_TO_FLOAT  TI方式INT32的Q6转化浮点类型\n
*     LQ_TI_INT32_Q5_TO_FLOAT  TI方式INT32的Q5转化浮点类型\n
*     LQ_TI_INT32_Q4_TO_FLOAT  TI方式INT32的Q4转化浮点类型\n
*     LQ_TI_INT32_Q3_TO_FLOAT  TI方式INT32的Q3转化浮点类型\n
*     LQ_TI_INT32_Q2_TO_FLOAT  TI方式INT32的Q2转化浮点类型\n
*     LQ_TI_INT32_Q1_TO_FLOAT  TI方式INT32的Q1转化浮点类型\n
*/
LQ_F_32BIT LQ_TI_INT32_Q2_TO_FLOAT(LQ_I_32BIT A, LQ_ERROR* lq_error)
{
    LQ_UI_16BIT ui16Exp;
    LQ_UI_32BIT uiq23Result;
    LQ_UI_32BIT uiq31Input;
    //!< 初始化指数部分偏移量
    ui16Exp = 19968;
    //!< 保存符号位
    if (A < 0)
    {
        ui16Exp |= 0x8000;
        uiq31Input = (LQ_UI_32BIT)(-(LQ_I_64BIT)A);
    }
    else if (A == 0)
    {
        return (0);
    }
    else
    {
        uiq31Input = A;
    }
    LQ_TI_Q2F_NORMALIZE(uiq31Input, ui16Exp);
    /*对uiq31结果进行四舍五入并切换到uiq23*/
    uiq23Result = (LQ_UI_32BIT)(((LQ_UI_64BIT)uiq31Input + 0x0080u) >> 8);
    if (uiq23Result >= 0x01000000u)
    {
        uiq23Result = 0;
        ui16Exp += 0x0080;
    }
    /*删除尾数的隐含MSB位 */
    uiq23Result &= ~0x00800000;
    /*
    *将构造的指数和符号位添加到尾数。我们必须使用
    *四舍五入会导致尾数溢出的情况下的加法。
    *当这种情况发生时，尾数结果为2，其中MSB为零
    *exp的LSB被设置为1。在指数上加一就是
    *尾数为2的正确处理。不需要缩放
    *尾数，因为在这种情况下它总是等于零。
   */
    uiq23Result += (LQ_UI_32BIT)ui16Exp << 16;
    return LQ_TI_UINT32_BITS_TO_FLOAT(uiq23Result);
}
/**@brief (TI方法)INT32类型Q1格式转浮点
* @details 采用估算位+指数位+符号位三位结合，能提高精度
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为浮点数
* @code*    LQ_TI_INT32_Q1_TO_FLOAT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_INT32_Q31_TO_FLOAT  TI方式INT32的Q31转化浮点类型\n
*     LQ_TI_INT32_Q30_TO_FLOAT  TI方式INT32的Q30转化浮点类型\n
*     LQ_TI_INT32_Q29_TO_FLOAT  TI方式INT32的Q29转化浮点类型\n
*     LQ_TI_INT32_Q28_TO_FLOAT  TI方式INT32的Q28转化浮点类型\n
*     LQ_TI_INT32_Q27_TO_FLOAT  TI方式INT32的Q27转化浮点类型\n
*     LQ_TI_INT32_Q26_TO_FLOAT  TI方式INT32的Q26转化浮点类型\n
*     LQ_TI_INT32_Q25_TO_FLOAT  TI方式INT32的Q25转化浮点类型\n
*     LQ_TI_INT32_Q24_TO_FLOAT  TI方式INT32的Q24转化浮点类型\n
*     LQ_TI_INT32_Q23_TO_FLOAT  TI方式INT32的Q23转化浮点类型\n
*     LQ_TI_INT32_Q22_TO_FLOAT  TI方式INT32的Q22转化浮点类型\n
*     LQ_TI_INT32_Q21_TO_FLOAT  TI方式INT32的Q21转化浮点类型\n
*     LQ_TI_INT32_Q20_TO_FLOAT  TI方式INT32的Q20转化浮点类型\n
*     LQ_TI_INT32_Q19_TO_FLOAT  TI方式INT32的Q19转化浮点类型\n
*     LQ_TI_INT32_Q18_TO_FLOAT  TI方式INT32的Q18转化浮点类型\n
*     LQ_TI_INT32_Q17_TO_FLOAT  TI方式INT32的Q17转化浮点类型\n
*     LQ_TI_INT32_Q16_TO_FLOAT  TI方式INT32的Q16转化浮点类型\n
*     LQ_TI_INT32_Q15_TO_FLOAT  TI方式INT32的Q15转化浮点类型\n
*     LQ_TI_INT32_Q14_TO_FLOAT  TI方式INT32的Q14转化浮点类型\n
*     LQ_TI_INT32_Q13_TO_FLOAT  TI方式INT32的Q13转化浮点类型\n
*     LQ_TI_INT32_Q12_TO_FLOAT  TI方式INT32的Q12转化浮点类型\n
*     LQ_TI_INT32_Q11_TO_FLOAT  TI方式INT32的Q11转化浮点类型\n
*     LQ_TI_INT32_Q10_TO_FLOAT  TI方式INT32的Q10转化浮点类型\n
*     LQ_TI_INT32_Q9_TO_FLOAT  TI方式INT32的Q9转化浮点类型\n
*     LQ_TI_INT32_Q8_TO_FLOAT  TI方式INT32的Q8转化浮点类型\n
*     LQ_TI_INT32_Q7_TO_FLOAT  TI方式INT32的Q7转化浮点类型\n
*     LQ_TI_INT32_Q6_TO_FLOAT  TI方式INT32的Q6转化浮点类型\n
*     LQ_TI_INT32_Q5_TO_FLOAT  TI方式INT32的Q5转化浮点类型\n
*     LQ_TI_INT32_Q4_TO_FLOAT  TI方式INT32的Q4转化浮点类型\n
*     LQ_TI_INT32_Q3_TO_FLOAT  TI方式INT32的Q3转化浮点类型\n
*     LQ_TI_INT32_Q2_TO_FLOAT  TI方式INT32的Q2转化浮点类型\n
*     LQ_TI_INT32_Q1_TO_FLOAT  TI方式INT32的Q1转化浮点类型\n
*/
LQ_F_32BIT LQ_TI_INT32_Q1_TO_FLOAT(LQ_I_32BIT A, LQ_ERROR* lq_error)
{
    LQ_UI_16BIT ui16Exp;
    LQ_UI_32BIT uiq23Result;
    LQ_UI_32BIT uiq31Input;
    //!< 初始化指数部分偏移量
    ui16Exp = 20096;
    //!< 保存符号位
    if (A < 0)
    {
        ui16Exp |= 0x8000;
        uiq31Input = (LQ_UI_32BIT)(-(LQ_I_64BIT)A);
    }
    else if (A == 0)
    {
        return (0);
    }
    else
    {
        uiq31Input = A;
    }
    LQ_TI_Q2F_NORMALIZE(uiq31Input, ui16Exp);
    /*对uiq31结果进行四舍五入并切换到uiq23*/
    uiq23Result = (LQ_UI_32BIT)(((LQ_UI_64BIT)uiq31Input + 0x0080u) >> 8);
    if (uiq23Result >= 0x01000000u)
    {
        uiq23Result = 0;
        ui16Exp += 0x0080;
    }
    /*删除尾数的隐含MSB位 */
    uiq23Result &= ~0x00800000;
    /*
    *将构造的指数和符号位添加到尾数。我们必须使用
    *四舍五入会导致尾数溢出的情况下的加法。
    *当这种情况发生时，尾数结果为2，其中MSB为零
    *exp的LSB被设置为1。在指数上加一就是
    *尾数为2的正确处理。不需要缩放
    *尾数，因为在这种情况下它总是等于零。
   */
    uiq23Result += (LQ_UI_32BIT)ui16Exp << 16;
    return LQ_TI_UINT32_BITS_TO_FLOAT(uiq23Result);
}
/**@brief (TI方法)UINT32类型UQ32格式转浮点
* @details 采用估算位+指数位+符号位三位结合，能提高精度
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为浮点数
* @code*    LQ_TI_UINT32_UQ32_TO_FLOAT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_UINT32_UQ32_TO_FLOAT  TI方式UINT32的UQ32转化浮点类型\n
*     LQ_TI_UINT32_UQ31_TO_FLOAT  TI方式UINT32的UQ31转化浮点类型\n
*     LQ_TI_UINT32_UQ30_TO_FLOAT  TI方式UINT32的UQ30转化浮点类型\n
*     LQ_TI_UINT32_UQ29_TO_FLOAT  TI方式UINT32的UQ29转化浮点类型\n
*     LQ_TI_UINT32_UQ28_TO_FLOAT  TI方式UINT32的UQ28转化浮点类型\n
*     LQ_TI_UINT32_UQ27_TO_FLOAT  TI方式UINT32的UQ27转化浮点类型\n
*     LQ_TI_UINT32_UQ26_TO_FLOAT  TI方式UINT32的UQ26转化浮点类型\n
*     LQ_TI_UINT32_UQ25_TO_FLOAT  TI方式UINT32的UQ25转化浮点类型\n
*     LQ_TI_UINT32_UQ24_TO_FLOAT  TI方式UINT32的UQ24转化浮点类型\n
*     LQ_TI_UINT32_UQ23_TO_FLOAT  TI方式UINT32的UQ23转化浮点类型\n
*     LQ_TI_UINT32_UQ22_TO_FLOAT  TI方式UINT32的UQ22转化浮点类型\n
*     LQ_TI_UINT32_UQ21_TO_FLOAT  TI方式UINT32的UQ21转化浮点类型\n
*     LQ_TI_UINT32_UQ20_TO_FLOAT  TI方式UINT32的UQ20转化浮点类型\n
*     LQ_TI_UINT32_UQ19_TO_FLOAT  TI方式UINT32的UQ19转化浮点类型\n
*     LQ_TI_UINT32_UQ18_TO_FLOAT  TI方式UINT32的UQ18转化浮点类型\n
*     LQ_TI_UINT32_UQ17_TO_FLOAT  TI方式UINT32的UQ17转化浮点类型\n
*     LQ_TI_UINT32_UQ16_TO_FLOAT  TI方式UINT32的UQ16转化浮点类型\n
*     LQ_TI_UINT32_UQ15_TO_FLOAT  TI方式UINT32的UQ15转化浮点类型\n
*     LQ_TI_UINT32_UQ14_TO_FLOAT  TI方式UINT32的UQ14转化浮点类型\n
*     LQ_TI_UINT32_UQ13_TO_FLOAT  TI方式UINT32的UQ13转化浮点类型\n
*     LQ_TI_UINT32_UQ12_TO_FLOAT  TI方式UINT32的UQ12转化浮点类型\n
*     LQ_TI_UINT32_UQ11_TO_FLOAT  TI方式UINT32的UQ11转化浮点类型\n
*     LQ_TI_UINT32_UQ10_TO_FLOAT  TI方式UINT32的UQ10转化浮点类型\n
*     LQ_TI_UINT32_UQ9_TO_FLOAT  TI方式UINT32的UQ9转化浮点类型\n
*     LQ_TI_UINT32_UQ8_TO_FLOAT  TI方式UINT32的UQ8转化浮点类型\n
*     LQ_TI_UINT32_UQ7_TO_FLOAT  TI方式UINT32的UQ7转化浮点类型\n
*     LQ_TI_UINT32_UQ6_TO_FLOAT  TI方式UINT32的UQ6转化浮点类型\n
*     LQ_TI_UINT32_UQ5_TO_FLOAT  TI方式UINT32的UQ5转化浮点类型\n
*     LQ_TI_UINT32_UQ4_TO_FLOAT  TI方式UINT32的UQ4转化浮点类型\n
*     LQ_TI_UINT32_UQ3_TO_FLOAT  TI方式UINT32的UQ3转化浮点类型\n
*     LQ_TI_UINT32_UQ2_TO_FLOAT  TI方式UINT32的UQ2转化浮点类型\n
*     LQ_TI_UINT32_UQ1_TO_FLOAT  TI方式UINT32的UQ1转化浮点类型\n
*/
LQ_F_32BIT LQ_TI_UINT32_UQ32_TO_FLOAT(LQ_I_32BIT A, LQ_ERROR* lq_error)
{
    LQ_UI_16BIT ui16Exp;
    LQ_UI_32BIT uiq23Result;
    LQ_UI_32BIT uiq31Input;
    //!< 初始化指数部分偏移量
    ui16Exp = 16128;
    //!< 保存符号位
    if (A < 0)
    {
        ui16Exp |= 0x8000;
        uiq31Input = (LQ_UI_32BIT)(-(LQ_I_64BIT)A);
    }
    else if (A == 0)
    {
        return (0);
    }
    else
    {
        uiq31Input = A;
    }
    LQ_TI_Q2F_NORMALIZE(uiq31Input, ui16Exp);
    /*对uiq31结果进行四舍五入并切换到uiq23*/
    uiq23Result = (LQ_UI_32BIT)(((LQ_UI_64BIT)uiq31Input + 0x0080u) >> 8);
    if (uiq23Result >= 0x01000000u)
    {
        uiq23Result = 0;
        ui16Exp += 0x0080;
    }
    /*删除尾数的隐含MSB位 */
    uiq23Result &= ~0x00800000;
    /*
    *将构造的指数和符号位添加到尾数。我们必须使用
    *四舍五入会导致尾数溢出的情况下的加法。
    *当这种情况发生时，尾数结果为2，其中MSB为零
    *exp的LSB被设置为1。在指数上加一就是
    *尾数为2的正确处理。不需要缩放
    *尾数，因为在这种情况下它总是等于零。
   */
    uiq23Result += (LQ_UI_32BIT)ui16Exp << 16;
    return LQ_TI_UINT32_BITS_TO_FLOAT(uiq23Result);
}
/**@brief (TI方法)UINT32类型UQ31格式转浮点
* @details 采用估算位+指数位+符号位三位结合，能提高精度
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为浮点数
* @code*    LQ_TI_UINT32_UQ31_TO_FLOAT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_UINT32_UQ32_TO_FLOAT  TI方式UINT32的UQ32转化浮点类型\n
*     LQ_TI_UINT32_UQ31_TO_FLOAT  TI方式UINT32的UQ31转化浮点类型\n
*     LQ_TI_UINT32_UQ30_TO_FLOAT  TI方式UINT32的UQ30转化浮点类型\n
*     LQ_TI_UINT32_UQ29_TO_FLOAT  TI方式UINT32的UQ29转化浮点类型\n
*     LQ_TI_UINT32_UQ28_TO_FLOAT  TI方式UINT32的UQ28转化浮点类型\n
*     LQ_TI_UINT32_UQ27_TO_FLOAT  TI方式UINT32的UQ27转化浮点类型\n
*     LQ_TI_UINT32_UQ26_TO_FLOAT  TI方式UINT32的UQ26转化浮点类型\n
*     LQ_TI_UINT32_UQ25_TO_FLOAT  TI方式UINT32的UQ25转化浮点类型\n
*     LQ_TI_UINT32_UQ24_TO_FLOAT  TI方式UINT32的UQ24转化浮点类型\n
*     LQ_TI_UINT32_UQ23_TO_FLOAT  TI方式UINT32的UQ23转化浮点类型\n
*     LQ_TI_UINT32_UQ22_TO_FLOAT  TI方式UINT32的UQ22转化浮点类型\n
*     LQ_TI_UINT32_UQ21_TO_FLOAT  TI方式UINT32的UQ21转化浮点类型\n
*     LQ_TI_UINT32_UQ20_TO_FLOAT  TI方式UINT32的UQ20转化浮点类型\n
*     LQ_TI_UINT32_UQ19_TO_FLOAT  TI方式UINT32的UQ19转化浮点类型\n
*     LQ_TI_UINT32_UQ18_TO_FLOAT  TI方式UINT32的UQ18转化浮点类型\n
*     LQ_TI_UINT32_UQ17_TO_FLOAT  TI方式UINT32的UQ17转化浮点类型\n
*     LQ_TI_UINT32_UQ16_TO_FLOAT  TI方式UINT32的UQ16转化浮点类型\n
*     LQ_TI_UINT32_UQ15_TO_FLOAT  TI方式UINT32的UQ15转化浮点类型\n
*     LQ_TI_UINT32_UQ14_TO_FLOAT  TI方式UINT32的UQ14转化浮点类型\n
*     LQ_TI_UINT32_UQ13_TO_FLOAT  TI方式UINT32的UQ13转化浮点类型\n
*     LQ_TI_UINT32_UQ12_TO_FLOAT  TI方式UINT32的UQ12转化浮点类型\n
*     LQ_TI_UINT32_UQ11_TO_FLOAT  TI方式UINT32的UQ11转化浮点类型\n
*     LQ_TI_UINT32_UQ10_TO_FLOAT  TI方式UINT32的UQ10转化浮点类型\n
*     LQ_TI_UINT32_UQ9_TO_FLOAT  TI方式UINT32的UQ9转化浮点类型\n
*     LQ_TI_UINT32_UQ8_TO_FLOAT  TI方式UINT32的UQ8转化浮点类型\n
*     LQ_TI_UINT32_UQ7_TO_FLOAT  TI方式UINT32的UQ7转化浮点类型\n
*     LQ_TI_UINT32_UQ6_TO_FLOAT  TI方式UINT32的UQ6转化浮点类型\n
*     LQ_TI_UINT32_UQ5_TO_FLOAT  TI方式UINT32的UQ5转化浮点类型\n
*     LQ_TI_UINT32_UQ4_TO_FLOAT  TI方式UINT32的UQ4转化浮点类型\n
*     LQ_TI_UINT32_UQ3_TO_FLOAT  TI方式UINT32的UQ3转化浮点类型\n
*     LQ_TI_UINT32_UQ2_TO_FLOAT  TI方式UINT32的UQ2转化浮点类型\n
*     LQ_TI_UINT32_UQ1_TO_FLOAT  TI方式UINT32的UQ1转化浮点类型\n
*/
LQ_F_32BIT LQ_TI_UINT32_UQ31_TO_FLOAT(LQ_I_32BIT A, LQ_ERROR* lq_error)
{
    LQ_UI_16BIT ui16Exp;
    LQ_UI_32BIT uiq23Result;
    LQ_UI_32BIT uiq31Input;
    //!< 初始化指数部分偏移量
    ui16Exp = 16256;
    //!< 保存符号位
    if (A < 0)
    {
        ui16Exp |= 0x8000;
        uiq31Input = (LQ_UI_32BIT)(-(LQ_I_64BIT)A);
    }
    else if (A == 0)
    {
        return (0);
    }
    else
    {
        uiq31Input = A;
    }
    LQ_TI_Q2F_NORMALIZE(uiq31Input, ui16Exp);
    /*对uiq31结果进行四舍五入并切换到uiq23*/
    uiq23Result = (LQ_UI_32BIT)(((LQ_UI_64BIT)uiq31Input + 0x0080u) >> 8);
    if (uiq23Result >= 0x01000000u)
    {
        uiq23Result = 0;
        ui16Exp += 0x0080;
    }
    /*删除尾数的隐含MSB位 */
    uiq23Result &= ~0x00800000;
    /*
    *将构造的指数和符号位添加到尾数。我们必须使用
    *四舍五入会导致尾数溢出的情况下的加法。
    *当这种情况发生时，尾数结果为2，其中MSB为零
    *exp的LSB被设置为1。在指数上加一就是
    *尾数为2的正确处理。不需要缩放
    *尾数，因为在这种情况下它总是等于零。
   */
    uiq23Result += (LQ_UI_32BIT)ui16Exp << 16;
    return LQ_TI_UINT32_BITS_TO_FLOAT(uiq23Result);
}
/**@brief (TI方法)UINT32类型UQ30格式转浮点
* @details 采用估算位+指数位+符号位三位结合，能提高精度
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为浮点数
* @code*    LQ_TI_UINT32_UQ30_TO_FLOAT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_UINT32_UQ32_TO_FLOAT  TI方式UINT32的UQ32转化浮点类型\n
*     LQ_TI_UINT32_UQ31_TO_FLOAT  TI方式UINT32的UQ31转化浮点类型\n
*     LQ_TI_UINT32_UQ30_TO_FLOAT  TI方式UINT32的UQ30转化浮点类型\n
*     LQ_TI_UINT32_UQ29_TO_FLOAT  TI方式UINT32的UQ29转化浮点类型\n
*     LQ_TI_UINT32_UQ28_TO_FLOAT  TI方式UINT32的UQ28转化浮点类型\n
*     LQ_TI_UINT32_UQ27_TO_FLOAT  TI方式UINT32的UQ27转化浮点类型\n
*     LQ_TI_UINT32_UQ26_TO_FLOAT  TI方式UINT32的UQ26转化浮点类型\n
*     LQ_TI_UINT32_UQ25_TO_FLOAT  TI方式UINT32的UQ25转化浮点类型\n
*     LQ_TI_UINT32_UQ24_TO_FLOAT  TI方式UINT32的UQ24转化浮点类型\n
*     LQ_TI_UINT32_UQ23_TO_FLOAT  TI方式UINT32的UQ23转化浮点类型\n
*     LQ_TI_UINT32_UQ22_TO_FLOAT  TI方式UINT32的UQ22转化浮点类型\n
*     LQ_TI_UINT32_UQ21_TO_FLOAT  TI方式UINT32的UQ21转化浮点类型\n
*     LQ_TI_UINT32_UQ20_TO_FLOAT  TI方式UINT32的UQ20转化浮点类型\n
*     LQ_TI_UINT32_UQ19_TO_FLOAT  TI方式UINT32的UQ19转化浮点类型\n
*     LQ_TI_UINT32_UQ18_TO_FLOAT  TI方式UINT32的UQ18转化浮点类型\n
*     LQ_TI_UINT32_UQ17_TO_FLOAT  TI方式UINT32的UQ17转化浮点类型\n
*     LQ_TI_UINT32_UQ16_TO_FLOAT  TI方式UINT32的UQ16转化浮点类型\n
*     LQ_TI_UINT32_UQ15_TO_FLOAT  TI方式UINT32的UQ15转化浮点类型\n
*     LQ_TI_UINT32_UQ14_TO_FLOAT  TI方式UINT32的UQ14转化浮点类型\n
*     LQ_TI_UINT32_UQ13_TO_FLOAT  TI方式UINT32的UQ13转化浮点类型\n
*     LQ_TI_UINT32_UQ12_TO_FLOAT  TI方式UINT32的UQ12转化浮点类型\n
*     LQ_TI_UINT32_UQ11_TO_FLOAT  TI方式UINT32的UQ11转化浮点类型\n
*     LQ_TI_UINT32_UQ10_TO_FLOAT  TI方式UINT32的UQ10转化浮点类型\n
*     LQ_TI_UINT32_UQ9_TO_FLOAT  TI方式UINT32的UQ9转化浮点类型\n
*     LQ_TI_UINT32_UQ8_TO_FLOAT  TI方式UINT32的UQ8转化浮点类型\n
*     LQ_TI_UINT32_UQ7_TO_FLOAT  TI方式UINT32的UQ7转化浮点类型\n
*     LQ_TI_UINT32_UQ6_TO_FLOAT  TI方式UINT32的UQ6转化浮点类型\n
*     LQ_TI_UINT32_UQ5_TO_FLOAT  TI方式UINT32的UQ5转化浮点类型\n
*     LQ_TI_UINT32_UQ4_TO_FLOAT  TI方式UINT32的UQ4转化浮点类型\n
*     LQ_TI_UINT32_UQ3_TO_FLOAT  TI方式UINT32的UQ3转化浮点类型\n
*     LQ_TI_UINT32_UQ2_TO_FLOAT  TI方式UINT32的UQ2转化浮点类型\n
*     LQ_TI_UINT32_UQ1_TO_FLOAT  TI方式UINT32的UQ1转化浮点类型\n
*/
LQ_F_32BIT LQ_TI_UINT32_UQ30_TO_FLOAT(LQ_I_32BIT A, LQ_ERROR* lq_error)
{
    LQ_UI_16BIT ui16Exp;
    LQ_UI_32BIT uiq23Result;
    LQ_UI_32BIT uiq31Input;
    //!< 初始化指数部分偏移量
    ui16Exp = 16384;
    //!< 保存符号位
    if (A < 0)
    {
        ui16Exp |= 0x8000;
        uiq31Input = (LQ_UI_32BIT)(-(LQ_I_64BIT)A);
    }
    else if (A == 0)
    {
        return (0);
    }
    else
    {
        uiq31Input = A;
    }
    LQ_TI_Q2F_NORMALIZE(uiq31Input, ui16Exp);
    /*对uiq31结果进行四舍五入并切换到uiq23*/
    uiq23Result = (LQ_UI_32BIT)(((LQ_UI_64BIT)uiq31Input + 0x0080u) >> 8);
    if (uiq23Result >= 0x01000000u)
    {
        uiq23Result = 0;
        ui16Exp += 0x0080;
    }
    /*删除尾数的隐含MSB位 */
    uiq23Result &= ~0x00800000;
    /*
    *将构造的指数和符号位添加到尾数。我们必须使用
    *四舍五入会导致尾数溢出的情况下的加法。
    *当这种情况发生时，尾数结果为2，其中MSB为零
    *exp的LSB被设置为1。在指数上加一就是
    *尾数为2的正确处理。不需要缩放
    *尾数，因为在这种情况下它总是等于零。
   */
    uiq23Result += (LQ_UI_32BIT)ui16Exp << 16;
    return LQ_TI_UINT32_BITS_TO_FLOAT(uiq23Result);
}
/**@brief (TI方法)UINT32类型UQ29格式转浮点
* @details 采用估算位+指数位+符号位三位结合，能提高精度
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为浮点数
* @code*    LQ_TI_UINT32_UQ29_TO_FLOAT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_UINT32_UQ32_TO_FLOAT  TI方式UINT32的UQ32转化浮点类型\n
*     LQ_TI_UINT32_UQ31_TO_FLOAT  TI方式UINT32的UQ31转化浮点类型\n
*     LQ_TI_UINT32_UQ30_TO_FLOAT  TI方式UINT32的UQ30转化浮点类型\n
*     LQ_TI_UINT32_UQ29_TO_FLOAT  TI方式UINT32的UQ29转化浮点类型\n
*     LQ_TI_UINT32_UQ28_TO_FLOAT  TI方式UINT32的UQ28转化浮点类型\n
*     LQ_TI_UINT32_UQ27_TO_FLOAT  TI方式UINT32的UQ27转化浮点类型\n
*     LQ_TI_UINT32_UQ26_TO_FLOAT  TI方式UINT32的UQ26转化浮点类型\n
*     LQ_TI_UINT32_UQ25_TO_FLOAT  TI方式UINT32的UQ25转化浮点类型\n
*     LQ_TI_UINT32_UQ24_TO_FLOAT  TI方式UINT32的UQ24转化浮点类型\n
*     LQ_TI_UINT32_UQ23_TO_FLOAT  TI方式UINT32的UQ23转化浮点类型\n
*     LQ_TI_UINT32_UQ22_TO_FLOAT  TI方式UINT32的UQ22转化浮点类型\n
*     LQ_TI_UINT32_UQ21_TO_FLOAT  TI方式UINT32的UQ21转化浮点类型\n
*     LQ_TI_UINT32_UQ20_TO_FLOAT  TI方式UINT32的UQ20转化浮点类型\n
*     LQ_TI_UINT32_UQ19_TO_FLOAT  TI方式UINT32的UQ19转化浮点类型\n
*     LQ_TI_UINT32_UQ18_TO_FLOAT  TI方式UINT32的UQ18转化浮点类型\n
*     LQ_TI_UINT32_UQ17_TO_FLOAT  TI方式UINT32的UQ17转化浮点类型\n
*     LQ_TI_UINT32_UQ16_TO_FLOAT  TI方式UINT32的UQ16转化浮点类型\n
*     LQ_TI_UINT32_UQ15_TO_FLOAT  TI方式UINT32的UQ15转化浮点类型\n
*     LQ_TI_UINT32_UQ14_TO_FLOAT  TI方式UINT32的UQ14转化浮点类型\n
*     LQ_TI_UINT32_UQ13_TO_FLOAT  TI方式UINT32的UQ13转化浮点类型\n
*     LQ_TI_UINT32_UQ12_TO_FLOAT  TI方式UINT32的UQ12转化浮点类型\n
*     LQ_TI_UINT32_UQ11_TO_FLOAT  TI方式UINT32的UQ11转化浮点类型\n
*     LQ_TI_UINT32_UQ10_TO_FLOAT  TI方式UINT32的UQ10转化浮点类型\n
*     LQ_TI_UINT32_UQ9_TO_FLOAT  TI方式UINT32的UQ9转化浮点类型\n
*     LQ_TI_UINT32_UQ8_TO_FLOAT  TI方式UINT32的UQ8转化浮点类型\n
*     LQ_TI_UINT32_UQ7_TO_FLOAT  TI方式UINT32的UQ7转化浮点类型\n
*     LQ_TI_UINT32_UQ6_TO_FLOAT  TI方式UINT32的UQ6转化浮点类型\n
*     LQ_TI_UINT32_UQ5_TO_FLOAT  TI方式UINT32的UQ5转化浮点类型\n
*     LQ_TI_UINT32_UQ4_TO_FLOAT  TI方式UINT32的UQ4转化浮点类型\n
*     LQ_TI_UINT32_UQ3_TO_FLOAT  TI方式UINT32的UQ3转化浮点类型\n
*     LQ_TI_UINT32_UQ2_TO_FLOAT  TI方式UINT32的UQ2转化浮点类型\n
*     LQ_TI_UINT32_UQ1_TO_FLOAT  TI方式UINT32的UQ1转化浮点类型\n
*/
LQ_F_32BIT LQ_TI_UINT32_UQ29_TO_FLOAT(LQ_I_32BIT A, LQ_ERROR* lq_error)
{
    LQ_UI_16BIT ui16Exp;
    LQ_UI_32BIT uiq23Result;
    LQ_UI_32BIT uiq31Input;
    //!< 初始化指数部分偏移量
    ui16Exp = 16512;
    //!< 保存符号位
    if (A < 0)
    {
        ui16Exp |= 0x8000;
        uiq31Input = (LQ_UI_32BIT)(-(LQ_I_64BIT)A);
    }
    else if (A == 0)
    {
        return (0);
    }
    else
    {
        uiq31Input = A;
    }
    LQ_TI_Q2F_NORMALIZE(uiq31Input, ui16Exp);
    /*对uiq31结果进行四舍五入并切换到uiq23*/
    uiq23Result = (LQ_UI_32BIT)(((LQ_UI_64BIT)uiq31Input + 0x0080u) >> 8);
    if (uiq23Result >= 0x01000000u)
    {
        uiq23Result = 0;
        ui16Exp += 0x0080;
    }
    /*删除尾数的隐含MSB位 */
    uiq23Result &= ~0x00800000;
    /*
    *将构造的指数和符号位添加到尾数。我们必须使用
    *四舍五入会导致尾数溢出的情况下的加法。
    *当这种情况发生时，尾数结果为2，其中MSB为零
    *exp的LSB被设置为1。在指数上加一就是
    *尾数为2的正确处理。不需要缩放
    *尾数，因为在这种情况下它总是等于零。
   */
    uiq23Result += (LQ_UI_32BIT)ui16Exp << 16;
    return LQ_TI_UINT32_BITS_TO_FLOAT(uiq23Result);
}
/**@brief (TI方法)UINT32类型UQ28格式转浮点
* @details 采用估算位+指数位+符号位三位结合，能提高精度
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为浮点数
* @code*    LQ_TI_UINT32_UQ28_TO_FLOAT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_UINT32_UQ32_TO_FLOAT  TI方式UINT32的UQ32转化浮点类型\n
*     LQ_TI_UINT32_UQ31_TO_FLOAT  TI方式UINT32的UQ31转化浮点类型\n
*     LQ_TI_UINT32_UQ30_TO_FLOAT  TI方式UINT32的UQ30转化浮点类型\n
*     LQ_TI_UINT32_UQ29_TO_FLOAT  TI方式UINT32的UQ29转化浮点类型\n
*     LQ_TI_UINT32_UQ28_TO_FLOAT  TI方式UINT32的UQ28转化浮点类型\n
*     LQ_TI_UINT32_UQ27_TO_FLOAT  TI方式UINT32的UQ27转化浮点类型\n
*     LQ_TI_UINT32_UQ26_TO_FLOAT  TI方式UINT32的UQ26转化浮点类型\n
*     LQ_TI_UINT32_UQ25_TO_FLOAT  TI方式UINT32的UQ25转化浮点类型\n
*     LQ_TI_UINT32_UQ24_TO_FLOAT  TI方式UINT32的UQ24转化浮点类型\n
*     LQ_TI_UINT32_UQ23_TO_FLOAT  TI方式UINT32的UQ23转化浮点类型\n
*     LQ_TI_UINT32_UQ22_TO_FLOAT  TI方式UINT32的UQ22转化浮点类型\n
*     LQ_TI_UINT32_UQ21_TO_FLOAT  TI方式UINT32的UQ21转化浮点类型\n
*     LQ_TI_UINT32_UQ20_TO_FLOAT  TI方式UINT32的UQ20转化浮点类型\n
*     LQ_TI_UINT32_UQ19_TO_FLOAT  TI方式UINT32的UQ19转化浮点类型\n
*     LQ_TI_UINT32_UQ18_TO_FLOAT  TI方式UINT32的UQ18转化浮点类型\n
*     LQ_TI_UINT32_UQ17_TO_FLOAT  TI方式UINT32的UQ17转化浮点类型\n
*     LQ_TI_UINT32_UQ16_TO_FLOAT  TI方式UINT32的UQ16转化浮点类型\n
*     LQ_TI_UINT32_UQ15_TO_FLOAT  TI方式UINT32的UQ15转化浮点类型\n
*     LQ_TI_UINT32_UQ14_TO_FLOAT  TI方式UINT32的UQ14转化浮点类型\n
*     LQ_TI_UINT32_UQ13_TO_FLOAT  TI方式UINT32的UQ13转化浮点类型\n
*     LQ_TI_UINT32_UQ12_TO_FLOAT  TI方式UINT32的UQ12转化浮点类型\n
*     LQ_TI_UINT32_UQ11_TO_FLOAT  TI方式UINT32的UQ11转化浮点类型\n
*     LQ_TI_UINT32_UQ10_TO_FLOAT  TI方式UINT32的UQ10转化浮点类型\n
*     LQ_TI_UINT32_UQ9_TO_FLOAT  TI方式UINT32的UQ9转化浮点类型\n
*     LQ_TI_UINT32_UQ8_TO_FLOAT  TI方式UINT32的UQ8转化浮点类型\n
*     LQ_TI_UINT32_UQ7_TO_FLOAT  TI方式UINT32的UQ7转化浮点类型\n
*     LQ_TI_UINT32_UQ6_TO_FLOAT  TI方式UINT32的UQ6转化浮点类型\n
*     LQ_TI_UINT32_UQ5_TO_FLOAT  TI方式UINT32的UQ5转化浮点类型\n
*     LQ_TI_UINT32_UQ4_TO_FLOAT  TI方式UINT32的UQ4转化浮点类型\n
*     LQ_TI_UINT32_UQ3_TO_FLOAT  TI方式UINT32的UQ3转化浮点类型\n
*     LQ_TI_UINT32_UQ2_TO_FLOAT  TI方式UINT32的UQ2转化浮点类型\n
*     LQ_TI_UINT32_UQ1_TO_FLOAT  TI方式UINT32的UQ1转化浮点类型\n
*/
LQ_F_32BIT LQ_TI_UINT32_UQ28_TO_FLOAT(LQ_I_32BIT A, LQ_ERROR* lq_error)
{
    LQ_UI_16BIT ui16Exp;
    LQ_UI_32BIT uiq23Result;
    LQ_UI_32BIT uiq31Input;
    //!< 初始化指数部分偏移量
    ui16Exp = 16640;
    //!< 保存符号位
    if (A < 0)
    {
        ui16Exp |= 0x8000;
        uiq31Input = (LQ_UI_32BIT)(-(LQ_I_64BIT)A);
    }
    else if (A == 0)
    {
        return (0);
    }
    else
    {
        uiq31Input = A;
    }
    LQ_TI_Q2F_NORMALIZE(uiq31Input, ui16Exp);
    /*对uiq31结果进行四舍五入并切换到uiq23*/
    uiq23Result = (LQ_UI_32BIT)(((LQ_UI_64BIT)uiq31Input + 0x0080u) >> 8);
    if (uiq23Result >= 0x01000000u)
    {
        uiq23Result = 0;
        ui16Exp += 0x0080;
    }
    /*删除尾数的隐含MSB位 */
    uiq23Result &= ~0x00800000;
    /*
    *将构造的指数和符号位添加到尾数。我们必须使用
    *四舍五入会导致尾数溢出的情况下的加法。
    *当这种情况发生时，尾数结果为2，其中MSB为零
    *exp的LSB被设置为1。在指数上加一就是
    *尾数为2的正确处理。不需要缩放
    *尾数，因为在这种情况下它总是等于零。
   */
    uiq23Result += (LQ_UI_32BIT)ui16Exp << 16;
    return LQ_TI_UINT32_BITS_TO_FLOAT(uiq23Result);
}
/**@brief (TI方法)UINT32类型UQ27格式转浮点
* @details 采用估算位+指数位+符号位三位结合，能提高精度
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为浮点数
* @code*    LQ_TI_UINT32_UQ27_TO_FLOAT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_UINT32_UQ32_TO_FLOAT  TI方式UINT32的UQ32转化浮点类型\n
*     LQ_TI_UINT32_UQ31_TO_FLOAT  TI方式UINT32的UQ31转化浮点类型\n
*     LQ_TI_UINT32_UQ30_TO_FLOAT  TI方式UINT32的UQ30转化浮点类型\n
*     LQ_TI_UINT32_UQ29_TO_FLOAT  TI方式UINT32的UQ29转化浮点类型\n
*     LQ_TI_UINT32_UQ28_TO_FLOAT  TI方式UINT32的UQ28转化浮点类型\n
*     LQ_TI_UINT32_UQ27_TO_FLOAT  TI方式UINT32的UQ27转化浮点类型\n
*     LQ_TI_UINT32_UQ26_TO_FLOAT  TI方式UINT32的UQ26转化浮点类型\n
*     LQ_TI_UINT32_UQ25_TO_FLOAT  TI方式UINT32的UQ25转化浮点类型\n
*     LQ_TI_UINT32_UQ24_TO_FLOAT  TI方式UINT32的UQ24转化浮点类型\n
*     LQ_TI_UINT32_UQ23_TO_FLOAT  TI方式UINT32的UQ23转化浮点类型\n
*     LQ_TI_UINT32_UQ22_TO_FLOAT  TI方式UINT32的UQ22转化浮点类型\n
*     LQ_TI_UINT32_UQ21_TO_FLOAT  TI方式UINT32的UQ21转化浮点类型\n
*     LQ_TI_UINT32_UQ20_TO_FLOAT  TI方式UINT32的UQ20转化浮点类型\n
*     LQ_TI_UINT32_UQ19_TO_FLOAT  TI方式UINT32的UQ19转化浮点类型\n
*     LQ_TI_UINT32_UQ18_TO_FLOAT  TI方式UINT32的UQ18转化浮点类型\n
*     LQ_TI_UINT32_UQ17_TO_FLOAT  TI方式UINT32的UQ17转化浮点类型\n
*     LQ_TI_UINT32_UQ16_TO_FLOAT  TI方式UINT32的UQ16转化浮点类型\n
*     LQ_TI_UINT32_UQ15_TO_FLOAT  TI方式UINT32的UQ15转化浮点类型\n
*     LQ_TI_UINT32_UQ14_TO_FLOAT  TI方式UINT32的UQ14转化浮点类型\n
*     LQ_TI_UINT32_UQ13_TO_FLOAT  TI方式UINT32的UQ13转化浮点类型\n
*     LQ_TI_UINT32_UQ12_TO_FLOAT  TI方式UINT32的UQ12转化浮点类型\n
*     LQ_TI_UINT32_UQ11_TO_FLOAT  TI方式UINT32的UQ11转化浮点类型\n
*     LQ_TI_UINT32_UQ10_TO_FLOAT  TI方式UINT32的UQ10转化浮点类型\n
*     LQ_TI_UINT32_UQ9_TO_FLOAT  TI方式UINT32的UQ9转化浮点类型\n
*     LQ_TI_UINT32_UQ8_TO_FLOAT  TI方式UINT32的UQ8转化浮点类型\n
*     LQ_TI_UINT32_UQ7_TO_FLOAT  TI方式UINT32的UQ7转化浮点类型\n
*     LQ_TI_UINT32_UQ6_TO_FLOAT  TI方式UINT32的UQ6转化浮点类型\n
*     LQ_TI_UINT32_UQ5_TO_FLOAT  TI方式UINT32的UQ5转化浮点类型\n
*     LQ_TI_UINT32_UQ4_TO_FLOAT  TI方式UINT32的UQ4转化浮点类型\n
*     LQ_TI_UINT32_UQ3_TO_FLOAT  TI方式UINT32的UQ3转化浮点类型\n
*     LQ_TI_UINT32_UQ2_TO_FLOAT  TI方式UINT32的UQ2转化浮点类型\n
*     LQ_TI_UINT32_UQ1_TO_FLOAT  TI方式UINT32的UQ1转化浮点类型\n
*/
LQ_F_32BIT LQ_TI_UINT32_UQ27_TO_FLOAT(LQ_I_32BIT A, LQ_ERROR* lq_error)
{
    LQ_UI_16BIT ui16Exp;
    LQ_UI_32BIT uiq23Result;
    LQ_UI_32BIT uiq31Input;
    //!< 初始化指数部分偏移量
    ui16Exp = 16768;
    //!< 保存符号位
    if (A < 0)
    {
        ui16Exp |= 0x8000;
        uiq31Input = (LQ_UI_32BIT)(-(LQ_I_64BIT)A);
    }
    else if (A == 0)
    {
        return (0);
    }
    else
    {
        uiq31Input = A;
    }
    LQ_TI_Q2F_NORMALIZE(uiq31Input, ui16Exp);
    /*对uiq31结果进行四舍五入并切换到uiq23*/
    uiq23Result = (LQ_UI_32BIT)(((LQ_UI_64BIT)uiq31Input + 0x0080u) >> 8);
    if (uiq23Result >= 0x01000000u)
    {
        uiq23Result = 0;
        ui16Exp += 0x0080;
    }
    /*删除尾数的隐含MSB位 */
    uiq23Result &= ~0x00800000;
    /*
    *将构造的指数和符号位添加到尾数。我们必须使用
    *四舍五入会导致尾数溢出的情况下的加法。
    *当这种情况发生时，尾数结果为2，其中MSB为零
    *exp的LSB被设置为1。在指数上加一就是
    *尾数为2的正确处理。不需要缩放
    *尾数，因为在这种情况下它总是等于零。
   */
    uiq23Result += (LQ_UI_32BIT)ui16Exp << 16;
    return LQ_TI_UINT32_BITS_TO_FLOAT(uiq23Result);
}
/**@brief (TI方法)UINT32类型UQ26格式转浮点
* @details 采用估算位+指数位+符号位三位结合，能提高精度
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为浮点数
* @code*    LQ_TI_UINT32_UQ26_TO_FLOAT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_UINT32_UQ32_TO_FLOAT  TI方式UINT32的UQ32转化浮点类型\n
*     LQ_TI_UINT32_UQ31_TO_FLOAT  TI方式UINT32的UQ31转化浮点类型\n
*     LQ_TI_UINT32_UQ30_TO_FLOAT  TI方式UINT32的UQ30转化浮点类型\n
*     LQ_TI_UINT32_UQ29_TO_FLOAT  TI方式UINT32的UQ29转化浮点类型\n
*     LQ_TI_UINT32_UQ28_TO_FLOAT  TI方式UINT32的UQ28转化浮点类型\n
*     LQ_TI_UINT32_UQ27_TO_FLOAT  TI方式UINT32的UQ27转化浮点类型\n
*     LQ_TI_UINT32_UQ26_TO_FLOAT  TI方式UINT32的UQ26转化浮点类型\n
*     LQ_TI_UINT32_UQ25_TO_FLOAT  TI方式UINT32的UQ25转化浮点类型\n
*     LQ_TI_UINT32_UQ24_TO_FLOAT  TI方式UINT32的UQ24转化浮点类型\n
*     LQ_TI_UINT32_UQ23_TO_FLOAT  TI方式UINT32的UQ23转化浮点类型\n
*     LQ_TI_UINT32_UQ22_TO_FLOAT  TI方式UINT32的UQ22转化浮点类型\n
*     LQ_TI_UINT32_UQ21_TO_FLOAT  TI方式UINT32的UQ21转化浮点类型\n
*     LQ_TI_UINT32_UQ20_TO_FLOAT  TI方式UINT32的UQ20转化浮点类型\n
*     LQ_TI_UINT32_UQ19_TO_FLOAT  TI方式UINT32的UQ19转化浮点类型\n
*     LQ_TI_UINT32_UQ18_TO_FLOAT  TI方式UINT32的UQ18转化浮点类型\n
*     LQ_TI_UINT32_UQ17_TO_FLOAT  TI方式UINT32的UQ17转化浮点类型\n
*     LQ_TI_UINT32_UQ16_TO_FLOAT  TI方式UINT32的UQ16转化浮点类型\n
*     LQ_TI_UINT32_UQ15_TO_FLOAT  TI方式UINT32的UQ15转化浮点类型\n
*     LQ_TI_UINT32_UQ14_TO_FLOAT  TI方式UINT32的UQ14转化浮点类型\n
*     LQ_TI_UINT32_UQ13_TO_FLOAT  TI方式UINT32的UQ13转化浮点类型\n
*     LQ_TI_UINT32_UQ12_TO_FLOAT  TI方式UINT32的UQ12转化浮点类型\n
*     LQ_TI_UINT32_UQ11_TO_FLOAT  TI方式UINT32的UQ11转化浮点类型\n
*     LQ_TI_UINT32_UQ10_TO_FLOAT  TI方式UINT32的UQ10转化浮点类型\n
*     LQ_TI_UINT32_UQ9_TO_FLOAT  TI方式UINT32的UQ9转化浮点类型\n
*     LQ_TI_UINT32_UQ8_TO_FLOAT  TI方式UINT32的UQ8转化浮点类型\n
*     LQ_TI_UINT32_UQ7_TO_FLOAT  TI方式UINT32的UQ7转化浮点类型\n
*     LQ_TI_UINT32_UQ6_TO_FLOAT  TI方式UINT32的UQ6转化浮点类型\n
*     LQ_TI_UINT32_UQ5_TO_FLOAT  TI方式UINT32的UQ5转化浮点类型\n
*     LQ_TI_UINT32_UQ4_TO_FLOAT  TI方式UINT32的UQ4转化浮点类型\n
*     LQ_TI_UINT32_UQ3_TO_FLOAT  TI方式UINT32的UQ3转化浮点类型\n
*     LQ_TI_UINT32_UQ2_TO_FLOAT  TI方式UINT32的UQ2转化浮点类型\n
*     LQ_TI_UINT32_UQ1_TO_FLOAT  TI方式UINT32的UQ1转化浮点类型\n
*/
LQ_F_32BIT LQ_TI_UINT32_UQ26_TO_FLOAT(LQ_I_32BIT A, LQ_ERROR* lq_error)
{
    LQ_UI_16BIT ui16Exp;
    LQ_UI_32BIT uiq23Result;
    LQ_UI_32BIT uiq31Input;
    //!< 初始化指数部分偏移量
    ui16Exp = 16896;
    //!< 保存符号位
    if (A < 0)
    {
        ui16Exp |= 0x8000;
        uiq31Input = (LQ_UI_32BIT)(-(LQ_I_64BIT)A);
    }
    else if (A == 0)
    {
        return (0);
    }
    else
    {
        uiq31Input = A;
    }
    LQ_TI_Q2F_NORMALIZE(uiq31Input, ui16Exp);
    /*对uiq31结果进行四舍五入并切换到uiq23*/
    uiq23Result = (LQ_UI_32BIT)(((LQ_UI_64BIT)uiq31Input + 0x0080u) >> 8);
    if (uiq23Result >= 0x01000000u)
    {
        uiq23Result = 0;
        ui16Exp += 0x0080;
    }
    /*删除尾数的隐含MSB位 */
    uiq23Result &= ~0x00800000;
    /*
    *将构造的指数和符号位添加到尾数。我们必须使用
    *四舍五入会导致尾数溢出的情况下的加法。
    *当这种情况发生时，尾数结果为2，其中MSB为零
    *exp的LSB被设置为1。在指数上加一就是
    *尾数为2的正确处理。不需要缩放
    *尾数，因为在这种情况下它总是等于零。
   */
    uiq23Result += (LQ_UI_32BIT)ui16Exp << 16;
    return LQ_TI_UINT32_BITS_TO_FLOAT(uiq23Result);
}
/**@brief (TI方法)UINT32类型UQ25格式转浮点
* @details 采用估算位+指数位+符号位三位结合，能提高精度
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为浮点数
* @code*    LQ_TI_UINT32_UQ25_TO_FLOAT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_UINT32_UQ32_TO_FLOAT  TI方式UINT32的UQ32转化浮点类型\n
*     LQ_TI_UINT32_UQ31_TO_FLOAT  TI方式UINT32的UQ31转化浮点类型\n
*     LQ_TI_UINT32_UQ30_TO_FLOAT  TI方式UINT32的UQ30转化浮点类型\n
*     LQ_TI_UINT32_UQ29_TO_FLOAT  TI方式UINT32的UQ29转化浮点类型\n
*     LQ_TI_UINT32_UQ28_TO_FLOAT  TI方式UINT32的UQ28转化浮点类型\n
*     LQ_TI_UINT32_UQ27_TO_FLOAT  TI方式UINT32的UQ27转化浮点类型\n
*     LQ_TI_UINT32_UQ26_TO_FLOAT  TI方式UINT32的UQ26转化浮点类型\n
*     LQ_TI_UINT32_UQ25_TO_FLOAT  TI方式UINT32的UQ25转化浮点类型\n
*     LQ_TI_UINT32_UQ24_TO_FLOAT  TI方式UINT32的UQ24转化浮点类型\n
*     LQ_TI_UINT32_UQ23_TO_FLOAT  TI方式UINT32的UQ23转化浮点类型\n
*     LQ_TI_UINT32_UQ22_TO_FLOAT  TI方式UINT32的UQ22转化浮点类型\n
*     LQ_TI_UINT32_UQ21_TO_FLOAT  TI方式UINT32的UQ21转化浮点类型\n
*     LQ_TI_UINT32_UQ20_TO_FLOAT  TI方式UINT32的UQ20转化浮点类型\n
*     LQ_TI_UINT32_UQ19_TO_FLOAT  TI方式UINT32的UQ19转化浮点类型\n
*     LQ_TI_UINT32_UQ18_TO_FLOAT  TI方式UINT32的UQ18转化浮点类型\n
*     LQ_TI_UINT32_UQ17_TO_FLOAT  TI方式UINT32的UQ17转化浮点类型\n
*     LQ_TI_UINT32_UQ16_TO_FLOAT  TI方式UINT32的UQ16转化浮点类型\n
*     LQ_TI_UINT32_UQ15_TO_FLOAT  TI方式UINT32的UQ15转化浮点类型\n
*     LQ_TI_UINT32_UQ14_TO_FLOAT  TI方式UINT32的UQ14转化浮点类型\n
*     LQ_TI_UINT32_UQ13_TO_FLOAT  TI方式UINT32的UQ13转化浮点类型\n
*     LQ_TI_UINT32_UQ12_TO_FLOAT  TI方式UINT32的UQ12转化浮点类型\n
*     LQ_TI_UINT32_UQ11_TO_FLOAT  TI方式UINT32的UQ11转化浮点类型\n
*     LQ_TI_UINT32_UQ10_TO_FLOAT  TI方式UINT32的UQ10转化浮点类型\n
*     LQ_TI_UINT32_UQ9_TO_FLOAT  TI方式UINT32的UQ9转化浮点类型\n
*     LQ_TI_UINT32_UQ8_TO_FLOAT  TI方式UINT32的UQ8转化浮点类型\n
*     LQ_TI_UINT32_UQ7_TO_FLOAT  TI方式UINT32的UQ7转化浮点类型\n
*     LQ_TI_UINT32_UQ6_TO_FLOAT  TI方式UINT32的UQ6转化浮点类型\n
*     LQ_TI_UINT32_UQ5_TO_FLOAT  TI方式UINT32的UQ5转化浮点类型\n
*     LQ_TI_UINT32_UQ4_TO_FLOAT  TI方式UINT32的UQ4转化浮点类型\n
*     LQ_TI_UINT32_UQ3_TO_FLOAT  TI方式UINT32的UQ3转化浮点类型\n
*     LQ_TI_UINT32_UQ2_TO_FLOAT  TI方式UINT32的UQ2转化浮点类型\n
*     LQ_TI_UINT32_UQ1_TO_FLOAT  TI方式UINT32的UQ1转化浮点类型\n
*/
LQ_F_32BIT LQ_TI_UINT32_UQ25_TO_FLOAT(LQ_I_32BIT A, LQ_ERROR* lq_error)
{
    LQ_UI_16BIT ui16Exp;
    LQ_UI_32BIT uiq23Result;
    LQ_UI_32BIT uiq31Input;
    //!< 初始化指数部分偏移量
    ui16Exp = 17024;
    //!< 保存符号位
    if (A < 0)
    {
        ui16Exp |= 0x8000;
        uiq31Input = (LQ_UI_32BIT)(-(LQ_I_64BIT)A);
    }
    else if (A == 0)
    {
        return (0);
    }
    else
    {
        uiq31Input = A;
    }
    LQ_TI_Q2F_NORMALIZE(uiq31Input, ui16Exp);
    /*对uiq31结果进行四舍五入并切换到uiq23*/
    uiq23Result = (LQ_UI_32BIT)(((LQ_UI_64BIT)uiq31Input + 0x0080u) >> 8);
    if (uiq23Result >= 0x01000000u)
    {
        uiq23Result = 0;
        ui16Exp += 0x0080;
    }
    /*删除尾数的隐含MSB位 */
    uiq23Result &= ~0x00800000;
    /*
    *将构造的指数和符号位添加到尾数。我们必须使用
    *四舍五入会导致尾数溢出的情况下的加法。
    *当这种情况发生时，尾数结果为2，其中MSB为零
    *exp的LSB被设置为1。在指数上加一就是
    *尾数为2的正确处理。不需要缩放
    *尾数，因为在这种情况下它总是等于零。
   */
    uiq23Result += (LQ_UI_32BIT)ui16Exp << 16;
    return LQ_TI_UINT32_BITS_TO_FLOAT(uiq23Result);
}
/**@brief (TI方法)UINT32类型UQ24格式转浮点
* @details 采用估算位+指数位+符号位三位结合，能提高精度
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为浮点数
* @code*    LQ_TI_UINT32_UQ24_TO_FLOAT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_UINT32_UQ32_TO_FLOAT  TI方式UINT32的UQ32转化浮点类型\n
*     LQ_TI_UINT32_UQ31_TO_FLOAT  TI方式UINT32的UQ31转化浮点类型\n
*     LQ_TI_UINT32_UQ30_TO_FLOAT  TI方式UINT32的UQ30转化浮点类型\n
*     LQ_TI_UINT32_UQ29_TO_FLOAT  TI方式UINT32的UQ29转化浮点类型\n
*     LQ_TI_UINT32_UQ28_TO_FLOAT  TI方式UINT32的UQ28转化浮点类型\n
*     LQ_TI_UINT32_UQ27_TO_FLOAT  TI方式UINT32的UQ27转化浮点类型\n
*     LQ_TI_UINT32_UQ26_TO_FLOAT  TI方式UINT32的UQ26转化浮点类型\n
*     LQ_TI_UINT32_UQ25_TO_FLOAT  TI方式UINT32的UQ25转化浮点类型\n
*     LQ_TI_UINT32_UQ24_TO_FLOAT  TI方式UINT32的UQ24转化浮点类型\n
*     LQ_TI_UINT32_UQ23_TO_FLOAT  TI方式UINT32的UQ23转化浮点类型\n
*     LQ_TI_UINT32_UQ22_TO_FLOAT  TI方式UINT32的UQ22转化浮点类型\n
*     LQ_TI_UINT32_UQ21_TO_FLOAT  TI方式UINT32的UQ21转化浮点类型\n
*     LQ_TI_UINT32_UQ20_TO_FLOAT  TI方式UINT32的UQ20转化浮点类型\n
*     LQ_TI_UINT32_UQ19_TO_FLOAT  TI方式UINT32的UQ19转化浮点类型\n
*     LQ_TI_UINT32_UQ18_TO_FLOAT  TI方式UINT32的UQ18转化浮点类型\n
*     LQ_TI_UINT32_UQ17_TO_FLOAT  TI方式UINT32的UQ17转化浮点类型\n
*     LQ_TI_UINT32_UQ16_TO_FLOAT  TI方式UINT32的UQ16转化浮点类型\n
*     LQ_TI_UINT32_UQ15_TO_FLOAT  TI方式UINT32的UQ15转化浮点类型\n
*     LQ_TI_UINT32_UQ14_TO_FLOAT  TI方式UINT32的UQ14转化浮点类型\n
*     LQ_TI_UINT32_UQ13_TO_FLOAT  TI方式UINT32的UQ13转化浮点类型\n
*     LQ_TI_UINT32_UQ12_TO_FLOAT  TI方式UINT32的UQ12转化浮点类型\n
*     LQ_TI_UINT32_UQ11_TO_FLOAT  TI方式UINT32的UQ11转化浮点类型\n
*     LQ_TI_UINT32_UQ10_TO_FLOAT  TI方式UINT32的UQ10转化浮点类型\n
*     LQ_TI_UINT32_UQ9_TO_FLOAT  TI方式UINT32的UQ9转化浮点类型\n
*     LQ_TI_UINT32_UQ8_TO_FLOAT  TI方式UINT32的UQ8转化浮点类型\n
*     LQ_TI_UINT32_UQ7_TO_FLOAT  TI方式UINT32的UQ7转化浮点类型\n
*     LQ_TI_UINT32_UQ6_TO_FLOAT  TI方式UINT32的UQ6转化浮点类型\n
*     LQ_TI_UINT32_UQ5_TO_FLOAT  TI方式UINT32的UQ5转化浮点类型\n
*     LQ_TI_UINT32_UQ4_TO_FLOAT  TI方式UINT32的UQ4转化浮点类型\n
*     LQ_TI_UINT32_UQ3_TO_FLOAT  TI方式UINT32的UQ3转化浮点类型\n
*     LQ_TI_UINT32_UQ2_TO_FLOAT  TI方式UINT32的UQ2转化浮点类型\n
*     LQ_TI_UINT32_UQ1_TO_FLOAT  TI方式UINT32的UQ1转化浮点类型\n
*/
LQ_F_32BIT LQ_TI_UINT32_UQ24_TO_FLOAT(LQ_I_32BIT A, LQ_ERROR* lq_error)
{
    LQ_UI_16BIT ui16Exp;
    LQ_UI_32BIT uiq23Result;
    LQ_UI_32BIT uiq31Input;
    //!< 初始化指数部分偏移量
    ui16Exp = 17152;
    //!< 保存符号位
    if (A < 0)
    {
        ui16Exp |= 0x8000;
        uiq31Input = (LQ_UI_32BIT)(-(LQ_I_64BIT)A);
    }
    else if (A == 0)
    {
        return (0);
    }
    else
    {
        uiq31Input = A;
    }
    LQ_TI_Q2F_NORMALIZE(uiq31Input, ui16Exp);
    /*对uiq31结果进行四舍五入并切换到uiq23*/
    uiq23Result = (LQ_UI_32BIT)(((LQ_UI_64BIT)uiq31Input + 0x0080u) >> 8);
    if (uiq23Result >= 0x01000000u)
    {
        uiq23Result = 0;
        ui16Exp += 0x0080;
    }
    /*删除尾数的隐含MSB位 */
    uiq23Result &= ~0x00800000;
    /*
    *将构造的指数和符号位添加到尾数。我们必须使用
    *四舍五入会导致尾数溢出的情况下的加法。
    *当这种情况发生时，尾数结果为2，其中MSB为零
    *exp的LSB被设置为1。在指数上加一就是
    *尾数为2的正确处理。不需要缩放
    *尾数，因为在这种情况下它总是等于零。
   */
    uiq23Result += (LQ_UI_32BIT)ui16Exp << 16;
    return LQ_TI_UINT32_BITS_TO_FLOAT(uiq23Result);
}
/**@brief (TI方法)UINT32类型UQ23格式转浮点
* @details 采用估算位+指数位+符号位三位结合，能提高精度
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为浮点数
* @code*    LQ_TI_UINT32_UQ23_TO_FLOAT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_UINT32_UQ32_TO_FLOAT  TI方式UINT32的UQ32转化浮点类型\n
*     LQ_TI_UINT32_UQ31_TO_FLOAT  TI方式UINT32的UQ31转化浮点类型\n
*     LQ_TI_UINT32_UQ30_TO_FLOAT  TI方式UINT32的UQ30转化浮点类型\n
*     LQ_TI_UINT32_UQ29_TO_FLOAT  TI方式UINT32的UQ29转化浮点类型\n
*     LQ_TI_UINT32_UQ28_TO_FLOAT  TI方式UINT32的UQ28转化浮点类型\n
*     LQ_TI_UINT32_UQ27_TO_FLOAT  TI方式UINT32的UQ27转化浮点类型\n
*     LQ_TI_UINT32_UQ26_TO_FLOAT  TI方式UINT32的UQ26转化浮点类型\n
*     LQ_TI_UINT32_UQ25_TO_FLOAT  TI方式UINT32的UQ25转化浮点类型\n
*     LQ_TI_UINT32_UQ24_TO_FLOAT  TI方式UINT32的UQ24转化浮点类型\n
*     LQ_TI_UINT32_UQ23_TO_FLOAT  TI方式UINT32的UQ23转化浮点类型\n
*     LQ_TI_UINT32_UQ22_TO_FLOAT  TI方式UINT32的UQ22转化浮点类型\n
*     LQ_TI_UINT32_UQ21_TO_FLOAT  TI方式UINT32的UQ21转化浮点类型\n
*     LQ_TI_UINT32_UQ20_TO_FLOAT  TI方式UINT32的UQ20转化浮点类型\n
*     LQ_TI_UINT32_UQ19_TO_FLOAT  TI方式UINT32的UQ19转化浮点类型\n
*     LQ_TI_UINT32_UQ18_TO_FLOAT  TI方式UINT32的UQ18转化浮点类型\n
*     LQ_TI_UINT32_UQ17_TO_FLOAT  TI方式UINT32的UQ17转化浮点类型\n
*     LQ_TI_UINT32_UQ16_TO_FLOAT  TI方式UINT32的UQ16转化浮点类型\n
*     LQ_TI_UINT32_UQ15_TO_FLOAT  TI方式UINT32的UQ15转化浮点类型\n
*     LQ_TI_UINT32_UQ14_TO_FLOAT  TI方式UINT32的UQ14转化浮点类型\n
*     LQ_TI_UINT32_UQ13_TO_FLOAT  TI方式UINT32的UQ13转化浮点类型\n
*     LQ_TI_UINT32_UQ12_TO_FLOAT  TI方式UINT32的UQ12转化浮点类型\n
*     LQ_TI_UINT32_UQ11_TO_FLOAT  TI方式UINT32的UQ11转化浮点类型\n
*     LQ_TI_UINT32_UQ10_TO_FLOAT  TI方式UINT32的UQ10转化浮点类型\n
*     LQ_TI_UINT32_UQ9_TO_FLOAT  TI方式UINT32的UQ9转化浮点类型\n
*     LQ_TI_UINT32_UQ8_TO_FLOAT  TI方式UINT32的UQ8转化浮点类型\n
*     LQ_TI_UINT32_UQ7_TO_FLOAT  TI方式UINT32的UQ7转化浮点类型\n
*     LQ_TI_UINT32_UQ6_TO_FLOAT  TI方式UINT32的UQ6转化浮点类型\n
*     LQ_TI_UINT32_UQ5_TO_FLOAT  TI方式UINT32的UQ5转化浮点类型\n
*     LQ_TI_UINT32_UQ4_TO_FLOAT  TI方式UINT32的UQ4转化浮点类型\n
*     LQ_TI_UINT32_UQ3_TO_FLOAT  TI方式UINT32的UQ3转化浮点类型\n
*     LQ_TI_UINT32_UQ2_TO_FLOAT  TI方式UINT32的UQ2转化浮点类型\n
*     LQ_TI_UINT32_UQ1_TO_FLOAT  TI方式UINT32的UQ1转化浮点类型\n
*/
LQ_F_32BIT LQ_TI_UINT32_UQ23_TO_FLOAT(LQ_I_32BIT A, LQ_ERROR* lq_error)
{
    LQ_UI_16BIT ui16Exp;
    LQ_UI_32BIT uiq23Result;
    LQ_UI_32BIT uiq31Input;
    //!< 初始化指数部分偏移量
    ui16Exp = 17280;
    //!< 保存符号位
    if (A < 0)
    {
        ui16Exp |= 0x8000;
        uiq31Input = (LQ_UI_32BIT)(-(LQ_I_64BIT)A);
    }
    else if (A == 0)
    {
        return (0);
    }
    else
    {
        uiq31Input = A;
    }
    LQ_TI_Q2F_NORMALIZE(uiq31Input, ui16Exp);
    /*对uiq31结果进行四舍五入并切换到uiq23*/
    uiq23Result = (LQ_UI_32BIT)(((LQ_UI_64BIT)uiq31Input + 0x0080u) >> 8);
    if (uiq23Result >= 0x01000000u)
    {
        uiq23Result = 0;
        ui16Exp += 0x0080;
    }
    /*删除尾数的隐含MSB位 */
    uiq23Result &= ~0x00800000;
    /*
    *将构造的指数和符号位添加到尾数。我们必须使用
    *四舍五入会导致尾数溢出的情况下的加法。
    *当这种情况发生时，尾数结果为2，其中MSB为零
    *exp的LSB被设置为1。在指数上加一就是
    *尾数为2的正确处理。不需要缩放
    *尾数，因为在这种情况下它总是等于零。
   */
    uiq23Result += (LQ_UI_32BIT)ui16Exp << 16;
    return LQ_TI_UINT32_BITS_TO_FLOAT(uiq23Result);
}
/**@brief (TI方法)UINT32类型UQ22格式转浮点
* @details 采用估算位+指数位+符号位三位结合，能提高精度
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为浮点数
* @code*    LQ_TI_UINT32_UQ22_TO_FLOAT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_UINT32_UQ32_TO_FLOAT  TI方式UINT32的UQ32转化浮点类型\n
*     LQ_TI_UINT32_UQ31_TO_FLOAT  TI方式UINT32的UQ31转化浮点类型\n
*     LQ_TI_UINT32_UQ30_TO_FLOAT  TI方式UINT32的UQ30转化浮点类型\n
*     LQ_TI_UINT32_UQ29_TO_FLOAT  TI方式UINT32的UQ29转化浮点类型\n
*     LQ_TI_UINT32_UQ28_TO_FLOAT  TI方式UINT32的UQ28转化浮点类型\n
*     LQ_TI_UINT32_UQ27_TO_FLOAT  TI方式UINT32的UQ27转化浮点类型\n
*     LQ_TI_UINT32_UQ26_TO_FLOAT  TI方式UINT32的UQ26转化浮点类型\n
*     LQ_TI_UINT32_UQ25_TO_FLOAT  TI方式UINT32的UQ25转化浮点类型\n
*     LQ_TI_UINT32_UQ24_TO_FLOAT  TI方式UINT32的UQ24转化浮点类型\n
*     LQ_TI_UINT32_UQ23_TO_FLOAT  TI方式UINT32的UQ23转化浮点类型\n
*     LQ_TI_UINT32_UQ22_TO_FLOAT  TI方式UINT32的UQ22转化浮点类型\n
*     LQ_TI_UINT32_UQ21_TO_FLOAT  TI方式UINT32的UQ21转化浮点类型\n
*     LQ_TI_UINT32_UQ20_TO_FLOAT  TI方式UINT32的UQ20转化浮点类型\n
*     LQ_TI_UINT32_UQ19_TO_FLOAT  TI方式UINT32的UQ19转化浮点类型\n
*     LQ_TI_UINT32_UQ18_TO_FLOAT  TI方式UINT32的UQ18转化浮点类型\n
*     LQ_TI_UINT32_UQ17_TO_FLOAT  TI方式UINT32的UQ17转化浮点类型\n
*     LQ_TI_UINT32_UQ16_TO_FLOAT  TI方式UINT32的UQ16转化浮点类型\n
*     LQ_TI_UINT32_UQ15_TO_FLOAT  TI方式UINT32的UQ15转化浮点类型\n
*     LQ_TI_UINT32_UQ14_TO_FLOAT  TI方式UINT32的UQ14转化浮点类型\n
*     LQ_TI_UINT32_UQ13_TO_FLOAT  TI方式UINT32的UQ13转化浮点类型\n
*     LQ_TI_UINT32_UQ12_TO_FLOAT  TI方式UINT32的UQ12转化浮点类型\n
*     LQ_TI_UINT32_UQ11_TO_FLOAT  TI方式UINT32的UQ11转化浮点类型\n
*     LQ_TI_UINT32_UQ10_TO_FLOAT  TI方式UINT32的UQ10转化浮点类型\n
*     LQ_TI_UINT32_UQ9_TO_FLOAT  TI方式UINT32的UQ9转化浮点类型\n
*     LQ_TI_UINT32_UQ8_TO_FLOAT  TI方式UINT32的UQ8转化浮点类型\n
*     LQ_TI_UINT32_UQ7_TO_FLOAT  TI方式UINT32的UQ7转化浮点类型\n
*     LQ_TI_UINT32_UQ6_TO_FLOAT  TI方式UINT32的UQ6转化浮点类型\n
*     LQ_TI_UINT32_UQ5_TO_FLOAT  TI方式UINT32的UQ5转化浮点类型\n
*     LQ_TI_UINT32_UQ4_TO_FLOAT  TI方式UINT32的UQ4转化浮点类型\n
*     LQ_TI_UINT32_UQ3_TO_FLOAT  TI方式UINT32的UQ3转化浮点类型\n
*     LQ_TI_UINT32_UQ2_TO_FLOAT  TI方式UINT32的UQ2转化浮点类型\n
*     LQ_TI_UINT32_UQ1_TO_FLOAT  TI方式UINT32的UQ1转化浮点类型\n
*/
LQ_F_32BIT LQ_TI_UINT32_UQ22_TO_FLOAT(LQ_I_32BIT A, LQ_ERROR* lq_error)
{
    LQ_UI_16BIT ui16Exp;
    LQ_UI_32BIT uiq23Result;
    LQ_UI_32BIT uiq31Input;
    //!< 初始化指数部分偏移量
    ui16Exp = 17408;
    //!< 保存符号位
    if (A < 0)
    {
        ui16Exp |= 0x8000;
        uiq31Input = (LQ_UI_32BIT)(-(LQ_I_64BIT)A);
    }
    else if (A == 0)
    {
        return (0);
    }
    else
    {
        uiq31Input = A;
    }
    LQ_TI_Q2F_NORMALIZE(uiq31Input, ui16Exp);
    /*对uiq31结果进行四舍五入并切换到uiq23*/
    uiq23Result = (LQ_UI_32BIT)(((LQ_UI_64BIT)uiq31Input + 0x0080u) >> 8);
    if (uiq23Result >= 0x01000000u)
    {
        uiq23Result = 0;
        ui16Exp += 0x0080;
    }
    /*删除尾数的隐含MSB位 */
    uiq23Result &= ~0x00800000;
    /*
    *将构造的指数和符号位添加到尾数。我们必须使用
    *四舍五入会导致尾数溢出的情况下的加法。
    *当这种情况发生时，尾数结果为2，其中MSB为零
    *exp的LSB被设置为1。在指数上加一就是
    *尾数为2的正确处理。不需要缩放
    *尾数，因为在这种情况下它总是等于零。
   */
    uiq23Result += (LQ_UI_32BIT)ui16Exp << 16;
    return LQ_TI_UINT32_BITS_TO_FLOAT(uiq23Result);
}
/**@brief (TI方法)UINT32类型UQ21格式转浮点
* @details 采用估算位+指数位+符号位三位结合，能提高精度
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为浮点数
* @code*    LQ_TI_UINT32_UQ21_TO_FLOAT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_UINT32_UQ32_TO_FLOAT  TI方式UINT32的UQ32转化浮点类型\n
*     LQ_TI_UINT32_UQ31_TO_FLOAT  TI方式UINT32的UQ31转化浮点类型\n
*     LQ_TI_UINT32_UQ30_TO_FLOAT  TI方式UINT32的UQ30转化浮点类型\n
*     LQ_TI_UINT32_UQ29_TO_FLOAT  TI方式UINT32的UQ29转化浮点类型\n
*     LQ_TI_UINT32_UQ28_TO_FLOAT  TI方式UINT32的UQ28转化浮点类型\n
*     LQ_TI_UINT32_UQ27_TO_FLOAT  TI方式UINT32的UQ27转化浮点类型\n
*     LQ_TI_UINT32_UQ26_TO_FLOAT  TI方式UINT32的UQ26转化浮点类型\n
*     LQ_TI_UINT32_UQ25_TO_FLOAT  TI方式UINT32的UQ25转化浮点类型\n
*     LQ_TI_UINT32_UQ24_TO_FLOAT  TI方式UINT32的UQ24转化浮点类型\n
*     LQ_TI_UINT32_UQ23_TO_FLOAT  TI方式UINT32的UQ23转化浮点类型\n
*     LQ_TI_UINT32_UQ22_TO_FLOAT  TI方式UINT32的UQ22转化浮点类型\n
*     LQ_TI_UINT32_UQ21_TO_FLOAT  TI方式UINT32的UQ21转化浮点类型\n
*     LQ_TI_UINT32_UQ20_TO_FLOAT  TI方式UINT32的UQ20转化浮点类型\n
*     LQ_TI_UINT32_UQ19_TO_FLOAT  TI方式UINT32的UQ19转化浮点类型\n
*     LQ_TI_UINT32_UQ18_TO_FLOAT  TI方式UINT32的UQ18转化浮点类型\n
*     LQ_TI_UINT32_UQ17_TO_FLOAT  TI方式UINT32的UQ17转化浮点类型\n
*     LQ_TI_UINT32_UQ16_TO_FLOAT  TI方式UINT32的UQ16转化浮点类型\n
*     LQ_TI_UINT32_UQ15_TO_FLOAT  TI方式UINT32的UQ15转化浮点类型\n
*     LQ_TI_UINT32_UQ14_TO_FLOAT  TI方式UINT32的UQ14转化浮点类型\n
*     LQ_TI_UINT32_UQ13_TO_FLOAT  TI方式UINT32的UQ13转化浮点类型\n
*     LQ_TI_UINT32_UQ12_TO_FLOAT  TI方式UINT32的UQ12转化浮点类型\n
*     LQ_TI_UINT32_UQ11_TO_FLOAT  TI方式UINT32的UQ11转化浮点类型\n
*     LQ_TI_UINT32_UQ10_TO_FLOAT  TI方式UINT32的UQ10转化浮点类型\n
*     LQ_TI_UINT32_UQ9_TO_FLOAT  TI方式UINT32的UQ9转化浮点类型\n
*     LQ_TI_UINT32_UQ8_TO_FLOAT  TI方式UINT32的UQ8转化浮点类型\n
*     LQ_TI_UINT32_UQ7_TO_FLOAT  TI方式UINT32的UQ7转化浮点类型\n
*     LQ_TI_UINT32_UQ6_TO_FLOAT  TI方式UINT32的UQ6转化浮点类型\n
*     LQ_TI_UINT32_UQ5_TO_FLOAT  TI方式UINT32的UQ5转化浮点类型\n
*     LQ_TI_UINT32_UQ4_TO_FLOAT  TI方式UINT32的UQ4转化浮点类型\n
*     LQ_TI_UINT32_UQ3_TO_FLOAT  TI方式UINT32的UQ3转化浮点类型\n
*     LQ_TI_UINT32_UQ2_TO_FLOAT  TI方式UINT32的UQ2转化浮点类型\n
*     LQ_TI_UINT32_UQ1_TO_FLOAT  TI方式UINT32的UQ1转化浮点类型\n
*/
LQ_F_32BIT LQ_TI_UINT32_UQ21_TO_FLOAT(LQ_I_32BIT A, LQ_ERROR* lq_error)
{
    LQ_UI_16BIT ui16Exp;
    LQ_UI_32BIT uiq23Result;
    LQ_UI_32BIT uiq31Input;
    //!< 初始化指数部分偏移量
    ui16Exp = 17536;
    //!< 保存符号位
    if (A < 0)
    {
        ui16Exp |= 0x8000;
        uiq31Input = (LQ_UI_32BIT)(-(LQ_I_64BIT)A);
    }
    else if (A == 0)
    {
        return (0);
    }
    else
    {
        uiq31Input = A;
    }
    LQ_TI_Q2F_NORMALIZE(uiq31Input, ui16Exp);
    /*对uiq31结果进行四舍五入并切换到uiq23*/
    uiq23Result = (LQ_UI_32BIT)(((LQ_UI_64BIT)uiq31Input + 0x0080u) >> 8);
    if (uiq23Result >= 0x01000000u)
    {
        uiq23Result = 0;
        ui16Exp += 0x0080;
    }
    /*删除尾数的隐含MSB位 */
    uiq23Result &= ~0x00800000;
    /*
    *将构造的指数和符号位添加到尾数。我们必须使用
    *四舍五入会导致尾数溢出的情况下的加法。
    *当这种情况发生时，尾数结果为2，其中MSB为零
    *exp的LSB被设置为1。在指数上加一就是
    *尾数为2的正确处理。不需要缩放
    *尾数，因为在这种情况下它总是等于零。
   */
    uiq23Result += (LQ_UI_32BIT)ui16Exp << 16;
    return LQ_TI_UINT32_BITS_TO_FLOAT(uiq23Result);
}
/**@brief (TI方法)UINT32类型UQ20格式转浮点
* @details 采用估算位+指数位+符号位三位结合，能提高精度
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为浮点数
* @code*    LQ_TI_UINT32_UQ20_TO_FLOAT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_UINT32_UQ32_TO_FLOAT  TI方式UINT32的UQ32转化浮点类型\n
*     LQ_TI_UINT32_UQ31_TO_FLOAT  TI方式UINT32的UQ31转化浮点类型\n
*     LQ_TI_UINT32_UQ30_TO_FLOAT  TI方式UINT32的UQ30转化浮点类型\n
*     LQ_TI_UINT32_UQ29_TO_FLOAT  TI方式UINT32的UQ29转化浮点类型\n
*     LQ_TI_UINT32_UQ28_TO_FLOAT  TI方式UINT32的UQ28转化浮点类型\n
*     LQ_TI_UINT32_UQ27_TO_FLOAT  TI方式UINT32的UQ27转化浮点类型\n
*     LQ_TI_UINT32_UQ26_TO_FLOAT  TI方式UINT32的UQ26转化浮点类型\n
*     LQ_TI_UINT32_UQ25_TO_FLOAT  TI方式UINT32的UQ25转化浮点类型\n
*     LQ_TI_UINT32_UQ24_TO_FLOAT  TI方式UINT32的UQ24转化浮点类型\n
*     LQ_TI_UINT32_UQ23_TO_FLOAT  TI方式UINT32的UQ23转化浮点类型\n
*     LQ_TI_UINT32_UQ22_TO_FLOAT  TI方式UINT32的UQ22转化浮点类型\n
*     LQ_TI_UINT32_UQ21_TO_FLOAT  TI方式UINT32的UQ21转化浮点类型\n
*     LQ_TI_UINT32_UQ20_TO_FLOAT  TI方式UINT32的UQ20转化浮点类型\n
*     LQ_TI_UINT32_UQ19_TO_FLOAT  TI方式UINT32的UQ19转化浮点类型\n
*     LQ_TI_UINT32_UQ18_TO_FLOAT  TI方式UINT32的UQ18转化浮点类型\n
*     LQ_TI_UINT32_UQ17_TO_FLOAT  TI方式UINT32的UQ17转化浮点类型\n
*     LQ_TI_UINT32_UQ16_TO_FLOAT  TI方式UINT32的UQ16转化浮点类型\n
*     LQ_TI_UINT32_UQ15_TO_FLOAT  TI方式UINT32的UQ15转化浮点类型\n
*     LQ_TI_UINT32_UQ14_TO_FLOAT  TI方式UINT32的UQ14转化浮点类型\n
*     LQ_TI_UINT32_UQ13_TO_FLOAT  TI方式UINT32的UQ13转化浮点类型\n
*     LQ_TI_UINT32_UQ12_TO_FLOAT  TI方式UINT32的UQ12转化浮点类型\n
*     LQ_TI_UINT32_UQ11_TO_FLOAT  TI方式UINT32的UQ11转化浮点类型\n
*     LQ_TI_UINT32_UQ10_TO_FLOAT  TI方式UINT32的UQ10转化浮点类型\n
*     LQ_TI_UINT32_UQ9_TO_FLOAT  TI方式UINT32的UQ9转化浮点类型\n
*     LQ_TI_UINT32_UQ8_TO_FLOAT  TI方式UINT32的UQ8转化浮点类型\n
*     LQ_TI_UINT32_UQ7_TO_FLOAT  TI方式UINT32的UQ7转化浮点类型\n
*     LQ_TI_UINT32_UQ6_TO_FLOAT  TI方式UINT32的UQ6转化浮点类型\n
*     LQ_TI_UINT32_UQ5_TO_FLOAT  TI方式UINT32的UQ5转化浮点类型\n
*     LQ_TI_UINT32_UQ4_TO_FLOAT  TI方式UINT32的UQ4转化浮点类型\n
*     LQ_TI_UINT32_UQ3_TO_FLOAT  TI方式UINT32的UQ3转化浮点类型\n
*     LQ_TI_UINT32_UQ2_TO_FLOAT  TI方式UINT32的UQ2转化浮点类型\n
*     LQ_TI_UINT32_UQ1_TO_FLOAT  TI方式UINT32的UQ1转化浮点类型\n
*/
LQ_F_32BIT LQ_TI_UINT32_UQ20_TO_FLOAT(LQ_I_32BIT A, LQ_ERROR* lq_error)
{
    LQ_UI_16BIT ui16Exp;
    LQ_UI_32BIT uiq23Result;
    LQ_UI_32BIT uiq31Input;
    //!< 初始化指数部分偏移量
    ui16Exp = 17664;
    //!< 保存符号位
    if (A < 0)
    {
        ui16Exp |= 0x8000;
        uiq31Input = (LQ_UI_32BIT)(-(LQ_I_64BIT)A);
    }
    else if (A == 0)
    {
        return (0);
    }
    else
    {
        uiq31Input = A;
    }
    LQ_TI_Q2F_NORMALIZE(uiq31Input, ui16Exp);
    /*对uiq31结果进行四舍五入并切换到uiq23*/
    uiq23Result = (LQ_UI_32BIT)(((LQ_UI_64BIT)uiq31Input + 0x0080u) >> 8);
    if (uiq23Result >= 0x01000000u)
    {
        uiq23Result = 0;
        ui16Exp += 0x0080;
    }
    /*删除尾数的隐含MSB位 */
    uiq23Result &= ~0x00800000;
    /*
    *将构造的指数和符号位添加到尾数。我们必须使用
    *四舍五入会导致尾数溢出的情况下的加法。
    *当这种情况发生时，尾数结果为2，其中MSB为零
    *exp的LSB被设置为1。在指数上加一就是
    *尾数为2的正确处理。不需要缩放
    *尾数，因为在这种情况下它总是等于零。
   */
    uiq23Result += (LQ_UI_32BIT)ui16Exp << 16;
    return LQ_TI_UINT32_BITS_TO_FLOAT(uiq23Result);
}
/**@brief (TI方法)UINT32类型UQ19格式转浮点
* @details 采用估算位+指数位+符号位三位结合，能提高精度
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为浮点数
* @code*    LQ_TI_UINT32_UQ19_TO_FLOAT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_UINT32_UQ32_TO_FLOAT  TI方式UINT32的UQ32转化浮点类型\n
*     LQ_TI_UINT32_UQ31_TO_FLOAT  TI方式UINT32的UQ31转化浮点类型\n
*     LQ_TI_UINT32_UQ30_TO_FLOAT  TI方式UINT32的UQ30转化浮点类型\n
*     LQ_TI_UINT32_UQ29_TO_FLOAT  TI方式UINT32的UQ29转化浮点类型\n
*     LQ_TI_UINT32_UQ28_TO_FLOAT  TI方式UINT32的UQ28转化浮点类型\n
*     LQ_TI_UINT32_UQ27_TO_FLOAT  TI方式UINT32的UQ27转化浮点类型\n
*     LQ_TI_UINT32_UQ26_TO_FLOAT  TI方式UINT32的UQ26转化浮点类型\n
*     LQ_TI_UINT32_UQ25_TO_FLOAT  TI方式UINT32的UQ25转化浮点类型\n
*     LQ_TI_UINT32_UQ24_TO_FLOAT  TI方式UINT32的UQ24转化浮点类型\n
*     LQ_TI_UINT32_UQ23_TO_FLOAT  TI方式UINT32的UQ23转化浮点类型\n
*     LQ_TI_UINT32_UQ22_TO_FLOAT  TI方式UINT32的UQ22转化浮点类型\n
*     LQ_TI_UINT32_UQ21_TO_FLOAT  TI方式UINT32的UQ21转化浮点类型\n
*     LQ_TI_UINT32_UQ20_TO_FLOAT  TI方式UINT32的UQ20转化浮点类型\n
*     LQ_TI_UINT32_UQ19_TO_FLOAT  TI方式UINT32的UQ19转化浮点类型\n
*     LQ_TI_UINT32_UQ18_TO_FLOAT  TI方式UINT32的UQ18转化浮点类型\n
*     LQ_TI_UINT32_UQ17_TO_FLOAT  TI方式UINT32的UQ17转化浮点类型\n
*     LQ_TI_UINT32_UQ16_TO_FLOAT  TI方式UINT32的UQ16转化浮点类型\n
*     LQ_TI_UINT32_UQ15_TO_FLOAT  TI方式UINT32的UQ15转化浮点类型\n
*     LQ_TI_UINT32_UQ14_TO_FLOAT  TI方式UINT32的UQ14转化浮点类型\n
*     LQ_TI_UINT32_UQ13_TO_FLOAT  TI方式UINT32的UQ13转化浮点类型\n
*     LQ_TI_UINT32_UQ12_TO_FLOAT  TI方式UINT32的UQ12转化浮点类型\n
*     LQ_TI_UINT32_UQ11_TO_FLOAT  TI方式UINT32的UQ11转化浮点类型\n
*     LQ_TI_UINT32_UQ10_TO_FLOAT  TI方式UINT32的UQ10转化浮点类型\n
*     LQ_TI_UINT32_UQ9_TO_FLOAT  TI方式UINT32的UQ9转化浮点类型\n
*     LQ_TI_UINT32_UQ8_TO_FLOAT  TI方式UINT32的UQ8转化浮点类型\n
*     LQ_TI_UINT32_UQ7_TO_FLOAT  TI方式UINT32的UQ7转化浮点类型\n
*     LQ_TI_UINT32_UQ6_TO_FLOAT  TI方式UINT32的UQ6转化浮点类型\n
*     LQ_TI_UINT32_UQ5_TO_FLOAT  TI方式UINT32的UQ5转化浮点类型\n
*     LQ_TI_UINT32_UQ4_TO_FLOAT  TI方式UINT32的UQ4转化浮点类型\n
*     LQ_TI_UINT32_UQ3_TO_FLOAT  TI方式UINT32的UQ3转化浮点类型\n
*     LQ_TI_UINT32_UQ2_TO_FLOAT  TI方式UINT32的UQ2转化浮点类型\n
*     LQ_TI_UINT32_UQ1_TO_FLOAT  TI方式UINT32的UQ1转化浮点类型\n
*/
LQ_F_32BIT LQ_TI_UINT32_UQ19_TO_FLOAT(LQ_I_32BIT A, LQ_ERROR* lq_error)
{
    LQ_UI_16BIT ui16Exp;
    LQ_UI_32BIT uiq23Result;
    LQ_UI_32BIT uiq31Input;
    //!< 初始化指数部分偏移量
    ui16Exp = 17792;
    //!< 保存符号位
    if (A < 0)
    {
        ui16Exp |= 0x8000;
        uiq31Input = (LQ_UI_32BIT)(-(LQ_I_64BIT)A);
    }
    else if (A == 0)
    {
        return (0);
    }
    else
    {
        uiq31Input = A;
    }
    LQ_TI_Q2F_NORMALIZE(uiq31Input, ui16Exp);
    /*对uiq31结果进行四舍五入并切换到uiq23*/
    uiq23Result = (LQ_UI_32BIT)(((LQ_UI_64BIT)uiq31Input + 0x0080u) >> 8);
    if (uiq23Result >= 0x01000000u)
    {
        uiq23Result = 0;
        ui16Exp += 0x0080;
    }
    /*删除尾数的隐含MSB位 */
    uiq23Result &= ~0x00800000;
    /*
    *将构造的指数和符号位添加到尾数。我们必须使用
    *四舍五入会导致尾数溢出的情况下的加法。
    *当这种情况发生时，尾数结果为2，其中MSB为零
    *exp的LSB被设置为1。在指数上加一就是
    *尾数为2的正确处理。不需要缩放
    *尾数，因为在这种情况下它总是等于零。
   */
    uiq23Result += (LQ_UI_32BIT)ui16Exp << 16;
    return LQ_TI_UINT32_BITS_TO_FLOAT(uiq23Result);
}
/**@brief (TI方法)UINT32类型UQ18格式转浮点
* @details 采用估算位+指数位+符号位三位结合，能提高精度
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为浮点数
* @code*    LQ_TI_UINT32_UQ18_TO_FLOAT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_UINT32_UQ32_TO_FLOAT  TI方式UINT32的UQ32转化浮点类型\n
*     LQ_TI_UINT32_UQ31_TO_FLOAT  TI方式UINT32的UQ31转化浮点类型\n
*     LQ_TI_UINT32_UQ30_TO_FLOAT  TI方式UINT32的UQ30转化浮点类型\n
*     LQ_TI_UINT32_UQ29_TO_FLOAT  TI方式UINT32的UQ29转化浮点类型\n
*     LQ_TI_UINT32_UQ28_TO_FLOAT  TI方式UINT32的UQ28转化浮点类型\n
*     LQ_TI_UINT32_UQ27_TO_FLOAT  TI方式UINT32的UQ27转化浮点类型\n
*     LQ_TI_UINT32_UQ26_TO_FLOAT  TI方式UINT32的UQ26转化浮点类型\n
*     LQ_TI_UINT32_UQ25_TO_FLOAT  TI方式UINT32的UQ25转化浮点类型\n
*     LQ_TI_UINT32_UQ24_TO_FLOAT  TI方式UINT32的UQ24转化浮点类型\n
*     LQ_TI_UINT32_UQ23_TO_FLOAT  TI方式UINT32的UQ23转化浮点类型\n
*     LQ_TI_UINT32_UQ22_TO_FLOAT  TI方式UINT32的UQ22转化浮点类型\n
*     LQ_TI_UINT32_UQ21_TO_FLOAT  TI方式UINT32的UQ21转化浮点类型\n
*     LQ_TI_UINT32_UQ20_TO_FLOAT  TI方式UINT32的UQ20转化浮点类型\n
*     LQ_TI_UINT32_UQ19_TO_FLOAT  TI方式UINT32的UQ19转化浮点类型\n
*     LQ_TI_UINT32_UQ18_TO_FLOAT  TI方式UINT32的UQ18转化浮点类型\n
*     LQ_TI_UINT32_UQ17_TO_FLOAT  TI方式UINT32的UQ17转化浮点类型\n
*     LQ_TI_UINT32_UQ16_TO_FLOAT  TI方式UINT32的UQ16转化浮点类型\n
*     LQ_TI_UINT32_UQ15_TO_FLOAT  TI方式UINT32的UQ15转化浮点类型\n
*     LQ_TI_UINT32_UQ14_TO_FLOAT  TI方式UINT32的UQ14转化浮点类型\n
*     LQ_TI_UINT32_UQ13_TO_FLOAT  TI方式UINT32的UQ13转化浮点类型\n
*     LQ_TI_UINT32_UQ12_TO_FLOAT  TI方式UINT32的UQ12转化浮点类型\n
*     LQ_TI_UINT32_UQ11_TO_FLOAT  TI方式UINT32的UQ11转化浮点类型\n
*     LQ_TI_UINT32_UQ10_TO_FLOAT  TI方式UINT32的UQ10转化浮点类型\n
*     LQ_TI_UINT32_UQ9_TO_FLOAT  TI方式UINT32的UQ9转化浮点类型\n
*     LQ_TI_UINT32_UQ8_TO_FLOAT  TI方式UINT32的UQ8转化浮点类型\n
*     LQ_TI_UINT32_UQ7_TO_FLOAT  TI方式UINT32的UQ7转化浮点类型\n
*     LQ_TI_UINT32_UQ6_TO_FLOAT  TI方式UINT32的UQ6转化浮点类型\n
*     LQ_TI_UINT32_UQ5_TO_FLOAT  TI方式UINT32的UQ5转化浮点类型\n
*     LQ_TI_UINT32_UQ4_TO_FLOAT  TI方式UINT32的UQ4转化浮点类型\n
*     LQ_TI_UINT32_UQ3_TO_FLOAT  TI方式UINT32的UQ3转化浮点类型\n
*     LQ_TI_UINT32_UQ2_TO_FLOAT  TI方式UINT32的UQ2转化浮点类型\n
*     LQ_TI_UINT32_UQ1_TO_FLOAT  TI方式UINT32的UQ1转化浮点类型\n
*/
LQ_F_32BIT LQ_TI_UINT32_UQ18_TO_FLOAT(LQ_I_32BIT A, LQ_ERROR* lq_error)
{
    LQ_UI_16BIT ui16Exp;
    LQ_UI_32BIT uiq23Result;
    LQ_UI_32BIT uiq31Input;
    //!< 初始化指数部分偏移量
    ui16Exp = 17920;
    //!< 保存符号位
    if (A < 0)
    {
        ui16Exp |= 0x8000;
        uiq31Input = (LQ_UI_32BIT)(-(LQ_I_64BIT)A);
    }
    else if (A == 0)
    {
        return (0);
    }
    else
    {
        uiq31Input = A;
    }
    LQ_TI_Q2F_NORMALIZE(uiq31Input, ui16Exp);
    /*对uiq31结果进行四舍五入并切换到uiq23*/
    uiq23Result = (LQ_UI_32BIT)(((LQ_UI_64BIT)uiq31Input + 0x0080u) >> 8);
    if (uiq23Result >= 0x01000000u)
    {
        uiq23Result = 0;
        ui16Exp += 0x0080;
    }
    /*删除尾数的隐含MSB位 */
    uiq23Result &= ~0x00800000;
    /*
    *将构造的指数和符号位添加到尾数。我们必须使用
    *四舍五入会导致尾数溢出的情况下的加法。
    *当这种情况发生时，尾数结果为2，其中MSB为零
    *exp的LSB被设置为1。在指数上加一就是
    *尾数为2的正确处理。不需要缩放
    *尾数，因为在这种情况下它总是等于零。
   */
    uiq23Result += (LQ_UI_32BIT)ui16Exp << 16;
    return LQ_TI_UINT32_BITS_TO_FLOAT(uiq23Result);
}
/**@brief (TI方法)UINT32类型UQ17格式转浮点
* @details 采用估算位+指数位+符号位三位结合，能提高精度
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为浮点数
* @code*    LQ_TI_UINT32_UQ17_TO_FLOAT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_UINT32_UQ32_TO_FLOAT  TI方式UINT32的UQ32转化浮点类型\n
*     LQ_TI_UINT32_UQ31_TO_FLOAT  TI方式UINT32的UQ31转化浮点类型\n
*     LQ_TI_UINT32_UQ30_TO_FLOAT  TI方式UINT32的UQ30转化浮点类型\n
*     LQ_TI_UINT32_UQ29_TO_FLOAT  TI方式UINT32的UQ29转化浮点类型\n
*     LQ_TI_UINT32_UQ28_TO_FLOAT  TI方式UINT32的UQ28转化浮点类型\n
*     LQ_TI_UINT32_UQ27_TO_FLOAT  TI方式UINT32的UQ27转化浮点类型\n
*     LQ_TI_UINT32_UQ26_TO_FLOAT  TI方式UINT32的UQ26转化浮点类型\n
*     LQ_TI_UINT32_UQ25_TO_FLOAT  TI方式UINT32的UQ25转化浮点类型\n
*     LQ_TI_UINT32_UQ24_TO_FLOAT  TI方式UINT32的UQ24转化浮点类型\n
*     LQ_TI_UINT32_UQ23_TO_FLOAT  TI方式UINT32的UQ23转化浮点类型\n
*     LQ_TI_UINT32_UQ22_TO_FLOAT  TI方式UINT32的UQ22转化浮点类型\n
*     LQ_TI_UINT32_UQ21_TO_FLOAT  TI方式UINT32的UQ21转化浮点类型\n
*     LQ_TI_UINT32_UQ20_TO_FLOAT  TI方式UINT32的UQ20转化浮点类型\n
*     LQ_TI_UINT32_UQ19_TO_FLOAT  TI方式UINT32的UQ19转化浮点类型\n
*     LQ_TI_UINT32_UQ18_TO_FLOAT  TI方式UINT32的UQ18转化浮点类型\n
*     LQ_TI_UINT32_UQ17_TO_FLOAT  TI方式UINT32的UQ17转化浮点类型\n
*     LQ_TI_UINT32_UQ16_TO_FLOAT  TI方式UINT32的UQ16转化浮点类型\n
*     LQ_TI_UINT32_UQ15_TO_FLOAT  TI方式UINT32的UQ15转化浮点类型\n
*     LQ_TI_UINT32_UQ14_TO_FLOAT  TI方式UINT32的UQ14转化浮点类型\n
*     LQ_TI_UINT32_UQ13_TO_FLOAT  TI方式UINT32的UQ13转化浮点类型\n
*     LQ_TI_UINT32_UQ12_TO_FLOAT  TI方式UINT32的UQ12转化浮点类型\n
*     LQ_TI_UINT32_UQ11_TO_FLOAT  TI方式UINT32的UQ11转化浮点类型\n
*     LQ_TI_UINT32_UQ10_TO_FLOAT  TI方式UINT32的UQ10转化浮点类型\n
*     LQ_TI_UINT32_UQ9_TO_FLOAT  TI方式UINT32的UQ9转化浮点类型\n
*     LQ_TI_UINT32_UQ8_TO_FLOAT  TI方式UINT32的UQ8转化浮点类型\n
*     LQ_TI_UINT32_UQ7_TO_FLOAT  TI方式UINT32的UQ7转化浮点类型\n
*     LQ_TI_UINT32_UQ6_TO_FLOAT  TI方式UINT32的UQ6转化浮点类型\n
*     LQ_TI_UINT32_UQ5_TO_FLOAT  TI方式UINT32的UQ5转化浮点类型\n
*     LQ_TI_UINT32_UQ4_TO_FLOAT  TI方式UINT32的UQ4转化浮点类型\n
*     LQ_TI_UINT32_UQ3_TO_FLOAT  TI方式UINT32的UQ3转化浮点类型\n
*     LQ_TI_UINT32_UQ2_TO_FLOAT  TI方式UINT32的UQ2转化浮点类型\n
*     LQ_TI_UINT32_UQ1_TO_FLOAT  TI方式UINT32的UQ1转化浮点类型\n
*/
LQ_F_32BIT LQ_TI_UINT32_UQ17_TO_FLOAT(LQ_I_32BIT A, LQ_ERROR* lq_error)
{
    LQ_UI_16BIT ui16Exp;
    LQ_UI_32BIT uiq23Result;
    LQ_UI_32BIT uiq31Input;
    //!< 初始化指数部分偏移量
    ui16Exp = 18048;
    //!< 保存符号位
    if (A < 0)
    {
        ui16Exp |= 0x8000;
        uiq31Input = (LQ_UI_32BIT)(-(LQ_I_64BIT)A);
    }
    else if (A == 0)
    {
        return (0);
    }
    else
    {
        uiq31Input = A;
    }
    LQ_TI_Q2F_NORMALIZE(uiq31Input, ui16Exp);
    /*对uiq31结果进行四舍五入并切换到uiq23*/
    uiq23Result = (LQ_UI_32BIT)(((LQ_UI_64BIT)uiq31Input + 0x0080u) >> 8);
    if (uiq23Result >= 0x01000000u)
    {
        uiq23Result = 0;
        ui16Exp += 0x0080;
    }
    /*删除尾数的隐含MSB位 */
    uiq23Result &= ~0x00800000;
    /*
    *将构造的指数和符号位添加到尾数。我们必须使用
    *四舍五入会导致尾数溢出的情况下的加法。
    *当这种情况发生时，尾数结果为2，其中MSB为零
    *exp的LSB被设置为1。在指数上加一就是
    *尾数为2的正确处理。不需要缩放
    *尾数，因为在这种情况下它总是等于零。
   */
    uiq23Result += (LQ_UI_32BIT)ui16Exp << 16;
    return LQ_TI_UINT32_BITS_TO_FLOAT(uiq23Result);
}
/**@brief (TI方法)UINT32类型UQ16格式转浮点
* @details 采用估算位+指数位+符号位三位结合，能提高精度
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为浮点数
* @code*    LQ_TI_UINT32_UQ16_TO_FLOAT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_UINT32_UQ32_TO_FLOAT  TI方式UINT32的UQ32转化浮点类型\n
*     LQ_TI_UINT32_UQ31_TO_FLOAT  TI方式UINT32的UQ31转化浮点类型\n
*     LQ_TI_UINT32_UQ30_TO_FLOAT  TI方式UINT32的UQ30转化浮点类型\n
*     LQ_TI_UINT32_UQ29_TO_FLOAT  TI方式UINT32的UQ29转化浮点类型\n
*     LQ_TI_UINT32_UQ28_TO_FLOAT  TI方式UINT32的UQ28转化浮点类型\n
*     LQ_TI_UINT32_UQ27_TO_FLOAT  TI方式UINT32的UQ27转化浮点类型\n
*     LQ_TI_UINT32_UQ26_TO_FLOAT  TI方式UINT32的UQ26转化浮点类型\n
*     LQ_TI_UINT32_UQ25_TO_FLOAT  TI方式UINT32的UQ25转化浮点类型\n
*     LQ_TI_UINT32_UQ24_TO_FLOAT  TI方式UINT32的UQ24转化浮点类型\n
*     LQ_TI_UINT32_UQ23_TO_FLOAT  TI方式UINT32的UQ23转化浮点类型\n
*     LQ_TI_UINT32_UQ22_TO_FLOAT  TI方式UINT32的UQ22转化浮点类型\n
*     LQ_TI_UINT32_UQ21_TO_FLOAT  TI方式UINT32的UQ21转化浮点类型\n
*     LQ_TI_UINT32_UQ20_TO_FLOAT  TI方式UINT32的UQ20转化浮点类型\n
*     LQ_TI_UINT32_UQ19_TO_FLOAT  TI方式UINT32的UQ19转化浮点类型\n
*     LQ_TI_UINT32_UQ18_TO_FLOAT  TI方式UINT32的UQ18转化浮点类型\n
*     LQ_TI_UINT32_UQ17_TO_FLOAT  TI方式UINT32的UQ17转化浮点类型\n
*     LQ_TI_UINT32_UQ16_TO_FLOAT  TI方式UINT32的UQ16转化浮点类型\n
*     LQ_TI_UINT32_UQ15_TO_FLOAT  TI方式UINT32的UQ15转化浮点类型\n
*     LQ_TI_UINT32_UQ14_TO_FLOAT  TI方式UINT32的UQ14转化浮点类型\n
*     LQ_TI_UINT32_UQ13_TO_FLOAT  TI方式UINT32的UQ13转化浮点类型\n
*     LQ_TI_UINT32_UQ12_TO_FLOAT  TI方式UINT32的UQ12转化浮点类型\n
*     LQ_TI_UINT32_UQ11_TO_FLOAT  TI方式UINT32的UQ11转化浮点类型\n
*     LQ_TI_UINT32_UQ10_TO_FLOAT  TI方式UINT32的UQ10转化浮点类型\n
*     LQ_TI_UINT32_UQ9_TO_FLOAT  TI方式UINT32的UQ9转化浮点类型\n
*     LQ_TI_UINT32_UQ8_TO_FLOAT  TI方式UINT32的UQ8转化浮点类型\n
*     LQ_TI_UINT32_UQ7_TO_FLOAT  TI方式UINT32的UQ7转化浮点类型\n
*     LQ_TI_UINT32_UQ6_TO_FLOAT  TI方式UINT32的UQ6转化浮点类型\n
*     LQ_TI_UINT32_UQ5_TO_FLOAT  TI方式UINT32的UQ5转化浮点类型\n
*     LQ_TI_UINT32_UQ4_TO_FLOAT  TI方式UINT32的UQ4转化浮点类型\n
*     LQ_TI_UINT32_UQ3_TO_FLOAT  TI方式UINT32的UQ3转化浮点类型\n
*     LQ_TI_UINT32_UQ2_TO_FLOAT  TI方式UINT32的UQ2转化浮点类型\n
*     LQ_TI_UINT32_UQ1_TO_FLOAT  TI方式UINT32的UQ1转化浮点类型\n
*/
LQ_F_32BIT LQ_TI_UINT32_UQ16_TO_FLOAT(LQ_I_32BIT A, LQ_ERROR* lq_error)
{
    LQ_UI_16BIT ui16Exp;
    LQ_UI_32BIT uiq23Result;
    LQ_UI_32BIT uiq31Input;
    //!< 初始化指数部分偏移量
    ui16Exp = 18176;
    //!< 保存符号位
    if (A < 0)
    {
        ui16Exp |= 0x8000;
        uiq31Input = (LQ_UI_32BIT)(-(LQ_I_64BIT)A);
    }
    else if (A == 0)
    {
        return (0);
    }
    else
    {
        uiq31Input = A;
    }
    LQ_TI_Q2F_NORMALIZE(uiq31Input, ui16Exp);
    /*对uiq31结果进行四舍五入并切换到uiq23*/
    uiq23Result = (LQ_UI_32BIT)(((LQ_UI_64BIT)uiq31Input + 0x0080u) >> 8);
    if (uiq23Result >= 0x01000000u)
    {
        uiq23Result = 0;
        ui16Exp += 0x0080;
    }
    /*删除尾数的隐含MSB位 */
    uiq23Result &= ~0x00800000;
    /*
    *将构造的指数和符号位添加到尾数。我们必须使用
    *四舍五入会导致尾数溢出的情况下的加法。
    *当这种情况发生时，尾数结果为2，其中MSB为零
    *exp的LSB被设置为1。在指数上加一就是
    *尾数为2的正确处理。不需要缩放
    *尾数，因为在这种情况下它总是等于零。
   */
    uiq23Result += (LQ_UI_32BIT)ui16Exp << 16;
    return LQ_TI_UINT32_BITS_TO_FLOAT(uiq23Result);
}
/**@brief (TI方法)UINT32类型UQ15格式转浮点
* @details 采用估算位+指数位+符号位三位结合，能提高精度
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为浮点数
* @code*    LQ_TI_UINT32_UQ15_TO_FLOAT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_UINT32_UQ32_TO_FLOAT  TI方式UINT32的UQ32转化浮点类型\n
*     LQ_TI_UINT32_UQ31_TO_FLOAT  TI方式UINT32的UQ31转化浮点类型\n
*     LQ_TI_UINT32_UQ30_TO_FLOAT  TI方式UINT32的UQ30转化浮点类型\n
*     LQ_TI_UINT32_UQ29_TO_FLOAT  TI方式UINT32的UQ29转化浮点类型\n
*     LQ_TI_UINT32_UQ28_TO_FLOAT  TI方式UINT32的UQ28转化浮点类型\n
*     LQ_TI_UINT32_UQ27_TO_FLOAT  TI方式UINT32的UQ27转化浮点类型\n
*     LQ_TI_UINT32_UQ26_TO_FLOAT  TI方式UINT32的UQ26转化浮点类型\n
*     LQ_TI_UINT32_UQ25_TO_FLOAT  TI方式UINT32的UQ25转化浮点类型\n
*     LQ_TI_UINT32_UQ24_TO_FLOAT  TI方式UINT32的UQ24转化浮点类型\n
*     LQ_TI_UINT32_UQ23_TO_FLOAT  TI方式UINT32的UQ23转化浮点类型\n
*     LQ_TI_UINT32_UQ22_TO_FLOAT  TI方式UINT32的UQ22转化浮点类型\n
*     LQ_TI_UINT32_UQ21_TO_FLOAT  TI方式UINT32的UQ21转化浮点类型\n
*     LQ_TI_UINT32_UQ20_TO_FLOAT  TI方式UINT32的UQ20转化浮点类型\n
*     LQ_TI_UINT32_UQ19_TO_FLOAT  TI方式UINT32的UQ19转化浮点类型\n
*     LQ_TI_UINT32_UQ18_TO_FLOAT  TI方式UINT32的UQ18转化浮点类型\n
*     LQ_TI_UINT32_UQ17_TO_FLOAT  TI方式UINT32的UQ17转化浮点类型\n
*     LQ_TI_UINT32_UQ16_TO_FLOAT  TI方式UINT32的UQ16转化浮点类型\n
*     LQ_TI_UINT32_UQ15_TO_FLOAT  TI方式UINT32的UQ15转化浮点类型\n
*     LQ_TI_UINT32_UQ14_TO_FLOAT  TI方式UINT32的UQ14转化浮点类型\n
*     LQ_TI_UINT32_UQ13_TO_FLOAT  TI方式UINT32的UQ13转化浮点类型\n
*     LQ_TI_UINT32_UQ12_TO_FLOAT  TI方式UINT32的UQ12转化浮点类型\n
*     LQ_TI_UINT32_UQ11_TO_FLOAT  TI方式UINT32的UQ11转化浮点类型\n
*     LQ_TI_UINT32_UQ10_TO_FLOAT  TI方式UINT32的UQ10转化浮点类型\n
*     LQ_TI_UINT32_UQ9_TO_FLOAT  TI方式UINT32的UQ9转化浮点类型\n
*     LQ_TI_UINT32_UQ8_TO_FLOAT  TI方式UINT32的UQ8转化浮点类型\n
*     LQ_TI_UINT32_UQ7_TO_FLOAT  TI方式UINT32的UQ7转化浮点类型\n
*     LQ_TI_UINT32_UQ6_TO_FLOAT  TI方式UINT32的UQ6转化浮点类型\n
*     LQ_TI_UINT32_UQ5_TO_FLOAT  TI方式UINT32的UQ5转化浮点类型\n
*     LQ_TI_UINT32_UQ4_TO_FLOAT  TI方式UINT32的UQ4转化浮点类型\n
*     LQ_TI_UINT32_UQ3_TO_FLOAT  TI方式UINT32的UQ3转化浮点类型\n
*     LQ_TI_UINT32_UQ2_TO_FLOAT  TI方式UINT32的UQ2转化浮点类型\n
*     LQ_TI_UINT32_UQ1_TO_FLOAT  TI方式UINT32的UQ1转化浮点类型\n
*/
LQ_F_32BIT LQ_TI_UINT32_UQ15_TO_FLOAT(LQ_I_32BIT A, LQ_ERROR* lq_error)
{
    LQ_UI_16BIT ui16Exp;
    LQ_UI_32BIT uiq23Result;
    LQ_UI_32BIT uiq31Input;
    //!< 初始化指数部分偏移量
    ui16Exp = 18304;
    //!< 保存符号位
    if (A < 0)
    {
        ui16Exp |= 0x8000;
        uiq31Input = (LQ_UI_32BIT)(-(LQ_I_64BIT)A);
    }
    else if (A == 0)
    {
        return (0);
    }
    else
    {
        uiq31Input = A;
    }
    LQ_TI_Q2F_NORMALIZE(uiq31Input, ui16Exp);
    /*对uiq31结果进行四舍五入并切换到uiq23*/
    uiq23Result = (LQ_UI_32BIT)(((LQ_UI_64BIT)uiq31Input + 0x0080u) >> 8);
    if (uiq23Result >= 0x01000000u)
    {
        uiq23Result = 0;
        ui16Exp += 0x0080;
    }
    /*删除尾数的隐含MSB位 */
    uiq23Result &= ~0x00800000;
    /*
    *将构造的指数和符号位添加到尾数。我们必须使用
    *四舍五入会导致尾数溢出的情况下的加法。
    *当这种情况发生时，尾数结果为2，其中MSB为零
    *exp的LSB被设置为1。在指数上加一就是
    *尾数为2的正确处理。不需要缩放
    *尾数，因为在这种情况下它总是等于零。
   */
    uiq23Result += (LQ_UI_32BIT)ui16Exp << 16;
    return LQ_TI_UINT32_BITS_TO_FLOAT(uiq23Result);
}
/**@brief (TI方法)UINT32类型UQ14格式转浮点
* @details 采用估算位+指数位+符号位三位结合，能提高精度
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为浮点数
* @code*    LQ_TI_UINT32_UQ14_TO_FLOAT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_UINT32_UQ32_TO_FLOAT  TI方式UINT32的UQ32转化浮点类型\n
*     LQ_TI_UINT32_UQ31_TO_FLOAT  TI方式UINT32的UQ31转化浮点类型\n
*     LQ_TI_UINT32_UQ30_TO_FLOAT  TI方式UINT32的UQ30转化浮点类型\n
*     LQ_TI_UINT32_UQ29_TO_FLOAT  TI方式UINT32的UQ29转化浮点类型\n
*     LQ_TI_UINT32_UQ28_TO_FLOAT  TI方式UINT32的UQ28转化浮点类型\n
*     LQ_TI_UINT32_UQ27_TO_FLOAT  TI方式UINT32的UQ27转化浮点类型\n
*     LQ_TI_UINT32_UQ26_TO_FLOAT  TI方式UINT32的UQ26转化浮点类型\n
*     LQ_TI_UINT32_UQ25_TO_FLOAT  TI方式UINT32的UQ25转化浮点类型\n
*     LQ_TI_UINT32_UQ24_TO_FLOAT  TI方式UINT32的UQ24转化浮点类型\n
*     LQ_TI_UINT32_UQ23_TO_FLOAT  TI方式UINT32的UQ23转化浮点类型\n
*     LQ_TI_UINT32_UQ22_TO_FLOAT  TI方式UINT32的UQ22转化浮点类型\n
*     LQ_TI_UINT32_UQ21_TO_FLOAT  TI方式UINT32的UQ21转化浮点类型\n
*     LQ_TI_UINT32_UQ20_TO_FLOAT  TI方式UINT32的UQ20转化浮点类型\n
*     LQ_TI_UINT32_UQ19_TO_FLOAT  TI方式UINT32的UQ19转化浮点类型\n
*     LQ_TI_UINT32_UQ18_TO_FLOAT  TI方式UINT32的UQ18转化浮点类型\n
*     LQ_TI_UINT32_UQ17_TO_FLOAT  TI方式UINT32的UQ17转化浮点类型\n
*     LQ_TI_UINT32_UQ16_TO_FLOAT  TI方式UINT32的UQ16转化浮点类型\n
*     LQ_TI_UINT32_UQ15_TO_FLOAT  TI方式UINT32的UQ15转化浮点类型\n
*     LQ_TI_UINT32_UQ14_TO_FLOAT  TI方式UINT32的UQ14转化浮点类型\n
*     LQ_TI_UINT32_UQ13_TO_FLOAT  TI方式UINT32的UQ13转化浮点类型\n
*     LQ_TI_UINT32_UQ12_TO_FLOAT  TI方式UINT32的UQ12转化浮点类型\n
*     LQ_TI_UINT32_UQ11_TO_FLOAT  TI方式UINT32的UQ11转化浮点类型\n
*     LQ_TI_UINT32_UQ10_TO_FLOAT  TI方式UINT32的UQ10转化浮点类型\n
*     LQ_TI_UINT32_UQ9_TO_FLOAT  TI方式UINT32的UQ9转化浮点类型\n
*     LQ_TI_UINT32_UQ8_TO_FLOAT  TI方式UINT32的UQ8转化浮点类型\n
*     LQ_TI_UINT32_UQ7_TO_FLOAT  TI方式UINT32的UQ7转化浮点类型\n
*     LQ_TI_UINT32_UQ6_TO_FLOAT  TI方式UINT32的UQ6转化浮点类型\n
*     LQ_TI_UINT32_UQ5_TO_FLOAT  TI方式UINT32的UQ5转化浮点类型\n
*     LQ_TI_UINT32_UQ4_TO_FLOAT  TI方式UINT32的UQ4转化浮点类型\n
*     LQ_TI_UINT32_UQ3_TO_FLOAT  TI方式UINT32的UQ3转化浮点类型\n
*     LQ_TI_UINT32_UQ2_TO_FLOAT  TI方式UINT32的UQ2转化浮点类型\n
*     LQ_TI_UINT32_UQ1_TO_FLOAT  TI方式UINT32的UQ1转化浮点类型\n
*/
LQ_F_32BIT LQ_TI_UINT32_UQ14_TO_FLOAT(LQ_I_32BIT A, LQ_ERROR* lq_error)
{
    LQ_UI_16BIT ui16Exp;
    LQ_UI_32BIT uiq23Result;
    LQ_UI_32BIT uiq31Input;
    //!< 初始化指数部分偏移量
    ui16Exp = 18432;
    //!< 保存符号位
    if (A < 0)
    {
        ui16Exp |= 0x8000;
        uiq31Input = (LQ_UI_32BIT)(-(LQ_I_64BIT)A);
    }
    else if (A == 0)
    {
        return (0);
    }
    else
    {
        uiq31Input = A;
    }
    LQ_TI_Q2F_NORMALIZE(uiq31Input, ui16Exp);
    /*对uiq31结果进行四舍五入并切换到uiq23*/
    uiq23Result = (LQ_UI_32BIT)(((LQ_UI_64BIT)uiq31Input + 0x0080u) >> 8);
    if (uiq23Result >= 0x01000000u)
    {
        uiq23Result = 0;
        ui16Exp += 0x0080;
    }
    /*删除尾数的隐含MSB位 */
    uiq23Result &= ~0x00800000;
    /*
    *将构造的指数和符号位添加到尾数。我们必须使用
    *四舍五入会导致尾数溢出的情况下的加法。
    *当这种情况发生时，尾数结果为2，其中MSB为零
    *exp的LSB被设置为1。在指数上加一就是
    *尾数为2的正确处理。不需要缩放
    *尾数，因为在这种情况下它总是等于零。
   */
    uiq23Result += (LQ_UI_32BIT)ui16Exp << 16;
    return LQ_TI_UINT32_BITS_TO_FLOAT(uiq23Result);
}
/**@brief (TI方法)UINT32类型UQ13格式转浮点
* @details 采用估算位+指数位+符号位三位结合，能提高精度
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为浮点数
* @code*    LQ_TI_UINT32_UQ13_TO_FLOAT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_UINT32_UQ32_TO_FLOAT  TI方式UINT32的UQ32转化浮点类型\n
*     LQ_TI_UINT32_UQ31_TO_FLOAT  TI方式UINT32的UQ31转化浮点类型\n
*     LQ_TI_UINT32_UQ30_TO_FLOAT  TI方式UINT32的UQ30转化浮点类型\n
*     LQ_TI_UINT32_UQ29_TO_FLOAT  TI方式UINT32的UQ29转化浮点类型\n
*     LQ_TI_UINT32_UQ28_TO_FLOAT  TI方式UINT32的UQ28转化浮点类型\n
*     LQ_TI_UINT32_UQ27_TO_FLOAT  TI方式UINT32的UQ27转化浮点类型\n
*     LQ_TI_UINT32_UQ26_TO_FLOAT  TI方式UINT32的UQ26转化浮点类型\n
*     LQ_TI_UINT32_UQ25_TO_FLOAT  TI方式UINT32的UQ25转化浮点类型\n
*     LQ_TI_UINT32_UQ24_TO_FLOAT  TI方式UINT32的UQ24转化浮点类型\n
*     LQ_TI_UINT32_UQ23_TO_FLOAT  TI方式UINT32的UQ23转化浮点类型\n
*     LQ_TI_UINT32_UQ22_TO_FLOAT  TI方式UINT32的UQ22转化浮点类型\n
*     LQ_TI_UINT32_UQ21_TO_FLOAT  TI方式UINT32的UQ21转化浮点类型\n
*     LQ_TI_UINT32_UQ20_TO_FLOAT  TI方式UINT32的UQ20转化浮点类型\n
*     LQ_TI_UINT32_UQ19_TO_FLOAT  TI方式UINT32的UQ19转化浮点类型\n
*     LQ_TI_UINT32_UQ18_TO_FLOAT  TI方式UINT32的UQ18转化浮点类型\n
*     LQ_TI_UINT32_UQ17_TO_FLOAT  TI方式UINT32的UQ17转化浮点类型\n
*     LQ_TI_UINT32_UQ16_TO_FLOAT  TI方式UINT32的UQ16转化浮点类型\n
*     LQ_TI_UINT32_UQ15_TO_FLOAT  TI方式UINT32的UQ15转化浮点类型\n
*     LQ_TI_UINT32_UQ14_TO_FLOAT  TI方式UINT32的UQ14转化浮点类型\n
*     LQ_TI_UINT32_UQ13_TO_FLOAT  TI方式UINT32的UQ13转化浮点类型\n
*     LQ_TI_UINT32_UQ12_TO_FLOAT  TI方式UINT32的UQ12转化浮点类型\n
*     LQ_TI_UINT32_UQ11_TO_FLOAT  TI方式UINT32的UQ11转化浮点类型\n
*     LQ_TI_UINT32_UQ10_TO_FLOAT  TI方式UINT32的UQ10转化浮点类型\n
*     LQ_TI_UINT32_UQ9_TO_FLOAT  TI方式UINT32的UQ9转化浮点类型\n
*     LQ_TI_UINT32_UQ8_TO_FLOAT  TI方式UINT32的UQ8转化浮点类型\n
*     LQ_TI_UINT32_UQ7_TO_FLOAT  TI方式UINT32的UQ7转化浮点类型\n
*     LQ_TI_UINT32_UQ6_TO_FLOAT  TI方式UINT32的UQ6转化浮点类型\n
*     LQ_TI_UINT32_UQ5_TO_FLOAT  TI方式UINT32的UQ5转化浮点类型\n
*     LQ_TI_UINT32_UQ4_TO_FLOAT  TI方式UINT32的UQ4转化浮点类型\n
*     LQ_TI_UINT32_UQ3_TO_FLOAT  TI方式UINT32的UQ3转化浮点类型\n
*     LQ_TI_UINT32_UQ2_TO_FLOAT  TI方式UINT32的UQ2转化浮点类型\n
*     LQ_TI_UINT32_UQ1_TO_FLOAT  TI方式UINT32的UQ1转化浮点类型\n
*/
LQ_F_32BIT LQ_TI_UINT32_UQ13_TO_FLOAT(LQ_I_32BIT A, LQ_ERROR* lq_error)
{
    LQ_UI_16BIT ui16Exp;
    LQ_UI_32BIT uiq23Result;
    LQ_UI_32BIT uiq31Input;
    //!< 初始化指数部分偏移量
    ui16Exp = 18560;
    //!< 保存符号位
    if (A < 0)
    {
        ui16Exp |= 0x8000;
        uiq31Input = (LQ_UI_32BIT)(-(LQ_I_64BIT)A);
    }
    else if (A == 0)
    {
        return (0);
    }
    else
    {
        uiq31Input = A;
    }
    LQ_TI_Q2F_NORMALIZE(uiq31Input, ui16Exp);
    /*对uiq31结果进行四舍五入并切换到uiq23*/
    uiq23Result = (LQ_UI_32BIT)(((LQ_UI_64BIT)uiq31Input + 0x0080u) >> 8);
    if (uiq23Result >= 0x01000000u)
    {
        uiq23Result = 0;
        ui16Exp += 0x0080;
    }
    /*删除尾数的隐含MSB位 */
    uiq23Result &= ~0x00800000;
    /*
    *将构造的指数和符号位添加到尾数。我们必须使用
    *四舍五入会导致尾数溢出的情况下的加法。
    *当这种情况发生时，尾数结果为2，其中MSB为零
    *exp的LSB被设置为1。在指数上加一就是
    *尾数为2的正确处理。不需要缩放
    *尾数，因为在这种情况下它总是等于零。
   */
    uiq23Result += (LQ_UI_32BIT)ui16Exp << 16;
    return LQ_TI_UINT32_BITS_TO_FLOAT(uiq23Result);
}
/**@brief (TI方法)UINT32类型UQ12格式转浮点
* @details 采用估算位+指数位+符号位三位结合，能提高精度
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为浮点数
* @code*    LQ_TI_UINT32_UQ12_TO_FLOAT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_UINT32_UQ32_TO_FLOAT  TI方式UINT32的UQ32转化浮点类型\n
*     LQ_TI_UINT32_UQ31_TO_FLOAT  TI方式UINT32的UQ31转化浮点类型\n
*     LQ_TI_UINT32_UQ30_TO_FLOAT  TI方式UINT32的UQ30转化浮点类型\n
*     LQ_TI_UINT32_UQ29_TO_FLOAT  TI方式UINT32的UQ29转化浮点类型\n
*     LQ_TI_UINT32_UQ28_TO_FLOAT  TI方式UINT32的UQ28转化浮点类型\n
*     LQ_TI_UINT32_UQ27_TO_FLOAT  TI方式UINT32的UQ27转化浮点类型\n
*     LQ_TI_UINT32_UQ26_TO_FLOAT  TI方式UINT32的UQ26转化浮点类型\n
*     LQ_TI_UINT32_UQ25_TO_FLOAT  TI方式UINT32的UQ25转化浮点类型\n
*     LQ_TI_UINT32_UQ24_TO_FLOAT  TI方式UINT32的UQ24转化浮点类型\n
*     LQ_TI_UINT32_UQ23_TO_FLOAT  TI方式UINT32的UQ23转化浮点类型\n
*     LQ_TI_UINT32_UQ22_TO_FLOAT  TI方式UINT32的UQ22转化浮点类型\n
*     LQ_TI_UINT32_UQ21_TO_FLOAT  TI方式UINT32的UQ21转化浮点类型\n
*     LQ_TI_UINT32_UQ20_TO_FLOAT  TI方式UINT32的UQ20转化浮点类型\n
*     LQ_TI_UINT32_UQ19_TO_FLOAT  TI方式UINT32的UQ19转化浮点类型\n
*     LQ_TI_UINT32_UQ18_TO_FLOAT  TI方式UINT32的UQ18转化浮点类型\n
*     LQ_TI_UINT32_UQ17_TO_FLOAT  TI方式UINT32的UQ17转化浮点类型\n
*     LQ_TI_UINT32_UQ16_TO_FLOAT  TI方式UINT32的UQ16转化浮点类型\n
*     LQ_TI_UINT32_UQ15_TO_FLOAT  TI方式UINT32的UQ15转化浮点类型\n
*     LQ_TI_UINT32_UQ14_TO_FLOAT  TI方式UINT32的UQ14转化浮点类型\n
*     LQ_TI_UINT32_UQ13_TO_FLOAT  TI方式UINT32的UQ13转化浮点类型\n
*     LQ_TI_UINT32_UQ12_TO_FLOAT  TI方式UINT32的UQ12转化浮点类型\n
*     LQ_TI_UINT32_UQ11_TO_FLOAT  TI方式UINT32的UQ11转化浮点类型\n
*     LQ_TI_UINT32_UQ10_TO_FLOAT  TI方式UINT32的UQ10转化浮点类型\n
*     LQ_TI_UINT32_UQ9_TO_FLOAT  TI方式UINT32的UQ9转化浮点类型\n
*     LQ_TI_UINT32_UQ8_TO_FLOAT  TI方式UINT32的UQ8转化浮点类型\n
*     LQ_TI_UINT32_UQ7_TO_FLOAT  TI方式UINT32的UQ7转化浮点类型\n
*     LQ_TI_UINT32_UQ6_TO_FLOAT  TI方式UINT32的UQ6转化浮点类型\n
*     LQ_TI_UINT32_UQ5_TO_FLOAT  TI方式UINT32的UQ5转化浮点类型\n
*     LQ_TI_UINT32_UQ4_TO_FLOAT  TI方式UINT32的UQ4转化浮点类型\n
*     LQ_TI_UINT32_UQ3_TO_FLOAT  TI方式UINT32的UQ3转化浮点类型\n
*     LQ_TI_UINT32_UQ2_TO_FLOAT  TI方式UINT32的UQ2转化浮点类型\n
*     LQ_TI_UINT32_UQ1_TO_FLOAT  TI方式UINT32的UQ1转化浮点类型\n
*/
LQ_F_32BIT LQ_TI_UINT32_UQ12_TO_FLOAT(LQ_I_32BIT A, LQ_ERROR* lq_error)
{
    LQ_UI_16BIT ui16Exp;
    LQ_UI_32BIT uiq23Result;
    LQ_UI_32BIT uiq31Input;
    //!< 初始化指数部分偏移量
    ui16Exp = 18688;
    //!< 保存符号位
    if (A < 0)
    {
        ui16Exp |= 0x8000;
        uiq31Input = (LQ_UI_32BIT)(-(LQ_I_64BIT)A);
    }
    else if (A == 0)
    {
        return (0);
    }
    else
    {
        uiq31Input = A;
    }
    LQ_TI_Q2F_NORMALIZE(uiq31Input, ui16Exp);
    /*对uiq31结果进行四舍五入并切换到uiq23*/
    uiq23Result = (LQ_UI_32BIT)(((LQ_UI_64BIT)uiq31Input + 0x0080u) >> 8);
    if (uiq23Result >= 0x01000000u)
    {
        uiq23Result = 0;
        ui16Exp += 0x0080;
    }
    /*删除尾数的隐含MSB位 */
    uiq23Result &= ~0x00800000;
    /*
    *将构造的指数和符号位添加到尾数。我们必须使用
    *四舍五入会导致尾数溢出的情况下的加法。
    *当这种情况发生时，尾数结果为2，其中MSB为零
    *exp的LSB被设置为1。在指数上加一就是
    *尾数为2的正确处理。不需要缩放
    *尾数，因为在这种情况下它总是等于零。
   */
    uiq23Result += (LQ_UI_32BIT)ui16Exp << 16;
    return LQ_TI_UINT32_BITS_TO_FLOAT(uiq23Result);
}
/**@brief (TI方法)UINT32类型UQ11格式转浮点
* @details 采用估算位+指数位+符号位三位结合，能提高精度
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为浮点数
* @code*    LQ_TI_UINT32_UQ11_TO_FLOAT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_UINT32_UQ32_TO_FLOAT  TI方式UINT32的UQ32转化浮点类型\n
*     LQ_TI_UINT32_UQ31_TO_FLOAT  TI方式UINT32的UQ31转化浮点类型\n
*     LQ_TI_UINT32_UQ30_TO_FLOAT  TI方式UINT32的UQ30转化浮点类型\n
*     LQ_TI_UINT32_UQ29_TO_FLOAT  TI方式UINT32的UQ29转化浮点类型\n
*     LQ_TI_UINT32_UQ28_TO_FLOAT  TI方式UINT32的UQ28转化浮点类型\n
*     LQ_TI_UINT32_UQ27_TO_FLOAT  TI方式UINT32的UQ27转化浮点类型\n
*     LQ_TI_UINT32_UQ26_TO_FLOAT  TI方式UINT32的UQ26转化浮点类型\n
*     LQ_TI_UINT32_UQ25_TO_FLOAT  TI方式UINT32的UQ25转化浮点类型\n
*     LQ_TI_UINT32_UQ24_TO_FLOAT  TI方式UINT32的UQ24转化浮点类型\n
*     LQ_TI_UINT32_UQ23_TO_FLOAT  TI方式UINT32的UQ23转化浮点类型\n
*     LQ_TI_UINT32_UQ22_TO_FLOAT  TI方式UINT32的UQ22转化浮点类型\n
*     LQ_TI_UINT32_UQ21_TO_FLOAT  TI方式UINT32的UQ21转化浮点类型\n
*     LQ_TI_UINT32_UQ20_TO_FLOAT  TI方式UINT32的UQ20转化浮点类型\n
*     LQ_TI_UINT32_UQ19_TO_FLOAT  TI方式UINT32的UQ19转化浮点类型\n
*     LQ_TI_UINT32_UQ18_TO_FLOAT  TI方式UINT32的UQ18转化浮点类型\n
*     LQ_TI_UINT32_UQ17_TO_FLOAT  TI方式UINT32的UQ17转化浮点类型\n
*     LQ_TI_UINT32_UQ16_TO_FLOAT  TI方式UINT32的UQ16转化浮点类型\n
*     LQ_TI_UINT32_UQ15_TO_FLOAT  TI方式UINT32的UQ15转化浮点类型\n
*     LQ_TI_UINT32_UQ14_TO_FLOAT  TI方式UINT32的UQ14转化浮点类型\n
*     LQ_TI_UINT32_UQ13_TO_FLOAT  TI方式UINT32的UQ13转化浮点类型\n
*     LQ_TI_UINT32_UQ12_TO_FLOAT  TI方式UINT32的UQ12转化浮点类型\n
*     LQ_TI_UINT32_UQ11_TO_FLOAT  TI方式UINT32的UQ11转化浮点类型\n
*     LQ_TI_UINT32_UQ10_TO_FLOAT  TI方式UINT32的UQ10转化浮点类型\n
*     LQ_TI_UINT32_UQ9_TO_FLOAT  TI方式UINT32的UQ9转化浮点类型\n
*     LQ_TI_UINT32_UQ8_TO_FLOAT  TI方式UINT32的UQ8转化浮点类型\n
*     LQ_TI_UINT32_UQ7_TO_FLOAT  TI方式UINT32的UQ7转化浮点类型\n
*     LQ_TI_UINT32_UQ6_TO_FLOAT  TI方式UINT32的UQ6转化浮点类型\n
*     LQ_TI_UINT32_UQ5_TO_FLOAT  TI方式UINT32的UQ5转化浮点类型\n
*     LQ_TI_UINT32_UQ4_TO_FLOAT  TI方式UINT32的UQ4转化浮点类型\n
*     LQ_TI_UINT32_UQ3_TO_FLOAT  TI方式UINT32的UQ3转化浮点类型\n
*     LQ_TI_UINT32_UQ2_TO_FLOAT  TI方式UINT32的UQ2转化浮点类型\n
*     LQ_TI_UINT32_UQ1_TO_FLOAT  TI方式UINT32的UQ1转化浮点类型\n
*/
LQ_F_32BIT LQ_TI_UINT32_UQ11_TO_FLOAT(LQ_I_32BIT A, LQ_ERROR* lq_error)
{
    LQ_UI_16BIT ui16Exp;
    LQ_UI_32BIT uiq23Result;
    LQ_UI_32BIT uiq31Input;
    //!< 初始化指数部分偏移量
    ui16Exp = 18816;
    //!< 保存符号位
    if (A < 0)
    {
        ui16Exp |= 0x8000;
        uiq31Input = (LQ_UI_32BIT)(-(LQ_I_64BIT)A);
    }
    else if (A == 0)
    {
        return (0);
    }
    else
    {
        uiq31Input = A;
    }
    LQ_TI_Q2F_NORMALIZE(uiq31Input, ui16Exp);
    /*对uiq31结果进行四舍五入并切换到uiq23*/
    uiq23Result = (LQ_UI_32BIT)(((LQ_UI_64BIT)uiq31Input + 0x0080u) >> 8);
    if (uiq23Result >= 0x01000000u)
    {
        uiq23Result = 0;
        ui16Exp += 0x0080;
    }
    /*删除尾数的隐含MSB位 */
    uiq23Result &= ~0x00800000;
    /*
    *将构造的指数和符号位添加到尾数。我们必须使用
    *四舍五入会导致尾数溢出的情况下的加法。
    *当这种情况发生时，尾数结果为2，其中MSB为零
    *exp的LSB被设置为1。在指数上加一就是
    *尾数为2的正确处理。不需要缩放
    *尾数，因为在这种情况下它总是等于零。
   */
    uiq23Result += (LQ_UI_32BIT)ui16Exp << 16;
    return LQ_TI_UINT32_BITS_TO_FLOAT(uiq23Result);
}
/**@brief (TI方法)UINT32类型UQ10格式转浮点
* @details 采用估算位+指数位+符号位三位结合，能提高精度
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为浮点数
* @code*    LQ_TI_UINT32_UQ10_TO_FLOAT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_UINT32_UQ32_TO_FLOAT  TI方式UINT32的UQ32转化浮点类型\n
*     LQ_TI_UINT32_UQ31_TO_FLOAT  TI方式UINT32的UQ31转化浮点类型\n
*     LQ_TI_UINT32_UQ30_TO_FLOAT  TI方式UINT32的UQ30转化浮点类型\n
*     LQ_TI_UINT32_UQ29_TO_FLOAT  TI方式UINT32的UQ29转化浮点类型\n
*     LQ_TI_UINT32_UQ28_TO_FLOAT  TI方式UINT32的UQ28转化浮点类型\n
*     LQ_TI_UINT32_UQ27_TO_FLOAT  TI方式UINT32的UQ27转化浮点类型\n
*     LQ_TI_UINT32_UQ26_TO_FLOAT  TI方式UINT32的UQ26转化浮点类型\n
*     LQ_TI_UINT32_UQ25_TO_FLOAT  TI方式UINT32的UQ25转化浮点类型\n
*     LQ_TI_UINT32_UQ24_TO_FLOAT  TI方式UINT32的UQ24转化浮点类型\n
*     LQ_TI_UINT32_UQ23_TO_FLOAT  TI方式UINT32的UQ23转化浮点类型\n
*     LQ_TI_UINT32_UQ22_TO_FLOAT  TI方式UINT32的UQ22转化浮点类型\n
*     LQ_TI_UINT32_UQ21_TO_FLOAT  TI方式UINT32的UQ21转化浮点类型\n
*     LQ_TI_UINT32_UQ20_TO_FLOAT  TI方式UINT32的UQ20转化浮点类型\n
*     LQ_TI_UINT32_UQ19_TO_FLOAT  TI方式UINT32的UQ19转化浮点类型\n
*     LQ_TI_UINT32_UQ18_TO_FLOAT  TI方式UINT32的UQ18转化浮点类型\n
*     LQ_TI_UINT32_UQ17_TO_FLOAT  TI方式UINT32的UQ17转化浮点类型\n
*     LQ_TI_UINT32_UQ16_TO_FLOAT  TI方式UINT32的UQ16转化浮点类型\n
*     LQ_TI_UINT32_UQ15_TO_FLOAT  TI方式UINT32的UQ15转化浮点类型\n
*     LQ_TI_UINT32_UQ14_TO_FLOAT  TI方式UINT32的UQ14转化浮点类型\n
*     LQ_TI_UINT32_UQ13_TO_FLOAT  TI方式UINT32的UQ13转化浮点类型\n
*     LQ_TI_UINT32_UQ12_TO_FLOAT  TI方式UINT32的UQ12转化浮点类型\n
*     LQ_TI_UINT32_UQ11_TO_FLOAT  TI方式UINT32的UQ11转化浮点类型\n
*     LQ_TI_UINT32_UQ10_TO_FLOAT  TI方式UINT32的UQ10转化浮点类型\n
*     LQ_TI_UINT32_UQ9_TO_FLOAT  TI方式UINT32的UQ9转化浮点类型\n
*     LQ_TI_UINT32_UQ8_TO_FLOAT  TI方式UINT32的UQ8转化浮点类型\n
*     LQ_TI_UINT32_UQ7_TO_FLOAT  TI方式UINT32的UQ7转化浮点类型\n
*     LQ_TI_UINT32_UQ6_TO_FLOAT  TI方式UINT32的UQ6转化浮点类型\n
*     LQ_TI_UINT32_UQ5_TO_FLOAT  TI方式UINT32的UQ5转化浮点类型\n
*     LQ_TI_UINT32_UQ4_TO_FLOAT  TI方式UINT32的UQ4转化浮点类型\n
*     LQ_TI_UINT32_UQ3_TO_FLOAT  TI方式UINT32的UQ3转化浮点类型\n
*     LQ_TI_UINT32_UQ2_TO_FLOAT  TI方式UINT32的UQ2转化浮点类型\n
*     LQ_TI_UINT32_UQ1_TO_FLOAT  TI方式UINT32的UQ1转化浮点类型\n
*/
LQ_F_32BIT LQ_TI_UINT32_UQ10_TO_FLOAT(LQ_I_32BIT A, LQ_ERROR* lq_error)
{
    LQ_UI_16BIT ui16Exp;
    LQ_UI_32BIT uiq23Result;
    LQ_UI_32BIT uiq31Input;
    //!< 初始化指数部分偏移量
    ui16Exp = 18944;
    //!< 保存符号位
    if (A < 0)
    {
        ui16Exp |= 0x8000;
        uiq31Input = (LQ_UI_32BIT)(-(LQ_I_64BIT)A);
    }
    else if (A == 0)
    {
        return (0);
    }
    else
    {
        uiq31Input = A;
    }
    LQ_TI_Q2F_NORMALIZE(uiq31Input, ui16Exp);
    /*对uiq31结果进行四舍五入并切换到uiq23*/
    uiq23Result = (LQ_UI_32BIT)(((LQ_UI_64BIT)uiq31Input + 0x0080u) >> 8);
    if (uiq23Result >= 0x01000000u)
    {
        uiq23Result = 0;
        ui16Exp += 0x0080;
    }
    /*删除尾数的隐含MSB位 */
    uiq23Result &= ~0x00800000;
    /*
    *将构造的指数和符号位添加到尾数。我们必须使用
    *四舍五入会导致尾数溢出的情况下的加法。
    *当这种情况发生时，尾数结果为2，其中MSB为零
    *exp的LSB被设置为1。在指数上加一就是
    *尾数为2的正确处理。不需要缩放
    *尾数，因为在这种情况下它总是等于零。
   */
    uiq23Result += (LQ_UI_32BIT)ui16Exp << 16;
    return LQ_TI_UINT32_BITS_TO_FLOAT(uiq23Result);
}
/**@brief (TI方法)UINT32类型UQ9格式转浮点
* @details 采用估算位+指数位+符号位三位结合，能提高精度
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为浮点数
* @code*    LQ_TI_UINT32_UQ9_TO_FLOAT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_UINT32_UQ32_TO_FLOAT  TI方式UINT32的UQ32转化浮点类型\n
*     LQ_TI_UINT32_UQ31_TO_FLOAT  TI方式UINT32的UQ31转化浮点类型\n
*     LQ_TI_UINT32_UQ30_TO_FLOAT  TI方式UINT32的UQ30转化浮点类型\n
*     LQ_TI_UINT32_UQ29_TO_FLOAT  TI方式UINT32的UQ29转化浮点类型\n
*     LQ_TI_UINT32_UQ28_TO_FLOAT  TI方式UINT32的UQ28转化浮点类型\n
*     LQ_TI_UINT32_UQ27_TO_FLOAT  TI方式UINT32的UQ27转化浮点类型\n
*     LQ_TI_UINT32_UQ26_TO_FLOAT  TI方式UINT32的UQ26转化浮点类型\n
*     LQ_TI_UINT32_UQ25_TO_FLOAT  TI方式UINT32的UQ25转化浮点类型\n
*     LQ_TI_UINT32_UQ24_TO_FLOAT  TI方式UINT32的UQ24转化浮点类型\n
*     LQ_TI_UINT32_UQ23_TO_FLOAT  TI方式UINT32的UQ23转化浮点类型\n
*     LQ_TI_UINT32_UQ22_TO_FLOAT  TI方式UINT32的UQ22转化浮点类型\n
*     LQ_TI_UINT32_UQ21_TO_FLOAT  TI方式UINT32的UQ21转化浮点类型\n
*     LQ_TI_UINT32_UQ20_TO_FLOAT  TI方式UINT32的UQ20转化浮点类型\n
*     LQ_TI_UINT32_UQ19_TO_FLOAT  TI方式UINT32的UQ19转化浮点类型\n
*     LQ_TI_UINT32_UQ18_TO_FLOAT  TI方式UINT32的UQ18转化浮点类型\n
*     LQ_TI_UINT32_UQ17_TO_FLOAT  TI方式UINT32的UQ17转化浮点类型\n
*     LQ_TI_UINT32_UQ16_TO_FLOAT  TI方式UINT32的UQ16转化浮点类型\n
*     LQ_TI_UINT32_UQ15_TO_FLOAT  TI方式UINT32的UQ15转化浮点类型\n
*     LQ_TI_UINT32_UQ14_TO_FLOAT  TI方式UINT32的UQ14转化浮点类型\n
*     LQ_TI_UINT32_UQ13_TO_FLOAT  TI方式UINT32的UQ13转化浮点类型\n
*     LQ_TI_UINT32_UQ12_TO_FLOAT  TI方式UINT32的UQ12转化浮点类型\n
*     LQ_TI_UINT32_UQ11_TO_FLOAT  TI方式UINT32的UQ11转化浮点类型\n
*     LQ_TI_UINT32_UQ10_TO_FLOAT  TI方式UINT32的UQ10转化浮点类型\n
*     LQ_TI_UINT32_UQ9_TO_FLOAT  TI方式UINT32的UQ9转化浮点类型\n
*     LQ_TI_UINT32_UQ8_TO_FLOAT  TI方式UINT32的UQ8转化浮点类型\n
*     LQ_TI_UINT32_UQ7_TO_FLOAT  TI方式UINT32的UQ7转化浮点类型\n
*     LQ_TI_UINT32_UQ6_TO_FLOAT  TI方式UINT32的UQ6转化浮点类型\n
*     LQ_TI_UINT32_UQ5_TO_FLOAT  TI方式UINT32的UQ5转化浮点类型\n
*     LQ_TI_UINT32_UQ4_TO_FLOAT  TI方式UINT32的UQ4转化浮点类型\n
*     LQ_TI_UINT32_UQ3_TO_FLOAT  TI方式UINT32的UQ3转化浮点类型\n
*     LQ_TI_UINT32_UQ2_TO_FLOAT  TI方式UINT32的UQ2转化浮点类型\n
*     LQ_TI_UINT32_UQ1_TO_FLOAT  TI方式UINT32的UQ1转化浮点类型\n
*/
LQ_F_32BIT LQ_TI_UINT32_UQ9_TO_FLOAT(LQ_I_32BIT A, LQ_ERROR* lq_error)
{
    LQ_UI_16BIT ui16Exp;
    LQ_UI_32BIT uiq23Result;
    LQ_UI_32BIT uiq31Input;
    //!< 初始化指数部分偏移量
    ui16Exp = 19072;
    //!< 保存符号位
    if (A < 0)
    {
        ui16Exp |= 0x8000;
        uiq31Input = (LQ_UI_32BIT)(-(LQ_I_64BIT)A);
    }
    else if (A == 0)
    {
        return (0);
    }
    else
    {
        uiq31Input = A;
    }
    LQ_TI_Q2F_NORMALIZE(uiq31Input, ui16Exp);
    /*对uiq31结果进行四舍五入并切换到uiq23*/
    uiq23Result = (LQ_UI_32BIT)(((LQ_UI_64BIT)uiq31Input + 0x0080u) >> 8);
    if (uiq23Result >= 0x01000000u)
    {
        uiq23Result = 0;
        ui16Exp += 0x0080;
    }
    /*删除尾数的隐含MSB位 */
    uiq23Result &= ~0x00800000;
    /*
    *将构造的指数和符号位添加到尾数。我们必须使用
    *四舍五入会导致尾数溢出的情况下的加法。
    *当这种情况发生时，尾数结果为2，其中MSB为零
    *exp的LSB被设置为1。在指数上加一就是
    *尾数为2的正确处理。不需要缩放
    *尾数，因为在这种情况下它总是等于零。
   */
    uiq23Result += (LQ_UI_32BIT)ui16Exp << 16;
    return LQ_TI_UINT32_BITS_TO_FLOAT(uiq23Result);
}
/**@brief (TI方法)UINT32类型UQ8格式转浮点
* @details 采用估算位+指数位+符号位三位结合，能提高精度
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为浮点数
* @code*    LQ_TI_UINT32_UQ8_TO_FLOAT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_UINT32_UQ32_TO_FLOAT  TI方式UINT32的UQ32转化浮点类型\n
*     LQ_TI_UINT32_UQ31_TO_FLOAT  TI方式UINT32的UQ31转化浮点类型\n
*     LQ_TI_UINT32_UQ30_TO_FLOAT  TI方式UINT32的UQ30转化浮点类型\n
*     LQ_TI_UINT32_UQ29_TO_FLOAT  TI方式UINT32的UQ29转化浮点类型\n
*     LQ_TI_UINT32_UQ28_TO_FLOAT  TI方式UINT32的UQ28转化浮点类型\n
*     LQ_TI_UINT32_UQ27_TO_FLOAT  TI方式UINT32的UQ27转化浮点类型\n
*     LQ_TI_UINT32_UQ26_TO_FLOAT  TI方式UINT32的UQ26转化浮点类型\n
*     LQ_TI_UINT32_UQ25_TO_FLOAT  TI方式UINT32的UQ25转化浮点类型\n
*     LQ_TI_UINT32_UQ24_TO_FLOAT  TI方式UINT32的UQ24转化浮点类型\n
*     LQ_TI_UINT32_UQ23_TO_FLOAT  TI方式UINT32的UQ23转化浮点类型\n
*     LQ_TI_UINT32_UQ22_TO_FLOAT  TI方式UINT32的UQ22转化浮点类型\n
*     LQ_TI_UINT32_UQ21_TO_FLOAT  TI方式UINT32的UQ21转化浮点类型\n
*     LQ_TI_UINT32_UQ20_TO_FLOAT  TI方式UINT32的UQ20转化浮点类型\n
*     LQ_TI_UINT32_UQ19_TO_FLOAT  TI方式UINT32的UQ19转化浮点类型\n
*     LQ_TI_UINT32_UQ18_TO_FLOAT  TI方式UINT32的UQ18转化浮点类型\n
*     LQ_TI_UINT32_UQ17_TO_FLOAT  TI方式UINT32的UQ17转化浮点类型\n
*     LQ_TI_UINT32_UQ16_TO_FLOAT  TI方式UINT32的UQ16转化浮点类型\n
*     LQ_TI_UINT32_UQ15_TO_FLOAT  TI方式UINT32的UQ15转化浮点类型\n
*     LQ_TI_UINT32_UQ14_TO_FLOAT  TI方式UINT32的UQ14转化浮点类型\n
*     LQ_TI_UINT32_UQ13_TO_FLOAT  TI方式UINT32的UQ13转化浮点类型\n
*     LQ_TI_UINT32_UQ12_TO_FLOAT  TI方式UINT32的UQ12转化浮点类型\n
*     LQ_TI_UINT32_UQ11_TO_FLOAT  TI方式UINT32的UQ11转化浮点类型\n
*     LQ_TI_UINT32_UQ10_TO_FLOAT  TI方式UINT32的UQ10转化浮点类型\n
*     LQ_TI_UINT32_UQ9_TO_FLOAT  TI方式UINT32的UQ9转化浮点类型\n
*     LQ_TI_UINT32_UQ8_TO_FLOAT  TI方式UINT32的UQ8转化浮点类型\n
*     LQ_TI_UINT32_UQ7_TO_FLOAT  TI方式UINT32的UQ7转化浮点类型\n
*     LQ_TI_UINT32_UQ6_TO_FLOAT  TI方式UINT32的UQ6转化浮点类型\n
*     LQ_TI_UINT32_UQ5_TO_FLOAT  TI方式UINT32的UQ5转化浮点类型\n
*     LQ_TI_UINT32_UQ4_TO_FLOAT  TI方式UINT32的UQ4转化浮点类型\n
*     LQ_TI_UINT32_UQ3_TO_FLOAT  TI方式UINT32的UQ3转化浮点类型\n
*     LQ_TI_UINT32_UQ2_TO_FLOAT  TI方式UINT32的UQ2转化浮点类型\n
*     LQ_TI_UINT32_UQ1_TO_FLOAT  TI方式UINT32的UQ1转化浮点类型\n
*/
LQ_F_32BIT LQ_TI_UINT32_UQ8_TO_FLOAT(LQ_I_32BIT A, LQ_ERROR* lq_error)
{
    LQ_UI_16BIT ui16Exp;
    LQ_UI_32BIT uiq23Result;
    LQ_UI_32BIT uiq31Input;
    //!< 初始化指数部分偏移量
    ui16Exp = 19200;
    //!< 保存符号位
    if (A < 0)
    {
        ui16Exp |= 0x8000;
        uiq31Input = (LQ_UI_32BIT)(-(LQ_I_64BIT)A);
    }
    else if (A == 0)
    {
        return (0);
    }
    else
    {
        uiq31Input = A;
    }
    LQ_TI_Q2F_NORMALIZE(uiq31Input, ui16Exp);
    /*对uiq31结果进行四舍五入并切换到uiq23*/
    uiq23Result = (LQ_UI_32BIT)(((LQ_UI_64BIT)uiq31Input + 0x0080u) >> 8);
    if (uiq23Result >= 0x01000000u)
    {
        uiq23Result = 0;
        ui16Exp += 0x0080;
    }
    /*删除尾数的隐含MSB位 */
    uiq23Result &= ~0x00800000;
    /*
    *将构造的指数和符号位添加到尾数。我们必须使用
    *四舍五入会导致尾数溢出的情况下的加法。
    *当这种情况发生时，尾数结果为2，其中MSB为零
    *exp的LSB被设置为1。在指数上加一就是
    *尾数为2的正确处理。不需要缩放
    *尾数，因为在这种情况下它总是等于零。
   */
    uiq23Result += (LQ_UI_32BIT)ui16Exp << 16;
    return LQ_TI_UINT32_BITS_TO_FLOAT(uiq23Result);
}
/**@brief (TI方法)UINT32类型UQ7格式转浮点
* @details 采用估算位+指数位+符号位三位结合，能提高精度
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为浮点数
* @code*    LQ_TI_UINT32_UQ7_TO_FLOAT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_UINT32_UQ32_TO_FLOAT  TI方式UINT32的UQ32转化浮点类型\n
*     LQ_TI_UINT32_UQ31_TO_FLOAT  TI方式UINT32的UQ31转化浮点类型\n
*     LQ_TI_UINT32_UQ30_TO_FLOAT  TI方式UINT32的UQ30转化浮点类型\n
*     LQ_TI_UINT32_UQ29_TO_FLOAT  TI方式UINT32的UQ29转化浮点类型\n
*     LQ_TI_UINT32_UQ28_TO_FLOAT  TI方式UINT32的UQ28转化浮点类型\n
*     LQ_TI_UINT32_UQ27_TO_FLOAT  TI方式UINT32的UQ27转化浮点类型\n
*     LQ_TI_UINT32_UQ26_TO_FLOAT  TI方式UINT32的UQ26转化浮点类型\n
*     LQ_TI_UINT32_UQ25_TO_FLOAT  TI方式UINT32的UQ25转化浮点类型\n
*     LQ_TI_UINT32_UQ24_TO_FLOAT  TI方式UINT32的UQ24转化浮点类型\n
*     LQ_TI_UINT32_UQ23_TO_FLOAT  TI方式UINT32的UQ23转化浮点类型\n
*     LQ_TI_UINT32_UQ22_TO_FLOAT  TI方式UINT32的UQ22转化浮点类型\n
*     LQ_TI_UINT32_UQ21_TO_FLOAT  TI方式UINT32的UQ21转化浮点类型\n
*     LQ_TI_UINT32_UQ20_TO_FLOAT  TI方式UINT32的UQ20转化浮点类型\n
*     LQ_TI_UINT32_UQ19_TO_FLOAT  TI方式UINT32的UQ19转化浮点类型\n
*     LQ_TI_UINT32_UQ18_TO_FLOAT  TI方式UINT32的UQ18转化浮点类型\n
*     LQ_TI_UINT32_UQ17_TO_FLOAT  TI方式UINT32的UQ17转化浮点类型\n
*     LQ_TI_UINT32_UQ16_TO_FLOAT  TI方式UINT32的UQ16转化浮点类型\n
*     LQ_TI_UINT32_UQ15_TO_FLOAT  TI方式UINT32的UQ15转化浮点类型\n
*     LQ_TI_UINT32_UQ14_TO_FLOAT  TI方式UINT32的UQ14转化浮点类型\n
*     LQ_TI_UINT32_UQ13_TO_FLOAT  TI方式UINT32的UQ13转化浮点类型\n
*     LQ_TI_UINT32_UQ12_TO_FLOAT  TI方式UINT32的UQ12转化浮点类型\n
*     LQ_TI_UINT32_UQ11_TO_FLOAT  TI方式UINT32的UQ11转化浮点类型\n
*     LQ_TI_UINT32_UQ10_TO_FLOAT  TI方式UINT32的UQ10转化浮点类型\n
*     LQ_TI_UINT32_UQ9_TO_FLOAT  TI方式UINT32的UQ9转化浮点类型\n
*     LQ_TI_UINT32_UQ8_TO_FLOAT  TI方式UINT32的UQ8转化浮点类型\n
*     LQ_TI_UINT32_UQ7_TO_FLOAT  TI方式UINT32的UQ7转化浮点类型\n
*     LQ_TI_UINT32_UQ6_TO_FLOAT  TI方式UINT32的UQ6转化浮点类型\n
*     LQ_TI_UINT32_UQ5_TO_FLOAT  TI方式UINT32的UQ5转化浮点类型\n
*     LQ_TI_UINT32_UQ4_TO_FLOAT  TI方式UINT32的UQ4转化浮点类型\n
*     LQ_TI_UINT32_UQ3_TO_FLOAT  TI方式UINT32的UQ3转化浮点类型\n
*     LQ_TI_UINT32_UQ2_TO_FLOAT  TI方式UINT32的UQ2转化浮点类型\n
*     LQ_TI_UINT32_UQ1_TO_FLOAT  TI方式UINT32的UQ1转化浮点类型\n
*/
LQ_F_32BIT LQ_TI_UINT32_UQ7_TO_FLOAT(LQ_I_32BIT A, LQ_ERROR* lq_error)
{
    LQ_UI_16BIT ui16Exp;
    LQ_UI_32BIT uiq23Result;
    LQ_UI_32BIT uiq31Input;
    //!< 初始化指数部分偏移量
    ui16Exp = 19328;
    //!< 保存符号位
    if (A < 0)
    {
        ui16Exp |= 0x8000;
        uiq31Input = (LQ_UI_32BIT)(-(LQ_I_64BIT)A);
    }
    else if (A == 0)
    {
        return (0);
    }
    else
    {
        uiq31Input = A;
    }
    LQ_TI_Q2F_NORMALIZE(uiq31Input, ui16Exp);
    /*对uiq31结果进行四舍五入并切换到uiq23*/
    uiq23Result = (LQ_UI_32BIT)(((LQ_UI_64BIT)uiq31Input + 0x0080u) >> 8);
    if (uiq23Result >= 0x01000000u)
    {
        uiq23Result = 0;
        ui16Exp += 0x0080;
    }
    /*删除尾数的隐含MSB位 */
    uiq23Result &= ~0x00800000;
    /*
    *将构造的指数和符号位添加到尾数。我们必须使用
    *四舍五入会导致尾数溢出的情况下的加法。
    *当这种情况发生时，尾数结果为2，其中MSB为零
    *exp的LSB被设置为1。在指数上加一就是
    *尾数为2的正确处理。不需要缩放
    *尾数，因为在这种情况下它总是等于零。
   */
    uiq23Result += (LQ_UI_32BIT)ui16Exp << 16;
    return LQ_TI_UINT32_BITS_TO_FLOAT(uiq23Result);
}
/**@brief (TI方法)UINT32类型UQ6格式转浮点
* @details 采用估算位+指数位+符号位三位结合，能提高精度
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为浮点数
* @code*    LQ_TI_UINT32_UQ6_TO_FLOAT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_UINT32_UQ32_TO_FLOAT  TI方式UINT32的UQ32转化浮点类型\n
*     LQ_TI_UINT32_UQ31_TO_FLOAT  TI方式UINT32的UQ31转化浮点类型\n
*     LQ_TI_UINT32_UQ30_TO_FLOAT  TI方式UINT32的UQ30转化浮点类型\n
*     LQ_TI_UINT32_UQ29_TO_FLOAT  TI方式UINT32的UQ29转化浮点类型\n
*     LQ_TI_UINT32_UQ28_TO_FLOAT  TI方式UINT32的UQ28转化浮点类型\n
*     LQ_TI_UINT32_UQ27_TO_FLOAT  TI方式UINT32的UQ27转化浮点类型\n
*     LQ_TI_UINT32_UQ26_TO_FLOAT  TI方式UINT32的UQ26转化浮点类型\n
*     LQ_TI_UINT32_UQ25_TO_FLOAT  TI方式UINT32的UQ25转化浮点类型\n
*     LQ_TI_UINT32_UQ24_TO_FLOAT  TI方式UINT32的UQ24转化浮点类型\n
*     LQ_TI_UINT32_UQ23_TO_FLOAT  TI方式UINT32的UQ23转化浮点类型\n
*     LQ_TI_UINT32_UQ22_TO_FLOAT  TI方式UINT32的UQ22转化浮点类型\n
*     LQ_TI_UINT32_UQ21_TO_FLOAT  TI方式UINT32的UQ21转化浮点类型\n
*     LQ_TI_UINT32_UQ20_TO_FLOAT  TI方式UINT32的UQ20转化浮点类型\n
*     LQ_TI_UINT32_UQ19_TO_FLOAT  TI方式UINT32的UQ19转化浮点类型\n
*     LQ_TI_UINT32_UQ18_TO_FLOAT  TI方式UINT32的UQ18转化浮点类型\n
*     LQ_TI_UINT32_UQ17_TO_FLOAT  TI方式UINT32的UQ17转化浮点类型\n
*     LQ_TI_UINT32_UQ16_TO_FLOAT  TI方式UINT32的UQ16转化浮点类型\n
*     LQ_TI_UINT32_UQ15_TO_FLOAT  TI方式UINT32的UQ15转化浮点类型\n
*     LQ_TI_UINT32_UQ14_TO_FLOAT  TI方式UINT32的UQ14转化浮点类型\n
*     LQ_TI_UINT32_UQ13_TO_FLOAT  TI方式UINT32的UQ13转化浮点类型\n
*     LQ_TI_UINT32_UQ12_TO_FLOAT  TI方式UINT32的UQ12转化浮点类型\n
*     LQ_TI_UINT32_UQ11_TO_FLOAT  TI方式UINT32的UQ11转化浮点类型\n
*     LQ_TI_UINT32_UQ10_TO_FLOAT  TI方式UINT32的UQ10转化浮点类型\n
*     LQ_TI_UINT32_UQ9_TO_FLOAT  TI方式UINT32的UQ9转化浮点类型\n
*     LQ_TI_UINT32_UQ8_TO_FLOAT  TI方式UINT32的UQ8转化浮点类型\n
*     LQ_TI_UINT32_UQ7_TO_FLOAT  TI方式UINT32的UQ7转化浮点类型\n
*     LQ_TI_UINT32_UQ6_TO_FLOAT  TI方式UINT32的UQ6转化浮点类型\n
*     LQ_TI_UINT32_UQ5_TO_FLOAT  TI方式UINT32的UQ5转化浮点类型\n
*     LQ_TI_UINT32_UQ4_TO_FLOAT  TI方式UINT32的UQ4转化浮点类型\n
*     LQ_TI_UINT32_UQ3_TO_FLOAT  TI方式UINT32的UQ3转化浮点类型\n
*     LQ_TI_UINT32_UQ2_TO_FLOAT  TI方式UINT32的UQ2转化浮点类型\n
*     LQ_TI_UINT32_UQ1_TO_FLOAT  TI方式UINT32的UQ1转化浮点类型\n
*/
LQ_F_32BIT LQ_TI_UINT32_UQ6_TO_FLOAT(LQ_I_32BIT A, LQ_ERROR* lq_error)
{
    LQ_UI_16BIT ui16Exp;
    LQ_UI_32BIT uiq23Result;
    LQ_UI_32BIT uiq31Input;
    //!< 初始化指数部分偏移量
    ui16Exp = 19456;
    //!< 保存符号位
    if (A < 0)
    {
        ui16Exp |= 0x8000;
        uiq31Input = (LQ_UI_32BIT)(-(LQ_I_64BIT)A);
    }
    else if (A == 0)
    {
        return (0);
    }
    else
    {
        uiq31Input = A;
    }
    LQ_TI_Q2F_NORMALIZE(uiq31Input, ui16Exp);
    /*对uiq31结果进行四舍五入并切换到uiq23*/
    uiq23Result = (LQ_UI_32BIT)(((LQ_UI_64BIT)uiq31Input + 0x0080u) >> 8);
    if (uiq23Result >= 0x01000000u)
    {
        uiq23Result = 0;
        ui16Exp += 0x0080;
    }
    /*删除尾数的隐含MSB位 */
    uiq23Result &= ~0x00800000;
    /*
    *将构造的指数和符号位添加到尾数。我们必须使用
    *四舍五入会导致尾数溢出的情况下的加法。
    *当这种情况发生时，尾数结果为2，其中MSB为零
    *exp的LSB被设置为1。在指数上加一就是
    *尾数为2的正确处理。不需要缩放
    *尾数，因为在这种情况下它总是等于零。
   */
    uiq23Result += (LQ_UI_32BIT)ui16Exp << 16;
    return LQ_TI_UINT32_BITS_TO_FLOAT(uiq23Result);
}
/**@brief (TI方法)UINT32类型UQ5格式转浮点
* @details 采用估算位+指数位+符号位三位结合，能提高精度
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为浮点数
* @code*    LQ_TI_UINT32_UQ5_TO_FLOAT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_UINT32_UQ32_TO_FLOAT  TI方式UINT32的UQ32转化浮点类型\n
*     LQ_TI_UINT32_UQ31_TO_FLOAT  TI方式UINT32的UQ31转化浮点类型\n
*     LQ_TI_UINT32_UQ30_TO_FLOAT  TI方式UINT32的UQ30转化浮点类型\n
*     LQ_TI_UINT32_UQ29_TO_FLOAT  TI方式UINT32的UQ29转化浮点类型\n
*     LQ_TI_UINT32_UQ28_TO_FLOAT  TI方式UINT32的UQ28转化浮点类型\n
*     LQ_TI_UINT32_UQ27_TO_FLOAT  TI方式UINT32的UQ27转化浮点类型\n
*     LQ_TI_UINT32_UQ26_TO_FLOAT  TI方式UINT32的UQ26转化浮点类型\n
*     LQ_TI_UINT32_UQ25_TO_FLOAT  TI方式UINT32的UQ25转化浮点类型\n
*     LQ_TI_UINT32_UQ24_TO_FLOAT  TI方式UINT32的UQ24转化浮点类型\n
*     LQ_TI_UINT32_UQ23_TO_FLOAT  TI方式UINT32的UQ23转化浮点类型\n
*     LQ_TI_UINT32_UQ22_TO_FLOAT  TI方式UINT32的UQ22转化浮点类型\n
*     LQ_TI_UINT32_UQ21_TO_FLOAT  TI方式UINT32的UQ21转化浮点类型\n
*     LQ_TI_UINT32_UQ20_TO_FLOAT  TI方式UINT32的UQ20转化浮点类型\n
*     LQ_TI_UINT32_UQ19_TO_FLOAT  TI方式UINT32的UQ19转化浮点类型\n
*     LQ_TI_UINT32_UQ18_TO_FLOAT  TI方式UINT32的UQ18转化浮点类型\n
*     LQ_TI_UINT32_UQ17_TO_FLOAT  TI方式UINT32的UQ17转化浮点类型\n
*     LQ_TI_UINT32_UQ16_TO_FLOAT  TI方式UINT32的UQ16转化浮点类型\n
*     LQ_TI_UINT32_UQ15_TO_FLOAT  TI方式UINT32的UQ15转化浮点类型\n
*     LQ_TI_UINT32_UQ14_TO_FLOAT  TI方式UINT32的UQ14转化浮点类型\n
*     LQ_TI_UINT32_UQ13_TO_FLOAT  TI方式UINT32的UQ13转化浮点类型\n
*     LQ_TI_UINT32_UQ12_TO_FLOAT  TI方式UINT32的UQ12转化浮点类型\n
*     LQ_TI_UINT32_UQ11_TO_FLOAT  TI方式UINT32的UQ11转化浮点类型\n
*     LQ_TI_UINT32_UQ10_TO_FLOAT  TI方式UINT32的UQ10转化浮点类型\n
*     LQ_TI_UINT32_UQ9_TO_FLOAT  TI方式UINT32的UQ9转化浮点类型\n
*     LQ_TI_UINT32_UQ8_TO_FLOAT  TI方式UINT32的UQ8转化浮点类型\n
*     LQ_TI_UINT32_UQ7_TO_FLOAT  TI方式UINT32的UQ7转化浮点类型\n
*     LQ_TI_UINT32_UQ6_TO_FLOAT  TI方式UINT32的UQ6转化浮点类型\n
*     LQ_TI_UINT32_UQ5_TO_FLOAT  TI方式UINT32的UQ5转化浮点类型\n
*     LQ_TI_UINT32_UQ4_TO_FLOAT  TI方式UINT32的UQ4转化浮点类型\n
*     LQ_TI_UINT32_UQ3_TO_FLOAT  TI方式UINT32的UQ3转化浮点类型\n
*     LQ_TI_UINT32_UQ2_TO_FLOAT  TI方式UINT32的UQ2转化浮点类型\n
*     LQ_TI_UINT32_UQ1_TO_FLOAT  TI方式UINT32的UQ1转化浮点类型\n
*/
LQ_F_32BIT LQ_TI_UINT32_UQ5_TO_FLOAT(LQ_I_32BIT A, LQ_ERROR* lq_error)
{
    LQ_UI_16BIT ui16Exp;
    LQ_UI_32BIT uiq23Result;
    LQ_UI_32BIT uiq31Input;
    //!< 初始化指数部分偏移量
    ui16Exp = 19584;
    //!< 保存符号位
    if (A < 0)
    {
        ui16Exp |= 0x8000;
        uiq31Input = (LQ_UI_32BIT)(-(LQ_I_64BIT)A);
    }
    else if (A == 0)
    {
        return (0);
    }
    else
    {
        uiq31Input = A;
    }
    LQ_TI_Q2F_NORMALIZE(uiq31Input, ui16Exp);
    /*对uiq31结果进行四舍五入并切换到uiq23*/
    uiq23Result = (LQ_UI_32BIT)(((LQ_UI_64BIT)uiq31Input + 0x0080u) >> 8);
    if (uiq23Result >= 0x01000000u)
    {
        uiq23Result = 0;
        ui16Exp += 0x0080;
    }
    /*删除尾数的隐含MSB位 */
    uiq23Result &= ~0x00800000;
    /*
    *将构造的指数和符号位添加到尾数。我们必须使用
    *四舍五入会导致尾数溢出的情况下的加法。
    *当这种情况发生时，尾数结果为2，其中MSB为零
    *exp的LSB被设置为1。在指数上加一就是
    *尾数为2的正确处理。不需要缩放
    *尾数，因为在这种情况下它总是等于零。
   */
    uiq23Result += (LQ_UI_32BIT)ui16Exp << 16;
    return LQ_TI_UINT32_BITS_TO_FLOAT(uiq23Result);
}
/**@brief (TI方法)UINT32类型UQ4格式转浮点
* @details 采用估算位+指数位+符号位三位结合，能提高精度
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为浮点数
* @code*    LQ_TI_UINT32_UQ4_TO_FLOAT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_UINT32_UQ32_TO_FLOAT  TI方式UINT32的UQ32转化浮点类型\n
*     LQ_TI_UINT32_UQ31_TO_FLOAT  TI方式UINT32的UQ31转化浮点类型\n
*     LQ_TI_UINT32_UQ30_TO_FLOAT  TI方式UINT32的UQ30转化浮点类型\n
*     LQ_TI_UINT32_UQ29_TO_FLOAT  TI方式UINT32的UQ29转化浮点类型\n
*     LQ_TI_UINT32_UQ28_TO_FLOAT  TI方式UINT32的UQ28转化浮点类型\n
*     LQ_TI_UINT32_UQ27_TO_FLOAT  TI方式UINT32的UQ27转化浮点类型\n
*     LQ_TI_UINT32_UQ26_TO_FLOAT  TI方式UINT32的UQ26转化浮点类型\n
*     LQ_TI_UINT32_UQ25_TO_FLOAT  TI方式UINT32的UQ25转化浮点类型\n
*     LQ_TI_UINT32_UQ24_TO_FLOAT  TI方式UINT32的UQ24转化浮点类型\n
*     LQ_TI_UINT32_UQ23_TO_FLOAT  TI方式UINT32的UQ23转化浮点类型\n
*     LQ_TI_UINT32_UQ22_TO_FLOAT  TI方式UINT32的UQ22转化浮点类型\n
*     LQ_TI_UINT32_UQ21_TO_FLOAT  TI方式UINT32的UQ21转化浮点类型\n
*     LQ_TI_UINT32_UQ20_TO_FLOAT  TI方式UINT32的UQ20转化浮点类型\n
*     LQ_TI_UINT32_UQ19_TO_FLOAT  TI方式UINT32的UQ19转化浮点类型\n
*     LQ_TI_UINT32_UQ18_TO_FLOAT  TI方式UINT32的UQ18转化浮点类型\n
*     LQ_TI_UINT32_UQ17_TO_FLOAT  TI方式UINT32的UQ17转化浮点类型\n
*     LQ_TI_UINT32_UQ16_TO_FLOAT  TI方式UINT32的UQ16转化浮点类型\n
*     LQ_TI_UINT32_UQ15_TO_FLOAT  TI方式UINT32的UQ15转化浮点类型\n
*     LQ_TI_UINT32_UQ14_TO_FLOAT  TI方式UINT32的UQ14转化浮点类型\n
*     LQ_TI_UINT32_UQ13_TO_FLOAT  TI方式UINT32的UQ13转化浮点类型\n
*     LQ_TI_UINT32_UQ12_TO_FLOAT  TI方式UINT32的UQ12转化浮点类型\n
*     LQ_TI_UINT32_UQ11_TO_FLOAT  TI方式UINT32的UQ11转化浮点类型\n
*     LQ_TI_UINT32_UQ10_TO_FLOAT  TI方式UINT32的UQ10转化浮点类型\n
*     LQ_TI_UINT32_UQ9_TO_FLOAT  TI方式UINT32的UQ9转化浮点类型\n
*     LQ_TI_UINT32_UQ8_TO_FLOAT  TI方式UINT32的UQ8转化浮点类型\n
*     LQ_TI_UINT32_UQ7_TO_FLOAT  TI方式UINT32的UQ7转化浮点类型\n
*     LQ_TI_UINT32_UQ6_TO_FLOAT  TI方式UINT32的UQ6转化浮点类型\n
*     LQ_TI_UINT32_UQ5_TO_FLOAT  TI方式UINT32的UQ5转化浮点类型\n
*     LQ_TI_UINT32_UQ4_TO_FLOAT  TI方式UINT32的UQ4转化浮点类型\n
*     LQ_TI_UINT32_UQ3_TO_FLOAT  TI方式UINT32的UQ3转化浮点类型\n
*     LQ_TI_UINT32_UQ2_TO_FLOAT  TI方式UINT32的UQ2转化浮点类型\n
*     LQ_TI_UINT32_UQ1_TO_FLOAT  TI方式UINT32的UQ1转化浮点类型\n
*/
LQ_F_32BIT LQ_TI_UINT32_UQ4_TO_FLOAT(LQ_I_32BIT A, LQ_ERROR* lq_error)
{
    LQ_UI_16BIT ui16Exp;
    LQ_UI_32BIT uiq23Result;
    LQ_UI_32BIT uiq31Input;
    //!< 初始化指数部分偏移量
    ui16Exp = 19712;
    //!< 保存符号位
    if (A < 0)
    {
        ui16Exp |= 0x8000;
        uiq31Input = (LQ_UI_32BIT)(-(LQ_I_64BIT)A);
    }
    else if (A == 0)
    {
        return (0);
    }
    else
    {
        uiq31Input = A;
    }
    LQ_TI_Q2F_NORMALIZE(uiq31Input, ui16Exp);
    /*对uiq31结果进行四舍五入并切换到uiq23*/
    uiq23Result = (LQ_UI_32BIT)(((LQ_UI_64BIT)uiq31Input + 0x0080u) >> 8);
    if (uiq23Result >= 0x01000000u)
    {
        uiq23Result = 0;
        ui16Exp += 0x0080;
    }
    /*删除尾数的隐含MSB位 */
    uiq23Result &= ~0x00800000;
    /*
    *将构造的指数和符号位添加到尾数。我们必须使用
    *四舍五入会导致尾数溢出的情况下的加法。
    *当这种情况发生时，尾数结果为2，其中MSB为零
    *exp的LSB被设置为1。在指数上加一就是
    *尾数为2的正确处理。不需要缩放
    *尾数，因为在这种情况下它总是等于零。
   */
    uiq23Result += (LQ_UI_32BIT)ui16Exp << 16;
    return LQ_TI_UINT32_BITS_TO_FLOAT(uiq23Result);
}
/**@brief (TI方法)UINT32类型UQ3格式转浮点
* @details 采用估算位+指数位+符号位三位结合，能提高精度
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为浮点数
* @code*    LQ_TI_UINT32_UQ3_TO_FLOAT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_UINT32_UQ32_TO_FLOAT  TI方式UINT32的UQ32转化浮点类型\n
*     LQ_TI_UINT32_UQ31_TO_FLOAT  TI方式UINT32的UQ31转化浮点类型\n
*     LQ_TI_UINT32_UQ30_TO_FLOAT  TI方式UINT32的UQ30转化浮点类型\n
*     LQ_TI_UINT32_UQ29_TO_FLOAT  TI方式UINT32的UQ29转化浮点类型\n
*     LQ_TI_UINT32_UQ28_TO_FLOAT  TI方式UINT32的UQ28转化浮点类型\n
*     LQ_TI_UINT32_UQ27_TO_FLOAT  TI方式UINT32的UQ27转化浮点类型\n
*     LQ_TI_UINT32_UQ26_TO_FLOAT  TI方式UINT32的UQ26转化浮点类型\n
*     LQ_TI_UINT32_UQ25_TO_FLOAT  TI方式UINT32的UQ25转化浮点类型\n
*     LQ_TI_UINT32_UQ24_TO_FLOAT  TI方式UINT32的UQ24转化浮点类型\n
*     LQ_TI_UINT32_UQ23_TO_FLOAT  TI方式UINT32的UQ23转化浮点类型\n
*     LQ_TI_UINT32_UQ22_TO_FLOAT  TI方式UINT32的UQ22转化浮点类型\n
*     LQ_TI_UINT32_UQ21_TO_FLOAT  TI方式UINT32的UQ21转化浮点类型\n
*     LQ_TI_UINT32_UQ20_TO_FLOAT  TI方式UINT32的UQ20转化浮点类型\n
*     LQ_TI_UINT32_UQ19_TO_FLOAT  TI方式UINT32的UQ19转化浮点类型\n
*     LQ_TI_UINT32_UQ18_TO_FLOAT  TI方式UINT32的UQ18转化浮点类型\n
*     LQ_TI_UINT32_UQ17_TO_FLOAT  TI方式UINT32的UQ17转化浮点类型\n
*     LQ_TI_UINT32_UQ16_TO_FLOAT  TI方式UINT32的UQ16转化浮点类型\n
*     LQ_TI_UINT32_UQ15_TO_FLOAT  TI方式UINT32的UQ15转化浮点类型\n
*     LQ_TI_UINT32_UQ14_TO_FLOAT  TI方式UINT32的UQ14转化浮点类型\n
*     LQ_TI_UINT32_UQ13_TO_FLOAT  TI方式UINT32的UQ13转化浮点类型\n
*     LQ_TI_UINT32_UQ12_TO_FLOAT  TI方式UINT32的UQ12转化浮点类型\n
*     LQ_TI_UINT32_UQ11_TO_FLOAT  TI方式UINT32的UQ11转化浮点类型\n
*     LQ_TI_UINT32_UQ10_TO_FLOAT  TI方式UINT32的UQ10转化浮点类型\n
*     LQ_TI_UINT32_UQ9_TO_FLOAT  TI方式UINT32的UQ9转化浮点类型\n
*     LQ_TI_UINT32_UQ8_TO_FLOAT  TI方式UINT32的UQ8转化浮点类型\n
*     LQ_TI_UINT32_UQ7_TO_FLOAT  TI方式UINT32的UQ7转化浮点类型\n
*     LQ_TI_UINT32_UQ6_TO_FLOAT  TI方式UINT32的UQ6转化浮点类型\n
*     LQ_TI_UINT32_UQ5_TO_FLOAT  TI方式UINT32的UQ5转化浮点类型\n
*     LQ_TI_UINT32_UQ4_TO_FLOAT  TI方式UINT32的UQ4转化浮点类型\n
*     LQ_TI_UINT32_UQ3_TO_FLOAT  TI方式UINT32的UQ3转化浮点类型\n
*     LQ_TI_UINT32_UQ2_TO_FLOAT  TI方式UINT32的UQ2转化浮点类型\n
*     LQ_TI_UINT32_UQ1_TO_FLOAT  TI方式UINT32的UQ1转化浮点类型\n
*/
LQ_F_32BIT LQ_TI_UINT32_UQ3_TO_FLOAT(LQ_I_32BIT A, LQ_ERROR* lq_error)
{
    LQ_UI_16BIT ui16Exp;
    LQ_UI_32BIT uiq23Result;
    LQ_UI_32BIT uiq31Input;
    //!< 初始化指数部分偏移量
    ui16Exp = 19840;
    //!< 保存符号位
    if (A < 0)
    {
        ui16Exp |= 0x8000;
        uiq31Input = (LQ_UI_32BIT)(-(LQ_I_64BIT)A);
    }
    else if (A == 0)
    {
        return (0);
    }
    else
    {
        uiq31Input = A;
    }
    LQ_TI_Q2F_NORMALIZE(uiq31Input, ui16Exp);
    /*对uiq31结果进行四舍五入并切换到uiq23*/
    uiq23Result = (LQ_UI_32BIT)(((LQ_UI_64BIT)uiq31Input + 0x0080u) >> 8);
    if (uiq23Result >= 0x01000000u)
    {
        uiq23Result = 0;
        ui16Exp += 0x0080;
    }
    /*删除尾数的隐含MSB位 */
    uiq23Result &= ~0x00800000;
    /*
    *将构造的指数和符号位添加到尾数。我们必须使用
    *四舍五入会导致尾数溢出的情况下的加法。
    *当这种情况发生时，尾数结果为2，其中MSB为零
    *exp的LSB被设置为1。在指数上加一就是
    *尾数为2的正确处理。不需要缩放
    *尾数，因为在这种情况下它总是等于零。
   */
    uiq23Result += (LQ_UI_32BIT)ui16Exp << 16;
    return LQ_TI_UINT32_BITS_TO_FLOAT(uiq23Result);
}
/**@brief (TI方法)UINT32类型UQ2格式转浮点
* @details 采用估算位+指数位+符号位三位结合，能提高精度
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为浮点数
* @code*    LQ_TI_UINT32_UQ2_TO_FLOAT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_UINT32_UQ32_TO_FLOAT  TI方式UINT32的UQ32转化浮点类型\n
*     LQ_TI_UINT32_UQ31_TO_FLOAT  TI方式UINT32的UQ31转化浮点类型\n
*     LQ_TI_UINT32_UQ30_TO_FLOAT  TI方式UINT32的UQ30转化浮点类型\n
*     LQ_TI_UINT32_UQ29_TO_FLOAT  TI方式UINT32的UQ29转化浮点类型\n
*     LQ_TI_UINT32_UQ28_TO_FLOAT  TI方式UINT32的UQ28转化浮点类型\n
*     LQ_TI_UINT32_UQ27_TO_FLOAT  TI方式UINT32的UQ27转化浮点类型\n
*     LQ_TI_UINT32_UQ26_TO_FLOAT  TI方式UINT32的UQ26转化浮点类型\n
*     LQ_TI_UINT32_UQ25_TO_FLOAT  TI方式UINT32的UQ25转化浮点类型\n
*     LQ_TI_UINT32_UQ24_TO_FLOAT  TI方式UINT32的UQ24转化浮点类型\n
*     LQ_TI_UINT32_UQ23_TO_FLOAT  TI方式UINT32的UQ23转化浮点类型\n
*     LQ_TI_UINT32_UQ22_TO_FLOAT  TI方式UINT32的UQ22转化浮点类型\n
*     LQ_TI_UINT32_UQ21_TO_FLOAT  TI方式UINT32的UQ21转化浮点类型\n
*     LQ_TI_UINT32_UQ20_TO_FLOAT  TI方式UINT32的UQ20转化浮点类型\n
*     LQ_TI_UINT32_UQ19_TO_FLOAT  TI方式UINT32的UQ19转化浮点类型\n
*     LQ_TI_UINT32_UQ18_TO_FLOAT  TI方式UINT32的UQ18转化浮点类型\n
*     LQ_TI_UINT32_UQ17_TO_FLOAT  TI方式UINT32的UQ17转化浮点类型\n
*     LQ_TI_UINT32_UQ16_TO_FLOAT  TI方式UINT32的UQ16转化浮点类型\n
*     LQ_TI_UINT32_UQ15_TO_FLOAT  TI方式UINT32的UQ15转化浮点类型\n
*     LQ_TI_UINT32_UQ14_TO_FLOAT  TI方式UINT32的UQ14转化浮点类型\n
*     LQ_TI_UINT32_UQ13_TO_FLOAT  TI方式UINT32的UQ13转化浮点类型\n
*     LQ_TI_UINT32_UQ12_TO_FLOAT  TI方式UINT32的UQ12转化浮点类型\n
*     LQ_TI_UINT32_UQ11_TO_FLOAT  TI方式UINT32的UQ11转化浮点类型\n
*     LQ_TI_UINT32_UQ10_TO_FLOAT  TI方式UINT32的UQ10转化浮点类型\n
*     LQ_TI_UINT32_UQ9_TO_FLOAT  TI方式UINT32的UQ9转化浮点类型\n
*     LQ_TI_UINT32_UQ8_TO_FLOAT  TI方式UINT32的UQ8转化浮点类型\n
*     LQ_TI_UINT32_UQ7_TO_FLOAT  TI方式UINT32的UQ7转化浮点类型\n
*     LQ_TI_UINT32_UQ6_TO_FLOAT  TI方式UINT32的UQ6转化浮点类型\n
*     LQ_TI_UINT32_UQ5_TO_FLOAT  TI方式UINT32的UQ5转化浮点类型\n
*     LQ_TI_UINT32_UQ4_TO_FLOAT  TI方式UINT32的UQ4转化浮点类型\n
*     LQ_TI_UINT32_UQ3_TO_FLOAT  TI方式UINT32的UQ3转化浮点类型\n
*     LQ_TI_UINT32_UQ2_TO_FLOAT  TI方式UINT32的UQ2转化浮点类型\n
*     LQ_TI_UINT32_UQ1_TO_FLOAT  TI方式UINT32的UQ1转化浮点类型\n
*/
LQ_F_32BIT LQ_TI_UINT32_UQ2_TO_FLOAT(LQ_I_32BIT A, LQ_ERROR* lq_error)
{
    LQ_UI_16BIT ui16Exp;
    LQ_UI_32BIT uiq23Result;
    LQ_UI_32BIT uiq31Input;
    //!< 初始化指数部分偏移量
    ui16Exp = 19968;
    //!< 保存符号位
    if (A < 0)
    {
        ui16Exp |= 0x8000;
        uiq31Input = (LQ_UI_32BIT)(-(LQ_I_64BIT)A);
    }
    else if (A == 0)
    {
        return (0);
    }
    else
    {
        uiq31Input = A;
    }
    LQ_TI_Q2F_NORMALIZE(uiq31Input, ui16Exp);
    /*对uiq31结果进行四舍五入并切换到uiq23*/
    uiq23Result = (LQ_UI_32BIT)(((LQ_UI_64BIT)uiq31Input + 0x0080u) >> 8);
    if (uiq23Result >= 0x01000000u)
    {
        uiq23Result = 0;
        ui16Exp += 0x0080;
    }
    /*删除尾数的隐含MSB位 */
    uiq23Result &= ~0x00800000;
    /*
    *将构造的指数和符号位添加到尾数。我们必须使用
    *四舍五入会导致尾数溢出的情况下的加法。
    *当这种情况发生时，尾数结果为2，其中MSB为零
    *exp的LSB被设置为1。在指数上加一就是
    *尾数为2的正确处理。不需要缩放
    *尾数，因为在这种情况下它总是等于零。
   */
    uiq23Result += (LQ_UI_32BIT)ui16Exp << 16;
    return LQ_TI_UINT32_BITS_TO_FLOAT(uiq23Result);
}
/**@brief (TI方法)UINT32类型UQ1格式转浮点
* @details 采用估算位+指数位+符号位三位结合，能提高精度
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为浮点数
* @code*    LQ_TI_UINT32_UQ1_TO_FLOAT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_UINT32_UQ32_TO_FLOAT  TI方式UINT32的UQ32转化浮点类型\n
*     LQ_TI_UINT32_UQ31_TO_FLOAT  TI方式UINT32的UQ31转化浮点类型\n
*     LQ_TI_UINT32_UQ30_TO_FLOAT  TI方式UINT32的UQ30转化浮点类型\n
*     LQ_TI_UINT32_UQ29_TO_FLOAT  TI方式UINT32的UQ29转化浮点类型\n
*     LQ_TI_UINT32_UQ28_TO_FLOAT  TI方式UINT32的UQ28转化浮点类型\n
*     LQ_TI_UINT32_UQ27_TO_FLOAT  TI方式UINT32的UQ27转化浮点类型\n
*     LQ_TI_UINT32_UQ26_TO_FLOAT  TI方式UINT32的UQ26转化浮点类型\n
*     LQ_TI_UINT32_UQ25_TO_FLOAT  TI方式UINT32的UQ25转化浮点类型\n
*     LQ_TI_UINT32_UQ24_TO_FLOAT  TI方式UINT32的UQ24转化浮点类型\n
*     LQ_TI_UINT32_UQ23_TO_FLOAT  TI方式UINT32的UQ23转化浮点类型\n
*     LQ_TI_UINT32_UQ22_TO_FLOAT  TI方式UINT32的UQ22转化浮点类型\n
*     LQ_TI_UINT32_UQ21_TO_FLOAT  TI方式UINT32的UQ21转化浮点类型\n
*     LQ_TI_UINT32_UQ20_TO_FLOAT  TI方式UINT32的UQ20转化浮点类型\n
*     LQ_TI_UINT32_UQ19_TO_FLOAT  TI方式UINT32的UQ19转化浮点类型\n
*     LQ_TI_UINT32_UQ18_TO_FLOAT  TI方式UINT32的UQ18转化浮点类型\n
*     LQ_TI_UINT32_UQ17_TO_FLOAT  TI方式UINT32的UQ17转化浮点类型\n
*     LQ_TI_UINT32_UQ16_TO_FLOAT  TI方式UINT32的UQ16转化浮点类型\n
*     LQ_TI_UINT32_UQ15_TO_FLOAT  TI方式UINT32的UQ15转化浮点类型\n
*     LQ_TI_UINT32_UQ14_TO_FLOAT  TI方式UINT32的UQ14转化浮点类型\n
*     LQ_TI_UINT32_UQ13_TO_FLOAT  TI方式UINT32的UQ13转化浮点类型\n
*     LQ_TI_UINT32_UQ12_TO_FLOAT  TI方式UINT32的UQ12转化浮点类型\n
*     LQ_TI_UINT32_UQ11_TO_FLOAT  TI方式UINT32的UQ11转化浮点类型\n
*     LQ_TI_UINT32_UQ10_TO_FLOAT  TI方式UINT32的UQ10转化浮点类型\n
*     LQ_TI_UINT32_UQ9_TO_FLOAT  TI方式UINT32的UQ9转化浮点类型\n
*     LQ_TI_UINT32_UQ8_TO_FLOAT  TI方式UINT32的UQ8转化浮点类型\n
*     LQ_TI_UINT32_UQ7_TO_FLOAT  TI方式UINT32的UQ7转化浮点类型\n
*     LQ_TI_UINT32_UQ6_TO_FLOAT  TI方式UINT32的UQ6转化浮点类型\n
*     LQ_TI_UINT32_UQ5_TO_FLOAT  TI方式UINT32的UQ5转化浮点类型\n
*     LQ_TI_UINT32_UQ4_TO_FLOAT  TI方式UINT32的UQ4转化浮点类型\n
*     LQ_TI_UINT32_UQ3_TO_FLOAT  TI方式UINT32的UQ3转化浮点类型\n
*     LQ_TI_UINT32_UQ2_TO_FLOAT  TI方式UINT32的UQ2转化浮点类型\n
*     LQ_TI_UINT32_UQ1_TO_FLOAT  TI方式UINT32的UQ1转化浮点类型\n
*/
LQ_F_32BIT LQ_TI_UINT32_UQ1_TO_FLOAT(LQ_I_32BIT A, LQ_ERROR* lq_error)
{
    LQ_UI_16BIT ui16Exp;
    LQ_UI_32BIT uiq23Result;
    LQ_UI_32BIT uiq31Input;
    //!< 初始化指数部分偏移量
    ui16Exp = 20096;
    //!< 保存符号位
    if (A < 0)
    {
        ui16Exp |= 0x8000;
        uiq31Input = (LQ_UI_32BIT)(-(LQ_I_64BIT)A);
    }
    else if (A == 0)
    {
        return (0);
    }
    else
    {
        uiq31Input = A;
    }
    LQ_TI_Q2F_NORMALIZE(uiq31Input, ui16Exp);
    /*对uiq31结果进行四舍五入并切换到uiq23*/
    uiq23Result = (LQ_UI_32BIT)(((LQ_UI_64BIT)uiq31Input + 0x0080u) >> 8);
    if (uiq23Result >= 0x01000000u)
    {
        uiq23Result = 0;
        ui16Exp += 0x0080;
    }
    /*删除尾数的隐含MSB位 */
    uiq23Result &= ~0x00800000;
    /*
    *将构造的指数和符号位添加到尾数。我们必须使用
    *四舍五入会导致尾数溢出的情况下的加法。
    *当这种情况发生时，尾数结果为2，其中MSB为零
    *exp的LSB被设置为1。在指数上加一就是
    *尾数为2的正确处理。不需要缩放
    *尾数，因为在这种情况下它总是等于零。
   */
    uiq23Result += (LQ_UI_32BIT)ui16Exp << 16;
    return LQ_TI_UINT32_BITS_TO_FLOAT(uiq23Result);
}
/**@brief (TI方法)INT8类型Q格式转浮点
* @details 采用估算位+指数位+符号位三位结合，能提高精度
* @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_UI_8BIT    Q_A             输入Q格式值
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为浮点数
* @code*    LQ_TI_INT8_Q_TO_FLOAT(a,Q_A,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_INT8_Q_TO_FLOAT  TI方式INT8的Q转化浮点类型\n
*/
LQ_F_32BIT LQ_TI_INT8_Q_TO_FLOAT(LQ_I_32BIT A, LQ_UI_8BIT Q_A, LQ_ERROR* lq_error)
{
    LQ_UI_16BIT ui16Exp;
    LQ_UI_32BIT uiq23Result;
    LQ_UI_32BIT uiq31Input;
    if (Q_A > 32u)
    {
        (*lq_error) = LQ_Q_FORMAT_PARAMETER_ERROR;
        return (0.0f);
    }
    //!< 初始化指数部分偏移量
    ui16Exp = 0x3f80 + ((31 - Q_A) * ((LQ_UI_8BIT)1 << (23 - 16)));
    //!< 保存符号位
    if (A < 0)
    {
        ui16Exp |= 0x8000;
        uiq31Input = (LQ_UI_32BIT)(-(LQ_I_64BIT)A);
    }
    else if (A == 0)
    {
        return (0);
    }
    else
    {
        uiq31Input = A;
    }
    LQ_TI_Q2F_NORMALIZE(uiq31Input, ui16Exp);
    /*对uiq31结果进行四舍五入并切换到uiq23*/
    uiq23Result = (LQ_UI_32BIT)(((LQ_UI_64BIT)uiq31Input + 0x0080u) >> 8);
    if (uiq23Result >= 0x01000000u)
    {
        uiq23Result = 0;
        ui16Exp += 0x0080;
    }
    /*删除尾数的隐含MSB位 */
    uiq23Result &= ~0x00800000;
    /*
    *将构造的指数和符号位添加到尾数。我们必须使用
    *四舍五入会导致尾数溢出的情况下的加法。
    *当这种情况发生时，尾数结果为2，其中MSB为零
    *exp的LSB被设置为1。在指数上加一就是
    *尾数为2的正确处理。不需要缩放
    *尾数，因为在这种情况下它总是等于零。
   */
    uiq23Result += (LQ_UI_32BIT)ui16Exp << 16;
    return LQ_TI_UINT32_BITS_TO_FLOAT(uiq23Result);
}
/**@brief (TI方法)UINT8类型UQ格式转浮点
* @details 采用估算位+指数位+符号位三位结合，能提高精度
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in]  LQ_UI_8BIT     Q_A             输入Q格式值
* @param[in]  LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为浮点数
* @code*    LQ_TI_UINT8_UQ_TO_FLOAT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_UINT8_UQ_TO_FLOAT  TI方式UINT8的UQ转化浮点类型\n
*/
LQ_F_32BIT LQ_TI_UINT8_UQ_TO_FLOAT(LQ_I_32BIT A, LQ_UI_8BIT Q_A, LQ_ERROR* lq_error)
{
    LQ_UI_16BIT ui16Exp;
    LQ_UI_32BIT uiq23Result;
    LQ_UI_32BIT uiq31Input;
    if (Q_A > 32u)
    {
        (*lq_error) = LQ_Q_FORMAT_PARAMETER_ERROR;
        return (0.0f);
    }
    //!< 初始化指数部分偏移量
    ui16Exp = 0x3f80 + ((31 - Q_A) * ((LQ_UI_8BIT)1 << (23 - 16)));
    //!< 保存符号位
    if (A < 0)
    {
        ui16Exp |= 0x8000;
        uiq31Input = (LQ_UI_32BIT)(-(LQ_I_64BIT)A);
    }
    else if (A == 0)
    {
        return (0);
    }
    else
    {
        uiq31Input = A;
    }
    LQ_TI_Q2F_NORMALIZE(uiq31Input, ui16Exp);
    /*对uiq31结果进行四舍五入并切换到uiq23*/
    uiq23Result = (LQ_UI_32BIT)(((LQ_UI_64BIT)uiq31Input + 0x0080u) >> 8);
    if (uiq23Result >= 0x01000000u)
    {
        uiq23Result = 0;
        ui16Exp += 0x0080;
    }
    /*删除尾数的隐含MSB位 */
    uiq23Result &= ~0x00800000;
    /*
    *将构造的指数和符号位添加到尾数。我们必须使用
    *四舍五入会导致尾数溢出的情况下的加法。
    *当这种情况发生时，尾数结果为2，其中MSB为零
    *exp的LSB被设置为1。在指数上加一就是
    *尾数为2的正确处理。不需要缩放
    *尾数，因为在这种情况下它总是等于零。
   */
    uiq23Result += (LQ_UI_32BIT)ui16Exp << 16;
    return LQ_TI_UINT32_BITS_TO_FLOAT(uiq23Result);
}
/**@brief (TI方法)INT16类型Q格式转浮点
* @details 采用估算位+指数位+符号位三位结合，能提高精度
* @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_UI_8BIT    Q_A             输入Q格式值
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为浮点数
* @code*    LQ_TI_INT16_Q_TO_FLOAT(a,Q_A,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_INT16_Q_TO_FLOAT  TI方式INT16的Q转化浮点类型\n
*/
LQ_F_32BIT LQ_TI_INT16_Q_TO_FLOAT(LQ_I_32BIT A, LQ_UI_8BIT Q_A, LQ_ERROR* lq_error)
{
    LQ_UI_16BIT ui16Exp;
    LQ_UI_32BIT uiq23Result;
    LQ_UI_32BIT uiq31Input;
    if (Q_A > 32u)
    {
        (*lq_error) = LQ_Q_FORMAT_PARAMETER_ERROR;
        return (0.0f);
    }
    //!< 初始化指数部分偏移量
    ui16Exp = 0x3f80 + ((31 - Q_A) * ((LQ_UI_16BIT)1 << (23 - 16)));
    //!< 保存符号位
    if (A < 0)
    {
        ui16Exp |= 0x8000;
        uiq31Input = (LQ_UI_32BIT)(-(LQ_I_64BIT)A);
    }
    else if (A == 0)
    {
        return (0);
    }
    else
    {
        uiq31Input = A;
    }
    LQ_TI_Q2F_NORMALIZE(uiq31Input, ui16Exp);
    /*对uiq31结果进行四舍五入并切换到uiq23*/
    uiq23Result = (LQ_UI_32BIT)(((LQ_UI_64BIT)uiq31Input + 0x0080u) >> 8);
    if (uiq23Result >= 0x01000000u)
    {
        uiq23Result = 0;
        ui16Exp += 0x0080;
    }
    /*删除尾数的隐含MSB位 */
    uiq23Result &= ~0x00800000;
    /*
    *将构造的指数和符号位添加到尾数。我们必须使用
    *四舍五入会导致尾数溢出的情况下的加法。
    *当这种情况发生时，尾数结果为2，其中MSB为零
    *exp的LSB被设置为1。在指数上加一就是
    *尾数为2的正确处理。不需要缩放
    *尾数，因为在这种情况下它总是等于零。
   */
    uiq23Result += (LQ_UI_32BIT)ui16Exp << 16;
    return LQ_TI_UINT32_BITS_TO_FLOAT(uiq23Result);
}
/**@brief (TI方法)UINT16类型UQ格式转浮点
* @details 采用估算位+指数位+符号位三位结合，能提高精度
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in]  LQ_UI_8BIT     Q_A             输入Q格式值
* @param[in]  LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为浮点数
* @code*    LQ_TI_UINT16_UQ_TO_FLOAT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_UINT16_UQ_TO_FLOAT  TI方式UINT16的UQ转化浮点类型\n
*/
LQ_F_32BIT LQ_TI_UINT16_UQ_TO_FLOAT(LQ_I_32BIT A, LQ_UI_8BIT Q_A, LQ_ERROR* lq_error)
{
    LQ_UI_16BIT ui16Exp;
    LQ_UI_32BIT uiq23Result;
    LQ_UI_32BIT uiq31Input;
    if (Q_A > 32u)
    {
        (*lq_error) = LQ_Q_FORMAT_PARAMETER_ERROR;
        return (0.0f);
    }
    //!< 初始化指数部分偏移量
    ui16Exp = 0x3f80 + ((31 - Q_A) * ((LQ_UI_16BIT)1 << (23 - 16)));
    //!< 保存符号位
    if (A < 0)
    {
        ui16Exp |= 0x8000;
        uiq31Input = (LQ_UI_32BIT)(-(LQ_I_64BIT)A);
    }
    else if (A == 0)
    {
        return (0);
    }
    else
    {
        uiq31Input = A;
    }
    LQ_TI_Q2F_NORMALIZE(uiq31Input, ui16Exp);
    /*对uiq31结果进行四舍五入并切换到uiq23*/
    uiq23Result = (LQ_UI_32BIT)(((LQ_UI_64BIT)uiq31Input + 0x0080u) >> 8);
    if (uiq23Result >= 0x01000000u)
    {
        uiq23Result = 0;
        ui16Exp += 0x0080;
    }
    /*删除尾数的隐含MSB位 */
    uiq23Result &= ~0x00800000;
    /*
    *将构造的指数和符号位添加到尾数。我们必须使用
    *四舍五入会导致尾数溢出的情况下的加法。
    *当这种情况发生时，尾数结果为2，其中MSB为零
    *exp的LSB被设置为1。在指数上加一就是
    *尾数为2的正确处理。不需要缩放
    *尾数，因为在这种情况下它总是等于零。
   */
    uiq23Result += (LQ_UI_32BIT)ui16Exp << 16;
    return LQ_TI_UINT32_BITS_TO_FLOAT(uiq23Result);
}
/**@brief (TI方法)INT32类型Q格式转浮点
* @details 采用估算位+指数位+符号位三位结合，能提高精度
* @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_UI_8BIT    Q_A             输入Q格式值
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为浮点数
* @code*    LQ_TI_INT32_Q_TO_FLOAT(a,Q_A,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_INT32_Q_TO_FLOAT  TI方式INT32的Q转化浮点类型\n
*/
LQ_F_32BIT LQ_TI_INT32_Q_TO_FLOAT(LQ_I_32BIT A, LQ_UI_8BIT Q_A, LQ_ERROR* lq_error)
{
    LQ_UI_16BIT ui16Exp;
    LQ_UI_32BIT uiq23Result;
    LQ_UI_32BIT uiq31Input;
    if (Q_A > 32u)
    {
        (*lq_error) = LQ_Q_FORMAT_PARAMETER_ERROR;
        return (0.0f);
    }
    //!< 初始化指数部分偏移量
    ui16Exp = 0x3f80 + ((31 - Q_A) * ((LQ_UI_32BIT)1 << (23 - 16)));
    //!< 保存符号位
    if (A < 0)
    {
        ui16Exp |= 0x8000;
        uiq31Input = (LQ_UI_32BIT)(-(LQ_I_64BIT)A);
    }
    else if (A == 0)
    {
        return (0);
    }
    else
    {
        uiq31Input = A;
    }
    LQ_TI_Q2F_NORMALIZE(uiq31Input, ui16Exp);
    /*对uiq31结果进行四舍五入并切换到uiq23*/
    uiq23Result = (LQ_UI_32BIT)(((LQ_UI_64BIT)uiq31Input + 0x0080u) >> 8);
    if (uiq23Result >= 0x01000000u)
    {
        uiq23Result = 0;
        ui16Exp += 0x0080;
    }
    /*删除尾数的隐含MSB位 */
    uiq23Result &= ~0x00800000;
    /*
    *将构造的指数和符号位添加到尾数。我们必须使用
    *四舍五入会导致尾数溢出的情况下的加法。
    *当这种情况发生时，尾数结果为2，其中MSB为零
    *exp的LSB被设置为1。在指数上加一就是
    *尾数为2的正确处理。不需要缩放
    *尾数，因为在这种情况下它总是等于零。
   */
    uiq23Result += (LQ_UI_32BIT)ui16Exp << 16;
    return LQ_TI_UINT32_BITS_TO_FLOAT(uiq23Result);
}
/**@brief (TI方法)UINT32类型UQ格式转浮点
* @details 采用估算位+指数位+符号位三位结合，能提高精度
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in]  LQ_UI_8BIT     Q_A             输入Q格式值
* @param[in]  LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为浮点数
* @code*    LQ_TI_UINT32_UQ_TO_FLOAT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_UINT32_UQ_TO_FLOAT  TI方式UINT32的UQ转化浮点类型\n
*/
LQ_F_32BIT LQ_TI_UINT32_UQ_TO_FLOAT(LQ_I_32BIT A, LQ_UI_8BIT Q_A, LQ_ERROR* lq_error)
{
    LQ_UI_16BIT ui16Exp;
    LQ_UI_32BIT uiq23Result;
    LQ_UI_32BIT uiq31Input;
    if (Q_A > 32u)
    {
        (*lq_error) = LQ_Q_FORMAT_PARAMETER_ERROR;
        return (0.0f);
    }
    //!< 初始化指数部分偏移量
    ui16Exp = 0x3f80 + ((31 - Q_A) * ((LQ_UI_32BIT)1 << (23 - 16)));
    //!< 保存符号位
    if (A < 0)
    {
        ui16Exp |= 0x8000;
        uiq31Input = (LQ_UI_32BIT)(-(LQ_I_64BIT)A);
    }
    else if (A == 0)
    {
        return (0);
    }
    else
    {
        uiq31Input = A;
    }
    LQ_TI_Q2F_NORMALIZE(uiq31Input, ui16Exp);
    /*对uiq31结果进行四舍五入并切换到uiq23*/
    uiq23Result = (LQ_UI_32BIT)(((LQ_UI_64BIT)uiq31Input + 0x0080u) >> 8);
    if (uiq23Result >= 0x01000000u)
    {
        uiq23Result = 0;
        ui16Exp += 0x0080;
    }
    /*删除尾数的隐含MSB位 */
    uiq23Result &= ~0x00800000;
    /*
    *将构造的指数和符号位添加到尾数。我们必须使用
    *四舍五入会导致尾数溢出的情况下的加法。
    *当这种情况发生时，尾数结果为2，其中MSB为零
    *exp的LSB被设置为1。在指数上加一就是
    *尾数为2的正确处理。不需要缩放
    *尾数，因为在这种情况下它总是等于零。
   */
    uiq23Result += (LQ_UI_32BIT)ui16Exp << 16;
    return LQ_TI_UINT32_BITS_TO_FLOAT(uiq23Result);
}
#endif
