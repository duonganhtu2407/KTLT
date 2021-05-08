#include <stdio.h>
#include <string.h>

#define MAX 100
struct SINHVIEN
{
	char hoten[30];
	char maSV[10];
	float TK, GK , CK , TH, DTB;
	
};
SINHVIEN A[MAX];
void nhap1SV(SINHVIEN &sv){
	fflush(stdin);
	printf("\n Nhap Ten SV:");
	gets(sv.hoten);
	printf("\n Nhap Ma SV:");
	gets(sv.maSV);
	printf("\n Nhap diem TK GK CK TK cua SV:");
	scanf("%f%f%f%f", &sv.TK, &sv.GK, &sv.CK, &sv.TH);
	sv.DTB = ((2*sv.TK + 3*sv.GK + 5*sv.CK)/5 + sv.TH)/3;
	
}
void xuat1SV(SINHVIEN sv){
	printf("\n  Ten SV:%s",sv.hoten);
	printf("\n  Ma SV:%s",sv.maSV);
	printf("\n  diem TK GK CK TK cua SV:%.2f\t%.2f\t%.2f\t%.2f\t%.2f", sv.TK, sv.GK, sv.CK, sv.TH, sv.DTB);
}
void nhapDSSV(SINHVIEN sv[], int &n){
	printf("\n Ban muon nhap bao nhieu SV: ");
	scanf("%d", &n);
	for(int i = 0; i < n ; i++){
		printf("\n Nhap Sinh vien thu %d:",i+1);
		nhap1SV(sv[i]);
	}
}
void xuatDSSV(SINHVIEN sv[], int n){
	int dem = 1;
	printf("\n Danh Sach Sien vien hoc lai");
	printf("\n------------------------------------------------------------------");
	printf("\n|%6s|%-30s|%-15s|%-10s|","STT"," HO TEN", "MA SINH VIEN", "DIEM TB");
	printf("\n------------------------------------------------------------------");
	//xuat DS SV;
	for(int i = 0; i < n ; i++){
		if(sv[i].DTB < 4.0){
			printf("\n|%6d|%-30s|%-15s|%-10f|",dem++,sv[i].hoten, sv[i].maSV, sv[i].DTB);
			printf("\n------------------------------------------------------------------");
		}
		
	}
}
void TimSV(SINHVIEN sv[], int n, char vt[]){
	for(int i = 0;i<n;i++){
		if(strcmp(sv[i].maSV,vt)==0){
			printf("Tim Thay Sinh Vien: ");
			xuat1SV(sv[i]);
			return;
		}
	}
	printf("\nKhong tim thay :");
}

void DSDTSV(SINHVIEN sv[], int n){
	int dem = 1;
	printf("\n Danh Sach Diem Kiem Tra Cua SINH VIEN");
	printf("\n--------------------------------------------------------------------------------");
	printf("\n|%6s|%-15s|%-10s|%-6s|%-6s|%-6s|%-6s|%-6s|%-6s|","STT"," HO TEN", "MA SINH VIEN", "TK","GK","CK","TH","DTB","GHI CHU");
	printf("\n--------------------------------------------------------------------------------");
	for(int i = 0; i < n ; i++){
		printf("\n|%6d|%-15s|%-10s|%-6.2f|%-6.2f|%-6.2f|%-6.2f|%-6.2f|%-6s|",dem++,sv[i].hoten, sv[i].maSV, sv[i].TK,sv[i].GK,sv[i].CK,sv[i].TH,sv[i].DTB,sv[i].DTB<4 ? "Hoc Lai" : " ");
		printf("\n--------------------------------------------------------------------------------");
	}
}
int main(int argc, char *argv[])
{
	SINHVIEN sv[MAX];
	int n;
	nhapDSSV(sv,n);
	xuatDSSV(sv, n);
	char vt[10];
	fflush(stdin);
	printf("\n nhap ma sinh vien can tim:");
	gets(vt);
	TimSV(sv,n,vt);
	DSDTSV(sv,n);
	return 0;
}