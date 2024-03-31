#include<iostream>
#include<cstdlib>
#include"Node.h"
using namespace std;
template<typename T>

class BinarySearchTree{
	Node<T>* root;
	Node<T>* insertHelper(Node<T>* node, T elem, Node<T>* parent){
		if(!node){
			return new Node<T>(elem, parent);
		}
		if(elem < node->elem){
			node->left = insertHelper(node->left,elem,node);
		} else if(elem > node->elem){
			node->right = insertHelper(node->right,elem,node);
		}
		return node;
	}
	Node<T>* searchHelper(Node<T>* node, T elem){
		if(!node){
			return nullptr;
		}
		if(elem < node->elem){
			return searchHelper(node->left,elem);
		} else if(elem > node->elem){
			return searchHelper(node->right,elem);
		} else if(elem == node->elem){
			return node;
		} else{
			return nullptr;
		}
	}
	void removeHelper(Node<T>* node){
		if(!node){
			cout << "Node null" << endl;
			return;
		}
		if(node->left && node->right){
			Node<T>* leftMost = leftest(node->right);
			swap(node,leftMost);
			if(leftMost->parent != node){
				if(leftMost->right){
					leftMost->parent->left = leftMost->right;
					leftMost->right->parent = leftMost->parent;
				} else{
					leftMost->parent->left = nullptr;
				}
			} else if(leftMost->parent == node){
				if(leftMost->right){
					node->right = leftMost->right;
					leftMost->right->parent = node;
				} else{
					node->right = nullptr;
				}
			}
			delete leftMost;
			return;
		}
		if(node == root){ //if root has only one child
			Node<T>* toDelete = root;
			if(node->left){
				root = node->left;
			} else if(node->right){
				root = node->right;
			}
			delete toDelete;
			toDelete = nullptr;
			return;
		}
		if(node == node->parent->left){
			if(node->left){
				node->parent->left = node->left;
				node->left->parent = node->parent;
			} else if(node->right){
				node->parent->left = node->right;
				node->right->parent = node->parent;
			} else{
				node->parent->left = nullptr;
			}
		} else{
			if(node->left){
				node->parent->right = node->left;
				node->left->parent = node->parent;
			} else if(node->right){
				node->parent->right = node->right;
				node->right->parent = node->parent;
			} else{
				node->parent->right = nullptr;
			}
		}
		delete node;
	}
	Node<T>* leftest(Node<T>* node){
		if(!node){
			return nullptr;
		}
		Node<T>* p = node;
		while(p->left){
			p = p->left;
		}
		return p;
	}
	void swap(Node<T>* a, Node<T>* b){
		T temp = a->elem;
		a->elem = b->elem;
		b->elem = temp;
	}
	void preorder(Node<T>* node){
	    if(!node){
	        return;
	    }
	    cout << node->elem << " ";
	    preorder(node->left);
	    preorder(node->right);
	}
	void inorder(Node<T>* node){
	    if(!node){
	        return;
	    }
	    inorder(node->left);
	    cout << node->elem << " ";
	    inorder(node->right);
	}
	void postorder(Node<T>* node){
	    if(!node){
	        return;
	    }
	    postorder(node->left);
	    postorder(node->right);
	    cout << node->elem << " ";
	}
public:
	BinarySearchTree(){
		root = nullptr;
	}
	void insertNode(T elem){
		root = insertHelper(root,elem,nullptr);
	}
	Node<T>* searchNode(T elem){
		return searchHelper(root,elem);
	}
	void removeNode(T elem){
		Node<T>* toDelete = searchNode(elem);
		if(toDelete){
			removeHelper(toDelete);
		}
	}
	void preorder(){
		preorder(root);
	}
	void inorder(){
		inorder(root);
	}
	void postorder(){
		postorder(root);
	}
};