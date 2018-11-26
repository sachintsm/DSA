#include<stdio.h>
#include<stdlib.h>

#define size 10

//create the linked list
struct node{
    int key;
    struct node *next;
    struct node *head;
};

//create the hasharray
struct node *hasharray[size];

struct node *temp;

//hash function
int hashfunction(int key){
    int index = key%size;
    return index;
}

//hash table insert data
int insert(int key){

    int index = hashfunction(key);
    struct node* item = (struct node*) malloc(sizeof(struct node));
    item -> key = key;
    item -> next = NULL;
    if(hasharray[index] == NULL){
        hasharray[index] = item;
    }
    else{
        struct node* curr = (struct node*) malloc(sizeof(struct node));
        curr = hasharray[index];
        while(curr->next != NULL){
            curr = curr->next;
        }
        curr -> next = item;
    }
}
void dlt(int key){
    int index = hashfunction(key);
    struct node *item = (struct node*) malloc(sizeof(struct node));
    struct node *temp = (struct node*) malloc(sizeof(struct node));
    while(item!=NULL){
        if(key == item->key){
            if(temp == NULL){
                hasharray[key] = item->next;
            }
            else{
                temp->next = item->next;
            }
            free(item);
            break;
        }
        temp = item;
        item = item->next;
    }
}

int search(int key){
    int index = hashfunction(key);
    int i=0;
	struct node *temp = (struct node*) malloc(sizeof(struct node));
	temp->key = key;
    for(i=0 ; i<size; i++){
        if(hasharray[i]->key == key){
            printf("Item found");
        }
        else if(i == index){
            temp = temp->next;
            i++;
        }
    }

}
void print(){
    int i = 0;
	for (i = 0; i < size ; i++){
		struct node *temp = hasharray[i];
		if (temp == NULL){
			printf("index %d value : ~~\n",i);
		}
        else{
            printf("index %d value : ",i);
            while (temp != NULL){
                printf("%d\t",temp->key);
                temp = temp->next;
            }   
        printf("\n");
		}
	}
}

int main(){
    struct node* item = (struct node*) malloc(sizeof(struct node));
    printf("helloo1\n");
    insert(55);
    insert(65);
    insert(23);
    insert(50);
    insert(5);
    print();
    search(55);
   // dlt(50);
  //  print();
    return 0;
}
