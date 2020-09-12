//-----------------------------------------------------------------------------
// Filename: PolyDouble.h
// Project: PolygonalMath
// Author: Chris Ubben
// Creation Date: 2019/01/05
//-----------------------------------------------------------------------------

#ifndef POLYGONALMATH_POLYDOUBLE_H
#define POLYGONALMATH_POLYDOUBLE_H

// Precompiled Headers
#include "stdafx.h"

// System Headers

// Library Headers

// Project Headers

// Defines/Macros

namespace PolygonalMath
{
    namespace Double
    {
        constexpr double Epsilon = 0.0000000000000001;

        bool Equals(double a, double b, double epsilon = Epsilon);
    }
}

#endif
