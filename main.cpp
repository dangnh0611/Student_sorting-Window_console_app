/*
CHỨA CÁC HÀM HIỂN THỊ MENU VÀ HÀM MAIN()
*/


#include<iostream>
#include<cstring>
#include<cstdlib>
#include<windows.h>
#include<conio.h>
#include<filesystem>
#include <string>
#include"main.h"
#include"sort.h"
#include"func.h"

using namespace std;

Student* Class_base[100];
Student* Class[100];
int n = 0;

//Menu chọn cách sắp xếp
void sortMenu(bool(*compare)(Student*,Student*)) {
	cout << "-------------------------MENU----------------------------\n"
		<< "\t\t1.Insertion sort\n"
		<< "\t\t2.Selection sort\n"
		<< "\t\t3.Bubble sort\n"
		<< "\t\t4.Merge sort\n"
		<< "\t\t5.Quick sort\n"
		<< "\t\t6.Heap sort\n";
	int i = 0;
	do {
		if (cin.fail()) {
			cin.clear();
			cin.ignore(256, '\n');
		}
		cout << "->Nhap lua chon(1-6):";
		cin >> i;
	} while ((cin.fail()) || (i < 1) || (i > 6));
	cin.ignore(256, '\n');
	switch (i) {
	case 1:
		insertionSort(compare);
		printList(Class);
		cout << "+-------+----------------------------------+---------+\n";
		break;
	case 2:
		selectionSort(compare);
		printList(Class);
		cout << "+-------+----------------------------------+---------+\n";
		break;
	case 3:
		bubbleSort(compare);
		printList(Class);
		break;
	case 4:
		mergeSort(compare, 0, n - 1);
		printList(Class);
		cout << "+-------+----------------------------------+---------+\n";
		break;
	case 5:
		quickSort(compare, 0, n - 1);
		printList(Class);
		cout << "+-------+----------------------------------+---------+\n";
		break;
	case 6:
		heapSort(compare);
		printList(Class);
		cout << "+-------+----------------------------------+---------+\n";
	}
}

//Menu chọn kiểu sắp xếp
void formMenu() {
	cout << "-------------------------MENU----------------------------\n"
		<< "\t\t1.Theo diem,tang dan\n"
		<< "\t\t2.Theo diem,giam dan\n"
		<< "\t\t3.Theo ten,tang dan\n"
		<< "\t\t4.Theo ten,giam dan\n";
		int i = 0;
	do {
		if (cin.fail()) {
			cin.clear();
			cin.ignore(256, '\n');
		}
		cout << "->Nhap lua chon(1-4):";
		cin >> i;
	} while ((cin.fail()) || (i < 1) || (i > 4));
	cin.ignore(256, '\n');
	switch (i) {
	case 1:
		sortMenu(compareGradeIncreasing);
		break;
	case 2:
		sortMenu(compareGradeDecreasing);
		break;
	case 3:
		sortMenu(compareNameIncreasing);
		break;
	case 4:
		sortMenu(compareNameDecreasing);
	}
}

//Menu chức năng chính
void mainMenu() {
	cout << "-------------------------MENU----------------------------\n"
		<< "\t\t1.Sap xep sinh vien\n"
		<< "\t\t2.Hien thi danh sach chua sap xep\n"
		<< "\t\t3.Bo sung sinh vien\n"
		<< "\t\t4.Nhap sinh vien tu file\n"
		<< "\t\t5.Luu danh sach da sap xep ra file\n"
		<< "\t\t6.Thoat\n";
	int i = 0;
	do {
		if (cin.fail()) {
			cin.clear();
			cin.ignore(256, '\n');
		}
		cout << "->Nhap lua chon(1-6):";
		cin >> i;
	} while ((cin.fail()) || (i < 1) || (i > 6));
	cin.ignore(256, '\n');
	switch (i) {
	case 1:
		formMenu();
		cout << "\nPRESS ANY KEY TO CONTINUTE...";
		_getch();
		system("cls");
		break;
	case 2:
		printList(Class_base);
		cout << "+-------+----------------------------------+---------+\n";
		cout << "\nPRESS ANY KEY TO CONTINUTE...";
		_getch();
		system("cls");
		break;
	case 3:
		inputKB();
		cout << "\nPRESS ANY KEY TO CONTINUTE...";
		_getch();
		system("cls");
		break;
	case 4:
		inputFile();
		cout << "\nPRESS ANY KEY TO CONTINUTE...";
		_getch();
		system("cls");
		break;
	case 5:
		writeToFile();
		cout << "\nPRESS ANY KEY TO CONTINUTE...";
		_getch();
		system("cls");
		break;
	case 6:
		exit(EXIT_SUCCESS);
	}
}


/* MAIN */
int main() {
	
	while (1) {
		mainMenu();
	}
}
