#ifndef __LQ_SATURATION_Q_FORMAT_ADD_ARM__
#define __LQ_SATURATION_Q_FORMAT_ADD_ARM__
#include "lq_mode.h"
#include "lq_error.h"
#include "lq_type.h"
#include "lq_arm_dsp.h"
/**@file      lq_saturation_q_format_add_arm.h
* @brief      LittleQmath饱和算法Q格式加法的ARM专用分支
* @details    用ARM的SSAT饱和指令替代比较判断，实现饱和加法的定点加速。\n覆盖INT8(Q1到Q7)、INT16(Q1到Q15)共22个有符号接口。\n只在LQ_ARM_DSP_SSAT_ENABLE为1时编译，否则整个文件为空。
* @author     尹冠华
* @date        2026-11-14
* @version     V2.0
* @copyright    Copyright (c ) 2018-2024  黑龙江大学A8楼514
**********************************************************************************
* @attention
* 硬件平台:带DSP饱和指令的ARM处理器（Cortex-M3及以上） \n
* @par 修改日志:
* <table>
* <tr><th>Date        <th>Version  <th>Author    <th>Description
* <tr><td>2024/03/28  <td>1.0      <td>尹冠华    <td>创建初始版本
* <tr><td>2026/11/14  <td>2.1      <td>尹冠华    <td>新增ARM DSP饱和指令分支
* </table>
*
**********************************************************************************
*/

#if LQ_ARM_DSP_SSAT_ENABLE == 1

/****************************饱和算法 INT8 Q格式加法(ARM)************************************/
/**@brief 饱和算法:INT8类型Q7格式加法(ARM SSAT分支)
* @details 能对加法运算进行检查。\n
* @param[in] LQ_INT8_Q7     A              输入Q格式数
* @param[in] LQ_INT8_Q7     B              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
* @return    A+B的饱和值
* @attention  仅在LQ_ARM_DSP_SSAT_ENABLE为1时参与编译\n
*             用户权限:用户无需调用
*/

LQ_INLINE LQ_INT8_Q7 LQ_ARM_SATURATION_INT8_Q7_ADD(LQ_INT8_Q7 A, LQ_INT8_Q7 B, LQ_ERROR* Lq_Error)
{
    LQ_I_32BIT lq_tmp;
    LQ_I_32BIT lq_sat;
    lq_tmp = (LQ_I_32BIT)(A)+(LQ_I_32BIT)(B);
    lq_sat = (LQ_I_32BIT)LQ_Q_SSAT(lq_tmp, 8);
    if (lq_sat != lq_tmp)
    {
        *Lq_Error = (lq_tmp > 0) ? SATURATION_INT8_Q7_FORMAT_ADD_POSITIVE_OVER : SATURATION_INT8_Q7_FORMAT_ADD_NEGATIVE_OVER;
    }
    return   (LQ_INT8_Q7)lq_sat;
}

/**@brief 饱和算法:INT8类型Q6格式加法(ARM SSAT分支)
* @details 能对加法运算进行检查。\n
* @param[in] LQ_INT8_Q6     A              输入Q格式数
* @param[in] LQ_INT8_Q6     B              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
* @return    A+B的饱和值
* @attention  仅在LQ_ARM_DSP_SSAT_ENABLE为1时参与编译\n
*             用户权限:用户无需调用
*/

LQ_INLINE LQ_INT8_Q6 LQ_ARM_SATURATION_INT8_Q6_ADD(LQ_INT8_Q6 A, LQ_INT8_Q6 B, LQ_ERROR* Lq_Error)
{
    LQ_I_32BIT lq_tmp;
    LQ_I_32BIT lq_sat;
    lq_tmp = (LQ_I_32BIT)(A)+(LQ_I_32BIT)(B);
    lq_sat = (LQ_I_32BIT)LQ_Q_SSAT(lq_tmp, 8);
    if (lq_sat != lq_tmp)
    {
        *Lq_Error = (lq_tmp > 0) ? SATURATION_INT8_Q6_FORMAT_ADD_POSITIVE_OVER : SATURATION_INT8_Q6_FORMAT_ADD_NEGATIVE_OVER;
    }
    return   (LQ_INT8_Q6)lq_sat;
}

