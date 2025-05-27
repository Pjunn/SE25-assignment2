#pragma once

#include <string>
#include <fstream>
using namespace std;

class AddBicycle; // AddBicycle 클래스 전방 선언

/*
    클래스 이름 : AddBicycleUI
    기능       : 자전거 등록 UI를 담당하는 클래스
    멤버 변수  : AddBicycle* control - AddBicycle 컨트롤 객체 포인터
                ifstream& in_fp     - 입력 파일 스트림 참조
                ofstream& out_fp    - 출력 파일 스트림 참조
                string id           - 자전거 ID
                string name         - 자전거 이름
*/
class AddBicycleUI {
private:
    AddBicycle* control; // AddBicycle 클래스의 인스턴스
    ifstream& in_fp;     // 입력 파일 스트림
    ofstream& out_fp;    // 출력 파일 스트림
    string id;           // 자전거 ID
    string name;         // 자전거 이름
public:
    /*
        함수 이름 : AddBicycleUI::AddBicycleUI
        기능     : AddBicycleUI 객체를 생성하고, 멤버 변수들을 초기화함
        전달 인자 : ifstream& in_fp - 입력 파일 스트림 참조
                   ofstream& out_fp - 출력 파일 스트림 참조
        반환값   : 없음 (생성자)
    */
    AddBicycleUI(ifstream& in_fp, ofstream& out_fp);

    /*
        함수 이름 : AddBicycleUI::startInterface
        기능     : 컨트롤 객체를 연결하고 입력 스트림에서 자전거 정보를 읽어옴
        전달 인자 : AddBicycle* control - 컨트롤 객체 포인터
        반환값   : 없음
    */
    void startInterface(AddBicycle* control); // 인터페이스 시작 메소드

    /*
        함수 이름 : AddBicycleUI::createBicycle
        기능     : 자전거 등록 기능을 수행하고 결과를 출력 파일에 기록함
        전달 인자 : 없음
        반환값   : 없음
    */
    void createBicycle(); // 자전거 추가 메소드
};

