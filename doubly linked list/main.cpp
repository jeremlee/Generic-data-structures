#include<iostream>
#include<cstdlib>
#include"LinkedList.h"
using namespace std;

int main(void){
	LinkedList<int>* list = new LinkedList<int>();
	char op;
	int num,pos;
	while(true){
		cout << "Enter operation: ";
		cin >> op;
		switch(op){
			case 'a': //add
				cin >> num;
				list->add(num);
				break;
			case 'e': //addHead
				cin >> num;
				list->addHead(num);
				break;
			case '@': //addAt
				cin >> num >> pos;
				list->addAt(num,pos);
				break;
			case 'r': //remove
				list->remove();
				break;
			case 'v': //removeHead
				list->removeHead();
				break;
			case 'w': //removeAt
				cin >> pos;
				list->removeAt(pos);
				break;
			case 'd': //display list
				list->display();
				break;
		}
	}
	
	return 0;
}