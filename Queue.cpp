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

class Queue{
	private:
		Node* first;
		Node* last;
		int length;
		
	public:
		Queue(int value){
			Node* newNode = new Node(value);
			first = newNode;
			last = newNode;
			length = 1;
		}
		
		void printQueue(){
			Node* temp = first;
			while(temp != NULL){
				cout<<temp->value<<endl;
				temp = temp->next;
			}
		}
		
		void getFirst(){
			cout<<"First: "<<first->value<<endl;
		}
		
		void getLast(){
			cout<<"Last: "<<last->value<<endl;
		}
		
		void getLength(){
			cout<<"Length: "<<length<<endl;
		}
		
		void enqueue(int value){
			Node* newNode = new Node(value);
			
			if(length == 0){
				first = newNode;
				last = newNode;
			}
			else{
				last->next = newNode;
				last = newNode;
			}
			length++;
		}
		
		int dequeue() {
            if (length == 0) return INT_MIN;
            Node* temp = first;
            int dequeuedValue = first->value;
            if (length == 1) {
                first = NULL;
                last = NULL;
            } 
			else{
                first = first->next;
            }
            delete temp;
            length--;
            return dequeuedValue;
        }
        
        ~Queue() {
            Node* temp = first;
            while (first) {
                first = first->next;
                delete temp;
                temp = first;
            }
        }
};


int main()
{
	Queue* myQueue = new Queue(2);
	
	myQueue->enqueue(1);
	
	cout<<endl;
	
	myQueue->printQueue();
	
	cout<<"\nDequeued value: "<<myQueue->dequeue();

	
	return 0;
}
