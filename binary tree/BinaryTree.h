#include<iostream>
#include<cstdlib>
#include<stdexcept>
#include"Node.h"
using namespace std;

template<typename T>

class BinaryTree{
public:
	Node<T>* root;
	BinaryTree(){
		root = nullptr;
	}
	
	Node<T>* addRoot(T elem){
		if(root){
			throw logic_error("Root already exists");
		}
		Node<T>* node = new Node<T>(elem);
		root = node;
		return node;
	}
	
	Node<T>* addLeft(Node<T>* parent, T elem){
		if(parent->left){
			throw logic_error("Left child of this node already exists");
		}
		Node<T>* node = new Node<T>(elem,parent);
		parent->left = node;
		return node;
	}
	
	Node<T>* addRight(Node<T>* parent, T elem){
		if(parent->right){
			throw logic_error("Right child of this node already exists");
		}
		Node<T>* node = new Node<T>(elem,parent);
		parent->right = node;
		return node;
	}
	
	void removeNode(Node<T>* node){
		if(!node){
			return;
		}
		if(!node->parent){
			throw logic_error("Cannot remove root");
		}
		if(node->left && node->right){
			throw logic_error("Cannot remove if node has two children");
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
	
	void preorder(Node<T>* node){
	    if(!node){
	        return;
	    }
	    cout << node->elem << " ";
	    preorder(node->left);
	    preorder(node->right);
	}
	
	void preorder(){
		preorder(root);
	}
	
	void inorder(Node<T>* node){
	    if(!node){
	        return;
	    }
	    inorder(node->left);
	    cout << node->elem << " ";
	    inorder(node->right);
	}
	
	void inorder(){
		inorder(root);
	}
	
	void postorder(Node<T>* node){
	    if(!node){
	        return;
	    }
	    postorder(node->left);
	    postorder(node->right);
	    cout << node->elem << " ";
	}
	
	void postorder(){
		postorder(root);
	}
};