#include<iostream>
#include<string>
#include"priorityqueue.h"
using namespace std;

int main(void){
	PriorityQueue<string,float> pq;
	char op;
	string element;
	float prio;
	while(true){
		cout << "Enter operation: ";
		cin >> op;
		cin.ignore();
		try{
			switch(op){
				case 'e':
					cout << "Enter element: ";
					getline(cin,element);
					cout << "Enter priority: ";
					cin >> prio;
					pq.enqueue(element,prio);
					break;
				case 'd':
					cout << "Removed: " << pq.dequeue() << endl;
					break;
				case 'f':
					cout << "Front of priority queue is: " << pq.first() << endl;
					break;
				case 'p':
					pq.display();
					break;
			}
		}catch(logic_error& e){
			cout << e.what() << endl;
		}
		if(op == 'x'){
			cout << "Exiting...";
			break;
		}
	}
	return 0;
}