/**@brief 饱和算法:INT8类型Q5格式加法(ARM SSAT分支)
* @details 能对加法运算进行检查。\n
* @param[in] LQ_INT8_Q5     A              输入Q格式数
* @param[in] LQ_INT8_Q5     B              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
* @return    A+B的饱和值
* @attention  仅在LQ_ARM_DSP_SSAT_ENABLE为1时参与编译\n
*             用户权限:用户无需调用
*/

LQ_INLINE LQ_INT8_Q5 LQ_ARM_SATURATION_INT8_Q5_ADD(LQ_INT8_Q5 A, LQ_INT8_Q5 B, LQ_ERROR* Lq_Error)
{
    LQ_I_32BIT lq_tmp;
    LQ_I_32BIT lq_sat;
    lq_tmp = (LQ_I_32BIT)(A)+(LQ_I_32BIT)(B);
    lq_sat = (LQ_I_32BIT)LQ_Q_SSAT(lq_tmp, 8);
    if (lq_sat != lq_tmp)
    {
        *Lq_Error = (lq_tmp > 0) ? SATURATION_INT8_Q5_FORMAT_ADD_POSITIVE_OVER : SATURATION_INT8_Q5_FORMAT_ADD_NEGATIVE_OVER;
    }
    return   (LQ_INT8_Q5)lq_sat;
}

/**@brief 饱和算法:INT8类型Q4格式加法(ARM SSAT分支)
* @details 能对加法运算进行检查。\n
* @param[in] LQ_INT8_Q4     A              输入Q格式数
* @param[in] LQ_INT8_Q4     B              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
* @return    A+B的饱和值
* @attention  仅在LQ_ARM_DSP_SSAT_ENABLE为1时参与编译\n
*             用户权限:用户无需调用
*/

LQ_INLINE LQ_INT8_Q4 LQ_ARM_SATURATION_INT8_Q4_ADD(LQ_INT8_Q4 A, LQ_INT8_Q4 B, LQ_ERROR* Lq_Error)
{
    LQ_I_32BIT lq_tmp;
    LQ_I_32BIT lq_sat;
    lq_tmp = (LQ_I_32BIT)(A)+(LQ_I_32BIT)(B);
    lq_sat = (LQ_I_32BIT)LQ_Q_SSAT(lq_tmp, 8);
    if (lq_sat != lq_tmp)
    {
        *Lq_Error = (lq_tmp > 0) ? SATURATION_INT8_Q4_FORMAT_ADD_POSITIVE_OVER : SATURATION_INT8_Q4_FORMAT_ADD_NEGATIVE_OVER;
    }
    return   (LQ_INT8_Q4)lq_sat;
}

/**@brief 饱和算法:INT8类型Q3格式加法(ARM SSAT分支)
* @details 能对加法运算进行检查。\n
* @param[in] LQ_INT8_Q3     A              输入Q格式数
* @param[in] LQ_INT8_Q3     B              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
* @return    A+B的饱和值
* @attention  仅在LQ_ARM_DSP_SSAT_ENABLE为1时参与编译\n
*             用户权限:用户无需调用
*/

LQ_INLINE LQ_INT8_Q3 LQ_ARM_SATURATION_INT8_Q3_ADD(LQ_INT8_Q3 A, LQ_INT8_Q3 B, LQ_ERROR* Lq_Error)
{
    LQ_I_32BIT lq_tmp;
    LQ_I_32BIT lq_sat;
    lq_tmp = (LQ_I_32BIT)(A)+(LQ_I_32BIT)(B);
    lq_sat = (LQ_I_32BIT)LQ_Q_SSAT(lq_tmp, 8);
    if (lq_sat != lq_tmp)
    {
        *Lq_Error = (lq_tmp > 0) ? SATURATION_INT8_Q3_FORMAT_ADD_POSITIVE_OVER : SATURATION_INT8_Q3_FORMAT_ADD_NEGATIVE_OVER;
    }
    return   (LQ_INT8_Q3)lq_sat;
}

/**@brief 饱和算法:INT8类型Q2格式加法(ARM SSAT分支)
* @details 能对加法运算进行检查。\n
* @param[in] LQ_INT8_Q2     A              输入Q格式数
* @param[in] LQ_INT8_Q2     B              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
* @return    A+B的饱和值
* @attention  仅在LQ_ARM_DSP_SSAT_ENABLE为1时参与编译\n
*             用户权限:用户无需调用
*/

