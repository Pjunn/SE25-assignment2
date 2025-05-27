// 헤더 선언
#include <fstream>

#include "MemberCollection.h"
#include "CurrentMember.h"
#include "Register.h"
#include "RegisterUI.h"
#include "Login.h"
#include "LoginUI.h"
#include "Logout.h"
#include "LogoutUI.h"
#include "BicycleCollection.h"
#include "AddBicycle.h"
#include "AddBicycleUI.h"
#include "Rental.h"
#include "RentalBicycle.h"
#include "RentalBicycleUI.h"
#include "CheckBicycleRental.h"
#include "CheckBicycleRentalUI.h"
#include "Exit.h"
#include "ExitUI.h"
using namespace std;

// 상수 선언
#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"

/*
    함수 이름 : doTask
    기능     : 프로그램의 주요 로직을 수행하며, 각 메뉴에 따라 적절한 컨트롤러와 UI를 호출함
    전달 인자 : ifstream& in_fp  - 입력 파일 스트림 참조
               ofstream& out_fp - 출력 파일 스트림 참조
    반환값   : 없음
*/
void doTask(ifstream& in_fp, ofstream& out_fp);

/*
    함수 이름 : main
    기능     : 입출력 파일을 열고 doTask를 호출하여 프로그램을 실행함
    전달 인자 : 없음
    반환값   : int - 프로그램 종료 코드
*/
int main() {
    ifstream in_fp(INPUT_FILE_NAME);
    ofstream out_fp(OUTPUT_FILE_NAME);

    doTask(in_fp, out_fp);
    
    in_fp.close();
    out_fp.close();
    
    return 0;
}  

/*
    함수 이름 : doTask
    기능     : 입력 파일에서 메뉴 정보를 읽어 각 기능(회원가입, 로그인, 로그아웃, 자전거 등록, 대여, 대여 리스트, 종료)을 수행함
    전달 인자 : ifstream& in_fp  - 입력 파일 스트림 참조
               ofstream& out_fp - 출력 파일 스트림 참조
    반환값   : 없음
*/
void doTask(ifstream& in_fp, ofstream& out_fp) {
    // 메뉴 파싱을 위한 level 구분을 위한 변수
    int menu_level_1 = 0, menu_level_2 = 0;
    int is_program_exit = 0;
    // 엔티티 객체 생성
    MemberCollection* memberCollection = new MemberCollection();
    CurrentMember* currentMember = new CurrentMember();
    BicycleCollection* bicycleCollection = new BicycleCollection();
    Rental* rental = new Rental();
    // 컨트롤러 객체 생성
    Register* registerControl = new Register(memberCollection, in_fp, out_fp);
    Login* loginControl = new Login(currentMember, memberCollection, in_fp, out_fp);
    Logout* logoutControl = new Logout(currentMember, in_fp, out_fp);
    AddBicycle* addBicycleControl = new AddBicycle(bicycleCollection, in_fp, out_fp);
    RentalBicycle* rentalBicycleControl = new RentalBicycle(bicycleCollection, currentMember, rental, in_fp, out_fp);
    CheckBicycleRental* checkBicycleRentalControl = new CheckBicycleRental(in_fp, out_fp, currentMember, rental);
    Exit* exitControl = new Exit(in_fp, out_fp);

    while(!is_program_exit) {
        in_fp >> menu_level_1 >> menu_level_2;

        switch(menu_level_1) {
            case 1: {
                switch(menu_level_2) {
                    case 1: {
                        // 회원 가입
                        registerControl->getRegisterUI()->startInterface(registerControl);
                        registerControl->getRegisterUI()->createNewMember();
                        out_fp << endl;
                        break;
                    }
                }
                break;
            }
            case 2: {
                switch(menu_level_2) {
                    case 1: {
                        // 로그인
                        loginControl->getLoginUI()->startInterface(loginControl);
                        loginControl->getLoginUI()->login();
                        out_fp << endl;
                        break;
                    }
                    case 2: {
                        // 로그아웃
                        logoutControl->getLogoutUI()->startInterface(logoutControl);
                        logoutControl->getLogoutUI()->logout();
                        out_fp << endl;
                        break;
                    }
                }
                break;
            }
            case 3: {
                switch(menu_level_2) {
                    case 1: {
                        // 자전거 등록
                        addBicycleControl->getAddBicycleUI()->startInterface(addBicycleControl);
                        addBicycleControl->getAddBicycleUI()->createBicycle();
                        out_fp << endl;
                        break;
                    }
                }
                break;
            }
            case 4: {
                switch(menu_level_2) {
                    case 1: {
                        // 자전거 대여
                        rentalBicycleControl->getRentalBicycleUI()->startInterface(rentalBicycleControl);
                        rentalBicycleControl->getRentalBicycleUI()->rentBicycle();
                        out_fp << endl;
                        break;
                    }
                }
                break;
            }
            case 5: {
                switch(menu_level_2) {
                    case 1: {
                        // 자전거 대여 리스트
                        checkBicycleRentalControl->getCheckBicycleRentalUI()->startInterface(checkBicycleRentalControl);
                        checkBicycleRentalControl->getCheckBicycleRentalUI()->checkRental();
                        out_fp << endl;
                        break;
                    }
                }
                break;
            }
            case 6: {
                switch(menu_level_2) {
                    case 1: {
                        // 프로그램 종료
                        exitControl->getExitUI()->startInterface(exitControl);
                        exitControl->getExitUI()->exitProgram();
                        is_program_exit = 1;
                        break;
                    }
                }
                break;
            }
        }            
    }
}
