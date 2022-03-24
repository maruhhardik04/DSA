#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<stdbool.h>

typedef struct Queue
{
    unsigned Size;
    int *queue;
    int rear;
    int front;
}Queue;


Queue* creatQueue();
bool isFull(Queue* self);
bool isEmpty(Queue* self);
void insertAnElement(Queue* self);
void removeAnElement(Queue* self);

Queue* creatQueue()
{
    unsigned Size;
    printf("Enter Size of the Queue:");
    scanf("%u",&Size); 

    Queue* queue=(Queue*)malloc(sizeof(Queue));
    queue->Size=Size;
    queue->front=-1;
    queue->rear=-1;
    queue->queue=(int*)malloc(queue->Size*sizeof(int));
    return queue;
}

bool isFull(Queue* self)
{
    return self->rear==self->Size-1;
}

bool isEmpty(Queue* self)
{
    return self->front==-1;
}

void insertAnElement(Queue* self)
{

    int val;
    if(!isFull(self))
    {
    printf("Enter A value into Queue:");
    scanf("%d",&val);
    
    if(self->rear ==-1 && self->front== -1)
    {
        self->rear++;
        self->front++;
    }
    else
    {
        self->rear++;
    }
    self->queue[self->rear]=val;
    return ;
    }
    printf("Queue is Full");
    
}

void removeAnElement(Queue* self)
{
    if( !isEmpty(self) && self->front!=self->rear+1)
    {
        if(self->front==self->Size-1 && self->rear==self->Size-1)
        {
        	printf("\n%d is removed from the Queue",self->queue[self->front]);
			self->rear=-1;
        	self->front=-1;
        	
        }
        else
        {	
        	printf("\n%d is removed from the Queue",self->queue[self->front]);
        	self->front++;
		}
        
       return ;
    }
     printf("\nQueue is Empty");
}

int main()
{
    Queue *queue=creatQueue();
    insertAnElement(queue);
    insertAnElement(queue);
    insertAnElement(queue);
    removeAnElement(queue);
    removeAnElement(queue);
    removeAnElement(queue);
    removeAnElement(queue);
    removeAnElement(queue);
	return 0;
}
