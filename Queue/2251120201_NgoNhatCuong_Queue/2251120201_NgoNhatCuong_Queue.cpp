#include <iostream>
#include "queue.h"

using namespace std;

int main() {
	queue* q = new queue();
	for (int i = 0; i < 3; i++) {
		int input; cout << "Nhap gia tri: "; cin >> input;
		q->enqueue(input);
	}

	/*for (int i = 0; i < 4; i++) q->dequeue();*/
	q->dequeue();
	if (q->check()) q->print();
	else cout << "QUEUE RONG, KHONG LAY DUOC PHAN TU";

	return 0;
}