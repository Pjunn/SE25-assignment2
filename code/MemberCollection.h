#pragma once


#include "Member.h"
#include <string>


#define MAX_NUMBER_OF_MEMBERS 100 // 최대 회원 수

using namespace std;

/*
    클래스 이름 : MemberCollection
    기능       : 여러 회원 객체를 저장하고 관리하는 클래스
    멤버 변수  : Member* registeredMember[MAX_NUMBER_OF_MEMBERS] - 회원 객체 배열
*/
class MemberCollection {
private:
    Member* registeredMember[MAX_NUMBER_OF_MEMBERS]; // 회원 객체 배열
public:
    /*
        함수 이름 : MemberCollection::MemberCollection
        기능     : 회원 배열을 초기화하고, 관리자 계정을 추가함
        전달 인자 : 없음
        반환값   : 없음 (생성자)
    */
    MemberCollection();

    /*
        함수 이름 : MemberCollection::addNewMember
        기능     : 새로운 회원 정보를 배열에 추가함
        전달 인자 : string id          - 회원 아이디
                   string password    - 회원 비밀번호
                   string phoneNumber - 회원 전화번호
        반환값   : 없음
    */
    void addNewMember(string id, string password, string phoneNumber);

    /*
        함수 이름 : MemberCollection::findMemberById
        기능     : 주어진 아이디와 일치하는 회원을 배열에서 찾아 반환함
        전달 인자 : string id - 회원 아이디
        반환값   : Member* - 해당 아이디의 회원 객체 포인터(없으면 nullptr)
    */
    Member* findMemberById(string id);
};
