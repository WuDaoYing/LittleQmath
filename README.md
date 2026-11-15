# LittleQmath

面向嵌入式（Cortex-M0/M0+/M3/M4/M7 等）的定点 Q 格式数学库。全部实现只依赖 C99 标准库，无动态内存、无全局状态、无浮点运算依赖（转换族除外），可作为纯头文件内联、静态库函数或宏展开三种方式装载。

- 覆盖：8/16/32 位有符号 Q 与无符号 UQ 格式；算术/转换族共 109 种格式（INT8 7 + UINT8 8 + INT16 15 + UINT16 16 + INT32 31 + UINT32 32），三角/反三角族覆盖 53 种有符号 Q 格式
- 功能：浮点/整数与 Q 互转、饱和与非饱和四则运算、Q 格式互转、sin/cos（查表 + CORDIC）、asin/acos、sqrt、atan2、浮点转 Q 值类型
- 三装载模式：`0` = 函数、`1` = 内联、`2` = 宏展开，按族独立配置
- 三个工具链验证：Keil AC5 / Keil AC6（Cortex-M3、Cortex-M0）、GCC、MSVC（VS2022）
- 饱和语义：溢出时钳位到最大/最小值并输出错误码；非饱和语义：保留回绕结果并输出错误码

```
作者   尹冠华
版本   V2.0（2024-06-27 重构）
版权   Copyright (c) 2018-2025 黑龙江大学 A8 楼 514
```

---

## 目录

