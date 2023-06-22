/*
    TÍNH ĐA HÌNH
các method có tên giống nhau nhưng inputp parameter khác nhau
*/
#include <iostream>

class ToanHoc
{
private:
    /* data */
public:
    void tong(int a, int b);
    void tong(int a, int b, int c);
    void tong(int a, double b);
};

void ToanHoc::tong(int a, int b)
{
    printf("Tong a+b = %d\n", (a+b));
}

void ToanHoc::tong(int a, int b, int c)
{
    printf("Tong a+b+c = %d\n", (a+b+c));
}
void ToanHoc::tong(int a, double b)
{
    printf("Tong a+b = %.2f\n", ((double)a+b));
}

/*
        Khi code các hàm tương tư nhau, có fom giống nhau nhưng khác kiểu input đầu vào.
*/
//template<typename var>
template<typename var, typename varB>
var hieu(var a, varB b){
    return (var)(a-b);
}

int main(int argc, char const *argv[])
{
    ToanHoc toan;
    toan.tong(7,8);
    toan.tong(7, 8, 9);
    toan.tong(5, 5.2);

    printf("\nhieu a - b = %d", hieu(12, 6.2));

    return 0;
}

