#pragma once
#include <stdio.h>
#include <iostream> 
#include "graphics.h"
#include <Windows.h>

#pragma comment(lib, "graphics.lib")

void Man_hinh_dang_nhap();
void Menu_cua_giao_vien();

void Quan_ly_lop();
void Khung_hien_thi_danh_sach_lop_graphic();
void BangDanhsachLop();
void Khu_vuc_nhap_thong_tin_lop();
void Khu_vuc_SUA_thong_tin_lop();
void Nhap_MA_LOP_de_xoa();
void Nhap_NAM_HOC_de_in_graphic();

void Quan_ly_sinh_vien();
void BangDanhSachSinhVien();
void Quan_ly_sinh_vien_Hien_thi_danh_sach_lop();
void Khu_vuc_Nhap_thong_tin_sinh_vien();
void Khu_vuc_Sua_thong_tin_sinh_vien();
void Khu_vuc_nhap_ma_de_Sua_thong_tin_sinh_vien();
void Khu_vuc_Xoa_thong_tin_sinh_vien();
void Hien_thi_chuc_nang_sinh_vien();

void Quan_ly_mon_hoc();
void BangDanhSachMonHoc();
void Nhap_thong_tin_mon_hoc();
void Xoa_thong_tin_mon_hoc();
void Sua_thong_tin_mon_hoc();
void Khu_vuc_Sua_thong_tin_mon_hoc();

void Quan_ly_cau_hoi();
void BangDanhSachCauHoi();
void Quan_ly_cau_hoi_Hien_thi_danh_sach_MON();
void Khu_vuc_nhap_MA_MONHOC();
void Xoa_khu_vuc_dien_MA_MONHOC_va_THONG_BAO();
void Nhap_cau_hoi_thi();

void Thi_trac_nghiem_ChonMonHoc();
void Xem_Diem_Sinh_Vien_graphic();
void TienHanhThi_graphic();
void BangThiTracNghiem_graphic();
void XemDapAn_graphic();

void Quan_ly_diem_thi();
void Quan_ly_Diem_thi_Hien_thi_danh_sach_lop();
void Quan_ly_mon_hoc_Diem_thi();
void Truy_cap_mon_hoc_Diem_thi();
void Xem_Diem_thi();
void BangDanhSachSinhVien_XemDiem();