#include "Login.h"
#include "LoginUI.h"
#include <fstream>

/*
    함수 이름 : Login::Login
    기능     : Login 객체를 생성하고, 멤버 변수 및 UI 객체를 초기화함
    전달 인자 : CurrentMember* currentMember      - 현재 로그인된 회원 정보 포인터
               MemberCollection* memberCollection - 회원 정보 컬렉션 포인터
               ifstream& in_fp                   - 입력 파일 스트림 참조
               ofstream& out_fp                  - 출력 파일 스트림 참조
    반환값   : 없음 (생성자)
*/
Login::Login(CurrentMember* currentMember, MemberCollection* memberCollection, ifstream& in_fp, ofstream& out_fp)
    : currentMember(currentMember), memberCollection(memberCollection), in_fp(in_fp), out_fp(out_fp) {
    loginUI = new LoginUI(in_fp, out_fp);
}

/*
    함수 이름 : Login::getLoginUI
    기능     : 내부에 생성된 LoginUI 객체의 포인터를 반환함
    전달 인자 : 없음
    반환값   : LoginUI* - UI 객체 포인터
*/
LoginUI* Login::getLoginUI() {
    return loginUI;
}

/*
    함수 이름 : Login::login
    기능     : 입력받은 ID로 회원을 찾아 현재 로그인 회원으로 설정함
    전달 인자 : string id       - 회원 ID
               string password - 회원 비밀번호
    반환값   : 없음
*/
void Login::login(string id, string password) {
    Member* member = memberCollection->findMemberById(id);
    currentMember->setCurrentMember(member);
}