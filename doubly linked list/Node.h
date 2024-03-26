template<typename T>

struct Node{
	T data;
	Node* next;
	Node* previous;
	Node(T newData) : data(newData),next(nullptr),previous(nullptr){}
	Node(T newData, Node* nextNode, Node* previousNode) : data(newData),next(nextNode),previous(previousNode){}
};