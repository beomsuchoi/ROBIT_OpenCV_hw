#include "robot_arm_control/robot_arm.hpp"

RobotArm::RobotArm(int joint_length1, int joint_length2) 
    : joint_length1(joint_length1), joint_length2(joint_length2),
      base_x(400), base_y(300), angle1(0.0), angle2(45.0) {
    updateJointPositions();
}

void RobotArm::rotate(double angle_increment) {
    // 어깨와 팔꿈치의 각도를 angle_increment만큼 회전
    angle1 += angle_increment;
    angle2 += angle_increment / 2.0;  // 팔꿈치가 어깨의 절반 속도로 움직임
    updateJointPositions();
}

void RobotArm::updateJointPositions() {
    // 첫 번째 관절 위치 계산 (어깨 기준)
    joint1 = cv::Point(base_x + joint_length1 * cos(angle1),
                        base_y + joint_length1 * sin(angle1));
    
    // 두 번째 관절 위치 계산 (팔꿈치 기준)
    joint2= cv::Point(joint1.x + joint_length2* cos(angle1+ angle2),
                        joint1.y + joint_length2 * sin(angle1 + angle2));
}

void RobotArm::draw(cv::Mat &image) {
    // 이미지 초기화
    image = cv::Mat::zeros(600, 800, CV_8UC3);
    
    // 로봇 팔 그리기
    cv::line(image, cv::Point(base_x, base_y), joint1, cv::Scalar(0, 255, 0), 3); // 첫 번째 팔
    cv::line(image, joint1, joint2, cv::Scalar(0, 255, 0), 3);                     // 두 번째 팔
    cv::circle(image, cv::Point(base_x, base_y), 5, cv::Scalar(255, 0, 0), -1);     // 어깨 원
    cv::circle(image, joint1, 5, cv::Scalar(255, 0, 0), -1);                         // 팔꿈치 원
    cv::circle(image, joint2, 5, cv::Scalar(255, 0, 0), -1);                         // 팔 끝 원
}
