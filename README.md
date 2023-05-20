# B1 Quá Trình Biên Dịch
## **Quá trình biên dịch bao gồm 4 giai đoạn:**

- **_Pre-processor (Giai đoạn tiền xử lý):_** Xóa bỏ các dòng comments, xử lý các chỉ thị tiền xử lý có bắt đầu bằng kí hiệu `#`. Như `#include` (thay thế mã chương trình của một tệp tiêu để vào mã nguồn cần dịch), `#define` (thay thế bằng giá trị cụ thể vào các biến được gọi).
  -  Sau khi qua quá trình tiền xử lý thì file code lúc này sẽ có dạng `.i`.
  -  Dùng lệnh `gcc -E filename.c -o filename.i` hoặc `gcc -E filename.c` để xem code sau khi qua quá trình preprocessor.
- **_Compiler (Giai đoạn dịch sang ngôn ngữ Assembly):_** Kiểm tra các kiểu dữ liệu có lỗi hay không, phân tích cú pháp (syntax) và tối ưu code.
  -  Quá trình này sẽ biên dịch từ code `.i` sang ngôn ngữ assembly code `.s`.
  -  Dùng lệnh `gcc -S -o filename.s filename.c` để có thể xem code sau quá tình compiler.
- **_Assembler (Giai đoạn dịch sang ngôn ngữ máy):_** Biên dịch ngôn ngữ Assembly code sang ngôn ngữ máy (0 và 1). Và tạo ra tệp tin Object `.o`.
  -  Dùng lệnh `gcc -c filename.c -o filename.o` để tạo ra file ".o" và dùng lệnh `objdump -d -Mintel filename.o` để xem code.
- **_Linker (Giải đoạn liên kết):_** Là giai đoạn cuối cùng. Trong giai đoạn này mã máy của một chương trình `.o` dịch từ nhiều nguồn (file .c hoặc file thư viện .lib) được liên kết lại với nhau để tạo thành chương trình duy nhất
  - File sau khi được gộp lại thì sẽ có đuôi mở rộng Executable `.exe`, còn trên Linux và MacOs thì có thể có đuối theo chỉ định hoặc không có đuôi mở rộng.

- Để chạy file code C trên `terminal linux` dùng lệnh `gcc -o filename filename.c` đẻ tạo ra tệp thực thi, sau đó dùng lệnh `./filename` để chạy tệp thực thi đó.


## **Phân vùng bộ nhớ trên RAM, cấp phát bộ nhớ động**

- ***Text:*** Quyền truy cập chỉ có thể Read
	- Chứa khai báo các hằng số(.rodata)
	- Nó chưa lệnh thực thị nên tránh sửa đổi instruction
- ***Data:*** Quyền truy cập Read-Write
	- Chứa biến toàn cục hoặc biến static: Có giá trị khởi tạo khác 0
	- Được giải phóng khi kết thúc chương trình
- ***Bss:*** Quyền truy cập Read-Write
	- Chứa biến toàn cục hoặc các biến static: Có giá trị khởi tạo bằng 0 hoặc không khởi tạo
	- Được giải phóng khi kết thúc chương trình
- ***Stack:*** Quyền truy cập là Read-Write.
	- Được sử dụng cấp phát cho biến local, input parameter của hàm,...
	- Sẽ được giải phóng khi ra khỏi block code/hàm
- ***Heap:*** Quyền truy cập là Read-Write.
	- Được sử dụng để cấp phát bộ nhớ động như: Malloc, Calloc,...
	- Sẽ được giải phóng khi gọi hàm free,...
# B2 THAO TÁC BIT
## **AND:** x=y & z;
![image](https://github.com/MaThanhVan/Embedded_Intervierw_T5/assets/119687191/21bf003d-e9c8-4536-a05e-d94fb34df11b)
![image](https://github.com/MaThanhVan/Embedded_Intervierw_T5/assets/119687191/0b9a1154-2070-471b-a158-ce496e916d80)
## **NOT:** x=~y;
![image](https://github.com/MaThanhVan/Embedded_Intervierw_T5/assets/119687191/7dcfee9e-3ac0-47d7-932c-d0b1c0e99c16)
![image](https://github.com/MaThanhVan/Embedded_Intervierw_T5/assets/119687191/a3aba9b8-a46a-4a59-9407-135d22a8bcc6)
## **OR:** x=y | z;
![image](https://github.com/MaThanhVan/Embedded_Intervierw_T5/assets/119687191/6df28a9a-6518-4481-b52a-32614e15b9c8)
![image](https://github.com/MaThanhVan/Embedded_Intervierw_T5/assets/119687191/f370c912-3b8b-49d6-bbec-236c4ebe23e5)
## **XOR: x = y ^ z;
![image](https://github.com/MaThanhVan/Embedded_Intervierw_T5/assets/119687191/9ba37c61-a5ed-4b6b-a566-b853a02edc0c)
![image](https://github.com/MaThanhVan/Embedded_Intervierw_T5/assets/119687191/964b9a8f-ad3f-45ee-8f7a-f443c02501ce)

## **Dịch Bit: >> (Dịch phải) và << ( Dịch trái )
![image](https://github.com/MaThanhVan/Embedded_Intervierw_T5/assets/119687191/affb5af4-cca3-4a19-ad49-ac2c458fad57)

# B3 STRUCT and UNION
STRUCT và UNION là kiểu dữ liệu người dùng tự định nghĩa
## **Từng phần tử của STRUCT sẽ có địa chỉ riêng, có thể dùng nhiều biến trong Struct cùng lúc**
### **Struct khi chạy được lưu vào bộ nhớ Stack trên RAM** 
	
struct Exam{
  uint8_t X1[10]; // Mất 2 lần quét tạo ra 2 lần 8 byte, 8 byte cuối lần 2 sẽ dư ra 6 byte gọi là bộ nhớ đệm
  uint64_t X2[5]; // Bộ nhớ Đệm không nhỏ hơn lần quét tiếp cần có thì sẽ tạo ra 8 byte mới, nếu nhỏ hơn hoặc bẳng sẽ dùng bô nhớ Đệm.
  uint32_t X3[6]; // Kiểu u32 lỗi lần quét mất 4 byte, đây cần tạo 3 lần 8 byte
};
/* Bộ nhớ mỗi lần quét sẽ được tính theo kiểu dữ liệu lớn nhất trong struct. Như trên mỗi lần quét là 8 byte 
 Cách tính Bộ Nhớ 

