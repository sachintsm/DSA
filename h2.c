#include<stdlib.h>
#include<stdio.h>

#define size 10

struct node{
    int key;
};

struct node *array[size];

int fun(int key){
    int index = key%size;
    return index;
}

int insert(int key){
    int index = fun(key);
    struct node *item = (struct node*)malloc(sizeof(struct node));

    item->key = key;
    while(array[index] != NULL && array[index] -> key != -1){
        index++;
        index = index%size;
    }
    array[index] = item;
}
struct node *search(int key){
    int index = fun(key);
    while(array[index] != NULL){
        if(array[index]-> key == key){
            printf("Item found");
            return array[index];
        }else{
            index++;
            index = index%size;
        }
    }

}
void dlt(int key){
    int index = fun(key);
    struct node *item = (struct node*)malloc(sizeof(struct node));
    item->key = key;
    while(array[index] != NULL){
        if(array[index]->key == key ){
            array[index] = NULL;
        }
        else{
            index++;
            index = index%size;
        }
    }
}

void print(){
    int i;
    for(i=0;i<size; i++){
        if(array[i] == NULL){
            printf("NUll\n");
        }
        else{
            printf("%d index val %d\n",i, array[i]->key);
        }
    }
}

int main(int argc, char const *argv[])
{
    insert(55);
    insert(62);
    insert(65);
    print();
    search(62);
    dlt(62);
    print();
    return 0;
}
