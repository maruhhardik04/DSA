#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<stdbool.h>
#include<string.h>
int i;

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
void display(Queue* self);

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
    memset(queue->queue,0,queue->Size*sizeof(queue->queue[0]));
    return queue;
}

bool isFull(Queue* self)
{
    return ((self->front==self->rear+1) || (self->front==0 && self->rear==self->Size-1));
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
    
    if(self->rear == -1 && self->front== -1)
    {
        self->rear=0;
        self->front=0;
    }
    else if(self->rear==self->Size-1  && self->front!=0)
    {
        self->rear=0;
        
    }
    else
    {
        self->rear++;
    }
    self->queue[self->rear]=val;
    return ;
    }
    printf("Queue is Full\n");
    
}

void removeAnElement(Queue* self)
{
    if( !isEmpty(self))
    {
        if(self->front==self->Size-1 && self->rear==self->Size-1)
        {
        	printf("\n%d is removed from the Queue",self->queue[self->front]);
        	printf("\n Queue is reset");
            self->queue[self->front]=0;
			self->rear=-1;
        	self->front=-1;
        	
        }
        else
        {	
           if(!(self->front==self->Size))
           {
           	
           		printf("\n%d is removed from the Queue",self->queue[self->front]);
        		self->queue[self->front]=0;
				self->front++;
		   }
			else
			{
				
           			self->front=0;
				   printf("\n%d is removed from the Queue",self->queue[self->front]);
        		   self->queue[self->front]=0;
			}
						     
		}


        
       return ;
    }
     printf("Queue is Empty\n");
}

void display(Queue* self){
    char c;
    FILE *fp=fopen("Circular_Queue.txt","w");
    fprintf(fp,"\t\t\tCircular Queue\n\n");
    fprintf(fp,"\t\t\t|-----|\n");
    if(isEmpty(self))
    {
        for (i  = 0; i < self->Size; i++)
        {
            fprintf(fp,"\t\t\t|     |\n");
            fprintf(fp,"\t\t\t|-----|\n");
        }
        fprintf(fp,"\n\t\t\tQueue is Empty");
    }
    else{
    
        for (i = 0; i < self->Size; i++)
        {
            if(i==self->rear)
                fprintf(fp,"Rear->");
            
            if(self->queue[i]==0)
                fprintf(fp,"\t\t\t|     |");
            else
                fprintf(fp,"\t\t\t|%3d  |",self->queue[i]);

            if(i==self->front)
                fprintf(fp,"<-Front");

            fprintf(fp,"\n\t\t\t|-----|\n");
        }
        if(isFull(self))
        {
            fprintf(fp,"\n\t\t\tQueue is Full");
        }
    }
    
    fclose(fp);

            fp=fopen("Circular_Queue.txt","r");
            if(fp != NULL)
            {
                while ((c=fgetc(fp)) != EOF)
                {
                    printf("%c",c);    
                }
                fclose(fp);
                return ;
            }
            printf("Cannot open file \n");

}


int main()
{
    unsigned ch;
    Queue *queue=creatQueue();
    while(1)
    {


       printf("\n1.Insert An Element");
       printf("\n2.Remove An Element");
       printf("\n3.isFull"); 
       printf("\n4.isEmpty");      
       printf("\n5.Display"); 
       printf("\n0.Exit"); 

        printf("\nEnter operation:");
        scanf("%u",&ch);
        printf("\n\n");

            if(ch==0)
            {
                break;
            }

            switch (ch)
            {
            case 1:
                insertAnElement(queue);
                break;
            case 2:
                removeAnElement(queue);
                break;
             case 3:
                printf("%s",(isFull(queue)?"Yes":"No"));
                break;    
            case 4:
                printf("%s",(isEmpty(queue)?"Yes":"No"));
                break; 
            case 5:
                display(queue);
                break;    

            default:
                printf("Invalid Operation");
                break;
            }


    }
    
    getch();
	return 0;
}
