#pragma once

#include "Logout.h"
#include <string>
#include <fstream>

using namespace std;

/*
    클래스 이름 : LogoutUI
    기능       : 회원 로그아웃 UI를 담당하는 클래스
    멤버 변수  : Logout* control   - 로그아웃 컨트롤 객체 포인터
                ifstream& in_fp   - 입력 파일 스트림 참조
                ofstream& out_fp  - 출력 파일 스트림 참조
*/
class LogoutUI {
private:
    Logout* control;    // 로그아웃 컨트롤 객체
    ifstream& in_fp;    // 입력 파일 스트림
    ofstream& out_fp;   // 출력 파일 스트림
public:
    /*
        함수 이름 : LogoutUI::LogoutUI
        기능     : LogoutUI 객체를 생성하고, 멤버 변수들을 초기화함
        전달 인자 : ifstream& in_fp - 입력 파일 스트림 참조
                   ofstream& out_fp - 출력 파일 스트림 참조
        반환값   : 없음 (생성자)
    */
    LogoutUI(ifstream& in_fp, ofstream& out_fp); // 생성자

    /*
        함수 이름 : LogoutUI::startInterface
        기능     : 컨트롤 객체를 연결함
        전달 인자 : Logout* control - 컨트롤 객체 포인터
        반환값   : 없음
    */
    void startInterface(Logout* control); // 인터페이스 시작 메소드

    /*
        함수 이름 : LogoutUI::logout
        기능     : 로그아웃 기능을 수행하고 결과를 출력 파일에 기록함
        전달 인자 : 없음
        반환값   : 없음
    */
    void logout(); // 로그아웃 메소드
};
