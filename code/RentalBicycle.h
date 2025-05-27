#pragma once

#include "BicycleCollection.h"
#include "CurrentMember.h"
#include "Bicycle.h"
#include "Rental.h"
#include <string>
#include <fstream>

using namespace std;

class RentalBicycleUI; // Forward declaration of RentalBicycleUI

/*
    클래스 이름 : RentalBicycle
    기능       : 자전거 대여 기능을 담당하는 컨트롤 클래스
    멤버 변수  : BicycleCollection* bicycleCollection - 자전거 컬렉션 포인터
                CurrentMember* currentMember         - 현재 로그인된 회원 정보 포인터
                Rental* rental                       - 자전거 대여 정보 포인터
                ifstream& in_fp                      - 입력 파일 스트림 참조
                ofstream& out_fp                     - 출력 파일 스트림 참조
                RentalBicycleUI* rentalBicycleUI     - 대여 자전거 UI 클래스 포인터
*/
class RentalBicycle {
private:
    BicycleCollection* bicycleCollection; // 자전거 컬렉션
    CurrentMember* currentMember;         // 현재 로그인된 회원 정보
    Rental* rental;                       // 자전거 대여 정보
    ifstream& in_fp;                      // 입력 파일 스트림
    ofstream& out_fp;                     // 출력 파일 스트림
    RentalBicycleUI* rentalBicycleUI;     // 대여 자전거 UI 클래스 포인터

public:
    /*
        함수 이름 : RentalBicycle::RentalBicycle
        기능     : RentalBicycle 객체를 생성하고, 멤버 변수 및 UI 객체를 초기화함
        전달 인자 : BicycleCollection* bicycleCollection - 자전거 컬렉션 포인터
                   CurrentMember* currentMember         - 현재 로그인된 회원 정보 포인터
                   Rental* rental                       - 자전거 대여 정보 포인터
                   ifstream& in_fp                      - 입력 파일 스트림 참조
                   ofstream& out_fp                     - 출력 파일 스트림 참조
        반환값   : 없음 (생성자)
    */
    RentalBicycle(BicycleCollection* bicycleCollection, CurrentMember* currentMember, Rental* rental, ifstream& in_fp, ofstream& out_fp);

    /*
        함수 이름 : RentalBicycle::getRentalBicycleUI
        기능     : 내부에 생성된 RentalBicycleUI 객체의 포인터를 반환함
        전달 인자 : 없음
        반환값   : RentalBicycleUI* - UI 객체 포인터
    */
    RentalBicycleUI* getRentalBicycleUI(); // 대여 자전거 UI 반환 메소드

    /*
        함수 이름 : RentalBicycle::rent
        기능     : 자전거를 찾아 현재 회원의 대여 목록에 추가하고, 대여한 자전거 객체를 반환함
        전달 인자 : string id - 대여할 자전거 ID
        반환값   : Bicycle*  - 대여한 자전거 객체 포인터
    */
    Bicycle* rent(string id); // 자전거 대여 메소드
};