//-----------------------------------------------------------------------------
// Filename: Float.h
// Project: PolygonalMath
// Author: Chris Ubben
// Creation Date: 2019/01/05
//-----------------------------------------------------------------------------

#ifndef POLYGONALMATH_FLOAT_H
#define POLYGONALMATH_FLOAT_H

// Precompiled Headers
#include "stdafx.h"

// System Headers

// Library Headers

// Project Headers

// Defines/Macros

namespace PolygonalMath
{
    namespace Float
    {
        constexpr float Epsilon = 0.000001f;

        bool Equals(float a, float b, float epsilon = Epsilon);
    }
}

#endif
