//-----------------------------------------------------------------------------
// Filename: Float.h
// Project: PolyMath
// Author: Chris Ubben
// Creation Date: 2019/01/05
//-----------------------------------------------------------------------------

#ifndef POLYMATH_FLOAT_H
#define POLYMATH_FLOAT_H

// Precompiled Headers
#include "stdafx.h"

// System Headers

// Library Headers

// Project Headers

// Defines/Macros

namespace PolyMath
{
    namespace Float
    {
        constexpr float Epsilon = 0.000001f;

        bool Equals(float a, float b, float epsilon = Epsilon);
    }
}

#endif
