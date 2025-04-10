#include "disk.hh"

bool Disk::hasCollisionWith(const Ray& ray, float &t_hit) const {
    t_hit = ray.getPlaneCollisionParameter(m_Normal, m_Position);
    //std::cout << t << std::endl;
    if(t_hit <= 0) return false;

    vec3 ray_position_on_plane = ray*t_hit;

    //std::cout << "Checking if ray: " << ray << "collides with plane normal: " << m_Normal << "with center: " << m_Position << std::endl;
    //std::cout << "Ray position on plane is: " << ray_position_on_plane << std::endl;
    //std::cout << "Ray distance from disk center is: " << ray_position_on_plane.distanceFrom(m_Position) << std::endl;

    if(ray_position_on_plane.distanceFrom(m_Position) > m_Radius) return false;
    else return true;
}

bool Disk::hasCollisionWith(const Ray& ray) const {
    float t;
    return hasCollisionWith(ray, t);
}

vec3 Disk::getNormalAt(const vec3& hitPoint) const {
    //  For a disk, normal is always the same! Also, this method should only be called after a collision with the disk has been
    //  confirmed. So no need to check that hitPoint is within surface of disk!
    return m_Normal;
}