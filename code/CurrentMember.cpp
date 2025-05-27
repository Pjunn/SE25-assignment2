#include "CurrentMember.h"

/*
    함수 이름 : CurrentMember::setCurrentMember
    기능     : 현재 로그인된 회원 정보를 설정하고, 이전 회원 정보가 있으면 동적으로 해제함
    전달 인자 : Member* member - 새로 설정할 회원 정보 포인터
    반환값   : 없음
*/
void CurrentMember::setCurrentMember(Member* member) {
    if (currentMember != nullptr) {
        delete currentMember; // 이전 회원 정보 동적 할당 해제
    }
    currentMember = member; // 현재 회원 정보 설정
}

/*
    함수 이름 : CurrentMember::getCurrentMember
    기능     : 현재 로그인된 회원 정보를 반환함
    전달 인자 : 없음
    반환값   : Member* - 현재 회원 정보 포인터
*/
Member* CurrentMember::getCurrentMember() const {
    return currentMember; // 현재 회원 정보 반환
}

