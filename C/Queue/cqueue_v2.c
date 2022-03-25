#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>


typedef struct Queue
{
    
    int *queue;
    unsigned size;
    int front,rear,num_entries;
}Queue;


Queue* creatQueue();
void queueDestroy(Queue *self);
bool isFull(Queue* self);
bool isEmpty(Queue* self);
void insertAnElement(Queue* self);
void removeAnElement(Queue* self);
void display(Queue* self);

Queue* creatQueue()
{
    Queue *self=malloc(sizeof(Queue));
    unsigned Size;
    printf("Enter Size of the Queue:");
    scanf("%u",&Size);    
    self->size=Size;
    self->queue=malloc(self->size * sizeof(int));
    memset(self->queue,0,self->size*sizeof(self->queue[0]));
    self->num_entries=0;
    self->front=0;
    self->rear=0;

    return self;
     
}

bool isEmpty(Queue *self)
{
    return (self->num_entries==0);
}

bool isFull(Queue *self)
{
    return (self->num_entries==self->size);
}

void insertAnElement(Queue* self)
{
    int val;
    if(isFull(self))
    {
        printf("Queue is full..");
        return ;
    }
     printf("Enter A value into Queue:");
     scanf("%d",&val);

        self->queue[self->rear]=val;
        self->num_entries++;
        self->rear=(self->rear + 1)% self->size;
    
}


void removeAnElement(Queue* self)
{
    if(isEmpty(self))
    {
        printf("Queue is Empty..");
        return ;
    }
    printf("\n%d is removed from the Queue",self->queue[self->front]);
    self->queue[self->front]=0;
    self->num_entries--;
    self->front=(self->front + 1) % self->size;
}

 void display(Queue* self){
    char c;
    int i,flag=0;
    FILE *fp=fopen("CQueue.txt","w");
    fprintf(fp,"\tQueue\n\n");
    fprintf(fp,"      |-----|\n");
    if(isEmpty(self))
    {
        for (i = 0; i < self->size; i++)
        {
            fprintf(fp,"      |     |\n");
            fprintf(fp,"      |-----|\n");
        }
        fprintf(fp,"\n      Queue is Empty\n");
    }
    else{
    
        for (i = 0; i < self->size; i++)
        {
            if(i==self->rear)
                fprintf(fp,"Rear->");
            
            if(self->queue[i]==0)
            {
            	if(self->rear==i)
            		fprintf(fp,"|     |");
            	else{
            		fprintf(fp,"      |     |");
				}	
			}
                
            else
            {
            	
            	
            	if(self->front==self->rear && flag==0)
            	{
            		fprintf(fp,"|%3d  |",self->queue[i]);
					flag++;	
				}
				else
				{
					fprintf(fp,"      |%3d  |",self->queue[i]);
				}
            	
			}
                

            if(i==self->front)
                fprintf(fp,"<-Front");

            fprintf(fp,"\n      |-----|\n");
        }
        if(isFull(self))
        {
            fprintf(fp,"\n      Queue is Full\n");
        }
    }
    
    fclose(fp);

            fp=fopen("CQueue.txt","r");
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


void queueDestroy(Queue *self)
{
        free(self->queue);
        free(self);
} 



int main()
{
    unsigned ch;
    Queue *queue=creatQueue();
    while(1)
    {


       printf("\n1.Insert An Element");
       printf("\n2.Remove An Element");
       printf("\n3.isEmpty"); 
       printf("\n4.isFull");      
       printf("\n5.Display"); 
       printf("\n0.Exit"); 

        printf("\nEnter operation:");
        scanf("%u",&ch);
        printf("\n\n");

            if(ch==0)
            {
                queueDestroy(queue);
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
                printf("%s",(isEmpty(queue)?"Yes\n":"No\n"));
                break;    
            case 4:
                printf("%s",(isFull(queue)?"Yes\n":"No\n"));
                break; 
            case 5:
                display(queue);
                break;    

            default:
                printf("Invalid Operation");
                break;
            }


    }
    

	return 0;
}
