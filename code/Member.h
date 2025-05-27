#pragma once


#include <string>


using namespace std;

/*
    클래스 이름 : Member
    기능       : 회원 정보를 저장하는 클래스
    멤버 변수  : string id          - 회원 아이디
                string password    - 회원 비밀번호
                string phoneNumber - 회원 전화번호
*/
class Member {
private:
    string id;            // 회원 아이디
    string password;      // 회원 비밀번호
    string phoneNumber;   // 회원 전화번호
public:
    /*
        함수 이름 : Member::Member
        기능     : 회원 정보를 받아 Member 객체를 생성함
        전달 인자 : string id          - 회원 아이디
                   string password    - 회원 비밀번호
                   string phoneNumber - 회원 전화번호
        반환값   : 없음 (생성자)
    */
    Member(string id, string password, string phoneNumber);

    /*
        함수 이름 : Member::getId
        기능     : 회원 아이디를 반환함
        전달 인자 : 없음
        반환값   : string - 회원 아이디
    */
    string getId() const { return id; }            // 아이디 반환
};
