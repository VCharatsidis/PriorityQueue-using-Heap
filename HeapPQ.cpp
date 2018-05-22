#include "VectorCompleteTree.cpp";

template<typename K, typename C>
class HeapPQ {

public:
	int size() {
		return tree.size();
	}

	bool empty() {
		return tree.size() == 0;
	}
	
	void insert(const K& node) {
		tree.add_last(node);
		NodePosition<K> v = tree.last();

		while (!tree.is_root(v)) {
			NodePosition<K> u = tree.get_parent(v);
			
			if (!isLess(*v, *u)) {
				break;
			}

			tree.swap(v, u);
			v = u;
		}
	}

	void remove_min() {
		if (size() == 1) {
			tree.remove_last();
		}

		else {
			NodePosition<K> u = tree.root();
			tree.swap(u, tree.last());
			tree.remove_last();

			while (tree.has_left_child(u)) {
				NodePosition<K> v = tree.get_left_child(u);

				/*if (tree.has_right_child(u) && isLess(*(tree.get_right_child(u), *v))) {
					v = tree.get_right_child(u);
				}*/

				if (isLess(*v, *u)) {
					tree.swap(u, v);
					u = v;
				}

				else {
					break;
				}
			}
		}
	}

	const K& min() {
		return *(tree.root());
	}

private:
	VectorCompleteTree<K> tree;
	C isLess;
};