LQ_INLINE LQ_INT8_Q2 LQ_ARM_SATURATION_INT8_Q2_ADD(LQ_INT8_Q2 A, LQ_INT8_Q2 B, LQ_ERROR* Lq_Error)
{
    LQ_I_32BIT lq_tmp;
    LQ_I_32BIT lq_sat;
    lq_tmp = (LQ_I_32BIT)(A)+(LQ_I_32BIT)(B);
    lq_sat = (LQ_I_32BIT)LQ_Q_SSAT(lq_tmp, 8);
    if (lq_sat != lq_tmp)
    {
        *Lq_Error = (lq_tmp > 0) ? SATURATION_INT8_Q2_FORMAT_ADD_POSITIVE_OVER : SATURATION_INT8_Q2_FORMAT_ADD_NEGATIVE_OVER;
    }
    return   (LQ_INT8_Q2)lq_sat;
}

/**@brief 饱和算法:INT8类型Q1格式加法(ARM SSAT分支)
* @details 能对加法运算进行检查。\n
* @param[in] LQ_INT8_Q1     A              输入Q格式数
* @param[in] LQ_INT8_Q1     B              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
* @return    A+B的饱和值
* @attention  仅在LQ_ARM_DSP_SSAT_ENABLE为1时参与编译\n
*             用户权限:用户无需调用
*/

LQ_INLINE LQ_INT8_Q1 LQ_ARM_SATURATION_INT8_Q1_ADD(LQ_INT8_Q1 A, LQ_INT8_Q1 B, LQ_ERROR* Lq_Error)
{
    LQ_I_32BIT lq_tmp;
    LQ_I_32BIT lq_sat;
    lq_tmp = (LQ_I_32BIT)(A)+(LQ_I_32BIT)(B);
    lq_sat = (LQ_I_32BIT)LQ_Q_SSAT(lq_tmp, 8);
    if (lq_sat != lq_tmp)
    {
        *Lq_Error = (lq_tmp > 0) ? SATURATION_INT8_Q1_FORMAT_ADD_POSITIVE_OVER : SATURATION_INT8_Q1_FORMAT_ADD_NEGATIVE_OVER;
    }
    return   (LQ_INT8_Q1)lq_sat;
}

/****************************饱和算法 INT16 Q格式加法(ARM)************************************/
/**@brief 饱和算法:INT16类型Q15格式加法(ARM SSAT分支)
* @details 能对加法运算进行检查。\n
* @param[in] LQ_INT16_Q15     A              输入Q格式数
* @param[in] LQ_INT16_Q15     B              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
* @return    A+B的饱和值
* @attention  仅在LQ_ARM_DSP_SSAT_ENABLE为1时参与编译\n
*             用户权限:用户无需调用
*/

LQ_INLINE LQ_INT16_Q15 LQ_ARM_SATURATION_INT16_Q15_ADD(LQ_INT16_Q15 A, LQ_INT16_Q15 B, LQ_ERROR* Lq_Error)
{
    LQ_I_32BIT lq_tmp;
    LQ_I_32BIT lq_sat;
    lq_tmp = (LQ_I_32BIT)(A)+(LQ_I_32BIT)(B);
    lq_sat = (LQ_I_32BIT)LQ_Q_SSAT(lq_tmp, 16);
    if (lq_sat != lq_tmp)
    {
        *Lq_Error = (lq_tmp > 0) ? SATURATION_INT16_Q15_FORMAT_ADD_POSITIVE_OVER : SATURATION_INT16_Q15_FORMAT_ADD_NEGATIVE_OVER;
    }
    return   (LQ_INT16_Q15)lq_sat;
}

/**@brief 饱和算法:INT16类型Q14格式加法(ARM SSAT分支)
* @details 能对加法运算进行检查。\n
* @param[in] LQ_INT16_Q14     A              输入Q格式数
* @param[in] LQ_INT16_Q14     B              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
* @return    A+B的饱和值
* @attention  仅在LQ_ARM_DSP_SSAT_ENABLE为1时参与编译\n
*             用户权限:用户无需调用
*/

