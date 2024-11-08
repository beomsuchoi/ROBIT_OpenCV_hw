#ifndef WATERMARK_BACKGROUND_HPP
#define WATERMARK_BACKGROUND_HPP

#include <opencv2/opencv.hpp>
#include <string>

class WatermarkBackground {
public:
    WatermarkBackground(const std::string &watermark_path, const std::string &background_path);

    // 이미지 처리 함수
    void process();
    
    // 처리된 이미지들을 화면에 표시
    void displayImages();

private:
    cv::Mat watermark_image;    // 워터마크 이미지
    cv::Mat background_image;   // 배경 이미지
    cv::Mat result_image;       // 결과 이미지
    double alpha = 0.5;         // 투명도 (50%)
};

#endif // WATERMARK_BACKGROUND_HPP