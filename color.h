#ifndef COLOR_H
#define COLOR_H

#include "vec3.h"
#include <iostream>

void write_color(std::ostream &out, color pixel_color) {
    // Write translated [0, 255] value of each color
    const float max_color = 255.999;
    out << static_cast<int>(max_color * pixel_color.x()) << ' '
        << static_cast<int>(max_color * pixel_color.y()) << ' '
        << static_cast<int>(max_color * pixel_color.z()) << '\n';
}

#endif
