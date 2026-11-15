#ifndef __LQ_FLOAT_TO_Q_VALUE_TYPE_H__
#define __LQ_FLOAT_TO_Q_VALUE_TYPE_H__

#include "lq_error.h"
#include "lq_mode.h"
#include "lq_type.h"
#include <string.h>

 
 
#if LQ_FLOAT_TO_Q_VALUE_TYPE_LOADING_MODE == 1

static const LQ_F_32BIT LQ_UINT16_Q_FLOAT_TO_Q_UPPER[17] =
{
    0.0f,
    32767.5f, 16383.75f, 8191.875f, 4095.9375f, 2047.96875f, 1023.984375f,
    511.9921875f, 255.99609375f, 127.998046875f, 63.9990234375f, 31.99951171875f,
    15.999755859375f, 7.9998779296875f, 3.99993896484375f, 1.99996948242188f,
    0.999984741210937f
};

static const LQ_F_32BIT LQ_INT16_Q_FLOAT_TO_Q_UPPER[16] =
{
    0.0f,
    16383.5f, 8191.75f, 4095.9375f, 2047.96875f, 1023.984375f,
    511.9921875f, 255.99609375f, 127.998046875f, 63.9990234375f, 31.99951171875f,
    15.999755859375f, 7.9998779296875f, 3.99993896484375f, 1.99996948242188f,
    0.999984741210937f
};

static const LQ_F_32BIT LQ_UINT8_Q_FLOAT_TO_Q_UPPER[9] =
{
    0.0f,
    127.5f, 63.75f, 31.875f, 15.9375f, 7.96875f, 3.984375f, 1.9921875f, 0.99609375f
};

static const LQ_F_32BIT LQ_INT8_Q_FLOAT_TO_Q_UPPER[8] =
{
    0.0f,
    63.75f, 31.875f, 15.9375f, 7.96875f, 3.984375f, 1.9921875f, 0.99609375f
};

LQ_INLINE int LQ_UINT32_Q_FLOAT_TO_Q_VALUE_TYPE(LQ_F_32BIT A)
{
    LQ_UI_32BIT Bits;
    LQ_I_32BIT Exp;

    if (!(A >= 0.0f))
    {
        return 0;
    }
    if (A < 1.0f)
    {
        return 32;
    }
    memcpy(&Bits, &A, sizeof(Bits));
    Exp = (LQ_I_32BIT)((Bits >> 23) & 0xFFu) - 127;
    if (Exp > 30)
    {
        return 0;
    }
    return 31 - Exp;
}

LQ_INLINE int LQ_INT32_Q_FLOAT_TO_Q_VALUE_TYPE(LQ_F_32BIT A)
{
    LQ_UI_32BIT Bits;
    LQ_I_32BIT Exp;
    LQ_I_32BIT Q;

    if (!(A >= 0.0f))
    {
        if (A >= -1.0f)
        {
            return 31;
        }
        memcpy(&Bits, &A, sizeof(Bits));
        Exp = (LQ_I_32BIT)((Bits >> 23) & 0xFFu) - 127;
        Q = 31 - Exp - (LQ_I_32BIT)((Bits & 0x7FFFFFu) != 0u);
        return (Q > 0) ? Q : 0;
    }
    if (A < 1.0f)
    {
        return 31;
    }
    memcpy(&Bits, &A, sizeof(Bits));
    Exp = (LQ_I_32BIT)((Bits >> 23) & 0xFFu) - 127;
    Q = 30 - Exp;
    return (Q > 0) ? Q : 0;
}

LQ_INLINE int LQ_UINT16_Q_FLOAT_TO_Q_VALUE_TYPE(LQ_F_32BIT A)
{
    LQ_UI_32BIT Bits;
    LQ_I_32BIT Q;

    if (!(A >= 0.0f))
    {
        return 0;
    }
    if (A < 0.5f)
    {
        return 16;
    }
    memcpy(&Bits, &A, sizeof(Bits));
    Q = 15 - ((LQ_I_32BIT)((Bits >> 23) & 0xFFu) - 127);
    if (Q < 1)
    {
        Q = 1;
    }
    return (A > LQ_UINT16_Q_FLOAT_TO_Q_UPPER[Q]) ? (Q - 1) : Q;
}

