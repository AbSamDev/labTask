#include<iostream>
using namespace std;
class node{
	public:
		int data;
		node* next;
};
class linkList{
	public:
		node *head, *tail;
	public:
		linkList(){
			head = NULL;
			tail = NULL;
		}
		//create list
		void creatList(int value){
			node *temp = new node;
			temp -> data = value;
			temp -> next = NULL;
			if(head == NULL){
				head = temp;
				tail = temp;
			}
			else{
				tail -> next = temp;
				tail = temp;
			}
			
		}
		//print list
		void printList(){
			node *temp = new node;
			temp = head;
			if(temp == NULL){
				cout << "List is empty";
				return;
			}
			while(temp != NULL){
				cout << temp -> data << "\t";
				temp = temp -> next;
			}
		}
		//sorting
		void sortedList(){
			node *prev = head;
			while(prev != NULL){
				node *current = head;
				while(current != NULL){				
					if(prev -> data < current -> data){
						prev -> data = prev -> data + current -> data;
						current -> data = prev -> data - current -> data;
						prev -> data = prev -> data - current -> data;										
					}
					current = current -> next;					
				}
				prev = prev -> next;				
									
			}
		}

void insertInOrder(int val)  
{  
    node* current;  
    node *temp = new node;
	temp -> data = val;
	temp -> next = NULL;
    if (head == NULL)  
    {   
        head = temp;
    }  
    else
    {  
        current = head;  
        while (current->next!=NULL && current->next->data < temp->data)  
        {  
            current = current->next;  
        }  
        temp->next = current->next;  
        current->next = temp;  
    }  
}  
};
int main(){
	linkList l;
	l.creatList(1);
    l.insertInOrder(5);
	l.insertInOrder(10);
	l.insertInOrder(6);
	l.insertInOrder(4);
	l.insertInOrder(9);	
	
//	l.printList();
	
//	l.sortedList();
	//cout<<endl;
	
	l.printList();
	cout<<endl;
	
	cout<<"-------------------------Output is: ---------------------"<<endl;
	l.insertInOrder(7);
	l.printList();
	return 0;
}
