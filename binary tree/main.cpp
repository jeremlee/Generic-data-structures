#include<iostream>
#include"BinaryTree.h"
using namespace std;

int main(void){
	BinaryTree<int>* tree = new BinaryTree<int>();
	Node<int>* node1 = tree->addRoot(1);
	Node<int>* node2 = tree->addLeft(node1,2);
	Node<int>* node3 = tree->addRight(node1,3);
	tree->preorder();
	cout << endl;
	Node<int>* node4 = tree->addLeft(node2,4);
	tree->removeNode(node4);
	tree->preorder();
	cout << endl;
	cout << "Height of root: " << tree->root->height() << endl;
	Node<int>* node5 = tree->addLeft(node3,4);
	Node<int>* node6 = tree->addRight(node5,5);
	tree->preorder();
	cout << "Height of root: " << tree->root->height() << endl;
	tree->removeNode(node5);
	cout << endl;
	
	tree->preorder();
	cout << "Height of root: " << tree->root->height() << endl;
	cout << "Depth of deepest leaf node: " << node6->depth() << endl;
	return 0;
}