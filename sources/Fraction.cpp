#include "Fraction.hpp"

Fraction::Fraction(int numerator, int denominator) : numerator(numerator), denominator(denominator) {}

std::ostream &operator<<(std::ostream &out, const Fraction &c) {
    return out;
}

std::istream &operator>>(std::istream &in, Fraction &fraction) {
    return in;
}

Fraction Fraction::operator+(const Fraction &other) const {
    return other;
}

Fraction &Fraction::operator-(Fraction &other) const {
    return other;
}

Fraction &Fraction::operator/(Fraction &other) const {
    return other;
}

Fraction &Fraction::operator*(Fraction &other) const {
    return other;
}

int Fraction::getNumerator() const {
    return numerator;
}

int Fraction::getDenominator() const {
    return denominator;
}

bool Fraction::operator==(const Fraction &other) const {
    return false;
}

Fraction Fraction::operator++() {
    ++numerator;
    ++denominator;
    return *this;
}

Fraction Fraction::operator--() {
    --numerator;
    --denominator;
    return *this;
}

bool Fraction::operator>(const Fraction &other) const {
    return false;
}

bool Fraction::operator<(const Fraction &other) const {
    return false;
}

bool Fraction::operator>=(const Fraction &other) const {
    return false;
}

bool Fraction::operator<=(const Fraction &other) const {
    return false;
}

bool Fraction::operator>(const float other) const {
    return false;
}

bool Fraction::operator<(const float other) const {
    return false;
}

bool Fraction::operator>=(const float other) const {
    return false;
}

bool Fraction::operator<=(const float other) const {
    return false;
}

Fraction Fraction::operator+(float other) const {
    Fraction temp(*this);
    return temp;
}

Fraction Fraction::operator-(float other) const {
    return {0, 0};
}

Fraction Fraction::operator/(float other) const {
    return {0, 0};
}

bool Fraction::operator==(float other) const {
    return false;
}

Fraction Fraction::operator*(float other) const {
    return {0, 0};
}

Fraction operator*(float value, const Fraction &f) {
    return {0, 0};
}

Fraction Fraction::operator++(int) {
    return {0, 0};
}

Fraction Fraction::operator--(int) {
    return {0, 0};
}

Fraction operator/(float value, const Fraction &f) {
    return {0, 0};
}

bool operator==(float value, const Fraction &f) {
    return false;
}

bool Fraction::operator!=(const Fraction &other) const {
    return false;
}

bool Fraction::operator!=(float other) const {
    return false;
}

bool operator!=(float value, const Fraction &f) {
    return false;
}

bool operator>(float value, const Fraction &f) {
    return false;
}

Fraction operator+(float value, const Fraction &f) {
    return {0, 0};
}

Fraction operator-(float value, const Fraction &f) {
    return {0, 0};
}

bool operator<(float value, const Fraction &f) {
    return false;
}

bool operator>=(float value, const Fraction &f) {
    return false;
}

bool operator<=(float value, const Fraction &f) {
    return false;
}