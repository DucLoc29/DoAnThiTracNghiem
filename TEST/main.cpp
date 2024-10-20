#include <stdio.h>
#include <iostream>
#include "graphics.h"
#include <Windows.h>
#include <cstring>
#include <string>
#include <string.h>
#include <fstream>
#include <cstdlib> // random number
#include <ctime>
#include <thread> // dong ho
#include <iomanip>
#include <math.h>

#pragma warning (disable:4996); // strlwr
#pragma comment(lib, "graphics.lib")

// Thu vien rieng
#include "DoHoa.h"
#include "ThongBao.h"


// DS SINH VIEN lien ket don

using namespace std;

#define MAXDSMONHOC 300
#define MAXDSLOP 500
#define MAXDSCAUHOI 300

struct CauHoiThi {
	int id;
	string mamh;
	string noidung, A, B, C, D;
	string dapan;
};
struct nodeCauHoiThi {
	CauHoiThi CH;
	nodeCauHoiThi* left, * right;
	int height;
};
typedef nodeCauHoiThi* ptrCauHoiThi;

// DS MON HOC mang con tro
struct MonHoc {
	string mamh;
	string tenmh;
};
struct DS_MonHoc {
	int n = 0;
	MonHoc* DS[MAXDSMONHOC];
};

// DS DIEM THI lien ket don
struct Diem {
	string mamh;
	float diem;

	int n = 0;
	CauHoiThi* DapAn[MAXDSCAUHOI];
	CauHoiThi* CauTraLoi[MAXDSCAUHOI];
};
struct nodeDiemThi {
	Diem info;
	nodeDiemThi* next;
};
typedef struct nodeDiemThi* ptrDiemThi;

// DS SINH VIEN lien ket don
struct SinhVien {
	string  masv;
	string ten, phai, matkhau;
	string ho;
	ptrDiemThi ds_diemthi = NULL;
};


struct nodeSinhVien {
	SinhVien info;
	nodeSinhVien* next;
};
typedef struct nodeSinhVien* ptrSinhVien;

// DS LOP tuyen tinh
struct Lop {
	string malop;
	string tenlop;
	int namnhaphoc;
	ptrSinhVien ds_sinhvien = NULL;
};
struct DS_Lop {
	int n = 0;
	Lop* DS[MAXDSLOP];
};


//========================HAM VIET TEXT==========================================
string vietText_khung_TAI_KHOAN(int x, int y, int dodaichuoi) {
	// to de len khung DANG NHAP
	setfillstyle(1, 15);
	bar(702, 382, 1058, 418);

	char connhay[100] = "|";
	char hienText[100] = "";
	char inputText[100] = "";

	while (true) {
		strcpy_s(hienText, inputText);
		strcat_s(hienText, connhay);

		setbkcolor(15);
		setcolor(0);
		settextstyle(8, 0, 3);
		outtextxy(x, y, hienText);

		if (kbhit()) {
			char ch = getch();

			if (ch == '\b' && strlen(inputText) > 0 && strlen(hienText) > 0) {
				inputText[strlen(inputText) - 1] = '\0';
				hienText[strlen(hienText) - 1] = '\0';

				// to de len khung DANG NHAP
				setfillstyle(1, 15);
				bar(702, 382, 1058, 418);

				outtextxy(x, y, hienText);
			}
			else if (ch == '\r' || ch == '\n') {
				setfillstyle(1, 15);
				bar(702, 382, 1058, 418);

				outtextxy(x, y, inputText);
				return inputText;
			}
			else if (('a' <= ch && ch <= 'z') || ('A' <= ch && ch <= 'Z') || ('0' <= ch && ch <= '9')) {
				int tmp = strlen(inputText);
				if (tmp < dodaichuoi) {
					strncat_s(inputText, &ch, 1);
				}
			}
		}
		delay(200);
	}
}
string vietText_khung_MAT_KHAU(int x, int y, int dodaichuoi) {
	// to de len khung MAT KHAU
	setfillstyle(1, 15);
	bar(702, 452, 1058, 488);

	char connhay[100] = "|";
	char hienText[100] = "";
	char inputText[100] = "";

	while (true) {
		strcpy_s(hienText, inputText);

		setbkcolor(15);
		setcolor(0);
		settextstyle(8, 0, 3);

		// Hien thi mat khau dang (*) va co dau NHAY 
		for (int i = 0; i < strlen(hienText); ++i) {
			hienText[i] = '*';
		}
		strcat_s(hienText, connhay);
		outtextxy(x, y, hienText);

		if (kbhit()) {
			char ch = getch();

			if (ch == '\b' && strlen(inputText) > 0 && strlen(hienText) > 0) {
				inputText[strlen(inputText) - 1] = '\0';
				hienText[strlen(hienText) - 1] = '\0';

				// to de len khung MAT KHAU
				setfillstyle(1, 15);
				bar(702, 452, 1058, 488);

				outtextxy(x, y, hienText);
			}
			else if (ch == '\r' || ch == '\n') {
				setfillstyle(1, 15);
				bar(702, 452, 1058, 488);

				//Xoa dau NHAY va hien mat khau dang (*) ra man hinh
				hienText[strlen(hienText) - 1] = '\0';
				outtextxy(x, y, hienText);
				return inputText;
			}
			else if (('a' <= ch && ch <= 'z') || ('A' <= ch && ch <= 'Z') || ('0' <= ch && ch <= '9')) {
				int tmp = strlen(inputText);
				if (tmp < dodaichuoi) {
					strncat_s(inputText, &ch, 1);
				}
			}
		}
		delay(200);
	}
}
// ---------------------nhap lop-------------------------------------
string vietText_khung_MA_LOP(int x, int y, int dodaichuoi) {
	// to de len khung MA LOP rectangle(400, 120, 900, 160);
	setfillstyle(1, 11);
	bar(252, 122, 598, 158);

	char connhay[100] = "|";
	char hienText[100] = "";
	char inputText[100] = "";

	while (true) {
		strcpy_s(hienText, inputText);
		strcat_s(hienText, connhay);

		setbkcolor(11);
		setcolor(0);
		settextstyle(8, 0, 3);
		outtextxy(x, y, hienText);

		if (kbhit()) {
			char ch = getch();

			if (ch == '\b' && strlen(inputText) > 0 && strlen(hienText) > 0) {
				inputText[strlen(inputText) - 1] = '\0';
				hienText[strlen(hienText) - 1] = '\0';

				// to de len khung MA LOP rectangle(400, 120, 900, 160);
				setfillstyle(1, 11);
				bar(252, 122, 598, 158);

				outtextxy(x, y, hienText);
			}
			else if (ch == '\r' || ch == '\n') {
				setfillstyle(1, 11);
				bar(252, 122, 598, 158);

				outtextxy(x, y, inputText);
				return inputText;
			}
			else if (('a' <= ch && ch <= 'z') || ('A' <= ch && ch <= 'Z') || ('0' <= ch && ch <= '9')) {
				int tmp = strlen(inputText);
				if (tmp < dodaichuoi) {
					strncat_s(inputText, &ch, 1);
				}
			}
		}
		delay(200);
	}
}
string vietText_khung_NAM_HOC_LOP(int x, int y, int dodaichuoi) {
	// to de len khung MA LOP rectangle(400, 120, 900, 160);
	setfillstyle(1, 11);
	bar(782, 122, 948, 158);

	char connhay[100] = "|";
	char hienText[100] = "";
	char inputText[100] = "";

	while (true) {
		strcpy_s(hienText, inputText);
		strcat_s(hienText, connhay);

		setbkcolor(11);
		setcolor(0);
		settextstyle(8, 0, 3);
		outtextxy(x, y, hienText);

		if (kbhit()) {
			char ch = getch();

			if (ch == '\b' && strlen(inputText) > 0 && strlen(hienText) > 0) {
				inputText[strlen(inputText) - 1] = '\0';
				hienText[strlen(hienText) - 1] = '\0';

				// to de len khung MA LOP rectangle(400, 120, 900, 160);
				setfillstyle(1, 11);
				bar(782, 122, 948, 158);

				outtextxy(x, y, hienText);
			}
			else if (ch == '\r' || ch == '\n') {
				setfillstyle(1, 11);
				bar(782, 122, 948, 158);

				outtextxy(x, y, inputText);
				return inputText;
			}
			else if (('0' <= ch && ch <= '9')) {
				int tmp = strlen(inputText);
				if (tmp < dodaichuoi) {
					strncat_s(inputText, &ch, 1);
				}
			}
		}
		delay(200);
	}
}
string vietText_khung_TEN_LOP(int x, int y, int dodaichuoi) {
	// to de len khung TEN LOP rectangle(400, 180, 900, 220);
	setfillstyle(1, 11);
	bar(252, 182, 898, 218);

	char connhay[100] = "|";
	char hienText[100] = "";
	char inputText[100] = "";

	while (true) {
		strcpy_s(hienText, inputText);
		strcat_s(hienText, connhay);

		setbkcolor(11);
		setcolor(0);
		settextstyle(8, 0, 3);
		outtextxy(x, y, hienText);

		if (kbhit()) {
			char ch = getch();

			if (ch == '\b' && strlen(inputText) > 0 && strlen(hienText) > 0) {
				inputText[strlen(inputText) - 1] = '\0';
				hienText[strlen(hienText) - 1] = '\0';

				// to de len khung TEN LOP rectangle(400, 180, 900, 220);
				setfillstyle(1, 11);
				bar(252, 182, 898, 218);

				outtextxy(x, y, hienText);
			}
			else if (ch == '\r' || ch == '\n') {
				setfillstyle(1, 11);
				bar(252, 182, 898, 218);

				outtextxy(x, y, inputText);
				return inputText;
			}
			else if (('a' <= ch && ch <= 'z') || ('A' <= ch && ch <= 'Z') || ('0' <= ch && ch <= '9') || (ch == 32)) {
				int tmp = strlen(inputText);
				if (tmp < dodaichuoi) {
					strncat_s(inputText, &ch, 1);
				}
			}
		}
		delay(200);
	}
}
//----------------------nhap mon--------------------------------------
string vietText_khung_MA_MON(int x, int y, int dodaichuoi) {
	// to de len khung MA MON rectangle(400, 120, 900, 160);
	setfillstyle(1, 11);
	bar(352, 122, 698, 158);

	char connhay[100] = "|";
	char hienText[100] = "";
	char inputText[100] = "";

	while (true) {
		strcpy_s(hienText, inputText);
		strcat_s(hienText, connhay);

		setbkcolor(11);
		setcolor(0);
		settextstyle(8, 0, 3);
		outtextxy(x, y, hienText);

		if (kbhit()) {
			char ch = getch();

			if (ch == '\b' && strlen(inputText) > 0 && strlen(hienText) > 0) {
				inputText[strlen(inputText) - 1] = '\0';
				hienText[strlen(hienText) - 1] = '\0';

				// to de len khung MA MON rectangle(400, 120, 900, 160);
				setfillstyle(1, 11);
				bar(352, 122, 698, 158);

				outtextxy(x, y, hienText);
			}
			else if (ch == '\r' || ch == '\n') {
				setfillstyle(1, 11);
				bar(352, 122, 698, 158);

				outtextxy(x, y, inputText);
				return inputText;
			}
			else if (('a' <= ch && ch <= 'z') || ('A' <= ch && ch <= 'Z') || ('0' <= ch && ch <= '9')) {
				int tmp = strlen(inputText);
				if (tmp < dodaichuoi) {
					strncat_s(inputText, &ch, 1);
				}
			}
		}
		delay(200);
	}
}
string vietText_khung_TEN_MON(int x, int y, int dodaichuoi) {
	// to de len khung TEN MON bar(352, 182, 978, 218);
	setfillstyle(1, 11);
	bar(352, 182, 978, 218);

	char connhay[100] = "|";
	char hienText[100] = "";
	char inputText[100] = "";

	while (true) {
		strcpy_s(hienText, inputText);
		strcat_s(hienText, connhay);

		setbkcolor(11);
		setcolor(0);
		settextstyle(8, 0, 3);
		outtextxy(x, y, hienText);

		if (kbhit()) {
			char ch = getch();

			if (ch == '\b' && strlen(inputText) > 0 && strlen(hienText) > 0) {
				inputText[strlen(inputText) - 1] = '\0';
				hienText[strlen(hienText) - 1] = '\0';

				// to de len khung TEN MON bar(352, 182, 978, 218);
				setfillstyle(1, 11);
				bar(352, 182, 978, 218);

				outtextxy(x, y, hienText);
			}
			else if (ch == '\r' || ch == '\n') {
				setfillstyle(1, 11);
				bar(352, 182, 978, 218);

				outtextxy(x, y, inputText);
				return inputText;
			}
			else if (('a' <= ch && ch <= 'z') || ('A' <= ch && ch <= 'Z') || ('0' <= ch && ch <= '9') || (ch == 32)) {
				int tmp = strlen(inputText);
				if (tmp < dodaichuoi) {
					strncat_s(inputText, &ch, 1);
				}
			}
		}
		delay(200);
	}
}
//----------------------nhap SINH VIEN--------------------------------
//                   Chuc nang nhap
string vietText_khung_MA_SINH_VIEN(int x, int y, int dodaichuoi) {
	// to de len khung MA MON rectangle(400, 120, 900, 160);
	setfillstyle(1, 11);
	bar(202, 92, 598, 128);

	char connhay[100] = "|";
	char hienText[100] = "";
	char inputText[100] = "";

	while (true) {
		strcpy_s(hienText, inputText);
		strcat_s(hienText, connhay);

		setbkcolor(11);
		setcolor(0);
		settextstyle(8, 0, 3);
		outtextxy(x, y, hienText);

		if (kbhit()) {
			char ch = getch();

			if (ch == '\b' && strlen(inputText) > 0 && strlen(hienText) > 0) {
				inputText[strlen(inputText) - 1] = '\0';
				hienText[strlen(hienText) - 1] = '\0';

				// to de len khung MA MON rectangle(400, 120, 900, 160);
				setfillstyle(1, 11);
				bar(202, 92, 598, 128);

				outtextxy(x, y, hienText);
			}
			else if (ch == '\r' || ch == '\n') {
				setfillstyle(1, 11);
				bar(202, 92, 598, 128);

				outtextxy(x, y, inputText);
				return inputText;
			}
			else if (('0' <= ch && ch <= '9')) {
				int tmp = strlen(inputText);
				if (tmp < dodaichuoi) {
					strncat_s(inputText, &ch, 1);
				}
			}
		}
		delay(200);
	}
}
string vietText_khung_HO_SINH_VIEN(int x, int y, int dodaichuoi) {
	// to de len khung MA MON rectangle(400, 120, 900, 160);
	setfillstyle(1, 11);
	bar(202, 152, 598, 188);

	char connhay[100] = "|";
	char hienText[100] = "";
	char inputText[100] = "";

	while (true) {
		strcpy_s(hienText, inputText);
		strcat_s(hienText, connhay);

		setbkcolor(11);
		setcolor(0);
		settextstyle(8, 0, 3);
		outtextxy(x, y, hienText);

		if (kbhit()) {
			char ch = getch();

			if (ch == '\b' && strlen(inputText) > 0 && strlen(hienText) > 0) {
				inputText[strlen(inputText) - 1] = '\0';
				hienText[strlen(hienText) - 1] = '\0';

				// to de len khung MA MON rectangle(400, 120, 900, 160);
				setfillstyle(1, 11);
				bar(202, 152, 598, 188);

				outtextxy(x, y, hienText);
			}
			else if (ch == '\r' || ch == '\n') {
				setfillstyle(1, 11);
				bar(202, 152, 598, 188);

				outtextxy(x, y, inputText);
				return inputText;
			}
			else if (('a' <= ch && ch <= 'z') || ('A' <= ch && ch <= 'Z') || (ch == 32)) {
				int tmp = strlen(inputText);
				if (tmp < dodaichuoi) {
					strncat_s(inputText, &ch, 1);
				}
			}
		}
		delay(200);
	}
}
string vietText_khung_TEN_SINH_VIEN(int x, int y, int dodaichuoi) {
	// to de len khung MA MON rectangle(400, 120, 900, 160);
	setfillstyle(1, 11);
	bar(202, 212, 598, 248);

	char connhay[100] = "|";
	char hienText[100] = "";
	char inputText[100] = "";

	while (true) {
		strcpy_s(hienText, inputText);
		strcat_s(hienText, connhay);

		setbkcolor(11);
		setcolor(0);
		settextstyle(8, 0, 3);
		outtextxy(x, y, hienText);

		if (kbhit()) {
			char ch = getch();

			if (ch == '\b' && strlen(inputText) > 0 && strlen(hienText) > 0) {
				inputText[strlen(inputText) - 1] = '\0';
				hienText[strlen(hienText) - 1] = '\0';

				// to de len khung MA MON rectangle(400, 120, 900, 160);
				setfillstyle(1, 11);
				bar(202, 212, 598, 248);

				outtextxy(x, y, hienText);
			}
			else if (ch == '\r' || ch == '\n') {
				setfillstyle(1, 11);
				bar(202, 212, 598, 248);

				outtextxy(x, y, inputText);
				return inputText;
			}
			else if (('a' <= ch && ch <= 'z') || ('A' <= ch && ch <= 'Z')) {
				int tmp = strlen(inputText);
				if (tmp < dodaichuoi) {
					strncat_s(inputText, &ch, 1);
				}
			}
		}
		delay(200);
	}
}
string vietText_khung_MAT_KHAU_SINH_VIEN(int x, int y, int dodaichuoi) {
	// to de len khung MA MON rectangle(400, 120, 900, 160);
	setfillstyle(1, 11);
	bar(802, 182, 1048, 218);

	char connhay[100] = "|";
	char hienText[100] = "";
	char inputText[100] = "";

	while (true) {
		strcpy_s(hienText, inputText);
		strcat_s(hienText, connhay);

		setbkcolor(11);
		setcolor(0);
		settextstyle(8, 0, 3);
		outtextxy(x, y, hienText);

		if (kbhit()) {
			char ch = getch();

			if (ch == '\b' && strlen(inputText) > 0 && strlen(hienText) > 0) {
				inputText[strlen(inputText) - 1] = '\0';
				hienText[strlen(hienText) - 1] = '\0';

				// to de len khung MA MON rectangle(400, 120, 900, 160);
				setfillstyle(1, 11);
				bar(802, 182, 1048, 218);

				outtextxy(x, y, hienText);
			}
			else if (ch == '\r' || ch == '\n') {
				setfillstyle(1, 11);
				bar(802, 182, 1048, 218);

				outtextxy(x, y, inputText);
				return inputText;
			}
			else if (('a' <= ch && ch <= 'z') || ('A' <= ch && ch <= 'Z') || ('0' <= ch && ch <= '9')) {
				int tmp = strlen(inputText);
				if (tmp < dodaichuoi) {
					strncat_s(inputText, &ch, 1);
				}
			}
		}
		delay(200);
	}
}
string vietText_khung_MAT_KHAU_SV(int x, int y, int dodaichuoi) {
	// to de len khung MA MON rectangle(400, 120, 900, 160);
	setfillstyle(1, 11);
	bar(802, 182, 1048, 218);

	char connhay[100] = "|";
	char hienText[100] = "";
	char inputText[100] = "";

	while (true) {
		strcpy_s(hienText, inputText);

		setbkcolor(11);
		setcolor(0);
		settextstyle(8, 0, 3);

		// Hien thi mat khau dang (*) va co dau NHAY 
		for (int i = 0; i < strlen(hienText); ++i) {
			hienText[i] = '*';
		}

		strcat_s(hienText, connhay);
		outtextxy(x, y, hienText);

		if (kbhit()) {
			char ch = getch();

			if (ch == '\b' && strlen(inputText) > 0 && strlen(hienText) > 0) {
				inputText[strlen(inputText) - 1] = '\0';
				hienText[strlen(hienText) - 1] = '\0';

				// to de len khung MA MON rectangle(400, 120, 900, 160);
				setfillstyle(1, 11);
				bar(802, 182, 1048, 218);

				outtextxy(x, y, hienText);
			}
			else if (ch == '\r' || ch == '\n') {
				setfillstyle(1, 11);
				bar(802, 182, 1048, 218);

				//Xoa dau NHAY va hien mat khau dang (*) ra man hinh
				hienText[strlen(hienText) - 1] = '\0';
				outtextxy(x, y, hienText);
				return inputText;
			}
			else if (('a' <= ch && ch <= 'z') || ('A' <= ch && ch <= 'Z') || ('0' <= ch && ch <= '9')) {
				int tmp = strlen(inputText);
				if (tmp < dodaichuoi) {
					strncat_s(inputText, &ch, 1);
				}
			}
		}
		delay(200);
	}
}
//---------------------nhap CAU HOI-------------------------------------------
string vietText_ChuHoa_ChuThuong_So_KhoangTrang(int x, int y, int dodaichuoi, int trai, int tren, int phai, int duoi) {
	// to de len khung 	rectangle(205, 120, 1070, 220);
	setfillstyle(1, 11);
	bar(trai, tren, phai, duoi);

	char connhay[100] = "|";
	char hienText[100] = "";
	char inputText[100] = "";

	while (true) {
		strcpy_s(hienText, inputText);
		strcat_s(hienText, connhay);

		setbkcolor(11);
		setcolor(0);
		settextstyle(8, 0, 2);
		outtextxy(x, y, hienText);

		if (kbhit()) {
			char ch = getch();

			if (ch == '\b' && strlen(inputText) > 0 && strlen(hienText) > 0) {
				inputText[strlen(inputText) - 1] = '\0';
				hienText[strlen(hienText) - 1] = '\0';

				// to de len khung MA MON rectangle(400, 120, 900, 160);
				setfillstyle(1, 11);
				bar(trai, tren, phai, duoi);

				outtextxy(x, y, hienText);
			}
			else if (ch == '\r' || ch == '\n') {
				setfillstyle(1, 11);
				bar(trai, tren, phai, duoi);

				outtextxy(x, y, inputText);
				return inputText;
			}
			else if (('a' <= ch && ch <= 'z') || ('A' <= ch && ch <= 'Z') || ('0' <= ch && ch <= '9') || (ch == 32)) {
				int tmp = strlen(inputText);
				if (tmp < dodaichuoi) {
					strncat_s(inputText, &ch, 1);
				}
			}
		}
		delay(200);
	}
}
string vietText_ChuHoa_ChuThuong_So(int x, int y, int dodaichuoi, int trai, int tren, int phai, int duoi) {
	// to de len khung 	rectangle(205, 120, 1070, 220);
	setfillstyle(1, 11);
	bar(trai, tren, phai, duoi);

	char connhay[100] = "|";
	char hienText[100] = "";
	char inputText[100] = "";

	while (true) {
		strcpy_s(hienText, inputText);
		strcat_s(hienText, connhay);

		setbkcolor(11);
		setcolor(0);
		settextstyle(8, 0, 2);
		outtextxy(x, y, hienText);

		if (kbhit()) {
			char ch = getch();

			if (ch == '\b' && strlen(inputText) > 0 && strlen(hienText) > 0) {
				inputText[strlen(inputText) - 1] = '\0';
				hienText[strlen(hienText) - 1] = '\0';

				// to de len khung MA MON rectangle(400, 120, 900, 160);
				setfillstyle(1, 11);
				bar(trai, tren, phai, duoi);

				outtextxy(x, y, hienText);
			}
			else if (ch == '\r' || ch == '\n') {
				setfillstyle(1, 11);
				bar(trai, tren, phai, duoi);

				outtextxy(x, y, inputText);
				return inputText;
			}
			else if (('a' <= ch && ch <= 'z') || ('A' <= ch && ch <= 'Z') || ('0' <= ch && ch <= '9')) {
				int tmp = strlen(inputText);
				if (tmp < dodaichuoi) {
					strncat_s(inputText, &ch, 1);
				}
			}
		}
		delay(200);
	}
}
string vietText_So(int x, int y, int dodaichuoi, int trai, int tren, int phai, int duoi) {
	// to de len khung 	rectangle(205, 120, 1070, 220);
	setfillstyle(1, 11);
	bar(trai, tren, phai, duoi);

	char connhay[100] = "|";
	char hienText[100] = "";
	char inputText[100] = "";

	while (true) {
		strcpy_s(hienText, inputText);
		strcat_s(hienText, connhay);

		setbkcolor(11);
		setcolor(0);
		settextstyle(8, 0, 2);
		outtextxy(x, y, hienText);

		if (kbhit()) {
			char ch = getch();

			if (ch == '\b' && strlen(inputText) > 0 && strlen(hienText) > 0) {
				inputText[strlen(inputText) - 1] = '\0';
				hienText[strlen(hienText) - 1] = '\0';

				// to de len khung MA MON rectangle(400, 120, 900, 160);
				setfillstyle(1, 11);
				bar(trai, tren, phai, duoi);

				outtextxy(x, y, hienText);
			}
			else if (ch == '\r' || ch == '\n') {
				setfillstyle(1, 11);
				bar(trai, tren, phai, duoi);

				outtextxy(x, y, inputText);
				return inputText;
			}
			else if ('0' <= ch && ch <= '9') {
				int tmp = strlen(inputText);
				if (tmp < dodaichuoi) {
					strncat_s(inputText, &ch, 1);
				}
			}
		}
		delay(200);
	}
}


//                   Chuc nang xoa
string vietText_khung_MA_SINH_VIEN_chuc_nang_xoa(int x, int y, int dodaichuoi) {
	// to de len khung MA MON rectangle(400, 120, 900, 160);
	setfillstyle(1, 11);
	bar(402, 152, 798, 188);

	char connhay[100] = "|";
	char hienText[100] = "";
	char inputText[100] = "";

	while (true) {
		strcpy_s(hienText, inputText);
		strcat_s(hienText, connhay);

		setbkcolor(11);
		setcolor(0);
		settextstyle(8, 0, 3);
		outtextxy(x, y, hienText);

		if (kbhit()) {
			char ch = getch();

			if (ch == '\b' && strlen(inputText) > 0 && strlen(hienText) > 0) {
				inputText[strlen(inputText) - 1] = '\0';
				hienText[strlen(hienText) - 1] = '\0';

				// to de len khung MA MON rectangle(400, 120, 900, 160);
				setfillstyle(1, 11);
				bar(402, 152, 798, 188);

				outtextxy(x, y, hienText);
			}
			else if (ch == '\r' || ch == '\n') {
				setfillstyle(1, 11);
				bar(402, 152, 798, 188);

				outtextxy(x, y, inputText);
				return inputText;
			}
			else if (('0' <= ch && ch <= '9')) {
				int tmp = strlen(inputText);
				if (tmp < dodaichuoi) {
					strncat_s(inputText, &ch, 1);
				}
			}
		}
		delay(200);
	}
}


//========================HAM CHUAN HOA CHUOI===================================
void XoaKhoangTrangThuaDauVaCuoi(string& a) {
	// Xóa tất cả các kí tự khoảng trống ở đầu chuỗi 
	while (a[0] == ' ') {
		a.erase(a.begin() + 0); // Xóa kí tự tại vị trí 0 
	}
	// Xóa tất cả các kí tự khoảng trống ở cuối chuỗi 
	while (a[a.length() - 1] == ' ') {
		a.erase(a.begin() + a.length() - 1); // Xóa kí tự tại vị trí cuối cùng 
	}
}
void XoaKhoangTrangThuaGiuaCacTu(string& a) {
	for (int i = 0; i < a.length(); i++) {
		// Nếu giữa hai kí tự có nhiều hơn hai khoảng trắng thì xóa tới khi còn 1 khoảng trắng 
		if (a[i] == ' ' && a[i + 1] == ' ') {
			a.erase(a.begin() + i);
			i--;
		}
	}
}
void InHoaCacKiTuDauTien(string& a) {
	strlwr(((char*)a.c_str()));
	if (a[0] != ' ') {
		if (a[0] >= 97 && a[0] <= 122) {
			a[0] -= 32;
		}
	}
	for (int i = 0; i < a.length() - 1; i++) {
		if (a[i] == ' ' && a[i + 1] != ' ') {
			if (a[i + 1] >= 97 && a[i + 1] <= 122) {
				a[i + 1] -= 32;
			}
		}
	}
}
void VietThuongTatCaChu(string& a) {
	for (int i = 0; i < a.length(); i++) {
		if (a[i] >= 65 && a[i] <= 90) {
			a[i] += 32;
		}
	}
}
void VietHoaTatCaChu(string& a) {
	for (int i = 0; i < a.length(); i++) {
		if (a[i] >= 97 && a[i] <= 122) {
			a[i] -= 32;
		}
	}
}
void VietHoaChuDauTien(string& a) {
	string b = "";
	b = toupper(a[0]);

	if (a.length() > 1) {
		b.append(a, 1, a.length());
	}
	a = b;
}

void ChuanHoaChuoi(string& a) {
	XoaKhoangTrangThuaDauVaCuoi(a);
	XoaKhoangTrangThuaGiuaCacTu(a);
	VietThuongTatCaChu(a);
	InHoaCacKiTuDauTien(a);
}
void ChuanHoaChuoi_inhoa_kitudautien(string& a) {
	XoaKhoangTrangThuaDauVaCuoi(a);
	XoaKhoangTrangThuaGiuaCacTu(a);
	VietThuongTatCaChu(a);
	VietHoaChuDauTien(a);
}


//========================HAM KIEM TRA===========================================
bool Kiem_tra_tai_khoan(string taikhoan, string inputText) {
	if (taikhoan == inputText) {
		return true;
	}
	else return false;
}
bool Kiem_tra_tai_khoan_SINH_VIEN(DS_Lop dslop, string taikhoan_nhapvao, string matkhau_nhapvao) {
	ptrSinhVien p;
	for (int i = 0; i < dslop.n; i++) {
		p = dslop.DS[i]->ds_sinhvien;
		for (p; p != NULL; p = p->next) {
			if (strcmp((p->info.masv).c_str(), taikhoan_nhapvao.c_str()) == 0) {
				if (strcmp((p->info.matkhau).c_str(), matkhau_nhapvao.c_str()) == 0) {
					return true;
				}
			}
		}
	}
	return false;
}
bool Lua_chon_CO_hoac_KHONG_cua_thong_bao_trong_ham_chuc_nang() {
	int xmouse = -1;
	int ymouse = -1;
	while (true) {
		if (ismouseclick(WM_LBUTTONDOWN)) {
			getmouseclick(WM_LBUTTONDOWN, xmouse, ymouse);
			// Nguoi dung chon nut CO rectangle(1140, 300, 1290, 350);
			if (xmouse >= 1140 && xmouse <= 1290 && ymouse >= 300 && ymouse <= 350) {
				return true;
			}
			// Nguoi dung chon nut KHONG rectangle(1320, 300, 1470, 350);
			if (xmouse >= 1320 && xmouse <= 1470 && ymouse >= 300 && ymouse <= 350) {
				return false;
			}
		}
	}
}

bool KiemTraTrungChuoi(string a, string b) {
	if (strcmp(a.c_str(), b.c_str()) == 0) {
		return true;
	}
	else
		return false;
}
bool KiemTraTrung_MALOP(DS_Lop dslop, string a) {
	for (int i = 0; i < dslop.n; i++) {
		if (strcmp((dslop.DS[i]->malop).c_str(), a.c_str()) == 0) {
			return true;
		}
	}
	return false;
}
bool KiemTraTrung_TENLOP(DS_Lop dslop, string a) {
	for (int i = 0; i < dslop.n; i++) {
		if (strcmp((dslop.DS[i]->tenlop).c_str(), a.c_str()) == 0) {
			return true;
		}
	}
	return false;
}
bool KiemTraTrung_NAMHOC(DS_Lop dslop, string a) {
	for (int i = 0; i < dslop.n; i++) {
		if (strcmp((to_string(dslop.DS[i]->namnhaphoc)).c_str(), a.c_str()) == 0) {
			return true;
		}
	}
	return false;
}


//========================CAU TRUC LOP HOC======================================
void xuat1Lop(Lop lop) {
	cout << lop.malop << " " << lop.namnhaphoc << " " << lop.tenlop;
}

void ThemvaoDslop(DS_Lop& dslop, Lop lop) {
	dslop.DS[dslop.n] = new Lop;
	dslop.DS[dslop.n]->malop = lop.malop;
	dslop.DS[dslop.n]->namnhaphoc = lop.namnhaphoc;
	dslop.DS[dslop.n]->tenlop = lop.tenlop;
	dslop.n++;
}
void xuatDslop(DS_Lop dslop) {
	for (int i = 0; i < dslop.n; i++) {
		cout << dslop.DS[i]->malop << " " << dslop.DS[i]->namnhaphoc << " " << dslop.DS[i]->tenlop << endl;
	}
}
void hienDsLop_graphic(DS_Lop dslop) {
	setbkcolor(15);
	setcolor(0);
	settextstyle(8, 0, 2);

	int y = 400;

	for (int i = 0; i < dslop.n && i < 9; i++) {
		outtextxy(400, 400 + i * 40, (char*)(dslop.DS[i]->tenlop).c_str());
		outtextxy(220, 400 + i * 40, (char*)(dslop.DS[i]->malop).c_str());
		outtextxy(90, 400 + i * 40, (char*)(to_string(dslop.DS[i]->namnhaphoc).c_str()));
	}
}
void hienDsLop_graphic_trang2(DS_Lop dslop) {
	setbkcolor(15);
	setcolor(0);
	settextstyle(8, 0, 2);

	int j = 0;

	for (int i = 9; i < dslop.n && i < 18; i++) {
		outtextxy(400, 400 + j * 40, (char*)(dslop.DS[i]->tenlop).c_str());
		outtextxy(220, 400 + j * 40, (char*)(dslop.DS[i]->malop).c_str());
		outtextxy(90, 400 + j * 40, (char*)(to_string(dslop.DS[i]->namnhaphoc).c_str()));
		j++;
	}
}

void hienDsLop_graphic_inTheoNamHoc(DS_Lop dslop, int tmp[], int n) {
	setbkcolor(15);
	setcolor(0);
	settextstyle(8, 0, 2);


	for (int i = 0; i < n && i < 9; i++) {
		outtextxy(400, 400 + i * 40, (char*)(dslop.DS[tmp[i]]->tenlop).c_str());
		outtextxy(220, 400 + i * 40, (char*)(dslop.DS[tmp[i]]->malop).c_str());
		outtextxy(90, 400 + i * 40, (char*)(to_string(dslop.DS[tmp[i]]->namnhaphoc).c_str()));
	}
}

