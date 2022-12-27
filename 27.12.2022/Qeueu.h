#pragma once
#include <iostream>
using namespace std;

class Qeueu {
	int* Wait;//очередь
	int MaxQeueuLength;//максимальнвц размер очереди
	int QeueuLength;//текущий размер очереди

public:
	Qeueu(int m);//конструктор
	~Qeueu();//деструктор
	void Add(int c);//добавление элемента
	int Extract();///извлечение элемента
	void Clear();//очистка очереди
	bool IsEmpty();//проверка на существование элемента в очереди
	bool IsFull();//проверка на переполнение очереди
	int GetCount();//колво элементов в очереди
	void Show();//демонстрация

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