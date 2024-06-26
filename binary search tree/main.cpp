#include<iostream>
#include<cstdlib>
#include"binarysearchtree.h"
using namespace std;

int main(void){
	BinarySearchTree<int>* bst = new BinarySearchTree<int>();
	Node<int>* n = nullptr;
	char op;
	int num;
	while(true){
		cout << "Enter operation: ";
		cin >> op;
		switch(op){
			case 'a':
				cin >> num;
				bst->insertNode(num);
				break;
			case 's':
				cin >> num;
				n = bst->searchNode(num);
				if(n){
					cout << "Found "<< n->elem << endl;
				}
				n = nullptr;
				break;
			case 'r':
				cin >> num;
				bst->removeNode(num);
				break;
			case 'd':
				bst->preorder();
				cout << endl;
				break;
		}
		if(op == 'x'){
			cout << "Exiting...";
			break;
		}
	}
	
	return 0;
}