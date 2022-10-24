
#include <ostream>
#include <initializer_list>
#include <cassert>
#include <string>
#include <cstring>
#include <iterator>
#include <iostream>
#include <vector>
#include <initializer_list>
#include "vector.hh"

Vector& Vector::operator=(const Vector& v) {
    taille = v.size();
    for (size_t i = 0; i < taille; i++)
    {
        coord[i] = v[i];
    }
    return *this;
}

Vector::Vector(const Vector& v) {
    taille = v.size();
    coord = std::make_unique<value[]>(taille);
    for (size_t i = 0; i < taille; i++)
    {
        coord[i] = v[i];
    }
}

Vector::Vector(size_t N) {
    taille = N;
    coord = std::make_unique<value[]>(N);
    for (size_t i = 0; i < N; i++)
    {
        coord[i] = 0;
    }
}

Vector::Vector(std::initializer_list<value> l)
{
    taille = l.size();
    coord = std::make_unique<value[]>(taille);
    size_t index = 0;
    std::initializer_list<value>::iterator it;
    for (it = l.begin(); it != l.end(); ++it)
    {
        coord[index++] = *it;
    }
}

size_t Vector::size() const {
    return taille;
}

Vector& Vector::operator+=(const Vector &rhs)
{
    assert(rhs.size() == taille);
    for (size_t i = 0; i < rhs.size(); i++) {
        coord[i] += rhs[i];
    }
    return *this;
}

Vector& Vector::operator-=(const Vector &rhs)
{
    assert(rhs.size() == taille);
    for (size_t i = 0; i < rhs.size(); i++) {
        coord[i] -= rhs[i];
    }
    return *this;
}

Vector& Vector::operator+=(value lambda)
{
    for (size_t i = 0; i < taille; i++) {
        coord[i] += lambda;
    }
    return *this;
}

Vector& Vector::operator*=(value lambda)
{
    for (size_t i = 0; i < taille; i++) {
        coord[i] *= lambda;
    }
    return *this;
}

Vector Vector::operator+(const Vector &rhs) const
{
    assert(rhs.size() == taille);
    auto u = Vector(taille);
    for (size_t i = 0; i < taille; i++) {
        u[i] = rhs[i] + (*this)[i];
    }
    return u;
}

Vector Vector::operator+(value v) const
{
    auto u = Vector(taille);
    for (size_t i = 0; i < taille; i++) {
        u[i] = (*this)[i] + v;
    }
    return u;
}

value Vector::operator*(const Vector &rhs) const
{
    assert(rhs.size() == taille);
    value n = 0;
    for (size_t i = 0; i < taille; i++) {
        n += rhs[i] * (*this)[i];
    }
    return n;
}

Vector Vector::operator*(value v) const
{
    auto u = Vector(taille);
    for (size_t i = 0; i < taille; i++) {
        u[i] = (*this)[i] * v;
    }
    return u;
}

value Vector::operator[](size_t index) const
{
    assert(taille > index);
    return coord[index];
}

value &Vector::operator[](size_t index)
{
    assert(taille > index);
    return coord[index];
}

std::ostream& operator<<(std::ostream &os, const Vector &rhs)
{
    os << "{";
    
    for (size_t i = 0; i < rhs.size(); i++)
    {
        os << rhs[i] << (i < rhs.size() - 1 ? "," : "");
    }
    os << "}";
    return os;
}

Vector operator*(const value& s, const Vector& v) {
    auto u = Vector(v.size());
    for (size_t i = 0; i < v.size(); i++) {
        u[i] = v[i] * s;
    }
    return u;
}

Vector operator+(const value& s, const Vector& v) {
    auto u = Vector(v.size());
    for (size_t i = 0; i < v.size(); i++) {
        u[i] = v[i] + s;
    }
    return u;
}
