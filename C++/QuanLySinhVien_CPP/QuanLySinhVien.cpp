/*
* File: QuanLySinhVien.cpp
* Author: Ma Thanh Van
* Date: 26/06/2023
* Description: This is file for student management
*/

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

/*------------------------------------------Class Student--------------------------------------*/
class SinhVien
{
    protected:
       uint8_t ID;
        string TEN;
        GIOITINH gioiTinh;
        int Tuoi;
        float dToan;
        float dLy;
        float dHoa;
        float DiemTrungBinh;
        HOCLUC hocLuc;
    public:
        void setID();
        uint8_t getID();
        void setTen(string ten);
        string getTen();
        void setTuoi(uint8_t tuoi);
        int getTuoi();
        void setGioiTinh(GIOITINH gioitinh);
        GIOITINH getGioiTinh();
        void setdtoan(float dtoan);
        float getdToan();
        void setdLy(float dly);
        float getdLy();
        void setdHoa(float dhoa);
        float getdHoa();
        float getDiemTrungBinh();
        HOCLUC gethocluc();
        
};

/*
* Class: Student
* Function: setID
* Description: This function use for set ID of a Student
* Input:
*    ID  Student
* Output:
*   return: None
*/
void SinhVien::setID(){
    static uint8_t id = 0;
    ID = id;
    id++;
    this->ID = id;
}

/*
* Class: Student
* Function: getID
* Description: This function use for get ID of a Student
* Input:
*    Don't have input parameters
* Output:
*   return: ID Student
*/
uint8_t SinhVien::getID(){
    return this->ID;
}

/*
* Class: Student
* Function: setTen
* Description: This function use for set name of a Student
* Input:
*   name of Student
* Output:
*   return: None
*/
void  SinhVien::setTen(string ten){
    this->TEN = ten;
}

/*
* Class: Student
* Function: getTen
* Description: This function use for get Name of a Student
* Input:
*    Don't have input parameters
* Output:
*   return: Name Student
*/
string SinhVien::getTen(){
    return this->TEN;
}

/*
* Class: Student
* Function: setGioiTinh
* Description: This function use for set Sex of a Student
* Input:
*   Sex of Student
* Output:
*   return: None
*/
void SinhVien::setGioiTinh(GIOITINH gioitinh){
    this->gioiTinh = gioitinh;
}

/*
* Class: Student
* Function: getGioiTinh
* Description: This function use for get Sex of a Student
* Input:
*    Don't have input parameters
* Output:
*   return: Sex Student
*/
GIOITINH SinhVien::getGioiTinh(){
    return this->gioiTinh;
}

/*
* Class: Student
* Function: setTuoi
* Description: This function use for set Age of a Student
* Input:
*   Age of Student
* Output:
*   return: None
*/
void SinhVien::setTuoi(uint8_t tuoi){
    this->Tuoi = tuoi;
}

/*
* Class: Student
* Function: getTuoi
* Description: This function use for get Age of a Student
* Input:
*    Don't have input parameters
* Output:
*   return: Age Student
*/
int SinhVien::getTuoi(){
    return this->Tuoi;
}


/*
* Class: Student
* Function: setdtoan
* Description: This function use for set mark of Math
* Input:
*   mark of Math
* Output:
*   return: None
*/
void SinhVien::setdtoan(float dtoan){
    this->dToan = dtoan;
}

/*
* Class: Student
* Function: getdToan
* Description: This function use for get mark of a Math
* Input:
*    Don't have input parameters
* Output:
*   return: mark of Math
*/
float SinhVien::getdToan(){
    return this->dToan;
}

/*
* Class: Student
* Function: setdly
* Description: This function use for set mark of Physical
* Input:
*   mark of Physical
* Output:
*   return: None
*/
void SinhVien::setdLy(float dly){
    this->dLy = dly;
}

/*
* Class: Student
* Function: getdLy
* Description: This function use for get mark of a Physical
* Input:
*    Don't have input parameters
* Output:
*   return: mark of Physical
*/
float SinhVien::getdLy(){
    return this->dLy;
}

/*
* Class: Student
* Function: setdtoan
* Description: This function use for set mark of Chemical
* Input:
*   mark of Chemical
* Output:
*   return: None
*/
void SinhVien::setdHoa(float dhoa){
    this->dHoa = dhoa;
}

/*
* Class: Student
* Function: getdHoa
* Description: This function use for get mark of a Chemical
* Input:
*    Don't have input parameters
* Output:
*   return: mark of Chemical
*/
float SinhVien::getdHoa(){
    return this->dHoa;
}

