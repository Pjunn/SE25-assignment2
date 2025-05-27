#pragma once

#include "Member.h"
#include <string>

using namespace std;

/*
    클래스 이름 : CurrentMember
    기능       : 현재 로그인된 회원 정보를 관리하는 클래스
    멤버 변수  : Member* currentMember - 현재 로그인된 회원 정보 포인터
*/
class CurrentMember {
private:
    Member* currentMember; // 현재 로그인된 회원 정보
public:
    /*
        함수 이름 : CurrentMember::CurrentMember
        기능     : currentMember를 nullptr로 초기화하는 생성자
        전달 인자 : 없음
        반환값   : 없음 (생성자)
    */
    CurrentMember() : currentMember(nullptr) {} // 생성자, 초기화

    /*
        함수 이름 : CurrentMember::~CurrentMember
        기능     : 동적으로 할당된 회원 정보를 해제하는 소멸자
        전달 인자 : 없음
        반환값   : 없음 (소멸자)
    */
    ~CurrentMember() { delete currentMember; } // 소멸자, 동적 할당 해제

    /*
        함수 이름 : CurrentMember::setCurrentMember
        기능     : 현재 로그인된 회원 정보를 설정하고, 이전 회원 정보가 있으면 동적으로 해제함
        전달 인자 : Member* member - 새로 설정할 회원 정보 포인터
        반환값   : 없음
    */
    void setCurrentMember(Member* member); // 현재 회원 설정

    /*
        함수 이름 : CurrentMember::getCurrentMember
        기능     : 현재 로그인된 회원 정보를 반환함
        전달 인자 : 없음
        반환값   : Member* - 현재 회원 정보 포인터
    */
    Member* getCurrentMember() const; // 현재 회원 정보 반환
};
