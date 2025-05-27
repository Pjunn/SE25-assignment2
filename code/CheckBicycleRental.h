#pragma once

#include "CurrentMember.h"
#include "Rental.h"
#include <string>
#include <fstream>
using namespace std;

class CheckBicycleRentalUI; // Forward declaration of CheckBicycleRentalUI

/*
    클래스 이름 : CheckBicycleRental
    기능       : 회원의 자전거 대여 내역을 확인하는 컨트롤 클래스
    멤버 변수  : ifstream& in_fp                - 입력 파일 스트림 참조
                ofstream& out_fp               - 출력 파일 스트림 참조
                CurrentMember* currentMember   - 현재 로그인된 회원 정보 포인터
                Rental* rental                 - 대여 정보 관리 객체 포인터
                CheckBicycleRentalUI* checkBicycleRentalUI - UI 클래스 포인터
*/
class CheckBicycleRental {
private:
    ifstream& in_fp;  // 입력 파일 스트림
    ofstream& out_fp; // 출력 파일 스트림
    CurrentMember* currentMember; // 현재 로그인된 회원 정보
    Rental* rental; // 대여 정보 관리 객체
    CheckBicycleRentalUI* checkBicycleRentalUI; // UI 클래스 포인터 (필요시 사용)

public:
    /*
        함수 이름 : CheckBicycleRental::CheckBicycleRental
        기능     : 객체를 생성하고 멤버 변수 및 UI 객체를 초기화함
        전달 인자 : ifstream& in_fp         - 입력 파일 스트림 참조
                   ofstream& out_fp         - 출력 파일 스트림 참조
                   CurrentMember* currentMember - 현재 회원 정보 포인터
                   Rental* rental           - 대여 정보 포인터
        반환값   : 없음 (생성자)
    */
    CheckBicycleRental(ifstream& in_fp, ofstream& out_fp, CurrentMember* currentMember, Rental* rental);

    /*
        함수 이름 : CheckBicycleRental::getCheckBicycleRentalUI
        기능     : 내부에 생성된 CheckBicycleRentalUI 객체의 포인터를 반환함
        전달 인자 : 없음
        반환값   : CheckBicycleRentalUI* - UI 객체 포인터
    */
    CheckBicycleRentalUI* getCheckBicycleRentalUI(); // UI 반환 메소드

    /*
        함수 이름 : CheckBicycleRental::checkRental
        기능     : 현재 회원의 자전거 대여 목록을 조회하여 반환함
        전달 인자 : 없음
        반환값   : vector<Bicycle*> - 회원의 대여 자전거 목록
    */
    vector<Bicycle*> checkRental(); // 자전거 대여 정보 확인 메소드
};