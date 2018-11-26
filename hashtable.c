#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

#define size 10

struct node{
    int key;
};

struct node *htable[size];
struct node *temp;

int function(int key){
    int index = key%size;
    return index;
}

int insert(int key){
    int index = function(key);
    struct node* item = (struct node*) malloc(sizeof(struct node));
    item -> key = key;

    while(htable[index] != NULL && htable[index] -> key != -1){
        index++;
    }
    htable[index] = item;
}

struct node *search(int key){
    int index = function(key);
    while(htable[index] != NULL){
        if(htable[index]->key = key){
            printf("%d found in index %d\n",key,index);
            return htable[index];
        }
        else{
            index++;
        }
    }
}
void dlt(int key){
    int index = function(key);
    struct node* item = (struct node*) malloc(sizeof(struct node));
    item->key = key;
    while(htable[index] != NULL){
        if(htable[index] -> key == key){
            htable[index] = NULL;
        }
        else{
            index++;
        }
    }
}

void print(){
    int i;
    for(i=0; i<size ; i++){
        if(htable[i] == NULL){
            printf("index %d value : ~~\n",i);
        }
        else{
            printf("index %d value : %d\n",i, htable[i]->key);
        }
    }
}

int main(){
    insert(10);
    insert(20);
    insert(55);
    print();
    search(55);
    dlt(55);
    print();
    insert(55);
    print();
}