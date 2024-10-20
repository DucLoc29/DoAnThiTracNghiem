#pragma once
#include <stdio.h>
#include <iostream>
#include "graphics.h"
#include <Windows.h>

#pragma comment(lib, "graphics.lib")

void Man_hinh_dang_nhap() {
	// mau man hinh
	setbkcolor(7);
	cleardevice();

	// THI TRAC NGHIEM
	setcolor(0);
	settextstyle(10, 0, 9);
	outtextxy(350, 80, (char*)"THI TRAC NGHIEM");

	// chu dang nhap
	setcolor(0);
	settextstyle(10, 0, 5);
	outtextxy(670, 280, (char*)"DANG NHAP");

	// hinh chu nhat: dang nhap
	setfillstyle(1, 15);
	bar(700, 420, 1060, 380);
	setcolor(0);
	rectangle(700, 420, 1060, 380);


	// hinh chu nhat: mat khau
	setfillstyle(1, 15);
	bar(700, 490, 1060, 450);
	setcolor(0);
	rectangle(700, 490, 1060, 450);


	// Chu: dang nhap va mat khau
	settextstyle(9, 0, 2);
	setcolor(0);
	outtextxy(520, 390, (char*)"Tai khoan");

	setcolor(0);
	outtextxy(523, 460, (char*)"Mat khau");

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
	outtextxy(610, 610, (char*)"ENTER");

	// Nut THOAT
	setfillstyle(1, 3);
	bar(800, 600, 1010, 650);
	setcolor(15);
	rectangle(800, 600, 1010, 650);
	rectangle(799, 599, 1011, 651);

	setbkcolor(3);

	settextstyle(10, 0, 4);
	setcolor(15);
	outtextxy(865, 610, (char*)"EXIT");

	// CREDIT
	setbkcolor(7);
	settextstyle(9, 0, 1);
	setcolor(0);
	outtextxy(120, 670, (char*)"Thuc hien boi");

	setbkcolor(7);
	settextstyle(8, 0, 1);
	setcolor(0);
	outtextxy(40, 720, (char*)"Nguyen Duc Loc");

	setbkcolor(7);
	settextstyle(8, 0, 1);
	setcolor(0);
	outtextxy(240, 720, (char*)"N22DCCN150");

	setbkcolor(7);
	settextstyle(8, 0, 1);
	setcolor(0);
	outtextxy(40, 750, (char*)"Nguyen Huu Huynh");

	setbkcolor(7);
	settextstyle(8, 0, 1);
	setcolor(0);
	outtextxy(240, 750, (char*)"N22DCCN135");

	setbkcolor(7);
	settextstyle(8, 0, 1);
	setcolor(0);
	outtextxy(40, 780, (char*)"Huu Trung Kien");

	setbkcolor(7);
	settextstyle(8, 0, 1);
	setcolor(0);
	outtextxy(240, 780, (char*)"N22DCCN144");
}
void Menu_cua_giao_vien() {
	setbkcolor(7);
	cleardevice();

	setcolor(0);
	settextstyle(10, 0, 9);
	outtextxy(340, 80, (char*)"MENU GIANG VIEN");

	setcolor(0);
	settextstyle(10, 0, 6);
	outtextxy(660, 210, (char*)"QUAN LY");

	// MENU
	setfillstyle(1, 15);
	bar(600, 300, 940, 350);
	setcolor(0);
	rectangle(600, 300, 940, 350);

	setfillstyle(1, 15);
	bar(600, 380, 940, 430);
	setcolor(0);
	rectangle(600, 380, 940, 430);

	setfillstyle(1, 15);
	bar(600, 460, 940, 510);
	setcolor(0);
	rectangle(600, 460, 940, 510);

	setfillstyle(1, 15);
	bar(600, 540, 940, 590);
	setcolor(0);
	rectangle(600, 540, 940, 590);

	setfillstyle(1, 15);
	bar(600, 620, 940, 670);
	setcolor(0);
	rectangle(600, 620, 940, 670);

	setfillstyle(1, 15);
	bar(600, 700, 940, 750);
	setcolor(0);
	rectangle(600, 700, 940, 750);

	// Khung cua MENU
	setcolor(15);
	rectangle(430, 270, 1100, 780);
	// Chu cua MENU
	setbkcolor(15);
	setcolor(0);
	settextstyle(6, 0, 3);
	outtextxy(735, 315, (char*)"LOP");

	setcolor(0);
	settextstyle(6, 0, 3);
	outtextxy(690, 395, (char*)"SINH VIEN");

	setcolor(0);
	settextstyle(6, 0, 3);
	outtextxy(695, 473, (char*)"MON HOC");

	setcolor(0);
	settextstyle(6, 0, 3);
	outtextxy(705, 553, (char*)"CAU HOI");

	setcolor(0);
	settextstyle(6, 0, 3);
	outtextxy(730, 635, (char*)"DIEM");

	setcolor(0);
	settextstyle(6, 0, 3);
	outtextxy(715, 715, (char*)"THOAT");
}

void Quan_ly_lop() {
	// Set mau background
	setbkcolor(7);
	cleardevice();

	// Chu tieu de
	setcolor(0);
	settextstyle(10, 0, 6);
	outtextxy(530, 10, (char*)"QUAN LY LOP HOC");

	// Khung hien thi danh sach lop
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

	// Khung chuc nang
	setfillstyle(1, 15);
	bar(50, 80, 1080, 320);

	setcolor(0);
	rectangle(50, 80, 1080, 320);

	// Nut chuc nang THEM SUA XOA XEM THEO NAM
	setfillstyle(1, 9);
	bar(100, 260, 270, 310);
	setcolor(0);
	rectangle(100, 260, 270, 310);

	setfillstyle(1, 9);
	bar(320, 260, 490, 310);
	setcolor(0);
	rectangle(320, 260, 490, 310);

	setfillstyle(1, 9);
	bar(540, 260, 710, 310);
	setcolor(0);
	rectangle(540, 260, 710, 310);

	setfillstyle(1, 9);
	bar(760, 260, 1030, 310);
	setcolor(0);
	rectangle(760, 260, 1030, 310);

	setbkcolor(9);
	setcolor(0);
	settextstyle(10, 0, 3);
	outtextxy(160, 275, (char*)"THEM");

	setbkcolor(9);
	setcolor(0);
	settextstyle(10, 0, 3);
	outtextxy(385, 275, (char*)"SUA");

	setbkcolor(9);
	setcolor(0);
	settextstyle(10, 0, 3);
	outtextxy(605, 275, (char*)"XOA");

	setbkcolor(9);
	setcolor(0);
	settextstyle(10, 0, 3);
	outtextxy(815, 275, (char*)"XEM THEO NAM");


	// Khung thong bao
	setfillstyle(1, 15);
	bar(1110, 80, 1500, 750);
	setcolor(0);
	rectangle(1110, 80, 1500, 750);
	line(1110, 140, 1500, 140);

	setbkcolor(15);
	setcolor(4);
	settextstyle(10, 0, 3);
	outtextxy(1240, 100, (char*)"THONG BAO");

	// Nut chuyen trang
	setfillstyle(1, 9);
	bar(250, 770, 420, 820);
	setcolor(0);
	rectangle(250, 770, 420, 820);

	setfillstyle(1, 9);
	bar(700, 770, 870, 820);
	setcolor(0);
	rectangle(700, 770, 870, 820);

	setbkcolor(9);
	setcolor(0);
	settextstyle(10, 0, 3);
	outtextxy(320, 785, (char*)"<=");

	setbkcolor(9);
	setcolor(0);
	settextstyle(10, 0, 3);
	outtextxy(775, 785, (char*)"=>");

	// Khu vuc dien thong tin
	//setfillstyle(1, 11);
	//bar(400, 120, 900, 160);
	//setcolor(0);
	//rectangle(400, 120, 900, 160);

	//setfillstyle(1, 11);
	//bar(400, 180, 900, 220);
	//setcolor(0);
	//rectangle(400, 180, 900, 220);

	//setbkcolor(15);
	//setcolor(0);
	//settextstyle(10, 0, 2);
	//outtextxy(280, 130, (char*)"MA LOP");

	//setbkcolor(15);
	//setcolor(0);
	//settextstyle(10, 0, 2);
	//outtextxy(270, 190, (char*)"TEN LOP");

	// nut THOAT
	setfillstyle(1, 10);
	bar(1200, 770, 1370, 820);
	setcolor(0);
	rectangle(1200, 770, 1370, 820);

	setbkcolor(10);
	setcolor(0);
	settextstyle(10, 0, 3);
	outtextxy(1250, 785, (char*)"THOAT");

}
void Khung_hien_thi_danh_sach_lop_graphic() {
	// Khung hien thi danh sach lop
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
}
void BangDanhsachLop() {
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
}
void Khu_vuc_nhap_thong_tin_lop() {
	// Khung chuc nang
	setfillstyle(1, 15);
	bar(50, 80, 1080, 320);

	setcolor(0);
	rectangle(50, 80, 1080, 320);

	setfillstyle(1, 11);
	bar(250, 120, 600, 160);
	setcolor(0);
	rectangle(250, 120, 600, 160);

	setfillstyle(1, 11);
	bar(250, 180, 900, 220);
	setcolor(0);
	rectangle(250, 180, 900, 220);

	setfillstyle(1, 11);
	bar(780, 120, 950, 160);
	setcolor(0);
	rectangle(780, 120, 950, 160);

	setbkcolor(15);
	setcolor(0);
	settextstyle(10, 0, 2);
	outtextxy(130, 130, (char*)"MA LOP");

	setbkcolor(15);
	setcolor(0);
	settextstyle(10, 0, 2);
	outtextxy(120, 190, (char*)"TEN LOP");

	setbkcolor(15);
	setcolor(0);
	settextstyle(10, 0, 2);
	outtextxy(670, 130, (char*)"NAM HOC");

	setbkcolor(15);
	setcolor(1);
	settextstyle(8, 0, 1);
	outtextxy(205, 90, (char*)"[D__ MA LOP] (chuan hoa theo Nam hoc)");

	setfillstyle(1, 9);
	bar(470, 310, 640, 260);
	setcolor(0);
	rectangle(470, 260, 640, 310);

	setbkcolor(9);
	setcolor(0);
	settextstyle(10, 0, 3);
	outtextxy(530, 275, (char*)"THEM");
}
void Khu_vuc_SUA_thong_tin_lop() {
	// Khung chuc nang
	setfillstyle(1, 15);
	bar(50, 80, 1080, 320);

	setcolor(0);
	rectangle(50, 80, 1080, 320);

	setfillstyle(1, 11);
	bar(250, 120, 600, 160);
	setcolor(0);
	rectangle(250, 120, 600, 160);

	setfillstyle(1, 11);
	bar(250, 180, 900, 220);
	setcolor(0);
	rectangle(250, 180, 900, 220);

	setfillstyle(1, 11);
	bar(780, 120, 950, 160);
	setcolor(0);
	rectangle(780, 120, 950, 160);

	setbkcolor(15);
	setcolor(0);
	settextstyle(10, 0, 2);
	outtextxy(130, 130, (char*)"MA LOP");

	setbkcolor(15);
	setcolor(0);
	settextstyle(10, 0, 2);
	outtextxy(120, 190, (char*)"TEN LOP");

	setbkcolor(15);
	setcolor(0);
	settextstyle(10, 0, 2);
	outtextxy(670, 130, (char*)"NAM HOC");

	setbkcolor(15);
	setcolor(1);
	settextstyle(8, 0, 1);
	outtextxy(205, 90, (char*)"[D__ MA LOP] (chuan hoa theo Nam hoc)");

	setfillstyle(1, 9);
	bar(470, 310, 640, 260);
	setcolor(0);
	rectangle(470, 260, 640, 310);

	setbkcolor(9);
	setcolor(0);
	settextstyle(10, 0, 3);
	outtextxy(530, 275, (char*)"SUA");
}
void Nhap_MA_LOP_de_xoa() {

	setfillstyle(1, 11);
	bar(250, 120, 600, 160);
	setcolor(0);
	rectangle(250, 120, 600, 160);

	setbkcolor(15);
	setcolor(0);
	settextstyle(10, 0, 2);
	outtextxy(130, 130, (char*)"MA LOP");
}
void Nhap_NAM_HOC_de_in_graphic() {

	setbkcolor(15);
	setcolor(0);
	settextstyle(10, 0, 3);
	outtextxy(270, 130, (char*)"Hay nhap nam hoc ->");

	setfillstyle(1, 11);
	bar(780, 120, 950, 160);
	setcolor(0);
	rectangle(780, 120, 950, 160);

	setbkcolor(15);
	setcolor(0);
	settextstyle(10, 0, 2);
	outtextxy(670, 130, (char*)"NAM HOC");
}

