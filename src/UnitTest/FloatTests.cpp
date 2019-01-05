//-----------------------------------------------------------------------------
// Filename: FloatTests.cpp
// Project: UnitTest
// Author: Chris Ubben
// Creation Date: 2019/01/05
//-----------------------------------------------------------------------------

// Precompiled Headers
#include "pch.h"

using namespace PolygonalMath;

#pragma region FloatTests

TEST(MathTests, FloatEqualsPositiveTest)
{
    float a = 1.0f;
    float b = 1.0f;
    EXPECT_TRUE(Float::Equals(a, b));
}

TEST(MathTests, FloatEqualsNegativeTest)
{
    float a = 0.0f;
    float b = 1.0f;
    EXPECT_TRUE(!Float::Equals(a, b));
}

TEST(MathTests, FloatEqualsCustomEpsilonTest)
{
    float a = 0.99f;
    float b = 1.0f;
    EXPECT_TRUE(Float::Equals(a, b, 0.1f));
}

#pragma endregion FloatTests
