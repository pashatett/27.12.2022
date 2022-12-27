#pragma once
#include <iostream>
using namespace std;

class QeueuRing {
	int* Wait;//очередь
	int MaxQeueuLength;//максимальнвц размер очереди
	int QeueuLength;//текущий размер очереди

public:
	QeueuRing(int m);//конструктор
	~QeueuRing();//деструктор
	void Add(int c);//добавление элемента
	int Extract();///извлечение элемента
	void Clear();//очистка очереди
	bool IsEmpty();//проверка на существование элемента в очереди
	bool IsFull();//проверка на переполнение очереди
	int GetCount();//колво элементов в очереди
	void Show();//демонстрация

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