#include "color.h"
#include <map>
#include <algorithm>
#include <cctype>
#include <sstream>
#include <iomanip>

static std::string toLower(const std::string& str) {
    std::string res = str;
    std::transform(res.begin(), res.end(), res.begin(),
        [](unsigned char c) { return std::tolower(c); });
    return res;
}

static std::string toHex(int value) {
    std::stringstream ss;
    ss << std::hex << std::setw(2) << std::setfill('0') << value;
    return ss.str();
}

static const std::map<std::string, std::tuple<int, int, int>> colorMap = {
    {"black",   {0,   0,   0}},
    {"silver",  {192, 192, 192}},
    {"gray",    {128, 128, 128}},
    {"white",   {255, 255, 255}},
    {"maroon",  {128, 0,   0}},
    {"red",     {255, 0,   0}},
    {"purple",  {128, 0,   128}},
    {"fuchsia", {255, 0,   255}},
    {"green",   {0,   128, 0}},
    {"lime",    {0,   255, 0}},
    {"olive",   {128, 128, 0}},
    {"yellow",  {255, 255, 0}},
    {"navy",    {0,   0,   128}},
    {"blue",    {0,   0,   255}},
    {"teal",    {0,   128, 128}},
    {"aqua",    {0,   255, 255}}
};

Color::Color(int r, int g, int b) : r(0), g(0), b(0), a(255) {
    setRed(r);
    setGreen(g);
    setBlue(b);
}

Color::Color(int r, int g, int b, int a) : r(0), g(0), b(0), a(255) {
    setRed(r);
    setGreen(g);
    setBlue(b);
    setAlpha(a);
}

Color::Color(const std::string& colorName) : r(0), g(0), b(0), a(255) {
    std::string lowerName = toLower(colorName);
    auto it = colorMap.find(lowerName);
    if (it != colorMap.end()) {
        auto [rr, gg, bb] = it->second;
        setRed(rr);
        setGreen(gg);
        setBlue(bb);
    }
}

int Color::getRed() const { return r; }
int Color::getGreen() const { return g; }
int Color::getBlue() const { return b; }
int Color::getAlpha() const { return a; }

void Color::setRed(int r) { this->r = (r < 0) ? 0 : (r > 255) ? 255 : r; }
void Color::setGreen(int g) { this->g = (g < 0) ? 0 : (g > 255) ? 255 : g; }
void Color::setBlue(int b) { this->b = (b < 0) ? 0 : (b > 255) ? 255 : b; }
void Color::setAlpha(int a) { this->a = (a < 0) ? 0 : (a > 255) ? 255 : a; }

std::string Color::toRGB() const {
    return "rgb(" + std::to_string(r) + "," + std::to_string(g) + "," + std::to_string(b) + ")";
}

std::string Color::toRGBA() const {
    return "rgba(" + std::to_string(r) + "," + std::to_string(g) + "," + std::to_string(b) + "," + std::to_string(a) + ")";
}

std::string Color::toHEX() const {
    return "#" + toHex(r) + toHex(g) + toHex(b) + (a != 255 ? toHex(a) : "");
}

std::tuple<int, int, int> Color::getRGB() const {
    return {r, g, b};
}

std::tuple<int, int, int, int> Color::getRGBA() const {
    return {r, g, b, a};
}

Color Color::operator/(const Color& other) const {
    return Color(
        (r + other.r) / 2,
        (g + other.g) / 2,
        (b + other.b) / 2,
        (a + other.a) / 2
    );
}

std::ostream& operator<<(std::ostream& os, const Color& color) {
    os << color.toRGBA();
    return os;
}