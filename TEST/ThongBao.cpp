#pragma once
#include <stdio.h>
#include <iostream>
#include "graphics.h"
#include <Windows.h>
#include "DoHoa.h"
#include <string>
#include <string.h>
#include <cstring>
#include <cstringt.h>


#pragma comment(lib, "graphics.lib")

void Thong_bao_sai_tai_khoan() {
	setbkcolor(7);
	setcolor(4);
	settextstyle(10, 0, 3);
	outtextxy(1150, 388, (char*)"Sai tai khoan!");
	Sleep(1500);

	setfillstyle(1, 7);
	bar(1150, 382, 1400, 418);
}
void Thong_bao_sai_mat_khau() {
	setbkcolor(7);
	setcolor(4);
	settextstyle(10, 0, 3);
	outtextxy(1150, 458, (char*)"Sai mat khau!");
	Sleep(1500);

	setfillstyle(1, 7);
	bar(1150, 452, 1400, 488);
}
void Thong_bao_dang_nhap_thanh_cong() {
	setbkcolor(7);
	setcolor(4);
	settextstyle(10, 0, 3);
	outtextxy(640, 520, (char*)"Dang nhap thanh cong!");
	Sleep(1500);
}
void Thong_bao_dang_nhap_that_bai() {
	setbkcolor(7);
	setcolor(4);
	settextstyle(10, 0, 3);
	outtextxy(640, 520, (char*)"Dang nhap that bai!");
	Sleep(1500);

	setfillstyle(1, 7);
	bar(520, 500, 930, 550);
}

