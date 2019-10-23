#include <iostream>
#include <cstdlib>
using namespace std;

class prims
{
private:
	int nodes;
	int weight[10][10], visited[10];
public:
	prims()
{
		int i;
		nodes=0;
		for(i=0; i<nodes; i++)
		{
			visited[i]=0;
		}
}
	void accept();
	void prims_mst();
};

void prims :: accept()
{
	int i,j;
	cout<<"Enter total number of nodes: ";
	cin>>nodes;
	cout<<"Enter the adjacency matrix: ";
	for(i=0; i<nodes; i++)
	{
		for(j=0; j<nodes; j++)
		{
			cin>>weight[i][j];
		}
	}
}

void prims :: prims_mst()
{
	int i, j, min, k, l, m, total_cost=0;
	min=9999;
	for(i=0; i<nodes; i++)
	{
		for(j=0; j<nodes; j++)
		{
			if(weight[i][j]<min && weight[i][j]!=0)
			{
				min=weight[i][j];
				k=i;
				l=j;
			}
		}
	}
	cout<<"\nEdge "<<k<<"<-->"<<l<<"having weight: "<<min;
	visited[k]=1;
	visited[l]=1;			//            1/l
	total_cost=min;
	for(m=0; m<nodes-2; m++)
	{
		min=9999;
		for(i=0; i<nodes; i++)
		{
			if(visited[i]==1)		//		1/l
			{
				for(j=0; j<nodes; j++)
				{
					if(visited[j]!=1)		//		1/l
					{
						if(weight[i][j]<min && weight[i][j]!=0)
						{
							min=weight[i][j];
							k=i;
							l=j;
						}
					}
				}
			}
		}
		cout<<"\nEdge "<<k<<"<-->"<<l<<" having weight: "<<min;
		visited[k]=1;
		visited[l]=1;
		total_cost=total_cost+min;
	}
	cout<<"\nTotal cost is: "<<total_cost<<endl;
}

int main() {
	int ch;
	prims p;
	do{
		cout<<"1. Accept the graph\n2. Apply Prim's MST\n3. Exit\nEnter choice: ";
		cin>>ch;
		switch(ch)
		{
		case 1: p.accept();
		break;
		case 2: p.prims_mst();
		break;
		case 3: exit(0);
		default: cout<<"Invalid choice";
		break;
		}}
	while(ch!=3);
	return 0;
}