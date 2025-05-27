#include <string>
#include "MemberCollection.h"
#include "Member.h"

/*
    함수 이름 : MemberCollection::MemberCollection
    기능     : MemberCollection 객체를 생성하고, 회원 배열을 초기화하며 관리자 계정을 추가함
    전달 인자 : 없음
    반환값   : 없음 (생성자)
*/
MemberCollection::MemberCollection() {
    // 초기화: 모든 회원 포인터를 nullptr로 설정
    for (int i = 0; i < MAX_NUMBER_OF_MEMBERS; i++) {
        registeredMember[i] = nullptr;
    }
    registeredMember[0] = new Member("admin", "admin", "010-1234-5678"); // 초기 관리자 계정 추가
}

/*
    함수 이름 : MemberCollection::addNewMember
    기능     : 새로운 회원 정보를 배열에 추가함
    전달 인자 : string id          - 회원 아이디
               string password    - 회원 비밀번호
               string phoneNumber - 회원 전화번호
    반환값   : 없음
*/
void MemberCollection::addNewMember(string id, string password, string phoneNumber) {
    for (int i = 0; i < MAX_NUMBER_OF_MEMBERS; i++) {
        if (registeredMember[i] == nullptr) {
            registeredMember[i] = new Member(id, password, phoneNumber);
            break;
        }
    }
}

/*
    함수 이름 : MemberCollection::findMemberById
    기능     : 주어진 아이디와 일치하는 회원을 배열에서 찾아 반환함
    전달 인자 : string id - 회원 아이디
    반환값   : Member* - 해당 아이디의 회원 객체 포인터(없으면 nullptr)
*/
Member* MemberCollection::findMemberById(string id) {
    for (int i = 0; i < MAX_NUMBER_OF_MEMBERS; i++) {
        if (registeredMember[i] != nullptr && registeredMember[i]->getId() == id) {
            return registeredMember[i];
        }
    }
    return nullptr; // 회원이 존재하지 않으면 nullptr 반환
}