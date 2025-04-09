#include "disk.hh"

bool Disk::hasCollisionWith(const Ray& ray) const {
    float t = ray.getPlaneCollisionParameter(m_Normal, m_Position);
    //std::cout << t << std::endl;
    if(t <= 0) return false;

    vec3 ray_position_on_plane = ray*t;

    //std::cout << "Checking if ray: " << ray << "collides with plane normal: " << m_Normal << "with center: " << m_Position << std::endl;
    //std::cout << "Ray position on plane is: " << ray_position_on_plane << std::endl;
    //std::cout << "Ray distance from disk center is: " << ray_position_on_plane.distanceFrom(m_Position) << std::endl;

    if(ray_position_on_plane.distanceFrom(m_Position) > m_Radius) return false;
    else return true;
}