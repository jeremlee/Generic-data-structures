#include<iostream>
#include<cstdlib>
#include"Node.h"
using namespace std;


template<typename T>
class LinkedList{
	Node<T>* head;
	Node<T>* tail;
	int size;
public:
	LinkedList(){
		head = nullptr;
		tail = nullptr;
		size = 0;
	}
	void add(T num){
		Node<T>* node = new Node<T>(num);
		if(!head){
			node->previous = nullptr;
			head = node;
		} else{
			node->previous = tail;
			tail->next = node;
		}
		tail = node;
		size++;
		return;
	}
	void addHead(T num){
		if(!head){
			add(num);
			return;
		}
		Node<T>* node = new Node<T>(num,head,nullptr);
		head->previous = node;
		head = node;
		size++;
		return;
	}
	void addAt(T num, int pos){
		if(pos == 1){
			add(num);
			return;
		}
		if(pos <= 0){
			cout << "Invalid position" << endl;
			return;
		}
		if(pos == size+1){
			add(num);	
			return;
		} 
		Node<T>* p = head;
		int count = 1;
		while(count < pos){
			p = p->next;
			count++;
		}
		Node<T>* node = new Node<T>(num,p,p->previous);
		p->previous->next = node;
		p->previous = node;
		size++;
		return;
	}
	void remove(){
		if(!head){
			cout << "List is empty" << endl;
			return;
		}
		if(!tail->previous){
			Node<T>* temp = tail;
			tail = nullptr;
			head = nullptr;
			delete temp;
			size--;
			return;
		}
		Node<T>* temp = tail;
		tail = temp->previous;
		tail->next = nullptr;
		free(temp);
		size--;
		return;
	}
	void removeHead(){
		if(!head){
			cout << "List is empty" << endl;
			return;
		}
		if(size == 1){
			delete head;
			head = nullptr;
			tail = nullptr;
			size--;
			return;
		}
		Node<T>* temp = head;
		head = head->next;
		head->previous = nullptr;
		delete temp;
		size--;
		return;
	}
	void removeAt(int pos){
		if(!head){
			cout << "List is empty" << endl;
			return;
		}
		if(pos == 1){
			removeHead();
			return;
		}
		if(pos == size){
			remove();
			return;
		}
		int count = 1;
		Node<T>* p = head;
		while(count < pos){
			p = p->next;
			count++;
		}
		Node<T>* temp = p;
		temp->next->previous = temp->previous;
		temp->previous->next = temp->next;
		delete temp;
		size--;
		return;
	}
	
	void display(){
		Node<T>* p = head;
		cout << "Size: " << size << endl;
		while(p){
			cout << p->data << " ";
			p = p->next;
		}
		cout << endl;
		return;
	}

};