/*
* Class: Student
* Function: getDiemTrungBinh
* Description: This function use for get GPA of Student
* Input:
*    Don't have input parameters
* Output:
*   return: GPA of Student
*/
float SinhVien::getDiemTrungBinh(){
    
    return this->DiemTrungBinh = (this->dToan + this->dLy + this->dHoa) / 3;
}

/*
* Class: Student
* Function: gethocluc
* Description: This function use for get classification of Student
* Input:
*    Don't have input parameters
* Output:
*   return: classification of Student
*/
HOCLUC SinhVien::gethocluc(){
    if(this->getDiemTrungBinh() >= 8 ){
        return this->hocLuc =  GIOI;
    }
    else if(this->getDiemTrungBinh() >= 6.5){
        return this->hocLuc = KHA;
    }
    else if(this->getDiemTrungBinh() >= 5){
        return this->hocLuc = TRUNGBINH;
    }
    else if(this->getDiemTrungBinh() < 5){
        return this->hocLuc = YEU;
    }
}

/*-----------------------------------Class Menu-----------------------------*/


class Menu
{
    private:
        vector <SinhVien> sinhvien;
    public:
        void ThemSinhVien();
        void CapNhatThongTinBoiID();
        void HienThi();
        void XoaSinhVienBoiID();
        void TimSinhVienTheoTen();
        void SapXepTheoDiemTB();
        void SapXepTheoTen();
        
};

/*
* Class: Menu
* Function: add Student
* Description: This function use for adding student
* Input:
*   Dont have input parameters
* Output:
*   return: none
*/
void Menu::ThemSinhVien(){
    string ten;
    GIOITINH gioiTinh;
    int tuoi;
    float Toan;
    float Ly;
    float Hoa;
    SinhVien sv;
    int gt;
    cout << "HAY NHAP THONG TIN SINH VIEN:" <<endl;

    cout << "Nhap ten:";
    cin >> ten;
    sv.setTen(ten);

    cout << "Nhap Tuoi = "; 
    cin>>tuoi;
    sv.setTuoi(tuoi);
    fflush(stdin);

    cout << "Chon gioi tinh  1 Nam/ 2 Nu" << endl;
    cin >> gt;
    if(gt == 1)
    {
        gioiTinh = Nam;
    }
    else if(gt == 2){
        gioiTinh = Nu;
    }
    sv.setGioiTinh(gioiTinh);

   do
   {
        cout << "Nhap diem Toan = "; 
        cin >> Toan;
        sv.setdtoan(Toan);
   } while ((sv.getdToan() < 0) || (sv.getdToan() > 10));
    sv.setdtoan(Toan);

    do
    {
        cout << "Nhap diem Ly = ";
        cin>> Ly;
        
    } while ((Ly < 0) || (Ly > 10));
    sv.setdLy(Ly);

    do
    {
        cout << "Nhap diem Hoa = ";
        cin>> Hoa;
        
    } while ((Hoa < 0) || (Hoa > 10));

    sv.setdHoa(Hoa);
    sv.setID();
    sv.getDiemTrungBinh();
    sv.gethocluc();
    Menu::sinhvien.push_back(sv);
    
}

