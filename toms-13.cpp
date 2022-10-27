1
//SET էլեմենտի պատկանելիությունը բազմության
//միավորումը
//տպել
#include <iostream>
using namespace std;
class SET{
 public:
 SET();
 void push_back( int data );
 bool patkan_e(int value);
 SET comb(SET A,SET B);
 void printSET();
 int GetSize(){
 return Size;
 }
 private:
 class Node{
 public:
 int data;
 Node *pnext;
 Node (int data=int(),Node *pnext=NULL){
 this->data=data;
 this->pnext=pnext;
 }
2
 };
 int Size;
 Node *head;
};
SET::SET(){
 Size=0;
 head=NULL; }
void SET::push_back(int data){
 if(head==NULL){
 head=new Node ( data );

}
 else{
 Node * current=this
->head;
 while(current
->pnext!=NULL){
 current=current
->pnext;

}
 current
->pnext=new Node (data);

}
 Size++; }
bool SET::patkan_e(int value){
Node *current=this
->head;
bool t=false;
3
int index=0;
while(current!=nullptr){
 if(current
->data==value){
 t=true;
 break;

}
 else{
 current=current
->pnext;

}
 index++; }
cout<<index<<endl;
return t; }
/*SET SET::comb(SET A,SET B){
 SET C;
 Node *curr=A.head
->pnext;
 Node* curr1=B.head
->pnext;
 while(curr){
 C.push_back(curr
->data);
 curr=curr
->pnext;

}
 while(curr1){
 C.push_back(curr1
->data);
4
 curr1=curr1
->pnext;

}
 Size=Size+B.GetSize();
 return C;
}*/
void SET:: printSET(){
 Node *curr=head;
 while(curr){
 cout<<curr
->data<<" ";
 curr=curr
->pnext;

}
}
int main(){
 SET lst;
 lst.push_back(7);
 lst.push_back(8);
 lst.push_back(9);
 lst.push_back(10);
 lst.printSET();
 SET lst1;
 lst1.push_back(11);
 lst1.push_back(12);
 lst1.push_back(13);
 lst1.push_back(14);
5
 // cout<<comb(lst1,lst);

}
// Q3= Q1 և Q2 REVERSED
#include <iostream>
using namespace std;
class Queue
{
public:
 Queue (int n);
 ~Queue ();
 bool empaty ();
 int front ();
 void enqueue (int obj);
 void dequeue ();
 void reverseQueue (Queue & q);
 void marged_queue (Queue q1, Queue q2);
private:
 int size;
 int front_index;
 int rear_index;
6
 int capacity;
 int *data_array;
};
Queue::Queue (int n):
size (0),
front_index (0),
rear_index (
-1),
capacity (n),
data_array (new int[capacity]) {}
Queue::~Queue () {
 delete[]data_array; }
bool
Queue::empaty () {
 return size == 0; }
int
Queue::front ()
7
{
 return data_array[front_index]; }
void
Queue::enqueue (int obj) {
 if (size == capacity)

{
 return;

}
 ++rear_index;
 if (rear_index == capacity)

{
 rear_index = 0;

}
 data_array[rear_index] = obj;
 size++; }
void
Queue::dequeue () {
 if (empaty ())

{
8
 return;

}
 size--
;

++front_index;
 if (front_index == capacity)

{
 front_index = 0;

}
}
void
reverseQueue (Queue & q) {
 if (q.empaty ())

{
 return;

}
 int fr = q.front ();
 q.dequeue ();
 reverseQueue (q);
 q.enqueue (fr); }
int
main ()
9
{
 Queue Q1 (7);
 Queue Q2 (8);
 for (int i = 1; i <= 7; i++)

{
 Q1.enqueue (i);

}
 /* while(!Q1.empaty()){
 cout<<Q1.front()<<" ";
 Q1.dequeue();
 } */
 cout << endl;
 for (int i = 8; i <= 16; i++)

{
 Q2.enqueue (i);

}
 /* while(!Q2.empaty()){
 cout<<Q2.front()<<" ";
 Q2.dequeue();
 } */
 cout << endl;
 Queue conected (20);
 while (!Q1.empaty () || !Q2.empaty ())

{
 if (!Q1.empaty ())
10
{
 int temp = Q1.front ();
 conected.enqueue (temp);
 Q1.dequeue (); }
 else if (!Q2.empaty ()) {
 int temp2 = Q2.front ();
 conected.enqueue (temp2);
 Q2.dequeue (); }

}
 /* while(!conected.empaty()){
 cout<<conected.front()<<" ";
 conected.dequeue();
 } */
 reverseQueue (conected);
 while (!conected.empaty ())

{
 cout << conected.front () << " ";
 conected.dequeue ();

}
}
