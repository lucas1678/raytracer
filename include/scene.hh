#ifndef SCENE_HH
#define SCENE_HH

#include "object.hh"
#include <vector>

class Scene {
private:
    std::vector<Object*> m_Objects;  // needs to store pointers to object, since Object itself is an abstract class! 
    Color m_DefaultColour;
public:
    Scene() : m_DefaultColour{Color::BLACK} {};
    ~Scene() {
        for(auto *object : m_Objects){  //  iterates through all these obj ptrs and frees the memory of each one!
            delete object;
        }
    };

    const Color& getBackgroundColour() const {return m_DefaultColour;}
    void setBackgroundColour(const Color& bckg_colour) {m_DefaultColour = bckg_colour;}

    void addObject(Object *object) {m_Objects.push_back(object);}
    const std::vector<Object*>& getObjectList() const {return m_Objects;}  // returns a const reference to our vector to avoid copying

    size_t getNumberOfObjects() const {return size(m_Objects);}
};

#endif