void docFileDsLop(DS_Lop& dslop) {
	fstream f;
	f.open("LopHoc.txt", ios::in);
	int cnt = 0;
	char ch;
	// Đếm file có bao nhiêu dòng 
	while (f.get(ch)) {
		if (ch == '\n') {
			++cnt;
		}
	}
	// Đưa con trỏ chuột về đầu file 
	f.clear();
	f.seekg(0, ios::beg);
	// Bắt đầu ghi vào danh sách LỚP 
	for (int i = 0; i < cnt; i++) {
		Lop lop;
		f >> lop.namnhaphoc;
		f.ignore(1);
		getline(f, lop.malop, '|');
		getline(f, lop.tenlop, '|');
		ThemvaoDslop(dslop, lop);
	}

	f.close();
}
void ghiFileDsLop(DS_Lop dslop) {
	fstream f;
	f.open("LopHoc.txt", ios::out);

	for (int i = 0; i < dslop.n; i++) {
		f << dslop.DS[i]->namnhaphoc << "|" << dslop.DS[i]->malop << "|" << dslop.DS[i]->tenlop << "|";
		f << endl;
	}
	f.close();
}

int TimKiemMaLop(DS_Lop dslop, string a) {
	for (int i = 0; i < dslop.n; i++) {
		if (strcmp(a.c_str(), (dslop.DS[i]->malop).c_str()) == 0) {
			return i;
		}
	}
	return -1;
}
void Xoa1Lop(DS_Lop& dslop, int i) {
	delete dslop.DS[i];
	for (int j = i + 1; j < dslop.n; j++) {
		dslop.DS[j - 1] = dslop.DS[j];
	}
	dslop.n--;
}

void In_DsLop_theo_NAM_HOC(DS_Lop dslop) {
	string namhoc_timkiem = "";
	namhoc_timkiem = vietText_khung_NAM_HOC_LOP(800, 129, 4);

	if (namhoc_timkiem.length() == 0 || stoi(namhoc_timkiem) < 1950 || stoi(namhoc_timkiem) > 2050) {
		Thong_bao_Loi_NAMHOC();
		return;
	}
	// Dem so luong phan tu
	int count = 0;
	for (int i = 0; i < dslop.n; i++) {
		if (strcmp((to_string(dslop.DS[i]->namnhaphoc)).c_str(), namhoc_timkiem.c_str()) == 0) {
			count++;
		}
	}
	// Dua dia chi phan tu trong mang CHINH vao mang tmp
	int* tmp = new int[count];
	int index = 0;
	for (int i = 0; i < dslop.n; i++) {
		if (strcmp((to_string(dslop.DS[i]->namnhaphoc)).c_str(), namhoc_timkiem.c_str()) == 0) {
			tmp[index] = i;
			if (index < count) {
				index++;
			}
		}
	}
	
	// xoa danh sach du lieu cu tren man hinh
	setfillstyle(1, 15);
	bar(50, 350, 1080, 750);
	setcolor(0);
	rectangle(50, 350, 1080, 750);

	line(50, 710, 1080, 710);
	line(50, 670, 1080, 670);
	line(50, 630, 1080, 630);
	line(50, 590, 1080, 590);
	line(50, 550, 1080, 550);
	line(50, 510, 1080, 510);
	line(50, 470, 1080, 470);
	line(50, 430, 1080, 430);
	line(50, 390, 1080, 390);
	line(180, 350, 180, 750);
	line(375, 350, 375, 750);

	setbkcolor(15);
	setcolor(1);
	settextstyle(10, 0, 3);
	outtextxy(95, 360, (char*)"NAM");

	setbkcolor(15);
	setcolor(1);
	settextstyle(10, 0, 3);
	outtextxy(240, 360, (char*)"MA LOP");

	setbkcolor(15);
	setcolor(1);
	settextstyle(10, 0, 3);
	outtextxy(680, 360, (char*)"TEN LOP");

	hienDsLop_graphic_inTheoNamHoc(dslop, tmp, count);

	// Xoa mang tmp
	delete[]tmp;
}
bool In_DsLop_theo_NAM_HOC_chuc_nang_XOA(DS_Lop dslop) {
	string namhoc_timkiem = "";
	namhoc_timkiem = vietText_khung_NAM_HOC_LOP(800, 129, 4);

	if (namhoc_timkiem.length() == 0 || stoi(namhoc_timkiem) < 1950 || stoi(namhoc_timkiem) > 2050) {
		Thong_bao_Loi_NAMHOC();
		return false;
	}

	// Dem so luong phan tu
	int count = 0;
	for (int i = 0; i < dslop.n; i++) {
		if (strcmp((to_string(dslop.DS[i]->namnhaphoc)).c_str(), namhoc_timkiem.c_str()) == 0) {
			count++;
		}
	}

	// Ghi chi so phan tu trong mang CHINH sang mang tmp
	int* tmp = new int[count];
	int index = 0;
	for (int i = 0; i < dslop.n; i++) {
		if (strcmp((to_string(dslop.DS[i]->namnhaphoc)).c_str(), namhoc_timkiem.c_str()) == 0) {
			tmp[index] = i;
			if (index < count) {
				index++;
			}
		}
	}
	// xoa danh sach du lieu cu tren man hinh
	setfillstyle(1, 15);
	bar(50, 350, 1080, 750);
	setcolor(0);
	rectangle(50, 350, 1080, 750);

	line(50, 710, 1080, 710);
	line(50, 670, 1080, 670);
	line(50, 630, 1080, 630);
	line(50, 590, 1080, 590);
	line(50, 550, 1080, 550);
	line(50, 510, 1080, 510);
	line(50, 470, 1080, 470);
	line(50, 430, 1080, 430);
	line(50, 390, 1080, 390);
	line(180, 350, 180, 750);
	line(375, 350, 375, 750);

	setbkcolor(15);
	setcolor(1);
	settextstyle(10, 0, 3);
	outtextxy(95, 360, (char*)"NAM");

	setbkcolor(15);
	setcolor(1);
	settextstyle(10, 0, 3);
	outtextxy(240, 360, (char*)"MA LOP");

	setbkcolor(15);
	setcolor(1);
	settextstyle(10, 0, 3);
	outtextxy(680, 360, (char*)"TEN LOP");

	hienDsLop_graphic_inTheoNamHoc(dslop, tmp, count);

	// Xoa mang tmp
	delete[]tmp;

	return true;
}
void ChuyenTrang_DsLop(DS_Lop dslop, bool trangthai) {
	if (dslop.n > 9) {
		setbkcolor(7);
		setcolor(0);
		settextstyle(8, 0, 3);
		outtextxy(555, 785, (char*)"/2");
		if (trangthai) {
			hienDsLop_graphic_trang2(dslop);
			setbkcolor(7);
			setcolor(0);
			settextstyle(8, 0, 3);
			outtextxy(540, 785, (char*)"2");
		}
		else {
			hienDsLop_graphic(dslop);
			setbkcolor(7);
			setcolor(0);
			settextstyle(8, 0, 3);
			outtextxy(540, 785, (char*)"1");
		}
	}
	else {
		hienDsLop_graphic(dslop);
		setbkcolor(7);
		setcolor(0);
		settextstyle(8, 0, 3);
		outtextxy(540, 785, (char*)"1");

		setbkcolor(7);
		setcolor(0);
		settextstyle(8, 0, 3);
		outtextxy(555, 785, (char*)"/1");
	}
}



//===========================CAU TRUC SINH VIEN====================================
int TimKiemMaLop_SINHVIEN(DS_Lop dslop) {
	int xmouse = -1;
	int ymouse = -1;

	// Nhap MA LOP va chuan hoa
	string malop_cantim = vietText_khung_MA_LOP(265, 129, 15);
	VietHoaTatCaChu(malop_cantim);

	int vitri = TimKiemMaLop(dslop, malop_cantim);
	if (vitri < 0) {
		Thong_bao_Ko_tim_thay_MA();
		return -1;
	}
	else {
		Quan_ly_sinh_vien();
		return vitri;
	}
}
// Tao moi node Sinh vien
ptrSinhVien taoNodeSinhVien(string nhap_masv, string nhap_ho, string nhap_ten, string nhap_phai, string nhap_matkhau) {
	SinhVien a;
	a.masv = nhap_masv;
	a.ho = nhap_ho;
	a.ten = nhap_ten;
	a.phai = nhap_phai;
	a.matkhau = nhap_matkhau;


	ptrSinhVien sv = new nodeSinhVien;
	sv->info = a;
	sv->next = NULL;
	return sv;
}
// Chen node Sinh Vien vao cuoi danh sach
void insertLastSinhVien(ptrSinhVien& a, ptrSinhVien tmp) {
	if (a == NULL) {
		a = tmp;
	}
	else {
		ptrSinhVien p = a;
		while (p->next != NULL) {
			p = p->next;
		}
		p->next = tmp;
	}
}
int SL_DsSinhVien(ptrSinhVien a) {
	int cnt = 0;
	while (a != NULL) {
		++cnt;
		a = a->next;
	}
	return cnt;
}
void hienDsSinhVien_graphic(DS_Lop dslop, int vitrilop) {
	setbkcolor(15);
	setcolor(0);
	settextstyle(8, 0, 2);

	int cnt = 0;
	int i = 0;
	for (ptrSinhVien p = dslop.DS[vitrilop]->ds_sinhvien; p != NULL && cnt < 9; p = p->next) {
		outtextxy(90, 400 + i * 40, (char*)(p->info.masv).c_str());
		outtextxy(285, 400 + i * 40, (char*)(p->info.phai).c_str());
		outtextxy(390, 400 + i * 40, (char*)(p->info.ho).c_str());
		outtextxy(770, 400 + i * 40, (char*)(p->info.ten).c_str());
		outtextxy(900, 400 + i * 40, (char*)(p->info.matkhau).c_str());

		i++;
		cnt++;
	}
}
void hienDsSinhVien_graphic_trang2(DS_Lop dslop, int vitrilop) {
	setbkcolor(15);
	setcolor(0);
	settextstyle(8, 0, 2);

	int cnt = 0;
	ptrSinhVien p = dslop.DS[vitrilop]->ds_sinhvien;
	while (cnt < 9) {
		p = p->next;
		cnt++;
	}


	int soluong = 0;
	int i = 0;
	for (p; p != NULL && soluong < 18; p = p->next) {
		outtextxy(90, 400 + i * 40, (char*)(p->info.masv).c_str());
		outtextxy(285, 400 + i * 40, (char*)(p->info.phai).c_str());
		outtextxy(390, 400 + i * 40, (char*)(p->info.ho).c_str());
		outtextxy(770, 400 + i * 40, (char*)(p->info.ten).c_str());
		outtextxy(900, 400 + i * 40, (char*)(p->info.matkhau).c_str());

		i++;
		soluong++;
	}
}
void ChuyenTrang_DsSinhVien(DS_Lop dslop, bool trangthai, int vitrilop) {
	int soluong = SL_DsSinhVien(dslop.DS[vitrilop]->ds_sinhvien);

	if (soluong > 9) {
		setbkcolor(7);
		setcolor(0);
		settextstyle(8, 0, 3);
		outtextxy(555, 785, (char*)"/2");
		if (trangthai) {
			hienDsSinhVien_graphic_trang2(dslop, vitrilop);
			setbkcolor(7);
			setcolor(0);
			settextstyle(8, 0, 3);
			outtextxy(540, 785, (char*)"2");
		}
		else {
			hienDsSinhVien_graphic(dslop, vitrilop);
			setbkcolor(7);
			setcolor(0);
			settextstyle(8, 0, 3);
			outtextxy(540, 785, (char*)"1");
		}
	}
	else {
		hienDsSinhVien_graphic(dslop, vitrilop);
		setbkcolor(7);
		setcolor(0);
		settextstyle(8, 0, 3);
		outtextxy(540, 785, (char*)"1");

		setbkcolor(7);
		setcolor(0);
		settextstyle(8, 0, 3);
		outtextxy(555, 785, (char*)"/1");
	}
}

void docFileDsSinhVien(DS_Lop& dslop) {
	fstream f;
	f.open("SinhVien.txt", ios::in);
	int cnt = 0;
	char ch;
	// Đếm file có bao nhiêu dòng 
	while (f.get(ch)) {
		if (ch == '\n') {
			++cnt;
		}
	}
	// Đưa con trỏ chuột về đầu file 
	f.clear();
	f.seekg(0, ios::beg);

	int vitriLopHoc;


	// Bắt đầu ghi vào danh sách Sinh Vien
	for (int i = 0; i < cnt; i++) {
		string maLopHoc;
		getline(f, maLopHoc, '|');
		vitriLopHoc = TimKiemMaLop(dslop, maLopHoc);

		SinhVien sv;
		getline(f, sv.masv, '|');
		getline(f, sv.phai, '|');
		getline(f, sv.ho, '|');
		getline(f, sv.ten, '|');
		getline(f, sv.matkhau, '\n');

		ptrSinhVien a = new nodeSinhVien;
		a->info = sv;
		a->next = NULL;

		insertLastSinhVien(dslop.DS[vitriLopHoc]->ds_sinhvien, a);
	}

	f.close();
}
void DuyetSinhVien(ptrSinhVien head, ptrSinhVien* a, int& index) {
	if (head == NULL) {
		return;
	}
	a[index++] = head;
	DuyetSinhVien(head->next, a, index);
}
void ghiFileDsSinhVien(DS_Lop dslop) {
	fstream f;
	int dem = 0;
	f.open("SinhVien.txt", ios::out);
	for (int i = 0; i < dslop.n; i++) {
		if (dslop.DS[i]->ds_sinhvien != NULL) {
			ptrSinhVien* dsSV = new ptrSinhVien[SL_DsSinhVien(dslop.DS[i]->ds_sinhvien)];
			int index = 0;
			// Cho danh sach Sinh Vien vao mang dsSV
			DuyetSinhVien(dslop.DS[i]->ds_sinhvien, dsSV, index);
			for (int j = 0; j < SL_DsSinhVien(dslop.DS[i]->ds_sinhvien); j++) {
				if (j == 0 && dem != 0) f << endl;

				f << dslop.DS[i]->malop << "|";
				f << dsSV[j]->info.masv << "|";
				f << dsSV[j]->info.phai << "|";
				f << dsSV[j]->info.ho << "|";
				f << dsSV[j]->info.ten << "|";
				f << dsSV[j]->info.matkhau;

				if (j != SL_DsSinhVien(dslop.DS[i]->ds_sinhvien) - 1) f << endl;
				dem++;
			}
			delete[] dsSV;
		}
	}
	f << endl;
	f.close();
}

int TimKiemMaSinhVien_chuc_nang_xoa(DS_Lop dslop, string masv, int vitrilop) {
	ptrSinhVien p = dslop.DS[vitrilop]->ds_sinhvien;
	int cnt = 0;

	for (p; p != NULL; p = p->next) {
		++cnt;
		if (strcmp((p->info.masv).c_str(), masv.c_str()) == 0) {
			return cnt;
		}
	}
	return 0;
}
bool TimKiemMaSinhVien(DS_Lop dslop, string masv, int vitrilop) {
	ptrSinhVien p = dslop.DS[vitrilop]->ds_sinhvien;

	for (p; p != NULL; p = p->next) {
		if (strcmp((p->info.masv).c_str(), masv.c_str()) == 0) {
			return true;
		}
	}
	return false;
}
ptrSinhVien TimKiemMaSinhVien_TraVeNode(DS_Lop dslop, string masv, int vitrilop) {
	ptrSinhVien p = dslop.DS[vitrilop]->ds_sinhvien;

	for (p; p != NULL; p = p->next) {
		if (strcmp((p->info.masv).c_str(), masv.c_str()) == 0) {
			return p;
		}
	}
	return NULL;
}
bool TimKiemMaSinhVien_chuc_nang_sua(DS_Lop dslop, string masv, int vitrilop, int pos) {
	ptrSinhVien p = dslop.DS[vitrilop]->ds_sinhvien;
	int cnt = 0;
	for (p; p != NULL; p = p->next) {
		cnt++;
		if (cnt == pos) {
			continue;
		}
		if (strcmp((p->info.masv).c_str(), masv.c_str()) == 0) {
			return true;
		}
	}
	return false;
}

bool TimKiemHoSinhVien(ptrSinhVien p, string ho) {

	for (p; p != NULL; p = p->next) {
		if (strcmp((p->info.ho).c_str(), ho.c_str()) == 0) {
			return true;
		}
	}
	return false;
}
bool TimKiemTenSinhVien(ptrSinhVien p, string ten) {

	for (p; p != NULL; p = p->next) {
		if (strcmp((p->info.ten).c_str(), ten.c_str()) == 0) {
			return true;
		}
	}
	return false;
}
bool TimKiemPhaiSinhVien(ptrSinhVien p, string phai) {

	for (p; p != NULL; p = p->next) {
		if (stricmp((p->info.phai).c_str(), phai.c_str()) == 0) {
			return true;
		}
	}
	return false;
}
bool KiemTraTrungHoTenSinhVien(DS_Lop dslop, string ho, string ten, string phai, int vitrilop) {
	ptrSinhVien p = dslop.DS[vitrilop]->ds_sinhvien;
	for (p; p != NULL; p = p->next) {
		if (TimKiemPhaiSinhVien(p, phai) == true && TimKiemHoSinhVien(p, ho) == true && TimKiemTenSinhVien(p, ten) == true) {
			return true;
		}
	}
	return false;
}
bool KiemTraTrungHoTenSinhVien_chuc_nang_sua(DS_Lop dslop, string ho, string ten, string phai, int vitrilop, int pos) {
	ptrSinhVien p = dslop.DS[vitrilop]->ds_sinhvien;
	int cnt = 0;
	for (p; p != NULL; p = p->next) {
		cnt++;
		if (cnt == pos) {
			continue;
		}
		if (TimKiemPhaiSinhVien(p, phai) == true && TimKiemHoSinhVien(p, ho) == true && TimKiemTenSinhVien(p, ten) == true) {
			return true;
		}
	}
	return false;
}

void deleteFirst(ptrSinhVien& a) {
	if (a == NULL) return;
	a = a->next;
}
void deleteLast(ptrSinhVien& a) {
	if (a == NULL) return;
	ptrSinhVien truoc = NULL;
	ptrSinhVien sau = a;
	while (sau->next != NULL) {
		truoc = sau;
		sau = sau->next;
	}
	if (truoc == NULL) {
		a = NULL;
	}
	else {
		truoc->next = NULL;
	}
}
void deleteMiddle(ptrSinhVien& a, int pos) {
	// Xoa duoc vi tri dau tien den vi tri gan cuoi 
	ptrSinhVien truoc = NULL;
	ptrSinhVien sau = a;
	for (int i = 1; i < pos; i++) {
		truoc = sau;
		sau = sau->next;
	}
	if (truoc == NULL) {
		a = a->next;
	}
	else {
		truoc->next = sau->next;
	}
}

void XuatDsSinhVien(DS_Lop dslop, int vitrilop) {
	ptrSinhVien p = dslop.DS[vitrilop]->ds_sinhvien;

	for (p; p != NULL; p = p->next) {
		cout << p->info.masv << "|";
		cout << p->info.phai << "|";
		cout << p->info.ho << "|";
		cout << p->info.ten << "|";
		cout << p->info.matkhau << "|";
		cout << endl;
	}
}
void Hien_thi_thong_tin_LOP_HOC_dang_duoc_truy_cap(string ma, string ten) {
	setbkcolor(15);
	setcolor(0);
	settextstyle(10, 0, 2);
	// 185 220
	outtextxy(1230, 420, (char*)"DANG TRUY CAP");
	setcolor(4);
	outtextxy(1130, 460, (char*)ma.c_str());
	outtextxy(1130, 490, (char*)ten.c_str());
}


//============================ CAU TRUC MON HOC ===================================================================
void ThemVaoDsMonhoc(DS_MonHoc& dsmon, MonHoc mon) {
	dsmon.DS[dsmon.n] = new MonHoc;
	dsmon.DS[dsmon.n]->mamh = mon.mamh;
	dsmon.DS[dsmon.n]->tenmh = mon.tenmh;
	dsmon.n++;
}
void ThemMonHocVaoViTriCanThem(DS_MonHoc& dsmon, MonHoc mon, int vitri) {
	for (int j = dsmon.n - 1; j >= vitri; j--) {
		dsmon.DS[j + 1] = dsmon.DS[j];
	}
	++dsmon.n;
	dsmon.DS[vitri] = new MonHoc;
	*dsmon.DS[vitri] = mon;
}
bool SoSanhHonChuoi(string a, string b) {
	if (strcmp(a.c_str(), b.c_str()) > 0) {
		return true;
	}
	return false;
}

void xuatDsMonHoc(DS_MonHoc dsmon) {
	for (int i = 0; i < dsmon.n; i++) {

		cout << dsmon.DS[i]->mamh << " " << dsmon.DS[i]->tenmh << endl;
	}
}

int TimKiemMaMon(DS_MonHoc dsmon, string a) {
	for (int i = 0; i < dsmon.n; i++) {
		if (strcmp(a.c_str(), (dsmon.DS[i]->mamh).c_str()) == 0) {
			return i;
		}
	}
	return -1;
}
void Xoa1MonHoc(DS_MonHoc& dsmon, int i) {
	delete dsmon.DS[i];
	for (int j = i + 1; j < dsmon.n; j++) {
		dsmon.DS[j - 1] = dsmon.DS[j];
	}
	dsmon.n--;
}

bool KiemTraTrungMaMon(DS_MonHoc dsmon, string mamon) {
	for (int i = 0; i < dsmon.n; i++) {
		if (strcmp((dsmon.DS[i]->mamh).c_str(), mamon.c_str()) == 0) {
			return true;
		}
	}
	return false;
}
bool KiemTraTrungTenMon(DS_MonHoc dsmon, string tenmon) {
	for (int i = 0; i < dsmon.n; i++) {
		if (strcmp((dsmon.DS[i]->tenmh).c_str(), tenmon.c_str()) == 0) {
			return true;
		}
	}
	return false;
}

bool KiemTraTrungMaMon_chuc_nang_SUA(DS_MonHoc dsmon, string mamon, int vitri) {
	for (int i = 0; i < dsmon.n; i++) {
		if (vitri == i) {
			continue;
		}
		if (strcmp((dsmon.DS[i]->mamh).c_str(), mamon.c_str()) == 0) {
			return true;
		}
	}
	return false;
}
bool KiemTraTrungTenMon_chuc_nang_SUA(DS_MonHoc dsmon, string tenmon, int vitri) {
	for (int i = 0; i < dsmon.n; i++) {
		if (vitri == 1) {
			continue;
		}
		if (strcmp((dsmon.DS[i]->tenmh).c_str(), tenmon.c_str()) == 0) {
			return true;
		}
	}
	return false;
}

void hienDsMonHoc_graphic(DS_MonHoc dsmon) {
	setbkcolor(15);
	setcolor(0);
	settextstyle(8, 0, 2);

	for (int i = 0; i < dsmon.n && i < 9; i++) {
		outtextxy(180, 400 + i * 40, (char*)(dsmon.DS[i]->mamh).c_str());
		outtextxy(430, 400 + i * 40, (char*)(dsmon.DS[i]->tenmh).c_str());
	}
}
void hienDsMonHoc_graphic_trang2(DS_MonHoc dsmon) {
	setbkcolor(15);
	setcolor(0);
	settextstyle(8, 0, 2);

	int j = 0;

	for (int i = 9; i < dsmon.n && i < 18; i++) {
		outtextxy(180, 400 + j * 40, (char*)(dsmon.DS[i]->mamh).c_str());
		outtextxy(430, 400 + j * 40, (char*)(dsmon.DS[i]->tenmh).c_str());
		j++;
	}
}

void docFileDsMonHoc(DS_MonHoc& dsmon) {
	fstream f;
	f.open("MonHoc.txt", ios::in);
	int cnt = 0;
	char ch;
	// Đếm file có bao nhiêu dòng 
	while (f.get(ch)) {
		if (ch == '\n') {
			++cnt;
		}
	}
	// Đưa con trỏ chuột về đầu file 
	f.clear();
	f.seekg(0, ios::beg);
	// Bắt đầu ghi vào danh sách LỚP 
	for (int i = 0; i < cnt; i++) {
		MonHoc mon;
		getline(f, mon.mamh, '|');
		getline(f, mon.tenmh, '|');
		f.ignore(1);
		ThemVaoDsMonhoc(dsmon, mon);
	}

	f.close();
}
void ghiFileDsMonHoc(DS_MonHoc dsmon) {
	fstream f;
	f.open("MonHoc.txt", ios::out);

	for (int i = 0; i < dsmon.n; i++) {
		f << dsmon.DS[i]->mamh << "|" << dsmon.DS[i]->tenmh << "|";
		f << endl;
	}
	f.close();
}

void ChuyenTrang_DsMonHoc(DS_MonHoc dsmon, bool trangthai) {
	if (dsmon.n > 9) {
		setbkcolor(7);
		setcolor(0);
		settextstyle(8, 0, 3);
		outtextxy(555, 785, (char*)"/2");
		if (trangthai) {
			hienDsMonHoc_graphic_trang2(dsmon);
			setbkcolor(7);
			setcolor(0);
			settextstyle(8, 0, 3);
			outtextxy(540, 785, (char*)"2");
		}
		else {
			hienDsMonHoc_graphic(dsmon);
			setbkcolor(7);
			setcolor(0);
			settextstyle(8, 0, 3);
			outtextxy(540, 785, (char*)"1");
		}
	}
	else {
		hienDsMonHoc_graphic(dsmon);
		setbkcolor(7);
		setcolor(0);
		settextstyle(8, 0, 3);
		outtextxy(540, 785, (char*)"1");

		setbkcolor(7);
		setcolor(0);
		settextstyle(8, 0, 3);
		outtextxy(555, 785, (char*)"/1");
	}
}

void Hien_thi_thong_tin_MON_HOC_dang_duoc_truy_cap(string ma, string ten) {
	setbkcolor(15);
	setcolor(0);
	settextstyle(10, 0, 2);
	// 185 220
	setcolor(4);
	outtextxy(1130, 500 + 40, (char*)ma.c_str());
	outtextxy(1130, 530 + 40, (char*)ten.c_str());
}


// =================================CAU TRUC CAU HOI==========================================
int height(ptrCauHoiThi n) {
	if (n == NULL) {
		return 0;
	}
	return n->height;
}
ptrCauHoiThi newNode(int id_input, string mamh_input, string noidung_input, string A_input, string B_input, string C_input, string D_input, string dapan_input) {
	ptrCauHoiThi a = new nodeCauHoiThi;
	a->CH.id = id_input;
	a->CH.mamh = mamh_input;
	a->CH.noidung = noidung_input;
	a->CH.A = A_input;
	a->CH.B = B_input;
	a->CH.C = C_input;
	a->CH.D = D_input;
	a->CH.dapan = dapan_input;

	a->height = 1;
	a->left = NULL;
	a->right = NULL;
	return a;
}

ptrCauHoiThi rightRotate(ptrCauHoiThi y) {
	ptrCauHoiThi x = y->left;
	ptrCauHoiThi T2 = x->right;

	// Tien hanh xoay phai
	x->right = y;
	y->left = T2;

	// Cap nhap chieu cao
	y->height = max(height(y->left), height(y->right)) + 1;
	x->height = max(height(x->left), height(x->right)) + 1;

	// Tra ve nut Root moi
	return x;
}
ptrCauHoiThi leftRotate(ptrCauHoiThi x) {
	ptrCauHoiThi y = x->right;
	ptrCauHoiThi T2 = y->left;

	// Tien hanh xoay trai
	y->left = x;
	x->right = T2;

	// Cap nhap chieu cao
	x->height = max(height(x->left), height(x->right)) + 1;
	y->height = max(height(y->left), height(y->right)) + 1;

	// Tra ve nut Root moi
	return y;
}
int getBalance(ptrCauHoiThi a) {
	if (a == NULL) {
		return 0;
	}
	return height(a->left) - height(a->right);
}

// Them | Xoa
ptrCauHoiThi insertNodeAVL(ptrCauHoiThi a, int id_input, string mamh_input, string noidung_input, string A_input, string B_input, string C_input, string D_input, string dapan_input) {

	if (a == NULL) {
		return newNode(id_input, mamh_input, noidung_input, A_input, B_input, C_input, D_input, dapan_input);
	}
	if (id_input < a->CH.id)
		a->left = insertNodeAVL(a->left, id_input, mamh_input, noidung_input, A_input, B_input, C_input, D_input, dapan_input);
	else if (id_input > a->CH.id)
		a->right = insertNodeAVL(a->right, id_input, mamh_input, noidung_input, A_input, B_input, C_input, D_input, dapan_input);
	else // Da co ID ton tai
		return a;

	// Cap nhap chieu cao node a
	a->height = 1 + max(height(a->left), height(a->right));

	// Lay gia tri Can bang cua Node a
	int bf = getBalance(a);

	// Tien hanh Can bang lai Cay

	// Left - Left
	if (bf > 1 && id_input < a->left->CH.id)
		return rightRotate(a);

	// Right - Right
	if (bf < -1 && id_input > a->right->CH.id)
		return leftRotate(a);

	// Left - Right
	if (bf > 1 && id_input > a->left->CH.id) {
		a->left = leftRotate(a->left);
		return rightRotate(a);
	}

	// Right - Left
	if (bf < -1 && id_input < a->right->CH.id) {
		a->right = rightRotate(a->right);
		return leftRotate(a);
	}
	return a;
}
ptrCauHoiThi minValueNode(ptrCauHoiThi a) {
	ptrCauHoiThi current = a;

	while (current->left != NULL) {
		current = current->left;
	}
	return current;
}
ptrCauHoiThi deleteNodeAVL(ptrCauHoiThi root, int id_input) {
	if (root == NULL) {
		return root;
	}

	if (id_input < root->CH.id)
		root->left = deleteNodeAVL(root->left, id_input);
	else if (id_input > root->CH.id)
		root->right = deleteNodeAVL(root->right, id_input);
	// Id_input == ID
	else {
		// Chi co mot Con hoac ko co Con
		if ((root->left == NULL) || (root->right == NULL)) {
			ptrCauHoiThi tmp = root->left ? root->left : root->right;

			// Truong hop ko co Con
			if (tmp == NULL) {
				tmp = root;
				root = NULL;
			}
			// Truong hop co 1 Con
			else
				*root = *tmp; // Copy gia tri cua dua Con co gia tri

			free(tmp);
		}
		// Co hai Con
		else {
			// Tim node cuc Trai
			ptrCauHoiThi tmp = minValueNode(root->right);

			// Copy gia tri
			root->CH.id = tmp->CH.id;
			root->CH.mamh = tmp->CH.mamh;
			root->CH.noidung = tmp->CH.noidung;
			root->CH.dapan = tmp->CH.dapan;
			root->CH.A = tmp->CH.A;
			root->CH.B = tmp->CH.B;
			root->CH.C = tmp->CH.C;
			root->CH.D = tmp->CH.D;

			root->right = deleteNodeAVL(root->right, tmp->CH.id);
		}
	}

	// Neu xoa xong, Cay chi con 1 Node
	if (root == NULL) {
		return root;
	}

	// Cap nhap chieu cao Node hien tai
	root->height = 1 + max(height(root->left), height(root->right));

	// Lay gia tri Can bang cua node hien tai
	int bf = getBalance(root);

	// Tien hanh can bang lai Cay

	// Left - Left
	if (bf > 1 && getBalance(root->left) >= 0)
		return rightRotate(root);

	// Left - Right
	if (bf > 1 && getBalance(root->left) < 0) {
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}

	// Right - Right
	if (bf < -1 && getBalance(root->right) <= 0)
		return leftRotate(root);

	// Right - Left
	if (bf < -1 && getBalance(root->right) > 0) {
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}

	return root;
}

// Duyet Cay 
void duyetLNR(ptrCauHoiThi p) {
	if (p != NULL) {
		duyetLNR(p->left);
		cout << p->CH.id << " ";
		cout << p->CH.mamh << " ";
		cout << p->CH.noidung << " ";
		cout << p->CH.A << " ";
		cout << p->CH.B << " ";
		cout << p->CH.C << " ";
		cout << p->CH.D << " ";
		cout << p->CH.dapan << endl;
		duyetLNR(p->right);
	}
}
void duyetNLR(ptrCauHoiThi p) {
	if (p != NULL) {
		cout << p->CH.id << " ";
		duyetNLR(p->left);
		duyetNLR(p->right);
	}
}
void duyetLRN(ptrCauHoiThi p) {
	if (p != NULL) {
		duyetLRN(p->left);
		duyetLRN(p->right);
		cout << p->CH.id << " ";
	}
}

// Tim gia tri lon nhat va be nhat
int findMax(ptrCauHoiThi p) {
	if (p != NULL) {
		if (p->right != NULL) {
			return findMax(p->right);
		}
		else
			return p->CH.id;
	}
}
int findMin(ptrCauHoiThi p) {
	if (p != NULL) {
		if (p->left != NULL) {
			return findMin(p->left);
		}
		else {
			return p->CH.id;
		}
	}
}

// Dem node
int demNode(ptrCauHoiThi p) {
	if (p != NULL) {
		if (p->left == NULL && p->right == NULL) {
			return 1;
		}
		else
			return 1 + demNode(p->left) + demNode(p->right);
	}
	else
		return 0;
}
int demNode_theoMaMon(ptrCauHoiThi root, string mamon) {
	int soluongcauhoi = 0;
	const int STACKSIZE = 500;
	ptrCauHoiThi Stack[STACKSIZE];
	ptrCauHoiThi p = root;
	int sp = -1;	 // Khoi tao Stack rong
	do {
		while (p != NULL) {
			Stack[++sp] = p;
			p = p->left;
		}
		if (sp != -1) {
			p = Stack[sp--];
			// xử lý nút p
			if (p->CH.mamh == mamon) {
				soluongcauhoi++;
			}
			p = p->right;
		}
		else
			break;
	} while (true);
	return soluongcauhoi;
}

