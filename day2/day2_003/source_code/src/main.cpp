#include "watermark_background/watermark_background.hpp"

int main()
{
    // 이미지 경로 설정
    std::string watermark_path = "/home/choibeomsu/Documents/KakaoTalk Downloads/watermark.png";
    std::string background_path = "/home/choibeomsu/Documents/KakaoTalk Downloads/background.png";
    
    // 저장할 경로 설정
    std::string original_watermark_save_path = "/home/choibeomsu/Documents/KakaoTalk Downloads/original_watermark.png";
    std::string original_background_save_path = "/home/choibeomsu/Documents/KakaoTalk Downloads/original_background.png";
    std::string processed_save_path = "/home/choibeomsu/Documents/KakaoTalk Downloads/processed_result.png";

    // 워터마크 객체 생성
    WatermarkBackground watermarker(watermark_path, background_path);
    
    // 이미지 처리
    watermarker.process();
    
    // 결과 표시
    watermarker.displayImages();

    return 0;
}