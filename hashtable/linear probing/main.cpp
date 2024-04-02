#include<iostream>
#include<string>
#include<cmath>
#include"hashtable.h"
using namespace std;

int stringHasher(string key){
	int hash = 0;
	for(char c : key){
		hash+=c;
	}
	return hash;
}

int polynomialHash(string key){
    int i = key.length()-1, hash = 0;
    for(char c : key){
        hash+=(int)c * pow(2,i);
        i--;
    }
    return hash;
}

int intHasher(int key){
	return key;
}

int doubleHasher(double key){
	return (int)key;
}

int main(void){
	HashTable<string,string>* ht = new HashTable<string,string>(polynomialHash);
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