void Thong_bao_chon_thoat_chuc_nang_THEM() {
	setbkcolor(15);
	setcolor(4);
	settextstyle(10, 0, 3);
	outtextxy(1150, 185, (char*)"Ban muon thoat chuc nang");
	setcolor(1);
	outtextxy(1280, 220, (char*)"THEM?");
	// nut CO
	setfillstyle(1, 10);
	bar(1140, 300, 1290, 350);
	setcolor(0);
	rectangle(1140, 300, 1290, 350);
	// nut KHONG
	setfillstyle(1, 10);
	bar(1320, 300, 1470, 350);
	setcolor(0);
	rectangle(1320, 300, 1470, 350);

	setbkcolor(10);
	setcolor(0);
	settextstyle(10, 0, 3);
	outtextxy(1200, 315, (char*)"CO");

	setbkcolor(10);
	setcolor(0);
	settextstyle(10, 0, 3);
	outtextxy(1360, 315, (char*)"KHONG");
}
void Thong_bao_chon_thoat_chuc_nang_XOA() {
	setbkcolor(15);
	setcolor(4);
	settextstyle(10, 0, 3);
	outtextxy(1150, 185, (char*)"Ban muon thoat chuc nang");
	setcolor(1);
	outtextxy(1285, 220, (char*)"XOA?");
	// nut CO
	setfillstyle(1, 10);
	bar(1140, 300, 1290, 350);
	setcolor(0);
	rectangle(1140, 300, 1290, 350);
	// nut KHONG
	setfillstyle(1, 10);
	bar(1320, 300, 1470, 350);
	setcolor(0);
	rectangle(1320, 300, 1470, 350);

	setbkcolor(10);
	setcolor(0);
	settextstyle(10, 0, 3);
	outtextxy(1200, 315, (char*)"CO");

	setbkcolor(10);
	setcolor(0);
	settextstyle(10, 0, 3);
	outtextxy(1360, 315, (char*)"KHONG");
}
void Thong_bao_chon_thoat_chuc_nang_SUA() {
	setbkcolor(15);
	setcolor(4);
	settextstyle(10, 0, 3);
	outtextxy(1150, 185, (char*)"Ban muon thoat chuc nang");
	setcolor(1);
	outtextxy(1285, 220, (char*)"SUA?");
	// nut CO
	setfillstyle(1, 10);
	bar(1140, 300, 1290, 350);
	setcolor(0);
	rectangle(1140, 300, 1290, 350);
	// nut KHONG
	setfillstyle(1, 10);
	bar(1320, 300, 1470, 350);
	setcolor(0);
	rectangle(1320, 300, 1470, 350);

	setbkcolor(10);
	setcolor(0);
	settextstyle(10, 0, 3);
	outtextxy(1200, 315, (char*)"CO");

	setbkcolor(10);
	setcolor(0);
	settextstyle(10, 0, 3);
	outtextxy(1360, 315, (char*)"KHONG");
}
void Thong_bao_chon_thoat_chuc_nang_XEM_THEO_NAM() {
	setbkcolor(15);
	setcolor(4);
	settextstyle(10, 0, 3);
	outtextxy(1150, 185, (char*)"Ban muon thoat chuc nang");
	setcolor(1);
	outtextxy(1230, 220, (char*)"XEM THEO NAM?");
	// nut CO
	setfillstyle(1, 10);
	bar(1140, 300, 1290, 350);
	setcolor(0);
	rectangle(1140, 300, 1290, 350);
	// nut KHONG
	setfillstyle(1, 10);
	bar(1320, 300, 1470, 350);
	setcolor(0);
	rectangle(1320, 300, 1470, 350);

	setbkcolor(10);
	setcolor(0);
	settextstyle(10, 0, 3);
	outtextxy(1200, 315, (char*)"CO");

	setbkcolor(10);
	setcolor(0);
	settextstyle(10, 0, 3);
	outtextxy(1360, 315, (char*)"KHONG");
}
void Thong_bao_chon_thoat_chuc_nang_TRUY_CAP() {
	setbkcolor(15);
	setcolor(4);
	settextstyle(10, 0, 3);
	outtextxy(1150, 185, (char*)"Ban muon thoat chuc nang");
	setcolor(1);
	outtextxy(1260, 220, (char*)"TRUY CAP?");
	// nut CO
	setfillstyle(1, 10);
	bar(1140, 300, 1290, 350);
	setcolor(0);
	rectangle(1140, 300, 1290, 350);
	// nut KHONG
	setfillstyle(1, 10);
	bar(1320, 300, 1470, 350);
	setcolor(0);
	rectangle(1320, 300, 1470, 350);

	setbkcolor(10);
	setcolor(0);
	settextstyle(10, 0, 3);
	outtextxy(1200, 315, (char*)"CO");

	setbkcolor(10);
	setcolor(0);
	settextstyle(10, 0, 3);
	outtextxy(1360, 315, (char*)"KHONG");
}

