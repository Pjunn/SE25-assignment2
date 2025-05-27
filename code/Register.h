#pragma once

#include "MemberCollection.h"
#include <string>
#include <fstream>

using namespace std;

class RegisterUI; // Forward declaration of RegisterUI

/*
    클래스 이름 : Register
    기능       : 회원 가입 기능을 담당하는 컨트롤 클래스
    멤버 변수  : MemberCollection* memberCollection - 회원 정보 컬렉션 포인터
                ifstream& in_fp                    - 입력 파일 스트림 참조
                ofstream& out_fp                   - 출력 파일 스트림 참조
                RegisterUI* registerUI             - UI 클래스 포인터
*/
class Register {
private:
    MemberCollection* memberCollection; // 회원 정보 컬렉션
    ifstream& in_fp;  // 입력 파일 스트림
    ofstream& out_fp; // 출력 파일 스트림
    RegisterUI* registerUI; // UI 클래스 포인터 (필요시 사용)
public:
    /*
        함수 이름 : Register::Register
        기능     : Register 객체를 생성하고, 멤버 변수 및 UI 객체를 초기화함
        전달 인자 : MemberCollection* memberCollection - 회원 정보 컬렉션 포인터
                   ifstream& in_fp                    - 입력 파일 스트림 참조
                   ofstream& out_fp                   - 출력 파일 스트림 참조
        반환값   : 없음 (생성자)
    */
    Register(MemberCollection* memberCollection, ifstream& in_fp, ofstream& out_fp);

    /*
        함수 이름 : Register::getRegisterUI
        기능     : 내부에 생성된 RegisterUI 객체의 포인터를 반환함
        전달 인자 : 없음
        반환값   : RegisterUI* - UI 객체 포인터
    */
    RegisterUI* getRegisterUI();

    /*
        함수 이름 : Register::addNewMember
        기능     : 회원 정보 컬렉션에 새로운 회원 정보를 추가함
        전달 인자 : string id          - 회원 아이디
                   string password    - 회원 비밀번호
                   string phoneNumber - 회원 전화번호
        반환값   : 없음
    */
    void addNewMember(string id, string password, string phoneNumber);
};

