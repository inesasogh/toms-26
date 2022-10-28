//TOMS-2 HARC 5

#include <iostream>
#include <deque>
#include <climits>
using namespace std;
using namespace std;
  
void showdq(deque<int> g)
{
    deque<int>::iterator it;
    for (it = g.begin(); it != g.end(); ++it)
        cout << '\t' << *it;
    cout << '\n';
}
  int MinIndex(deque <int> &q,int SortedIndex){
    int min_value=INT_MAX;
    int min_index=-1;
    int n=q.size();
    for(int i=0;i<n;i++){
        int current=q.front();
            q.pop();
            if(current<=min_value && i<=SortedIndex){
                min_value=current;
                min_index=i;
            }
            q.push(current);
        }
    return min_index;
}
void InsertMinToRear(deque <int> &q,int min_index){
    int min_value;
    int n=q.size();
    for(int i=0;i<n;i++){
        int current=q.front();
        q.pop();
        if(i!=min_index){
            q.push(current);
        }
        else{
            min_value=current;
        }
        q.push(min_value);
    }
}
void SortQueue(deque <int> &q){
    for(int i=1;i<=q.size();i++){
        int min_index=MinIndex(q,q.size()-1);
         InsertMinToRear(q,min_index);
    }
}
int main()
{
    deque<int> Q1;
    deque<int> Q2;
    Q1.push_back(10);
    Q1.push_back(541); 
    Q1.push_back(14);
    Q1.push_back(50);
    Q1.push_back(80);
    int n=Q1.size();
    for(int i=0;i<n;i++){
        Q2.push_back(Q1.front());
            Q1.pop_front();
    }
    cout << "The deque Q2 is : ";
    SortQueue(Q2);
    showdq(Q2);
    return 0;
}
