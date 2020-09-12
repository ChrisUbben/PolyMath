//-----------------------------------------------------------------------------
// Filename: PolyDouble.cpp
// Project: PolyMath
// Author: Chris Ubben
// Creation Date: 2019/01/05
//-----------------------------------------------------------------------------

// Precompiled Headers
#include "stdafx.h"

// System Headers

// Library Headers

// Project Headers
#include "PolyDouble.h"

namespace PolyMath
{

    bool Double::Equals(double a, double b, double epsilon /*= Epsilon*/)
    {
        return std::abs(a - b) <= epsilon;
    }
}
