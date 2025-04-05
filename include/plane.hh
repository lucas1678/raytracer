#ifndef PLANE_HH
#define PLANE_HH

#include "vec3.hh"

class Plane {
private:
    vec3 m_Position;
    float m_Height;
    float m_Width;
public:
    Plane(float height, float width, vec3 position) : m_Height{height}, m_Width{width}, m_Position{position} {}
    //Plane(vec3 position) : Plane(1, 1, position) {}
    //Plane() : Plane(1, 1, vec3(0,0,0)) {};
    ~Plane() {};
};

#endif