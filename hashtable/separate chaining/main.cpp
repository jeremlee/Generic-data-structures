#include<iostream>
#include<string>
#include"hashtable.h"
using namespace std;

int stringHasher(string key, int capacity){
	int hash = 0;
	for(char c : key){
		hash+=c;
	}
	return hash%capacity;
}

int string_djb2Hash(string key, int capacity) {
    unsigned long hash = 5381;
    for (char c : key) {
        hash = ((hash << 5) + hash) + c; 
    }
    return (int)(hash % capacity);
}

int intHasher(int key,int capacity){
	return key%capacity;
}

int doubleHasher(double key, int capacity){
	return (int)key%capacity;
}

int main(void){
	HashTable<string,string>* ht = new HashTable<string,string>(string_djb2Hash);
	string input1;
	string input2;
	char op;
	while(true){
		cout << "Enter operation: ";
		cin >> op;
		cin.ignore();
		try{
			switch(op){
				case 'a':
					cout << "Enter key: ";
					getline(cin,input1);
					cout << "Enter value: ";
					getline(cin,input2);
					ht->add(input1,input2);
					break;
				case 'f':
					cout << "Enter key: ";
					getline(cin,input1);
					cout << "Element: " << ht->getElement(input1) << endl;
					break;
				case 'r':
					cout << "Enter key: ";
					getline(cin,input1);
					ht->remove(input1);
					break;
				case 'd':
					ht->display();
					break;
			}
			if(op == 'x'){
				cout << "Exiting...";
				break;
			}
		}catch(logic_error& e){
			cout << e.what() << endl;
		}
	}
	return 0;
}