LQ_INLINE LQ_INT16_Q14 LQ_ARM_SATURATION_INT16_Q14_ADD(LQ_INT16_Q14 A, LQ_INT16_Q14 B, LQ_ERROR* Lq_Error)
{
    LQ_I_32BIT lq_tmp;
    LQ_I_32BIT lq_sat;
    lq_tmp = (LQ_I_32BIT)(A)+(LQ_I_32BIT)(B);
    lq_sat = (LQ_I_32BIT)LQ_Q_SSAT(lq_tmp, 16);
    if (lq_sat != lq_tmp)
    {
        *Lq_Error = (lq_tmp > 0) ? SATURATION_INT16_Q14_FORMAT_ADD_POSITIVE_OVER : SATURATION_INT16_Q14_FORMAT_ADD_NEGATIVE_OVER;
    }
    return   (LQ_INT16_Q14)lq_sat;
}

/**@brief 饱和算法:INT16类型Q13格式加法(ARM SSAT分支)
* @details 能对加法运算进行检查。\n
* @param[in] LQ_INT16_Q13     A              输入Q格式数
* @param[in] LQ_INT16_Q13     B              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
* @return    A+B的饱和值
* @attention  仅在LQ_ARM_DSP_SSAT_ENABLE为1时参与编译\n
*             用户权限:用户无需调用
*/

LQ_INLINE LQ_INT16_Q13 LQ_ARM_SATURATION_INT16_Q13_ADD(LQ_INT16_Q13 A, LQ_INT16_Q13 B, LQ_ERROR* Lq_Error)
{
    LQ_I_32BIT lq_tmp;
    LQ_I_32BIT lq_sat;
    lq_tmp = (LQ_I_32BIT)(A)+(LQ_I_32BIT)(B);
    lq_sat = (LQ_I_32BIT)LQ_Q_SSAT(lq_tmp, 16);
    if (lq_sat != lq_tmp)
    {
        *Lq_Error = (lq_tmp > 0) ? SATURATION_INT16_Q13_FORMAT_ADD_POSITIVE_OVER : SATURATION_INT16_Q13_FORMAT_ADD_NEGATIVE_OVER;
    }
    return   (LQ_INT16_Q13)lq_sat;
}

/**@brief 饱和算法:INT16类型Q12格式加法(ARM SSAT分支)
* @details 能对加法运算进行检查。\n
* @param[in] LQ_INT16_Q12     A              输入Q格式数
* @param[in] LQ_INT16_Q12     B              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
* @return    A+B的饱和值
* @attention  仅在LQ_ARM_DSP_SSAT_ENABLE为1时参与编译\n
*             用户权限:用户无需调用
*/

LQ_INLINE LQ_INT16_Q12 LQ_ARM_SATURATION_INT16_Q12_ADD(LQ_INT16_Q12 A, LQ_INT16_Q12 B, LQ_ERROR* Lq_Error)
{
    LQ_I_32BIT lq_tmp;
    LQ_I_32BIT lq_sat;
    lq_tmp = (LQ_I_32BIT)(A)+(LQ_I_32BIT)(B);
    lq_sat = (LQ_I_32BIT)LQ_Q_SSAT(lq_tmp, 16);
    if (lq_sat != lq_tmp)
    {
        *Lq_Error = (lq_tmp > 0) ? SATURATION_INT16_Q12_FORMAT_ADD_POSITIVE_OVER : SATURATION_INT16_Q12_FORMAT_ADD_NEGATIVE_OVER;
    }
    return   (LQ_INT16_Q12)lq_sat;
}

/**@brief 饱和算法:INT16类型Q11格式加法(ARM SSAT分支)
* @details 能对加法运算进行检查。\n
* @param[in] LQ_INT16_Q11     A              输入Q格式数
* @param[in] LQ_INT16_Q11     B              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
* @return    A+B的饱和值
* @attention  仅在LQ_ARM_DSP_SSAT_ENABLE为1时参与编译\n
*             用户权限:用户无需调用
*/

