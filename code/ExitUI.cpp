#include "ExitUI.h"
#include "Exit.h"

/*
    함수 이름 : ExitUI::ExitUI
    기능     : ExitUI 객체를 생성하고, 멤버 변수들을 초기화함
    전달 인자 : ifstream& in_fp - 입력 파일 스트림 참조
               ofstream& out_fp - 출력 파일 스트림 참조
    반환값   : 없음 (생성자)
*/
ExitUI::ExitUI(ifstream& in_fp, ofstream& out_fp) : in_fp(in_fp), out_fp(out_fp) {}

/*
    함수 이름 : ExitUI::startInterface
    기능     : 컨트롤 객체를 연결함
    전달 인자 : Exit* control - 컨트롤 객체 포인터
    반환값   : 없음
*/
void ExitUI::startInterface(Exit* control) {
    this->control = control;
}

/*
    함수 이름 : ExitUI::exitProgram
    기능     : 프로그램 종료 메시지를 출력 파일에 기록함
    전달 인자 : 없음
    반환값   : 없음
*/
void ExitUI::exitProgram() {
    out_fp << "6.1. 종료" << endl; 
}