void Thong_bao_chon_lua_vao_file() {
	setbkcolor(15);
	setcolor(4);
	settextstyle(10, 0, 3);
	outtextxy(1150, 185, (char*)"Ban muon luu vao file?");
	// nut CO
	setfillstyle(1, 10);
	bar(1140, 300, 1290, 350);
	setcolor(0);
	rectangle(1140, 300, 1290, 350);
	// nut KHONG
	setfillstyle(1, 10);
	bar(1320, 300, 1470, 350);
	setcolor(0);
	rectangle(1320, 300, 1470, 350);

	setbkcolor(10);
	setcolor(0);
	settextstyle(10, 0, 3);
	outtextxy(1200, 315, (char*)"CO");

	setbkcolor(10);
	setcolor(0);
	settextstyle(10, 0, 3);
	outtextxy(1360, 315, (char*)"KHONG");
}
void Thong_bao_xac_nhan_THEM() {
	setbkcolor(15);
	setcolor(4);
	settextstyle(10, 0, 3);
	outtextxy(1190, 185, (char*)"Ban muon xac nhan");
	setcolor(1);
	outtextxy(1280, 220, (char*)"THEM?");
	// nut CO
	setfillstyle(1, 10);
	bar(1140, 300, 1290, 350);
	setcolor(0);
	rectangle(1140, 300, 1290, 350);
	// nut KHONG
	setfillstyle(1, 10);
	bar(1320, 300, 1470, 350);
	setcolor(0);
	rectangle(1320, 300, 1470, 350);

	setbkcolor(10);
	setcolor(0);
	settextstyle(10, 0, 3);
	outtextxy(1200, 315, (char*)"CO");

	setbkcolor(10);
	setcolor(0);
	settextstyle(10, 0, 3);
	outtextxy(1360, 315, (char*)"KHONG");
}
void Thong_bao_xac_nhan_XOA() {
	setbkcolor(15);
	setcolor(4);
	settextstyle(10, 0, 3);
	outtextxy(1190, 185, (char*)"Ban muon xac nhan");
	setcolor(1);
	outtextxy(1285, 220, (char*)"XOA?");
	// nut CO
	setfillstyle(1, 10);
	bar(1140, 300, 1290, 350);
	setcolor(0);
	rectangle(1140, 300, 1290, 350);
	// nut KHONG
	setfillstyle(1, 10);
	bar(1320, 300, 1470, 350);
	setcolor(0);
	rectangle(1320, 300, 1470, 350);

	setbkcolor(10);
	setcolor(0);
	settextstyle(10, 0, 3);
	outtextxy(1200, 315, (char*)"CO");

	setbkcolor(10);
	setcolor(0);
	settextstyle(10, 0, 3);
	outtextxy(1360, 315, (char*)"KHONG");
}
void Thong_bao_xac_nhan_SUA() {
	setbkcolor(15);
	setcolor(4);
	settextstyle(10, 0, 3);
	outtextxy(1190, 185, (char*)"Ban muon xac nhan");
	setcolor(1);
	outtextxy(1285, 220, (char*)"SUA?");
	// nut CO
	setfillstyle(1, 10);
	bar(1140, 300, 1290, 350);
	setcolor(0);
	rectangle(1140, 300, 1290, 350);
	// nut KHONG
	setfillstyle(1, 10);
	bar(1320, 300, 1470, 350);
	setcolor(0);
	rectangle(1320, 300, 1470, 350);

	setbkcolor(10);
	setcolor(0);
	settextstyle(10, 0, 3);
	outtextxy(1200, 315, (char*)"CO");

	setbkcolor(10);
	setcolor(0);
	settextstyle(10, 0, 3);
	outtextxy(1360, 315, (char*)"KHONG");
}

void Thong_bao_dang_tien_hanh_SUA() {
	setbkcolor(15);
	setcolor(4);
	settextstyle(10, 0, 3);
	// 185 220
	outtextxy(1190, 385, (char*)"Ban dang tien hanh");
	setcolor(1);
	outtextxy(1285, 420, (char*)"SUA");
}
void Thong_bao_THANH_CONG() {
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

	// in ch? THÀNH CÔNG 
	setbkcolor(15);
	setcolor(4);
	settextstyle(10, 0, 3);
	outtextxy(1230, 185, (char*)"THANH CONG!");
	Sleep(2000);

	setfillstyle(1, 15);
	bar(1110, 80, 1500, 370);
	setcolor(0);
	rectangle(1110, 80, 1500, 750);
	line(1110, 140, 1500, 140);

	setbkcolor(15);
	setcolor(4);
	settextstyle(10, 0, 3);
	outtextxy(1240, 100, (char*)"THONG BAO");

}

void Thong_bao_Ko_tim_thay_MA() {

	// in ch? THÀNH CÔNG 
	setbkcolor(15);
	setcolor(4);
	settextstyle(10, 0, 3);
	outtextxy(1185, 185, (char*)"Khong tim thay MA");
	Sleep(2000);

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

}
void Thong_bao_Ko_tim_thay_ID() {

	// in ch? THÀNH CÔNG 
	setbkcolor(15);
	setcolor(4);
	settextstyle(10, 0, 3);
	outtextxy(1185, 185, (char*)"Khong tim thay ID");
	Sleep(2000);

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

}