LQ_INLINE LQ_INT16_Q11 LQ_ARM_SATURATION_INT16_Q11_ADD(LQ_INT16_Q11 A, LQ_INT16_Q11 B, LQ_ERROR* Lq_Error)
{
    LQ_I_32BIT lq_tmp;
    LQ_I_32BIT lq_sat;
    lq_tmp = (LQ_I_32BIT)(A)+(LQ_I_32BIT)(B);
    lq_sat = (LQ_I_32BIT)LQ_Q_SSAT(lq_tmp, 16);
    if (lq_sat != lq_tmp)
    {
        *Lq_Error = (lq_tmp > 0) ? SATURATION_INT16_Q11_FORMAT_ADD_POSITIVE_OVER : SATURATION_INT16_Q11_FORMAT_ADD_NEGATIVE_OVER;
    }
    return   (LQ_INT16_Q11)lq_sat;
}

/**@brief 饱和算法:INT16类型Q10格式加法(ARM SSAT分支)
* @details 能对加法运算进行检查。\n
* @param[in] LQ_INT16_Q10     A              输入Q格式数
* @param[in] LQ_INT16_Q10     B              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
* @return    A+B的饱和值
* @attention  仅在LQ_ARM_DSP_SSAT_ENABLE为1时参与编译\n
*             用户权限:用户无需调用
*/

LQ_INLINE LQ_INT16_Q10 LQ_ARM_SATURATION_INT16_Q10_ADD(LQ_INT16_Q10 A, LQ_INT16_Q10 B, LQ_ERROR* Lq_Error)
{
    LQ_I_32BIT lq_tmp;
    LQ_I_32BIT lq_sat;
    lq_tmp = (LQ_I_32BIT)(A)+(LQ_I_32BIT)(B);
    lq_sat = (LQ_I_32BIT)LQ_Q_SSAT(lq_tmp, 16);
    if (lq_sat != lq_tmp)
    {
        *Lq_Error = (lq_tmp > 0) ? SATURATION_INT16_Q10_FORMAT_ADD_POSITIVE_OVER : SATURATION_INT16_Q10_FORMAT_ADD_NEGATIVE_OVER;
    }
    return   (LQ_INT16_Q10)lq_sat;
}

/**@brief 饱和算法:INT16类型Q9格式加法(ARM SSAT分支)
* @details 能对加法运算进行检查。\n
* @param[in] LQ_INT16_Q9     A              输入Q格式数
* @param[in] LQ_INT16_Q9     B              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
* @return    A+B的饱和值
* @attention  仅在LQ_ARM_DSP_SSAT_ENABLE为1时参与编译\n
*             用户权限:用户无需调用
*/

LQ_INLINE LQ_INT16_Q9 LQ_ARM_SATURATION_INT16_Q9_ADD(LQ_INT16_Q9 A, LQ_INT16_Q9 B, LQ_ERROR* Lq_Error)
{
    LQ_I_32BIT lq_tmp;
    LQ_I_32BIT lq_sat;
    lq_tmp = (LQ_I_32BIT)(A)+(LQ_I_32BIT)(B);
    lq_sat = (LQ_I_32BIT)LQ_Q_SSAT(lq_tmp, 16);
    if (lq_sat != lq_tmp)
    {
        *Lq_Error = (lq_tmp > 0) ? SATURATION_INT16_Q9_FORMAT_ADD_POSITIVE_OVER : SATURATION_INT16_Q9_FORMAT_ADD_NEGATIVE_OVER;
    }
    return   (LQ_INT16_Q9)lq_sat;
}

/**@brief 饱和算法:INT16类型Q8格式加法(ARM SSAT分支)
* @details 能对加法运算进行检查。\n
* @param[in] LQ_INT16_Q8     A              输入Q格式数
* @param[in] LQ_INT16_Q8     B              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
* @return    A+B的饱和值
* @attention  仅在LQ_ARM_DSP_SSAT_ENABLE为1时参与编译\n
*             用户权限:用户无需调用
*/

LQ_INLINE LQ_INT16_Q8 LQ_ARM_SATURATION_INT16_Q8_ADD(LQ_INT16_Q8 A, LQ_INT16_Q8 B, LQ_ERROR* Lq_Error)
{
    LQ_I_32BIT lq_tmp;
    LQ_I_32BIT lq_sat;
    lq_tmp = (LQ_I_32BIT)(A)+(LQ_I_32BIT)(B);
    lq_sat = (LQ_I_32BIT)LQ_Q_SSAT(lq_tmp, 16);
    if (lq_sat != lq_tmp)
    {
        *Lq_Error = (lq_tmp > 0) ? SATURATION_INT16_Q8_FORMAT_ADD_POSITIVE_OVER : SATURATION_INT16_Q8_FORMAT_ADD_NEGATIVE_OVER;
    }
    return   (LQ_INT16_Q8)lq_sat;
}

