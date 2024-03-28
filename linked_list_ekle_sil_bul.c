#include <stdio.h>
#include <stdlib.h>

	struct node{
		int data;
		struct node *next;
	};
	struct node *head = NULL;
	struct node *tail = NULL;

	int addNode(int n){
		//linked list is empty
		if(head==NULL){
			struct node *new = (struct node*)malloc(sizeof(struct node));
			new -> data = n;
			new -> next = NULL;
			head = tail = new;
		}
		
		//linked list is not empty
		else{
			struct node *new = (struct node*)malloc(sizeof(struct node));
			new -> data = n ;
			new -> next = NULL;
			
			tail -> next = new;	
			tail = new;
		}
		return 1;
	}
	int print(){
		struct node *temp = head;
		int i=1;
		while(temp!= NULL){
			printf("%d. terimin degeri %d dir\n",i,temp -> data);
			i++;
			temp = temp -> next;
		}
	}
	
	int searchAndDelete(){
		printf("could you enter the number which want to delete\t");
		int x;
		scanf("%d",&x);
		struct node *temp;
		struct node *previous;
		temp=head;
		int control=0;
		while(temp!=NULL){
			if(head -> data == x){//if desired value is the same as the head
				head = head -> next;
				printf("\ndesired value(%d) was found in %x",x,temp);
				printf("\ndesired value was deleted\n",x,temp);
				free(temp);
				return 1;
			}
			if(temp -> data == x)	control = 1;
			else {
				previous=temp;
				temp = temp -> next;
				control=0;
				}
			if(control == 1){
				printf("\ndesired value(%d) was found in %x",x,temp);
				printf("\ndesired value was deleted\n",x,temp);
				previous -> next = temp -> next;
				free(temp);
				return 1;
			}
		}
		if(temp == tail)
		printf("\ndesired value wasn't founded");
	}
	
int main(int argc, char *argv[]) {
	int number;
	printf("if you exit ,you enter '-1'\n");
	while(1){printf("could you enter the number		\n");scanf("%d",&number);	
		if(number==-1)break;		
		else addNode(number);	
	}
	while(1){
		printf("\n1 for display\t2 for search and display\t -1 for exit\t");
		scanf("%d",&number);
		if(number == -1 ) break;
		switch(number){
			case 1:
				print();
				break;
			case 2:
				searchAndDelete();
				break;
		}
	}
	return 0;
}
