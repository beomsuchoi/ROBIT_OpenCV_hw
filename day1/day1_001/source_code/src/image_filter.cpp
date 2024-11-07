#include "image_package/image_filter.hpp"
#include <iostream>

ImageFilter::ImageFilter(const std::string& image_path) {
    // 이미지 불러오기
    img = cv::imread(image_path, cv::IMREAD_COLOR);
    if (img.empty()) {
        std::cerr << "이미지를 불러올 수 없습니다! 경로를 확인하세요: " << image_path << std::endl;
    }
}

void ImageFilter::process() {
    if (img.empty()) return;

    // HSV 색상 공간으로 변환
    cv::Mat hsv_image;
    cv::cvtColor(img, hsv_image, cv::COLOR_BGR2HSV);

    // 노란색 범위 설정 (노란색의 일반적인 HSV 범위)
    cv::Scalar lower_yellow(20, 180, 100), upper_yellow(30, 255, 255);

    // 노란색 마스크 생성
    cv::inRange(hsv_image, lower_yellow, upper_yellow, yellow_binary);

    // 가우시안 블러 적용
    cv::GaussianBlur(yellow_binary, yellow_binary, cv::Size(5, 5), 0);
}

void ImageFilter::displayImages() {
    if (img.empty()) return;

    // 원본 이미지와 노란색 이진화 이미지 출력
    cv::imshow("Original Image", img);
    cv::imshow("Yellow Binary Image with Gaussian Blur", yellow_binary);
    cv::waitKey(0); // 키 입력을 받을 때까지 대기
}

void ImageFilter::saveImages(const std::string& original_path, const std::string& binary_path) {
    if (img.empty()) return;

    // 이미지 저장
    cv::imwrite(original_path, img);
    cv::imwrite(binary_path + "_yellow_blurred.png", yellow_binary);
}