void Quan_ly_sinh_vien() {
	// Set mau background
	setbkcolor(7);
	cleardevice();

	// Chu tieu de
	setcolor(0);
	settextstyle(10, 0, 6);
	outtextxy(530, 10, (char*)"QUAN LY SINH VIEN");

	// Khung hien thi danh sach lop
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
	line(250, 350, 250, 750);
	line(360, 350, 360, 750);
	line(740, 350, 740, 750);
	line(870, 350, 870, 750);

	setbkcolor(15);
	setcolor(1);
	settextstyle(10, 0, 3);
	outtextxy(115, 360, (char*)"MA SV");

	setbkcolor(15);
	setcolor(1);
	settextstyle(10, 0, 3);
	outtextxy(280, 360, (char*)"PHAI");

	setbkcolor(15);
	setcolor(1);
	settextstyle(10, 0, 3);
	outtextxy(540, 360, (char*)"HO");

	setbkcolor(15);
	setcolor(1);
	settextstyle(10, 0, 3);
	outtextxy(785, 360, (char*)"TEN");

	setbkcolor(15);
	setcolor(1);
	settextstyle(10, 0, 3);
	outtextxy(920, 360, (char*)"MAT KHAU");

	// Khung chuc nang
	setfillstyle(1, 15);
	bar(50, 80, 1080, 320);

	setcolor(0);
	rectangle(50, 80, 1080, 320);

	// Nut chuc nang THEM SUA XOA
	setfillstyle(1, 9);
	bar(250, 310, 420, 260);
	setcolor(0);
	rectangle(250, 310, 420, 260);

	setfillstyle(1, 9);
	bar(470, 310, 640, 260);
	setcolor(0);
	rectangle(470, 310, 640, 260);

	setfillstyle(1, 9);
	bar(690, 310, 860, 260);
	setcolor(0);
	rectangle(690, 310, 860, 260);

	setbkcolor(9);
	setcolor(0);
	settextstyle(10, 0, 3);
	outtextxy(310, 275, (char*)"THEM");

	setbkcolor(9);
	setcolor(0);
	settextstyle(10, 0, 3);
	outtextxy(535, 275, (char*)"SUA");

	setbkcolor(9);
	setcolor(0);
	settextstyle(10, 0, 3);
	outtextxy(755, 275, (char*)"XOA");

	// Khung thong bao
	setfillstyle(1, 15);
	bar(1110, 80, 1500, 750);
	setcolor(0);
	rectangle(1110, 80, 1500, 750);
	line(1110, 140, 1500, 140);

	setbkcolor(15);
	setcolor(4);
	settextstyle(10, 0, 3);
	outtextxy(1240, 100, (char*)"THONG BAO");

	// Nut chuyen trang
	setfillstyle(1, 9);
	bar(250, 770, 420, 820);
	setcolor(0);
	rectangle(250, 770, 420, 820);

	setfillstyle(1, 9);
	bar(700, 770, 870, 820);
	setcolor(0);
	rectangle(700, 770, 870, 820);

	setbkcolor(9);
	setcolor(0);
	settextstyle(10, 0, 3);
	outtextxy(320, 785, (char*)"<=");

	setbkcolor(9);
	setcolor(0);
	settextstyle(10, 0, 3);
	outtextxy(770, 785, (char*)"=>");

	//// Khu vuc dien thong tin MA SINH VIEN | HO TEN | MAT KHAU
	//setfillstyle(1, 11);
	//bar(200, 120, 600, 160);
	//setcolor(0);
	//rectangle(200, 120, 600, 160);

	//setfillstyle(1, 11);
	//bar(200, 180, 600, 220);
	//setcolor(0);
	//rectangle(200, 180, 600, 220);

	//setfillstyle(1, 11);
	//bar(800, 180, 1050, 220);
	//setcolor(0);
	//rectangle(800, 180, 1050, 220);

	//// Chon gioi tinh NAM NU

	//setfillstyle(1, 10);
	//bar(700, 110, 850, 160);
	//setcolor(0);
	//rectangle(700, 110, 850, 160);

	//setfillstyle(1, 10);
	//bar(900, 110, 1050, 160);
	//setcolor(0);
	//rectangle(900, 110, 1050, 160);

	//setbkcolor(15);
	//setcolor(0);
	//settextstyle(10, 0, 2);
	//outtextxy(130, 130, (char*)"MA SV");

	//setbkcolor(15);
	//setcolor(0);
	//settextstyle(10, 0, 2);
	//outtextxy(120, 190, (char*)"HO TEN");

	//setbkcolor(15);
	//setcolor(0);
	//settextstyle(10, 0, 2);
	//outtextxy(670, 190, (char*)"MAT KHAU");

	//setbkcolor(10);
	//setcolor(0);
	//settextstyle(10, 0, 3);
	//outtextxy(755, 125, (char*)"NAM");

	//setbkcolor(10);
	//setcolor(0);
	//settextstyle(10, 0, 3);
	//outtextxy(965, 125, (char*)"NU");

	// nut THOAT
	setfillstyle(1, 10);
	bar(1200, 770, 1370, 820);
	setcolor(0);
	rectangle(1200, 770, 1370, 820);

	setbkcolor(10);
	setcolor(0);
	settextstyle(10, 0, 3);
	outtextxy(1250, 785, (char*)"THOAT");
}
void BangDanhSachSinhVien() {
	// Khung hien thi danh sach lop
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
	line(250, 350, 250, 750);
	line(360, 350, 360, 750);
	line(740, 350, 740, 750);
	line(870, 350, 870, 750);

	setbkcolor(15);
	setcolor(1);
	settextstyle(10, 0, 3);
	outtextxy(115, 360, (char*)"MA SV");

	setbkcolor(15);
	setcolor(1);
	settextstyle(10, 0, 3);
	outtextxy(280, 360, (char*)"PHAI");

	setbkcolor(15);
	setcolor(1);
	settextstyle(10, 0, 3);
	outtextxy(540, 360, (char*)"HO");

	setbkcolor(15);
	setcolor(1);
	settextstyle(10, 0, 3);
	outtextxy(785, 360, (char*)"TEN");

	setbkcolor(15);
	setcolor(1);
	settextstyle(10, 0, 3);
	outtextxy(920, 360, (char*)"MAT KHAU");
}
void Quan_ly_sinh_vien_Hien_thi_danh_sach_lop() {
	// Set mau background
	setbkcolor(7);
	cleardevice();

	// Chu tieu de
	setcolor(0);
	settextstyle(10, 0, 6);
	outtextxy(530, 10, (char*)"QUAN LY SINH VIEN");

	// Khung hien thi danh sach Lop
	Khung_hien_thi_danh_sach_lop_graphic();


	// Khung chuc nang
	setfillstyle(1, 15);
	bar(50, 80, 1080, 320);

	setcolor(0);
	rectangle(50, 80, 1080, 320);

	// Nut chuc nang TRUY CAP
	setfillstyle(1, 9);
	bar(480, 260, 650, 310);
	setcolor(0);
	rectangle(480, 260, 650, 310);

	setbkcolor(9);
	setcolor(0);
	settextstyle(10, 0, 3);
	outtextxy(510, 275, (char*)"TRUY CAP");



	// Khung thong bao
	setfillstyle(1, 15);
	bar(1110, 80, 1500, 750);
	setcolor(0);
	rectangle(1110, 80, 1500, 750);
	line(1110, 140, 1500, 140);

	setbkcolor(15);
	setcolor(4);
	settextstyle(10, 0, 3);
	outtextxy(1240, 100, (char*)"THONG BAO");

	// Nut chuyen trang
	setfillstyle(1, 9);
	bar(250, 770, 420, 820);
	setcolor(0);
	rectangle(250, 770, 420, 820);

	setfillstyle(1, 9);
	bar(700, 770, 870, 820);
	setcolor(0);
	rectangle(700, 770, 870, 820);

	setbkcolor(9);
	setcolor(0);
	settextstyle(10, 0, 3);
	outtextxy(320, 785, (char*)"<=");

	setbkcolor(9);
	setcolor(0);
	settextstyle(10, 0, 3);
	outtextxy(770, 785, (char*)"=>");

	//// Khu vuc dien thong tin MA SINH VIEN | HO TEN | MAT KHAU
	//setfillstyle(1, 11);
	//bar(200, 120, 600, 160);
	//setcolor(0);
	//rectangle(200, 120, 600, 160);

	//setfillstyle(1, 11);
	//bar(200, 180, 600, 220);
	//setcolor(0);
	//rectangle(200, 180, 600, 220);

	//setfillstyle(1, 11);
	//bar(800, 180, 1050, 220);
	//setcolor(0);
	//rectangle(800, 180, 1050, 220);

	//// Chon gioi tinh NAM NU

	//setfillstyle(1, 10);
	//bar(700, 110, 850, 160);
	//setcolor(0);
	//rectangle(700, 110, 850, 160);

	//setfillstyle(1, 10);
	//bar(900, 110, 1050, 160);
	//setcolor(0);
	//rectangle(900, 110, 1050, 160);

	//setbkcolor(15);
	//setcolor(0);
	//settextstyle(10, 0, 2);
	//outtextxy(130, 130, (char*)"MA SV");

	//setbkcolor(15);
	//setcolor(0);
	//settextstyle(10, 0, 2);
	//outtextxy(120, 190, (char*)"HO TEN");

	//setbkcolor(15);
	//setcolor(0);
	//settextstyle(10, 0, 2);
	//outtextxy(670, 190, (char*)"MAT KHAU");

	//setbkcolor(10);
	//setcolor(0);
	//settextstyle(10, 0, 3);
	//outtextxy(755, 125, (char*)"NAM");

	//setbkcolor(10);
	//setcolor(0);
	//settextstyle(10, 0, 3);
	//outtextxy(965, 125, (char*)"NU");

	// nut THOAT
	setfillstyle(1, 10);
	bar(1200, 770, 1370, 820);
	setcolor(0);
	rectangle(1200, 770, 1370, 820);

	setbkcolor(10);
	setcolor(0);
	settextstyle(10, 0, 3);
	outtextxy(1250, 785, (char*)"THOAT");
}
void Khu_vuc_Nhap_thong_tin_sinh_vien() {

	// Khung chuc nang
	setfillstyle(1, 15);
	bar(50, 80, 1080, 320);

	setcolor(0);
	rectangle(50, 80, 1080, 320);

	// Khu vuc dien thong tin MA SINH VIEN | HO TEN | MAT KHAU
	setfillstyle(1, 11);
	bar(200, 90, 600, 130);
	setcolor(0);
	rectangle(200, 90, 600, 130);

	setfillstyle(1, 11);
	bar(200, 150, 600, 190);
	setcolor(0);
	rectangle(200, 150, 600, 190);

	setfillstyle(1, 11);
	bar(200, 210, 600, 250);
	setcolor(0);
	rectangle(200, 210, 600, 250);

	setfillstyle(1, 11);
	bar(800, 180, 1050, 220);
	setcolor(0);
	rectangle(800, 180, 1050, 220);

	// Chon gioi tinh NAM NU

	setfillstyle(1, 10);
	bar(700, 110, 850, 160);
	setcolor(0);
	rectangle(700, 110, 850, 160);

	setfillstyle(1, 10);
	bar(900, 110, 1050, 160);
	setcolor(0);
	rectangle(900, 110, 1050, 160);

	setbkcolor(15);
	setcolor(0);
	settextstyle(10, 0, 2);
	outtextxy(120, 100, (char*)"MA SV");

	setbkcolor(15);
	setcolor(0);
	settextstyle(10, 0, 2);
	outtextxy(150, 160, (char*)"HO");

	setbkcolor(15);
	setcolor(0);
	settextstyle(10, 0, 2);
	outtextxy(140, 220, (char*)"TEN");

	setbkcolor(15);
	setcolor(0);
	settextstyle(10, 0, 2);
	outtextxy(670, 190, (char*)"MAT KHAU");

	setbkcolor(10);
	setcolor(0);
	settextstyle(10, 0, 3);
	outtextxy(755, 125, (char*)"NAM");

	setbkcolor(10);
	setcolor(0);
	settextstyle(10, 0, 3);
	outtextxy(965, 125, (char*)"NU");

	setfillstyle(1, 9);
	bar(470, 310, 640, 260);
	setcolor(0);
	rectangle(470, 310, 640, 260);


	setbkcolor(9);
	setcolor(0);
	settextstyle(10, 0, 3);
	outtextxy(530, 275, (char*)"THEM");
}
void Khu_vuc_Sua_thong_tin_sinh_vien() {

	// Khung chuc nang
	setfillstyle(1, 15);
	bar(50, 80, 1080, 320);

	setcolor(0);
	rectangle(50, 80, 1080, 320);

	// Khu vuc dien thong tin MA SINH VIEN | HO TEN | MAT KHAU
	setfillstyle(1, 11);
	bar(200, 90, 600, 130);
	setcolor(0);
	rectangle(200, 90, 600, 130);

	setfillstyle(1, 11);
	bar(200, 150, 600, 190);
	setcolor(0);
	rectangle(200, 150, 600, 190);

	setfillstyle(1, 11);
	bar(200, 210, 600, 250);
	setcolor(0);
	rectangle(200, 210, 600, 250);

	setfillstyle(1, 11);
	bar(800, 180, 1050, 220);
	setcolor(0);
	rectangle(800, 180, 1050, 220);

	// Chon gioi tinh NAM NU

	setfillstyle(1, 10);
	bar(700, 110, 850, 160);
	setcolor(0);
	rectangle(700, 110, 850, 160);

	setfillstyle(1, 10);
	bar(900, 110, 1050, 160);
	setcolor(0);
	rectangle(900, 110, 1050, 160);

	setbkcolor(15);
	setcolor(0);
	settextstyle(10, 0, 2);
	outtextxy(120, 100, (char*)"MA SV");

	setbkcolor(15);
	setcolor(0);
	settextstyle(10, 0, 2);
	outtextxy(150, 160, (char*)"HO");

	setbkcolor(15);
	setcolor(0);
	settextstyle(10, 0, 2);
	outtextxy(140, 220, (char*)"TEN");

	setbkcolor(15);
	setcolor(0);
	settextstyle(10, 0, 2);
	outtextxy(670, 190, (char*)"MAT KHAU");

	setbkcolor(10);
	setcolor(0);
	settextstyle(10, 0, 3);
	outtextxy(755, 125, (char*)"NAM");

	setbkcolor(10);
	setcolor(0);
	settextstyle(10, 0, 3);
	outtextxy(965, 125, (char*)"NU");

	setfillstyle(1, 9);
	bar(470, 310, 640, 260);
	setcolor(0);
	rectangle(470, 310, 640, 260);


	setbkcolor(9);
	setcolor(0);
	settextstyle(10, 0, 3);
	outtextxy(530, 275, (char*)"SUA");
}
void Khu_vuc_nhap_ma_de_Sua_thong_tin_sinh_vien() {
	// Khung chuc nang
	setfillstyle(1, 15);
	bar(50, 80, 1080, 320);

	setcolor(0);
	rectangle(50, 80, 1080, 320);

	setfillstyle(1, 11);
	bar(400, 150, 800, 190);
	setcolor(0);
	rectangle(400, 150, 800, 190);

	setbkcolor(15);
	setcolor(0);
	settextstyle(10, 0, 2);
	outtextxy(230, 160, (char*)"MA SINH VIEN");

	setfillstyle(1, 9);
	bar(470, 310, 640, 260);
	setcolor(0);
	rectangle(470, 310, 640, 260);

	setbkcolor(9);
	setcolor(0);
	settextstyle(10, 0, 3);
	outtextxy(535, 275, (char*)"SUA");
}
void Khu_vuc_Xoa_thong_tin_sinh_vien() {
	// Khung chuc nang
	setfillstyle(1, 15);
	bar(50, 80, 1080, 320);

	setcolor(0);
	rectangle(50, 80, 1080, 320);

	setfillstyle(1, 11);
	bar(400, 150, 800, 190);
	setcolor(0);
	rectangle(400, 150, 800, 190);

	setbkcolor(15);
	setcolor(0);
	settextstyle(10, 0, 2);
	outtextxy(230, 160, (char*)"MA SINH VIEN");

	setfillstyle(1, 9);
	bar(470, 310, 640, 260);
	setcolor(0);
	rectangle(470, 310, 640, 260);

	setbkcolor(9);
	setcolor(0);
	settextstyle(10, 0, 3);
	outtextxy(535, 275, (char*)"XOA");
}
void Hien_thi_chuc_nang_sinh_vien() {

	// Khung chuc nang
	setfillstyle(1, 15);
	bar(50, 80, 1080, 320);

	setcolor(0);
	rectangle(50, 80, 1080, 320);


	// Nut chuc nang THEM SUA XOA
	setfillstyle(1, 9);
	bar(250, 310, 420, 260);
	setcolor(0);
	rectangle(250, 310, 420, 260);

	setfillstyle(1, 9);
	bar(470, 310, 640, 260);
	setcolor(0);
	rectangle(470, 310, 640, 260);

	setfillstyle(1, 9);
	bar(690, 310, 860, 260);
	setcolor(0);
	rectangle(690, 310, 860, 260);

	setbkcolor(9);
	setcolor(0);
	settextstyle(10, 0, 3);
	outtextxy(310, 275, (char*)"THEM");

	setbkcolor(9);
	setcolor(0);
	settextstyle(10, 0, 3);
	outtextxy(535, 275, (char*)"SUA");

	setbkcolor(9);
	setcolor(0);
	settextstyle(10, 0, 3);
	outtextxy(755, 275, (char*)"XOA");
}
void Hien_thi_thong_tin_LOP_HOC_dang_duoc_truy_cap() {
	setbkcolor(15);
	setcolor(4);
	settextstyle(10, 0, 3);
	// 185 220
	outtextxy(1190, 385, (char*)"MA LOP: ");
	setcolor(1);
	outtextxy(1285, 420, (char*)"TEN LOP: ");
}

