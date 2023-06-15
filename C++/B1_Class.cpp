#include <iostream>
using namespace std;
class SinhVien{
   // private:		//chỉ có class truy cập đến các member trong private
    protected:      //giống private nhưng giúp các class con có thể truy cập vào các property bên trong
        int TUOI;		// day goi la property
        int LOP;
        string TEN;
    public:
        SinhVien(string ten = "van", int tuoi = 5, int lop = 1);    //Đây gọi là contuctor, nó sẽ chạy đầu tiên, có thể có tham số đầu vào
        void Nhap(int tuoi, int lop);
        void hienThi();	/* day goi la method, có thể viết chương trình trong method */
};
SinhVien::SinhVien(string ten, int tuoi, int lop){
    SinhVien::TEN = ten;
    SinhVien::TUOI = tuoi;
    SinhVien::LOP = lop;
}

void SinhVien::Nhap(int tuoi, int lop){
    SinhVien::TUOI = tuoi;
    SinhVien::LOP = lop;
}
void SinhVien::hienThi(){
    cout<<"ten "<<TEN<<endl;
    cout<<"tuoi "<<TUOI<<endl;
    cout<<"lop "<<LOP<<endl;
}

class DOITUONG : public SinhVien    //DOITUONG kế thừa public của class sinhviên
{
    private:
        int MSSV;
    public:
        void Nhap(string ten, int tuoi, int lop, int mssv);
        void hienThi();     // Sử dụng tính ghi đè, phải code lại
};

void DOITUONG::Nhap(string ten, int tuoi, int lop, int mssv)
{
    TEN = ten;
    TUOI = tuoi;
    LOP = lop;
    MSSV = mssv;
}
void DOITUONG::hienThi(){
    cout<<"ten "<<TEN<<endl;
    cout<<"tuoi "<<TUOI<<endl;
    cout<<"lop "<<LOP<<endl;
    cout<<"MSSV "<<MSSV<<endl;
}
int main()
{
    SinhVien sv, sv2; // Class SinhVen, object la sv và sv 2, có địa chỉ khác nhau, object chi truy cap den pham vi trong public.
    //sv.Nhap(12,6);
    
    sv.hienThi();
    DOITUONG DT1;
    DT1.Nhap("hoang", 15, 10, 1235);
    DT1.hienThi();
    return 0;
}