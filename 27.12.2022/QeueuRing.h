#pragma once
#include <iostream>
using namespace std;

class QeueuRing {
	int* Wait;//�������
	int MaxQeueuLength;//������������ ������ �������
	int QeueuLength;//������� ������ �������

public:
	QeueuRing(int m);//�����������
	~QeueuRing();//����������
	void Add(int c);//���������� ��������
	int Extract();///���������� ��������
	void Clear();//������� �������
	bool IsEmpty();//�������� �� ������������� �������� � �������
	bool IsFull();//�������� �� ������������ �������
	int GetCount();//����� ��������� � �������
	void Show();//������������

};

void QeueuRing::Show() {
	for (int i{ 0 }; i < QeueuLength; i++) {
		cout << Wait[i] << " ";
	}
	cout << endl;
}

QeueuRing::~QeueuRing() {
	delete[] Wait;
}

QeueuRing::QeueuRing(int m) {
	MaxQeueuLength = m;
	Wait = new int[MaxQeueuLength];
	QeueuLength = 0;
}

bool QeueuRing::IsEmpty() {
	return QeueuLength == 0;
}

bool QeueuRing::IsFull() {
	return QeueuLength == MaxQeueuLength;
}

int QeueuRing::GetCount() {
	return QeueuLength;
}

void QeueuRing::Add(int c) {
	if (!IsFull())Wait[QeueuLength++] = c;
}

int QeueuRing::Extract() {
	if (!IsEmpty()) {
		int temp = Wait[0];
		for (int i{ 1 }; i < QeueuLength; i++) {
			Wait[i - 1] = Wait[i];
		}
		Wait[QeueuLength - 1] = temp;
		return 1;
	}
	else return -1;
}

void QeueuRing::Clear() {
	QeueuLength = 0;
}
};