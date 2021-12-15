#include<stdio.h>
#include<stdlib.h>
struct polynomial
{
    int coeff,exp;
    struct polynomial *next;
};
typedef struct polynomial node;
node* addterm(node *first,node *new)
{
    node *temp,*temp1;
    if(first==NULL)
    {
        first=new;
    }
    else if(first->exp < new->exp)
    {
        new->next=first;
        first=new;
    }
    else
    {
        temp=first->next;
        temp1=first;
        while((temp!=NULL)&&(temp->exp > new->exp))
        {
            temp1=temp;
            temp=temp->next;
        }
        if(temp==NULL)
        {
            temp=new;
        }
        else if(temp->exp==new->exp)
        {
            temp->coeff=temp->coeff+new->coeff;
        }
        else
        {
            temp1->next=new;
            new->next=temp;
        }
    }
    return first;
}
node* create(node *first)
{
    node *temp=NULL,*new;
    char c;
    do
    {
        new=(node*)malloc(sizeof(node));
        new->next=NULL;
        printf("enter coeff,exponent of the term\n");
        scanf("%d%d",&new->coeff,&new->exp);
        first=addterm(first,new);
        printf("enter another term(enter 'n' to stop)");
        scanf("%c",&c);
    }while(c!='n');
    return first;
}

node* add(node *p1,node *p2)
{
    node *p3=NULL,*new;
    while(p1!=NULL && p2!=NULL)
    {
        new=(node*)malloc(sizeof(node));
        new->next=NULL;
        if(p1->exp > p2->exp)
        {
            new->coeff=p1->coeff;
            new->exp=p1->exp;
            p3=addterm(p3,new);
            p1=p1->next;
        }
        else if(p2->exp > p1->exp)
        {
            new->coeff=p2->coeff;
            new->exp=p2->exp;
            p3=addterm(p3,new);
            p2=p2->next;
        }
        else
        {
            new->coeff=p1->coeff+p2->coeff;
            new->exp=p1->exp;
            p3=addterm(p3,new);
            p1=p1->next;
            p2=p2->next;
        }
    }
    if(p1==NULL)
    {
        while(p2!=NULL)
        {
            new=(node*)malloc(sizeof(node));
            new->coeff=p2->coeff;
            new->exp=p2->exp;
            p3=addterm(p3,new);
            p2=p2->next;
        }
    }
    if(p2==NULL)
    {
        while(p1!=NULL)
        {
            new=(node*)malloc(sizeof(node));
            new->coeff=p1->coeff;
            new->exp=p1->exp;
            p3=addterm(p3,new);
            p1=p1->next;
        }
    }
    return p3;
}
node* sub(node *p1,node *p2)
{
    node *p3=NULL,*new;
    while(p1!=NULL && p2!=NULL)
    {
        new=(node*)malloc(sizeof(node));
        new->next=NULL;
        if(p1->coeff > p2->coeff)
        {
            new->coeff=p1->coeff;
            new->exp=p1->exp;
            p3=addterm(p3,new);
            p1=p1->next;
        }
        else if(p2->coeff > p1->coeff)
        {
            new->coeff=-p2->coeff;
            new->exp=p2->exp;
            p3=addterm(p3,new);
            p2=p2->next;
        }
        else
        {
            new->coeff=p1->coeff-p2->coeff;
            new->exp=p1->exp;
            p3=addterm(p3,new);
            p1=p1->next;
            p2=p2->next;
        }
    }
    if(p1==NULL)
    {
        while(p2!=NULL)
        {
            new=(node*)malloc(sizeof(node));
            new->coeff=-p2->coeff;
            new->exp=p2->exp;
            p3=addterm(p3,new);
            p2=p2->next;
        }
    }
    if(p2==NULL)
    {
        while(p1!=NULL)
        {
            new=(node*)malloc(sizeof(node));
            new->coeff=p1->coeff;
            new->exp=p1->exp;
            p3=addterm(p3,new);
            p1=p1->next;
        }
    }
    return p3;
}
node* mul(node *p1,node *p2)
{
    node *p3=NULL,*new,*temp=p2;
    while(p1!=NULL)
    {
        p2=temp;
        while(p2!=NULL)
        {
            new=(node*)malloc(sizeof(node));
            new->coeff=p1->coeff*p2->coeff;
            new->exp=p1->exp+p2->exp;
            new->next=NULL;
            p3=addterm(p3,new);
            p2=p2->next;
        }
        p1=p1->next;
    }
    return p3;
}
void display(node *p)
{
    while(p!=NULL)
    {
        printf("%dX^%d+",p->coeff,p->exp);
        p=p->next;
    }
}
int main()
{
    node *p1=NULL,*p2=NULL,*p3=NULL;                                      
    int ch;                                                
    printf("enter the first polynomial\n");                
    p1=create(p1);                                          
    display(p1);                                          
    printf("\nenter the second polynomial\n");              
    p2=create(p2);                                          
    display(p2);                                          
    while(1)                                              
    {                                                      
        printf("\n1.addition\n 2.substraction\n 3.multiplication\n 4.exit\n");
        printf("enter your choice\n");                                        
        scanf("%d",&ch);                                                      
        switch(ch)                                                            
        {                                                                      
            case 1: p3=add(p1,p2);                                              
                    printf("the addition of p1 and p2 is");                            
                    display(p3);                                                      
                    break;                                                            
            case 2: p3=sub(p1,p2);                                              
                    printf("the substraction of p1 and p2 is");                        
                    display(p3);                                                      
                    break;                                                                                        
            case 3: p3=mul(p1,p2);          
                    printf("the multiplication of p1 and p2 is");    
                    display(p3);                                    
                    break;                                          
            case 4: exit(0);                                  
                    break;                                          
            default:printf("invalid input");                
        }                                                
    }                                                
}
