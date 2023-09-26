#include<iostream>
#include<climits>
#include<queue>
#include<cmath>
using namespace std;
//T:C pop is O(N) and space is O(1)
//for push it is O(1) and space is O(Nodes created)
//sir in this the head is used appropriately and not vice versa
class node{
    public:
    int val;
    node*next;
    int priority;
    node(int f,int k){
        this->val = f;
        this->priority = k;
        this->next = NULL;
    }
};
class pq{
    public:
    node*head;
    void push(int f,int pr){
        if(head == NULL){
            node*newnode = new node(f,pr);
            head = newnode;
            return;
        }
        else{
            node*newnode = new node(f,pr);
            newnode->next = head;
            head = newnode;
            return;
        }
    }
    int pop(){
        if(head == NULL){
            cout<<"Given priority queue is empty"<<endl;
            return -1;
        }
        else{
            int maxi = INT_MIN;
            maxi=head->priority;
            node*temp=head;
            node*prev=NULL;
            node*prev2 = NULL;
            node*temp2 = head;
            if(head->next == NULL){
                head = NULL;
                return temp->val;
            }
            while(temp != NULL){
                int v = temp->priority;
                if(v > maxi){
                    prev2 = prev;
                    temp2 = temp;
                    maxi = temp->priority;
                }
                prev = temp;
                temp = temp->next;
                
            }
            prev2->next=temp2->next;
            temp2->next=NULL;
            return temp2->val;
        }
    }
    int top(){
         if(head == NULL){
            cout<<"Given priority queue is empty"<<endl;
            return -1;
        }
        else{
            int maxi = INT_MIN;
            maxi=head->priority;
            node*temp=head;
            node*prev=NULL;
            node*prev2 = NULL;
            node*temp2 = head;
            if(head->next == NULL){
                return temp->val;
            }
            while(temp != NULL){
                int v = temp->priority;
                if(v > maxi){
                    prev2 = prev;
                    temp2 = temp;
                    maxi = temp->priority;
                }
                prev = temp;
                temp = temp->next;
                
            }
            return temp2->val;
        }
    }
    void print(){
        node*temp = head;
        while(temp != NULL){
            cout<<temp->val<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
};
int main(){
    pq p1;
    p1.push(2,3);
    p1.push(1,1);
    p1.push(45,0);
    cout<<p1.pop()<<endl;
    p1.print();
    cout<<p1.top()<<endl;
    cout<<p1.pop()<<endl;
    cout<<p1.pop()<<endl;
    
    //p1.print();
    
}