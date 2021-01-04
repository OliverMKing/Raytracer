#include <iostream>
#include <fstream>
#include <string>
#include "color.h"

int main() {

    // Image params
    const unsigned image_width = 256;
    const unsigned image_height = 256;

    // Render in PPM P3 format
    const std::string filename = "output.ppm";
    std::ofstream outputStream;

    outputStream.open(filename);

    outputStream << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for (int y = image_height - 1; y >= 0; --y) {
        // Progress bar
        std::cout << "\rScanlines remaining: " << y << ' ' << std::flush;


        for (int x = 0; x < image_width; ++x) {
            auto red = double(x) / (image_width - 1);
            auto green = double(y) / (image_height - 1);
            auto blue = 0.25;

            // Write color to picture
            color pixel_color(red, green, blue);
            write_color(outputStream, pixel_color);
        }
    }

    outputStream.close();
    std::cout << "\nDone.\n";

    return 0;
}