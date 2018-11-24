/*
CHỨA CÁC HÀM INPUT,OUTPUT VÀ HÀM CON PHỤC VỤ QUÁ TRÌNH SẮP XẾP
*/


#include<iostream>
#include<fstream>
#include<cstdio>
#include<Windows.h>
#include<conio.h>
#include"main.h"
using namespace std;

//Các hàm làm nhiệm vụ so sánh 2 Student theo tên/điểm
bool compareGradeIncreasing(Student* student1, Student* student2) {
	return student1->grade < student2->grade;
}
bool compareGradeDecreasing(Student* student1, Student* student2) {
	return student1->grade > student2->grade;
}
bool compareString(char* str1, char* str2, int pos1, int pos2) {
	while (str1[pos1] != ' ') {
		pos1--;
		if (pos1 == -1) break;
	}
	while (str2[pos2] != ' ') {
		pos2--;
		if (pos2 == -1) break;
	}

	if (strcmp(&str1[pos1 + 1], &str2[pos2 + 1]) < 0) return true;
	else if (strcmp(&str1[pos1 + 1], &str2[pos2 + 1]) > 0) return false;
	else if ((pos1 == -1) && (pos2 == -1)) return (strcmp(str1, str2) < 0);
	else if ((pos2 == -1) && (pos1 != -1)) return false;
	else if ((pos1 == -1) && (pos2 != -1)) return true;
	else	return compareString(str1, str2, pos1 - 1, pos2 - 1);
}

bool compareNameIncreasing(Student* student1, Student* student2) {
	return compareString(student1->name, student2->name, strlen(student1->name), strlen(student2->name));
}
bool compareNameDecreasing(Student* student1, Student* student2) {
	return compareString(student2->name, student1->name, strlen(student2->name), strlen(student1->name));
}

//Tráo đổi vị trí 2 Student
void swap(Student*& student1, Student*& student2) {
	Student* ptr = student1;
	student1 = student2;
	student2 = ptr;
}

//In danh sách
void printList(Student* Class[]) {
	cout << "+-------+----------------------------------+---------+\n"
		 << "|  STT  |              HO VA TEN           |   DIEM  |\n"
		 << "+-------+----------------------------------+---------+\n";
	for (int i = 0; i < n; i++) {
		printf("|  %2d   |   ",i+1);
		printf("%-30s |   ", Class[i]->name);
		printf("%4.1f  |\n", Class[i]->grade);
	}
}

//Kiểm tra 1 dãy có thỏa mãn điều kiện là tên hay không
bool isOK(char str[30]) {
	if (!isalpha(str[0])) return false;
	if (!isalpha(str[strlen(str)-1])) return false;
	for (int i = strlen(str) - 1; i >= 1; i--) {
		if ((!isalpha(str[i])) && (str[i] != ' ')) return false;
		if (((str[i] == ' ') && (str[i - 1] == ' '))) return false;
	}
	return true;
}

void gotoxy(short x, short y) {
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { x,y });
}

