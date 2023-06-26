#include <iostream>
#include <string>
#include <stdio.h>
#include <math.h>
#include <list>

using namespace std;

typedef enum{
    Nam,
    Nu
}GIOITINH;

typedef enum{
    GIOI,
    KHA,
    TRUNGBINH,
    YEU
}HOCLUC;

class SinhVien
{
    private:
       uint8_t ID;
        string TEN;
        GIOITINH gioiTinh;
        uint8_t Tuoi;
        float dToan;
        float dLy;
        float dHoa;
        float DiemTrungBinh;
        HOCLUC hocLuc;
    public:
        SinhVien(uint8_t ID, string ten[], uint8_t tuoi, GIOITINH gioitinh ,float dToan, float dLy, float dHoa);
        uint8_t getID();
        string getTen();
        uint8_t getTuoi();
        float getdToan();
        float getdLy();
        float getdHoa();
        float DiemTrungBinh();
        HOCLUC hocluc();
};

class Menu
{
    private:
        list<SinhVien> Database;
    public:
        void ThemSinhVien();
        void CapNhatThongTin();
};

void Menu::ThemSinhVien(){
    string TEN;
    GIOITINH gioiTinh;
    uint8_t Tuoi;
    float dToan;
    float dLy;
    float dHoa;

    SinhVien sv();

    Database.pop_back(sv);
}

void Menu::CapNhatThongTin(){
    uint8_t id;

    for (SinhVien item :: Database){
        if(item.getID() == id);

        break;
    }
}


SinhVien::SinhVien(uint8_t ID, string ten[], uint8_t tuoi, GIOITINH gioitinh ,float dToan, float dLy, float dHoa){
    static uint8_t id = 1;
    ID = id;
    id++;
    this->TEN = ten;
    this->Tuoi = tuoi;
    this->gioiTinh = gioitinh;
    this->dToan = dToan;
    this->dLy = dLy;
    this->dHoa = dHoa;
}

uint8_t SinhVien::getID(){
    return this->ID;
}

string SinhVien::getTen(){
    return this->TEN;
}

uint8_t SinhVien::getTuoi(){
    return this->Tuoi;
}

float SinhVien::getdToan(){
    return this->dToan;
}

float SinhVien::getdLy(){
    return this->dLy;
}

float SinhVien::getdHoa(){
    return this->dHoa;
}

float SinhVien::DiemTrungBinh(){
    return (this->dToan + this->dLy + this->dHoa) / 4;

}

HOCLUC SinhVien::hocluc(){
    if(this->DiemTrungBinh() >= 8 ){
        return GIOI;
    }
    else if(this->DiemTrungBinh() >= 6.5){
        return KHA;
    }
    else if(this->DiemTrungBinh() >= 5){
        return TRUNGBINH;
    }
    else{
        return YEU;
    }
}
int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
