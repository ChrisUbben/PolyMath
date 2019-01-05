//-----------------------------------------------------------------------------
// Filename: Vec2.cpp
// Project: PolygonalMath
// Author: Chris Ubben
// Creation Date: 2018/09/01
//-----------------------------------------------------------------------------

// Precompiled Headers
#include "stdafx.h"

// System Headers

// Library Headers

// Project Headers
#include "Vec2.h"
#include <iostream>

namespace PolygonalMath
{
    // Magnitude (length) of the vector
    float Length(const Vec2<float>& v)
    {
        return std::sqrt(Dot(v, v));
    }

    // Normalize vector in place
    Vec2<float>& Normalize(Vec2<float>& v)
    {
        float len = Length(v);
        v.x = v.x / len;
        v.y = v.y / len;
        return v;
    }

    // Returns normalized version of vector
    Vec2<float> Normalized(const Vec2<float>& v)
    {
        float len = Length(v);
        return Vec2<float>({ (v.x / len),
                             (v.y / len) });
    }
}
