#pragma once

#include <string>
#include <fstream>

using namespace std;

class Register; // Forward declaration of Register

/*
    클래스 이름 : RegisterUI
    기능       : 회원 가입 UI를 담당하는 클래스
    멤버 변수  : Register* control   - Register 컨트롤 객체 포인터
                ifstream& in_fp     - 입력 파일 스트림 참조
                ofstream& out_fp    - 출력 파일 스트림 참조
                string id           - 입력받은 회원 아이디
                string password     - 입력받은 회원 비밀번호
                string phoneNumber  - 입력받은 회원 전화번호
*/
class RegisterUI {
private:
    Register* control;      // Register 컨트롤 객체 포인터
    ifstream& in_fp;        // 입력 파일 스트림
    ofstream& out_fp;       // 출력 파일 스트림
    string id;              // 입력받은 회원 아이디
    string password;        // 입력받은 회원 비밀번호
    string phoneNumber;     // 입력받은 회원 전화번호
public:
    /*
        함수 이름 : RegisterUI::RegisterUI
        기능     : RegisterUI 객체를 생성하고, 멤버 변수들을 초기화함
        전달 인자 : ifstream& in_fp - 입력 파일 스트림 참조
                   ofstream& out_fp - 출력 파일 스트림 참조
        반환값   : 없음 (생성자)
    */
    RegisterUI(ifstream& in_fp, ofstream& out_fp);

    /*
        함수 이름 : RegisterUI::startInterface
        기능     : 컨트롤 객체를 연결하고 입력 스트림에서 회원 정보를 읽어옴
        전달 인자 : Register* control - 컨트롤 객체 포인터
        반환값   : 없음
    */
    void startInterface(Register* control);

    /*
        함수 이름 : RegisterUI::createNewMember
        기능     : 회원가입 기능을 수행하고 결과를 출력 파일에 기록함
        전달 인자 : 없음
        반환값   : 없음
    */
    void createNewMember();
};
