#include<iostream>
using namespace std;
int EMPTY = -1;
int DELETED = -2;
int SIZE = 10;
int hashTable[10];
void initHashTable(){
    for(int i = 0; i< SIZE ; i++){
        hashTable[i] = EMPTY;
    }
}
int HashFunction(int key){
    return key % SIZE;
}
void insert(int key){
    int idx= HashFunction(key) ;
    int originalIndex = idx;
    int i = 0;
    while(hashTable[idx]!= EMPTY && hashTable[idx]!= DELETED){
        if(hashTable[idx]==key){
            cout<<"\n Key "<< key << " already exist" <<endl;
            return;
        }
        i++;
        idx = (originalIndex + i * i) %  SIZE;
        if(i == SIZE){
            cout<<" Hash table is full";
            return;
        }
    }
    hashTable[idx]=key;
    cout<< " Key inserted " <<key << " at index " <<idx << endl;
}
void Search(int key){
    int idx =  HashFunction(key);
    int i = 0;
    int originalIndex = idx;
    while(hashTable[idx] != EMPTY){
        if(hashTable[idx] == key){
            cout<< "Key " << key << " found at index " << idx << endl;
            return;
        }
        i++;
        idx = (originalIndex + i* i) % SIZE;

    }
    cout<< " \nKey not found";
}
void Delete(int key){
    int idx = HashFunction(key);
    int i = 0;
    int originalIndex = idx;
    while(hashTable[idx] != EMPTY){
        if (hashTable[idx] == key){
            hashTable[idx] = DELETED;
            cout << " Key " << key << " deleted successfully";
            return;
        }
        i++;
        idx = (originalIndex + i * i ) % SIZE;

    }
    cout<< "\n Key not found";
}
void Display(){
    cout<< "\n Hash Table \n";
    for(int i = 0; i < SIZE; i++){
        if(hashTable[i] != EMPTY){
            cout<< " Key value at index "<< i << " is " <<hashTable[i]<< endl;
        }
        else if(hashTable[i] == EMPTY){
            cout<< "\n NULL";
        }
        else {
            cout<< "\n The table values are deleted";
        }
    }
    cout<< endl;
}
int main(){
    initHashTable();
    int choice;
    int value;
    while(true){
        cout<<"\n1.Insert";
        cout<<"\n2.Search";
        cout<<"\n3.Delete";
        cout<<"\n4.Display";
        cout<<"\n Enter your choice: ";
        cin>>choice;
        switch(choice){
            case 1:
            cout<<"\nEnter the value to insert:  ";
            cin>> value;
            insert(value);
            break;
            case 2: 
            cout<<"\nEnter the value to search: ";
            cin>> value;
            Search(value);
            break;
            case 3:
            cout<<"\nEnter the value to delete: ";
            cin>> value;
            Delete(value);
            break;
            case 4:
            cout<<"\n Displaying results: ";
            Display();
            break;
            default:
            cout<<" \nInvalid choice";

        }

    }
    return 0;
}