/*
* Class: Menu
* Function: update information
* Description: This function use for update information by ID
* Input:
*   Dont have input parameters
* Output:
*   return: none
*/
void Menu::CapNhatThongTinBoiID(){
    int id_sv;
    int stt, gt;
    string ten;
    GIOITINH gioiTinh;
    int tuoi;
    float Toan;
    float Ly;
    float Hoa;
    

    if(sinhvien.empty()) cout << "is emty\n";

    cout << "Hay nhap ID cua sinh vien ban muon thay doi = "; 
        scanf("%d", &id_sv);
        

    for(SinhVien item : sinhvien )
    {
        printf("id sv-- %d\n", item.getID());
        if(item.getID() == id_sv ){
        
            cout << "Da tim thay thong tin Sinh Vien co id " << id_sv;
            cout << "BAN MUON CAP NHAT THONG TIN NAO" << endl;
            cout << "1. Cap nhat TEN" << endl;
            cout << "2. Cap nhat TUOI" << endl;
            cout << "3. Cap nhat GIOI TINH" << endl;
            cout << "4. Cap nhat diem TOAN" << endl;
            cout << "5. Cap nhat diem LY" << endl;
            cout << "6. Cap nhat diem HOA" << endl;
            cout << "0. Thoat chuong trinh" << endl;
            cout << "ban chon chuc nang so " << endl;
            cin >> stt;

            switch (stt)
            {
                exit(0);

                case 1:
                    
                    cout << "Nhap TEN moi "; 
                    cin >> ten;;
                    sinhvien.at(id_sv - 1).setTen(ten); // at(1) nhu la ar[i], phai - di mot vi vi tri dau tien cua vector la 0

                    break;

                case 2:
                    cout << "Nhap TUOI moi "; cin >> tuoi;
                    sinhvien.at(id_sv - 1).setTuoi(tuoi);
                    break;

                case 3:
                    cout << "Nhap GIOI TINH moi 1 Nam/ 2 Nu "; cin >> gt;
                    cin >> gt;
                    if(gt == 1)
                    {
                        gioiTinh = Nam;
                    }
                    else if(gt == 2){
                        gioiTinh = Nu;
                    }
                    
                    sinhvien.at(id_sv - 1).setGioiTinh(gioiTinh);
                    break;

                case 4:
                    do
                    {
                        cout << "Nhap diem Toan  moi = ";
                        cin>> Toan;
                        
                    } while ((Toan < 0) || (Toan > 10));

                    sinhvien.at(id_sv-1).setdtoan(Toan); 
                    break;  

                case 5:
                    do
                    {
                        cout << "Nhap diem Ly  moi = ";
                        cin>> Ly;
                        
                    } while ((Ly < 0) || (Ly > 10));

                    sinhvien.at(id_sv-1).setdLy(Ly); 
                    break;  

                case 6:
                    do
                    {
                        cout << "Nhap diem Hoa moi = ";
                        cin>> Hoa;
                        
                    } while ((Hoa < 0) || (Hoa > 10));

                    sinhvien.at(id_sv-1).setdHoa(Hoa); 
                    break;

                default:
                    cout << "ban da nhap sai hay nhap lai"<< endl;
                break;
                
            }        
         }
         else{
            cout << "Khong tim thay SInh Vien co Id " << id_sv << endl;  
         }
    }   

}

/*
* Class: Menu
* Function: delete information student
* Description: This function use for delete information student by ID
* Input:
*   Dont have input parameters
* Output:
*   return: none
*/
void Menu::XoaSinhVienBoiID(){
    int id_sv;
    cout << "3. Xoa Sinh Vien Boi ID" << endl;

    if(sinhvien.empty()) cout << "is emty\n";

    cout << "Hay nhap ID cua sinh vien ban muon thay doi = "; 
    scanf("%d", &id_sv);
        
    for(SinhVien item : sinhvien ){
        if(item.getID()  == id_sv){
            sinhvien.erase(sinhvien.begin() + id_sv);
            cout << "Sinh vien co ID = " << id_sv << "da duoc xoa" << endl;
            break;
        }
        else{
            cout << "Khong tim thay SInh Vien co Id " << id_sv << endl;  
        }
    }
    
}    

/*
* Class: Menu
* Function: find information student
* Description: This function use for find information student by Name
* Input:
*   Dont have input parameters
* Output:
*   return: none
*/
void Menu::TimSinhVienTheoTen(){
    string ten_tim_kiem;
    cout << "4. Xoa Sinh Vien Boi ID" << endl;

    if(sinhvien.empty()) cout << "is emty\n";

    cout << "Hay nhap ID cua sinh vien ban muon thay doi = "; 
    cin >> ten_tim_kiem;
        
    for(SinhVien item : sinhvien ){
        if(item.getTen()  == ten_tim_kiem){
            cout << "DA TIM THAY THONG TIN SINH VIEN CO TEN " << ten_tim_kiem << endl;
            cout<<"ID\tTEN\tTUOI\tGIOITINH\tTOAN\tLY\tHOA\tDiemTB\tHOC_LUC\n";
            printf("\n%d\t", item.getID());
            cout << item.getTen() << "\t";
            cout << item.getTuoi() << "\t";
            if (item.getGioiTinh() == Nam) {
                cout << "Nam" <<"\t\t";
            }
            else{
                cout << "Nu" <<"\t\t";
            } 
            cout << item.getdToan() << "\t";
            cout << item.getdLy() << "\t";
            cout << item.getdHoa() << "\t";
            cout << item.getDiemTrungBinh() << "\t";
            
            if(item.gethocluc() == GIOI){
                cout << "Gioi" <<"\t";
            }
            else if(item.gethocluc() == KHA){
                cout << "Kha" <<"\t";
            }
            else if(item.gethocluc() == TRUNGBINH){
                cout << "Trung Binh" <<"\t";
            }
            else if(item.gethocluc() == YEU){
                cout << "Yeu" <<"\t" << endl;
            }
        }
        else{
            cout << "Khong tim thay SInh Vien co Id " << ten_tim_kiem << endl;  
        }
    }
}