/**@brief 饱和算法:INT16类型Q7格式加法(ARM SSAT分支)
* @details 能对加法运算进行检查。\n
* @param[in] LQ_INT16_Q7     A              输入Q格式数
* @param[in] LQ_INT16_Q7     B              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
* @return    A+B的饱和值
* @attention  仅在LQ_ARM_DSP_SSAT_ENABLE为1时参与编译\n
*             用户权限:用户无需调用
*/

LQ_INLINE LQ_INT16_Q7 LQ_ARM_SATURATION_INT16_Q7_ADD(LQ_INT16_Q7 A, LQ_INT16_Q7 B, LQ_ERROR* Lq_Error)
{
    LQ_I_32BIT lq_tmp;
    LQ_I_32BIT lq_sat;
    lq_tmp = (LQ_I_32BIT)(A)+(LQ_I_32BIT)(B);
    lq_sat = (LQ_I_32BIT)LQ_Q_SSAT(lq_tmp, 16);
    if (lq_sat != lq_tmp)
    {
        *Lq_Error = (lq_tmp > 0) ? SATURATION_INT16_Q7_FORMAT_ADD_POSITIVE_OVER : SATURATION_INT16_Q7_FORMAT_ADD_NEGATIVE_OVER;
    }
    return   (LQ_INT16_Q7)lq_sat;
}

/**@brief 饱和算法:INT16类型Q6格式加法(ARM SSAT分支)
* @details 能对加法运算进行检查。\n
* @param[in] LQ_INT16_Q6     A              输入Q格式数
* @param[in] LQ_INT16_Q6     B              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
* @return    A+B的饱和值
* @attention  仅在LQ_ARM_DSP_SSAT_ENABLE为1时参与编译\n
*             用户权限:用户无需调用
*/

LQ_INLINE LQ_INT16_Q6 LQ_ARM_SATURATION_INT16_Q6_ADD(LQ_INT16_Q6 A, LQ_INT16_Q6 B, LQ_ERROR* Lq_Error)
{
    LQ_I_32BIT lq_tmp;
    LQ_I_32BIT lq_sat;
    lq_tmp = (LQ_I_32BIT)(A)+(LQ_I_32BIT)(B);
    lq_sat = (LQ_I_32BIT)LQ_Q_SSAT(lq_tmp, 16);
    if (lq_sat != lq_tmp)
    {
        *Lq_Error = (lq_tmp > 0) ? SATURATION_INT16_Q6_FORMAT_ADD_POSITIVE_OVER : SATURATION_INT16_Q6_FORMAT_ADD_NEGATIVE_OVER;
    }
    return   (LQ_INT16_Q6)lq_sat;
}

/**@brief 饱和算法:INT16类型Q5格式加法(ARM SSAT分支)
* @details 能对加法运算进行检查。\n
* @param[in] LQ_INT16_Q5     A              输入Q格式数
* @param[in] LQ_INT16_Q5     B              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
* @return    A+B的饱和值
* @attention  仅在LQ_ARM_DSP_SSAT_ENABLE为1时参与编译\n
*             用户权限:用户无需调用
*/

LQ_INLINE LQ_INT16_Q5 LQ_ARM_SATURATION_INT16_Q5_ADD(LQ_INT16_Q5 A, LQ_INT16_Q5 B, LQ_ERROR* Lq_Error)
{
    LQ_I_32BIT lq_tmp;
    LQ_I_32BIT lq_sat;
    lq_tmp = (LQ_I_32BIT)(A)+(LQ_I_32BIT)(B);
    lq_sat = (LQ_I_32BIT)LQ_Q_SSAT(lq_tmp, 16);
    if (lq_sat != lq_tmp)
    {
        *Lq_Error = (lq_tmp > 0) ? SATURATION_INT16_Q5_FORMAT_ADD_POSITIVE_OVER : SATURATION_INT16_Q5_FORMAT_ADD_NEGATIVE_OVER;
    }
    return   (LQ_INT16_Q5)lq_sat;
}

