#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;

int main()
{
	int m;
	ifstream in;
	in.open("input.txt");

in>>m;
struct hash_fun
	{
		long long int a;
		long long int b;
		long long int c;
	};
struct hash_fun S[m];
struct elements
{
	int element;
	int *hash;
};


for(int i=0;i<m;i++)
	in>>S[i].a>>S[i].b>>S[i].c;
	
	

int n;

in>>n;

int k;
int A[n];
//BLOOM FILTER initialization
for(int i=0 ;i< n ;i++)
{
	A[i] = 0;
}

in>>k;
struct elements S1[k] ,S2[n-k];
for(int i=0;i<k;i++)
S1[i].hash =(int*)malloc(m*sizeof(int));
for(int i=0;i<n-k;i++)
S2[i].hash =(int*)malloc(m*sizeof(int));

for(int i=0;i<k;i++)
in>>S1[i].element;
in.close();	  
char fn[100];
sprintf(fn,"op_m%dn%dk%d.txt",m,n,k);
ofstream op;
op.open(fn);	

for(int i =0 ;i< k ;i++)
{
	
	for(int j=0; j< m ;j++)
	{
		
		S1[i].hash[j] =(((S[j].a * (S1[i].element) + S[j].b) % S[j].c)%n);
		if(A[(S1[i].hash[j])]==0)
			A[(S1[i].hash[j])] =1;
	}
}

op<<"m = "<<m<<"\n\n";
op<<"n = "<<n<<"\n\n";
op<<"k = "<<k<<"\n\n";
op<<"The Bloom Filter is \n";
for(int i=0;i<n;i++)
op<<A[i];
op<<"\n\n";
system("bash -c \"read -n 1 -s -p \"Move_forward_with_a_keypress...\"\"\n");
cout<<endl;

int p=0;
op<<"Membership queries for all x <-{U-S}\n"<<endl;

for(int i=0;i<n && p<(n-k);i++)
{
	int j;
	for(j=0;j<k && i!=(S1[j].element);j++);
	if(j==k)
	{
		
		S2[p].element = i;
		
		p++;
	}
}
for(int i=0;i<(n-k) ;i++)
{
	for(int j=0;j<m;j++)
	{
		S2[i].hash[j] =(((S[j].a * S2[i].element + S[j].b) % S[j].c)%n);
		
	}

}
int fp=0;
for(int i=0;i<(n-k) ;i++)
{
	int j;
	for(j=0;j<m && (A[S2[i].hash[j]]==1);j++);
	
		if(j==m)
		{
			fp++;
			op<<S2[i].element<<","<<"False Positive : YES , ";
			int l=0;
					
			while(l<m)
			{
				int flag=0,count=0;
			for(int x =0;x<k;x++)
			{
				for(int y=0;y<m ;y++)
				{
					
					if(S2[i].hash[l] == S1[x].hash[y])
					{
						flag=1;
						op<<"<"<<S1[x].element<<" ,"<<(y+1)<<"> ";
						
						
					}
				}
				
				if(flag==1)
				count++;
				if(count>m)
				break;
				flag=0;
			}
			l++;
				
			}
		}
		else
		{
			op<<S2[i].element<<","<<"False Positive : NO  ";
		}
	op<<endl;
}
double prob;
prob =((double)fp)/(n-k);
op<<"\n"<<"Fraction of false positives , p = "<<prob<<endl;
		
for(int i=0;i<k;i++)
free(S1[i].hash);
	
for(int i=0;i<n-k;i++)
free(S2[i].hash);		

return 0;

}

