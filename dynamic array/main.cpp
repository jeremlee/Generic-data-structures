#include<iostream>
#include"array.h"
using namespace std;

int main(void){
	ArrayList<float>* list = new ArrayList<float>();
	int pos;
	float num;
	char op;
	do{
		cout << "Enter operation: ";
		cin >> op;
		switch(op){
			case 'a':
				cin >> num;
				list->add(num);
				break;
			case 'r':
				list->removeLast();
				break;
			case '@':
				cin >> num;
				cin >> pos;
				list->addAt(num,pos);
				break;
			case 'R':
				cin >> pos;
				list->removeAt(pos);
				break;
			case 'f':
				list->removeFirst();
				break;
			case 'p':
				list->print();
				break;
		}
	}while(op!= 'x');
	
	return 0;
}