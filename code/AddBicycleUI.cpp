#include "AddBicycleUI.h"
#include "AddBicycle.h"
#include <fstream>

/*
    함수 이름 : AddBicycleUI::AddBicycleUI
    기능     : AddBicycleUI 객체를 생성하고, 멤버 변수들을 초기화함
    전달 인자 : ifstream& in_fp - 입력 파일 스트림 참조
               ofstream& out_fp - 출력 파일 스트림 참조
    반환값   : 없음 (생성자)
*/
AddBicycleUI::AddBicycleUI(ifstream& in_fp, ofstream& out_fp) : in_fp(in_fp), out_fp(out_fp) {
    control = nullptr;
    id = "";
    name = "";
}

/*
    함수 이름 : AddBicycleUI::startInterface
    기능     : 컨트롤 객체를 연결하고 입력 스트림에서 자전거 정보를 읽어옴
    전달 인자 : AddBicycle* control - 컨트롤 객체 포인터
    반환값   : 없음
*/
void AddBicycleUI::startInterface(AddBicycle* control) {
    this->control = control;
    in_fp >> id >> name;
}

/*
    함수 이름 : AddBicycleUI::createBicycle
    기능     : 자전거 등록 기능을 수행하고 결과를 출력 파일에 기록함
    전달 인자 : 없음
    반환값   : 없음
*/
void AddBicycleUI::createBicycle() {
    this->control->addBicycle(id, name);
    out_fp << "3.1. 자전거 등록" << endl;
    out_fp << "> " << id << " " << name << endl;
}