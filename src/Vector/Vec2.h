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

namespace PolygonalMath
{
    template <typename T>
    class Vec2
    {
    public:
        //======================= Public Types/Constants ======================

        //======================= Public Static Members =======================

        // Returns the zero vector
        static Vec2 Zero();

        //======================= Constructors/Destructors ====================

        // default constructor
        Vec2();
        Vec2(std::initializer_list<T> elements);
        Vec2(const Vec2& copy);
        explicit Vec2(const std::array<T, 2>& elements);
        ~Vec2() = default;

        //======================= Public Methods ==============================

        T Dot(const Vec2<T>& rhs);
        Vec2<T>& Scale(T c);
        Vec2<T> Scaled(T c);
        float Length();
        Vec2<float>& Normalize();
        Vec2<float> Normalized();

        //======================= Public Operator Overloads ===================
        Vec2<T>& operator=(const Vec2<T>& rhs);
        T& operator[](std::size_t i);

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
        void ZeroData();
        void SetReferences();

        //======================= Private Operator Overloads ==================

        //======================= Private Properties ==========================
        std::array<T, 2> m_data;
    };

    //====================== Template Implementations =========================

    template <typename T>
    void PolygonalMath::Vec2<T>::SetReferences()
    {
        x = i = m_data[0];
        y = j = m_data[1];
    }

    template <typename T>
    void PolygonalMath::Vec2<T>::ZeroData()
    {
        m_data[0] = T(0);
        m_data[1] = T(0);
    }

    template <typename T>
    Vec2<T> PolygonalMath::Vec2<T>::Zero()
    {
        return Vec2<T>();
    }

    template <typename T>
    T& PolygonalMath::Vec2<T>::operator[](std::size_t i)
    {
        // Assert index not out of range

        return m_data[i];
    }

    template <typename T>
    PolygonalMath::Vec2<T>& PolygonalMath::Vec2<T>::operator=(const Vec2<T>& rhs)
    {
        if (this == &rhs)
            return (*this);

        m_data[0] = rhs[0];
        m_data[1] = rhs[0];
        return *this;
    }

    template <typename T>
    PolygonalMath::Vec2<float> PolygonalMath::Vec2<T>::Normalized()
    {
        return PolygonalMath::Normalized(*this);
    }

    template <typename T>
    PolygonalMath::Vec2<float>& PolygonalMath::Vec2<T>::Normalize()
    {
        return PolygonalMath::Normalize(*this);
    }

    template <typename T>
    float PolygonalMath::Vec2<T>::Length()
    {
        return PolygonalMath::Length(*this);
    }

    template <typename T>
    PolygonalMath::Vec2<T> PolygonalMath::Vec2<T>::Scaled(T c)
    {
        return c * (*this);
    }

    template <typename T>
    PolygonalMath::Vec2<T>& PolygonalMath::Vec2<T>::Scale(T c)
    {
        return (*this) *= c;
    }

    template <typename T>
    T PolygonalMath::Vec2<T>::Dot(const Vec2<T>& rhs)
    {
        return PolygonalMath::Dot(*this, rhs);
    }

    template <typename T>
    PolygonalMath::Vec2<T>::Vec2(const std::array<T, 2>& elements)
    {
        SetReferences();

        m_data[0] = elements[0];
        m_data[1] = elements[1];
    }

    template <typename T>
    PolygonalMath::Vec2<T>::Vec2(const Vec2& copy)
    {
        SetReferences();

        m_data[0] = copy[0];
        m_data[1] = copy[1];
    }

    template <typename T>
    PolygonalMath::Vec2<T>::Vec2(std::initializer_list<T> elements)
    {
        // Assert initializer list is correct size

        SetReferences();

        m_data[0] = elements[0];
        m_data[1] = elements[1];
    }

    template <typename T>
    PolygonalMath::Vec2<T>::Vec2()
    {
        SetReferences();
        ZeroData();
    }

    // Dot product of 2D vectors
    //  Dot(v,w) = | v0 | * | w0 | = Sum(v[i] * w[i]), 0 <= i < 2
    //             | v1 |   | w0 | 
    template <typename T>
    T Dot(const Vec2<T>& lhs, const Vec2<T>& rhs)
    {
        return (lhs.x * rhs.x) + (lhs.y * rhs.y);
    }

    // Magnitude (length) of the vector
    float Length(const Vec2<float>& v)
    {
        return std::sqrt(Dot(v, v));
    }

    // Normalize vector in place
    Vec2<float>& Normalize(Vec2<float>& v)
    {
        float len = Length(v);
        v.x = v.x / len;
        v.y = v.y / len;
        return v;
    }

    // Returns normalized version of vector
    Vec2<float> Normalized(const Vec2<float>& v)
    {
        float len = Length(v);
        return Vec2<float>({ (v.x / len),
                             (v.y / len) });
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
    Vec2<T>& operator*=( Vec2<T>& v, T c)
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
}

#endif
