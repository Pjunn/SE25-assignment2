#pragma once

#include "CurrentMember.h"
#include "Member.h"
#include <string>
#include <fstream>

using namespace std;

class LogoutUI; // Forward declaration of LogoutUI

/*
    클래스 이름 : Logout
    기능       : 회원 로그아웃 기능을 담당하는 컨트롤 클래스
    멤버 변수  : CurrentMember* currentMember - 현재 로그인된 회원 정보 포인터
                ifstream& in_fp              - 입력 파일 스트림 참조
                ofstream& out_fp             - 출력 파일 스트림 참조
                LogoutUI* logoutUI           - UI 클래스 포인터
*/
class Logout {
private:
    CurrentMember* currentMember; // 현재 로그인된 회원 정보
    ifstream& in_fp;              // 입력 파일 스트림
    ofstream& out_fp;             // 출력 파일 스트림
    LogoutUI* logoutUI;           // UI 클래스 포인터 (필요시 사용)
public:
    /*
        함수 이름 : Logout::Logout
        기능     : Logout 객체를 생성하고, 멤버 변수 및 UI 객체를 초기화함
        전달 인자 : CurrentMember* currentMember - 현재 로그인된 회원 정보 포인터
                   ifstream& in_fp              - 입력 파일 스트림 참조
                   ofstream& out_fp             - 출력 파일 스트림 참조
        반환값   : 없음 (생성자)
    */
    Logout(CurrentMember* currentMember, ifstream& in_fp, ofstream& out_fp);

    /*
        함수 이름 : Logout::getLogoutUI
        기능     : 내부에 생성된 LogoutUI 객체의 포인터를 반환함
        전달 인자 : 없음
        반환값   : LogoutUI* - UI 객체 포인터
    */
    LogoutUI* getLogoutUI(); // 로그아웃 UI 반환 메소드

    /*
        함수 이름 : Logout::logout
        기능     : 현재 로그인된 회원 정보를 복사하여 반환하고, 현재 회원 정보를 초기화함
        전달 인자 : 없음
        반환값   : Member* - 로그아웃된 회원 정보(복사본) 포인터
    */
    Member* logout();
};
