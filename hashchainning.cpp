#include<iostream>

using namespace std;

int size=10;

struct node{
    int val;
    struct node *next;
};

void add(int x,node *array[]){
    int key = x%size;
    node *p = new node;
    p->val = x;
    p->next = NULL;

    if(array[key] == NULL){
        array[key] = p;
    }
    else{
        node *curr = new node;
        curr = array[key];
        while(curr->next!=NULL){
            curr = curr->next;
        }
        curr->next = p;
    }
}

void print(node *array[]){
    int i;
    cout<<endl;
    for(i=0;i<size;i++){
        cout<<i<<"  ";
        node *curr = array[i];
        while(curr!=NULL){
            cout<<curr->val<<"  ";
            curr = curr->next;
        }
        cout<<endl;
    }
    cout<<endl;
}

void contain(int val,node *array[]){
    int i,flag=0;
    int key = val%size;
    node *curr = array[key];
    while(curr!=NULL){
        if(val==curr->val){
            cout<<val<<" Element found in key "<<key<<endl;
            flag=1;
            break;
        }
        curr = curr->next;
    }
    if(flag==0){
        cout<<val<<" Element not found"<<endl;
    }
}

void dlt(int val,node *array[]){
    int i,flag=0;
    int key = val%size;
    node *curr = array[key];
    node *prev = NULL;
    while(curr!=NULL){
        if(val==curr->val){
            if(prev==NULL){
                array[key] = curr->next;
            }
            else{
                prev->next = curr->next;
            }
            delete curr;
            break;
        }
        prev = curr;
        curr = curr->next;
    }
}


int main(){

    node *array[size] = {NULL};
    add(5,array);
    add(6,array);
    add(55,array);
    add(53,array);
    add(64,array);
    add(55,array);
    add(21,array);
    add(32,array);
    add(46,array);
    add(63,array);
    add(10,array);
    add(33,array);

    print(array);

    contain(63,array);
//
//    contain(61,array);
//    contain(21,array);
//    contain(55,array);

   // dlt(63,array);
    dlt(33,array);
    add(13,array);

    print(array);

//    contain(63,array);
}
