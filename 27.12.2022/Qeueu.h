#pragma once
#include <iostream>
using namespace std;

class Qeueu {
	int* Wait;//�������
	int MaxQeueuLength;//������������ ������ �������
	int QeueuLength;//������� ������ �������

public:
	Qeueu(int m);//�����������
	~Qeueu();//����������
	void Add(int c);//���������� ��������
	int Extract();///���������� ��������
	void Clear();//������� �������
	bool IsEmpty();//�������� �� ������������� �������� � �������
	bool IsFull();//�������� �� ������������ �������
	int GetCount();//����� ��������� � �������
	void Show();//������������

};

void Qeueu::Show() {
	for (int i{ 0 }; i < QeueuLength; i++) {
		cout << Wait[i] << " ";
	}
	cout << endl;
}

Qeueu::~Qeueu() {
	delete[] Wait;
}

Qeueu::Qeueu(int m) {
	MaxQeueuLength = m;
	Wait = new int[MaxQeueuLength];
	QeueuLength = 0;
}

bool Qeueu::IsEmpty() {
	return QeueuLength == 0;
}

bool Qeueu::IsFull() {
	return QeueuLength == MaxQeueuLength;
}

int Qeueu::GetCount() {
	return QeueuLength;
}

void Qeueu::Add(int c) {
	if (!IsFull())Wait[QeueuLength++] = c;
}

int Qeueu::Extract() {
	if (!IsEmpty()) {
		int temp = Wait[0];
		for (int i{ 1 }; i < QeueuLength; i++) {
			Wait[i - 1] = Wait[i];
		}
		QeueuLength--;
		return temp;
	}
	else return -1;
}

void Qeueu::Clear() {
	QeueuLength = 0;
}