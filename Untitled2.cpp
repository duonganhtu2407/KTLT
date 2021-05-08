#include <stdio.h>
#include <string.h>

void xoaKyTu(char a[], int vt)
{
	for(int i =vt; i<strlen(a);i++)
		a[i]=a[i+1];
}

int main(int argc, char *argv[])
{
	char a[100];
	printf("\nnhap chuoi:");
	gets(a);
	printf("\n chuoi vua nhap:");
	puts(a);
	//xoa ky tu khaong trang dau
	printf("chuoi truoc khi nhap: %d\n", strlen(a));
	int i =0;
	while(a[i]==' ')
	{
		if(a[i]==' ')
			xoaKyTu(a,i);
	};
	//xoa cuoi
	i=strlen(a)-1;
	while(a[i]==' ') i--;;
	a[i+1]='\0';
	//xoa giua
	for(i =0;i<strlen(a);)
		if(a[i]==' ' && a[i+i]==' ')
			xoaKyTu(a,i);
		else
			i++;
	
	printf("chuoi vua xoa :");
	puts(a);
	
	
	
	
}