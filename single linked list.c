#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *link;
}*head;
struct node* createList(int);
struct node* display();
struct node* insert(int);
int main(){
	int size,choice;
	head=(struct node*)malloc(sizeof(struct node));
	if(head==NULL)
	{
		printf("Head memory allocation failed");
		return 0;
	}
	
	while(1){
		printf("\n\n-------------MAIN MENU--------------\n1. Create List\n2. Display\n3. Insert\n\nEnter choice: ");
		scanf("%d",&choice);
		switch(choice){
			case 1: printf("Enter the number of nodes:  ");
					scanf("%d",&size);
					createList(size);
					break;
			case 2: display();
					break;
					
			case 3: insert(size);
					break;
			default: printf("Please enter a valid choice");
		}
	}
}

struct node* createList(int size){
	struct node *traverse, *newNode;
	int i;
	printf("\nEnter Node 1 data: ");
	scanf("%d",&head->data);
	head->link=NULL;
	traverse=head;
	for(i=2;i<=size;i++)
	{
		newNode=(struct node*)malloc(sizeof(struct node));
		if(newNode==NULL){
			printf("Memory allocation failed");
			return head;
		}
		printf("Enter Node %d data: ",i);
		scanf("%d",&newNode->data);
		newNode->link=NULL;
		traverse->link=newNode;
		traverse=traverse->link;
	}
}


struct node* display(){
	struct node *traverse;
	int i=0;
	traverse=head;
	printf("\n\nDisplaying\n");
	while(traverse!=NULL){
		printf("Node %d : %d\n",++i,traverse->data);
		traverse=traverse->link;
	}
}


struct node* insert(int size){
	int data,choice, item;
	struct node *traverse, *newNode, *prev;
	traverse=head;
	printf("\n\n1. Insertion at the begining\n2. Insertion at the end\n3. Insertion after a node\n\nEnter choice: ");
	scanf("%d",&choice);
	switch(choice){
		case 1: newNode=(struct node*)malloc(sizeof(struct node));
				printf("Enter the data of the new node: ");
				scanf("%d",&newNode->data);
				newNode->link=head;
				head=newNode;
				break;
		
		case 2: traverse=head;
				newNode=(struct node*)malloc(sizeof(struct node));
				while(traverse!=NULL){
					prev=traverse;
					traverse=traverse->link;
				}
				printf("Enter the data of the new node: ");
				scanf("%d",&newNode->data);
				newNode->link=NULL;
				prev->link=newNode;
				break;
				
		case 3: traverse=head;
				
		default: printf("Wrong Input");
	}
}
