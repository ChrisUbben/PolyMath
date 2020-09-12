//-----------------------------------------------------------------------------
// Filename: Vec2.cpp
// Project: PolyMath
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

namespace PolyMath
{
    //================ Vec2 Member Implementations ===================

    // Returns the zero vector
    Vec2 PolyMath::Vec2::Zero()
    {
        return Vec2();
    }

    // Default constructor
    PolyMath::Vec2::Vec2() : m_data({ 0.0f, 0.0f }),
        x(m_data[0]), y(m_data[1]),
        i(m_data[0]), j(m_data[1])
    {
    }

    // Component wise constructor
    PolyMath::Vec2::Vec2(float x, float y) : m_data({ x, y }),
        x(m_data[0]), y(m_data[1]),
        i(m_data[0]), j(m_data[1])
    {
    }

    // Initializer list constructor
    PolyMath::Vec2::Vec2(std::initializer_list<float> elements) : m_data({ (elements.begin())[0], (elements.begin())[1] }),
        x(m_data[0]), y(m_data[1]),
        i(m_data[0]), j(m_data[1])
    {
        // Assert initializer list is correct size
    }

    // Copy constructor
    PolyMath::Vec2::Vec2(const Vec2& copy) : m_data({ copy.x, copy.y }),
        x(m_data[0]), y(m_data[1]),
        i(m_data[0]), j(m_data[1])
    {
    }

    // Conversion constructor from array of elements
    PolyMath::Vec2::Vec2(const std::array<float, 2>& elements) : m_data({ elements[0], elements[1] }),
        x(m_data[0]), y(m_data[1]),
        i(m_data[0]), j(m_data[1])
    {
    }

    // Returns dot product of this vector by rhs
    float PolyMath::Vec2::Dot(const Vec2& rhs) const
    {
        return PolyMath::Dot(*this, rhs);
    }

    // Scales vector components by c
    PolyMath::Vec2& PolyMath::Vec2::Scale(float c)
    {
        return (*this) *= c;
    }

    // Returns vector with each component scaled by c
    PolyMath::Vec2 PolyMath::Vec2::Scaled(float c) const
    {
        return c * (*this);
    }

    // Magnitude (length) of the vector
    float PolyMath::Vec2::Length() const
    {
        return PolyMath::Length(*this);
    }

    // Normalize vector in place
    PolyMath::Vec2& PolyMath::Vec2::Normalize()
    {
        return PolyMath::Normalize(*this);
    }

    // Returns normalized version of vector
    PolyMath::Vec2 PolyMath::Vec2::Normalized() const
    {
        return PolyMath::Normalized(*this);
    }

    // Assignment operator
    PolyMath::Vec2& PolyMath::Vec2::operator=(const Vec2& rhs)
    {
        if (this == &rhs)
            return (*this);

        m_data[0] = rhs[0];
        m_data[1] = rhs[0];
        return *this;
    }

    // Access components with array syntax
    float& PolyMath::Vec2::operator[](std::size_t index)
    {
        // Assert index not out of range

        return m_data[index];
    }

    // Access components with array syntax
    float PolyMath::Vec2::operator[](std::size_t index) const
    {
        // Assert index not out of range

        return m_data[index];
    }

    //====================== Non-Member Implementations =========================

    // Magnitude (length) of the vector
    float Length(const Vec2& v)
    {
        return std::sqrt(Dot(v, v));
    }

    // Normalize vector in place
    Vec2& Normalize(Vec2& v)
    {
        float len = Length(v);
        v.x = v.x / len;
        v.y = v.y / len;
        return v;
    }

    // Returns normalized version of vector
    Vec2 Normalized(const Vec2& v)
    {
        float len = Length(v);
        return Vec2({ (v.x / len),
                      (v.y / len) });
    }

    // Dot product of 2D vectors
    //  Dot(v,w) = | v0 | * | w0 | = Sum(v[i] * w[i]), 0 <= i < 2
    //             | v1 |   | w0 | 
    float Dot(const Vec2& lhs, const Vec2& rhs)
    {
        return (lhs.x * rhs.x) + (lhs.y * rhs.y);
    }

    // 2D component wise vector multiplication
    //  v * w = | v0 | * | w0 | = | v0 * w0 |
    //          | v1 |   | w0 |   | v1 * w1 |
    Vec2 operator*(const Vec2& lhs, const Vec2& rhs)
    {
        return Vec2({ (lhs.x * rhs.x),
                      (lhs.y * rhs.y) });
    }

    // 2D component wise vector multiplication
    //  v * w = | v0 | * | w0 | = | v0 * w0 |
    //          | v1 |   | w0 |   | v1 * w1 |
    Vec2& operator*=(Vec2& lhs, const Vec2& rhs)
    {
        lhs.x *= rhs.x;
        lhs.y *= rhs.y;
        return lhs;
    }

    // 2D vector scale
    //  c * v = c * | v0 | = | c * v0 |
    //              | v1 |   | c * v1 |
    Vec2 operator*(float c, const Vec2& v)
    {
        return Vec2({ (c * v.x),
                      (c * v.y) });
    }
    Vec2 operator*(const Vec2& v, float c)
    {
        return c * v;
    }

    // 2D vector scale
    //  c * v = c * | v0 | = | c * v0 |
    //              | v1 |   | c * v1 |
    Vec2& operator*=(Vec2& v, float c)
    {
        v.x *= c;
        v.y *= c;
        return v;
    }

    // 2D vector addition
    //  v + w = | v0 | + | w0 | = | v0 + w0 |
    //          | v1 |   | w0 |   | v1 + w1 |
    Vec2 operator+(const Vec2& lhs, const Vec2& rhs)
    {
        return Vec2({ (lhs.x + rhs.x),
                      (lhs.y + rhs.y) });
    }

    // 2D vector addition
    //  v + w = | v0 | + | w0 | = | v0 + w0 |
    //          | v1 |   | w0 |   | v1 + w1 |
    Vec2& operator+=(Vec2& lhs, const Vec2& rhs)
    {
        lhs.x += rhs.x;
        lhs.y += rhs.y;
        return lhs;
    }

    // 2D vector subtraction
    //  v - w = | v0 | - | w0 | = | v0 - w0 |
    //          | v1 |   | w0 |   | v1 - w1 |
    Vec2 operator-(const Vec2& lhs, const Vec2& rhs)
    {
        return Vec2({ (lhs.x - rhs.x),
                      (lhs.y - rhs.y) });
    }

    // 2D vector subtraction
    //  v - w = | v0 | - | w0 | = | v0 - w0 |
    //          | v1 |   | w0 |   | v1 - w1 |
    Vec2& operator-=(Vec2& lhs, const Vec2& rhs)
    {
        lhs.x -= rhs.x;
        lhs.y -= rhs.y;
        return lhs;
    }

    // 2D vector negation
    //  -v = | -v0 |
    //       | -v1 |
    Vec2 operator-(const Vec2& v)
    {
        return Vec2({ (-v.x),
                      (-v.y) });
    }

    // 2D vector equal
    bool operator==(const Vec2& lhs, const Vec2& rhs)
    {
        if (&lhs == &rhs)
            return true;

        //else
        return Float::Equals(lhs[0], rhs[0]) && Float::Equals(lhs[1], rhs[1]);
    }
}