void Quan_ly_mon_hoc() {
	// Set mau background
	setbkcolor(7);
	cleardevice();

	// Chu tieu de
	setcolor(0);
	settextstyle(10, 0, 6);
	outtextxy(530, 10, (char*)"QUAN LY MON HOC");

	// Khung hien thi danh sach Mon
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
	line(400, 350, 400, 750);

	setbkcolor(15);
	setcolor(1);
	settextstyle(10, 0, 3);
	outtextxy(190, 360, (char*)"MA MON");

	setbkcolor(15);
	setcolor(1);
	settextstyle(10, 0, 3);
	outtextxy(700, 360, (char*)"TEN MON");

	// Khung chuc nang
	setfillstyle(1, 15);
	bar(50, 80, 1080, 320);

	setcolor(0);
	rectangle(50, 80, 1080, 320);

	// Nut chuc nang THEM SUA XOA
	setfillstyle(1, 9);
	bar(250, 310, 420, 260);
	setcolor(0);
	rectangle(250, 260, 420, 310);

	setfillstyle(1, 9);
	bar(470, 310, 640, 260);
	setcolor(0);
	rectangle(470, 260, 640, 310);

	setfillstyle(1, 9);
	bar(690, 310, 860, 260);
	setcolor(0);
	rectangle(690, 260, 860, 310);

	setbkcolor(9);
	setcolor(0);
	settextstyle(10, 0, 3);
	outtextxy(310, 275, (char*)"THEM");

	setbkcolor(9);
	setcolor(0);
	settextstyle(10, 0, 3);
	outtextxy(535, 275, (char*)"SUA");

	setbkcolor(9);
	setcolor(0);
	settextstyle(10, 0, 3);
	outtextxy(755, 275, (char*)"XOA");

	// Khung thong bao
	setfillstyle(1, 15);
	bar(1110, 80, 1500, 750);
	setcolor(0);
	rectangle(1110, 80, 1500, 750);
	line(1110, 140, 1500, 140);

	setbkcolor(15);
	setcolor(4);
	settextstyle(10, 0, 3);
	outtextxy(1240, 100, (char*)"THONG BAO");

	// Nut chuyen trang
	setfillstyle(1, 9);
	bar(250, 770, 420, 820);
	setcolor(0);
	rectangle(250, 770, 420, 820);

	setfillstyle(1, 9);
	bar(700, 770, 870, 820);
	setcolor(0);
	rectangle(700, 770, 870, 820);

	setbkcolor(9);
	setcolor(0);
	settextstyle(10, 0, 3);
	outtextxy(320, 785, (char*)"<=");

	setbkcolor(9);
	setcolor(0);
	settextstyle(10, 0, 3);
	outtextxy(775, 785, (char*)"=>");

	//// Khu vuc dien thong tin
	//setfillstyle(1, 11);
	//bar(400, 120, 900, 160);
	//setcolor(0);
	//rectangle(400, 120, 900, 160);

	//setfillstyle(1, 11);
	//bar(400, 180, 900, 220);
	//setcolor(0);
	//rectangle(400, 180, 900, 220);

	//setbkcolor(15);
	//setcolor(0);
	//settextstyle(10, 0, 2);
	//outtextxy(280, 130, (char*)"MA MON");

	//setbkcolor(15);
	//setcolor(0);
	//settextstyle(10, 0, 2);
	//outtextxy(270, 190, (char*)"TEN MON");

	// nut THOAT
	setfillstyle(1, 10);
	bar(1200, 770, 1370, 820);
	setcolor(0);
	rectangle(1200, 770, 1370, 820);

	setbkcolor(10);
	setcolor(0);
	settextstyle(10, 0, 3);
	outtextxy(1250, 785, (char*)"THOAT");

}
void BangDanhSachMonHoc() {
	// Khung hien thi danh sach Mon
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
	line(400, 350, 400, 750);

	setbkcolor(15);
	setcolor(1);
	settextstyle(10, 0, 3);
	outtextxy(190, 360, (char*)"MA MON");

	setbkcolor(15);
	setcolor(1);
	settextstyle(10, 0, 3);
	outtextxy(700, 360, (char*)"TEN MON");
}
void Nhap_thong_tin_mon_hoc() {

	// Khung chuc nang
	setfillstyle(1, 15);
	bar(50, 80, 1080, 320);

	setcolor(0);
	rectangle(50, 80, 1080, 320);

	// Khu vuc dien thong tin
	setfillstyle(1, 11);
	bar(350, 120, 700, 160);
	setcolor(0);
	rectangle(350, 120, 700, 160);

	setfillstyle(1, 11);
	bar(350, 180, 980, 220);
	setcolor(0);
	rectangle(350, 180, 980, 220);

	setbkcolor(15);
	setcolor(0);
	settextstyle(10, 0, 2);
	outtextxy(230, 130, (char*)"MA MON");

	setbkcolor(15);
	setcolor(0);
	settextstyle(10, 0, 2);
	outtextxy(220, 190, (char*)"TEN MON");

	setfillstyle(1, 9);
	bar(470, 310, 640, 260);
	setcolor(0);
	rectangle(470, 260, 640, 310);


	setbkcolor(9);
	setcolor(0);
	settextstyle(10, 0, 3);
	outtextxy(530, 275, (char*)"THEM");
}
void Xoa_thong_tin_mon_hoc() {

	// Khung chuc nang
	setfillstyle(1, 15);
	bar(50, 80, 1080, 320);

	setcolor(0);
	rectangle(50, 80, 1080, 320);

	// Khu vuc dien MA MON
	setfillstyle(1, 11);
	bar(350, 120, 700, 160);
	setcolor(0);
	rectangle(350, 120, 700, 160);

	setbkcolor(15);
	setcolor(0);
	settextstyle(10, 0, 2);
	outtextxy(230, 130, (char*)"MA MON");

	setfillstyle(1, 9);
	bar(470, 310, 640, 260);
	setcolor(0);
	rectangle(470, 260, 640, 310);

	setbkcolor(9);
	setcolor(0);
	settextstyle(10, 0, 3);
	outtextxy(530, 275, (char*)"XOA");
}
void Sua_thong_tin_mon_hoc() {

	// Khung chuc nang
	setfillstyle(1, 15);
	bar(50, 80, 1080, 320);

	setcolor(0);
	rectangle(50, 80, 1080, 320);

	// Khu vuc dien MA MON
	setfillstyle(1, 11);
	bar(350, 120, 700, 160);
	setcolor(0);
	rectangle(350, 120, 700, 160);

	setbkcolor(15);
	setcolor(0);
	settextstyle(10, 0, 2);
	outtextxy(230, 130, (char*)"MA MON");

	setfillstyle(1, 9);
	bar(470, 310, 640, 260);
	setcolor(0);
	rectangle(470, 260, 640, 310);

	setbkcolor(9);
	setcolor(0);
	settextstyle(10, 0, 3);
	outtextxy(530, 275, (char*)"SUA");
}
void Khu_vuc_Sua_thong_tin_mon_hoc() {

	// Khung chuc nang
	setfillstyle(1, 15);
	bar(50, 80, 1080, 320);

	setcolor(0);
	rectangle(50, 80, 1080, 320);

	// Khu vuc dien thong tin
	setfillstyle(1, 11);
	bar(350, 120, 700, 160);
	setcolor(0);
	rectangle(350, 120, 700, 160);

	setfillstyle(1, 11);
	bar(350, 180, 980, 220);
	setcolor(0);
	rectangle(350, 180, 980, 220);

	setbkcolor(15);
	setcolor(0);
	settextstyle(10, 0, 2);
	outtextxy(230, 130, (char*)"MA MON");

	setbkcolor(15);
	setcolor(0);
	settextstyle(10, 0, 2);
	outtextxy(220, 190, (char*)"TEN MON");

	setfillstyle(1, 9);
	bar(470, 310, 640, 260);
	setcolor(0);
	rectangle(470, 260, 640, 310);

	setbkcolor(9);
	setcolor(0);
	settextstyle(10, 0, 3);
	outtextxy(530, 275, (char*)"SUA");
}

