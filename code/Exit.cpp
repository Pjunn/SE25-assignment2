#include "Exit.h"
#include "ExitUI.h"
#include <fstream>

/*
    함수 이름 : Exit::Exit
    기능     : Exit 객체를 생성하고, 멤버 변수 및 UI 객체를 초기화함
    전달 인자 : ifstream& in_fp - 입력 파일 스트림 참조
               ofstream& out_fp - 출력 파일 스트림 참조
    반환값   : 없음 (생성자)
*/
Exit::Exit(ifstream& in_fp, ofstream& out_fp) : in_fp(in_fp), out_fp(out_fp) {
    exitUI = new ExitUI(in_fp, out_fp);
}

/*
    함수 이름 : Exit::getExitUI
    기능     : 내부에 생성된 ExitUI 객체의 포인터를 반환함
    전달 인자 : 없음
    반환값   : ExitUI* - UI 객체 포인터
*/
ExitUI* Exit::getExitUI() {
    return exitUI;
}