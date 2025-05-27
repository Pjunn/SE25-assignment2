#include "AddBicycle.h"
#include "AddBicycleUI.h"
#include <fstream>

/*
    함수 이름 : AddBicycle::AddBicycle
    기능     : AddBicycle 객체를 생성하고, 내부 멤버 변수와 UI 객체를 초기화함
    전달 인자 : BicycleCollection* bicycleCollection - 자전거 컬렉션 포인터
               ifstream& in_fp - 입력 파일 스트림 참조
               ofstream& out_fp - 출력 파일 스트림 참조
    반환값   : 없음 (생성자)
*/
AddBicycle::AddBicycle(BicycleCollection* bicycleCollection, ifstream& in_fp, ofstream& out_fp)
    : bicycleCollection(bicycleCollection), in_fp(in_fp), out_fp(out_fp) {
    addBicycleUI = new AddBicycleUI(in_fp, out_fp);
}

/*
    함수 이름 : AddBicycle::getAddBicycleUI
    기능     : 내부에 생성된 AddBicycleUI 객체의 포인터를 반환함
    전달 인자 : 없음
    반환값   : AddBicycleUI* - UI 객체 포인터
*/
AddBicycleUI* AddBicycle::getAddBicycleUI() {
    return addBicycleUI;
}

/*
    함수 이름 : AddBicycle::addBicycle
    기능     : 자전거 컬렉션에 새로운 자전거 정보를 추가함
    전달 인자 : string id   - 자전거 ID
               string name - 자전거 이름
    반환값   : 없음
*/
void AddBicycle::addBicycle(string id, string name) {
    bicycleCollection->addBicycle(id, name);
}