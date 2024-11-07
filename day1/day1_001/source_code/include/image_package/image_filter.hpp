#ifndef IMAGE_FILTER_HPP
#define IMAGE_FILTER_HPP

#include <opencv2/opencv.hpp>
#include <string>

class ImageFilter {
public:
    ImageFilter(const std::string& image_path);
    void process();
    void displayImages();
    void saveImages(const std::string& original_path, const std::string& binary_path);

private:
    cv::Mat img;
    cv::Mat yellow_binary;
};

#endif // IMAGE_FILTER_HPP
