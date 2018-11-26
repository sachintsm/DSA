#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <stdbool.h>

#define size 10
int listsize = 0;

struct node{
    int key;
    struct node *next;
};

struct node *hasharray[size];
struct node* dummyItem;

int hashfunction(int key){
    int index = key%size;
    return index;
}

int insert(int key){
    struct node *item = (struct node*) malloc(sizeof(struct node));
    item->key = key;

    int hashindex = hashfunction(key);

    while(hasharray[hashindex] != NULL && hasharray[hashindex]->key != -1){
        hashindex++;
        hashindex = hashindex%size;
    }
    hasharray[hashindex] = item;
}

struct node *search(int key) { 
   int hashIndex = hashfunction(key);  
   while(hasharray[hashIndex] != NULL) {
      if(hasharray[hashIndex]->key == key){
          printf("%d is found in index %d\n",key,hashIndex);
         return hasharray[hashIndex]; 
      }
      hashIndex++;
      hashIndex %= size;
   }        
   return NULL;        
}
struct node* delete(struct node* item) {
   int key = item->key;
   int hashIndex = hashfunction(key);
   while(hasharray[hashIndex] != NULL) {	
      if(hasharray[hashIndex]->key == key) {
         struct node* temp = hasharray[hashIndex]; 
         hasharray[hashIndex] = dummyItem; 
         return temp;
      }
      hashIndex++;
      hashIndex %= size;
   }      
   return NULL;        
}



void print(){
    int i = 0;
    for(i=0; i<size; i++){
        if(hasharray[i] == NULL){
            printf("index %d : value NULL\n" ,i);
        }
        else{
            printf("index %d : value %d\n", i,hasharray[i]->key);
        }
    }
}

int main(){
    dummyItem = (struct node*) malloc(sizeof(struct node));
    dummyItem->key = -1; 
    printf("Hello sachin\n");

    insert(5);
    insert(55);
    insert(65);
    print();
    search(65);
    //delete(65);
}