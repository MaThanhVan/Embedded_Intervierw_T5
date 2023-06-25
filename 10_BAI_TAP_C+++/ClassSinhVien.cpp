#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string>
#include <vector>

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

class ClassSinhVien
{
    private:
       uint8_t ID;
       char TEN[50];
        GIOITINH gioiTinh;
        uint8_t Tuoi;
        double dToan;
        double dLy;
        double dHoa;
        double DiemTrungBinh;
        HOCLUC hocLuc;
    public:
        ClassSinhVien(char ten[], uint8_t tuoi, GIOITINH gioitinh ,double dToan, double dLy, double dHoa);
        
};


