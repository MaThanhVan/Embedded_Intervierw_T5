<details>
  <summary><h2>▶ B1 Quá trình biên dịch</h2></summary>

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
	### So sánh Stack và Heap?
	- Bộ nhớ: Bộ nhớ Heap và bộ nhớ Stack bản chất đều cùng là vùng nhớ được tạo ra và lưu trữ trong RAM khi chương trình được thực thi.
		- Stack được dùng để lưu trữ các biến cục bộ trong hàm, tham số truyền vào... Truy cập vào bộ nhớ này rất nhanh và được thực thi khi chương trình được biên dịch.
		- Heap được dùng để lưu trữ vùng nhớ cho những biến con trỏ được cấp phát động bởi các hàm malloc - calloc - realloc (trong C)
	- Kích thước vùng nhớ:
		- Stack: kích thước của bộ nhớ Stack là cố định, tùy thuộc vào từng hệ điều hành, ví dụ hệ điều hành Windows là 1 MB, hệ điều hành Linux là 8 MB (lưu ý là con số có thể khác tùy thuộc vào kiến trúc hệ điều hành của bạn).
		- Heap: kích thước của bộ nhớ Heap là không cố định, có thể tăng giảm do đó đáp ứng được nhu cầu lưu trữ dữ liệu của chương trình.
	- Đặc điểm vùng nhớ
		- Stack: vùng nhớ Stack được quản lý bởi hệ điều hành, dữ liệu được lưu trong Stack sẽ tự động hủy khi hàm thực hiện xong công việc của mình.
		- Heap: Vùng nhớ Heap được quản lý bởi lập trình viên (trong C hoặc C++), dữ liệu trong Heap sẽ không bị hủy khi hàm thực hiện xong, điều đó có nghĩa bạn phải tự tay hủy vùng nhớ bằng câu lệnh free (trong C), và delete hoặc delete [] (trong C++), nếu không sẽ xảy ra hiện tượng rò rỉ bộ nhớ. 

<details>
  <summary><h2>▶B2 Macro, Inline, Function</h2></summary>
## **Macro**
   - Được xử lý bởi preprocessor(Tiền xử lý)
   - Macro thường được dùng để thay thế các đoạn code có tính lặp lại nhiều lần trong chương trình.
   - Size của file chương trình chứa macro sẽ lớn hơn function nhưng tốc độ chương trình sẽ nhanh hơn. Bới vì Hàm Bình thường sử dụng một địa chỉ cố định và dùng stack counter và propram counter trỏ đến chương trình, Hàm Macro sẽ Build chương trình thành mã máy và dán chương trình vào đúng vị trí hàm sử dụng.

	#define SUM(a, b) a+b
	int main()
	{
		printf("Tong a va b = %d\n", SUM(4, 7));
	}
  ***Macro Funtion***
  
  	#define CREATE_FUNC(ten_ham, noi_dung)	\
	void ten_ham(){				\
		printf("%s\n", noi_dung);		\
	}
	CREATE_FUNC(test, "this is test")
	\*tao ra mot ham 
	void tets(){
		printf("%s\n", "this is test");
	}*/
	
## **inline** 
- Size của file chương trình chứa **inline** sẽ lớn hơn các chương trình khác nhưng tốc độ chương trình sẽ nhanh hơn. Bới vì Hàm Bình thường sử dụng một địa chỉ cố định và dùng stack pointer và propram couter trỏ đến chương trình.
-  Hàm **inline** sẽ Build chương trình thành mã máy và dán chương trình vào đúng vị trí hàm sử dụng.


	inline void test(int a, int b){
		return a+b;
	}//0xc4 0xc5 mã máy, vdk sẽ hiểu
	int main()
	{
		test(3, 4);//0xc4 0xc5 dán vào vị trí chương trình sử dụng
		return 0;
	}
<details>
  <summary><h2>▶B3 THAO TÁC BIT</h2></summary>

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

<details>
  <summary><h2>▶B4 STRUCT and UNION</h2></summary>

