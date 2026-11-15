#ifndef __LQ_ARM_DSP_H__
#define __LQ_ARM_DSP_H__
#include "lq_mode.h"
#include "lq_type.h"
/**@file      lq_arm_dsp.h
* @brief      LittleQmath的ARM DSP饱和指令映射
* @details    把ARM处理器的SSAT/USAT饱和指令封装为统一的LQ_Q_SSAT/LQ_Q_USAT。\nAC5走__ssat/__usat，AC6与GCC走__builtin_arm_ssat/__builtin_arm_usat，\n非ARM平台自动回退为按位宽钳位的等价实现。\n只在LQ_ARM_DSP_SSAT_ENABLE为1时生效。
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

//!<第二位参数N必须是编译期常量(取8或16时对应1条SSAT指令)
/* 目标内核是否具备SSAT/USAT指令: Cortex-M0/M0+(ARMv6-M)没有 */
#if defined(__CC_ARM)
#if defined(__TARGET_ARCH_THUMB) && (__TARGET_ARCH_THUMB < 4)
#define LQ_ARM_DSP_SSAT_HAS_INSN 0
#else
#define LQ_ARM_DSP_SSAT_HAS_INSN 1
#endif
#elif defined(__ARM_FEATURE_SAT) || defined(__ARM_FEATURE_DSP)
#define LQ_ARM_DSP_SSAT_HAS_INSN 1
#else
#define LQ_ARM_DSP_SSAT_HAS_INSN 0
#endif

/* 有硬件SSAT/USAT指令时映射为内建指令,否则用下面的可移植钳位 */
#if LQ_ARM_DSP_SSAT_HAS_INSN == 1
#if defined(__CC_ARM)
/* ARMCC(AC5):内建映射指令 */
#define LQ_Q_SSAT(X, N)          __ssat((X), (N))
#define LQ_Q_USAT(X, N)          __usat((X), (N))
#else
/* ARMCLANG(AC6)/GCC:内建映射指令 */
#define LQ_Q_SSAT(X, N)          __builtin_arm_ssat((X), (N))
#define LQ_Q_USAT(X, N)          __builtin_arm_usat((X), (N))
#endif
#define LQ_ARM_DSP_SSAT_NATIVE   1
#else
/* 可移植:定位宽钳位,结果与SSAT/USAT一致(ARMv6-M与非ARM平台) */
#define LQ_ARM_DSP_SSAT_NATIVE   0

LQ_INLINE LQ_I_32BIT LQ_ARM_DSP_SSAT_PORTABLE(LQ_I_32BIT X, LQ_I_32BIT N)
{
    LQ_I_32BIT lq_max;
    LQ_I_32BIT lq_min;
    lq_max = (LQ_I_32BIT)(((LQ_UI_32BIT)1 << (N - 1)) - 1U);
    lq_min = (LQ_I_32BIT)(~lq_max);
    if (X > lq_max)
    {
        return lq_max;
    }
    if (X < lq_min)
    {
        return lq_min;
    }
    return X;
}

/* 与__usat语义一致:入参按有符号解释,负数饱和到0 */
LQ_INLINE LQ_UI_32BIT LQ_ARM_DSP_USAT_PORTABLE(LQ_I_32BIT X, LQ_I_32BIT N)
{
    LQ_UI_32BIT lq_max;
    if (X <= 0)
    {
        return 0U;
    }
    if (N >= 32)
    {
        return (LQ_UI_32BIT)X;
    }
    lq_max = (LQ_UI_32BIT)(((LQ_UI_32BIT)1 << N) - 1U);
    if ((LQ_UI_32BIT)X > lq_max)
    {
        return lq_max;
    }
    return (LQ_UI_32BIT)X;
}

#define LQ_Q_SSAT(X, N)          LQ_ARM_DSP_SSAT_PORTABLE((LQ_I_32BIT)(X), (N))
#define LQ_Q_USAT(X, N)          LQ_ARM_DSP_USAT_PORTABLE((LQ_I_32BIT)(X), (N))
#endif

#endif
#endif
