#include<iostream>
#include"heap.h"
using namespace std;

int main(void){
	Heap<int>* heap = new Heap<int>();
	char op;
	int num;
	while(true){
		cout << "Enter operation: ";
		cin >> op;
		try{
			switch(op){
				case 'a':
					cin >> num;
					heap->insert(num);
					break;
				case 'r':
					cout << "Removed: " << heap->remove() << endl;
					break;
				case 'd':
					heap->display();
					break;
			}
			if(op == 'x'){
				break;
			}
		}catch(logic_error& e){
			cout << e.what() << endl;
		}
	}
	return 0;
}