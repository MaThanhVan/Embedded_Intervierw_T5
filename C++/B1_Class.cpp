#include <iostream>
using namespace std;
class SinhVien{
   // private:		//chỉ có class truy cập đến các member trong private
    protected:      //giống private nhưng giúp các class con có thể truy cập vào các property bên trong
        int TUOI;		// day goi la property
        int LOP;
        string TEN;
    public:
        SinhVien(string ten = "van", int tuoi = 5, int lop = 1);    //Đây gọi là contuctor, dùng để khoi tạo các thông số đầu tiên, nó sẽ chạy đầu tiên, có thể có tham số đầu vào
        void Nhap(int tuoi, int lop);
        void hienThi();	/* day goi la method, có thể viết chương trình trong method */
        uint8_t VarA;
        static uint8_t VarB;/// Static sẽ khởi tạo một lần và tồn tại suốt vòng đời của chương trình
};
SinhVien::SinhVien(string ten, int tuoi, int lop){
    SinhVien::TEN = ten;
    SinhVien::TUOI = tuoi;
    SinhVien::LOP = lop;
}

uint8_t SinhVien::VarB; //KHI DUNG static TA SẼ PHẢI KHỞI TẠO lần đầu,  và cũng có thể gán giá trị cho nó

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
    SinhVien sv1, sv2; // Class SinhVen, object la sv và sv 2, có địa chỉ khác nhau, object chi truy cap den pham vi trong public.
    //sv.Nhap(12,6);
    
    sv1.hienThi();
    DOITUONG DT1;
    DT1.Nhap("hoang", 15, 10, 1235);
    DT1.hienThi();

    sv1.VarA = 10;
    sv1.VarB = 20;
    sv2.VarA = 25;
    sv2.VarB = 30;
    printf("\nVarA.sv1 = %p, VarB.sv1 = %p", &sv1.VarA, &sv1.VarB );    // object khác nhau sẽ có địa chir khác nhau, và mỗi member chung object cũng có địa chỉ khác nhau
    printf("\nVarA.sv2 = %p, VarB.sv2 = %p", &sv2.VarA, &sv2.VarB );    // BIẾN STATIC SẼ CÓ MỘT ĐỊA CHỈ TỒN TẠI SUỐT VÒNG DỜI CỦA CHUONG TRÌNH
    return 0;
}