#ifndef COLOR_H
#define COLOR_H

#include <string>
#include <tuple>
#include <iostream>

class Color {
private:
    int r, g, b, a;

public:
    Color(int r, int g, int b);
    Color(int r, int g, int b, int a);
    Color(const std::string& colorName);

    int getRed() const;
    int getGreen() const;
    int getBlue() const;
    int getAlpha() const;

    void setRed(int r);
    void setGreen(int g);
    void setBlue(int b);
    void setAlpha(int a);

    std::string toRGB() const;
    std::string toRGBA() const;
    std::string toHEX() const;

    std::tuple<int, int, int> getRGB() const;
    std::tuple<int, int, int, int> getRGBA() const;

    Color operator/(const Color& other) const;
    friend std::ostream& operator<<(std::ostream& os, const Color& color);
};

#endif