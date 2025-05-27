#include "CheckBicycleRentalUI.h"
#include "CheckBicycleRental.h"
#include <vector>
#include <fstream>
#include <algorithm>

/*
    함수 이름 : CheckBicycleRentalUI::CheckBicycleRentalUI
    기능     : CheckBicycleRentalUI 객체를 생성하고, 멤버 변수들을 초기화함
    전달 인자 : ifstream& in_fp - 입력 파일 스트림 참조
               ofstream& out_fp - 출력 파일 스트림 참조
    반환값   : 없음 (생성자)
*/
CheckBicycleRentalUI::CheckBicycleRentalUI(ifstream& in_fp, ofstream& out_fp)
    : in_fp(in_fp), out_fp(out_fp) {
    control = nullptr;
}

/*
    함수 이름 : CheckBicycleRentalUI::startInterface
    기능     : 컨트롤 객체를 연결함
    전달 인자 : CheckBicycleRental* control - 컨트롤 객체 포인터
    반환값   : 없음
*/
void CheckBicycleRentalUI::startInterface(CheckBicycleRental* control) {
    this->control = control;
}

/*
    함수 이름 : CheckBicycleRentalUI::checkRental
    기능     : 자전거 대여 정보를 조회하여 정렬 후 출력 파일에 기록함
    전달 인자 : 없음
    반환값   : 없음
*/
void CheckBicycleRentalUI::checkRental() {
    vector<Bicycle*> rentals = control->checkRental(); // 자전거 대여 정보 확인
    sort(rentals.begin(), rentals.end(), [](Bicycle* a, Bicycle* b) {
        return a->getId() < b->getId();
    });
    out_fp << "5.1. 자전거 대여 리스트" << endl; // 출력 형식에 맞춰 출력
    for (const auto& bicycle : rentals) {
        out_fp << "> " << bicycle->getId() << " " << bicycle->getName() << endl; // 대여한 자전거 ID와 이름 출력
    }
}