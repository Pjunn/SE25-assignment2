#pragma once

#include "BicycleCollection.h"
#include <string>
#include <fstream>

using namespace std;
class AddBicycleUI; // AddBicycleUI 클래스 전방 선언

/*
    클래스 이름 : AddBicycle
    기능       : 자전거 추가 기능을 담당하는 컨트롤 클래스
    멤버 변수  : BicycleCollection* bicycleCollection - 자전거 정보 컬렉션 포인터
                ifstream& in_fp - 입력 파일 스트림 참조
                ofstream& out_fp - 출력 파일 스트림 참조
                AddBicycleUI* addBicycleUI - UI 클래스 포인터
*/
class AddBicycle {
private:
    BicycleCollection* bicycleCollection; // 자전거 정보 컬렉션
    ifstream& in_fp;  // 입력 파일 스트림
    ofstream& out_fp; // 출력 파일 스트림
    AddBicycleUI* addBicycleUI; // UI 클래스 포인터 (필요시 사용)
public:
    /*
        함수 이름 : AddBicycle::AddBicycle
        기능     : AddBicycle 객체를 생성하고, 멤버 변수 및 UI 객체를 초기화함
        전달 인자 : BicycleCollection* bicycleCollection - 자전거 컬렉션 포인터
                   ifstream& in_fp - 입력 파일 스트림 참조
                   ofstream& out_fp - 출력 파일 스트림 참조
        반환값   : 없음 (생성자)
    */
    AddBicycle(BicycleCollection* bicycleCollection, ifstream& in_fp, ofstream& out_fp);

    /*
        함수 이름 : AddBicycle::getAddBicycleUI
        기능     : 내부에 생성된 AddBicycleUI 객체의 포인터를 반환함
        전달 인자 : 없음
        반환값   : AddBicycleUI* - UI 객체 포인터
    */
    AddBicycleUI* getAddBicycleUI(); // AddBicycleUI 반환 메소드

    /*
        함수 이름 : AddBicycle::addBicycle
        기능     : 자전거 컬렉션에 새로운 자전거 정보를 추가함
        전달 인자 : string id   - 자전거 ID
                   string name - 자전거 이름
        반환값   : 없음
    */
    void addBicycle(string id, string name); // 자전거 추가 메소드
};