// Tim kiem
bool SearchNode(ptrCauHoiThi p, int id_input) {
	while (p != NULL) {
		if (p->CH.id == id_input) {
			return true;
		}
		else {
			if (p->CH.id > id_input) {
				p = p->left;
			}
			else {
				p = p->right;
			}
		}
	}
	return false;
}
ptrCauHoiThi SearchNodeInfo(ptrCauHoiThi p, int id_input) {
	while (p != NULL) {
		if (p->CH.id == id_input) {
			return p;
		}
		else {
			if (p->CH.id > id_input) {
				p = p->left;
			}
			else {
				p = p->right;
			}
		}
	}
	return NULL;
}
bool duyetLNR_Tim_MaMon(ptrCauHoiThi root, string mamon) {
	const int STACKSIZE = 500;
	ptrCauHoiThi Stack[STACKSIZE];
	ptrCauHoiThi p = root;
	int sp = -1;	 // Khoi tao Stack rong
	do {
		while (p != NULL) {
			Stack[++sp] = p;
			p = p->left;
		}
		if (sp != -1) {
			p = Stack[sp--];
			// Kiem tra co ton tai Cau hoi co Mamon ko
			if (p->CH.mamh == mamon) {
				return true;
			}
			p = p->right;
		}
		else break;
	} while (true);

	return false;
}


// RanDom Number
int randomNumber(ptrCauHoiThi root) {
	int ID_random;

	// Tao ID_random khong bi trung trong Cay
	while (true) {
		ID_random = rand() % 9999 + 1000;
		if (SearchNode(root, ID_random))
			continue;
		else
			break;
	}
	return ID_random;
}

// random Cau Hoi
bool checktrungdiachi(int arr[], int n, int id) {
	for (int i = 0; i < n; i++) {
		if (arr[i] == id) {
			return true;
		}
	}
	return false;
}
void randomCauHoi(ptrCauHoiThi cauhoihienco[], ptrCauHoiThi cauhoithi[], int socauhoi) {
	int id;
	int index = 0;

	int* diachicauhoirandom = new int[socauhoi];


	while (true) {
		id = rand() % (socauhoi);
		if (checktrungdiachi(diachicauhoirandom, socauhoi, id) == true) {
			continue;
		}
		diachicauhoirandom[index] = id;

		if (index == (socauhoi - 1)) {
			break;
		}
		index++;
	}

	for (int i = 0; i < socauhoi; i++) {
		cauhoithi[i] = cauhoihienco[diachicauhoirandom[i]];
	}

	delete[] diachicauhoirandom;
}

void Hien_thi_thong_tin_MON_HOC_dang_duoc_them_CAU_HOI(string ma, string ten) {
	setbkcolor(15);
	setcolor(0);
	settextstyle(10, 0, 2);
	// 185 220
	outtextxy(1230, 420, (char*)"THEM CAU HOI");
	setcolor(4);
	outtextxy(1130, 460, (char*)ma.c_str());
	outtextxy(1130, 490, (char*)ten.c_str());
}
void Hien_thi_thong_tin_MON_HOC_dang_duoc_xoa_CAU_HOI(string ma, string ten) {
	setbkcolor(15);
	setcolor(0);
	settextstyle(10, 0, 2);
	// 185 220
	outtextxy(1230, 420, (char*)"XOA CAU HOI");
	setcolor(4);
	outtextxy(1130, 460, (char*)ma.c_str());
	outtextxy(1130, 490, (char*)ten.c_str());
}
void Hien_thi_thong_tin_MON_HOC_dang_duoc_sua_CAU_HOI(string ma, string ten) {
	setbkcolor(15);
	setcolor(0);
	settextstyle(10, 0, 2);
	// 185 220
	outtextxy(1230, 420, (char*)"SUA CAU HOI");
	setcolor(4);
	outtextxy(1130, 460, (char*)ma.c_str());
	outtextxy(1130, 490, (char*)ten.c_str());
}

void duyetLNR_Gan_DIA_CHI(ptrCauHoiThi root, ptrCauHoiThi arr[]) {
	int index = 0; // dia chi cua mang arr
	const int STACKSIZE = 500;
	ptrCauHoiThi Stack[STACKSIZE];
	ptrCauHoiThi p = root;
	int sp = -1;	 // Khoi tao Stack rong
	do {
		while (p != NULL) {
			Stack[++sp] = p;
			p = p->left;
		}
		if (sp != -1) {
			p = Stack[sp--];
			// xử lý nút p
			arr[index] = *&p; // gan dia chi p vao mang
			index++; // tang dia chi cua mang
			p = p->right;
		}
		else break;
	} while (true);
}
void duyetLNR_Gan_DIA_CHI_theoMaMon(ptrCauHoiThi root, ptrCauHoiThi arr[], string mamon) {
	int index = 0; // dia chi cua mang arr
	const int STACKSIZE = 500;
	ptrCauHoiThi Stack[STACKSIZE];
	ptrCauHoiThi p = root;
	int sp = -1;	 // Khoi tao Stack rong
	do {
		while (p != NULL) {
			Stack[++sp] = p;
			p = p->left;
		}
		if (sp != -1) {
			p = Stack[sp--];
			// xử lý nút p
			if (p->CH.mamh == mamon) {
				arr[index] = *&p; // gan dia chi p vao mang
				index++; // tang dia chi cua mang
			}
			p = p->right;
		}
		else break;
	} while (true);
}

void hienDsCauHoi_graphic(ptrCauHoiThi root) {

	// Gan dia chi cac Node trong Cay vao Mang arr
	int soluong = demNode(root);
	ptrCauHoiThi* arr = new ptrCauHoiThi[soluong];
	duyetLNR_Gan_DIA_CHI(root, arr);

	// In ra man hinh Graphic
	setbkcolor(15);
	setcolor(0);
	settextstyle(8, 0, 2);

	for (int i = 0; i < soluong && i < 9; i++) {
		outtextxy(75, 400 + i * 40, (char*)(to_string(arr[i]->CH.id)).c_str());
		outtextxy(190, 400 + i * 40, (char*)(arr[i]->CH.mamh).c_str());
		outtextxy(300, 400 + i * 40, (char*)(arr[i]->CH.noidung).c_str());
	}
}
void hienDsCauHoi_graphic_trang1(ptrCauHoiThi root, ptrCauHoiThi arr[], int soluong) {
	// In ra man hinh Graphic
	setbkcolor(15);
	setcolor(0);
	settextstyle(8, 0, 2);

	string noidung_hienthi = "";
	string tmp = "...";

	for (int i = 0; i < soluong && i < 9; i++) {
		outtextxy(75, 400 + i * 40, (char*)(to_string(arr[i]->CH.id)).c_str());
		outtextxy(190, 400 + i * 40, (char*)(arr[i]->CH.mamh).c_str());
		if (arr[i]->CH.noidung.length() > 60) {
			noidung_hienthi = arr[i]->CH.noidung;
			// Xoa phan noi dung tu ki tu 59 den het chuoi va noi voi string "..."
			noidung_hienthi.erase(noidung_hienthi.begin() + 59, noidung_hienthi.begin() + noidung_hienthi.length());
			noidung_hienthi.append(tmp);
			outtextxy(300, 400 + i * 40, (char*)(noidung_hienthi).c_str());
		}
		else {
			outtextxy(300, 400 + i * 40, (char*)(arr[i]->CH.noidung).c_str());
		}
	}
}
void hienDsCauHoi_graphic_trang2(ptrCauHoiThi root, ptrCauHoiThi arr[], int soluong) {

	// In ra man hinh Graphic
	setbkcolor(15);
	setcolor(0);
	settextstyle(8, 0, 2);

	string noidung_hienthi = "";
	string tmp = "...";

	int j = 0;
	for (int i = 9; (i < soluong) && (i < 18); i++) {
		outtextxy(75, 400 + j * 40, (char*)(to_string(arr[i]->CH.id)).c_str());
		outtextxy(190, 400 + j * 40, (char*)(arr[i]->CH.mamh).c_str());
		if (arr[i]->CH.noidung.length() > 60) {
			noidung_hienthi = arr[i]->CH.noidung;
			// Xoa phan noi dung tu ki tu 59 den het chuoi va noi voi string "..."
			noidung_hienthi.erase(noidung_hienthi.begin() + 59, noidung_hienthi.begin() + noidung_hienthi.length());
			noidung_hienthi.append(tmp);
			outtextxy(300, 400 + j * 40, (char*)(noidung_hienthi).c_str());
		}
		else {
			outtextxy(300, 400 + j * 40, (char*)(arr[i]->CH.noidung).c_str());
		}
		j++;
	}
}
void hienDsCauHoi_graphic_trang3(ptrCauHoiThi root, ptrCauHoiThi arr[], int soluong) {

	// In ra man hinh Graphic
	setbkcolor(15);
	setcolor(0);
	settextstyle(8, 0, 2);

	string noidung_hienthi = "";
	string tmp = "...";

	int j = 0;
	for (int i = 18; (i < soluong) && (i < 27); i++) {
		outtextxy(75, 400 + j * 40, (char*)(to_string(arr[i]->CH.id)).c_str());
		outtextxy(190, 400 + j * 40, (char*)(arr[i]->CH.mamh).c_str());
		if (arr[i]->CH.noidung.length() > 60) {
			noidung_hienthi = arr[i]->CH.noidung;
			// Xoa phan noi dung tu ki tu 59 den het chuoi va noi voi string "..."
			noidung_hienthi.erase(noidung_hienthi.begin() + 59, noidung_hienthi.begin() + noidung_hienthi.length());
			noidung_hienthi.append(tmp);
			outtextxy(300, 400 + j * 40, (char*)(noidung_hienthi).c_str());
		}
		else {
			outtextxy(300, 400 + j * 40, (char*)(arr[i]->CH.noidung).c_str());
		}
		j++;
	}
}
void hienDsCauHoi_graphic_trang4(ptrCauHoiThi root, ptrCauHoiThi arr[], int soluong) {

	// In ra man hinh Graphic
	setbkcolor(15);
	setcolor(0);
	settextstyle(8, 0, 2);

	string noidung_hienthi = "";
	string tmp = "...";

	int j = 0;
	for (int i = 27; (i < soluong) && (i < 36); i++) {
		outtextxy(75, 400 + j * 40, (char*)(to_string(arr[i]->CH.id)).c_str());
		outtextxy(190, 400 + j * 40, (char*)(arr[i]->CH.mamh).c_str());
		if (arr[i]->CH.noidung.length() > 60) {
			noidung_hienthi = arr[i]->CH.noidung;
			// Xoa phan noi dung tu ki tu 59 den het chuoi va noi voi string "..."
			noidung_hienthi.erase(noidung_hienthi.begin() + 59, noidung_hienthi.begin() + noidung_hienthi.length());
			noidung_hienthi.append(tmp);
			outtextxy(300, 400 + j * 40, (char*)(noidung_hienthi).c_str());
		}
		else {
			outtextxy(300, 400 + j * 40, (char*)(arr[i]->CH.noidung).c_str());
		}
		j++;
	}
}
void hienDsCauHoi_graphic_trang5(ptrCauHoiThi root, ptrCauHoiThi arr[], int soluong) {

	// In ra man hinh Graphic
	setbkcolor(15);
	setcolor(0);
	settextstyle(8, 0, 2);

	string noidung_hienthi = "";
	string tmp = "...";

	int j = 0;
	for (int i = 36; (i < soluong) && (i < 45); i++) {
		outtextxy(75, 400 + j * 40, (char*)(to_string(arr[i]->CH.id)).c_str());
		outtextxy(190, 400 + j * 40, (char*)(arr[i]->CH.mamh).c_str());
		if (arr[i]->CH.noidung.length() > 60) {
			noidung_hienthi = arr[i]->CH.noidung;
			// Xoa phan noi dung tu ki tu 59 den het chuoi va noi voi string "..."
			noidung_hienthi.erase(noidung_hienthi.begin() + 59, noidung_hienthi.begin() + noidung_hienthi.length());
			noidung_hienthi.append(tmp);
			outtextxy(300, 400 + j * 40, (char*)(noidung_hienthi).c_str());
		}
		else {
			outtextxy(300, 400 + j * 40, (char*)(arr[i]->CH.noidung).c_str());
		}
		j++;
	}
}

