#ifndef CAMERA_WINDOW_HH
#define CAMERA_WINDOW_HH

#include <vector>
#include "pixel.hh"
#include "vec3.hh"

//  might want to rename this to "screen" or "camera window"
class CameraWindow {
private:
    int m_Window_height;
    int m_Window_width;
    vec3 m_Window_pos;  // defines the TOP_LEFT corner of the window plane!
public:
    CameraWindow(int window_height, int window_width, vec3 window_pos)
        : m_Window_height{window_height}, m_Window_width{window_width}, m_Window_pos{window_pos} {}
    CameraWindow(int window_height, int window_width) : CameraWindow(window_height, window_width, vec3(0,0,0)) {}
    CameraWindow() : CameraWindow{900, 1600, vec3(0,0,0)} {};
    ~CameraWindow() {};

    int getWindowLength() const {return m_Window_height;}
    int getWindowWidth() const {return m_Window_width;}

    void setWindowLength(int window_height) {m_Window_height = window_height;}
    void setWindowWidth(int window_width) {m_Window_width = window_width;}
    //  Sets dimensions of window (height, width)
    void setWindowDimensions(int window_height, int window_width) {m_Window_height = window_height; m_Window_width = window_width;}

    //  Shoots ray from origin through screen, seeing what hits, generating corresponding pixels and creating an image
    //  (remember that .ppm image draws from screen going left to right, top to bottom!)
    void draw() const;
    //  Draws an image from a given list of pixels
    void draw(std::vector<Pixel> pixel_list) const;

};

#endif