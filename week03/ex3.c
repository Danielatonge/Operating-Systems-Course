#include <stdio.h>
#include <stdlib.h>

struct LinkedList {
  int value;
  struct node *next;
};

typedef struct LinkedList *node;

node create_node(){
    node temp;
    temp = (node)malloc(sizeof(struct LinkedList));
    temp->next = NULL;
    return temp;
}

void print_list(node head){
  node p;
  p = head;
  while(p != NULL){
    printf("%d - ", p->value);
    p = p->next;
  }
}

node insert_node(node head, int value){
    node temp,p;
    temp = create_node();
    temp->value = value;
    if(head == NULL){
        head = temp;
    }else{
        p = head;
        while(p->next != NULL){
            p = p->next;
        }
        p->next = temp;
    }
    return head;
}

void delete_node() {

}
int main(){
  printf("Hello World!\n");

  return 0;
}
