#ifndef PIXEL_HH
#define PIXEL_HH

#include <iostream>

class Pixel {
private:
    int rgb_val[3];
public:
    Pixel() : rgb_val{0,0,0} {}
    Pixel(int red, int green, int blue) : rgb_val{red, green, blue} {
        for(const int color : rgb_val){
            if(color < 0 || color > 255) {std::cout << "Pixel RGB value(s) below 0 or above 255! Careful" << std::endl;}
        }
    }
    ~Pixel() {}

    friend std::ostream& operator<<(std::ostream& os, const Pixel& pix);
};

#endif