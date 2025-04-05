#include "vec3.hh"

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