//-----------------------------------------------------------------------------
// Filename: Float.cpp
// Project: PolyMath
// Author: Chris Ubben
// Creation Date: 2019/01/05
//-----------------------------------------------------------------------------

// Precompiled Headers
#include "stdafx.h"

// System Headers

// Library Headers

// Project Headers
#include "PolyFloat.h"

namespace PolyMath
{
    namespace Float
    {
        bool Equals(float a, float b, float epsilon /*= Epsilon*/)
        {
            return std::fabs(a - b) <= epsilon;
        }
    }
}