void getPos(short& x, short& y) {
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
	x = info.dwCursorPosition.X;
	y = info.dwCursorPosition.Y;
}
//Input từ bàn phím
void inputKB() {
	cout << "          -----NHAP SINH VIEN-----\n\n"
		<< "->NOTE:Sau moi buoc nhap sinh vien,nhan ESC de thoat,phim bat ki de tiep tuc.\n";
	
	short x = 0, y = 0;
	printList(Class_base);
	while (n <= 100) {
		bool end=false;
		Class_base[n] = new Student;
		getPos(x, y);
		while (1) {
			cin.clear();
			printf("|  %2d   |                                  |         |", n+1);
			gotoxy(x+12, y);
			cin.getline(Class_base[n]->name, 30);
			if (cin.fail() || (!isOK(Class_base[n]->name))) {
				if (cin.fail()) {
					cin.clear();
					cin.ignore(256, '\n');
				}
				gotoxy(x , y);
				for (int i = 0; i < 256; i++) cout << " ";
				gotoxy(x + 60, y);
				cout << "\a!ERROR: Ten khong hop le,moi nhap lai!";
				gotoxy(x , y);
				continue;
			}
			gotoxy(x + 60, y);
			cout << "                                      ";
			while (1) {
				gotoxy(x + 47, y);
				cin >> Class_base[n]->grade;
				if (cin.fail() || (Class_base[n]->grade < 0) || (Class_base[n]->grade > 10)) {
					cin.clear();
					cin.ignore(256, '\n');
					gotoxy(x + 47, y);
					for (int i = 0; i < 256; i++) cout << " ";
					gotoxy(x + 60, y);
					cout << "\a!ERROR: Diem khong hop le,moi nhap lai!";
					gotoxy(x + 53, y);
					cout << "|";
					continue;
				}
				gotoxy(x + 47, y);
				for (int i = 0; i < 256; i++) cout << " ";
				gotoxy(x + 47, y);
				printf("%4.1f  |\n", Class_base[n]->grade);

				cin.ignore(256, '\n');
				break;
			}
			Class[n] = Class_base[n];
			n++;
			break;
		}
		cout << "->Tiep tuc?";
		if (_getch() == 27) {
			gotoxy(0, y + 1);
			cout << "+-------+----------------------------------+---------+\n";
			break;
		}
		gotoxy(0, y + 1);
		cout << "         ";
		gotoxy(x, y + 1);
	}
}

//In ra danh sách các file đã lưu
void showFileList() {
	cout << "---FILES LIST---:\n";
	char name_path[256];
	GetCurrentDirectory(256, name_path); //lấy đường dẫn thư mục hiện tại
	char dir_path[256];
	strcpy_s(dir_path, name_path);
	strcat_s(name_path, "\\Data\\*");
	strcat_s(dir_path, "\\Data\\");
		WIN32_FIND_DATA data;
		HANDLE hFind;
		hFind = FindFirstFile(name_path, &data);
		FindNextFile(hFind, &data);
		FindNextFile(hFind, &data);
			do {
				cout <<"  "<<dir_path<< data.cFileName << endl;
			} while (FindNextFile(hFind, &data) != 0);
			FindClose(hFind);
}



//Input từ file
void inputFile() {
	for (int i = 0; i < n; i++) {
		delete[] Class[i];
	}
	n = 0;
	showFileList();
	char file_name[20];
	cout << "\n\n->Nhap ten file:\n   ";
	char file_path[256];
	GetCurrentDirectory(256, file_path); //lấy đường dẫn thư mục hiện tại
	strcat_s(file_path,"\\Data\\");
	cout << file_path;
	cin >> file_name;
	strcat_s(file_path, file_name);
	cin.ignore(256, '\n');
	ifstream file(file_path);
	if (file.fail()) {
		cerr << "\a-----Da xay ra loi,file khong ton tai!-----" << std::endl;
		return;
	}
	while (n < 100) {
		Class_base[n] = new Student;
		file.getline(Class_base[n]->name, 30, ':');
		if (file.eof()) break;
		file >> Class_base[n]->grade;
		Class[n] = Class_base[n];
		file.ignore(256, '\n');
		n++;
		if (file.eof()) break;
		
	}
	cerr << "\n-----Doc du lieu thanh cong!-----" << endl;
}

//Ghi ra file
void writeToFile() {
	char file_name[20];
	char file_path[256];
	GetCurrentDirectory(256, file_path); //lấy đường dẫn thư mục hiện tại
	strcat_s(file_path, "\\Data\\");
	showFileList();
	cout << "->Nhap ten file:";
	cout << file_path;
	cin >>file_name;
	cin.ignore(256, '\n');
	
	strcat_s(file_path, file_name);
	ofstream file(file_path);
	if (file.fail()) {
		cerr << "\a-----Thao tac khong thanh cong,da xay ra loi!-----" << std::endl;
		return;
	}
	for (int i = 0; i < n-1; i++) {
		file << Class[i]->name << ":" << Class[i]->grade<<endl;
	}
	file << Class[n - 1]->name << ":" << Class[n - 1]->grade;
	cout << "\n-----Ghi ra file " << file_path << " thanh cong-----\n";
}