void Thong_bao_khong_duoc_de_trong_MALOP() {

	setbkcolor(15);
	setcolor(4);
	settextstyle(10, 0, 3);
	outtextxy(1175, 185, (char*)"Khong duoc de trong");
	setcolor(1);
	outtextxy(1260, 220, (char*)"MA LOP");
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

}
void Thong_bao_trung_TENLOP() {

	setbkcolor(15);
	setcolor(4);
	settextstyle(10, 0, 3);
	outtextxy(1245, 185, (char*)"Bi trung");
	setcolor(1);
	outtextxy(1260, 220, (char*)"TEN LOP");
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

}
void Thong_bao_khong_duoc_de_trong_TENLOP() {

	setbkcolor(15);
	setcolor(4);
	settextstyle(10, 0, 3);
	outtextxy(1175, 185, (char*)"Khong duoc de trong");
	setcolor(1);
	outtextxy(1260, 220, (char*)"TEN LOP");
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

}
void Thong_bao_trung_MALOP() {
	setbkcolor(15);
	setcolor(4);
	settextstyle(10, 0, 3);
	outtextxy(1245, 185, (char*)"Bi trung");
	setcolor(1);
	outtextxy(1260, 220, (char*)"MA LOP");
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
}
void Thong_bao_khong_xoa_duoc_Lop() {
	setbkcolor(15);
	setcolor(4);
	settextstyle(10, 0, 3);
	outtextxy(1210, 185, (char*)"Lop co hoc sinh");
	setcolor(1);
	outtextxy(1220, 220, (char*)"Khong duoc Xoa");
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
}
void Thong_bao_khong_sua_duoc_Lop() {
	setbkcolor(15);
	setcolor(4);
	settextstyle(10, 0, 3);
	outtextxy(1210, 185, (char*)"Lop co hoc sinh");
	setcolor(1);
	outtextxy(1220, 220, (char*)"Khong duoc Sua");
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
}

void Thong_bao_Loi_NAMHOC() {

	setbkcolor(15);
	setcolor(4);
	settextstyle(10, 0, 3);
	outtextxy(1220, 220, (char*)"(1950 - 2050)");
	setcolor(1);
	outtextxy(1260, 185, (char*)"NAM HOC");
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

}
void Thong_bao_Loi_THOIGIAN() {

	setbkcolor(15);
	setcolor(4);
	settextstyle(10, 0, 3);
	outtextxy(1240, 220, (char*)"(1 - 180)");
	setcolor(1);
	outtextxy(1240, 185, (char*)"THOI GIAN");
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

}
void Thong_bao_Loi_SOCAUHOI() {

	setbkcolor(15);
	setcolor(4);
	settextstyle(10, 0, 3);
	outtextxy(1240, 220, (char*)"(1 -   )");
	setcolor(1);
	outtextxy(1245, 185, (char*)"CAU HOI");


}
void Thong_bao_Vui_long_nhap_MA_LOP() {
	setbkcolor(15);
	setcolor(4);
	settextstyle(10, 0, 3);
	outtextxy(1220, 185, (char*)"Vui long nhap");
	setcolor(1);
	outtextxy(1270, 220, (char*)"MA LOP");

}

