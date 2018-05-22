#ifndef NODE_H
#define NODE_H
template<typename T>
struct Node {
	T element;
	Node* parent;
	Node* left;
	Node* right;

	Node(T elem) : parent(NULL), left(NULL), right(NULL) {
		element = elem;
	}
};
#endif