/*
* Class: Menu
* Function: arrange list student
* Description: This function use for to arrange list student by GPA
* Input:
*   Dont have input parameters
* Output:
*   return: none
*/
void Menu::SapXepTheoDiemTB(){
    SinhVien sv;
    
     if(sinhvien.empty()) cout << "is emty\n";

    for(int i = 0; i < sinhvien.size(); i++){
        for (int j = i + 1; j < sinhvien.size(); j++)
        {
            if(sinhvien[i].getDiemTrungBinh() > sinhvien[j].getDiemTrungBinh()){
                sv = sinhvien[i];
                sinhvien[i] = sinhvien[j];
                sinhvien[j] = sv;
            }
        }
        
    }
    cout << "Sap xep Sinh Vien theo diem Trung Binh tang dan" << endl;
    Menu::HienThi();
}


/*
* Class: Menu
* Function: arrange list student
* Description: This function use for to arrange list student by Name
* Input:
*   Dont have input parameters
* Output:
*   return: none
*/
void Menu::SapXepTheoTen(){
    SinhVien sv;
    
    if(sinhvien.empty()) cout << "is emty\n";

    for(int i = 0; i < sinhvien.size(); i++){
        for (int j = i + 1; j < sinhvien.size(); j++)
        {
            if(sinhvien[i].getTen() > sinhvien[j].getTen()){
                sv = sinhvien[i];
                sinhvien[i] = sinhvien[j];
                sinhvien[j] = sv;
            }
        }
        
    }
    cout << "Sap xep Sinh Vien theo Ten" << endl;
    Menu::HienThi();
}

/*
* Class: Menu
* Function: show List Student
* Description: This function use for showing list Student
* Input:
*   Dont have input parameters
* Output:
*   return: none
*/
void Menu::HienThi(){
    cout<<"ID\tTEN\tTUOI\tGIOITINH\tTOAN\tLY\tHOA\tDiemTB\tHOC_LUC\n";
    for (int i = 0; i < sinhvien.size(); i++){ 
        printf("\n%d\t", sinhvien[i].getID());
        cout << sinhvien[i].getTen() << "\t";
        cout << sinhvien[i].getTuoi() << "\t";
        if (sinhvien[i].getGioiTinh() == Nam) {
            cout << "Nam" <<"\t\t";
        }
        else{
            cout << "Nu" <<"\t\t";
        } 
        cout << sinhvien[i].getdToan() << "\t";
        cout << sinhvien[i].getdLy() << "\t";
        cout << sinhvien[i].getdHoa() << "\t";
        cout << sinhvien[i].getDiemTrungBinh() << "\t";
        
        if(sinhvien[i].gethocluc() == GIOI){
            cout << "Gioi" <<"\t";
        }
        else if(sinhvien[i].gethocluc() == KHA){
            cout << "Kha" <<"\t";
        }
        else if(sinhvien[i].gethocluc() == TRUNGBINH){
            cout << "Trung Binh" <<"\t";
        }
        else if(sinhvien[i].gethocluc() == YEU){
            cout << "Yeu" <<"\t" << endl;
        }
    }
}


int main(int argc, char const *argv[])
{
    Menu sv;
    
        int chucnang;
        dauCT:
            cout << "<<<CHON MENU>>>" << endl;
            cout << "1. Them Sinh vien" << endl;
            cout << "2. Cap nhat sinh vien boi ID" << endl;
            cout << "3. Xoa Sinh Vien boi ID" << endl;
            cout << "4. Tim kiem Sinh Vien theo ten" << endl;
            cout << "5. Xap xep Sinh Vien theo diem trung binh" << endl;
            cout << "6. Xap xep Sinh Vien theo ten" << endl;
            cout << "7. Hien thi Sinh Vien" << endl;
            cout << "0. Thoat chuong trinh" << endl;
            cin >> chucnang;
            
            switch (chucnang)
            {
            case 1:
                sv.ThemSinhVien();
                goto dauCT;

            case 2:
                sv.CapNhatThongTinBoiID();
                goto dauCT;   

            case 3:
                sv.XoaSinhVienBoiID();
                goto dauCT; 

            case 4:
                sv.TimSinhVienTheoTen();
                goto dauCT; 
            
            case 5:
                sv.SapXepTheoDiemTB();
                goto dauCT;
            
            case 6:
                sv.SapXepTheoTen();
                goto dauCT;

            case 7:
                sv.HienThi();
                goto dauCT;

            case 0:
                break;

            default:
                cout << "ban da nhap sai hay nhap lai" << endl;
                goto dauCT;
            }

    return 0;
}