LQ_INLINE int LQ_INT16_Q_FLOAT_TO_Q_VALUE_TYPE(LQ_F_32BIT A)
{
    LQ_UI_32BIT Bits;
    LQ_I_32BIT Exp;
    LQ_I_32BIT Q;

    if (!(A >= 0.0f))
    {
        memcpy(&Bits, &A, sizeof(Bits));
        Exp = (LQ_I_32BIT)((Bits >> 23) & 0xFFu) - 127;
        Q = 14 - Exp + (LQ_I_32BIT)((Bits & 0x7FFFFFu) == 0u);
        if (Q > 15)
        {
            Q = 15;
        }
        return (Q > 0) ? Q : 0;
    }
    if (A < 0.5f)
    {
        return 15;
    }
    memcpy(&Bits, &A, sizeof(Bits));
    Exp = (LQ_I_32BIT)((Bits >> 23) & 0xFFu) - 127;
    if (Exp >= 14)
    {
        return 0;
    }
    Q = 14 - Exp;
    return (A > LQ_INT16_Q_FLOAT_TO_Q_UPPER[Q]) ? (Q - 1) : Q;
}

LQ_INLINE int LQ_UINT8_Q_FLOAT_TO_Q_VALUE_TYPE(LQ_F_32BIT A)
{
    LQ_UI_32BIT Bits;
    LQ_I_32BIT Q;

    if (!(A >= 0.0f))
    {
        return 0;
    }
    if (A < 0.5f)
    {
        return 8;
    }
    memcpy(&Bits, &A, sizeof(Bits));
    Q = 7 - ((LQ_I_32BIT)((Bits >> 23) & 0xFFu) - 127);
    if (Q < 1)
    {
        Q = 1;
    }
    return (A > LQ_UINT8_Q_FLOAT_TO_Q_UPPER[Q]) ? (Q - 1) : Q;
}

LQ_INLINE int LQ_INT8_Q_FLOAT_TO_Q_VALUE_TYPE(LQ_F_32BIT A)
{
    LQ_UI_32BIT Bits;
    LQ_I_32BIT Exp;
    LQ_I_32BIT Q;

    if (!(A >= 0.0f))
    {
        memcpy(&Bits, &A, sizeof(Bits));
        Exp = (LQ_I_32BIT)((Bits >> 23) & 0xFFu) - 127;
        Q = 6 - Exp + (LQ_I_32BIT)((Bits & 0x7FFFFFu) == 0u);
        if (Q > 7)
        {
            Q = 7;
        }
        return (Q > 0) ? Q : 0;
    }
    if (A < 0.5f)
    {
        return 7;
    }
    memcpy(&Bits, &A, sizeof(Bits));
    Exp = (LQ_I_32BIT)((Bits >> 23) & 0xFFu) - 127;
    if (Exp >= 6)
    {
        return 0;
    }
    Q = 6 - Exp;
    return (A > LQ_INT8_Q_FLOAT_TO_Q_UPPER[Q]) ? (Q - 1) : Q;
}
#endif

#if LQ_FLOAT_TO_Q_VALUE_TYPE_LOADING_MODE == 0
 int LQ_UINT32_Q_FLOAT_TO_Q_VALUE_TYPE(LQ_F_32BIT A);
 int LQ_INT32_Q_FLOAT_TO_Q_VALUE_TYPE(LQ_F_32BIT A);
 int LQ_UINT16_Q_FLOAT_TO_Q_VALUE_TYPE(LQ_F_32BIT A);
 int LQ_INT16_Q_FLOAT_TO_Q_VALUE_TYPE(LQ_F_32BIT A);
 int LQ_UINT8_Q_FLOAT_TO_Q_VALUE_TYPE(LQ_F_32BIT A);
 int LQ_INT8_Q_FLOAT_TO_Q_VALUE_TYPE(LQ_F_32BIT A);
#endif
 

#endif

