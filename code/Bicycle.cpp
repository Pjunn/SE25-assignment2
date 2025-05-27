#include "Bicycle.h"
#include <string>

/*
    함수 이름 : Bicycle::Bicycle
    기능     : Bicycle 객체를 생성하고, 자전거 ID와 이름을 초기화함
    전달 인자 : string id   - 자전거 ID
               string name - 자전거 이름
    반환값   : 없음 (생성자)
*/
Bicycle::Bicycle(string id, string name) 
    : id(id), name(name) {}