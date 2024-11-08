#ifndef IMAGE_LABEL_HPP
#define IMAGE_LABEL_HPP

#include <opencv2/opencv.hpp>
#include <string>

class ImageLabel {
public:
    ImageLabel(const std::string &image_path);

    void process();
    
    // 처리된 이미지들을 화면에 표시
    void displayImages();

private:
    cv::Mat original_image;
    cv::Mat hsv_image;
    cv::Mat red_result;
    cv::Mat green_result;
    cv::Mat blue_result;
    cv::Mat result_image;
};

#endif // IMAGE_LABEL_HPP