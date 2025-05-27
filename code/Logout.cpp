#include "Logout.h"
#include "LogoutUI.h"
#include <iostream>
#include <fstream>

/*
    함수 이름 : Logout::Logout
    기능     : Logout 객체를 생성하고, 멤버 변수 및 UI 객체를 초기화함
    전달 인자 : CurrentMember* currentMember - 현재 로그인된 회원 정보 포인터
               ifstream& in_fp              - 입력 파일 스트림 참조
               ofstream& out_fp             - 출력 파일 스트림 참조
    반환값   : 없음 (생성자)
*/
Logout::Logout(CurrentMember* currentMember, ifstream& in_fp, ofstream& out_fp)
    : currentMember(currentMember), in_fp(in_fp), out_fp(out_fp) {
    logoutUI = new LogoutUI(in_fp, out_fp);
}

/*
    함수 이름 : Logout::getLogoutUI
    기능     : 내부에 생성된 LogoutUI 객체의 포인터를 반환함
    전달 인자 : 없음
    반환값   : LogoutUI* - UI 객체 포인터
*/
LogoutUI* Logout::getLogoutUI() {
    return logoutUI; // 로그아웃 UI 반환
}

/*
    함수 이름 : Logout::logout
    기능     : 현재 로그인된 회원 정보를 복사하여 반환하고, 현재 회원 정보를 초기화함
    전달 인자 : 없음
    반환값   : Member* - 로그아웃된 회원 정보(복사본) 포인터
*/
Member* Logout::logout() {
    Member* member = currentMember->getCurrentMember(); // 현재 로그인된 회원 정보 가져오기
    Member* logoutMember = new Member(*member); // 로그아웃된 회원 정보 생성
    currentMember->setCurrentMember(nullptr); // 현재 회원 정보 초기화
    return logoutMember; // 로그아웃된 회원 정보 반환
}