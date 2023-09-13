#include <stdio.h>

/*/////////////////////////////////Macro, dien ra o Tien xu ly: thay the doan dinh nghia code define vao phan minh goi ///////////////////
 Toc do xu ly cua macro chay se nhanh hon funtion vi ham function se co buoc luu dia chi tiep theo vao stack pointer, macro se chay liene tuc. Nhung macro se mat nhieu bo nho hon */
#define MAX 10
#define SUM(a,b) a+b

#define CREATE_FUNC(ten_ham, noi_dung)          \
    void ten_ham(){                             \
        printf("%s\n", noi_dung);               \

    }

CREATE_FUNC(test, "this is test");
//////////////////// Khi CT dung macro nhieu lan size no se lon

#define sum_macro(a, b) ((a) + (b))
// do trình biên dịch này không hỗ trợ từ khóa inline nên ta thêm static vào.
static inline int sum_inline(int a, int b) {
    return a + b;
}

int sum_function(int a, int b) {
    return a + b;
}
inline void test(int a, int b){
		return a+b;
	}//0xc4 0xc5 mã máy, vdk sẽ hiểu

int main() {
    int num1 = 5;
    int num2 = 10;
    
    printf("MAX = %d\n", MAX);          // Cho nao co MAX thay the vao = 10
    
    printf("Tong a va b = %d\n", SUM(4,7));
    
    test();     // Tao ra mot ham test

    // Sử dụng Macro
    int result_macro = sum_macro(num1, num2);
    printf("sum of macro: %d\n", result_macro);
    
    // Sử dụng inline function
    int result_inline = sum_inline(num1, num2);
    printf("sum of inline: %d\n", result_inline);
    
    // Sử dụng function
    int result_function = sum_function(num1, num2);
    printf("sum of function: %d\n", result_function);
    
    return 0;
}