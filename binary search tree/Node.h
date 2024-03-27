#include<algorithm>
using namespace std;
template<typename T>

struct Node{
	T elem;
	Node* parent;
	Node* left;
	Node* right;
	Node(T element, Node* parentNode):elem(element),left(nullptr),right(nullptr),parent(parentNode){}
	Node(T element):elem(element),left(nullptr),right(nullptr),parent(nullptr){}	
	
	int depth(){
	    if(!parent){
	        return 0;
	    }
	    return 1 + parent->depth();
	}

	int height(){
	    if(!this){
	        return -1;
	    }
	    return 1 + max(left->height(),right->height());
	}
};