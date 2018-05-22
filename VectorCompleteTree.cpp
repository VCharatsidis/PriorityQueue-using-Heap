#ifndef VECTORCOMPLETETREE_H // Use a unique identifier for every file.
#define VECTORCOMPLETETREE_H
#include <vector>
#include "NodePosition.cpp"

using std::vector;

template<typename T>
class VectorCompleteTree {
private:
	vector<T> nodes;

protected:

	NodePosition<T> position(int i) {
		return nodes.begin() + i;
	}

	int idx(const NodePosition<T>& p) const {
		return p - nodes.begin();
	}

public:
	//typedef typename std::vector<T>::iterator NodePosition<T>;

	VectorCompleteTree() : nodes(1) {

	}

	int size() const {
		return nodes.size() - 1;
	}

	NodePosition<T> get_left_child(const NodePosition<T>& node_position) {
		return position(idx(node_position)*2);
	}

	NodePosition<T> get_right_child(const NodePosition<T>& node_position) {
		return position(idx(node_position) * 2 + 1);
	}

	NodePosition<T> get_parent(const NodePosition<T>& node_position) {
		return position(idx(node_position)/2);
	}

	bool has_left_child(const NodePosition<T>& p) {
		return 2 * idx(p) <= size();
	}

	bool has_right_child(const NodePosition<T>& p) {
		return 2 * idx(p) + 1 <= size();
	}

	bool is_root(const NodePosition<T>& p) {
		return idx(p) == 1;
	}

	void add_last(const T& node) {
		nodes.push_back(node);
	}

	void remove_last() {
		nodes.pop_back();
	}
	//TO DO check if works;
	void swap(const NodePosition<T>& p, const NodePosition<T>& q) {
		swap(p, q);
	}

	NodePosition<T> last() {
		return position(size());
	}

	NodePosition<T> root() {
		return position(1);
	}

};
#endif