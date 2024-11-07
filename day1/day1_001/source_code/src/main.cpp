#include "image_package/image_filter.hpp"

int main() {
    // 이미지 경로 설정
    std::string image_path = "/home/choibeomsu/Documents/KakaoTalk Downloads/image.png";
    std::string original_save_path = "/home/choibeomsu/Documents/KakaoTalk Downloads/image.png";
    std::string binary_save_path = "/home/choibeomsu/Documents/KakaoTalk Downloads/image.png";

    // ImageFilter 객체 생성 및 처리
    ImageFilter filter(image_path);
    filter.process();
    filter.displayImages();
    filter.saveImages(original_save_path, binary_save_path);

    return 0;
}
