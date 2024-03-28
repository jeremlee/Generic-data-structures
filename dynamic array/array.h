#include<iostream>
#include<cstdlib>
using namespace std;

template<typename T>

class ArrayList{
	T* arr;
	int size;
	int capacity;
public:
	ArrayList(){
		size = 0;
		capacity = 5;
		arr = new T[5];
	}
	
	void add(T num){
		if(size > capacity-1){
			cout << "Resizing..." << endl;
			capacity*=1.5;
			arr = (T*)realloc(arr,capacity*sizeof(T));
		} 
		arr[size] = num;
		size++;
		return;
	}
	
	void addAt(T num,int pos){
		if(pos <= 0 || pos > size){
			cout << "Invalid position" << endl;
			return;
		}
		if(size >= capacity-1){
			cout << "Resizing..." << endl;
			capacity*=1.5;
			arr = (T*)realloc(arr,capacity*sizeof(T));
		} 
		for(int i = size-1;i>=pos;i--){
			arr[i+1] = arr[i];
		}
		arr[pos-1] = num;
		size++;
		return;
	}
	
	void removeLast(){
		if(size == 0){
			cout << "List is empty." << endl;
			return;
		}
		arr[size-1] = 0;
		size--;
		if(size <= capacity * (2/3.0)){
			if(capacity > 5){
				cout << "Resizing..." << endl;
			}
			capacity*=0.75;
			if(capacity < 5){
				capacity = 5;
			}
			arr = (T*)realloc(arr,capacity*sizeof(T));
		}
		return;
	}
	
	void removeAt(int pos){
		if(pos <= 0 || pos > size){
			cout << "Invalid position" << endl;
			return;
		}
		for(int i = pos-1; i < size; i++){
			arr[i] = arr[i+1];
		}
		size--;
		if(size <= capacity * (2/3.0)){
			if(capacity > 5){
				cout << "Resizing..." << endl;
			}
			capacity*=0.75;
			if(capacity < 5){
				capacity = 5;
			}
			arr = (T*)realloc(arr,capacity*sizeof(T));
		}
		return;
	}
	
	void removeFirst(){
		if(size == 0){
			return;
		}
		for(int i=0;i<size-1;i++){
			arr[i] = arr[i+1];
		}
		size--;
		if(size <= capacity * (2/3.0)){
			if(capacity > 5){
				cout << "Resizing..." << endl;
			}
			capacity*=0.75;
			if(capacity < 5){
				capacity = 5;
			}
			arr = (T*)realloc(arr,capacity*sizeof(T));
		}
	}
	
	void print(){
		cout << "Capacity: " << capacity << " Size: " << size << endl;
		for(int i=0;i<size;i++){
			cout << arr[i] << " ";
		}
		cout << endl;
		return;
	}
};

