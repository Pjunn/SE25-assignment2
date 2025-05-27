#include "Rental.h"

/*
    함수 이름 : Rental::addRental
    기능     : 회원의 대여 목록에 자전거를 추가함
    전달 인자 : string memberId   - 회원 ID
               Bicycle* bicycle  - 대여할 자전거 객체 포인터
    반환값   : 없음
*/
void Rental::addRental(string memberId, Bicycle* bicycle) {
    rental[memberId].push_back(bicycle); // 회원 ID를 키로 하여 자전거를 대여 목록에 추가
}

/*
    함수 이름 : Rental::getRentalsByMember
    기능     : 회원 ID로 해당 회원의 자전거 대여 목록을 반환함
    전달 인자 : string memberId - 회원 ID
    반환값   : vector<Bicycle*> - 해당 회원의 대여 자전거 목록(없으면 빈 벡터)
*/
vector<Bicycle*> Rental::getRentalsByMember(string memberId) const {
    auto it = rental.find(memberId); // 회원 ID로 대여 목록 찾기
    if (it != rental.end()) {
        return it->second; // 해당 회원의 대여 목록 반환
    }
    return vector<Bicycle*>(); // 회원이 존재하지 않으면 빈 벡터 반환
}