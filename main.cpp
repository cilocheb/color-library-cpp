#include "color.h"
#include <iostream>
#include <tuple>

int main() {
    Color red("red");
    Color blue(0, 0, 255);
    Color transparentGreen(0, 255, 0, 128);
    Color unknown("unknown");

    std::cout << "Red channel: " << red.getRed() << std::endl;
    std::cout << "Green alpha: " << transparentGreen.getAlpha() << std::endl;

    blue.setGreen(150);
    std::cout << "Modified blue: " << blue.toRGB() << std::endl;

    std::cout << "Red (RGB): " << red.toRGB() << std::endl;
    std::cout << "Blue (RGBA): " << blue.toRGBA() << std::endl;
    std::cout << "Green (HEX): " << transparentGreen.toHEX() << std::endl;

    Color purple = red / blue;
    std::cout << "Purple (red/blue): " << purple.toRGB() << std::endl;

    auto [r, g, b] = purple.getRGB();
    std::cout << "Purple RGB: " << r << " " << g << " " << b << std::endl;

    auto [rr, gg, bb, aa] = transparentGreen.getRGBA();
    std::cout << "Green RGBA: " << rr << " " << gg << " " << bb << " " << aa << std::endl;

    std::cout << "Unknown color: " << unknown << std::endl;

    return 0;
}