void Thong_bao_Vui_long_nhap_MA_SINH_VIEN() {
	setbkcolor(15);
	setcolor(4);
	settextstyle(10, 0, 3);
	outtextxy(1220, 185, (char*)"Vui long nhap");
	setcolor(1);
	outtextxy(1220, 220, (char*)"MA SINH VIEN");

	Sleep(2500);


	setfillstyle(1, 15);
	bar(1110, 80, 1500, 350);
	setcolor(0);
	rectangle(1110, 80, 1500, 750);
	line(1110, 140, 1500, 140);

	setbkcolor(15);
	setcolor(4);
	settextstyle(10, 0, 3);
	outtextxy(1240, 100, (char*)"THONG BAO");
}
void Thong_bao_Vui_long_nhap_HO_SINH_VIEN() {
	setbkcolor(15);
	setcolor(4);
	settextstyle(10, 0, 3);
	outtextxy(1220, 185, (char*)"Vui long nhap");
	setcolor(1);
	outtextxy(1220, 220, (char*)"HO SINH VIEN");

	Sleep(2500);

	// Khung thong bao

	setfillstyle(1, 15);
	bar(1110, 80, 1500, 350);
	setcolor(0);
	rectangle(1110, 80, 1500, 750);
	line(1110, 140, 1500, 140);

	setbkcolor(15);
	setcolor(4);
	settextstyle(10, 0, 3);
	outtextxy(1240, 100, (char*)"THONG BAO");
}
void Thong_bao_Vui_long_nhap_TEN_SINH_VIEN() {
	setbkcolor(15);
	setcolor(4);
	settextstyle(10, 0, 3);
	outtextxy(1220, 185, (char*)"Vui long nhap");
	setcolor(1);
	outtextxy(1220, 220, (char*)"TEN SINH VIEN");

	Sleep(2500);

	// Khung thong bao

	setfillstyle(1, 15);
	bar(1110, 80, 1500, 370);
	setcolor(0);
	rectangle(1110, 80, 1500, 750);
	line(1110, 140, 1500, 140);

	setbkcolor(15);
	setcolor(4);
	settextstyle(10, 0, 3);
	outtextxy(1240, 100, (char*)"THONG BAO");
}
void Thong_bao_Vui_long_nhap_PHAI_SINH_VIEN() {
	setbkcolor(15);
	setcolor(4);
	settextstyle(10, 0, 3);
	outtextxy(1220, 185, (char*)"Vui long chon");
	setcolor(1);
	outtextxy(1230, 220, (char*)"GIOI TINH");

	Sleep(2500);

	// Khung thong bao

	setfillstyle(1, 15);
	bar(1110, 80, 1500, 350);
	setcolor(0);
	rectangle(1110, 80, 1500, 750);
	line(1110, 140, 1500, 140);

	setbkcolor(15);
	setcolor(4);
	settextstyle(10, 0, 3);
	outtextxy(1240, 100, (char*)"THONG BAO");
}
void Thong_bao_Vui_long_nhap_MAT_KHAU_SINH_VIEN() {
	setbkcolor(15);
	setcolor(4);
	settextstyle(10, 0, 3);
	outtextxy(1220, 185, (char*)"Vui long nhap");
	setcolor(1);
	outtextxy(1230, 220, (char*)"MAT KHAU");

	Sleep(2500);

	// Khung thong bao

	setfillstyle(1, 15);
	bar(1110, 80, 1500, 350);
	setcolor(0);
	rectangle(1110, 80, 1500, 750);
	line(1110, 140, 1500, 140);

	setbkcolor(15);
	setcolor(4);
	settextstyle(10, 0, 3);
	outtextxy(1240, 100, (char*)"THONG BAO");
}
void Thong_bao_Vui_long_nhap_DAY_DU_THONG_TIN() {
	setbkcolor(15);
	setcolor(4);
	settextstyle(10, 0, 3);
	outtextxy(1220, 185, (char*)"Vui long nhap");
	setcolor(1);
	outtextxy(1200, 220, (char*)"DAY DU THONG TIN");

	Sleep(2500);

	// Khung thong bao

	setfillstyle(1, 15);
	bar(1110, 80, 1500, 350);
	setcolor(0);
	rectangle(1110, 80, 1500, 750);
	line(1110, 140, 1500, 140);

	setbkcolor(15);
	setcolor(4);
	settextstyle(10, 0, 3);
	outtextxy(1240, 100, (char*)"THONG BAO");
}

