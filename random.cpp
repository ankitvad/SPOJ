#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	string x;
	cin>>x;
	
	int length=x.length();
	vector<char> check(x.begin(),x.end());
	vector<char>::iterator p;
	for(p=check.begin();p!=check.end();p++)
	{
		cout<<*p+1;
	}





		return 0;
}