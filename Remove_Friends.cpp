#include <iostream>
#include<cstdlib>
using namespace std;

struct node{
	int data;
	struct node * next;
};

struct node * head;

void insert(int data){
	struct node * newnode = new struct node;
	newnode->data = data;
	newnode->next = NULL;
	if(head == NULL){
		head = newnode;
	}
	else{
		struct node * temp = head;
		while(temp->next != NULL){
			temp = temp->next;
		}
		temp->next = newnode;
	}
}


int main()
{
    int T, N, K, inp;
    cin>>T;
    while(T--){
    	head = NULL;
    	cin>>N>>K;
    	for(int i = 0; i < N; ++i){
    		cin>>inp;
    		insert(inp);
    	}
    	bool DeleteFriend = false;
    	while(K--){
    		struct node * deleter = head;
    		for(int i = 0; i < N-1; ++i){
    			if(deleter->data < deleter->next->data){
    				DeleteFriend = true;
    				struct node * temp = deleter->next;
    				deleter->data = deleter->next->data;
    				deleter->next = temp->next;
    				free(temp);
    				break;
    			}
    			else{
    				deleter = deleter->next;
    			}
    			
    		}
    		if(!DeleteFriend){
    				deleter->next = NULL;
    		}
    	}
     	struct node * printer = head;
     	while(printer != NULL){
     		cout<<printer->data<< " ";
     		printer = printer->next;
     	}
    	cout<<endl;
    }
    return 0;
}