void Quan_ly_cau_hoi() {
	// Set mau background
	setbkcolor(7);
	cleardevice();

	// Chu tieu de
	setcolor(0);
	settextstyle(10, 0, 6);
	outtextxy(530, 10, (char*)"QUAN LY CAU HOI");

	// Khung hien thi danh sach CAU HOI
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
	line(150, 350, 150, 750);
	line(280, 350, 280, 750);

	setbkcolor(15);
	setcolor(1);
	settextstyle(10, 0, 3);
	outtextxy(85, 360, (char*)"ID");

	setbkcolor(15);
	setcolor(1);
	settextstyle(10, 0, 3);
	outtextxy(175, 360, (char*)"MA MON");

	setbkcolor(15);
	setcolor(1);
	settextstyle(10, 0, 3);
	outtextxy(620, 360, (char*)"NOI DUNG");

	// Khung chuc nang
	setfillstyle(1, 15);
	bar(50, 80, 1080, 320);

	setcolor(0);
	rectangle(50, 80, 1080, 320);

	// Nut chuc nang THEM SUA XOA
	setfillstyle(1, 9);
	bar(250, 310, 420, 260);
	setcolor(0);
	rectangle(250, 310, 420, 260);

	setfillstyle(1, 9);
	bar(470, 310, 640, 260);
	setcolor(0);
	rectangle(470, 310, 640, 260);

	setfillstyle(1, 9);
	bar(690, 310, 860, 260);
	setcolor(0);
	rectangle(690, 310, 860, 260);

	setbkcolor(9);
	setcolor(0);
	settextstyle(10, 0, 3);
	outtextxy(310, 275, (char*)"THEM");

	setbkcolor(9);
	setcolor(0);
	settextstyle(10, 0, 3);
	outtextxy(535, 275, (char*)"SUA");

	setbkcolor(9);
	setcolor(0);
	settextstyle(10, 0, 3);
	outtextxy(755, 275, (char*)"XOA");

	// Khung thong bao
	setfillstyle(1, 15);
	bar(1110, 80, 1500, 750);
	setcolor(0);
	rectangle(1110, 80, 1500, 750);
	line(1110, 140, 1500, 140);

	setbkcolor(15);
	setcolor(4);
	settextstyle(10, 0, 3);
	outtextxy(1240, 100, (char*)"THONG BAO");

	// Nut chuyen trang
	setfillstyle(1, 9);
	bar(250, 770, 420, 820);
	setcolor(0);
	rectangle(250, 770, 420, 820);

	setfillstyle(1, 9);
	bar(700, 770, 870, 820);
	setcolor(0);
	rectangle(700, 770, 870, 820);

	setbkcolor(9);
	setcolor(0);
	settextstyle(10, 0, 3);
	outtextxy(320, 785, (char*)"<=");

	setbkcolor(9);
	setcolor(0);
	settextstyle(10, 0, 3);
	outtextxy(775, 785, (char*)"=>");

	// nut THOAT
	setfillstyle(1, 10);
	bar(1200, 770, 1370, 820);
	setcolor(0);
	rectangle(1200, 770, 1370, 820);

	setbkcolor(10);
	setcolor(0);
	settextstyle(10, 0, 3);
	outtextxy(1245, 785, (char*)"THOAT");

}
void BangDanhSachCauHoi() {
	// Khung hien thi danh sach CAU HOI
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
	line(150, 350, 150, 750);
	line(280, 350, 280, 750);

	setbkcolor(15);
	setcolor(1);
	settextstyle(10, 0, 3);
	outtextxy(85, 360, (char*)"ID");

	setbkcolor(15);
	setcolor(1);
	settextstyle(10, 0, 3);
	outtextxy(175, 360, (char*)"MA MON");

	setbkcolor(15);
	setcolor(1);
	settextstyle(10, 0, 3);
	outtextxy(620, 360, (char*)"NOI DUNG");
}
void Quan_ly_cau_hoi_Hien_thi_danh_sach_MON() {
	// Set mau background
	setbkcolor(7);
	cleardevice();

	// Chu tieu de
	setcolor(0);
	settextstyle(10, 0, 6);
	outtextxy(530, 10, (char*)"QUAN LY CAU HOI");

	// Khung hien thi danh sach MON
	BangDanhSachMonHoc();

	// Khung chuc nang
	setfillstyle(1, 15);
	bar(50, 80, 1080, 320);

	setcolor(0);
	rectangle(50, 80, 1080, 320);

	// Nut chuc nang TRUY CAP
	setfillstyle(1, 9);
	bar(480, 260, 650, 310);
	setcolor(0);
	rectangle(480, 260, 650, 310);

	setbkcolor(9);
	setcolor(0);
	settextstyle(10, 0, 3);
	outtextxy(510, 275, (char*)"TRUY CAP");

	// Khung thong bao
	setfillstyle(1, 15);
	bar(1110, 80, 1500, 750);
	setcolor(0);
	rectangle(1110, 80, 1500, 750);
	line(1110, 140, 1500, 140);

	setbkcolor(15);
	setcolor(4);
	settextstyle(10, 0, 3);
	outtextxy(1240, 100, (char*)"THONG BAO");

	// Nut chuyen trang
	setfillstyle(1, 9);
	bar(250, 770, 420, 820);
	setcolor(0);
	rectangle(250, 770, 420, 820);

	setfillstyle(1, 9);
	bar(700, 770, 870, 820);
	setcolor(0);
	rectangle(700, 770, 870, 820);

	setbkcolor(9);
	setcolor(0);
	settextstyle(10, 0, 3);
	outtextxy(320, 785, (char*)"<=");

	setbkcolor(9);
	setcolor(0);
	settextstyle(10, 0, 3);
	outtextxy(770, 785, (char*)"=>");

	// nut THOAT
	setfillstyle(1, 10);
	bar(1200, 770, 1370, 820);
	setcolor(0);
	rectangle(1200, 770, 1370, 820);

	setbkcolor(10);
	setcolor(0);
	settextstyle(10, 0, 3);
	outtextxy(1250, 785, (char*)"THOAT");

	// Khu vuc dien MA MON
	setfillstyle(1, 11);
	bar(350, 120, 700, 160);
	setcolor(0);
	rectangle(350, 120, 700, 160);

	setbkcolor(15);
	setcolor(0);
	settextstyle(10, 0, 2);
	outtextxy(230, 130, (char*)"MA MON");
}
void Khu_vuc_nhap_MA_MONHOC() {
	// Khu vuc dien MA MON
	setfillstyle(1, 11);
	bar(350, 120, 700, 160);
	setcolor(0);
	rectangle(350, 120, 700, 160);

	setbkcolor(15);
	setcolor(0);
	settextstyle(10, 0, 2);
	outtextxy(230, 130, (char*)"MA MON");
}
void Xoa_khu_vuc_dien_MA_MONHOC_va_THONG_BAO() {
	// Khung chuc nang
	setfillstyle(1, 15);
	bar(50, 80, 1080, 320);

	setcolor(0);
	rectangle(50, 80, 1080, 320);

	// Nut chuc nang TRUY CAP
	setfillstyle(1, 9);
	bar(480, 260, 650, 310);
	setcolor(0);
	rectangle(480, 260, 650, 310);

	setbkcolor(9);
	setcolor(0);
	settextstyle(10, 0, 3);
	outtextxy(510, 275, (char*)"TRUY CAP");

	setfillstyle(1, 15);
	bar(1110, 80, 1500, 380);
	setcolor(0);
	rectangle(1110, 80, 1500, 750);
	line(1110, 140, 1500, 140);

	setbkcolor(15);
	setcolor(4);
	settextstyle(10, 0, 3);
	outtextxy(1240, 100, (char*)"THONG BAO");
}
void Nhap_cau_hoi_thi() {
	// Set mau background
	setbkcolor(7);
	cleardevice();

	// Chu tieu de
	setcolor(0);
	settextstyle(10, 0, 6);
	outtextxy(530, 10, (char*)"QUAN LY CAU HOI");

	// Khung THEM CAU HOI
	setfillstyle(1, 15);
	bar(50, 80, 1080, 750);
	setcolor(0);
	rectangle(50, 80, 1080, 750);

	setfillstyle(1, 11);
	bar(205, 120, 1070, 220);
	setcolor(0);
	rectangle(205, 120, 1070, 220);

	setfillstyle(1, 11);
	bar(250, 280, 1000, 370);
	setcolor(0);
	rectangle(250, 280, 1000, 370);

	setfillstyle(1, 11);
	bar(250, 400, 1000, 490);
	setcolor(0);
	rectangle(250, 400, 1000, 490);

	setfillstyle(1, 11);
	bar(250, 520, 1000, 610);
	setcolor(0);
	rectangle(250, 520, 1000, 610);

	setfillstyle(1, 11);
	bar(250, 640, 1000, 730);
	setcolor(0);
	rectangle(250, 640, 1000, 730);

	setbkcolor(15);
	setcolor(0);
	settextstyle(10, 0, 2);
	outtextxy(100, 160, (char*)"NOI DUNG");

	setbkcolor(15);
	setcolor(0);
	settextstyle(10, 0, 2);
	outtextxy(150, 315, (char*)"CAU A");

	setbkcolor(15);
	setcolor(0);
	settextstyle(10, 0, 2);
	outtextxy(150, 435, (char*)"CAU B");

	setbkcolor(15);
	setcolor(0);
	settextstyle(10, 0, 2);
	outtextxy(150, 555, (char*)"CAU C");

	setbkcolor(15);
	setcolor(0);
	settextstyle(10, 0, 2);
	outtextxy(150, 670, (char*)"CAU D");

	circle(100, 325, 15);
	circle(100, 444, 15);
	circle(100, 563, 15);
	circle(100, 682, 15);

	// Khung thong bao
	setfillstyle(1, 15);
	bar(1110, 80, 1500, 750);
	setcolor(0);
	rectangle(1110, 80, 1500, 750);
	line(1110, 140, 1500, 140);

	setbkcolor(15);
	setcolor(4);
	settextstyle(10, 0, 3);
	outtextxy(1240, 100, (char*)"THONG BAO");

	// Nut THEM
	setfillstyle(1, 10);
	bar(480, 770, 650, 820);
	setcolor(0);
	rectangle(480, 770, 650, 820);

	setbkcolor(10);
	setcolor(0);
	settextstyle(10, 0, 3);
	outtextxy(535, 785, (char*)"THEM");

	// nut THOAT
	setfillstyle(1, 10);
	bar(1200, 770, 1370, 820);
	setcolor(0);
	rectangle(1200, 770, 1370, 820);

	setbkcolor(10);
	setcolor(0);
	settextstyle(10, 0, 3);
	outtextxy(1250, 785, (char*)"THOAT");
}

