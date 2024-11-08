#include "watermark_background/watermark_background.hpp"
#include <iostream>

WatermarkBackground::WatermarkBackground(const std::string &watermark_path, const std::string &background_path) {
    watermark_image = cv::imread(watermark_path);
    background_image = cv::imread(background_path);
}

void WatermarkBackground::process() {
    // 결과 이미지를 배경 이미지로 초기화
    result_image = background_image.clone();
    
    // 워터마크를 삽입할 ROI 정의
    cv::Mat roi = result_image(cv::Rect(0, 0, watermark_image.cols, watermark_image.rows));
    
    // OpenCV 로고의 RGB 색상 마스크 생성
    cv::Mat mask = cv::Mat::zeros(watermark_image.size(), CV_8UC1);
    
    // RGB 채널 분리
    std::vector<cv::Mat> channels;
    cv::split(watermark_image, channels);
    
    // 빨간색 마스크
    cv::Mat red_mask;
    cv::inRange(watermark_image, cv::Scalar(0, 0, 200), cv::Scalar(80, 80, 255), red_mask);
    
    // 초록색 마스크
    cv::Mat green_mask;
    cv::inRange(watermark_image, cv::Scalar(0, 200, 0), cv::Scalar(80, 255, 80), green_mask);
    
    // 파란색 마스크
    cv::Mat blue_mask;
    cv::inRange(watermark_image, cv::Scalar(200, 0, 0), cv::Scalar(255, 80, 80), blue_mask);
    // 검정색 마스크
    cv::Mat black_mask;
    cv::inRange(watermark_image, cv::Scalar(0, 0, 0), cv::Scalar(10,10,10), black_mask);
    // 마스크 합치기
    mask = red_mask | green_mask | blue_mask | black_mask;
    
    for(int i = 0; i < watermark_image.rows; i++) {
        for(int j = 0; j < watermark_image.cols; j++) {
            if(mask.at<uchar>(i,j) > 0) {
                roi.at<cv::Vec3b>(i,j) = 0.5 * watermark_image.at<cv::Vec3b>(i,j) + 
                                        0.5 * roi.at<cv::Vec3b>(i,j);
            }
        }
    }
}

void WatermarkBackground::displayImages() {
    //결과 이미지 표시
    cv::imshow("Watermark Image", watermark_image);
    cv::imshow("Background Image", background_image);
    cv::imshow("Result Image", result_image);
    
    cv::waitKey(0);
    cv::destroyAllWindows();
}