/* 
CÁC HÀM SẮP XẾP 
1.SẮP XẾP CHÈN (INSERTION SORT)	
2.SẮP XẾP CHỌN (SELECTION SORT)
3.SẮP XẾP NỔI BỌT (BUBBLE SORT)
4.SẮP XẾP TRỘN (MERGE SORT)
5.SẮP XẾP NHANH (QUICK SORT)
6.SẮP XẾP VUN ĐỐNG (HEAP SORT) 
*/

#include"main.h"
#include"func.h"


/* 3 HÀM SẮP XẾP CƠ BẢN */

//SẮP XẾP CHÈN (INSERTION SORT)
void insertionSort(bool(*compare)(Student*, Student*)) {
	Student* last;
	int j;
	for (int i = 1; i < n; i++) {
		last = Class[i];
		j = i;
		while (compare(last, Class[j-1]) && j >= 0) {
			Class[j] = Class[j-1];
			j--;
			if (j == 0) break;
		}
		Class[j] = last;
	}
}

//SẮP XẾP CHỌN (SELECTION SORT)
void selectionSort(bool(*compare)(Student*, Student*)) {
	int index;
	for (int i = 0; i < n - 1; i++) {
		index = i;
		for (int j = i + 1; j < n; j++) {
			if (compare(Class[j], Class[index]))  index = j;
		}
		swap(Class[i], Class[index]);
	}
}

//SẮP XẾP NỔI BỌT (BUBBLE SORT)
void bubbleSort(bool(*compare)(Student*, Student*)) {
	for (int i = n-1; i>=0; i--) {
		for (int j = 0; j < i; j++) {
			if (compare(Class[j + 1], Class[j]))  swap(Class[j + 1], Class[j]);
		}
	}
}





/* SẮP XẾP TRỘN(MERGE SORT) */

//Hàm trộn
void merge(bool(*compare)(Student*, Student*), int first, int mid, int last) {
	int m = mid - first + 1;
	int n = last - mid;

	//Tạo và copy dữ liệu vào mảng phụ
	Student** ptr1 = new Student*[m];
	Student** ptr2 = new Student*[n];
	int k = 0;
	for (int i = first; i <= mid; i++) {
		ptr1[k] = Class[i];
		k++;
	}
	k = 0;
	for (int i = mid + 1; i <= last; i++) {
		ptr2[k] = Class[i];
		k++;
	}

	//Sắp xếp trộn
	int i = 0, j = 0;
	for (k = first; k <= last; k++) {
		if (i >= m) {
			Class[k] = ptr2[j];
			j++;
		}
		else if (j >= n) {
			Class[k] = ptr1[i];
			i++;
		}
		else if (compare(ptr1[i], ptr2[j])) {
			Class[k] = ptr1[i];
			i++;
		}
		else {
			Class[k] = ptr2[j];
			j++;
		}
	}
	delete[] ptr1;
	delete[] ptr2;
}

//Hàm sắp xếp trộn
void mergeSort(bool(*compare)(Student*, Student*), int first, int last) {
	if (first < last) {
		//Chia
		int mid = (first + last) / 2;
		mergeSort(compare, first, mid);
		mergeSort(compare, mid + 1, last);
		//Trộn
		merge(compare, first, mid, last);
	}
}





/* SẮP XẾP NHANH(QUICK SORT) */

//Hàm chia
int divide(bool(*compare)(Student*, Student*), int first, int last) {

	int i = first, j = last;
	Student* key = Class[first];
	//chuyển các phần tử nhỏ hơn key sang trái,lớn hơn key sang phải
	while (i < j) {
		while ((i <= last) && (!compare(key, Class[i]))) {
			i++;
		}
		while ((j >= first) && compare(key, Class[j])) {
			j--;
		}
		if (i < j) swap(Class[i], Class[j]);
	}
	swap(Class[first], Class[j]);
	return j;
}

//Hàm sắp xếp nhanh
void quickSort(bool(*compare)(Student*, Student*), int first, int last) {
	if (first < last) {
		//chia
		int p = divide(compare, first, last);
		//trị
		quickSort(compare, first, p - 1);
		quickSort(compare, p + 1, last);
	}
}





/* SẮP XẾP ĐỐNG(HEAP SORT) */

//Trả về vị trí con trái,con phải,cha của 1 nút
inline int  left_child(int i) {
	return 2 * i + 1;
}
inline int right_child(int i) {
	return 2 * i + 2;
}
inline int parent(int i) {
	return (i - 1) / 2;
}

//Tái tạo tính chất đống
void rebuildHeap(bool(*compare)(Student*, Student*), int i, int n) {
	int temp = i;
	int left = left_child(i);
	int right = right_child(i);

	if (left <= n) {
		if (compare(Class[temp], Class[left])) temp = left;
	}
	if (right <= n) {
		if (compare(Class[temp], Class[right])) temp = right;
	}
	if (temp != i) {
		swap(Class[temp], Class[i]);
		rebuildHeap(compare, temp, n);
	}
}

//Xây dựng đống
void buildHeap(bool(*compare)(Student*, Student*)) {
	for (int i = (n - 1) / 2; i >= 0; i--) {
		rebuildHeap(compare, i, n - 1);
	}
}

//Sắp xếp vun đống
void heapSort(bool(*compare)(Student*, Student*)) {
	buildHeap(compare);
	for (int i = n - 1; i > 0; i--) {
		swap(Class[0], Class[i]);
		rebuildHeap(compare, 0, i - 1);
	}
}



