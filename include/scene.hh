#ifndef SCENE_HH
#define SCENE_HH

#include "plane.hh"
#include <vector>

//  right now, this only works with a plane!! Def modify later so we can get any shape (sphere, plane, cube, triangle/pyramid etc.)

class Scene {
private:
    std::vector<Plane> m_Planes;
public:
    Scene() {};
    ~Scene() {};

    void addPlane(Plane plane) const;
};

#endif