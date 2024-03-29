template<typename T,typename Y>
struct Node{
	T key;
	Y value;
	Node* next;
	Node(T newKey,Y newValue) : key(newKey),value(newValue),next(nullptr){}
};