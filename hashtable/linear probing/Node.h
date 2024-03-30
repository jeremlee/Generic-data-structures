template<typename T,typename Y>
struct Node{
	T key;
	Y value;
	Node(T newKey,Y newValue) : key(newKey),value(newValue){}
};