void ChuyenTrang_DsCauHoi(ptrCauHoiThi root, int trangthai) {
	int soluong = demNode(root);
	ptrCauHoiThi* arr = new ptrCauHoiThi[soluong];
	duyetLNR_Gan_DIA_CHI(root, arr);

	// Sap xep theo Ma Mon Hoc
	ptrCauHoiThi tmp = NULL;
	for (int i = 0; i < soluong - 1; i++) {
		for (int j = i + 1; j < soluong; j++) {
			if (arr[i]->CH.mamh > arr[j]->CH.mamh) {
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}

	setbkcolor(7);
	setcolor(0);
	settextstyle(8, 0, 3);
	outtextxy(555, 785, (char*)"/5");

	switch (trangthai) {
	case 1:
		hienDsCauHoi_graphic_trang1(root, arr, soluong);
		setbkcolor(7);
		setcolor(0);
		settextstyle(8, 0, 3);
		outtextxy(540, 785, (char*)"1");
		break;
	case 2:
		hienDsCauHoi_graphic_trang2(root, arr, soluong);
		setbkcolor(7);
		setcolor(0);
		settextstyle(8, 0, 3);
		outtextxy(540, 785, (char*)"2");
		break;
	case 3:
		hienDsCauHoi_graphic_trang3(root, arr, soluong);
		setbkcolor(7);
		setcolor(0);
		settextstyle(8, 0, 3);
		outtextxy(540, 785, (char*)"3");
		break;
	case 4:
		hienDsCauHoi_graphic_trang4(root, arr, soluong);
		setbkcolor(7);
		setcolor(0);
		settextstyle(8, 0, 3);
		outtextxy(540, 785, (char*)"4");
		break;
	case 5:
		hienDsCauHoi_graphic_trang5(root, arr, soluong);
		setbkcolor(7);
		setcolor(0);
		settextstyle(8, 0, 3);
		outtextxy(540, 785, (char*)"5");
		break;
	}
	// Xoa mang
	delete[] arr;
}

void docFileDsCauHoi(ptrCauHoiThi& root) {
	fstream f;
	f.open("CauHoi.txt", ios::in);
	int cnt = 0;
	char ch;

	// Dem file co bao nhieu dong
	while (f.get(ch)) {
		if (ch == '\n') {
			++cnt;
		}
	}

	// Dua con tro chuot ve dau file
	f.clear();
	f.seekg(0, ios::beg);

	//fix loi ghi du lieu
	string mamh_tmp = "";
	bool check = false;
	bool check2 = false;

	int id = 0;
	string mamh = "";
	string noidung = "";
	string A = "";
	string B = "";
	string C = "";
	string D = "";
	string dapan = "";

	// Bat dau ghi du lieu vao danh sach
	for (int i = 0; i < cnt; i++) {
		id = randomNumber(root);
		getline(f, mamh, '|');
		getline(f, noidung, '|');
		getline(f, A, '|');
		getline(f, B, '|');
		getline(f, C, '|');
		getline(f, D, '|');
		getline(f, dapan, '|');
		f.ignore();

		root = insertNodeAVL(root, id, mamh, noidung, A, B, C, D, dapan);
	}
	f.close();
}
void ghiFileDsCauHoi(ptrCauHoiThi root) {
	fstream f;
	f.open("CauHoi.txt", ios::out);


	int soluong = demNode(root);
	ptrCauHoiThi* arr = new ptrCauHoiThi[soluong];
	duyetLNR_Gan_DIA_CHI(root, arr);

	// Sap xep theo Ma Mon Hoc
	ptrCauHoiThi tmp = NULL;
	for (int i = 0; i < soluong - 1; i++) {
		for (int j = i + 1; j < soluong; j++) {
			if (arr[i]->CH.mamh > arr[j]->CH.mamh) {
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}

	for (int i = 0; i < soluong; i++) {
		f << arr[i]->CH.mamh << "|";
		f << arr[i]->CH.noidung << "|";
		f << arr[i]->CH.A << "|";
		f << arr[i]->CH.B << "|";
		f << arr[i]->CH.C << "|";
		f << arr[i]->CH.D << "|";
		f << arr[i]->CH.dapan << "|";
		f << endl;
	}

	delete[] arr;
}


//====================================THI TRAC NGHIEM==================================================
int phut = 0;
int giay = 0;
bool stop = false;

ptrDiemThi taoNodeDiemThi(string mamh_input, float diem_input) {
	Diem a;
	a.diem = diem_input;
	a.mamh = mamh_input;

	ptrDiemThi tmp = new nodeDiemThi;
	tmp->info = a;
	tmp->next = NULL;
	return tmp;
}
void insertLastDiemThi(ptrDiemThi& a, ptrDiemThi tmp) {
	if (a == NULL) {
		a = tmp;
	}
	else {
		ptrDiemThi p = a;
		while (p->next != NULL) {
			p = p->next;
		}
		p->next = tmp;
	}
}
ptrDiemThi TimKiemDiemSinhVien_TraVeNode(ptrSinhVien sv, string mamonthi) {
	ptrDiemThi p = sv->info.ds_diemthi;

	for (p; p != NULL; p = p->next) {
		if (strcmp((p->info.mamh).c_str(), mamonthi.c_str()) == 0) {
			return p;
		}
	}
	return NULL;
}
bool TimKiemDiemSinhVien(DS_Lop dslop, string masinhvien, string mamonhoc, int vitrilop) {
	ptrSinhVien sinhvien_dangtruycap = TimKiemMaSinhVien_TraVeNode(dslop, masinhvien, vitrilop); 
	ptrDiemThi p = sinhvien_dangtruycap->info.ds_diemthi;
	for (p; p != NULL; p = p->next) {
		if (strcmp((p->info.mamh).c_str(), mamonhoc.c_str()) == 0) {
			return true;
		}
	}
	return false;
}

void HienThiKetQuaThi(float diem, string mamonthi, string tenmonthi) {
	// Set mau background
	setbkcolor(7);
	cleardevice();

	// chu dang nhap
	setcolor(0);
	settextstyle(10, 0, 6);
	outtextxy(670, 170, (char*)"KET QUA");

	setcolor(15);
	rectangle(430, 250, 1120, 570);


	// Nut ENTER
	setfillstyle(1, 3);
	bar(550, 600, 760, 650);
	setcolor(15);
	rectangle(550, 600, 760, 650);
	rectangle(549, 599, 761, 651);

	setbkcolor(3);
	settextstyle(10, 0, 4);
	setcolor(15);
	outtextxy(600, 610, (char*)"DAP AN");

	// Nut THOAT
	setfillstyle(1, 3);
	bar(800, 600, 1010, 650);
	setcolor(15);
	rectangle(800, 600, 1010, 650);
	rectangle(799, 599, 1011, 651);

	setbkcolor(3);

	settextstyle(10, 0, 4);
	setcolor(15);
	outtextxy(860, 610, (char*)"THOAT");

	string diemhienthi = "";
	diemhienthi = to_string(diem);
	diemhienthi.erase(4, 8);

	// Diem 
	setbkcolor(7);
	settextstyle(10, 0, 7);
	setcolor(4);
	outtextxy(700, 300, (char*)(diemhienthi).c_str());

	setbkcolor(7);
	setcolor(0);
	settextstyle(10, 0, 3);
	setcolor(1);

	outtextxy(650, 460, (char*)(mamonthi).c_str());
	outtextxy(650, 490, (char*)(tenmonthi).c_str());

	setcolor(0);
	outtextxy(550, 460, (char*)"MA");
	outtextxy(550, 490, (char*)"MON");
}
bool Lua_chon_CO_hoac_KHONG_cua_thong_bao_trong_ham_chuc_nang_thitracnghiem() {
	int xmouse = -1;
	int ymouse = -1;
	while (true) {

		// Dong Ho
		setbkcolor(7);
		setcolor(0);
		settextstyle(10, 0, 6);
		outtextxy(1230, 10, (char*)(to_string(phut)).c_str());
		outtextxy(1290, 10, (char*)":");
		outtextxy(1330, 10, (char*)(to_string(giay)).c_str());


		if (ismouseclick(WM_LBUTTONDOWN)) {
			getmouseclick(WM_LBUTTONDOWN, xmouse, ymouse);
			// Nguoi dung chon nut CO rectangle(1140, 300 + 230, 1290, 350 + 230);
			if (xmouse >= 1140 && xmouse <= 1290 && ymouse >= 300 + 230 && ymouse <= 350 + 230) {
				return true;
			}
			// Nguoi dung chon nut KHONG rectangle(1320, 300, 1470, 350);
			if (xmouse >= 1320 && xmouse <= 1470 && ymouse >= 300 + 230 && ymouse <= 350 + 230) {
				return false;
			}
		}
	}
}
bool Lua_chon_CO_hoac_KHONG_cua_thong_bao_trong_ham_chuc_nang_xemdapan() {
	int xmouse = -1;
	int ymouse = -1;
	while (true) {


		if (ismouseclick(WM_LBUTTONDOWN)) {
			getmouseclick(WM_LBUTTONDOWN, xmouse, ymouse);
			// Nguoi dung chon nut CO rectangle(1140, 300 + 230, 1290, 350 + 230);
			if (xmouse >= 1140 && xmouse <= 1290 && ymouse >= 300 + 230 && ymouse <= 350 + 230) {
				return true;
			}
			// Nguoi dung chon nut KHONG rectangle(1320, 300, 1470, 350);
			if (xmouse >= 1320 && xmouse <= 1470 && ymouse >= 300 + 230 && ymouse <= 350 + 230) {
				return false;
			}
		}
	}
}

void printClock() {
	while (true) {
		giay--;
		if (giay < 0) {
			giay = 59;
			phut--;
			if (phut < 0) {
				phut = 59;
			}
		}
		Sleep(1000);
		// het thoi gian hoac nguoi dung nop bai => stop = true (thoat chuong trinh thi)
		if ((phut == 0 && giay == 0) || stop == true) {
			stop = true;
			break;
		}
		// xoa dong ho
		setfillstyle(1, 7);
		bar(1110, 10, 1500, 70);
	}
}


//=====================================XEM DIEM===========================================================

int SL_DsDiemThi(ptrDiemThi a) {
	int cnt = 0;
	while (a != NULL) {
		++cnt;
		a = a->next;
	}
	return cnt;
}
float TimKiemDiemSinhVien_theoMaMon(ptrSinhVien arr[], string mamonthi, int index) {
	ptrDiemThi p = arr[index]->info.ds_diemthi;

	for (p; p != NULL; p = p->next) {
		if (strcmp((p->info.mamh).c_str(), mamonthi.c_str()) == 0) {
			return p->info.diem;
		}
	}
	return -1;
}
void hienDsSinhVien_XemDiem_graphic_trang1(DS_Lop dslop, ptrSinhVien arr[], int soluong, int vitrilop, string mamonthi) {
	setbkcolor(15);
	setcolor(0);
	settextstyle(8, 0, 2);

	float diemSinhVien = 0;
	string diemhienthi = "";
	
	int cnt = 0;
	int j = 0;
	for (int i = 0; i < soluong && cnt < 9; i++) {
		outtextxy(90, 400 + i * 40, (char*)(arr[i]->info.masv).c_str());
		outtextxy(285, 400 + i * 40, (char*)(arr[i]->info.phai).c_str());
		outtextxy(390, 400 + i * 40, (char*)(arr[i]->info.ho).c_str());
		outtextxy(770, 400 + i * 40, (char*)(arr[i]->info.ten).c_str());

		diemSinhVien = TimKiemDiemSinhVien_theoMaMon(arr, mamonthi, i);
		diemhienthi = to_string(diemSinhVien);
		diemhienthi.erase(4, 8);

		if (diemSinhVien != -1) {
			outtextxy(950, 400 + i * 40, (char*)(diemhienthi).c_str());
		}
		else {
			outtextxy(920, 400 + i * 40, (char*)"Chua thi");

		}

		j++;
		cnt++;
	}
}
void hienDsSinhVien_XemDiem_graphic_trang2(DS_Lop dslop, ptrSinhVien arr[], int soluong, int vitrilop, string mamonthi) {
	setbkcolor(15);
	setcolor(0);
	settextstyle(8, 0, 2);

	float diemSinhVien = 0;
	string diemhienthi = "";

	int cnt = 0;
	int j = 0;
	for (int i = 9; i < soluong && cnt < 18; i++) {
		outtextxy(90, 400 + i * 40, (char*)(arr[i]->info.masv).c_str());
		outtextxy(285, 400 + i * 40, (char*)(arr[i]->info.phai).c_str());
		outtextxy(390, 400 + i * 40, (char*)(arr[i]->info.ho).c_str());
		outtextxy(770, 400 + i * 40, (char*)(arr[i]->info.ten).c_str());

		diemSinhVien = TimKiemDiemSinhVien_theoMaMon(arr, mamonthi, i);
		diemhienthi = to_string(diemSinhVien);
		diemhienthi.erase(4, 8);

		if (diemSinhVien != -1) {
			outtextxy(950, 400 + i * 40, (char*)(diemhienthi).c_str());
		}
		else {
			outtextxy(920, 400 + i * 40, (char*)"Chua thi");

		}

		j++;
		cnt++;
	}
}
void hienDsSinhVien_XemDiem_graphic_trang3(DS_Lop dslop, ptrSinhVien arr[], int soluong, int vitrilop, string mamonthi) {
	setbkcolor(15);
	setcolor(0);
	settextstyle(8, 0, 2);

	float diemSinhVien = 0;
	string diemhienthi = "";

	int cnt = 0;
	int j = 0;
	for (int i = 18; i < soluong && cnt < 27; i++) {
		outtextxy(90, 400 + i * 40, (char*)(arr[i]->info.masv).c_str());
		outtextxy(285, 400 + i * 40, (char*)(arr[i]->info.phai).c_str());
		outtextxy(390, 400 + i * 40, (char*)(arr[i]->info.ho).c_str());
		outtextxy(770, 400 + i * 40, (char*)(arr[i]->info.ten).c_str());

		diemSinhVien = TimKiemDiemSinhVien_theoMaMon(arr, mamonthi, i);
		diemhienthi = to_string(diemSinhVien);
		diemhienthi.erase(4, 8);

		if (diemSinhVien != -1) {
			outtextxy(950, 400 + i * 40, (char*)(diemhienthi).c_str());
		}
		else {
			outtextxy(920, 400 + i * 40, (char*)"Chua thi");

		}

		j++;
		cnt++;
	}
}
void hienDsSinhVien_XemDiem_graphic_trang4(DS_Lop dslop, ptrSinhVien arr[], int soluong, int vitrilop, string mamonthi) {
	setbkcolor(15);
	setcolor(0);
	settextstyle(8, 0, 2);

	float diemSinhVien = 0;
	string diemhienthi = "";

	int cnt = 0;
	int j = 0;
	for (int i = 27; i < soluong && cnt < 36; i++) {
		outtextxy(90, 400 + i * 40, (char*)(arr[i]->info.masv).c_str());
		outtextxy(285, 400 + i * 40, (char*)(arr[i]->info.phai).c_str());
		outtextxy(390, 400 + i * 40, (char*)(arr[i]->info.ho).c_str());
		outtextxy(770, 400 + i * 40, (char*)(arr[i]->info.ten).c_str());

		diemSinhVien = TimKiemDiemSinhVien_theoMaMon(arr, mamonthi, i);
		diemhienthi = to_string(diemSinhVien);
		diemhienthi.erase(4, 8);

		if (diemSinhVien != -1) {
			outtextxy(950, 400 + i * 40, (char*)(diemhienthi).c_str());
		}
		else {
			outtextxy(920, 400 + i * 40, (char*)"Chua thi");

		}

		j++;
		cnt++;
	}
}
void hienDsSinhVien_XemDiem_graphic_trang5(DS_Lop dslop, ptrSinhVien arr[], int soluong, int vitrilop, string mamonthi) {
	setbkcolor(15);
	setcolor(0);
	settextstyle(8, 0, 2);

	float diemSinhVien = 0;
	string diemhienthi = "";

	int cnt = 0;
	int j = 0;
	for (int i = 36; i < soluong && cnt < 45; i++) {
		outtextxy(90, 400 + i * 40, (char*)(arr[i]->info.masv).c_str());
		outtextxy(285, 400 + i * 40, (char*)(arr[i]->info.phai).c_str());
		outtextxy(390, 400 + i * 40, (char*)(arr[i]->info.ho).c_str());
		outtextxy(770, 400 + i * 40, (char*)(arr[i]->info.ten).c_str());

		diemSinhVien = TimKiemDiemSinhVien_theoMaMon(arr, mamonthi, i);
		diemhienthi = to_string(diemSinhVien);
		diemhienthi.erase(4, 8);

		if (diemSinhVien != -1) {
			outtextxy(950, 400 + i * 40, (char*)(diemhienthi).c_str());
		}
		else {
			outtextxy(920, 400 + i * 40, (char*)"Chua thi");

		}

		j++;
		cnt++;
	}
}

void ChuyenTrang_DsSinhVien_XemDiem(DS_Lop dslop, int vitrilop, int trangthai, string mamonthi) {
	int soluong = SL_DsSinhVien(dslop.DS[vitrilop]->ds_sinhvien);
	ptrSinhVien* arr = new ptrSinhVien[soluong];

	// Sao chep Danh sach sinh vien vao mang arr
	int index = 0;
	ptrSinhVien p = dslop.DS[vitrilop]->ds_sinhvien;
	for (p; p != NULL; p = p->next) {
		arr[index] = p;

		if (index == soluong) {
			break;
		}
		else {
			index++;
		}
	}

	// Sap xep danh sach sinh vien theo MA SINH VIEN
	ptrSinhVien tmp = NULL;
	for (int i = 0; i < soluong - 1; i++) {
		for (int j = i + 1; j < soluong; j++) {
			if (arr[i]->info.masv > arr[j]->info.masv) {
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}

	setbkcolor(7);
	setcolor(0);
	settextstyle(8, 0, 3);
	outtextxy(555, 785, (char*)"/5");

	switch (trangthai) {
	case 1:
		hienDsSinhVien_XemDiem_graphic_trang1(dslop, arr, soluong, vitrilop, mamonthi);
		setbkcolor(7);
		setcolor(0);
		settextstyle(8, 0, 3);
		outtextxy(540, 785, (char*)"1");
		break;
	case 2:
		hienDsSinhVien_XemDiem_graphic_trang2(dslop, arr, soluong, vitrilop, mamonthi);
		setbkcolor(7);
		setcolor(0);
		settextstyle(8, 0, 3);
		outtextxy(540, 785, (char*)"2");
		break;
	case 3:
		hienDsSinhVien_XemDiem_graphic_trang3(dslop, arr, soluong, vitrilop, mamonthi);
		setbkcolor(7);
		setcolor(0);
		settextstyle(8, 0, 3);
		outtextxy(540, 785, (char*)"3");
		break;
	case 4:
		hienDsSinhVien_XemDiem_graphic_trang4(dslop, arr, soluong, vitrilop, mamonthi);
		setbkcolor(7);
		setcolor(0);
		settextstyle(8, 0, 3);
		outtextxy(540, 785, (char*)"4");
		break;
	case 5:
		hienDsSinhVien_XemDiem_graphic_trang5(dslop, arr, soluong, vitrilop, mamonthi);
		setbkcolor(7);
		setcolor(0);
		settextstyle(8, 0, 3);
		outtextxy(540, 785, (char*)"5");
		break;
	}

	// xoa mang
	delete[]arr;
}
void DuyetDiemThi(ptrDiemThi head, ptrDiemThi* a, int& index) {
	if (head == NULL) {
		return;
	}
	a[index++] = head;
	DuyetDiemThi(head->next, a, index);
}

void ghiFileDsDiemThi(DS_Lop dslop) {
	int soluong_sinhvien = 0;
	int soluong_diemthi = 0;
	int indexArrDssv = 0;
	int indexArrDsDiemThi = 0;
	int dem = 0;

	fstream f;
	f.open("DiemThi.txt", ios::out);
	for (int i = 0; i < dslop.n; i++) {

		// Neu trong lop hoc co Sinh vien thi moi thuc hien
		if (dslop.DS[i]->ds_sinhvien != NULL) {
			soluong_sinhvien = SL_DsSinhVien(dslop.DS[i]->ds_sinhvien);
			ptrSinhVien* dssv = new ptrSinhVien[soluong_sinhvien];

			// Cho danh sach Sinh Vien vao mang dssv
			indexArrDssv = 0;
			DuyetSinhVien(dslop.DS[i]->ds_sinhvien, dssv, indexArrDssv);
			for (int j = 0; j < soluong_sinhvien; j++) {

				// Neu trong Sinh Vien co Diem thi moi thuc hien
				if (dssv[j]->info.ds_diemthi != NULL) {
					

					soluong_diemthi = SL_DsDiemThi(dssv[j]->info.ds_diemthi);
					ptrDiemThi* dsDiemThi = new ptrDiemThi[soluong_diemthi];

					// Cho danh sach Diem Thi vao mang dsDiemThi
					indexArrDsDiemThi = 0;
					DuyetDiemThi(dssv[j]->info.ds_diemthi, dsDiemThi, indexArrDsDiemThi);
					
					for (int k = 0; k < soluong_diemthi; k++) {
						if (k == 0 && dem != 0) f << endl;

						f << dslop.DS[i]->malop << "|";
						f << dssv[j]->info.masv << "|";
						f << dsDiemThi[k]->info.mamh << "|";
						f << dsDiemThi[k]->info.diem << "|";

						if (k != (soluong_diemthi - 1)) f << endl;
						dem++;
						
					}
					delete[] dsDiemThi;
				}
			}
			delete[] dssv;
		}
	}
	f << endl;
	f.close();
}
void docFileDsDiemThi(DS_Lop& dslop) {
	fstream f;
	f.open("DiemThi.txt", ios::in);
	int cnt = 0;
	char ch;
	// Đếm file có bao nhiêu dòng 
	while (f.get(ch)) {
		if (ch == '\n') {
			++cnt;
		}
	}
	// Đưa con trỏ chuột về đầu file 
	f.clear();
	f.seekg(0, ios::beg);

	int vitriLopHoc;
	string maLopHoc = "";
	string maSinhVien = "";
	string maMonThi = "";
	string diem = "";

	// Bắt đầu ghi vào danh sách Sinh Vien
	for (int i = 0; i < cnt; i++) {
		maLopHoc = "";
		maMonThi = "";
		maSinhVien = "";
		diem = "";

		getline(f, maLopHoc, '|');
		getline(f, maSinhVien, '|');
		getline(f, maMonThi, '|');
		getline(f, diem, '|');
		f.ignore(1);

		vitriLopHoc = TimKiemMaLop(dslop, maLopHoc);
		ptrSinhVien sinhvien_dangtruycap = TimKiemMaSinhVien_TraVeNode(dslop, maSinhVien, vitriLopHoc);

		
		Diem DiemThiSinhVien;
		DiemThiSinhVien.mamh = maMonThi;
		DiemThiSinhVien.diem = stof(diem);

		ptrDiemThi tmp = new nodeDiemThi;
		tmp->info = DiemThiSinhVien;
		tmp->next = NULL;

		insertLastDiemThi(sinhvien_dangtruycap->info.ds_diemthi, tmp);
	}

	f.close();
}

void ghiFileDsDapAnSinhVien(DS_Lop dslop) {
	int soluong_sinhvien = 0;
	int soluong_diemthi = 0;
	int soluong_cauhoithi = 0;

	int indexArrDssv = 0;
	int indexArrDsDiemThi = 0;
	int dem = 0;

	fstream f;
	f.open("DapAnSinhVien.txt", ios::out);
	for (int i = 0; i < dslop.n; i++) {

		// Neu trong lop hoc co Sinh vien thi moi thuc hien
		if (dslop.DS[i]->ds_sinhvien != NULL) {
			soluong_sinhvien = SL_DsSinhVien(dslop.DS[i]->ds_sinhvien);
			ptrSinhVien* dssv = new ptrSinhVien[soluong_sinhvien];

			// Cho danh sach Sinh Vien vao mang dssv
			indexArrDssv = 0;
			DuyetSinhVien(dslop.DS[i]->ds_sinhvien, dssv, indexArrDssv);
			for (int j = 0; j < soluong_sinhvien; j++) {

				// Neu trong Sinh Vien co Diem thi moi thuc hien
				if (dssv[j]->info.ds_diemthi != NULL) {


					soluong_diemthi = SL_DsDiemThi(dssv[j]->info.ds_diemthi);
					ptrDiemThi* dsDiemThi = new ptrDiemThi[soluong_diemthi];

					// Cho danh sach Diem Thi vao mang dsDiemThi
					indexArrDsDiemThi = 0;
					DuyetDiemThi(dssv[j]->info.ds_diemthi, dsDiemThi, indexArrDsDiemThi);

					for (int k = 0; k < soluong_diemthi; k++) {
								

						soluong_cauhoithi = dsDiemThi[k]->info.n + 1;
						for (int l = 0; l < soluong_cauhoithi; l++) {
							if (l == 0 && dem != 0) f << endl;

							f << dslop.DS[i]->malop << "|";
							f << dssv[j]->info.masv << "|";
							f << dsDiemThi[k]->info.mamh << "|";
							f << soluong_cauhoithi << "|";
							//f << dsDiemThi[k]->info.CauTraLoi[l]->mamh << "|";
							f << dsDiemThi[k]->info.CauTraLoi[l]->noidung << "|";
							f << dsDiemThi[k]->info.CauTraLoi[l]->dapan << "|";
							f << dsDiemThi[k]->info.CauTraLoi[l]->A << "|";
							f << dsDiemThi[k]->info.CauTraLoi[l]->B << "|";
							f << dsDiemThi[k]->info.CauTraLoi[l]->C << "|";
							f << dsDiemThi[k]->info.CauTraLoi[l]->D << "|";

							f << dsDiemThi[k]->info.DapAn[l]->dapan << "|";

							if (l != (soluong_cauhoithi - 1)) f << endl;
							dem++;
						}
					}
					delete[] dsDiemThi;
				}
			}
			delete[] dssv;
		}
	}
	f << endl;
	f.close();
}
void docFileDsDapAnSinhVien(DS_Lop& dslop) {
	fstream f;
	f.open("DapAnSinhVien.txt", ios::in);
	int cnt = 0;
	char ch;
	// Đếm file có bao nhiêu dòng 
	while (f.get(ch)) {
		if (ch == '\n') {
			++cnt;
		}
	}
	// Đưa con trỏ chuột về đầu file 
	f.clear();
	f.seekg(0, ios::beg);

	int vitriLopHoc;
	string maLopHoc = "";
	string maSinhVien = "";
	string maMonThi = "";
	string socauhoi = "";
	string noidungcauhoi = "";
	string dapancauhoi = "";
	string dapansinhvien = "";
	string cauA = "";
	string cauB = "";
	string cauC = "";
	string cauD = "";
	int dem = 0;

	// Bắt đầu ghi vào danh sách Sinh Vien
	for (int i = 0; i < cnt; i++) {
		maLopHoc = "";
		maMonThi = "";
		maSinhVien = "";
		maMonThi = "";
		socauhoi = "";
		noidungcauhoi = "";
		dapancauhoi = "";
		dapansinhvien = "";
		cauA = "";
		cauB = "";
		cauC = "";
		cauD = "";

		getline(f, maLopHoc, '|');
		getline(f, maSinhVien, '|');
		getline(f, maMonThi, '|');
		getline(f, socauhoi, '|');
		getline(f, noidungcauhoi, '|');
		getline(f, dapancauhoi, '|');
		getline(f, cauA, '|');
		getline(f, cauB, '|');
		getline(f, cauC, '|');
		getline(f, cauD, '|');
		getline(f, dapansinhvien, '|');

		f.ignore(1);

		vitriLopHoc = TimKiemMaLop(dslop, maLopHoc);
		ptrSinhVien sinhvien_dangtruycap = TimKiemMaSinhVien_TraVeNode(dslop, maSinhVien, vitriLopHoc);
		

		sinhvien_dangtruycap->info.ds_diemthi->info.CauTraLoi[dem] = new CauHoiThi;
		sinhvien_dangtruycap->info.ds_diemthi->info.CauTraLoi[dem]->mamh = maMonThi;
		//sinhvien_dangtruycap->info.ds_diemthi->info.CauTraLoi[dem]->id = stoi(idcauhoi);
		sinhvien_dangtruycap->info.ds_diemthi->info.CauTraLoi[dem]->noidung = noidungcauhoi;
		sinhvien_dangtruycap->info.ds_diemthi->info.CauTraLoi[dem]->dapan = dapansinhvien;
		sinhvien_dangtruycap->info.ds_diemthi->info.CauTraLoi[dem]->A = cauA;
		sinhvien_dangtruycap->info.ds_diemthi->info.CauTraLoi[dem]->B = cauB;
		sinhvien_dangtruycap->info.ds_diemthi->info.CauTraLoi[dem]->C = cauC;
		sinhvien_dangtruycap->info.ds_diemthi->info.CauTraLoi[dem]->D = cauD;

		sinhvien_dangtruycap->info.ds_diemthi->info.DapAn[dem] = new CauHoiThi;
		sinhvien_dangtruycap->info.ds_diemthi->info.DapAn[dem]->mamh = maMonThi;
		//sinhvien_dangtruycap->info.ds_diemthi->info.DapAn[dem]->id = stoi(idcauhoi);
		sinhvien_dangtruycap->info.ds_diemthi->info.DapAn[dem]->noidung = noidungcauhoi;
		sinhvien_dangtruycap->info.ds_diemthi->info.DapAn[dem]->dapan = dapancauhoi;
		sinhvien_dangtruycap->info.ds_diemthi->info.DapAn[dem]->A = cauA;
		sinhvien_dangtruycap->info.ds_diemthi->info.DapAn[dem]->B = cauB;
		sinhvien_dangtruycap->info.ds_diemthi->info.DapAn[dem]->C = cauC;
		sinhvien_dangtruycap->info.ds_diemthi->info.DapAn[dem]->D = cauD;

		if (sinhvien_dangtruycap->info.ds_diemthi->info.n < (stoi(socauhoi) - 1)) {
			sinhvien_dangtruycap->info.ds_diemthi->info.n++;
			dem++;
		}
		else {
			dem = 0;
		}	
	}
	f.close();
}


//================================================HAM CHUC NANG NGUOI DUNG=================================================================
// 
//-----------------LOP HOC-------------------------------------
void ThemLopHoc(DS_Lop& dslop) {
	// Xoa du lieu cu
	BangDanhsachLop();

	string nhap_malop;
	string nhap_tenlop;
	string nhap_namhoc;
	Lop lop;

	string chuanhoa_malop;
	bool check; // Chuan Hoa chuoi Ma Lop 1 lan

	bool trangthai_trangDsLop = false;

	int xmouse = -1;
	int ymouse = -1;

	Khu_vuc_nhap_thong_tin_lop();
	while (true) {
		ChuyenTrang_DsLop(dslop, trangthai_trangDsLop);

		if (ismouseclick(WM_LBUTTONDOWN)) {
			getmouseclick(WM_LBUTTONDOWN, xmouse, ymouse);

			// Nguoi dung chon nut => rectangle(700, 770, 870, 820);
			if (xmouse >= 700 && xmouse <= 870 && ymouse >= 770 && ymouse <= 820) {
				BangDanhsachLop();
				trangthai_trangDsLop = true;
			}
			// Nguoi dung chon nut <= rectangle(250, 770, 420, 820);
			else if (xmouse >= 250 && xmouse <= 420 && ymouse >= 770 && ymouse <= 820) {
				BangDanhsachLop();
				trangthai_trangDsLop = false;
			}
			// Nguoi dung chon nut THOAT
			else if (xmouse >= 1200 && xmouse <= 1370 && ymouse >= 770 && ymouse <= 820) {
				Thong_bao_chon_thoat_chuc_nang_THEM();
				if (Lua_chon_CO_hoac_KHONG_cua_thong_bao_trong_ham_chuc_nang()) {
					// khung thong bao
					setfillstyle(1, 15);
					bar(1110, 80, 1500, 370);
					setcolor(0);
					rectangle(1110, 80, 1500, 750);
					line(1110, 140, 1500, 140);

					setbkcolor(15);
					setcolor(4);
					settextstyle(10, 0, 3);
					outtextxy(1240, 100, (char*)"THONG BAO");
					return;
				}
				else {
					// khung thong bao
					setfillstyle(1, 15);
					bar(1110, 80, 1500, 370);
					setcolor(0);
					rectangle(1110, 80, 1500, 750);
					line(1110, 140, 1500, 140);

					setbkcolor(15);
					setcolor(4);
					settextstyle(10, 0, 3);
					outtextxy(1240, 100, (char*)"THONG BAO");
					continue;
				}
			}
			// Nguoi dung nhap MA LOP rectangle(250, 120, 600, 160);
			else if (xmouse >= 250 && xmouse <= 600 && ymouse >= 120 && ymouse <= 160) {
				nhap_malop = "";
				nhap_malop = vietText_khung_MA_LOP(265, 129, 15);

				check = true;
				chuanhoa_malop = "";
			}
			// Nguoi dung nhap TEN LOP rectangle(250, 180, 900, 220);
			else if (xmouse >= 250 && xmouse <= 900 && ymouse >= 180 && ymouse <= 220) {
				nhap_tenlop = "";
				nhap_tenlop = vietText_khung_TEN_LOP(265, 188, 40);
			}
			// Nguoi dung nhap NAM HOC rectangle(780, 120, 950, 160);
			else if (xmouse >= 780 && xmouse <= 950 && ymouse >= 120 && ymouse <= 160) {
				nhap_namhoc = "";
				nhap_namhoc = vietText_khung_NAM_HOC_LOP(800, 129, 4);
				check = true;
			}
			// Nguoi dung chon THEM
			else if (xmouse >= 470 && xmouse <= 640 && ymouse >= 260 && ymouse <= 310) {
				// Kiem tra khong nhap THONG TIN
				if (nhap_malop.length() == 0) {
					Thong_bao_khong_duoc_de_trong_MALOP();
					continue;
				}
				else if (nhap_tenlop.length() == 0) {
					Thong_bao_khong_duoc_de_trong_TENLOP();
					continue;
				}
				else if (nhap_namhoc.length() == 0 || stoi(nhap_namhoc) < 1950 || stoi(nhap_namhoc) > 2050) {
					Thong_bao_Loi_NAMHOC();
					continue;
				}

				// Chuan hoa THONG TIN
				VietHoaTatCaChu(nhap_malop);
				ChuanHoaChuoi(nhap_tenlop);

				// Chuan hoa Ma Lop 1 lan
				if (check == true) {
					chuanhoa_malop = "D";
					chuanhoa_malop.push_back(nhap_namhoc[2]);
					chuanhoa_malop.push_back(nhap_namhoc[3]);
					chuanhoa_malop.append(nhap_malop);
					check = false;
				}

				// Kiem tra trung 
				if (KiemTraTrung_MALOP(dslop, chuanhoa_malop) == true) {
					Thong_bao_trung_MALOP();
					continue;
				}
				/*else if (KiemTraTrung_TENLOP(dslop, nhap_tenlop) == true) {
					Thong_bao_trung_TENLOP();
					continue;
				}*/

				// Them vao danh sach LOP HOC
				lop.malop = chuanhoa_malop;
				lop.namnhaphoc = stoi(nhap_namhoc);
				lop.tenlop = nhap_tenlop;

				ThemvaoDslop(dslop, lop);
				Thong_bao_THANH_CONG();
				Khu_vuc_nhap_thong_tin_lop();
				continue;
			}
		}
		delay(200);
	}
}
void SuaLopHoc(DS_Lop& dslop) {

	string malop_cantim;
	string malop_cansua;
	string tenlop_cansua;
	string namhoc_cansua;
	string chuanhoa_malop;
	string malop_bandau;

	bool trangthai_trangDsLop = false;
	bool check = false; // chuan hoa chuoi MA LOP 1 lan
	bool check_sua_namhoc = false;

	// Khu vuc nhap MA LOP
	setfillstyle(1, 11);
	bar(250, 120, 600, 160);
	setcolor(0);
	rectangle(250, 120, 600, 160);
	setbkcolor(15);
	setcolor(0);
	settextstyle(10, 0, 2);
	outtextxy(130, 130, (char*)"MA LOP");

	int xmouse = -1;
	int ymouse = -1;

	int vitri;

	while (true) {
		if (ismouseclick(WM_LBUTTONDOWN)) {
			getmouseclick(WM_LBUTTONDOWN, xmouse, ymouse);

			// Nguoi dung chon nut THOAT
			if (xmouse >= 1200 && xmouse <= 1370 && ymouse >= 770 && ymouse <= 820) {
				return;
			}
			// Nguoi dung nhap MA LOP rectangle(250, 120, 600, 160);
			else if (xmouse >= 250 && xmouse <= 600 && ymouse >= 120 && ymouse <= 160) {
				malop_cantim = "";
				malop_cantim = vietText_khung_MA_LOP(265, 129, 15);
				VietHoaTatCaChu(malop_cantim);

				vitri = TimKiemMaLop(dslop, malop_cantim);

				if (TimKiemMaLop(dslop, malop_cantim) >= 0) {
					// Co Sinh vien thi ko duoc sua
					if (dslop.DS[vitri]->ds_sinhvien != NULL) {
						Thong_bao_khong_sua_duoc_Lop();
						continue;
					}

					// Xoa du lieu cu tren man hinh
					BangDanhsachLop();
					// Hien thi thong tin Lop hoc can xoa
					setbkcolor(15);
					setcolor(4);
					settextstyle(8, 0, 2);
					outtextxy(400, 400, (char*)(dslop.DS[vitri]->tenlop).c_str());
					outtextxy(220, 400, (char*)(dslop.DS[vitri]->malop).c_str());
					outtextxy(90, 400, (char*)(to_string(dslop.DS[vitri]->namnhaphoc).c_str()));

					Thong_bao_xac_nhan_SUA();
					if (Lua_chon_CO_hoac_KHONG_cua_thong_bao_trong_ham_chuc_nang()) {
						// Hien khu vuc nhap thong tin de SUA				
						Khu_vuc_SUA_thong_tin_lop();

						// De xoa hai nut Co va Khong cua ham Thong_bao_xac_nhan_SUA
						setfillstyle(1, 15);
						bar(1110, 80, 1500, 370);
						setcolor(0);
						rectangle(1110, 80, 1500, 750);
						line(1110, 140, 1500, 140);

						setbkcolor(15);
						setcolor(4);
						settextstyle(10, 0, 3);
						outtextxy(1240, 100, (char*)"THONG BAO");

						// Hien thong bao nguoi dung dang tien hanh che do SUA
						Thong_bao_dang_tien_hanh_SUA();

						setbkcolor(11);
						setcolor(0);
						settextstyle(8, 0, 2);
						outtextxy(270, 130, (char*)(dslop.DS[vitri]->malop).c_str());
						outtextxy(270, 190, (char*)(dslop.DS[vitri]->tenlop).c_str());
						outtextxy(800, 130, (char*)(to_string(dslop.DS[vitri]->namnhaphoc)).c_str());

						malop_bandau = dslop.DS[vitri]->malop; // Truong hop nguoi dung khong SUA Thong Tin nao ma bam SUA
						malop_cansua = dslop.DS[vitri]->malop;
						malop_cansua.erase(malop_cansua.begin() + 0, malop_cansua.begin() + 3);
						tenlop_cansua = dslop.DS[vitri]->tenlop;
						namhoc_cansua = to_string(dslop.DS[vitri]->namnhaphoc);

						BangDanhsachLop();
						while (true) {
							ChuyenTrang_DsLop(dslop, trangthai_trangDsLop);

							if (ismouseclick(WM_LBUTTONDOWN)) {
								getmouseclick(WM_LBUTTONDOWN, xmouse, ymouse);

								// Nguoi dung chon nut => rectangle(700, 770, 870, 820);
								if (xmouse >= 700 && xmouse <= 870 && ymouse >= 770 && ymouse <= 820) {
									BangDanhsachLop();
									trangthai_trangDsLop = true;
								}
								// Nguoi dung chon nut <= rectangle(250, 770, 420, 820);
								else if (xmouse >= 250 && xmouse <= 420 && ymouse >= 770 && ymouse <= 820) {
									BangDanhsachLop();
									trangthai_trangDsLop = false;
								}
								// Nguoi dung chon nut THOAT
								else if (xmouse >= 1200 && xmouse <= 1370 && ymouse >= 770 && ymouse <= 820) {
									Thong_bao_chon_thoat_chuc_nang_SUA();
									if (Lua_chon_CO_hoac_KHONG_cua_thong_bao_trong_ham_chuc_nang()) {
										// khung thong bao
										setfillstyle(1, 15);
										bar(1110, 80, 1500, 370);
										setcolor(0);
										rectangle(1110, 80, 1500, 750);
										line(1110, 140, 1500, 140);

										setbkcolor(15);
										setcolor(4);
										settextstyle(10, 0, 3);
										outtextxy(1240, 100, (char*)"THONG BAO");
										return;
									}
									else {
										// khung thong bao
										setfillstyle(1, 15);
										bar(1110, 80, 1500, 370);
										setcolor(0);
										rectangle(1110, 80, 1500, 750);
										line(1110, 140, 1500, 140);

										setbkcolor(15);
										setcolor(4);
										settextstyle(10, 0, 3);
										outtextxy(1240, 100, (char*)"THONG BAO");
										continue;
									}
								}
								// Nguoi dung nhap MA LOP rectangle(250, 120, 600, 160);
								else if (xmouse >= 250 && xmouse <= 600 && ymouse >= 120 && ymouse <= 160) {
									malop_cansua = "";
									malop_cansua = vietText_khung_MA_LOP(265, 129, 15);

									check = true;
									chuanhoa_malop = "";
								}
								// Nguoi dung nhap TEN LOP rectangle(250, 180, 900, 220);
								else if (xmouse >= 250 && xmouse <= 900 && ymouse >= 180 && ymouse <= 220) {
									tenlop_cansua = "";
									tenlop_cansua = vietText_khung_TEN_LOP(265, 188, 40);
								}
								// Nguoi dung nhap NAM HOC rectangle(780, 120, 950, 160);
								else if (xmouse >= 780 && xmouse <= 950 && ymouse >= 120 && ymouse <= 160) {
									check_sua_namhoc = true;
									namhoc_cansua = "";
									namhoc_cansua = vietText_khung_NAM_HOC_LOP(800, 129, 4);
									check = true;
								}
								// Nguoi dung chon SUA
								else if (xmouse >= 470 && xmouse <= 640 && ymouse >= 260 && ymouse <= 310) {
									// Kiem tra khong nhap THONG TIN
									if (malop_cansua.length() == 0) {
										Thong_bao_khong_duoc_de_trong_MALOP();
										continue;
									}
									else if (tenlop_cansua.length() == 0) {
										Thong_bao_khong_duoc_de_trong_TENLOP();
										continue;
									}
									else if (namhoc_cansua.length() == 0 || stoi(namhoc_cansua) < 1950 || stoi(namhoc_cansua) > 2050) {
										Thong_bao_Loi_NAMHOC();
										continue;
									}

									// Chuan hoa THONG TIN
									VietHoaTatCaChu(malop_cansua);
									ChuanHoaChuoi(tenlop_cansua);

									// Chuan hoa Ma Lop 1 lan
									if (check == true) {
										chuanhoa_malop = "D";
										chuanhoa_malop.push_back(namhoc_cansua[2]);
										chuanhoa_malop.push_back(namhoc_cansua[3]);
										chuanhoa_malop.append(malop_cansua);
										check = false;
									}
									

									// Kiem tra trung 
									if (KiemTraTrung_MALOP(dslop, chuanhoa_malop) == true) {
										Thong_bao_trung_MALOP();
										continue;
									}
									/*else if (KiemTraTrung_TENLOP(dslop, tenlop_cansua) == true) {
										Thong_bao_trung_TENLOP();
										continue;
									}*/

									// Thay doi thong tin LOP HOC									
									/*if (check_sua_namhoc == false) {
										dslop.DS[vitri]->malop = malop_bandau;
									}
									else {
									}*/


									dslop.DS[vitri]->malop = chuanhoa_malop;
									dslop.DS[vitri]->namnhaphoc = stoi(namhoc_cansua);
									dslop.DS[vitri]->tenlop = tenlop_cansua;

									Thong_bao_THANH_CONG();
									return;
								}
							}
							delay(200);
						}
					}
					else {
						return;
					}
				}
				else {
					Thong_bao_Ko_tim_thay_MA();
					continue;
				}
			}
		}
		delay(200);
	}
}
void XoaLop(DS_Lop& dslop) {
	string malop_canxoa = "";
	malop_canxoa = vietText_khung_MA_LOP(265, 129, 15);
	VietHoaTatCaChu(malop_canxoa);

	int vitrilop = TimKiemMaLop(dslop, malop_canxoa);

	if (TimKiemMaLop(dslop, malop_canxoa) >= 0) {
		if (dslop.DS[vitrilop]->ds_sinhvien != NULL) {
			Thong_bao_khong_xoa_duoc_Lop();
			return;
		}

		Thong_bao_xac_nhan_XOA();
		if (Lua_chon_CO_hoac_KHONG_cua_thong_bao_trong_ham_chuc_nang()) {
			Xoa1Lop(dslop, vitrilop);

			Thong_bao_THANH_CONG();
			return;
		}
		else {
			return;
		}
	}
	else {
		Thong_bao_Ko_tim_thay_MA();
		return;
	}
}

//----------------SINH VIEN------------------------------------
void NhapThongTinSinhVien(DS_Lop& dslop, int vitrilop) {
	string nhap_masv;
	string nhap_ten, nhap_ho, nhap_matkhau, nhap_phai;
	string chuanhoa_masv;
	bool check;

	ptrSinhVien tmp;

	bool trangthai_trangDsSinhVien = false;

	int xmouse = -1;
	int ymouse = -1;

	Khu_vuc_Nhap_thong_tin_sinh_vien();

	while (true) {

		ChuyenTrang_DsSinhVien(dslop, trangthai_trangDsSinhVien, vitrilop);
		//hienDsSinhVien_graphic(dslop, vitrilop);

		if (ismouseclick(WM_LBUTTONDOWN)) {
			getmouseclick(WM_LBUTTONDOWN, xmouse, ymouse);

			// Nguoi dung chon nut => rectangle(700, 770, 870, 820);
			if (xmouse >= 700 && xmouse <= 870 && ymouse >= 770 && ymouse <= 820) {
				BangDanhSachSinhVien();
				trangthai_trangDsSinhVien = true;
			}
			// Nguoi dung chon nut <= rectangle(250, 770, 420, 820);
			else if (xmouse >= 250 && xmouse <= 420 && ymouse >= 770 && ymouse <= 820) {
				BangDanhSachSinhVien();
				trangthai_trangDsSinhVien = false;
			}
			// Nguoi dung nhap MA SINH VIEN rectangle(200, 90, 600, 130);
			else if (xmouse >= 200 && xmouse <= 600 && ymouse >= 90 && ymouse <= 130) {
				check = true;
				chuanhoa_masv = "";
				chuanhoa_masv = dslop.DS[vitrilop]->malop;
				nhap_masv = "";
				nhap_masv = vietText_khung_MA_SINH_VIEN(215, 99, 3);
			}
			// Nguoi dung nhap HO rectangle(200, 150, 600, 190);
			else if (xmouse >= 200 && xmouse <= 600 && ymouse >= 150 && ymouse <= 190) {
				nhap_ho = "";
				nhap_ho = vietText_khung_HO_SINH_VIEN(215, 159, 23);
			}
			// Nguoi dung nhap TEN rectangle(200, 210, 600, 250);
			else if (xmouse >= 200 && xmouse <= 600 && ymouse >= 210 && ymouse <= 250) {
				nhap_ten = "";
				nhap_ten = vietText_khung_TEN_SINH_VIEN(215, 219, 10);
			}
			// Nguoi dung chon gioi tinh NAM rectangle(700, 110, 850, 160);
			else if (xmouse >= 700 && xmouse <= 850 && ymouse >= 110 && ymouse <= 160) {
				// CHUYEN mau NAM sang len
				setfillstyle(1, 2);
				bar(700, 110, 850, 160);
				setcolor(1);
				rectangle(700, 110, 850, 160);
				// Chuyen mau NU binh thuong
				setfillstyle(1, 10);
				bar(900, 110, 1050, 160);
				setcolor(0);
				rectangle(900, 110, 1050, 160);

				setbkcolor(2);
				setcolor(0);
				settextstyle(10, 0, 3);
				outtextxy(755, 125, (char*)"NAM");

				setbkcolor(10);
				setcolor(0);
				settextstyle(10, 0, 3);
				outtextxy(965, 125, (char*)"NU");
				nhap_phai = "";
				nhap_phai = "Nam";
			}
			// Nguoi dung chon gioi tinh NU rectangle(900, 110, 1050, 160);
			else if (xmouse >= 900 && xmouse <= 1050 && ymouse >= 110 && ymouse <= 160) {
				// CHUYEN mau NAM ve binh thuong
				setfillstyle(1, 10);
				bar(700, 110, 850, 160);
				setcolor(0);
				rectangle(700, 110, 850, 160);
				// Chuyen mau NU sang len
				setfillstyle(1, 2);
				bar(900, 110, 1050, 160);
				setcolor(1);
				rectangle(900, 110, 1050, 160);

				setbkcolor(10);
				setcolor(0);
				settextstyle(10, 0, 3);
				outtextxy(755, 125, (char*)"NAM");

				setbkcolor(2);
				setcolor(0);
				settextstyle(10, 0, 3);
				outtextxy(965, 125, (char*)"NU");
				nhap_phai = "";
				nhap_phai = "Nu";
			}
			// Nguoi dung nhap MAT KHAU rectangle(800, 180, 1050, 220);
			else if (xmouse >= 800 && xmouse <= 1050 && ymouse >= 180 && ymouse <= 220) {
				nhap_matkhau = "";
				nhap_matkhau = vietText_khung_MAT_KHAU_SV(810, 189, 14);
			}
			// Nguoi dung chon nut THOAT
			else if (xmouse >= 1200 && xmouse <= 1370 && ymouse >= 770 && ymouse <= 820) {
				Thong_bao_chon_thoat_chuc_nang_THEM();
				if (Lua_chon_CO_hoac_KHONG_cua_thong_bao_trong_ham_chuc_nang()) {
					// khung thong bao
					setfillstyle(1, 15);
					bar(1110, 80, 1500, 370);
					setcolor(0);
					rectangle(1110, 80, 1500, 750);
					line(1110, 140, 1500, 140);

					setbkcolor(15);
					setcolor(4);
					settextstyle(10, 0, 3);
					outtextxy(1240, 100, (char*)"THONG BAO");
					return;
				}
				else {
					// khung thong bao
					setfillstyle(1, 15);
					bar(1110, 80, 1500, 370);
					setcolor(0);
					rectangle(1110, 80, 1500, 750);
					line(1110, 140, 1500, 140);

					setbkcolor(15);
					setcolor(4);
					settextstyle(10, 0, 3);
					outtextxy(1240, 100, (char*)"THONG BAO");
					continue;
				}
			}
			// Nguoi dung chon THEM rectangle(470, 310, 640, 260);
			else if (xmouse >= 470 && xmouse <= 640 && ymouse >= 260 && ymouse <= 310) {
				// Kiem tra nguoi dung khong nhap THONG TIN
				if (nhap_masv.length() == 0) {
					Thong_bao_Vui_long_nhap_MA_SINH_VIEN();
					continue;
				}
				else if (nhap_ho.length() == 0) {
					Thong_bao_Vui_long_nhap_HO_SINH_VIEN();
					continue;
				}
				else if (nhap_ten.length() == 0) {
					Thong_bao_Vui_long_nhap_TEN_SINH_VIEN();
					continue;
				}
				else if (nhap_phai.length() == 0) {
					Thong_bao_Vui_long_nhap_PHAI_SINH_VIEN();
					continue;
				}
				else if (nhap_matkhau.length() == 0) {
					Thong_bao_Vui_long_nhap_MAT_KHAU_SINH_VIEN();
					continue;
				}

				// Chuan hoa Thong tin

				VietHoaTatCaChu(nhap_masv);
				// chi ghep chuoi 1 lan
				if (check == true) {
					chuanhoa_masv.append(nhap_masv);
					check = false;
				}

				ChuanHoaChuoi(nhap_ho);
				ChuanHoaChuoi(nhap_ten);

				// Kiem tra trung Ma sinh vien
				if (TimKiemMaSinhVien(dslop, chuanhoa_masv, vitrilop) == true) {

					Thong_bao_trung_MA_SINH_VIEN();
					continue;
				}
				//// Kiem tra trung Ho ten
				//else if (KiemTraTrungHoTenSinhVien(dslop, nhap_ho, nhap_ten, nhap_phai, vitrilop)) {
				//	Thong_bao_trung_HO_TEN_SINH_VIEN();
				//	continue;
				//}

				// Luu du lieu vao 1 node sinh vien
				tmp = taoNodeSinhVien(chuanhoa_masv, nhap_ho, nhap_ten, nhap_phai, nhap_matkhau);

				// Chen node SinhVien vao cuoi danh sach				

				insertLastSinhVien(dslop.DS[vitrilop]->ds_sinhvien, tmp);

				Thong_bao_THANH_CONG();
				Khu_vuc_Nhap_thong_tin_sinh_vien();
				continue;
			}
		}
		delay(200);
	}
	return;
}
void XoaThongTinSinhVien(DS_Lop& dslop, int vitrilop) {
	string nhap_masv;
	string chuanhoa_masv;

	bool trangthai_trangDsSinhVien = false;

	int xmouse = -1;
	int ymouse = -1;

	while (true) {

		ChuyenTrang_DsSinhVien(dslop, trangthai_trangDsSinhVien, vitrilop);

		if (ismouseclick(WM_LBUTTONDOWN)) {
			getmouseclick(WM_LBUTTONDOWN, xmouse, ymouse);


			// Nguoi dung chon nut => rectangle(700, 770, 870, 820);
			if (xmouse >= 700 && xmouse <= 870 && ymouse >= 770 && ymouse <= 820) {
				BangDanhSachSinhVien();
				trangthai_trangDsSinhVien = true;

			}
			// Nguoi dung chon nut <= rectangle(250, 770, 420, 820);
			else if (xmouse >= 250 && xmouse <= 420 && ymouse >= 770 && ymouse <= 820) {
				BangDanhSachSinhVien();
				trangthai_trangDsSinhVien = false;
			}
			// Nguoi dung chon nut THOAT
			else if (xmouse >= 1200 && xmouse <= 1370 && ymouse >= 770 && ymouse <= 820) {
				Thong_bao_chon_thoat_chuc_nang_XOA();
				if (Lua_chon_CO_hoac_KHONG_cua_thong_bao_trong_ham_chuc_nang()) {
					// khung thong bao
					setfillstyle(1, 15);
					bar(1110, 80, 1500, 370);
					setcolor(0);
					rectangle(1110, 80, 1500, 750);
					line(1110, 140, 1500, 140);

					setbkcolor(15);
					setcolor(4);
					settextstyle(10, 0, 3);
					outtextxy(1240, 100, (char*)"THONG BAO");

					return;
				}
				else {
					// khung thong bao
					setfillstyle(1, 15);
					bar(1110, 80, 1500, 370);
					setcolor(0);
					rectangle(1110, 80, 1500, 750);
					line(1110, 140, 1500, 140);

					setbkcolor(15);
					setcolor(4);
					settextstyle(10, 0, 3);
					outtextxy(1240, 100, (char*)"THONG BAO");
					continue;
				}
			}
			// Nguoi dung chon nhap MA SINH VIEN rectangle(400, 150, 800, 190);
			else if (xmouse >= 400 && xmouse <= 800 && ymouse >= 150 && ymouse <= 190) {
				chuanhoa_masv = "";
				chuanhoa_masv = dslop.DS[vitrilop]->malop;
				nhap_masv = "";
				nhap_masv = vietText_khung_MA_SINH_VIEN_chuc_nang_xoa(410, 158, 3);

				// Kiem tra nguoi dung khong nhap MA SINH VIEN
				if (nhap_masv.length() == 0) {
					Thong_bao_Vui_long_nhap_MA_SINH_VIEN();
					continue;
				}

				// Chuan hoa MA SINH VIEN nhap vao
				VietHoaTatCaChu(nhap_masv);
				chuanhoa_masv.append(nhap_masv);

				// Neu Sinh Vien da thi, da co DIEM thi ko duoc xoa
				ptrSinhVien sinhvien = TimKiemMaSinhVien_TraVeNode(dslop, chuanhoa_masv, vitrilop);
				if (sinhvien->info.ds_diemthi != NULL) {
					Thong_bao_khong_xoa_duoc_SinhVien();
					continue;
				}

				// Pos de xac dinh truong hop can xoa cho DANH SACH LK DON
				int pos = TimKiemMaSinhVien_chuc_nang_xoa(dslop, chuanhoa_masv, vitrilop);

				if (pos != 0) {
					Thong_bao_xac_nhan_XOA();
					if (Lua_chon_CO_hoac_KHONG_cua_thong_bao_trong_ham_chuc_nang()) {
						// Tien hanh XOA
						if (pos == 1) {
							deleteFirst(dslop.DS[vitrilop]->ds_sinhvien);
						}
						else if (pos == SL_DsSinhVien(dslop.DS[vitrilop]->ds_sinhvien)) {
							deleteLast(dslop.DS[vitrilop]->ds_sinhvien);
						}
						else if (pos > 1 && pos < SL_DsSinhVien(dslop.DS[vitrilop]->ds_sinhvien)) {
							deleteMiddle(dslop.DS[vitrilop]->ds_sinhvien, pos);
						}
						Thong_bao_THANH_CONG();
						BangDanhSachSinhVien();
						continue;
					}
					else {
						// in l?i khung thông báo 
						setfillstyle(1, 15);
						bar(1110, 80, 1500, 370);
						setcolor(0);
						rectangle(1110, 80, 1500, 750);
						line(1110, 140, 1500, 140);

						setbkcolor(15);
						setcolor(4);
						settextstyle(10, 0, 3);
						outtextxy(1240, 100, (char*)"THONG BAO");
						continue;
					}
				}
				else {
					Thong_bao_Ko_tim_thay_MA();
					continue;
				}
			}
		}
		delay(200);
	}
	return;
}
void SuaThongTinSinhVien(DS_Lop& dslop, int vitrilop) {
	string masv;

	string nhap_masv;
	string nhap_ten, nhap_ho, nhap_matkhau, nhap_phai;
	string chuanhoa_masv;
	bool check = false;

	bool trangthai_trangDsSinhVien = false;

	int xmouse = -1;
	int ymouse = -1;

	while (true) {
		ChuyenTrang_DsSinhVien(dslop, trangthai_trangDsSinhVien, vitrilop);

		if (ismouseclick(WM_LBUTTONDOWN)) {
			getmouseclick(WM_LBUTTONDOWN, xmouse, ymouse);


			// Nguoi dung chon nut => rectangle(700, 770, 870, 820);
			if (xmouse >= 700 && xmouse <= 870 && ymouse >= 770 && ymouse <= 820) {
				BangDanhSachSinhVien();
				trangthai_trangDsSinhVien = true;

			}
			// Nguoi dung chon nut <= rectangle(250, 770, 420, 820);
			else if (xmouse >= 250 && xmouse <= 420 && ymouse >= 770 && ymouse <= 820) {
				BangDanhSachSinhVien();
				trangthai_trangDsSinhVien = false;
			}
			// Nguoi dung chon nut THOAT
			else if (xmouse >= 1200 && xmouse <= 1370 && ymouse >= 770 && ymouse <= 820) {
				Thong_bao_chon_thoat_chuc_nang_SUA();
				if (Lua_chon_CO_hoac_KHONG_cua_thong_bao_trong_ham_chuc_nang()) {
					// khung thong bao
					setfillstyle(1, 15);
					bar(1110, 80, 1500, 370);
					setcolor(0);
					rectangle(1110, 80, 1500, 750);
					line(1110, 140, 1500, 140);

					setbkcolor(15);
					setcolor(4);
					settextstyle(10, 0, 3);
					outtextxy(1240, 100, (char*)"THONG BAO");

					return;
				}
				else {
					// khung thong bao
					setfillstyle(1, 15);
					bar(1110, 80, 1500, 370);
					setcolor(0);
					rectangle(1110, 80, 1500, 750);
					line(1110, 140, 1500, 140);

					setbkcolor(15);
					setcolor(4);
					settextstyle(10, 0, 3);
					outtextxy(1240, 100, (char*)"THONG BAO");
					continue;
				}
			}
			// Nguoi dung chon nhap MA SINH VIEN rectangle(400, 150, 800, 190);
			else if (xmouse >= 400 && xmouse <= 800 && ymouse >= 150 && ymouse <= 190) {
				chuanhoa_masv = "";
				chuanhoa_masv = dslop.DS[vitrilop]->malop;
				masv = "";
				masv = vietText_khung_MA_SINH_VIEN_chuc_nang_xoa(410, 158, 3);

				// Kiem tra nguoi dung khong nhap MA SINH VIEN
				if (masv.length() == 0) {
					Thong_bao_Vui_long_nhap_MA_SINH_VIEN();
					continue;
				}

				// Chuan hoa MA SINH VIEN nhap vao
				VietHoaTatCaChu(masv);
				chuanhoa_masv.append(masv);

				// Neu Sinh Vien da thi, da co DIEM thi ko duoc sua
				ptrSinhVien sinhvien = TimKiemMaSinhVien_TraVeNode(dslop, chuanhoa_masv, vitrilop);
				if (sinhvien->info.ds_diemthi != NULL) {
					Thong_bao_khong_sua_duoc_SinhVien();
					continue;
				}

				int pos = TimKiemMaSinhVien_chuc_nang_xoa(dslop, chuanhoa_masv, vitrilop);
				int cnt = 1;

				if (pos != 0) {

					// Lay du lieu cua node SinhVien do sao chep vao bien nhap thong tin va hien thi len man hinh
					ptrSinhVien p = dslop.DS[vitrilop]->ds_sinhvien;
					while (p != NULL) {
						if (pos == cnt) {
							break;
						}
						cnt++;
						p = p->next;
					}

					nhap_phai = p->info.phai;
					nhap_masv = p->info.masv;
					nhap_ho = p->info.ho;
					nhap_ten = p->info.ten;
					nhap_matkhau = p->info.matkhau;

					Khu_vuc_Sua_thong_tin_sinh_vien();
					setbkcolor(11);
					setcolor(0);
					settextstyle(8, 0, 2);

					outtextxy(215, 99, (char*)(nhap_masv).c_str());
					outtextxy(215, 159, (char*)(nhap_ho).c_str());
					outtextxy(215, 219, (char*)(nhap_ten).c_str());
					outtextxy(810, 189, (char*)(nhap_matkhau).c_str());

					if (nhap_phai == "Nam") {
						setfillstyle(1, 2);
						bar(700, 110, 850, 160);
						setcolor(0);
						rectangle(700, 110, 850, 160);

						setbkcolor(2);
						setcolor(0);
						settextstyle(10, 0, 3);
						outtextxy(755, 125, (char*)"NAM");
					}
					else if (nhap_phai == "Nu") {
						setfillstyle(1, 2);
						bar(900, 110, 1050, 160);
						setcolor(0);
						rectangle(900, 110, 1050, 160);

						setbkcolor(2);
						setcolor(0);
						settextstyle(10, 0, 3);
						outtextxy(965, 125, (char*)"NU");
					}

					while (true) {

						if (ismouseclick(WM_LBUTTONDOWN)) {
							getmouseclick(WM_LBUTTONDOWN, xmouse, ymouse);

							// Nguoi dung nhap MA SINH VIEN rectangle(200, 90, 600, 130);
							if (xmouse >= 200 && xmouse <= 600 && ymouse >= 90 && ymouse <= 130) {
								check = true;
								chuanhoa_masv = "";
								chuanhoa_masv = dslop.DS[vitrilop]->malop;
								nhap_masv = "";
								nhap_masv = vietText_khung_MA_SINH_VIEN(215, 99, 5);
							}
							// Nguoi dung nhap HO rectangle(200, 150, 600, 190);
							else if (xmouse >= 200 && xmouse <= 600 && ymouse >= 150 && ymouse <= 190) {
								nhap_ho = "";
								nhap_ho = vietText_khung_HO_SINH_VIEN(215, 159, 23);
							}
							// Nguoi dung nhap TEN rectangle(200, 210, 600, 250);
							else if (xmouse >= 200 && xmouse <= 600 && ymouse >= 210 && ymouse <= 250) {
								nhap_ten = "";
								nhap_ten = vietText_khung_TEN_SINH_VIEN(215, 219, 10);

							}
							// Nguoi dung chon gioi tinh NAM rectangle(700, 110, 850, 160);
							else if (xmouse >= 700 && xmouse <= 850 && ymouse >= 110 && ymouse <= 160) {
								// CHUYEN mau NAM sang len
								setfillstyle(1, 2);
								bar(700, 110, 850, 160);
								setcolor(1);
								rectangle(700, 110, 850, 160);
								// Chuyen mau NU binh thuong
								setfillstyle(1, 10);
								bar(900, 110, 1050, 160);
								setcolor(0);
								rectangle(900, 110, 1050, 160);

								setbkcolor(2);
								setcolor(0);
								settextstyle(10, 0, 3);
								outtextxy(755, 125, (char*)"NAM");

								setbkcolor(10);
								setcolor(0);
								settextstyle(10, 0, 3);
								outtextxy(965, 125, (char*)"NU");
								nhap_phai = "";
								nhap_phai = "Nam";
							}
							// Nguoi dung chon gioi tinh NU rectangle(900, 110, 1050, 160);
							else if (xmouse >= 900 && xmouse <= 1050 && ymouse >= 110 && ymouse <= 160) {
								// CHUYEN mau NAM ve binh thuong
								setfillstyle(1, 10);
								bar(700, 110, 850, 160);
								setcolor(0);
								rectangle(700, 110, 850, 160);
								// Chuyen mau NU sang len
								setfillstyle(1, 2);
								bar(900, 110, 1050, 160);
								setcolor(1);
								rectangle(900, 110, 1050, 160);

								setbkcolor(10);
								setcolor(0);
								settextstyle(10, 0, 3);
								outtextxy(755, 125, (char*)"NAM");

								setbkcolor(2);
								setcolor(0);
								settextstyle(10, 0, 3);
								outtextxy(965, 125, (char*)"NU");
								nhap_phai = "";
								nhap_phai = "Nu";
							}
							// Nguoi dung nhap MAT KHAU rectangle(800, 180, 1050, 220);
							else if (xmouse >= 800 && xmouse <= 1050 && ymouse >= 180 && ymouse <= 220) {
								nhap_matkhau = "";
								nhap_matkhau = vietText_khung_MAT_KHAU_SV(810, 189, 14);
							}
							// Nguoi dung chon nut THOAT
							else if (xmouse >= 1200 && xmouse <= 1370 && ymouse >= 770 && ymouse <= 820) {
								Thong_bao_chon_thoat_chuc_nang_SUA();
								if (Lua_chon_CO_hoac_KHONG_cua_thong_bao_trong_ham_chuc_nang()) {
									// khung thong bao
									setfillstyle(1, 15);
									bar(1110, 80, 1500, 370);
									setcolor(0);
									rectangle(1110, 80, 1500, 750);
									line(1110, 140, 1500, 140);

									setbkcolor(15);
									setcolor(4);
									settextstyle(10, 0, 3);
									outtextxy(1240, 100, (char*)"THONG BAO");
									return;
								}
								else {
									// khung thong bao
									setfillstyle(1, 15);
									bar(1110, 80, 1500, 370);
									setcolor(0);
									rectangle(1110, 80, 1500, 750);
									line(1110, 140, 1500, 140);

									setbkcolor(15);
									setcolor(4);
									settextstyle(10, 0, 3);
									outtextxy(1240, 100, (char*)"THONG BAO");
									continue;
								}
							}
							// Nguoi dung chon THEM rectangle(470, 310, 640, 260);
							else if (xmouse >= 470 && xmouse <= 640 && ymouse >= 260 && ymouse <= 310) {
								// Kiem tra nguoi dung khong nhap THONG TIN
								if (nhap_masv.length() == 0) {
									Thong_bao_Vui_long_nhap_MA_SINH_VIEN();
									continue;
								}
								else if (nhap_ho.length() == 0) {
									Thong_bao_Vui_long_nhap_HO_SINH_VIEN();
									continue;
								}
								else if (nhap_ten.length() == 0) {
									Thong_bao_Vui_long_nhap_TEN_SINH_VIEN();
									continue;
								}
								else if (nhap_phai.length() == 0) {
									Thong_bao_Vui_long_nhap_PHAI_SINH_VIEN();
									continue;
								}
								else if (nhap_matkhau.length() == 0) {
									Thong_bao_Vui_long_nhap_MAT_KHAU_SINH_VIEN();
									continue;
								}

								// Chuan hoa Thong tin
								VietHoaTatCaChu(nhap_masv);

								if (check == true) {
									chuanhoa_masv.append(nhap_masv);
									check = false;
								}

								ChuanHoaChuoi(nhap_ho);
								ChuanHoaChuoi(nhap_ten);

								// Kiem tra trung Ma sinh vien
								if (TimKiemMaSinhVien_chuc_nang_sua(dslop, chuanhoa_masv, vitrilop, pos) == true) {
									Thong_bao_trung_MA_SINH_VIEN();
									continue;
								}
								// Kiem tra trung Ho ten
								/*if (KiemTraTrungHoTenSinhVien_chuc_nang_sua(dslop, nhap_ho, nhap_ten, nhap_phai, vitrilop, pos)) {
									Thong_bao_trung_HO_TEN_SINH_VIEN();
									continue;
								}*/

								p->info.masv = chuanhoa_masv;
								p->info.phai = nhap_phai;
								p->info.ho = nhap_ho;
								p->info.ten = nhap_ten;
								p->info.matkhau = nhap_matkhau;
								break;
							}
						}
						delay(200);
					}
					Thong_bao_THANH_CONG();
					BangDanhSachSinhVien();

					return;

				}
				else {
					Thong_bao_Ko_tim_thay_MA();
					continue;
				}
			}
		}
		delay(200);
	}
}

//-----------------MON HOC--------------------------------------
void ThemMonHoc(DS_MonHoc& dsmon) {
	string nhap_mamon, nhap_tenmon;
	MonHoc mon;

	int xmouse = -1;
	int ymouse = -1;

	bool trangthai_trangDSMonHoc = false;

	Nhap_thong_tin_mon_hoc();

	while (true) {

		ChuyenTrang_DsMonHoc(dsmon, trangthai_trangDSMonHoc);

		if (ismouseclick(WM_LBUTTONDOWN)) {
			getmouseclick(WM_LBUTTONDOWN, xmouse, ymouse);


			// Nguoi dung chon nut => rectangle(700, 770, 870, 820);
			if (xmouse >= 700 && xmouse <= 870 && ymouse >= 770 && ymouse <= 820) {
				BangDanhSachMonHoc();
				trangthai_trangDSMonHoc = true;
			}
			// Nguoi dung chon nut <= rectangle(250, 770, 420, 820);
			else if (xmouse >= 250 && xmouse <= 420 && ymouse >= 770 && ymouse <= 820) {
				BangDanhSachMonHoc();
				trangthai_trangDSMonHoc = false;
			}
			// Nguoi dung chon nut THOAT
			else if (xmouse >= 1200 && xmouse <= 1370 && ymouse >= 770 && ymouse <= 820) {
				Thong_bao_chon_thoat_chuc_nang_THEM();
				if (Lua_chon_CO_hoac_KHONG_cua_thong_bao_trong_ham_chuc_nang()) {
					// khung thong bao
					setfillstyle(1, 15);
					bar(1110, 80, 1500, 370);
					setcolor(0);
					rectangle(1110, 80, 1500, 750);
					line(1110, 140, 1500, 140);

					setbkcolor(15);
					setcolor(4);
					settextstyle(10, 0, 3);
					outtextxy(1240, 100, (char*)"THONG BAO");
					return;
				}
				else {
					// khung thong bao
					setfillstyle(1, 15);
					bar(1110, 80, 1500, 370);
					setcolor(0);
					rectangle(1110, 80, 1500, 750);
					line(1110, 140, 1500, 140);

					setbkcolor(15);
					setcolor(4);
					settextstyle(10, 0, 3);
					outtextxy(1240, 100, (char*)"THONG BAO");
					continue;
				}
			}
			// Nguoi dung chon nhap MA MON 	rectangle(350, 120, 700, 160);
			else if (xmouse >= 350 && xmouse <= 700 && ymouse >= 120 && ymouse <= 160) {
				nhap_mamon = "";
				nhap_mamon = vietText_khung_MA_MON(360, 128, 15);
			}
			// Nguoi dung chon nhap TEN MON rectangle(350, 180, 980, 220);
			else if (xmouse >= 350 && xmouse <= 980 && ymouse >= 180 && ymouse <= 220) {
				nhap_tenmon = "";
				nhap_tenmon = vietText_khung_TEN_MON(360, 189, 40);
			}
			// Nguoi dung chon nut THEM	rectangle(470, 310, 640, 260);
			else if (xmouse >= 470 && xmouse <= 640 && ymouse >= 260 && ymouse <= 310) {
				// Kiem tra khong nhap thong tin
				if (nhap_mamon.length() == 0) {
					Thong_bao_khong_duoc_de_trong_MAMON();
					continue;
				}
				else if (nhap_tenmon.length() == 0) {
					Thong_bao_khong_duoc_de_trong_TENMON();
					continue;
				}

				// Chuan hoa thong tin
				VietHoaTatCaChu(nhap_mamon);
				ChuanHoaChuoi(nhap_tenmon);

				// Kiem tra trung
				if (KiemTraTrungMaMon(dsmon, nhap_mamon)) {
					Thong_bao_trung_MA_MON();
					continue;
				}
				/*else if (KiemTraTrungTenMon(dsmon, nhap_tenmon)) {
					Thong_bao_trung_TENLOP();
					continue;
				}*/

				// Them vao danh sach mon (them co thu tu)
				mon.mamh = nhap_mamon;
				mon.tenmh = nhap_tenmon;

				bool vitri_cuoidanhsach = true;

				int vitri = 0;
				for (int i = 0; i < dsmon.n; i++) {
					if (SoSanhHonChuoi(dsmon.DS[i]->tenmh, mon.tenmh)) {
						vitri = i;
						vitri_cuoidanhsach = false;
						break;
					}
				}
				// Them vao cuoi danh sach
				if (vitri_cuoidanhsach == true) {
					ThemVaoDsMonhoc(dsmon, mon);
				}
				// Them vao vi tri trong danh sach
				else {
					ThemMonHocVaoViTriCanThem(dsmon, mon, vitri);
				}

				Thong_bao_THANH_CONG();
				// Xoa du lieu cu
				BangDanhSachMonHoc();
				Nhap_thong_tin_mon_hoc();
				continue;
			}
		}
		delay(200);
	}
}
void XoaMonHoc(DS_MonHoc& dsmon, ptrCauHoiThi root) {
	string mamon_canxoa;
	int vitri;

	bool trangthai_trangDSMonHoc = false;

	int xmouse = -1;
	int ymouse = -1;

	Xoa_thong_tin_mon_hoc();

	while (true) {
		ChuyenTrang_DsMonHoc(dsmon, trangthai_trangDSMonHoc);

		if (ismouseclick(WM_LBUTTONDOWN)) {
			getmouseclick(WM_LBUTTONDOWN, xmouse, ymouse);

			// Nguoi dung chon nut => rectangle(700, 770, 870, 820);
			if (xmouse >= 700 && xmouse <= 870 && ymouse >= 770 && ymouse <= 820) {
				BangDanhSachMonHoc();
				trangthai_trangDSMonHoc = true;
			}
			// Nguoi dung chon nut <= rectangle(250, 770, 420, 820);
			else if (xmouse >= 250 && xmouse <= 420 && ymouse >= 770 && ymouse <= 820) {
				BangDanhSachMonHoc();
				trangthai_trangDSMonHoc = false;
			}
			// Nguoi dung chon THOAT
			else if (xmouse >= 1200 && xmouse <= 1370 && ymouse >= 770 && ymouse <= 820) {
				Thong_bao_chon_thoat_chuc_nang_XOA();
				if (Lua_chon_CO_hoac_KHONG_cua_thong_bao_trong_ham_chuc_nang()) {
					// khung thong bao
					setfillstyle(1, 15);
					bar(1110, 80, 1500, 370);
					setcolor(0);
					rectangle(1110, 80, 1500, 750);
					line(1110, 140, 1500, 140);

					setbkcolor(15);
					setcolor(4);
					settextstyle(10, 0, 3);
					outtextxy(1240, 100, (char*)"THONG BAO");
					break;
				}
				else {
					// khung thong bao
					setfillstyle(1, 15);
					bar(1110, 80, 1500, 370);
					setcolor(0);
					rectangle(1110, 80, 1500, 750);
					line(1110, 140, 1500, 140);

					setbkcolor(15);
					setcolor(4);
					settextstyle(10, 0, 3);
					outtextxy(1240, 100, (char*)"THONG BAO");
					continue;
				}

			}
			// Nguoi dung chon nhap MA MON rectangle(350, 120, 700, 160);
			else if (xmouse >= 350 && xmouse <= 700 && ymouse >= 120 && ymouse <= 160) {
				mamon_canxoa = "";
				mamon_canxoa = vietText_khung_MA_MON(360, 128, 15);
			}
			// Nguoi dung chon nut XOA 	rectangle(470, 260, 640, 310);
			else if (xmouse >= 470 && xmouse <= 640 && ymouse >= 260 && ymouse <= 310) {
				// check nguoi dung khong nhap ma mon
				if (mamon_canxoa.length() == 0) {
					Thong_bao_khong_duoc_de_trong_MAMON();
					continue;
				}			

				VietHoaTatCaChu(mamon_canxoa);

				// Neu Mon Hoc co Cau Hoi thi ko duoc xoa
				if (duyetLNR_Tim_MaMon(root, mamon_canxoa) == true) {
					Thong_bao_khong_xoa_duoc_MonHoc();
					continue;
				}

				vitri = TimKiemMaMon(dsmon, mamon_canxoa);

				if (vitri >= 0) {
					Thong_bao_xac_nhan_XOA();
					if (Lua_chon_CO_hoac_KHONG_cua_thong_bao_trong_ham_chuc_nang()) {
						Xoa1MonHoc(dsmon, vitri);
						Thong_bao_THANH_CONG();
						return;
					}
					else {
						// khung thong bao
						setfillstyle(1, 15);
						bar(1110, 80, 1500, 370);
						setcolor(0);
						rectangle(1110, 80, 1500, 750);
						line(1110, 140, 1500, 140);

						setbkcolor(15);
						setcolor(4);
						settextstyle(10, 0, 3);
						outtextxy(1240, 100, (char*)"THONG BAO");
						Xoa_thong_tin_mon_hoc();
						continue;
					}
				}
				else {
					Thong_bao_Ko_tim_thay_MA();
					continue;
				}
			}
		}
		delay(200);
	}
}
void SuaMonHoc(DS_MonHoc& dsmon, ptrCauHoiThi root) {
	string mamon_cansua;
	string nhap_mamon;
	string nhap_tenmon;

	int vitri;
	MonHoc tmp;
	MonHoc mon;

	bool trangthai_trangDSMonHoc = false;

	int xmouse = -1;
	int ymouse = -1;

	Sua_thong_tin_mon_hoc();

	while (true) {
		ChuyenTrang_DsMonHoc(dsmon, trangthai_trangDSMonHoc);

		if (ismouseclick(WM_LBUTTONDOWN)) {
			getmouseclick(WM_LBUTTONDOWN, xmouse, ymouse);

			// Nguoi dung chon nut => rectangle(700, 770, 870, 820);
			if (xmouse >= 700 && xmouse <= 870 && ymouse >= 770 && ymouse <= 820) {
				BangDanhSachMonHoc();
				trangthai_trangDSMonHoc = true;
			}
			// Nguoi dung chon nut <= rectangle(250, 770, 420, 820);
			else if (xmouse >= 250 && xmouse <= 420 && ymouse >= 770 && ymouse <= 820) {
				BangDanhSachMonHoc();
				trangthai_trangDSMonHoc = false;
			}
			// Nguoi dung chon THOAT
			else if (xmouse >= 1200 && xmouse <= 1370 && ymouse >= 770 && ymouse <= 820) {
				Thong_bao_chon_thoat_chuc_nang_SUA();
				if (Lua_chon_CO_hoac_KHONG_cua_thong_bao_trong_ham_chuc_nang()) {
					// khung thong bao
					setfillstyle(1, 15);
					bar(1110, 80, 1500, 370);
					setcolor(0);
					rectangle(1110, 80, 1500, 750);
					line(1110, 140, 1500, 140);

					setbkcolor(15);
					setcolor(4);
					settextstyle(10, 0, 3);
					outtextxy(1240, 100, (char*)"THONG BAO");
					break;
				}
				else {
					// khung thong bao
					setfillstyle(1, 15);
					bar(1110, 80, 1500, 370);
					setcolor(0);
					rectangle(1110, 80, 1500, 750);
					line(1110, 140, 1500, 140);

					setbkcolor(15);
					setcolor(4);
					settextstyle(10, 0, 3);
					outtextxy(1240, 100, (char*)"THONG BAO");
					continue;
				}

			}
			// Nguoi dung chon nhap MA MON CAN SUA 	rectangle(350, 120, 700, 160);
			else if (xmouse >= 350 && xmouse <= 700 && ymouse >= 120 && ymouse <= 160) {
				mamon_cansua = "";
				mamon_cansua = vietText_khung_MA_MON(360, 128, 15);
			}
			// Nguoi dung chon nut SUA 	rectangle(470, 260, 640, 310);
			else if (xmouse >= 470 && xmouse <= 640 && ymouse >= 260 && ymouse <= 310) {
				// Kiem tra nguoi dung khong nhap MA MON
				if (mamon_cansua.length() == 0) {
					Thong_bao_khong_duoc_de_trong_MAMON();
					continue;
				}
				// Chuan hoa MA MON
				VietHoaTatCaChu(mamon_cansua);

				// Neu Mon Hoc co Cau Hoi thi ko duoc Sua
				if (duyetLNR_Tim_MaMon(root, mamon_cansua) == true) {
					Thong_bao_khong_sua_duoc_MonHoc();
					continue;
				}

				vitri = TimKiemMaMon(dsmon, mamon_cansua);
			
				if (vitri >= 0) {
					Thong_bao_dang_tien_hanh_SUA();

					nhap_mamon = dsmon.DS[vitri]->mamh;
					nhap_tenmon = dsmon.DS[vitri]->tenmh;

					Nhap_thong_tin_mon_hoc();

					setbkcolor(11);
					setcolor(0);
					settextstyle(8, 0, 2);
					outtextxy(370, 128, (char*)(dsmon.DS[vitri]->mamh).c_str());

					setbkcolor(11);
					setcolor(0);
					settextstyle(8, 0, 2);
					outtextxy(370, 188, (char*)(dsmon.DS[vitri]->tenmh).c_str());

					setfillstyle(1, 9);
					bar(470, 310, 640, 260);
					setcolor(0);
					rectangle(470, 260, 640, 310);

					setbkcolor(9);
					setcolor(0);
					settextstyle(10, 0, 3);
					outtextxy(530, 275, (char*)"SUA");
					while (true) {

						ChuyenTrang_DsMonHoc(dsmon, trangthai_trangDSMonHoc);

						if (ismouseclick(WM_LBUTTONDOWN)) {
							getmouseclick(WM_LBUTTONDOWN, xmouse, ymouse);


							// Nguoi dung chon nut => rectangle(700, 770, 870, 820);
							if (xmouse >= 700 && xmouse <= 870 && ymouse >= 770 && ymouse <= 820) {
								BangDanhSachMonHoc();
								trangthai_trangDSMonHoc = true;
							}
							// Nguoi dung chon nut <= rectangle(250, 770, 420, 820);
							else if (xmouse >= 250 && xmouse <= 420 && ymouse >= 770 && ymouse <= 820) {
								BangDanhSachMonHoc();
								trangthai_trangDSMonHoc = false;
							}
							// Nguoi dung chon nut THOAT
							else if (xmouse >= 1200 && xmouse <= 1370 && ymouse >= 770 && ymouse <= 820) {
								Thong_bao_chon_thoat_chuc_nang_SUA();
								if (Lua_chon_CO_hoac_KHONG_cua_thong_bao_trong_ham_chuc_nang()) {
									// khung thong bao
									setfillstyle(1, 15);
									bar(1110, 80, 1500, 370);
									setcolor(0);
									rectangle(1110, 80, 1500, 750);
									line(1110, 140, 1500, 140);

									setbkcolor(15);
									setcolor(4);
									settextstyle(10, 0, 3);
									outtextxy(1240, 100, (char*)"THONG BAO");
									return;
								}
								else {
									// khung thong bao
									setfillstyle(1, 15);
									bar(1110, 80, 1500, 370);
									setcolor(0);
									rectangle(1110, 80, 1500, 750);
									line(1110, 140, 1500, 140);

									setbkcolor(15);
									setcolor(4);
									settextstyle(10, 0, 3);
									outtextxy(1240, 100, (char*)"THONG BAO");
									continue;
								}
							}
							// Nguoi dung chon nhap MA MON 	rectangle(350, 120, 700, 160);
							else if (xmouse >= 350 && xmouse <= 700 && ymouse >= 120 && ymouse <= 160) {
								nhap_mamon = "";
								nhap_mamon = vietText_khung_MA_MON(360, 128, 15);
							}
							// Nguoi dung chon nhap TEN MON rectangle(350, 180, 980, 220);
							else if (xmouse >= 350 && xmouse <= 980 && ymouse >= 180 && ymouse <= 220) {
								nhap_tenmon = "";
								nhap_tenmon = vietText_khung_TEN_MON(360, 189, 40);
							}
							// Nguoi dung chon nut SUA	rectangle(470, 310, 640, 260);
							else if (xmouse >= 470 && xmouse <= 640 && ymouse >= 260 && ymouse <= 310) {
								// Kiem tra khong nhap thong tin
								Thong_bao_xac_nhan_SUA();
								if (Lua_chon_CO_hoac_KHONG_cua_thong_bao_trong_ham_chuc_nang()) {
									// khung thong bao
									setfillstyle(1, 15);
									bar(1110, 80, 1500, 370);
									setcolor(0);
									rectangle(1110, 80, 1500, 750);
									line(1110, 140, 1500, 140);

									setbkcolor(15);
									setcolor(4);
									settextstyle(10, 0, 3);
									outtextxy(1240, 100, (char*)"THONG BAO");

									// Kiem tra nguoi dung khong nhap THONG TIN
									if (nhap_mamon.length() == 0) {
										Thong_bao_khong_duoc_de_trong_MAMON();
										continue;
									}
									else if (nhap_tenmon.length() == 0) {
										Thong_bao_khong_duoc_de_trong_TENMON();
										continue;
									}
									// Chuan hoa thong tin
									VietHoaTatCaChu(nhap_mamon);
									ChuanHoaChuoi(nhap_tenmon);

									if (KiemTraTrungMaMon_chuc_nang_SUA(dsmon, nhap_mamon, vitri)) {
										Thong_bao_trung_MA_MON();
										continue;
									}
									/*if (KiemTraTrungTenMon_chuc_nang_SUA(dsmon, nhap_tenmon, vitri)) {
										Thong_bao_trung_TEN_MON();
										continue;
									}*/

									// Them vao danh sach mon
									dsmon.DS[vitri]->mamh = nhap_mamon;
									dsmon.DS[vitri]->tenmh = nhap_tenmon;

									Thong_bao_THANH_CONG();
									break;
								}
								else {
									// khung thong bao
									setfillstyle(1, 15);
									bar(1110, 80, 1500, 370);
									setcolor(0);
									rectangle(1110, 80, 1500, 750);
									line(1110, 140, 1500, 140);

									setbkcolor(15);
									setcolor(4);
									settextstyle(10, 0, 3);
									outtextxy(1240, 100, (char*)"THONG BAO");
									continue;
								}
							}
						}

						delay(200);
					}

					return;
				}
				else {
					Thong_bao_Ko_tim_thay_MA();
					continue;
				}
			}
		}
		delay(200);
	}

}

//-----------------CAU HOI----------------------------------------
void ThemCauHoi(DS_MonHoc dsmon, ptrCauHoiThi& root, bool& trangthai_trangDSMonHoc) {
	string nhap_mamon = "";
	int vitri;

	int ID = 0;
	string cauhoi = "";
	string cauA, cauB, cauC, cauD;
	string dapAn = "";

	int xmouse = -1;
	int ymouse = -1;

	Quan_ly_cau_hoi_Hien_thi_danh_sach_MON();
	while (true) {
		// Chuyen trang va hien thi danh sach MON
		ChuyenTrang_DsMonHoc(dsmon, trangthai_trangDSMonHoc);

		if (ismouseclick(WM_LBUTTONDOWN)) {
			getmouseclick(WM_LBUTTONDOWN, xmouse, ymouse);

			// Nguoi dung chon nut THOAT
			if (xmouse >= 1200 && xmouse <= 1370 && ymouse >= 770 && ymouse <= 820) {
				Thong_bao_chon_thoat_chuc_nang_THEM();
				if (Lua_chon_CO_hoac_KHONG_cua_thong_bao_trong_ham_chuc_nang()) {

					Xoa_khu_vuc_dien_MA_MONHOC_va_THONG_BAO();
					break;
				}
				else {
					setfillstyle(1, 15);
					bar(1110, 80, 1500, 370);
					setcolor(0);
					rectangle(1110, 80, 1500, 750);
					line(1110, 140, 1500, 140);

					setbkcolor(15);
					setcolor(4);
					settextstyle(10, 0, 3);
					outtextxy(1240, 100, (char*)"THONG BAO");
					continue;
				}
			}
			// Nguoi dung chon nut => rectangle(700, 770, 870, 820);
			else if (xmouse >= 700 && xmouse <= 870 && ymouse >= 770 && ymouse <= 820) {
				BangDanhSachMonHoc();
				trangthai_trangDSMonHoc = true;
			}
			// Nguoi dung chon nut <= rectangle(250, 770, 420, 820);
			else if (xmouse >= 250 && xmouse <= 420 && ymouse >= 770 && ymouse <= 820) {
				BangDanhSachMonHoc();
				trangthai_trangDSMonHoc = false;
			}
			// Nguoi dung nhap MA MON rectangle(350, 120, 700, 160);
			else if (xmouse >= 350 && xmouse <= 700 && ymouse >= 120 && ymouse <= 160) {
				nhap_mamon = "";
				nhap_mamon = vietText_khung_MA_MON(360, 128, 15);
			}
			// Nguoi dung chon nut TRUY CAP rectangle(480, 260, 650, 310);
			else if (xmouse >= 480 && xmouse <= 650 && ymouse >= 260 && ymouse <= 310) {
				// Kiem tra nguoi dung ko nhap MA MON
				if (nhap_mamon.length() == 0) {
					Thong_bao_khong_duoc_de_trong_MAMON();
					continue;
				}

				// Chuan hoa MA MON
				VietHoaTatCaChu(nhap_mamon);

				// Tim kiem MA MON
				vitri = TimKiemMaMon(dsmon, nhap_mamon);

				if (vitri < 0) {
					Thong_bao_Ko_tim_thay_MA();
					continue;
				}
				// Them CAU HOI
				Nhap_cau_hoi_thi();
				Hien_thi_thong_tin_MON_HOC_dang_duoc_them_CAU_HOI(dsmon.DS[vitri]->mamh, dsmon.DS[vitri]->tenmh);

				while (true) {
					if (ismouseclick(WM_LBUTTONDOWN)) {
						getmouseclick(WM_LBUTTONDOWN, xmouse, ymouse);

						// Nguoi dung chon nut THOAT
						if (xmouse >= 1200 && xmouse <= 1370 && ymouse >= 770 && ymouse <= 820) {
							// Reset MA MON nhap vao
							nhap_mamon = "";

							break;
						}
						// Nguoi dung nhap CAU HOI rectangle(250, 120, 1000, 230);
						else if (xmouse >= 250 && xmouse <= 1000 && ymouse >= 120 && ymouse <= 230) {
							cauhoi = "";
							cauhoi = vietText_ChuHoa_ChuThuong_So_KhoangTrang(210, 160, 70, 207, 122, 1068, 218);
						}
						// Nguoi dung nhap CAU A rectangle(250, 280, 1000, 370);
						else if (xmouse >= 250 && xmouse <= 1000 && ymouse >= 280 && ymouse <= 370) {
							cauA = "";
							cauA = vietText_ChuHoa_ChuThuong_So_KhoangTrang(255, 315, 60, 252, 282, 998, 368);
						}
						// Nguoi dung nhap CAU B rectangle(250, 400, 1000, 490);
						else if (xmouse >= 250 && xmouse <= 1000 && ymouse >= 400 && ymouse <= 490) {
							cauB = "";
							cauB = vietText_ChuHoa_ChuThuong_So_KhoangTrang(255, 435, 60, 252, 402, 998, 488);
						}
						// Nguoi dung nhap CAU C rectangle(250, 520, 1000, 610);
						else if (xmouse >= 250 && xmouse <= 1000 && ymouse >= 520 && ymouse <= 610) {
							cauC = "";
							cauC = vietText_ChuHoa_ChuThuong_So_KhoangTrang(255, 555, 60, 252, 522, 998, 608);
						}
						// Nguoi dung nhap CAU D rectangle(250, 640, 1000, 730);
						else if (xmouse >= 250 && xmouse <= 1000 && ymouse >= 640 && ymouse <= 730) {
							cauD = "";
							cauD = vietText_ChuHoa_ChuThuong_So_KhoangTrang(255, 675, 60, 252, 642, 998, 728);
						}
						// Nguoi dung chon A rectangle(70, 295, 130, 355);
						else if (xmouse >= 70 && xmouse <= 130 && ymouse >= 295 && ymouse <= 355) {
							dapAn = "";
							dapAn = "A";
							// Doi mau Cau A
							setcolor(1);
							circle(100, 325, 10);
							setfillstyle(1, 1);
							floodfill(106, 327, 1);

							// Doi cac Cau con lai ve binh thuong							
							setfillstyle(1, 15);
							floodfill(101, 445, 0);
							floodfill(101, 564, 0);
							floodfill(101, 683, 0);
						}
						// Nguoi dung chon B rectangle(70, 415, 130, 475);
						else if (xmouse >= 70 && xmouse <= 130 && ymouse >= 415 && ymouse <= 475) {
							dapAn = "";
							dapAn = "B";
							// Doi mau Cau B
							setcolor(1);
							circle(100, 444, 10);
							setfillstyle(1, 1);
							floodfill(106, 445, 1);

							// Doi cac Cau con lai ve binh thuong							
							setfillstyle(1, 15);
							floodfill(101, 326, 0);
							floodfill(101, 564, 0);
							floodfill(101, 683, 0);

						}
						// Nguoi dung chon C rectangle(70, 535, 130, 595);
						else if (xmouse >= 70 && xmouse <= 130 && ymouse >= 535 && ymouse <= 595) {
							dapAn = "";
							dapAn = "C";
							// Doi mau Cau C
							setcolor(1);
							circle(100, 563, 10);
							setfillstyle(1, 1);
							floodfill(106, 564, 1);

							// Doi cac Cau con lai ve binh thuong							
							setfillstyle(1, 15);
							floodfill(101, 326, 0);
							floodfill(101, 445, 0);
							floodfill(101, 683, 0);

						}
						// Nguoi dung chon D 	rectangle(70, 655, 130, 715);
						else if (xmouse >= 70 && xmouse <= 130 && ymouse >= 655 && ymouse <= 715) {
							dapAn = "";
							dapAn = "D";
							// Doi mau Cau D
							setcolor(1);
							circle(100, 682, 10);
							setfillstyle(1, 1);
							floodfill(106, 683, 1);

							// Doi cac Cau con lai ve binh thuong							
							setfillstyle(1, 15);
							floodfill(101, 326, 0);
							floodfill(101, 564, 0);
							floodfill(101, 445, 0);

						}
						// Nguoi dung chon THEM rectangle(480, 770, 650, 820);
						else if (xmouse >= 480 && xmouse <= 650 && ymouse >= 770 && ymouse <= 820) {
							// Check nguoi dung ko nhap day du thong tin
							if ((cauhoi.length() == 0) || (cauA.length() == 0) || (cauB.length() == 0) || (cauC.length() == 0) || (cauD.length() == 0)) {
								Thong_bao_Vui_long_nhap_DAY_DU_THONG_TIN();
								continue;
							}
							// check nguoi dung chon DAP AN dung
							else if (dapAn == "") {
								Thong_bao_vui_long_Chon_DAP_AN();
								continue;
							}

							// Chuan hoa chuoi
							ChuanHoaChuoi_inhoa_kitudautien(cauhoi);
							ChuanHoaChuoi_inhoa_kitudautien(cauA);
							ChuanHoaChuoi_inhoa_kitudautien(cauB);
							ChuanHoaChuoi_inhoa_kitudautien(cauC);
							ChuanHoaChuoi_inhoa_kitudautien(cauD);

							// Kiem tra trung DAP AN
							if ((cauA == cauB) || (cauA == cauC) || (cauA == cauD) || (cauB == cauC) || (cauB == cauD) || (cauC == cauD)) {
								Thong_bao_trung_DAP_AN();
								continue;
							}

							ID = randomNumber(root);

							// Them vao DS Cau hoi
							root = insertNodeAVL(root, ID, nhap_mamon, cauhoi, cauA, cauB, cauC, cauD, dapAn);

							Thong_bao_THANH_CONG();
							Nhap_cau_hoi_thi();
							continue;
						}
					}
					delay(200);
				}
				Quan_ly_cau_hoi_Hien_thi_danh_sach_MON();
				continue;
			}
		}
		delay(200);
	}
}
void XoaCauHoi(DS_MonHoc dsmon, ptrCauHoiThi& root, int& trangthai_trangDSCauHoi) {
	// Khung chuc nang
	setfillstyle(1, 15);
	bar(50, 80, 1080, 320);
	setcolor(0);
	rectangle(50, 80, 1080, 320);

	// Nut XOA
	setfillstyle(1, 9);
	bar(470, 310, 640, 260);
	setcolor(0);
	rectangle(470, 310, 640, 260);

	setbkcolor(9);
	setcolor(0);
	settextstyle(10, 0, 3);
	outtextxy(535, 275, (char*)"XOA");

	// Khu vuc dien ID
	setfillstyle(1, 11);
	bar(350, 120, 700, 160);
	setcolor(0);
	rectangle(350, 120, 700, 160);

	setbkcolor(15);
	setcolor(0);
	settextstyle(10, 0, 2);
	outtextxy(230, 130, (char*)"ID");

	int xmouse = -1;
	int ymouse = -1;

	string id = "";

	while (true) {
		ChuyenTrang_DsCauHoi(root, trangthai_trangDSCauHoi);

		if (ismouseclick(WM_LBUTTONDOWN)) {
			getmouseclick(WM_LBUTTONDOWN, xmouse, ymouse);

			// Nguoi dung chon nut THOAT
			if (xmouse >= 1200 && xmouse <= 1370 && ymouse >= 770 && ymouse <= 820) {
				Thong_bao_chon_thoat_chuc_nang_XOA();
				if (Lua_chon_CO_hoac_KHONG_cua_thong_bao_trong_ham_chuc_nang()) {

					break;
				}
				else {
					setfillstyle(1, 15);
					bar(1110, 80, 1500, 370);
					setcolor(0);
					rectangle(1110, 80, 1500, 750);
					line(1110, 140, 1500, 140);

					setbkcolor(15);
					setcolor(4);
					settextstyle(10, 0, 3);
					outtextxy(1240, 100, (char*)"THONG BAO");
					continue;
				}
			}
			// Nguoi dung chon nut => rectangle(700, 770, 870, 820);
			else if (xmouse >= 700 && xmouse <= 870 && ymouse >= 770 && ymouse <= 820) {
				BangDanhSachCauHoi();
				// chi hien thi 5 trang
				if (trangthai_trangDSCauHoi < 5) {
					trangthai_trangDSCauHoi++;
				}
			}
			// Nguoi dung chon nut <= rectangle(250, 770, 420, 820);
			else if (xmouse >= 250 && xmouse <= 420 && ymouse >= 770 && ymouse <= 820) {
				BangDanhSachCauHoi();
				if (trangthai_trangDSCauHoi > 1) {
					trangthai_trangDSCauHoi--;
				}
			}
			// Nguoi dung nhap ID 	rectangle(350, 120, 700, 160);
			else if (xmouse >= 350 && xmouse <= 700 && ymouse >= 120 && ymouse <= 160) {
				id = "";
				id = vietText_So(360, 128, 5, 352, 122, 698, 158);
			}
			// Nguoi dung chon nut XOA 	rectangle(470, 310, 640, 260);
			else if (xmouse >= 470 && xmouse <= 640 && ymouse >= 260 && ymouse <= 310) {
				// check nguoi dung khong nhap ID
				if (id.length() == 0) {
					Thong_bao_khong_duoc_de_trong_ID();
					continue;
				}
				// Tim kiem ID
				if (SearchNode(root, stoi(id)) == false) {
					Thong_bao_Ko_tim_thay_ID();
					continue;
				}
				// Tien hanh xoa Cau Hoi
				root = deleteNodeAVL(root, stoi(id));

				Thong_bao_THANH_CONG();

				// Khu vuc dien ID
				setfillstyle(1, 11);
				bar(350, 120, 700, 160);
				setcolor(0);
				rectangle(350, 120, 700, 160);

				BangDanhSachCauHoi();
				continue;
			}
		}
		delay(200);
	}

}
void SuaCauHoi(DS_MonHoc dsmon, ptrCauHoiThi& root, int& trangthai_trangDSCauHoi) {
	// Khung chuc nang
	setfillstyle(1, 15);
	bar(50, 80, 1080, 320);
	setcolor(0);
	rectangle(50, 80, 1080, 320);

	// Nut SUA
	setfillstyle(1, 9);
	bar(470, 310, 640, 260);
	setcolor(0);
	rectangle(470, 310, 640, 260);

	setbkcolor(9);
	setcolor(0);
	settextstyle(10, 0, 3);
	outtextxy(535, 275, (char*)"SUA");

	// Khu vuc dien ID
	setfillstyle(1, 11);
	bar(350, 120, 700, 160);
	setcolor(0);
	rectangle(350, 120, 700, 160);

	setbkcolor(15);
	setcolor(0);
	settextstyle(10, 0, 2);
	outtextxy(230, 130, (char*)"ID");

	int xmouse = -1;
	int ymouse = -1;

	string id = "";
	ptrCauHoiThi node = NULL;
	int vitri = 0;

	string cauhoi = "";
	string cauA, cauB, cauC, cauD;
	string dapAn = "";

	// gan dia chi cac Node vao arr
	int soluong = demNode(root);
	ptrCauHoiThi* arr = new ptrCauHoiThi[soluong];
	duyetLNR_Gan_DIA_CHI(root, arr);

	while (true) {
		ChuyenTrang_DsCauHoi(root, trangthai_trangDSCauHoi);

		if (ismouseclick(WM_LBUTTONDOWN)) {
			getmouseclick(WM_LBUTTONDOWN, xmouse, ymouse);

			// Nguoi dung chon nut => rectangle(700, 770, 870, 820);
			if (xmouse >= 700 && xmouse <= 870 && ymouse >= 770 && ymouse <= 820) {
				BangDanhSachCauHoi();
				// chi hien thi 5 trang
				if (trangthai_trangDSCauHoi < 5) {
					trangthai_trangDSCauHoi++;
				}
			}
			// Nguoi dung chon nut <= rectangle(250, 770, 420, 820);
			else if (xmouse >= 250 && xmouse <= 420 && ymouse >= 770 && ymouse <= 820) {
				BangDanhSachCauHoi();
				if (trangthai_trangDSCauHoi > 1) {
					trangthai_trangDSCauHoi--;
				}
			}
			// Nguoi dung chon nut THOAT
			else if (xmouse >= 1200 && xmouse <= 1370 && ymouse >= 770 && ymouse <= 820) {
				Thong_bao_chon_thoat_chuc_nang_SUA();
				if (Lua_chon_CO_hoac_KHONG_cua_thong_bao_trong_ham_chuc_nang()) {
					break;
				}
				else {
					setfillstyle(1, 15);
					bar(1110, 80, 1500, 370);
					setcolor(0);
					rectangle(1110, 80, 1500, 750);
					line(1110, 140, 1500, 140);

					setbkcolor(15);
					setcolor(4);
					settextstyle(10, 0, 3);
					outtextxy(1240, 100, (char*)"THONG BAO");

					continue;
				}
			}
			// Nguoi dung nhap ID 	rectangle(350, 120, 700, 160);
			else if (xmouse >= 350 && xmouse <= 700 && ymouse >= 120 && ymouse <= 160) {
				id = "";
				id = vietText_So(360, 128, 5, 352, 122, 698, 158);
			}
			// Nguoi dung chon nut SUA 	rectangle(470, 310, 640, 260);
			else if (xmouse >= 470 && xmouse <= 640 && ymouse >= 260 && ymouse <= 310) {
				// check nguoi dung khong nhap ID
				if (id.length() == 0) {
					Thong_bao_khong_duoc_de_trong_ID();
					continue;
				}
				// Tim kiem ID
				node = SearchNodeInfo(root, stoi(id));
				if (node == NULL) {
					Thong_bao_Ko_tim_thay_ID();
					continue;
				}
				// Tim thay Cau Hoi
				vitri = TimKiemMaMon(dsmon, node->CH.mamh);

				Nhap_cau_hoi_thi();
				Hien_thi_thong_tin_MON_HOC_dang_duoc_sua_CAU_HOI(dsmon.DS[vitri]->mamh, dsmon.DS[vitri]->tenmh);

				// hien thong tin cau hoi dang duoc SUA
				setbkcolor(11);
				setcolor(0);
				settextstyle(8, 0, 2);

				outtextxy(215, 160, (char*)(node->CH.noidung).c_str());
				outtextxy(260, 315, (char*)(node->CH.A).c_str());
				outtextxy(260, 435, (char*)(node->CH.B).c_str());
				outtextxy(260, 555, (char*)(node->CH.C).c_str());
				outtextxy(260, 675, (char*)(node->CH.D).c_str());

				if (node->CH.dapan == "A") {
					// Doi mau Cau A
					setcolor(1);
					circle(100, 325, 10);
					setfillstyle(1, 1);
					floodfill(106, 327, 1);
				}
				else if (node->CH.dapan == "B") {
					// Doi mau Cau B
					setcolor(1);
					circle(100, 444, 10);
					setfillstyle(1, 1);
					floodfill(106, 445, 1);
				}
				else if (node->CH.dapan == "C") {
					// Doi mau Cau C
					setcolor(1);
					circle(100, 563, 10);
					setfillstyle(1, 1);
					floodfill(106, 564, 1);
				}
				else if (node->CH.dapan == "D") {
					// Doi mau Cau D
					setcolor(1);
					circle(100, 682, 10);
					setfillstyle(1, 1);
					floodfill(106, 683, 1);
				}

				cauhoi = node->CH.noidung;
				cauA = node->CH.A;
				cauB = node->CH.B;
				cauC = node->CH.C;
				cauD = node->CH.D;
				dapAn = node->CH.dapan;

				// Nut SUA
				setfillstyle(1, 10);
				bar(480, 770, 650, 820);
				setcolor(0);
				rectangle(480, 770, 650, 820);

				setbkcolor(10);
				setcolor(0);
				settextstyle(10, 0, 3);
				outtextxy(545, 785, (char*)"SUA");

				while (true) {
					if (ismouseclick(WM_LBUTTONDOWN)) {
						getmouseclick(WM_LBUTTONDOWN, xmouse, ymouse);

						// Nguoi dung chon nut THOAT
						if (xmouse >= 1200 && xmouse <= 1370 && ymouse >= 770 && ymouse <= 820) {
							// reset id
							id = "";
							break;
						}
						// Nguoi dung nhap CAU HOI rectangle(250, 120, 1000, 230);
						else if (xmouse >= 250 && xmouse <= 1000 && ymouse >= 120 && ymouse <= 230) {
							cauhoi = "";
							cauhoi = vietText_ChuHoa_ChuThuong_So_KhoangTrang(210, 160, 70, 207, 122, 1068, 218);
						}
						// Nguoi dung nhap CAU A rectangle(250, 280, 1000, 370);
						else if (xmouse >= 250 && xmouse <= 1000 && ymouse >= 280 && ymouse <= 370) {
							cauA = "";
							cauA = vietText_ChuHoa_ChuThuong_So_KhoangTrang(255, 315, 60, 252, 282, 998, 368);
						}
						// Nguoi dung nhap CAU B rectangle(250, 400, 1000, 490);
						else if (xmouse >= 250 && xmouse <= 1000 && ymouse >= 400 && ymouse <= 490) {
							cauB = "";
							cauB = vietText_ChuHoa_ChuThuong_So_KhoangTrang(255, 435, 60, 252, 402, 998, 488);
						}
						// Nguoi dung nhap CAU C rectangle(250, 520, 1000, 610);
						else if (xmouse >= 250 && xmouse <= 1000 && ymouse >= 520 && ymouse <= 610) {
							cauC = "";
							cauC = vietText_ChuHoa_ChuThuong_So_KhoangTrang(255, 555, 60, 252, 522, 998, 608);
						}
						// Nguoi dung nhap CAU D rectangle(250, 640, 1000, 730);
						else if (xmouse >= 250 && xmouse <= 1000 && ymouse >= 640 && ymouse <= 730) {
							cauD = "";
							cauD = vietText_ChuHoa_ChuThuong_So_KhoangTrang(255, 675, 60, 252, 642, 998, 728);
						}
						// Nguoi dung chon A rectangle(70, 295, 130, 355);
						else if (xmouse >= 70 && xmouse <= 130 && ymouse >= 295 && ymouse <= 355) {
							dapAn = "";
							dapAn = "A";
							// Doi mau Cau A
							setcolor(1);
							circle(100, 325, 10);
							setfillstyle(1, 1);
							floodfill(106, 327, 1);

							// Doi cac Cau con lai ve binh thuong							
							setfillstyle(1, 15);
							floodfill(101, 445, 0);
							floodfill(101, 564, 0);
							floodfill(101, 683, 0);
						}
						// Nguoi dung chon B rectangle(70, 415, 130, 475);
						else if (xmouse >= 70 && xmouse <= 130 && ymouse >= 415 && ymouse <= 475) {
							dapAn = "";
							dapAn = "B";
							// Doi mau Cau B
							setcolor(1);
							circle(100, 444, 10);
							setfillstyle(1, 1);
							floodfill(106, 445, 1);

							// Doi cac Cau con lai ve binh thuong							
							setfillstyle(1, 15);
							floodfill(101, 326, 0);
							floodfill(101, 564, 0);
							floodfill(101, 683, 0);

						}
						// Nguoi dung chon C rectangle(70, 535, 130, 595);
						else if (xmouse >= 70 && xmouse <= 130 && ymouse >= 535 && ymouse <= 595) {
							dapAn = "";
							dapAn = "C";
							// Doi mau Cau C
							setcolor(1);
							circle(100, 563, 10);
							setfillstyle(1, 1);
							floodfill(106, 564, 1);

							// Doi cac Cau con lai ve binh thuong							
							setfillstyle(1, 15);
							floodfill(101, 326, 0);
							floodfill(101, 445, 0);
							floodfill(101, 683, 0);

						}
						// Nguoi dung chon D 	rectangle(70, 655, 130, 715);
						else if (xmouse >= 70 && xmouse <= 130 && ymouse >= 655 && ymouse <= 715) {
							dapAn = "";
							dapAn = "D";
							// Doi mau Cau D
							setcolor(1);
							circle(100, 682, 10);
							setfillstyle(1, 1);
							floodfill(106, 683, 1);

							// Doi cac Cau con lai ve binh thuong							
							setfillstyle(1, 15);
							floodfill(101, 326, 0);
							floodfill(101, 564, 0);
							floodfill(101, 445, 0);

						}
						// Nguoi dung chon SUA rectangle(480, 770, 650, 820);
						else if (xmouse >= 480 && xmouse <= 650 && ymouse >= 770 && ymouse <= 820) {
							// Check nguoi dung ko nhap day du thong tin
							if ((cauhoi.length() == 0) || (cauA.length() == 0) || (cauB.length() == 0) || (cauC.length() == 0) || (cauD.length() == 0)) {
								Thong_bao_Vui_long_nhap_DAY_DU_THONG_TIN();
								continue;
							}
							// check nguoi dung chon DAP AN dung
							else if (dapAn == "") {
								Thong_bao_vui_long_Chon_DAP_AN();
								continue;
							}

							// Chuan hoa chuoi
							ChuanHoaChuoi_inhoa_kitudautien(cauhoi);
							ChuanHoaChuoi_inhoa_kitudautien(cauA);
							ChuanHoaChuoi_inhoa_kitudautien(cauB);
							ChuanHoaChuoi_inhoa_kitudautien(cauC);
							ChuanHoaChuoi_inhoa_kitudautien(cauD);

							// Kiem tra trung DAP AN
							if ((cauA == cauB) || (cauA == cauC) || (cauA == cauD) || (cauB == cauC) || (cauB == cauD) || (cauC == cauD)) {
								Thong_bao_trung_DAP_AN();
								continue;
							}

							// Thay doi thong tin cau hoi
							for (int i = 0; i < soluong; i++) {
								if (stoi(id) == arr[i]->CH.id) {
									arr[i]->CH.noidung = cauhoi;
									arr[i]->CH.A = cauA;
									arr[i]->CH.B = cauB;
									arr[i]->CH.C = cauC;
									arr[i]->CH.D = cauD;
									arr[i]->CH.dapan = dapAn;
									break;
								}
							}

							Thong_bao_THANH_CONG();
							continue;
						}
					}
					delay(200);
				}
				Quan_ly_cau_hoi();
				// Khung chuc nang
				setfillstyle(1, 15);
				bar(50, 80, 1080, 320);
				setcolor(0);
				rectangle(50, 80, 1080, 320);

				// Nut SUA
				setfillstyle(1, 9);
				bar(470, 310, 640, 260);
				setcolor(0);
				rectangle(470, 310, 640, 260);

				setbkcolor(9);
				setcolor(0);
				settextstyle(10, 0, 3);
				outtextxy(535, 275, (char*)"SUA");

				// Khu vuc dien ID
				setfillstyle(1, 11);
				bar(350, 120, 700, 160);
				setcolor(0);
				rectangle(350, 120, 700, 160);

				setbkcolor(15);
				setcolor(0);
				settextstyle(10, 0, 2);
				outtextxy(230, 130, (char*)"ID");
				continue;
			}
		}
		delay(200);
	}
	// xoa mang tam
	delete[]arr;
}

//----------------THI TRAC NGHIEM----------------------------------
void XemLaiDapAn(DS_Lop dslop, int vitrilop, string mamonthi, string masinhvien, int socauhoi) {
	ptrSinhVien sinhvien_dangthi = TimKiemMaSinhVien_TraVeNode(dslop, masinhvien, vitrilop); // Dung de kiem tra chuong trinh 
	ptrDiemThi DiemThiSinhVien = sinhvien_dangthi->info.ds_diemthi; // tra ve diem thi mon hoc can xem dap an

	int xmouse = -1;
	int ymouse = -1;
	int trang = 1;

	XemDapAn_graphic();
	while (true) {
		// Cau hoi so 1, 2, 3...
		setbkcolor(15);
		setcolor(0);
		settextstyle(10, 0, 2);
		outtextxy(615, 100, (char*)(to_string(trang)).c_str());

		// Noi dung Cau hoi
		setbkcolor(15);
		setcolor(1);
		settextstyle(8, 0, 2);
		outtextxy(100, 170, (char*)(DiemThiSinhVien->info.DapAn[trang - 1]->noidung).c_str());

		// Dap an
		setcolor(0);
		outtextxy(190, 360, (char*)(DiemThiSinhVien->info.DapAn[trang - 1]->A).c_str());
		outtextxy(190, 460, (char*)(DiemThiSinhVien->info.DapAn[trang - 1]->B).c_str());
		outtextxy(190, 560, (char*)(DiemThiSinhVien->info.DapAn[trang - 1]->C).c_str());
		outtextxy(190, 660, (char*)(DiemThiSinhVien->info.DapAn[trang - 1]->D).c_str());

		// Dap an duoc chon
		if ((DiemThiSinhVien->info.CauTraLoi[trang - 1]->dapan == "A")) {
			setcolor(1);
			circle(100, 370, 10);
			setfillstyle(1, 1);
			floodfill(106, 374, 1);

		}
		else if (DiemThiSinhVien->info.CauTraLoi[trang - 1]->dapan == "B") {
			// Doi mau Cau B
			setcolor(1);
			circle(100, 470, 10);
			setfillstyle(1, 1);
			floodfill(106, 472, 1);
		}
		else if (DiemThiSinhVien->info.CauTraLoi[trang - 1]->dapan == "C") {
			// Doi mau Cau C
			setcolor(1);
			circle(100, 570, 10);
			setfillstyle(1, 1);
			floodfill(106, 572, 1);
		}
		else if (DiemThiSinhVien->info.CauTraLoi[trang - 1]->dapan == "D") {
			// Doi mau Cau D
			setcolor(1);
			circle(100, 670, 10);
			setfillstyle(1, 1);
			floodfill(106, 672, 1);
		}


		// Dap an DUNG
		if ((DiemThiSinhVien->info.DapAn[trang - 1]->dapan == "A") && (DiemThiSinhVien->info.DapAn[trang - 1]->dapan != DiemThiSinhVien->info.CauTraLoi[trang - 1]->dapan)) {
			setcolor(4);
			circle(100, 370, 10);
			setfillstyle(1, 4);
			floodfill(106, 374, 4);
		}
		else if ((DiemThiSinhVien->info.DapAn[trang - 1]->dapan == "B") && (DiemThiSinhVien->info.DapAn[trang - 1]->dapan != DiemThiSinhVien->info.CauTraLoi[trang - 1]->dapan)) {
			// Doi mau Cau B
			setcolor(4);
			circle(100, 470, 10);
			setfillstyle(1, 4);
			floodfill(106, 472, 4);
		}
		else if ((DiemThiSinhVien->info.DapAn[trang - 1]->dapan == "C") && (DiemThiSinhVien->info.DapAn[trang - 1]->dapan != DiemThiSinhVien->info.CauTraLoi[trang - 1]->dapan)) {
			// Doi mau Cau C
			setcolor(4);
			circle(100, 570, 10);
			setfillstyle(1, 4);
			floodfill(106, 572, 4);
		}
		else if ((DiemThiSinhVien->info.DapAn[trang - 1]->dapan == "D") && (DiemThiSinhVien->info.DapAn[trang - 1]->dapan != DiemThiSinhVien->info.CauTraLoi[trang - 1]->dapan)) {
			// Doi mau Cau D
			setcolor(4);
			circle(100, 670, 10);
			setfillstyle(1, 4);
			floodfill(106, 672, 4);
		}


		if (ismouseclick(WM_LBUTTONDOWN)) {
			getmouseclick(WM_LBUTTONDOWN, xmouse, ymouse);
			// Nguoi dung chon nut => rectangle(700, 770, 870, 820);
			if (xmouse >= 700 && xmouse <= 870 && ymouse >= 770 && ymouse <= 820) {
				BangThiTracNghiem_graphic();

				if (trang < socauhoi) {
					trang++;
				}
			}
			// Nguoi dung chon nut <= rectangle(250, 770, 420, 820);
			else if (xmouse >= 250 && xmouse <= 420 && ymouse >= 770 && ymouse <= 820) {
				BangThiTracNghiem_graphic();

				if (trang > 1) {
					trang--;
				}
			}
			// Nguoi dung chon nut THOAT
			else if (xmouse >= 1200 && xmouse <= 1370 && ymouse >= 770 && ymouse <= 820) {
				Thong_bao_xac_nhan_THOAT();
				if (Lua_chon_CO_hoac_KHONG_cua_thong_bao_trong_ham_chuc_nang_xemdapan()) {
					break;
				}
				else {
					// Khung thong bao
					setfillstyle(1, 15);
					bar(1115, 365, 1495, 745);
					continue;
				}

			}
		}
		delay(200);
	}
}
void XemDiemThi_SinhVien(DS_Lop dslop, DS_MonHoc dsmon, string masinhvien, bool& trangthai_trangDSMonHoc) {
	string mamon = "";
	string malop = "";
	int vitrilop = -1;
	int vitrimon = -1;

	int xmouse = -1;
	int ymouse = -1;

	Xem_Diem_Sinh_Vien_graphic();
	while (true) {

		// Thong tin Sinh Vien
		setbkcolor(7);
		setcolor(1);
		settextstyle(10, 0, 3);
		outtextxy(50, 10, (char*)"THI SINH");

		setbkcolor(15);
		setcolor(1);
		settextstyle(10, 0, 3);
		outtextxy(50, 40, (char*)(masinhvien).c_str());

		ChuyenTrang_DsMonHoc(dsmon, trangthai_trangDSMonHoc);

		if (ismouseclick(WM_LBUTTONDOWN)) {
			getmouseclick(WM_LBUTTONDOWN, xmouse, ymouse);

			// Nguoi dung chon nut => rectangle(700, 770, 870, 820);
			if (xmouse >= 700 && xmouse <= 870 && ymouse >= 770 && ymouse <= 820) {
				BangDanhSachMonHoc();
				trangthai_trangDSMonHoc = true;
			}
			// Nguoi dung chon nut <= rectangle(250, 770, 420, 820);
			else if (xmouse >= 250 && xmouse <= 420 && ymouse >= 770 && ymouse <= 820) {
				BangDanhSachMonHoc();
				trangthai_trangDSMonHoc = false;
			}
			// Nguoi dung chon nut THOAT 	
			else if (xmouse >= 1200 && xmouse <= 1370 && ymouse >= 770 && ymouse <= 820) {
				break;
			}
			// Nguoi dung nhap MA MON rectangle(350, 120, 700, 160);
			else if (xmouse >= 350 && xmouse <= 700 && ymouse >= 120 && ymouse <= 160) {
				mamon = "";
				mamon = vietText_khung_MA_MON(360, 128, 15);

			}
			// Nguoi dung chon XEM 	rectangle(470, 260, 640, 310);
			else if (xmouse >= 470 && xmouse <= 640 && ymouse >= 260 && ymouse <= 310) {
				// Kiem tra nguoi dung ko nhap  MA MON
				if (mamon.length() == 0) {
					Thong_bao_khong_duoc_de_trong_MAMON();
					continue;
				}

				// Chuan hoa MA MON
				VietHoaTatCaChu(mamon);

				// Tim va tra ve vi tri MON HOC trong mang, de xem co ton tai hay ko
				vitrimon = TimKiemMaMon(dsmon, mamon);

				// Tim vi tri LOP co chua SINH VIEN hien tai trong mang
				malop = "";
				malop = malop.append(masinhvien, 0, masinhvien.length() - 3);
				vitrilop = TimKiemMaLop(dslop, malop);


				if (vitrimon >= 0) {

					// sinh vien chua THI MON HOC 
					if (TimKiemDiemSinhVien(dslop, masinhvien, mamon, vitrilop) == false) {
						Thong_bao_Sinh_Vien_Chua_Thi_Mon_Hoc();
						continue;
					}
					// Sinh vien DA THI MON HOC
					else {
						ptrSinhVien sinhvien_dangtruycap = TimKiemMaSinhVien_TraVeNode(dslop, masinhvien, vitrilop);
						ptrDiemThi DiemThiSinhVien = TimKiemDiemSinhVien_TraVeNode(sinhvien_dangtruycap, mamon); // tra ve diem thi mon hoc can xem dap an
						// Hien ket qua thi
						HienThiKetQuaThi(DiemThiSinhVien->info.diem, mamon, dsmon.DS[vitrimon]->tenmh);

						while (true) {
							if (ismouseclick(WM_LBUTTONDOWN)) {
								getmouseclick(WM_LBUTTONDOWN, xmouse, ymouse);

								// Nguoi dung chon THOAT
								if (xmouse >= 800 && xmouse <= 1010 && ymouse >= 600 && ymouse <= 650) {
									break;
								}
								// Nguoi dung chon DAP AN
								else if (xmouse >= 550 && xmouse <= 760 && ymouse >= 600 && ymouse <= 650) {
									XemLaiDapAn(dslop, vitrilop, mamon, masinhvien, (DiemThiSinhVien->info.n + 1));								
									break;
								}
							}
							delay(200);
						}

						Xem_Diem_Sinh_Vien_graphic();
						continue;
					}
				}
				else {
					Thong_bao_Ko_tim_thay_MA();
					continue;
				}
			}
		}
		delay(200);
	}
}
void TienHanhThi(DS_Lop& dslop, int time, int socauhoi, int vitrilop, ptrCauHoiThi cauhoihienco[], string masinhvien, string mamonthi, string tenmonthi) {
	int xmouse = -1;
	int ymouse = -1;
	int trang = 1;

	phut = time;
	stop = false; // khoi dong lai dieu kien dung cua luong 

	// danh sach cau hoi de thi da duoc chon random va Mang luu Dap An cua Sinh Vien
	ptrCauHoiThi* cauhoithi = new ptrCauHoiThi[socauhoi]; // dung de so sanh dap an va tinh diem
	CauHoiThi* dapAnSinhVien = new CauHoiThi[socauhoi]; // luu lai noi dung cau tra loi cua Sinh Vien

	randomCauHoi(cauhoihienco, cauhoithi, socauhoi);

	for (int i = 0; i < socauhoi; i++) {
		dapAnSinhVien[i].noidung = cauhoithi[i]->CH.noidung;
		dapAnSinhVien[i].id = cauhoithi[i]->CH.id;
		dapAnSinhVien[i].mamh = cauhoithi[i]->CH.mamh;
		dapAnSinhVien[i].A = cauhoithi[i]->CH.A;
		dapAnSinhVien[i].B = cauhoithi[i]->CH.B;
		dapAnSinhVien[i].C = cauhoithi[i]->CH.C;
		dapAnSinhVien[i].D = cauhoithi[i]->CH.D;
		dapAnSinhVien[i].dapan = "";
	}

	ptrSinhVien sinhvien_dangthi = TimKiemMaSinhVien_TraVeNode(dslop, masinhvien, vitrilop); // Dung de kiem tra chuong trinh 

	TienHanhThi_graphic();

	thread clock;
	clock = thread(printClock);

	while (true) {
		// het thoi gian
		if (stop == true) {
			break;

		}
		// Dong Ho
		setbkcolor(7);
		setcolor(0);
		settextstyle(10, 0, 6);
		outtextxy(1230, 10, (char*)(to_string(phut)).c_str());
		outtextxy(1290, 10, (char*)":");
		outtextxy(1330, 10, (char*)(to_string(giay)).c_str());

		// Cau hoi so 1, 2, 3...
		setbkcolor(15);
		setcolor(0);
		settextstyle(10, 0, 2);
		outtextxy(615, 100, (char*)(to_string(trang)).c_str());

		// Noi dung Cau hoi
		setbkcolor(15);
		setcolor(1);
		settextstyle(8, 0, 2);
		outtextxy(100, 170, (char*)(dapAnSinhVien[trang - 1].noidung).c_str());

		// Dap an
		setcolor(0);
		outtextxy(190, 360, (char*)(dapAnSinhVien[trang - 1].A).c_str());
		outtextxy(190, 460, (char*)(dapAnSinhVien[trang - 1].B).c_str());
		outtextxy(190, 560, (char*)(dapAnSinhVien[trang - 1].C).c_str());
		outtextxy(190, 660, (char*)(dapAnSinhVien[trang - 1].D).c_str());

		// Dap an duoc chon

		if (dapAnSinhVien[trang - 1].dapan == "A") {
			// Doi mau Cau A
			setcolor(1);
			circle(100, 370, 10);
			setfillstyle(1, 1);
			floodfill(106, 374, 1);
		}
		else if (dapAnSinhVien[trang - 1].dapan == "B") {
			// Doi mau Cau B
			setcolor(1);
			circle(100, 470, 10);
			setfillstyle(1, 1);
			floodfill(106, 472, 1);
		}
		else if (dapAnSinhVien[trang - 1].dapan == "C") {
			// Doi mau Cau C
			setcolor(1);
			circle(100, 570, 10);
			setfillstyle(1, 1);
			floodfill(106, 572, 1);
		}
		else if (dapAnSinhVien[trang - 1].dapan == "D") {
			// Doi mau Cau D
			setcolor(1);
			circle(100, 670, 10);
			setfillstyle(1, 1);
			floodfill(106, 672, 1);
		}

		if (ismouseclick(WM_LBUTTONDOWN)) {
			getmouseclick(WM_LBUTTONDOWN, xmouse, ymouse);

			// Nguoi dung chon nut => rectangle(700, 770, 870, 820);
			if (xmouse >= 700 && xmouse <= 870 && ymouse >= 770 && ymouse <= 820) {
				BangThiTracNghiem_graphic();

				if (trang < socauhoi) {
					trang++;
				}
			}
			// Nguoi dung chon nut <= rectangle(250, 770, 420, 820);
			else if (xmouse >= 250 && xmouse <= 420 && ymouse >= 770 && ymouse <= 820) {
				BangThiTracNghiem_graphic();

				if (trang > 1) {
					trang--;
				}
			}
			// Nguoi dung chon A rectangle(70, 340, 130, 400);
			else if (xmouse >= 70 && xmouse <= 130 && ymouse >= 340 && ymouse <= 400) {
				dapAnSinhVien[trang - 1].dapan = "A";

				// Doi mau Cau A
				setcolor(1);
				circle(100, 370, 10);
				setfillstyle(1, 1);
				floodfill(106, 374, 1);

				// Doi cac Cau con lai ve binh thuong							
				setfillstyle(1, 15);
				floodfill(101, 472, 0);
				floodfill(101, 572, 0);
				floodfill(101, 672, 0);
			}
			// Nguoi dung chon B rectangle(70, 440, 130, 500);
			else if (xmouse >= 70 && xmouse <= 130 && ymouse >= 440 && ymouse <= 500) {
				dapAnSinhVien[trang - 1].dapan = "B";

				// Doi mau Cau B
				setcolor(1);
				circle(100, 470, 10);
				setfillstyle(1, 1);
				floodfill(106, 472, 1);

				// Doi cac Cau con lai ve binh thuong							
				setfillstyle(1, 15);
				floodfill(101, 372, 0);
				floodfill(101, 572, 0);
				floodfill(101, 672, 0);

			}
			// Nguoi dung chon C rectangle(70, 540, 130, 600);
			else if (xmouse >= 70 && xmouse <= 130 && ymouse >= 540 && ymouse <= 600) {
				dapAnSinhVien[trang - 1].dapan = "C";
				// Doi mau Cau C
				setcolor(1);
				circle(100, 570, 10);
				setfillstyle(1, 1);
				floodfill(106, 572, 1);

				// Doi cac Cau con lai ve binh thuong							
				setfillstyle(1, 15);
				floodfill(101, 372, 0);
				floodfill(101, 472, 0);
				floodfill(101, 672, 0);

			}
			// Nguoi dung chon D rectangle(70, 640, 130, 700);
			else if (xmouse >= 70 && xmouse <= 130 && ymouse >= 640 && ymouse <= 700) {
				dapAnSinhVien[trang - 1].dapan = "D";
				// Doi mau Cau D
				setcolor(1);
				circle(100, 670, 10);
				setfillstyle(1, 1);
				floodfill(106, 672, 1);

				// Doi cac Cau con lai ve binh thuong							
				setfillstyle(1, 15);
				floodfill(101, 372, 0);
				floodfill(101, 572, 0);
				floodfill(101, 472, 0);

			}
			// Nguoi dung chon NOP BAI 	rectangle(480, 770, 650, 820);
			else if (xmouse >= 480 && xmouse <= 650 && ymouse >= 770 && ymouse <= 820) {
				Thong_bao_xac_nhan_NOP_BAI();
				if (Lua_chon_CO_hoac_KHONG_cua_thong_bao_trong_ham_chuc_nang_thitracnghiem()) {
					stop = true;
					break;
				}
				else {
					// Khung thong bao
					setfillstyle(1, 15);
					bar(1115, 365, 1495, 745);
					continue;
				}
			}
		}
		delay(200);
	}

	clock.join();

	// Tinh Diem
	int socaudung = 0;
	float diem = 0;
	for (int i = 0; i < socauhoi; i++) {
		if (cauhoithi[i]->CH.dapan == dapAnSinhVien[i].dapan) {
			socaudung++;
		}
	}
	diem = (10.0 / (float)socauhoi) * (float)socaudung;
	diem = (round(diem * 100)) / 100;

	// Them Diem | Ma Mon Thi | Cau Tra Loi cua SINH VIEN
	ptrDiemThi DiemThiSinhVien = taoNodeDiemThi(mamonthi, diem);

	DiemThiSinhVien->info.n = socauhoi - 1;
	for (int i = 0; i < socauhoi; i++) {
		DiemThiSinhVien->info.CauTraLoi[i] = new CauHoiThi;
		DiemThiSinhVien->info.CauTraLoi[i]->id = dapAnSinhVien[i].id;
		DiemThiSinhVien->info.CauTraLoi[i]->mamh = dapAnSinhVien[i].mamh;
		DiemThiSinhVien->info.CauTraLoi[i]->noidung = dapAnSinhVien[i].noidung;
		DiemThiSinhVien->info.CauTraLoi[i]->A = dapAnSinhVien[i].A;
		DiemThiSinhVien->info.CauTraLoi[i]->B = dapAnSinhVien[i].B;
		DiemThiSinhVien->info.CauTraLoi[i]->C = dapAnSinhVien[i].C;
		DiemThiSinhVien->info.CauTraLoi[i]->D = dapAnSinhVien[i].D;
		DiemThiSinhVien->info.CauTraLoi[i]->dapan = dapAnSinhVien[i].dapan;

		DiemThiSinhVien->info.DapAn[i] = new CauHoiThi;
		DiemThiSinhVien->info.DapAn[i]->id = cauhoithi[i]->CH.id;
		DiemThiSinhVien->info.DapAn[i]->mamh = cauhoithi[i]->CH.mamh;
		DiemThiSinhVien->info.DapAn[i]->noidung = cauhoithi[i]->CH.noidung;
		DiemThiSinhVien->info.DapAn[i]->A = cauhoithi[i]->CH.A;
		DiemThiSinhVien->info.DapAn[i]->B = cauhoithi[i]->CH.B;
		DiemThiSinhVien->info.DapAn[i]->C = cauhoithi[i]->CH.C;
		DiemThiSinhVien->info.DapAn[i]->D = cauhoithi[i]->CH.D;
		DiemThiSinhVien->info.DapAn[i]->dapan = cauhoithi[i]->CH.dapan;
	}
	insertLastDiemThi(sinhvien_dangthi->info.ds_diemthi, DiemThiSinhVien);

	// Luu thong tin vao FILE
	ghiFileDsDiemThi(dslop);
	ghiFileDsDapAnSinhVien(dslop);

	// Hien ket qua thi
	HienThiKetQuaThi(diem, mamonthi, tenmonthi);
	while (true) {
		if (ismouseclick(WM_LBUTTONDOWN)) {
			getmouseclick(WM_LBUTTONDOWN, xmouse, ymouse);

			// Nguoi dung chon THOAT
			if (xmouse >= 800 && xmouse <= 1010 && ymouse >= 600 && ymouse <= 650) {
				break;
			}
			// Nguoi dung chon DAP AN
			else if (xmouse >= 550 && xmouse <= 760 && ymouse >= 600 && ymouse <= 650) {
				XemLaiDapAn(dslop, vitrilop, mamonthi, masinhvien, socauhoi);
				break;
			}
		}
		delay(200);
	}

	delete[] cauhoithi;
	delete[] dapAnSinhVien;
}
void ThiTracNghiem(DS_Lop& dslop, DS_MonHoc dsmon, ptrCauHoiThi root, bool& trangthai_trangDSMonHoc, string masinhvien) {
	int xmouse = -1;
	int ymouse = -1;

	string mamonthi = "";
	string tenmonthi = "";
	string socauhoi = "";
	string thoigian = "";
	string malop = "";
	int vitrimon = 0;
	int vitrilop = 0;
	int soluongcauhoihienco = 0;


	Thi_trac_nghiem_ChonMonHoc();

	while (true) {
		// Thong tin Sinh Vien
		setbkcolor(7);
		setcolor(1);
		settextstyle(10, 0, 3);
		outtextxy(50, 10, (char*)"THI SINH");

		setbkcolor(15);
		setcolor(1);
		settextstyle(10, 0, 3);
		outtextxy(50, 40, (char*)(masinhvien).c_str());

		malop = "";
		malop = malop.append(masinhvien, 0, masinhvien.length() - 3);
		int vitrilop = TimKiemMaLop(dslop, malop);

		ptrSinhVien sinhvien_dangtruycap = TimKiemMaSinhVien_TraVeNode(dslop, masinhvien, vitrilop);

		setbkcolor(15);
		setcolor(1);
		settextstyle(10, 0, 3);
		outtextxy(200, 10, (char*)(sinhvien_dangtruycap->info.ten).c_str());



		ChuyenTrang_DsMonHoc(dsmon, trangthai_trangDSMonHoc);

		if (ismouseclick(WM_LBUTTONDOWN)) {
			getmouseclick(WM_LBUTTONDOWN, xmouse, ymouse);

			// Nguoi dung chon nut => rectangle(700, 770, 870, 820);
			if (xmouse >= 700 && xmouse <= 870 && ymouse >= 770 && ymouse <= 820) {
				BangDanhSachMonHoc();
				trangthai_trangDSMonHoc = true;
			}
			// Nguoi dung chon nut <= rectangle(250, 770, 420, 820);
			else if (xmouse >= 250 && xmouse <= 420 && ymouse >= 770 && ymouse <= 820) {
				BangDanhSachMonHoc();
				trangthai_trangDSMonHoc = false;
			}
			// Nguoi dung chon nut THOAT
			else if (xmouse >= 1200 && xmouse <= 1370 && ymouse >= 770 && ymouse <= 820) {
				break;
			}
			// Nguoi dung nhap MA MON rectangle(350, 190, 500, 230);
			else if (xmouse >= 350 && xmouse <= 500 && ymouse >= 190 && ymouse <= 230) {
				mamonthi = "";
				mamonthi = vietText_ChuHoa_ChuThuong_So(380, 200, 6, 352, 192, 498, 228);
			}
			// Nguoi dung nhap SO CAU HOI rectangle(850, 140, 950, 180);
			else if (xmouse >= 850 && xmouse <= 950 && ymouse >= 140 && ymouse <= 180) {
				socauhoi = "";
				socauhoi = vietText_So(880, 150, 2, 852, 142, 948, 178);
			}
			// Nguoi dung nhap THOI GIAN rectangle(850, 190, 950, 230);
			else if (xmouse >= 850 && xmouse <= 950 && ymouse >= 190 && ymouse <= 230) {
				thoigian = "";
				thoigian = vietText_So(880, 200, 3, 852, 192, 948, 228);
			}
			// Nguoi dung chon XEM DIEM rectangle(590, 260, 760, 310);
			else if (xmouse >= 590 && xmouse <= 760 && ymouse >= 260 && ymouse <= 310) {
				XemDiemThi_SinhVien(dslop, dsmon, masinhvien, trangthai_trangDSMonHoc);

				Thi_trac_nghiem_ChonMonHoc();
				continue;
			}
			// Nguoi dung chon THI 	rectangle(470, 260, 640, 310);
			else if (xmouse >= 470 && xmouse <= 640 && ymouse >= 260 && ymouse <= 310) {
				// check nguoi dung nhap MA MON
				if (mamonthi.length() == 0) {
					Thong_bao_khong_duoc_de_trong_MAMON();
					continue;
				}
				// Chuan hoa MA MON
				VietHoaTatCaChu(mamonthi);

				// tim kiem MA MON co ton tai hay khong
				vitrimon = TimKiemMaMon(dsmon, mamonthi);

				if (vitrimon == -1) {
					Thong_bao_Ko_tim_thay_MA();
					continue;
				}

				tenmonthi = dsmon.DS[vitrimon]->tenmh;

				// Dem so cau hoi hien tai la bao nhieu
				soluongcauhoihienco = demNode_theoMaMon(root, mamonthi);

				// Ko co cau hoi trong danh sach
				if (soluongcauhoihienco == 0) {
					Thong_bao_Danh_sach_Cau_Hoi_Trong();
					continue;
				}

				// Check nguoi dung nhap SO CAU HOI
				if ((socauhoi.length() == 0) || (stoi(socauhoi) < 1) || (stoi(socauhoi) > 20) || (stoi(socauhoi) > soluongcauhoihienco)) {
					Thong_bao_Loi_SOCAUHOI();

					setbkcolor(15);
					setcolor(1);
					settextstyle(10, 0, 3);
					outtextxy(1315, 220, (char*)(to_string(soluongcauhoihienco)).c_str());

					Sleep(3000);
					setfillstyle(1, 15);
					bar(1110, 80, 1500, 350);
					setcolor(0);
					rectangle(1110, 80, 1500, 750);
					line(1110, 140, 1500, 140);

					setbkcolor(15);
					setcolor(4);
					settextstyle(10, 0, 3);
					outtextxy(1240, 100, (char*)"THONG BAO");

					continue;
				}

				// Check nguoi dung nhap THOI GIAN
				if ((thoigian.length() == 0) || (stoi(thoigian) < 1) || (stoi(thoigian) > 180)) {
					Thong_bao_Loi_THOIGIAN();
					continue;
				}

				// Mon Hoc da thi => Sinh Vien lua chon xem lai cau tra loi hoac thoat
				// Tim vi tri lop trong mang
				malop = "";
				malop = malop.append(masinhvien, 0, masinhvien.length() - 3);
				int vitrilop = TimKiemMaLop(dslop, malop);

				if (TimKiemDiemSinhVien(dslop, masinhvien, mamonthi, vitrilop) == true) {
					Thong_bao_Sinh_Vien_Da_Thi_Mon_Hoc();
					if (Lua_chon_CO_hoac_KHONG_cua_thong_bao_trong_ham_chuc_nang()) {
						ptrSinhVien sinhvien_dangtruycap = TimKiemMaSinhVien_TraVeNode(dslop, masinhvien, vitrilop);
						ptrDiemThi DiemThiSinhVien = TimKiemDiemSinhVien_TraVeNode(sinhvien_dangtruycap, mamonthi); // tra ve diem thi mon hoc can xem dap an
						
						XemLaiDapAn(dslop, vitrilop, mamonthi, masinhvien, (DiemThiSinhVien->info.n + 1));

						Thi_trac_nghiem_ChonMonHoc();
						continue;
					}
					else {
						// in l?i khung thông báo 
						setfillstyle(1, 15);
						bar(1110, 80, 1500, 370);
						setcolor(0);
						rectangle(1110, 80, 1500, 750);
						line(1110, 140, 1500, 140);

						setbkcolor(15);
						setcolor(4);
						settextstyle(10, 0, 3);
						outtextxy(1240, 100, (char*)"THONG BAO");
						continue;
					}
				}

				// tat ca cac cau hoi mon hoc da chon
				ptrCauHoiThi* cauhoihienco = new ptrCauHoiThi[soluongcauhoihienco];
				duyetLNR_Gan_DIA_CHI_theoMaMon(root, cauhoihienco, mamonthi);


				TienHanhThi(dslop, stoi(thoigian), stoi(socauhoi), vitrilop, cauhoihienco, masinhvien, mamonthi, tenmonthi);
				mamonthi = "";

				delete[] cauhoihienco;

				Thi_trac_nghiem_ChonMonHoc();
				continue;
			}
		}
		delay(200);
	}
}

//-----------------XEM DIEM THI--------------------------------------
void XemDiemThi(DS_Lop dslop, DS_MonHoc dsmon, bool& trangthai_trangDSMonHoc, int vitrilop, int& trangthai_trangDsSinhVien_XemDiem) {

	// Truy cap Mon Hoc de xem diem
	string mamonhoc = "";
	int vitrimonhoc = 0;

	string masv = "";
	string chuanhoa_masv = "";
	bool check = false; // Chuan hoa masv 1 lan

	int xmouse = -1;
	int ymouse = -1;
	Truy_cap_mon_hoc_Diem_thi();
	while (true) {
		Hien_thi_thong_tin_LOP_HOC_dang_duoc_truy_cap(dslop.DS[vitrilop]->malop, dslop.DS[vitrilop]->tenlop);
		ChuyenTrang_DsMonHoc(dsmon, trangthai_trangDSMonHoc);

		if (ismouseclick(WM_LBUTTONDOWN)) {
			getmouseclick(WM_LBUTTONDOWN, xmouse, ymouse);

			// Nguoi dung chon nut THOAT
			if (xmouse >= 1200 && xmouse <= 1370 && ymouse >= 770 && ymouse <= 820) {
				break;
			}
			// Nguoi dung chon nut => rectangle(700, 770, 870, 820);
			else if (xmouse >= 700 && xmouse <= 870 && ymouse >= 770 && ymouse <= 820) {
				BangDanhSachMonHoc();
				trangthai_trangDSMonHoc = true;
			}
			// Nguoi dung chon nut <= rectangle(250, 770, 420, 820);
			else if (xmouse >= 250 && xmouse <= 420 && ymouse >= 770 && ymouse <= 820) {
				BangDanhSachMonHoc();
				trangthai_trangDSMonHoc = false;
			}
			// Nguoi dung nhap MA MON rectangle(350, 120, 700, 160);
			else if (xmouse >= 350 && xmouse <= 700 && ymouse >= 120 && ymouse <= 160) {
				mamonhoc = "";
				mamonhoc = vietText_khung_MA_MON(360, 128, 15);
			}
			// Nguoi dung chon nut TRUY CAP rectangle(480, 260, 650, 310);
			else if (xmouse >= 480 && xmouse <= 650 && ymouse >= 260 && ymouse <= 310) {
				// Nguoi dung ko nhap MA MON
				if (mamonhoc.length() == 0) {
					Thong_bao_khong_duoc_de_trong_MAMON();
					continue;
				}

				// Kiem tra MA MON co ton tai?
				VietHoaTatCaChu(mamonhoc);
				vitrimonhoc = TimKiemMaMon(dsmon, mamonhoc);

				if (vitrimonhoc >= 0) {

					// Xem Diem
					Xem_Diem_thi();
					while (true) {
						ChuyenTrang_DsSinhVien_XemDiem(dslop, vitrilop, trangthai_trangDsSinhVien_XemDiem, mamonhoc);
						Hien_thi_thong_tin_LOP_HOC_dang_duoc_truy_cap(dslop.DS[vitrilop]->malop, dslop.DS[vitrilop]->tenlop);
						Hien_thi_thong_tin_MON_HOC_dang_duoc_truy_cap(dsmon.DS[vitrimonhoc]->mamh, dsmon.DS[vitrimonhoc]->tenmh);

						if (ismouseclick(WM_LBUTTONDOWN)) {
							getmouseclick(WM_LBUTTONDOWN, xmouse, ymouse);

							// Nguoi dung chon nut => rectangle(700, 770, 870, 820);
							if (xmouse >= 700 && xmouse <= 870 && ymouse >= 770 && ymouse <= 820) {
								BangDanhSachSinhVien_XemDiem();
								// chi hien thi 5 trang
								if (trangthai_trangDsSinhVien_XemDiem < 5) {
									trangthai_trangDsSinhVien_XemDiem++;
								}
							}
							// Nguoi dung chon nut <= rectangle(250, 770, 420, 820);
							else if (xmouse >= 250 && xmouse <= 420 && ymouse >= 770 && ymouse <= 820) {
								BangDanhSachSinhVien_XemDiem();
								if (trangthai_trangDsSinhVien_XemDiem > 1) {
									trangthai_trangDsSinhVien_XemDiem--;
								}
							}
							// Nguoi dung chon nut THOAT
							else if (xmouse >= 1200 && xmouse <= 1370 && ymouse >= 770 && ymouse <= 820) {							
								break;
							}
							// Nguoi dung nhap MA SINH VIEN
							else if (xmouse >= 400 && xmouse <= 800 && ymouse >= 150 && ymouse <= 190) {
								check = true;
								chuanhoa_masv = "";
								chuanhoa_masv = dslop.DS[vitrilop]->malop;
								masv = "";
								masv = vietText_khung_MA_SINH_VIEN_chuc_nang_xoa(410, 158, 15);
							}
							// Nguoi dung chon XEM BAI LAM 	rectangle(450, 260, 680, 310);
							else if (xmouse >= 450 && xmouse <= 680 && ymouse >= 260 && ymouse <= 310) {
								// Kiem tra nguoi dung khong nhap MA SINH VIEN
								if (masv.length() == 0) {
									Thong_bao_Vui_long_nhap_MA_SINH_VIEN();
									continue;
								}
								// chuanhoa 1 lan
								if (check == true) {
									// Chuan hoa MA SINH VIEN nhap vao
									VietHoaTatCaChu(masv);
									chuanhoa_masv.append(masv);
									check = false;
								}
								
								// tim va tra ve Sinh Vien dang duoc XEM BAI LAM
								int pos = TimKiemMaSinhVien_chuc_nang_xoa(dslop, chuanhoa_masv, vitrilop);
								int cnt = 1;								

								if (pos != 0) {

									ptrSinhVien p = dslop.DS[vitrilop]->ds_sinhvien;
									while (p != NULL) {
										if (pos == cnt) {
											break;
										}
										cnt++;
										p = p->next;
									}
									
									// Truong hop sinh vien CHUA THI
									if (p->info.ds_diemthi == NULL) {
										Thong_bao_Sinh_Vien_Chua_Thi_Mon_Hoc();
										continue;
									}
									else {
										ptrDiemThi DiemThiSinhVien = p->info.ds_diemthi;
										XemLaiDapAn(dslop, vitrilop, mamonhoc, chuanhoa_masv, (DiemThiSinhVien->info.n + 1));

										Xem_Diem_thi();

										// Xoa ma sinh vien
										chuanhoa_masv = "";
										masv = "";
										continue;
									}
								}
								else {
									Thong_bao_Ko_tim_thay_MA();
									continue;
								}
							}
						}
						delay(200);
					}

				}
				else {
					Thong_bao_Ko_tim_thay_MA();
					continue;
				}
				Truy_cap_mon_hoc_Diem_thi();
				BangDanhSachMonHoc();
				break;
			}
		}
		delay(200);
	}
}



int main() {
	DS_MonHoc dsmon;
	MonHoc mon;

	DS_Lop dslop;
	Lop lop;
	ptrCauHoiThi dscauhoithi = NULL;	

	initwindow(1900, 1070, (char*)"THI TRAC NGHIEM", -15, 0);
	// Tai khoan cua giao vien
	string TaikhoanGiaovien = "giaovien";
	string MatkhauGiaovien = "giaovien";

	// dung de kiem tra xem nguoi dung nhap dung tai khoan va mat khau hay khong
	int checkTaikhoan = false;
	int checkMatkhau = false;
	// Dung cho ham chuyen trang
	bool trangthai_trangDsLop = false;
	bool trangthai_trangDsSinhVien = false;
	bool trangthai_trangDSMonHoc = false;
	int trangthai_trangDSCauHoi = 1;
	int trangthai_trangDsSinhVien_XemDiem = 1;
	// Cac bien nhap du lieu
	string nhapTaikhoan;
	string nhapMatkhau;
	string masinhvien = "";
	string malopsinhvien = "";

	// Tiến hành đọc file 
	docFileDsLop(dslop);
	docFileDsSinhVien(dslop);
	docFileDsMonHoc(dsmon);
	docFileDsCauHoi(dscauhoithi);
	docFileDsDiemThi(dslop);
	docFileDsDapAnSinhVien(dslop);

	srand(time(0)); // RanDom ID Cau hoi

	int xmouse = -1;
	int ymouse = -1;


	Man_hinh_dang_nhap();
	while (true) {
		if (ismouseclick(WM_LBUTTONDOWN)) {
			getmouseclick(WM_LBUTTONDOWN, xmouse, ymouse);

			// Nguoi dung nhap TAI KHOAN
			if (xmouse >= 700 && xmouse <= 1060 && ymouse >= 380 && ymouse <= 420) {
				checkTaikhoan = 0;
				nhapTaikhoan = "";
				nhapTaikhoan = vietText_khung_TAI_KHOAN(710, 388, 20);			
			}
			// Nguoi dung nhap MAT KHAU
			else if (xmouse >= 700 && xmouse <= 1060 && ymouse >= 450 && ymouse <= 490) {
				checkMatkhau = 0;
				nhapMatkhau = "";
				nhapMatkhau = vietText_khung_MAT_KHAU(710, 458, 20);								
			}
			// Nguoi dung chon ENTER
			else if (xmouse >= 550 && xmouse <= 760 && ymouse >= 600 && ymouse <= 650) {		

				// Kiem tra tai khoan 
				if (Kiem_tra_tai_khoan(nhapTaikhoan, TaikhoanGiaovien) == true && Kiem_tra_tai_khoan(nhapMatkhau, MatkhauGiaovien) == true) {
					checkTaikhoan = 1;				
					checkMatkhau = 1;
				}
				else if (Kiem_tra_tai_khoan_SINH_VIEN(dslop, nhapTaikhoan, nhapMatkhau)) {
					checkMatkhau = 2;
					checkTaikhoan = 2;
				}

				// Kiem tra tai khoan GIAO VIEN				
				if (checkTaikhoan == 1 && checkMatkhau == 1) {
					checkTaikhoan = 0;
					checkMatkhau = 0;

					nhapMatkhau = "";
					nhapTaikhoan = "";
					Thong_bao_dang_nhap_thanh_cong();
				
					Menu_cua_giao_vien();
					while (true) {
						//=============================== XU LY PHIM BAM CHUOT ========================
						if (ismouseclick(WM_LBUTTONDOWN)) {
							getmouseclick(WM_LBUTTONDOWN, xmouse, ymouse);
					
							
							// Nguoi dung chon nut LOP 
							if (xmouse >= 600 && xmouse <= 940 && ymouse >= 300 && ymouse <= 350) {
								Quan_ly_lop();
								while (true) {
									// Chuyen trang va hien danh sach lop
									ChuyenTrang_DsLop(dslop, trangthai_trangDsLop);

									if (ismouseclick(WM_LBUTTONDOWN)) {
										getmouseclick(WM_LBUTTONDOWN, xmouse, ymouse);

										// Nguoi dung chon nut => rectangle(700, 770, 870, 820);
										if (xmouse >= 700 && xmouse <= 870 && ymouse >= 770 && ymouse <= 820) {
											BangDanhsachLop();
											trangthai_trangDsLop = true;

										}
										// Nguoi dung chon nut <= rectangle(250, 770, 420, 820);
										else if (xmouse >= 250 && xmouse <= 420 && ymouse >= 770 && ymouse <= 820) {
											BangDanhsachLop();
											trangthai_trangDsLop = false;
										}
										// Nguoi dung chon nut THOAT	
										else if (xmouse >= 1200 && xmouse <= 1370 && ymouse >= 770 && ymouse <= 820) {
											Thong_bao_chon_lua_vao_file();
											if (Lua_chon_CO_hoac_KHONG_cua_thong_bao_trong_ham_chuc_nang()) {
												ghiFileDsLop(dslop);
												break;
											}
											else {
												break;
											}
										}
										// Nguoi dung chon nut THEM rectangle(100, 260, 270, 310);
										else if (xmouse >= 100 && xmouse <= 270 && ymouse >= 260 && ymouse <= 310) {
											// khu vuc DIEN THONG TIN
											ThemLopHoc(dslop);
											Quan_ly_lop();
											continue;
										}
										// Nguoi dung chon nut SUA rectangle(320, 260, 490, 310);
										else if (xmouse >= 320 && xmouse <= 490 && ymouse >= 260 && ymouse <= 310) {
											// Khung chuc nang
											setfillstyle(1, 15);
											bar(50, 80, 1080, 320);

											setcolor(0);
											rectangle(50, 80, 1080, 320);

											Nhap_NAM_HOC_de_in_graphic();											
											while (true) {
												// Chuyen trang
												ChuyenTrang_DsLop(dslop, trangthai_trangDsLop);

												if (ismouseclick(WM_LBUTTONDOWN)) {
													getmouseclick(WM_LBUTTONDOWN, xmouse, ymouse);

													// hien lai o nhap NAM HOC
													setfillstyle(1, 11);
													bar(780, 120, 950, 160);
													setcolor(0);
													rectangle(780, 120, 950, 160);

													setbkcolor(15);
													setcolor(0);
													settextstyle(10, 0, 2);
													outtextxy(670, 130, (char*)"NAM HOC");

													// hien lai danh sach lop
													hienDsLop_graphic(dslop);

													//Nguoi dung chon nhap du lieu NAM HOC
													if (xmouse >= 50 && xmouse <= 1080 && ymouse >= 80 && ymouse <= 220) {

														if (!In_DsLop_theo_NAM_HOC_chuc_nang_XOA(dslop)) {
															continue;
														}
														/////////////////////////
														setfillstyle(1, 11);
														bar(250, 120, 600, 160);
														setcolor(0);
														rectangle(250, 120, 600, 160);
														setbkcolor(15);
														setcolor(0);
														settextstyle(10, 0, 2);
														outtextxy(130, 130, (char*)"MA LOP");

														while (true) {
															if (ismouseclick(WM_LBUTTONDOWN)) {
																getmouseclick(WM_LBUTTONDOWN, xmouse, ymouse);

																//Nguoi dung chon nhap MA LOP rectangle(250, 120, 600, 160);
																if (xmouse >= 50 && xmouse <= 1080 && ymouse >= 80 && ymouse <= 220) {
																	SuaLopHoc(dslop);

																	setfillstyle(1, 15);
																	bar(1110, 80, 1500, 750);
																	setcolor(0);
																	rectangle(1110, 80, 1500, 750);
																	line(1110, 140, 1500, 140);

																	setbkcolor(15);
																	setcolor(4);
																	settextstyle(10, 0, 3);
																	outtextxy(1240, 100, (char*)"THONG BAO");
																	break;
																}
																// Nguoi dung chon nut THOAT
																else if (xmouse >= 1200 && xmouse <= 1370 && ymouse >= 770 && ymouse <= 820) {
																	Thong_bao_chon_thoat_chuc_nang_SUA();
																	if (Lua_chon_CO_hoac_KHONG_cua_thong_bao_trong_ham_chuc_nang()) {

																		break;
																	}
																	else {
																		// khung thong bao
																		setfillstyle(1, 15);
																		bar(1110, 80, 1500, 750);
																		setcolor(0);
																		rectangle(1110, 80, 1500, 750);
																		line(1110, 140, 1500, 140);

																		setbkcolor(15);
																		setcolor(4);
																		settextstyle(10, 0, 3);
																		outtextxy(1240, 100, (char*)"THONG BAO");
																	}
																}
															}

															delay(200);
														}
														
														hienDsLop_graphic(dslop);
														break;
													}
													//Nguoi dung chon nut THOAT
													else if (xmouse >= 1200 && xmouse <= 1370 && ymouse >= 770 && ymouse <= 820) {
														Thong_bao_chon_thoat_chuc_nang_SUA();
														if (Lua_chon_CO_hoac_KHONG_cua_thong_bao_trong_ham_chuc_nang()) {
															break;
														}
														else {
															// khung thong bao
															setfillstyle(1, 15);
															bar(1110, 80, 1500, 750);
															setcolor(0);
															rectangle(1110, 80, 1500, 750);
															line(1110, 140, 1500, 140);

															setbkcolor(15);
															setcolor(4);
															settextstyle(10, 0, 3);
															outtextxy(1240, 100, (char*)"THONG BAO");
														}
													}
													// Nguoi dung chon nut => rectangle(700, 770, 870, 820);
													else if (xmouse >= 700 && xmouse <= 870 && ymouse >= 770 && ymouse <= 820) {
														BangDanhsachLop(); // xoa du lieu cu
														trangthai_trangDsLop = true;

													}
													// Nguoi dung chon nut <= rectangle(250, 770, 420, 820);
													else if (xmouse >= 250 && xmouse <= 420 && ymouse >= 770 && ymouse <= 820) {
														BangDanhsachLop(); // xoa du lieu cu
														trangthai_trangDsLop = false;
													}
												}

												delay(200);
											}																			
											Quan_ly_lop();
											continue;
										}
										// Nguoi dung chon nut XOA rectangle(690, 260, 710, 310);
										else if (xmouse >= 540 && xmouse <= 710 && ymouse >= 260 && ymouse <= 310) {
											// Khung chuc nang
											setfillstyle(1, 15);
											bar(50, 80, 1080, 320);
											setcolor(0);
											rectangle(50, 80, 1080, 320);

											Nhap_NAM_HOC_de_in_graphic();										
											while (true) {
												// Chuyen trang
												ChuyenTrang_DsLop(dslop, trangthai_trangDsLop);

												if (ismouseclick(WM_LBUTTONDOWN)) {
													getmouseclick(WM_LBUTTONDOWN, xmouse, ymouse);

													// hien lai o nhap NAM HOC
													setfillstyle(1, 11);
													bar(780, 120, 950, 160);
													setcolor(0);
													rectangle(780, 120, 950, 160);

													setbkcolor(15);
													setcolor(0);
													settextstyle(10, 0, 2);
													outtextxy(670, 130, (char*)"NAM HOC");													

													// hien lai danh sach lop
													hienDsLop_graphic(dslop);

													//Nguoi dung chon nhap du lieu NAM HOC
													if (xmouse >= 50 && xmouse <= 1080 && ymouse >= 80 && ymouse <= 220) {

														// Neu nguoi dung nhap ko dung dinh dang NAM HOC thi se ko cho qua
														if (!In_DsLop_theo_NAM_HOC_chuc_nang_XOA(dslop)) {
															continue;
														}

														setfillstyle(1, 11);
														bar(250, 120, 600, 160);
														setcolor(0);
														rectangle(250, 120, 600, 160);
														setbkcolor(15);
														setcolor(0);
														settextstyle(10, 0, 2);
														outtextxy(130, 130, (char*)"MA LOP");

														while (true) {
															if (ismouseclick(WM_LBUTTONDOWN)) {
																getmouseclick(WM_LBUTTONDOWN, xmouse, ymouse);

																// Nguoi dung chon nhap MA LOP rectangle(250, 120, 600, 160);
																if (xmouse >= 50 && xmouse <= 1080 && ymouse >= 80 && ymouse <= 220) {
																	XoaLop(dslop);

																	setfillstyle(1, 15);
																	bar(1110, 80, 1500, 750);
																	setcolor(0);
																	rectangle(1110, 80, 1500, 750);
																	line(1110, 140, 1500, 140);

																	setbkcolor(15);
																	setcolor(4);
																	settextstyle(10, 0, 3);
																	outtextxy(1240, 100, (char*)"THONG BAO");
																	break;
																}
																// Nguoi dung chon nut THOAT
																else if (xmouse >= 1200 && xmouse <= 1370 && ymouse >= 770 && ymouse <= 820) {
																	Thong_bao_chon_thoat_chuc_nang_XOA();
																	if (Lua_chon_CO_hoac_KHONG_cua_thong_bao_trong_ham_chuc_nang()) {																		
																		break;
																	}
																	else {
																		// khung thong bao
																		setfillstyle(1, 15);
																		bar(1110, 80, 1500, 750);
																		setcolor(0);
																		rectangle(1110, 80, 1500, 750);
																		line(1110, 140, 1500, 140);

																		setbkcolor(15);
																		setcolor(4);
																		settextstyle(10, 0, 3);
																		outtextxy(1240, 100, (char*)"THONG BAO");
																	}
																}
															}
															delay(200);
														}
														hienDsLop_graphic(dslop);
														break;
													}
													//Nguoi dung chon nut THOAT
													else if (xmouse >= 1200 && xmouse <= 1370 && ymouse >= 770 && ymouse <= 820) {
														Thong_bao_chon_thoat_chuc_nang_XOA();
														if (Lua_chon_CO_hoac_KHONG_cua_thong_bao_trong_ham_chuc_nang()) {
															break;
														}
														else {
															// khung thong bao
															setfillstyle(1, 15);
															bar(1110, 80, 1500, 750);
															setcolor(0);
															rectangle(1110, 80, 1500, 750);
															line(1110, 140, 1500, 140);

															setbkcolor(15);
															setcolor(4);
															settextstyle(10, 0, 3);
															outtextxy(1240, 100, (char*)"THONG BAO");
														}
													}
													// Nguoi dung chon nut => rectangle(700, 770, 870, 820);
													else if (xmouse >= 700 && xmouse <= 870 && ymouse >= 770 && ymouse <= 820) {
														BangDanhsachLop(); // xoa du lieu cu
														trangthai_trangDsLop = true;

													}
													// Nguoi dung chon nut <= rectangle(250, 770, 420, 820);
													else if (xmouse >= 250 && xmouse <= 420 && ymouse >= 770 && ymouse <= 820) {
														BangDanhsachLop(); // xoa du lieu cu
														trangthai_trangDsLop = false;
													}
												}

												delay(200);
											}											
											Quan_ly_lop();
											continue;
										}
										// Nguoi dung chon nut XEM THEO NAM rectangle(760, 260, 1030, 310);
										else if (xmouse >= 760 && xmouse <= 1030 && ymouse >= 260 && ymouse <= 310) {
											// Khung chuc nang
											setfillstyle(1, 15);
											bar(50, 80, 1080, 320);

											setcolor(0);
											rectangle(50, 80, 1080, 320);

											Nhap_NAM_HOC_de_in_graphic();
											while (true) {
												
												if (ismouseclick(WM_LBUTTONDOWN)) {
													getmouseclick(WM_LBUTTONDOWN, xmouse, ymouse);

													// hien lai o nhap NAM HOC
													setfillstyle(1, 11);
													bar(780, 120, 950, 160);
													setcolor(0);
													rectangle(780, 120, 950, 160);

													setbkcolor(15);
													setcolor(0);
													settextstyle(10, 0, 2);
													outtextxy(670, 130, (char*)"NAM HOC");

													// Xoa du lieu cu tren man hinh
													BangDanhsachLop();

													// hien lai danh sach lop
													hienDsLop_graphic(dslop);

													//Nguoi dung chon nhap du lieu NAM HOC
													if (xmouse >= 50 && xmouse <= 1080 && ymouse >= 80 && ymouse <= 220) {
														In_DsLop_theo_NAM_HOC(dslop);
													}
													//Nguoi dung chon nut THOAT
													else if (xmouse >= 1200 && xmouse <= 1370 && ymouse >= 770 && ymouse <= 820) {
														Thong_bao_chon_thoat_chuc_nang_XEM_THEO_NAM();
														if (Lua_chon_CO_hoac_KHONG_cua_thong_bao_trong_ham_chuc_nang()) {
															break;
														}
														else {
															// khung thong bao
															setfillstyle(1, 15);
															bar(1110, 80, 1500, 750);
															setcolor(0);
															rectangle(1110, 80, 1500, 750);
															line(1110, 140, 1500, 140);

															setbkcolor(15);
															setcolor(4);
															settextstyle(10, 0, 3);
															outtextxy(1240, 100, (char*)"THONG BAO");
														}
													}												
												}									
												delay(200);
											}

											Quan_ly_lop();

											continue;
										}
									}
									delay(200);
								}
								Menu_cua_giao_vien();	
								continue;
							}
							// Nguoi dung chon nut SINH VIEN
							else if (xmouse >= 600 && xmouse <= 940 && ymouse >= 380 && ymouse <= 430) {
								Quan_ly_sinh_vien_Hien_thi_danh_sach_lop();
								while (true) {

									// Chuyen trang va hien danh sach lop
									ChuyenTrang_DsLop(dslop, trangthai_trangDsLop);

									if (ismouseclick(WM_LBUTTONDOWN)) {
										getmouseclick(WM_LBUTTONDOWN, xmouse, ymouse);

										// Nguoi dung chon nut => rectangle(700, 770, 870, 820);
										if (xmouse >= 700 && xmouse <= 870 && ymouse >= 770 && ymouse <= 820) {
											BangDanhsachLop();
											trangthai_trangDsLop = true;
										}
										// Nguoi dung chon nut <= rectangle(250, 770, 420, 820);
										else if (xmouse >= 250 && xmouse <= 420 && ymouse >= 770 && ymouse <= 820) {
											BangDanhsachLop();
											trangthai_trangDsLop = false;
										}
										// Nguoi dung chon nut THOAT
										else if (xmouse >= 1200 && xmouse <= 1370 && ymouse >= 770 && ymouse <= 820) {
											break;
										}
										// Nguoi dung chon nut TRUY CAP rectangle(480, 260, 650, 310);
										else if (xmouse >= 480 && xmouse <= 650 && ymouse >= 260 && ymouse <= 310) {
											Nhap_NAM_HOC_de_in_graphic();
											while (true) {

												// Chuyen trang
												ChuyenTrang_DsLop(dslop, trangthai_trangDsLop);

												if (ismouseclick(WM_LBUTTONDOWN)) {
													getmouseclick(WM_LBUTTONDOWN, xmouse, ymouse);

													// hien lai o nhap NAM HOC
													setfillstyle(1, 11);
													bar(780, 120, 950, 160);
													setcolor(0);
													rectangle(780, 120, 950, 160);

													setbkcolor(15);
													setcolor(0);
													settextstyle(10, 0, 2);
													outtextxy(670, 130, (char*)"NAM HOC");

													// hien lai danh sach lop
													hienDsLop_graphic(dslop);

													//Nguoi dung chon nhap du lieu NAM HOC
													if (xmouse >= 50 && xmouse <= 1080 && ymouse >= 80 && ymouse <= 220) {

														if (!In_DsLop_theo_NAM_HOC_chuc_nang_XOA(dslop)) {
															continue;
														}

														setfillstyle(1, 11);
														bar(250, 120, 600, 160);
														setcolor(0);
														rectangle(250, 120, 600, 160);
														setbkcolor(15);
														setcolor(0);
														settextstyle(10, 0, 2);
														outtextxy(130, 130, (char*)"MA LOP");

														while (true) {
															if (ismouseclick(WM_LBUTTONDOWN)) {
																getmouseclick(WM_LBUTTONDOWN, xmouse, ymouse);

																//Nguoi dung chon nhap MA LOP rectangle(250, 120, 600, 160);
																if (xmouse >= 50 && xmouse <= 1080 && ymouse >= 80 && ymouse <= 220) {
																	int vitrilop = TimKiemMaLop_SINHVIEN(dslop);

																	if (vitrilop >= 0) {
																		Hien_thi_thong_tin_LOP_HOC_dang_duoc_truy_cap(dslop.DS[vitrilop]->malop, dslop.DS[vitrilop]->tenlop);
																		Hien_thi_chuc_nang_sinh_vien();

																		while (true) {																	
																			// hien thi danh sach sinh vien lop hoc																							
																			ChuyenTrang_DsSinhVien(dslop, trangthai_trangDsSinhVien, vitrilop);

																			if (ismouseclick(WM_LBUTTONDOWN)) {
																				getmouseclick(WM_LBUTTONDOWN, xmouse, ymouse);

																				// Nguoi dung chon nut THOAT
																				if (xmouse >= 1200 && xmouse <= 1370 && ymouse >= 770 && ymouse <= 820) {
																					Thong_bao_chon_lua_vao_file();
																					if (Lua_chon_CO_hoac_KHONG_cua_thong_bao_trong_ham_chuc_nang()) {
																						ghiFileDsSinhVien(dslop);
																						// Xoa du lieu cu tren man hinh
																						BangDanhSachSinhVien();
																						break;
																					}
																					else {
																						// khung thong bao
																						setfillstyle(1, 15);
																						bar(1110, 80, 1500, 370);
																						setcolor(0);
																						rectangle(1110, 80, 1500, 750);
																						line(1110, 140, 1500, 140);

																						setbkcolor(15);
																						setcolor(4);
																						settextstyle(10, 0, 3);
																						outtextxy(1240, 100, (char*)"THONG BAO");

																						// Xoa du lieu cu tren man hinh
																						BangDanhSachSinhVien();
																						break;
																					}
																				}
																				// Nguoi dung chon nut THEM rectangle(250, 310, 420, 260);
																				else if (xmouse >= 250 && xmouse <= 420 && ymouse >= 260 && ymouse <= 310) {
																					NhapThongTinSinhVien(dslop, vitrilop);
																					Hien_thi_chuc_nang_sinh_vien();

																					// khung thong bao
																					setfillstyle(1, 15);
																					bar(1110, 80, 1500, 370);
																					setcolor(0);
																					rectangle(1110, 80, 1500, 750);
																					line(1110, 140, 1500, 140);

																					setbkcolor(15);
																					setcolor(4);
																					settextstyle(10, 0, 3);
																					outtextxy(1240, 100, (char*)"THONG BAO");
																					continue;
																				}
																				// Nguoi dung chon nut XOA rectangle(690, 310, 860, 260);
																				else if (xmouse >= 690 && xmouse <= 860 && ymouse >= 260 && ymouse <= 310) {
																					Khu_vuc_Xoa_thong_tin_sinh_vien();
																					XoaThongTinSinhVien(dslop, vitrilop);

																					Hien_thi_chuc_nang_sinh_vien();
																					continue;
																				}
																				// Nguoi dung chon nut SUA rectangle(470, 310, 640, 260);
																				else if (xmouse >= 470 && xmouse <= 640 && ymouse >= 260 && ymouse <= 310) {
																					Khu_vuc_nhap_ma_de_Sua_thong_tin_sinh_vien();
																					SuaThongTinSinhVien(dslop, vitrilop);

																					Hien_thi_chuc_nang_sinh_vien();
																					continue;
																				}
																				// Nguoi dung chon nut => rectangle(700, 770, 870, 820);
																				else if (xmouse >= 700 && xmouse <= 870 && ymouse >= 770 && ymouse <= 820) {
																					BangDanhSachSinhVien();
																					trangthai_trangDsSinhVien = true;

																				}
																				// Nguoi dung chon nut <= rectangle(250, 770, 420, 820);
																				else if (xmouse >= 250 && xmouse <= 420 && ymouse >= 770 && ymouse <= 820) {
																					BangDanhSachSinhVien();
																					trangthai_trangDsSinhVien = false;
																				}
																			}
																			delay(200);
																		}

																	}
																	else {
																		continue;
																	}
																	setfillstyle(1, 15);
																	bar(1110, 80, 1500, 750);
																	setcolor(0);
																	rectangle(1110, 80, 1500, 750);
																	line(1110, 140, 1500, 140);

																	setbkcolor(15);
																	setcolor(4);
																	settextstyle(10, 0, 3);
																	outtextxy(1240, 100, (char*)"THONG BAO");
																	break;
																}
																// Nguoi dung chon nut THOAT
																else if (xmouse >= 1200 && xmouse <= 1370 && ymouse >= 770 && ymouse <= 820) {
																	Thong_bao_chon_thoat_chuc_nang_TRUY_CAP();
																	if (Lua_chon_CO_hoac_KHONG_cua_thong_bao_trong_ham_chuc_nang()) {

																		break;
																	}
																	else {
																		// khung thong bao
																		setfillstyle(1, 15);
																		bar(1110, 80, 1500, 750);
																		setcolor(0);
																		rectangle(1110, 80, 1500, 750);
																		line(1110, 140, 1500, 140);

																		setbkcolor(15);
																		setcolor(4);
																		settextstyle(10, 0, 3);
																		outtextxy(1240, 100, (char*)"THONG BAO");
																	}
																}
															}

															delay(200);
														}
														hienDsLop_graphic(dslop);
														break;
													}
													//Nguoi dung chon nut THOAT
													else if (xmouse >= 1200 && xmouse <= 1370 && ymouse >= 770 && ymouse <= 820) {
														Thong_bao_chon_thoat_chuc_nang_TRUY_CAP();
														if (Lua_chon_CO_hoac_KHONG_cua_thong_bao_trong_ham_chuc_nang()) {
															ghiFileDsSinhVien(dslop);
															break;
														}
														else {
															// khung thong bao
															setfillstyle(1, 15);
															bar(1110, 80, 1500, 750);
															setcolor(0);
															rectangle(1110, 80, 1500, 750);
															line(1110, 140, 1500, 140);

															setbkcolor(15);
															setcolor(4);
															settextstyle(10, 0, 3);
															outtextxy(1240, 100, (char*)"THONG BAO");
														}
													}
													// Nguoi dung chon nut => rectangle(700, 770, 870, 820);
													else if (xmouse >= 700 && xmouse <= 870 && ymouse >= 770 && ymouse <= 820) {
														BangDanhsachLop(); // xoa du lieu cu
														trangthai_trangDsLop = true;

													}
													// Nguoi dung chon nut <= rectangle(250, 770, 420, 820);
													else if (xmouse >= 250 && xmouse <= 420 && ymouse >= 770 && ymouse <= 820) {
														BangDanhsachLop(); // xoa du lieu cu
														trangthai_trangDsLop = false;
													}
												}

												delay(200);
											}

											Quan_ly_sinh_vien_Hien_thi_danh_sach_lop();
											continue;
										}
									}
									delay(200);
								}
								Menu_cua_giao_vien();
								continue;
							}
							// Nguoi dung chon nut MON HOC
							else if (xmouse >= 600 && xmouse <= 940 && ymouse >= 460 && ymouse <= 510) {
								Quan_ly_mon_hoc();
								while (true) {
									ChuyenTrang_DsMonHoc(dsmon, trangthai_trangDSMonHoc);

									if (ismouseclick(WM_LBUTTONDOWN)) {
										getmouseclick(WM_LBUTTONDOWN, xmouse, ymouse);

										// Nguoi dung chon nut => rectangle(700, 770, 870, 820);
										if (xmouse >= 700 && xmouse <= 870 && ymouse >= 770 && ymouse <= 820) {
											BangDanhSachMonHoc();
											trangthai_trangDSMonHoc = true;
										}
										// Nguoi dung chon nut <= rectangle(250, 770, 420, 820);
										else if (xmouse >= 250 && xmouse <= 420 && ymouse >= 770 && ymouse <= 820) {
											BangDanhSachMonHoc();
											trangthai_trangDSMonHoc = false;
										}
										// Nguoi dung chon nut THOAT
										else if (xmouse >= 1200 && xmouse <= 1370 && ymouse >= 770 && ymouse <= 820) {
											Thong_bao_chon_lua_vao_file();
											if (Lua_chon_CO_hoac_KHONG_cua_thong_bao_trong_ham_chuc_nang()) {
												ghiFileDsMonHoc(dsmon);
												break;
											}
											else {
												// khung thong bao
												setfillstyle(1, 15);
												bar(1110, 80, 1500, 370);
												setcolor(0);
												rectangle(1110, 80, 1500, 750);
												line(1110, 140, 1500, 140);

												setbkcolor(15);
												setcolor(4);
												settextstyle(10, 0, 3);
												outtextxy(1240, 100, (char*)"THONG BAO");
												break;
											}

										}
										// Nguoi dung chon nut THEM
										else if (xmouse >= 250 && xmouse <= 420 && ymouse >= 260 && ymouse <= 310) {
											ThemMonHoc(dsmon);
											Quan_ly_mon_hoc();
											continue;
										}
										// Nguoi dung chon nut SUA rectangle(470, 310, 640, 260);
										else if (xmouse >= 470 && xmouse <= 640 && ymouse >= 260 && ymouse <= 310) {
											SuaMonHoc(dsmon, dscauhoithi);
											Quan_ly_mon_hoc();
											continue;
										}
										// Nguoi dung chon nut XOA rectangle(690, 310, 860, 260);
										else if (xmouse >= 690 && xmouse <= 860 && ymouse >= 260 && ymouse <= 310) {
											XoaMonHoc(dsmon, dscauhoithi);
											Quan_ly_mon_hoc();
											continue;
										}
									}

									delay(200);
								}
								Menu_cua_giao_vien();
								continue;
							}
							// Nguoi dung chon nut CAU HOI
							else if (xmouse >= 600 && xmouse <= 940 && ymouse >= 540 && ymouse <= 590) {
								Quan_ly_cau_hoi();
								while (true) {
									ChuyenTrang_DsCauHoi(dscauhoithi, trangthai_trangDSCauHoi);
									//hienDsCauHoi_graphic(dscauhoithi);

									if (ismouseclick(WM_LBUTTONDOWN)) {
										getmouseclick(WM_LBUTTONDOWN, xmouse, ymouse);

										// Nguoi dung chon nut => rectangle(700, 770, 870, 820);
										if (xmouse >= 700 && xmouse <= 870 && ymouse >= 770 && ymouse <= 820) {
											BangDanhSachCauHoi();
											// chi hien thi 5 trang
											if (trangthai_trangDSCauHoi < 5) {
												trangthai_trangDSCauHoi++;
											}
										}
										// Nguoi dung chon nut <= rectangle(250, 770, 420, 820);
										else if (xmouse >= 250 && xmouse <= 420 && ymouse >= 770 && ymouse <= 820) {
											BangDanhSachCauHoi();
											if (trangthai_trangDSCauHoi > 1) {
												trangthai_trangDSCauHoi--;
											}
										}
										// Nguoi dung chon nut THOAT
										else if (xmouse >= 1200 && xmouse <= 1370 && ymouse >= 770 && ymouse <= 820) {
											Thong_bao_chon_lua_vao_file();
											if (Lua_chon_CO_hoac_KHONG_cua_thong_bao_trong_ham_chuc_nang()) {
												ghiFileDsCauHoi(dscauhoithi);
												break;
											}
											else {
												break;
											}
										}
										// Nguoi dung chon nut THEM rectangle(250, 310, 420, 260);
										else if (xmouse >= 250 && xmouse <= 420 && ymouse >= 260 && ymouse <= 310) {
											ThemCauHoi(dsmon, dscauhoithi, trangthai_trangDSMonHoc);

											Quan_ly_cau_hoi();
											continue;
										}
										// Nguoi dung chon nut XOA rectangle(690, 310, 860, 260);
										else if (xmouse >= 690 && xmouse <= 860 && ymouse >= 260 && ymouse <= 310) {
											XoaCauHoi(dsmon, dscauhoithi, trangthai_trangDSCauHoi);

											Quan_ly_cau_hoi();
											continue;
										}
										// Nguoi dung chon nut SUA 	rectangle(470, 310, 640, 260);
										else if (xmouse >= 470 && xmouse <= 640 && ymouse >= 260 && ymouse <= 310) {
											SuaCauHoi(dsmon, dscauhoithi, trangthai_trangDSCauHoi);

											Quan_ly_cau_hoi();
											continue;
										}
									}
									delay(200);
								}
								Menu_cua_giao_vien();
								continue;
							}
							// Nguoi dung chon nut XEM DIEM
							else if (xmouse >= 600 && xmouse <= 940 && ymouse >= 620 && ymouse <= 670) {
								Quan_ly_Diem_thi_Hien_thi_danh_sach_lop();
								while (true) {
									// Chuyen trang va hien danh sach lop
									ChuyenTrang_DsLop(dslop, trangthai_trangDsLop);

									if (ismouseclick(WM_LBUTTONDOWN)) {
										getmouseclick(WM_LBUTTONDOWN, xmouse, ymouse);

										// Nguoi dung chon nut => rectangle(700, 770, 870, 820);
										if (xmouse >= 700 && xmouse <= 870 && ymouse >= 770 && ymouse <= 820) {
											BangDanhsachLop();
											trangthai_trangDsLop = true;
										}
										// Nguoi dung chon nut <= rectangle(250, 770, 420, 820);
										else if (xmouse >= 250 && xmouse <= 420 && ymouse >= 770 && ymouse <= 820) {
											BangDanhsachLop();
											trangthai_trangDsLop = false;
										}
										// Nguoi dung chon nut THOAT
										else if (xmouse >= 1200 && xmouse <= 1370 && ymouse >= 770 && ymouse <= 820) {
											break;
										}
										// Nguoi dung chon nut TRUY CAP rectangle(480, 260, 650, 310);
										else if (xmouse >= 480 && xmouse <= 650 && ymouse >= 260 && ymouse <= 310) {
											Nhap_NAM_HOC_de_in_graphic();
											while (true) {
												// Chuyen trang
												ChuyenTrang_DsLop(dslop, trangthai_trangDsLop);

												if (ismouseclick(WM_LBUTTONDOWN)) {
													getmouseclick(WM_LBUTTONDOWN, xmouse, ymouse);

													// hien lai o nhap NAM HOC
													setfillstyle(1, 11);
													bar(780, 120, 950, 160);
													setcolor(0);
													rectangle(780, 120, 950, 160);

													setbkcolor(15);
													setcolor(0);
													settextstyle(10, 0, 2);
													outtextxy(670, 130, (char*)"NAM HOC");

													// hien lai danh sach lop
													hienDsLop_graphic(dslop);

													//Nguoi dung chon nhap du lieu NAM HOC
													if (xmouse >= 50 && xmouse <= 1080 && ymouse >= 80 && ymouse <= 220) {

														if (!In_DsLop_theo_NAM_HOC_chuc_nang_XOA(dslop)) {
															continue;
														}

														setfillstyle(1, 11);
														bar(250, 120, 600, 160);
														setcolor(0);
														rectangle(250, 120, 600, 160);
														setbkcolor(15);
														setcolor(0);
														settextstyle(10, 0, 2);
														outtextxy(130, 130, (char*)"MA LOP");

														while (true) {
															if (ismouseclick(WM_LBUTTONDOWN)) {
																getmouseclick(WM_LBUTTONDOWN, xmouse, ymouse);

																//Nguoi dung chon nhap MA LOP rectangle(250, 120, 600, 160);
																if (xmouse >= 50 && xmouse <= 1080 && ymouse >= 80 && ymouse <= 220) {
																	int vitrilop = TimKiemMaLop_SINHVIEN(dslop);

																	if (vitrilop >= 0) {
																		Quan_ly_mon_hoc_Diem_thi();

																		while (true) {
																			Hien_thi_thong_tin_LOP_HOC_dang_duoc_truy_cap(dslop.DS[vitrilop]->malop, dslop.DS[vitrilop]->tenlop);
																			ChuyenTrang_DsMonHoc(dsmon, trangthai_trangDSMonHoc);

																			if (ismouseclick(WM_LBUTTONDOWN)) {
																				getmouseclick(WM_LBUTTONDOWN, xmouse, ymouse);

																				// Nguoi dung chon nut => rectangle(700, 770, 870, 820);
																				if (xmouse >= 700 && xmouse <= 870 && ymouse >= 770 && ymouse <= 820) {
																					BangDanhSachMonHoc();
																					trangthai_trangDSMonHoc = true;
																				}
																				// Nguoi dung chon nut <= rectangle(250, 770, 420, 820);
																				else if (xmouse >= 250 && xmouse <= 420 && ymouse >= 770 && ymouse <= 820) {
																					BangDanhSachMonHoc();
																					trangthai_trangDSMonHoc = false;
																				}
																				// Nguoi dung chon nut THOAT
																				else if (xmouse >= 1200 && xmouse <= 1370 && ymouse >= 770 && ymouse <= 820) {
																					break;
																				}
																				// Nguoi dung chon nut TRUY CAP rectangle(470, 310, 640, 260);
																				else if (xmouse >= 480 && xmouse <= 650 && ymouse >= 260 && ymouse <= 310) {
																					XemDiemThi(dslop, dsmon, trangthai_trangDSMonHoc, vitrilop, trangthai_trangDsSinhVien_XemDiem);
																					Quan_ly_mon_hoc_Diem_thi();
																					continue;
																				}
																			}
																			delay(10);
																		}
																	}
																	else {
																		continue;
																	}

																	setfillstyle(1, 15);
																	bar(1110, 80, 1500, 750);
																	setcolor(0);
																	rectangle(1110, 80, 1500, 750);
																	line(1110, 140, 1500, 140);

																	setbkcolor(15);
																	setcolor(4);
																	settextstyle(10, 0, 3);
																	outtextxy(1240, 100, (char*)"THONG BAO");
																	break;
																}
																// Nguoi dung chon nut THOAT
																else if (xmouse >= 1200 && xmouse <= 1370 && ymouse >= 770 && ymouse <= 820) {
																	Thong_bao_chon_thoat_chuc_nang_TRUY_CAP();
																	if (Lua_chon_CO_hoac_KHONG_cua_thong_bao_trong_ham_chuc_nang()) {

																		break;
																	}
																	else {
																		// khung thong bao
																		setfillstyle(1, 15);
																		bar(1110, 80, 1500, 750);
																		setcolor(0);
																		rectangle(1110, 80, 1500, 750);
																		line(1110, 140, 1500, 140);

																		setbkcolor(15);
																		setcolor(4);
																		settextstyle(10, 0, 3);
																		outtextxy(1240, 100, (char*)"THONG BAO");
																	}
																}
															}

															delay(200);
														}
														hienDsLop_graphic(dslop);
														break;
													}
													//Nguoi dung chon nut THOAT
													else if (xmouse >= 1200 && xmouse <= 1370 && ymouse >= 770 && ymouse <= 820) {
														Thong_bao_chon_thoat_chuc_nang_TRUY_CAP();
														if (Lua_chon_CO_hoac_KHONG_cua_thong_bao_trong_ham_chuc_nang()) {
															ghiFileDsSinhVien(dslop);
															break;
														}
														else {
															// khung thong bao
															setfillstyle(1, 15);
															bar(1110, 80, 1500, 750);
															setcolor(0);
															rectangle(1110, 80, 1500, 750);
															line(1110, 140, 1500, 140);

															setbkcolor(15);
															setcolor(4);
															settextstyle(10, 0, 3);
															outtextxy(1240, 100, (char*)"THONG BAO");
														}
													}
													// Nguoi dung chon nut => rectangle(700, 770, 870, 820);
													else if (xmouse >= 700 && xmouse <= 870 && ymouse >= 770 && ymouse <= 820) {
														BangDanhsachLop(); // xoa du lieu cu
														trangthai_trangDsLop = true;

													}
													// Nguoi dung chon nut <= rectangle(250, 770, 420, 820);
													else if (xmouse >= 250 && xmouse <= 420 && ymouse >= 770 && ymouse <= 820) {
														BangDanhsachLop(); // xoa du lieu cu
														trangthai_trangDsLop = false;
													}
												}

												delay(200);
											}

											Quan_ly_sinh_vien_Hien_thi_danh_sach_lop();
											continue;
										}
									}
									delay(200);
								}
								Menu_cua_giao_vien();
								continue;
							}
							// Nguoi dung chon nut THOAT
							else if (xmouse >= 600 && xmouse <= 940 && ymouse >= 700 && ymouse <= 750) {
								break;
							}
						}
						delay(200);
					}
					Man_hinh_dang_nhap();
					continue;
				}
				// Kiem tra tai khoan SINH VIEN
				else if (checkTaikhoan == 2 && checkMatkhau == 2) {
					checkTaikhoan = 0;
					checkMatkhau = 0;

					masinhvien = nhapTaikhoan;
					malopsinhvien = malopsinhvien.append(masinhvien, 0, 5);
					
					
					nhapTaikhoan = "";
					nhapMatkhau = "";

					Thong_bao_dang_nhap_thanh_cong();
					ThiTracNghiem(dslop, dsmon, dscauhoithi, trangthai_trangDSMonHoc, masinhvien);

					Man_hinh_dang_nhap();
					continue;
				}
				else {
					Thong_bao_dang_nhap_that_bai();										
				}				
			}
			// Nguoi dung chon EXIT
			else if (xmouse >= 800 && xmouse <= 1010 && ymouse >= 600 && ymouse <= 650) {
				break;
			}
		}
		delay(200);
	}
	closegraph();
	return 0;
}