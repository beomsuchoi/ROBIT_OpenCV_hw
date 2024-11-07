#include <opencv2/opencv.hpp>
#include "robot_arm_control/robot_arm.hpp"

int main() {
    cv::Mat image;
    RobotArm robot_arm(150, 100); // 첫 번째 팔 길이 150, 두 번째 팔 길이 100

    char key;
    while (true) {
        robot_arm.draw(image);     // 로봇 팔 그리기
        cv::imshow("2DOF Robot Arm", image);

        key = cv::waitKey(30);
        if (key == 'd') {
            robot_arm.rotate(0.05); // 오른쪽으로 회전
        } else if (key == 'a') {
            robot_arm.rotate(-0.05); // 왼쪽으로 회전
        }
    }
    return 0;
}