void Thong_bao_trung_MA_SINH_VIEN() {

	setbkcolor(15);
	setcolor(4);
	settextstyle(10, 0, 3);
	outtextxy(1245, 185, (char*)"Bi trung");
	setcolor(1);
	outtextxy(1220, 220, (char*)"MA SINH VIEN");
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

}
void Thong_bao_trung_HO_TEN_SINH_VIEN() {

	setbkcolor(15);
	setcolor(4);
	settextstyle(10, 0, 3);
	outtextxy(1245, 185, (char*)"Bi trung");
	setcolor(1);
	outtextxy(1200, 220, (char*)"HO TEN SINH VIEN");
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

}
void Thong_bao_khong_xoa_duoc_SinhVien() {
	setbkcolor(15);
	setcolor(4);
	settextstyle(10, 0, 3);
	outtextxy(1150, 185, (char*)"Sinh Vien da co Diem thi");
	setcolor(1);
	outtextxy(1215, 220, (char*)"Khong duoc Xoa");
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
}
void Thong_bao_khong_sua_duoc_SinhVien() {
	setbkcolor(15);
	setcolor(4);
	settextstyle(10, 0, 3);
	outtextxy(1150, 185, (char*)"Sinh Vien da co Diem thi");
	setcolor(1);
	outtextxy(1215, 220, (char*)"Khong duoc Sua");
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
}

void Thong_bao_khong_duoc_de_trong_MAMON() {

	setbkcolor(15);
	setcolor(4);
	settextstyle(10, 0, 3);
	outtextxy(1175, 185, (char*)"Khong duoc de trong");
	setcolor(1);
	outtextxy(1260, 220, (char*)"MA MON");
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

}
void Thong_bao_khong_duoc_de_trong_TENMON() {

	setbkcolor(15);
	setcolor(4);
	settextstyle(10, 0, 3);
	outtextxy(1175, 185, (char*)"Khong duoc de trong");
	setcolor(1);
	outtextxy(1260, 220, (char*)"TEN MON");
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

}
void Thong_bao_khong_duoc_de_trong_ID() {

	setbkcolor(15);
	setcolor(4);
	settextstyle(10, 0, 3);
	outtextxy(1175, 185, (char*)"Khong duoc de trong");
	setcolor(1);
	outtextxy(1290, 220, (char*)"ID");
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

}
void Thong_bao_khong_xoa_duoc_MonHoc() {
	setbkcolor(15);
	setcolor(4);
	settextstyle(10, 0, 3);
	outtextxy(1210, 185, (char*)"Mon co Cau Hoi");
	setcolor(1);
	outtextxy(1215, 220, (char*)"Khong duoc Xoa");
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
}
void Thong_bao_khong_sua_duoc_MonHoc() {
	setbkcolor(15);
	setcolor(4);
	settextstyle(10, 0, 3);
	outtextxy(1210, 185, (char*)"Mon co Cau Hoi");
	setcolor(1);
	outtextxy(1215, 220, (char*)"Khong duoc Sua");
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
}

void Thong_bao_trung_MA_MON() {

	setbkcolor(15);
	setcolor(4);
	settextstyle(10, 0, 3);
	outtextxy(1245, 185, (char*)"Bi trung");
	setcolor(1);
	outtextxy(1260, 220, (char*)"MA MON");
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

}
void Thong_bao_trung_TEN_MON() {

	setbkcolor(15);
	setcolor(4);
	settextstyle(10, 0, 3);
	outtextxy(1245, 185, (char*)"Bi trung");
	setcolor(1);
	outtextxy(1260, 220, (char*)"TEN MON");
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

}

void Thong_bao_trung_DAP_AN() {

	setbkcolor(15);
	setcolor(4);
	settextstyle(10, 0, 3);
	outtextxy(1245, 185, (char*)"Bi trung");
	setcolor(1);
	outtextxy(1260, 220, (char*)"DAP AN");
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

}
void Thong_bao_vui_long_Chon_DAP_AN() {

	setbkcolor(15);
	setcolor(4);
	settextstyle(10, 0, 3);
	outtextxy(1225, 185, (char*)"Vui long chon");
	setcolor(1);
	outtextxy(1240, 220, (char*)"DAP AN DUNG");
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

}

