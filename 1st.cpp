#include<stdio.h> 

int fun(unsigned int n){
	if(n==0 || n==1)
		return n;
	if(n%3 != 0)
		return 0;
	return fun(n/3);
}



int main(){
	printf("joshtechnology\rgroup");
	return 0;
}



A program P reads in 500 integers
in the range [0..100] representing
the scores of 500 students. It then
prints the frequency of each score 
above 50. What would be the best way
for P to store the frequencies?



The array data contains the following
values:
4 4 5 5 6 6 6 7 7 7 8 8
The variable numItems contains 12. 
What is the value of count after the 
following code fragment is executed?

count =0;
for(i=1;i<=numItems-1;i++){
	if(data[i]==data[i-1]){
		count=count+1;
	}
}



int f(int n){
	static int r=0;
	if(n<=0) return 1;
	if(n>3){
		r=n;
		return f(n-2)+2;
	}
	return f(n-1)+r;
}

int main(){
	printf("%d",f(5));
}



void main(){
	int const *p=5;
	printf("%d",++(*p));
}



int Z(char* string, int length){
	int i,j,response;
	i=0;
	j=length-1;
	response=1;

	do{
		if(*(string+i)!=*(string +j)){
			response=0;
		}
		i=i+1;
		j=j-1;
	}while(i<j);
	return response;
}



 incomplete:

struct node{
	int data;
	struct node* next;
};
/* head_ref is a double pointer
   of linked list */
static void reverse(struct node* ){
	struct node* prev = NULL;
	struct node* current = *head_ref;
	struct node* next;
	while(current!=NULL){
		next = current->next;
		current->next = prev;
		prev = current;
		current=next;
	}
	// ADD A STATEMENT HERE
}


int f(int x){
	if(x<=4)
		return x;
	return f(--x);
}
void main(){
	printf("%d ", f(7));
}



void main(){
	int c=- -2;
	printf("c=%d",c);
}



int main(){
	int x=5;
	if(x>=10)
		printf("Hello");
		printf("GFG");
	else printf("hi");
}



Time required to marge two sorted 
lists of size m and n, is



void main(){
	int i=10;
	printf("%d,",i);
	{
		int i=20;
		printf("%d,",i);
		i++;
		printf("%d,",i);
	}
	printf("%d,",i);
}


