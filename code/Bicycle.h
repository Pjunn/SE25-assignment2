#pragma once

#include <string>

using namespace std;

/*
    클래스 이름 : Bicycle
    기능       : 자전거 정보를 저장하는 클래스
    멤버 변수  : string id   - 자전거 ID
                string name - 자전거 이름
*/
class Bicycle {
private:
    string id;            // 자전거 ID
    string name;          // 자전거 이름
public:
    /*
        함수 이름 : Bicycle::Bicycle
        기능     : 자전거 ID와 이름을 받아 Bicycle 객체를 생성함
        전달 인자 : string id   - 자전거 ID
                   string name - 자전거 이름
        반환값   : 없음 (생성자)
    */
    Bicycle(string id, string name);

    /*
        함수 이름 : Bicycle::getId
        기능     : 자전거 ID를 반환함
        전달 인자 : 없음
        반환값   : string - 자전거 ID
    */
    string getId() const { return id; }            // 자전거 ID 반환

    /*
        함수 이름 : Bicycle::getName
        기능     : 자전거 이름을 반환함
        전달 인자 : 없음
        반환값   : string - 자전거 이름
    */
    string getName() const { return name; }        // 자전거 이름 반환
};
