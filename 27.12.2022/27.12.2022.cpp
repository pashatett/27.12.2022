#include <iostream>
using namespace std;

/*#include "Qeueu.h"
int main() {
	srand(time(0));

	Qeueu qu{25};
	for (int i{ 0 }; i < 5; i++) {
		qu.Add(rand() % 50);
	}
	qu.Show();
	qu.Extract();
	qu.Show();
}*/

#include "QeueuPriority.h"
int main() {
	srand(time(0));
	QeueuPriority qu(25);
	for (int i{ 0 }; i < 5; i++) {
		qu.Add(rand() % 50, rand() % 10);
	}
	qu.Show();
	qu.Extract();
	qu.Show();
}