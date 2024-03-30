#include<iostream>
#include<stdexcept>
#include<cstdlib>
#include"Node.h"
using namespace std;

template<typename T, typename Y>

class LinkedList{
	int size;
	Node<T,Y>* head;
	Node<T,Y>* tail;
public:
	LinkedList(){
		size = 0;
		head = nullptr;
		tail = nullptr;
	}
	void add(T key,Y value){
		Node<T,Y>* node = new Node<T,Y>(key,value);
		if(!head){
			head = node;
		} else{
			tail->next = node;
		}
		tail = node;
		tail->next = nullptr;
		size++;
		return;
	}
	
	void removeAt(int position){
		if(!head || position<=0){
			cout << "No" << endl;
			return;
		}
		if(position == 1){
			removeHead();
			return;
		}
		if(position == size){
			removeHead();
			return;
		}
		Node<T,Y>* current = head;
		int count = 1;
		while(current && count < position - 1){
			current = current->next;
			count++;
		}
		Node<T,Y>* temp = current->next;
		current->next = temp->next;
		if(!temp->next){
			current->next = nullptr;
			tail = current;
		}
		delete temp;
		size--;
	}
	
	void addAt(T key, Y value, int position){
		if(!head || position<=0){
			cout << "No" << endl;
			return;
		}
		if(position == 1){
			addHead(key,value);
			return;
		}
		Node<T,Y>* current = head;
		int count = 1;
		while(current && count < position-1){
			current = current->next;
			count++;
		}
		Node<T,Y>* node = new Node<T,Y>(key,value,current->next);
		if(!current->next){
			node->next = nullptr;
			tail = node;
		}
		current->next = node;
		size++;
	}
	
	void removeHead(){
		if(!head){
			return;
		}
		if(size == 1){
			size--;
			delete head;
			head = nullptr;
			tail = nullptr;
			return;
		}
		Node<T,Y>* temp = head;
		head = head->next;
		size--;
		delete temp;
	}
	
	void remove(){
		if(!head){
			return;
		}
		if(size == 1){
			size--;
			delete head;
			head = nullptr;
			tail = nullptr;
			return;
		}
		Node<T,Y>* temp = head;
		while(temp->next != tail){
			temp = temp->next;
		}
		delete tail;
		temp->next = nullptr;
		tail = temp;
		size--;
	}
	
	void removeNode(T key){
		if(!head){
			throw logic_error("Key not found!");
		}
		bool delay = false;
		bool found = false;
		Node<T,Y>* current = head;
		Node<T,Y>* delayed = head;
		while(current){
			if(current->key == key){
				found = true;
				break;
			}
			current = current->next;
			if(!delay){
				delay = true;
			} else{
				delayed = delayed->next;
			}
		}
		if(!found){
			throw logic_error("Key not found!");
		}
		if(current == head){
			removeHead();
			return;
		}
		if(!current->next){
			remove();
			return;
		}
		delayed->next = current->next;
		delete current;
		size--;
	}

	void addHead(T key,Y value){
		Node<T,Y>* node = new Node<T,Y>(key,value,head);
		head = node;
		size++;
	}
	
	Node<T,Y>* getHead(){
		if(!head){
			return nullptr;
		}
		return head;
	}
	
	
};