void Thi_trac_nghiem_ChonMonHoc() {
	// Set mau background
	setbkcolor(7);
	cleardevice();

	// Chu tieu de
	setcolor(0);
	settextstyle(10, 0, 6);
	outtextxy(530, 10, (char*)"THI TRAC NGHIEM");

	// Khung hien thi danh sach lop
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
	line(400, 350, 400, 750);

	setbkcolor(15);
	setcolor(1);
	settextstyle(10, 0, 3);
	outtextxy(190, 360, (char*)"MA MON");

	setbkcolor(15);
	setcolor(1);
	settextstyle(10, 0, 3);
	outtextxy(700, 360, (char*)"TEN MON");

	// Khung chuc nang
	setfillstyle(1, 15);
	bar(50, 80, 1080, 320);
	setcolor(0);
	rectangle(50, 80, 1080, 320);

	setbkcolor(15);
	setcolor(1);
	settextstyle(10, 0, 3);
	outtextxy(500, 90, (char*)"CHON MON THI");

	// Dien thong tin MonHoc can thi
	setfillstyle(1, 11);
	bar(350, 190, 500, 230);
	setcolor(0);
	rectangle(350, 190, 500, 230);

	setbkcolor(15);
	setcolor(0);
	settextstyle(10, 0, 2);
	outtextxy(230, 200, (char*)"MA MON");


	setfillstyle(1, 11);
	bar(850, 190, 950, 230);
	setcolor(0);
	rectangle(850, 190, 950, 230);

	setbkcolor(15);
	setcolor(0);
	settextstyle(10, 0, 2);
	outtextxy(600, 200, (char*)"THOI GIAN (PHUT)");


	setfillstyle(1, 11);
	bar(850, 140, 950, 180);
	setcolor(0);
	rectangle(850, 140, 950, 180);

	setbkcolor(15);
	setcolor(0);
	settextstyle(10, 0, 2);
	outtextxy(665, 150, (char*)"SO CAU HOI");


	// Khung thong bao
	setfillstyle(1, 15);
	bar(1110, 80, 1500, 750);
	setcolor(0);
	rectangle(1110, 80, 1500, 750);
	line(1110, 140, 1500, 140);

	setbkcolor(15);
	setcolor(4);
	settextstyle(10, 0, 3);
	outtextxy(1240, 100, (char*)"THONG BAO");

	// Nut chuyen trang
	setfillstyle(1, 9);
	bar(250, 770, 420, 820);
	setcolor(0);
	rectangle(250, 770, 420, 820);

	setfillstyle(1, 9);
	bar(700, 770, 870, 820);
	setcolor(0);
	rectangle(700, 770, 870, 820);

	setbkcolor(9);
	setcolor(0);
	settextstyle(10, 0, 3);
	outtextxy(320, 785, (char*)"<=");

	setbkcolor(9);
	setcolor(0);
	settextstyle(10, 0, 3);
	outtextxy(775, 785, (char*)"=>");


	// Nut THI
	setfillstyle(1, 9);
	bar(400, 310, 570, 260);
	setcolor(0);
	rectangle(400, 260, 570, 310);

	setbkcolor(9);
	setcolor(0);
	settextstyle(10, 0, 3);
	outtextxy(465, 275, (char*)"THI");

	// Nut XEM DIEM
	setfillstyle(1, 9);
	bar(590, 310, 760, 260);
	setcolor(0);
	rectangle(590, 260, 760, 310);

	setbkcolor(9);
	setcolor(0);
	settextstyle(10, 0, 3);
	outtextxy(620, 275, (char*)"XEM DIEM");

	// nut THOAT
	setfillstyle(1, 10);
	bar(1200, 770, 1370, 820);
	setcolor(0);
	rectangle(1200, 770, 1370, 820);

	setbkcolor(10);
	setcolor(0);
	settextstyle(10, 0, 3);
	outtextxy(1250, 785, (char*)"THOAT");

}
void Xem_Diem_Sinh_Vien_graphic() {
	// Set mau background
	setbkcolor(7);
	cleardevice();

	// Chu tieu de
	setcolor(0);
	settextstyle(10, 0, 6);
	outtextxy(530, 10, (char*)"THI TRAC NGHIEM");

	// Khung hien thi danh sach lop
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
	line(400, 350, 400, 750);

	setbkcolor(15);
	setcolor(1);
	settextstyle(10, 0, 3);
	outtextxy(190, 360, (char*)"MA MON");

	setbkcolor(15);
	setcolor(1);
	settextstyle(10, 0, 3);
	outtextxy(700, 360, (char*)"TEN MON");

	// Khung chuc nang
	setfillstyle(1, 15);
	bar(50, 80, 1080, 320);
	setcolor(0);
	rectangle(50, 80, 1080, 320);

	setfillstyle(1, 11);
	bar(350, 120, 700, 160);
	setcolor(0);
	rectangle(350, 120, 700, 160);

	setbkcolor(15);
	setcolor(0);
	settextstyle(10, 0, 2);
	outtextxy(230, 130, (char*)"MA MON");

	// Nut XEM
	setfillstyle(1, 9);
	bar(470, 310, 640, 260);
	setcolor(0);
	rectangle(470, 260, 640, 310);

	setbkcolor(9);
	setcolor(0);
	settextstyle(10, 0, 3);
	outtextxy(535, 275, (char*)"XEM");

	// Khung thong bao
	setfillstyle(1, 15);
	bar(1110, 80, 1500, 750);
	setcolor(0);
	rectangle(1110, 80, 1500, 750);
	line(1110, 140, 1500, 140);

	setbkcolor(15);
	setcolor(4);
	settextstyle(10, 0, 3);
	outtextxy(1240, 100, (char*)"THONG BAO");

	// Nut chuyen trang
	setfillstyle(1, 9);
	bar(250, 770, 420, 820);
	setcolor(0);
	rectangle(250, 770, 420, 820);

	setfillstyle(1, 9);
	bar(700, 770, 870, 820);
	setcolor(0);
	rectangle(700, 770, 870, 820);

	setbkcolor(9);
	setcolor(0);
	settextstyle(10, 0, 3);
	outtextxy(320, 785, (char*)"<=");

	setbkcolor(9);
	setcolor(0);
	settextstyle(10, 0, 3);
	outtextxy(775, 785, (char*)"=>");


	// nut THOAT
	setfillstyle(1, 10);
	bar(1200, 770, 1370, 820);
	setcolor(0);
	rectangle(1200, 770, 1370, 820);

	setbkcolor(10);
	setcolor(0);
	settextstyle(10, 0, 3);
	outtextxy(1250, 785, (char*)"THOAT");

}
void TienHanhThi_graphic() {
	// Set mau background
	setbkcolor(7);
	cleardevice();

	// Chu tieu de
	setcolor(0);
	settextstyle(10, 0, 6);
	outtextxy(530, 10, (char*)"THI TRAC NGHIEM");

	// Khung CAU HOI
	setfillstyle(1, 15);
	bar(50, 80, 1080, 280);
	setcolor(0);
	rectangle(50, 80, 1080, 280);

	// Khung DAP AN
	setfillstyle(1, 15);
	bar(50, 310, 1080, 750);
	setcolor(0);
	rectangle(50, 310, 1080, 750);

	setbkcolor(15);
	setcolor(0);
	settextstyle(10, 0, 2);
	outtextxy(520, 100, (char*)"CAU HOI");

	setbkcolor(15);
	setcolor(0);
	settextstyle(10, 0, 2);
	outtextxy(150, 360, (char*)"A");

	setbkcolor(15);
	setcolor(0);
	settextstyle(10, 0, 2);
	outtextxy(150, 460, (char*)"B");

	setbkcolor(15);
	setcolor(0);
	settextstyle(10, 0, 2);
	outtextxy(150, 560, (char*)"C");

	setbkcolor(15);
	setcolor(0);
	settextstyle(10, 0, 2);
	outtextxy(150, 660, (char*)"D");

	circle(100, 370, 15);
	circle(100, 470, 15);
	circle(100, 570, 15);
	circle(100, 670, 15);


	setfillstyle(1, 15);
	bar(1110, 80, 1500, 330);
	setcolor(0);
	rectangle(1110, 80, 1500, 330);

	line(1305, 80, 1305, 330);
	line(1110, 130, 1500, 130);
	line(1110, 180, 1500, 180);
	line(1110, 230, 1500, 230);
	line(1110, 280, 1500, 280);
	line(1110, 330, 1500, 330);

	// Khung thong bao
	setfillstyle(1, 15);
	bar(1110, 360, 1500, 750);
	setcolor(0);
	rectangle(1110, 360, 1500, 750);

	// Nut NOP BAI
	setfillstyle(1, 10);
	bar(480, 770, 650, 820);
	setcolor(0);
	rectangle(480, 770, 650, 820);

	setbkcolor(10);
	setcolor(0);
	settextstyle(10, 0, 3);
	outtextxy(520, 785, (char*)"NOP BAI");

	// Nut chuyen trang
	setfillstyle(1, 9);
	bar(250, 770, 420, 820);
	setcolor(0);
	rectangle(250, 770, 420, 820);

	setfillstyle(1, 9);
	bar(700, 770, 870, 820);
	setcolor(0);
	rectangle(700, 770, 870, 820);

	setbkcolor(9);
	setcolor(0);
	settextstyle(10, 0, 3);
	outtextxy(320, 785, (char*)"<=");

	setbkcolor(9);
	setcolor(0);
	settextstyle(10, 0, 3);
	outtextxy(775, 785, (char*)"=>");
}
void BangThiTracNghiem_graphic() {
	// Khung CAU HOI
	setfillstyle(1, 15);
	bar(50, 80, 1080, 280);
	setcolor(0);
	rectangle(50, 80, 1080, 280);

	// Khung DAP AN
	setfillstyle(1, 15);
	bar(50, 310, 1080, 750);
	setcolor(0);
	rectangle(50, 310, 1080, 750);

	setbkcolor(15);
	setcolor(0);
	settextstyle(10, 0, 2);
	outtextxy(520, 100, (char*)"CAU HOI");

	setbkcolor(15);
	setcolor(0);
	settextstyle(10, 0, 2);
	outtextxy(150, 360, (char*)"A");

	setbkcolor(15);
	setcolor(0);
	settextstyle(10, 0, 2);
	outtextxy(150, 460, (char*)"B");

	setbkcolor(15);
	setcolor(0);
	settextstyle(10, 0, 2);
	outtextxy(150, 560, (char*)"C");

	setbkcolor(15);
	setcolor(0);
	settextstyle(10, 0, 2);
	outtextxy(150, 660, (char*)"D");

	circle(100, 370, 15);
	circle(100, 470, 15);
	circle(100, 570, 15);
	circle(100, 670, 15);
}
void XemDapAn_graphic() {
	// Set mau background
	setbkcolor(7);
	cleardevice();

	// Chu tieu de
	setcolor(0);
	settextstyle(10, 0, 6);
	outtextxy(510, 10, (char*)"DAP AN TRAC NGHIEM");

	// Khung CAU HOI
	setfillstyle(1, 15);
	bar(50, 80, 1080, 280);
	setcolor(0);
	rectangle(50, 80, 1080, 280);

	// Khung DAP AN
	setfillstyle(1, 15);
	bar(50, 310, 1080, 750);
	setcolor(0);
	rectangle(50, 310, 1080, 750);

	setbkcolor(15);
	setcolor(0);
	settextstyle(10, 0, 2);
	outtextxy(520, 100, (char*)"CAU HOI");

	setbkcolor(15);
	setcolor(0);
	settextstyle(10, 0, 2);
	outtextxy(150, 360, (char*)"A");

	setbkcolor(15);
	setcolor(0);
	settextstyle(10, 0, 2);
	outtextxy(150, 460, (char*)"B");

	setbkcolor(15);
	setcolor(0);
	settextstyle(10, 0, 2);
	outtextxy(150, 560, (char*)"C");

	setbkcolor(15);
	setcolor(0);
	settextstyle(10, 0, 2);
	outtextxy(150, 660, (char*)"D");

	circle(100, 370, 15);
	circle(100, 470, 15);
	circle(100, 570, 15);
	circle(100, 670, 15);


	setfillstyle(1, 15);
	bar(1110, 80, 1500, 330);
	setcolor(0);
	rectangle(1110, 80, 1500, 330);

	line(1305, 80, 1305, 330);
	line(1110, 130, 1500, 130);
	line(1110, 180, 1500, 180);
	line(1110, 230, 1500, 230);
	line(1110, 280, 1500, 280);
	line(1110, 330, 1500, 330);

	// Khung thong bao
	setfillstyle(1, 15);
	bar(1110, 360, 1500, 750);
	setcolor(0);
	rectangle(1110, 360, 1500, 750);


	// Nut chuyen trang
	setfillstyle(1, 9);
	bar(250, 770, 420, 820);
	setcolor(0);
	rectangle(250, 770, 420, 820);

	setfillstyle(1, 9);
	bar(700, 770, 870, 820);
	setcolor(0);
	rectangle(700, 770, 870, 820);

	setbkcolor(9);
	setcolor(0);
	settextstyle(10, 0, 3);
	outtextxy(320, 785, (char*)"<=");

	setbkcolor(9);
	setcolor(0);
	settextstyle(10, 0, 3);
	outtextxy(775, 785, (char*)"=>");

	// nut THOAT
	setfillstyle(1, 10);
	bar(1200, 770, 1370, 820);
	setcolor(0);
	rectangle(1200, 770, 1370, 820);

	setbkcolor(10);
	setcolor(0);
	settextstyle(10, 0, 3);
	outtextxy(1250, 785, (char*)"THOAT");
}

