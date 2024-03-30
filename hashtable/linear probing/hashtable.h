#include<iostream>
#include<cstdlib>
#include<functional>
#include<stack>
#include<stdexcept>
#include"Node.h"
using namespace std;

template<typename T,typename Y>

class HashTable{
	Node<T,Y>** list;
	int capacity, size;
	function<int(const T&,int)> hash;
	void initialize(){
		for(int i=0;i<capacity;i++){
			list[i] = nullptr;
		}
	}
	int findNextPrime(int n){
		int prime = n+1;
		while(!isPrime(prime)){
			prime++;
		}
		return prime;
	}
	bool isPrime(int n) {
		if(n == 0||n == 1){
		    return false;
		}
		for(int i=2;i<=n/2;i++){
			if(n%i == 0) {
				return false;
			}
		}
		return true;
	}
	stack<Node<T,Y>*> getAll(){
		stack<Node<T,Y>*> elements;
		for(int i=0;i<capacity;i++){
			if(!list[i]){
				continue;
			}
			elements.push(list[i]);
		}
		return elements;
	}
	void grow(){
		stack<Node<T,Y>*> elements = getAll();
		capacity = findNextPrime(capacity);
		reHash(elements);
	}
	void shrink(){
		stack<Node<T,Y>*> elements = getAll();
		capacity = findNextPrime(size-1);
		if(capacity < 5){
			capacity = 5;
		}
		reHash(elements);
	}
	void reHash(stack<Node<T,Y>*> elements){ 
		delete[] list;
		list = new Node<T,Y>*[capacity];
		initialize();
		Node<T,Y>* temp;
		while(!elements.empty()){
			temp = elements.top();
			int idx = hash(temp->key,capacity);
			if(!list[idx]){
				list[idx] = new Node<T,Y>(temp->key,temp->value);
			}else{
				while(list[idx]){
					idx++;
					if(idx >= capacity){
						idx = 0;
					}
				}
				list[idx] = new Node<T,Y>(temp->key,temp->value);
			}
			elements.pop();
		}
	}	
	
	bool checkDuplicate(T key, Y value, int idx){
		int oldIdx = idx-1;
		if(list[oldIdx] && list[oldIdx]->key == key){
			list[oldIdx]->value = value;
			return true;
		}
		if(list[idx]&&list[idx]->key == key){
			list[idx]->value = value;
			return true;
		}
		while(true){
			idx++;
			if(idx >= capacity){
				idx = 0;
			}
			if(idx == oldIdx){
				break;
			}
			if(!list[idx]){
				continue;
			}
			if(list[idx]->key == key){
				list[idx]->value = value;
				return true;
			}
		}
		return false;
	}
	void removeHelper(int idx){
		list[idx] = nullptr;
		size--;
		if(size <= capacity*0.75){
			shrink();
		}
	}
public:
	HashTable(function<int(const T&,int)> customHash){
		hash = customHash;
		capacity = 5;
		size = 0;
		list = new Node<T,Y>*[capacity];
		initialize();
	}
	
	void add(T key, Y value){
		int oldIdx = hash(key,capacity);
		if(checkDuplicate(key,value,oldIdx)){
			return;
		}
		if(size == capacity){
			grow();
		}
		int idx = hash(key,capacity);
		if(!list[idx]){
			list[idx] = new Node<T,Y>(key,value);
		}else{
			while(list[idx]){
				idx++;
				if(idx >= capacity){
					idx = 0;
				}
			}
			list[idx] = new Node<T,Y>(key,value);
		}
		size++;
	}
	
	Y getElement(T key){
		int idx = hash(key,capacity);
		int oldIdx = idx-1;
		while(true){
			if(list[idx]){
				if(list[idx]->key == key){
					return list[idx]->value;
				}
			}
			idx++;
			if(idx >= capacity){
				idx = 0;
			}
			if(idx == oldIdx){
				break;
			}
		}
		throw logic_error("Not found");
	}
	
	void remove(T key){
		bool removed = false;
		int idx = hash(key,capacity);
		int oldIdx = idx-1;
		if(list[idx] && list[idx]->key == key){
			removeHelper(idx);
			return;
		}
		while(true){
			idx++;
			if(idx >= capacity){
				idx = 0;
			}
			if(idx == oldIdx){
				break;
			}
			if(!list[idx]){
				continue;
			}
			if(list[idx]->key == key){
				removeHelper(idx);
				removed = true;
				break;
			}else{
				continue;
			}
		}
		if(!removed){
			throw logic_error("No such element!");
		}
	}
	
	void display(){
		cout << "Size: " << size << " Capacity: " << capacity << endl;
		for(int i=0;i<capacity;i++){
			if(!list[i]){
				continue;
			}
			cout << "Index: " << i << " Key: " << list[i]->key << " | Value: " << list[i]->value << endl;
		}
	}
	
};