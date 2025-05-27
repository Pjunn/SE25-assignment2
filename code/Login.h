#pragma once

#include "CurrentMember.h"
#include "MemberCollection.h"
#include <string>
#include <fstream>

using namespace std;

class LoginUI; // Forward declaration of LoginUI

/*
    클래스 이름 : Login
    기능       : 회원 로그인 기능을 담당하는 컨트롤 클래스
    멤버 변수  : CurrentMember* currentMember      - 현재 로그인된 회원 정보 포인터
                MemberCollection* memberCollection - 회원 정보 컬렉션 포인터
                ifstream& in_fp                   - 입력 파일 스트림 참조
                ofstream& out_fp                  - 출력 파일 스트림 참조
                LoginUI* loginUI                  - UI 클래스 포인터
*/
class Login {
private:
    CurrentMember* currentMember; // 현재 로그인된 회원 정보
    MemberCollection* memberCollection; // 회원 정보 컬렉션
    ifstream& in_fp;  // 입력 파일 스트림
    ofstream& out_fp; // 출력 파일 스트림
    LoginUI* loginUI; // UI 클래스 포인터 (필요시 사용)
public:
    /*
        함수 이름 : Login::Login
        기능     : Login 객체를 생성하고, 멤버 변수 및 UI 객체를 초기화함
        전달 인자 : CurrentMember* currentMember      - 현재 로그인된 회원 정보 포인터
                   MemberCollection* memberCollection - 회원 정보 컬렉션 포인터
                   ifstream& in_fp                   - 입력 파일 스트림 참조
                   ofstream& out_fp                  - 출력 파일 스트림 참조
        반환값   : 없음 (생성자)
    */
    Login(CurrentMember* currentMember, MemberCollection* memberCollection, ifstream& in_fp, ofstream& out_fp);

    /*
        함수 이름 : Login::getLoginUI
        기능     : 내부에 생성된 LoginUI 객체의 포인터를 반환함
        전달 인자 : 없음
        반환값   : LoginUI* - UI 객체 포인터
    */
    LoginUI* getLoginUI(); // 로그인 UI 반환 메소드

    /*
        함수 이름 : Login::login
        기능     : 입력받은 ID와 비밀번호로 회원을 찾아 현재 로그인 회원으로 설정함
        전달 인자 : string id       - 회원 ID
                   string password - 회원 비밀번호
        반환값   : 없음
    */
    void login(string id, string password); // 로그인 메소드
};
