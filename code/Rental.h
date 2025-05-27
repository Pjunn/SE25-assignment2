#pragma once

#include "Bicycle.h"
#include <map>
#include <vector>
#include <string>

using namespace std;

/*
    클래스 이름 : Rental
    기능       : 회원별 자전거 대여 정보를 관리하는 클래스
    멤버 변수  : map<string, vector<Bicycle*>> rental - 회원 ID별 자전거 대여 목록 맵
*/
class Rental{
private:
    map<string, vector<Bicycle*>> rental; // 회원 ID별 자전거 대여 목록
public:
    /*
        함수 이름 : Rental::Rental
        기능     : Rental 객체를 생성하는 기본 생성자
        전달 인자 : 없음
        반환값   : 없음 (생성자)
    */
    Rental() = default; // 기본 생성자

    /*
        함수 이름 : Rental::addRental
        기능     : 회원의 대여 목록에 자전거를 추가함
        전달 인자 : string memberId   - 회원 ID
                   Bicycle* bicycle  - 대여할 자전거 객체 포인터
        반환값   : 없음
    */
    void addRental(string memberId, Bicycle* bicycle); // 자전거 대여 추가

    /*
        함수 이름 : Rental::getRentalsByMember
        기능     : 회원 ID로 해당 회원의 자전거 대여 목록을 반환함
        전달 인자 : string memberId - 회원 ID
        반환값   : vector<Bicycle*> - 해당 회원의 대여 자전거 목록(없으면 빈 벡터)
    */
    vector<Bicycle*> getRentalsByMember(string memberId) const; // 특정 회원의 대여 목록 반환
};