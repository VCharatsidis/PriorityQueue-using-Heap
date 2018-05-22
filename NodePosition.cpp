#ifndef NODEPOSITION_H // Use a unique identifier for every file.
#define NODEPOSITION_H
#include "Node.cpp";

template<typename T>
class NodePosition {
private:
	Node<T>* v;
public:
	NodePosition(Node<T>* _v = NULL) : v(_v) {

	}
	T& operator*() {
		return v->element;
	}

	NodePosition parent() const {
		return NodePosition(v->parent);
	}

	NodePosition left_child() const{
		return NodePosition(v->left);
	}

	NodePosition right_child() const {
		return NodePosition(v->right);
	}
	
	bool is_leaf() {
		return ((v->left == NULL) && (v->rigth == NULL));
	}

	bool has_left_child() {
		return v->left == NULL;
	}

	bool has_right_child() {
		return v->rigth == NULL;
	}

	bool is_root() {
		return v->parent == NULL;
	}
};

#endif