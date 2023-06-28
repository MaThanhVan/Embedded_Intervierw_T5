#include <iostream>
#include <string>
#include <stdio.h>
#include <math.h>
#include <vector>

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
        void setID(uint8_t id);
        uint8_t getID();
        void setTen(string ten);
        string getTen();
        void setTuoi(uint8_t tuoi);
        uint8_t getTuoi();
        void setGioiTinh(GIOITINH gioitinh);
        GIOITINH getGioiTinh();
        void setdtoan(float dtoan);
        float getdToan();
        void setdLy(float dly);
        float getdLy();
        void setdHoa(float dhoa);
        float getdHoa();
        float getDiemTrungBinh();
        HOCLUC hocluc();
};

void SinhVien::setID(uint8_t id){
    static uint8_t id = 1;
    ID = id;
    id++;
    this->ID = id;
}

uint8_t SinhVien::getID(){
    return this->ID;
}

void  SinhVien::setTen(string ten){
    this->TEN = ten;
}

string SinhVien::getTen(){
    return this->TEN;
}
void SinhVien::setGioiTinh(GIOITINH gioitinh){
    this->gioiTinh = gioitinh;
}
GIOITINH SinhVien::getGioiTinh(){
    return this->gioiTinh;
}

void SinhVien::setTuoi(uint8_t tuoi){
    this->Tuoi = tuoi;
}
uint8_t SinhVien::getTuoi(){
    return this->Tuoi;
}

void SinhVien::setdToan(float dtoan){
    this->dToan = dtoan;
}
float SinhVien::getdToan(){
    return this->dToan;
}

void SinhVien::setdLy(float dly){
    this->dLy = dly;
}
float SinhVien::getdLy(){
    return this->dLy;
}

void SinhVien::setdHoa(float dhoa){
    this->getdHoa = dhoa;
}
float SinhVien::getdHoa(){
    return this->dHoa;
}

float SinhVien::getDiemTrungBinh(){
    return (this->dToan + this->dLy + this->dHoa) / 3;

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

class Menu
{
    private:
        vector <SinhVien> sinhvien;
    public:
        void ThemSinhVien(SinhVien sv);
        void CapNhatThongTin();
        void HienThi();
};

void Menu::ThemSinhVien(){
    string TEN;
    GIOITINH gioiTinh;
    uint8_t Tuoi;
    float dToan;
    float dLy;
    float dHoa;

    cout << "Hay nhap thong tin sinh vien:" <<endl;

    cout << "Nhap ten:";
    cin >> TEN;
    cout >> "Chon gioi tinh 1 Nam/ 2 Nu" << endl;
    cin >>  gioiTinh;
    if(gioiTinh == Nam)
    {
        GIOITINH = Nam
    }
    else if(gioiTinh == Nu){
        GIOITINH = Nu;
    }
    else{
        cout >> "gioi tinh khong xac dinh";
    }
    
    do
    {
        cout << "Nhap diem Toan =";
        cin>> dToan;
    } while ((dToan >= 0) || (dToan >= 10));
    
    do
    {
        cout << "Nhap diem Ly =";
        cin>> dLy;
    } while ((dLy >= 0) || (dLy >= 10));

    do
    {
        cout << "Nhap diem Hoa =";
        cin>> dHoa;
    } while ((dHoa >= 0) || (dHoa >= 10));

    SinhVien sv(TEN, Tuoi, gioiTinh, dToan, dLy, dHoa);
    Database.pop_back(sv);
}

void Menu::HienThi(){
    cout<<"ID\tTEN\tTUOI\tGIOITINH\tTOAN\tLY\tHOA\tDiemTB\tHOC_LUC\n";
    for (int i = 0; i < sinhvien.size(); i++){ 
        printf("%d\t", sinhvien[i].getID);
        cout << sinhvien[i].getTen() << "\t";
        cout << sinhvien[i].getTuoi() << "\t";
        cout << sinhvien[i].getGioiTinh() <<"\t";
        cout << sinhvien[i].getdToan() << "\t";
        cout << sinhvien[i].getdLy() << "\t";
        cout << sinhvien[i].getdHoa() << "\t";
        cout << sinhvien[i].DiemTrungBinh() << "\t";
        cout << sinhvien[i].hocluc() << "\t";
}
}
void Menu::CapNhatThongTin(){
    uint8_t id;

    // for (SinhVien item :: Database){
    //     if(item.getID() == id);

    //     break;
    // }
}
int main(int argc, char const *argv[])
{
    Menu sv;
    int chucnang;
    cout << "<<<CHON MENU>>>" << endl;
    cout << "1. Them Sinh vien" << endl;
    cout << "2. Hien thi Sinh Vien" << endl;

    switch (chucnang)
    {
    case 1:
        sv.ThemSinhVien();
        break;
    case 2:
        sv.HienThi();
        break;
    default:
        break;
    }
    return 0;
}
