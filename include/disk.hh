#ifndef Disk_HH
#define Disk_HH

#include "object.hh"

//  For now, Disks will only be drawn in the XY Disk!
//  For now, all Disks will be squares!
class Disk : public Object {
private:
    vec3 m_Normal;   // can be used to define rotation!
    float m_Radius;
public:
    Disk(vec3 normal, float radius, vec3 position, Color color)
        : m_Normal{normal}, m_Radius{radius}, Object(position, color) {}

    Disk(vec3 normal, float radius) : Object(), m_Normal{normal}, m_Radius{radius} {}

    ~Disk() {};

    bool hasCollisionWith(const Ray& ray) const override;
};

#endif