/**@brief 饱和算法:INT16类型Q4格式加法(ARM SSAT分支)
* @details 能对加法运算进行检查。\n
* @param[in] LQ_INT16_Q4     A              输入Q格式数
* @param[in] LQ_INT16_Q4     B              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
* @return    A+B的饱和值
* @attention  仅在LQ_ARM_DSP_SSAT_ENABLE为1时参与编译\n
*             用户权限:用户无需调用
*/

LQ_INLINE LQ_INT16_Q4 LQ_ARM_SATURATION_INT16_Q4_ADD(LQ_INT16_Q4 A, LQ_INT16_Q4 B, LQ_ERROR* Lq_Error)
{
    LQ_I_32BIT lq_tmp;
    LQ_I_32BIT lq_sat;
    lq_tmp = (LQ_I_32BIT)(A)+(LQ_I_32BIT)(B);
    lq_sat = (LQ_I_32BIT)LQ_Q_SSAT(lq_tmp, 16);
    if (lq_sat != lq_tmp)
    {
        *Lq_Error = (lq_tmp > 0) ? SATURATION_INT16_Q4_FORMAT_ADD_POSITIVE_OVER : SATURATION_INT16_Q4_FORMAT_ADD_NEGATIVE_OVER;
    }
    return   (LQ_INT16_Q4)lq_sat;
}

/**@brief 饱和算法:INT16类型Q3格式加法(ARM SSAT分支)
* @details 能对加法运算进行检查。\n
* @param[in] LQ_INT16_Q3     A              输入Q格式数
* @param[in] LQ_INT16_Q3     B              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
* @return    A+B的饱和值
* @attention  仅在LQ_ARM_DSP_SSAT_ENABLE为1时参与编译\n
*             用户权限:用户无需调用
*/

LQ_INLINE LQ_INT16_Q3 LQ_ARM_SATURATION_INT16_Q3_ADD(LQ_INT16_Q3 A, LQ_INT16_Q3 B, LQ_ERROR* Lq_Error)
{
    LQ_I_32BIT lq_tmp;
    LQ_I_32BIT lq_sat;
    lq_tmp = (LQ_I_32BIT)(A)+(LQ_I_32BIT)(B);
    lq_sat = (LQ_I_32BIT)LQ_Q_SSAT(lq_tmp, 16);
    if (lq_sat != lq_tmp)
    {
        *Lq_Error = (lq_tmp > 0) ? SATURATION_INT16_Q3_FORMAT_ADD_POSITIVE_OVER : SATURATION_INT16_Q3_FORMAT_ADD_NEGATIVE_OVER;
    }
    return   (LQ_INT16_Q3)lq_sat;
}

/**@brief 饱和算法:INT16类型Q2格式加法(ARM SSAT分支)
* @details 能对加法运算进行检查。\n
* @param[in] LQ_INT16_Q2     A              输入Q格式数
* @param[in] LQ_INT16_Q2     B              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
* @return    A+B的饱和值
* @attention  仅在LQ_ARM_DSP_SSAT_ENABLE为1时参与编译\n
*             用户权限:用户无需调用
*/

LQ_INLINE LQ_INT16_Q2 LQ_ARM_SATURATION_INT16_Q2_ADD(LQ_INT16_Q2 A, LQ_INT16_Q2 B, LQ_ERROR* Lq_Error)
{
    LQ_I_32BIT lq_tmp;
    LQ_I_32BIT lq_sat;
    lq_tmp = (LQ_I_32BIT)(A)+(LQ_I_32BIT)(B);
    lq_sat = (LQ_I_32BIT)LQ_Q_SSAT(lq_tmp, 16);
    if (lq_sat != lq_tmp)
    {
        *Lq_Error = (lq_tmp > 0) ? SATURATION_INT16_Q2_FORMAT_ADD_POSITIVE_OVER : SATURATION_INT16_Q2_FORMAT_ADD_NEGATIVE_OVER;
    }
    return   (LQ_INT16_Q2)lq_sat;
}

