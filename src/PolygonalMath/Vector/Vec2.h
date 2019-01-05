//-----------------------------------------------------------------------------
// Filename: Vec2.h
// Project: PolygonalMath
// Author: Chris Ubben
// Creation Date: 2018/09/01
//-----------------------------------------------------------------------------

#ifndef POLYGONALMATH_VEC2_H
#define POLYGONALMATH_VEC2_H

// Precompiled Headers
#include "stdafx.h"

// System Headers

// Library Headers

// Project Headers
#include "Math\PolyFloat.h"
#include "Math\PolyDouble.h"

// Defines/Macros

namespace PolygonalMath
{
    //====================== Class Declarations =========================

    template <typename T>
    class Vec2
    {
    public:
        //======================= Public Types/Constants ======================

        //======================= Public Static Members =======================

        // Returns the zero vector
        static Vec2 Zero();

        //======================= Constructors/Destructors ====================

        // Default constructor
        Vec2();
        // Component wise constructor
        Vec2(const T& x, const T& y);
        // Initializer list constructor
        Vec2(std::initializer_list<T> elements);
        // Copy constructor
        Vec2(const Vec2& copy);
        // Conversion constructor from array of elements
        explicit Vec2(const std::array<T, 2>& elements);

        // Default destructor
        ~Vec2() = default;

        //======================= Public Methods ==============================

        // Returns dot product of this vector by rhs
        T Dot(const Vec2<T>& rhs) const;
        // Scales vector components by c
        Vec2<T>& Scale(T c);
        // Returns vector with each component scaled by c
        Vec2<T> Scaled(T c) const;
        // Magnitude (length) of the vector
        float Length() const;
        // Normalize vector in place
        Vec2<float>& Normalize();
        // Returns normalized version of vector
        Vec2<float> Normalized() const;

        //======================= Public Operator Overloads ===================

        // Assignment operator
        Vec2<T>& operator=(const Vec2<T>& rhs);
        // Access components with array syntax
        T& operator[](std::size_t i);
        // Access components with array syntax
        const T& operator[](std::size_t i) const;

        //======================= Public Properties ===========================

        // Euclidean components
        T& x;
        T& y;

        // basis components
        T& i;
        T& j;

    private:
        //======================= Private Types/Constants =====================

        //======================= Private Static Members ======================

        //======================= Private Methods =============================

        //======================= Private Operator Overloads ==================

        //======================= Private Properties ==========================

        // Actual component data
        std::array<T, 2> m_data;
    };

    //====================== Function Declarations =========================

    // Magnitude (length) of the vector
    float Length(const Vec2<float>& v);

    // Normalize vector in place
    Vec2<float>& Normalize(Vec2<float>& v);

    // Returns normalized version of vector
    Vec2<float> Normalized(const Vec2<float>& v);

    //================ Vec2 Member Template Implementations ===================

    // Returns the zero vector
    template <typename T>
    Vec2<T> PolygonalMath::Vec2<T>::Zero()
    {
        return Vec2<T>();
    }

    // Default constructor
    template <typename T>
    PolygonalMath::Vec2<T>::Vec2() : m_data({ T(0), T(0) }),
        x(m_data[0]), y(m_data[1]),
        i(m_data[0]), j(m_data[1])
    {
    }

    // Component wise constructor
    template <typename T>
    PolygonalMath::Vec2<T>::Vec2(const T& x, const T& y) : m_data({ T(x), T(y) }),
        x(m_data[0]), y(m_data[1]),
        i(m_data[0]), j(m_data[1])
    {
    }

    // Initializer list constructor
    template <typename T>
    PolygonalMath::Vec2<T>::Vec2(std::initializer_list<T> elements) : m_data({ (elements.begin())[0], (elements.begin())[1] }),
        x(m_data[0]), y(m_data[1]),
        i(m_data[0]), j(m_data[1])
    {
        // Assert initializer list is correct size
    }

    // Copy constructor
    template <typename T>
    PolygonalMath::Vec2<T>::Vec2(const Vec2& copy) : m_data({ copy.x, copy.y }),
        x(m_data[0]), y(m_data[1]),
        i(m_data[0]), j(m_data[1])
    {
    }

    // Conversion constructor from array of elements
    template <typename T>
    PolygonalMath::Vec2<T>::Vec2(const std::array<T, 2>& elements) : m_data({ elements[0], elements[1] }),
        x(m_data[0]), y(m_data[1]),
        i(m_data[0]), j(m_data[1])
    {
    }

    // Returns dot product of this vector by rhs
    template <typename T>
    T PolygonalMath::Vec2<T>::Dot(const Vec2<T>& rhs) const
    {
        return PolygonalMath::Dot(*this, rhs);
    }

    // Scales vector components by c
    template <typename T>
    PolygonalMath::Vec2<T>& PolygonalMath::Vec2<T>::Scale(T c)
    {
        return (*this) *= c;
    }

    // Returns vector with each component scaled by c
    template <typename T>
    PolygonalMath::Vec2<T> PolygonalMath::Vec2<T>::Scaled(T c) const
    {
        return c * (*this);
    }

    // Magnitude (length) of the vector
    template <typename T>
    float PolygonalMath::Vec2<T>::Length() const
    {
        return PolygonalMath::Length(*this);
    }

