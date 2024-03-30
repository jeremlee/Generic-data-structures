#include<iostream>
#include<cstdlib>
#include<functional>
#include<stack>
#include<stdexcept>
#include"LinkedList.h"
using namespace std;

template<typename T,typename Y>

class HashTable{
	LinkedList<T,Y>** list;
	int capacity, size;
	function<int(const T&,int)> hash;
	void initialize(){
		for(int i=0;i<capacity;i++){
			list[i] = new LinkedList<T,Y>();
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
			if(!list[i] || !list[i]->getHead()){
				continue;
			}
			Node<T,Y>* current = list[i]->getHead();
			while(current){
				elements.push(current);
				current = current->next;
			}
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
		list = new LinkedList<T,Y>*[capacity];
		initialize();
		Node<T,Y>* temp;
		while(!elements.empty()){
			temp = elements.top();
			int idx = hash(temp->key,capacity);
			list[idx]->add(temp->key,temp->value);
			elements.pop();
		}
	}	
	
	bool checkDuplicate(T key, Y value, int idx){
		Node<T,Y>* current = list[idx]->getHead();
		while(current){
			if(current->key == key){
				current->value = value;
				return true;
			}
			current = current->next;
		}
		return false;
	}
public:
	HashTable(function<int(const T&,int)> customHash){
		hash = customHash;
		capacity = 5;
		size = 0;
		list = new LinkedList<T,Y>*[capacity];
		initialize();
	}
	
	void add(T key, Y value){
		int idx = hash(key,capacity);
		if(!checkDuplicate(key,value,idx)){
			if(size == capacity){
				grow();
			}
			list[idx]->add(key,value);
			size++;
		}
	}
	
	Y getElement(T key){
		int idx = hash(key,capacity);
		Node<T,Y>* current = list[idx]->getHead();
		while(current){
			if(current->key == key){
				return current->value;
			}
			current = current->next;
		}
		throw logic_error("not found!");
	}
	
	void remove(T key){
		int idx = hash(key,capacity);
		list[idx]->removeNode(key);
		size--;
		if(size <= capacity*0.75){
			shrink();
		}
	}
	
	void display(){
		cout << "Size: " << size << " Capacity: " << capacity << endl;
		for(int i=0;i<capacity;i++){
			if(!list[i] || !list[i]->getHead()){
				continue;
			}
			Node<T,Y>* current = list[i]->getHead();
			while(current){
				cout << "Index: " << i << " Key: " << current->key << " | Value: " << current->value << endl;
				current = current->next;
			}
		}
	}
	
};