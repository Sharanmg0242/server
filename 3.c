#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct rtable {
	int dist[20];
	int nextnode[20];
} table[20];

int cost[20][20], adj[20][20], d[20];
int n, node;

void distvector() {
	int i,j,k,count;
	for(i=1;i<=n;i++) {
		for(j=1;j<=n;j++) {
			table[i].dist[j]=cost[i][j];
			table[i].nextnode[j]=j;
		}
	}
	for(i=1;i<=n;i++) {
		for(j=1;j<=n;j++) {
			for(k=1;k<=n;k++) {
				if(table[i].dist[j]>cost[i][k]+table[k].dist[j]) {
					table[i].dist[j]=table[i].dist[k]+table[k].dist[j];
					table[i].nextnode[j]=k;
				}
			}
		}
	}
}


void main() {
	int i,j,ch;
	printf("Enter the no.of nodes : ");
	scanf("%d",&n);
	printf("Enter the cost matrix.\n");
	for(i=1;i<=n;i++) {
		for(j=1;j<=n;j++) {
			scanf("%d",&cost[i][j]);
			if(i!=j&&cost[i][j]==0)
				cost[i][j]=999;
			if(i==j||cost[i][j]==999)
				adj[i][j]=0;
			else
				adj[i][j]=1;
		}
	}
	distvector();
	printf("Enter the node whose route table is to be found : ");
	scanf("%d",&node);
	printf("Enter the delay to neighbouring node :\n");
	for(i=1;i<=n;i++) {
		if(adj[node][i]==1) {
			printf("node-->%d=",i);
			scanf("%d",&cost[node][i]);
		}
	}
	distvector();
	printf("The new routing table for node %d is :\n",node);
	for(i=1;i<=n;i++) {
		printf("%d-->%d\n",table[node].dist[i],table[node].nextnode[i]);
	}
	printf("Shortest path from %d to other node is\n",node);
	for(i=1;i<=n;i++) {
		printf("%d->%d=%d\n",node,i,table[node].dist[i]);
	}
}


Sample output:

Enter the no.of nodes : 4
Enter the cost matrix.
0 3 4 2
3 0 2 999
4 2 0 1
2 999 1 0
Enter the node whose route table is to be found : 1
Enter the delay to neighbouring node :
node-->2=2
node-->3=5
node-->4=1
The new routing table for node 1 is :
0-->1
2-->2
2-->4
1-->4
Shortest path from 1 to other node is
1->1=0
1->2=2
1->3=2
1->4=1

