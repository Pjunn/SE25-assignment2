#include <string>
#include "Member.h"

/*
    함수 이름 : Member::Member
    기능     : Member 객체를 생성하고, 회원 ID, 비밀번호, 전화번호를 초기화함
    전달 인자 : string id          - 회원 ID
               string password    - 회원 비밀번호
               string phoneNumber - 회원 전화번호
    반환값   : 없음 (생성자)
*/
Member::Member(string id, string password, string phoneNumber) 
    : id(id), password(password), phoneNumber(phoneNumber) {}
