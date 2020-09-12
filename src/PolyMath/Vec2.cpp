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
    //================ Vec2 Member Implementations ===================

    // Returns the zero vector
    Vec2 PolygonalMath::Vec2::Zero()
    {
        return Vec2();
    }

    // Default constructor
    PolygonalMath::Vec2::Vec2() : m_data({ 0.0f, 0.0f }),
        x(m_data[0]), y(m_data[1]),
        i(m_data[0]), j(m_data[1])
    {
    }

    // Component wise constructor
    PolygonalMath::Vec2::Vec2(float x, float y) : m_data({ x, y }),
        x(m_data[0]), y(m_data[1]),
        i(m_data[0]), j(m_data[1])
    {
    }

    // Initializer list constructor
    PolygonalMath::Vec2::Vec2(std::initializer_list<float> elements) : m_data({ (elements.begin())[0], (elements.begin())[1] }),
        x(m_data[0]), y(m_data[1]),
        i(m_data[0]), j(m_data[1])
    {
        // Assert initializer list is correct size
    }

    // Copy constructor
    PolygonalMath::Vec2::Vec2(const Vec2& copy) : m_data({ copy.x, copy.y }),
        x(m_data[0]), y(m_data[1]),
        i(m_data[0]), j(m_data[1])
    {
    }

    // Conversion constructor from array of elements
    PolygonalMath::Vec2::Vec2(const std::array<float, 2>& elements) : m_data({ elements[0], elements[1] }),
        x(m_data[0]), y(m_data[1]),
        i(m_data[0]), j(m_data[1])
    {
    }

    // Returns dot product of this vector by rhs
    float PolygonalMath::Vec2::Dot(const Vec2& rhs) const
    {
        return PolygonalMath::Dot(*this, rhs);
    }

    // Scales vector components by c
    PolygonalMath::Vec2& PolygonalMath::Vec2::Scale(float c)
    {
        return (*this) *= c;
    }

    // Returns vector with each component scaled by c
    PolygonalMath::Vec2 PolygonalMath::Vec2::Scaled(float c) const
    {
        return c * (*this);
    }

    // Magnitude (length) of the vector
    float PolygonalMath::Vec2::Length() const
    {
        return PolygonalMath::Length(*this);
    }

    // Normalize vector in place
    PolygonalMath::Vec2& PolygonalMath::Vec2::Normalize()
    {
        return PolygonalMath::Normalize(*this);
    }

    // Returns normalized version of vector
    PolygonalMath::Vec2 PolygonalMath::Vec2::Normalized() const
    {
        return PolygonalMath::Normalized(*this);
    }

    // Assignment operator
    PolygonalMath::Vec2& PolygonalMath::Vec2::operator=(const Vec2& rhs)
    {
        if (this == &rhs)
            return (*this);

        m_data[0] = rhs[0];
        m_data[1] = rhs[0];
        return *this;
    }

    // Access components with array syntax
    float& PolygonalMath::Vec2::operator[](std::size_t index)
    {
        // Assert index not out of range

        return m_data[index];
    }

    // Access components with array syntax
    float PolygonalMath::Vec2::operator[](std::size_t index) const
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