- [1. 目录结构](#1-目录结构)
- [2. 快速开始](#2-快速开始)
- [3. 数据类型与命名规范](#3-数据类型与命名规范)
- [4. 装载模式配置（lq_mode.h）](#4-装载模式配置lq_modeh)
- [5. 功能函数手册](#5-功能函数手册)
- [6. 错误码与饱和语义](#6-错误码与饱和语义)
- [7. 精度与性能实测](#7-精度与性能实测)
- [8. 三环境编译与自测](#8-三环境编译与自测)
- [9. Cortex-M0/M0+ 与 M3+ 的自动分支](#9-cortex-m0m0-与-m3-的自动分支)
- [10. 注意事项](#10-注意事项)

---

## 1. 目录结构

```
LittleQmath/
├── Inc/                             # 全部对外头文件
│   ├── lq_includes.h                # 汇总头（推荐唯一 include）
│   ├── lq_type.h                    # 基础类型与前缀宏
│   ├── lq_mode.h                    # ★ 装载模式与全局配置开关
│   ├── lq_error.h                   # LQ_ERROR 枚举（错误码）
│   ├── lq_arm_dsp.h                 # ARM __ssat/__usat 封装与可移植钳位
│   ├── lq_saturation_*.h            # 饱和：浮点/整数/Q → Q、四则、Q→Q
│   ├── lq_unsaturation_*.h          # 非饱和：同上
│   ├── lq_q_format_to_float.h       # Q → float（非 TI 风格）
│   ├── lq_q_format_to_int.h         # Q → int（非 TI 风格）
│   ├── lq_ti_q_format_to_float.h    # Q → float（TI 风格接口）
│   ├── lq_ti_q_format_to_int.h      # Q → int（TI 风格接口）
│   ├── lq_sin_cos_pu_subdivide*.h   # sin/cos 查表法
│   ├── lq_sin_cos_pu_cordic_depth*.h# sin/cos CORDIC 法
│   ├── lq_arcsin_arccos_pu_subdivide*.h  # asin/acos 查表法
│   ├── lq_sqrt_newton_iteration.h   # sqrt 牛顿迭代
│   ├── lq_sqrt_bitwise_root.h       # sqrt 逐位法（无除法）
│   ├── lq_arctan2_pu_approximate_curve.h # atan2 曲线拟合
│   └── lq_float_to_q_value_type.h   # 浮点 → Q 值类型（QVAL）
├── Src/                             # 与 Inc 同名的 .c 实现（模式 0 使用）
└── README.md
```

- `Inc/` 与 `Src/` 中的文件按族一一对应，裁剪时成对增删即可。
- 每个功能族都有独立 `.h`/`.c`，按需裁剪即可减小编译时间与代码体积。

## 2. 快速开始

### 2.1 加入工程

1. 把 `Inc/` 加入头文件搜索路径；
2. 把 `Src/` 下全部 `.c` 加入工程（仅编译模式 0 时才真正产生代码，模式 1/2 下这些 `.c` 会编译为空单元，保留它们不会重复定义符号）；
3. 在 `Inc/lq_mode.h` 中按需调整装载模式（见第 4 节），默认配置已针对 ARM 性能调优。

### 2.2 第一个程序

```c
#include <stdio.h>
#include "lq_includes.h"

int main(void)
{
    LQ_ERROR Err = LQ_SUCCESS;

    /* 浮点 → Q7：0.5 → 64 */
    LQ_INT8_Q7 q = LQ_SATURATION_INT8_FLOAT_TO_Q7(0.5f, &Err);

    /* 定点加法：0.5 + 0.5 饱和到 Q7 上限 127，并置正向溢出错误码 */
    LQ_INT8_Q7 sum = LQ_SATURATION_INT8_Q7_ADD(q, q, &Err);

    /* Q → 浮点：127/128 ≈ 0.992188 */
    LQ_F_32BIT f = LQ_INT8_Q7_TO_FLOAT(sum, &Err);

    /* sin(π/4)：三角函数以 π 归一化为单位，输入/输出均为 PU 值 */
    LQ_INT32_Q31 sin_pu = LQ_INT32_Q31_SIN_PU_32768_SUBDIVIDE(0x20000000, &Err);

    /* sqrt(0.5)：A 为 Q31 的 0.5，Q_A = 31，Error_Range = 1 LSB */
    LQ_INT32_Q31 sqrt_pu = LQ_INT32_Q_SQRT_NEWTON_ITERATION(1 << 30, 31, 1, &Err);

    /* 1234.5 用 INT32 表示所需的最小 Q 值（返回 20） */
    int qbits = LQ_INT32_Q_FLOAT_TO_Q_VALUE_TYPE(1234.5f);

    printf("q      = %d\n", (int)q);
    printf("sum    = %d\n", (int)sum);
    printf("f      = %f\n", (double)f);
    printf("sin    = %lld (%.6f)\n", (long long)sin_pu, (double)sin_pu / 2147483648.0);
    printf("sqrt2  = %lld (%.6f)\n", (long long)sqrt_pu, (double)sqrt_pu / 2147483648.0);
    printf("qbits  = %d\n", qbits);
    printf("Err    = %d\n", (int)Err);
    return 0;
}
```

输出（GCC 实测，三种装载模式逐位一致）：

```
q      = 64
sum    = 127
f      = 0.992188
sin    = 1518469120 (0.707092)     # 参考 sin(π/4) = 0.707107，误差约 4.4e5 LSB(Q31)
sqrt2  = 1518500249 (0.707107)     # sqrt(0.5) 精确到 1 LSB
qbits  = 20
Err    = 449                       # 来自第 2 步 0.5+0.5 饱和到 127 的正向溢出码
```

> `LQ_ERROR` 变量不会被库自动清零，**每次调用前应重新赋 `LQ_SUCCESS`**，否则旧错误码会残留。详见第 6 节。

## 3. 数据类型与命名规范

### 3.1 基础类型（`lq_type.h`）

| 类型 | 实际类型 | 说明 |
|---|---|---|
| `LQ_I_8BIT` / `LQ_I_16BIT` / `LQ_I_32BIT` / `LQ_I_64BIT` | `int8_t` … `int64_t` | 有符号底层类型 |
| `LQ_UI_8BIT` / `LQ_UI_16BIT` / `LQ_UI_32BIT` / `LQ_UI_64BIT` | `uint8_t` … `uint64_t` | 无符号底层类型 |
| `LQ_F_32BIT` / `LQ_D_64BIT` | `float` / `double` | 浮点类型 |
| `LQ_INT8_Q7` … `LQ_INT32_Q31` | 对应宽度有符号整数 | 定点 Q 格式语义类型 |
| `LQ_UINT8_UQ8` … `LQ_UINT32_UQ32` | 对应宽度无符号整数 | 定点 UQ 格式语义类型 |
| `LQ_INLINE` | `static __inline` | 内联修饰，模式 1 使用 |

取值范围宏：`LQ_I_8BIT_MAX/MIN`、`LQ_UI_16BIT_MAX` 等与 `<stdint.h>` 的 `INT8_MAX` 等一一对应。

### 3.2 命名规则

```
LQ_<饱和性>_<底层类型>_<Q 值>_<操作>
│   │          │            │      └─ ADD / SUB / MUL / DIV / FLOAT_TO_Q7 / INT_TO_Q7 ...
│   │          │            └─ Q7、Q15、Q31、UQ7 ...（UQ 为无符号）
│   │          └─ INT8 / UINT8 / INT16 / UINT16 / INT32 / UINT32
│   └─ SATURATION / UNSATURATION
```

示例：

| API | 含义 |
|---|---|
| `LQ_SATURATION_INT8_FLOAT_TO_Q7(float A, LQ_ERROR*)` | 浮点 → 饱和 Q7 |
| `LQ_UNSATURATION_INT16_INT_TO_Q15(int16 A, LQ_ERROR*)` | 整数 → 非饱和 Q15 |
| `LQ_SATURATION_INT32_Q31_ADD(Q31 A, Q31 B, LQ_ERROR*)` | 饱和 Q31 加法 |
| `LQ_UNSATURATION_UINT16_UQ15_DIV(UQ15 A, UQ15 B, LQ_ERROR*)` | 非饱和 UQ15 除法 |
| `LQ_SATURATION_INT16_Q_FORMAT_TO_Q_FORMAT(A, Q_A, Q_B, LQ_ERROR*)` | 任意 Q → 任意 Q |
| `LQ_INT8_Q7_TO_FLOAT(A, LQ_ERROR*)` | Q7 → 浮点 |
| `LQ_TI_INT32_Q_TO_FLOAT(A, Q, LQ_ERROR*)` | TI 风格 Q → 浮点 |

- 算术与转换族每族有 **109 个具名格式函数 + 6 个泛型格式函数**（泛型函数以 `Q_A`/`Q_B`/`Q_C` 参数在运行时指定 Q 值）。
- TI 风格接口（`LQ_TI_*_TO_INT` / `LQ_TI_*_TO_FLOAT`）与非 TI 风格（`LQ_*_FORMAT_TO_*`）均为**已发布的公开 API 名称**，两种命名并存是有意设计。

## 4. 装载模式配置（lq_mode.h）

### 4.1 三种装载模式

| 值 | 名称 | 实现方式 | 适用场景 |
|---|---|---|---|
| `0` | 函数模式 | 实现在 `.c`，头文件只声明 | 代码体积优先；同族只用到少数格式；需要可调试的独立符号 |
| `1` | 内联模式 | `LQ_INLINE` 在头文件内实现 | **默认推荐**；性能优先；编译器可跨函数优化 |
| `2` | 宏展开模式 | 纯 `#define`，无调用无内联 | x86 上消除最后一层调用开销；参数必须无副作用（见 10.2） |

三个模式只改变「代码如何被装载」，**精度完全一致**（105 个用例 × 6 个测量目标，三模式误差逐位相同）。

105 个用例的几何平均耗时比（m1/m0、m2/m0，越小越快）：

| 目标 | m1 / m0 | m2 / m0 |
|---|---|---|
| GCC x86-64 -O2 | **0.69** | **0.68** |
| MSVC x64 -O2 | 0.76 | 0.75 |
| Keil AC6 Cortex-M3 -O2 | 0.76 | 0.79 |
| Keil AC5 Cortex-M3 -O2 | 0.81 | 0.85 |
| Keil AC6 Cortex-M0 -O2 | 0.89 | 0.92 |
| Keil AC5 Cortex-M0 -O2 | 0.87 | 0.86 |

> 结论：x86 上模式 2 略优；ARM 上模式 2 在部分转换族反而慢于模式 1（双精度常量乘法会引入 `__aeabi_dmul`），因此**默认全部四则/转换族取 1，仅饱和加/减两族取 0**（见下表，原因是 SSAT 分支在函数级已足够紧凑，宏展开会显著增大代码体积）。

### 4.2 四则与转换族（19 个，合法值 0/1/2）

宏位于 `Inc/lq_mode.h` 第 93–138 行，默认值如下：

| 宏 | 行号 | 默认 | 说明 |
|---|---|---|---|
| `LQ_SATURATION_FLOAT_TO_Q_FORMAT_LOADING_MODE` | 93 | `1` | 浮点 → Q（饱和） |
| `LQ_UNSATURATION_FLOAT_TO_Q_FORMAT_LOADING_MODE` | 95 | `1` | 浮点 → Q（非饱和） |
| `LQ_SATURATION_INT_TO_Q_FORMAT_LOADING_MODE` | 98 | `1` | 整数 → Q（饱和） |
| `LQ_UNSATURATION_INT_TO_Q_FORMAT_LOADING_MODE` | 100 | `1` | 整数 → Q（非饱和） |
| `LQ_TI_Q_FORMAT_TO_FLOAT_LOADING_MODE` | 103 | `1` | TI 风格 Q → 浮点 |
| `LQ_Q_FORMAT_TO_FLOAT_LOADING_MODE` | 105 | `1` | Q → 浮点 |
| `LQ_TI_Q_FORMAT_TO_INT_LOADING_MODE` | 108 | `1` | TI 风格 Q → 整数 |
| `LQ_Q_FORMAT_TO_INT_LOADING_MODE` | 110 | `1` | Q → 整数 |
| `LQ_SATURATION_Q_FORMAT_ADD_LOADING_MODE` | 115 | `0` | 饱和加法（含 ARM SSAT 快路径） |
| `LQ_UNSATURATION_Q_FORMAT_ADD_LOADING_MODE` | 117 | `1` | 非饱和加法 |
| `LQ_SATURATION_Q_FORMAT_SUB_LOADING_MODE` | 120 | `0` | 饱和减法（含 ARM SSAT 快路径） |
| `LQ_UNSATURATION_Q_FORMAT_SUB_LOADING_MODE` | 122 | `1` | 非饱和减法 |
| `LQ_SATURATION_Q_FORMAT_MUL_LOADING_MODE` | 125 | `1` | 饱和乘法 |
| `LQ_UNSATURATION_Q_FORMAT_MUL_LOADING_MODE` | 127 | `1` | 非饱和乘法 |
| `LQ_SATURATION_Q_FORMAT_DIV_LOADING_MODE` | 130 | `1` | 饱和除法 |
| `LQ_UNSATURATION_Q_FORMAT_DIV_LOADING_MODE` | 132 | `1` | 非饱和除法 |
| `LQ_SATURATION_Q_FORMAT_TO_Q_FORMAT_LOADING_MODE` | 135 | `1` | 饱和 Q → Q |
| `LQ_UNSATURATION_Q_FORMAT_TO_Q_FORMAT_LOADING_MODE` | 138 | `1` | 非饱和 Q → Q |

### 4.3 算法族（7 个，合法值仅 0/1）

| 宏 | 行号 | 默认 | 说明 |
|---|---|---|---|
| `LQ_SQRT_NEWTON_ITERATION_LOADING_MODE` | 142–148 | 条件：M0/M0+ = `0`，其余 `1` | sqrt 牛顿迭代；M0 无除法指令，条件默认切回函数以复用逐位实现 |
| `LQ_SQRT_BITWISE_ROOT_LOADING_MODE` | 151 | `0` | sqrt 逐位法（无除法，M0 友好） |
| `LQ_ARCTAN2_PU_APPROXIMATE_CURVE_LOADING_MODE` | 154 | `0` | atan2 曲线拟合 |
| `LQ_FLOAT_TO_Q_VALUE_TYPE_LOADING_MODE` | 157 | `1` | 浮点 → Q 值类型（QVAL） |
| `LQ_SIN_COS_PU_SUBDIVIDE_LOADING_MODE` | 225 | `1` | sin/cos 查表法 |
| `LQ_ARCSIN_ARCCOS_PU_SUBDIVIDE_LOADING_MODE` | 291 | `1` | asin/acos 查表法 |
| `LQ_SIN_COS_PU_CORDIC_DEPTH_LOADING_MODE` | 384 | `0` | sin/cos CORDIC 法（慢，但无大表） |

> 算法族没有模式 2；内部构建把 `2` 视为 `1`。

### 4.4 自动检测开关（无需手工配置）

| 宏 | 行号 | 自动取值 |
|---|---|---|
| `LQ_ARM_DSP_SSAT_ENABLE` | 31 | 固定 `1`；ARM 上使用 `__ssat/__usat`，非 ARM 自动退化为可移植钳位 |
| `LQ_SQRT_NODIV_ENABLE` | 38–44 | ARMv6-M / ARMv8-M Baseline（M0/M0+）= `1`，其余 `0` |
| `LQ_ARCTAN2_NODIV_ENABLE` | 48–54 | 同上：M0 上用移位长除法替代 64 位除法 |
| `LQ_CORDIC_SHIFT_ENABLE` | 61–67 | 同上：M0 上 CORDIC 改用移位近似 |
| `LQ_TI_Q_FORMAT_TO_FLOAT_CLZ_ENABLE` | 73–81 | ARMv7+ 与非 ARM 平台 `1`；M0 上 `0`（改用循环） |

以上均写成 `#ifndef … #define … #endif`，可在编译器命令行 `-D` 强制覆盖。

`LQ_OPERATIONS_GLOBAL_MODE`（第 87 行，默认 `0`）为历史保留宏，当前不参与任何编译分支，请勿依赖。

### 4.5 查表开关

三角/反三角函数的具体表项由 `lq_mode.h` 第 161–382 行控制，语法为「细分点数/迭代深度 × Q 格式」二维开关：

| 组 | 行号 | 默认开启 |
|---|---|---|
| sin/cos 细分点数（512 … 32768） | 162–168 | 仅 `LQ_SIN_COS_PU_32768_SUBDIVIDE_ENABLE` |
| sin/cos 各 Q 格式的细分表 | 170–222 | 仅 `LQ_INT32_Q31_…_SUBDIVIDE_ENABLE` |
| asin/acos 细分点数 | 229–235 | 仅 `LQ_ARCSIN_ARCCOS_PU_32768_SUBDIVIDE_ENABLE` |
| asin/acos 各 Q 格式细分表 | 237–289 | 仅 `LQ_INT32_Q31_…_SUBDIVIDE_ENABLE` |
| CORDIC 迭代深度（1 … 30） | 296–325 | 深度 `14` 与 `30` |
| CORDIC 各 Q 格式 | 330–382 | 仅 `LQ_INT16_Q15_…` 与 `LQ_INT32_Q31_…` |

表项越多，精度/格式覆盖越全，`.rodata` 越大。开关是「细分点数 × Q 格式」两级，两者同时为 `1` 才会把对应表编译进来；默认只开 Q31 一张：sin/cos 32768 细分 8192 项 × 2 字节 = **16 KB**（int16 存储，查表后左移 16 位还原），asin/acos 32768 细分 16384 项 × 4 字节 = **64 KB**，合计 80 KB。其余细分点数与其他 52 种 Q 格式的表都不参与编译。

把对应 `_ENABLE` 置 `0` 后，表与使用该表的函数会被整体裁掉（表在 `#if …_ENABLE == 1` 内），因此关闭后不要再调用这些接口，否则链接阶段会报未定义符号；可改用 CORDIC（默认深度 14/30、Q15/Q31 的两张角度/索引表合计不足 1 KB），或只保留实际用到的 Q 格式。

## 5. 功能函数手册

所有接口的最后一个参数（除 QVAL 与 `LQ_SQRT_U32/U64_*` 外）都是 `LQ_ERROR*` 错误输出。

### 5.1 浮点 → Q（16 个族：饱和 / 非饱和 × 8 种宽度-符号组合）

```c
LQ_INT8_Q7  LQ_SATURATION_INT8_FLOAT_TO_Q7(LQ_F_32BIT A, LQ_ERROR* Lq_Error);
LQ_INT32_Q  LQ_SATURATION_INT32_FLOAT_TO_Q(LQ_F_32BIT A, LQ_UI_8BIT Q_A, LQ_ERROR* Lq_Error);
```

- 具名接口：`INT8` 提供 Q1–Q7、`UINT8` 提供 UQ1–UQ8、`INT16` Q1–Q15、`UINT16` UQ1–UQ16、`INT32` Q1–Q31、`UINT32` UQ1–UQ32（共 109 个）。
- 泛型接口：`LQ_SATURATION_INT8_FLOAT_TO_Q`、`…_UINT8_…_TO_UQ`、`…_INT16_…_TO_Q`、`…_UINT16_…_TO_UQ`、`…_INT32_…_TO_Q`、`…_UINT32_…_TO_UQ`，在运行时传 `Q_A`。
- NaN 输入：置 `…_POSITIVE_OVER` 错误码并返回 `0`（不会产生未定义行为）。
- 饱和版越界钳位到最大/最小值；非饱和版返回截断结果并置错误码。

### 5.2 整数 → Q

```c
LQ_INT8_Q7  LQ_SATURATION_INT8_INT_TO_Q7(LQ_I_16BIT A, LQ_ERROR* Lq_Error);
LQ_INT32_Q  LQ_SATURATION_INT32_INT_TO_Q(LQ_I_64BIT A, LQ_UI_8BIT Q_A, LQ_ERROR* Lq_Error);
```

输入使用宽一档的整数类型（如 8 位 Q 接收 `int16_t`），便于在内部判定溢出。

### 5.3 Q ↔ 浮点 / 整数

```c
LQ_F_32BIT LQ_INT8_Q7_TO_FLOAT(LQ_INT8_Q7 A, LQ_ERROR* lq_error);
LQ_F_32BIT LQ_INT32_Q_FORMAT_TO_FLOAT(LQ_INT32_Q A, LQ_UI_8BIT Q_A, LQ_ERROR* lq_error);
LQ_INT8_Q7 LQ_INT8_Q7_TO_INT(LQ_INT8_Q7 A, LQ_ERROR* lq_error);
LQ_INT32_Q LQ_INT32_Q_FORMAT_TO_INT(LQ_INT32_Q A, LQ_UI_8BIT Q_A, LQ_ERROR* lq_error);
```

TI 风格（`lq_ti_q_format_to_float.h` / `lq_ti_q_format_to_int.h`）语义一致，入参为 `LQ_I_32BIT`：

```c
LQ_F_32BIT LQ_TI_INT8_Q7_TO_FLOAT(LQ_I_32BIT A, LQ_ERROR* lq_error);
LQ_F_32BIT LQ_TI_INT32_Q_TO_FLOAT(LQ_I_32BIT A, LQ_UI_8BIT Q_A, LQ_ERROR* lq_error);
```

`TI Q→float` 在 ARMv7+ 上走 CLZ 路径，非 ARM 平台走可移植回退（见 4.4）。

### 5.4 四则运算（饱和 / 非饱和 × ADD / SUB / MUL / DIV）

```c
LQ_INT8_Q7  LQ_SATURATION_INT8_Q7_ADD(LQ_INT8_Q7 A, LQ_INT8_Q7 B, LQ_ERROR* Lq_Error);
LQ_INT32_Q  LQ_SATURATION_INT32_Q_ADD(LQ_INT32_Q A, LQ_UI_8BIT Q_A,
                                      LQ_INT32_Q B, LQ_UI_8BIT Q_B,
                                      LQ_UI_8BIT Q_C, LQ_ERROR* Lq_Error);
```

- 具名接口按格式直接调用，泛型接口用 `Q_A/Q_B` 描述两个操作数的 Q 值、`Q_C` 描述结果的 Q 值。
- `DIV` 除数为 0 时：**饱和版返回最大值 `MAX`**，**非饱和版返回 `0`**，两者均置 `…_DIVSION_ZERO` 错误码。
- ARMv7-M 及以上，`INT8`/`INT16` 的饱和加/减自动走 `__ssat/__usat` 单指令快路径（`LQ_ARM_SATURATION_*` 系列），非 ARM 平台使用等价的可移植钳位。

### 5.5 Q 格式 → Q 格式

```c
LQ_I_8BIT  LQ_SATURATION_INT8_Q_FORMAT_TO_Q_FORMAT(LQ_I_8BIT A, LQ_UI_8BIT Q_A,
                                                   LQ_UI_8BIT Q_B, LQ_ERROR* Lq_Error);
```

共 6 个（INT8/UINT8/INT16/UINT16/INT32/UINT32）；`Q_A` 为输入 Q 值、`Q_B` 为目标 Q 值，左移/右移都先在更宽类型中完成。合法 `Q_A/Q_B` 范围：INT8 1–7、UINT8 1–8、INT16 1–15、UINT16 1–16、INT32 1–31、UINT32 1–32，越界置 `LQ_Q_FORMAT_PARAMETER_ERROR`。

### 5.6 sin / cos（PU 归一化，查表法）

```c
LQ_INT32_Q31 LQ_INT32_Q31_SIN_PU_32768_SUBDIVIDE(LQ_INT32_Q31 A_Pu, LQ_ERROR* Lq_Error);
LQ_INT32_Q31 LQ_INT32_Q31_COS_PU_32768_SUBDIVIDE(LQ_INT32_Q31 A_Pu, LQ_ERROR* Lq_Error);
LQ_INT32_Q31 LQ_INT32_Q31_SIN_COS_PU_32768_SUBDIVIDE(LQ_INT32_Q31 A_Pu,
                                                     LQ_INT32_Q31* Out_Sin,
                                                     LQ_INT32_Q31* Out_Cos,
                                                     LQ_ERROR* Lq_Error);
```

- 输入 `A_Pu = 角度 / π`，以目标 Q 格式表示（Q31 的 0x20000000 表示 π/4，0x40000000 表示 π/2）。
- 输出为 `sin/cos` 的 Q 值，组合接口一次算出 sin 与 cos。
- 命名字形：`LQ_<类型>_<Q>_SIN_PU_<细分点数>_SUBDIVIDE`，共 53 种格式 × 7 种细分 × 3 种输出（sin / cos / 组合）。
- 组合接口允许 `Out_Sin/Out_Cos/Lq_Error` 为 `LQ_NULL`（传入空输出指针时直接返回 0）。

### 5.7 sin / cos（CORDIC）

```c
LQ_INT32_Q31 LQ_INT32_Q31_SIN_PU_14_CORDIC_DEPTH(LQ_INT32_Q31 A_Pu, LQ_ERROR* Lq_Error);
```

命名字形 `LQ_<类型>_<Q>_SIN_PU_<深度>_CORDIC_DEPTH`。深度 14 精度约 1e-4（Q31），深度 30 可接近表法精度但指令数约 2000 IC，仅在 Flash 无法容纳查表时推荐。

### 5.8 asin / acos（PU 归一化）

```c
LQ_INT32_Q31 LQ_INT32_Q31_ARCSIN_PU_32768_SUBDIVIDE(LQ_INT32_Q31 A, LQ_ERROR* Lq_Error);
LQ_INT32_Q31 LQ_INT32_Q31_ARCSIN_ARCCOS_PU_32768_SUBDIVIDE(LQ_INT32_Q31 A,
                                                           LQ_INT32_Q31* Out_Arcsin,
                                                           LQ_INT32_Q31* Out_Arccos,
                                                           LQ_ERROR* Lq_Error);
```

输入为 `[-1, 1]` 区间的 Q 值，输出为 `角度 / π` 的 Q 值。

### 5.9 sqrt

```c
LQ_INT32_Q LQ_INT32_Q_SQRT_NEWTON_ITERATION(LQ_INT32_Q A, LQ_UI_8BIT Q_A,
                                            LQ_INT32_Q Error_Range, LQ_ERROR* Lq_Error);
LQ_UI_32BIT LQ_SQRT_U32_BITWISE(LQ_UI_32BIT value, LQ_UI_32BIT Error_Range);
LQ_UI_64BIT LQ_SQRT_U64_BITWISE(LQ_UI_64BIT value, LQ_UI_64BIT Error_Range);
LQ_UI_32BIT LQ_SQRT_U32_NEWTON(LQ_UI_32BIT value, LQ_UI_32BIT Error_Range);
LQ_UI_64BIT LQ_SQRT_U64_NEWTON(LQ_UI_64BIT value, LQ_UI_64BIT Error_Range);

/* 分派入口（宏）：按 LQ_SQRT_NODIV_ENABLE 选择逐位法或牛顿法 */
#define LQ_SQRT_U32_ROOT(value, Error_Range)  ...
#define LQ_SQRT_U64_ROOT(value, Error_Range)  ...
```

- 牛顿迭代族：计算 `sqrt(A / 2^Q_A)`，返回 `Q_A` 格式结果；`Error_Range` 为相邻两次迭代允许的最大差（≥1 LSB），为 0 时置 `…_THE_RANGE_IS_TOO_LOW`。
- 逐位法：输入输出都是纯整数，`sqrt(A)` 精确向下取整（`exact = 100%`），无除法。
- `LQ_SQRT_U32_ROOT/U64_ROOT` 会按 `LQ_SQRT_NODIV_ENABLE` 自动选择牛顿法或逐位法，**应用层推荐只调用 ROOT 入口**。

### 5.10 atan2

```c
LQ_INT32_Q31 LQ_INT32_Q31_ARCTAN2_PU_APPROXIMATE_CURVE(LQ_INT32_Q31 Dy,
                                                       LQ_INT32_Q31 Dx,
                                                       LQ_ERROR* Lq_Error);
```

返回 `atan2(Dy, Dx) / π` 的 Q 值（范围 `[-1, 1)`，象限由 `Dy/Dx` 符号自动判定）。曲线拟合精度约 `6.05e-4`；`Dy == Dx == 0` 时置 `…_INPUT_VALUE_ZERO` 并返回 0。

### 5.11 浮点 → Q 值类型（QVAL）

```c
int LQ_INT8_Q_FLOAT_TO_Q_VALUE_TYPE(LQ_F_32BIT A);
int LQ_INT32_Q_FLOAT_TO_Q_VALUE_TYPE(LQ_F_32BIT A);
```

无错误参数。返回「用该宽度有符号/无符号类型表示输入值时所需的最小 Q 值」：

- `LQ_INT8_Q_FLOAT_TO_Q_VALUE_TYPE(0.5f)` → 7；`(1234.5f)` 用 INT32 → 20
- 无符号路径的 NaN/负数返回 0；有符号路径的 NaN 返回中间值（不越界）
- 典型用法：`q = LQ_INT32_Q_FLOAT_TO_Q_VALUE_TYPE(x); y = LQ_SATURATION_INT32_FLOAT_TO_Q(x, q, &Err);` —— 自动选取不损失整数位的最高精度。

## 6. 错误码与饱和语义

### 6.1 错误变量约定

- 所有函数通过 `LQ_ERROR*` 输出错误码（`lq_error.h`，0 = `LQ_SUCCESS`）。
- 库**不会**自动把错误变量重置为 `LQ_SUCCESS`，一个错误变量跨多次调用时应每次先手动清零。
- 单输出接口仅在错误路径写 `*Lq_Error`；若传入 `LQ_NULL` 且确实发生错误会导致空指针写。**请始终传入有效指针**（`SIN_COS`/`ARCSIN_ARCCOS` 组合接口除外，它们显式检查空指针）。
- 错误码粒度为「族 + 格式 + 方向」：`SATURATION_INT8_Q7_FORMAT_DIV_DIVSION_ZERO`、`UNSATURATION_UINT16_UQ15_FORMAT_MUL_NEGATIVE_OVER` 等。

### 6.2 饱和 vs 非饱和

| 场景 | 饱和接口 | 非饱和接口 |
|---|---|---|
| 结果超出目标范围 | 钳位到 `MAX`/`MIN`，置正向/负向溢出码 | 保留回绕（截断）结果，置正向/负向溢出码 |
| 除数为 0 | 返回 `MAX`，置 `DIVSION_ZERO` | 返回 `0`，置 `DIVSION_ZERO` |
| 浮点输入为 NaN | 返回 `0`，置 `POSITIVE_OVER` | 返回 `0`，置 `POSITIVE_OVER` |

## 7. 精度与性能实测

### 7.1 方法

- 精度基准：`math.h` 双精度结果四舍五入到目标 Q 格式，误差以输出 LSB 计；「精确率」= `|误差| < 0.5 LSB` 的采样点占比（每用例 512–1024 个均匀/随机采样点）。
- GCC / MSVC：x86-64 `-O2`，DLL 内 `clock_gettime` 计时 1024 次调用的平均 ns（含测试循环基线 0.23 ns，可忽略）。
- Keil AC5（5.x）/ AC6（6.x）：Cortex-M3 / Cortex-M0 `-O2` ELF，在 Unicorn 中统计**动态指令数（IC）**，512 次调用平均值（含 9 IC 循环基线）。
- 三命令行的结果完全可复现（见第 8 节自测）。

### 7.2 默认配置（模式 1，饱和加减为模式 0）实测

| 用例 | 最大误差 (LSB) | 归一化绝对值 | RMS | 精确率 | GCC ns | AC6-M3 IC | AC5-M3 IC | AC6-M0 IC | AC5-M0 IC | GCC m0→m1 |
|---|---|---|---|---|---|---|---|---|---|---|
| SIN Q31 SUBDIV | 4.37e+05 | 2.04e-4 | 2.06e+05 | 0.3% | 0.79 | 14 | 20 | 25 | 32 | 0.77x |
| SIN_COS Q31 SUBDIV | 4.37e+05 | 2.04e-4 | 2.91e+05 | 0.0% | 0.97 | 19 | 30 | 28 | 39 | 0.56x |
| SIN Q31 CORDIC14 | 2.5e+05 | 1.16e-4 | 1.06e+05 | 0.0% | 50.41 | 999 | 772 | 1191 | 984 | 1.10x |
| SIN_COS Q31 CORDIC30 | 64.4 | 3.00e-8 | 31.1 | 0.1% | 117.56 | 2175 | 1630 | 2626 | 2012 | 0.87x |
| ASIN Q31 SUBDIV | 149 | 6.94e-8 | 17.7 | 7.1% | 1.15 | 35 | 69 | 76 | 110 | 0.78x |
| ASIN_ACOS Q31 SUBDIV | 149 | 6.94e-8 | 17.7 | 6.9% | 1.16 | 38 | 81 | 84 | 124 | 0.53x |
| ATAN2 Q31 | 1.39e+05 | 6.47e-5 | 6.27e+04 | 0.6% | 4.19 | 202 | 202 | 696 | 706 | 1.01x |
| SQRT U32 ROOT | 0 | 0 | 0 | 100.0% | 4.05 | 50 | 64 | 164 | 148 | 0.96x |
| SQRT U32 BITWISE | 0 | 0 | 0 | 100.0% | 31.45 | 145 | 133 | 164 | 148 | 1.15x |
| SQRT U64 ROOT | 0 | 0 | 0 | 100.0% | 9.09 | 534 | 569 | 815 | 725 | 1.02x |
| SQRT Q31 NEWTON | 0 | 0 | 0 | 100.0% | 8.82 | 528 | 569 | 767 | 729 | 1.00x |
| SAT ADD INT8_Q7 | 0 | 0 | 0 | 100.0% | 0.55 | 14 | 20 | 25 | 40 | 0.51x |
| SAT MUL INT32_Q31 | 1 | 4.66e-10 | 0.585 | 50.1% | 0.41 | 10 | 22 | 46 | 56 | 0.49x |
| SAT DIV INT32_Q31 | 0.997 | 4.64e-10 | 0.402 | 76.2% | 2.24 | 152 | 152 | 787 | 785 | 1.00x |
| UNSAT ADD INT32_Q31 | 0 | 0 | 0 | 100.0% | 0.45 | 18 | 22 | 31 | 32 | 0.35x |
| Q2Q SAT INT16 14->15 | 0 | 0 | 0 | 100.0% | 0.85 | 13 | 16 | 23 | 23 | 0.51x |
| Q2F INT8_Q7 | 0 | 0 | 0 | 100.0% | 0.37 | 47 | 33 | 91 | 67 | 0.60x |
| Q2I INT32_Q31 | 0 | 0 | 0 | 100.0% | 0.37 | 9 | 10 | 13 | 14 | 0.55x |
| F2Q SAT INT8_Q7 | 0.997 | 7.79e-3 | 0.466 | 66.8% | 0.64 | 69 | 32 | 104 | 53 | 0.54x |
| F2Q SAT INT32_Q31 | 0.5 | 2.33e-10 | 0.0155 | 99.9% | 0.66 | 67 | 30 | 102 | 53 | 0.54x |
| I2Q SAT INT32_Q31 | 0 | 0 | 0 | 100.0% | 0.53 | 20 | 19 | 37 | 31 | 0.67x |
| Q2F TI INT32_Q31 | 4.66e-10 | 相对 | 1.45e-11 | 100.0% | 1.08 | 21 | 25 | 35 | 49 | 0.86x |
| Q2I TI INT32_Q31 | 0 | 0 | 0 | 100.0% | 0.36 | 9 | 10 | 13 | 14 | 0.53x |
| QVAL FLOAT->INT32 | 0 | 0 | 0 | 100.0% | 1.11 | 43 | 15 | 57 | 20 | 0.94x |

> 完整 105 个用例的逐项数据（含 53 种格式的三角/反三角/开方/atan2）由仓库外的 QA 脚本生成；上表为每族代表项。`Q2F TI` 的误差是 `float` 表示误差（相对值），不是 LSB。
>
> `精确率` 是逐 LSB 的严格指标（`|误差| < 0.5 LSB` 的采样点占比），查表/截断类实现天然偏低：`SIN_COS Q31 SUBDIV` 的最大误差约一个表步长（`2π/32768 ≈ 1.92e-4`，即 `4.4e5` LSB），组合接口要求 sin、cos **同时**命中半 LSB，因此 `0.0%` 表示「不与理想四舍五入值逐 LSB 相同」，而非功能错误；需要逐 LSB 精度时改用 CORDIC30（最大 64 LSB）。
>
> LSB 单位换算：Q31 输出 `1 LSB = 2^-31 ≈ 4.66e-10`，表中 `4.37e5 LSB ≈ 2.0e-4`（满量程约 0.02%）。「归一化绝对值」= 最大误差 × 该用例输出格式的 1 LSB（Q31 为 `2^-31`，`INT8_Q7` 为 `2^-7 ≈ 7.8e-3`，整数/QVAL 为 1）；`Q2F TI` 行为 `float` 相对误差，标为「相对」。

### 7.3 选型建议

| 需求 | 建议 |
|---|---|
| 通用 ARM 工程 | 保持默认（四则/转换 = 1，SAT ADD/SUB = 0，三角查表 = 1，CORDIC/逐位/atan2 = 0） |
| Cortex-M0/M0+ 且 Flash 紧张 | 保持默认即可：sqrt/atan2 自动无除法；关闭 asin/acos 表可省 64 KB |
| 极小程序（< 64 KB Flash） | 关闭 `ARCSIN_ARCCOS`、`SIN_COS SUBDIV` 表族，改用 CORDIC（`LQ_SIN_COS_PU_CORDIC_DEPTH_LOADING_MODE=1`） |
| 极限吞吐（x86） | 可把四则/转换 19 族全部改 2（注意第 10.2 节的副作用约束） |
| 调试期 | 全部改 0，便于单步与断点 |

## 8. 三环境编译与自测

### 8.1 自测程序

`Project1/main.c`（约 2700 行）是覆盖全库的穷举自测：

- 每族 109 个具名接口 + 6 个泛型接口；
- sin/cos 53 种格式、asin/acos、sqrt 全路径、atan2、QVAL、TI 风格；
- 饱和/非饱和边界、溢出、除零、NaN、参数越界、错误码校验。

预期输出：

```
[SUMMARY]
  total checks : 45718633
  failures     : 0
RESULT: PASS
```

### 8.2 GCC

```bash
# 库 + 应用
gcc -O2 -std=c99 -I Inc Src/*.c app.c -o app

# Cortex-M 交叉编译（示例：M3）
arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -O2 -std=c99 -I Inc \
    Src/*.c app.c -o app.elf
```

### 8.3 Keil MDK（AC5 / AC6）

1. Options for Target → C/C++ → Include Paths 添加 `..\Inc`；
2. 把 `Src/*.c` 全部加入工程；
3. AC5：勾选 **C99 Mode**；AC6：默认语言标准即可；
4. 需要 ARM `__ssat/__usat` 快路径时保持 `LQ_ARM_DSP_SSAT_ENABLE = 1`（默认，`armclang`/`armcc` 均支持内建）；
5. 库不依赖 `printf/malloc`，是否使用 MicroLIB 均可。

已在以下组合通过编译与自测：

| 工具链 | 内核 | 优化 | 结果 |
|---|---|---|---|
| Keil AC6 6.x | Cortex-M3 | -O2 | 编译 0 错误，精度与 PC 一致 |
| Keil AC6 6.x | Cortex-M0 | -O2 | 编译 0 错误 |
| Keil AC5 5.x | Cortex-M3 | -O2 --c99 | 编译 0 错误 |
| Keil AC5 5.x | Cortex-M0 | -O2 --c99 | 编译 0 错误 |

### 8.4 Visual Studio 2022

1. 项目属性 → C/C++ → 常规 → 附加包含目录：`$(ProjectDir)..\LittleQmath\Inc`；
2. 把 `Src/*.c` 加入「源文件」；
3. C 语言标准选 C11（库代码本身兼容 C99）；
4. 已验证 **Debug|Win32、Release|Win32、Debug|x64、Release|x64** 四种配置全部编译通过、运行 `RESULT: PASS`（各 45,718,633 项检查）。

> 参考工程：`Project1/Project1.vcxproj`，四种配置的附加包含目录均已配置。

## 9. Cortex-M0/M0+ 与 M3+ 的自动分支

M0/M0+ 没有硬件除法与部分 DSP 指令，库通过 4.4 的自动开关选择等价实现，**应用代码无需改动**：

| 能力 | M3/M4/M7（ARMv7-M+） | M0/M0+（ARMv6-M / ARMv8-M Baseline） |
|---|---|---|
| 饱和加/减 | `__ssat/__usat` 单指令 | 同一个宏映射为可移植钳位（分支实现） |
| sqrt | 牛顿迭代（硬件除法） | `LQ_SQRT_NODIV_ENABLE=1`：`ROOT` 入口自动改用逐位法 |
| atan2 | 硬件 64 位除法 | `LQ_ARCTAN2_NODIV_ENABLE=1`：移位长除法替代 |
| CORDIC | 常规移位 | `LQ_CORDIC_SHIFT_ENABLE=1`：流水移位近似 |
| TI Q→float | CLZ 指令求指数 | 循环归一化（`…_CLZ_ENABLE=0`） |

代价已量化：M0 上 `SQRT U32 ROOT` 为 164 IC（M3 为 50 IC），`SQRT U64 ROOT` 为 815 IC（M3 为 534 IC）；若不希望走逐位法，可在工程中强制 `-DLQ_SQRT_NODIV_ENABLE=0`（会引入除法库调用，通常更慢且更大）。

## 10. 注意事项

### 10.1 错误变量

见 6.1：每次调用前重置、始终传有效指针。

### 10.2 模式 2 的参数副作用

宏展开模式（`…_LOADING_MODE == 2`）为了消除函数调用做了表达式内联，**同一个参数可能在展开式里出现多次**：

```c
/* 危险：i 可能自增多次 */
LQ_SATURATION_INT8_Q7_ADD(i++, j, &Err);
```

模式 2 下请只传入纯变量/常量/无副作用表达式。模式 0/1 无此限制。

### 10.3 三角函数单位

所有 `*_PU_*` 接口的输入/输出都是 **π 归一化**（值 = 角度/π），不是弧度。弧度换算：`pu = rad / π`。

### 10.4 Q 值合法性

`Q_A/Q_B` 有合法范围（见 5.5），越界置 `LQ_Q_FORMAT_PARAMETER_ERROR` 并返回 0；编译期无法检查运行时传入的 Q 值，请自查。

### 10.5 代码体积

- 代码与数据的体积完全跟随 `lq_mode.h` 中的装载模式与 `_ENABLE` 开关：只编译实际启用的族、格式和细分表，未启用的不产生任何函数与常量，可按工程需要裁剪；
- 查表族是 Flash 的主要消耗（默认 sin/cos 16 KB + asin/acos 64 KB，合计 80 KB；关闭 `_ENABLE` 后表与对应函数一起不参与编译）；
- 模式 1 会在每个包含头文件的编译单元内生成内联副本，开启 LTO/`-ffunction-sections` 后可合并；
- 模式 2 在函数调用密集的场景会显著增大代码。

### 10.6 可重入性

库无全局可变状态，所有接口可重入、可多任务并发调用；错误变量由调用方提供，**不要在多任务间共享同一个 `LQ_ERROR`**。

### 10.7 未使用的保留宏

`LQ_OPERATIONS_GLOBAL_MODE` 为历史保留，当前不参与编译分支。

---

Copyright (c) 2018-2025 黑龙江大学 A8 楼 514
