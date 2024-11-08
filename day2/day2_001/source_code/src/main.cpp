#include "open_close/open_close.hpp"

int main() {
    std::string image_path = "/home/choibeomsu/Documents/KakaoTalk Downloads/colorball.png";
    std::string original_save_path = "/home/choibeomsu/Documents/KakaoTalk Downloads/original_colorball.png";
    std::string processed_save_path = "/home/choibeomsu/Documents/KakaoTalk Downloads/processed_colorball.png";

    OpenClose filter(image_path);
    filter.process();
    filter.process_mine();
    filter.displayImages();

    return 0;
}