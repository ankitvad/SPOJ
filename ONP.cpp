#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <cctype>
using namespace std;



int set_operand(char op)
		{
			int x;
			if(op=='^') x=4;
			if(op=='/'||op=='*') x=3;
			if(op=='+'||op=='-') x=2;
			if(op=='('||op==')') x=1;

			return x;
		}

int main()
{
	int t;
	cin>>t;
	vector<char>pooper[t];
	for(int i=0;i<t;i++)
	{
				
		string poop;
		cin>>poop;
		vector<char> expression(poop.begin(),poop.end());
		expression.push_back('\0');
		vector<char> operandstack;
		vector<char> outputqueue;

		vector<char>::iterator c;
		for(c=expression.begin();c!=expression.end();c++)
		{
			if(*c=='(') operandstack.push_back(*c);
			else if((*c=='^')||(*c=='*')||(*c=='/')||(*c=='+')||(*c=='-'))
			{
				int temp=set_operand(*c);
				vector<char>::iterator a;	
				for(a=operandstack.end()-1;a>=operandstack.begin();a--)
				{
					int temp2=set_operand(*a);
					if(temp2<temp)
					{
						operandstack.push_back(*c);
						break;
					}
					if(temp2>=temp)
					{
						outputqueue.push_back(*a);
						operandstack.pop_back();
					}
				}
			
			}
			else if(*c==')')
			{
				vector<char>::iterator temp;
				temp=operandstack.end()-1;
				while(*temp!='(')
				{
					outputqueue.push_back(*temp);
					operandstack.pop_back();
					temp--;
				}
				operandstack.pop_back();
			}
			else
			outputqueue.push_back(*c);
				

		}

		vector<char>::iterator x;
		for(x=operandstack.end()-1;x>=operandstack.begin();x--)
		{
			outputqueue.push_back(*x);
		}
vector<char>::iterator y;
for(y=outputqueue.begin();y!=outputqueue.end();y++)
{
	pooper[i].push_back(*y);
	//cout<<*y;
}
}
for(int j=0;j<t;j++)
{
	vector<char>::iterator zoom;
	for(zoom=pooper[j].begin();zoom!=pooper[j].end();zoom++)
	{
		cout<<*zoom;
	}
	cout<<endl;
}
return 0;
}
