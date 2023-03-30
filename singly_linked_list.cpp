#include<iostream>

using namespace std;

class Node
{
	public:
		int value;
		Node* next;
		
		Node(int value){
			this->value = value;
			next = NULL;
		}	
};

class LinkedList{
	private:
		Node* head;
		Node* tail;
		int length;
		
	public:
		LinkedList(int value){
			Node* newNode = new Node(value);
			head = newNode;
			tail = newNode;
			length = 1;
		}
		void printList(){
			Node* temp = head;
			while(temp != NULL)
			{
				cout<<temp->value<<endl;
				temp = temp->next;
			}
		}
		void getHead(){
			cout<<"Head: "<<head->value<<endl;
		}
		void getTail(){
			cout<<"Tail: "<<tail->value<<endl;
		}
		void getLength(){
			cout<<"Length: "<<length<<endl;
		}
		void append(int value){
			Node* newNode = new Node(value);
			if(length == 0)
			{
				head = newNode;
				tail = newNode;
			}
			else{
				tail->next = newNode;
				tail = newNode;
			}
			length++;
		}
		
		void prepend(int value)
		{
			Node* newNode = new Node(value);
			if(length == 0)
			{
				head = newNode;
				tail = newNode;
			}
			else
			{
				newNode->next = head;
				head = newNode;
			}
			length++;
		}
		
		void deleteLast(){
			if(length ==0 )
			{
				cout<<"Empty List"<<endl;
			}
			Node* temp = head;
			if(length == 1){
				head = NULL;
				tail = NULL;
			}else{
				
				Node* pre = head;
				while(temp->next != NULL)
				{
					pre = temp;
					temp = temp->next;
				}
			tail = pre;
			tail->next = NULL;
			}
			delete temp;
			length--;
		}
		
		void deleteFirst()
		{
			if(length == 0)
			{
				return;
			}
			Node* temp = head;
			if (length == 1)
			{
				head = NULL;
				tail = NULL;
			}
			else
			{
				head = head->next;
			}
			delete temp;
			length--;
		}
		
		void deleteNode(int index)
		{
			if(index < 0 || index >= length)
			{
				return;
			}
			if (index == 0)
			{
				return deleteFirst();
			}
			if(index == length-1)
			{
				return deleteLast();
			}
			Node* prev = get(index-1);
			Node* temp = prev->next;
			prev->next = temp->next;
			delete temp;
			length--;
			
		}
		
		Node* get(int index)
		{
			if(index < 0 || index >= length)
			{
				return NULL;
			}
			Node* temp = head;
			for (int i=0; i < index; i++)
			{
				temp = temp->next;
			}
			return temp;
		}
		
		bool set(int index, int value)
		{
			Node* temp = get(index);
			if(temp){
				temp->value = value;
				return true;
			}
			return false;
		}
		
		bool insert(int index, int value)
		{
			if(index < 0 || index > length)
			{
				return false;
			}
			if(index == 0)
			{
				prepend(value);
				return true;
			}
			if (index == length)
			{
				append(value);
				return true;
			}
			
			Node* newNode = new Node(value);
			Node* temp = get(index-1);
			newNode->next = temp->next;
			temp->next = newNode;
			length++;
			return true;
		}
		
		void reverse(){
			Node* temp = head;
			head = tail;
			tail = temp;	
			
			Node* after = temp->next;
			Node* before = NULL;
			
			for (int i=0;i<length;i++)
			{
				after = temp->next;
				temp->next = before;
				before = temp;
				temp = after;
			}
		}
		
		~LinkedList(){
			Node* temp = head;
			while(head !=NULL){
				head=head->next;
				delete temp;
				temp=head;
			}
		}
};

int main(){
	LinkedList* myLinkedList = new LinkedList(2);
	myLinkedList->append(3);
	myLinkedList->prepend(1);
	myLinkedList->printList();
	cout<<endl;
	myLinkedList->reverse();
	myLinkedList->printList();
	cout<<"Index 0's value is: "<< myLinkedList->get(0)->value<<endl;
	
	
	return 0;
}
