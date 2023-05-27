#include <stdio.h>
#include <stdlib.h>

int n = 5;

int main() {

    // Sử dụng malloc để cấp phát bộ nhớ cho một mảng các số nguyên
    int* ptr = (int*)malloc(n * sizeof(int));
    if (ptr == NULL) {
        printf("Khong the cap phat bo nho");
        return 0;
    }
    printf("Gia tri sau khi su dung malloc:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", ptr[i]);
    }

    // Sử dụng calloc để cấp phát bộ nhớ cho một mảng các số nguyên với giá trị ban đầu là 0
    int* ptr2 = (int*)calloc(n, sizeof(int));
    if (ptr2 == NULL) {
        printf("khong the cap phat bo nho");
        return 0;
    }
    printf("\n\ngia tri sau khi su dung calloc:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", ptr2[i]);
    }

    // Sử dụng realloc để thay đổi kích thước của mảng đã cấp phát từ 5 thành 10 phần tử kiểu int
    ptr = (int*)realloc(ptr, 10 * sizeof(int));
    if (ptr == NULL) {
        printf("khong cap phat bo nho.");
        return 0;
    }
    printf("\n\ngia tri su dung cua realloc:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", ptr[i]);
    }

    // Giải phóng bộ nhớ đã cấp phát
    free(ptr);
    free(ptr2);

    return 0;
}
