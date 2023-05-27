#include<stdio.h>
#include<stdint.h>

struct Data
{
	/*
            Struct và Union đều là kiểu dữ liêu người dùng tự định nghĩa
        Struct sẽ chiếm nhiều bộ nhớ lớn hơn Union, vùng nhớ struct sẽ được lưu vào vùng nhớ stack trên RAM
    Để tính bộ nhớ của struct ta dựa vào kiểu dữ liệu lớn nhất trong struct đó
    Vd dưới có kiểu u64 lớn nhất ==> mỗi lần quét là 64/8 = 8 Byte
    */ 
	uint8_t arr1[4];	// 1 lần 8 byte (4 lần quét 1byte, tổng chiếm 4bytes. một lần quét 8byte bộ nhớ ==> dư 3byte bộ nhớ đệm)
	uint16_t arr2[2];	// 0 lần quét (2 lần quết 2 byte, vừa đủ bộ nhớ đệm bên trên nên sẽ sd. Nếu không đủ sẽ tạo lần quét tiếp) 
	uint64_t arr3[4];	// 4 lần 8byte
	uint32_t arr4[3];	// 2 lần quét 8 byte(3 lần quét 4 byte, tốn 12 byte, CT sẽ quét 2 lần 8 byte, còn 4 byte trống được gọi là bộ nhớ đệm)
};

int main(){
	printf("%d Byte\n", sizeof(struct Data)); ///KQ == 56 Byte
	return 0;
}
st