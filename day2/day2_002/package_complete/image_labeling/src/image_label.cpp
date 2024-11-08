#include "image_labeling/image_label.hpp"

ImageLabel::ImageLabel(const std::string &image_path) {
    original_image = cv::imread(image_path);
}

void ImageLabel::process() {
    cv::cvtColor(original_image, hsv_image, cv::COLOR_BGR2HSV);
    cv::Mat red_mask, green_mask, blue_mask;
    
    // HSV 색상 범위로 마스크 생성
    cv::inRange(hsv_image, cv::Scalar(0, 100, 100), cv::Scalar(10, 255, 255), red_mask);
    cv::inRange(hsv_image, cv::Scalar(35, 100, 100), cv::Scalar(85, 255, 255), green_mask);
    cv::inRange(hsv_image, cv::Scalar(90, 100, 100), cv::Scalar(130, 255, 255), blue_mask);
    
    // 커널 사이즈 7,7로 설정 (적당한 크기)
    cv::Mat kernel = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(7, 7));
    
    // Opening, Closing 연산
    cv::morphologyEx(red_mask, red_result, cv::MORPH_OPEN, kernel);
    cv::morphologyEx(red_result, red_result, cv::MORPH_CLOSE, kernel);
    cv::morphologyEx(green_mask, green_result, cv::MORPH_OPEN, kernel);
    cv::morphologyEx(green_result, green_result, cv::MORPH_CLOSE, kernel);
    cv::morphologyEx(blue_mask, blue_result, cv::MORPH_OPEN, kernel);
    cv::morphologyEx(blue_result, blue_result, cv::MORPH_CLOSE, kernel);
    
    // 레이블링 및 바운딩 박스를 그릴 결과 이미지 생성
    result_image = original_image.clone();
    cv::Mat labels, stats, centroids;
    
    // 빨간공 레이블링
    int num_labels = cv::connectedComponentsWithStats(red_result, labels, stats, centroids);
    for(int i = 1; i < num_labels; i++) {
        int x = stats.at<int>(i, cv::CC_STAT_LEFT);
        int y = stats.at<int>(i, cv::CC_STAT_TOP);
        int w = stats.at<int>(i, cv::CC_STAT_WIDTH);
        int h = stats.at<int>(i, cv::CC_STAT_HEIGHT);
            cv::rectangle(result_image, cv::Rect(x, y, w, h), cv::Scalar(0, 0, 255), 2);
            cv::putText(result_image, "Red", cv::Point(x, y-10),
                       cv::FONT_HERSHEY_SIMPLEX, 0.5, cv::Scalar(0, 0, 255), 2);
    }
    
    // 초록공 레이블링
    num_labels = cv::connectedComponentsWithStats(green_result, labels, stats, centroids);
    for(int i = 1; i < num_labels; i++) {
        int x = stats.at<int>(i, cv::CC_STAT_LEFT);
        int y = stats.at<int>(i, cv::CC_STAT_TOP);
        int w = stats.at<int>(i, cv::CC_STAT_WIDTH);
        int h = stats.at<int>(i, cv::CC_STAT_HEIGHT);
            cv::rectangle(result_image, cv::Rect(x, y, w, h), cv::Scalar(0, 255, 0), 2);
            cv::putText(result_image, "Green", cv::Point(x, y-10),
                       cv::FONT_HERSHEY_SIMPLEX, 0.5, cv::Scalar(0, 255, 0), 2);
    }
    
    // 파란공 레이블링
    num_labels = cv::connectedComponentsWithStats(blue_result, labels, stats, centroids);
    for(int i = 1; i < num_labels; i++) {
        int x = stats.at<int>(i, cv::CC_STAT_LEFT);
        int y = stats.at<int>(i, cv::CC_STAT_TOP);
        int w = stats.at<int>(i, cv::CC_STAT_WIDTH);
        int h = stats.at<int>(i, cv::CC_STAT_HEIGHT);        
            cv::rectangle(result_image, cv::Rect(x, y, w, h), cv::Scalar(255, 0, 0), 2);
            cv::putText(result_image, "Blue", cv::Point(x, y-10),
                       cv::FONT_HERSHEY_SIMPLEX, 0.5, cv::Scalar(255, 0, 0), 2);
    }
}

void ImageLabel::displayImages() {
    cv::imshow("Original", original_image);
    cv::imshow("Red Ball Detection", red_result);
    cv::imshow("Green Ball Detection", green_result);
    cv::imshow("Blue Ball Detection", blue_result);
    cv::imshow("Detected Objects", result_image);
    
    cv::waitKey(0);
    cv::destroyAllWindows();
}