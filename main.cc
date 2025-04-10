#include <iostream>
#include "vec3.hh"
#include "pixel.hh"
#include "camera_window.hh"
#include "scene.hh"

int main(){
    int window_height = 400;
    int window_width = 800;
    vec3 window_pos{-4,2,-1};


    CameraWindow cam_window{window_height, window_width, window_pos};
    Scene scene;
    scene.addObject(new Disk(vec3(0,0,1), 5.0, vec3(0,0,-5), Color::BLUE));
    scene.addObject(new Disk(vec3(0,0,1), 1.0, vec3(-2,-2,-3), Color::RED));
    scene.addObject(new Disk(vec3(0,1,0), 100.0, vec3(0,-5,0), Color::GREY));


    cam_window.draw(scene);

    return 0;
}