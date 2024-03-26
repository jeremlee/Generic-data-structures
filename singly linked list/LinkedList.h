#include<iostream>
#include<cstdlib>
#include"Node.h"
using namespace std;

template<typename T>

class LinkedList{
	int size;
	Node<T>* head;
	Node<T>* tail;
public:
	LinkedList(){
		size = 0;
		head = nullptr;
		tail = nullptr;
	}
	void add(T data){
		Node<T>* node = new Node<T>(data);
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
		Node<T>* current = head;
		int count = 1;
		while(current && count < position - 1){
			current = current->next;
			count++;
		}
		Node<T>* temp = current->next;
		current->next = temp->next;
		if(!temp->next){
			current->next = nullptr;
			tail = current;
		}
		delete temp;
		size--;
	}
	
	void addAt(T data, int position){
		if(!head || position<=0){
			cout << "No" << endl;
			return;
		}
		if(position == 1){
			addHead(data);
			return;
		}
		Node<T>* current = head;
		int count = 1;
		while(current && count < position-1){
			current = current->next;
			count++;
		}
		Node<T>* node = new Node<T>(data,current->next);
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
		Node<T>* temp = head;
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
		Node<T>* temp = head;
		while(temp->next != tail){
			temp = temp->next;
		}
		delete tail;
		temp->next = nullptr;
		tail = temp;
		size--;
	}

	void addHead(T data){
		Node<T>* node = new Node<T>(data,head);
		head = node;
		size++;
	}
	
	void display(){
		cout << "Size: " << size << endl;
		Node<T>* temp = head;
		while(temp){
			cout << temp->data << " ";
			temp=temp->next;
		}
		cout << endl;
	}
	
};
