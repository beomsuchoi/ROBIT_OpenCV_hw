#ifndef ROBOT_ARM_CONTROL_ROBOT_ARM_HPP
#define ROBOT_ARM_CONTROL_ROBOT_ARM_HPP

#include <opencv2/opencv.hpp>
#include <cmath>

class RobotArm {
public:
    RobotArm(int joint_length1, int joint_length2);
    void rotate(double angle_increment);          // 각도를 조정하여 회전 방향 제어
    void draw(cv::Mat &image);                    // 이미지를 그리고 출력

private:
    int joint_length1, joint_length2;           // 각 팔의 길이
    int base_x, base_y;                         // 팔의 시작 좌표
    double angle1, angle2;                      // 두 관절의 현재 각도 (2DOF)
    cv::Point joint1, joint2;                   // 두 관절 위치

    void updateJointPositions();                  // 각도에 따른 관절 위치 업데이트
};

#endif // ROBOT_ARM_CONTROL_ROBOT_ARM_HPP
