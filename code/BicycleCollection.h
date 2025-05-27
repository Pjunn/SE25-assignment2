#pragma once

#include "Bicycle.h"
#include <string>

#define MAX_NUMBER_OF_BICYCLES 100 // 최대 자전거 수
using namespace std;

/*
    클래스 이름 : BicycleCollection
    기능       : 여러 자전거 객체를 저장하고 관리하는 클래스
    멤버 변수  : Bicycle* registeredBicycles[MAX_NUMBER_OF_BICYCLES] - 자전거 객체 배열
*/
class BicycleCollection {
private:
    Bicycle* registeredBicycles[MAX_NUMBER_OF_BICYCLES]; // 자전거 배열
public:
    /*
        함수 이름 : BicycleCollection::BicycleCollection
        기능     : 자전거 배열을 nullptr로 초기화하는 생성자
        전달 인자 : 없음
        반환값   : 없음 (생성자)
    */
    BicycleCollection() {
        for (int i = 0; i < MAX_NUMBER_OF_BICYCLES; i++) {
            registeredBicycles[i] = nullptr; // 초기화
        }
    }

    /*
        함수 이름 : BicycleCollection::~BicycleCollection
        기능     : 동적으로 할당된 자전거 객체들을 해제하는 소멸자
        전달 인자 : 없음
        반환값   : 없음 (소멸자)
    */
    ~BicycleCollection() {
        for (int i = 0; i < MAX_NUMBER_OF_BICYCLES; i++) {
            delete registeredBicycles[i]; // 동적 할당 해제
        }
    }

    /*
        함수 이름 : BicycleCollection::addBicycle
        기능     : 자전거 정보를 받아 배열에 새로운 자전거 객체를 추가함
        전달 인자 : string id   - 자전거 ID
                   string name - 자전거 이름
        반환값   : 없음
    */
    void addBicycle(string id, string name);

    /*
        함수 이름 : BicycleCollection::findBicycleById
        기능     : 주어진 ID와 일치하는 자전거 객체를 배열에서 찾아 반환함
        전달 인자 : string id - 자전거 ID
        반환값   : Bicycle* - 해당 ID의 자전거 객체 포인터(없으면 nullptr)
    */
    Bicycle* findBicycleById(string id);
};
