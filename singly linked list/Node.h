template<typename T>
struct Node{
	T data;
	Node* next;
	Node(T newData) : data(newData),next(nullptr){}
	Node(T newData, Node* nextNode) : data(newData),next(nextNode){}
};