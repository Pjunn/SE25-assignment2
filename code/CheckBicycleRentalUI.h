#pragma once

#include <string>
#include <fstream>
using namespace std;

class CheckBicycleRental; // Forward declaration of CheckBicycleRental

/*
    클래스 이름 : CheckBicycleRentalUI
    기능       : 자전거 대여 내역 조회 UI를 담당하는 클래스
    멤버 변수  : ifstream& in_fp                - 입력 파일 스트림 참조
                ofstream& out_fp               - 출력 파일 스트림 참조
                CheckBicycleRental* control    - 자전거 대여 정보 확인 컨트롤러 포인터
*/
class CheckBicycleRentalUI {
private:
    ifstream& in_fp;  // 입력 파일 스트림
    ofstream& out_fp; // 출력 파일 스트림
    CheckBicycleRental* control; // 자전거 대여 정보 확인 컨트롤러
public:
    /*
        함수 이름 : CheckBicycleRentalUI::CheckBicycleRentalUI
        기능     : CheckBicycleRentalUI 객체를 생성하고, 멤버 변수들을 초기화함
        전달 인자 : ifstream& in_fp - 입력 파일 스트림 참조
                   ofstream& out_fp - 출력 파일 스트림 참조
        반환값   : 없음 (생성자)
    */
    CheckBicycleRentalUI(ifstream& in_fp, ofstream& out_fp);

    /*
        함수 이름 : CheckBicycleRentalUI::startInterface
        기능     : 컨트롤 객체를 연결함
        전달 인자 : CheckBicycleRental* control - 컨트롤 객체 포인터
        반환값   : 없음
    */
    void startInterface(CheckBicycleRental* control);

    /*
        함수 이름 : CheckBicycleRentalUI::checkRental
        기능     : 자전거 대여 정보를 조회하여 출력 파일에 기록함
        전달 인자 : 없음
        반환값   : 없음
    */
    void checkRental();
};