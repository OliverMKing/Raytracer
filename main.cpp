#include <iostream>
#include <fstream>
#include <string>

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
        for (int x = 0; x < image_width; ++x) {
            auto red = double(x) / (image_width - 1);
            auto green = double(y) / (image_height - 1);
            auto blue = 0.25;

            // Max color that can be in a space is 255. This will be rounded down on conversion to int
            const float max_color = 255.999;

            int ir = static_cast<int>(max_color * red);
            int ig = static_cast<int>(max_color * green);
            int ib = static_cast<int>(max_color * blue);

            outputStream << ir << ' ' << ig << ' ' << ib << '\n';
        }
    }

    outputStream.close();

    return 0;
}