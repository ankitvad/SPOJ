#include <iostream>
#include <set>
#include <vector>
#include <cmath>

using namespace std;

const int SZ=32000;
//Greedy Approach we now end value so we calculate all primes.
int main() 
{
	
vector<int> primes;
primes.clear();
primes.push_back(2);

int limit=0;
for(int i=3;i<=SZ;i+=2)
{
	bool isprime=true;
	limit=sqrt(i)+1;
	vector<int>::iterator p;
	for(p=primes.begin();p!=primes.end();p++)
	{
		if(*p>=limit) break;
		if(i % *p == 0) 
		{
			isprime=false;
			break;

		}
	}
if(isprime) primes.push_back(i);
}

/*vector<int>::iterator p;

		for(p=primes.begin();p!=primes.end();p++)
		{
			cout<<*p<<endl;
		}
*/

int T;
cin>>T;
set<int> notprime;
for(int i=0;i<T;i++)
{
	notprime.clear();
	int s,e;
	cin>>s>>e;
	if(s==1) s=2;
	for(int j=s;j<=e;j++)
	{
		int temp=sqrt(j);
		vector<int>::iterator p;

		for(p=primes.begin();p!=primes.end();p++)
		{
			if(j==*p) break;
			if(*p>temp) break;
			else
			if((j%*p)==0)
			{
				notprime.insert(j);
				break;

			}
		}
		
	}

for(int i=s;i<=e;i++)
	{
		if(notprime.count(i)==0)
			cout<<i<<endl;
	}

}
return 0;
}



