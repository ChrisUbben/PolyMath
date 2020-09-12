//-----------------------------------------------------------------------------
// Filename: Vec2.h
// Project: PolyMath
// Author: Chris Ubben
// Creation Date: 2018/09/01
//-----------------------------------------------------------------------------

#ifndef POLYMATH_VEC2_H
#define POLYMATH_VEC2_H

// Precompiled Headers
#include "stdafx.h"

// System Headers

// Library Headers

// Project Headers
#include "PolyFloat.h"

// Defines/Macros

namespace PolyMath
{
    //====================== Class Declarations =========================

    class Vec2
    {
    public:
        //======================= Public floatypes/Constants ======================

        //======================= Public Static Members =======================

        // Returns the zero vector
        static Vec2 Zero();

        //======================= Constructors/Destructors ====================

        // Default constructor
        Vec2();
        // Component wise constructor
        Vec2(float x, float y);
        // Initializer list constructor
        Vec2(std::initializer_list<float> elements);
        // Copy constructor
        Vec2(const Vec2& copy);
        // Conversion constructor from array of elements
        explicit Vec2(const std::array<float, 2>& elements);

        // Default destructor
        ~Vec2() = default;

        //======================= Public Methods ==============================

        // Returns dot product of this vector by rhs
        float Dot(const Vec2& rhs) const;
        // Scales vector components by c
        Vec2& Scale(float c);
        // Returns vector with each component scaled by c
        Vec2 Scaled(float c) const;
        // Magnitude (length) of the vector
        float Length() const;
        // Normalize vector in place
        Vec2& Normalize();
        // Returns normalized version of vector
        Vec2 Normalized() const;

        //======================= Public Operator Overloads ===================

        // Assignment operator
        Vec2& operator=(const Vec2& rhs);
        // Access components with array syntax
        float& operator[](std::size_t i);
        // Access components with array syntax
        float operator[](std::size_t i) const;

        //======================= Public Properties ===========================

        // Euclidean components
        float& x;
        float& y;

        // basis components
        float& i;
        float& j;

    private:
        //======================= Private floatypes/Constants =====================

        //======================= Private Static Members ======================

        //======================= Private Methods =============================

        //======================= Private Operator Overloads ==================

        //======================= Private Properties ==========================

        // Actual component data
        std::array<float, 2> m_data;
    };

    //====================== Non-Member Declarations =========================

    // Magnitude (length) of the vector
    float Length(const Vec2& v);

    // Normalize vector in place
    Vec2& Normalize(Vec2& v);

    // Returns normalized version of vector
    Vec2 Normalized(const Vec2& v);

    // Dot product of 2D vectors
    //  Dot(v,w) = | v0 | * | w0 | = Sum(v[i] * w[i]), 0 <= i < 2
    //             | v1 |   | w0 | 
    float Dot(const Vec2& lhs, const Vec2& rhs);

    // 2D component wise vector multiplication
    //  v * w = | v0 | * | w0 | = | v0 * w0 |
    //          | v1 |   | w0 |   | v1 * w1 |
    Vec2 operator*(const Vec2& lhs, const Vec2& rhs);

    // 2D component wise vector multiplication
    //  v * w = | v0 | * | w0 | = | v0 * w0 |
    //          | v1 |   | w0 |   | v1 * w1 |
    Vec2& operator*=(Vec2& lhs, const Vec2& rhs);

    // 2D vector scale
    //  c * v = c * | v0 | = | c * v0 |
    //              | v1 |   | c * v1 |
    Vec2 operator*(float c, const Vec2& v);
    Vec2 operator*(const Vec2& v, float c);

    // 2D vector scale
    //  c * v = c * | v0 | = | c * v0 |
    //              | v1 |   | c * v1 |
    Vec2& operator*=(Vec2& v, float c);

    // 2D vector addition
    //  v + w = | v0 | + | w0 | = | v0 + w0 |
    //          | v1 |   | w0 |   | v1 + w1 |
    Vec2 operator+(const Vec2& lhs, const Vec2& rhs);

    // 2D vector addition
    //  v + w = | v0 | + | w0 | = | v0 + w0 |
    //          | v1 |   | w0 |   | v1 + w1 |
    Vec2& operator+=(Vec2& lhs, const Vec2& rhs);

    // 2D vector subtraction
    //  v - w = | v0 | - | w0 | = | v0 - w0 |
    //          | v1 |   | w0 |   | v1 - w1 |
    Vec2 operator-(const Vec2& lhs, const Vec2& rhs);

    // 2D vector subtraction
    //  v - w = | v0 | - | w0 | = | v0 - w0 |
    //          | v1 |   | w0 |   | v1 - w1 |
    Vec2& operator-=(Vec2& lhs, const Vec2& rhs);

    // 2D vector negation
    //  -v = | -v0 |
    //       | -v1 |
    Vec2 operator-(const Vec2& v);

    // 2D vector equal
    bool operator==(const Vec2& lhs, const Vec2& rhs);
}
#endif
