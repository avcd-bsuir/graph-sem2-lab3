#include "Vec3.hpp"

Vec3::Vec3(double x, double y, double z) : x(x), y(y), z(z) {
}

Vec3::~Vec3() {
}

double Vec3::magnitude() {
    return std::sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
}

Vec3 Vec3::normalized() {
    // Will crash if magnitude is 0
    return *this / this->magnitude();
}

/*
 * Comparing
 */

bool operator == (const Vec3 & first, const Vec3 & second) {
    return first.x == second.x && first.y == second.y && first.z == second.z;
}

/*
 * Adding
 */

Vec3 operator + (const Vec3 & first, const Vec3 & second) {
    return Vec3(first.x + second.x, first.y + second.y, first.z + second.z);
}

Vec3 operator += (Vec3 & first, const Vec3 & second) {
    first.x += second.x;
    first.y += second.y;
    first.z += second.z;
    return first;
}

/*
 * Subtracting
 */

Vec3 operator - (const Vec3 & first, const Vec3 & second) {
    return Vec3(first.x - second.x, first.y - second.y, first.z - second.z);
}

Vec3 operator -= (Vec3 & first, const Vec3 & second) {
    first.x -= second.x;
    first.y -= second.y;
    first.z -= second.z;
    return first;
}

/*
 * Multiplying
 */

Vec3 operator * (const Vec3 & first, const float second) {
    return Vec3(first.x * second, first.y * second, first.z * second);
}

Vec3 operator *= (Vec3 & first, const float second) {
    first.x *= second;
    first.y *= second;
    first.z *= second;
    return first;
}

Vec3 operator * (float second, const Vec3 & first) {
    return first * second;
}

/*
 * Dividing
 */

Vec3 operator / (const Vec3 & first, const float second) {
    return Vec3(first.x / second, first.y / second, first.z / second);
}

Vec3 operator /= (Vec3 & first, const float second) {
    first.x /= second;
    first.y /= second;
    first.z /= second;
    return first;
}

/*
 * Other
 */

double distance(Vec3 first, Vec3 second) {
    return std::sqrt(std::pow(first.x - second.x, 2) + std::pow(first.y - second.y, 2) + std::pow(first.z - second.z, 2));
}
