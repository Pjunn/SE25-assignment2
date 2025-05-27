#include "BicycleCollection.h"
#include <string>

/*
    함수 이름 : BicycleCollection::addBicycle
    기능     : 자전거 정보를 받아 배열에 새로운 자전거 객체를 추가함
    전달 인자 : string id   - 자전거 ID
               string name - 자전거 이름
    반환값   : 없음
*/
void BicycleCollection::addBicycle(string id, string name) {
    for (int i = 0; i < MAX_NUMBER_OF_BICYCLES; i++) {
        if (registeredBicycles[i] == nullptr) {
            registeredBicycles[i] = new Bicycle(id, name);
            break;
        }
    }
}

/*
    함수 이름 : BicycleCollection::findBicycleById
    기능     : 주어진 ID와 일치하는 자전거 객체를 배열에서 찾아 반환함
    전달 인자 : string id - 자전거 ID
    반환값   : Bicycle* - 해당 ID의 자전거 객체 포인터(없으면 nullptr)
*/
Bicycle* BicycleCollection::findBicycleById(string id) {
    for (int i = 0; i < MAX_NUMBER_OF_BICYCLES; i++) {
        if (registeredBicycles[i] != nullptr && registeredBicycles[i]->getId() == id) {
            return registeredBicycles[i];
        }
    }
    return nullptr; // 자전거가 존재하지 않으면 nullptr 반환
}