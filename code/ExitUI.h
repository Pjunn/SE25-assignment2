#pragma once

#include <fstream>

using namespace std;

class Exit; // Forward declaration of Exit

/*
    클래스 이름 : ExitUI
    기능       : 프로그램 종료 UI를 담당하는 클래스
    멤버 변수  : ifstream& in_fp   - 입력 파일 스트림 참조
                ofstream& out_fp  - 출력 파일 스트림 참조
                Exit* control     - Exit 컨트롤 객체 포인터
*/
class ExitUI {
private:
    ifstream& in_fp;  // 입력 파일 스트림
    ofstream& out_fp; // 출력 파일 스트림
    Exit* control;    // Exit 클래스의 제어 객체
public:
    /*
        함수 이름 : ExitUI::ExitUI
        기능     : ExitUI 객체를 생성하고, 멤버 변수들을 초기화함
        전달 인자 : ifstream& in_fp - 입력 파일 스트림 참조
                   ofstream& out_fp - 출력 파일 스트림 참조
        반환값   : 없음 (생성자)
    */
    ExitUI(ifstream& in_fp, ofstream& out_fp);

    /*
        함수 이름 : ExitUI::startInterface
        기능     : 컨트롤 객체를 연결함
        전달 인자 : Exit* control - 컨트롤 객체 포인터
        반환값   : 없음
    */
    void startInterface(Exit* control); // 인터페이스 시작 메소드

    /*
        함수 이름 : ExitUI::exitProgram
        기능     : 프로그램 종료 메시지를 출력 파일에 기록함
        전달 인자 : 없음
        반환값   : 없음
    */
    void exitProgram(); // 프로그램 종료 메소드
};