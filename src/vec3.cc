#include "vec3.hh"

using Ray = vec3;

//  we want this class (vec3 AKA ray) to play nice with objects. As in, there should be runtime POLYMORPHISM
//  meaning a ray can call a method such as checkColision(object) and each object (sphere, plane etc.) will have the instructions
//  on how a ray can check colisions with said object!

void vec3::info() const {
    std::cout << *this << std::endl;
}

std::ostream& operator<<(std::ostream& os, const vec3& vector_to_print) {
    os << "(" << vector_to_print.m_Coords[0] << ", "
    << vector_to_print.m_Coords[1] << ", "
    << vector_to_print.m_Coords[2] << ")";

    return os;
}

vec3 vec3::operator+(const vec3& vector_to_add) const {
    return vec3{this->m_Coords[0] + vector_to_add.m_Coords[0],
                this->m_Coords[1] + vector_to_add.m_Coords[1],
                this->m_Coords[2] + vector_to_add.m_Coords[2],
    };
}

vec3 vec3::operator-() const {
    return vec3(-this->m_Coords[0], -this->m_Coords[1], -this->m_Coords[2]);
}

vec3 vec3::operator-(const vec3& vector_to_subtract) const {
    return -vector_to_subtract + *this;
}

vec3 vec3::operator*(const float scalar) const {
    return vec3(this->m_Coords[0]*scalar, this->m_Coords[1]*scalar, this->m_Coords[2]*scalar);
}

float vec3::dot(const vec3& vec) const {
    return this->m_Coords[0]*vec.m_Coords[0] +
           this->m_Coords[1]*vec.m_Coords[1] +
           this->m_Coords[2]*vec.m_Coords[2];
}

float vec3::magnitude() const {
    return std::sqrt(this->dot(*this));
}

void vec3::normalize(){
    *this = *this * (1/(this->magnitude()));
}

float vec3::getPlaneCollisionParameter(const vec3& normal, const vec3& point_on_plane) const {
    float numerator = point_on_plane.dot(normal);
    //std::cout << "Denominator is dot product between: " << *this << " and " << normal << std::endl;
    float denominator = this->dot(normal);
    //std::cout << denominator << std::endl;
    if (abs(denominator) < 0.00001) {return -1;}  // when ray and plane are parallel!

    float t = numerator / denominator;
    return t;
}

//  magnitude of the difference between this vector and the vector pointing to the point.
float vec3::distanceFrom(const vec3& point) const {
    return (*this  - point).magnitude();  
}
