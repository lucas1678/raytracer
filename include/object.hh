#ifndef OBJECT_HH
#define OBJECT_HH

#include "vec3.hh"
#include "pixel.hh"

using Color = Pixel; 
using Ray = vec3;

//  Later, objects should also have a rotation (matrix?) of sorts to define their orientation about some axis
class Object {
protected:
    Color m_Color;
    vec3 m_Position;
public:
    Object(const vec3& position, const Color& color) : m_Position{position}, m_Color{color} {}
    Object() : Object(vec3(0,0,0), Color::GREY) {}

    virtual ~Object() {};

    void setColor(const Color& color) {m_Color = color;}
    Color getColor() const {return m_Color;};

    void setPosition(const vec3& pos) {m_Position = pos;}  
    vec3 getPosition() const {return m_Position;}

    virtual bool hasCollisionWith(const Ray& ray) const = 0; //pure abstract method (each shape will have a diff way to check collision with a ray)
    virtual bool hasCollisionWith(const Ray& ray, float &t_hit) const = 0;

    virtual vec3 getNormalAt(const vec3& hitPoint) const = 0;
};

#endif