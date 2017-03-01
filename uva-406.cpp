#include<iostream>
#include<vector>
#include<cstdio>

using namespace std;

std::vector<int>L;
int num[1010];
int prime[1010];
int is_p[1010];

bool is_prime(int x)//判断是否是质数
{
	int i;
	for(i=2;i*i<=x;i++)
		if(x%i==0)
			return 0;
	return 1;
	}

main()
{
	int i,c,n;
	for(i=1;i<=1000;i++)
		is_p[i]=is_prime(i);//打表判断质数
	num[0]=0;
	for(i=1;i<=1000;i++)
		num[i]=num[i-1]+is_p[i];//num[i]表示到i为止一共有多少个质数
    L.clear();//清空向量
	for(i=1;i<1000;i++)
		if(is_p[i])
			L.push_back(i);//L重新设成质数表
	while(scanf("%d%d",&n,&c)!=EOF)
	{
		printf("%d %d:",n,c);
		if(num[n]<=2*c)
		{
			for(i=0;i<num[n];i++)
				printf(" %d",L[i]);
			}
		else
		{
			if(num[n]&1)
			{
				int m=(num[n]-1)/2;
				for(i=m+1-c;i<=m+c-1;i++)
					printf(" %d",L[i]);
			}
			else
			{
				int m=num[n]/2;
				for(i=m-c;i<=m+c-1;i++)
					printf(" %d",L[i]);
			}
		}
		printf("\n\n");
	}
}
