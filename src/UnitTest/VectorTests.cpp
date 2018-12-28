//-----------------------------------------------------------------------------
// Filename: VectorTests.cpp
// Project: UnitTest
// Author: Chris Ubben
// Creation Date: 2018/12/27
//-----------------------------------------------------------------------------

// Precompiled Headers
#include "pch.h"

using namespace PolygonalMath;

TEST(Vec2Tests, Vec2IntZeroWorks) {
    Vec2<int> zeroVec = Vec2<int>::Zero();
    EXPECT_EQ(zeroVec.x, 0);
    EXPECT_EQ(zeroVec.y, 0);
}
