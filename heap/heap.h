#include<iostream>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<vector>
#include<stdexcept>
using namespace std;

template<typename T>

class Heap{
	vector<T> arr;
	void bubbleUp(int idx){
		if(idx <= 0){
			return;
		}
		int parentIdx = floor((idx-1)/2.0);
		if(arr[idx] < arr[parentIdx]){
			swap(arr[idx],arr[parentIdx]);
			bubbleUp(parentIdx);
		}
	}
	void bubbleDown(int idx){
		if(idx >= arr.size()){
			return;
		}
		int left = 2*idx+1;
		int right = 2*idx+2;
		int chosenChild = idx;
		if(left < arr.size() && arr[left] < arr[chosenChild]){
			chosenChild = left;
		}
		if(right < arr.size() && arr[right] < arr[chosenChild]){
			chosenChild = right;
		}
		if(chosenChild == idx){
			return;
		} else{
			swap(arr[idx],arr[chosenChild]);
			bubbleDown(chosenChild);
		}
	}
public:
	void insert(T elem){
		arr.push_back(elem);
		bubbleUp(arr.size()-1);
	}
	T remove(){
		if(arr.empty()){
			throw logic_error("nothing because heap is empty!");
		}
		T toReturn = arr[0];
		swap(arr[0],arr[arr.size()-1]);
		arr.pop_back();
		bubbleDown(0);
		return toReturn;		
	}
	void display(){
		if(arr.empty()){
			throw logic_error("Heap is empty!");
		}
		for(T t : arr){
			cout << t << " ";
		}
		cout << endl;
	}
};