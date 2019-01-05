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

TEST(Vec2Tests, Vec2FloatZeroTest)
{
    Vec2<float> zeroVec = Vec2<float>::Zero();
    EXPECT_TRUE(Float::Equals(zeroVec.x, 0.0f));
    EXPECT_TRUE(Float::Equals(zeroVec.y, 0.0f));
}

#pragma endregion StaticMemberTests

#pragma region ConstructorTests

TEST(Vec2Tests, Vec2FloatDefaultConstructorTest)
{
    Vec2<float> v = Vec2<float>();
    EXPECT_TRUE(Float::Equals(v.x, 0.0f));
    EXPECT_TRUE(Float::Equals(v.y, 0.0f));
}

TEST(Vec2Tests, Vec2FloatComponentConstructorTest)
{
    Vec2<float> v = Vec2<float>(1.0f, 2.0f);
    EXPECT_TRUE(Float::Equals(v.x, 1.0f));
    EXPECT_TRUE(Float::Equals(v.y, 2.0f));
}

TEST(Vec2Tests, Vec2FloatInitializerListConstructorTest)
{
    Vec2<float> v{ 1.0f, 2.0f };
    EXPECT_TRUE(Float::Equals(v.x, 1.0f));
    EXPECT_TRUE(Float::Equals(v.y, 2.0f));
}

TEST(Vec2Tests, Vec2FloatCopyConstructorTest)
{
    Vec2<float> v = Vec2<float>(1.0f, 2.0f);
    Vec2<float> v_copy = Vec2<float>(v);
    EXPECT_TRUE(Float::Equals(v_copy.x, 1.0f));
    EXPECT_TRUE(Float::Equals(v_copy.y, 2.0f));
    EXPECT_EQ(v, v_copy);
}

TEST(Vec2Tests, Vec2FloatConversionConstructorTest)
{
    std::array<float, 2> a{ 1.0f, 2.0f };
    Vec2<float> v = Vec2<float>(a);
    EXPECT_TRUE(Float::Equals(v.x, 1.0f));
    EXPECT_TRUE(Float::Equals(v.y, 2.0f));
}

#pragma endregion ConstructorTests

#pragma region MemberMethodTests

TEST(Vec2Tests, Vec2FloatDotProductPositiveTest)
{
    Vec2<float> v1 = Normalized(Vec2<float>{ 1.0f, 1.0f });
    Vec2<float> v2{ 0.0f, 1.0f };

    float dot = v1.Dot(v2);
    float expected = std::sqrt(2.0f) / 2.0f;

    EXPECT_TRUE(Float::Equals(dot, expected));
}

TEST(Vec2Tests, Vec2FloatDotProductNegativeTest)
{
    Vec2<float> v1 = Normalized(Vec2<float>{ -1.0f, 1.0f });
    Vec2<float> v2{ 1.0f, 0.0f };

    float dot = v1.Dot(v2);
    float expected = -1.0f * (std::sqrt(2.0f) / 2.0f);

    EXPECT_TRUE(Float::Equals(dot, expected));
}

TEST(Vec2Tests, Vec2FloatDotPerpendicularTest)
{
    Vec2<float> v1{ 1.0f, 0.0f };
    Vec2<float> v2{ 0.0f, 1.0f };
    float dot = v1.Dot(v2);
    EXPECT_TRUE(Float::Equals(dot, 0.0f));
}

TEST(Vec2Tests, Vec2FloatDotParallelTest)
{
    Vec2<float> v1{ 1.0f, 0.0f };
    Vec2<float> v2{ 1.0f, 0.0f };
    float dot = v1.Dot(v2);
    EXPECT_TRUE(Float::Equals(dot, 1.0f));
}

TEST(Vec2Tests, Vec2FloatDot180DegreeTest)
{
    Vec2<float> v1{ 1.0f, 0.0f };
    Vec2<float> v2{ -1.0f, 0.0f };
    float dot = v1.Dot(v2);
    EXPECT_TRUE(Float::Equals(dot, -1.0f));
}

TEST(Vec2Tests, Vec2ScaleZeroTest)
{
    Vec2<float> v{ 1.0f, 2.0f };
    v.Scale(0.0f);
    EXPECT_TRUE(Float::Equals(v.x, 0.0f));
    EXPECT_TRUE(Float::Equals(v.y, 0.0f));
}

#pragma endregion MemberMethodTests

#pragma endregion Vec2Tests
