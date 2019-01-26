//-----------------------------------------------------------------------------
// Filename: VectorTests.cpp
// Project: UnitTest
// Author: Chris Ubben
// Creation Date: 2018/12/27
//-----------------------------------------------------------------------------

// Precompiled Headers
#include "pch.h"

using namespace PolygonalMath;

#pragma region Vec2Tests

#pragma region StaticMemberTests

TEST(Vec2Tests, Vec2ZeroTest)
{
    Vec2 zeroVec = Vec2::Zero();
    EXPECT_TRUE(Float::Equals(zeroVec.x, 0.0f));
    EXPECT_TRUE(Float::Equals(zeroVec.y, 0.0f));
}

#pragma endregion StaticMemberTests

#pragma region ConstructorTests

TEST(Vec2Tests, Vec2DefaultConstructorTest)
{
    Vec2 v = Vec2();
    EXPECT_TRUE(Float::Equals(v.x, 0.0f));
    EXPECT_TRUE(Float::Equals(v.y, 0.0f));
}

TEST(Vec2Tests, Vec2ComponentConstructorTest)
{
    Vec2 v = Vec2(1.0f, 2.0f);
    EXPECT_TRUE(Float::Equals(v.x, 1.0f));
    EXPECT_TRUE(Float::Equals(v.y, 2.0f));
}

TEST(Vec2Tests, Vec2InitializerListConstructorTest)
{
    Vec2 v{ 1.0f, 2.0f };
    EXPECT_TRUE(Float::Equals(v.x, 1.0f));
    EXPECT_TRUE(Float::Equals(v.y, 2.0f));
}

TEST(Vec2Tests, Vec2CopyConstructorTest)
{
    Vec2 v = Vec2(1.0f, 2.0f);
    Vec2 v_copy = Vec2(v);
    EXPECT_TRUE(Float::Equals(v_copy.x, 1.0f));
    EXPECT_TRUE(Float::Equals(v_copy.y, 2.0f));
    EXPECT_EQ(v, v_copy);
}

TEST(Vec2Tests, Vec2ConversionConstructorTest)
{
    std::array<float, 2> a{ 1.0f, 2.0f };
    Vec2 v = Vec2(a);
    EXPECT_TRUE(Float::Equals(v.x, 1.0f));
    EXPECT_TRUE(Float::Equals(v.y, 2.0f));
}

#pragma endregion ConstructorTests

#pragma region MemberMethodTests

TEST(Vec2Tests, Vec2DotProductPositiveTest)
{
    Vec2 v1 = Normalized(Vec2{ 1.0f, 1.0f });
    Vec2 v2{ 0.0f, 1.0f };

    float dot = v1.Dot(v2);
    float expected = std::sqrt(2.0f) / 2.0f;

    EXPECT_TRUE(Float::Equals(dot, expected));
}

TEST(Vec2Tests, Vec2DotProductNegativeTest)
{
    Vec2 v1 = Normalized(Vec2{ -1.0f, 1.0f });
    Vec2 v2{ 1.0f, 0.0f };

    float dot = v1.Dot(v2);
    float expected = -1.0f * (std::sqrt(2.0f) / 2.0f);

    EXPECT_TRUE(Float::Equals(dot, expected));
}

TEST(Vec2Tests, Vec2DotPerpendicularTest)
{
    Vec2 v1{ 1.0f, 0.0f };
    Vec2 v2{ 0.0f, 1.0f };
    float dot = v1.Dot(v2);
    EXPECT_TRUE(Float::Equals(dot, 0.0f));
}

TEST(Vec2Tests, Vec2DotParallelTest)
{
    Vec2 v1{ 1.0f, 0.0f };
    Vec2 v2{ 1.0f, 0.0f };
    float dot = v1.Dot(v2);
    EXPECT_TRUE(Float::Equals(dot, 1.0f));
}

TEST(Vec2Tests, Vec2Dot180DegreeTest)
{
    Vec2 v1{ 1.0f, 0.0f };
    Vec2 v2{ -1.0f, 0.0f };
    float dot = v1.Dot(v2);
    EXPECT_TRUE(Float::Equals(dot, -1.0f));
}

TEST(Vec2Tests, Vec2ScaleZeroTest)
{
    Vec2 v{ 1.0f, 2.0f };
    v.Scale(0.0f);
    EXPECT_TRUE(Float::Equals(v.x, 0.0f));
    EXPECT_TRUE(Float::Equals(v.y, 0.0f));
}

#pragma endregion MemberMethodTests

#pragma endregion Vec2Tests
