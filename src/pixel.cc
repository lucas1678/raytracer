#include "pixel.hh"

std::ostream& operator<<(std::ostream& os, const Pixel& pix) {
    os << pix.rgb_val[0] << "\t" << pix.rgb_val[1] << "\t" << pix.rgb_val[2];
    return os;
}

const Pixel Pixel::WHITE(255,255,255);
const Pixel Pixel::GREY(125,125,125);
const Pixel Pixel::RED(255,0,0);
const Pixel Pixel::BLUE(0,0,255);
const Pixel Pixel::BLACK(0,0,0);