STRUCT và UNION là kiểu dữ liệu người dùng tự định nghĩa
## **Từng phần tử của STRUCT sẽ có địa chỉ riêng, có thể dùng nhiều biến trong Struct cùng lúc**
### **_Struct khi chạy được lưu vào bộ nhớ Stack trên RAM_** 
	
	struct Exam{
	  uint8_t X1[10]; // Mất 2 lần quét tạo ra 2 lần 8 byte, 8 byte cuối lần 2 sẽ dư ra 6 byte gọi là bộ nhớ đệm
	  uint64_t X2[5]; // Bộ nhớ Đệm không nhỏ hơn lần quét tiếp cần có thì sẽ tạo ra 8 byte mới, nếu nhỏ hơn hoặc bẳng sẽ dùng bô nhớ Đệm.
	  uint32_t X3[6]; // Kiểu u32 lỗi lần quét mất 4 byte, đây cần tạo 3 lần 8 byte
	  //Bộ nhớ của kiểu Struct trên là 80 Byte
	}EX;
	/* Bộ nhớ mỗi lần quét sẽ được tính theo kiểu dữ liệu lớn nhất trong struct. Như trên mỗi lần quét là 8 byte 
 ## **Union** 
**_Union Sử Dụng Địa chỉ dùng chung cho các member bên trong nó, Bô nhớ union bằng member lớn nhất trong nó**
	'''c
	typedef union 
	{
	    uint8_t a;
	    uint8_t b;
	    uint8_t c;
	}Data;

	void hienthi( Data data){
	    printf("a = %d, b = %d, c = %d", data.a, data.b, data.c);
	}

	int main()
	{
	   Data data;
	   data.a = 25;
	   data.b = 12;
	   data.c = 65;

	   hienthi(data);
	}//ket qua {a = 65, b = 65, c = 65}
	'''

<details>
  <summary><h2>▶B5 Static and Pointer</h2></summary>

## Static
   - Biến **Static** khởi tạo một lần và sẽ tồn tại hết vòng đời của chương trình.
   - Biến static cục bộ chỉ có thể sử dụng trong **pham vi hàm chứa nó** và nếu biến static toàn cục chỉ sử dụng được trong file đó.
  	void test(){
   		static int a = 10;
		printf("a = %d\n", a);
		a++;
  	}
	int main()
	{
		test();
		test();
		test();
	}//KQ a = 10 / a = 11 / a = 12; 
	//Không có static KQ = 10 hết. 
# Pointer and Pointer to Pointer
## Pointer
    - Khai báo con trỏ
    	int *ptr; // Khai báo như các biến bình thường nhưng thêm dấu * 
	// chưa gán địa chỉ nó sẽ sử dụng một địa chỉ rác. 
	// Khi khai báo một con trỏ Nên khai báo cho nó một địa chỉ như NUL, để tránh bị lỗi chương trình.
	int *ptr = NULL;
 	//Con trỏ NUL là con trỏ có giá trị = 0 và địa chỉ = 0;
	// Khi không sử dụng một con trỏ cũng nên gán cho nó bằng con trỏ NUL
 Con trỏ chỉ lưu địa chỉ có giá trị cùng kiểu dữ liệu với con trỏ.
 ## Con trỏ Hàm
	'''c
 	void tong(int a,int b){
		printf("tong %d va %d = %d\n", a, b, a+b);
	}
	int main()
	{
		void (*ptr_phepToan)(int a, int b) = NUL;
		prt_phepToan = &tong;
		ptr_phepToan 
	}
	'''
## Con Trỏ Void
	int main()
	{
		
	}
	
## Pointer to Pointer
### là một con trỏ lưu địa chỉ con trỏ trước
	char *aray = "hello";
	char arr

<details>
  <summary><h2>▶B6 C++</h2></summary>

## CLASS
- Cấu trúc của class:
	'''c
	#include <iostream>
	using namespace std;
	class SinhVien{
		private:		//chỉ có class truy cập đến các member trong private
			int tuoi;		// day goi la property
			int lop;
		public:
			
			void hienThi();	/* day goi la method, có thể viết chương trình trong method */
	}

	void SinhVien::hienThi(){

	}

	int main()
	{
		SinhVien sv, sv2; // Class SinhVen, object la sv và sv 2, có địa chỉ khác nhau, object chi truy cap den pham vi trong public.
		return 0;
	}
	'''


