#pragma once

#include "RentalBicycle.h"
#include <string>
#include <fstream>
using namespace std;

/*
    클래스 이름 : RentalBicycleUI
    기능       : 자전거 대여 UI를 담당하는 클래스
    멤버 변수  : ifstream& in_fp        - 입력 파일 스트림 참조
                ofstream& out_fp       - 출력 파일 스트림 참조
                RentalBicycle* control - 대여 자전거 컨트롤 객체 포인터
                string id              - 자전거 ID
*/
class RentalBicycleUI {
private:
    ifstream& in_fp;  // 입력 파일 스트림
    ofstream& out_fp; // 출력 파일 스트림
    RentalBicycle* control; // 대여 자전거 컨트롤 객체
    string id;        // 자전거 ID
public:
    /*
        함수 이름 : RentalBicycleUI::RentalBicycleUI
        기능     : RentalBicycleUI 객체를 생성하고, 멤버 변수들을 초기화함
        전달 인자 : ifstream& in_fp - 입력 파일 스트림 참조
                   ofstream& out_fp - 출력 파일 스트림 참조
        반환값   : 없음 (생성자)
    */
    RentalBicycleUI(ifstream& in_fp, ofstream& out_fp);

    /*
        함수 이름 : RentalBicycleUI::startInterface
        기능     : 컨트롤 객체를 연결하고 입력 스트림에서 자전거 ID를 읽어옴
        전달 인자 : RentalBicycle* control - 컨트롤 객체 포인터
        반환값   : 없음
    */
    void startInterface(RentalBicycle* control); // 인터페이스 시작 메소드

    /*
        함수 이름 : RentalBicycleUI::rentBicycle
        기능     : 자전거 대여 기능을 수행하고 결과를 출력 파일에 기록함
        전달 인자 : 없음
        반환값   : 없음
    */
    void rentBicycle(); // 자전거 대여 메소드
};