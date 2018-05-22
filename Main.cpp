#include <iostream>;
#include <string>;
#include <bitset>;
#include "Comparator.cpp";
#include "HeapPQ.cpp";

using std::vector;
using std::cout;


int main() {

	Box* a = new Box(1, 2);
	Box* b = new Box(2, 3);
	Box* c = new Box(3, 4);
	Box* d = new Box(4, 5);

	a->available_values = 0b1011;
	b->available_values = 0b100000000000000000001;
	c->available_values = 0b110011;
	d->available_values = 0b1;

	HeapPQ<Box*, Comparator> pq;

	pq.insert(a);
	pq.insert(b);
	pq.insert(c);
	pq.insert(d);

	while (!pq.empty()) {
		Box* k = pq.min();
		cout << std::bitset<25>(k->available_values) << std::endl;
		pq.remove_min();
	}

	return 0;
}