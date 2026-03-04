#include<iostream>
using namespace std;

#define EMPTY -1
int SIZE = 10;
int DELETED = -2;
int hashTable[10];
// initializing hash table
void initHashTable(){
    for(int i = 0; i < 10 ; i++) {
        hashTable[i] = EMPTY;
    }
    cout<< "\n Hash Table initialized";
}
// Now for hash Function
int HashFunction(int key){
    return key % SIZE;
}
// For inserting values
void insert(int key){
int idx = HashFunction(key);
int OriginalIndx = idx;
int i = 0; // counter 
// Linear probing
while((hashTable[idx]!= EMPTY) && (hashTable[idx]!= DELETED)) {
    if(hashTable[idx]== key){
        cout<< "\n Key" << key << " already exist" << endl;
    }
    i++;
    idx = (hashTable[idx] + i) % SIZE;
    if(i == SIZE) {
        cout<< "Hash table is full";
        return;
    }
}
hashTable[idx]= key;
cout<< "Inserted "<< key << " at index "<<idx << endl;
}
void Search(int key){
    int idx = HashFunction(key);
    int i = 0;
    int originalIndex = idx;
    while(hashTable[idx]!= EMPTY){
            if(hashTable[idx] == key){
                cout<< "Key " << key << " Found at index: " << idx << endl;
            }
            i++;
            idx = (originalIndex + i ) % SIZE;
    }
    cout<< "\nKey not found";
    
}
void display() {
    cout<<"\n Hash Table \n";
    for(int i = 0; i < SIZE; i ++){
        if(hashTable[i]!= EMPTY) {
        cout<< "\nKey value at index " << i << " is: " <<  hashTable[i] << endl;
        }
        else if(hashTable[i]== EMPTY){
            cout<<"\n NULL";
        }
        else {
            cout<<"\n The table values are deleted";
        }
    }
    cout<<endl;
}
void Delete(int key) {
    int idx = HashFunction(key);
    int originalIndex = idx;
    int i = 0;
    while (hashTable[idx]!= EMPTY){
        if(hashTable[idx]== key){
        hashTable[idx] = DELETED;
        cout<<"\n Value successfully deleted";
        return;
        }
        i++;
        idx = (originalIndex + i) % SIZE;
    }
    cout<< "\n Value not found";
}
int main() {
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
            display();
            break;
            default:
            cout<<" \nInvalid choice";

        }

    }
    return 0;
}
