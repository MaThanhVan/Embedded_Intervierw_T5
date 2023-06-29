#include <stdint.h>
#include <stdio.h>
#include <math.h>


class Diem{
    private:
        int8_t ToaDoX;
        int8_t ToaDoY;
    public:
        Diem(int8_t toaDoX = 0, int8_t toaDoY = 0);
        double getToaDoX();
        double getToaDoY();
        

};

Diem::Diem(int8_t toaDoX, int8_t toaDoY){
   // Diem::getToaDoX == this->getToaDoX
   this->ToaDoX = toaDoX;
   Diem::ToaDoY = toaDoY;
}

double Diem::getToaDoX(){
    return this->ToaDoX;
}

double Diem::getToaDoY(){
    return this->ToaDoY;
}

class PhepToan
{
    private:
        /* data */
        Diem diemA;
        Diem diemB;
        Diem diemC;
        typedef enum{
            KHOANG_CACH,
            DIEN_TICH
        }CacPhepToan;
        CacPhepToan checkPhepToan;
    public:
        PhepToan(Diem diemA, Diem diemB);
        PhepToan(Diem diemA, Diem diemB, Diem diemC);
        double getKhoangCach();
        double getDienTich();
    
    };

PhepToan::PhepToan(Diem diemA, Diem diemB){
    this->diemA = diemA;
    this->diemB = diemB;
    this->checkPhepToan = KHOANG_CACH;
};
PhepToan::PhepToan(Diem diemA, Diem diemB, Diem diemC)
{
    this->diemA = diemA;
    this->diemB = diemB;
    this->diemC = diemC;
    this->checkPhepToan = DIEN_TICH;
};

double PhepToan::getKhoangCach(){
    if(this->checkPhepToan == KHOANG_CACH){
         
         return (double) (sqrt(pow(this->diemA.getToaDoX() - this->diemB.getToaDoX(),2) + pow(this->diemA.getToaDoY() - this->diemB.getToaDoY(),2)));
    }
    else{
        printf(".......");
    }
};

double PhepToan::getDienTich(){
    if(this->checkPhepToan  == DIEN_TICH){
        double x1 = (this->diemB.getToaDoX() - this->diemA.getToaDoX());
        double y1 = (this->diemB.getToaDoY() - this->diemA.getToaDoY());

        double x2 = (this->diemC.getToaDoX() - this->diemA.getToaDoX());
        double y2 = (this->diemC.getToaDoY() - this->diemA.getToaDoY());
        return (double) (0.5*(fabs(x1*y2 - x2*y1)));  
   }
}

int main(int argc, char const *argv[])
{
    Diem diemA(2.0,3.1);
    Diem diemB(1.2,8.6);
    PhepToan khoangcach( diemA,  diemB);
   // PhepToan PhepToan(Diem diemA, Diem diemB, Diem diemC);

   printf("Diem A(%.2f, %.2f)\n", diemA.getToaDoX(), diemA.getToaDoY() );
    printf("Diem B(%.2f, %.2f)\n", diemB.getToaDoX(), diemB.getToaDoY() );
    printf("khoang cach %.2f", khoangcach.getKhoangCach());
}