void Quan_ly_diem_thi() {
	// Set mau background
	setbkcolor(7);
	cleardevice();

	// Chu tieu de
	setcolor(0);
	settextstyle(10, 0, 6);
	outtextxy(530, 10, (char*)"QUAN LY DIEM THI");

	// Khung hien thi danh sach lop
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
	line(400, 350, 400, 750);

	setbkcolor(15);
	setcolor(1);
	settextstyle(10, 0, 3);
	outtextxy(190, 360, (char*)"MA LOP");

	setbkcolor(15);
	setcolor(1);
	settextstyle(10, 0, 3);
	outtextxy(700, 360, (char*)"TEN LOP");

	// Khung chuc nang
	setfillstyle(1, 15);
	bar(50, 80, 1080, 320);

	setcolor(0);
	rectangle(50, 80, 1080, 320);

	// Nut chuc nang THEM SUA XOA
	setfillstyle(1, 9);
	bar(250, 310, 420, 260);
	setcolor(0);
	rectangle(250, 310, 420, 260);

	setfillstyle(1, 9);
	bar(470, 310, 640, 260);
	setcolor(0);
	rectangle(470, 310, 640, 260);

	setfillstyle(1, 9);
	bar(690, 310, 860, 260);
	setcolor(0);
	rectangle(690, 260, 860, 310);

	setbkcolor(9);
	setcolor(0);
	settextstyle(10, 0, 3);
	outtextxy(310, 275, (char*)"THEM");

	setbkcolor(9);
	setcolor(0);
	settextstyle(10, 0, 3);
	outtextxy(535, 275, (char*)"SUA");

	setbkcolor(9);
	setcolor(0);
	settextstyle(10, 0, 3);
	outtextxy(755, 275, (char*)"XOA");

	// Khung thong bao
	setfillstyle(1, 15);
	bar(1110, 80, 1500, 750);
	setcolor(0);
	rectangle(1110, 80, 1500, 750);
	line(1110, 140, 1500, 140);

	setbkcolor(15);
	setcolor(4);
	settextstyle(10, 0, 3);
	outtextxy(1240, 100, (char*)"THONG BAO");

	// Nut chuyen trang
	setfillstyle(1, 9);
	bar(250, 770, 420, 820);
	setcolor(0);
	rectangle(250, 770, 420, 820);

	setfillstyle(1, 9);
	bar(700, 770, 870, 820);
	setcolor(0);
	rectangle(700, 770, 870, 820);

	setbkcolor(9);
	setcolor(0);
	settextstyle(10, 0, 3);
	outtextxy(320, 785, (char*)"<=");

	setbkcolor(9);
	setcolor(0);
	settextstyle(10, 0, 3);
	outtextxy(775, 785, (char*)"=>");

	//// Khu vuc dien thong tin
	//setfillstyle(1, 11);
	//bar(400, 120, 900, 160);
	//setcolor(0);
	//rectangle(400, 120, 900, 160);

	//setfillstyle(1, 11);
	//bar(400, 180, 900, 220);
	//setcolor(0);
	//rectangle(400, 180, 900, 220);

	//setbkcolor(15);
	//setcolor(0);
	//settextstyle(10, 0, 2);
	//outtextxy(280, 130, (char*)"MA LOP");

	//setbkcolor(15);
	//setcolor(0);
	//settextstyle(10, 0, 2);
	//outtextxy(270, 190, (char*)"TEN LOP");

	// nut THOAT
	setfillstyle(1, 10);
	bar(1200, 770, 1370, 820);
	setcolor(0);
	rectangle(1200, 770, 1370, 820);

	setbkcolor(10);
	setcolor(0);
	settextstyle(10, 0, 3);
	outtextxy(1245, 785, (char*)"THOAT");

}
void Quan_ly_Diem_thi_Hien_thi_danh_sach_lop() {
	// Set mau background
	setbkcolor(7);
	cleardevice();

	// Chu tieu de
	setcolor(0);
	settextstyle(10, 0, 6);
	outtextxy(530, 10, (char*)"QUAN LY DIEM THI");

	// Khung hien thi danh sach Lop
	Khung_hien_thi_danh_sach_lop_graphic();


	// Khung chuc nang
	setfillstyle(1, 15);
	bar(50, 80, 1080, 320);

	setcolor(0);
	rectangle(50, 80, 1080, 320);

	// Nut chuc nang TRUY CAP
	setfillstyle(1, 9);
	bar(480, 260, 650, 310);
	setcolor(0);
	rectangle(480, 260, 650, 310);

	setbkcolor(9);
	setcolor(0);
	settextstyle(10, 0, 3);
	outtextxy(510, 275, (char*)"TRUY CAP");



	// Khung thong bao
	setfillstyle(1, 15);
	bar(1110, 80, 1500, 750);
	setcolor(0);
	rectangle(1110, 80, 1500, 750);
	line(1110, 140, 1500, 140);

	setbkcolor(15);
	setcolor(4);
	settextstyle(10, 0, 3);
	outtextxy(1240, 100, (char*)"THONG BAO");

	// Nut chuyen trang
	setfillstyle(1, 9);
	bar(250, 770, 420, 820);
	setcolor(0);
	rectangle(250, 770, 420, 820);

	setfillstyle(1, 9);
	bar(700, 770, 870, 820);
	setcolor(0);
	rectangle(700, 770, 870, 820);

	setbkcolor(9);
	setcolor(0);
	settextstyle(10, 0, 3);
	outtextxy(320, 785, (char*)"<=");

	setbkcolor(9);
	setcolor(0);
	settextstyle(10, 0, 3);
	outtextxy(770, 785, (char*)"=>");

	//// Khu vuc dien thong tin MA SINH VIEN | HO TEN | MAT KHAU
	//setfillstyle(1, 11);
	//bar(200, 120, 600, 160);
	//setcolor(0);
	//rectangle(200, 120, 600, 160);

	//setfillstyle(1, 11);
	//bar(200, 180, 600, 220);
	//setcolor(0);
	//rectangle(200, 180, 600, 220);

	//setfillstyle(1, 11);
	//bar(800, 180, 1050, 220);
	//setcolor(0);
	//rectangle(800, 180, 1050, 220);

	//// Chon gioi tinh NAM NU

	//setfillstyle(1, 10);
	//bar(700, 110, 850, 160);
	//setcolor(0);
	//rectangle(700, 110, 850, 160);

	//setfillstyle(1, 10);
	//bar(900, 110, 1050, 160);
	//setcolor(0);
	//rectangle(900, 110, 1050, 160);

	//setbkcolor(15);
	//setcolor(0);
	//settextstyle(10, 0, 2);
	//outtextxy(130, 130, (char*)"MA SV");

	//setbkcolor(15);
	//setcolor(0);
	//settextstyle(10, 0, 2);
	//outtextxy(120, 190, (char*)"HO TEN");

	//setbkcolor(15);
	//setcolor(0);
	//settextstyle(10, 0, 2);
	//outtextxy(670, 190, (char*)"MAT KHAU");

	//setbkcolor(10);
	//setcolor(0);
	//settextstyle(10, 0, 3);
	//outtextxy(755, 125, (char*)"NAM");

	//setbkcolor(10);
	//setcolor(0);
	//settextstyle(10, 0, 3);
	//outtextxy(965, 125, (char*)"NU");

	// nut THOAT
	setfillstyle(1, 10);
	bar(1200, 770, 1370, 820);
	setcolor(0);
	rectangle(1200, 770, 1370, 820);

	setbkcolor(10);
	setcolor(0);
	settextstyle(10, 0, 3);
	outtextxy(1250, 785, (char*)"THOAT");
}
void Quan_ly_mon_hoc_Diem_thi() {
	// Set mau background
	setbkcolor(7);
	cleardevice();

	// Chu tieu de
	setcolor(0);
	settextstyle(10, 0, 6);
	outtextxy(530, 10, (char*)"QUAN LY DIEM THI");

	// Khung hien thi danh sach Mon
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
	line(400, 350, 400, 750);

	setbkcolor(15);
	setcolor(1);
	settextstyle(10, 0, 3);
	outtextxy(190, 360, (char*)"MA MON");

	setbkcolor(15);
	setcolor(1);
	settextstyle(10, 0, 3);
	outtextxy(700, 360, (char*)"TEN MON");

	// Khung chuc nang
	setfillstyle(1, 15);
	bar(50, 80, 1080, 320);

	setcolor(0);
	rectangle(50, 80, 1080, 320);

	// Nut chuc nang TRUY CAP
	setfillstyle(1, 9);
	bar(480, 260, 650, 310);
	setcolor(0);
	rectangle(480, 260, 650, 310);

	setbkcolor(9);
	setcolor(0);
	settextstyle(10, 0, 3);
	outtextxy(510, 275, (char*)"TRUY CAP");

	// Khung thong bao
	setfillstyle(1, 15);
	bar(1110, 80, 1500, 750);
	setcolor(0);
	rectangle(1110, 80, 1500, 750);
	line(1110, 140, 1500, 140);

	setbkcolor(15);
	setcolor(4);
	settextstyle(10, 0, 3);
	outtextxy(1240, 100, (char*)"THONG BAO");

	// Nut chuyen trang
	setfillstyle(1, 9);
	bar(250, 770, 420, 820);
	setcolor(0);
	rectangle(250, 770, 420, 820);

	setfillstyle(1, 9);
	bar(700, 770, 870, 820);
	setcolor(0);
	rectangle(700, 770, 870, 820);

	setbkcolor(9);
	setcolor(0);
	settextstyle(10, 0, 3);
	outtextxy(320, 785, (char*)"<=");

	setbkcolor(9);
	setcolor(0);
	settextstyle(10, 0, 3);
	outtextxy(775, 785, (char*)"=>");

	//// Khu vuc dien thong tin
	//setfillstyle(1, 11);
	//bar(400, 120, 900, 160);
	//setcolor(0);
	//rectangle(400, 120, 900, 160);

	//setfillstyle(1, 11);
	//bar(400, 180, 900, 220);
	//setcolor(0);
	//rectangle(400, 180, 900, 220);

	//setbkcolor(15);
	//setcolor(0);
	//settextstyle(10, 0, 2);
	//outtextxy(280, 130, (char*)"MA MON");

	//setbkcolor(15);
	//setcolor(0);
	//settextstyle(10, 0, 2);
	//outtextxy(270, 190, (char*)"TEN MON");

	// nut THOAT
	setfillstyle(1, 10);
	bar(1200, 770, 1370, 820);
	setcolor(0);
	rectangle(1200, 770, 1370, 820);

	setbkcolor(10);
	setcolor(0);
	settextstyle(10, 0, 3);
	outtextxy(1250, 785, (char*)"THOAT");

}
void Truy_cap_mon_hoc_Diem_thi() {

	// Khung chuc nang
	setfillstyle(1, 15);
	bar(50, 80, 1080, 320);

	setcolor(0);
	rectangle(50, 80, 1080, 320);

	// Khu vuc dien MA MON
	setfillstyle(1, 11);
	bar(350, 120, 700, 160);
	setcolor(0);
	rectangle(350, 120, 700, 160);

	setbkcolor(15);
	setcolor(0);
	settextstyle(10, 0, 2);
	outtextxy(230, 130, (char*)"MA MON");

	// Nut chuc nang TRUY CAP
	setfillstyle(1, 9);
	bar(480, 260, 650, 310);
	setcolor(0);
	rectangle(480, 260, 650, 310);

	setbkcolor(9);
	setcolor(0);
	settextstyle(10, 0, 3);
	outtextxy(510, 275, (char*)"TRUY CAP");
}
void Xem_Diem_thi() {
	// Set mau background
	setbkcolor(7);
	cleardevice();

	// Chu tieu de
	setcolor(0);
	settextstyle(10, 0, 6);
	outtextxy(530, 10, (char*)"QUAN LY DIEM THI");

	// Khung hien thi danh sach lop
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
	line(250, 350, 250, 750);
	line(360, 350, 360, 750);
	line(740, 350, 740, 750);
	line(870, 350, 870, 750);

	setbkcolor(15);
	setcolor(1);
	settextstyle(10, 0, 3);
	outtextxy(115, 360, (char*)"MA SV");

	setbkcolor(15);
	setcolor(1);
	settextstyle(10, 0, 3);
	outtextxy(280, 360, (char*)"PHAI");

	setbkcolor(15);
	setcolor(1);
	settextstyle(10, 0, 3);
	outtextxy(540, 360, (char*)"HO");

	setbkcolor(15);
	setcolor(1);
	settextstyle(10, 0, 3);
	outtextxy(785, 360, (char*)"TEN");

	setbkcolor(15);
	setcolor(1);
	settextstyle(10, 0, 3);
	outtextxy(920, 360, (char*)"DIEM THI");

	// Khung chuc nang
	setfillstyle(1, 15);
	bar(50, 80, 1080, 320);

	setcolor(0);
	rectangle(50, 80, 1080, 320);

	// Khung thong bao
	setfillstyle(1, 15);
	bar(1110, 80, 1500, 750);
	setcolor(0);
	rectangle(1110, 80, 1500, 750);
	line(1110, 140, 1500, 140);

	setbkcolor(15);
	setcolor(4);
	settextstyle(10, 0, 3);
	outtextxy(1240, 100, (char*)"THONG BAO");

	Khu_vuc_nhap_ma_de_Sua_thong_tin_sinh_vien();

	// Nut chuc nang XEM BAI LAM
	setfillstyle(1, 9);
	bar(450, 260, 680, 310);
	setcolor(0);
	rectangle(450, 260, 680, 310);

	setbkcolor(9);
	setcolor(0);
	settextstyle(10, 0, 3);
	outtextxy(485, 275, (char*)"XEM BAI LAM");

	// Nut chuyen trang
	setfillstyle(1, 9);
	bar(250, 770, 420, 820);
	setcolor(0);
	rectangle(250, 770, 420, 820);

	setfillstyle(1, 9);
	bar(700, 770, 870, 820);
	setcolor(0);
	rectangle(700, 770, 870, 820);

	setbkcolor(9);
	setcolor(0);
	settextstyle(10, 0, 3);
	outtextxy(320, 785, (char*)"<=");

	setbkcolor(9);
	setcolor(0);
	settextstyle(10, 0, 3);
	outtextxy(770, 785, (char*)"=>");

	// nut THOAT
	setfillstyle(1, 10);
	bar(1200, 770, 1370, 820);
	setcolor(0);
	rectangle(1200, 770, 1370, 820);

	setbkcolor(10);
	setcolor(0);
	settextstyle(10, 0, 3);
	outtextxy(1250, 785, (char*)"THOAT");
}
void BangDanhSachSinhVien_XemDiem() {
	// Khung hien thi danh sach lop
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
	line(250, 350, 250, 750);
	line(360, 350, 360, 750);
	line(740, 350, 740, 750);
	line(870, 350, 870, 750);

	setbkcolor(15);
	setcolor(1);
	settextstyle(10, 0, 3);
	outtextxy(115, 360, (char*)"MA SV");

	setbkcolor(15);
	setcolor(1);
	settextstyle(10, 0, 3);
	outtextxy(280, 360, (char*)"PHAI");

	setbkcolor(15);
	setcolor(1);
	settextstyle(10, 0, 3);
	outtextxy(540, 360, (char*)"HO");

	setbkcolor(15);
	setcolor(1);
	settextstyle(10, 0, 3);
	outtextxy(785, 360, (char*)"TEN");

	setbkcolor(15);
	setcolor(1);
	settextstyle(10, 0, 3);
	outtextxy(920, 360, (char*)"DIEM THI");
}