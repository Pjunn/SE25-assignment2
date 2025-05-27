#include "CheckBicycleRental.h"
#include "CheckBicycleRentalUI.h"
#include "Bicycle.h"
#include "Rental.h"
#include <vector>
#include <fstream>

/*
    함수 이름 : CheckBicycleRental::CheckBicycleRental
    기능     : CheckBicycleRental 객체를 생성하고, 멤버 변수 및 UI 객체를 초기화함
    전달 인자 : ifstream& in_fp         - 입력 파일 스트림 참조
               ofstream& out_fp         - 출력 파일 스트림 참조
               CurrentMember* currentMember - 현재 회원 정보 포인터
               Rental* rental           - 대여 정보 포인터
    반환값   : 없음 (생성자)
*/
CheckBicycleRental::CheckBicycleRental(ifstream& in_fp, ofstream& out_fp, CurrentMember* currentMember, Rental* rental)
    : in_fp(in_fp), out_fp(out_fp), currentMember(currentMember), rental(rental) {
    checkBicycleRentalUI = new CheckBicycleRentalUI(in_fp, out_fp);
}

/*
    함수 이름 : CheckBicycleRental::getCheckBicycleRentalUI
    기능     : 내부에 생성된 CheckBicycleRentalUI 객체의 포인터를 반환함
    전달 인자 : 없음
    반환값   : CheckBicycleRentalUI* - UI 객체 포인터
*/
CheckBicycleRentalUI* CheckBicycleRental::getCheckBicycleRentalUI() {
    return checkBicycleRentalUI; // UI 반환
}

/*
    함수 이름 : CheckBicycleRental::checkRental
    기능     : 현재 회원의 자전거 대여 목록을 조회하여 반환함
    전달 인자 : 없음
    반환값   : vector<Bicycle*> - 회원의 대여 자전거 목록
*/
vector<Bicycle*> CheckBicycleRental::checkRental() {
    Member* member = currentMember->getCurrentMember(); // 현재 회원 정보 가져오기

    vector<Bicycle*> rentals = rental->getRentalsByMember(member->getId()); // 회원의 대여 목록 가져오기
    return rentals; // 대여 목록 반환
}