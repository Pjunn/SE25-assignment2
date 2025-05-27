#include "RentalBicycleUI.h"
#include "RentalBicycle.h"
#include "Bicycle.h"
#include <fstream>

/*
    함수 이름 : RentalBicycleUI::RentalBicycleUI
    기능     : RentalBicycleUI 객체를 생성하고, 멤버 변수들을 초기화함
    전달 인자 : ifstream& in_fp - 입력 파일 스트림 참조
               ofstream& out_fp - 출력 파일 스트림 참조
    반환값   : 없음 (생성자)
*/
RentalBicycleUI::RentalBicycleUI(ifstream& in_fp, ofstream& out_fp) 
    : in_fp(in_fp), out_fp(out_fp) {
    id = "";
}

/*
    함수 이름 : RentalBicycleUI::startInterface
    기능     : 컨트롤 객체를 연결하고 입력 스트림에서 자전거 ID를 읽어옴
    전달 인자 : RentalBicycle* control - 컨트롤 객체 포인터
    반환값   : 없음
*/
void RentalBicycleUI::startInterface(RentalBicycle* control) {
    this->control = control;
    in_fp >> id; // 자전거 ID 입력 받기
}

/*
    함수 이름 : RentalBicycleUI::rentBicycle
    기능     : 자전거 대여 기능을 수행하고 결과를 출력 파일에 기록함
    전달 인자 : 없음
    반환값   : 없음
*/
void RentalBicycleUI::rentBicycle() {
    Bicycle* bicycle = control->rent(id); // 자전거 대여 메소드 호출
    out_fp << "4.1. 자전거 대여" << endl;
    out_fp << "> " << bicycle->getId() << " " << bicycle->getName() << endl; // 대여한 자전거 ID 출력
}