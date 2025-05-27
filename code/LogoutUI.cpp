#include "LogoutUI.h"
#include "Logout.h"
#include <fstream>
#include <iostream>

/*
    함수 이름 : LogoutUI::LogoutUI
    기능     : LogoutUI 객체를 생성하고, 멤버 변수들을 초기화함
    전달 인자 : ifstream& in_fp - 입력 파일 스트림 참조
               ofstream& out_fp - 출력 파일 스트림 참조
    반환값   : 없음 (생성자)
*/
LogoutUI::LogoutUI(ifstream& in_fp, ofstream& out_fp) 
    : in_fp(in_fp), out_fp(out_fp) {
    control = nullptr;
}

/*
    함수 이름 : LogoutUI::startInterface
    기능     : 컨트롤 객체를 연결함
    전달 인자 : Logout* control - 컨트롤 객체 포인터
    반환값   : 없음
*/
void LogoutUI::startInterface(Logout* control) {
    this->control = control;
}

/*
    함수 이름 : LogoutUI::logout
    기능     : 로그아웃 기능을 수행하고 결과를 출력 파일에 기록함
    전달 인자 : 없음
    반환값   : 없음
*/
void LogoutUI::logout() {
    Member* member = this->control->logout();
    out_fp << "2.2. 로그아웃" << endl;
    out_fp << "> " << member->getId() << endl;
}