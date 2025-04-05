#include "pixel.hh"

std::ostream& operator<<(std::ostream& os, const Pixel& pix) {
    os << pix.rgb_val[0] << "\t" << pix.rgb_val[1] << "\t" << pix.rgb_val[2];
    return os;
}