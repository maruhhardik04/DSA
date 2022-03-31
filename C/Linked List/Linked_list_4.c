#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Node{

  int data;
 struct Node *next;

}Node;



Node *createNewNode();
Node *insertAtHead(Node **head,Node *node_to_insert);
void insertAtEnd(Node *head,Node *node_to_insert);
Node *search(Node *head,int value);
void printList(Node *node);

Node *createNewNode(){
    int val;
    printf("Enter Value:");
    scanf("%d",&val);

    Node *node=malloc(sizeof(Node));
    node->data=val;
    node->next=NULL;
    
    return node;
    
}

Node *insertAtHead(Node **head,Node *node_to_insert){
    node_to_insert->next=*head;
    *head=node_to_insert;
    return node_to_insert;
}

void insertAtEnd(Node *head,Node *node_to_insert)
{
    Node *tmp=head;
     while (tmp->next != NULL)
     {
         tmp=tmp->next;
     }
     tmp->next=node_to_insert;    
}

Node *search(Node *head,int value)
{
     Node *tmp=head;
     while(tmp->data != value && tmp->next != NULL)
     {
        tmp=tmp->next;
     }
     return tmp;
}

void printList(Node *node)
{
    Node *tmp=node;
    
    while(tmp !=  NULL)
    {
        printf("%d==>",tmp->data);
        tmp=tmp->next;
    }
    printf("NULL");
    printf("\n");
}


int main()
{

    Node *tmp;
    Node *head=createNewNode();
    insertAtEnd(head,createNewNode());
    printList(head);
    
    insertAtEnd(head,createNewNode());
    printList(head);
     
    insertAtEnd(head,createNewNode());
    printList(head);
    
     tmp=search(head,13);
     
    printf("%d is %s",13,((tmp->data == 13)?"Found":"Not Found"));

    return 0;
}