void Thong_bao_xac_nhan_NOP_BAI() {
	setbkcolor(15);
	setcolor(4);
	settextstyle(10, 0, 3);
	outtextxy(1190, 185 + 230, (char*)"Ban muon xac nhan");
	setcolor(1);
	outtextxy(1260, 220 + 230, (char*)"NOP BAI");
	// nut CO
	setfillstyle(1, 10);
	bar(1140, 300 + 230, 1290, 350 + 230);
	setcolor(0);
	rectangle(1140, 300 + 230, 1290, 350 + 230);
	// nut KHONG
	setfillstyle(1, 10);
	bar(1320, 300 + 230, 1470, 350 + 230);
	setcolor(0);
	rectangle(1320, 300 + 230, 1470, 350 + 230);

	setbkcolor(10);
	setcolor(0);
	settextstyle(10, 0, 3);
	outtextxy(1200, 315 + 230, (char*)"CO");

	setbkcolor(10);
	setcolor(0);
	settextstyle(10, 0, 3);
	outtextxy(1360, 315 + 230, (char*)"KHONG");
}
void Thong_bao_xac_nhan_THOAT() {
	setbkcolor(15);
	setcolor(4);
	settextstyle(10, 0, 3);
	outtextxy(1190, 185 + 230, (char*)"Ban muon xac nhan");
	setcolor(1);
	outtextxy(1270, 220 + 230, (char*)"THOAT");
	// nut CO
	setfillstyle(1, 10);
	bar(1140, 300 + 230, 1290, 350 + 230);
	setcolor(0);
	rectangle(1140, 300 + 230, 1290, 350 + 230);
	// nut KHONG
	setfillstyle(1, 10);
	bar(1320, 300 + 230, 1470, 350 + 230);
	setcolor(0);
	rectangle(1320, 300 + 230, 1470, 350 + 230);

	setbkcolor(10);
	setcolor(0);
	settextstyle(10, 0, 3);
	outtextxy(1200, 315 + 230, (char*)"CO");

	setbkcolor(10);
	setcolor(0);
	settextstyle(10, 0, 3);
	outtextxy(1360, 315 + 230, (char*)"KHONG");
}

void Thong_bao_Danh_sach_Cau_Hoi_Trong() {

	// in ch? THÀNH CÔNG 
	setbkcolor(15);
	setcolor(4);
	settextstyle(10, 0, 3);
	outtextxy(1155, 185, (char*)"Danh sach Cau hoi trong!");
	Sleep(2000);

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
}
void Thong_bao_Sinh_Vien_Da_Thi_Mon_Hoc() {

	// in ch? THÀNH CÔNG 
	setbkcolor(15);
	setcolor(4);
	settextstyle(10, 0, 3);
	outtextxy(1195, 185, (char*)"Mon Hoc da thi!");
	outtextxy(1195, 215, (char*)"Xem lai dap an?");

	// nut CO
	setfillstyle(1, 10);
	bar(1140, 300, 1290, 350);
	setcolor(0);
	rectangle(1140, 300, 1290, 350);
	// nut KHONG
	setfillstyle(1, 10);
	bar(1320, 300, 1470, 350);
	setcolor(0);
	rectangle(1320, 300, 1470, 350);

	setbkcolor(10);
	setcolor(0);
	settextstyle(10, 0, 3);
	outtextxy(1200, 315, (char*)"CO");

	setbkcolor(10);
	setcolor(0);
	settextstyle(10, 0, 3);
	outtextxy(1360, 315, (char*)"KHONG");
}
void Thong_bao_Sinh_Vien_Chua_Thi_Mon_Hoc() {

	// in ch? THÀNH CÔNG 
	setbkcolor(15);
	setcolor(4);
	settextstyle(10, 0, 3);
	outtextxy(1195, 185, (char*)"Sinh vien chua thi!");

	Sleep(2000);

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
}