    // Normalize vector in place
    template <typename T>
    PolygonalMath::Vec2<float>& PolygonalMath::Vec2<T>::Normalize()
    {
        return PolygonalMath::Normalize(*this);
    }

    // Returns normalized version of vector
    template <typename T>
    PolygonalMath::Vec2<float> PolygonalMath::Vec2<T>::Normalized() const
    {
        return PolygonalMath::Normalized(*this);
    }

    // Assignment operator
    template <typename T>
    PolygonalMath::Vec2<T>& PolygonalMath::Vec2<T>::operator=(const Vec2<T>& rhs)
    {
        if (this == &rhs)
            return (*this);

        m_data[0] = rhs[0];
        m_data[1] = rhs[0];
        return *this;
    }

    // Access components with array syntax
    template <typename T>
    T& PolygonalMath::Vec2<T>::operator[](std::size_t index)
    {
        // Assert index not out of range

        return m_data[index];
    }

    // Access components with array syntax
    template <typename T>
    const T& PolygonalMath::Vec2<T>::operator[](std::size_t index) const
    {
        // Assert index not out of range

        return m_data[index];
    }

    //====================== Template Implementations =========================

    // Dot product of 2D vectors
    //  Dot(v,w) = | v0 | * | w0 | = Sum(v[i] * w[i]), 0 <= i < 2
    //             | v1 |   | w0 | 
    template <typename T>
    T Dot(const Vec2<T>& lhs, const Vec2<T>& rhs)
    {
        return (lhs.x * rhs.x) + (lhs.y * rhs.y);
    }

    // 2D component wise vector multiplication
    //  v * w = | v0 | * | w0 | = | v0 * w0 |
    //          | v1 |   | w0 |   | v1 * w1 |
    template <typename T>
    Vec2<T> operator*(const Vec2<T>& lhs, const Vec2<T>& rhs)
    {
        return Vec2<T>({ (lhs.x * rhs.x),
                         (lhs.y * rhs.y) });
    }

    // 2D component wise vector multiplication
    //  v * w = | v0 | * | w0 | = | v0 * w0 |
    //          | v1 |   | w0 |   | v1 * w1 |
    template <typename T>
    Vec2<T>& operator*=(Vec2<T>& lhs, const Vec2<T>& rhs)
    {
        lhs.x *= rhs.x;
        lhs.y *= rhs.y;
        return lhs;
    }

    // 2D vector scale
    //  c * v = c * | v0 | = | c * v0 |
    //              | v1 |   | c * v1 |
    template <typename T>
    Vec2<T> operator*(T c, const Vec2<T>& v)
    {
        return Vec2<T>({ (c * v.x),
                         (c * v.y) });
    }
    template <typename T>
    Vec2<T> operator*(const Vec2<T>& v, T c)
    {
        return c * v;
    }

    // 2D vector scale
    //  c * v = c * | v0 | = | c * v0 |
    //              | v1 |   | c * v1 |
    template <typename T>
    Vec2<T>& operator*=(Vec2<T>& v, T c)
    {
        v.x *= c;
        v.y *= c;
        return v;
    }

    // 2D vector addition
    //  v + w = | v0 | + | w0 | = | v0 + w0 |
    //          | v1 |   | w0 |   | v1 + w1 |
    template <typename T>
    Vec2<T> operator+(const Vec2<T>& lhs, const Vec2<T>& rhs)
    {
        return Vec2<T>({ (lhs.x + rhs.x),
                         (lhs.y + rhs.y) });
    }

    // 2D vector addition
    //  v + w = | v0 | + | w0 | = | v0 + w0 |
    //          | v1 |   | w0 |   | v1 + w1 |
    template <typename T>
    Vec2<T&> operator+=(Vec2<T>& lhs, const Vec2<T>& rhs)
    {
        lhs.x += rhs.x;
        lhs.y += rhs.y;
        return lhs;
    }

    // 2D vector subtraction
    //  v - w = | v0 | - | w0 | = | v0 - w0 |
    //          | v1 |   | w0 |   | v1 - w1 |
    template <typename T>
    Vec2<T> operator-(const Vec2<T>& lhs, const Vec2<T>& rhs)
    {
        return Vec2<T>({ (lhs.x - rhs.x),
                         (lhs.y - rhs.y) });
    }

    // 2D vector subtraction
    //  v - w = | v0 | - | w0 | = | v0 - w0 |
    //          | v1 |   | w0 |   | v1 - w1 |
    template <typename T>
    Vec2<T&> operator-=(Vec2<T>& lhs, const Vec2<T>& rhs)
    {
        lhs.x -= rhs.x;
        lhs.y -= rhs.y;
        return lhs;
    }

    // 2D vector negation
    //  -v = | -v0 |
    //       | -v1 |
    template <typename T>
    Vec2<T> operator-(const Vec2<T>& v)
    {
        return Vec2<T>({ (-v.x),
                         (-v.y) });
    }

    // 2D vector equal
    template <typename T>
    bool operator==(const Vec2<T>& lhs, const Vec2<T>& rhs)
    {
        if (&lhs == &rhs)
            return true;

        //else
        return lhs[0] == rhs[0] && lhs[1] == rhs[1];
    }

    // 2D vector equal
    template <>
    bool operator==(const Vec2<float>& lhs, const Vec2<float>& rhs);
    template <>
    bool operator==(const Vec2<double>& lhs, const Vec2<double>& rhs);
}
#endif
