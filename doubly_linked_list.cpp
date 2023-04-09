#include<iostream>

using namespace std;

class Node
{
public:
	int value;
	Node* next;
	Node* prev;

	Node(int value)
	{
		this->value = value;
		this->next = NULL;
		this->prev = NULL;
	}
};

class DoublyLinkedList
{
private:
	Node* head;
	Node* tail;
	int length;

public:
	DoublyLinkedList(int value)
	{
		Node* newNode = new Node(value);
		head = newNode;
		tail = newNode;
		length = 1;
	}

	void printList()
	{
		Node* temp = head;
		while (temp != NULL)
		{
			cout << temp->value << endl;
			temp = temp->next;
		}
	}

	void getHead()
	{
		cout << "Head: " << head->value << endl;
	}

	void getTail()
	{
		cout << "Tail: " << tail->value << endl;
	}

	void getLength()
	{
		cout << "Length: " << length << endl;
	}
	
	Node* get(int index){
		if(index<0 || index >= length){
			return NULL;
		}
		Node* temp = head;
		if(index < length/2)
		{
			for (int i=0; i<index; i++)
			{
				temp = temp->next;
			}
		}
		else
		{
			temp = tail;
			for(int i = length-1;i>index;i--)
			{
				temp = temp->prev;
			}
		}
		
		return temp;
	}
	
	bool set(int index, int value){
		Node* temp = get(index);
		if(temp != NULL)
		{
			temp->value = value;
			return true;
		}
		return false;
	}
	
	bool insert(int index, int value){
		if(index<0 || index > length){
			return false;
		}
		if(index == 0)
		{
			prepend(value);
			return true;
		}
		if(index == length)
		{
			append(value);
			return true;
		}
		Node* newNode = new Node(value);
		Node* before = get(index-1);
		Node* after = before->next;
		
		newNode->prev = before;
		newNode->next = after;
		before->next = newNode;
		after->prev = newNode;
		
		length++;
		return true;
	}

	void append(int value)
	{
		Node* newNode = new Node(value);
		if (length == 0)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			tail->next = newNode;
			newNode->prev = tail;
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
			head->prev = newNode;
			head = newNode;
		}
		length++;
	}

	void deleteLast() {
		if (length == 0) {
			return;
		}
		Node* temp = tail;
		if (length == 1) {
			head = NULL;
			tail = NULL;
		}
		else {
			tail = tail->prev;
			tail->next = NULL;
		}
		delete temp;
		length--;
	}
	
	void deleteFirst()
	{
		if(length == 0) return;
		Node* temp = head;
		if(length == 1)
		{
			head = NULL;
			tail = NULL;
		}
		else
		{
			head = head->next;
			head->prev = NULL;
		}
		delete temp;
		length--;
	}
	
	void deleteNode(int index)
	{
		if(index<0 || index >= length){return;}
		if(index == 0){return deleteFirst();}
		if(index == length-1){return deleteLast();}
		
		Node* temp = get(index);
		temp->next->prev = temp->prev;
		temp->prev->next = temp->next;
		delete temp;
		length--;
	}
	
	~DoublyLinkedList() {
            Node* temp = head;
            while (head) {
                head = head->next;
                delete temp;
                temp = head;
            }
        }
};

int main()
{
	DoublyLinkedList* myDLL = new DoublyLinkedList(11);
	myDLL->append(22);
	myDLL->append(33);
	myDLL->append(44);
	myDLL->printList();
	cout<<endl;
	
	cout<<myDLL->get(1)->value<<endl;
	cout<<endl;
	
	myDLL->insert(1,99);
	myDLL->printList();
	cout<<endl;
	
	myDLL->deleteNode(1);
	myDLL->printList();
	
	return 0;
}
