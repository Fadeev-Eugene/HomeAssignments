//Fadeev Eugene st128225@student.spbu.ru
//This programm contains code for the first laboratory work
//This code reads 24 bit per pixel bmp image and apply to it rotation and gaussian filter

#include <iostream>
#include <fstream>
#include <vector>
#include <string>


//Pixel realization
struct Pixel
{
    uint8_t blue;
    uint8_t green;
    uint8_t red;
};


//BMP image realization
struct BMPImage
{
    int width, height;
    std::vector<Pixel> pixels;

    BMPImage(int w, int h) : width(w), height(h), pixels(w * h) {}

    Pixel& getPixel(int x, int y)
    {
        return pixels[y * width + x];
    }


    const Pixel& getPixel(int x, int y) const
    {
        return pixels[y * width + x];
    }

    // Function for rotation 90 degries clockwise
    void rotate90Clockwise()
    {
        std::vector<Pixel> rotatedPixels(height * width);
        for (int y = 0; y < height; ++y)
        {
            for (int x = 0; x < width; ++x)
            {
                rotatedPixels[x * height + (height - y - 1)] = getPixel(x, y);
            }
        }
        pixels = std::move(rotatedPixels);
        std::swap(width, height);
    }

    // Function for rotation 90 degries counter clockwise
    void rotate90CounterClockwise()
    {
        std::vector<Pixel> rotatedPixels(height * width);
        for (int y = 0; y < height; ++y)
        {
            for (int x = 0; x < width; ++x)
            {
                rotatedPixels[(width - x - 1) * height + y] = getPixel(x, y);
            }
        }
        pixels = std::move(rotatedPixels);
        std::swap(width, height);
    }

    // Function for gaussian filter
    void applyGaussianFilter()
    {
        const double kernel[3][3] =
        {
            {1 / 16.0, 1 / 8.0, 1 / 16.0},
            {1 / 8.0,  1 / 4.0, 1 / 8.0},
            {1 / 16.0, 1 / 8.0, 1 / 16.0}
        };

        std::vector<Pixel> filteredPixels = pixels;
        for (int y = 1; y < height - 1; ++y)
        {
            for (int x = 1; x < width - 1; ++x)
            {
                double red = 0, green = 0, blue = 0;
                for (int ky = -1; ky <= 1; ++ky)
                {
                    for (int kx = -1; kx <= 1; ++kx)
                    {
                        Pixel& p = getPixel(x + kx, y + ky);
                        red += p.red * kernel[ky + 1][kx + 1];
                        green += p.green * kernel[ky + 1][kx + 1];
                        blue += p.blue * kernel[ky + 1][kx + 1];
                    }
                }
                Pixel& fp = filteredPixels[y * width + x];
                fp.red = static_cast<uint8_t>(std::min(std::max(int(red), 0), 255));
                fp.green = static_cast<uint8_t>(std::min(std::max(int(green), 0), 255));
                fp.blue = static_cast<uint8_t>(std::min(std::max(int(blue), 0), 255));
            }
        }
        pixels = std::move(filteredPixels);
    }
};


// Function for loading image
BMPImage loadBMP(const std::string& filename)
{
    std::ifstream file(filename, std::ios::binary);

    // Read BMP header
    file.seekg(14);
    int w;
    file.read(reinterpret_cast<char*>(&w), 4);

    file.seekg(18);
    int width, height;
    file.read(reinterpret_cast<char*>(&width), 4);
    file.read(reinterpret_cast<char*>(&height), 4);
    BMPImage image(width, height);

    // Skip header and read pixel data
    file.seekg(w+14);
    int padding = (4 - (width * 3) % 4) % 4;
    for (int y = height - 1; y >= 0; --y)
    {
        for (int x = 0; x < width; ++x)
        {
            Pixel& p = image.getPixel(x, y);
            file.read(reinterpret_cast<char*>(&p), 3);
        }
        file.ignore(padding);  // Пропустить padding байты
    }

    return image;
}


// Function or saving image
void saveBMP(const std::string& filename, const BMPImage& image)
{
    std::ofstream file(filename, std::ios::binary);

    const int padding = (4 - (image.width * 3) % 4) % 4;
    //std::cout<<padding<<std::endl;
    const int fileSize = 54 + (3 * image.width + padding) * image.height;

    // BMP Header
    file.put('B').put('M');                            // Signature
    file.write(reinterpret_cast<const char*>(&fileSize), 4); // File size
    file.put(0).put(0).put(0).put(0);                  // Reserved
    file.put(54).put(0).put(0).put(0);                 // Pixel data offset
    // DIB Header
    const int headerSize = 40;
    file.write(reinterpret_cast<const char*>(&headerSize), 4);       // DIB header size
    file.write(reinterpret_cast<const char*>(&image.width), 4);      // Image width
    file.write(reinterpret_cast<const char*>(&image.height), 4);     // Image height
    file.put(1).put(0);                                       // Planes
    file.put(24).put(0);                                      // Bits per pixel
    file.put(0).put(0).put(0).put(0);                         // Compression (none)
    const int dataSize = (3 * image.width + padding) * image.height;
    file.write(reinterpret_cast<const char*>(&dataSize), 4);         // Image data size
    const int ppm = 2835;                                    // Pixels per meter (72 DPI)
    file.write(reinterpret_cast<const char*>(&ppm), 4);      // Horizontal resolution
    file.write(reinterpret_cast<const char*>(&ppm), 4);      // Vertical resolution
    file.put(0).put(0).put(0).put(0);                        // Colors in color table
    file.put(0).put(0).put(0).put(0);                        // Important color count

    // Pixel data

    for (int y = image.height - 1; y >= 0; --y)
    {
        for (int x = 0; x < image.width; ++x)
        {
            const Pixel& p = image.getPixel(x, y);
            file.write(reinterpret_cast<const char*>(&p.blue), 1);
            file.write(reinterpret_cast<const char*>(&p.green), 1);
            file.write(reinterpret_cast<const char*>(&p.red), 1);
        }
        file.write("\0\0\0", padding); // Add padding bytes if needed
    }
}


int main()
{
    //input file name
    std::string name;
    std::cout<<"Type name of your file >> ";
    std::cin>>name;
    std::cout<<std::endl;

    {
        BMPImage image = loadBMP(name);
        image.rotate90Clockwise();
        saveBMP("rotated_clockwise.bmp", image);
        std::cout<<"rotated_clockwise.bmp is created"<<std::endl;
        image.applyGaussianFilter();
        saveBMP("gaussian_filtered_clockwise.bmp", image);
        std::cout<<"gaussian_filtered_clockwise.bmp is created"<<std::endl;
    }

    {
        BMPImage image2 = loadBMP(name);
        image2.rotate90CounterClockwise();
        saveBMP("rotated_counterclockwise.bmp", image2);
        std::cout<<"rotated_counterclockwise.bmp is created"<<std::endl;
        image2.applyGaussianFilter();
        saveBMP("gaussian_filtered_counterclockwise.bmp", image2);
        std::cout<<"gaussian_filtered_counterclockwise.bmp is created"<<std::endl;
    }

    return 0;
}
