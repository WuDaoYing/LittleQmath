#ifndef __LQ_MODE_H__
#define __LQ_MODE_H__

/**@file      lq_mode.h
* @brief      LittleQmath重载模式切换
* @details    128bit可选择函数模式、内联模式进行切换。\n
*             四则运算符可选择函数模式、内联模式、宏展开进行切换。\n
*             sin、cos函数可选择函数模式、内联模式进行切换。
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
 
 
//!<ARM DSP饱和指令加速开关  0 失能  1 使能
//!<注意：使能后饱和加法、减法、除法的INT8/INT16有符号接口(每族22个,共66个)改用SSAT指令实现，
//!<      函数模式、内联模式、宏展开模式同时生效；编译器需支持SSAT(AC5/AC6/GCC均可)，
//!<      非ARM平台自动回退为等价的按位宽钳位实现。
#define LQ_ARM_DSP_SSAT_ENABLE             1

//!<开方算法选择  0 牛顿迭代(硬件除法内核更快)  1 逐位试探(无除法,适合Cortex-M0/M0+/M1)
//!<默认按编译目标自动判断:ARMv6-M/ARMv8-M Baseline(无硬件除法)置1,其余置0;也可手动强制。
//!<逐位试探仅用移位/加法/比较,不产生udiv或__aeabi_uidiv/__aeabi_uldivmod调用。
//!<两个内核均位于lq_sqrt_bitwise_root.c/.h,由本开关选择。
//!<注意:移植到Cortex-M0/M0+时编译选项必须与目标内核一致(如--cpu Cortex-M0+),否则其余除法仍按所选内核生成指令。
#ifndef LQ_SQRT_NODIV_ENABLE
#if defined(__ARM_ARCH_6M__) || defined(__ARM_ARCH_8M_BASE__) || (defined(__TARGET_ARCH_THUMB) && (__TARGET_ARCH_THUMB == 3))
#define LQ_SQRT_NODIV_ENABLE               1
#else
#define LQ_SQRT_NODIV_ENABLE               0
#endif
#endif
//!<arctan2近似曲线族的除法选择 0 无符号整除(硬件除法或__aeabi_uldivmod更快) 1 32位逐位除法(无除法,适合Cortex-M0/M0+/M1)
//!<默认按编译目标自动判断:ARMv6-M/ARMv8-M Baseline(无硬件除法)置1,其余置0;也可手动强制。
//!<逐位除法仅用移位/加减/比较,不产生64位除法或__aeabi_uldivmod/__aeabi_ldivmod调用,商与原式逐位一致。
#ifndef LQ_ARCTAN2_NODIV_ENABLE
#if defined(__ARM_ARCH_6M__) || defined(__ARM_ARCH_8M_BASE__) || (defined(__TARGET_ARCH_THUMB) && (__TARGET_ARCH_THUMB == 3))
#define LQ_ARCTAN2_NODIV_ENABLE            1
#else
#define LQ_ARCTAN2_NODIV_ENABLE            0
#endif
#endif

//!<CORDIC深度表旋转乘法项选择 0 保留(v*2^(Q-k))>>Q查表乘法 1 改为算术右移v>>k
//!<默认按编译目标自动判断:ARMv6-M/ARMv8-M Baseline(无64位乘法指令,需调用__aeabi_lmul)置1,其余置0;也可手动强制。
//!<索引表满足INDEX_TABLE[k]=2^(Q-k)(k>=1),故(v*INDEX_TABLE[k])>>Q与v>>k逐位一致;
//!<最大Q表(Q31/Q15/Q7)的INDEX_TABLE[0]=2^Q-1,其第0级仍保留查表乘法。
//!<使能后每级省去两次32x32->64位乘法(__aeabi_lmul调用),Cortex-M0上每级迭代指令数约降三成。
#ifndef LQ_CORDIC_SHIFT_ENABLE
#if defined(__ARM_ARCH_6M__) || defined(__ARM_ARCH_8M_BASE__) || (defined(__TARGET_ARCH_THUMB) && (__TARGET_ARCH_THUMB == 3))
#define LQ_CORDIC_SHIFT_ENABLE             1
#else
#define LQ_CORDIC_SHIFT_ENABLE             0
#endif
#endif

//!<TI版本Q转浮点归一化方式选择 0 保留逐位移位循环 1 前导零个数O(1)规格化
//!<默认按编译目标自动判断:有单周期CLZ指令的ARMv7-M/ARMv8-M Mainline及其它平台置1,
//!<ARMv6-M/ARMv8-M Baseline(M0/M0+/M1,__clz为库函数)置0;也可手动强制。
//!<M0上逐位移位每次迭代仅3条指令,对满幅输入比库函数调用更快;M3上CLZ单周期且省去寄存器压栈。
#ifndef LQ_TI_Q_FORMAT_TO_FLOAT_CLZ_ENABLE
#if defined(__ARM_FEATURE_CLZ) || (defined(__ARM_ARCH) && (__ARM_ARCH >= 7)) || (defined(__TARGET_ARCH_THUMB) && (__TARGET_ARCH_THUMB >= 4))
#define LQ_TI_Q_FORMAT_TO_FLOAT_CLZ_ENABLE  1
#elif defined(__ARM_ARCH_6M__) || defined(__ARM_ARCH_8M_BASE__) || (defined(__TARGET_ARCH_THUMB) && (__TARGET_ARCH_THUMB == 3))
#define LQ_TI_Q_FORMAT_TO_FLOAT_CLZ_ENABLE  0
#else
#define LQ_TI_Q_FORMAT_TO_FLOAT_CLZ_ENABLE  1
#endif
#endif



//!<四则运算全局模式 :0 函数模式 1内联模式 2宏展开
//!<注意：函数模式、内联模式和宏展开模式都进行溢出检测
#define LQ_OPERATIONS_GLOBAL_MODE          0


 

 //!<饱和算法:浮点转Q格式装载模式 :0 函数模式 1内联模式 2宏展开
#define LQ_SATURATION_FLOAT_TO_Q_FORMAT_LOADING_MODE        1
 //!<不饱和算法:浮点转Q格式装载模式 :0 函数模式 1内联模式 2宏展开
#define LQ_UNSATURATION_FLOAT_TO_Q_FORMAT_LOADING_MODE      1

 //!<饱和算法:整形转Q格式装载模式 :0 函数模式 1内联模式 2宏展开
#define LQ_SATURATION_INT_TO_Q_FORMAT_LOADING_MODE          1
 //!<不饱和算法:整形转Q格式装载模式 :0 函数模式 1内联模式 2宏展开
#define LQ_UNSATURATION_INT_TO_Q_FORMAT_LOADING_MODE        1

 //!<ti版本的Q格式转浮点装载模式 :0 函数模式 1内联模式 2宏展开
#define LQ_TI_Q_FORMAT_TO_FLOAT_LOADING_MODE                1
 //!<Q格式转浮点装载模式 :0 函数模式 1内联模式 2宏展开
#define LQ_Q_FORMAT_TO_FLOAT_LOADING_MODE                   1

 //!<ti版本的Q格式转整形装载模式 :0 函数模式 1内联模式 2宏展开
#define LQ_TI_Q_FORMAT_TO_INT_LOADING_MODE                  1
 //!<Q格式转整形装载模式 :0 函数模式 1内联模式 2宏展开
#define LQ_Q_FORMAT_TO_INT_LOADING_MODE                     1



 //!<饱和类型:Q格式类型加法装载模式 :0 函数模式 1内联模式 2宏展开
#define LQ_SATURATION_Q_FORMAT_ADD_LOADING_MODE             0
 //!<不饱和类型:Q格式类型加法装载模式 :0 函数模式 1内联模式 2宏展开
#define LQ_UNSATURATION_Q_FORMAT_ADD_LOADING_MODE           1

 //!<饱和类型:Q格式类型减法装载模式 :0 函数模式 1内联模式 2宏展开
#define LQ_SATURATION_Q_FORMAT_SUB_LOADING_MODE             0
 //!<不饱和类型:Q格式类型减法装载模式 :0 函数模式 1内联模式 2宏展开
#define LQ_UNSATURATION_Q_FORMAT_SUB_LOADING_MODE           1

 //!<饱和类型:Q格式类型乘法装载模式 :0 函数模式 1内联模式 2宏展开
#define LQ_SATURATION_Q_FORMAT_MUL_LOADING_MODE             1
 //!<不饱和类型:Q格式类型乘法装载模式 :0 函数模式 1内联模式 2宏展开
#define LQ_UNSATURATION_Q_FORMAT_MUL_LOADING_MODE           1

 //!<饱和类型:Q格式类型除法装载模式 :0 函数模式 1内联模式 2宏展开
#define LQ_SATURATION_Q_FORMAT_DIV_LOADING_MODE             1
 //!<不饱和类型:Q格式类型除法装载模式 :0 函数模式 1内联模式 2宏展开
#define LQ_UNSATURATION_Q_FORMAT_DIV_LOADING_MODE           1

 //!<饱和类型:Q格式到Q格式转换装载模式 :0 函数模式 1内联模式 2宏展开
#define LQ_SATURATION_Q_FORMAT_TO_Q_FORMAT_LOADING_MODE     1

 //!<不饱和类型:Q格式到Q格式转换装载模式 :0 函数模式 1内联模式 2宏展开
#define LQ_UNSATURATION_Q_FORMAT_TO_Q_FORMAT_LOADING_MODE   1

 //!<Q格式开根：牛顿迭代法装载模式 :0 函数模式 1内联模式
//!<默认按编译目标自动判断:ARMv6-M/ARMv8-M Baseline(M0/M0+/M1)置0,其余(含Cortex-M3及以上)置1
#ifndef LQ_SQRT_NEWTON_ITERATION_LOADING_MODE
#if defined(__ARM_ARCH_6M__) || defined(__ARM_ARCH_8M_BASE__) || (defined(__TARGET_ARCH_THUMB) && (__TARGET_ARCH_THUMB == 3))
#define LQ_SQRT_NEWTON_ITERATION_LOADING_MODE            0
#else
#define LQ_SQRT_NEWTON_ITERATION_LOADING_MODE            1
#endif
#endif

 //!<Q格式开根：无除法逐位试探法装载模式 :0 函数模式 1内联模式
#define LQ_SQRT_BITWISE_ROOT_LOADING_MODE            0

 //!<Q格式arctan曲线拟合法装载模式 :0 函数模式 1内联模式
#define LQ_ARCTAN2_PU_APPROXIMATE_CURVE_LOADING_MODE            0

 //!<Q格式arctan曲线拟合法装载模式 :0 函数模式 1内联模式
#define LQ_FLOAT_TO_Q_VALUE_TYPE_LOADING_MODE           1

 

//!<Q格式细分表是否使能      0 失能      1使能
#define LQ_SIN_COS_PU_512_SUBDIVIDE_ENABLE       0
#define LQ_SIN_COS_PU_1024_SUBDIVIDE_ENABLE       0
#define LQ_SIN_COS_PU_2048_SUBDIVIDE_ENABLE       0
#define LQ_SIN_COS_PU_4096_SUBDIVIDE_ENABLE       0
#define LQ_SIN_COS_PU_8192_SUBDIVIDE_ENABLE       0
#define LQ_SIN_COS_PU_16384_SUBDIVIDE_ENABLE       0
#define LQ_SIN_COS_PU_32768_SUBDIVIDE_ENABLE       1
//!<Q格式每单位SIN_COS变换中Q格式是否使能     0失能    1使能
#define LQ_INT8_Q1_SIN_COS_PU_SUBDIVIDE_ENABLE           0
#define LQ_INT8_Q2_SIN_COS_PU_SUBDIVIDE_ENABLE           0
#define LQ_INT8_Q3_SIN_COS_PU_SUBDIVIDE_ENABLE           0
#define LQ_INT8_Q4_SIN_COS_PU_SUBDIVIDE_ENABLE           0
#define LQ_INT8_Q5_SIN_COS_PU_SUBDIVIDE_ENABLE           0
#define LQ_INT8_Q6_SIN_COS_PU_SUBDIVIDE_ENABLE           0
#define LQ_INT8_Q7_SIN_COS_PU_SUBDIVIDE_ENABLE           0
#define LQ_INT16_Q1_SIN_COS_PU_SUBDIVIDE_ENABLE           0
#define LQ_INT16_Q2_SIN_COS_PU_SUBDIVIDE_ENABLE           0
#define LQ_INT16_Q3_SIN_COS_PU_SUBDIVIDE_ENABLE           0
#define LQ_INT16_Q4_SIN_COS_PU_SUBDIVIDE_ENABLE           0
#define LQ_INT16_Q5_SIN_COS_PU_SUBDIVIDE_ENABLE           0
#define LQ_INT16_Q6_SIN_COS_PU_SUBDIVIDE_ENABLE           0
#define LQ_INT16_Q7_SIN_COS_PU_SUBDIVIDE_ENABLE           0
#define LQ_INT16_Q8_SIN_COS_PU_SUBDIVIDE_ENABLE           0
#define LQ_INT16_Q9_SIN_COS_PU_SUBDIVIDE_ENABLE           0
#define LQ_INT16_Q10_SIN_COS_PU_SUBDIVIDE_ENABLE           0
#define LQ_INT16_Q11_SIN_COS_PU_SUBDIVIDE_ENABLE           0
#define LQ_INT16_Q12_SIN_COS_PU_SUBDIVIDE_ENABLE           0
#define LQ_INT16_Q13_SIN_COS_PU_SUBDIVIDE_ENABLE           0
#define LQ_INT16_Q14_SIN_COS_PU_SUBDIVIDE_ENABLE           0
#define LQ_INT16_Q15_SIN_COS_PU_SUBDIVIDE_ENABLE           0
#define LQ_INT32_Q1_SIN_COS_PU_SUBDIVIDE_ENABLE           0
#define LQ_INT32_Q2_SIN_COS_PU_SUBDIVIDE_ENABLE           0
#define LQ_INT32_Q3_SIN_COS_PU_SUBDIVIDE_ENABLE           0
#define LQ_INT32_Q4_SIN_COS_PU_SUBDIVIDE_ENABLE           0
#define LQ_INT32_Q5_SIN_COS_PU_SUBDIVIDE_ENABLE           0
#define LQ_INT32_Q6_SIN_COS_PU_SUBDIVIDE_ENABLE           0
#define LQ_INT32_Q7_SIN_COS_PU_SUBDIVIDE_ENABLE           0
#define LQ_INT32_Q8_SIN_COS_PU_SUBDIVIDE_ENABLE           0
#define LQ_INT32_Q9_SIN_COS_PU_SUBDIVIDE_ENABLE           0
#define LQ_INT32_Q10_SIN_COS_PU_SUBDIVIDE_ENABLE           0
#define LQ_INT32_Q11_SIN_COS_PU_SUBDIVIDE_ENABLE           0
#define LQ_INT32_Q12_SIN_COS_PU_SUBDIVIDE_ENABLE           0
#define LQ_INT32_Q13_SIN_COS_PU_SUBDIVIDE_ENABLE           0
#define LQ_INT32_Q14_SIN_COS_PU_SUBDIVIDE_ENABLE           0
#define LQ_INT32_Q15_SIN_COS_PU_SUBDIVIDE_ENABLE           0
#define LQ_INT32_Q16_SIN_COS_PU_SUBDIVIDE_ENABLE           0
#define LQ_INT32_Q17_SIN_COS_PU_SUBDIVIDE_ENABLE           0
#define LQ_INT32_Q18_SIN_COS_PU_SUBDIVIDE_ENABLE           0
#define LQ_INT32_Q19_SIN_COS_PU_SUBDIVIDE_ENABLE           0
#define LQ_INT32_Q20_SIN_COS_PU_SUBDIVIDE_ENABLE           0
#define LQ_INT32_Q21_SIN_COS_PU_SUBDIVIDE_ENABLE           0
#define LQ_INT32_Q22_SIN_COS_PU_SUBDIVIDE_ENABLE           0
#define LQ_INT32_Q23_SIN_COS_PU_SUBDIVIDE_ENABLE           0
#define LQ_INT32_Q24_SIN_COS_PU_SUBDIVIDE_ENABLE           0
#define LQ_INT32_Q25_SIN_COS_PU_SUBDIVIDE_ENABLE           0
#define LQ_INT32_Q26_SIN_COS_PU_SUBDIVIDE_ENABLE           0
#define LQ_INT32_Q27_SIN_COS_PU_SUBDIVIDE_ENABLE           0
#define LQ_INT32_Q28_SIN_COS_PU_SUBDIVIDE_ENABLE           0
#define LQ_INT32_Q29_SIN_COS_PU_SUBDIVIDE_ENABLE           0
#define LQ_INT32_Q30_SIN_COS_PU_SUBDIVIDE_ENABLE           0
#define LQ_INT32_Q31_SIN_COS_PU_SUBDIVIDE_ENABLE           1


#define LQ_SIN_COS_PU_SUBDIVIDE_LOADING_MODE     1              //!<sin/cos细分查表法:0 函数模式 1内联模式


//!<Q格式细分表是否使能      0 失能      1使能
#define LQ_ARCSIN_ARCCOS_PU_512_SUBDIVIDE_ENABLE       0
#define LQ_ARCSIN_ARCCOS_PU_1024_SUBDIVIDE_ENABLE       0
#define LQ_ARCSIN_ARCCOS_PU_2048_SUBDIVIDE_ENABLE       0
#define LQ_ARCSIN_ARCCOS_PU_4096_SUBDIVIDE_ENABLE       0
#define LQ_ARCSIN_ARCCOS_PU_8192_SUBDIVIDE_ENABLE       0
#define LQ_ARCSIN_ARCCOS_PU_16384_SUBDIVIDE_ENABLE       0
#define LQ_ARCSIN_ARCCOS_PU_32768_SUBDIVIDE_ENABLE       1
//!<Q格式每单位ARCSIN_ARCCOS变换中Q格式是否使能     0失能    1使能
#define LQ_INT8_Q1_ARCSIN_ARCCOS_PU_SUBDIVIDE_ENABLE           0
#define LQ_INT8_Q2_ARCSIN_ARCCOS_PU_SUBDIVIDE_ENABLE           0
#define LQ_INT8_Q3_ARCSIN_ARCCOS_PU_SUBDIVIDE_ENABLE           0
#define LQ_INT8_Q4_ARCSIN_ARCCOS_PU_SUBDIVIDE_ENABLE           0
#define LQ_INT8_Q5_ARCSIN_ARCCOS_PU_SUBDIVIDE_ENABLE           0
#define LQ_INT8_Q6_ARCSIN_ARCCOS_PU_SUBDIVIDE_ENABLE           0
#define LQ_INT8_Q7_ARCSIN_ARCCOS_PU_SUBDIVIDE_ENABLE           0
#define LQ_INT16_Q1_ARCSIN_ARCCOS_PU_SUBDIVIDE_ENABLE           0
#define LQ_INT16_Q2_ARCSIN_ARCCOS_PU_SUBDIVIDE_ENABLE           0
#define LQ_INT16_Q3_ARCSIN_ARCCOS_PU_SUBDIVIDE_ENABLE           0
#define LQ_INT16_Q4_ARCSIN_ARCCOS_PU_SUBDIVIDE_ENABLE           0
#define LQ_INT16_Q5_ARCSIN_ARCCOS_PU_SUBDIVIDE_ENABLE           0
#define LQ_INT16_Q6_ARCSIN_ARCCOS_PU_SUBDIVIDE_ENABLE           0
#define LQ_INT16_Q7_ARCSIN_ARCCOS_PU_SUBDIVIDE_ENABLE           0
#define LQ_INT16_Q8_ARCSIN_ARCCOS_PU_SUBDIVIDE_ENABLE           0
#define LQ_INT16_Q9_ARCSIN_ARCCOS_PU_SUBDIVIDE_ENABLE           0
#define LQ_INT16_Q10_ARCSIN_ARCCOS_PU_SUBDIVIDE_ENABLE           0
#define LQ_INT16_Q11_ARCSIN_ARCCOS_PU_SUBDIVIDE_ENABLE           0
#define LQ_INT16_Q12_ARCSIN_ARCCOS_PU_SUBDIVIDE_ENABLE           0
#define LQ_INT16_Q13_ARCSIN_ARCCOS_PU_SUBDIVIDE_ENABLE           0
#define LQ_INT16_Q14_ARCSIN_ARCCOS_PU_SUBDIVIDE_ENABLE           0
#define LQ_INT16_Q15_ARCSIN_ARCCOS_PU_SUBDIVIDE_ENABLE           0
#define LQ_INT32_Q1_ARCSIN_ARCCOS_PU_SUBDIVIDE_ENABLE           0
#define LQ_INT32_Q2_ARCSIN_ARCCOS_PU_SUBDIVIDE_ENABLE           0
#define LQ_INT32_Q3_ARCSIN_ARCCOS_PU_SUBDIVIDE_ENABLE           0
#define LQ_INT32_Q4_ARCSIN_ARCCOS_PU_SUBDIVIDE_ENABLE           0
#define LQ_INT32_Q5_ARCSIN_ARCCOS_PU_SUBDIVIDE_ENABLE           0
#define LQ_INT32_Q6_ARCSIN_ARCCOS_PU_SUBDIVIDE_ENABLE           0
#define LQ_INT32_Q7_ARCSIN_ARCCOS_PU_SUBDIVIDE_ENABLE           0
#define LQ_INT32_Q8_ARCSIN_ARCCOS_PU_SUBDIVIDE_ENABLE           0
#define LQ_INT32_Q9_ARCSIN_ARCCOS_PU_SUBDIVIDE_ENABLE           0
#define LQ_INT32_Q10_ARCSIN_ARCCOS_PU_SUBDIVIDE_ENABLE           0
#define LQ_INT32_Q11_ARCSIN_ARCCOS_PU_SUBDIVIDE_ENABLE           0
#define LQ_INT32_Q12_ARCSIN_ARCCOS_PU_SUBDIVIDE_ENABLE           0
#define LQ_INT32_Q13_ARCSIN_ARCCOS_PU_SUBDIVIDE_ENABLE           0
#define LQ_INT32_Q14_ARCSIN_ARCCOS_PU_SUBDIVIDE_ENABLE           0
#define LQ_INT32_Q15_ARCSIN_ARCCOS_PU_SUBDIVIDE_ENABLE           0
#define LQ_INT32_Q16_ARCSIN_ARCCOS_PU_SUBDIVIDE_ENABLE           0
#define LQ_INT32_Q17_ARCSIN_ARCCOS_PU_SUBDIVIDE_ENABLE           0
#define LQ_INT32_Q18_ARCSIN_ARCCOS_PU_SUBDIVIDE_ENABLE           0
#define LQ_INT32_Q19_ARCSIN_ARCCOS_PU_SUBDIVIDE_ENABLE           0
#define LQ_INT32_Q20_ARCSIN_ARCCOS_PU_SUBDIVIDE_ENABLE           0
#define LQ_INT32_Q21_ARCSIN_ARCCOS_PU_SUBDIVIDE_ENABLE           0
#define LQ_INT32_Q22_ARCSIN_ARCCOS_PU_SUBDIVIDE_ENABLE           0
#define LQ_INT32_Q23_ARCSIN_ARCCOS_PU_SUBDIVIDE_ENABLE           0
#define LQ_INT32_Q24_ARCSIN_ARCCOS_PU_SUBDIVIDE_ENABLE           0
#define LQ_INT32_Q25_ARCSIN_ARCCOS_PU_SUBDIVIDE_ENABLE           0
#define LQ_INT32_Q26_ARCSIN_ARCCOS_PU_SUBDIVIDE_ENABLE           0
#define LQ_INT32_Q27_ARCSIN_ARCCOS_PU_SUBDIVIDE_ENABLE           0
#define LQ_INT32_Q28_ARCSIN_ARCCOS_PU_SUBDIVIDE_ENABLE           0
#define LQ_INT32_Q29_ARCSIN_ARCCOS_PU_SUBDIVIDE_ENABLE           0
#define LQ_INT32_Q30_ARCSIN_ARCCOS_PU_SUBDIVIDE_ENABLE           0
#define LQ_INT32_Q31_ARCSIN_ARCCOS_PU_SUBDIVIDE_ENABLE           1

#define LQ_ARCSIN_ARCCOS_PU_SUBDIVIDE_LOADING_MODE     1      //!<asin/acos细分查表法:0 函数模式 1内联模式



//!<Q格式COEDIC表是否使能      0 失能      1使能
#define LQ_SIN_COS_PU_1_CORDIC_DEPTH_ENABLE       0
#define LQ_SIN_COS_PU_2_CORDIC_DEPTH_ENABLE       0
#define LQ_SIN_COS_PU_3_CORDIC_DEPTH_ENABLE       0
#define LQ_SIN_COS_PU_4_CORDIC_DEPTH_ENABLE       0
#define LQ_SIN_COS_PU_5_CORDIC_DEPTH_ENABLE       0
#define LQ_SIN_COS_PU_6_CORDIC_DEPTH_ENABLE       0
#define LQ_SIN_COS_PU_7_CORDIC_DEPTH_ENABLE       0
#define LQ_SIN_COS_PU_8_CORDIC_DEPTH_ENABLE       0
#define LQ_SIN_COS_PU_9_CORDIC_DEPTH_ENABLE       0
#define LQ_SIN_COS_PU_10_CORDIC_DEPTH_ENABLE       0
#define LQ_SIN_COS_PU_11_CORDIC_DEPTH_ENABLE       0
#define LQ_SIN_COS_PU_12_CORDIC_DEPTH_ENABLE       0
#define LQ_SIN_COS_PU_13_CORDIC_DEPTH_ENABLE       0
#define LQ_SIN_COS_PU_14_CORDIC_DEPTH_ENABLE       1
#define LQ_SIN_COS_PU_15_CORDIC_DEPTH_ENABLE       0
#define LQ_SIN_COS_PU_16_CORDIC_DEPTH_ENABLE       0
#define LQ_SIN_COS_PU_17_CORDIC_DEPTH_ENABLE       0
#define LQ_SIN_COS_PU_18_CORDIC_DEPTH_ENABLE       0
#define LQ_SIN_COS_PU_19_CORDIC_DEPTH_ENABLE       0
#define LQ_SIN_COS_PU_20_CORDIC_DEPTH_ENABLE       0
#define LQ_SIN_COS_PU_21_CORDIC_DEPTH_ENABLE       0
#define LQ_SIN_COS_PU_22_CORDIC_DEPTH_ENABLE       0
#define LQ_SIN_COS_PU_23_CORDIC_DEPTH_ENABLE       0
#define LQ_SIN_COS_PU_24_CORDIC_DEPTH_ENABLE       0
#define LQ_SIN_COS_PU_25_CORDIC_DEPTH_ENABLE       0
#define LQ_SIN_COS_PU_26_CORDIC_DEPTH_ENABLE       0
#define LQ_SIN_COS_PU_27_CORDIC_DEPTH_ENABLE       0
#define LQ_SIN_COS_PU_28_CORDIC_DEPTH_ENABLE       0
#define LQ_SIN_COS_PU_29_CORDIC_DEPTH_ENABLE       0
#define LQ_SIN_COS_PU_30_CORDIC_DEPTH_ENABLE       1
 


//!<Q格式每单位CORDIC SIN_COS变换中Q格式是否使能     0失能    1使能
#define LQ_INT8_Q1_SIN_COS_PU_CORDIC_DEPTH_ENABLE           0
#define LQ_INT8_Q2_SIN_COS_PU_CORDIC_DEPTH_ENABLE           0
#define LQ_INT8_Q3_SIN_COS_PU_CORDIC_DEPTH_ENABLE           0
#define LQ_INT8_Q4_SIN_COS_PU_CORDIC_DEPTH_ENABLE           0
#define LQ_INT8_Q5_SIN_COS_PU_CORDIC_DEPTH_ENABLE           0
#define LQ_INT8_Q6_SIN_COS_PU_CORDIC_DEPTH_ENABLE           0
#define LQ_INT8_Q7_SIN_COS_PU_CORDIC_DEPTH_ENABLE           0
#define LQ_INT16_Q1_SIN_COS_PU_CORDIC_DEPTH_ENABLE           0
#define LQ_INT16_Q2_SIN_COS_PU_CORDIC_DEPTH_ENABLE           0
#define LQ_INT16_Q3_SIN_COS_PU_CORDIC_DEPTH_ENABLE           0
#define LQ_INT16_Q4_SIN_COS_PU_CORDIC_DEPTH_ENABLE           0
#define LQ_INT16_Q5_SIN_COS_PU_CORDIC_DEPTH_ENABLE           0
#define LQ_INT16_Q6_SIN_COS_PU_CORDIC_DEPTH_ENABLE           0
#define LQ_INT16_Q7_SIN_COS_PU_CORDIC_DEPTH_ENABLE           0
#define LQ_INT16_Q8_SIN_COS_PU_CORDIC_DEPTH_ENABLE           0
#define LQ_INT16_Q9_SIN_COS_PU_CORDIC_DEPTH_ENABLE           0
#define LQ_INT16_Q10_SIN_COS_PU_CORDIC_DEPTH_ENABLE           0
#define LQ_INT16_Q11_SIN_COS_PU_CORDIC_DEPTH_ENABLE           0
#define LQ_INT16_Q12_SIN_COS_PU_CORDIC_DEPTH_ENABLE           0
#define LQ_INT16_Q13_SIN_COS_PU_CORDIC_DEPTH_ENABLE           0
#define LQ_INT16_Q14_SIN_COS_PU_CORDIC_DEPTH_ENABLE           0
#define LQ_INT16_Q15_SIN_COS_PU_CORDIC_DEPTH_ENABLE           1
#define LQ_INT32_Q1_SIN_COS_PU_CORDIC_DEPTH_ENABLE           0
#define LQ_INT32_Q2_SIN_COS_PU_CORDIC_DEPTH_ENABLE           0
#define LQ_INT32_Q3_SIN_COS_PU_CORDIC_DEPTH_ENABLE           0
#define LQ_INT32_Q4_SIN_COS_PU_CORDIC_DEPTH_ENABLE           0
#define LQ_INT32_Q5_SIN_COS_PU_CORDIC_DEPTH_ENABLE           0
#define LQ_INT32_Q6_SIN_COS_PU_CORDIC_DEPTH_ENABLE           0
#define LQ_INT32_Q7_SIN_COS_PU_CORDIC_DEPTH_ENABLE           0
#define LQ_INT32_Q8_SIN_COS_PU_CORDIC_DEPTH_ENABLE           0
#define LQ_INT32_Q9_SIN_COS_PU_CORDIC_DEPTH_ENABLE           0
#define LQ_INT32_Q10_SIN_COS_PU_CORDIC_DEPTH_ENABLE           0
#define LQ_INT32_Q11_SIN_COS_PU_CORDIC_DEPTH_ENABLE           0
#define LQ_INT32_Q12_SIN_COS_PU_CORDIC_DEPTH_ENABLE           0
#define LQ_INT32_Q13_SIN_COS_PU_CORDIC_DEPTH_ENABLE           0
#define LQ_INT32_Q14_SIN_COS_PU_CORDIC_DEPTH_ENABLE           0
#define LQ_INT32_Q15_SIN_COS_PU_CORDIC_DEPTH_ENABLE           0
#define LQ_INT32_Q16_SIN_COS_PU_CORDIC_DEPTH_ENABLE           0
#define LQ_INT32_Q17_SIN_COS_PU_CORDIC_DEPTH_ENABLE           0
#define LQ_INT32_Q18_SIN_COS_PU_CORDIC_DEPTH_ENABLE           0
#define LQ_INT32_Q19_SIN_COS_PU_CORDIC_DEPTH_ENABLE           0
#define LQ_INT32_Q20_SIN_COS_PU_CORDIC_DEPTH_ENABLE           0
#define LQ_INT32_Q21_SIN_COS_PU_CORDIC_DEPTH_ENABLE           0
#define LQ_INT32_Q22_SIN_COS_PU_CORDIC_DEPTH_ENABLE           0
#define LQ_INT32_Q23_SIN_COS_PU_CORDIC_DEPTH_ENABLE           0
#define LQ_INT32_Q24_SIN_COS_PU_CORDIC_DEPTH_ENABLE           0
#define LQ_INT32_Q25_SIN_COS_PU_CORDIC_DEPTH_ENABLE           0
#define LQ_INT32_Q26_SIN_COS_PU_CORDIC_DEPTH_ENABLE           0
#define LQ_INT32_Q27_SIN_COS_PU_CORDIC_DEPTH_ENABLE           0
#define LQ_INT32_Q28_SIN_COS_PU_CORDIC_DEPTH_ENABLE           0
#define LQ_INT32_Q29_SIN_COS_PU_CORDIC_DEPTH_ENABLE           0
#define LQ_INT32_Q30_SIN_COS_PU_CORDIC_DEPTH_ENABLE           0
#define LQ_INT32_Q31_SIN_COS_PU_CORDIC_DEPTH_ENABLE           1

#define LQ_SIN_COS_PU_CORDIC_DEPTH_LOADING_MODE               0  //!<sin/cos CORDIC法:0 函数模式 1内联模式
#endif