/**@brief 饱和算法:INT16类型Q1格式加法(ARM SSAT分支)
* @details 能对加法运算进行检查。\n
* @param[in] LQ_INT16_Q1     A              输入Q格式数
* @param[in] LQ_INT16_Q1     B              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
* @return    A+B的饱和值
* @attention  仅在LQ_ARM_DSP_SSAT_ENABLE为1时参与编译\n
*             用户权限:用户无需调用
*/

LQ_INLINE LQ_INT16_Q1 LQ_ARM_SATURATION_INT16_Q1_ADD(LQ_INT16_Q1 A, LQ_INT16_Q1 B, LQ_ERROR* Lq_Error)
{
    LQ_I_32BIT lq_tmp;
    LQ_I_32BIT lq_sat;
    lq_tmp = (LQ_I_32BIT)(A)+(LQ_I_32BIT)(B);
    lq_sat = (LQ_I_32BIT)LQ_Q_SSAT(lq_tmp, 16);
    if (lq_sat != lq_tmp)
    {
        *Lq_Error = (lq_tmp > 0) ? SATURATION_INT16_Q1_FORMAT_ADD_POSITIVE_OVER : SATURATION_INT16_Q1_FORMAT_ADD_NEGATIVE_OVER;
    }
    return   (LQ_INT16_Q1)lq_sat;
}

#if (LQ_SATURATION_Q_FORMAT_ADD_LOADING_MODE == 1) || (LQ_SATURATION_Q_FORMAT_ADD_LOADING_MODE == 2)
//!<内联模式与宏展开模式:公开接口名映射到ARM饱和实现
#define LQ_SATURATION_INT8_Q7_ADD LQ_ARM_SATURATION_INT8_Q7_ADD
#define LQ_SATURATION_INT8_Q6_ADD LQ_ARM_SATURATION_INT8_Q6_ADD
#define LQ_SATURATION_INT8_Q5_ADD LQ_ARM_SATURATION_INT8_Q5_ADD
#define LQ_SATURATION_INT8_Q4_ADD LQ_ARM_SATURATION_INT8_Q4_ADD
#define LQ_SATURATION_INT8_Q3_ADD LQ_ARM_SATURATION_INT8_Q3_ADD
#define LQ_SATURATION_INT8_Q2_ADD LQ_ARM_SATURATION_INT8_Q2_ADD
#define LQ_SATURATION_INT8_Q1_ADD LQ_ARM_SATURATION_INT8_Q1_ADD
#define LQ_SATURATION_INT16_Q15_ADD LQ_ARM_SATURATION_INT16_Q15_ADD
#define LQ_SATURATION_INT16_Q14_ADD LQ_ARM_SATURATION_INT16_Q14_ADD
#define LQ_SATURATION_INT16_Q13_ADD LQ_ARM_SATURATION_INT16_Q13_ADD
#define LQ_SATURATION_INT16_Q12_ADD LQ_ARM_SATURATION_INT16_Q12_ADD
#define LQ_SATURATION_INT16_Q11_ADD LQ_ARM_SATURATION_INT16_Q11_ADD
#define LQ_SATURATION_INT16_Q10_ADD LQ_ARM_SATURATION_INT16_Q10_ADD
#define LQ_SATURATION_INT16_Q9_ADD LQ_ARM_SATURATION_INT16_Q9_ADD
#define LQ_SATURATION_INT16_Q8_ADD LQ_ARM_SATURATION_INT16_Q8_ADD
#define LQ_SATURATION_INT16_Q7_ADD LQ_ARM_SATURATION_INT16_Q7_ADD
#define LQ_SATURATION_INT16_Q6_ADD LQ_ARM_SATURATION_INT16_Q6_ADD
#define LQ_SATURATION_INT16_Q5_ADD LQ_ARM_SATURATION_INT16_Q5_ADD
#define LQ_SATURATION_INT16_Q4_ADD LQ_ARM_SATURATION_INT16_Q4_ADD
#define LQ_SATURATION_INT16_Q3_ADD LQ_ARM_SATURATION_INT16_Q3_ADD
#define LQ_SATURATION_INT16_Q2_ADD LQ_ARM_SATURATION_INT16_Q2_ADD
#define LQ_SATURATION_INT16_Q1_ADD LQ_ARM_SATURATION_INT16_Q1_ADD
#endif
#endif
#endif
