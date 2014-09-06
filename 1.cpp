#include <iostream>
using namespace std;

int flag=0;
int n;
int main()
{
do
{
	cin>>n;
	if(n==42)
		flag=1;
	if(flag==0)
		cout<<n;

}while(1);
return 0;
}