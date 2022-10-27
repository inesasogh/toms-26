//ՏՈՄՍ 26 (1-4 ՀԱՐՑԵՐ)
//ԱԶԱՏԱՆԴԱՄԻՈՐՈՇՈՒՄ
//ԲԱԶ․ ԱՐԺԵՔԸ X ԿԵՏՈՒՄ
//ԵՐԿՈՒ ԲԱԶ․ ՀԱՆՄԱՆ ԳՈՐԾՈՂ
//ՊՐԻՆՏ ՖՈՒՆԿՑԻԱ
#include <iostream>
using namespace std;
struct node
{
int exp;
double coef;
node* pnext;
node(double c = 1, int e = 0, node* ptr = 0) :
coef(c), exp(e), pnext(ptr) {}
};
class polynom
{
public:
node* Head;
 polynom();
polynom(const polynom& cp);
polynom(double*, int); 
polynom operator + (const polynom&); //գումարում
polynom operator - (const polynom&); // հանում
double result(double) const; //արժեքի հաշվում x կետում
void print() const; //բազմանդամի արտածում
int order() const; //բազմանդամի կարգը
double freeMember() const; // բազմանդամի ազատ անդամը
};
polynom::polynom() {
Head = new node();
}
void polynom::print() const
{
 node* ptr = Head->pnext;
while (ptr)
{
if ((ptr->coef > 0) && (ptr != Head->pnext))
cout << "+";
if (ptr->coef != 1)
cout << ptr->coef;
if (ptr->exp != 0)
cout << "x";
if (ptr->exp != 1 && ptr->exp != 0)
cout << "^" << ptr->exp;
ptr = ptr->pnext;
}
}
polynom::polynom(const polynom& p)
{
node* ptr, *Pptr = p.Head->pnext;
ptr = Head = new node();
while (Pptr)
{
ptr->pnext = new node(Pptr->coef, Pptr->exp);
ptr = ptr->pnext;
Pptr = Pptr->pnext;
}
}
polynom::polynom(double* a, int n)
{
node* ptr = Head = new node();
for (int i = 0; i < n; i++)
if (a[i] != 0)
{
ptr->pnext = new node(a[i], n-1-i);
ptr = ptr->pnext;
}
}
polynom polynom::operator + (const polynom& Q)
{
node* pptr = Head->pnext, *qptr = Q.Head->pnext;
polynom Sum;
node* sumptr = Sum.Head;
while (pptr && qptr)
{
if (pptr->exp > qptr->exp) {
sumptr->pnext = new node(pptr->coef, pptr->exp);
pptr = pptr->pnext;
sumptr = sumptr->pnext;
}
else if (pptr->exp < qptr->exp)
{
sumptr->pnext = new node(qptr->coef, qptr->exp);
qptr = qptr->pnext;
sumptr = sumptr->pnext;
}
else
{
double coefsum = qptr->coef + pptr->coef;
if (coefsum != 0)
{
sumptr->pnext = new node(coefsum, pptr->exp);
sumptr = sumptr->pnext;
}
qptr = qptr->pnext;
pptr = pptr->pnext;
}
}
if (qptr)
pptr = qptr;
while (pptr)
{
sumptr->pnext = new node(pptr->coef, pptr->exp);
pptr = pptr->pnext;
sumptr = sumptr->pnext;
}
return Sum;
}
double Degree(double a, double exp)
{
double result = 1;
while (exp)
{
result *= a;
exp--;
}
return result;
}
double polynom::result(double x) const
{
node* ptr = Head->pnext;
double result = 0;
while (ptr)
{
result += ptr->coef * Degree(x, ptr->exp);
ptr = ptr->pnext;
}
return result;
}
double polynom::freeMember() const
{
return result(0);
}
polynom polynom :: operator-(const polynom& B)
{
polynom ded;
node* ptr1, *ptr2;
ptr1 = Head->pnext;
ptr2 = B.Head->pnext;
while (ptr2)
{
ptr2->coef *= -1;
ptr2 = ptr2->pnext;
}
sub = *this + B;
return ded;
}
int main()
{
const int n = 10;
double arrayA[5] = { 7, 9, 1, 0, -7 };
double arrayB[6] = { -7, 5, 2, 0, 0, 1 };
polynom A(arrayA, 5);
polynom B(arrayB, 6);
polynom ded = A-B;
cout << "A-B="; ded.print(); cout << endl;
return 0;
}




//S1 S2 ՀԵՐԹԵՐԸ;S2=S1 SORTED
#include <iostream>
#include <stack>
using namespace std;
int main(){
 stack<int> S1,S2;
 int item;
 for(int i=0; i<6; i++){
 cin>>item;
 S1.push(item);
 }
const int n= S1.size();
int a[n];
for(int i=0; i<n; i++){
 a[i]=S1.top();
 S1.pop();
}
for(int i=0; i<n; i++){
 for(int j=i+1; j<n; j++){
 if(a[i]<=a[j]){
 swap(a[i], a[j]);
 }
 }
}
for(int i=n-1; i>=0; i--){
 S1.push(a[i]);
}
S2.push(S1.top());
S1.pop();
while(!S1.empty()){
 if(S1.top()!=S2.top()){
 S2.push(S1.top());
 S1.pop();
 }
 else S1.pop();
 }
 while(!S2.empty()){
 cout<<S2.top()<<" ";
 S2.pop();
 }
return 0;
}
