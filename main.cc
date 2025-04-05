#include <iostream>
#include "vec3.hh"
#include "pixel.hh"
#include "camera_window.hh"

int main(){
    int window_height = 400;
    int window_width = 800;
    vec3 window_pos{1,1,1};
    CameraWindow cam_window{window_height, window_width, window_pos};
    std::vector<Pixel> pixel_list;

    for(int i=0; i<window_height; i++){
        for(int j=0; j<window_width; j++){
            int red{(int) (255 * ((float)i/window_height))};
            int green{(int) (255 * ((float)j/window_width))};
            int blue{0};

            pixel_list.push_back(Pixel(red,green,blue));
        }
    }

    cam_window.draw(pixel_list);

    return 0;
}