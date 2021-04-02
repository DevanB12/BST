// BST.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <array>
using namespace std;

template <class T>
class Node {
public:
	T value;
	Node* left;
	Node* right;
	Node(T val) {
		value = val;
		left = NULL;
		right = NULL;
	}
	Node(T val, Node<T> left, Node<T> right) {
		value = val;
		left = left;
		right = right;
	}
};
template <class T>
class BST {
private:
	Node<T>* root;
	int heightHelper(Node<T>* root) {
		if (!root) return 0;
		else return 1 + max(heightHelper(root->left), heightHelper(root->right));
	}
	void printHelp(Node<T> *root)
	{
		if (!root) return;
		printHelp(root->left);
		cout << root->value << ' ';
		printHelp(root->right);
	}
	bool deleteValueHelper(Node<T>* parent, Node<T>* current, T value) {
		if (!current) return false;
		if (current->value == value) {
			if (current->left == NULL || current->right == NULL) {
				Node<T>* temp = current->left;
				if (current->right) temp = current->right;
				if (parent) {
					if (parent->left == current) {
						parent->left = temp;
					}
					else {
						parent->right = temp;
					}
				}
				else {
					this->root = temp;
				}
			}
			else {
				Node<T>* validSubs = current->right;
				while (validSubs->left) {
					validSubs = validSubs->left;
				}
				T temp = current->value;
				current->value = validSubs->value;
				validSubs->value = temp;
				return deleteValueHelper(current, current->right, temp);
			}
			delete current;
			return true;
		}
		return deleteValueHelper(current, current->left, value) ||
			deleteValueHelper(current, current->right, value);
	}
public:
	void add(T val) {
	}
	// print items in ascending order
	void print() {
		printHelp(this->root);
	}
	int nodesCount() {

	}
	int height() {
		return heightHelper(this->root);
	}
	bool deleteValue(T value) {
		return this->deleteValueHelper(NULL, this->root, value);
	}
};




int main() {
	const size_t arraySize{ 21 };
	array <string, arraySize> names = { "Martin", "Thapa", "Black", "Bruggeman",
   "Khatri", "Nam", "Echeveste", "McElhannon", "Kilde", "Robertson", "Wilmot",
   "Novacek", "Garten", "Tian", "Ziemann", "Davis", "Corcoran", "Villnow", "Wade", "Buzo" };
	BST<string>* bst = new BST<string>();
	for (size_t i{ 0 }; i < names.size(); ++i)
		bst->add(names[i]);
	bst->print();
	cout << endl;
	cout << "Nodes count: " << bst->nodesCount();
	cout << endl;
	cout << "Height: " << bst->height();
	cout << endl;
	bst->deleteValue("Tian");
	cout << "Tian removed: ";
	bst->print();
	cout << endl;
	bst->deleteValue("Kline");
	cout << "Kline removed: ";
	bst->print();
	cout << endl;
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
