#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int info;
	struct node *next;
}node;
node * getnode(int);
node * AddLast(node *,int);
node * Sort(node *);
void Traverse(node *);
node * freeall(node *);
node * Reverse(node *);
node * merge(node *,node *);
int main()
{
	node *l1=NULL,*l2=NULL,*l3;
	l1=AddLast(l1,10);
	l1=AddLast(l1,20);
	l1=AddLast(l1,50);
	
	l2=AddLast(l2,5);
	l2=AddLast(l2,30);
	l2=AddLast(l2,80);
	
	l3=merge(l1,l2);
	
	Traverse(l1);
	Traverse(l2);
	Traverse(l3);
	
	freeall(l1);
	freeall(l2);
	freeall(l3);
	
	return 0;	
}
node * getnode(int item){
	node *t=(node *)malloc(sizeof(node));
	t->info=item;
	return t;	
}
node * AddLast(node *start,int item)
{
	node *ptr,*newnode;
	newnode=getnode(item);
	ptr=start;
	newnode->next=NULL;
	if(start==NULL)
	{
		start=newnode;
		newnode->next=NULL;
	}
	else{
	while(ptr->next!=NULL)
	{
		ptr=ptr->next;
	}
	ptr->next=newnode;
}
	return start;
	
}
void Traverse(node *start)
{
	node *ptr;
	ptr=start;
	printf("\nThe list is: ");
	while(ptr!=NULL)
	{
		printf("%d\t",ptr->info);
		ptr=ptr->next;
	}
	printf("\n");	
}
node * Sort(node *start)
{
	node *p1,*p2;
	for(p1=start;p1->next!=NULL;p1=p1->next)
	{		
	for(p2=p1->next;p2!=NULL;p2=p2->next)
	{
		if(p1->info > p2->info)
		{
			int t;
     		t=p1->info;
     		p1->info=p2->info;
      		p2->info=t;
		}
	}
}
	return start;
}
node *freeall(node *start)
{
	node *ptr;
	ptr =start;
	while(start!=NULL)
	{
		ptr=start;
		start=start->next;
		free(ptr);
	}
	return start;
}
node * Reverse(node *start){
	node *p1,*p2,*p3;	
	
}

node * merge(node * l1,node * l2)
{
	node *l3=NULL;
	while(l1!=NULL && l2!=NULL)
	{
		if(l1->info<l2->info)
		{
			l3=AddLast(l3,l1->info);
			l1=l1->next;
		}
		else if(l2->info<l1->info)
		{
			l3=AddLast(l3,l2->info);
			l2=l2->next;
		}
	}
	while(l1!=NULL)
	{
		l3=AddLast(l3,l1->info);
		l1=l1->next;
	}
	while(l2!=NULL)
	{
		l3=AddLast(l3,l2->info);
		l2=l2->next;
	}
	return l3;
}

