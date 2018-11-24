#pragma once
extern int n;
//Kiểu dữ liệu cấu trúc Student
struct Student {
	char name[30];
	float grade;
};
typedef struct Student Student;

extern Student* Class_base[100]; //Mảng gốc-không thay đổi khi thực hiện sắp xếp
extern Student* Class[100];  //Thay đổi khi thực hiện sắp xếp

