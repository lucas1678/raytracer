#include "pixel.hh"

std::ostream& operator<<(std::ostream& os, const Pixel& pix) {
    os << pix.rgb_val[0] << "\t" << pix.rgb_val[1] << "\t" << pix.rgb_val[2];
    return os;
}

Pixel operator*(const Pixel& pixel, float scalar) {
    //  actually, should not allow for negative scalars multiplying colors... FIX LATER!
    if(scalar*scalar > 1){
        std::cerr << "Multiplying a color by a scalar bigger than 1! Returning original color..." << std::endl;
        return pixel;
    }

    int red = (int) (pixel.rgb_val[0] * scalar);
    int green = (int) (pixel.rgb_val[1] * scalar);
    int blue = (int) (pixel.rgb_val[2] * scalar);

    return Pixel(red, green, blue);
}

Pixel operator*(float scalar, const Pixel& pixel) {
    return pixel*scalar;
}

Pixel Pixel::operator+(const Pixel& pixel) const {
    int red = std::min(255, rgb_val[0] + pixel.rgb_val[0]);
    int green = std::min(255, rgb_val[1] + pixel.rgb_val[1]);
    int blue = std::min(255, rgb_val[2] + pixel.rgb_val[2]);

    return Pixel(red, green, blue);
}

const Pixel Pixel::WHITE(255,255,255);
const Pixel Pixel::GREY(125,125,125);
const Pixel Pixel::RED(255,0,0);
const Pixel Pixel::BLUE(0,0,255);
const Pixel Pixel::BLACK(0,0,0);