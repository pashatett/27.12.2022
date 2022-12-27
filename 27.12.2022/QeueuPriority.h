#pragma once
#include <iostream>
using namespace std;

class QeueuPriority {
	int* Wait;//�������
	int* Pri;//�������
	int MaxQeueuLength;//������������ ������ �������
	int QeueuLength;//������� ������ �������

public:
	QeueuPriority(int m);//�����������
	~QeueuPriority();//����������
	void Add(int c, int p);//���������� ��������
	int Extract();///���������� ��������
	void Clear();//������� �������
	bool IsEmpty();//�������� �� ������������� �������� � �������
	bool IsFull();//�������� �� ������������ �������
	int GetCount();//����� ��������� � �������
	void Show();//������������

};

void QeueuPriority::Show() {
	for (int i{ 0 }; i < QeueuLength; i++) {
		cout << Wait[i] << " - " << Pri[i] << " " << endl;;
	}
	cout << endl;
}

QeueuPriority::~QeueuPriority() {
	delete[] Wait;
	delete[] Pri;
}

QeueuPriority::QeueuPriority(int m) {
	MaxQeueuLength = m;
	Wait = new int[MaxQeueuLength];
	Pri = new int[MaxQeueuLength];
	QeueuLength = 0;
}

bool QeueuPriority::IsEmpty() {
	return QeueuLength == 0;
}

bool QeueuPriority::IsFull() {
	return QeueuLength == MaxQeueuLength;
}

int QeueuPriority::GetCount() {
	return QeueuLength;
}

void QeueuPriority::Add(int c, int p) {
	if (!IsFull()) {
		Wait[QeueuLength] = c;
		Pri[QeueuLength] = p;
		QeueuLength++;
	}
}

int QeueuPriority::Extract() {
	if (!IsEmpty()) {
		int max_pri = Pri[0];
		int pos_max_pri = 0;

		for (int i{ 1 }; i < QeueuLength; i++) {
			if (max_pri < Pri[i]) {
				max_pri = Pri[i];
				pos_max_pri += i;
			}
		}
		int temp1 = Wait[pos_max_pri];
		//int temp2 = Pri[pos_max_pri];

		for (int i{ pos_max_pri }; i < QeueuLength - 1; i++) {
			Wait[i] = Wait[i + 1];
			Pri[i] = Pri[i + 1];
		}
		QeueuLength--;
		return temp1;
	}
	else return -1;
}

void QeueuPriority::Clear() {
	QeueuLength = 0;
}