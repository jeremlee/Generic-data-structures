#include<iostream>
#include<vector>
#include<type_traits>
#include<algorithm>
#include<stdexcept>
#include"Element.h"
using namespace std;
template<typename T, typename Y,typename = typename enable_if<is_arithmetic<Y>::value>::type>

class PriorityQueue{
	vector<Element<T,Y>> arr;
public:
	void enqueue(T element, Y prio){
		Element<T,Y> var;
		var.elem = element;
		var.priority = prio;
		arr.push_back(var);
		sort(arr.begin(),arr.end(),[](Element<T,Y> a, Element<T,Y> b){
			return a.priority < b.priority;
		});
	}
	T dequeue(){
		if(arr.empty()){
			throw logic_error("nothing because priority queue is empty!");
		}
		T toReturn = arr.front().elem;
		arr.erase(arr.begin());
		return toReturn;
	}
	T first(){
		if(arr.empty()){
			throw logic_error("nothing because priority queue is empty!");
		}
		return arr.front().elem;
	}
	void display(){
		if(arr.empty()){
			throw logic_error("Priority Queue is empty!");
		}
		for(Element<T,Y> e : arr){
			cout << "Element: " << e.elem << " || Priority: " << e.priority << endl;
		}
	}
};