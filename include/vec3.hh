#ifndef VEC3_HH
#define VEC3_HH

#include <iostream>
#include <cmath>

class vec3 {
private:
    float m_Coords[3];
public:
    vec3() : m_Coords{0,0,0} {};  // default ctor
    vec3(float x, float y, float z) : m_Coords{x,y,z} {};

    void setTo(float x, float y, float z) {m_Coords[0] = x; m_Coords[1] = y; m_Coords[2] = z;}
    void info() const;

    float x() const {return m_Coords[0];}
    float y() const {return m_Coords[1];}
    float z() const {return m_Coords[2];}

    friend std::ostream& operator<<(std::ostream& os, const vec3& vector_to_print);
    vec3 operator-() const;
    vec3 operator+(const vec3& vector_to_add) const;
    vec3 operator-(const vec3& vector_to_subtract) const;
    vec3 operator*(const float scalar) const;

    float dot(const vec3& vec) const;
    float magnitude() const;
    void normalize();
};

#endif