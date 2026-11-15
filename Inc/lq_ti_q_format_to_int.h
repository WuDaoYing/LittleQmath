#ifndef __LQ_TI_Q_FORMAT_TO_INT_H__
#define __LQ_TI_Q_FORMAT_TO_INT_H__

#include "lq_error.h"
#include "lq_mode.h"
#include "lq_type.h"
/**@file      lq_ti_q_to_int.h
* @brief      LittleQmath的ti算法的q格式转整形格式
* @details    采用指数偏移方式将Q格式转换为整形变量
* @author     尹冠华
* @date        2024-7-04
* @version     V2.0
* @copyright    Copyright (c ) 2018-2024  黑龙江大学A8楼514
**********************************************************************************
* @attention
* 硬件平台:兼容任何只要使用C语言编程的处理器 \n
* @par 修改日志:
* <table>
* <tr><th>Date        <th>Version  <th>Author    <th>Description
* <tr><td>2024/03/28  <td>1.0      <td>尹冠华    <td>创建初始版本
* <tr><td>2024/07/04  <td>2.0      <td>尹冠华    <td>重新架构
* </table>
*
**********************************************************************************
*/

//!< TI版本的Q格式转化整形类型宏定义展开
#if LQ_TI_Q_FORMAT_TO_INT_LOADING_MODE == 2
/****************************INT8 TI方法 Q格式转整形************************************/
//!< 以INT8为基准翻译有符号Q格式(Q1到Q7)
#define LQ_TI_INT8_Q7_TO_INT(A, Lq_Error) ((LQ_INT8_Q)(((LQ_I_32BIT)(A) + (((LQ_I_32BIT)(A) < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 7) - 1u) : 0)) >> 7))
#define LQ_TI_INT8_Q6_TO_INT(A, Lq_Error) ((LQ_INT8_Q)(((LQ_I_32BIT)(A) + (((LQ_I_32BIT)(A) < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 6) - 1u) : 0)) >> 6))
#define LQ_TI_INT8_Q5_TO_INT(A, Lq_Error) ((LQ_INT8_Q)(((LQ_I_32BIT)(A) + (((LQ_I_32BIT)(A) < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 5) - 1u) : 0)) >> 5))
#define LQ_TI_INT8_Q4_TO_INT(A, Lq_Error) ((LQ_INT8_Q)(((LQ_I_32BIT)(A) + (((LQ_I_32BIT)(A) < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 4) - 1u) : 0)) >> 4))
#define LQ_TI_INT8_Q3_TO_INT(A, Lq_Error) ((LQ_INT8_Q)(((LQ_I_32BIT)(A) + (((LQ_I_32BIT)(A) < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 3) - 1u) : 0)) >> 3))
#define LQ_TI_INT8_Q2_TO_INT(A, Lq_Error) ((LQ_INT8_Q)(((LQ_I_32BIT)(A) + (((LQ_I_32BIT)(A) < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 2) - 1u) : 0)) >> 2))
#define LQ_TI_INT8_Q1_TO_INT(A, Lq_Error) ((LQ_INT8_Q)(((LQ_I_32BIT)(A) + (((LQ_I_32BIT)(A) < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 1) - 1u) : 0)) >> 1))
/****************************UINT8 TI方法 UQ格式转整形************************************/
//!< 以UINT8为基准翻译无符号UQ格式(UQ1到UQ8)
#define LQ_TI_UINT8_UQ8_TO_INT(A, Lq_Error) ((LQ_UINT8_UQ)(((LQ_I_32BIT)(A) + (((LQ_I_32BIT)(A) < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 8) - 1u) : 0)) >> 8))
#define LQ_TI_UINT8_UQ7_TO_INT(A, Lq_Error) ((LQ_UINT8_UQ)(((LQ_I_32BIT)(A) + (((LQ_I_32BIT)(A) < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 7) - 1u) : 0)) >> 7))
#define LQ_TI_UINT8_UQ6_TO_INT(A, Lq_Error) ((LQ_UINT8_UQ)(((LQ_I_32BIT)(A) + (((LQ_I_32BIT)(A) < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 6) - 1u) : 0)) >> 6))
#define LQ_TI_UINT8_UQ5_TO_INT(A, Lq_Error) ((LQ_UINT8_UQ)(((LQ_I_32BIT)(A) + (((LQ_I_32BIT)(A) < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 5) - 1u) : 0)) >> 5))
#define LQ_TI_UINT8_UQ4_TO_INT(A, Lq_Error) ((LQ_UINT8_UQ)(((LQ_I_32BIT)(A) + (((LQ_I_32BIT)(A) < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 4) - 1u) : 0)) >> 4))
#define LQ_TI_UINT8_UQ3_TO_INT(A, Lq_Error) ((LQ_UINT8_UQ)(((LQ_I_32BIT)(A) + (((LQ_I_32BIT)(A) < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 3) - 1u) : 0)) >> 3))
#define LQ_TI_UINT8_UQ2_TO_INT(A, Lq_Error) ((LQ_UINT8_UQ)(((LQ_I_32BIT)(A) + (((LQ_I_32BIT)(A) < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 2) - 1u) : 0)) >> 2))
#define LQ_TI_UINT8_UQ1_TO_INT(A, Lq_Error) ((LQ_UINT8_UQ)(((LQ_I_32BIT)(A) + (((LQ_I_32BIT)(A) < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 1) - 1u) : 0)) >> 1))
/****************************INT16 TI方法 Q格式转整形************************************/
//!< 以INT16为基准翻译有符号Q格式(Q1到Q15)
#define LQ_TI_INT16_Q15_TO_INT(A, Lq_Error) ((LQ_INT16_Q)(((LQ_I_32BIT)(A) + (((LQ_I_32BIT)(A) < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 15) - 1u) : 0)) >> 15))
#define LQ_TI_INT16_Q14_TO_INT(A, Lq_Error) ((LQ_INT16_Q)(((LQ_I_32BIT)(A) + (((LQ_I_32BIT)(A) < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 14) - 1u) : 0)) >> 14))
#define LQ_TI_INT16_Q13_TO_INT(A, Lq_Error) ((LQ_INT16_Q)(((LQ_I_32BIT)(A) + (((LQ_I_32BIT)(A) < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 13) - 1u) : 0)) >> 13))
#define LQ_TI_INT16_Q12_TO_INT(A, Lq_Error) ((LQ_INT16_Q)(((LQ_I_32BIT)(A) + (((LQ_I_32BIT)(A) < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 12) - 1u) : 0)) >> 12))
#define LQ_TI_INT16_Q11_TO_INT(A, Lq_Error) ((LQ_INT16_Q)(((LQ_I_32BIT)(A) + (((LQ_I_32BIT)(A) < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 11) - 1u) : 0)) >> 11))
#define LQ_TI_INT16_Q10_TO_INT(A, Lq_Error) ((LQ_INT16_Q)(((LQ_I_32BIT)(A) + (((LQ_I_32BIT)(A) < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 10) - 1u) : 0)) >> 10))
#define LQ_TI_INT16_Q9_TO_INT(A, Lq_Error) ((LQ_INT16_Q)(((LQ_I_32BIT)(A) + (((LQ_I_32BIT)(A) < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 9) - 1u) : 0)) >> 9))
#define LQ_TI_INT16_Q8_TO_INT(A, Lq_Error) ((LQ_INT16_Q)(((LQ_I_32BIT)(A) + (((LQ_I_32BIT)(A) < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 8) - 1u) : 0)) >> 8))
#define LQ_TI_INT16_Q7_TO_INT(A, Lq_Error) ((LQ_INT16_Q)(((LQ_I_32BIT)(A) + (((LQ_I_32BIT)(A) < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 7) - 1u) : 0)) >> 7))
#define LQ_TI_INT16_Q6_TO_INT(A, Lq_Error) ((LQ_INT16_Q)(((LQ_I_32BIT)(A) + (((LQ_I_32BIT)(A) < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 6) - 1u) : 0)) >> 6))
#define LQ_TI_INT16_Q5_TO_INT(A, Lq_Error) ((LQ_INT16_Q)(((LQ_I_32BIT)(A) + (((LQ_I_32BIT)(A) < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 5) - 1u) : 0)) >> 5))
#define LQ_TI_INT16_Q4_TO_INT(A, Lq_Error) ((LQ_INT16_Q)(((LQ_I_32BIT)(A) + (((LQ_I_32BIT)(A) < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 4) - 1u) : 0)) >> 4))
#define LQ_TI_INT16_Q3_TO_INT(A, Lq_Error) ((LQ_INT16_Q)(((LQ_I_32BIT)(A) + (((LQ_I_32BIT)(A) < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 3) - 1u) : 0)) >> 3))
#define LQ_TI_INT16_Q2_TO_INT(A, Lq_Error) ((LQ_INT16_Q)(((LQ_I_32BIT)(A) + (((LQ_I_32BIT)(A) < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 2) - 1u) : 0)) >> 2))
#define LQ_TI_INT16_Q1_TO_INT(A, Lq_Error) ((LQ_INT16_Q)(((LQ_I_32BIT)(A) + (((LQ_I_32BIT)(A) < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 1) - 1u) : 0)) >> 1))
/****************************UINT16 TI方法 UQ格式转整形************************************/
//!< 以UINT16为基准翻译无符号UQ格式(UQ1到UQ16)
#define LQ_TI_UINT16_UQ16_TO_INT(A, Lq_Error) ((LQ_UINT16_UQ)(((LQ_I_32BIT)(A) + (((LQ_I_32BIT)(A) < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 16) - 1u) : 0)) >> 16))
#define LQ_TI_UINT16_UQ15_TO_INT(A, Lq_Error) ((LQ_UINT16_UQ)(((LQ_I_32BIT)(A) + (((LQ_I_32BIT)(A) < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 15) - 1u) : 0)) >> 15))
#define LQ_TI_UINT16_UQ14_TO_INT(A, Lq_Error) ((LQ_UINT16_UQ)(((LQ_I_32BIT)(A) + (((LQ_I_32BIT)(A) < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 14) - 1u) : 0)) >> 14))
#define LQ_TI_UINT16_UQ13_TO_INT(A, Lq_Error) ((LQ_UINT16_UQ)(((LQ_I_32BIT)(A) + (((LQ_I_32BIT)(A) < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 13) - 1u) : 0)) >> 13))
#define LQ_TI_UINT16_UQ12_TO_INT(A, Lq_Error) ((LQ_UINT16_UQ)(((LQ_I_32BIT)(A) + (((LQ_I_32BIT)(A) < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 12) - 1u) : 0)) >> 12))
#define LQ_TI_UINT16_UQ11_TO_INT(A, Lq_Error) ((LQ_UINT16_UQ)(((LQ_I_32BIT)(A) + (((LQ_I_32BIT)(A) < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 11) - 1u) : 0)) >> 11))
#define LQ_TI_UINT16_UQ10_TO_INT(A, Lq_Error) ((LQ_UINT16_UQ)(((LQ_I_32BIT)(A) + (((LQ_I_32BIT)(A) < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 10) - 1u) : 0)) >> 10))
#define LQ_TI_UINT16_UQ9_TO_INT(A, Lq_Error) ((LQ_UINT16_UQ)(((LQ_I_32BIT)(A) + (((LQ_I_32BIT)(A) < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 9) - 1u) : 0)) >> 9))
#define LQ_TI_UINT16_UQ8_TO_INT(A, Lq_Error) ((LQ_UINT16_UQ)(((LQ_I_32BIT)(A) + (((LQ_I_32BIT)(A) < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 8) - 1u) : 0)) >> 8))
#define LQ_TI_UINT16_UQ7_TO_INT(A, Lq_Error) ((LQ_UINT16_UQ)(((LQ_I_32BIT)(A) + (((LQ_I_32BIT)(A) < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 7) - 1u) : 0)) >> 7))
#define LQ_TI_UINT16_UQ6_TO_INT(A, Lq_Error) ((LQ_UINT16_UQ)(((LQ_I_32BIT)(A) + (((LQ_I_32BIT)(A) < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 6) - 1u) : 0)) >> 6))
#define LQ_TI_UINT16_UQ5_TO_INT(A, Lq_Error) ((LQ_UINT16_UQ)(((LQ_I_32BIT)(A) + (((LQ_I_32BIT)(A) < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 5) - 1u) : 0)) >> 5))
#define LQ_TI_UINT16_UQ4_TO_INT(A, Lq_Error) ((LQ_UINT16_UQ)(((LQ_I_32BIT)(A) + (((LQ_I_32BIT)(A) < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 4) - 1u) : 0)) >> 4))
#define LQ_TI_UINT16_UQ3_TO_INT(A, Lq_Error) ((LQ_UINT16_UQ)(((LQ_I_32BIT)(A) + (((LQ_I_32BIT)(A) < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 3) - 1u) : 0)) >> 3))
#define LQ_TI_UINT16_UQ2_TO_INT(A, Lq_Error) ((LQ_UINT16_UQ)(((LQ_I_32BIT)(A) + (((LQ_I_32BIT)(A) < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 2) - 1u) : 0)) >> 2))
#define LQ_TI_UINT16_UQ1_TO_INT(A, Lq_Error) ((LQ_UINT16_UQ)(((LQ_I_32BIT)(A) + (((LQ_I_32BIT)(A) < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 1) - 1u) : 0)) >> 1))
/****************************INT32 TI方法 Q格式转整形************************************/
//!< 以INT32为基准翻译有符号Q格式(Q1到Q31)
#define LQ_TI_INT32_Q31_TO_INT(A, Lq_Error) ((LQ_INT32_Q)(((LQ_I_32BIT)(A) + (((LQ_I_32BIT)(A) < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 31) - 1u) : 0)) >> 31))
#define LQ_TI_INT32_Q30_TO_INT(A, Lq_Error) ((LQ_INT32_Q)(((LQ_I_32BIT)(A) + (((LQ_I_32BIT)(A) < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 30) - 1u) : 0)) >> 30))
#define LQ_TI_INT32_Q29_TO_INT(A, Lq_Error) ((LQ_INT32_Q)(((LQ_I_32BIT)(A) + (((LQ_I_32BIT)(A) < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 29) - 1u) : 0)) >> 29))
#define LQ_TI_INT32_Q28_TO_INT(A, Lq_Error) ((LQ_INT32_Q)(((LQ_I_32BIT)(A) + (((LQ_I_32BIT)(A) < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 28) - 1u) : 0)) >> 28))
#define LQ_TI_INT32_Q27_TO_INT(A, Lq_Error) ((LQ_INT32_Q)(((LQ_I_32BIT)(A) + (((LQ_I_32BIT)(A) < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 27) - 1u) : 0)) >> 27))
#define LQ_TI_INT32_Q26_TO_INT(A, Lq_Error) ((LQ_INT32_Q)(((LQ_I_32BIT)(A) + (((LQ_I_32BIT)(A) < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 26) - 1u) : 0)) >> 26))
#define LQ_TI_INT32_Q25_TO_INT(A, Lq_Error) ((LQ_INT32_Q)(((LQ_I_32BIT)(A) + (((LQ_I_32BIT)(A) < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 25) - 1u) : 0)) >> 25))
#define LQ_TI_INT32_Q24_TO_INT(A, Lq_Error) ((LQ_INT32_Q)(((LQ_I_32BIT)(A) + (((LQ_I_32BIT)(A) < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 24) - 1u) : 0)) >> 24))
#define LQ_TI_INT32_Q23_TO_INT(A, Lq_Error) ((LQ_INT32_Q)(((LQ_I_32BIT)(A) + (((LQ_I_32BIT)(A) < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 23) - 1u) : 0)) >> 23))
#define LQ_TI_INT32_Q22_TO_INT(A, Lq_Error) ((LQ_INT32_Q)(((LQ_I_32BIT)(A) + (((LQ_I_32BIT)(A) < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 22) - 1u) : 0)) >> 22))
#define LQ_TI_INT32_Q21_TO_INT(A, Lq_Error) ((LQ_INT32_Q)(((LQ_I_32BIT)(A) + (((LQ_I_32BIT)(A) < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 21) - 1u) : 0)) >> 21))
#define LQ_TI_INT32_Q20_TO_INT(A, Lq_Error) ((LQ_INT32_Q)(((LQ_I_32BIT)(A) + (((LQ_I_32BIT)(A) < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 20) - 1u) : 0)) >> 20))
#define LQ_TI_INT32_Q19_TO_INT(A, Lq_Error) ((LQ_INT32_Q)(((LQ_I_32BIT)(A) + (((LQ_I_32BIT)(A) < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 19) - 1u) : 0)) >> 19))
#define LQ_TI_INT32_Q18_TO_INT(A, Lq_Error) ((LQ_INT32_Q)(((LQ_I_32BIT)(A) + (((LQ_I_32BIT)(A) < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 18) - 1u) : 0)) >> 18))
#define LQ_TI_INT32_Q17_TO_INT(A, Lq_Error) ((LQ_INT32_Q)(((LQ_I_32BIT)(A) + (((LQ_I_32BIT)(A) < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 17) - 1u) : 0)) >> 17))
#define LQ_TI_INT32_Q16_TO_INT(A, Lq_Error) ((LQ_INT32_Q)(((LQ_I_32BIT)(A) + (((LQ_I_32BIT)(A) < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 16) - 1u) : 0)) >> 16))
#define LQ_TI_INT32_Q15_TO_INT(A, Lq_Error) ((LQ_INT32_Q)(((LQ_I_32BIT)(A) + (((LQ_I_32BIT)(A) < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 15) - 1u) : 0)) >> 15))
#define LQ_TI_INT32_Q14_TO_INT(A, Lq_Error) ((LQ_INT32_Q)(((LQ_I_32BIT)(A) + (((LQ_I_32BIT)(A) < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 14) - 1u) : 0)) >> 14))
#define LQ_TI_INT32_Q13_TO_INT(A, Lq_Error) ((LQ_INT32_Q)(((LQ_I_32BIT)(A) + (((LQ_I_32BIT)(A) < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 13) - 1u) : 0)) >> 13))
#define LQ_TI_INT32_Q12_TO_INT(A, Lq_Error) ((LQ_INT32_Q)(((LQ_I_32BIT)(A) + (((LQ_I_32BIT)(A) < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 12) - 1u) : 0)) >> 12))
#define LQ_TI_INT32_Q11_TO_INT(A, Lq_Error) ((LQ_INT32_Q)(((LQ_I_32BIT)(A) + (((LQ_I_32BIT)(A) < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 11) - 1u) : 0)) >> 11))
#define LQ_TI_INT32_Q10_TO_INT(A, Lq_Error) ((LQ_INT32_Q)(((LQ_I_32BIT)(A) + (((LQ_I_32BIT)(A) < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 10) - 1u) : 0)) >> 10))
#define LQ_TI_INT32_Q9_TO_INT(A, Lq_Error) ((LQ_INT32_Q)(((LQ_I_32BIT)(A) + (((LQ_I_32BIT)(A) < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 9) - 1u) : 0)) >> 9))
#define LQ_TI_INT32_Q8_TO_INT(A, Lq_Error) ((LQ_INT32_Q)(((LQ_I_32BIT)(A) + (((LQ_I_32BIT)(A) < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 8) - 1u) : 0)) >> 8))
#define LQ_TI_INT32_Q7_TO_INT(A, Lq_Error) ((LQ_INT32_Q)(((LQ_I_32BIT)(A) + (((LQ_I_32BIT)(A) < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 7) - 1u) : 0)) >> 7))
#define LQ_TI_INT32_Q6_TO_INT(A, Lq_Error) ((LQ_INT32_Q)(((LQ_I_32BIT)(A) + (((LQ_I_32BIT)(A) < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 6) - 1u) : 0)) >> 6))
#define LQ_TI_INT32_Q5_TO_INT(A, Lq_Error) ((LQ_INT32_Q)(((LQ_I_32BIT)(A) + (((LQ_I_32BIT)(A) < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 5) - 1u) : 0)) >> 5))
#define LQ_TI_INT32_Q4_TO_INT(A, Lq_Error) ((LQ_INT32_Q)(((LQ_I_32BIT)(A) + (((LQ_I_32BIT)(A) < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 4) - 1u) : 0)) >> 4))
#define LQ_TI_INT32_Q3_TO_INT(A, Lq_Error) ((LQ_INT32_Q)(((LQ_I_32BIT)(A) + (((LQ_I_32BIT)(A) < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 3) - 1u) : 0)) >> 3))
#define LQ_TI_INT32_Q2_TO_INT(A, Lq_Error) ((LQ_INT32_Q)(((LQ_I_32BIT)(A) + (((LQ_I_32BIT)(A) < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 2) - 1u) : 0)) >> 2))
#define LQ_TI_INT32_Q1_TO_INT(A, Lq_Error) ((LQ_INT32_Q)(((LQ_I_32BIT)(A) + (((LQ_I_32BIT)(A) < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 1) - 1u) : 0)) >> 1))
/****************************UINT32 TI方法 UQ格式转整形************************************/
//!< 以UINT32为基准翻译无符号UQ格式(UQ1到UQ32)
#define LQ_TI_UINT32_UQ32_TO_INT(A, Lq_Error) ((LQ_UINT32_UQ32)0)
#define LQ_TI_UINT32_UQ31_TO_INT(A, Lq_Error) ((LQ_UINT32_UQ)(((LQ_I_32BIT)(A) + (((LQ_I_32BIT)(A) < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 31) - 1u) : 0)) >> 31))
#define LQ_TI_UINT32_UQ30_TO_INT(A, Lq_Error) ((LQ_UINT32_UQ)(((LQ_I_32BIT)(A) + (((LQ_I_32BIT)(A) < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 30) - 1u) : 0)) >> 30))
#define LQ_TI_UINT32_UQ29_TO_INT(A, Lq_Error) ((LQ_UINT32_UQ)(((LQ_I_32BIT)(A) + (((LQ_I_32BIT)(A) < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 29) - 1u) : 0)) >> 29))
#define LQ_TI_UINT32_UQ28_TO_INT(A, Lq_Error) ((LQ_UINT32_UQ)(((LQ_I_32BIT)(A) + (((LQ_I_32BIT)(A) < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 28) - 1u) : 0)) >> 28))
#define LQ_TI_UINT32_UQ27_TO_INT(A, Lq_Error) ((LQ_UINT32_UQ)(((LQ_I_32BIT)(A) + (((LQ_I_32BIT)(A) < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 27) - 1u) : 0)) >> 27))
#define LQ_TI_UINT32_UQ26_TO_INT(A, Lq_Error) ((LQ_UINT32_UQ)(((LQ_I_32BIT)(A) + (((LQ_I_32BIT)(A) < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 26) - 1u) : 0)) >> 26))
#define LQ_TI_UINT32_UQ25_TO_INT(A, Lq_Error) ((LQ_UINT32_UQ)(((LQ_I_32BIT)(A) + (((LQ_I_32BIT)(A) < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 25) - 1u) : 0)) >> 25))
#define LQ_TI_UINT32_UQ24_TO_INT(A, Lq_Error) ((LQ_UINT32_UQ)(((LQ_I_32BIT)(A) + (((LQ_I_32BIT)(A) < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 24) - 1u) : 0)) >> 24))
#define LQ_TI_UINT32_UQ23_TO_INT(A, Lq_Error) ((LQ_UINT32_UQ)(((LQ_I_32BIT)(A) + (((LQ_I_32BIT)(A) < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 23) - 1u) : 0)) >> 23))
#define LQ_TI_UINT32_UQ22_TO_INT(A, Lq_Error) ((LQ_UINT32_UQ)(((LQ_I_32BIT)(A) + (((LQ_I_32BIT)(A) < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 22) - 1u) : 0)) >> 22))
#define LQ_TI_UINT32_UQ21_TO_INT(A, Lq_Error) ((LQ_UINT32_UQ)(((LQ_I_32BIT)(A) + (((LQ_I_32BIT)(A) < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 21) - 1u) : 0)) >> 21))
#define LQ_TI_UINT32_UQ20_TO_INT(A, Lq_Error) ((LQ_UINT32_UQ)(((LQ_I_32BIT)(A) + (((LQ_I_32BIT)(A) < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 20) - 1u) : 0)) >> 20))
#define LQ_TI_UINT32_UQ19_TO_INT(A, Lq_Error) ((LQ_UINT32_UQ)(((LQ_I_32BIT)(A) + (((LQ_I_32BIT)(A) < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 19) - 1u) : 0)) >> 19))
#define LQ_TI_UINT32_UQ18_TO_INT(A, Lq_Error) ((LQ_UINT32_UQ)(((LQ_I_32BIT)(A) + (((LQ_I_32BIT)(A) < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 18) - 1u) : 0)) >> 18))
#define LQ_TI_UINT32_UQ17_TO_INT(A, Lq_Error) ((LQ_UINT32_UQ)(((LQ_I_32BIT)(A) + (((LQ_I_32BIT)(A) < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 17) - 1u) : 0)) >> 17))
#define LQ_TI_UINT32_UQ16_TO_INT(A, Lq_Error) ((LQ_UINT32_UQ)(((LQ_I_32BIT)(A) + (((LQ_I_32BIT)(A) < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 16) - 1u) : 0)) >> 16))
#define LQ_TI_UINT32_UQ15_TO_INT(A, Lq_Error) ((LQ_UINT32_UQ)(((LQ_I_32BIT)(A) + (((LQ_I_32BIT)(A) < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 15) - 1u) : 0)) >> 15))
#define LQ_TI_UINT32_UQ14_TO_INT(A, Lq_Error) ((LQ_UINT32_UQ)(((LQ_I_32BIT)(A) + (((LQ_I_32BIT)(A) < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 14) - 1u) : 0)) >> 14))
#define LQ_TI_UINT32_UQ13_TO_INT(A, Lq_Error) ((LQ_UINT32_UQ)(((LQ_I_32BIT)(A) + (((LQ_I_32BIT)(A) < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 13) - 1u) : 0)) >> 13))
#define LQ_TI_UINT32_UQ12_TO_INT(A, Lq_Error) ((LQ_UINT32_UQ)(((LQ_I_32BIT)(A) + (((LQ_I_32BIT)(A) < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 12) - 1u) : 0)) >> 12))
#define LQ_TI_UINT32_UQ11_TO_INT(A, Lq_Error) ((LQ_UINT32_UQ)(((LQ_I_32BIT)(A) + (((LQ_I_32BIT)(A) < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 11) - 1u) : 0)) >> 11))
#define LQ_TI_UINT32_UQ10_TO_INT(A, Lq_Error) ((LQ_UINT32_UQ)(((LQ_I_32BIT)(A) + (((LQ_I_32BIT)(A) < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 10) - 1u) : 0)) >> 10))
#define LQ_TI_UINT32_UQ9_TO_INT(A, Lq_Error) ((LQ_UINT32_UQ)(((LQ_I_32BIT)(A) + (((LQ_I_32BIT)(A) < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 9) - 1u) : 0)) >> 9))
#define LQ_TI_UINT32_UQ8_TO_INT(A, Lq_Error) ((LQ_UINT32_UQ)(((LQ_I_32BIT)(A) + (((LQ_I_32BIT)(A) < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 8) - 1u) : 0)) >> 8))
#define LQ_TI_UINT32_UQ7_TO_INT(A, Lq_Error) ((LQ_UINT32_UQ)(((LQ_I_32BIT)(A) + (((LQ_I_32BIT)(A) < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 7) - 1u) : 0)) >> 7))
#define LQ_TI_UINT32_UQ6_TO_INT(A, Lq_Error) ((LQ_UINT32_UQ)(((LQ_I_32BIT)(A) + (((LQ_I_32BIT)(A) < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 6) - 1u) : 0)) >> 6))
#define LQ_TI_UINT32_UQ5_TO_INT(A, Lq_Error) ((LQ_UINT32_UQ)(((LQ_I_32BIT)(A) + (((LQ_I_32BIT)(A) < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 5) - 1u) : 0)) >> 5))
#define LQ_TI_UINT32_UQ4_TO_INT(A, Lq_Error) ((LQ_UINT32_UQ)(((LQ_I_32BIT)(A) + (((LQ_I_32BIT)(A) < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 4) - 1u) : 0)) >> 4))
#define LQ_TI_UINT32_UQ3_TO_INT(A, Lq_Error) ((LQ_UINT32_UQ)(((LQ_I_32BIT)(A) + (((LQ_I_32BIT)(A) < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 3) - 1u) : 0)) >> 3))
#define LQ_TI_UINT32_UQ2_TO_INT(A, Lq_Error) ((LQ_UINT32_UQ)(((LQ_I_32BIT)(A) + (((LQ_I_32BIT)(A) < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 2) - 1u) : 0)) >> 2))
#define LQ_TI_UINT32_UQ1_TO_INT(A, Lq_Error) ((LQ_UINT32_UQ)(((LQ_I_32BIT)(A) + (((LQ_I_32BIT)(A) < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 1) - 1u) : 0)) >> 1))
/****************************INT8 TI Q格式转整形(任意Q格式)************************************/
//!< 以INT8为基准翻译有符号Q格式(Q1到Q7)
#define LQ_TI_INT8_Q_TO_INT(A, Q_A, Lq_Error) (((Q_A) >= 32u) ? (LQ_INT8_Q)0 : (LQ_INT8_Q)(((LQ_I_64BIT)(A) + (((LQ_I_64BIT)(A) >> 63) & (LQ_I_64BIT)(((LQ_UI_64BIT)1 << (Q_A)) - 1u))) >> (Q_A)))
/****************************UINT8 TI UQ格式转整形(任意UQ格式)************************************/
//!< 以UINT8为基准翻译无符号UQ格式(UQ1到UQ8)
#define LQ_TI_UINT8_UQ_TO_INT(A, Q_A, Lq_Error) (((Q_A) >= 32u) ? (LQ_UINT8_UQ)0 : (LQ_UINT8_UQ)(((LQ_I_64BIT)(A) + (((LQ_I_64BIT)(A) >> 63) & (LQ_I_64BIT)(((LQ_UI_64BIT)1 << (Q_A)) - 1u))) >> (Q_A)))
/****************************INT16 TI Q格式转整形(任意Q格式)************************************/
//!< 以INT16为基准翻译有符号Q格式(Q1到Q15)
#define LQ_TI_INT16_Q_TO_INT(A, Q_A, Lq_Error) (((Q_A) >= 32u) ? (LQ_INT16_Q)0 : (LQ_INT16_Q)(((LQ_I_64BIT)(A) + (((LQ_I_64BIT)(A) >> 63) & (LQ_I_64BIT)(((LQ_UI_64BIT)1 << (Q_A)) - 1u))) >> (Q_A)))
/****************************UINT16 TI UQ格式转整形(任意UQ格式)************************************/
//!< 以UINT16为基准翻译无符号UQ格式(UQ1到UQ16)
#define LQ_TI_UINT16_UQ_TO_INT(A, Q_A, Lq_Error) (((Q_A) >= 32u) ? (LQ_UINT16_UQ)0 : (LQ_UINT16_UQ)(((LQ_I_64BIT)(A) + (((LQ_I_64BIT)(A) >> 63) & (LQ_I_64BIT)(((LQ_UI_64BIT)1 << (Q_A)) - 1u))) >> (Q_A)))
/****************************INT32 TI Q格式转整形(任意Q格式)************************************/
//!< 以INT32为基准翻译有符号Q格式(Q1到Q31)
#define LQ_TI_INT32_Q_TO_INT(A, Q_A, Lq_Error) (((Q_A) >= 32u) ? (LQ_INT32_Q)0 : (LQ_INT32_Q)(((LQ_I_64BIT)(A) + (((LQ_I_64BIT)(A) >> 63) & (LQ_I_64BIT)(((LQ_UI_64BIT)1 << (Q_A)) - 1u))) >> (Q_A)))
/****************************UINT32 TI UQ格式转整形(任意UQ格式)************************************/
//!< 以UINT32为基准翻译无符号UQ格式(UQ1到UQ32)
#define LQ_TI_UINT32_UQ_TO_INT(A, Q_A, Lq_Error) (((Q_A) >= 32u) ? (LQ_UINT32_UQ)0 : (LQ_UINT32_UQ)(((LQ_I_64BIT)(A) + (((LQ_I_64BIT)(A) >> 63) & (LQ_I_64BIT)(((LQ_UI_64BIT)1 << (Q_A)) - 1u))) >> (Q_A)))
#endif

#if LQ_TI_Q_FORMAT_TO_INT_LOADING_MODE == 1
/**@brief (TI方法)INT8类型Q7格式转整形
* @details 采用估算位+指数位+符号位三位结合
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为整形数
* @code*    LQ_TI_INT8_Q7_TO_INT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_INT8_Q7_TO_INT  TI方式INT8的Q7转化整形类型\n
*    LQ_TI_INT8_Q6_TO_INT  TI方式INT8的Q6转化整形类型\n
*    LQ_TI_INT8_Q5_TO_INT  TI方式INT8的Q5转化整形类型\n
*    LQ_TI_INT8_Q4_TO_INT  TI方式INT8的Q4转化整形类型\n
*    LQ_TI_INT8_Q3_TO_INT  TI方式INT8的Q3转化整形类型\n
*    LQ_TI_INT8_Q2_TO_INT  TI方式INT8的Q2转化整形类型\n
*    LQ_TI_INT8_Q1_TO_INT  TI方式INT8的Q1转化整形类型\n
*/
LQ_INLINE LQ_INT8_Q7 LQ_TI_INT8_Q7_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error){
    return (LQ_INT8_Q7)(((LQ_I_32BIT)A + (((LQ_I_32BIT)A < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 7) - 1u) : 0)) >> 7);
}
/**@brief (TI方法)INT8类型Q6格式转整形
* @details 采用估算位+指数位+符号位三位结合
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为整形数
* @code*    LQ_TI_INT8_Q6_TO_INT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_INT8_Q7_TO_INT  TI方式INT8的Q7转化整形类型\n
*    LQ_TI_INT8_Q6_TO_INT  TI方式INT8的Q6转化整形类型\n
*    LQ_TI_INT8_Q5_TO_INT  TI方式INT8的Q5转化整形类型\n
*    LQ_TI_INT8_Q4_TO_INT  TI方式INT8的Q4转化整形类型\n
*    LQ_TI_INT8_Q3_TO_INT  TI方式INT8的Q3转化整形类型\n
*    LQ_TI_INT8_Q2_TO_INT  TI方式INT8的Q2转化整形类型\n
*    LQ_TI_INT8_Q1_TO_INT  TI方式INT8的Q1转化整形类型\n
*/
LQ_INLINE LQ_INT8_Q6 LQ_TI_INT8_Q6_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error){
    return (LQ_INT8_Q6)(((LQ_I_32BIT)A + (((LQ_I_32BIT)A < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 6) - 1u) : 0)) >> 6);
}
/**@brief (TI方法)INT8类型Q5格式转整形
* @details 采用估算位+指数位+符号位三位结合
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为整形数
* @code*    LQ_TI_INT8_Q5_TO_INT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_INT8_Q7_TO_INT  TI方式INT8的Q7转化整形类型\n
*    LQ_TI_INT8_Q6_TO_INT  TI方式INT8的Q6转化整形类型\n
*    LQ_TI_INT8_Q5_TO_INT  TI方式INT8的Q5转化整形类型\n
*    LQ_TI_INT8_Q4_TO_INT  TI方式INT8的Q4转化整形类型\n
*    LQ_TI_INT8_Q3_TO_INT  TI方式INT8的Q3转化整形类型\n
*    LQ_TI_INT8_Q2_TO_INT  TI方式INT8的Q2转化整形类型\n
*    LQ_TI_INT8_Q1_TO_INT  TI方式INT8的Q1转化整形类型\n
*/
LQ_INLINE LQ_INT8_Q5 LQ_TI_INT8_Q5_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error){
    return (LQ_INT8_Q5)(((LQ_I_32BIT)A + (((LQ_I_32BIT)A < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 5) - 1u) : 0)) >> 5);
}
/**@brief (TI方法)INT8类型Q4格式转整形
* @details 采用估算位+指数位+符号位三位结合
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为整形数
* @code*    LQ_TI_INT8_Q4_TO_INT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_INT8_Q7_TO_INT  TI方式INT8的Q7转化整形类型\n
*    LQ_TI_INT8_Q6_TO_INT  TI方式INT8的Q6转化整形类型\n
*    LQ_TI_INT8_Q5_TO_INT  TI方式INT8的Q5转化整形类型\n
*    LQ_TI_INT8_Q4_TO_INT  TI方式INT8的Q4转化整形类型\n
*    LQ_TI_INT8_Q3_TO_INT  TI方式INT8的Q3转化整形类型\n
*    LQ_TI_INT8_Q2_TO_INT  TI方式INT8的Q2转化整形类型\n
*    LQ_TI_INT8_Q1_TO_INT  TI方式INT8的Q1转化整形类型\n
*/
LQ_INLINE LQ_INT8_Q4 LQ_TI_INT8_Q4_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error){
    return (LQ_INT8_Q4)(((LQ_I_32BIT)A + (((LQ_I_32BIT)A < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 4) - 1u) : 0)) >> 4);
}
/**@brief (TI方法)INT8类型Q3格式转整形
* @details 采用估算位+指数位+符号位三位结合
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为整形数
* @code*    LQ_TI_INT8_Q3_TO_INT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_INT8_Q7_TO_INT  TI方式INT8的Q7转化整形类型\n
*    LQ_TI_INT8_Q6_TO_INT  TI方式INT8的Q6转化整形类型\n
*    LQ_TI_INT8_Q5_TO_INT  TI方式INT8的Q5转化整形类型\n
*    LQ_TI_INT8_Q4_TO_INT  TI方式INT8的Q4转化整形类型\n
*    LQ_TI_INT8_Q3_TO_INT  TI方式INT8的Q3转化整形类型\n
*    LQ_TI_INT8_Q2_TO_INT  TI方式INT8的Q2转化整形类型\n
*    LQ_TI_INT8_Q1_TO_INT  TI方式INT8的Q1转化整形类型\n
*/
LQ_INLINE LQ_INT8_Q3 LQ_TI_INT8_Q3_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error){
    return (LQ_INT8_Q3)(((LQ_I_32BIT)A + (((LQ_I_32BIT)A < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 3) - 1u) : 0)) >> 3);
}
/**@brief (TI方法)INT8类型Q2格式转整形
* @details 采用估算位+指数位+符号位三位结合
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为整形数
* @code*    LQ_TI_INT8_Q2_TO_INT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_INT8_Q7_TO_INT  TI方式INT8的Q7转化整形类型\n
*    LQ_TI_INT8_Q6_TO_INT  TI方式INT8的Q6转化整形类型\n
*    LQ_TI_INT8_Q5_TO_INT  TI方式INT8的Q5转化整形类型\n
*    LQ_TI_INT8_Q4_TO_INT  TI方式INT8的Q4转化整形类型\n
*    LQ_TI_INT8_Q3_TO_INT  TI方式INT8的Q3转化整形类型\n
*    LQ_TI_INT8_Q2_TO_INT  TI方式INT8的Q2转化整形类型\n
*    LQ_TI_INT8_Q1_TO_INT  TI方式INT8的Q1转化整形类型\n
*/
LQ_INLINE LQ_INT8_Q2 LQ_TI_INT8_Q2_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error){
    return (LQ_INT8_Q2)(((LQ_I_32BIT)A + (((LQ_I_32BIT)A < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 2) - 1u) : 0)) >> 2);
}
/**@brief (TI方法)INT8类型Q1格式转整形
* @details 采用估算位+指数位+符号位三位结合
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为整形数
* @code*    LQ_TI_INT8_Q1_TO_INT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_INT8_Q7_TO_INT  TI方式INT8的Q7转化整形类型\n
*    LQ_TI_INT8_Q6_TO_INT  TI方式INT8的Q6转化整形类型\n
*    LQ_TI_INT8_Q5_TO_INT  TI方式INT8的Q5转化整形类型\n
*    LQ_TI_INT8_Q4_TO_INT  TI方式INT8的Q4转化整形类型\n
*    LQ_TI_INT8_Q3_TO_INT  TI方式INT8的Q3转化整形类型\n
*    LQ_TI_INT8_Q2_TO_INT  TI方式INT8的Q2转化整形类型\n
*    LQ_TI_INT8_Q1_TO_INT  TI方式INT8的Q1转化整形类型\n
*/
LQ_INLINE LQ_INT8_Q1 LQ_TI_INT8_Q1_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error){
    return (LQ_INT8_Q1)(((LQ_I_32BIT)A + (((LQ_I_32BIT)A < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 1) - 1u) : 0)) >> 1);
}
/**@brief (TI方法)UINT8类型UQ8格式转整形
* @details 采用估算位+指数位+符号位三位结合
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    整形
* @par       将Q格式转化为整形
* @code*    LQ_TI_UINT8_UQ8_TO_INT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_UINT8_UQ8_TO_INT  TI方式UINT8的UQ8转化整形类型\n
*  LQ_TI_UINT8_UQ7_TO_INT  TI方式UINT8的UQ7转化整形类型\n
*  LQ_TI_UINT8_UQ6_TO_INT  TI方式UINT8的UQ6转化整形类型\n
*  LQ_TI_UINT8_UQ5_TO_INT  TI方式UINT8的UQ5转化整形类型\n
*  LQ_TI_UINT8_UQ4_TO_INT  TI方式UINT8的UQ4转化整形类型\n
*  LQ_TI_UINT8_UQ3_TO_INT  TI方式UINT8的UQ3转化整形类型\n
*  LQ_TI_UINT8_UQ2_TO_INT  TI方式UINT8的UQ2转化整形类型\n
*  LQ_TI_UINT8_UQ1_TO_INT  TI方式UINT8的UQ1转化整形类型\n
*/
LQ_INLINE LQ_UINT8_UQ8 LQ_TI_UINT8_UQ8_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error){
    return (LQ_UINT8_UQ8)(((LQ_I_32BIT)A + (((LQ_I_32BIT)A < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 8) - 1u) : 0)) >> 8);
}
/**@brief (TI方法)UINT8类型UQ7格式转整形
* @details 采用估算位+指数位+符号位三位结合
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    整形
* @par       将Q格式转化为整形
* @code*    LQ_TI_UINT8_UQ7_TO_INT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_UINT8_UQ8_TO_INT  TI方式UINT8的UQ8转化整形类型\n
*  LQ_TI_UINT8_UQ7_TO_INT  TI方式UINT8的UQ7转化整形类型\n
*  LQ_TI_UINT8_UQ6_TO_INT  TI方式UINT8的UQ6转化整形类型\n
*  LQ_TI_UINT8_UQ5_TO_INT  TI方式UINT8的UQ5转化整形类型\n
*  LQ_TI_UINT8_UQ4_TO_INT  TI方式UINT8的UQ4转化整形类型\n
*  LQ_TI_UINT8_UQ3_TO_INT  TI方式UINT8的UQ3转化整形类型\n
*  LQ_TI_UINT8_UQ2_TO_INT  TI方式UINT8的UQ2转化整形类型\n
*  LQ_TI_UINT8_UQ1_TO_INT  TI方式UINT8的UQ1转化整形类型\n
*/
LQ_INLINE LQ_UINT8_UQ7 LQ_TI_UINT8_UQ7_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error){
    return (LQ_UINT8_UQ7)(((LQ_I_32BIT)A + (((LQ_I_32BIT)A < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 7) - 1u) : 0)) >> 7);
}
/**@brief (TI方法)UINT8类型UQ6格式转整形
* @details 采用估算位+指数位+符号位三位结合
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    整形
* @par       将Q格式转化为整形
* @code*    LQ_TI_UINT8_UQ6_TO_INT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_UINT8_UQ8_TO_INT  TI方式UINT8的UQ8转化整形类型\n
*  LQ_TI_UINT8_UQ7_TO_INT  TI方式UINT8的UQ7转化整形类型\n
*  LQ_TI_UINT8_UQ6_TO_INT  TI方式UINT8的UQ6转化整形类型\n
*  LQ_TI_UINT8_UQ5_TO_INT  TI方式UINT8的UQ5转化整形类型\n
*  LQ_TI_UINT8_UQ4_TO_INT  TI方式UINT8的UQ4转化整形类型\n
*  LQ_TI_UINT8_UQ3_TO_INT  TI方式UINT8的UQ3转化整形类型\n
*  LQ_TI_UINT8_UQ2_TO_INT  TI方式UINT8的UQ2转化整形类型\n
*  LQ_TI_UINT8_UQ1_TO_INT  TI方式UINT8的UQ1转化整形类型\n
*/
LQ_INLINE LQ_UINT8_UQ6 LQ_TI_UINT8_UQ6_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error){
    return (LQ_UINT8_UQ6)(((LQ_I_32BIT)A + (((LQ_I_32BIT)A < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 6) - 1u) : 0)) >> 6);
}
/**@brief (TI方法)UINT8类型UQ5格式转整形
* @details 采用估算位+指数位+符号位三位结合
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    整形
* @par       将Q格式转化为整形
* @code*    LQ_TI_UINT8_UQ5_TO_INT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_UINT8_UQ8_TO_INT  TI方式UINT8的UQ8转化整形类型\n
*  LQ_TI_UINT8_UQ7_TO_INT  TI方式UINT8的UQ7转化整形类型\n
*  LQ_TI_UINT8_UQ6_TO_INT  TI方式UINT8的UQ6转化整形类型\n
*  LQ_TI_UINT8_UQ5_TO_INT  TI方式UINT8的UQ5转化整形类型\n
*  LQ_TI_UINT8_UQ4_TO_INT  TI方式UINT8的UQ4转化整形类型\n
*  LQ_TI_UINT8_UQ3_TO_INT  TI方式UINT8的UQ3转化整形类型\n
*  LQ_TI_UINT8_UQ2_TO_INT  TI方式UINT8的UQ2转化整形类型\n
*  LQ_TI_UINT8_UQ1_TO_INT  TI方式UINT8的UQ1转化整形类型\n
*/
LQ_INLINE LQ_UINT8_UQ5 LQ_TI_UINT8_UQ5_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error){
    return (LQ_UINT8_UQ5)(((LQ_I_32BIT)A + (((LQ_I_32BIT)A < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 5) - 1u) : 0)) >> 5);
}
/**@brief (TI方法)UINT8类型UQ4格式转整形
* @details 采用估算位+指数位+符号位三位结合
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    整形
* @par       将Q格式转化为整形
* @code*    LQ_TI_UINT8_UQ4_TO_INT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_UINT8_UQ8_TO_INT  TI方式UINT8的UQ8转化整形类型\n
*  LQ_TI_UINT8_UQ7_TO_INT  TI方式UINT8的UQ7转化整形类型\n
*  LQ_TI_UINT8_UQ6_TO_INT  TI方式UINT8的UQ6转化整形类型\n
*  LQ_TI_UINT8_UQ5_TO_INT  TI方式UINT8的UQ5转化整形类型\n
*  LQ_TI_UINT8_UQ4_TO_INT  TI方式UINT8的UQ4转化整形类型\n
*  LQ_TI_UINT8_UQ3_TO_INT  TI方式UINT8的UQ3转化整形类型\n
*  LQ_TI_UINT8_UQ2_TO_INT  TI方式UINT8的UQ2转化整形类型\n
*  LQ_TI_UINT8_UQ1_TO_INT  TI方式UINT8的UQ1转化整形类型\n
*/
LQ_INLINE LQ_UINT8_UQ4 LQ_TI_UINT8_UQ4_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error){
    return (LQ_UINT8_UQ4)(((LQ_I_32BIT)A + (((LQ_I_32BIT)A < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 4) - 1u) : 0)) >> 4);
}
/**@brief (TI方法)UINT8类型UQ3格式转整形
* @details 采用估算位+指数位+符号位三位结合
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    整形
* @par       将Q格式转化为整形
* @code*    LQ_TI_UINT8_UQ3_TO_INT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_UINT8_UQ8_TO_INT  TI方式UINT8的UQ8转化整形类型\n
*  LQ_TI_UINT8_UQ7_TO_INT  TI方式UINT8的UQ7转化整形类型\n
*  LQ_TI_UINT8_UQ6_TO_INT  TI方式UINT8的UQ6转化整形类型\n
*  LQ_TI_UINT8_UQ5_TO_INT  TI方式UINT8的UQ5转化整形类型\n
*  LQ_TI_UINT8_UQ4_TO_INT  TI方式UINT8的UQ4转化整形类型\n
*  LQ_TI_UINT8_UQ3_TO_INT  TI方式UINT8的UQ3转化整形类型\n
*  LQ_TI_UINT8_UQ2_TO_INT  TI方式UINT8的UQ2转化整形类型\n
*  LQ_TI_UINT8_UQ1_TO_INT  TI方式UINT8的UQ1转化整形类型\n
*/
LQ_INLINE LQ_UINT8_UQ3 LQ_TI_UINT8_UQ3_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error){
    return (LQ_UINT8_UQ3)(((LQ_I_32BIT)A + (((LQ_I_32BIT)A < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 3) - 1u) : 0)) >> 3);
}
/**@brief (TI方法)UINT8类型UQ2格式转整形
* @details 采用估算位+指数位+符号位三位结合
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    整形
* @par       将Q格式转化为整形
* @code*    LQ_TI_UINT8_UQ2_TO_INT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_UINT8_UQ8_TO_INT  TI方式UINT8的UQ8转化整形类型\n
*  LQ_TI_UINT8_UQ7_TO_INT  TI方式UINT8的UQ7转化整形类型\n
*  LQ_TI_UINT8_UQ6_TO_INT  TI方式UINT8的UQ6转化整形类型\n
*  LQ_TI_UINT8_UQ5_TO_INT  TI方式UINT8的UQ5转化整形类型\n
*  LQ_TI_UINT8_UQ4_TO_INT  TI方式UINT8的UQ4转化整形类型\n
*  LQ_TI_UINT8_UQ3_TO_INT  TI方式UINT8的UQ3转化整形类型\n
*  LQ_TI_UINT8_UQ2_TO_INT  TI方式UINT8的UQ2转化整形类型\n
*  LQ_TI_UINT8_UQ1_TO_INT  TI方式UINT8的UQ1转化整形类型\n
*/
LQ_INLINE LQ_UINT8_UQ2 LQ_TI_UINT8_UQ2_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error){
    return (LQ_UINT8_UQ2)(((LQ_I_32BIT)A + (((LQ_I_32BIT)A < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 2) - 1u) : 0)) >> 2);
}
/**@brief (TI方法)UINT8类型UQ1格式转整形
* @details 采用估算位+指数位+符号位三位结合
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    整形
* @par       将Q格式转化为整形
* @code*    LQ_TI_UINT8_UQ1_TO_INT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_UINT8_UQ8_TO_INT  TI方式UINT8的UQ8转化整形类型\n
*  LQ_TI_UINT8_UQ7_TO_INT  TI方式UINT8的UQ7转化整形类型\n
*  LQ_TI_UINT8_UQ6_TO_INT  TI方式UINT8的UQ6转化整形类型\n
*  LQ_TI_UINT8_UQ5_TO_INT  TI方式UINT8的UQ5转化整形类型\n
*  LQ_TI_UINT8_UQ4_TO_INT  TI方式UINT8的UQ4转化整形类型\n
*  LQ_TI_UINT8_UQ3_TO_INT  TI方式UINT8的UQ3转化整形类型\n
*  LQ_TI_UINT8_UQ2_TO_INT  TI方式UINT8的UQ2转化整形类型\n
*  LQ_TI_UINT8_UQ1_TO_INT  TI方式UINT8的UQ1转化整形类型\n
*/
LQ_INLINE LQ_UINT8_UQ1 LQ_TI_UINT8_UQ1_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error){
    return (LQ_UINT8_UQ1)(((LQ_I_32BIT)A + (((LQ_I_32BIT)A < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 1) - 1u) : 0)) >> 1);
}
/**@brief (TI方法)INT16类型Q15格式转整形
* @details 采用估算位+指数位+符号位三位结合
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为整形数
* @code*    LQ_TI_INT16_Q15_TO_INT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_INT16_Q15_TO_INT  TI方式INT16的Q15转化整形类型\n
*    LQ_TI_INT16_Q14_TO_INT  TI方式INT16的Q14转化整形类型\n
*    LQ_TI_INT16_Q13_TO_INT  TI方式INT16的Q13转化整形类型\n
*    LQ_TI_INT16_Q12_TO_INT  TI方式INT16的Q12转化整形类型\n
*    LQ_TI_INT16_Q11_TO_INT  TI方式INT16的Q11转化整形类型\n
*    LQ_TI_INT16_Q10_TO_INT  TI方式INT16的Q10转化整形类型\n
*    LQ_TI_INT16_Q9_TO_INT  TI方式INT16的Q9转化整形类型\n
*    LQ_TI_INT16_Q8_TO_INT  TI方式INT16的Q8转化整形类型\n
*    LQ_TI_INT16_Q7_TO_INT  TI方式INT16的Q7转化整形类型\n
*    LQ_TI_INT16_Q6_TO_INT  TI方式INT16的Q6转化整形类型\n
*    LQ_TI_INT16_Q5_TO_INT  TI方式INT16的Q5转化整形类型\n
*    LQ_TI_INT16_Q4_TO_INT  TI方式INT16的Q4转化整形类型\n
*    LQ_TI_INT16_Q3_TO_INT  TI方式INT16的Q3转化整形类型\n
*    LQ_TI_INT16_Q2_TO_INT  TI方式INT16的Q2转化整形类型\n
*    LQ_TI_INT16_Q1_TO_INT  TI方式INT16的Q1转化整形类型\n
*/
LQ_INLINE LQ_INT16_Q15 LQ_TI_INT16_Q15_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error){
    return (LQ_INT16_Q15)(((LQ_I_32BIT)A + (((LQ_I_32BIT)A < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 15) - 1u) : 0)) >> 15);
}
/**@brief (TI方法)INT16类型Q14格式转整形
* @details 采用估算位+指数位+符号位三位结合
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为整形数
* @code*    LQ_TI_INT16_Q14_TO_INT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_INT16_Q15_TO_INT  TI方式INT16的Q15转化整形类型\n
*    LQ_TI_INT16_Q14_TO_INT  TI方式INT16的Q14转化整形类型\n
*    LQ_TI_INT16_Q13_TO_INT  TI方式INT16的Q13转化整形类型\n
*    LQ_TI_INT16_Q12_TO_INT  TI方式INT16的Q12转化整形类型\n
*    LQ_TI_INT16_Q11_TO_INT  TI方式INT16的Q11转化整形类型\n
*    LQ_TI_INT16_Q10_TO_INT  TI方式INT16的Q10转化整形类型\n
*    LQ_TI_INT16_Q9_TO_INT  TI方式INT16的Q9转化整形类型\n
*    LQ_TI_INT16_Q8_TO_INT  TI方式INT16的Q8转化整形类型\n
*    LQ_TI_INT16_Q7_TO_INT  TI方式INT16的Q7转化整形类型\n
*    LQ_TI_INT16_Q6_TO_INT  TI方式INT16的Q6转化整形类型\n
*    LQ_TI_INT16_Q5_TO_INT  TI方式INT16的Q5转化整形类型\n
*    LQ_TI_INT16_Q4_TO_INT  TI方式INT16的Q4转化整形类型\n
*    LQ_TI_INT16_Q3_TO_INT  TI方式INT16的Q3转化整形类型\n
*    LQ_TI_INT16_Q2_TO_INT  TI方式INT16的Q2转化整形类型\n
*    LQ_TI_INT16_Q1_TO_INT  TI方式INT16的Q1转化整形类型\n
*/
LQ_INLINE LQ_INT16_Q14 LQ_TI_INT16_Q14_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error){
    return (LQ_INT16_Q14)(((LQ_I_32BIT)A + (((LQ_I_32BIT)A < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 14) - 1u) : 0)) >> 14);
}
/**@brief (TI方法)INT16类型Q13格式转整形
* @details 采用估算位+指数位+符号位三位结合
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为整形数
* @code*    LQ_TI_INT16_Q13_TO_INT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_INT16_Q15_TO_INT  TI方式INT16的Q15转化整形类型\n
*    LQ_TI_INT16_Q14_TO_INT  TI方式INT16的Q14转化整形类型\n
*    LQ_TI_INT16_Q13_TO_INT  TI方式INT16的Q13转化整形类型\n
*    LQ_TI_INT16_Q12_TO_INT  TI方式INT16的Q12转化整形类型\n
*    LQ_TI_INT16_Q11_TO_INT  TI方式INT16的Q11转化整形类型\n
*    LQ_TI_INT16_Q10_TO_INT  TI方式INT16的Q10转化整形类型\n
*    LQ_TI_INT16_Q9_TO_INT  TI方式INT16的Q9转化整形类型\n
*    LQ_TI_INT16_Q8_TO_INT  TI方式INT16的Q8转化整形类型\n
*    LQ_TI_INT16_Q7_TO_INT  TI方式INT16的Q7转化整形类型\n
*    LQ_TI_INT16_Q6_TO_INT  TI方式INT16的Q6转化整形类型\n
*    LQ_TI_INT16_Q5_TO_INT  TI方式INT16的Q5转化整形类型\n
*    LQ_TI_INT16_Q4_TO_INT  TI方式INT16的Q4转化整形类型\n
*    LQ_TI_INT16_Q3_TO_INT  TI方式INT16的Q3转化整形类型\n
*    LQ_TI_INT16_Q2_TO_INT  TI方式INT16的Q2转化整形类型\n
*    LQ_TI_INT16_Q1_TO_INT  TI方式INT16的Q1转化整形类型\n
*/
LQ_INLINE LQ_INT16_Q13 LQ_TI_INT16_Q13_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error){
    return (LQ_INT16_Q13)(((LQ_I_32BIT)A + (((LQ_I_32BIT)A < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 13) - 1u) : 0)) >> 13);
}
/**@brief (TI方法)INT16类型Q12格式转整形
* @details 采用估算位+指数位+符号位三位结合
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为整形数
* @code*    LQ_TI_INT16_Q12_TO_INT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_INT16_Q15_TO_INT  TI方式INT16的Q15转化整形类型\n
*    LQ_TI_INT16_Q14_TO_INT  TI方式INT16的Q14转化整形类型\n
*    LQ_TI_INT16_Q13_TO_INT  TI方式INT16的Q13转化整形类型\n
*    LQ_TI_INT16_Q12_TO_INT  TI方式INT16的Q12转化整形类型\n
*    LQ_TI_INT16_Q11_TO_INT  TI方式INT16的Q11转化整形类型\n
*    LQ_TI_INT16_Q10_TO_INT  TI方式INT16的Q10转化整形类型\n
*    LQ_TI_INT16_Q9_TO_INT  TI方式INT16的Q9转化整形类型\n
*    LQ_TI_INT16_Q8_TO_INT  TI方式INT16的Q8转化整形类型\n
*    LQ_TI_INT16_Q7_TO_INT  TI方式INT16的Q7转化整形类型\n
*    LQ_TI_INT16_Q6_TO_INT  TI方式INT16的Q6转化整形类型\n
*    LQ_TI_INT16_Q5_TO_INT  TI方式INT16的Q5转化整形类型\n
*    LQ_TI_INT16_Q4_TO_INT  TI方式INT16的Q4转化整形类型\n
*    LQ_TI_INT16_Q3_TO_INT  TI方式INT16的Q3转化整形类型\n
*    LQ_TI_INT16_Q2_TO_INT  TI方式INT16的Q2转化整形类型\n
*    LQ_TI_INT16_Q1_TO_INT  TI方式INT16的Q1转化整形类型\n
*/
LQ_INLINE LQ_INT16_Q12 LQ_TI_INT16_Q12_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error){
    return (LQ_INT16_Q12)(((LQ_I_32BIT)A + (((LQ_I_32BIT)A < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 12) - 1u) : 0)) >> 12);
}
/**@brief (TI方法)INT16类型Q11格式转整形
* @details 采用估算位+指数位+符号位三位结合
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为整形数
* @code*    LQ_TI_INT16_Q11_TO_INT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_INT16_Q15_TO_INT  TI方式INT16的Q15转化整形类型\n
*    LQ_TI_INT16_Q14_TO_INT  TI方式INT16的Q14转化整形类型\n
*    LQ_TI_INT16_Q13_TO_INT  TI方式INT16的Q13转化整形类型\n
*    LQ_TI_INT16_Q12_TO_INT  TI方式INT16的Q12转化整形类型\n
*    LQ_TI_INT16_Q11_TO_INT  TI方式INT16的Q11转化整形类型\n
*    LQ_TI_INT16_Q10_TO_INT  TI方式INT16的Q10转化整形类型\n
*    LQ_TI_INT16_Q9_TO_INT  TI方式INT16的Q9转化整形类型\n
*    LQ_TI_INT16_Q8_TO_INT  TI方式INT16的Q8转化整形类型\n
*    LQ_TI_INT16_Q7_TO_INT  TI方式INT16的Q7转化整形类型\n
*    LQ_TI_INT16_Q6_TO_INT  TI方式INT16的Q6转化整形类型\n
*    LQ_TI_INT16_Q5_TO_INT  TI方式INT16的Q5转化整形类型\n
*    LQ_TI_INT16_Q4_TO_INT  TI方式INT16的Q4转化整形类型\n
*    LQ_TI_INT16_Q3_TO_INT  TI方式INT16的Q3转化整形类型\n
*    LQ_TI_INT16_Q2_TO_INT  TI方式INT16的Q2转化整形类型\n
*    LQ_TI_INT16_Q1_TO_INT  TI方式INT16的Q1转化整形类型\n
*/
LQ_INLINE LQ_INT16_Q11 LQ_TI_INT16_Q11_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error){
    return (LQ_INT16_Q11)(((LQ_I_32BIT)A + (((LQ_I_32BIT)A < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 11) - 1u) : 0)) >> 11);
}
/**@brief (TI方法)INT16类型Q10格式转整形
* @details 采用估算位+指数位+符号位三位结合
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为整形数
* @code*    LQ_TI_INT16_Q10_TO_INT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_INT16_Q15_TO_INT  TI方式INT16的Q15转化整形类型\n
*    LQ_TI_INT16_Q14_TO_INT  TI方式INT16的Q14转化整形类型\n
*    LQ_TI_INT16_Q13_TO_INT  TI方式INT16的Q13转化整形类型\n
*    LQ_TI_INT16_Q12_TO_INT  TI方式INT16的Q12转化整形类型\n
*    LQ_TI_INT16_Q11_TO_INT  TI方式INT16的Q11转化整形类型\n
*    LQ_TI_INT16_Q10_TO_INT  TI方式INT16的Q10转化整形类型\n
*    LQ_TI_INT16_Q9_TO_INT  TI方式INT16的Q9转化整形类型\n
*    LQ_TI_INT16_Q8_TO_INT  TI方式INT16的Q8转化整形类型\n
*    LQ_TI_INT16_Q7_TO_INT  TI方式INT16的Q7转化整形类型\n
*    LQ_TI_INT16_Q6_TO_INT  TI方式INT16的Q6转化整形类型\n
*    LQ_TI_INT16_Q5_TO_INT  TI方式INT16的Q5转化整形类型\n
*    LQ_TI_INT16_Q4_TO_INT  TI方式INT16的Q4转化整形类型\n
*    LQ_TI_INT16_Q3_TO_INT  TI方式INT16的Q3转化整形类型\n
*    LQ_TI_INT16_Q2_TO_INT  TI方式INT16的Q2转化整形类型\n
*    LQ_TI_INT16_Q1_TO_INT  TI方式INT16的Q1转化整形类型\n
*/
LQ_INLINE LQ_INT16_Q10 LQ_TI_INT16_Q10_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error){
    return (LQ_INT16_Q10)(((LQ_I_32BIT)A + (((LQ_I_32BIT)A < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 10) - 1u) : 0)) >> 10);
}
/**@brief (TI方法)INT16类型Q9格式转整形
* @details 采用估算位+指数位+符号位三位结合
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为整形数
* @code*    LQ_TI_INT16_Q9_TO_INT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_INT16_Q15_TO_INT  TI方式INT16的Q15转化整形类型\n
*    LQ_TI_INT16_Q14_TO_INT  TI方式INT16的Q14转化整形类型\n
*    LQ_TI_INT16_Q13_TO_INT  TI方式INT16的Q13转化整形类型\n
*    LQ_TI_INT16_Q12_TO_INT  TI方式INT16的Q12转化整形类型\n
*    LQ_TI_INT16_Q11_TO_INT  TI方式INT16的Q11转化整形类型\n
*    LQ_TI_INT16_Q10_TO_INT  TI方式INT16的Q10转化整形类型\n
*    LQ_TI_INT16_Q9_TO_INT  TI方式INT16的Q9转化整形类型\n
*    LQ_TI_INT16_Q8_TO_INT  TI方式INT16的Q8转化整形类型\n
*    LQ_TI_INT16_Q7_TO_INT  TI方式INT16的Q7转化整形类型\n
*    LQ_TI_INT16_Q6_TO_INT  TI方式INT16的Q6转化整形类型\n
*    LQ_TI_INT16_Q5_TO_INT  TI方式INT16的Q5转化整形类型\n
*    LQ_TI_INT16_Q4_TO_INT  TI方式INT16的Q4转化整形类型\n
*    LQ_TI_INT16_Q3_TO_INT  TI方式INT16的Q3转化整形类型\n
*    LQ_TI_INT16_Q2_TO_INT  TI方式INT16的Q2转化整形类型\n
*    LQ_TI_INT16_Q1_TO_INT  TI方式INT16的Q1转化整形类型\n
*/
LQ_INLINE LQ_INT16_Q9 LQ_TI_INT16_Q9_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error){
    return (LQ_INT16_Q9)(((LQ_I_32BIT)A + (((LQ_I_32BIT)A < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 9) - 1u) : 0)) >> 9);
}
/**@brief (TI方法)INT16类型Q8格式转整形
* @details 采用估算位+指数位+符号位三位结合
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为整形数
* @code*    LQ_TI_INT16_Q8_TO_INT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_INT16_Q15_TO_INT  TI方式INT16的Q15转化整形类型\n
*    LQ_TI_INT16_Q14_TO_INT  TI方式INT16的Q14转化整形类型\n
*    LQ_TI_INT16_Q13_TO_INT  TI方式INT16的Q13转化整形类型\n
*    LQ_TI_INT16_Q12_TO_INT  TI方式INT16的Q12转化整形类型\n
*    LQ_TI_INT16_Q11_TO_INT  TI方式INT16的Q11转化整形类型\n
*    LQ_TI_INT16_Q10_TO_INT  TI方式INT16的Q10转化整形类型\n
*    LQ_TI_INT16_Q9_TO_INT  TI方式INT16的Q9转化整形类型\n
*    LQ_TI_INT16_Q8_TO_INT  TI方式INT16的Q8转化整形类型\n
*    LQ_TI_INT16_Q7_TO_INT  TI方式INT16的Q7转化整形类型\n
*    LQ_TI_INT16_Q6_TO_INT  TI方式INT16的Q6转化整形类型\n
*    LQ_TI_INT16_Q5_TO_INT  TI方式INT16的Q5转化整形类型\n
*    LQ_TI_INT16_Q4_TO_INT  TI方式INT16的Q4转化整形类型\n
*    LQ_TI_INT16_Q3_TO_INT  TI方式INT16的Q3转化整形类型\n
*    LQ_TI_INT16_Q2_TO_INT  TI方式INT16的Q2转化整形类型\n
*    LQ_TI_INT16_Q1_TO_INT  TI方式INT16的Q1转化整形类型\n
*/
LQ_INLINE LQ_INT16_Q8 LQ_TI_INT16_Q8_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error){
    return (LQ_INT16_Q8)(((LQ_I_32BIT)A + (((LQ_I_32BIT)A < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 8) - 1u) : 0)) >> 8);
}
/**@brief (TI方法)INT16类型Q7格式转整形
* @details 采用估算位+指数位+符号位三位结合
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为整形数
* @code*    LQ_TI_INT16_Q7_TO_INT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_INT16_Q15_TO_INT  TI方式INT16的Q15转化整形类型\n
*    LQ_TI_INT16_Q14_TO_INT  TI方式INT16的Q14转化整形类型\n
*    LQ_TI_INT16_Q13_TO_INT  TI方式INT16的Q13转化整形类型\n
*    LQ_TI_INT16_Q12_TO_INT  TI方式INT16的Q12转化整形类型\n
*    LQ_TI_INT16_Q11_TO_INT  TI方式INT16的Q11转化整形类型\n
*    LQ_TI_INT16_Q10_TO_INT  TI方式INT16的Q10转化整形类型\n
*    LQ_TI_INT16_Q9_TO_INT  TI方式INT16的Q9转化整形类型\n
*    LQ_TI_INT16_Q8_TO_INT  TI方式INT16的Q8转化整形类型\n
*    LQ_TI_INT16_Q7_TO_INT  TI方式INT16的Q7转化整形类型\n
*    LQ_TI_INT16_Q6_TO_INT  TI方式INT16的Q6转化整形类型\n
*    LQ_TI_INT16_Q5_TO_INT  TI方式INT16的Q5转化整形类型\n
*    LQ_TI_INT16_Q4_TO_INT  TI方式INT16的Q4转化整形类型\n
*    LQ_TI_INT16_Q3_TO_INT  TI方式INT16的Q3转化整形类型\n
*    LQ_TI_INT16_Q2_TO_INT  TI方式INT16的Q2转化整形类型\n
*    LQ_TI_INT16_Q1_TO_INT  TI方式INT16的Q1转化整形类型\n
*/
LQ_INLINE LQ_INT16_Q7 LQ_TI_INT16_Q7_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error){
    return (LQ_INT16_Q7)(((LQ_I_32BIT)A + (((LQ_I_32BIT)A < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 7) - 1u) : 0)) >> 7);
}
/**@brief (TI方法)INT16类型Q6格式转整形
* @details 采用估算位+指数位+符号位三位结合
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为整形数
* @code*    LQ_TI_INT16_Q6_TO_INT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_INT16_Q15_TO_INT  TI方式INT16的Q15转化整形类型\n
*    LQ_TI_INT16_Q14_TO_INT  TI方式INT16的Q14转化整形类型\n
*    LQ_TI_INT16_Q13_TO_INT  TI方式INT16的Q13转化整形类型\n
*    LQ_TI_INT16_Q12_TO_INT  TI方式INT16的Q12转化整形类型\n
*    LQ_TI_INT16_Q11_TO_INT  TI方式INT16的Q11转化整形类型\n
*    LQ_TI_INT16_Q10_TO_INT  TI方式INT16的Q10转化整形类型\n
*    LQ_TI_INT16_Q9_TO_INT  TI方式INT16的Q9转化整形类型\n
*    LQ_TI_INT16_Q8_TO_INT  TI方式INT16的Q8转化整形类型\n
*    LQ_TI_INT16_Q7_TO_INT  TI方式INT16的Q7转化整形类型\n
*    LQ_TI_INT16_Q6_TO_INT  TI方式INT16的Q6转化整形类型\n
*    LQ_TI_INT16_Q5_TO_INT  TI方式INT16的Q5转化整形类型\n
*    LQ_TI_INT16_Q4_TO_INT  TI方式INT16的Q4转化整形类型\n
*    LQ_TI_INT16_Q3_TO_INT  TI方式INT16的Q3转化整形类型\n
*    LQ_TI_INT16_Q2_TO_INT  TI方式INT16的Q2转化整形类型\n
*    LQ_TI_INT16_Q1_TO_INT  TI方式INT16的Q1转化整形类型\n
*/
LQ_INLINE LQ_INT16_Q6 LQ_TI_INT16_Q6_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error){
    return (LQ_INT16_Q6)(((LQ_I_32BIT)A + (((LQ_I_32BIT)A < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 6) - 1u) : 0)) >> 6);
}
/**@brief (TI方法)INT16类型Q5格式转整形
* @details 采用估算位+指数位+符号位三位结合
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为整形数
* @code*    LQ_TI_INT16_Q5_TO_INT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_INT16_Q15_TO_INT  TI方式INT16的Q15转化整形类型\n
*    LQ_TI_INT16_Q14_TO_INT  TI方式INT16的Q14转化整形类型\n
*    LQ_TI_INT16_Q13_TO_INT  TI方式INT16的Q13转化整形类型\n
*    LQ_TI_INT16_Q12_TO_INT  TI方式INT16的Q12转化整形类型\n
*    LQ_TI_INT16_Q11_TO_INT  TI方式INT16的Q11转化整形类型\n
*    LQ_TI_INT16_Q10_TO_INT  TI方式INT16的Q10转化整形类型\n
*    LQ_TI_INT16_Q9_TO_INT  TI方式INT16的Q9转化整形类型\n
*    LQ_TI_INT16_Q8_TO_INT  TI方式INT16的Q8转化整形类型\n
*    LQ_TI_INT16_Q7_TO_INT  TI方式INT16的Q7转化整形类型\n
*    LQ_TI_INT16_Q6_TO_INT  TI方式INT16的Q6转化整形类型\n
*    LQ_TI_INT16_Q5_TO_INT  TI方式INT16的Q5转化整形类型\n
*    LQ_TI_INT16_Q4_TO_INT  TI方式INT16的Q4转化整形类型\n
*    LQ_TI_INT16_Q3_TO_INT  TI方式INT16的Q3转化整形类型\n
*    LQ_TI_INT16_Q2_TO_INT  TI方式INT16的Q2转化整形类型\n
*    LQ_TI_INT16_Q1_TO_INT  TI方式INT16的Q1转化整形类型\n
*/
LQ_INLINE LQ_INT16_Q5 LQ_TI_INT16_Q5_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error){
    return (LQ_INT16_Q5)(((LQ_I_32BIT)A + (((LQ_I_32BIT)A < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 5) - 1u) : 0)) >> 5);
}
/**@brief (TI方法)INT16类型Q4格式转整形
* @details 采用估算位+指数位+符号位三位结合
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为整形数
* @code*    LQ_TI_INT16_Q4_TO_INT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_INT16_Q15_TO_INT  TI方式INT16的Q15转化整形类型\n
*    LQ_TI_INT16_Q14_TO_INT  TI方式INT16的Q14转化整形类型\n
*    LQ_TI_INT16_Q13_TO_INT  TI方式INT16的Q13转化整形类型\n
*    LQ_TI_INT16_Q12_TO_INT  TI方式INT16的Q12转化整形类型\n
*    LQ_TI_INT16_Q11_TO_INT  TI方式INT16的Q11转化整形类型\n
*    LQ_TI_INT16_Q10_TO_INT  TI方式INT16的Q10转化整形类型\n
*    LQ_TI_INT16_Q9_TO_INT  TI方式INT16的Q9转化整形类型\n
*    LQ_TI_INT16_Q8_TO_INT  TI方式INT16的Q8转化整形类型\n
*    LQ_TI_INT16_Q7_TO_INT  TI方式INT16的Q7转化整形类型\n
*    LQ_TI_INT16_Q6_TO_INT  TI方式INT16的Q6转化整形类型\n
*    LQ_TI_INT16_Q5_TO_INT  TI方式INT16的Q5转化整形类型\n
*    LQ_TI_INT16_Q4_TO_INT  TI方式INT16的Q4转化整形类型\n
*    LQ_TI_INT16_Q3_TO_INT  TI方式INT16的Q3转化整形类型\n
*    LQ_TI_INT16_Q2_TO_INT  TI方式INT16的Q2转化整形类型\n
*    LQ_TI_INT16_Q1_TO_INT  TI方式INT16的Q1转化整形类型\n
*/
LQ_INLINE LQ_INT16_Q4 LQ_TI_INT16_Q4_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error){
    return (LQ_INT16_Q4)(((LQ_I_32BIT)A + (((LQ_I_32BIT)A < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 4) - 1u) : 0)) >> 4);
}
/**@brief (TI方法)INT16类型Q3格式转整形
* @details 采用估算位+指数位+符号位三位结合
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为整形数
* @code*    LQ_TI_INT16_Q3_TO_INT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_INT16_Q15_TO_INT  TI方式INT16的Q15转化整形类型\n
*    LQ_TI_INT16_Q14_TO_INT  TI方式INT16的Q14转化整形类型\n
*    LQ_TI_INT16_Q13_TO_INT  TI方式INT16的Q13转化整形类型\n
*    LQ_TI_INT16_Q12_TO_INT  TI方式INT16的Q12转化整形类型\n
*    LQ_TI_INT16_Q11_TO_INT  TI方式INT16的Q11转化整形类型\n
*    LQ_TI_INT16_Q10_TO_INT  TI方式INT16的Q10转化整形类型\n
*    LQ_TI_INT16_Q9_TO_INT  TI方式INT16的Q9转化整形类型\n
*    LQ_TI_INT16_Q8_TO_INT  TI方式INT16的Q8转化整形类型\n
*    LQ_TI_INT16_Q7_TO_INT  TI方式INT16的Q7转化整形类型\n
*    LQ_TI_INT16_Q6_TO_INT  TI方式INT16的Q6转化整形类型\n
*    LQ_TI_INT16_Q5_TO_INT  TI方式INT16的Q5转化整形类型\n
*    LQ_TI_INT16_Q4_TO_INT  TI方式INT16的Q4转化整形类型\n
*    LQ_TI_INT16_Q3_TO_INT  TI方式INT16的Q3转化整形类型\n
*    LQ_TI_INT16_Q2_TO_INT  TI方式INT16的Q2转化整形类型\n
*    LQ_TI_INT16_Q1_TO_INT  TI方式INT16的Q1转化整形类型\n
*/
LQ_INLINE LQ_INT16_Q3 LQ_TI_INT16_Q3_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error){
    return (LQ_INT16_Q3)(((LQ_I_32BIT)A + (((LQ_I_32BIT)A < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 3) - 1u) : 0)) >> 3);
}
/**@brief (TI方法)INT16类型Q2格式转整形
* @details 采用估算位+指数位+符号位三位结合
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为整形数
* @code*    LQ_TI_INT16_Q2_TO_INT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_INT16_Q15_TO_INT  TI方式INT16的Q15转化整形类型\n
*    LQ_TI_INT16_Q14_TO_INT  TI方式INT16的Q14转化整形类型\n
*    LQ_TI_INT16_Q13_TO_INT  TI方式INT16的Q13转化整形类型\n
*    LQ_TI_INT16_Q12_TO_INT  TI方式INT16的Q12转化整形类型\n
*    LQ_TI_INT16_Q11_TO_INT  TI方式INT16的Q11转化整形类型\n
*    LQ_TI_INT16_Q10_TO_INT  TI方式INT16的Q10转化整形类型\n
*    LQ_TI_INT16_Q9_TO_INT  TI方式INT16的Q9转化整形类型\n
*    LQ_TI_INT16_Q8_TO_INT  TI方式INT16的Q8转化整形类型\n
*    LQ_TI_INT16_Q7_TO_INT  TI方式INT16的Q7转化整形类型\n
*    LQ_TI_INT16_Q6_TO_INT  TI方式INT16的Q6转化整形类型\n
*    LQ_TI_INT16_Q5_TO_INT  TI方式INT16的Q5转化整形类型\n
*    LQ_TI_INT16_Q4_TO_INT  TI方式INT16的Q4转化整形类型\n
*    LQ_TI_INT16_Q3_TO_INT  TI方式INT16的Q3转化整形类型\n
*    LQ_TI_INT16_Q2_TO_INT  TI方式INT16的Q2转化整形类型\n
*    LQ_TI_INT16_Q1_TO_INT  TI方式INT16的Q1转化整形类型\n
*/
LQ_INLINE LQ_INT16_Q2 LQ_TI_INT16_Q2_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error){
    return (LQ_INT16_Q2)(((LQ_I_32BIT)A + (((LQ_I_32BIT)A < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 2) - 1u) : 0)) >> 2);
}
/**@brief (TI方法)INT16类型Q1格式转整形
* @details 采用估算位+指数位+符号位三位结合
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为整形数
* @code*    LQ_TI_INT16_Q1_TO_INT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_INT16_Q15_TO_INT  TI方式INT16的Q15转化整形类型\n
*    LQ_TI_INT16_Q14_TO_INT  TI方式INT16的Q14转化整形类型\n
*    LQ_TI_INT16_Q13_TO_INT  TI方式INT16的Q13转化整形类型\n
*    LQ_TI_INT16_Q12_TO_INT  TI方式INT16的Q12转化整形类型\n
*    LQ_TI_INT16_Q11_TO_INT  TI方式INT16的Q11转化整形类型\n
*    LQ_TI_INT16_Q10_TO_INT  TI方式INT16的Q10转化整形类型\n
*    LQ_TI_INT16_Q9_TO_INT  TI方式INT16的Q9转化整形类型\n
*    LQ_TI_INT16_Q8_TO_INT  TI方式INT16的Q8转化整形类型\n
*    LQ_TI_INT16_Q7_TO_INT  TI方式INT16的Q7转化整形类型\n
*    LQ_TI_INT16_Q6_TO_INT  TI方式INT16的Q6转化整形类型\n
*    LQ_TI_INT16_Q5_TO_INT  TI方式INT16的Q5转化整形类型\n
*    LQ_TI_INT16_Q4_TO_INT  TI方式INT16的Q4转化整形类型\n
*    LQ_TI_INT16_Q3_TO_INT  TI方式INT16的Q3转化整形类型\n
*    LQ_TI_INT16_Q2_TO_INT  TI方式INT16的Q2转化整形类型\n
*    LQ_TI_INT16_Q1_TO_INT  TI方式INT16的Q1转化整形类型\n
*/
LQ_INLINE LQ_INT16_Q1 LQ_TI_INT16_Q1_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error){
    return (LQ_INT16_Q1)(((LQ_I_32BIT)A + (((LQ_I_32BIT)A < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 1) - 1u) : 0)) >> 1);
}
/**@brief (TI方法)UINT16类型UQ16格式转整形
* @details 采用估算位+指数位+符号位三位结合
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    整形
* @par       将Q格式转化为整形
* @code*    LQ_TI_UINT16_UQ16_TO_INT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_UINT16_UQ16_TO_INT  TI方式UINT16的UQ16转化整形类型\n
*  LQ_TI_UINT16_UQ15_TO_INT  TI方式UINT16的UQ15转化整形类型\n
*  LQ_TI_UINT16_UQ14_TO_INT  TI方式UINT16的UQ14转化整形类型\n
*  LQ_TI_UINT16_UQ13_TO_INT  TI方式UINT16的UQ13转化整形类型\n
*  LQ_TI_UINT16_UQ12_TO_INT  TI方式UINT16的UQ12转化整形类型\n
*  LQ_TI_UINT16_UQ11_TO_INT  TI方式UINT16的UQ11转化整形类型\n
*  LQ_TI_UINT16_UQ10_TO_INT  TI方式UINT16的UQ10转化整形类型\n
*  LQ_TI_UINT16_UQ9_TO_INT  TI方式UINT16的UQ9转化整形类型\n
*  LQ_TI_UINT16_UQ8_TO_INT  TI方式UINT16的UQ8转化整形类型\n
*  LQ_TI_UINT16_UQ7_TO_INT  TI方式UINT16的UQ7转化整形类型\n
*  LQ_TI_UINT16_UQ6_TO_INT  TI方式UINT16的UQ6转化整形类型\n
*  LQ_TI_UINT16_UQ5_TO_INT  TI方式UINT16的UQ5转化整形类型\n
*  LQ_TI_UINT16_UQ4_TO_INT  TI方式UINT16的UQ4转化整形类型\n
*  LQ_TI_UINT16_UQ3_TO_INT  TI方式UINT16的UQ3转化整形类型\n
*  LQ_TI_UINT16_UQ2_TO_INT  TI方式UINT16的UQ2转化整形类型\n
*  LQ_TI_UINT16_UQ1_TO_INT  TI方式UINT16的UQ1转化整形类型\n
*/
LQ_INLINE LQ_UINT16_UQ16 LQ_TI_UINT16_UQ16_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error){
    return (LQ_UINT16_UQ16)(((LQ_I_32BIT)A + (((LQ_I_32BIT)A < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 16) - 1u) : 0)) >> 16);
}
/**@brief (TI方法)UINT16类型UQ15格式转整形
* @details 采用估算位+指数位+符号位三位结合
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    整形
* @par       将Q格式转化为整形
* @code*    LQ_TI_UINT16_UQ15_TO_INT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_UINT16_UQ16_TO_INT  TI方式UINT16的UQ16转化整形类型\n
*  LQ_TI_UINT16_UQ15_TO_INT  TI方式UINT16的UQ15转化整形类型\n
*  LQ_TI_UINT16_UQ14_TO_INT  TI方式UINT16的UQ14转化整形类型\n
*  LQ_TI_UINT16_UQ13_TO_INT  TI方式UINT16的UQ13转化整形类型\n
*  LQ_TI_UINT16_UQ12_TO_INT  TI方式UINT16的UQ12转化整形类型\n
*  LQ_TI_UINT16_UQ11_TO_INT  TI方式UINT16的UQ11转化整形类型\n
*  LQ_TI_UINT16_UQ10_TO_INT  TI方式UINT16的UQ10转化整形类型\n
*  LQ_TI_UINT16_UQ9_TO_INT  TI方式UINT16的UQ9转化整形类型\n
*  LQ_TI_UINT16_UQ8_TO_INT  TI方式UINT16的UQ8转化整形类型\n
*  LQ_TI_UINT16_UQ7_TO_INT  TI方式UINT16的UQ7转化整形类型\n
*  LQ_TI_UINT16_UQ6_TO_INT  TI方式UINT16的UQ6转化整形类型\n
*  LQ_TI_UINT16_UQ5_TO_INT  TI方式UINT16的UQ5转化整形类型\n
*  LQ_TI_UINT16_UQ4_TO_INT  TI方式UINT16的UQ4转化整形类型\n
*  LQ_TI_UINT16_UQ3_TO_INT  TI方式UINT16的UQ3转化整形类型\n
*  LQ_TI_UINT16_UQ2_TO_INT  TI方式UINT16的UQ2转化整形类型\n
*  LQ_TI_UINT16_UQ1_TO_INT  TI方式UINT16的UQ1转化整形类型\n
*/
LQ_INLINE LQ_UINT16_UQ15 LQ_TI_UINT16_UQ15_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error){
    return (LQ_UINT16_UQ15)(((LQ_I_32BIT)A + (((LQ_I_32BIT)A < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 15) - 1u) : 0)) >> 15);
}
/**@brief (TI方法)UINT16类型UQ14格式转整形
* @details 采用估算位+指数位+符号位三位结合
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    整形
* @par       将Q格式转化为整形
* @code*    LQ_TI_UINT16_UQ14_TO_INT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_UINT16_UQ16_TO_INT  TI方式UINT16的UQ16转化整形类型\n
*  LQ_TI_UINT16_UQ15_TO_INT  TI方式UINT16的UQ15转化整形类型\n
*  LQ_TI_UINT16_UQ14_TO_INT  TI方式UINT16的UQ14转化整形类型\n
*  LQ_TI_UINT16_UQ13_TO_INT  TI方式UINT16的UQ13转化整形类型\n
*  LQ_TI_UINT16_UQ12_TO_INT  TI方式UINT16的UQ12转化整形类型\n
*  LQ_TI_UINT16_UQ11_TO_INT  TI方式UINT16的UQ11转化整形类型\n
*  LQ_TI_UINT16_UQ10_TO_INT  TI方式UINT16的UQ10转化整形类型\n
*  LQ_TI_UINT16_UQ9_TO_INT  TI方式UINT16的UQ9转化整形类型\n
*  LQ_TI_UINT16_UQ8_TO_INT  TI方式UINT16的UQ8转化整形类型\n
*  LQ_TI_UINT16_UQ7_TO_INT  TI方式UINT16的UQ7转化整形类型\n
*  LQ_TI_UINT16_UQ6_TO_INT  TI方式UINT16的UQ6转化整形类型\n
*  LQ_TI_UINT16_UQ5_TO_INT  TI方式UINT16的UQ5转化整形类型\n
*  LQ_TI_UINT16_UQ4_TO_INT  TI方式UINT16的UQ4转化整形类型\n
*  LQ_TI_UINT16_UQ3_TO_INT  TI方式UINT16的UQ3转化整形类型\n
*  LQ_TI_UINT16_UQ2_TO_INT  TI方式UINT16的UQ2转化整形类型\n
*  LQ_TI_UINT16_UQ1_TO_INT  TI方式UINT16的UQ1转化整形类型\n
*/
LQ_INLINE LQ_UINT16_UQ14 LQ_TI_UINT16_UQ14_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error){
    return (LQ_UINT16_UQ14)(((LQ_I_32BIT)A + (((LQ_I_32BIT)A < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 14) - 1u) : 0)) >> 14);
}
/**@brief (TI方法)UINT16类型UQ13格式转整形
* @details 采用估算位+指数位+符号位三位结合
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    整形
* @par       将Q格式转化为整形
* @code*    LQ_TI_UINT16_UQ13_TO_INT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_UINT16_UQ16_TO_INT  TI方式UINT16的UQ16转化整形类型\n
*  LQ_TI_UINT16_UQ15_TO_INT  TI方式UINT16的UQ15转化整形类型\n
*  LQ_TI_UINT16_UQ14_TO_INT  TI方式UINT16的UQ14转化整形类型\n
*  LQ_TI_UINT16_UQ13_TO_INT  TI方式UINT16的UQ13转化整形类型\n
*  LQ_TI_UINT16_UQ12_TO_INT  TI方式UINT16的UQ12转化整形类型\n
*  LQ_TI_UINT16_UQ11_TO_INT  TI方式UINT16的UQ11转化整形类型\n
*  LQ_TI_UINT16_UQ10_TO_INT  TI方式UINT16的UQ10转化整形类型\n
*  LQ_TI_UINT16_UQ9_TO_INT  TI方式UINT16的UQ9转化整形类型\n
*  LQ_TI_UINT16_UQ8_TO_INT  TI方式UINT16的UQ8转化整形类型\n
*  LQ_TI_UINT16_UQ7_TO_INT  TI方式UINT16的UQ7转化整形类型\n
*  LQ_TI_UINT16_UQ6_TO_INT  TI方式UINT16的UQ6转化整形类型\n
*  LQ_TI_UINT16_UQ5_TO_INT  TI方式UINT16的UQ5转化整形类型\n
*  LQ_TI_UINT16_UQ4_TO_INT  TI方式UINT16的UQ4转化整形类型\n
*  LQ_TI_UINT16_UQ3_TO_INT  TI方式UINT16的UQ3转化整形类型\n
*  LQ_TI_UINT16_UQ2_TO_INT  TI方式UINT16的UQ2转化整形类型\n
*  LQ_TI_UINT16_UQ1_TO_INT  TI方式UINT16的UQ1转化整形类型\n
*/
LQ_INLINE LQ_UINT16_UQ13 LQ_TI_UINT16_UQ13_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error){
    return (LQ_UINT16_UQ13)(((LQ_I_32BIT)A + (((LQ_I_32BIT)A < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 13) - 1u) : 0)) >> 13);
}
/**@brief (TI方法)UINT16类型UQ12格式转整形
* @details 采用估算位+指数位+符号位三位结合
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    整形
* @par       将Q格式转化为整形
* @code*    LQ_TI_UINT16_UQ12_TO_INT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_UINT16_UQ16_TO_INT  TI方式UINT16的UQ16转化整形类型\n
*  LQ_TI_UINT16_UQ15_TO_INT  TI方式UINT16的UQ15转化整形类型\n
*  LQ_TI_UINT16_UQ14_TO_INT  TI方式UINT16的UQ14转化整形类型\n
*  LQ_TI_UINT16_UQ13_TO_INT  TI方式UINT16的UQ13转化整形类型\n
*  LQ_TI_UINT16_UQ12_TO_INT  TI方式UINT16的UQ12转化整形类型\n
*  LQ_TI_UINT16_UQ11_TO_INT  TI方式UINT16的UQ11转化整形类型\n
*  LQ_TI_UINT16_UQ10_TO_INT  TI方式UINT16的UQ10转化整形类型\n
*  LQ_TI_UINT16_UQ9_TO_INT  TI方式UINT16的UQ9转化整形类型\n
*  LQ_TI_UINT16_UQ8_TO_INT  TI方式UINT16的UQ8转化整形类型\n
*  LQ_TI_UINT16_UQ7_TO_INT  TI方式UINT16的UQ7转化整形类型\n
*  LQ_TI_UINT16_UQ6_TO_INT  TI方式UINT16的UQ6转化整形类型\n
*  LQ_TI_UINT16_UQ5_TO_INT  TI方式UINT16的UQ5转化整形类型\n
*  LQ_TI_UINT16_UQ4_TO_INT  TI方式UINT16的UQ4转化整形类型\n
*  LQ_TI_UINT16_UQ3_TO_INT  TI方式UINT16的UQ3转化整形类型\n
*  LQ_TI_UINT16_UQ2_TO_INT  TI方式UINT16的UQ2转化整形类型\n
*  LQ_TI_UINT16_UQ1_TO_INT  TI方式UINT16的UQ1转化整形类型\n
*/
LQ_INLINE LQ_UINT16_UQ12 LQ_TI_UINT16_UQ12_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error){
    return (LQ_UINT16_UQ12)(((LQ_I_32BIT)A + (((LQ_I_32BIT)A < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 12) - 1u) : 0)) >> 12);
}
/**@brief (TI方法)UINT16类型UQ11格式转整形
* @details 采用估算位+指数位+符号位三位结合
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    整形
* @par       将Q格式转化为整形
* @code*    LQ_TI_UINT16_UQ11_TO_INT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_UINT16_UQ16_TO_INT  TI方式UINT16的UQ16转化整形类型\n
*  LQ_TI_UINT16_UQ15_TO_INT  TI方式UINT16的UQ15转化整形类型\n
*  LQ_TI_UINT16_UQ14_TO_INT  TI方式UINT16的UQ14转化整形类型\n
*  LQ_TI_UINT16_UQ13_TO_INT  TI方式UINT16的UQ13转化整形类型\n
*  LQ_TI_UINT16_UQ12_TO_INT  TI方式UINT16的UQ12转化整形类型\n
*  LQ_TI_UINT16_UQ11_TO_INT  TI方式UINT16的UQ11转化整形类型\n
*  LQ_TI_UINT16_UQ10_TO_INT  TI方式UINT16的UQ10转化整形类型\n
*  LQ_TI_UINT16_UQ9_TO_INT  TI方式UINT16的UQ9转化整形类型\n
*  LQ_TI_UINT16_UQ8_TO_INT  TI方式UINT16的UQ8转化整形类型\n
*  LQ_TI_UINT16_UQ7_TO_INT  TI方式UINT16的UQ7转化整形类型\n
*  LQ_TI_UINT16_UQ6_TO_INT  TI方式UINT16的UQ6转化整形类型\n
*  LQ_TI_UINT16_UQ5_TO_INT  TI方式UINT16的UQ5转化整形类型\n
*  LQ_TI_UINT16_UQ4_TO_INT  TI方式UINT16的UQ4转化整形类型\n
*  LQ_TI_UINT16_UQ3_TO_INT  TI方式UINT16的UQ3转化整形类型\n
*  LQ_TI_UINT16_UQ2_TO_INT  TI方式UINT16的UQ2转化整形类型\n
*  LQ_TI_UINT16_UQ1_TO_INT  TI方式UINT16的UQ1转化整形类型\n
*/
LQ_INLINE LQ_UINT16_UQ11 LQ_TI_UINT16_UQ11_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error){
    return (LQ_UINT16_UQ11)(((LQ_I_32BIT)A + (((LQ_I_32BIT)A < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 11) - 1u) : 0)) >> 11);
}
/**@brief (TI方法)UINT16类型UQ10格式转整形
* @details 采用估算位+指数位+符号位三位结合
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    整形
* @par       将Q格式转化为整形
* @code*    LQ_TI_UINT16_UQ10_TO_INT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_UINT16_UQ16_TO_INT  TI方式UINT16的UQ16转化整形类型\n
*  LQ_TI_UINT16_UQ15_TO_INT  TI方式UINT16的UQ15转化整形类型\n
*  LQ_TI_UINT16_UQ14_TO_INT  TI方式UINT16的UQ14转化整形类型\n
*  LQ_TI_UINT16_UQ13_TO_INT  TI方式UINT16的UQ13转化整形类型\n
*  LQ_TI_UINT16_UQ12_TO_INT  TI方式UINT16的UQ12转化整形类型\n
*  LQ_TI_UINT16_UQ11_TO_INT  TI方式UINT16的UQ11转化整形类型\n
*  LQ_TI_UINT16_UQ10_TO_INT  TI方式UINT16的UQ10转化整形类型\n
*  LQ_TI_UINT16_UQ9_TO_INT  TI方式UINT16的UQ9转化整形类型\n
*  LQ_TI_UINT16_UQ8_TO_INT  TI方式UINT16的UQ8转化整形类型\n
*  LQ_TI_UINT16_UQ7_TO_INT  TI方式UINT16的UQ7转化整形类型\n
*  LQ_TI_UINT16_UQ6_TO_INT  TI方式UINT16的UQ6转化整形类型\n
*  LQ_TI_UINT16_UQ5_TO_INT  TI方式UINT16的UQ5转化整形类型\n
*  LQ_TI_UINT16_UQ4_TO_INT  TI方式UINT16的UQ4转化整形类型\n
*  LQ_TI_UINT16_UQ3_TO_INT  TI方式UINT16的UQ3转化整形类型\n
*  LQ_TI_UINT16_UQ2_TO_INT  TI方式UINT16的UQ2转化整形类型\n
*  LQ_TI_UINT16_UQ1_TO_INT  TI方式UINT16的UQ1转化整形类型\n
*/
LQ_INLINE LQ_UINT16_UQ10 LQ_TI_UINT16_UQ10_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error){
    return (LQ_UINT16_UQ10)(((LQ_I_32BIT)A + (((LQ_I_32BIT)A < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 10) - 1u) : 0)) >> 10);
}
/**@brief (TI方法)UINT16类型UQ9格式转整形
* @details 采用估算位+指数位+符号位三位结合
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    整形
* @par       将Q格式转化为整形
* @code*    LQ_TI_UINT16_UQ9_TO_INT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_UINT16_UQ16_TO_INT  TI方式UINT16的UQ16转化整形类型\n
*  LQ_TI_UINT16_UQ15_TO_INT  TI方式UINT16的UQ15转化整形类型\n
*  LQ_TI_UINT16_UQ14_TO_INT  TI方式UINT16的UQ14转化整形类型\n
*  LQ_TI_UINT16_UQ13_TO_INT  TI方式UINT16的UQ13转化整形类型\n
*  LQ_TI_UINT16_UQ12_TO_INT  TI方式UINT16的UQ12转化整形类型\n
*  LQ_TI_UINT16_UQ11_TO_INT  TI方式UINT16的UQ11转化整形类型\n
*  LQ_TI_UINT16_UQ10_TO_INT  TI方式UINT16的UQ10转化整形类型\n
*  LQ_TI_UINT16_UQ9_TO_INT  TI方式UINT16的UQ9转化整形类型\n
*  LQ_TI_UINT16_UQ8_TO_INT  TI方式UINT16的UQ8转化整形类型\n
*  LQ_TI_UINT16_UQ7_TO_INT  TI方式UINT16的UQ7转化整形类型\n
*  LQ_TI_UINT16_UQ6_TO_INT  TI方式UINT16的UQ6转化整形类型\n
*  LQ_TI_UINT16_UQ5_TO_INT  TI方式UINT16的UQ5转化整形类型\n
*  LQ_TI_UINT16_UQ4_TO_INT  TI方式UINT16的UQ4转化整形类型\n
*  LQ_TI_UINT16_UQ3_TO_INT  TI方式UINT16的UQ3转化整形类型\n
*  LQ_TI_UINT16_UQ2_TO_INT  TI方式UINT16的UQ2转化整形类型\n
*  LQ_TI_UINT16_UQ1_TO_INT  TI方式UINT16的UQ1转化整形类型\n
*/
LQ_INLINE LQ_UINT16_UQ9 LQ_TI_UINT16_UQ9_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error){
    return (LQ_UINT16_UQ9)(((LQ_I_32BIT)A + (((LQ_I_32BIT)A < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 9) - 1u) : 0)) >> 9);
}
/**@brief (TI方法)UINT16类型UQ8格式转整形
* @details 采用估算位+指数位+符号位三位结合
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    整形
* @par       将Q格式转化为整形
* @code*    LQ_TI_UINT16_UQ8_TO_INT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_UINT16_UQ16_TO_INT  TI方式UINT16的UQ16转化整形类型\n
*  LQ_TI_UINT16_UQ15_TO_INT  TI方式UINT16的UQ15转化整形类型\n
*  LQ_TI_UINT16_UQ14_TO_INT  TI方式UINT16的UQ14转化整形类型\n
*  LQ_TI_UINT16_UQ13_TO_INT  TI方式UINT16的UQ13转化整形类型\n
*  LQ_TI_UINT16_UQ12_TO_INT  TI方式UINT16的UQ12转化整形类型\n
*  LQ_TI_UINT16_UQ11_TO_INT  TI方式UINT16的UQ11转化整形类型\n
*  LQ_TI_UINT16_UQ10_TO_INT  TI方式UINT16的UQ10转化整形类型\n
*  LQ_TI_UINT16_UQ9_TO_INT  TI方式UINT16的UQ9转化整形类型\n
*  LQ_TI_UINT16_UQ8_TO_INT  TI方式UINT16的UQ8转化整形类型\n
*  LQ_TI_UINT16_UQ7_TO_INT  TI方式UINT16的UQ7转化整形类型\n
*  LQ_TI_UINT16_UQ6_TO_INT  TI方式UINT16的UQ6转化整形类型\n
*  LQ_TI_UINT16_UQ5_TO_INT  TI方式UINT16的UQ5转化整形类型\n
*  LQ_TI_UINT16_UQ4_TO_INT  TI方式UINT16的UQ4转化整形类型\n
*  LQ_TI_UINT16_UQ3_TO_INT  TI方式UINT16的UQ3转化整形类型\n
*  LQ_TI_UINT16_UQ2_TO_INT  TI方式UINT16的UQ2转化整形类型\n
*  LQ_TI_UINT16_UQ1_TO_INT  TI方式UINT16的UQ1转化整形类型\n
*/
LQ_INLINE LQ_UINT16_UQ8 LQ_TI_UINT16_UQ8_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error){
    return (LQ_UINT16_UQ8)(((LQ_I_32BIT)A + (((LQ_I_32BIT)A < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 8) - 1u) : 0)) >> 8);
}
/**@brief (TI方法)UINT16类型UQ7格式转整形
* @details 采用估算位+指数位+符号位三位结合
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    整形
* @par       将Q格式转化为整形
* @code*    LQ_TI_UINT16_UQ7_TO_INT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_UINT16_UQ16_TO_INT  TI方式UINT16的UQ16转化整形类型\n
*  LQ_TI_UINT16_UQ15_TO_INT  TI方式UINT16的UQ15转化整形类型\n
*  LQ_TI_UINT16_UQ14_TO_INT  TI方式UINT16的UQ14转化整形类型\n
*  LQ_TI_UINT16_UQ13_TO_INT  TI方式UINT16的UQ13转化整形类型\n
*  LQ_TI_UINT16_UQ12_TO_INT  TI方式UINT16的UQ12转化整形类型\n
*  LQ_TI_UINT16_UQ11_TO_INT  TI方式UINT16的UQ11转化整形类型\n
*  LQ_TI_UINT16_UQ10_TO_INT  TI方式UINT16的UQ10转化整形类型\n
*  LQ_TI_UINT16_UQ9_TO_INT  TI方式UINT16的UQ9转化整形类型\n
*  LQ_TI_UINT16_UQ8_TO_INT  TI方式UINT16的UQ8转化整形类型\n
*  LQ_TI_UINT16_UQ7_TO_INT  TI方式UINT16的UQ7转化整形类型\n
*  LQ_TI_UINT16_UQ6_TO_INT  TI方式UINT16的UQ6转化整形类型\n
*  LQ_TI_UINT16_UQ5_TO_INT  TI方式UINT16的UQ5转化整形类型\n
*  LQ_TI_UINT16_UQ4_TO_INT  TI方式UINT16的UQ4转化整形类型\n
*  LQ_TI_UINT16_UQ3_TO_INT  TI方式UINT16的UQ3转化整形类型\n
*  LQ_TI_UINT16_UQ2_TO_INT  TI方式UINT16的UQ2转化整形类型\n
*  LQ_TI_UINT16_UQ1_TO_INT  TI方式UINT16的UQ1转化整形类型\n
*/
LQ_INLINE LQ_UINT16_UQ7 LQ_TI_UINT16_UQ7_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error){
    return (LQ_UINT16_UQ7)(((LQ_I_32BIT)A + (((LQ_I_32BIT)A < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 7) - 1u) : 0)) >> 7);
}
/**@brief (TI方法)UINT16类型UQ6格式转整形
* @details 采用估算位+指数位+符号位三位结合
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    整形
* @par       将Q格式转化为整形
* @code*    LQ_TI_UINT16_UQ6_TO_INT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_UINT16_UQ16_TO_INT  TI方式UINT16的UQ16转化整形类型\n
*  LQ_TI_UINT16_UQ15_TO_INT  TI方式UINT16的UQ15转化整形类型\n
*  LQ_TI_UINT16_UQ14_TO_INT  TI方式UINT16的UQ14转化整形类型\n
*  LQ_TI_UINT16_UQ13_TO_INT  TI方式UINT16的UQ13转化整形类型\n
*  LQ_TI_UINT16_UQ12_TO_INT  TI方式UINT16的UQ12转化整形类型\n
*  LQ_TI_UINT16_UQ11_TO_INT  TI方式UINT16的UQ11转化整形类型\n
*  LQ_TI_UINT16_UQ10_TO_INT  TI方式UINT16的UQ10转化整形类型\n
*  LQ_TI_UINT16_UQ9_TO_INT  TI方式UINT16的UQ9转化整形类型\n
*  LQ_TI_UINT16_UQ8_TO_INT  TI方式UINT16的UQ8转化整形类型\n
*  LQ_TI_UINT16_UQ7_TO_INT  TI方式UINT16的UQ7转化整形类型\n
*  LQ_TI_UINT16_UQ6_TO_INT  TI方式UINT16的UQ6转化整形类型\n
*  LQ_TI_UINT16_UQ5_TO_INT  TI方式UINT16的UQ5转化整形类型\n
*  LQ_TI_UINT16_UQ4_TO_INT  TI方式UINT16的UQ4转化整形类型\n
*  LQ_TI_UINT16_UQ3_TO_INT  TI方式UINT16的UQ3转化整形类型\n
*  LQ_TI_UINT16_UQ2_TO_INT  TI方式UINT16的UQ2转化整形类型\n
*  LQ_TI_UINT16_UQ1_TO_INT  TI方式UINT16的UQ1转化整形类型\n
*/
LQ_INLINE LQ_UINT16_UQ6 LQ_TI_UINT16_UQ6_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error){
    return (LQ_UINT16_UQ6)(((LQ_I_32BIT)A + (((LQ_I_32BIT)A < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 6) - 1u) : 0)) >> 6);
}
/**@brief (TI方法)UINT16类型UQ5格式转整形
* @details 采用估算位+指数位+符号位三位结合
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    整形
* @par       将Q格式转化为整形
* @code*    LQ_TI_UINT16_UQ5_TO_INT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_UINT16_UQ16_TO_INT  TI方式UINT16的UQ16转化整形类型\n
*  LQ_TI_UINT16_UQ15_TO_INT  TI方式UINT16的UQ15转化整形类型\n
*  LQ_TI_UINT16_UQ14_TO_INT  TI方式UINT16的UQ14转化整形类型\n
*  LQ_TI_UINT16_UQ13_TO_INT  TI方式UINT16的UQ13转化整形类型\n
*  LQ_TI_UINT16_UQ12_TO_INT  TI方式UINT16的UQ12转化整形类型\n
*  LQ_TI_UINT16_UQ11_TO_INT  TI方式UINT16的UQ11转化整形类型\n
*  LQ_TI_UINT16_UQ10_TO_INT  TI方式UINT16的UQ10转化整形类型\n
*  LQ_TI_UINT16_UQ9_TO_INT  TI方式UINT16的UQ9转化整形类型\n
*  LQ_TI_UINT16_UQ8_TO_INT  TI方式UINT16的UQ8转化整形类型\n
*  LQ_TI_UINT16_UQ7_TO_INT  TI方式UINT16的UQ7转化整形类型\n
*  LQ_TI_UINT16_UQ6_TO_INT  TI方式UINT16的UQ6转化整形类型\n
*  LQ_TI_UINT16_UQ5_TO_INT  TI方式UINT16的UQ5转化整形类型\n
*  LQ_TI_UINT16_UQ4_TO_INT  TI方式UINT16的UQ4转化整形类型\n
*  LQ_TI_UINT16_UQ3_TO_INT  TI方式UINT16的UQ3转化整形类型\n
*  LQ_TI_UINT16_UQ2_TO_INT  TI方式UINT16的UQ2转化整形类型\n
*  LQ_TI_UINT16_UQ1_TO_INT  TI方式UINT16的UQ1转化整形类型\n
*/
LQ_INLINE LQ_UINT16_UQ5 LQ_TI_UINT16_UQ5_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error){
    return (LQ_UINT16_UQ5)(((LQ_I_32BIT)A + (((LQ_I_32BIT)A < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 5) - 1u) : 0)) >> 5);
}
/**@brief (TI方法)UINT16类型UQ4格式转整形
* @details 采用估算位+指数位+符号位三位结合
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    整形
* @par       将Q格式转化为整形
* @code*    LQ_TI_UINT16_UQ4_TO_INT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_UINT16_UQ16_TO_INT  TI方式UINT16的UQ16转化整形类型\n
*  LQ_TI_UINT16_UQ15_TO_INT  TI方式UINT16的UQ15转化整形类型\n
*  LQ_TI_UINT16_UQ14_TO_INT  TI方式UINT16的UQ14转化整形类型\n
*  LQ_TI_UINT16_UQ13_TO_INT  TI方式UINT16的UQ13转化整形类型\n
*  LQ_TI_UINT16_UQ12_TO_INT  TI方式UINT16的UQ12转化整形类型\n
*  LQ_TI_UINT16_UQ11_TO_INT  TI方式UINT16的UQ11转化整形类型\n
*  LQ_TI_UINT16_UQ10_TO_INT  TI方式UINT16的UQ10转化整形类型\n
*  LQ_TI_UINT16_UQ9_TO_INT  TI方式UINT16的UQ9转化整形类型\n
*  LQ_TI_UINT16_UQ8_TO_INT  TI方式UINT16的UQ8转化整形类型\n
*  LQ_TI_UINT16_UQ7_TO_INT  TI方式UINT16的UQ7转化整形类型\n
*  LQ_TI_UINT16_UQ6_TO_INT  TI方式UINT16的UQ6转化整形类型\n
*  LQ_TI_UINT16_UQ5_TO_INT  TI方式UINT16的UQ5转化整形类型\n
*  LQ_TI_UINT16_UQ4_TO_INT  TI方式UINT16的UQ4转化整形类型\n
*  LQ_TI_UINT16_UQ3_TO_INT  TI方式UINT16的UQ3转化整形类型\n
*  LQ_TI_UINT16_UQ2_TO_INT  TI方式UINT16的UQ2转化整形类型\n
*  LQ_TI_UINT16_UQ1_TO_INT  TI方式UINT16的UQ1转化整形类型\n
*/
LQ_INLINE LQ_UINT16_UQ4 LQ_TI_UINT16_UQ4_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error){
    return (LQ_UINT16_UQ4)(((LQ_I_32BIT)A + (((LQ_I_32BIT)A < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 4) - 1u) : 0)) >> 4);
}
/**@brief (TI方法)UINT16类型UQ3格式转整形
* @details 采用估算位+指数位+符号位三位结合
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    整形
* @par       将Q格式转化为整形
* @code*    LQ_TI_UINT16_UQ3_TO_INT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_UINT16_UQ16_TO_INT  TI方式UINT16的UQ16转化整形类型\n
*  LQ_TI_UINT16_UQ15_TO_INT  TI方式UINT16的UQ15转化整形类型\n
*  LQ_TI_UINT16_UQ14_TO_INT  TI方式UINT16的UQ14转化整形类型\n
*  LQ_TI_UINT16_UQ13_TO_INT  TI方式UINT16的UQ13转化整形类型\n
*  LQ_TI_UINT16_UQ12_TO_INT  TI方式UINT16的UQ12转化整形类型\n
*  LQ_TI_UINT16_UQ11_TO_INT  TI方式UINT16的UQ11转化整形类型\n
*  LQ_TI_UINT16_UQ10_TO_INT  TI方式UINT16的UQ10转化整形类型\n
*  LQ_TI_UINT16_UQ9_TO_INT  TI方式UINT16的UQ9转化整形类型\n
*  LQ_TI_UINT16_UQ8_TO_INT  TI方式UINT16的UQ8转化整形类型\n
*  LQ_TI_UINT16_UQ7_TO_INT  TI方式UINT16的UQ7转化整形类型\n
*  LQ_TI_UINT16_UQ6_TO_INT  TI方式UINT16的UQ6转化整形类型\n
*  LQ_TI_UINT16_UQ5_TO_INT  TI方式UINT16的UQ5转化整形类型\n
*  LQ_TI_UINT16_UQ4_TO_INT  TI方式UINT16的UQ4转化整形类型\n
*  LQ_TI_UINT16_UQ3_TO_INT  TI方式UINT16的UQ3转化整形类型\n
*  LQ_TI_UINT16_UQ2_TO_INT  TI方式UINT16的UQ2转化整形类型\n
*  LQ_TI_UINT16_UQ1_TO_INT  TI方式UINT16的UQ1转化整形类型\n
*/
LQ_INLINE LQ_UINT16_UQ3 LQ_TI_UINT16_UQ3_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error){
    return (LQ_UINT16_UQ3)(((LQ_I_32BIT)A + (((LQ_I_32BIT)A < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 3) - 1u) : 0)) >> 3);
}
/**@brief (TI方法)UINT16类型UQ2格式转整形
* @details 采用估算位+指数位+符号位三位结合
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    整形
* @par       将Q格式转化为整形
* @code*    LQ_TI_UINT16_UQ2_TO_INT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_UINT16_UQ16_TO_INT  TI方式UINT16的UQ16转化整形类型\n
*  LQ_TI_UINT16_UQ15_TO_INT  TI方式UINT16的UQ15转化整形类型\n
*  LQ_TI_UINT16_UQ14_TO_INT  TI方式UINT16的UQ14转化整形类型\n
*  LQ_TI_UINT16_UQ13_TO_INT  TI方式UINT16的UQ13转化整形类型\n
*  LQ_TI_UINT16_UQ12_TO_INT  TI方式UINT16的UQ12转化整形类型\n
*  LQ_TI_UINT16_UQ11_TO_INT  TI方式UINT16的UQ11转化整形类型\n
*  LQ_TI_UINT16_UQ10_TO_INT  TI方式UINT16的UQ10转化整形类型\n
*  LQ_TI_UINT16_UQ9_TO_INT  TI方式UINT16的UQ9转化整形类型\n
*  LQ_TI_UINT16_UQ8_TO_INT  TI方式UINT16的UQ8转化整形类型\n
*  LQ_TI_UINT16_UQ7_TO_INT  TI方式UINT16的UQ7转化整形类型\n
*  LQ_TI_UINT16_UQ6_TO_INT  TI方式UINT16的UQ6转化整形类型\n
*  LQ_TI_UINT16_UQ5_TO_INT  TI方式UINT16的UQ5转化整形类型\n
*  LQ_TI_UINT16_UQ4_TO_INT  TI方式UINT16的UQ4转化整形类型\n
*  LQ_TI_UINT16_UQ3_TO_INT  TI方式UINT16的UQ3转化整形类型\n
*  LQ_TI_UINT16_UQ2_TO_INT  TI方式UINT16的UQ2转化整形类型\n
*  LQ_TI_UINT16_UQ1_TO_INT  TI方式UINT16的UQ1转化整形类型\n
*/
LQ_INLINE LQ_UINT16_UQ2 LQ_TI_UINT16_UQ2_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error){
    return (LQ_UINT16_UQ2)(((LQ_I_32BIT)A + (((LQ_I_32BIT)A < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 2) - 1u) : 0)) >> 2);
}
/**@brief (TI方法)UINT16类型UQ1格式转整形
* @details 采用估算位+指数位+符号位三位结合
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    整形
* @par       将Q格式转化为整形
* @code*    LQ_TI_UINT16_UQ1_TO_INT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_UINT16_UQ16_TO_INT  TI方式UINT16的UQ16转化整形类型\n
*  LQ_TI_UINT16_UQ15_TO_INT  TI方式UINT16的UQ15转化整形类型\n
*  LQ_TI_UINT16_UQ14_TO_INT  TI方式UINT16的UQ14转化整形类型\n
*  LQ_TI_UINT16_UQ13_TO_INT  TI方式UINT16的UQ13转化整形类型\n
*  LQ_TI_UINT16_UQ12_TO_INT  TI方式UINT16的UQ12转化整形类型\n
*  LQ_TI_UINT16_UQ11_TO_INT  TI方式UINT16的UQ11转化整形类型\n
*  LQ_TI_UINT16_UQ10_TO_INT  TI方式UINT16的UQ10转化整形类型\n
*  LQ_TI_UINT16_UQ9_TO_INT  TI方式UINT16的UQ9转化整形类型\n
*  LQ_TI_UINT16_UQ8_TO_INT  TI方式UINT16的UQ8转化整形类型\n
*  LQ_TI_UINT16_UQ7_TO_INT  TI方式UINT16的UQ7转化整形类型\n
*  LQ_TI_UINT16_UQ6_TO_INT  TI方式UINT16的UQ6转化整形类型\n
*  LQ_TI_UINT16_UQ5_TO_INT  TI方式UINT16的UQ5转化整形类型\n
*  LQ_TI_UINT16_UQ4_TO_INT  TI方式UINT16的UQ4转化整形类型\n
*  LQ_TI_UINT16_UQ3_TO_INT  TI方式UINT16的UQ3转化整形类型\n
*  LQ_TI_UINT16_UQ2_TO_INT  TI方式UINT16的UQ2转化整形类型\n
*  LQ_TI_UINT16_UQ1_TO_INT  TI方式UINT16的UQ1转化整形类型\n
*/
LQ_INLINE LQ_UINT16_UQ1 LQ_TI_UINT16_UQ1_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error){
    return (LQ_UINT16_UQ1)(((LQ_I_32BIT)A + (((LQ_I_32BIT)A < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 1) - 1u) : 0)) >> 1);
}
/**@brief (TI方法)INT32类型Q31格式转整形
* @details 采用估算位+指数位+符号位三位结合
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为整形数
* @code*    LQ_TI_INT32_Q31_TO_INT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_INT32_Q31_TO_INT  TI方式INT32的Q31转化整形类型\n
*    LQ_TI_INT32_Q30_TO_INT  TI方式INT32的Q30转化整形类型\n
*    LQ_TI_INT32_Q29_TO_INT  TI方式INT32的Q29转化整形类型\n
*    LQ_TI_INT32_Q28_TO_INT  TI方式INT32的Q28转化整形类型\n
*    LQ_TI_INT32_Q27_TO_INT  TI方式INT32的Q27转化整形类型\n
*    LQ_TI_INT32_Q26_TO_INT  TI方式INT32的Q26转化整形类型\n
*    LQ_TI_INT32_Q25_TO_INT  TI方式INT32的Q25转化整形类型\n
*    LQ_TI_INT32_Q24_TO_INT  TI方式INT32的Q24转化整形类型\n
*    LQ_TI_INT32_Q23_TO_INT  TI方式INT32的Q23转化整形类型\n
*    LQ_TI_INT32_Q22_TO_INT  TI方式INT32的Q22转化整形类型\n
*    LQ_TI_INT32_Q21_TO_INT  TI方式INT32的Q21转化整形类型\n
*    LQ_TI_INT32_Q20_TO_INT  TI方式INT32的Q20转化整形类型\n
*    LQ_TI_INT32_Q19_TO_INT  TI方式INT32的Q19转化整形类型\n
*    LQ_TI_INT32_Q18_TO_INT  TI方式INT32的Q18转化整形类型\n
*    LQ_TI_INT32_Q17_TO_INT  TI方式INT32的Q17转化整形类型\n
*    LQ_TI_INT32_Q16_TO_INT  TI方式INT32的Q16转化整形类型\n
*    LQ_TI_INT32_Q15_TO_INT  TI方式INT32的Q15转化整形类型\n
*    LQ_TI_INT32_Q14_TO_INT  TI方式INT32的Q14转化整形类型\n
*    LQ_TI_INT32_Q13_TO_INT  TI方式INT32的Q13转化整形类型\n
*    LQ_TI_INT32_Q12_TO_INT  TI方式INT32的Q12转化整形类型\n
*    LQ_TI_INT32_Q11_TO_INT  TI方式INT32的Q11转化整形类型\n
*    LQ_TI_INT32_Q10_TO_INT  TI方式INT32的Q10转化整形类型\n
*    LQ_TI_INT32_Q9_TO_INT  TI方式INT32的Q9转化整形类型\n
*    LQ_TI_INT32_Q8_TO_INT  TI方式INT32的Q8转化整形类型\n
*    LQ_TI_INT32_Q7_TO_INT  TI方式INT32的Q7转化整形类型\n
*    LQ_TI_INT32_Q6_TO_INT  TI方式INT32的Q6转化整形类型\n
*    LQ_TI_INT32_Q5_TO_INT  TI方式INT32的Q5转化整形类型\n
*    LQ_TI_INT32_Q4_TO_INT  TI方式INT32的Q4转化整形类型\n
*    LQ_TI_INT32_Q3_TO_INT  TI方式INT32的Q3转化整形类型\n
*    LQ_TI_INT32_Q2_TO_INT  TI方式INT32的Q2转化整形类型\n
*    LQ_TI_INT32_Q1_TO_INT  TI方式INT32的Q1转化整形类型\n
*/
LQ_INLINE LQ_INT32_Q31 LQ_TI_INT32_Q31_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error){
    return (LQ_INT32_Q31)(((LQ_I_32BIT)A + (((LQ_I_32BIT)A < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 31) - 1u) : 0)) >> 31);
}
/**@brief (TI方法)INT32类型Q30格式转整形
* @details 采用估算位+指数位+符号位三位结合
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为整形数
* @code*    LQ_TI_INT32_Q30_TO_INT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_INT32_Q31_TO_INT  TI方式INT32的Q31转化整形类型\n
*    LQ_TI_INT32_Q30_TO_INT  TI方式INT32的Q30转化整形类型\n
*    LQ_TI_INT32_Q29_TO_INT  TI方式INT32的Q29转化整形类型\n
*    LQ_TI_INT32_Q28_TO_INT  TI方式INT32的Q28转化整形类型\n
*    LQ_TI_INT32_Q27_TO_INT  TI方式INT32的Q27转化整形类型\n
*    LQ_TI_INT32_Q26_TO_INT  TI方式INT32的Q26转化整形类型\n
*    LQ_TI_INT32_Q25_TO_INT  TI方式INT32的Q25转化整形类型\n
*    LQ_TI_INT32_Q24_TO_INT  TI方式INT32的Q24转化整形类型\n
*    LQ_TI_INT32_Q23_TO_INT  TI方式INT32的Q23转化整形类型\n
*    LQ_TI_INT32_Q22_TO_INT  TI方式INT32的Q22转化整形类型\n
*    LQ_TI_INT32_Q21_TO_INT  TI方式INT32的Q21转化整形类型\n
*    LQ_TI_INT32_Q20_TO_INT  TI方式INT32的Q20转化整形类型\n
*    LQ_TI_INT32_Q19_TO_INT  TI方式INT32的Q19转化整形类型\n
*    LQ_TI_INT32_Q18_TO_INT  TI方式INT32的Q18转化整形类型\n
*    LQ_TI_INT32_Q17_TO_INT  TI方式INT32的Q17转化整形类型\n
*    LQ_TI_INT32_Q16_TO_INT  TI方式INT32的Q16转化整形类型\n
*    LQ_TI_INT32_Q15_TO_INT  TI方式INT32的Q15转化整形类型\n
*    LQ_TI_INT32_Q14_TO_INT  TI方式INT32的Q14转化整形类型\n
*    LQ_TI_INT32_Q13_TO_INT  TI方式INT32的Q13转化整形类型\n
*    LQ_TI_INT32_Q12_TO_INT  TI方式INT32的Q12转化整形类型\n
*    LQ_TI_INT32_Q11_TO_INT  TI方式INT32的Q11转化整形类型\n
*    LQ_TI_INT32_Q10_TO_INT  TI方式INT32的Q10转化整形类型\n
*    LQ_TI_INT32_Q9_TO_INT  TI方式INT32的Q9转化整形类型\n
*    LQ_TI_INT32_Q8_TO_INT  TI方式INT32的Q8转化整形类型\n
*    LQ_TI_INT32_Q7_TO_INT  TI方式INT32的Q7转化整形类型\n
*    LQ_TI_INT32_Q6_TO_INT  TI方式INT32的Q6转化整形类型\n
*    LQ_TI_INT32_Q5_TO_INT  TI方式INT32的Q5转化整形类型\n
*    LQ_TI_INT32_Q4_TO_INT  TI方式INT32的Q4转化整形类型\n
*    LQ_TI_INT32_Q3_TO_INT  TI方式INT32的Q3转化整形类型\n
*    LQ_TI_INT32_Q2_TO_INT  TI方式INT32的Q2转化整形类型\n
*    LQ_TI_INT32_Q1_TO_INT  TI方式INT32的Q1转化整形类型\n
*/
LQ_INLINE LQ_INT32_Q30 LQ_TI_INT32_Q30_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error){
    return (LQ_INT32_Q30)(((LQ_I_32BIT)A + (((LQ_I_32BIT)A < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 30) - 1u) : 0)) >> 30);
}
/**@brief (TI方法)INT32类型Q29格式转整形
* @details 采用估算位+指数位+符号位三位结合
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为整形数
* @code*    LQ_TI_INT32_Q29_TO_INT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_INT32_Q31_TO_INT  TI方式INT32的Q31转化整形类型\n
*    LQ_TI_INT32_Q30_TO_INT  TI方式INT32的Q30转化整形类型\n
*    LQ_TI_INT32_Q29_TO_INT  TI方式INT32的Q29转化整形类型\n
*    LQ_TI_INT32_Q28_TO_INT  TI方式INT32的Q28转化整形类型\n
*    LQ_TI_INT32_Q27_TO_INT  TI方式INT32的Q27转化整形类型\n
*    LQ_TI_INT32_Q26_TO_INT  TI方式INT32的Q26转化整形类型\n
*    LQ_TI_INT32_Q25_TO_INT  TI方式INT32的Q25转化整形类型\n
*    LQ_TI_INT32_Q24_TO_INT  TI方式INT32的Q24转化整形类型\n
*    LQ_TI_INT32_Q23_TO_INT  TI方式INT32的Q23转化整形类型\n
*    LQ_TI_INT32_Q22_TO_INT  TI方式INT32的Q22转化整形类型\n
*    LQ_TI_INT32_Q21_TO_INT  TI方式INT32的Q21转化整形类型\n
*    LQ_TI_INT32_Q20_TO_INT  TI方式INT32的Q20转化整形类型\n
*    LQ_TI_INT32_Q19_TO_INT  TI方式INT32的Q19转化整形类型\n
*    LQ_TI_INT32_Q18_TO_INT  TI方式INT32的Q18转化整形类型\n
*    LQ_TI_INT32_Q17_TO_INT  TI方式INT32的Q17转化整形类型\n
*    LQ_TI_INT32_Q16_TO_INT  TI方式INT32的Q16转化整形类型\n
*    LQ_TI_INT32_Q15_TO_INT  TI方式INT32的Q15转化整形类型\n
*    LQ_TI_INT32_Q14_TO_INT  TI方式INT32的Q14转化整形类型\n
*    LQ_TI_INT32_Q13_TO_INT  TI方式INT32的Q13转化整形类型\n
*    LQ_TI_INT32_Q12_TO_INT  TI方式INT32的Q12转化整形类型\n
*    LQ_TI_INT32_Q11_TO_INT  TI方式INT32的Q11转化整形类型\n
*    LQ_TI_INT32_Q10_TO_INT  TI方式INT32的Q10转化整形类型\n
*    LQ_TI_INT32_Q9_TO_INT  TI方式INT32的Q9转化整形类型\n
*    LQ_TI_INT32_Q8_TO_INT  TI方式INT32的Q8转化整形类型\n
*    LQ_TI_INT32_Q7_TO_INT  TI方式INT32的Q7转化整形类型\n
*    LQ_TI_INT32_Q6_TO_INT  TI方式INT32的Q6转化整形类型\n
*    LQ_TI_INT32_Q5_TO_INT  TI方式INT32的Q5转化整形类型\n
*    LQ_TI_INT32_Q4_TO_INT  TI方式INT32的Q4转化整形类型\n
*    LQ_TI_INT32_Q3_TO_INT  TI方式INT32的Q3转化整形类型\n
*    LQ_TI_INT32_Q2_TO_INT  TI方式INT32的Q2转化整形类型\n
*    LQ_TI_INT32_Q1_TO_INT  TI方式INT32的Q1转化整形类型\n
*/
LQ_INLINE LQ_INT32_Q29 LQ_TI_INT32_Q29_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error){
    return (LQ_INT32_Q29)(((LQ_I_32BIT)A + (((LQ_I_32BIT)A < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 29) - 1u) : 0)) >> 29);
}
/**@brief (TI方法)INT32类型Q28格式转整形
* @details 采用估算位+指数位+符号位三位结合
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为整形数
* @code*    LQ_TI_INT32_Q28_TO_INT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_INT32_Q31_TO_INT  TI方式INT32的Q31转化整形类型\n
*    LQ_TI_INT32_Q30_TO_INT  TI方式INT32的Q30转化整形类型\n
*    LQ_TI_INT32_Q29_TO_INT  TI方式INT32的Q29转化整形类型\n
*    LQ_TI_INT32_Q28_TO_INT  TI方式INT32的Q28转化整形类型\n
*    LQ_TI_INT32_Q27_TO_INT  TI方式INT32的Q27转化整形类型\n
*    LQ_TI_INT32_Q26_TO_INT  TI方式INT32的Q26转化整形类型\n
*    LQ_TI_INT32_Q25_TO_INT  TI方式INT32的Q25转化整形类型\n
*    LQ_TI_INT32_Q24_TO_INT  TI方式INT32的Q24转化整形类型\n
*    LQ_TI_INT32_Q23_TO_INT  TI方式INT32的Q23转化整形类型\n
*    LQ_TI_INT32_Q22_TO_INT  TI方式INT32的Q22转化整形类型\n
*    LQ_TI_INT32_Q21_TO_INT  TI方式INT32的Q21转化整形类型\n
*    LQ_TI_INT32_Q20_TO_INT  TI方式INT32的Q20转化整形类型\n
*    LQ_TI_INT32_Q19_TO_INT  TI方式INT32的Q19转化整形类型\n
*    LQ_TI_INT32_Q18_TO_INT  TI方式INT32的Q18转化整形类型\n
*    LQ_TI_INT32_Q17_TO_INT  TI方式INT32的Q17转化整形类型\n
*    LQ_TI_INT32_Q16_TO_INT  TI方式INT32的Q16转化整形类型\n
*    LQ_TI_INT32_Q15_TO_INT  TI方式INT32的Q15转化整形类型\n
*    LQ_TI_INT32_Q14_TO_INT  TI方式INT32的Q14转化整形类型\n
*    LQ_TI_INT32_Q13_TO_INT  TI方式INT32的Q13转化整形类型\n
*    LQ_TI_INT32_Q12_TO_INT  TI方式INT32的Q12转化整形类型\n
*    LQ_TI_INT32_Q11_TO_INT  TI方式INT32的Q11转化整形类型\n
*    LQ_TI_INT32_Q10_TO_INT  TI方式INT32的Q10转化整形类型\n
*    LQ_TI_INT32_Q9_TO_INT  TI方式INT32的Q9转化整形类型\n
*    LQ_TI_INT32_Q8_TO_INT  TI方式INT32的Q8转化整形类型\n
*    LQ_TI_INT32_Q7_TO_INT  TI方式INT32的Q7转化整形类型\n
*    LQ_TI_INT32_Q6_TO_INT  TI方式INT32的Q6转化整形类型\n
*    LQ_TI_INT32_Q5_TO_INT  TI方式INT32的Q5转化整形类型\n
*    LQ_TI_INT32_Q4_TO_INT  TI方式INT32的Q4转化整形类型\n
*    LQ_TI_INT32_Q3_TO_INT  TI方式INT32的Q3转化整形类型\n
*    LQ_TI_INT32_Q2_TO_INT  TI方式INT32的Q2转化整形类型\n
*    LQ_TI_INT32_Q1_TO_INT  TI方式INT32的Q1转化整形类型\n
*/
LQ_INLINE LQ_INT32_Q28 LQ_TI_INT32_Q28_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error){
    return (LQ_INT32_Q28)(((LQ_I_32BIT)A + (((LQ_I_32BIT)A < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 28) - 1u) : 0)) >> 28);
}
/**@brief (TI方法)INT32类型Q27格式转整形
* @details 采用估算位+指数位+符号位三位结合
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为整形数
* @code*    LQ_TI_INT32_Q27_TO_INT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_INT32_Q31_TO_INT  TI方式INT32的Q31转化整形类型\n
*    LQ_TI_INT32_Q30_TO_INT  TI方式INT32的Q30转化整形类型\n
*    LQ_TI_INT32_Q29_TO_INT  TI方式INT32的Q29转化整形类型\n
*    LQ_TI_INT32_Q28_TO_INT  TI方式INT32的Q28转化整形类型\n
*    LQ_TI_INT32_Q27_TO_INT  TI方式INT32的Q27转化整形类型\n
*    LQ_TI_INT32_Q26_TO_INT  TI方式INT32的Q26转化整形类型\n
*    LQ_TI_INT32_Q25_TO_INT  TI方式INT32的Q25转化整形类型\n
*    LQ_TI_INT32_Q24_TO_INT  TI方式INT32的Q24转化整形类型\n
*    LQ_TI_INT32_Q23_TO_INT  TI方式INT32的Q23转化整形类型\n
*    LQ_TI_INT32_Q22_TO_INT  TI方式INT32的Q22转化整形类型\n
*    LQ_TI_INT32_Q21_TO_INT  TI方式INT32的Q21转化整形类型\n
*    LQ_TI_INT32_Q20_TO_INT  TI方式INT32的Q20转化整形类型\n
*    LQ_TI_INT32_Q19_TO_INT  TI方式INT32的Q19转化整形类型\n
*    LQ_TI_INT32_Q18_TO_INT  TI方式INT32的Q18转化整形类型\n
*    LQ_TI_INT32_Q17_TO_INT  TI方式INT32的Q17转化整形类型\n
*    LQ_TI_INT32_Q16_TO_INT  TI方式INT32的Q16转化整形类型\n
*    LQ_TI_INT32_Q15_TO_INT  TI方式INT32的Q15转化整形类型\n
*    LQ_TI_INT32_Q14_TO_INT  TI方式INT32的Q14转化整形类型\n
*    LQ_TI_INT32_Q13_TO_INT  TI方式INT32的Q13转化整形类型\n
*    LQ_TI_INT32_Q12_TO_INT  TI方式INT32的Q12转化整形类型\n
*    LQ_TI_INT32_Q11_TO_INT  TI方式INT32的Q11转化整形类型\n
*    LQ_TI_INT32_Q10_TO_INT  TI方式INT32的Q10转化整形类型\n
*    LQ_TI_INT32_Q9_TO_INT  TI方式INT32的Q9转化整形类型\n
*    LQ_TI_INT32_Q8_TO_INT  TI方式INT32的Q8转化整形类型\n
*    LQ_TI_INT32_Q7_TO_INT  TI方式INT32的Q7转化整形类型\n
*    LQ_TI_INT32_Q6_TO_INT  TI方式INT32的Q6转化整形类型\n
*    LQ_TI_INT32_Q5_TO_INT  TI方式INT32的Q5转化整形类型\n
*    LQ_TI_INT32_Q4_TO_INT  TI方式INT32的Q4转化整形类型\n
*    LQ_TI_INT32_Q3_TO_INT  TI方式INT32的Q3转化整形类型\n
*    LQ_TI_INT32_Q2_TO_INT  TI方式INT32的Q2转化整形类型\n
*    LQ_TI_INT32_Q1_TO_INT  TI方式INT32的Q1转化整形类型\n
*/
LQ_INLINE LQ_INT32_Q27 LQ_TI_INT32_Q27_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error){
    return (LQ_INT32_Q27)(((LQ_I_32BIT)A + (((LQ_I_32BIT)A < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 27) - 1u) : 0)) >> 27);
}
/**@brief (TI方法)INT32类型Q26格式转整形
* @details 采用估算位+指数位+符号位三位结合
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为整形数
* @code*    LQ_TI_INT32_Q26_TO_INT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_INT32_Q31_TO_INT  TI方式INT32的Q31转化整形类型\n
*    LQ_TI_INT32_Q30_TO_INT  TI方式INT32的Q30转化整形类型\n
*    LQ_TI_INT32_Q29_TO_INT  TI方式INT32的Q29转化整形类型\n
*    LQ_TI_INT32_Q28_TO_INT  TI方式INT32的Q28转化整形类型\n
*    LQ_TI_INT32_Q27_TO_INT  TI方式INT32的Q27转化整形类型\n
*    LQ_TI_INT32_Q26_TO_INT  TI方式INT32的Q26转化整形类型\n
*    LQ_TI_INT32_Q25_TO_INT  TI方式INT32的Q25转化整形类型\n
*    LQ_TI_INT32_Q24_TO_INT  TI方式INT32的Q24转化整形类型\n
*    LQ_TI_INT32_Q23_TO_INT  TI方式INT32的Q23转化整形类型\n
*    LQ_TI_INT32_Q22_TO_INT  TI方式INT32的Q22转化整形类型\n
*    LQ_TI_INT32_Q21_TO_INT  TI方式INT32的Q21转化整形类型\n
*    LQ_TI_INT32_Q20_TO_INT  TI方式INT32的Q20转化整形类型\n
*    LQ_TI_INT32_Q19_TO_INT  TI方式INT32的Q19转化整形类型\n
*    LQ_TI_INT32_Q18_TO_INT  TI方式INT32的Q18转化整形类型\n
*    LQ_TI_INT32_Q17_TO_INT  TI方式INT32的Q17转化整形类型\n
*    LQ_TI_INT32_Q16_TO_INT  TI方式INT32的Q16转化整形类型\n
*    LQ_TI_INT32_Q15_TO_INT  TI方式INT32的Q15转化整形类型\n
*    LQ_TI_INT32_Q14_TO_INT  TI方式INT32的Q14转化整形类型\n
*    LQ_TI_INT32_Q13_TO_INT  TI方式INT32的Q13转化整形类型\n
*    LQ_TI_INT32_Q12_TO_INT  TI方式INT32的Q12转化整形类型\n
*    LQ_TI_INT32_Q11_TO_INT  TI方式INT32的Q11转化整形类型\n
*    LQ_TI_INT32_Q10_TO_INT  TI方式INT32的Q10转化整形类型\n
*    LQ_TI_INT32_Q9_TO_INT  TI方式INT32的Q9转化整形类型\n
*    LQ_TI_INT32_Q8_TO_INT  TI方式INT32的Q8转化整形类型\n
*    LQ_TI_INT32_Q7_TO_INT  TI方式INT32的Q7转化整形类型\n
*    LQ_TI_INT32_Q6_TO_INT  TI方式INT32的Q6转化整形类型\n
*    LQ_TI_INT32_Q5_TO_INT  TI方式INT32的Q5转化整形类型\n
*    LQ_TI_INT32_Q4_TO_INT  TI方式INT32的Q4转化整形类型\n
*    LQ_TI_INT32_Q3_TO_INT  TI方式INT32的Q3转化整形类型\n
*    LQ_TI_INT32_Q2_TO_INT  TI方式INT32的Q2转化整形类型\n
*    LQ_TI_INT32_Q1_TO_INT  TI方式INT32的Q1转化整形类型\n
*/
LQ_INLINE LQ_INT32_Q26 LQ_TI_INT32_Q26_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error){
    return (LQ_INT32_Q26)(((LQ_I_32BIT)A + (((LQ_I_32BIT)A < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 26) - 1u) : 0)) >> 26);
}
/**@brief (TI方法)INT32类型Q25格式转整形
* @details 采用估算位+指数位+符号位三位结合
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为整形数
* @code*    LQ_TI_INT32_Q25_TO_INT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_INT32_Q31_TO_INT  TI方式INT32的Q31转化整形类型\n
*    LQ_TI_INT32_Q30_TO_INT  TI方式INT32的Q30转化整形类型\n
*    LQ_TI_INT32_Q29_TO_INT  TI方式INT32的Q29转化整形类型\n
*    LQ_TI_INT32_Q28_TO_INT  TI方式INT32的Q28转化整形类型\n
*    LQ_TI_INT32_Q27_TO_INT  TI方式INT32的Q27转化整形类型\n
*    LQ_TI_INT32_Q26_TO_INT  TI方式INT32的Q26转化整形类型\n
*    LQ_TI_INT32_Q25_TO_INT  TI方式INT32的Q25转化整形类型\n
*    LQ_TI_INT32_Q24_TO_INT  TI方式INT32的Q24转化整形类型\n
*    LQ_TI_INT32_Q23_TO_INT  TI方式INT32的Q23转化整形类型\n
*    LQ_TI_INT32_Q22_TO_INT  TI方式INT32的Q22转化整形类型\n
*    LQ_TI_INT32_Q21_TO_INT  TI方式INT32的Q21转化整形类型\n
*    LQ_TI_INT32_Q20_TO_INT  TI方式INT32的Q20转化整形类型\n
*    LQ_TI_INT32_Q19_TO_INT  TI方式INT32的Q19转化整形类型\n
*    LQ_TI_INT32_Q18_TO_INT  TI方式INT32的Q18转化整形类型\n
*    LQ_TI_INT32_Q17_TO_INT  TI方式INT32的Q17转化整形类型\n
*    LQ_TI_INT32_Q16_TO_INT  TI方式INT32的Q16转化整形类型\n
*    LQ_TI_INT32_Q15_TO_INT  TI方式INT32的Q15转化整形类型\n
*    LQ_TI_INT32_Q14_TO_INT  TI方式INT32的Q14转化整形类型\n
*    LQ_TI_INT32_Q13_TO_INT  TI方式INT32的Q13转化整形类型\n
*    LQ_TI_INT32_Q12_TO_INT  TI方式INT32的Q12转化整形类型\n
*    LQ_TI_INT32_Q11_TO_INT  TI方式INT32的Q11转化整形类型\n
*    LQ_TI_INT32_Q10_TO_INT  TI方式INT32的Q10转化整形类型\n
*    LQ_TI_INT32_Q9_TO_INT  TI方式INT32的Q9转化整形类型\n
*    LQ_TI_INT32_Q8_TO_INT  TI方式INT32的Q8转化整形类型\n
*    LQ_TI_INT32_Q7_TO_INT  TI方式INT32的Q7转化整形类型\n
*    LQ_TI_INT32_Q6_TO_INT  TI方式INT32的Q6转化整形类型\n
*    LQ_TI_INT32_Q5_TO_INT  TI方式INT32的Q5转化整形类型\n
*    LQ_TI_INT32_Q4_TO_INT  TI方式INT32的Q4转化整形类型\n
*    LQ_TI_INT32_Q3_TO_INT  TI方式INT32的Q3转化整形类型\n
*    LQ_TI_INT32_Q2_TO_INT  TI方式INT32的Q2转化整形类型\n
*    LQ_TI_INT32_Q1_TO_INT  TI方式INT32的Q1转化整形类型\n
*/
LQ_INLINE LQ_INT32_Q25 LQ_TI_INT32_Q25_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error){
    return (LQ_INT32_Q25)(((LQ_I_32BIT)A + (((LQ_I_32BIT)A < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 25) - 1u) : 0)) >> 25);
}
/**@brief (TI方法)INT32类型Q24格式转整形
* @details 采用估算位+指数位+符号位三位结合
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为整形数
* @code*    LQ_TI_INT32_Q24_TO_INT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_INT32_Q31_TO_INT  TI方式INT32的Q31转化整形类型\n
*    LQ_TI_INT32_Q30_TO_INT  TI方式INT32的Q30转化整形类型\n
*    LQ_TI_INT32_Q29_TO_INT  TI方式INT32的Q29转化整形类型\n
*    LQ_TI_INT32_Q28_TO_INT  TI方式INT32的Q28转化整形类型\n
*    LQ_TI_INT32_Q27_TO_INT  TI方式INT32的Q27转化整形类型\n
*    LQ_TI_INT32_Q26_TO_INT  TI方式INT32的Q26转化整形类型\n
*    LQ_TI_INT32_Q25_TO_INT  TI方式INT32的Q25转化整形类型\n
*    LQ_TI_INT32_Q24_TO_INT  TI方式INT32的Q24转化整形类型\n
*    LQ_TI_INT32_Q23_TO_INT  TI方式INT32的Q23转化整形类型\n
*    LQ_TI_INT32_Q22_TO_INT  TI方式INT32的Q22转化整形类型\n
*    LQ_TI_INT32_Q21_TO_INT  TI方式INT32的Q21转化整形类型\n
*    LQ_TI_INT32_Q20_TO_INT  TI方式INT32的Q20转化整形类型\n
*    LQ_TI_INT32_Q19_TO_INT  TI方式INT32的Q19转化整形类型\n
*    LQ_TI_INT32_Q18_TO_INT  TI方式INT32的Q18转化整形类型\n
*    LQ_TI_INT32_Q17_TO_INT  TI方式INT32的Q17转化整形类型\n
*    LQ_TI_INT32_Q16_TO_INT  TI方式INT32的Q16转化整形类型\n
*    LQ_TI_INT32_Q15_TO_INT  TI方式INT32的Q15转化整形类型\n
*    LQ_TI_INT32_Q14_TO_INT  TI方式INT32的Q14转化整形类型\n
*    LQ_TI_INT32_Q13_TO_INT  TI方式INT32的Q13转化整形类型\n
*    LQ_TI_INT32_Q12_TO_INT  TI方式INT32的Q12转化整形类型\n
*    LQ_TI_INT32_Q11_TO_INT  TI方式INT32的Q11转化整形类型\n
*    LQ_TI_INT32_Q10_TO_INT  TI方式INT32的Q10转化整形类型\n
*    LQ_TI_INT32_Q9_TO_INT  TI方式INT32的Q9转化整形类型\n
*    LQ_TI_INT32_Q8_TO_INT  TI方式INT32的Q8转化整形类型\n
*    LQ_TI_INT32_Q7_TO_INT  TI方式INT32的Q7转化整形类型\n
*    LQ_TI_INT32_Q6_TO_INT  TI方式INT32的Q6转化整形类型\n
*    LQ_TI_INT32_Q5_TO_INT  TI方式INT32的Q5转化整形类型\n
*    LQ_TI_INT32_Q4_TO_INT  TI方式INT32的Q4转化整形类型\n
*    LQ_TI_INT32_Q3_TO_INT  TI方式INT32的Q3转化整形类型\n
*    LQ_TI_INT32_Q2_TO_INT  TI方式INT32的Q2转化整形类型\n
*    LQ_TI_INT32_Q1_TO_INT  TI方式INT32的Q1转化整形类型\n
*/
LQ_INLINE LQ_INT32_Q24 LQ_TI_INT32_Q24_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error){
    return (LQ_INT32_Q24)(((LQ_I_32BIT)A + (((LQ_I_32BIT)A < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 24) - 1u) : 0)) >> 24);
}
/**@brief (TI方法)INT32类型Q23格式转整形
* @details 采用估算位+指数位+符号位三位结合
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为整形数
* @code*    LQ_TI_INT32_Q23_TO_INT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_INT32_Q31_TO_INT  TI方式INT32的Q31转化整形类型\n
*    LQ_TI_INT32_Q30_TO_INT  TI方式INT32的Q30转化整形类型\n
*    LQ_TI_INT32_Q29_TO_INT  TI方式INT32的Q29转化整形类型\n
*    LQ_TI_INT32_Q28_TO_INT  TI方式INT32的Q28转化整形类型\n
*    LQ_TI_INT32_Q27_TO_INT  TI方式INT32的Q27转化整形类型\n
*    LQ_TI_INT32_Q26_TO_INT  TI方式INT32的Q26转化整形类型\n
*    LQ_TI_INT32_Q25_TO_INT  TI方式INT32的Q25转化整形类型\n
*    LQ_TI_INT32_Q24_TO_INT  TI方式INT32的Q24转化整形类型\n
*    LQ_TI_INT32_Q23_TO_INT  TI方式INT32的Q23转化整形类型\n
*    LQ_TI_INT32_Q22_TO_INT  TI方式INT32的Q22转化整形类型\n
*    LQ_TI_INT32_Q21_TO_INT  TI方式INT32的Q21转化整形类型\n
*    LQ_TI_INT32_Q20_TO_INT  TI方式INT32的Q20转化整形类型\n
*    LQ_TI_INT32_Q19_TO_INT  TI方式INT32的Q19转化整形类型\n
*    LQ_TI_INT32_Q18_TO_INT  TI方式INT32的Q18转化整形类型\n
*    LQ_TI_INT32_Q17_TO_INT  TI方式INT32的Q17转化整形类型\n
*    LQ_TI_INT32_Q16_TO_INT  TI方式INT32的Q16转化整形类型\n
*    LQ_TI_INT32_Q15_TO_INT  TI方式INT32的Q15转化整形类型\n
*    LQ_TI_INT32_Q14_TO_INT  TI方式INT32的Q14转化整形类型\n
*    LQ_TI_INT32_Q13_TO_INT  TI方式INT32的Q13转化整形类型\n
*    LQ_TI_INT32_Q12_TO_INT  TI方式INT32的Q12转化整形类型\n
*    LQ_TI_INT32_Q11_TO_INT  TI方式INT32的Q11转化整形类型\n
*    LQ_TI_INT32_Q10_TO_INT  TI方式INT32的Q10转化整形类型\n
*    LQ_TI_INT32_Q9_TO_INT  TI方式INT32的Q9转化整形类型\n
*    LQ_TI_INT32_Q8_TO_INT  TI方式INT32的Q8转化整形类型\n
*    LQ_TI_INT32_Q7_TO_INT  TI方式INT32的Q7转化整形类型\n
*    LQ_TI_INT32_Q6_TO_INT  TI方式INT32的Q6转化整形类型\n
*    LQ_TI_INT32_Q5_TO_INT  TI方式INT32的Q5转化整形类型\n
*    LQ_TI_INT32_Q4_TO_INT  TI方式INT32的Q4转化整形类型\n
*    LQ_TI_INT32_Q3_TO_INT  TI方式INT32的Q3转化整形类型\n
*    LQ_TI_INT32_Q2_TO_INT  TI方式INT32的Q2转化整形类型\n
*    LQ_TI_INT32_Q1_TO_INT  TI方式INT32的Q1转化整形类型\n
*/
LQ_INLINE LQ_INT32_Q23 LQ_TI_INT32_Q23_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error){
    return (LQ_INT32_Q23)(((LQ_I_32BIT)A + (((LQ_I_32BIT)A < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 23) - 1u) : 0)) >> 23);
}
/**@brief (TI方法)INT32类型Q22格式转整形
* @details 采用估算位+指数位+符号位三位结合
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为整形数
* @code*    LQ_TI_INT32_Q22_TO_INT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_INT32_Q31_TO_INT  TI方式INT32的Q31转化整形类型\n
*    LQ_TI_INT32_Q30_TO_INT  TI方式INT32的Q30转化整形类型\n
*    LQ_TI_INT32_Q29_TO_INT  TI方式INT32的Q29转化整形类型\n
*    LQ_TI_INT32_Q28_TO_INT  TI方式INT32的Q28转化整形类型\n
*    LQ_TI_INT32_Q27_TO_INT  TI方式INT32的Q27转化整形类型\n
*    LQ_TI_INT32_Q26_TO_INT  TI方式INT32的Q26转化整形类型\n
*    LQ_TI_INT32_Q25_TO_INT  TI方式INT32的Q25转化整形类型\n
*    LQ_TI_INT32_Q24_TO_INT  TI方式INT32的Q24转化整形类型\n
*    LQ_TI_INT32_Q23_TO_INT  TI方式INT32的Q23转化整形类型\n
*    LQ_TI_INT32_Q22_TO_INT  TI方式INT32的Q22转化整形类型\n
*    LQ_TI_INT32_Q21_TO_INT  TI方式INT32的Q21转化整形类型\n
*    LQ_TI_INT32_Q20_TO_INT  TI方式INT32的Q20转化整形类型\n
*    LQ_TI_INT32_Q19_TO_INT  TI方式INT32的Q19转化整形类型\n
*    LQ_TI_INT32_Q18_TO_INT  TI方式INT32的Q18转化整形类型\n
*    LQ_TI_INT32_Q17_TO_INT  TI方式INT32的Q17转化整形类型\n
*    LQ_TI_INT32_Q16_TO_INT  TI方式INT32的Q16转化整形类型\n
*    LQ_TI_INT32_Q15_TO_INT  TI方式INT32的Q15转化整形类型\n
*    LQ_TI_INT32_Q14_TO_INT  TI方式INT32的Q14转化整形类型\n
*    LQ_TI_INT32_Q13_TO_INT  TI方式INT32的Q13转化整形类型\n
*    LQ_TI_INT32_Q12_TO_INT  TI方式INT32的Q12转化整形类型\n
*    LQ_TI_INT32_Q11_TO_INT  TI方式INT32的Q11转化整形类型\n
*    LQ_TI_INT32_Q10_TO_INT  TI方式INT32的Q10转化整形类型\n
*    LQ_TI_INT32_Q9_TO_INT  TI方式INT32的Q9转化整形类型\n
*    LQ_TI_INT32_Q8_TO_INT  TI方式INT32的Q8转化整形类型\n
*    LQ_TI_INT32_Q7_TO_INT  TI方式INT32的Q7转化整形类型\n
*    LQ_TI_INT32_Q6_TO_INT  TI方式INT32的Q6转化整形类型\n
*    LQ_TI_INT32_Q5_TO_INT  TI方式INT32的Q5转化整形类型\n
*    LQ_TI_INT32_Q4_TO_INT  TI方式INT32的Q4转化整形类型\n
*    LQ_TI_INT32_Q3_TO_INT  TI方式INT32的Q3转化整形类型\n
*    LQ_TI_INT32_Q2_TO_INT  TI方式INT32的Q2转化整形类型\n
*    LQ_TI_INT32_Q1_TO_INT  TI方式INT32的Q1转化整形类型\n
*/
LQ_INLINE LQ_INT32_Q22 LQ_TI_INT32_Q22_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error){
    return (LQ_INT32_Q22)(((LQ_I_32BIT)A + (((LQ_I_32BIT)A < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 22) - 1u) : 0)) >> 22);
}
/**@brief (TI方法)INT32类型Q21格式转整形
* @details 采用估算位+指数位+符号位三位结合
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为整形数
* @code*    LQ_TI_INT32_Q21_TO_INT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_INT32_Q31_TO_INT  TI方式INT32的Q31转化整形类型\n
*    LQ_TI_INT32_Q30_TO_INT  TI方式INT32的Q30转化整形类型\n
*    LQ_TI_INT32_Q29_TO_INT  TI方式INT32的Q29转化整形类型\n
*    LQ_TI_INT32_Q28_TO_INT  TI方式INT32的Q28转化整形类型\n
*    LQ_TI_INT32_Q27_TO_INT  TI方式INT32的Q27转化整形类型\n
*    LQ_TI_INT32_Q26_TO_INT  TI方式INT32的Q26转化整形类型\n
*    LQ_TI_INT32_Q25_TO_INT  TI方式INT32的Q25转化整形类型\n
*    LQ_TI_INT32_Q24_TO_INT  TI方式INT32的Q24转化整形类型\n
*    LQ_TI_INT32_Q23_TO_INT  TI方式INT32的Q23转化整形类型\n
*    LQ_TI_INT32_Q22_TO_INT  TI方式INT32的Q22转化整形类型\n
*    LQ_TI_INT32_Q21_TO_INT  TI方式INT32的Q21转化整形类型\n
*    LQ_TI_INT32_Q20_TO_INT  TI方式INT32的Q20转化整形类型\n
*    LQ_TI_INT32_Q19_TO_INT  TI方式INT32的Q19转化整形类型\n
*    LQ_TI_INT32_Q18_TO_INT  TI方式INT32的Q18转化整形类型\n
*    LQ_TI_INT32_Q17_TO_INT  TI方式INT32的Q17转化整形类型\n
*    LQ_TI_INT32_Q16_TO_INT  TI方式INT32的Q16转化整形类型\n
*    LQ_TI_INT32_Q15_TO_INT  TI方式INT32的Q15转化整形类型\n
*    LQ_TI_INT32_Q14_TO_INT  TI方式INT32的Q14转化整形类型\n
*    LQ_TI_INT32_Q13_TO_INT  TI方式INT32的Q13转化整形类型\n
*    LQ_TI_INT32_Q12_TO_INT  TI方式INT32的Q12转化整形类型\n
*    LQ_TI_INT32_Q11_TO_INT  TI方式INT32的Q11转化整形类型\n
*    LQ_TI_INT32_Q10_TO_INT  TI方式INT32的Q10转化整形类型\n
*    LQ_TI_INT32_Q9_TO_INT  TI方式INT32的Q9转化整形类型\n
*    LQ_TI_INT32_Q8_TO_INT  TI方式INT32的Q8转化整形类型\n
*    LQ_TI_INT32_Q7_TO_INT  TI方式INT32的Q7转化整形类型\n
*    LQ_TI_INT32_Q6_TO_INT  TI方式INT32的Q6转化整形类型\n
*    LQ_TI_INT32_Q5_TO_INT  TI方式INT32的Q5转化整形类型\n
*    LQ_TI_INT32_Q4_TO_INT  TI方式INT32的Q4转化整形类型\n
*    LQ_TI_INT32_Q3_TO_INT  TI方式INT32的Q3转化整形类型\n
*    LQ_TI_INT32_Q2_TO_INT  TI方式INT32的Q2转化整形类型\n
*    LQ_TI_INT32_Q1_TO_INT  TI方式INT32的Q1转化整形类型\n
*/
LQ_INLINE LQ_INT32_Q21 LQ_TI_INT32_Q21_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error){
    return (LQ_INT32_Q21)(((LQ_I_32BIT)A + (((LQ_I_32BIT)A < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 21) - 1u) : 0)) >> 21);
}
/**@brief (TI方法)INT32类型Q20格式转整形
* @details 采用估算位+指数位+符号位三位结合
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为整形数
* @code*    LQ_TI_INT32_Q20_TO_INT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_INT32_Q31_TO_INT  TI方式INT32的Q31转化整形类型\n
*    LQ_TI_INT32_Q30_TO_INT  TI方式INT32的Q30转化整形类型\n
*    LQ_TI_INT32_Q29_TO_INT  TI方式INT32的Q29转化整形类型\n
*    LQ_TI_INT32_Q28_TO_INT  TI方式INT32的Q28转化整形类型\n
*    LQ_TI_INT32_Q27_TO_INT  TI方式INT32的Q27转化整形类型\n
*    LQ_TI_INT32_Q26_TO_INT  TI方式INT32的Q26转化整形类型\n
*    LQ_TI_INT32_Q25_TO_INT  TI方式INT32的Q25转化整形类型\n
*    LQ_TI_INT32_Q24_TO_INT  TI方式INT32的Q24转化整形类型\n
*    LQ_TI_INT32_Q23_TO_INT  TI方式INT32的Q23转化整形类型\n
*    LQ_TI_INT32_Q22_TO_INT  TI方式INT32的Q22转化整形类型\n
*    LQ_TI_INT32_Q21_TO_INT  TI方式INT32的Q21转化整形类型\n
*    LQ_TI_INT32_Q20_TO_INT  TI方式INT32的Q20转化整形类型\n
*    LQ_TI_INT32_Q19_TO_INT  TI方式INT32的Q19转化整形类型\n
*    LQ_TI_INT32_Q18_TO_INT  TI方式INT32的Q18转化整形类型\n
*    LQ_TI_INT32_Q17_TO_INT  TI方式INT32的Q17转化整形类型\n
*    LQ_TI_INT32_Q16_TO_INT  TI方式INT32的Q16转化整形类型\n
*    LQ_TI_INT32_Q15_TO_INT  TI方式INT32的Q15转化整形类型\n
*    LQ_TI_INT32_Q14_TO_INT  TI方式INT32的Q14转化整形类型\n
*    LQ_TI_INT32_Q13_TO_INT  TI方式INT32的Q13转化整形类型\n
*    LQ_TI_INT32_Q12_TO_INT  TI方式INT32的Q12转化整形类型\n
*    LQ_TI_INT32_Q11_TO_INT  TI方式INT32的Q11转化整形类型\n
*    LQ_TI_INT32_Q10_TO_INT  TI方式INT32的Q10转化整形类型\n
*    LQ_TI_INT32_Q9_TO_INT  TI方式INT32的Q9转化整形类型\n
*    LQ_TI_INT32_Q8_TO_INT  TI方式INT32的Q8转化整形类型\n
*    LQ_TI_INT32_Q7_TO_INT  TI方式INT32的Q7转化整形类型\n
*    LQ_TI_INT32_Q6_TO_INT  TI方式INT32的Q6转化整形类型\n
*    LQ_TI_INT32_Q5_TO_INT  TI方式INT32的Q5转化整形类型\n
*    LQ_TI_INT32_Q4_TO_INT  TI方式INT32的Q4转化整形类型\n
*    LQ_TI_INT32_Q3_TO_INT  TI方式INT32的Q3转化整形类型\n
*    LQ_TI_INT32_Q2_TO_INT  TI方式INT32的Q2转化整形类型\n
*    LQ_TI_INT32_Q1_TO_INT  TI方式INT32的Q1转化整形类型\n
*/
LQ_INLINE LQ_INT32_Q20 LQ_TI_INT32_Q20_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error){
    return (LQ_INT32_Q20)(((LQ_I_32BIT)A + (((LQ_I_32BIT)A < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 20) - 1u) : 0)) >> 20);
}
/**@brief (TI方法)INT32类型Q19格式转整形
* @details 采用估算位+指数位+符号位三位结合
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为整形数
* @code*    LQ_TI_INT32_Q19_TO_INT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_INT32_Q31_TO_INT  TI方式INT32的Q31转化整形类型\n
*    LQ_TI_INT32_Q30_TO_INT  TI方式INT32的Q30转化整形类型\n
*    LQ_TI_INT32_Q29_TO_INT  TI方式INT32的Q29转化整形类型\n
*    LQ_TI_INT32_Q28_TO_INT  TI方式INT32的Q28转化整形类型\n
*    LQ_TI_INT32_Q27_TO_INT  TI方式INT32的Q27转化整形类型\n
*    LQ_TI_INT32_Q26_TO_INT  TI方式INT32的Q26转化整形类型\n
*    LQ_TI_INT32_Q25_TO_INT  TI方式INT32的Q25转化整形类型\n
*    LQ_TI_INT32_Q24_TO_INT  TI方式INT32的Q24转化整形类型\n
*    LQ_TI_INT32_Q23_TO_INT  TI方式INT32的Q23转化整形类型\n
*    LQ_TI_INT32_Q22_TO_INT  TI方式INT32的Q22转化整形类型\n
*    LQ_TI_INT32_Q21_TO_INT  TI方式INT32的Q21转化整形类型\n
*    LQ_TI_INT32_Q20_TO_INT  TI方式INT32的Q20转化整形类型\n
*    LQ_TI_INT32_Q19_TO_INT  TI方式INT32的Q19转化整形类型\n
*    LQ_TI_INT32_Q18_TO_INT  TI方式INT32的Q18转化整形类型\n
*    LQ_TI_INT32_Q17_TO_INT  TI方式INT32的Q17转化整形类型\n
*    LQ_TI_INT32_Q16_TO_INT  TI方式INT32的Q16转化整形类型\n
*    LQ_TI_INT32_Q15_TO_INT  TI方式INT32的Q15转化整形类型\n
*    LQ_TI_INT32_Q14_TO_INT  TI方式INT32的Q14转化整形类型\n
*    LQ_TI_INT32_Q13_TO_INT  TI方式INT32的Q13转化整形类型\n
*    LQ_TI_INT32_Q12_TO_INT  TI方式INT32的Q12转化整形类型\n
*    LQ_TI_INT32_Q11_TO_INT  TI方式INT32的Q11转化整形类型\n
*    LQ_TI_INT32_Q10_TO_INT  TI方式INT32的Q10转化整形类型\n
*    LQ_TI_INT32_Q9_TO_INT  TI方式INT32的Q9转化整形类型\n
*    LQ_TI_INT32_Q8_TO_INT  TI方式INT32的Q8转化整形类型\n
*    LQ_TI_INT32_Q7_TO_INT  TI方式INT32的Q7转化整形类型\n
*    LQ_TI_INT32_Q6_TO_INT  TI方式INT32的Q6转化整形类型\n
*    LQ_TI_INT32_Q5_TO_INT  TI方式INT32的Q5转化整形类型\n
*    LQ_TI_INT32_Q4_TO_INT  TI方式INT32的Q4转化整形类型\n
*    LQ_TI_INT32_Q3_TO_INT  TI方式INT32的Q3转化整形类型\n
*    LQ_TI_INT32_Q2_TO_INT  TI方式INT32的Q2转化整形类型\n
*    LQ_TI_INT32_Q1_TO_INT  TI方式INT32的Q1转化整形类型\n
*/
LQ_INLINE LQ_INT32_Q19 LQ_TI_INT32_Q19_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error){
    return (LQ_INT32_Q19)(((LQ_I_32BIT)A + (((LQ_I_32BIT)A < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 19) - 1u) : 0)) >> 19);
}
/**@brief (TI方法)INT32类型Q18格式转整形
* @details 采用估算位+指数位+符号位三位结合
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为整形数
* @code*    LQ_TI_INT32_Q18_TO_INT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_INT32_Q31_TO_INT  TI方式INT32的Q31转化整形类型\n
*    LQ_TI_INT32_Q30_TO_INT  TI方式INT32的Q30转化整形类型\n
*    LQ_TI_INT32_Q29_TO_INT  TI方式INT32的Q29转化整形类型\n
*    LQ_TI_INT32_Q28_TO_INT  TI方式INT32的Q28转化整形类型\n
*    LQ_TI_INT32_Q27_TO_INT  TI方式INT32的Q27转化整形类型\n
*    LQ_TI_INT32_Q26_TO_INT  TI方式INT32的Q26转化整形类型\n
*    LQ_TI_INT32_Q25_TO_INT  TI方式INT32的Q25转化整形类型\n
*    LQ_TI_INT32_Q24_TO_INT  TI方式INT32的Q24转化整形类型\n
*    LQ_TI_INT32_Q23_TO_INT  TI方式INT32的Q23转化整形类型\n
*    LQ_TI_INT32_Q22_TO_INT  TI方式INT32的Q22转化整形类型\n
*    LQ_TI_INT32_Q21_TO_INT  TI方式INT32的Q21转化整形类型\n
*    LQ_TI_INT32_Q20_TO_INT  TI方式INT32的Q20转化整形类型\n
*    LQ_TI_INT32_Q19_TO_INT  TI方式INT32的Q19转化整形类型\n
*    LQ_TI_INT32_Q18_TO_INT  TI方式INT32的Q18转化整形类型\n
*    LQ_TI_INT32_Q17_TO_INT  TI方式INT32的Q17转化整形类型\n
*    LQ_TI_INT32_Q16_TO_INT  TI方式INT32的Q16转化整形类型\n
*    LQ_TI_INT32_Q15_TO_INT  TI方式INT32的Q15转化整形类型\n
*    LQ_TI_INT32_Q14_TO_INT  TI方式INT32的Q14转化整形类型\n
*    LQ_TI_INT32_Q13_TO_INT  TI方式INT32的Q13转化整形类型\n
*    LQ_TI_INT32_Q12_TO_INT  TI方式INT32的Q12转化整形类型\n
*    LQ_TI_INT32_Q11_TO_INT  TI方式INT32的Q11转化整形类型\n
*    LQ_TI_INT32_Q10_TO_INT  TI方式INT32的Q10转化整形类型\n
*    LQ_TI_INT32_Q9_TO_INT  TI方式INT32的Q9转化整形类型\n
*    LQ_TI_INT32_Q8_TO_INT  TI方式INT32的Q8转化整形类型\n
*    LQ_TI_INT32_Q7_TO_INT  TI方式INT32的Q7转化整形类型\n
*    LQ_TI_INT32_Q6_TO_INT  TI方式INT32的Q6转化整形类型\n
*    LQ_TI_INT32_Q5_TO_INT  TI方式INT32的Q5转化整形类型\n
*    LQ_TI_INT32_Q4_TO_INT  TI方式INT32的Q4转化整形类型\n
*    LQ_TI_INT32_Q3_TO_INT  TI方式INT32的Q3转化整形类型\n
*    LQ_TI_INT32_Q2_TO_INT  TI方式INT32的Q2转化整形类型\n
*    LQ_TI_INT32_Q1_TO_INT  TI方式INT32的Q1转化整形类型\n
*/
LQ_INLINE LQ_INT32_Q18 LQ_TI_INT32_Q18_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error){
    return (LQ_INT32_Q18)(((LQ_I_32BIT)A + (((LQ_I_32BIT)A < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 18) - 1u) : 0)) >> 18);
}
/**@brief (TI方法)INT32类型Q17格式转整形
* @details 采用估算位+指数位+符号位三位结合
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为整形数
* @code*    LQ_TI_INT32_Q17_TO_INT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_INT32_Q31_TO_INT  TI方式INT32的Q31转化整形类型\n
*    LQ_TI_INT32_Q30_TO_INT  TI方式INT32的Q30转化整形类型\n
*    LQ_TI_INT32_Q29_TO_INT  TI方式INT32的Q29转化整形类型\n
*    LQ_TI_INT32_Q28_TO_INT  TI方式INT32的Q28转化整形类型\n
*    LQ_TI_INT32_Q27_TO_INT  TI方式INT32的Q27转化整形类型\n
*    LQ_TI_INT32_Q26_TO_INT  TI方式INT32的Q26转化整形类型\n
*    LQ_TI_INT32_Q25_TO_INT  TI方式INT32的Q25转化整形类型\n
*    LQ_TI_INT32_Q24_TO_INT  TI方式INT32的Q24转化整形类型\n
*    LQ_TI_INT32_Q23_TO_INT  TI方式INT32的Q23转化整形类型\n
*    LQ_TI_INT32_Q22_TO_INT  TI方式INT32的Q22转化整形类型\n
*    LQ_TI_INT32_Q21_TO_INT  TI方式INT32的Q21转化整形类型\n
*    LQ_TI_INT32_Q20_TO_INT  TI方式INT32的Q20转化整形类型\n
*    LQ_TI_INT32_Q19_TO_INT  TI方式INT32的Q19转化整形类型\n
*    LQ_TI_INT32_Q18_TO_INT  TI方式INT32的Q18转化整形类型\n
*    LQ_TI_INT32_Q17_TO_INT  TI方式INT32的Q17转化整形类型\n
*    LQ_TI_INT32_Q16_TO_INT  TI方式INT32的Q16转化整形类型\n
*    LQ_TI_INT32_Q15_TO_INT  TI方式INT32的Q15转化整形类型\n
*    LQ_TI_INT32_Q14_TO_INT  TI方式INT32的Q14转化整形类型\n
*    LQ_TI_INT32_Q13_TO_INT  TI方式INT32的Q13转化整形类型\n
*    LQ_TI_INT32_Q12_TO_INT  TI方式INT32的Q12转化整形类型\n
*    LQ_TI_INT32_Q11_TO_INT  TI方式INT32的Q11转化整形类型\n
*    LQ_TI_INT32_Q10_TO_INT  TI方式INT32的Q10转化整形类型\n
*    LQ_TI_INT32_Q9_TO_INT  TI方式INT32的Q9转化整形类型\n
*    LQ_TI_INT32_Q8_TO_INT  TI方式INT32的Q8转化整形类型\n
*    LQ_TI_INT32_Q7_TO_INT  TI方式INT32的Q7转化整形类型\n
*    LQ_TI_INT32_Q6_TO_INT  TI方式INT32的Q6转化整形类型\n
*    LQ_TI_INT32_Q5_TO_INT  TI方式INT32的Q5转化整形类型\n
*    LQ_TI_INT32_Q4_TO_INT  TI方式INT32的Q4转化整形类型\n
*    LQ_TI_INT32_Q3_TO_INT  TI方式INT32的Q3转化整形类型\n
*    LQ_TI_INT32_Q2_TO_INT  TI方式INT32的Q2转化整形类型\n
*    LQ_TI_INT32_Q1_TO_INT  TI方式INT32的Q1转化整形类型\n
*/
LQ_INLINE LQ_INT32_Q17 LQ_TI_INT32_Q17_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error){
    return (LQ_INT32_Q17)(((LQ_I_32BIT)A + (((LQ_I_32BIT)A < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 17) - 1u) : 0)) >> 17);
}
/**@brief (TI方法)INT32类型Q16格式转整形
* @details 采用估算位+指数位+符号位三位结合
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为整形数
* @code*    LQ_TI_INT32_Q16_TO_INT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_INT32_Q31_TO_INT  TI方式INT32的Q31转化整形类型\n
*    LQ_TI_INT32_Q30_TO_INT  TI方式INT32的Q30转化整形类型\n
*    LQ_TI_INT32_Q29_TO_INT  TI方式INT32的Q29转化整形类型\n
*    LQ_TI_INT32_Q28_TO_INT  TI方式INT32的Q28转化整形类型\n
*    LQ_TI_INT32_Q27_TO_INT  TI方式INT32的Q27转化整形类型\n
*    LQ_TI_INT32_Q26_TO_INT  TI方式INT32的Q26转化整形类型\n
*    LQ_TI_INT32_Q25_TO_INT  TI方式INT32的Q25转化整形类型\n
*    LQ_TI_INT32_Q24_TO_INT  TI方式INT32的Q24转化整形类型\n
*    LQ_TI_INT32_Q23_TO_INT  TI方式INT32的Q23转化整形类型\n
*    LQ_TI_INT32_Q22_TO_INT  TI方式INT32的Q22转化整形类型\n
*    LQ_TI_INT32_Q21_TO_INT  TI方式INT32的Q21转化整形类型\n
*    LQ_TI_INT32_Q20_TO_INT  TI方式INT32的Q20转化整形类型\n
*    LQ_TI_INT32_Q19_TO_INT  TI方式INT32的Q19转化整形类型\n
*    LQ_TI_INT32_Q18_TO_INT  TI方式INT32的Q18转化整形类型\n
*    LQ_TI_INT32_Q17_TO_INT  TI方式INT32的Q17转化整形类型\n
*    LQ_TI_INT32_Q16_TO_INT  TI方式INT32的Q16转化整形类型\n
*    LQ_TI_INT32_Q15_TO_INT  TI方式INT32的Q15转化整形类型\n
*    LQ_TI_INT32_Q14_TO_INT  TI方式INT32的Q14转化整形类型\n
*    LQ_TI_INT32_Q13_TO_INT  TI方式INT32的Q13转化整形类型\n
*    LQ_TI_INT32_Q12_TO_INT  TI方式INT32的Q12转化整形类型\n
*    LQ_TI_INT32_Q11_TO_INT  TI方式INT32的Q11转化整形类型\n
*    LQ_TI_INT32_Q10_TO_INT  TI方式INT32的Q10转化整形类型\n
*    LQ_TI_INT32_Q9_TO_INT  TI方式INT32的Q9转化整形类型\n
*    LQ_TI_INT32_Q8_TO_INT  TI方式INT32的Q8转化整形类型\n
*    LQ_TI_INT32_Q7_TO_INT  TI方式INT32的Q7转化整形类型\n
*    LQ_TI_INT32_Q6_TO_INT  TI方式INT32的Q6转化整形类型\n
*    LQ_TI_INT32_Q5_TO_INT  TI方式INT32的Q5转化整形类型\n
*    LQ_TI_INT32_Q4_TO_INT  TI方式INT32的Q4转化整形类型\n
*    LQ_TI_INT32_Q3_TO_INT  TI方式INT32的Q3转化整形类型\n
*    LQ_TI_INT32_Q2_TO_INT  TI方式INT32的Q2转化整形类型\n
*    LQ_TI_INT32_Q1_TO_INT  TI方式INT32的Q1转化整形类型\n
*/
LQ_INLINE LQ_INT32_Q16 LQ_TI_INT32_Q16_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error){
    return (LQ_INT32_Q16)(((LQ_I_32BIT)A + (((LQ_I_32BIT)A < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 16) - 1u) : 0)) >> 16);
}
/**@brief (TI方法)INT32类型Q15格式转整形
* @details 采用估算位+指数位+符号位三位结合
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为整形数
* @code*    LQ_TI_INT32_Q15_TO_INT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_INT32_Q31_TO_INT  TI方式INT32的Q31转化整形类型\n
*    LQ_TI_INT32_Q30_TO_INT  TI方式INT32的Q30转化整形类型\n
*    LQ_TI_INT32_Q29_TO_INT  TI方式INT32的Q29转化整形类型\n
*    LQ_TI_INT32_Q28_TO_INT  TI方式INT32的Q28转化整形类型\n
*    LQ_TI_INT32_Q27_TO_INT  TI方式INT32的Q27转化整形类型\n
*    LQ_TI_INT32_Q26_TO_INT  TI方式INT32的Q26转化整形类型\n
*    LQ_TI_INT32_Q25_TO_INT  TI方式INT32的Q25转化整形类型\n
*    LQ_TI_INT32_Q24_TO_INT  TI方式INT32的Q24转化整形类型\n
*    LQ_TI_INT32_Q23_TO_INT  TI方式INT32的Q23转化整形类型\n
*    LQ_TI_INT32_Q22_TO_INT  TI方式INT32的Q22转化整形类型\n
*    LQ_TI_INT32_Q21_TO_INT  TI方式INT32的Q21转化整形类型\n
*    LQ_TI_INT32_Q20_TO_INT  TI方式INT32的Q20转化整形类型\n
*    LQ_TI_INT32_Q19_TO_INT  TI方式INT32的Q19转化整形类型\n
*    LQ_TI_INT32_Q18_TO_INT  TI方式INT32的Q18转化整形类型\n
*    LQ_TI_INT32_Q17_TO_INT  TI方式INT32的Q17转化整形类型\n
*    LQ_TI_INT32_Q16_TO_INT  TI方式INT32的Q16转化整形类型\n
*    LQ_TI_INT32_Q15_TO_INT  TI方式INT32的Q15转化整形类型\n
*    LQ_TI_INT32_Q14_TO_INT  TI方式INT32的Q14转化整形类型\n
*    LQ_TI_INT32_Q13_TO_INT  TI方式INT32的Q13转化整形类型\n
*    LQ_TI_INT32_Q12_TO_INT  TI方式INT32的Q12转化整形类型\n
*    LQ_TI_INT32_Q11_TO_INT  TI方式INT32的Q11转化整形类型\n
*    LQ_TI_INT32_Q10_TO_INT  TI方式INT32的Q10转化整形类型\n
*    LQ_TI_INT32_Q9_TO_INT  TI方式INT32的Q9转化整形类型\n
*    LQ_TI_INT32_Q8_TO_INT  TI方式INT32的Q8转化整形类型\n
*    LQ_TI_INT32_Q7_TO_INT  TI方式INT32的Q7转化整形类型\n
*    LQ_TI_INT32_Q6_TO_INT  TI方式INT32的Q6转化整形类型\n
*    LQ_TI_INT32_Q5_TO_INT  TI方式INT32的Q5转化整形类型\n
*    LQ_TI_INT32_Q4_TO_INT  TI方式INT32的Q4转化整形类型\n
*    LQ_TI_INT32_Q3_TO_INT  TI方式INT32的Q3转化整形类型\n
*    LQ_TI_INT32_Q2_TO_INT  TI方式INT32的Q2转化整形类型\n
*    LQ_TI_INT32_Q1_TO_INT  TI方式INT32的Q1转化整形类型\n
*/
LQ_INLINE LQ_INT32_Q15 LQ_TI_INT32_Q15_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error){
    return (LQ_INT32_Q15)(((LQ_I_32BIT)A + (((LQ_I_32BIT)A < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 15) - 1u) : 0)) >> 15);
}
/**@brief (TI方法)INT32类型Q14格式转整形
* @details 采用估算位+指数位+符号位三位结合
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为整形数
* @code*    LQ_TI_INT32_Q14_TO_INT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_INT32_Q31_TO_INT  TI方式INT32的Q31转化整形类型\n
*    LQ_TI_INT32_Q30_TO_INT  TI方式INT32的Q30转化整形类型\n
*    LQ_TI_INT32_Q29_TO_INT  TI方式INT32的Q29转化整形类型\n
*    LQ_TI_INT32_Q28_TO_INT  TI方式INT32的Q28转化整形类型\n
*    LQ_TI_INT32_Q27_TO_INT  TI方式INT32的Q27转化整形类型\n
*    LQ_TI_INT32_Q26_TO_INT  TI方式INT32的Q26转化整形类型\n
*    LQ_TI_INT32_Q25_TO_INT  TI方式INT32的Q25转化整形类型\n
*    LQ_TI_INT32_Q24_TO_INT  TI方式INT32的Q24转化整形类型\n
*    LQ_TI_INT32_Q23_TO_INT  TI方式INT32的Q23转化整形类型\n
*    LQ_TI_INT32_Q22_TO_INT  TI方式INT32的Q22转化整形类型\n
*    LQ_TI_INT32_Q21_TO_INT  TI方式INT32的Q21转化整形类型\n
*    LQ_TI_INT32_Q20_TO_INT  TI方式INT32的Q20转化整形类型\n
*    LQ_TI_INT32_Q19_TO_INT  TI方式INT32的Q19转化整形类型\n
*    LQ_TI_INT32_Q18_TO_INT  TI方式INT32的Q18转化整形类型\n
*    LQ_TI_INT32_Q17_TO_INT  TI方式INT32的Q17转化整形类型\n
*    LQ_TI_INT32_Q16_TO_INT  TI方式INT32的Q16转化整形类型\n
*    LQ_TI_INT32_Q15_TO_INT  TI方式INT32的Q15转化整形类型\n
*    LQ_TI_INT32_Q14_TO_INT  TI方式INT32的Q14转化整形类型\n
*    LQ_TI_INT32_Q13_TO_INT  TI方式INT32的Q13转化整形类型\n
*    LQ_TI_INT32_Q12_TO_INT  TI方式INT32的Q12转化整形类型\n
*    LQ_TI_INT32_Q11_TO_INT  TI方式INT32的Q11转化整形类型\n
*    LQ_TI_INT32_Q10_TO_INT  TI方式INT32的Q10转化整形类型\n
*    LQ_TI_INT32_Q9_TO_INT  TI方式INT32的Q9转化整形类型\n
*    LQ_TI_INT32_Q8_TO_INT  TI方式INT32的Q8转化整形类型\n
*    LQ_TI_INT32_Q7_TO_INT  TI方式INT32的Q7转化整形类型\n
*    LQ_TI_INT32_Q6_TO_INT  TI方式INT32的Q6转化整形类型\n
*    LQ_TI_INT32_Q5_TO_INT  TI方式INT32的Q5转化整形类型\n
*    LQ_TI_INT32_Q4_TO_INT  TI方式INT32的Q4转化整形类型\n
*    LQ_TI_INT32_Q3_TO_INT  TI方式INT32的Q3转化整形类型\n
*    LQ_TI_INT32_Q2_TO_INT  TI方式INT32的Q2转化整形类型\n
*    LQ_TI_INT32_Q1_TO_INT  TI方式INT32的Q1转化整形类型\n
*/
LQ_INLINE LQ_INT32_Q14 LQ_TI_INT32_Q14_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error){
    return (LQ_INT32_Q14)(((LQ_I_32BIT)A + (((LQ_I_32BIT)A < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 14) - 1u) : 0)) >> 14);
}
/**@brief (TI方法)INT32类型Q13格式转整形
* @details 采用估算位+指数位+符号位三位结合
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为整形数
* @code*    LQ_TI_INT32_Q13_TO_INT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_INT32_Q31_TO_INT  TI方式INT32的Q31转化整形类型\n
*    LQ_TI_INT32_Q30_TO_INT  TI方式INT32的Q30转化整形类型\n
*    LQ_TI_INT32_Q29_TO_INT  TI方式INT32的Q29转化整形类型\n
*    LQ_TI_INT32_Q28_TO_INT  TI方式INT32的Q28转化整形类型\n
*    LQ_TI_INT32_Q27_TO_INT  TI方式INT32的Q27转化整形类型\n
*    LQ_TI_INT32_Q26_TO_INT  TI方式INT32的Q26转化整形类型\n
*    LQ_TI_INT32_Q25_TO_INT  TI方式INT32的Q25转化整形类型\n
*    LQ_TI_INT32_Q24_TO_INT  TI方式INT32的Q24转化整形类型\n
*    LQ_TI_INT32_Q23_TO_INT  TI方式INT32的Q23转化整形类型\n
*    LQ_TI_INT32_Q22_TO_INT  TI方式INT32的Q22转化整形类型\n
*    LQ_TI_INT32_Q21_TO_INT  TI方式INT32的Q21转化整形类型\n
*    LQ_TI_INT32_Q20_TO_INT  TI方式INT32的Q20转化整形类型\n
*    LQ_TI_INT32_Q19_TO_INT  TI方式INT32的Q19转化整形类型\n
*    LQ_TI_INT32_Q18_TO_INT  TI方式INT32的Q18转化整形类型\n
*    LQ_TI_INT32_Q17_TO_INT  TI方式INT32的Q17转化整形类型\n
*    LQ_TI_INT32_Q16_TO_INT  TI方式INT32的Q16转化整形类型\n
*    LQ_TI_INT32_Q15_TO_INT  TI方式INT32的Q15转化整形类型\n
*    LQ_TI_INT32_Q14_TO_INT  TI方式INT32的Q14转化整形类型\n
*    LQ_TI_INT32_Q13_TO_INT  TI方式INT32的Q13转化整形类型\n
*    LQ_TI_INT32_Q12_TO_INT  TI方式INT32的Q12转化整形类型\n
*    LQ_TI_INT32_Q11_TO_INT  TI方式INT32的Q11转化整形类型\n
*    LQ_TI_INT32_Q10_TO_INT  TI方式INT32的Q10转化整形类型\n
*    LQ_TI_INT32_Q9_TO_INT  TI方式INT32的Q9转化整形类型\n
*    LQ_TI_INT32_Q8_TO_INT  TI方式INT32的Q8转化整形类型\n
*    LQ_TI_INT32_Q7_TO_INT  TI方式INT32的Q7转化整形类型\n
*    LQ_TI_INT32_Q6_TO_INT  TI方式INT32的Q6转化整形类型\n
*    LQ_TI_INT32_Q5_TO_INT  TI方式INT32的Q5转化整形类型\n
*    LQ_TI_INT32_Q4_TO_INT  TI方式INT32的Q4转化整形类型\n
*    LQ_TI_INT32_Q3_TO_INT  TI方式INT32的Q3转化整形类型\n
*    LQ_TI_INT32_Q2_TO_INT  TI方式INT32的Q2转化整形类型\n
*    LQ_TI_INT32_Q1_TO_INT  TI方式INT32的Q1转化整形类型\n
*/
LQ_INLINE LQ_INT32_Q13 LQ_TI_INT32_Q13_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error){
    return (LQ_INT32_Q13)(((LQ_I_32BIT)A + (((LQ_I_32BIT)A < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 13) - 1u) : 0)) >> 13);
}
/**@brief (TI方法)INT32类型Q12格式转整形
* @details 采用估算位+指数位+符号位三位结合
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为整形数
* @code*    LQ_TI_INT32_Q12_TO_INT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_INT32_Q31_TO_INT  TI方式INT32的Q31转化整形类型\n
*    LQ_TI_INT32_Q30_TO_INT  TI方式INT32的Q30转化整形类型\n
*    LQ_TI_INT32_Q29_TO_INT  TI方式INT32的Q29转化整形类型\n
*    LQ_TI_INT32_Q28_TO_INT  TI方式INT32的Q28转化整形类型\n
*    LQ_TI_INT32_Q27_TO_INT  TI方式INT32的Q27转化整形类型\n
*    LQ_TI_INT32_Q26_TO_INT  TI方式INT32的Q26转化整形类型\n
*    LQ_TI_INT32_Q25_TO_INT  TI方式INT32的Q25转化整形类型\n
*    LQ_TI_INT32_Q24_TO_INT  TI方式INT32的Q24转化整形类型\n
*    LQ_TI_INT32_Q23_TO_INT  TI方式INT32的Q23转化整形类型\n
*    LQ_TI_INT32_Q22_TO_INT  TI方式INT32的Q22转化整形类型\n
*    LQ_TI_INT32_Q21_TO_INT  TI方式INT32的Q21转化整形类型\n
*    LQ_TI_INT32_Q20_TO_INT  TI方式INT32的Q20转化整形类型\n
*    LQ_TI_INT32_Q19_TO_INT  TI方式INT32的Q19转化整形类型\n
*    LQ_TI_INT32_Q18_TO_INT  TI方式INT32的Q18转化整形类型\n
*    LQ_TI_INT32_Q17_TO_INT  TI方式INT32的Q17转化整形类型\n
*    LQ_TI_INT32_Q16_TO_INT  TI方式INT32的Q16转化整形类型\n
*    LQ_TI_INT32_Q15_TO_INT  TI方式INT32的Q15转化整形类型\n
*    LQ_TI_INT32_Q14_TO_INT  TI方式INT32的Q14转化整形类型\n
*    LQ_TI_INT32_Q13_TO_INT  TI方式INT32的Q13转化整形类型\n
*    LQ_TI_INT32_Q12_TO_INT  TI方式INT32的Q12转化整形类型\n
*    LQ_TI_INT32_Q11_TO_INT  TI方式INT32的Q11转化整形类型\n
*    LQ_TI_INT32_Q10_TO_INT  TI方式INT32的Q10转化整形类型\n
*    LQ_TI_INT32_Q9_TO_INT  TI方式INT32的Q9转化整形类型\n
*    LQ_TI_INT32_Q8_TO_INT  TI方式INT32的Q8转化整形类型\n
*    LQ_TI_INT32_Q7_TO_INT  TI方式INT32的Q7转化整形类型\n
*    LQ_TI_INT32_Q6_TO_INT  TI方式INT32的Q6转化整形类型\n
*    LQ_TI_INT32_Q5_TO_INT  TI方式INT32的Q5转化整形类型\n
*    LQ_TI_INT32_Q4_TO_INT  TI方式INT32的Q4转化整形类型\n
*    LQ_TI_INT32_Q3_TO_INT  TI方式INT32的Q3转化整形类型\n
*    LQ_TI_INT32_Q2_TO_INT  TI方式INT32的Q2转化整形类型\n
*    LQ_TI_INT32_Q1_TO_INT  TI方式INT32的Q1转化整形类型\n
*/
LQ_INLINE LQ_INT32_Q12 LQ_TI_INT32_Q12_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error){
    return (LQ_INT32_Q12)(((LQ_I_32BIT)A + (((LQ_I_32BIT)A < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 12) - 1u) : 0)) >> 12);
}
/**@brief (TI方法)INT32类型Q11格式转整形
* @details 采用估算位+指数位+符号位三位结合
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为整形数
* @code*    LQ_TI_INT32_Q11_TO_INT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_INT32_Q31_TO_INT  TI方式INT32的Q31转化整形类型\n
*    LQ_TI_INT32_Q30_TO_INT  TI方式INT32的Q30转化整形类型\n
*    LQ_TI_INT32_Q29_TO_INT  TI方式INT32的Q29转化整形类型\n
*    LQ_TI_INT32_Q28_TO_INT  TI方式INT32的Q28转化整形类型\n
*    LQ_TI_INT32_Q27_TO_INT  TI方式INT32的Q27转化整形类型\n
*    LQ_TI_INT32_Q26_TO_INT  TI方式INT32的Q26转化整形类型\n
*    LQ_TI_INT32_Q25_TO_INT  TI方式INT32的Q25转化整形类型\n
*    LQ_TI_INT32_Q24_TO_INT  TI方式INT32的Q24转化整形类型\n
*    LQ_TI_INT32_Q23_TO_INT  TI方式INT32的Q23转化整形类型\n
*    LQ_TI_INT32_Q22_TO_INT  TI方式INT32的Q22转化整形类型\n
*    LQ_TI_INT32_Q21_TO_INT  TI方式INT32的Q21转化整形类型\n
*    LQ_TI_INT32_Q20_TO_INT  TI方式INT32的Q20转化整形类型\n
*    LQ_TI_INT32_Q19_TO_INT  TI方式INT32的Q19转化整形类型\n
*    LQ_TI_INT32_Q18_TO_INT  TI方式INT32的Q18转化整形类型\n
*    LQ_TI_INT32_Q17_TO_INT  TI方式INT32的Q17转化整形类型\n
*    LQ_TI_INT32_Q16_TO_INT  TI方式INT32的Q16转化整形类型\n
*    LQ_TI_INT32_Q15_TO_INT  TI方式INT32的Q15转化整形类型\n
*    LQ_TI_INT32_Q14_TO_INT  TI方式INT32的Q14转化整形类型\n
*    LQ_TI_INT32_Q13_TO_INT  TI方式INT32的Q13转化整形类型\n
*    LQ_TI_INT32_Q12_TO_INT  TI方式INT32的Q12转化整形类型\n
*    LQ_TI_INT32_Q11_TO_INT  TI方式INT32的Q11转化整形类型\n
*    LQ_TI_INT32_Q10_TO_INT  TI方式INT32的Q10转化整形类型\n
*    LQ_TI_INT32_Q9_TO_INT  TI方式INT32的Q9转化整形类型\n
*    LQ_TI_INT32_Q8_TO_INT  TI方式INT32的Q8转化整形类型\n
*    LQ_TI_INT32_Q7_TO_INT  TI方式INT32的Q7转化整形类型\n
*    LQ_TI_INT32_Q6_TO_INT  TI方式INT32的Q6转化整形类型\n
*    LQ_TI_INT32_Q5_TO_INT  TI方式INT32的Q5转化整形类型\n
*    LQ_TI_INT32_Q4_TO_INT  TI方式INT32的Q4转化整形类型\n
*    LQ_TI_INT32_Q3_TO_INT  TI方式INT32的Q3转化整形类型\n
*    LQ_TI_INT32_Q2_TO_INT  TI方式INT32的Q2转化整形类型\n
*    LQ_TI_INT32_Q1_TO_INT  TI方式INT32的Q1转化整形类型\n
*/
LQ_INLINE LQ_INT32_Q11 LQ_TI_INT32_Q11_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error){
    return (LQ_INT32_Q11)(((LQ_I_32BIT)A + (((LQ_I_32BIT)A < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 11) - 1u) : 0)) >> 11);
}
/**@brief (TI方法)INT32类型Q10格式转整形
* @details 采用估算位+指数位+符号位三位结合
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为整形数
* @code*    LQ_TI_INT32_Q10_TO_INT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_INT32_Q31_TO_INT  TI方式INT32的Q31转化整形类型\n
*    LQ_TI_INT32_Q30_TO_INT  TI方式INT32的Q30转化整形类型\n
*    LQ_TI_INT32_Q29_TO_INT  TI方式INT32的Q29转化整形类型\n
*    LQ_TI_INT32_Q28_TO_INT  TI方式INT32的Q28转化整形类型\n
*    LQ_TI_INT32_Q27_TO_INT  TI方式INT32的Q27转化整形类型\n
*    LQ_TI_INT32_Q26_TO_INT  TI方式INT32的Q26转化整形类型\n
*    LQ_TI_INT32_Q25_TO_INT  TI方式INT32的Q25转化整形类型\n
*    LQ_TI_INT32_Q24_TO_INT  TI方式INT32的Q24转化整形类型\n
*    LQ_TI_INT32_Q23_TO_INT  TI方式INT32的Q23转化整形类型\n
*    LQ_TI_INT32_Q22_TO_INT  TI方式INT32的Q22转化整形类型\n
*    LQ_TI_INT32_Q21_TO_INT  TI方式INT32的Q21转化整形类型\n
*    LQ_TI_INT32_Q20_TO_INT  TI方式INT32的Q20转化整形类型\n
*    LQ_TI_INT32_Q19_TO_INT  TI方式INT32的Q19转化整形类型\n
*    LQ_TI_INT32_Q18_TO_INT  TI方式INT32的Q18转化整形类型\n
*    LQ_TI_INT32_Q17_TO_INT  TI方式INT32的Q17转化整形类型\n
*    LQ_TI_INT32_Q16_TO_INT  TI方式INT32的Q16转化整形类型\n
*    LQ_TI_INT32_Q15_TO_INT  TI方式INT32的Q15转化整形类型\n
*    LQ_TI_INT32_Q14_TO_INT  TI方式INT32的Q14转化整形类型\n
*    LQ_TI_INT32_Q13_TO_INT  TI方式INT32的Q13转化整形类型\n
*    LQ_TI_INT32_Q12_TO_INT  TI方式INT32的Q12转化整形类型\n
*    LQ_TI_INT32_Q11_TO_INT  TI方式INT32的Q11转化整形类型\n
*    LQ_TI_INT32_Q10_TO_INT  TI方式INT32的Q10转化整形类型\n
*    LQ_TI_INT32_Q9_TO_INT  TI方式INT32的Q9转化整形类型\n
*    LQ_TI_INT32_Q8_TO_INT  TI方式INT32的Q8转化整形类型\n
*    LQ_TI_INT32_Q7_TO_INT  TI方式INT32的Q7转化整形类型\n
*    LQ_TI_INT32_Q6_TO_INT  TI方式INT32的Q6转化整形类型\n
*    LQ_TI_INT32_Q5_TO_INT  TI方式INT32的Q5转化整形类型\n
*    LQ_TI_INT32_Q4_TO_INT  TI方式INT32的Q4转化整形类型\n
*    LQ_TI_INT32_Q3_TO_INT  TI方式INT32的Q3转化整形类型\n
*    LQ_TI_INT32_Q2_TO_INT  TI方式INT32的Q2转化整形类型\n
*    LQ_TI_INT32_Q1_TO_INT  TI方式INT32的Q1转化整形类型\n
*/
LQ_INLINE LQ_INT32_Q10 LQ_TI_INT32_Q10_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error){
    return (LQ_INT32_Q10)(((LQ_I_32BIT)A + (((LQ_I_32BIT)A < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 10) - 1u) : 0)) >> 10);
}
/**@brief (TI方法)INT32类型Q9格式转整形
* @details 采用估算位+指数位+符号位三位结合
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为整形数
* @code*    LQ_TI_INT32_Q9_TO_INT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_INT32_Q31_TO_INT  TI方式INT32的Q31转化整形类型\n
*    LQ_TI_INT32_Q30_TO_INT  TI方式INT32的Q30转化整形类型\n
*    LQ_TI_INT32_Q29_TO_INT  TI方式INT32的Q29转化整形类型\n
*    LQ_TI_INT32_Q28_TO_INT  TI方式INT32的Q28转化整形类型\n
*    LQ_TI_INT32_Q27_TO_INT  TI方式INT32的Q27转化整形类型\n
*    LQ_TI_INT32_Q26_TO_INT  TI方式INT32的Q26转化整形类型\n
*    LQ_TI_INT32_Q25_TO_INT  TI方式INT32的Q25转化整形类型\n
*    LQ_TI_INT32_Q24_TO_INT  TI方式INT32的Q24转化整形类型\n
*    LQ_TI_INT32_Q23_TO_INT  TI方式INT32的Q23转化整形类型\n
*    LQ_TI_INT32_Q22_TO_INT  TI方式INT32的Q22转化整形类型\n
*    LQ_TI_INT32_Q21_TO_INT  TI方式INT32的Q21转化整形类型\n
*    LQ_TI_INT32_Q20_TO_INT  TI方式INT32的Q20转化整形类型\n
*    LQ_TI_INT32_Q19_TO_INT  TI方式INT32的Q19转化整形类型\n
*    LQ_TI_INT32_Q18_TO_INT  TI方式INT32的Q18转化整形类型\n
*    LQ_TI_INT32_Q17_TO_INT  TI方式INT32的Q17转化整形类型\n
*    LQ_TI_INT32_Q16_TO_INT  TI方式INT32的Q16转化整形类型\n
*    LQ_TI_INT32_Q15_TO_INT  TI方式INT32的Q15转化整形类型\n
*    LQ_TI_INT32_Q14_TO_INT  TI方式INT32的Q14转化整形类型\n
*    LQ_TI_INT32_Q13_TO_INT  TI方式INT32的Q13转化整形类型\n
*    LQ_TI_INT32_Q12_TO_INT  TI方式INT32的Q12转化整形类型\n
*    LQ_TI_INT32_Q11_TO_INT  TI方式INT32的Q11转化整形类型\n
*    LQ_TI_INT32_Q10_TO_INT  TI方式INT32的Q10转化整形类型\n
*    LQ_TI_INT32_Q9_TO_INT  TI方式INT32的Q9转化整形类型\n
*    LQ_TI_INT32_Q8_TO_INT  TI方式INT32的Q8转化整形类型\n
*    LQ_TI_INT32_Q7_TO_INT  TI方式INT32的Q7转化整形类型\n
*    LQ_TI_INT32_Q6_TO_INT  TI方式INT32的Q6转化整形类型\n
*    LQ_TI_INT32_Q5_TO_INT  TI方式INT32的Q5转化整形类型\n
*    LQ_TI_INT32_Q4_TO_INT  TI方式INT32的Q4转化整形类型\n
*    LQ_TI_INT32_Q3_TO_INT  TI方式INT32的Q3转化整形类型\n
*    LQ_TI_INT32_Q2_TO_INT  TI方式INT32的Q2转化整形类型\n
*    LQ_TI_INT32_Q1_TO_INT  TI方式INT32的Q1转化整形类型\n
*/
LQ_INLINE LQ_INT32_Q9 LQ_TI_INT32_Q9_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error){
    return (LQ_INT32_Q9)(((LQ_I_32BIT)A + (((LQ_I_32BIT)A < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 9) - 1u) : 0)) >> 9);
}
/**@brief (TI方法)INT32类型Q8格式转整形
* @details 采用估算位+指数位+符号位三位结合
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为整形数
* @code*    LQ_TI_INT32_Q8_TO_INT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_INT32_Q31_TO_INT  TI方式INT32的Q31转化整形类型\n
*    LQ_TI_INT32_Q30_TO_INT  TI方式INT32的Q30转化整形类型\n
*    LQ_TI_INT32_Q29_TO_INT  TI方式INT32的Q29转化整形类型\n
*    LQ_TI_INT32_Q28_TO_INT  TI方式INT32的Q28转化整形类型\n
*    LQ_TI_INT32_Q27_TO_INT  TI方式INT32的Q27转化整形类型\n
*    LQ_TI_INT32_Q26_TO_INT  TI方式INT32的Q26转化整形类型\n
*    LQ_TI_INT32_Q25_TO_INT  TI方式INT32的Q25转化整形类型\n
*    LQ_TI_INT32_Q24_TO_INT  TI方式INT32的Q24转化整形类型\n
*    LQ_TI_INT32_Q23_TO_INT  TI方式INT32的Q23转化整形类型\n
*    LQ_TI_INT32_Q22_TO_INT  TI方式INT32的Q22转化整形类型\n
*    LQ_TI_INT32_Q21_TO_INT  TI方式INT32的Q21转化整形类型\n
*    LQ_TI_INT32_Q20_TO_INT  TI方式INT32的Q20转化整形类型\n
*    LQ_TI_INT32_Q19_TO_INT  TI方式INT32的Q19转化整形类型\n
*    LQ_TI_INT32_Q18_TO_INT  TI方式INT32的Q18转化整形类型\n
*    LQ_TI_INT32_Q17_TO_INT  TI方式INT32的Q17转化整形类型\n
*    LQ_TI_INT32_Q16_TO_INT  TI方式INT32的Q16转化整形类型\n
*    LQ_TI_INT32_Q15_TO_INT  TI方式INT32的Q15转化整形类型\n
*    LQ_TI_INT32_Q14_TO_INT  TI方式INT32的Q14转化整形类型\n
*    LQ_TI_INT32_Q13_TO_INT  TI方式INT32的Q13转化整形类型\n
*    LQ_TI_INT32_Q12_TO_INT  TI方式INT32的Q12转化整形类型\n
*    LQ_TI_INT32_Q11_TO_INT  TI方式INT32的Q11转化整形类型\n
*    LQ_TI_INT32_Q10_TO_INT  TI方式INT32的Q10转化整形类型\n
*    LQ_TI_INT32_Q9_TO_INT  TI方式INT32的Q9转化整形类型\n
*    LQ_TI_INT32_Q8_TO_INT  TI方式INT32的Q8转化整形类型\n
*    LQ_TI_INT32_Q7_TO_INT  TI方式INT32的Q7转化整形类型\n
*    LQ_TI_INT32_Q6_TO_INT  TI方式INT32的Q6转化整形类型\n
*    LQ_TI_INT32_Q5_TO_INT  TI方式INT32的Q5转化整形类型\n
*    LQ_TI_INT32_Q4_TO_INT  TI方式INT32的Q4转化整形类型\n
*    LQ_TI_INT32_Q3_TO_INT  TI方式INT32的Q3转化整形类型\n
*    LQ_TI_INT32_Q2_TO_INT  TI方式INT32的Q2转化整形类型\n
*    LQ_TI_INT32_Q1_TO_INT  TI方式INT32的Q1转化整形类型\n
*/
LQ_INLINE LQ_INT32_Q8 LQ_TI_INT32_Q8_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error){
    return (LQ_INT32_Q8)(((LQ_I_32BIT)A + (((LQ_I_32BIT)A < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 8) - 1u) : 0)) >> 8);
}
/**@brief (TI方法)INT32类型Q7格式转整形
* @details 采用估算位+指数位+符号位三位结合
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为整形数
* @code*    LQ_TI_INT32_Q7_TO_INT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_INT32_Q31_TO_INT  TI方式INT32的Q31转化整形类型\n
*    LQ_TI_INT32_Q30_TO_INT  TI方式INT32的Q30转化整形类型\n
*    LQ_TI_INT32_Q29_TO_INT  TI方式INT32的Q29转化整形类型\n
*    LQ_TI_INT32_Q28_TO_INT  TI方式INT32的Q28转化整形类型\n
*    LQ_TI_INT32_Q27_TO_INT  TI方式INT32的Q27转化整形类型\n
*    LQ_TI_INT32_Q26_TO_INT  TI方式INT32的Q26转化整形类型\n
*    LQ_TI_INT32_Q25_TO_INT  TI方式INT32的Q25转化整形类型\n
*    LQ_TI_INT32_Q24_TO_INT  TI方式INT32的Q24转化整形类型\n
*    LQ_TI_INT32_Q23_TO_INT  TI方式INT32的Q23转化整形类型\n
*    LQ_TI_INT32_Q22_TO_INT  TI方式INT32的Q22转化整形类型\n
*    LQ_TI_INT32_Q21_TO_INT  TI方式INT32的Q21转化整形类型\n
*    LQ_TI_INT32_Q20_TO_INT  TI方式INT32的Q20转化整形类型\n
*    LQ_TI_INT32_Q19_TO_INT  TI方式INT32的Q19转化整形类型\n
*    LQ_TI_INT32_Q18_TO_INT  TI方式INT32的Q18转化整形类型\n
*    LQ_TI_INT32_Q17_TO_INT  TI方式INT32的Q17转化整形类型\n
*    LQ_TI_INT32_Q16_TO_INT  TI方式INT32的Q16转化整形类型\n
*    LQ_TI_INT32_Q15_TO_INT  TI方式INT32的Q15转化整形类型\n
*    LQ_TI_INT32_Q14_TO_INT  TI方式INT32的Q14转化整形类型\n
*    LQ_TI_INT32_Q13_TO_INT  TI方式INT32的Q13转化整形类型\n
*    LQ_TI_INT32_Q12_TO_INT  TI方式INT32的Q12转化整形类型\n
*    LQ_TI_INT32_Q11_TO_INT  TI方式INT32的Q11转化整形类型\n
*    LQ_TI_INT32_Q10_TO_INT  TI方式INT32的Q10转化整形类型\n
*    LQ_TI_INT32_Q9_TO_INT  TI方式INT32的Q9转化整形类型\n
*    LQ_TI_INT32_Q8_TO_INT  TI方式INT32的Q8转化整形类型\n
*    LQ_TI_INT32_Q7_TO_INT  TI方式INT32的Q7转化整形类型\n
*    LQ_TI_INT32_Q6_TO_INT  TI方式INT32的Q6转化整形类型\n
*    LQ_TI_INT32_Q5_TO_INT  TI方式INT32的Q5转化整形类型\n
*    LQ_TI_INT32_Q4_TO_INT  TI方式INT32的Q4转化整形类型\n
*    LQ_TI_INT32_Q3_TO_INT  TI方式INT32的Q3转化整形类型\n
*    LQ_TI_INT32_Q2_TO_INT  TI方式INT32的Q2转化整形类型\n
*    LQ_TI_INT32_Q1_TO_INT  TI方式INT32的Q1转化整形类型\n
*/
LQ_INLINE LQ_INT32_Q7 LQ_TI_INT32_Q7_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error){
    return (LQ_INT32_Q7)(((LQ_I_32BIT)A + (((LQ_I_32BIT)A < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 7) - 1u) : 0)) >> 7);
}
/**@brief (TI方法)INT32类型Q6格式转整形
* @details 采用估算位+指数位+符号位三位结合
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为整形数
* @code*    LQ_TI_INT32_Q6_TO_INT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_INT32_Q31_TO_INT  TI方式INT32的Q31转化整形类型\n
*    LQ_TI_INT32_Q30_TO_INT  TI方式INT32的Q30转化整形类型\n
*    LQ_TI_INT32_Q29_TO_INT  TI方式INT32的Q29转化整形类型\n
*    LQ_TI_INT32_Q28_TO_INT  TI方式INT32的Q28转化整形类型\n
*    LQ_TI_INT32_Q27_TO_INT  TI方式INT32的Q27转化整形类型\n
*    LQ_TI_INT32_Q26_TO_INT  TI方式INT32的Q26转化整形类型\n
*    LQ_TI_INT32_Q25_TO_INT  TI方式INT32的Q25转化整形类型\n
*    LQ_TI_INT32_Q24_TO_INT  TI方式INT32的Q24转化整形类型\n
*    LQ_TI_INT32_Q23_TO_INT  TI方式INT32的Q23转化整形类型\n
*    LQ_TI_INT32_Q22_TO_INT  TI方式INT32的Q22转化整形类型\n
*    LQ_TI_INT32_Q21_TO_INT  TI方式INT32的Q21转化整形类型\n
*    LQ_TI_INT32_Q20_TO_INT  TI方式INT32的Q20转化整形类型\n
*    LQ_TI_INT32_Q19_TO_INT  TI方式INT32的Q19转化整形类型\n
*    LQ_TI_INT32_Q18_TO_INT  TI方式INT32的Q18转化整形类型\n
*    LQ_TI_INT32_Q17_TO_INT  TI方式INT32的Q17转化整形类型\n
*    LQ_TI_INT32_Q16_TO_INT  TI方式INT32的Q16转化整形类型\n
*    LQ_TI_INT32_Q15_TO_INT  TI方式INT32的Q15转化整形类型\n
*    LQ_TI_INT32_Q14_TO_INT  TI方式INT32的Q14转化整形类型\n
*    LQ_TI_INT32_Q13_TO_INT  TI方式INT32的Q13转化整形类型\n
*    LQ_TI_INT32_Q12_TO_INT  TI方式INT32的Q12转化整形类型\n
*    LQ_TI_INT32_Q11_TO_INT  TI方式INT32的Q11转化整形类型\n
*    LQ_TI_INT32_Q10_TO_INT  TI方式INT32的Q10转化整形类型\n
*    LQ_TI_INT32_Q9_TO_INT  TI方式INT32的Q9转化整形类型\n
*    LQ_TI_INT32_Q8_TO_INT  TI方式INT32的Q8转化整形类型\n
*    LQ_TI_INT32_Q7_TO_INT  TI方式INT32的Q7转化整形类型\n
*    LQ_TI_INT32_Q6_TO_INT  TI方式INT32的Q6转化整形类型\n
*    LQ_TI_INT32_Q5_TO_INT  TI方式INT32的Q5转化整形类型\n
*    LQ_TI_INT32_Q4_TO_INT  TI方式INT32的Q4转化整形类型\n
*    LQ_TI_INT32_Q3_TO_INT  TI方式INT32的Q3转化整形类型\n
*    LQ_TI_INT32_Q2_TO_INT  TI方式INT32的Q2转化整形类型\n
*    LQ_TI_INT32_Q1_TO_INT  TI方式INT32的Q1转化整形类型\n
*/
LQ_INLINE LQ_INT32_Q6 LQ_TI_INT32_Q6_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error){
    return (LQ_INT32_Q6)(((LQ_I_32BIT)A + (((LQ_I_32BIT)A < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 6) - 1u) : 0)) >> 6);
}
/**@brief (TI方法)INT32类型Q5格式转整形
* @details 采用估算位+指数位+符号位三位结合
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为整形数
* @code*    LQ_TI_INT32_Q5_TO_INT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_INT32_Q31_TO_INT  TI方式INT32的Q31转化整形类型\n
*    LQ_TI_INT32_Q30_TO_INT  TI方式INT32的Q30转化整形类型\n
*    LQ_TI_INT32_Q29_TO_INT  TI方式INT32的Q29转化整形类型\n
*    LQ_TI_INT32_Q28_TO_INT  TI方式INT32的Q28转化整形类型\n
*    LQ_TI_INT32_Q27_TO_INT  TI方式INT32的Q27转化整形类型\n
*    LQ_TI_INT32_Q26_TO_INT  TI方式INT32的Q26转化整形类型\n
*    LQ_TI_INT32_Q25_TO_INT  TI方式INT32的Q25转化整形类型\n
*    LQ_TI_INT32_Q24_TO_INT  TI方式INT32的Q24转化整形类型\n
*    LQ_TI_INT32_Q23_TO_INT  TI方式INT32的Q23转化整形类型\n
*    LQ_TI_INT32_Q22_TO_INT  TI方式INT32的Q22转化整形类型\n
*    LQ_TI_INT32_Q21_TO_INT  TI方式INT32的Q21转化整形类型\n
*    LQ_TI_INT32_Q20_TO_INT  TI方式INT32的Q20转化整形类型\n
*    LQ_TI_INT32_Q19_TO_INT  TI方式INT32的Q19转化整形类型\n
*    LQ_TI_INT32_Q18_TO_INT  TI方式INT32的Q18转化整形类型\n
*    LQ_TI_INT32_Q17_TO_INT  TI方式INT32的Q17转化整形类型\n
*    LQ_TI_INT32_Q16_TO_INT  TI方式INT32的Q16转化整形类型\n
*    LQ_TI_INT32_Q15_TO_INT  TI方式INT32的Q15转化整形类型\n
*    LQ_TI_INT32_Q14_TO_INT  TI方式INT32的Q14转化整形类型\n
*    LQ_TI_INT32_Q13_TO_INT  TI方式INT32的Q13转化整形类型\n
*    LQ_TI_INT32_Q12_TO_INT  TI方式INT32的Q12转化整形类型\n
*    LQ_TI_INT32_Q11_TO_INT  TI方式INT32的Q11转化整形类型\n
*    LQ_TI_INT32_Q10_TO_INT  TI方式INT32的Q10转化整形类型\n
*    LQ_TI_INT32_Q9_TO_INT  TI方式INT32的Q9转化整形类型\n
*    LQ_TI_INT32_Q8_TO_INT  TI方式INT32的Q8转化整形类型\n
*    LQ_TI_INT32_Q7_TO_INT  TI方式INT32的Q7转化整形类型\n
*    LQ_TI_INT32_Q6_TO_INT  TI方式INT32的Q6转化整形类型\n
*    LQ_TI_INT32_Q5_TO_INT  TI方式INT32的Q5转化整形类型\n
*    LQ_TI_INT32_Q4_TO_INT  TI方式INT32的Q4转化整形类型\n
*    LQ_TI_INT32_Q3_TO_INT  TI方式INT32的Q3转化整形类型\n
*    LQ_TI_INT32_Q2_TO_INT  TI方式INT32的Q2转化整形类型\n
*    LQ_TI_INT32_Q1_TO_INT  TI方式INT32的Q1转化整形类型\n
*/
LQ_INLINE LQ_INT32_Q5 LQ_TI_INT32_Q5_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error){
    return (LQ_INT32_Q5)(((LQ_I_32BIT)A + (((LQ_I_32BIT)A < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 5) - 1u) : 0)) >> 5);
}
/**@brief (TI方法)INT32类型Q4格式转整形
* @details 采用估算位+指数位+符号位三位结合
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为整形数
* @code*    LQ_TI_INT32_Q4_TO_INT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_INT32_Q31_TO_INT  TI方式INT32的Q31转化整形类型\n
*    LQ_TI_INT32_Q30_TO_INT  TI方式INT32的Q30转化整形类型\n
*    LQ_TI_INT32_Q29_TO_INT  TI方式INT32的Q29转化整形类型\n
*    LQ_TI_INT32_Q28_TO_INT  TI方式INT32的Q28转化整形类型\n
*    LQ_TI_INT32_Q27_TO_INT  TI方式INT32的Q27转化整形类型\n
*    LQ_TI_INT32_Q26_TO_INT  TI方式INT32的Q26转化整形类型\n
*    LQ_TI_INT32_Q25_TO_INT  TI方式INT32的Q25转化整形类型\n
*    LQ_TI_INT32_Q24_TO_INT  TI方式INT32的Q24转化整形类型\n
*    LQ_TI_INT32_Q23_TO_INT  TI方式INT32的Q23转化整形类型\n
*    LQ_TI_INT32_Q22_TO_INT  TI方式INT32的Q22转化整形类型\n
*    LQ_TI_INT32_Q21_TO_INT  TI方式INT32的Q21转化整形类型\n
*    LQ_TI_INT32_Q20_TO_INT  TI方式INT32的Q20转化整形类型\n
*    LQ_TI_INT32_Q19_TO_INT  TI方式INT32的Q19转化整形类型\n
*    LQ_TI_INT32_Q18_TO_INT  TI方式INT32的Q18转化整形类型\n
*    LQ_TI_INT32_Q17_TO_INT  TI方式INT32的Q17转化整形类型\n
*    LQ_TI_INT32_Q16_TO_INT  TI方式INT32的Q16转化整形类型\n
*    LQ_TI_INT32_Q15_TO_INT  TI方式INT32的Q15转化整形类型\n
*    LQ_TI_INT32_Q14_TO_INT  TI方式INT32的Q14转化整形类型\n
*    LQ_TI_INT32_Q13_TO_INT  TI方式INT32的Q13转化整形类型\n
*    LQ_TI_INT32_Q12_TO_INT  TI方式INT32的Q12转化整形类型\n
*    LQ_TI_INT32_Q11_TO_INT  TI方式INT32的Q11转化整形类型\n
*    LQ_TI_INT32_Q10_TO_INT  TI方式INT32的Q10转化整形类型\n
*    LQ_TI_INT32_Q9_TO_INT  TI方式INT32的Q9转化整形类型\n
*    LQ_TI_INT32_Q8_TO_INT  TI方式INT32的Q8转化整形类型\n
*    LQ_TI_INT32_Q7_TO_INT  TI方式INT32的Q7转化整形类型\n
*    LQ_TI_INT32_Q6_TO_INT  TI方式INT32的Q6转化整形类型\n
*    LQ_TI_INT32_Q5_TO_INT  TI方式INT32的Q5转化整形类型\n
*    LQ_TI_INT32_Q4_TO_INT  TI方式INT32的Q4转化整形类型\n
*    LQ_TI_INT32_Q3_TO_INT  TI方式INT32的Q3转化整形类型\n
*    LQ_TI_INT32_Q2_TO_INT  TI方式INT32的Q2转化整形类型\n
*    LQ_TI_INT32_Q1_TO_INT  TI方式INT32的Q1转化整形类型\n
*/
LQ_INLINE LQ_INT32_Q4 LQ_TI_INT32_Q4_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error){
    return (LQ_INT32_Q4)(((LQ_I_32BIT)A + (((LQ_I_32BIT)A < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 4) - 1u) : 0)) >> 4);
}
/**@brief (TI方法)INT32类型Q3格式转整形
* @details 采用估算位+指数位+符号位三位结合
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为整形数
* @code*    LQ_TI_INT32_Q3_TO_INT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_INT32_Q31_TO_INT  TI方式INT32的Q31转化整形类型\n
*    LQ_TI_INT32_Q30_TO_INT  TI方式INT32的Q30转化整形类型\n
*    LQ_TI_INT32_Q29_TO_INT  TI方式INT32的Q29转化整形类型\n
*    LQ_TI_INT32_Q28_TO_INT  TI方式INT32的Q28转化整形类型\n
*    LQ_TI_INT32_Q27_TO_INT  TI方式INT32的Q27转化整形类型\n
*    LQ_TI_INT32_Q26_TO_INT  TI方式INT32的Q26转化整形类型\n
*    LQ_TI_INT32_Q25_TO_INT  TI方式INT32的Q25转化整形类型\n
*    LQ_TI_INT32_Q24_TO_INT  TI方式INT32的Q24转化整形类型\n
*    LQ_TI_INT32_Q23_TO_INT  TI方式INT32的Q23转化整形类型\n
*    LQ_TI_INT32_Q22_TO_INT  TI方式INT32的Q22转化整形类型\n
*    LQ_TI_INT32_Q21_TO_INT  TI方式INT32的Q21转化整形类型\n
*    LQ_TI_INT32_Q20_TO_INT  TI方式INT32的Q20转化整形类型\n
*    LQ_TI_INT32_Q19_TO_INT  TI方式INT32的Q19转化整形类型\n
*    LQ_TI_INT32_Q18_TO_INT  TI方式INT32的Q18转化整形类型\n
*    LQ_TI_INT32_Q17_TO_INT  TI方式INT32的Q17转化整形类型\n
*    LQ_TI_INT32_Q16_TO_INT  TI方式INT32的Q16转化整形类型\n
*    LQ_TI_INT32_Q15_TO_INT  TI方式INT32的Q15转化整形类型\n
*    LQ_TI_INT32_Q14_TO_INT  TI方式INT32的Q14转化整形类型\n
*    LQ_TI_INT32_Q13_TO_INT  TI方式INT32的Q13转化整形类型\n
*    LQ_TI_INT32_Q12_TO_INT  TI方式INT32的Q12转化整形类型\n
*    LQ_TI_INT32_Q11_TO_INT  TI方式INT32的Q11转化整形类型\n
*    LQ_TI_INT32_Q10_TO_INT  TI方式INT32的Q10转化整形类型\n
*    LQ_TI_INT32_Q9_TO_INT  TI方式INT32的Q9转化整形类型\n
*    LQ_TI_INT32_Q8_TO_INT  TI方式INT32的Q8转化整形类型\n
*    LQ_TI_INT32_Q7_TO_INT  TI方式INT32的Q7转化整形类型\n
*    LQ_TI_INT32_Q6_TO_INT  TI方式INT32的Q6转化整形类型\n
*    LQ_TI_INT32_Q5_TO_INT  TI方式INT32的Q5转化整形类型\n
*    LQ_TI_INT32_Q4_TO_INT  TI方式INT32的Q4转化整形类型\n
*    LQ_TI_INT32_Q3_TO_INT  TI方式INT32的Q3转化整形类型\n
*    LQ_TI_INT32_Q2_TO_INT  TI方式INT32的Q2转化整形类型\n
*    LQ_TI_INT32_Q1_TO_INT  TI方式INT32的Q1转化整形类型\n
*/
LQ_INLINE LQ_INT32_Q3 LQ_TI_INT32_Q3_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error){
    return (LQ_INT32_Q3)(((LQ_I_32BIT)A + (((LQ_I_32BIT)A < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 3) - 1u) : 0)) >> 3);
}
/**@brief (TI方法)INT32类型Q2格式转整形
* @details 采用估算位+指数位+符号位三位结合
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为整形数
* @code*    LQ_TI_INT32_Q2_TO_INT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_INT32_Q31_TO_INT  TI方式INT32的Q31转化整形类型\n
*    LQ_TI_INT32_Q30_TO_INT  TI方式INT32的Q30转化整形类型\n
*    LQ_TI_INT32_Q29_TO_INT  TI方式INT32的Q29转化整形类型\n
*    LQ_TI_INT32_Q28_TO_INT  TI方式INT32的Q28转化整形类型\n
*    LQ_TI_INT32_Q27_TO_INT  TI方式INT32的Q27转化整形类型\n
*    LQ_TI_INT32_Q26_TO_INT  TI方式INT32的Q26转化整形类型\n
*    LQ_TI_INT32_Q25_TO_INT  TI方式INT32的Q25转化整形类型\n
*    LQ_TI_INT32_Q24_TO_INT  TI方式INT32的Q24转化整形类型\n
*    LQ_TI_INT32_Q23_TO_INT  TI方式INT32的Q23转化整形类型\n
*    LQ_TI_INT32_Q22_TO_INT  TI方式INT32的Q22转化整形类型\n
*    LQ_TI_INT32_Q21_TO_INT  TI方式INT32的Q21转化整形类型\n
*    LQ_TI_INT32_Q20_TO_INT  TI方式INT32的Q20转化整形类型\n
*    LQ_TI_INT32_Q19_TO_INT  TI方式INT32的Q19转化整形类型\n
*    LQ_TI_INT32_Q18_TO_INT  TI方式INT32的Q18转化整形类型\n
*    LQ_TI_INT32_Q17_TO_INT  TI方式INT32的Q17转化整形类型\n
*    LQ_TI_INT32_Q16_TO_INT  TI方式INT32的Q16转化整形类型\n
*    LQ_TI_INT32_Q15_TO_INT  TI方式INT32的Q15转化整形类型\n
*    LQ_TI_INT32_Q14_TO_INT  TI方式INT32的Q14转化整形类型\n
*    LQ_TI_INT32_Q13_TO_INT  TI方式INT32的Q13转化整形类型\n
*    LQ_TI_INT32_Q12_TO_INT  TI方式INT32的Q12转化整形类型\n
*    LQ_TI_INT32_Q11_TO_INT  TI方式INT32的Q11转化整形类型\n
*    LQ_TI_INT32_Q10_TO_INT  TI方式INT32的Q10转化整形类型\n
*    LQ_TI_INT32_Q9_TO_INT  TI方式INT32的Q9转化整形类型\n
*    LQ_TI_INT32_Q8_TO_INT  TI方式INT32的Q8转化整形类型\n
*    LQ_TI_INT32_Q7_TO_INT  TI方式INT32的Q7转化整形类型\n
*    LQ_TI_INT32_Q6_TO_INT  TI方式INT32的Q6转化整形类型\n
*    LQ_TI_INT32_Q5_TO_INT  TI方式INT32的Q5转化整形类型\n
*    LQ_TI_INT32_Q4_TO_INT  TI方式INT32的Q4转化整形类型\n
*    LQ_TI_INT32_Q3_TO_INT  TI方式INT32的Q3转化整形类型\n
*    LQ_TI_INT32_Q2_TO_INT  TI方式INT32的Q2转化整形类型\n
*    LQ_TI_INT32_Q1_TO_INT  TI方式INT32的Q1转化整形类型\n
*/
LQ_INLINE LQ_INT32_Q2 LQ_TI_INT32_Q2_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error){
    return (LQ_INT32_Q2)(((LQ_I_32BIT)A + (((LQ_I_32BIT)A < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 2) - 1u) : 0)) >> 2);
}
/**@brief (TI方法)INT32类型Q1格式转整形
* @details 采用估算位+指数位+符号位三位结合
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为整形数
* @code*    LQ_TI_INT32_Q1_TO_INT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_INT32_Q31_TO_INT  TI方式INT32的Q31转化整形类型\n
*    LQ_TI_INT32_Q30_TO_INT  TI方式INT32的Q30转化整形类型\n
*    LQ_TI_INT32_Q29_TO_INT  TI方式INT32的Q29转化整形类型\n
*    LQ_TI_INT32_Q28_TO_INT  TI方式INT32的Q28转化整形类型\n
*    LQ_TI_INT32_Q27_TO_INT  TI方式INT32的Q27转化整形类型\n
*    LQ_TI_INT32_Q26_TO_INT  TI方式INT32的Q26转化整形类型\n
*    LQ_TI_INT32_Q25_TO_INT  TI方式INT32的Q25转化整形类型\n
*    LQ_TI_INT32_Q24_TO_INT  TI方式INT32的Q24转化整形类型\n
*    LQ_TI_INT32_Q23_TO_INT  TI方式INT32的Q23转化整形类型\n
*    LQ_TI_INT32_Q22_TO_INT  TI方式INT32的Q22转化整形类型\n
*    LQ_TI_INT32_Q21_TO_INT  TI方式INT32的Q21转化整形类型\n
*    LQ_TI_INT32_Q20_TO_INT  TI方式INT32的Q20转化整形类型\n
*    LQ_TI_INT32_Q19_TO_INT  TI方式INT32的Q19转化整形类型\n
*    LQ_TI_INT32_Q18_TO_INT  TI方式INT32的Q18转化整形类型\n
*    LQ_TI_INT32_Q17_TO_INT  TI方式INT32的Q17转化整形类型\n
*    LQ_TI_INT32_Q16_TO_INT  TI方式INT32的Q16转化整形类型\n
*    LQ_TI_INT32_Q15_TO_INT  TI方式INT32的Q15转化整形类型\n
*    LQ_TI_INT32_Q14_TO_INT  TI方式INT32的Q14转化整形类型\n
*    LQ_TI_INT32_Q13_TO_INT  TI方式INT32的Q13转化整形类型\n
*    LQ_TI_INT32_Q12_TO_INT  TI方式INT32的Q12转化整形类型\n
*    LQ_TI_INT32_Q11_TO_INT  TI方式INT32的Q11转化整形类型\n
*    LQ_TI_INT32_Q10_TO_INT  TI方式INT32的Q10转化整形类型\n
*    LQ_TI_INT32_Q9_TO_INT  TI方式INT32的Q9转化整形类型\n
*    LQ_TI_INT32_Q8_TO_INT  TI方式INT32的Q8转化整形类型\n
*    LQ_TI_INT32_Q7_TO_INT  TI方式INT32的Q7转化整形类型\n
*    LQ_TI_INT32_Q6_TO_INT  TI方式INT32的Q6转化整形类型\n
*    LQ_TI_INT32_Q5_TO_INT  TI方式INT32的Q5转化整形类型\n
*    LQ_TI_INT32_Q4_TO_INT  TI方式INT32的Q4转化整形类型\n
*    LQ_TI_INT32_Q3_TO_INT  TI方式INT32的Q3转化整形类型\n
*    LQ_TI_INT32_Q2_TO_INT  TI方式INT32的Q2转化整形类型\n
*    LQ_TI_INT32_Q1_TO_INT  TI方式INT32的Q1转化整形类型\n
*/
LQ_INLINE LQ_INT32_Q1 LQ_TI_INT32_Q1_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error){
    return (LQ_INT32_Q1)(((LQ_I_32BIT)A + (((LQ_I_32BIT)A < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 1) - 1u) : 0)) >> 1);
}
/**@brief (TI方法)UINT32类型UQ32格式转整形
* @details 采用估算位+指数位+符号位三位结合
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    整形
* @par       将Q格式转化为整形
* @code*    LQ_TI_UINT32_UQ32_TO_INT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_UINT32_UQ32_TO_INT  TI方式UINT32的UQ32转化整形类型\n
*  LQ_TI_UINT32_UQ31_TO_INT  TI方式UINT32的UQ31转化整形类型\n
*  LQ_TI_UINT32_UQ30_TO_INT  TI方式UINT32的UQ30转化整形类型\n
*  LQ_TI_UINT32_UQ29_TO_INT  TI方式UINT32的UQ29转化整形类型\n
*  LQ_TI_UINT32_UQ28_TO_INT  TI方式UINT32的UQ28转化整形类型\n
*  LQ_TI_UINT32_UQ27_TO_INT  TI方式UINT32的UQ27转化整形类型\n
*  LQ_TI_UINT32_UQ26_TO_INT  TI方式UINT32的UQ26转化整形类型\n
*  LQ_TI_UINT32_UQ25_TO_INT  TI方式UINT32的UQ25转化整形类型\n
*  LQ_TI_UINT32_UQ24_TO_INT  TI方式UINT32的UQ24转化整形类型\n
*  LQ_TI_UINT32_UQ23_TO_INT  TI方式UINT32的UQ23转化整形类型\n
*  LQ_TI_UINT32_UQ22_TO_INT  TI方式UINT32的UQ22转化整形类型\n
*  LQ_TI_UINT32_UQ21_TO_INT  TI方式UINT32的UQ21转化整形类型\n
*  LQ_TI_UINT32_UQ20_TO_INT  TI方式UINT32的UQ20转化整形类型\n
*  LQ_TI_UINT32_UQ19_TO_INT  TI方式UINT32的UQ19转化整形类型\n
*  LQ_TI_UINT32_UQ18_TO_INT  TI方式UINT32的UQ18转化整形类型\n
*  LQ_TI_UINT32_UQ17_TO_INT  TI方式UINT32的UQ17转化整形类型\n
*  LQ_TI_UINT32_UQ16_TO_INT  TI方式UINT32的UQ16转化整形类型\n
*  LQ_TI_UINT32_UQ15_TO_INT  TI方式UINT32的UQ15转化整形类型\n
*  LQ_TI_UINT32_UQ14_TO_INT  TI方式UINT32的UQ14转化整形类型\n
*  LQ_TI_UINT32_UQ13_TO_INT  TI方式UINT32的UQ13转化整形类型\n
*  LQ_TI_UINT32_UQ12_TO_INT  TI方式UINT32的UQ12转化整形类型\n
*  LQ_TI_UINT32_UQ11_TO_INT  TI方式UINT32的UQ11转化整形类型\n
*  LQ_TI_UINT32_UQ10_TO_INT  TI方式UINT32的UQ10转化整形类型\n
*  LQ_TI_UINT32_UQ9_TO_INT  TI方式UINT32的UQ9转化整形类型\n
*  LQ_TI_UINT32_UQ8_TO_INT  TI方式UINT32的UQ8转化整形类型\n
*  LQ_TI_UINT32_UQ7_TO_INT  TI方式UINT32的UQ7转化整形类型\n
*  LQ_TI_UINT32_UQ6_TO_INT  TI方式UINT32的UQ6转化整形类型\n
*  LQ_TI_UINT32_UQ5_TO_INT  TI方式UINT32的UQ5转化整形类型\n
*  LQ_TI_UINT32_UQ4_TO_INT  TI方式UINT32的UQ4转化整形类型\n
*  LQ_TI_UINT32_UQ3_TO_INT  TI方式UINT32的UQ3转化整形类型\n
*  LQ_TI_UINT32_UQ2_TO_INT  TI方式UINT32的UQ2转化整形类型\n
*  LQ_TI_UINT32_UQ1_TO_INT  TI方式UINT32的UQ1转化整形类型\n
*/
LQ_INLINE LQ_UINT32_UQ32 LQ_TI_UINT32_UQ32_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error){
    return (LQ_UINT32_UQ32)0;
}
/**@brief (TI方法)UINT32类型UQ31格式转整形
* @details 采用估算位+指数位+符号位三位结合
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    整形
* @par       将Q格式转化为整形
* @code*    LQ_TI_UINT32_UQ31_TO_INT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_UINT32_UQ32_TO_INT  TI方式UINT32的UQ32转化整形类型\n
*  LQ_TI_UINT32_UQ31_TO_INT  TI方式UINT32的UQ31转化整形类型\n
*  LQ_TI_UINT32_UQ30_TO_INT  TI方式UINT32的UQ30转化整形类型\n
*  LQ_TI_UINT32_UQ29_TO_INT  TI方式UINT32的UQ29转化整形类型\n
*  LQ_TI_UINT32_UQ28_TO_INT  TI方式UINT32的UQ28转化整形类型\n
*  LQ_TI_UINT32_UQ27_TO_INT  TI方式UINT32的UQ27转化整形类型\n
*  LQ_TI_UINT32_UQ26_TO_INT  TI方式UINT32的UQ26转化整形类型\n
*  LQ_TI_UINT32_UQ25_TO_INT  TI方式UINT32的UQ25转化整形类型\n
*  LQ_TI_UINT32_UQ24_TO_INT  TI方式UINT32的UQ24转化整形类型\n
*  LQ_TI_UINT32_UQ23_TO_INT  TI方式UINT32的UQ23转化整形类型\n
*  LQ_TI_UINT32_UQ22_TO_INT  TI方式UINT32的UQ22转化整形类型\n
*  LQ_TI_UINT32_UQ21_TO_INT  TI方式UINT32的UQ21转化整形类型\n
*  LQ_TI_UINT32_UQ20_TO_INT  TI方式UINT32的UQ20转化整形类型\n
*  LQ_TI_UINT32_UQ19_TO_INT  TI方式UINT32的UQ19转化整形类型\n
*  LQ_TI_UINT32_UQ18_TO_INT  TI方式UINT32的UQ18转化整形类型\n
*  LQ_TI_UINT32_UQ17_TO_INT  TI方式UINT32的UQ17转化整形类型\n
*  LQ_TI_UINT32_UQ16_TO_INT  TI方式UINT32的UQ16转化整形类型\n
*  LQ_TI_UINT32_UQ15_TO_INT  TI方式UINT32的UQ15转化整形类型\n
*  LQ_TI_UINT32_UQ14_TO_INT  TI方式UINT32的UQ14转化整形类型\n
*  LQ_TI_UINT32_UQ13_TO_INT  TI方式UINT32的UQ13转化整形类型\n
*  LQ_TI_UINT32_UQ12_TO_INT  TI方式UINT32的UQ12转化整形类型\n
*  LQ_TI_UINT32_UQ11_TO_INT  TI方式UINT32的UQ11转化整形类型\n
*  LQ_TI_UINT32_UQ10_TO_INT  TI方式UINT32的UQ10转化整形类型\n
*  LQ_TI_UINT32_UQ9_TO_INT  TI方式UINT32的UQ9转化整形类型\n
*  LQ_TI_UINT32_UQ8_TO_INT  TI方式UINT32的UQ8转化整形类型\n
*  LQ_TI_UINT32_UQ7_TO_INT  TI方式UINT32的UQ7转化整形类型\n
*  LQ_TI_UINT32_UQ6_TO_INT  TI方式UINT32的UQ6转化整形类型\n
*  LQ_TI_UINT32_UQ5_TO_INT  TI方式UINT32的UQ5转化整形类型\n
*  LQ_TI_UINT32_UQ4_TO_INT  TI方式UINT32的UQ4转化整形类型\n
*  LQ_TI_UINT32_UQ3_TO_INT  TI方式UINT32的UQ3转化整形类型\n
*  LQ_TI_UINT32_UQ2_TO_INT  TI方式UINT32的UQ2转化整形类型\n
*  LQ_TI_UINT32_UQ1_TO_INT  TI方式UINT32的UQ1转化整形类型\n
*/
LQ_INLINE LQ_UINT32_UQ31 LQ_TI_UINT32_UQ31_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error){
    return (LQ_UINT32_UQ31)(((LQ_I_32BIT)A + (((LQ_I_32BIT)A < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 31) - 1u) : 0)) >> 31);
}
/**@brief (TI方法)UINT32类型UQ30格式转整形
* @details 采用估算位+指数位+符号位三位结合
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    整形
* @par       将Q格式转化为整形
* @code*    LQ_TI_UINT32_UQ30_TO_INT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_UINT32_UQ32_TO_INT  TI方式UINT32的UQ32转化整形类型\n
*  LQ_TI_UINT32_UQ31_TO_INT  TI方式UINT32的UQ31转化整形类型\n
*  LQ_TI_UINT32_UQ30_TO_INT  TI方式UINT32的UQ30转化整形类型\n
*  LQ_TI_UINT32_UQ29_TO_INT  TI方式UINT32的UQ29转化整形类型\n
*  LQ_TI_UINT32_UQ28_TO_INT  TI方式UINT32的UQ28转化整形类型\n
*  LQ_TI_UINT32_UQ27_TO_INT  TI方式UINT32的UQ27转化整形类型\n
*  LQ_TI_UINT32_UQ26_TO_INT  TI方式UINT32的UQ26转化整形类型\n
*  LQ_TI_UINT32_UQ25_TO_INT  TI方式UINT32的UQ25转化整形类型\n
*  LQ_TI_UINT32_UQ24_TO_INT  TI方式UINT32的UQ24转化整形类型\n
*  LQ_TI_UINT32_UQ23_TO_INT  TI方式UINT32的UQ23转化整形类型\n
*  LQ_TI_UINT32_UQ22_TO_INT  TI方式UINT32的UQ22转化整形类型\n
*  LQ_TI_UINT32_UQ21_TO_INT  TI方式UINT32的UQ21转化整形类型\n
*  LQ_TI_UINT32_UQ20_TO_INT  TI方式UINT32的UQ20转化整形类型\n
*  LQ_TI_UINT32_UQ19_TO_INT  TI方式UINT32的UQ19转化整形类型\n
*  LQ_TI_UINT32_UQ18_TO_INT  TI方式UINT32的UQ18转化整形类型\n
*  LQ_TI_UINT32_UQ17_TO_INT  TI方式UINT32的UQ17转化整形类型\n
*  LQ_TI_UINT32_UQ16_TO_INT  TI方式UINT32的UQ16转化整形类型\n
*  LQ_TI_UINT32_UQ15_TO_INT  TI方式UINT32的UQ15转化整形类型\n
*  LQ_TI_UINT32_UQ14_TO_INT  TI方式UINT32的UQ14转化整形类型\n
*  LQ_TI_UINT32_UQ13_TO_INT  TI方式UINT32的UQ13转化整形类型\n
*  LQ_TI_UINT32_UQ12_TO_INT  TI方式UINT32的UQ12转化整形类型\n
*  LQ_TI_UINT32_UQ11_TO_INT  TI方式UINT32的UQ11转化整形类型\n
*  LQ_TI_UINT32_UQ10_TO_INT  TI方式UINT32的UQ10转化整形类型\n
*  LQ_TI_UINT32_UQ9_TO_INT  TI方式UINT32的UQ9转化整形类型\n
*  LQ_TI_UINT32_UQ8_TO_INT  TI方式UINT32的UQ8转化整形类型\n
*  LQ_TI_UINT32_UQ7_TO_INT  TI方式UINT32的UQ7转化整形类型\n
*  LQ_TI_UINT32_UQ6_TO_INT  TI方式UINT32的UQ6转化整形类型\n
*  LQ_TI_UINT32_UQ5_TO_INT  TI方式UINT32的UQ5转化整形类型\n
*  LQ_TI_UINT32_UQ4_TO_INT  TI方式UINT32的UQ4转化整形类型\n
*  LQ_TI_UINT32_UQ3_TO_INT  TI方式UINT32的UQ3转化整形类型\n
*  LQ_TI_UINT32_UQ2_TO_INT  TI方式UINT32的UQ2转化整形类型\n
*  LQ_TI_UINT32_UQ1_TO_INT  TI方式UINT32的UQ1转化整形类型\n
*/
LQ_INLINE LQ_UINT32_UQ30 LQ_TI_UINT32_UQ30_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error){
    return (LQ_UINT32_UQ30)(((LQ_I_32BIT)A + (((LQ_I_32BIT)A < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 30) - 1u) : 0)) >> 30);
}
/**@brief (TI方法)UINT32类型UQ29格式转整形
* @details 采用估算位+指数位+符号位三位结合
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    整形
* @par       将Q格式转化为整形
* @code*    LQ_TI_UINT32_UQ29_TO_INT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_UINT32_UQ32_TO_INT  TI方式UINT32的UQ32转化整形类型\n
*  LQ_TI_UINT32_UQ31_TO_INT  TI方式UINT32的UQ31转化整形类型\n
*  LQ_TI_UINT32_UQ30_TO_INT  TI方式UINT32的UQ30转化整形类型\n
*  LQ_TI_UINT32_UQ29_TO_INT  TI方式UINT32的UQ29转化整形类型\n
*  LQ_TI_UINT32_UQ28_TO_INT  TI方式UINT32的UQ28转化整形类型\n
*  LQ_TI_UINT32_UQ27_TO_INT  TI方式UINT32的UQ27转化整形类型\n
*  LQ_TI_UINT32_UQ26_TO_INT  TI方式UINT32的UQ26转化整形类型\n
*  LQ_TI_UINT32_UQ25_TO_INT  TI方式UINT32的UQ25转化整形类型\n
*  LQ_TI_UINT32_UQ24_TO_INT  TI方式UINT32的UQ24转化整形类型\n
*  LQ_TI_UINT32_UQ23_TO_INT  TI方式UINT32的UQ23转化整形类型\n
*  LQ_TI_UINT32_UQ22_TO_INT  TI方式UINT32的UQ22转化整形类型\n
*  LQ_TI_UINT32_UQ21_TO_INT  TI方式UINT32的UQ21转化整形类型\n
*  LQ_TI_UINT32_UQ20_TO_INT  TI方式UINT32的UQ20转化整形类型\n
*  LQ_TI_UINT32_UQ19_TO_INT  TI方式UINT32的UQ19转化整形类型\n
*  LQ_TI_UINT32_UQ18_TO_INT  TI方式UINT32的UQ18转化整形类型\n
*  LQ_TI_UINT32_UQ17_TO_INT  TI方式UINT32的UQ17转化整形类型\n
*  LQ_TI_UINT32_UQ16_TO_INT  TI方式UINT32的UQ16转化整形类型\n
*  LQ_TI_UINT32_UQ15_TO_INT  TI方式UINT32的UQ15转化整形类型\n
*  LQ_TI_UINT32_UQ14_TO_INT  TI方式UINT32的UQ14转化整形类型\n
*  LQ_TI_UINT32_UQ13_TO_INT  TI方式UINT32的UQ13转化整形类型\n
*  LQ_TI_UINT32_UQ12_TO_INT  TI方式UINT32的UQ12转化整形类型\n
*  LQ_TI_UINT32_UQ11_TO_INT  TI方式UINT32的UQ11转化整形类型\n
*  LQ_TI_UINT32_UQ10_TO_INT  TI方式UINT32的UQ10转化整形类型\n
*  LQ_TI_UINT32_UQ9_TO_INT  TI方式UINT32的UQ9转化整形类型\n
*  LQ_TI_UINT32_UQ8_TO_INT  TI方式UINT32的UQ8转化整形类型\n
*  LQ_TI_UINT32_UQ7_TO_INT  TI方式UINT32的UQ7转化整形类型\n
*  LQ_TI_UINT32_UQ6_TO_INT  TI方式UINT32的UQ6转化整形类型\n
*  LQ_TI_UINT32_UQ5_TO_INT  TI方式UINT32的UQ5转化整形类型\n
*  LQ_TI_UINT32_UQ4_TO_INT  TI方式UINT32的UQ4转化整形类型\n
*  LQ_TI_UINT32_UQ3_TO_INT  TI方式UINT32的UQ3转化整形类型\n
*  LQ_TI_UINT32_UQ2_TO_INT  TI方式UINT32的UQ2转化整形类型\n
*  LQ_TI_UINT32_UQ1_TO_INT  TI方式UINT32的UQ1转化整形类型\n
*/
LQ_INLINE LQ_UINT32_UQ29 LQ_TI_UINT32_UQ29_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error){
    return (LQ_UINT32_UQ29)(((LQ_I_32BIT)A + (((LQ_I_32BIT)A < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 29) - 1u) : 0)) >> 29);
}
/**@brief (TI方法)UINT32类型UQ28格式转整形
* @details 采用估算位+指数位+符号位三位结合
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    整形
* @par       将Q格式转化为整形
* @code*    LQ_TI_UINT32_UQ28_TO_INT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_UINT32_UQ32_TO_INT  TI方式UINT32的UQ32转化整形类型\n
*  LQ_TI_UINT32_UQ31_TO_INT  TI方式UINT32的UQ31转化整形类型\n
*  LQ_TI_UINT32_UQ30_TO_INT  TI方式UINT32的UQ30转化整形类型\n
*  LQ_TI_UINT32_UQ29_TO_INT  TI方式UINT32的UQ29转化整形类型\n
*  LQ_TI_UINT32_UQ28_TO_INT  TI方式UINT32的UQ28转化整形类型\n
*  LQ_TI_UINT32_UQ27_TO_INT  TI方式UINT32的UQ27转化整形类型\n
*  LQ_TI_UINT32_UQ26_TO_INT  TI方式UINT32的UQ26转化整形类型\n
*  LQ_TI_UINT32_UQ25_TO_INT  TI方式UINT32的UQ25转化整形类型\n
*  LQ_TI_UINT32_UQ24_TO_INT  TI方式UINT32的UQ24转化整形类型\n
*  LQ_TI_UINT32_UQ23_TO_INT  TI方式UINT32的UQ23转化整形类型\n
*  LQ_TI_UINT32_UQ22_TO_INT  TI方式UINT32的UQ22转化整形类型\n
*  LQ_TI_UINT32_UQ21_TO_INT  TI方式UINT32的UQ21转化整形类型\n
*  LQ_TI_UINT32_UQ20_TO_INT  TI方式UINT32的UQ20转化整形类型\n
*  LQ_TI_UINT32_UQ19_TO_INT  TI方式UINT32的UQ19转化整形类型\n
*  LQ_TI_UINT32_UQ18_TO_INT  TI方式UINT32的UQ18转化整形类型\n
*  LQ_TI_UINT32_UQ17_TO_INT  TI方式UINT32的UQ17转化整形类型\n
*  LQ_TI_UINT32_UQ16_TO_INT  TI方式UINT32的UQ16转化整形类型\n
*  LQ_TI_UINT32_UQ15_TO_INT  TI方式UINT32的UQ15转化整形类型\n
*  LQ_TI_UINT32_UQ14_TO_INT  TI方式UINT32的UQ14转化整形类型\n
*  LQ_TI_UINT32_UQ13_TO_INT  TI方式UINT32的UQ13转化整形类型\n
*  LQ_TI_UINT32_UQ12_TO_INT  TI方式UINT32的UQ12转化整形类型\n
*  LQ_TI_UINT32_UQ11_TO_INT  TI方式UINT32的UQ11转化整形类型\n
*  LQ_TI_UINT32_UQ10_TO_INT  TI方式UINT32的UQ10转化整形类型\n
*  LQ_TI_UINT32_UQ9_TO_INT  TI方式UINT32的UQ9转化整形类型\n
*  LQ_TI_UINT32_UQ8_TO_INT  TI方式UINT32的UQ8转化整形类型\n
*  LQ_TI_UINT32_UQ7_TO_INT  TI方式UINT32的UQ7转化整形类型\n
*  LQ_TI_UINT32_UQ6_TO_INT  TI方式UINT32的UQ6转化整形类型\n
*  LQ_TI_UINT32_UQ5_TO_INT  TI方式UINT32的UQ5转化整形类型\n
*  LQ_TI_UINT32_UQ4_TO_INT  TI方式UINT32的UQ4转化整形类型\n
*  LQ_TI_UINT32_UQ3_TO_INT  TI方式UINT32的UQ3转化整形类型\n
*  LQ_TI_UINT32_UQ2_TO_INT  TI方式UINT32的UQ2转化整形类型\n
*  LQ_TI_UINT32_UQ1_TO_INT  TI方式UINT32的UQ1转化整形类型\n
*/
LQ_INLINE LQ_UINT32_UQ28 LQ_TI_UINT32_UQ28_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error){
    return (LQ_UINT32_UQ28)(((LQ_I_32BIT)A + (((LQ_I_32BIT)A < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 28) - 1u) : 0)) >> 28);
}
/**@brief (TI方法)UINT32类型UQ27格式转整形
* @details 采用估算位+指数位+符号位三位结合
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    整形
* @par       将Q格式转化为整形
* @code*    LQ_TI_UINT32_UQ27_TO_INT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_UINT32_UQ32_TO_INT  TI方式UINT32的UQ32转化整形类型\n
*  LQ_TI_UINT32_UQ31_TO_INT  TI方式UINT32的UQ31转化整形类型\n
*  LQ_TI_UINT32_UQ30_TO_INT  TI方式UINT32的UQ30转化整形类型\n
*  LQ_TI_UINT32_UQ29_TO_INT  TI方式UINT32的UQ29转化整形类型\n
*  LQ_TI_UINT32_UQ28_TO_INT  TI方式UINT32的UQ28转化整形类型\n
*  LQ_TI_UINT32_UQ27_TO_INT  TI方式UINT32的UQ27转化整形类型\n
*  LQ_TI_UINT32_UQ26_TO_INT  TI方式UINT32的UQ26转化整形类型\n
*  LQ_TI_UINT32_UQ25_TO_INT  TI方式UINT32的UQ25转化整形类型\n
*  LQ_TI_UINT32_UQ24_TO_INT  TI方式UINT32的UQ24转化整形类型\n
*  LQ_TI_UINT32_UQ23_TO_INT  TI方式UINT32的UQ23转化整形类型\n
*  LQ_TI_UINT32_UQ22_TO_INT  TI方式UINT32的UQ22转化整形类型\n
*  LQ_TI_UINT32_UQ21_TO_INT  TI方式UINT32的UQ21转化整形类型\n
*  LQ_TI_UINT32_UQ20_TO_INT  TI方式UINT32的UQ20转化整形类型\n
*  LQ_TI_UINT32_UQ19_TO_INT  TI方式UINT32的UQ19转化整形类型\n
*  LQ_TI_UINT32_UQ18_TO_INT  TI方式UINT32的UQ18转化整形类型\n
*  LQ_TI_UINT32_UQ17_TO_INT  TI方式UINT32的UQ17转化整形类型\n
*  LQ_TI_UINT32_UQ16_TO_INT  TI方式UINT32的UQ16转化整形类型\n
*  LQ_TI_UINT32_UQ15_TO_INT  TI方式UINT32的UQ15转化整形类型\n
*  LQ_TI_UINT32_UQ14_TO_INT  TI方式UINT32的UQ14转化整形类型\n
*  LQ_TI_UINT32_UQ13_TO_INT  TI方式UINT32的UQ13转化整形类型\n
*  LQ_TI_UINT32_UQ12_TO_INT  TI方式UINT32的UQ12转化整形类型\n
*  LQ_TI_UINT32_UQ11_TO_INT  TI方式UINT32的UQ11转化整形类型\n
*  LQ_TI_UINT32_UQ10_TO_INT  TI方式UINT32的UQ10转化整形类型\n
*  LQ_TI_UINT32_UQ9_TO_INT  TI方式UINT32的UQ9转化整形类型\n
*  LQ_TI_UINT32_UQ8_TO_INT  TI方式UINT32的UQ8转化整形类型\n
*  LQ_TI_UINT32_UQ7_TO_INT  TI方式UINT32的UQ7转化整形类型\n
*  LQ_TI_UINT32_UQ6_TO_INT  TI方式UINT32的UQ6转化整形类型\n
*  LQ_TI_UINT32_UQ5_TO_INT  TI方式UINT32的UQ5转化整形类型\n
*  LQ_TI_UINT32_UQ4_TO_INT  TI方式UINT32的UQ4转化整形类型\n
*  LQ_TI_UINT32_UQ3_TO_INT  TI方式UINT32的UQ3转化整形类型\n
*  LQ_TI_UINT32_UQ2_TO_INT  TI方式UINT32的UQ2转化整形类型\n
*  LQ_TI_UINT32_UQ1_TO_INT  TI方式UINT32的UQ1转化整形类型\n
*/
LQ_INLINE LQ_UINT32_UQ27 LQ_TI_UINT32_UQ27_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error){
    return (LQ_UINT32_UQ27)(((LQ_I_32BIT)A + (((LQ_I_32BIT)A < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 27) - 1u) : 0)) >> 27);
}
/**@brief (TI方法)UINT32类型UQ26格式转整形
* @details 采用估算位+指数位+符号位三位结合
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    整形
* @par       将Q格式转化为整形
* @code*    LQ_TI_UINT32_UQ26_TO_INT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_UINT32_UQ32_TO_INT  TI方式UINT32的UQ32转化整形类型\n
*  LQ_TI_UINT32_UQ31_TO_INT  TI方式UINT32的UQ31转化整形类型\n
*  LQ_TI_UINT32_UQ30_TO_INT  TI方式UINT32的UQ30转化整形类型\n
*  LQ_TI_UINT32_UQ29_TO_INT  TI方式UINT32的UQ29转化整形类型\n
*  LQ_TI_UINT32_UQ28_TO_INT  TI方式UINT32的UQ28转化整形类型\n
*  LQ_TI_UINT32_UQ27_TO_INT  TI方式UINT32的UQ27转化整形类型\n
*  LQ_TI_UINT32_UQ26_TO_INT  TI方式UINT32的UQ26转化整形类型\n
*  LQ_TI_UINT32_UQ25_TO_INT  TI方式UINT32的UQ25转化整形类型\n
*  LQ_TI_UINT32_UQ24_TO_INT  TI方式UINT32的UQ24转化整形类型\n
*  LQ_TI_UINT32_UQ23_TO_INT  TI方式UINT32的UQ23转化整形类型\n
*  LQ_TI_UINT32_UQ22_TO_INT  TI方式UINT32的UQ22转化整形类型\n
*  LQ_TI_UINT32_UQ21_TO_INT  TI方式UINT32的UQ21转化整形类型\n
*  LQ_TI_UINT32_UQ20_TO_INT  TI方式UINT32的UQ20转化整形类型\n
*  LQ_TI_UINT32_UQ19_TO_INT  TI方式UINT32的UQ19转化整形类型\n
*  LQ_TI_UINT32_UQ18_TO_INT  TI方式UINT32的UQ18转化整形类型\n
*  LQ_TI_UINT32_UQ17_TO_INT  TI方式UINT32的UQ17转化整形类型\n
*  LQ_TI_UINT32_UQ16_TO_INT  TI方式UINT32的UQ16转化整形类型\n
*  LQ_TI_UINT32_UQ15_TO_INT  TI方式UINT32的UQ15转化整形类型\n
*  LQ_TI_UINT32_UQ14_TO_INT  TI方式UINT32的UQ14转化整形类型\n
*  LQ_TI_UINT32_UQ13_TO_INT  TI方式UINT32的UQ13转化整形类型\n
*  LQ_TI_UINT32_UQ12_TO_INT  TI方式UINT32的UQ12转化整形类型\n
*  LQ_TI_UINT32_UQ11_TO_INT  TI方式UINT32的UQ11转化整形类型\n
*  LQ_TI_UINT32_UQ10_TO_INT  TI方式UINT32的UQ10转化整形类型\n
*  LQ_TI_UINT32_UQ9_TO_INT  TI方式UINT32的UQ9转化整形类型\n
*  LQ_TI_UINT32_UQ8_TO_INT  TI方式UINT32的UQ8转化整形类型\n
*  LQ_TI_UINT32_UQ7_TO_INT  TI方式UINT32的UQ7转化整形类型\n
*  LQ_TI_UINT32_UQ6_TO_INT  TI方式UINT32的UQ6转化整形类型\n
*  LQ_TI_UINT32_UQ5_TO_INT  TI方式UINT32的UQ5转化整形类型\n
*  LQ_TI_UINT32_UQ4_TO_INT  TI方式UINT32的UQ4转化整形类型\n
*  LQ_TI_UINT32_UQ3_TO_INT  TI方式UINT32的UQ3转化整形类型\n
*  LQ_TI_UINT32_UQ2_TO_INT  TI方式UINT32的UQ2转化整形类型\n
*  LQ_TI_UINT32_UQ1_TO_INT  TI方式UINT32的UQ1转化整形类型\n
*/
LQ_INLINE LQ_UINT32_UQ26 LQ_TI_UINT32_UQ26_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error){
    return (LQ_UINT32_UQ26)(((LQ_I_32BIT)A + (((LQ_I_32BIT)A < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 26) - 1u) : 0)) >> 26);
}
/**@brief (TI方法)UINT32类型UQ25格式转整形
* @details 采用估算位+指数位+符号位三位结合
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    整形
* @par       将Q格式转化为整形
* @code*    LQ_TI_UINT32_UQ25_TO_INT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_UINT32_UQ32_TO_INT  TI方式UINT32的UQ32转化整形类型\n
*  LQ_TI_UINT32_UQ31_TO_INT  TI方式UINT32的UQ31转化整形类型\n
*  LQ_TI_UINT32_UQ30_TO_INT  TI方式UINT32的UQ30转化整形类型\n
*  LQ_TI_UINT32_UQ29_TO_INT  TI方式UINT32的UQ29转化整形类型\n
*  LQ_TI_UINT32_UQ28_TO_INT  TI方式UINT32的UQ28转化整形类型\n
*  LQ_TI_UINT32_UQ27_TO_INT  TI方式UINT32的UQ27转化整形类型\n
*  LQ_TI_UINT32_UQ26_TO_INT  TI方式UINT32的UQ26转化整形类型\n
*  LQ_TI_UINT32_UQ25_TO_INT  TI方式UINT32的UQ25转化整形类型\n
*  LQ_TI_UINT32_UQ24_TO_INT  TI方式UINT32的UQ24转化整形类型\n
*  LQ_TI_UINT32_UQ23_TO_INT  TI方式UINT32的UQ23转化整形类型\n
*  LQ_TI_UINT32_UQ22_TO_INT  TI方式UINT32的UQ22转化整形类型\n
*  LQ_TI_UINT32_UQ21_TO_INT  TI方式UINT32的UQ21转化整形类型\n
*  LQ_TI_UINT32_UQ20_TO_INT  TI方式UINT32的UQ20转化整形类型\n
*  LQ_TI_UINT32_UQ19_TO_INT  TI方式UINT32的UQ19转化整形类型\n
*  LQ_TI_UINT32_UQ18_TO_INT  TI方式UINT32的UQ18转化整形类型\n
*  LQ_TI_UINT32_UQ17_TO_INT  TI方式UINT32的UQ17转化整形类型\n
*  LQ_TI_UINT32_UQ16_TO_INT  TI方式UINT32的UQ16转化整形类型\n
*  LQ_TI_UINT32_UQ15_TO_INT  TI方式UINT32的UQ15转化整形类型\n
*  LQ_TI_UINT32_UQ14_TO_INT  TI方式UINT32的UQ14转化整形类型\n
*  LQ_TI_UINT32_UQ13_TO_INT  TI方式UINT32的UQ13转化整形类型\n
*  LQ_TI_UINT32_UQ12_TO_INT  TI方式UINT32的UQ12转化整形类型\n
*  LQ_TI_UINT32_UQ11_TO_INT  TI方式UINT32的UQ11转化整形类型\n
*  LQ_TI_UINT32_UQ10_TO_INT  TI方式UINT32的UQ10转化整形类型\n
*  LQ_TI_UINT32_UQ9_TO_INT  TI方式UINT32的UQ9转化整形类型\n
*  LQ_TI_UINT32_UQ8_TO_INT  TI方式UINT32的UQ8转化整形类型\n
*  LQ_TI_UINT32_UQ7_TO_INT  TI方式UINT32的UQ7转化整形类型\n
*  LQ_TI_UINT32_UQ6_TO_INT  TI方式UINT32的UQ6转化整形类型\n
*  LQ_TI_UINT32_UQ5_TO_INT  TI方式UINT32的UQ5转化整形类型\n
*  LQ_TI_UINT32_UQ4_TO_INT  TI方式UINT32的UQ4转化整形类型\n
*  LQ_TI_UINT32_UQ3_TO_INT  TI方式UINT32的UQ3转化整形类型\n
*  LQ_TI_UINT32_UQ2_TO_INT  TI方式UINT32的UQ2转化整形类型\n
*  LQ_TI_UINT32_UQ1_TO_INT  TI方式UINT32的UQ1转化整形类型\n
*/
LQ_INLINE LQ_UINT32_UQ25 LQ_TI_UINT32_UQ25_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error){
    return (LQ_UINT32_UQ25)(((LQ_I_32BIT)A + (((LQ_I_32BIT)A < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 25) - 1u) : 0)) >> 25);
}
/**@brief (TI方法)UINT32类型UQ24格式转整形
* @details 采用估算位+指数位+符号位三位结合
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    整形
* @par       将Q格式转化为整形
* @code*    LQ_TI_UINT32_UQ24_TO_INT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_UINT32_UQ32_TO_INT  TI方式UINT32的UQ32转化整形类型\n
*  LQ_TI_UINT32_UQ31_TO_INT  TI方式UINT32的UQ31转化整形类型\n
*  LQ_TI_UINT32_UQ30_TO_INT  TI方式UINT32的UQ30转化整形类型\n
*  LQ_TI_UINT32_UQ29_TO_INT  TI方式UINT32的UQ29转化整形类型\n
*  LQ_TI_UINT32_UQ28_TO_INT  TI方式UINT32的UQ28转化整形类型\n
*  LQ_TI_UINT32_UQ27_TO_INT  TI方式UINT32的UQ27转化整形类型\n
*  LQ_TI_UINT32_UQ26_TO_INT  TI方式UINT32的UQ26转化整形类型\n
*  LQ_TI_UINT32_UQ25_TO_INT  TI方式UINT32的UQ25转化整形类型\n
*  LQ_TI_UINT32_UQ24_TO_INT  TI方式UINT32的UQ24转化整形类型\n
*  LQ_TI_UINT32_UQ23_TO_INT  TI方式UINT32的UQ23转化整形类型\n
*  LQ_TI_UINT32_UQ22_TO_INT  TI方式UINT32的UQ22转化整形类型\n
*  LQ_TI_UINT32_UQ21_TO_INT  TI方式UINT32的UQ21转化整形类型\n
*  LQ_TI_UINT32_UQ20_TO_INT  TI方式UINT32的UQ20转化整形类型\n
*  LQ_TI_UINT32_UQ19_TO_INT  TI方式UINT32的UQ19转化整形类型\n
*  LQ_TI_UINT32_UQ18_TO_INT  TI方式UINT32的UQ18转化整形类型\n
*  LQ_TI_UINT32_UQ17_TO_INT  TI方式UINT32的UQ17转化整形类型\n
*  LQ_TI_UINT32_UQ16_TO_INT  TI方式UINT32的UQ16转化整形类型\n
*  LQ_TI_UINT32_UQ15_TO_INT  TI方式UINT32的UQ15转化整形类型\n
*  LQ_TI_UINT32_UQ14_TO_INT  TI方式UINT32的UQ14转化整形类型\n
*  LQ_TI_UINT32_UQ13_TO_INT  TI方式UINT32的UQ13转化整形类型\n
*  LQ_TI_UINT32_UQ12_TO_INT  TI方式UINT32的UQ12转化整形类型\n
*  LQ_TI_UINT32_UQ11_TO_INT  TI方式UINT32的UQ11转化整形类型\n
*  LQ_TI_UINT32_UQ10_TO_INT  TI方式UINT32的UQ10转化整形类型\n
*  LQ_TI_UINT32_UQ9_TO_INT  TI方式UINT32的UQ9转化整形类型\n
*  LQ_TI_UINT32_UQ8_TO_INT  TI方式UINT32的UQ8转化整形类型\n
*  LQ_TI_UINT32_UQ7_TO_INT  TI方式UINT32的UQ7转化整形类型\n
*  LQ_TI_UINT32_UQ6_TO_INT  TI方式UINT32的UQ6转化整形类型\n
*  LQ_TI_UINT32_UQ5_TO_INT  TI方式UINT32的UQ5转化整形类型\n
*  LQ_TI_UINT32_UQ4_TO_INT  TI方式UINT32的UQ4转化整形类型\n
*  LQ_TI_UINT32_UQ3_TO_INT  TI方式UINT32的UQ3转化整形类型\n
*  LQ_TI_UINT32_UQ2_TO_INT  TI方式UINT32的UQ2转化整形类型\n
*  LQ_TI_UINT32_UQ1_TO_INT  TI方式UINT32的UQ1转化整形类型\n
*/
LQ_INLINE LQ_UINT32_UQ24 LQ_TI_UINT32_UQ24_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error){
    return (LQ_UINT32_UQ24)(((LQ_I_32BIT)A + (((LQ_I_32BIT)A < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 24) - 1u) : 0)) >> 24);
}
/**@brief (TI方法)UINT32类型UQ23格式转整形
* @details 采用估算位+指数位+符号位三位结合
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    整形
* @par       将Q格式转化为整形
* @code*    LQ_TI_UINT32_UQ23_TO_INT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_UINT32_UQ32_TO_INT  TI方式UINT32的UQ32转化整形类型\n
*  LQ_TI_UINT32_UQ31_TO_INT  TI方式UINT32的UQ31转化整形类型\n
*  LQ_TI_UINT32_UQ30_TO_INT  TI方式UINT32的UQ30转化整形类型\n
*  LQ_TI_UINT32_UQ29_TO_INT  TI方式UINT32的UQ29转化整形类型\n
*  LQ_TI_UINT32_UQ28_TO_INT  TI方式UINT32的UQ28转化整形类型\n
*  LQ_TI_UINT32_UQ27_TO_INT  TI方式UINT32的UQ27转化整形类型\n
*  LQ_TI_UINT32_UQ26_TO_INT  TI方式UINT32的UQ26转化整形类型\n
*  LQ_TI_UINT32_UQ25_TO_INT  TI方式UINT32的UQ25转化整形类型\n
*  LQ_TI_UINT32_UQ24_TO_INT  TI方式UINT32的UQ24转化整形类型\n
*  LQ_TI_UINT32_UQ23_TO_INT  TI方式UINT32的UQ23转化整形类型\n
*  LQ_TI_UINT32_UQ22_TO_INT  TI方式UINT32的UQ22转化整形类型\n
*  LQ_TI_UINT32_UQ21_TO_INT  TI方式UINT32的UQ21转化整形类型\n
*  LQ_TI_UINT32_UQ20_TO_INT  TI方式UINT32的UQ20转化整形类型\n
*  LQ_TI_UINT32_UQ19_TO_INT  TI方式UINT32的UQ19转化整形类型\n
*  LQ_TI_UINT32_UQ18_TO_INT  TI方式UINT32的UQ18转化整形类型\n
*  LQ_TI_UINT32_UQ17_TO_INT  TI方式UINT32的UQ17转化整形类型\n
*  LQ_TI_UINT32_UQ16_TO_INT  TI方式UINT32的UQ16转化整形类型\n
*  LQ_TI_UINT32_UQ15_TO_INT  TI方式UINT32的UQ15转化整形类型\n
*  LQ_TI_UINT32_UQ14_TO_INT  TI方式UINT32的UQ14转化整形类型\n
*  LQ_TI_UINT32_UQ13_TO_INT  TI方式UINT32的UQ13转化整形类型\n
*  LQ_TI_UINT32_UQ12_TO_INT  TI方式UINT32的UQ12转化整形类型\n
*  LQ_TI_UINT32_UQ11_TO_INT  TI方式UINT32的UQ11转化整形类型\n
*  LQ_TI_UINT32_UQ10_TO_INT  TI方式UINT32的UQ10转化整形类型\n
*  LQ_TI_UINT32_UQ9_TO_INT  TI方式UINT32的UQ9转化整形类型\n
*  LQ_TI_UINT32_UQ8_TO_INT  TI方式UINT32的UQ8转化整形类型\n
*  LQ_TI_UINT32_UQ7_TO_INT  TI方式UINT32的UQ7转化整形类型\n
*  LQ_TI_UINT32_UQ6_TO_INT  TI方式UINT32的UQ6转化整形类型\n
*  LQ_TI_UINT32_UQ5_TO_INT  TI方式UINT32的UQ5转化整形类型\n
*  LQ_TI_UINT32_UQ4_TO_INT  TI方式UINT32的UQ4转化整形类型\n
*  LQ_TI_UINT32_UQ3_TO_INT  TI方式UINT32的UQ3转化整形类型\n
*  LQ_TI_UINT32_UQ2_TO_INT  TI方式UINT32的UQ2转化整形类型\n
*  LQ_TI_UINT32_UQ1_TO_INT  TI方式UINT32的UQ1转化整形类型\n
*/
LQ_INLINE LQ_UINT32_UQ23 LQ_TI_UINT32_UQ23_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error){
    return (LQ_UINT32_UQ23)(((LQ_I_32BIT)A + (((LQ_I_32BIT)A < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 23) - 1u) : 0)) >> 23);
}
/**@brief (TI方法)UINT32类型UQ22格式转整形
* @details 采用估算位+指数位+符号位三位结合
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    整形
* @par       将Q格式转化为整形
* @code*    LQ_TI_UINT32_UQ22_TO_INT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_UINT32_UQ32_TO_INT  TI方式UINT32的UQ32转化整形类型\n
*  LQ_TI_UINT32_UQ31_TO_INT  TI方式UINT32的UQ31转化整形类型\n
*  LQ_TI_UINT32_UQ30_TO_INT  TI方式UINT32的UQ30转化整形类型\n
*  LQ_TI_UINT32_UQ29_TO_INT  TI方式UINT32的UQ29转化整形类型\n
*  LQ_TI_UINT32_UQ28_TO_INT  TI方式UINT32的UQ28转化整形类型\n
*  LQ_TI_UINT32_UQ27_TO_INT  TI方式UINT32的UQ27转化整形类型\n
*  LQ_TI_UINT32_UQ26_TO_INT  TI方式UINT32的UQ26转化整形类型\n
*  LQ_TI_UINT32_UQ25_TO_INT  TI方式UINT32的UQ25转化整形类型\n
*  LQ_TI_UINT32_UQ24_TO_INT  TI方式UINT32的UQ24转化整形类型\n
*  LQ_TI_UINT32_UQ23_TO_INT  TI方式UINT32的UQ23转化整形类型\n
*  LQ_TI_UINT32_UQ22_TO_INT  TI方式UINT32的UQ22转化整形类型\n
*  LQ_TI_UINT32_UQ21_TO_INT  TI方式UINT32的UQ21转化整形类型\n
*  LQ_TI_UINT32_UQ20_TO_INT  TI方式UINT32的UQ20转化整形类型\n
*  LQ_TI_UINT32_UQ19_TO_INT  TI方式UINT32的UQ19转化整形类型\n
*  LQ_TI_UINT32_UQ18_TO_INT  TI方式UINT32的UQ18转化整形类型\n
*  LQ_TI_UINT32_UQ17_TO_INT  TI方式UINT32的UQ17转化整形类型\n
*  LQ_TI_UINT32_UQ16_TO_INT  TI方式UINT32的UQ16转化整形类型\n
*  LQ_TI_UINT32_UQ15_TO_INT  TI方式UINT32的UQ15转化整形类型\n
*  LQ_TI_UINT32_UQ14_TO_INT  TI方式UINT32的UQ14转化整形类型\n
*  LQ_TI_UINT32_UQ13_TO_INT  TI方式UINT32的UQ13转化整形类型\n
*  LQ_TI_UINT32_UQ12_TO_INT  TI方式UINT32的UQ12转化整形类型\n
*  LQ_TI_UINT32_UQ11_TO_INT  TI方式UINT32的UQ11转化整形类型\n
*  LQ_TI_UINT32_UQ10_TO_INT  TI方式UINT32的UQ10转化整形类型\n
*  LQ_TI_UINT32_UQ9_TO_INT  TI方式UINT32的UQ9转化整形类型\n
*  LQ_TI_UINT32_UQ8_TO_INT  TI方式UINT32的UQ8转化整形类型\n
*  LQ_TI_UINT32_UQ7_TO_INT  TI方式UINT32的UQ7转化整形类型\n
*  LQ_TI_UINT32_UQ6_TO_INT  TI方式UINT32的UQ6转化整形类型\n
*  LQ_TI_UINT32_UQ5_TO_INT  TI方式UINT32的UQ5转化整形类型\n
*  LQ_TI_UINT32_UQ4_TO_INT  TI方式UINT32的UQ4转化整形类型\n
*  LQ_TI_UINT32_UQ3_TO_INT  TI方式UINT32的UQ3转化整形类型\n
*  LQ_TI_UINT32_UQ2_TO_INT  TI方式UINT32的UQ2转化整形类型\n
*  LQ_TI_UINT32_UQ1_TO_INT  TI方式UINT32的UQ1转化整形类型\n
*/
LQ_INLINE LQ_UINT32_UQ22 LQ_TI_UINT32_UQ22_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error){
    return (LQ_UINT32_UQ22)(((LQ_I_32BIT)A + (((LQ_I_32BIT)A < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 22) - 1u) : 0)) >> 22);
}
/**@brief (TI方法)UINT32类型UQ21格式转整形
* @details 采用估算位+指数位+符号位三位结合
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    整形
* @par       将Q格式转化为整形
* @code*    LQ_TI_UINT32_UQ21_TO_INT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_UINT32_UQ32_TO_INT  TI方式UINT32的UQ32转化整形类型\n
*  LQ_TI_UINT32_UQ31_TO_INT  TI方式UINT32的UQ31转化整形类型\n
*  LQ_TI_UINT32_UQ30_TO_INT  TI方式UINT32的UQ30转化整形类型\n
*  LQ_TI_UINT32_UQ29_TO_INT  TI方式UINT32的UQ29转化整形类型\n
*  LQ_TI_UINT32_UQ28_TO_INT  TI方式UINT32的UQ28转化整形类型\n
*  LQ_TI_UINT32_UQ27_TO_INT  TI方式UINT32的UQ27转化整形类型\n
*  LQ_TI_UINT32_UQ26_TO_INT  TI方式UINT32的UQ26转化整形类型\n
*  LQ_TI_UINT32_UQ25_TO_INT  TI方式UINT32的UQ25转化整形类型\n
*  LQ_TI_UINT32_UQ24_TO_INT  TI方式UINT32的UQ24转化整形类型\n
*  LQ_TI_UINT32_UQ23_TO_INT  TI方式UINT32的UQ23转化整形类型\n
*  LQ_TI_UINT32_UQ22_TO_INT  TI方式UINT32的UQ22转化整形类型\n
*  LQ_TI_UINT32_UQ21_TO_INT  TI方式UINT32的UQ21转化整形类型\n
*  LQ_TI_UINT32_UQ20_TO_INT  TI方式UINT32的UQ20转化整形类型\n
*  LQ_TI_UINT32_UQ19_TO_INT  TI方式UINT32的UQ19转化整形类型\n
*  LQ_TI_UINT32_UQ18_TO_INT  TI方式UINT32的UQ18转化整形类型\n
*  LQ_TI_UINT32_UQ17_TO_INT  TI方式UINT32的UQ17转化整形类型\n
*  LQ_TI_UINT32_UQ16_TO_INT  TI方式UINT32的UQ16转化整形类型\n
*  LQ_TI_UINT32_UQ15_TO_INT  TI方式UINT32的UQ15转化整形类型\n
*  LQ_TI_UINT32_UQ14_TO_INT  TI方式UINT32的UQ14转化整形类型\n
*  LQ_TI_UINT32_UQ13_TO_INT  TI方式UINT32的UQ13转化整形类型\n
*  LQ_TI_UINT32_UQ12_TO_INT  TI方式UINT32的UQ12转化整形类型\n
*  LQ_TI_UINT32_UQ11_TO_INT  TI方式UINT32的UQ11转化整形类型\n
*  LQ_TI_UINT32_UQ10_TO_INT  TI方式UINT32的UQ10转化整形类型\n
*  LQ_TI_UINT32_UQ9_TO_INT  TI方式UINT32的UQ9转化整形类型\n
*  LQ_TI_UINT32_UQ8_TO_INT  TI方式UINT32的UQ8转化整形类型\n
*  LQ_TI_UINT32_UQ7_TO_INT  TI方式UINT32的UQ7转化整形类型\n
*  LQ_TI_UINT32_UQ6_TO_INT  TI方式UINT32的UQ6转化整形类型\n
*  LQ_TI_UINT32_UQ5_TO_INT  TI方式UINT32的UQ5转化整形类型\n
*  LQ_TI_UINT32_UQ4_TO_INT  TI方式UINT32的UQ4转化整形类型\n
*  LQ_TI_UINT32_UQ3_TO_INT  TI方式UINT32的UQ3转化整形类型\n
*  LQ_TI_UINT32_UQ2_TO_INT  TI方式UINT32的UQ2转化整形类型\n
*  LQ_TI_UINT32_UQ1_TO_INT  TI方式UINT32的UQ1转化整形类型\n
*/
LQ_INLINE LQ_UINT32_UQ21 LQ_TI_UINT32_UQ21_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error){
    return (LQ_UINT32_UQ21)(((LQ_I_32BIT)A + (((LQ_I_32BIT)A < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 21) - 1u) : 0)) >> 21);
}
/**@brief (TI方法)UINT32类型UQ20格式转整形
* @details 采用估算位+指数位+符号位三位结合
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    整形
* @par       将Q格式转化为整形
* @code*    LQ_TI_UINT32_UQ20_TO_INT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_UINT32_UQ32_TO_INT  TI方式UINT32的UQ32转化整形类型\n
*  LQ_TI_UINT32_UQ31_TO_INT  TI方式UINT32的UQ31转化整形类型\n
*  LQ_TI_UINT32_UQ30_TO_INT  TI方式UINT32的UQ30转化整形类型\n
*  LQ_TI_UINT32_UQ29_TO_INT  TI方式UINT32的UQ29转化整形类型\n
*  LQ_TI_UINT32_UQ28_TO_INT  TI方式UINT32的UQ28转化整形类型\n
*  LQ_TI_UINT32_UQ27_TO_INT  TI方式UINT32的UQ27转化整形类型\n
*  LQ_TI_UINT32_UQ26_TO_INT  TI方式UINT32的UQ26转化整形类型\n
*  LQ_TI_UINT32_UQ25_TO_INT  TI方式UINT32的UQ25转化整形类型\n
*  LQ_TI_UINT32_UQ24_TO_INT  TI方式UINT32的UQ24转化整形类型\n
*  LQ_TI_UINT32_UQ23_TO_INT  TI方式UINT32的UQ23转化整形类型\n
*  LQ_TI_UINT32_UQ22_TO_INT  TI方式UINT32的UQ22转化整形类型\n
*  LQ_TI_UINT32_UQ21_TO_INT  TI方式UINT32的UQ21转化整形类型\n
*  LQ_TI_UINT32_UQ20_TO_INT  TI方式UINT32的UQ20转化整形类型\n
*  LQ_TI_UINT32_UQ19_TO_INT  TI方式UINT32的UQ19转化整形类型\n
*  LQ_TI_UINT32_UQ18_TO_INT  TI方式UINT32的UQ18转化整形类型\n
*  LQ_TI_UINT32_UQ17_TO_INT  TI方式UINT32的UQ17转化整形类型\n
*  LQ_TI_UINT32_UQ16_TO_INT  TI方式UINT32的UQ16转化整形类型\n
*  LQ_TI_UINT32_UQ15_TO_INT  TI方式UINT32的UQ15转化整形类型\n
*  LQ_TI_UINT32_UQ14_TO_INT  TI方式UINT32的UQ14转化整形类型\n
*  LQ_TI_UINT32_UQ13_TO_INT  TI方式UINT32的UQ13转化整形类型\n
*  LQ_TI_UINT32_UQ12_TO_INT  TI方式UINT32的UQ12转化整形类型\n
*  LQ_TI_UINT32_UQ11_TO_INT  TI方式UINT32的UQ11转化整形类型\n
*  LQ_TI_UINT32_UQ10_TO_INT  TI方式UINT32的UQ10转化整形类型\n
*  LQ_TI_UINT32_UQ9_TO_INT  TI方式UINT32的UQ9转化整形类型\n
*  LQ_TI_UINT32_UQ8_TO_INT  TI方式UINT32的UQ8转化整形类型\n
*  LQ_TI_UINT32_UQ7_TO_INT  TI方式UINT32的UQ7转化整形类型\n
*  LQ_TI_UINT32_UQ6_TO_INT  TI方式UINT32的UQ6转化整形类型\n
*  LQ_TI_UINT32_UQ5_TO_INT  TI方式UINT32的UQ5转化整形类型\n
*  LQ_TI_UINT32_UQ4_TO_INT  TI方式UINT32的UQ4转化整形类型\n
*  LQ_TI_UINT32_UQ3_TO_INT  TI方式UINT32的UQ3转化整形类型\n
*  LQ_TI_UINT32_UQ2_TO_INT  TI方式UINT32的UQ2转化整形类型\n
*  LQ_TI_UINT32_UQ1_TO_INT  TI方式UINT32的UQ1转化整形类型\n
*/
LQ_INLINE LQ_UINT32_UQ20 LQ_TI_UINT32_UQ20_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error){
    return (LQ_UINT32_UQ20)(((LQ_I_32BIT)A + (((LQ_I_32BIT)A < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 20) - 1u) : 0)) >> 20);
}
/**@brief (TI方法)UINT32类型UQ19格式转整形
* @details 采用估算位+指数位+符号位三位结合
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    整形
* @par       将Q格式转化为整形
* @code*    LQ_TI_UINT32_UQ19_TO_INT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_UINT32_UQ32_TO_INT  TI方式UINT32的UQ32转化整形类型\n
*  LQ_TI_UINT32_UQ31_TO_INT  TI方式UINT32的UQ31转化整形类型\n
*  LQ_TI_UINT32_UQ30_TO_INT  TI方式UINT32的UQ30转化整形类型\n
*  LQ_TI_UINT32_UQ29_TO_INT  TI方式UINT32的UQ29转化整形类型\n
*  LQ_TI_UINT32_UQ28_TO_INT  TI方式UINT32的UQ28转化整形类型\n
*  LQ_TI_UINT32_UQ27_TO_INT  TI方式UINT32的UQ27转化整形类型\n
*  LQ_TI_UINT32_UQ26_TO_INT  TI方式UINT32的UQ26转化整形类型\n
*  LQ_TI_UINT32_UQ25_TO_INT  TI方式UINT32的UQ25转化整形类型\n
*  LQ_TI_UINT32_UQ24_TO_INT  TI方式UINT32的UQ24转化整形类型\n
*  LQ_TI_UINT32_UQ23_TO_INT  TI方式UINT32的UQ23转化整形类型\n
*  LQ_TI_UINT32_UQ22_TO_INT  TI方式UINT32的UQ22转化整形类型\n
*  LQ_TI_UINT32_UQ21_TO_INT  TI方式UINT32的UQ21转化整形类型\n
*  LQ_TI_UINT32_UQ20_TO_INT  TI方式UINT32的UQ20转化整形类型\n
*  LQ_TI_UINT32_UQ19_TO_INT  TI方式UINT32的UQ19转化整形类型\n
*  LQ_TI_UINT32_UQ18_TO_INT  TI方式UINT32的UQ18转化整形类型\n
*  LQ_TI_UINT32_UQ17_TO_INT  TI方式UINT32的UQ17转化整形类型\n
*  LQ_TI_UINT32_UQ16_TO_INT  TI方式UINT32的UQ16转化整形类型\n
*  LQ_TI_UINT32_UQ15_TO_INT  TI方式UINT32的UQ15转化整形类型\n
*  LQ_TI_UINT32_UQ14_TO_INT  TI方式UINT32的UQ14转化整形类型\n
*  LQ_TI_UINT32_UQ13_TO_INT  TI方式UINT32的UQ13转化整形类型\n
*  LQ_TI_UINT32_UQ12_TO_INT  TI方式UINT32的UQ12转化整形类型\n
*  LQ_TI_UINT32_UQ11_TO_INT  TI方式UINT32的UQ11转化整形类型\n
*  LQ_TI_UINT32_UQ10_TO_INT  TI方式UINT32的UQ10转化整形类型\n
*  LQ_TI_UINT32_UQ9_TO_INT  TI方式UINT32的UQ9转化整形类型\n
*  LQ_TI_UINT32_UQ8_TO_INT  TI方式UINT32的UQ8转化整形类型\n
*  LQ_TI_UINT32_UQ7_TO_INT  TI方式UINT32的UQ7转化整形类型\n
*  LQ_TI_UINT32_UQ6_TO_INT  TI方式UINT32的UQ6转化整形类型\n
*  LQ_TI_UINT32_UQ5_TO_INT  TI方式UINT32的UQ5转化整形类型\n
*  LQ_TI_UINT32_UQ4_TO_INT  TI方式UINT32的UQ4转化整形类型\n
*  LQ_TI_UINT32_UQ3_TO_INT  TI方式UINT32的UQ3转化整形类型\n
*  LQ_TI_UINT32_UQ2_TO_INT  TI方式UINT32的UQ2转化整形类型\n
*  LQ_TI_UINT32_UQ1_TO_INT  TI方式UINT32的UQ1转化整形类型\n
*/
LQ_INLINE LQ_UINT32_UQ19 LQ_TI_UINT32_UQ19_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error){
    return (LQ_UINT32_UQ19)(((LQ_I_32BIT)A + (((LQ_I_32BIT)A < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 19) - 1u) : 0)) >> 19);
}
/**@brief (TI方法)UINT32类型UQ18格式转整形
* @details 采用估算位+指数位+符号位三位结合
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    整形
* @par       将Q格式转化为整形
* @code*    LQ_TI_UINT32_UQ18_TO_INT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_UINT32_UQ32_TO_INT  TI方式UINT32的UQ32转化整形类型\n
*  LQ_TI_UINT32_UQ31_TO_INT  TI方式UINT32的UQ31转化整形类型\n
*  LQ_TI_UINT32_UQ30_TO_INT  TI方式UINT32的UQ30转化整形类型\n
*  LQ_TI_UINT32_UQ29_TO_INT  TI方式UINT32的UQ29转化整形类型\n
*  LQ_TI_UINT32_UQ28_TO_INT  TI方式UINT32的UQ28转化整形类型\n
*  LQ_TI_UINT32_UQ27_TO_INT  TI方式UINT32的UQ27转化整形类型\n
*  LQ_TI_UINT32_UQ26_TO_INT  TI方式UINT32的UQ26转化整形类型\n
*  LQ_TI_UINT32_UQ25_TO_INT  TI方式UINT32的UQ25转化整形类型\n
*  LQ_TI_UINT32_UQ24_TO_INT  TI方式UINT32的UQ24转化整形类型\n
*  LQ_TI_UINT32_UQ23_TO_INT  TI方式UINT32的UQ23转化整形类型\n
*  LQ_TI_UINT32_UQ22_TO_INT  TI方式UINT32的UQ22转化整形类型\n
*  LQ_TI_UINT32_UQ21_TO_INT  TI方式UINT32的UQ21转化整形类型\n
*  LQ_TI_UINT32_UQ20_TO_INT  TI方式UINT32的UQ20转化整形类型\n
*  LQ_TI_UINT32_UQ19_TO_INT  TI方式UINT32的UQ19转化整形类型\n
*  LQ_TI_UINT32_UQ18_TO_INT  TI方式UINT32的UQ18转化整形类型\n
*  LQ_TI_UINT32_UQ17_TO_INT  TI方式UINT32的UQ17转化整形类型\n
*  LQ_TI_UINT32_UQ16_TO_INT  TI方式UINT32的UQ16转化整形类型\n
*  LQ_TI_UINT32_UQ15_TO_INT  TI方式UINT32的UQ15转化整形类型\n
*  LQ_TI_UINT32_UQ14_TO_INT  TI方式UINT32的UQ14转化整形类型\n
*  LQ_TI_UINT32_UQ13_TO_INT  TI方式UINT32的UQ13转化整形类型\n
*  LQ_TI_UINT32_UQ12_TO_INT  TI方式UINT32的UQ12转化整形类型\n
*  LQ_TI_UINT32_UQ11_TO_INT  TI方式UINT32的UQ11转化整形类型\n
*  LQ_TI_UINT32_UQ10_TO_INT  TI方式UINT32的UQ10转化整形类型\n
*  LQ_TI_UINT32_UQ9_TO_INT  TI方式UINT32的UQ9转化整形类型\n
*  LQ_TI_UINT32_UQ8_TO_INT  TI方式UINT32的UQ8转化整形类型\n
*  LQ_TI_UINT32_UQ7_TO_INT  TI方式UINT32的UQ7转化整形类型\n
*  LQ_TI_UINT32_UQ6_TO_INT  TI方式UINT32的UQ6转化整形类型\n
*  LQ_TI_UINT32_UQ5_TO_INT  TI方式UINT32的UQ5转化整形类型\n
*  LQ_TI_UINT32_UQ4_TO_INT  TI方式UINT32的UQ4转化整形类型\n
*  LQ_TI_UINT32_UQ3_TO_INT  TI方式UINT32的UQ3转化整形类型\n
*  LQ_TI_UINT32_UQ2_TO_INT  TI方式UINT32的UQ2转化整形类型\n
*  LQ_TI_UINT32_UQ1_TO_INT  TI方式UINT32的UQ1转化整形类型\n
*/
LQ_INLINE LQ_UINT32_UQ18 LQ_TI_UINT32_UQ18_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error){
    return (LQ_UINT32_UQ18)(((LQ_I_32BIT)A + (((LQ_I_32BIT)A < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 18) - 1u) : 0)) >> 18);
}
/**@brief (TI方法)UINT32类型UQ17格式转整形
* @details 采用估算位+指数位+符号位三位结合
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    整形
* @par       将Q格式转化为整形
* @code*    LQ_TI_UINT32_UQ17_TO_INT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_UINT32_UQ32_TO_INT  TI方式UINT32的UQ32转化整形类型\n
*  LQ_TI_UINT32_UQ31_TO_INT  TI方式UINT32的UQ31转化整形类型\n
*  LQ_TI_UINT32_UQ30_TO_INT  TI方式UINT32的UQ30转化整形类型\n
*  LQ_TI_UINT32_UQ29_TO_INT  TI方式UINT32的UQ29转化整形类型\n
*  LQ_TI_UINT32_UQ28_TO_INT  TI方式UINT32的UQ28转化整形类型\n
*  LQ_TI_UINT32_UQ27_TO_INT  TI方式UINT32的UQ27转化整形类型\n
*  LQ_TI_UINT32_UQ26_TO_INT  TI方式UINT32的UQ26转化整形类型\n
*  LQ_TI_UINT32_UQ25_TO_INT  TI方式UINT32的UQ25转化整形类型\n
*  LQ_TI_UINT32_UQ24_TO_INT  TI方式UINT32的UQ24转化整形类型\n
*  LQ_TI_UINT32_UQ23_TO_INT  TI方式UINT32的UQ23转化整形类型\n
*  LQ_TI_UINT32_UQ22_TO_INT  TI方式UINT32的UQ22转化整形类型\n
*  LQ_TI_UINT32_UQ21_TO_INT  TI方式UINT32的UQ21转化整形类型\n
*  LQ_TI_UINT32_UQ20_TO_INT  TI方式UINT32的UQ20转化整形类型\n
*  LQ_TI_UINT32_UQ19_TO_INT  TI方式UINT32的UQ19转化整形类型\n
*  LQ_TI_UINT32_UQ18_TO_INT  TI方式UINT32的UQ18转化整形类型\n
*  LQ_TI_UINT32_UQ17_TO_INT  TI方式UINT32的UQ17转化整形类型\n
*  LQ_TI_UINT32_UQ16_TO_INT  TI方式UINT32的UQ16转化整形类型\n
*  LQ_TI_UINT32_UQ15_TO_INT  TI方式UINT32的UQ15转化整形类型\n
*  LQ_TI_UINT32_UQ14_TO_INT  TI方式UINT32的UQ14转化整形类型\n
*  LQ_TI_UINT32_UQ13_TO_INT  TI方式UINT32的UQ13转化整形类型\n
*  LQ_TI_UINT32_UQ12_TO_INT  TI方式UINT32的UQ12转化整形类型\n
*  LQ_TI_UINT32_UQ11_TO_INT  TI方式UINT32的UQ11转化整形类型\n
*  LQ_TI_UINT32_UQ10_TO_INT  TI方式UINT32的UQ10转化整形类型\n
*  LQ_TI_UINT32_UQ9_TO_INT  TI方式UINT32的UQ9转化整形类型\n
*  LQ_TI_UINT32_UQ8_TO_INT  TI方式UINT32的UQ8转化整形类型\n
*  LQ_TI_UINT32_UQ7_TO_INT  TI方式UINT32的UQ7转化整形类型\n
*  LQ_TI_UINT32_UQ6_TO_INT  TI方式UINT32的UQ6转化整形类型\n
*  LQ_TI_UINT32_UQ5_TO_INT  TI方式UINT32的UQ5转化整形类型\n
*  LQ_TI_UINT32_UQ4_TO_INT  TI方式UINT32的UQ4转化整形类型\n
*  LQ_TI_UINT32_UQ3_TO_INT  TI方式UINT32的UQ3转化整形类型\n
*  LQ_TI_UINT32_UQ2_TO_INT  TI方式UINT32的UQ2转化整形类型\n
*  LQ_TI_UINT32_UQ1_TO_INT  TI方式UINT32的UQ1转化整形类型\n
*/
LQ_INLINE LQ_UINT32_UQ17 LQ_TI_UINT32_UQ17_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error){
    return (LQ_UINT32_UQ17)(((LQ_I_32BIT)A + (((LQ_I_32BIT)A < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 17) - 1u) : 0)) >> 17);
}
/**@brief (TI方法)UINT32类型UQ16格式转整形
* @details 采用估算位+指数位+符号位三位结合
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    整形
* @par       将Q格式转化为整形
* @code*    LQ_TI_UINT32_UQ16_TO_INT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_UINT32_UQ32_TO_INT  TI方式UINT32的UQ32转化整形类型\n
*  LQ_TI_UINT32_UQ31_TO_INT  TI方式UINT32的UQ31转化整形类型\n
*  LQ_TI_UINT32_UQ30_TO_INT  TI方式UINT32的UQ30转化整形类型\n
*  LQ_TI_UINT32_UQ29_TO_INT  TI方式UINT32的UQ29转化整形类型\n
*  LQ_TI_UINT32_UQ28_TO_INT  TI方式UINT32的UQ28转化整形类型\n
*  LQ_TI_UINT32_UQ27_TO_INT  TI方式UINT32的UQ27转化整形类型\n
*  LQ_TI_UINT32_UQ26_TO_INT  TI方式UINT32的UQ26转化整形类型\n
*  LQ_TI_UINT32_UQ25_TO_INT  TI方式UINT32的UQ25转化整形类型\n
*  LQ_TI_UINT32_UQ24_TO_INT  TI方式UINT32的UQ24转化整形类型\n
*  LQ_TI_UINT32_UQ23_TO_INT  TI方式UINT32的UQ23转化整形类型\n
*  LQ_TI_UINT32_UQ22_TO_INT  TI方式UINT32的UQ22转化整形类型\n
*  LQ_TI_UINT32_UQ21_TO_INT  TI方式UINT32的UQ21转化整形类型\n
*  LQ_TI_UINT32_UQ20_TO_INT  TI方式UINT32的UQ20转化整形类型\n
*  LQ_TI_UINT32_UQ19_TO_INT  TI方式UINT32的UQ19转化整形类型\n
*  LQ_TI_UINT32_UQ18_TO_INT  TI方式UINT32的UQ18转化整形类型\n
*  LQ_TI_UINT32_UQ17_TO_INT  TI方式UINT32的UQ17转化整形类型\n
*  LQ_TI_UINT32_UQ16_TO_INT  TI方式UINT32的UQ16转化整形类型\n
*  LQ_TI_UINT32_UQ15_TO_INT  TI方式UINT32的UQ15转化整形类型\n
*  LQ_TI_UINT32_UQ14_TO_INT  TI方式UINT32的UQ14转化整形类型\n
*  LQ_TI_UINT32_UQ13_TO_INT  TI方式UINT32的UQ13转化整形类型\n
*  LQ_TI_UINT32_UQ12_TO_INT  TI方式UINT32的UQ12转化整形类型\n
*  LQ_TI_UINT32_UQ11_TO_INT  TI方式UINT32的UQ11转化整形类型\n
*  LQ_TI_UINT32_UQ10_TO_INT  TI方式UINT32的UQ10转化整形类型\n
*  LQ_TI_UINT32_UQ9_TO_INT  TI方式UINT32的UQ9转化整形类型\n
*  LQ_TI_UINT32_UQ8_TO_INT  TI方式UINT32的UQ8转化整形类型\n
*  LQ_TI_UINT32_UQ7_TO_INT  TI方式UINT32的UQ7转化整形类型\n
*  LQ_TI_UINT32_UQ6_TO_INT  TI方式UINT32的UQ6转化整形类型\n
*  LQ_TI_UINT32_UQ5_TO_INT  TI方式UINT32的UQ5转化整形类型\n
*  LQ_TI_UINT32_UQ4_TO_INT  TI方式UINT32的UQ4转化整形类型\n
*  LQ_TI_UINT32_UQ3_TO_INT  TI方式UINT32的UQ3转化整形类型\n
*  LQ_TI_UINT32_UQ2_TO_INT  TI方式UINT32的UQ2转化整形类型\n
*  LQ_TI_UINT32_UQ1_TO_INT  TI方式UINT32的UQ1转化整形类型\n
*/
LQ_INLINE LQ_UINT32_UQ16 LQ_TI_UINT32_UQ16_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error){
    return (LQ_UINT32_UQ16)(((LQ_I_32BIT)A + (((LQ_I_32BIT)A < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 16) - 1u) : 0)) >> 16);
}
/**@brief (TI方法)UINT32类型UQ15格式转整形
* @details 采用估算位+指数位+符号位三位结合
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    整形
* @par       将Q格式转化为整形
* @code*    LQ_TI_UINT32_UQ15_TO_INT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_UINT32_UQ32_TO_INT  TI方式UINT32的UQ32转化整形类型\n
*  LQ_TI_UINT32_UQ31_TO_INT  TI方式UINT32的UQ31转化整形类型\n
*  LQ_TI_UINT32_UQ30_TO_INT  TI方式UINT32的UQ30转化整形类型\n
*  LQ_TI_UINT32_UQ29_TO_INT  TI方式UINT32的UQ29转化整形类型\n
*  LQ_TI_UINT32_UQ28_TO_INT  TI方式UINT32的UQ28转化整形类型\n
*  LQ_TI_UINT32_UQ27_TO_INT  TI方式UINT32的UQ27转化整形类型\n
*  LQ_TI_UINT32_UQ26_TO_INT  TI方式UINT32的UQ26转化整形类型\n
*  LQ_TI_UINT32_UQ25_TO_INT  TI方式UINT32的UQ25转化整形类型\n
*  LQ_TI_UINT32_UQ24_TO_INT  TI方式UINT32的UQ24转化整形类型\n
*  LQ_TI_UINT32_UQ23_TO_INT  TI方式UINT32的UQ23转化整形类型\n
*  LQ_TI_UINT32_UQ22_TO_INT  TI方式UINT32的UQ22转化整形类型\n
*  LQ_TI_UINT32_UQ21_TO_INT  TI方式UINT32的UQ21转化整形类型\n
*  LQ_TI_UINT32_UQ20_TO_INT  TI方式UINT32的UQ20转化整形类型\n
*  LQ_TI_UINT32_UQ19_TO_INT  TI方式UINT32的UQ19转化整形类型\n
*  LQ_TI_UINT32_UQ18_TO_INT  TI方式UINT32的UQ18转化整形类型\n
*  LQ_TI_UINT32_UQ17_TO_INT  TI方式UINT32的UQ17转化整形类型\n
*  LQ_TI_UINT32_UQ16_TO_INT  TI方式UINT32的UQ16转化整形类型\n
*  LQ_TI_UINT32_UQ15_TO_INT  TI方式UINT32的UQ15转化整形类型\n
*  LQ_TI_UINT32_UQ14_TO_INT  TI方式UINT32的UQ14转化整形类型\n
*  LQ_TI_UINT32_UQ13_TO_INT  TI方式UINT32的UQ13转化整形类型\n
*  LQ_TI_UINT32_UQ12_TO_INT  TI方式UINT32的UQ12转化整形类型\n
*  LQ_TI_UINT32_UQ11_TO_INT  TI方式UINT32的UQ11转化整形类型\n
*  LQ_TI_UINT32_UQ10_TO_INT  TI方式UINT32的UQ10转化整形类型\n
*  LQ_TI_UINT32_UQ9_TO_INT  TI方式UINT32的UQ9转化整形类型\n
*  LQ_TI_UINT32_UQ8_TO_INT  TI方式UINT32的UQ8转化整形类型\n
*  LQ_TI_UINT32_UQ7_TO_INT  TI方式UINT32的UQ7转化整形类型\n
*  LQ_TI_UINT32_UQ6_TO_INT  TI方式UINT32的UQ6转化整形类型\n
*  LQ_TI_UINT32_UQ5_TO_INT  TI方式UINT32的UQ5转化整形类型\n
*  LQ_TI_UINT32_UQ4_TO_INT  TI方式UINT32的UQ4转化整形类型\n
*  LQ_TI_UINT32_UQ3_TO_INT  TI方式UINT32的UQ3转化整形类型\n
*  LQ_TI_UINT32_UQ2_TO_INT  TI方式UINT32的UQ2转化整形类型\n
*  LQ_TI_UINT32_UQ1_TO_INT  TI方式UINT32的UQ1转化整形类型\n
*/
LQ_INLINE LQ_UINT32_UQ15 LQ_TI_UINT32_UQ15_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error){
    return (LQ_UINT32_UQ15)(((LQ_I_32BIT)A + (((LQ_I_32BIT)A < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 15) - 1u) : 0)) >> 15);
}
/**@brief (TI方法)UINT32类型UQ14格式转整形
* @details 采用估算位+指数位+符号位三位结合
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    整形
* @par       将Q格式转化为整形
* @code*    LQ_TI_UINT32_UQ14_TO_INT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_UINT32_UQ32_TO_INT  TI方式UINT32的UQ32转化整形类型\n
*  LQ_TI_UINT32_UQ31_TO_INT  TI方式UINT32的UQ31转化整形类型\n
*  LQ_TI_UINT32_UQ30_TO_INT  TI方式UINT32的UQ30转化整形类型\n
*  LQ_TI_UINT32_UQ29_TO_INT  TI方式UINT32的UQ29转化整形类型\n
*  LQ_TI_UINT32_UQ28_TO_INT  TI方式UINT32的UQ28转化整形类型\n
*  LQ_TI_UINT32_UQ27_TO_INT  TI方式UINT32的UQ27转化整形类型\n
*  LQ_TI_UINT32_UQ26_TO_INT  TI方式UINT32的UQ26转化整形类型\n
*  LQ_TI_UINT32_UQ25_TO_INT  TI方式UINT32的UQ25转化整形类型\n
*  LQ_TI_UINT32_UQ24_TO_INT  TI方式UINT32的UQ24转化整形类型\n
*  LQ_TI_UINT32_UQ23_TO_INT  TI方式UINT32的UQ23转化整形类型\n
*  LQ_TI_UINT32_UQ22_TO_INT  TI方式UINT32的UQ22转化整形类型\n
*  LQ_TI_UINT32_UQ21_TO_INT  TI方式UINT32的UQ21转化整形类型\n
*  LQ_TI_UINT32_UQ20_TO_INT  TI方式UINT32的UQ20转化整形类型\n
*  LQ_TI_UINT32_UQ19_TO_INT  TI方式UINT32的UQ19转化整形类型\n
*  LQ_TI_UINT32_UQ18_TO_INT  TI方式UINT32的UQ18转化整形类型\n
*  LQ_TI_UINT32_UQ17_TO_INT  TI方式UINT32的UQ17转化整形类型\n
*  LQ_TI_UINT32_UQ16_TO_INT  TI方式UINT32的UQ16转化整形类型\n
*  LQ_TI_UINT32_UQ15_TO_INT  TI方式UINT32的UQ15转化整形类型\n
*  LQ_TI_UINT32_UQ14_TO_INT  TI方式UINT32的UQ14转化整形类型\n
*  LQ_TI_UINT32_UQ13_TO_INT  TI方式UINT32的UQ13转化整形类型\n
*  LQ_TI_UINT32_UQ12_TO_INT  TI方式UINT32的UQ12转化整形类型\n
*  LQ_TI_UINT32_UQ11_TO_INT  TI方式UINT32的UQ11转化整形类型\n
*  LQ_TI_UINT32_UQ10_TO_INT  TI方式UINT32的UQ10转化整形类型\n
*  LQ_TI_UINT32_UQ9_TO_INT  TI方式UINT32的UQ9转化整形类型\n
*  LQ_TI_UINT32_UQ8_TO_INT  TI方式UINT32的UQ8转化整形类型\n
*  LQ_TI_UINT32_UQ7_TO_INT  TI方式UINT32的UQ7转化整形类型\n
*  LQ_TI_UINT32_UQ6_TO_INT  TI方式UINT32的UQ6转化整形类型\n
*  LQ_TI_UINT32_UQ5_TO_INT  TI方式UINT32的UQ5转化整形类型\n
*  LQ_TI_UINT32_UQ4_TO_INT  TI方式UINT32的UQ4转化整形类型\n
*  LQ_TI_UINT32_UQ3_TO_INT  TI方式UINT32的UQ3转化整形类型\n
*  LQ_TI_UINT32_UQ2_TO_INT  TI方式UINT32的UQ2转化整形类型\n
*  LQ_TI_UINT32_UQ1_TO_INT  TI方式UINT32的UQ1转化整形类型\n
*/
LQ_INLINE LQ_UINT32_UQ14 LQ_TI_UINT32_UQ14_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error){
    return (LQ_UINT32_UQ14)(((LQ_I_32BIT)A + (((LQ_I_32BIT)A < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 14) - 1u) : 0)) >> 14);
}
/**@brief (TI方法)UINT32类型UQ13格式转整形
* @details 采用估算位+指数位+符号位三位结合
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    整形
* @par       将Q格式转化为整形
* @code*    LQ_TI_UINT32_UQ13_TO_INT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_UINT32_UQ32_TO_INT  TI方式UINT32的UQ32转化整形类型\n
*  LQ_TI_UINT32_UQ31_TO_INT  TI方式UINT32的UQ31转化整形类型\n
*  LQ_TI_UINT32_UQ30_TO_INT  TI方式UINT32的UQ30转化整形类型\n
*  LQ_TI_UINT32_UQ29_TO_INT  TI方式UINT32的UQ29转化整形类型\n
*  LQ_TI_UINT32_UQ28_TO_INT  TI方式UINT32的UQ28转化整形类型\n
*  LQ_TI_UINT32_UQ27_TO_INT  TI方式UINT32的UQ27转化整形类型\n
*  LQ_TI_UINT32_UQ26_TO_INT  TI方式UINT32的UQ26转化整形类型\n
*  LQ_TI_UINT32_UQ25_TO_INT  TI方式UINT32的UQ25转化整形类型\n
*  LQ_TI_UINT32_UQ24_TO_INT  TI方式UINT32的UQ24转化整形类型\n
*  LQ_TI_UINT32_UQ23_TO_INT  TI方式UINT32的UQ23转化整形类型\n
*  LQ_TI_UINT32_UQ22_TO_INT  TI方式UINT32的UQ22转化整形类型\n
*  LQ_TI_UINT32_UQ21_TO_INT  TI方式UINT32的UQ21转化整形类型\n
*  LQ_TI_UINT32_UQ20_TO_INT  TI方式UINT32的UQ20转化整形类型\n
*  LQ_TI_UINT32_UQ19_TO_INT  TI方式UINT32的UQ19转化整形类型\n
*  LQ_TI_UINT32_UQ18_TO_INT  TI方式UINT32的UQ18转化整形类型\n
*  LQ_TI_UINT32_UQ17_TO_INT  TI方式UINT32的UQ17转化整形类型\n
*  LQ_TI_UINT32_UQ16_TO_INT  TI方式UINT32的UQ16转化整形类型\n
*  LQ_TI_UINT32_UQ15_TO_INT  TI方式UINT32的UQ15转化整形类型\n
*  LQ_TI_UINT32_UQ14_TO_INT  TI方式UINT32的UQ14转化整形类型\n
*  LQ_TI_UINT32_UQ13_TO_INT  TI方式UINT32的UQ13转化整形类型\n
*  LQ_TI_UINT32_UQ12_TO_INT  TI方式UINT32的UQ12转化整形类型\n
*  LQ_TI_UINT32_UQ11_TO_INT  TI方式UINT32的UQ11转化整形类型\n
*  LQ_TI_UINT32_UQ10_TO_INT  TI方式UINT32的UQ10转化整形类型\n
*  LQ_TI_UINT32_UQ9_TO_INT  TI方式UINT32的UQ9转化整形类型\n
*  LQ_TI_UINT32_UQ8_TO_INT  TI方式UINT32的UQ8转化整形类型\n
*  LQ_TI_UINT32_UQ7_TO_INT  TI方式UINT32的UQ7转化整形类型\n
*  LQ_TI_UINT32_UQ6_TO_INT  TI方式UINT32的UQ6转化整形类型\n
*  LQ_TI_UINT32_UQ5_TO_INT  TI方式UINT32的UQ5转化整形类型\n
*  LQ_TI_UINT32_UQ4_TO_INT  TI方式UINT32的UQ4转化整形类型\n
*  LQ_TI_UINT32_UQ3_TO_INT  TI方式UINT32的UQ3转化整形类型\n
*  LQ_TI_UINT32_UQ2_TO_INT  TI方式UINT32的UQ2转化整形类型\n
*  LQ_TI_UINT32_UQ1_TO_INT  TI方式UINT32的UQ1转化整形类型\n
*/
LQ_INLINE LQ_UINT32_UQ13 LQ_TI_UINT32_UQ13_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error){
    return (LQ_UINT32_UQ13)(((LQ_I_32BIT)A + (((LQ_I_32BIT)A < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 13) - 1u) : 0)) >> 13);
}
/**@brief (TI方法)UINT32类型UQ12格式转整形
* @details 采用估算位+指数位+符号位三位结合
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    整形
* @par       将Q格式转化为整形
* @code*    LQ_TI_UINT32_UQ12_TO_INT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_UINT32_UQ32_TO_INT  TI方式UINT32的UQ32转化整形类型\n
*  LQ_TI_UINT32_UQ31_TO_INT  TI方式UINT32的UQ31转化整形类型\n
*  LQ_TI_UINT32_UQ30_TO_INT  TI方式UINT32的UQ30转化整形类型\n
*  LQ_TI_UINT32_UQ29_TO_INT  TI方式UINT32的UQ29转化整形类型\n
*  LQ_TI_UINT32_UQ28_TO_INT  TI方式UINT32的UQ28转化整形类型\n
*  LQ_TI_UINT32_UQ27_TO_INT  TI方式UINT32的UQ27转化整形类型\n
*  LQ_TI_UINT32_UQ26_TO_INT  TI方式UINT32的UQ26转化整形类型\n
*  LQ_TI_UINT32_UQ25_TO_INT  TI方式UINT32的UQ25转化整形类型\n
*  LQ_TI_UINT32_UQ24_TO_INT  TI方式UINT32的UQ24转化整形类型\n
*  LQ_TI_UINT32_UQ23_TO_INT  TI方式UINT32的UQ23转化整形类型\n
*  LQ_TI_UINT32_UQ22_TO_INT  TI方式UINT32的UQ22转化整形类型\n
*  LQ_TI_UINT32_UQ21_TO_INT  TI方式UINT32的UQ21转化整形类型\n
*  LQ_TI_UINT32_UQ20_TO_INT  TI方式UINT32的UQ20转化整形类型\n
*  LQ_TI_UINT32_UQ19_TO_INT  TI方式UINT32的UQ19转化整形类型\n
*  LQ_TI_UINT32_UQ18_TO_INT  TI方式UINT32的UQ18转化整形类型\n
*  LQ_TI_UINT32_UQ17_TO_INT  TI方式UINT32的UQ17转化整形类型\n
*  LQ_TI_UINT32_UQ16_TO_INT  TI方式UINT32的UQ16转化整形类型\n
*  LQ_TI_UINT32_UQ15_TO_INT  TI方式UINT32的UQ15转化整形类型\n
*  LQ_TI_UINT32_UQ14_TO_INT  TI方式UINT32的UQ14转化整形类型\n
*  LQ_TI_UINT32_UQ13_TO_INT  TI方式UINT32的UQ13转化整形类型\n
*  LQ_TI_UINT32_UQ12_TO_INT  TI方式UINT32的UQ12转化整形类型\n
*  LQ_TI_UINT32_UQ11_TO_INT  TI方式UINT32的UQ11转化整形类型\n
*  LQ_TI_UINT32_UQ10_TO_INT  TI方式UINT32的UQ10转化整形类型\n
*  LQ_TI_UINT32_UQ9_TO_INT  TI方式UINT32的UQ9转化整形类型\n
*  LQ_TI_UINT32_UQ8_TO_INT  TI方式UINT32的UQ8转化整形类型\n
*  LQ_TI_UINT32_UQ7_TO_INT  TI方式UINT32的UQ7转化整形类型\n
*  LQ_TI_UINT32_UQ6_TO_INT  TI方式UINT32的UQ6转化整形类型\n
*  LQ_TI_UINT32_UQ5_TO_INT  TI方式UINT32的UQ5转化整形类型\n
*  LQ_TI_UINT32_UQ4_TO_INT  TI方式UINT32的UQ4转化整形类型\n
*  LQ_TI_UINT32_UQ3_TO_INT  TI方式UINT32的UQ3转化整形类型\n
*  LQ_TI_UINT32_UQ2_TO_INT  TI方式UINT32的UQ2转化整形类型\n
*  LQ_TI_UINT32_UQ1_TO_INT  TI方式UINT32的UQ1转化整形类型\n
*/
LQ_INLINE LQ_UINT32_UQ12 LQ_TI_UINT32_UQ12_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error){
    return (LQ_UINT32_UQ12)(((LQ_I_32BIT)A + (((LQ_I_32BIT)A < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 12) - 1u) : 0)) >> 12);
}
/**@brief (TI方法)UINT32类型UQ11格式转整形
* @details 采用估算位+指数位+符号位三位结合
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    整形
* @par       将Q格式转化为整形
* @code*    LQ_TI_UINT32_UQ11_TO_INT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_UINT32_UQ32_TO_INT  TI方式UINT32的UQ32转化整形类型\n
*  LQ_TI_UINT32_UQ31_TO_INT  TI方式UINT32的UQ31转化整形类型\n
*  LQ_TI_UINT32_UQ30_TO_INT  TI方式UINT32的UQ30转化整形类型\n
*  LQ_TI_UINT32_UQ29_TO_INT  TI方式UINT32的UQ29转化整形类型\n
*  LQ_TI_UINT32_UQ28_TO_INT  TI方式UINT32的UQ28转化整形类型\n
*  LQ_TI_UINT32_UQ27_TO_INT  TI方式UINT32的UQ27转化整形类型\n
*  LQ_TI_UINT32_UQ26_TO_INT  TI方式UINT32的UQ26转化整形类型\n
*  LQ_TI_UINT32_UQ25_TO_INT  TI方式UINT32的UQ25转化整形类型\n
*  LQ_TI_UINT32_UQ24_TO_INT  TI方式UINT32的UQ24转化整形类型\n
*  LQ_TI_UINT32_UQ23_TO_INT  TI方式UINT32的UQ23转化整形类型\n
*  LQ_TI_UINT32_UQ22_TO_INT  TI方式UINT32的UQ22转化整形类型\n
*  LQ_TI_UINT32_UQ21_TO_INT  TI方式UINT32的UQ21转化整形类型\n
*  LQ_TI_UINT32_UQ20_TO_INT  TI方式UINT32的UQ20转化整形类型\n
*  LQ_TI_UINT32_UQ19_TO_INT  TI方式UINT32的UQ19转化整形类型\n
*  LQ_TI_UINT32_UQ18_TO_INT  TI方式UINT32的UQ18转化整形类型\n
*  LQ_TI_UINT32_UQ17_TO_INT  TI方式UINT32的UQ17转化整形类型\n
*  LQ_TI_UINT32_UQ16_TO_INT  TI方式UINT32的UQ16转化整形类型\n
*  LQ_TI_UINT32_UQ15_TO_INT  TI方式UINT32的UQ15转化整形类型\n
*  LQ_TI_UINT32_UQ14_TO_INT  TI方式UINT32的UQ14转化整形类型\n
*  LQ_TI_UINT32_UQ13_TO_INT  TI方式UINT32的UQ13转化整形类型\n
*  LQ_TI_UINT32_UQ12_TO_INT  TI方式UINT32的UQ12转化整形类型\n
*  LQ_TI_UINT32_UQ11_TO_INT  TI方式UINT32的UQ11转化整形类型\n
*  LQ_TI_UINT32_UQ10_TO_INT  TI方式UINT32的UQ10转化整形类型\n
*  LQ_TI_UINT32_UQ9_TO_INT  TI方式UINT32的UQ9转化整形类型\n
*  LQ_TI_UINT32_UQ8_TO_INT  TI方式UINT32的UQ8转化整形类型\n
*  LQ_TI_UINT32_UQ7_TO_INT  TI方式UINT32的UQ7转化整形类型\n
*  LQ_TI_UINT32_UQ6_TO_INT  TI方式UINT32的UQ6转化整形类型\n
*  LQ_TI_UINT32_UQ5_TO_INT  TI方式UINT32的UQ5转化整形类型\n
*  LQ_TI_UINT32_UQ4_TO_INT  TI方式UINT32的UQ4转化整形类型\n
*  LQ_TI_UINT32_UQ3_TO_INT  TI方式UINT32的UQ3转化整形类型\n
*  LQ_TI_UINT32_UQ2_TO_INT  TI方式UINT32的UQ2转化整形类型\n
*  LQ_TI_UINT32_UQ1_TO_INT  TI方式UINT32的UQ1转化整形类型\n
*/
LQ_INLINE LQ_UINT32_UQ11 LQ_TI_UINT32_UQ11_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error){
    return (LQ_UINT32_UQ11)(((LQ_I_32BIT)A + (((LQ_I_32BIT)A < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 11) - 1u) : 0)) >> 11);
}
/**@brief (TI方法)UINT32类型UQ10格式转整形
* @details 采用估算位+指数位+符号位三位结合
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    整形
* @par       将Q格式转化为整形
* @code*    LQ_TI_UINT32_UQ10_TO_INT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_UINT32_UQ32_TO_INT  TI方式UINT32的UQ32转化整形类型\n
*  LQ_TI_UINT32_UQ31_TO_INT  TI方式UINT32的UQ31转化整形类型\n
*  LQ_TI_UINT32_UQ30_TO_INT  TI方式UINT32的UQ30转化整形类型\n
*  LQ_TI_UINT32_UQ29_TO_INT  TI方式UINT32的UQ29转化整形类型\n
*  LQ_TI_UINT32_UQ28_TO_INT  TI方式UINT32的UQ28转化整形类型\n
*  LQ_TI_UINT32_UQ27_TO_INT  TI方式UINT32的UQ27转化整形类型\n
*  LQ_TI_UINT32_UQ26_TO_INT  TI方式UINT32的UQ26转化整形类型\n
*  LQ_TI_UINT32_UQ25_TO_INT  TI方式UINT32的UQ25转化整形类型\n
*  LQ_TI_UINT32_UQ24_TO_INT  TI方式UINT32的UQ24转化整形类型\n
*  LQ_TI_UINT32_UQ23_TO_INT  TI方式UINT32的UQ23转化整形类型\n
*  LQ_TI_UINT32_UQ22_TO_INT  TI方式UINT32的UQ22转化整形类型\n
*  LQ_TI_UINT32_UQ21_TO_INT  TI方式UINT32的UQ21转化整形类型\n
*  LQ_TI_UINT32_UQ20_TO_INT  TI方式UINT32的UQ20转化整形类型\n
*  LQ_TI_UINT32_UQ19_TO_INT  TI方式UINT32的UQ19转化整形类型\n
*  LQ_TI_UINT32_UQ18_TO_INT  TI方式UINT32的UQ18转化整形类型\n
*  LQ_TI_UINT32_UQ17_TO_INT  TI方式UINT32的UQ17转化整形类型\n
*  LQ_TI_UINT32_UQ16_TO_INT  TI方式UINT32的UQ16转化整形类型\n
*  LQ_TI_UINT32_UQ15_TO_INT  TI方式UINT32的UQ15转化整形类型\n
*  LQ_TI_UINT32_UQ14_TO_INT  TI方式UINT32的UQ14转化整形类型\n
*  LQ_TI_UINT32_UQ13_TO_INT  TI方式UINT32的UQ13转化整形类型\n
*  LQ_TI_UINT32_UQ12_TO_INT  TI方式UINT32的UQ12转化整形类型\n
*  LQ_TI_UINT32_UQ11_TO_INT  TI方式UINT32的UQ11转化整形类型\n
*  LQ_TI_UINT32_UQ10_TO_INT  TI方式UINT32的UQ10转化整形类型\n
*  LQ_TI_UINT32_UQ9_TO_INT  TI方式UINT32的UQ9转化整形类型\n
*  LQ_TI_UINT32_UQ8_TO_INT  TI方式UINT32的UQ8转化整形类型\n
*  LQ_TI_UINT32_UQ7_TO_INT  TI方式UINT32的UQ7转化整形类型\n
*  LQ_TI_UINT32_UQ6_TO_INT  TI方式UINT32的UQ6转化整形类型\n
*  LQ_TI_UINT32_UQ5_TO_INT  TI方式UINT32的UQ5转化整形类型\n
*  LQ_TI_UINT32_UQ4_TO_INT  TI方式UINT32的UQ4转化整形类型\n
*  LQ_TI_UINT32_UQ3_TO_INT  TI方式UINT32的UQ3转化整形类型\n
*  LQ_TI_UINT32_UQ2_TO_INT  TI方式UINT32的UQ2转化整形类型\n
*  LQ_TI_UINT32_UQ1_TO_INT  TI方式UINT32的UQ1转化整形类型\n
*/
LQ_INLINE LQ_UINT32_UQ10 LQ_TI_UINT32_UQ10_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error){
    return (LQ_UINT32_UQ10)(((LQ_I_32BIT)A + (((LQ_I_32BIT)A < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 10) - 1u) : 0)) >> 10);
}
/**@brief (TI方法)UINT32类型UQ9格式转整形
* @details 采用估算位+指数位+符号位三位结合
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    整形
* @par       将Q格式转化为整形
* @code*    LQ_TI_UINT32_UQ9_TO_INT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_UINT32_UQ32_TO_INT  TI方式UINT32的UQ32转化整形类型\n
*  LQ_TI_UINT32_UQ31_TO_INT  TI方式UINT32的UQ31转化整形类型\n
*  LQ_TI_UINT32_UQ30_TO_INT  TI方式UINT32的UQ30转化整形类型\n
*  LQ_TI_UINT32_UQ29_TO_INT  TI方式UINT32的UQ29转化整形类型\n
*  LQ_TI_UINT32_UQ28_TO_INT  TI方式UINT32的UQ28转化整形类型\n
*  LQ_TI_UINT32_UQ27_TO_INT  TI方式UINT32的UQ27转化整形类型\n
*  LQ_TI_UINT32_UQ26_TO_INT  TI方式UINT32的UQ26转化整形类型\n
*  LQ_TI_UINT32_UQ25_TO_INT  TI方式UINT32的UQ25转化整形类型\n
*  LQ_TI_UINT32_UQ24_TO_INT  TI方式UINT32的UQ24转化整形类型\n
*  LQ_TI_UINT32_UQ23_TO_INT  TI方式UINT32的UQ23转化整形类型\n
*  LQ_TI_UINT32_UQ22_TO_INT  TI方式UINT32的UQ22转化整形类型\n
*  LQ_TI_UINT32_UQ21_TO_INT  TI方式UINT32的UQ21转化整形类型\n
*  LQ_TI_UINT32_UQ20_TO_INT  TI方式UINT32的UQ20转化整形类型\n
*  LQ_TI_UINT32_UQ19_TO_INT  TI方式UINT32的UQ19转化整形类型\n
*  LQ_TI_UINT32_UQ18_TO_INT  TI方式UINT32的UQ18转化整形类型\n
*  LQ_TI_UINT32_UQ17_TO_INT  TI方式UINT32的UQ17转化整形类型\n
*  LQ_TI_UINT32_UQ16_TO_INT  TI方式UINT32的UQ16转化整形类型\n
*  LQ_TI_UINT32_UQ15_TO_INT  TI方式UINT32的UQ15转化整形类型\n
*  LQ_TI_UINT32_UQ14_TO_INT  TI方式UINT32的UQ14转化整形类型\n
*  LQ_TI_UINT32_UQ13_TO_INT  TI方式UINT32的UQ13转化整形类型\n
*  LQ_TI_UINT32_UQ12_TO_INT  TI方式UINT32的UQ12转化整形类型\n
*  LQ_TI_UINT32_UQ11_TO_INT  TI方式UINT32的UQ11转化整形类型\n
*  LQ_TI_UINT32_UQ10_TO_INT  TI方式UINT32的UQ10转化整形类型\n
*  LQ_TI_UINT32_UQ9_TO_INT  TI方式UINT32的UQ9转化整形类型\n
*  LQ_TI_UINT32_UQ8_TO_INT  TI方式UINT32的UQ8转化整形类型\n
*  LQ_TI_UINT32_UQ7_TO_INT  TI方式UINT32的UQ7转化整形类型\n
*  LQ_TI_UINT32_UQ6_TO_INT  TI方式UINT32的UQ6转化整形类型\n
*  LQ_TI_UINT32_UQ5_TO_INT  TI方式UINT32的UQ5转化整形类型\n
*  LQ_TI_UINT32_UQ4_TO_INT  TI方式UINT32的UQ4转化整形类型\n
*  LQ_TI_UINT32_UQ3_TO_INT  TI方式UINT32的UQ3转化整形类型\n
*  LQ_TI_UINT32_UQ2_TO_INT  TI方式UINT32的UQ2转化整形类型\n
*  LQ_TI_UINT32_UQ1_TO_INT  TI方式UINT32的UQ1转化整形类型\n
*/
LQ_INLINE LQ_UINT32_UQ9 LQ_TI_UINT32_UQ9_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error){
    return (LQ_UINT32_UQ9)(((LQ_I_32BIT)A + (((LQ_I_32BIT)A < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 9) - 1u) : 0)) >> 9);
}
/**@brief (TI方法)UINT32类型UQ8格式转整形
* @details 采用估算位+指数位+符号位三位结合
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    整形
* @par       将Q格式转化为整形
* @code*    LQ_TI_UINT32_UQ8_TO_INT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_UINT32_UQ32_TO_INT  TI方式UINT32的UQ32转化整形类型\n
*  LQ_TI_UINT32_UQ31_TO_INT  TI方式UINT32的UQ31转化整形类型\n
*  LQ_TI_UINT32_UQ30_TO_INT  TI方式UINT32的UQ30转化整形类型\n
*  LQ_TI_UINT32_UQ29_TO_INT  TI方式UINT32的UQ29转化整形类型\n
*  LQ_TI_UINT32_UQ28_TO_INT  TI方式UINT32的UQ28转化整形类型\n
*  LQ_TI_UINT32_UQ27_TO_INT  TI方式UINT32的UQ27转化整形类型\n
*  LQ_TI_UINT32_UQ26_TO_INT  TI方式UINT32的UQ26转化整形类型\n
*  LQ_TI_UINT32_UQ25_TO_INT  TI方式UINT32的UQ25转化整形类型\n
*  LQ_TI_UINT32_UQ24_TO_INT  TI方式UINT32的UQ24转化整形类型\n
*  LQ_TI_UINT32_UQ23_TO_INT  TI方式UINT32的UQ23转化整形类型\n
*  LQ_TI_UINT32_UQ22_TO_INT  TI方式UINT32的UQ22转化整形类型\n
*  LQ_TI_UINT32_UQ21_TO_INT  TI方式UINT32的UQ21转化整形类型\n
*  LQ_TI_UINT32_UQ20_TO_INT  TI方式UINT32的UQ20转化整形类型\n
*  LQ_TI_UINT32_UQ19_TO_INT  TI方式UINT32的UQ19转化整形类型\n
*  LQ_TI_UINT32_UQ18_TO_INT  TI方式UINT32的UQ18转化整形类型\n
*  LQ_TI_UINT32_UQ17_TO_INT  TI方式UINT32的UQ17转化整形类型\n
*  LQ_TI_UINT32_UQ16_TO_INT  TI方式UINT32的UQ16转化整形类型\n
*  LQ_TI_UINT32_UQ15_TO_INT  TI方式UINT32的UQ15转化整形类型\n
*  LQ_TI_UINT32_UQ14_TO_INT  TI方式UINT32的UQ14转化整形类型\n
*  LQ_TI_UINT32_UQ13_TO_INT  TI方式UINT32的UQ13转化整形类型\n
*  LQ_TI_UINT32_UQ12_TO_INT  TI方式UINT32的UQ12转化整形类型\n
*  LQ_TI_UINT32_UQ11_TO_INT  TI方式UINT32的UQ11转化整形类型\n
*  LQ_TI_UINT32_UQ10_TO_INT  TI方式UINT32的UQ10转化整形类型\n
*  LQ_TI_UINT32_UQ9_TO_INT  TI方式UINT32的UQ9转化整形类型\n
*  LQ_TI_UINT32_UQ8_TO_INT  TI方式UINT32的UQ8转化整形类型\n
*  LQ_TI_UINT32_UQ7_TO_INT  TI方式UINT32的UQ7转化整形类型\n
*  LQ_TI_UINT32_UQ6_TO_INT  TI方式UINT32的UQ6转化整形类型\n
*  LQ_TI_UINT32_UQ5_TO_INT  TI方式UINT32的UQ5转化整形类型\n
*  LQ_TI_UINT32_UQ4_TO_INT  TI方式UINT32的UQ4转化整形类型\n
*  LQ_TI_UINT32_UQ3_TO_INT  TI方式UINT32的UQ3转化整形类型\n
*  LQ_TI_UINT32_UQ2_TO_INT  TI方式UINT32的UQ2转化整形类型\n
*  LQ_TI_UINT32_UQ1_TO_INT  TI方式UINT32的UQ1转化整形类型\n
*/
LQ_INLINE LQ_UINT32_UQ8 LQ_TI_UINT32_UQ8_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error){
    return (LQ_UINT32_UQ8)(((LQ_I_32BIT)A + (((LQ_I_32BIT)A < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 8) - 1u) : 0)) >> 8);
}
/**@brief (TI方法)UINT32类型UQ7格式转整形
* @details 采用估算位+指数位+符号位三位结合
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    整形
* @par       将Q格式转化为整形
* @code*    LQ_TI_UINT32_UQ7_TO_INT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_UINT32_UQ32_TO_INT  TI方式UINT32的UQ32转化整形类型\n
*  LQ_TI_UINT32_UQ31_TO_INT  TI方式UINT32的UQ31转化整形类型\n
*  LQ_TI_UINT32_UQ30_TO_INT  TI方式UINT32的UQ30转化整形类型\n
*  LQ_TI_UINT32_UQ29_TO_INT  TI方式UINT32的UQ29转化整形类型\n
*  LQ_TI_UINT32_UQ28_TO_INT  TI方式UINT32的UQ28转化整形类型\n
*  LQ_TI_UINT32_UQ27_TO_INT  TI方式UINT32的UQ27转化整形类型\n
*  LQ_TI_UINT32_UQ26_TO_INT  TI方式UINT32的UQ26转化整形类型\n
*  LQ_TI_UINT32_UQ25_TO_INT  TI方式UINT32的UQ25转化整形类型\n
*  LQ_TI_UINT32_UQ24_TO_INT  TI方式UINT32的UQ24转化整形类型\n
*  LQ_TI_UINT32_UQ23_TO_INT  TI方式UINT32的UQ23转化整形类型\n
*  LQ_TI_UINT32_UQ22_TO_INT  TI方式UINT32的UQ22转化整形类型\n
*  LQ_TI_UINT32_UQ21_TO_INT  TI方式UINT32的UQ21转化整形类型\n
*  LQ_TI_UINT32_UQ20_TO_INT  TI方式UINT32的UQ20转化整形类型\n
*  LQ_TI_UINT32_UQ19_TO_INT  TI方式UINT32的UQ19转化整形类型\n
*  LQ_TI_UINT32_UQ18_TO_INT  TI方式UINT32的UQ18转化整形类型\n
*  LQ_TI_UINT32_UQ17_TO_INT  TI方式UINT32的UQ17转化整形类型\n
*  LQ_TI_UINT32_UQ16_TO_INT  TI方式UINT32的UQ16转化整形类型\n
*  LQ_TI_UINT32_UQ15_TO_INT  TI方式UINT32的UQ15转化整形类型\n
*  LQ_TI_UINT32_UQ14_TO_INT  TI方式UINT32的UQ14转化整形类型\n
*  LQ_TI_UINT32_UQ13_TO_INT  TI方式UINT32的UQ13转化整形类型\n
*  LQ_TI_UINT32_UQ12_TO_INT  TI方式UINT32的UQ12转化整形类型\n
*  LQ_TI_UINT32_UQ11_TO_INT  TI方式UINT32的UQ11转化整形类型\n
*  LQ_TI_UINT32_UQ10_TO_INT  TI方式UINT32的UQ10转化整形类型\n
*  LQ_TI_UINT32_UQ9_TO_INT  TI方式UINT32的UQ9转化整形类型\n
*  LQ_TI_UINT32_UQ8_TO_INT  TI方式UINT32的UQ8转化整形类型\n
*  LQ_TI_UINT32_UQ7_TO_INT  TI方式UINT32的UQ7转化整形类型\n
*  LQ_TI_UINT32_UQ6_TO_INT  TI方式UINT32的UQ6转化整形类型\n
*  LQ_TI_UINT32_UQ5_TO_INT  TI方式UINT32的UQ5转化整形类型\n
*  LQ_TI_UINT32_UQ4_TO_INT  TI方式UINT32的UQ4转化整形类型\n
*  LQ_TI_UINT32_UQ3_TO_INT  TI方式UINT32的UQ3转化整形类型\n
*  LQ_TI_UINT32_UQ2_TO_INT  TI方式UINT32的UQ2转化整形类型\n
*  LQ_TI_UINT32_UQ1_TO_INT  TI方式UINT32的UQ1转化整形类型\n
*/
LQ_INLINE LQ_UINT32_UQ7 LQ_TI_UINT32_UQ7_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error){
    return (LQ_UINT32_UQ7)(((LQ_I_32BIT)A + (((LQ_I_32BIT)A < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 7) - 1u) : 0)) >> 7);
}
/**@brief (TI方法)UINT32类型UQ6格式转整形
* @details 采用估算位+指数位+符号位三位结合
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    整形
* @par       将Q格式转化为整形
* @code*    LQ_TI_UINT32_UQ6_TO_INT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_UINT32_UQ32_TO_INT  TI方式UINT32的UQ32转化整形类型\n
*  LQ_TI_UINT32_UQ31_TO_INT  TI方式UINT32的UQ31转化整形类型\n
*  LQ_TI_UINT32_UQ30_TO_INT  TI方式UINT32的UQ30转化整形类型\n
*  LQ_TI_UINT32_UQ29_TO_INT  TI方式UINT32的UQ29转化整形类型\n
*  LQ_TI_UINT32_UQ28_TO_INT  TI方式UINT32的UQ28转化整形类型\n
*  LQ_TI_UINT32_UQ27_TO_INT  TI方式UINT32的UQ27转化整形类型\n
*  LQ_TI_UINT32_UQ26_TO_INT  TI方式UINT32的UQ26转化整形类型\n
*  LQ_TI_UINT32_UQ25_TO_INT  TI方式UINT32的UQ25转化整形类型\n
*  LQ_TI_UINT32_UQ24_TO_INT  TI方式UINT32的UQ24转化整形类型\n
*  LQ_TI_UINT32_UQ23_TO_INT  TI方式UINT32的UQ23转化整形类型\n
*  LQ_TI_UINT32_UQ22_TO_INT  TI方式UINT32的UQ22转化整形类型\n
*  LQ_TI_UINT32_UQ21_TO_INT  TI方式UINT32的UQ21转化整形类型\n
*  LQ_TI_UINT32_UQ20_TO_INT  TI方式UINT32的UQ20转化整形类型\n
*  LQ_TI_UINT32_UQ19_TO_INT  TI方式UINT32的UQ19转化整形类型\n
*  LQ_TI_UINT32_UQ18_TO_INT  TI方式UINT32的UQ18转化整形类型\n
*  LQ_TI_UINT32_UQ17_TO_INT  TI方式UINT32的UQ17转化整形类型\n
*  LQ_TI_UINT32_UQ16_TO_INT  TI方式UINT32的UQ16转化整形类型\n
*  LQ_TI_UINT32_UQ15_TO_INT  TI方式UINT32的UQ15转化整形类型\n
*  LQ_TI_UINT32_UQ14_TO_INT  TI方式UINT32的UQ14转化整形类型\n
*  LQ_TI_UINT32_UQ13_TO_INT  TI方式UINT32的UQ13转化整形类型\n
*  LQ_TI_UINT32_UQ12_TO_INT  TI方式UINT32的UQ12转化整形类型\n
*  LQ_TI_UINT32_UQ11_TO_INT  TI方式UINT32的UQ11转化整形类型\n
*  LQ_TI_UINT32_UQ10_TO_INT  TI方式UINT32的UQ10转化整形类型\n
*  LQ_TI_UINT32_UQ9_TO_INT  TI方式UINT32的UQ9转化整形类型\n
*  LQ_TI_UINT32_UQ8_TO_INT  TI方式UINT32的UQ8转化整形类型\n
*  LQ_TI_UINT32_UQ7_TO_INT  TI方式UINT32的UQ7转化整形类型\n
*  LQ_TI_UINT32_UQ6_TO_INT  TI方式UINT32的UQ6转化整形类型\n
*  LQ_TI_UINT32_UQ5_TO_INT  TI方式UINT32的UQ5转化整形类型\n
*  LQ_TI_UINT32_UQ4_TO_INT  TI方式UINT32的UQ4转化整形类型\n
*  LQ_TI_UINT32_UQ3_TO_INT  TI方式UINT32的UQ3转化整形类型\n
*  LQ_TI_UINT32_UQ2_TO_INT  TI方式UINT32的UQ2转化整形类型\n
*  LQ_TI_UINT32_UQ1_TO_INT  TI方式UINT32的UQ1转化整形类型\n
*/
LQ_INLINE LQ_UINT32_UQ6 LQ_TI_UINT32_UQ6_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error){
    return (LQ_UINT32_UQ6)(((LQ_I_32BIT)A + (((LQ_I_32BIT)A < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 6) - 1u) : 0)) >> 6);
}
/**@brief (TI方法)UINT32类型UQ5格式转整形
* @details 采用估算位+指数位+符号位三位结合
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    整形
* @par       将Q格式转化为整形
* @code*    LQ_TI_UINT32_UQ5_TO_INT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_UINT32_UQ32_TO_INT  TI方式UINT32的UQ32转化整形类型\n
*  LQ_TI_UINT32_UQ31_TO_INT  TI方式UINT32的UQ31转化整形类型\n
*  LQ_TI_UINT32_UQ30_TO_INT  TI方式UINT32的UQ30转化整形类型\n
*  LQ_TI_UINT32_UQ29_TO_INT  TI方式UINT32的UQ29转化整形类型\n
*  LQ_TI_UINT32_UQ28_TO_INT  TI方式UINT32的UQ28转化整形类型\n
*  LQ_TI_UINT32_UQ27_TO_INT  TI方式UINT32的UQ27转化整形类型\n
*  LQ_TI_UINT32_UQ26_TO_INT  TI方式UINT32的UQ26转化整形类型\n
*  LQ_TI_UINT32_UQ25_TO_INT  TI方式UINT32的UQ25转化整形类型\n
*  LQ_TI_UINT32_UQ24_TO_INT  TI方式UINT32的UQ24转化整形类型\n
*  LQ_TI_UINT32_UQ23_TO_INT  TI方式UINT32的UQ23转化整形类型\n
*  LQ_TI_UINT32_UQ22_TO_INT  TI方式UINT32的UQ22转化整形类型\n
*  LQ_TI_UINT32_UQ21_TO_INT  TI方式UINT32的UQ21转化整形类型\n
*  LQ_TI_UINT32_UQ20_TO_INT  TI方式UINT32的UQ20转化整形类型\n
*  LQ_TI_UINT32_UQ19_TO_INT  TI方式UINT32的UQ19转化整形类型\n
*  LQ_TI_UINT32_UQ18_TO_INT  TI方式UINT32的UQ18转化整形类型\n
*  LQ_TI_UINT32_UQ17_TO_INT  TI方式UINT32的UQ17转化整形类型\n
*  LQ_TI_UINT32_UQ16_TO_INT  TI方式UINT32的UQ16转化整形类型\n
*  LQ_TI_UINT32_UQ15_TO_INT  TI方式UINT32的UQ15转化整形类型\n
*  LQ_TI_UINT32_UQ14_TO_INT  TI方式UINT32的UQ14转化整形类型\n
*  LQ_TI_UINT32_UQ13_TO_INT  TI方式UINT32的UQ13转化整形类型\n
*  LQ_TI_UINT32_UQ12_TO_INT  TI方式UINT32的UQ12转化整形类型\n
*  LQ_TI_UINT32_UQ11_TO_INT  TI方式UINT32的UQ11转化整形类型\n
*  LQ_TI_UINT32_UQ10_TO_INT  TI方式UINT32的UQ10转化整形类型\n
*  LQ_TI_UINT32_UQ9_TO_INT  TI方式UINT32的UQ9转化整形类型\n
*  LQ_TI_UINT32_UQ8_TO_INT  TI方式UINT32的UQ8转化整形类型\n
*  LQ_TI_UINT32_UQ7_TO_INT  TI方式UINT32的UQ7转化整形类型\n
*  LQ_TI_UINT32_UQ6_TO_INT  TI方式UINT32的UQ6转化整形类型\n
*  LQ_TI_UINT32_UQ5_TO_INT  TI方式UINT32的UQ5转化整形类型\n
*  LQ_TI_UINT32_UQ4_TO_INT  TI方式UINT32的UQ4转化整形类型\n
*  LQ_TI_UINT32_UQ3_TO_INT  TI方式UINT32的UQ3转化整形类型\n
*  LQ_TI_UINT32_UQ2_TO_INT  TI方式UINT32的UQ2转化整形类型\n
*  LQ_TI_UINT32_UQ1_TO_INT  TI方式UINT32的UQ1转化整形类型\n
*/
LQ_INLINE LQ_UINT32_UQ5 LQ_TI_UINT32_UQ5_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error){
    return (LQ_UINT32_UQ5)(((LQ_I_32BIT)A + (((LQ_I_32BIT)A < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 5) - 1u) : 0)) >> 5);
}
/**@brief (TI方法)UINT32类型UQ4格式转整形
* @details 采用估算位+指数位+符号位三位结合
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    整形
* @par       将Q格式转化为整形
* @code*    LQ_TI_UINT32_UQ4_TO_INT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_UINT32_UQ32_TO_INT  TI方式UINT32的UQ32转化整形类型\n
*  LQ_TI_UINT32_UQ31_TO_INT  TI方式UINT32的UQ31转化整形类型\n
*  LQ_TI_UINT32_UQ30_TO_INT  TI方式UINT32的UQ30转化整形类型\n
*  LQ_TI_UINT32_UQ29_TO_INT  TI方式UINT32的UQ29转化整形类型\n
*  LQ_TI_UINT32_UQ28_TO_INT  TI方式UINT32的UQ28转化整形类型\n
*  LQ_TI_UINT32_UQ27_TO_INT  TI方式UINT32的UQ27转化整形类型\n
*  LQ_TI_UINT32_UQ26_TO_INT  TI方式UINT32的UQ26转化整形类型\n
*  LQ_TI_UINT32_UQ25_TO_INT  TI方式UINT32的UQ25转化整形类型\n
*  LQ_TI_UINT32_UQ24_TO_INT  TI方式UINT32的UQ24转化整形类型\n
*  LQ_TI_UINT32_UQ23_TO_INT  TI方式UINT32的UQ23转化整形类型\n
*  LQ_TI_UINT32_UQ22_TO_INT  TI方式UINT32的UQ22转化整形类型\n
*  LQ_TI_UINT32_UQ21_TO_INT  TI方式UINT32的UQ21转化整形类型\n
*  LQ_TI_UINT32_UQ20_TO_INT  TI方式UINT32的UQ20转化整形类型\n
*  LQ_TI_UINT32_UQ19_TO_INT  TI方式UINT32的UQ19转化整形类型\n
*  LQ_TI_UINT32_UQ18_TO_INT  TI方式UINT32的UQ18转化整形类型\n
*  LQ_TI_UINT32_UQ17_TO_INT  TI方式UINT32的UQ17转化整形类型\n
*  LQ_TI_UINT32_UQ16_TO_INT  TI方式UINT32的UQ16转化整形类型\n
*  LQ_TI_UINT32_UQ15_TO_INT  TI方式UINT32的UQ15转化整形类型\n
*  LQ_TI_UINT32_UQ14_TO_INT  TI方式UINT32的UQ14转化整形类型\n
*  LQ_TI_UINT32_UQ13_TO_INT  TI方式UINT32的UQ13转化整形类型\n
*  LQ_TI_UINT32_UQ12_TO_INT  TI方式UINT32的UQ12转化整形类型\n
*  LQ_TI_UINT32_UQ11_TO_INT  TI方式UINT32的UQ11转化整形类型\n
*  LQ_TI_UINT32_UQ10_TO_INT  TI方式UINT32的UQ10转化整形类型\n
*  LQ_TI_UINT32_UQ9_TO_INT  TI方式UINT32的UQ9转化整形类型\n
*  LQ_TI_UINT32_UQ8_TO_INT  TI方式UINT32的UQ8转化整形类型\n
*  LQ_TI_UINT32_UQ7_TO_INT  TI方式UINT32的UQ7转化整形类型\n
*  LQ_TI_UINT32_UQ6_TO_INT  TI方式UINT32的UQ6转化整形类型\n
*  LQ_TI_UINT32_UQ5_TO_INT  TI方式UINT32的UQ5转化整形类型\n
*  LQ_TI_UINT32_UQ4_TO_INT  TI方式UINT32的UQ4转化整形类型\n
*  LQ_TI_UINT32_UQ3_TO_INT  TI方式UINT32的UQ3转化整形类型\n
*  LQ_TI_UINT32_UQ2_TO_INT  TI方式UINT32的UQ2转化整形类型\n
*  LQ_TI_UINT32_UQ1_TO_INT  TI方式UINT32的UQ1转化整形类型\n
*/
LQ_INLINE LQ_UINT32_UQ4 LQ_TI_UINT32_UQ4_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error){
    return (LQ_UINT32_UQ4)(((LQ_I_32BIT)A + (((LQ_I_32BIT)A < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 4) - 1u) : 0)) >> 4);
}
/**@brief (TI方法)UINT32类型UQ3格式转整形
* @details 采用估算位+指数位+符号位三位结合
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    整形
* @par       将Q格式转化为整形
* @code*    LQ_TI_UINT32_UQ3_TO_INT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_UINT32_UQ32_TO_INT  TI方式UINT32的UQ32转化整形类型\n
*  LQ_TI_UINT32_UQ31_TO_INT  TI方式UINT32的UQ31转化整形类型\n
*  LQ_TI_UINT32_UQ30_TO_INT  TI方式UINT32的UQ30转化整形类型\n
*  LQ_TI_UINT32_UQ29_TO_INT  TI方式UINT32的UQ29转化整形类型\n
*  LQ_TI_UINT32_UQ28_TO_INT  TI方式UINT32的UQ28转化整形类型\n
*  LQ_TI_UINT32_UQ27_TO_INT  TI方式UINT32的UQ27转化整形类型\n
*  LQ_TI_UINT32_UQ26_TO_INT  TI方式UINT32的UQ26转化整形类型\n
*  LQ_TI_UINT32_UQ25_TO_INT  TI方式UINT32的UQ25转化整形类型\n
*  LQ_TI_UINT32_UQ24_TO_INT  TI方式UINT32的UQ24转化整形类型\n
*  LQ_TI_UINT32_UQ23_TO_INT  TI方式UINT32的UQ23转化整形类型\n
*  LQ_TI_UINT32_UQ22_TO_INT  TI方式UINT32的UQ22转化整形类型\n
*  LQ_TI_UINT32_UQ21_TO_INT  TI方式UINT32的UQ21转化整形类型\n
*  LQ_TI_UINT32_UQ20_TO_INT  TI方式UINT32的UQ20转化整形类型\n
*  LQ_TI_UINT32_UQ19_TO_INT  TI方式UINT32的UQ19转化整形类型\n
*  LQ_TI_UINT32_UQ18_TO_INT  TI方式UINT32的UQ18转化整形类型\n
*  LQ_TI_UINT32_UQ17_TO_INT  TI方式UINT32的UQ17转化整形类型\n
*  LQ_TI_UINT32_UQ16_TO_INT  TI方式UINT32的UQ16转化整形类型\n
*  LQ_TI_UINT32_UQ15_TO_INT  TI方式UINT32的UQ15转化整形类型\n
*  LQ_TI_UINT32_UQ14_TO_INT  TI方式UINT32的UQ14转化整形类型\n
*  LQ_TI_UINT32_UQ13_TO_INT  TI方式UINT32的UQ13转化整形类型\n
*  LQ_TI_UINT32_UQ12_TO_INT  TI方式UINT32的UQ12转化整形类型\n
*  LQ_TI_UINT32_UQ11_TO_INT  TI方式UINT32的UQ11转化整形类型\n
*  LQ_TI_UINT32_UQ10_TO_INT  TI方式UINT32的UQ10转化整形类型\n
*  LQ_TI_UINT32_UQ9_TO_INT  TI方式UINT32的UQ9转化整形类型\n
*  LQ_TI_UINT32_UQ8_TO_INT  TI方式UINT32的UQ8转化整形类型\n
*  LQ_TI_UINT32_UQ7_TO_INT  TI方式UINT32的UQ7转化整形类型\n
*  LQ_TI_UINT32_UQ6_TO_INT  TI方式UINT32的UQ6转化整形类型\n
*  LQ_TI_UINT32_UQ5_TO_INT  TI方式UINT32的UQ5转化整形类型\n
*  LQ_TI_UINT32_UQ4_TO_INT  TI方式UINT32的UQ4转化整形类型\n
*  LQ_TI_UINT32_UQ3_TO_INT  TI方式UINT32的UQ3转化整形类型\n
*  LQ_TI_UINT32_UQ2_TO_INT  TI方式UINT32的UQ2转化整形类型\n
*  LQ_TI_UINT32_UQ1_TO_INT  TI方式UINT32的UQ1转化整形类型\n
*/
LQ_INLINE LQ_UINT32_UQ3 LQ_TI_UINT32_UQ3_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error){
    return (LQ_UINT32_UQ3)(((LQ_I_32BIT)A + (((LQ_I_32BIT)A < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 3) - 1u) : 0)) >> 3);
}
/**@brief (TI方法)UINT32类型UQ2格式转整形
* @details 采用估算位+指数位+符号位三位结合
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    整形
* @par       将Q格式转化为整形
* @code*    LQ_TI_UINT32_UQ2_TO_INT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_UINT32_UQ32_TO_INT  TI方式UINT32的UQ32转化整形类型\n
*  LQ_TI_UINT32_UQ31_TO_INT  TI方式UINT32的UQ31转化整形类型\n
*  LQ_TI_UINT32_UQ30_TO_INT  TI方式UINT32的UQ30转化整形类型\n
*  LQ_TI_UINT32_UQ29_TO_INT  TI方式UINT32的UQ29转化整形类型\n
*  LQ_TI_UINT32_UQ28_TO_INT  TI方式UINT32的UQ28转化整形类型\n
*  LQ_TI_UINT32_UQ27_TO_INT  TI方式UINT32的UQ27转化整形类型\n
*  LQ_TI_UINT32_UQ26_TO_INT  TI方式UINT32的UQ26转化整形类型\n
*  LQ_TI_UINT32_UQ25_TO_INT  TI方式UINT32的UQ25转化整形类型\n
*  LQ_TI_UINT32_UQ24_TO_INT  TI方式UINT32的UQ24转化整形类型\n
*  LQ_TI_UINT32_UQ23_TO_INT  TI方式UINT32的UQ23转化整形类型\n
*  LQ_TI_UINT32_UQ22_TO_INT  TI方式UINT32的UQ22转化整形类型\n
*  LQ_TI_UINT32_UQ21_TO_INT  TI方式UINT32的UQ21转化整形类型\n
*  LQ_TI_UINT32_UQ20_TO_INT  TI方式UINT32的UQ20转化整形类型\n
*  LQ_TI_UINT32_UQ19_TO_INT  TI方式UINT32的UQ19转化整形类型\n
*  LQ_TI_UINT32_UQ18_TO_INT  TI方式UINT32的UQ18转化整形类型\n
*  LQ_TI_UINT32_UQ17_TO_INT  TI方式UINT32的UQ17转化整形类型\n
*  LQ_TI_UINT32_UQ16_TO_INT  TI方式UINT32的UQ16转化整形类型\n
*  LQ_TI_UINT32_UQ15_TO_INT  TI方式UINT32的UQ15转化整形类型\n
*  LQ_TI_UINT32_UQ14_TO_INT  TI方式UINT32的UQ14转化整形类型\n
*  LQ_TI_UINT32_UQ13_TO_INT  TI方式UINT32的UQ13转化整形类型\n
*  LQ_TI_UINT32_UQ12_TO_INT  TI方式UINT32的UQ12转化整形类型\n
*  LQ_TI_UINT32_UQ11_TO_INT  TI方式UINT32的UQ11转化整形类型\n
*  LQ_TI_UINT32_UQ10_TO_INT  TI方式UINT32的UQ10转化整形类型\n
*  LQ_TI_UINT32_UQ9_TO_INT  TI方式UINT32的UQ9转化整形类型\n
*  LQ_TI_UINT32_UQ8_TO_INT  TI方式UINT32的UQ8转化整形类型\n
*  LQ_TI_UINT32_UQ7_TO_INT  TI方式UINT32的UQ7转化整形类型\n
*  LQ_TI_UINT32_UQ6_TO_INT  TI方式UINT32的UQ6转化整形类型\n
*  LQ_TI_UINT32_UQ5_TO_INT  TI方式UINT32的UQ5转化整形类型\n
*  LQ_TI_UINT32_UQ4_TO_INT  TI方式UINT32的UQ4转化整形类型\n
*  LQ_TI_UINT32_UQ3_TO_INT  TI方式UINT32的UQ3转化整形类型\n
*  LQ_TI_UINT32_UQ2_TO_INT  TI方式UINT32的UQ2转化整形类型\n
*  LQ_TI_UINT32_UQ1_TO_INT  TI方式UINT32的UQ1转化整形类型\n
*/
LQ_INLINE LQ_UINT32_UQ2 LQ_TI_UINT32_UQ2_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error){
    return (LQ_UINT32_UQ2)(((LQ_I_32BIT)A + (((LQ_I_32BIT)A < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 2) - 1u) : 0)) >> 2);
}
/**@brief (TI方法)UINT32类型UQ1格式转整形
* @details 采用估算位+指数位+符号位三位结合
 * @param[in] LQ_I_32BIT     A              输入Q格式数
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    整形
* @par       将Q格式转化为整形
* @code*    LQ_TI_UINT32_UQ1_TO_INT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_UINT32_UQ32_TO_INT  TI方式UINT32的UQ32转化整形类型\n
*  LQ_TI_UINT32_UQ31_TO_INT  TI方式UINT32的UQ31转化整形类型\n
*  LQ_TI_UINT32_UQ30_TO_INT  TI方式UINT32的UQ30转化整形类型\n
*  LQ_TI_UINT32_UQ29_TO_INT  TI方式UINT32的UQ29转化整形类型\n
*  LQ_TI_UINT32_UQ28_TO_INT  TI方式UINT32的UQ28转化整形类型\n
*  LQ_TI_UINT32_UQ27_TO_INT  TI方式UINT32的UQ27转化整形类型\n
*  LQ_TI_UINT32_UQ26_TO_INT  TI方式UINT32的UQ26转化整形类型\n
*  LQ_TI_UINT32_UQ25_TO_INT  TI方式UINT32的UQ25转化整形类型\n
*  LQ_TI_UINT32_UQ24_TO_INT  TI方式UINT32的UQ24转化整形类型\n
*  LQ_TI_UINT32_UQ23_TO_INT  TI方式UINT32的UQ23转化整形类型\n
*  LQ_TI_UINT32_UQ22_TO_INT  TI方式UINT32的UQ22转化整形类型\n
*  LQ_TI_UINT32_UQ21_TO_INT  TI方式UINT32的UQ21转化整形类型\n
*  LQ_TI_UINT32_UQ20_TO_INT  TI方式UINT32的UQ20转化整形类型\n
*  LQ_TI_UINT32_UQ19_TO_INT  TI方式UINT32的UQ19转化整形类型\n
*  LQ_TI_UINT32_UQ18_TO_INT  TI方式UINT32的UQ18转化整形类型\n
*  LQ_TI_UINT32_UQ17_TO_INT  TI方式UINT32的UQ17转化整形类型\n
*  LQ_TI_UINT32_UQ16_TO_INT  TI方式UINT32的UQ16转化整形类型\n
*  LQ_TI_UINT32_UQ15_TO_INT  TI方式UINT32的UQ15转化整形类型\n
*  LQ_TI_UINT32_UQ14_TO_INT  TI方式UINT32的UQ14转化整形类型\n
*  LQ_TI_UINT32_UQ13_TO_INT  TI方式UINT32的UQ13转化整形类型\n
*  LQ_TI_UINT32_UQ12_TO_INT  TI方式UINT32的UQ12转化整形类型\n
*  LQ_TI_UINT32_UQ11_TO_INT  TI方式UINT32的UQ11转化整形类型\n
*  LQ_TI_UINT32_UQ10_TO_INT  TI方式UINT32的UQ10转化整形类型\n
*  LQ_TI_UINT32_UQ9_TO_INT  TI方式UINT32的UQ9转化整形类型\n
*  LQ_TI_UINT32_UQ8_TO_INT  TI方式UINT32的UQ8转化整形类型\n
*  LQ_TI_UINT32_UQ7_TO_INT  TI方式UINT32的UQ7转化整形类型\n
*  LQ_TI_UINT32_UQ6_TO_INT  TI方式UINT32的UQ6转化整形类型\n
*  LQ_TI_UINT32_UQ5_TO_INT  TI方式UINT32的UQ5转化整形类型\n
*  LQ_TI_UINT32_UQ4_TO_INT  TI方式UINT32的UQ4转化整形类型\n
*  LQ_TI_UINT32_UQ3_TO_INT  TI方式UINT32的UQ3转化整形类型\n
*  LQ_TI_UINT32_UQ2_TO_INT  TI方式UINT32的UQ2转化整形类型\n
*  LQ_TI_UINT32_UQ1_TO_INT  TI方式UINT32的UQ1转化整形类型\n
*/
LQ_INLINE LQ_UINT32_UQ1 LQ_TI_UINT32_UQ1_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error){
    return (LQ_UINT32_UQ1)(((LQ_I_32BIT)A + (((LQ_I_32BIT)A < 0) ? (LQ_I_32BIT)(((LQ_UI_32BIT)1 << 1) - 1u) : 0)) >> 1);
}
/**@brief (TI方法)INT8类型Q格式转整形
* @details 采用估算位+指数位+符号位三位结合
 * @param[in] LQ_I_32BIT     A              输入Q格式数
 * @param[in] LQ_UI_8BIT    Q_A             输入Q格式值
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为整形数
* @code*    LQ_TI_INT8_Q_TO_INT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_INT8_Q_TO_INT  TI方式INT8的Q转化整形类型\n
*/
LQ_INLINE LQ_INT8_Q LQ_TI_INT8_Q_TO_INT(LQ_I_32BIT A, LQ_UI_8BIT Q_A, LQ_ERROR* lq_error){
    if (Q_A >= 32u)
    {
        return (LQ_INT8_Q)0;
    }
    return (LQ_INT8_Q)(((LQ_I_32BIT)A + (((LQ_I_32BIT)A >> 31) & (LQ_I_32BIT)(((LQ_UI_32BIT)1 << Q_A) - 1u))) >> Q_A);
}
/**@brief (TI方法)UINT8类型UQ格式转整形
* @details 采用估算位+指数位+符号位三位结合
 * @param[in] LQ_I_32BIT     A              输入Q格式数
 * @param[in] LQ_UI_8BIT    Q_A             输入Q格式值
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    整形
* @par       将Q格式转化为整形
* @code*    LQ_TI_UINT8_UQ_TO_INT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_UINT8_UQ_TO_INT  TI方式UINT8的UQ转化整形类型\n
*/
LQ_INLINE LQ_UINT8_UQ LQ_TI_UINT8_UQ_TO_INT(LQ_I_32BIT A, LQ_UI_8BIT Q_A, LQ_ERROR* lq_error){
    if (Q_A >= 32u)
    {
        return (LQ_UINT8_UQ)0;
    }
    return (LQ_UINT8_UQ)(((LQ_I_32BIT)A + (((LQ_I_32BIT)A >> 31) & (LQ_I_32BIT)(((LQ_UI_32BIT)1 << Q_A) - 1u))) >> Q_A);
}
/**@brief (TI方法)INT16类型Q格式转整形
* @details 采用估算位+指数位+符号位三位结合
 * @param[in] LQ_I_32BIT     A              输入Q格式数
 * @param[in] LQ_UI_8BIT    Q_A             输入Q格式值
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为整形数
* @code*    LQ_TI_INT16_Q_TO_INT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_INT16_Q_TO_INT  TI方式INT16的Q转化整形类型\n
*/
LQ_INLINE LQ_INT16_Q LQ_TI_INT16_Q_TO_INT(LQ_I_32BIT A, LQ_UI_8BIT Q_A, LQ_ERROR* lq_error){
    if (Q_A >= 32u)
    {
        return (LQ_INT16_Q)0;
    }
    return (LQ_INT16_Q)(((LQ_I_32BIT)A + (((LQ_I_32BIT)A >> 31) & (LQ_I_32BIT)(((LQ_UI_32BIT)1 << Q_A) - 1u))) >> Q_A);
}
/**@brief (TI方法)UINT16类型UQ格式转整形
* @details 采用估算位+指数位+符号位三位结合
 * @param[in] LQ_I_32BIT     A              输入Q格式数
 * @param[in] LQ_UI_8BIT    Q_A             输入Q格式值
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    整形
* @par       将Q格式转化为整形
* @code*    LQ_TI_UINT16_UQ_TO_INT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_UINT16_UQ_TO_INT  TI方式UINT16的UQ转化整形类型\n
*/
LQ_INLINE LQ_UINT16_UQ LQ_TI_UINT16_UQ_TO_INT(LQ_I_32BIT A, LQ_UI_8BIT Q_A, LQ_ERROR* lq_error){
    if (Q_A >= 32u)
    {
        return (LQ_UINT16_UQ)0;
    }
    return (LQ_UINT16_UQ)(((LQ_I_32BIT)A + (((LQ_I_32BIT)A >> 31) & (LQ_I_32BIT)(((LQ_UI_32BIT)1 << Q_A) - 1u))) >> Q_A);
}
/**@brief (TI方法)INT32类型Q格式转整形
* @details 采用估算位+指数位+符号位三位结合
 * @param[in] LQ_I_32BIT     A              输入Q格式数
 * @param[in] LQ_UI_8BIT    Q_A             输入Q格式值
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    浮点数
* @par       将Q格式转化为整形数
* @code*    LQ_TI_INT32_Q_TO_INT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_INT32_Q_TO_INT  TI方式INT32的Q转化整形类型\n
*/
LQ_INLINE LQ_INT32_Q LQ_TI_INT32_Q_TO_INT(LQ_I_32BIT A, LQ_UI_8BIT Q_A, LQ_ERROR* lq_error){
    if (Q_A >= 32u)
    {
        return (LQ_INT32_Q)0;
    }
    return (LQ_INT32_Q)(((LQ_I_32BIT)A + (((LQ_I_32BIT)A >> 31) & (LQ_I_32BIT)(((LQ_UI_32BIT)1 << Q_A) - 1u))) >> Q_A);
}
/**@brief (TI方法)UINT32类型UQ格式转整形
* @details 采用估算位+指数位+符号位三位结合
 * @param[in] LQ_I_32BIT     A              输入Q格式数
 * @param[in] LQ_UI_8BIT    Q_A             输入Q格式值
* @param[in] LQ_ERROR*      Lq_Error       错误变量
 * @return    整形
* @par       将Q格式转化为整形
* @code*    LQ_TI_UINT32_UQ_TO_INT(a,&lq_error);
* @endcode* @attention   用户权限:用户可调用\n
*              用户更改权限:用户无需更改
* @see :: LQ_TI_UINT32_UQ_TO_INT  TI方式UINT32的UQ转化整形类型\n
*/
LQ_INLINE LQ_UINT32_UQ LQ_TI_UINT32_UQ_TO_INT(LQ_I_32BIT A, LQ_UI_8BIT Q_A, LQ_ERROR* lq_error){
    if (Q_A >= 32u)
    {
        return (LQ_UINT32_UQ)0;
    }
    return (LQ_UINT32_UQ)(((LQ_I_32BIT)A + (((LQ_I_32BIT)A >> 31) & (LQ_I_32BIT)(((LQ_UI_32BIT)1 << Q_A) - 1u))) >> Q_A);
}
#endif


#if LQ_TI_Q_FORMAT_TO_INT_LOADING_MODE == 0
/****************************INT8 TI方法 Q格式转整形************************************/
//!< 以INT8为基准翻译有符号Q格式(Q1到Q7)
LQ_INT8_Q7 LQ_TI_INT8_Q7_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error);
LQ_INT8_Q6 LQ_TI_INT8_Q6_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error);
LQ_INT8_Q5 LQ_TI_INT8_Q5_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error);
LQ_INT8_Q4 LQ_TI_INT8_Q4_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error);
LQ_INT8_Q3 LQ_TI_INT8_Q3_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error);
LQ_INT8_Q2 LQ_TI_INT8_Q2_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error);
LQ_INT8_Q1 LQ_TI_INT8_Q1_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error);
/****************************UINT8 TI方法 Q格式转整形************************************/
//!< 以UINT8为基准翻译无符号UQ格式(UQ1到UQ8)
LQ_UINT8_UQ8 LQ_TI_UINT8_UQ8_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error);
LQ_UINT8_UQ7 LQ_TI_UINT8_UQ7_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error);
LQ_UINT8_UQ6 LQ_TI_UINT8_UQ6_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error);
LQ_UINT8_UQ5 LQ_TI_UINT8_UQ5_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error);
LQ_UINT8_UQ4 LQ_TI_UINT8_UQ4_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error);
LQ_UINT8_UQ3 LQ_TI_UINT8_UQ3_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error);
LQ_UINT8_UQ2 LQ_TI_UINT8_UQ2_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error);
LQ_UINT8_UQ1 LQ_TI_UINT8_UQ1_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error);
/****************************INT16 TI方法 Q格式转整形************************************/
//!< 以INT16为基准翻译有符号Q格式(Q1到Q15)
LQ_INT16_Q15 LQ_TI_INT16_Q15_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error);
LQ_INT16_Q14 LQ_TI_INT16_Q14_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error);
LQ_INT16_Q13 LQ_TI_INT16_Q13_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error);
LQ_INT16_Q12 LQ_TI_INT16_Q12_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error);
LQ_INT16_Q11 LQ_TI_INT16_Q11_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error);
LQ_INT16_Q10 LQ_TI_INT16_Q10_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error);
LQ_INT16_Q9 LQ_TI_INT16_Q9_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error);
LQ_INT16_Q8 LQ_TI_INT16_Q8_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error);
LQ_INT16_Q7 LQ_TI_INT16_Q7_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error);
LQ_INT16_Q6 LQ_TI_INT16_Q6_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error);
LQ_INT16_Q5 LQ_TI_INT16_Q5_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error);
LQ_INT16_Q4 LQ_TI_INT16_Q4_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error);
LQ_INT16_Q3 LQ_TI_INT16_Q3_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error);
LQ_INT16_Q2 LQ_TI_INT16_Q2_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error);
LQ_INT16_Q1 LQ_TI_INT16_Q1_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error);
/****************************UINT16 TI方法 Q格式转整形************************************/
//!< 以UINT16为基准翻译无符号UQ格式(UQ1到UQ16)
LQ_UINT16_UQ16 LQ_TI_UINT16_UQ16_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error);
LQ_UINT16_UQ15 LQ_TI_UINT16_UQ15_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error);
LQ_UINT16_UQ14 LQ_TI_UINT16_UQ14_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error);
LQ_UINT16_UQ13 LQ_TI_UINT16_UQ13_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error);
LQ_UINT16_UQ12 LQ_TI_UINT16_UQ12_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error);
LQ_UINT16_UQ11 LQ_TI_UINT16_UQ11_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error);
LQ_UINT16_UQ10 LQ_TI_UINT16_UQ10_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error);
LQ_UINT16_UQ9 LQ_TI_UINT16_UQ9_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error);
LQ_UINT16_UQ8 LQ_TI_UINT16_UQ8_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error);
LQ_UINT16_UQ7 LQ_TI_UINT16_UQ7_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error);
LQ_UINT16_UQ6 LQ_TI_UINT16_UQ6_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error);
LQ_UINT16_UQ5 LQ_TI_UINT16_UQ5_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error);
LQ_UINT16_UQ4 LQ_TI_UINT16_UQ4_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error);
LQ_UINT16_UQ3 LQ_TI_UINT16_UQ3_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error);
LQ_UINT16_UQ2 LQ_TI_UINT16_UQ2_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error);
LQ_UINT16_UQ1 LQ_TI_UINT16_UQ1_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error);
/****************************INT32 TI方法 Q格式转整形************************************/
//!< 以INT32为基准翻译建有符号Q格式(Q1到Q31)
LQ_INT32_Q31 LQ_TI_INT32_Q31_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error);
LQ_INT32_Q30 LQ_TI_INT32_Q30_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error);
LQ_INT32_Q29 LQ_TI_INT32_Q29_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error);
LQ_INT32_Q28 LQ_TI_INT32_Q28_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error);
LQ_INT32_Q27 LQ_TI_INT32_Q27_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error);
LQ_INT32_Q26 LQ_TI_INT32_Q26_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error);
LQ_INT32_Q25 LQ_TI_INT32_Q25_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error);
LQ_INT32_Q24 LQ_TI_INT32_Q24_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error);
LQ_INT32_Q23 LQ_TI_INT32_Q23_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error);
LQ_INT32_Q22 LQ_TI_INT32_Q22_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error);
LQ_INT32_Q21 LQ_TI_INT32_Q21_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error);
LQ_INT32_Q20 LQ_TI_INT32_Q20_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error);
LQ_INT32_Q19 LQ_TI_INT32_Q19_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error);
LQ_INT32_Q18 LQ_TI_INT32_Q18_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error);
LQ_INT32_Q17 LQ_TI_INT32_Q17_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error);
LQ_INT32_Q16 LQ_TI_INT32_Q16_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error);
LQ_INT32_Q15 LQ_TI_INT32_Q15_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error);
LQ_INT32_Q14 LQ_TI_INT32_Q14_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error);
LQ_INT32_Q13 LQ_TI_INT32_Q13_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error);
LQ_INT32_Q12 LQ_TI_INT32_Q12_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error);
LQ_INT32_Q11 LQ_TI_INT32_Q11_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error);
LQ_INT32_Q10 LQ_TI_INT32_Q10_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error);
LQ_INT32_Q9 LQ_TI_INT32_Q9_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error);
LQ_INT32_Q8 LQ_TI_INT32_Q8_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error);
LQ_INT32_Q7 LQ_TI_INT32_Q7_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error);
LQ_INT32_Q6 LQ_TI_INT32_Q6_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error);
LQ_INT32_Q5 LQ_TI_INT32_Q5_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error);
LQ_INT32_Q4 LQ_TI_INT32_Q4_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error);
LQ_INT32_Q3 LQ_TI_INT32_Q3_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error);
LQ_INT32_Q2 LQ_TI_INT32_Q2_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error);
LQ_INT32_Q1 LQ_TI_INT32_Q1_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error);
/****************************UINT32 TI方法 Q格式转整形************************************/
//!< 以UINT32为基准翻译无符号UQ格式(UQ1到UQ32)
LQ_UINT32_UQ32 LQ_TI_UINT32_UQ32_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error);
LQ_UINT32_UQ31 LQ_TI_UINT32_UQ31_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error);
LQ_UINT32_UQ30 LQ_TI_UINT32_UQ30_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error);
LQ_UINT32_UQ29 LQ_TI_UINT32_UQ29_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error);
LQ_UINT32_UQ28 LQ_TI_UINT32_UQ28_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error);
LQ_UINT32_UQ27 LQ_TI_UINT32_UQ27_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error);
LQ_UINT32_UQ26 LQ_TI_UINT32_UQ26_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error);
LQ_UINT32_UQ25 LQ_TI_UINT32_UQ25_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error);
LQ_UINT32_UQ24 LQ_TI_UINT32_UQ24_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error);
LQ_UINT32_UQ23 LQ_TI_UINT32_UQ23_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error);
LQ_UINT32_UQ22 LQ_TI_UINT32_UQ22_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error);
LQ_UINT32_UQ21 LQ_TI_UINT32_UQ21_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error);
LQ_UINT32_UQ20 LQ_TI_UINT32_UQ20_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error);
LQ_UINT32_UQ19 LQ_TI_UINT32_UQ19_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error);
LQ_UINT32_UQ18 LQ_TI_UINT32_UQ18_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error);
LQ_UINT32_UQ17 LQ_TI_UINT32_UQ17_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error);
LQ_UINT32_UQ16 LQ_TI_UINT32_UQ16_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error);
LQ_UINT32_UQ15 LQ_TI_UINT32_UQ15_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error);
LQ_UINT32_UQ14 LQ_TI_UINT32_UQ14_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error);
LQ_UINT32_UQ13 LQ_TI_UINT32_UQ13_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error);
LQ_UINT32_UQ12 LQ_TI_UINT32_UQ12_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error);
LQ_UINT32_UQ11 LQ_TI_UINT32_UQ11_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error);
LQ_UINT32_UQ10 LQ_TI_UINT32_UQ10_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error);
LQ_UINT32_UQ9 LQ_TI_UINT32_UQ9_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error);
LQ_UINT32_UQ8 LQ_TI_UINT32_UQ8_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error);
LQ_UINT32_UQ7 LQ_TI_UINT32_UQ7_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error);
LQ_UINT32_UQ6 LQ_TI_UINT32_UQ6_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error);
LQ_UINT32_UQ5 LQ_TI_UINT32_UQ5_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error);
LQ_UINT32_UQ4 LQ_TI_UINT32_UQ4_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error);
LQ_UINT32_UQ3 LQ_TI_UINT32_UQ3_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error);
LQ_UINT32_UQ2 LQ_TI_UINT32_UQ2_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error);
LQ_UINT32_UQ1 LQ_TI_UINT32_UQ1_TO_INT(LQ_I_32BIT A, LQ_ERROR* lq_error);
/****************************INT8 TI Q格式转整形(任意Q格式)************************************/
//!< 以INT8为基准翻译有符号Q格式(Q1到Q7)
LQ_INT8_Q LQ_TI_INT8_Q_TO_INT(LQ_I_32BIT A, LQ_UI_8BIT Q_A, LQ_ERROR* lq_error);
/****************************UINT8 TI UQ格式转整形(任意UQ格式)************************************/
//!< 以UINT8为基准翻译有符号UQ格式(UQ1到UQ8)
LQ_UINT8_UQ LQ_TI_UINT8_UQ_TO_INT(LQ_I_32BIT A, LQ_UI_8BIT Q_A, LQ_ERROR* lq_error);
/****************************INT16 TI Q格式转整形(任意Q格式)************************************/
//!< 以INT16为基准翻译有符号Q格式(Q1到Q15)
LQ_INT16_Q LQ_TI_INT16_Q_TO_INT(LQ_I_32BIT A, LQ_UI_8BIT Q_A, LQ_ERROR* lq_error);
/****************************UINT16 TI UQ格式转整形(任意UQ格式)************************************/
//!< 以UINT16为基准翻译有符号UQ格式(UQ1到UQ16)
LQ_UINT16_UQ LQ_TI_UINT16_UQ_TO_INT(LQ_I_32BIT A, LQ_UI_8BIT Q_A, LQ_ERROR* lq_error);
/****************************INT32 TI Q格式转整形(任意Q格式)************************************/
//!< 以INT32为基准翻译有符号Q格式(Q1到Q31)
LQ_INT32_Q LQ_TI_INT32_Q_TO_INT(LQ_I_32BIT A, LQ_UI_8BIT Q_A, LQ_ERROR* lq_error);
/****************************UINT32 TI UQ格式转整形(任意UQ格式)************************************/
//!< 以UINT32为基准翻译有符号UQ格式(UQ1到UQ32)
LQ_UINT32_UQ LQ_TI_UINT32_UQ_TO_INT(LQ_I_32BIT A, LQ_UI_8BIT Q_A, LQ_ERROR* lq_error);

#endif

#endif
