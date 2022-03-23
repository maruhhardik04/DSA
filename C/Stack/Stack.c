 #include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<stdbool.h>

typedef struct Stack
{
       int top;
       unsigned size;
       int *arr;
}Stack;

Stack* createStack();
bool isEmpty(Stack* Stack); 
bool isFull(Stack* Stack);
void push(Stack* Stack);
void pop(Stack* Stack);
void peep(Stack* Stack);
void display(Stack *stack);

Stack* createStack()
{
    unsigned Size;
    printf("Enter Size of the Stack:");
    scanf("%u",&Size);
    Stack* stack =(Stack*)malloc(sizeof(Stack));
    stack->size=Size;
    stack->top=-1;
    stack->arr=(int*)malloc(stack->size *sizeof(int));
    return stack;
}


bool isEmpty(Stack* stack)
{
    return stack->top==-1;
}

bool isFull(Stack* stack)
{
    return stack->top==stack->size-1;
}

void push(Stack* stack)
{
    int value;
    if (!isFull(stack))
    {
        printf("Enter A value to push into stack:");
        scanf("%d",&value);
        stack->top++;
        stack->arr[stack->top]=value;
        return ;        
    }

            printf("\nOverflow...\n");

  
    
}

void pop(Stack* stack)
{
    if(!isEmpty(stack))
    {
        printf("%d is pop from  a stack\n",stack->arr[stack->top]);
        stack->top--;
        return ;
    }
    
    printf("\nUnderflow...\n");

    
}


void peep(Stack* stack)
{
       if(!isEmpty(stack))
        {
           printf("\nlast add  element to stack is %d\n",stack->arr[stack->top]);
            return ;
        }
        
        printf("\nUnderflow...\n");
}

void dispaly(Stack* stack)
{
    int i;
    char c;
    if(!isEmpty(stack))
    {
            FILE *fp;
            fp=fopen("Stack.txt","w");
            fprintf(fp,"\t\t Stack\n\n");
            fprintf(fp,"\t\t|-----|\n");
            for (i = stack->top; i >=0 ; --i)
            {
                fprintf(fp,"\t\t|%3d  |\n",stack->arr[i]);
                fprintf(fp,"\t\t|-----|\n");
            }
            fclose(fp);

            fp=fopen("Stack.txt","r");
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
        return ;
    }
     printf("\nUnderflow...\n");
    


    
}

int main()
{   
    unsigned ch;
    Stack *stack=createStack();

    while(1)
    {
            printf("\n\n");
            printf("\t\t1.Push\n");
            printf("\t\t2.Pop\n");
            printf("\t\t3.Isempty\n");
            printf("\t\t4.Isfull\n");
            printf("\t\t5.Peep\n");
            printf("\t\t6.Display\n");
            printf("\t\t0.Exit\n");
            printf("Enter operation number:");
            scanf("%u",&ch);
            printf("\n\n");

            if(ch==0)
            {
                break;
            }

            switch (ch)
            {
            case 1:
                push(stack);
                break;
            case 2:
                pop(stack);
                break;
            case 3:
                printf("%s",(isEmpty(stack)?"Yes":"No"));
                break;    
            case 4:
                printf("%s",(isFull(stack)?"Yes":"No"));
                break;  
            case 5:
                peep(stack);
                break;
            case 6:
                dispaly(stack);
                break;
            default:
                printf("Incorrect Operation");
                break;       
            }
            
    
    }
    

    
    return 0;
}
