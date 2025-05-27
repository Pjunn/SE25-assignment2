#include "LoginUI.h"
#include "Login.h"
#include <fstream>

/*
    함수 이름 : LoginUI::LoginUI
    기능     : LoginUI 객체를 생성하고, 멤버 변수들을 초기화함
    전달 인자 : ifstream& in_fp - 입력 파일 스트림 참조
               ofstream& out_fp - 출력 파일 스트림 참조
    반환값   : 없음 (생성자)
*/
LoginUI::LoginUI(ifstream& in_fp, ofstream& out_fp) 
    : in_fp(in_fp), out_fp(out_fp) {
    control = nullptr;
    id = "";
    password = "";
}

/*
    함수 이름 : LoginUI::startInterface
    기능     : 컨트롤 객체를 연결하고 입력 스트림에서 로그인 정보를 읽어옴
    전달 인자 : Login* control - 컨트롤 객체 포인터
    반환값   : 없음
*/
void LoginUI::startInterface(Login* control) {
    this->control = control;
    in_fp >> id >> password;
}

/*
    함수 이름 : LoginUI::login
    기능     : 로그인 기능을 수행하고 결과를 출력 파일에 기록함
    전달 인자 : 없음
    반환값   : 없음
*/
void LoginUI::login() {
    this->control->login(id, password);
    out_fp << "2.1. 로그인" << endl;
    out_fp << "> " << id << " " << password << endl;
}