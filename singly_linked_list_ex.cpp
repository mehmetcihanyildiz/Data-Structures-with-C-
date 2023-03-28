#include<iostream>

using namespace std;

struct node
{
	int data;
	struct node* next;
};

struct node* f_add(struct node* head , int key)
{
	system ("cls");
	if(head == NULL)
	{
		struct node* temp = new node();
		temp->data = key;
		temp->next = NULL;
		
		head = temp;
		cout<<"First node has been created."<<endl;
	}
	else
	{
		struct node* temp = new node();
		temp->data = key;
		temp->next = head;
		
		head = temp;
		cout<<"Node added to the head."<<endl;
	}
	return head;
};

struct node* l_add(struct node* head , int key)
{
	system ("cls");
	if(head == NULL)
	{
		struct node* temp = new node();
		temp->data = key;
		temp->next = NULL;
		
		head = temp;
		cout<<"First node has been created."<<endl;
	}
	else
	{
		struct node* temp = new node();
		temp->data = key;
		temp->next = NULL;		//Las node points NULL
		
		struct node* temp2 = head;
		while(temp2->next!=NULL)
		{
			temp2 = temp2->next;
		}
		
		
		temp2->next = temp;
		cout<<"Node added to the tail."<<endl;
	}
	return head;
};

void print_nodes(struct node *head)
{	
	system ("cls");
	if(head==NULL)
	{
		cout<<"Empty list..."<<endl;
	}
	else
	{
	struct node* temp = head;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	}
	
}

void print_all_info(struct node * head)
{	
	system ("cls");
	if(head==NULL)
	{
		cout<<"Empty list..."<<endl;
	}
	else
	{
	struct node * temp = head;
	int i=1; 
	while(temp!=NULL)
	{
		cout<<"Data of the "<<i<<". node: "<<temp->data<<" address of the node: "<<temp<<" address of the next node:"<<temp->next<<endl;
		temp = temp->next;
		i++;
	}
	}
	
}


int nodeNum(struct node * head)
{
	system ("cls");
	int num=0;
	
	if(head==NULL){
		cout<<"Empty List"<<endl;
		return 0;
	}
	else
	{
		struct node* temp = head;
		while(temp!=NULL)
		{
			num++;
			temp=temp->next;
		}
		return num;
	}
}

int nodeSum(struct node * head)
{
	system ("cls");
	int sum=0;
	
	if(head==NULL){
		cout<<"Empty List"<<endl;
		return 0;
	}
	else
	{
		struct node* temp = head;
		while(temp!=NULL)
		{
			sum += temp->data;
			temp=temp->next;
		}
		return sum;
	}
}

void search(struct node* head, int s_num)
{
	system ("cls");
	bool result = false;
	if(head==NULL)
	{
		cout<<"Empty List"<<endl;
	}
	else
	{
		int index=0;
		struct node* temp = head;
		while(temp!=NULL)
		{
			index++;
			if(temp->data == s_num)
			{
				result=true;
				break;
			}
			temp=temp->next;
		}
		
		if(result==true)
		{
			cout<<s_num<<" is found at node: "<<index<<endl;
		}
		else
		{
			cout<<"Number not found in the list..."<<endl;
		}
		
	}
}

struct node* delHead(struct node* head)
{
	system ("cls");
	if(head==NULL)
	{
		cout<<"Empty List..."<<endl;
	}
	else
	{
		if(head->next==NULL)
		{
			delete head;
			head=NULL;
		}
		else
		{
			struct node* temp= head->next;
			delete head;
			head=temp;
		}
	}
	return head;
}

struct node* delTail(struct node* head)
{
	system ("cls");
	if(head==NULL)
	{
		cout<<"Empty List..."<<endl;
	}
	else
	{
		if(head->next==NULL)
		{
			delete head;
			head=NULL;
		}
		else
		{
			struct node* temp= head;
			while(temp->next->next!=NULL)
			{
				temp=temp->next;
			}
			
			struct node* temp2 = temp;
			delete temp->next;
			temp2->next=NULL;

		}
	}
	return head;
}

int main()
{
	
	struct node* head =NULL;

	int num, inp, n;
	
	while(1)
	{
		cout<<endl;
		cout<<"Signly Linked List App."<<endl;
		cout<<"1-- Add number to the head..."<<endl;
		cout<<"2-- Add number to the tail..."<<endl;
		cout<<"3-- Print out node..."<<endl;
		cout<<"4-- Print out all info..."<<endl;
		cout<<"5-- Number of the nodes..."<<endl;
		cout<<"6-- Sum of the values of the nodes..."<<endl;
		cout<<"7-- Search number..."<<endl;
		cout<<"8-- Delete from head..."<<endl;
		cout<<"9-- Delete from tail..."<<endl;
		cout<<"10-- Quit..."<<endl;
		
		cin>>inp;
		
		switch(inp)
		{
			case 1: cout<<"Enter the number..."<<endl;
			cin>>num;
			head = f_add(head,num);
			break;
			
			case 2: cout<<"Enter the number..."<<endl;
			cin>>num;
			head = l_add(head,num);
			break;
			
			case 3: print_nodes(head);
			break;
			
			case 4: print_all_info(head);
			break;
			
			case 5: n=nodeNum(head);
			cout<<"Number of the nodes: "<<n<<endl;
			break;
			
			case 6: n=nodeSum(head);
			cout<<"Sum of the values of the nodes: "<<n<<endl;
			break;
			
			case 7: cout<<"Enter the number for searching..."<<endl;
			cin>>num;
			search(head,num);
			break;
			
			case 8: head = delHead(head);
			break;
			
			case 9: head = delTail(head);
			break;
			
			case 10: cout<<"Quitting..."<<endl;
			exit(0);
			
			default: cout<<"Invalid choice...";
			break;
		}
		
	}
	
	
	
	return 0;
}
