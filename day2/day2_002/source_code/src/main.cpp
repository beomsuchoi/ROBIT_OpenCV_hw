#include "image_labeling/image_label.hpp"

int main() {
    std::string image_path = "/home/choibeomsu/Documents/KakaoTalk Downloads/colorball.png";
    std::string original_save_path = "/home/choibeomsu/Documents/KakaoTalk Downloads/original_colorball.png";
    std::string processed_save_path = "/home/choibeomsu/Documents/KakaoTalk Downloads/processed_colorball.png";

    ImageLabel imageLabel(image_path);
    imageLabel.process();
    imageLabel.displayImages();

    return 0;
}