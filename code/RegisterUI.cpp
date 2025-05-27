#include <string>
#include <fstream>
#include "RegisterUI.h"
#include "Register.h"

/*
    함수 이름 : RegisterUI::RegisterUI
    기능     : RegisterUI 객체를 생성하고, 멤버 변수들을 초기화함
    전달 인자 : ifstream& in_fp - 입력 파일 스트림 참조
               ofstream& out_fp - 출력 파일 스트림 참조
    반환값   : 없음 (생성자)
*/
RegisterUI::RegisterUI(ifstream& in_fp, ofstream& out_fp) : in_fp(in_fp), out_fp(out_fp) {
    control = nullptr;
    id = "";
    password = "";
    phoneNumber = "";
}

/*
    함수 이름 : RegisterUI::startInterface
    기능     : 컨트롤 객체를 연결하고 입력 스트림에서 회원 정보를 읽어옴
    전달 인자 : Register* control - 컨트롤 객체 포인터
    반환값   : 없음
*/
void RegisterUI::startInterface(Register* control) {
    this->control = control;
    in_fp >> id >> password >> phoneNumber;
}

/*
    함수 이름 : RegisterUI::createNewMember
    기능     : 회원가입 기능을 수행하고 결과를 출력 파일에 기록함
    전달 인자 : 없음
    반환값   : 없음
*/
void RegisterUI::createNewMember() {
    this->control->addNewMember(id, password, phoneNumber);
    out_fp << "1.1. 회원가입" << endl;
    out_fp << "> " << id << " " << password << " " << phoneNumber << endl;
}