#include <stdint.h>
#include <stdio.h>
#include <math.h>

using namespace std;

class Rectangle
{
private:
    /* data */
    double cDai;
    double cRong;
public:
    Rectangle(double cDai = 0, double cRong = 0);
    double Dai();
    double Rong();

    double caculateAcreage();
    double caulatePerimeter();
    double caculateDiagonalLine();
    void getcheckRectangele();
};

Rectangle::Rectangle(double Dai, double Rong )
{
    if(cDai <= 0 || cRong <= 0){
        printf("Ban da nhap sai hay nhap lai ");
        return;
    }
    else{
        this->cDai = Dai;
        this->cRong = Rong;
    }

}

double Rectangle::Dai(){
    return this->cDai;
}

double Rectangle::Rong(){
    return this->cRong;
}

double Rectangle::caculateAcreage(){
    return (double) (this->cDai * this->cRong);
}

double Rectangle::caulatePerimeter(){
    return (double) ((this->cDai + this->cRong)/2);
}

double Rectangle::caculateDiagonalLine(){
    return (double) (sqrt(pow(this->cDai,2) + pow(this->cRong,2)));
}

void Rectangle::getcheckRectangele(){
    if(this->cDai == this->cRong){
        printf("Day khong phai la hinh chu nhat");
        return;
    }
    if(this->cDai < this->cRong){
        printf("Day khong phai la hinh chu nhat");
        return;
    }
    else{
        printf("day la hinh chu nhat");
        return;
    }
}
int main()
{
    
    Rectangle Tinhtoan(8, 4);

    printf("cDai = %.2f", Tinhtoan.Dai());
    printf("cRong = %.2f\n", Tinhtoan.Rong());
    
    printf("Dien tich = %.2f\n", Tinhtoan.caculateAcreage());

    printf("Chu vi = %.2f\n", Tinhtoan.caulatePerimeter());

    printf("Duong cheo = %.2f\n", Tinhtoan.caculateDiagonalLine());

    Tinhtoan.getcheckRectangele();
    
}

