#include<iostream>

using namespace std;

class Node{
	public:
		int value;
		Node* next;
	
	Node(int value){
		this->value = value;
		next = NULL;
	}
};

class Stack{
	private:
		Node* top;
		int height;
		
	public:
		Stack(int value)
		{
			Node* newNode = new Node(value);
			top = newNode;
			height = 1;
		}
		
		void printStack(){
			Node* temp = top;
			while(temp != NULL)
			{
				cout<<temp->value<<endl;
				temp = temp->next;
			}
		}
		
		void getTop()
		{
			cout<<"Top: "<<top->value<<endl;
		}
		
		void getHeight()
		{
			cout<<"Height: "<<height<<endl;
		}
		
		void push(int value){
			Node* newNode = new Node(value);
			newNode->next = top;
			top = newNode;
			height++;
		}
		
		int pop(){
			if(height == 0){return INT_MIN;}
			Node* temp = top;
			int poppedValue = top->value;
			top = top->next;
			delete temp;
			height--;
			
			return poppedValue;
		}
		
		~Stack() {
            Node* temp = top;
            while (top) {
                top = top->next;
                delete temp;
                temp = top;
            }
        }
};

int main()
{
	Stack* myStack = new Stack(4);
	myStack->push(3);
	myStack->printStack();
	
	cout<<endl;
	cout<<"Popped Value: "<<myStack->pop();
	cout<<"\nPopped Value: "<<myStack->pop();
	
	
	return 0;
}
