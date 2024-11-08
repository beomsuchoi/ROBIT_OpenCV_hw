#include "open_close/open_close.hpp"

OpenClose::OpenClose(const std::string &image_path)
{
    original_image = cv::imread(image_path);
}

void OpenClose::process()
{
    cv::cvtColor(original_image, hsv_image, cv::COLOR_BGR2HSV);

    cv::Mat red_mask, green_mask, blue_mask;

    // 커널 사이즈 7,9 적당 39로 했을 때 픽셀 모양으로 깨짐
    cv::inRange(hsv_image, cv::Scalar(0, 100, 100), cv::Scalar(10, 255, 255), red_mask);
    cv::inRange(hsv_image, cv::Scalar(35, 100, 100), cv::Scalar(85, 255, 255), green_mask);
    cv::inRange(hsv_image, cv::Scalar(90, 100, 100), cv::Scalar(130, 255, 255), blue_mask);

    cv::Mat kernel = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(7, 7));

    cv::morphologyEx(red_mask, red_result, cv::MORPH_OPEN, kernel);
    cv::morphologyEx(red_result, red_result, cv::MORPH_CLOSE, kernel);

    cv::morphologyEx(green_mask, green_result, cv::MORPH_OPEN, kernel);
    cv::morphologyEx(green_result, green_result, cv::MORPH_CLOSE, kernel);

    cv::morphologyEx(blue_mask, blue_result, cv::MORPH_OPEN, kernel);
    cv::morphologyEx(blue_result, blue_result, cv::MORPH_CLOSE, kernel);
}

void OpenClose::process_mine()
{
    cv::cvtColor(original_image, hsv_image, cv::COLOR_BGR2HSV);

    cv::Mat red_my_mask, green_my_mask, blue_my_mask;

    // 커널 사이즈 7,9 적당 39로 했을 때 픽셀 모양으로 깨짐
    cv::inRange(hsv_image, cv::Scalar(0, 100, 100), cv::Scalar(10, 255, 255), red_my_mask);
    cv::inRange(hsv_image, cv::Scalar(35, 100, 100), cv::Scalar(85, 255, 255), green_my_mask);
    cv::inRange(hsv_image, cv::Scalar(90, 100, 100), cv::Scalar(130, 255, 255), blue_my_mask);

    cv::Mat kernel = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(7, 7));

    cv::erode(red_my_mask, red_mine, kernel);
    cv::dilate(red_mine, red_mine, kernel);
    cv::dilate(red_mine, red_mine, kernel);
    cv::erode(red_mine, red_mine, kernel);
    //결과값 소스값 위치만 바꾸는게 아니라 계속 적용되어야 한다.

    cv::erode(green_my_mask, green_mine, kernel);
    cv::dilate(green_mine, green_mine, kernel);
    cv::dilate(green_mine, green_mine, kernel);
    cv::erode(green_mine, green_mine, kernel);

    cv::erode(blue_my_mask, blue_mine, kernel);
    cv::dilate(blue_mine, blue_mine, kernel);
    cv::dilate(blue_mine, blue_mine, kernel);
    cv::erode(blue_mine, blue_mine, kernel);
}

void OpenClose::displayImages()
{
    cv::imshow("Original", original_image);

    cv::imshow("Red Ball Detection", red_result);
    cv::imshow("Green Ball Detection", green_result);
    cv::imshow("Blue Ball Detection", blue_result);

    cv::imshow("Red Ball My o_c", red_mine);
    cv::imshow("Green Ball My o_c", green_mine);
    cv::imshow("Blue Ball My o_c", blue_mine);

    cv::waitKey(0);
    cv::destroyAllWindows();
}