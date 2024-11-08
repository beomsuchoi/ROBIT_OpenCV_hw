#ifndef Open_Close_HPP
#define Open_Close_HPP

#include <opencv2/opencv.hpp>
#include <string>

class OpenClose {
public:
    OpenClose(const std::string& image_path);
    void process();
    void process_mine();
    void displayImages();

private:
    cv::Mat original_image;
    cv::Mat hsv_image;
    cv::Mat red_result;
    cv::Mat green_result;
    cv::Mat blue_result;

    cv::Mat red_mine;
    cv::Mat green_mine;
    cv::Mat blue_mine;
};

#endif // Open_Close_HPP