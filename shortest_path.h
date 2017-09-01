//
//  shortest_path.h
//  soft computing project
//
//  Created by Mayank Valluru on 2/04/16.
//  Copyright (c) 2016 Mayank Valluru. All rights reserved.
//



//it's bidirectional

//problem is multiple transfer of  2D array

#include <limits.h>


int MIND(float distance[],int visited[],int n)
{
    float min=INT_MAX,MINI=0;
    
    for (int v=0;v<n;v++)
    {
        if (visited[v]==0&&distance[v]<=min)
        {
            min=distance[v],MINI=v;
        }
    }
    
    return MINI;
}


void show_path(int root_node[],int pos,int *path,int t,int size,int c)
{

    if(root_node[pos]==-1)
    {
        c=c+1;
        *((path+(size*t))+c)=-9999;
        return;
    }
    c=c+1;
    show_path(root_node,root_node[pos],path,t,size,c);
    
    *((path+(size*(t-1)))+c)=pos;
}

void store_solution(float distance[], int size, int root[],float *dist,int *path,int s)
{
    int c;
    *(dist)=0;
    for (int i=1;i<size;i++)
    {
        c=-1;
        *(dist)=(float)distance[i];
        dist++;
        if(distance[i]==(float)INT_MAX)
            *((path+(size*i))+0)=-9999;
        else
        show_path(root,i,path,i,size,c);
    }
}
void Dijkstra_modified(float *e,int s,int t,int n,int *S,int *D,float *dist,int *path,int breaking)
{
    //the weight passes on also stores the links which exits if non zero number is there
    //i=j, 0 self path is removed
    
    //report any node broke
    
    
    int breakpoint;
    float distance[n];
    int visit[n];
    int root_tree[n];
    int i,count,v,j;
    printf("Enter if any path is broken\n");
    printf("enter negative value if not\n");
    scanf("%d",&breakpoint);
    
    float d[n][n];
    
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            d[i][j]=*((e+i*n)+j);
        }
    }
    
    //disconnecting that point note it should start from zero
    if(breakpoint>=0)
    {
        for(i=0;i<n;i++)
        {
            d[breakpoint][i]=0;
            d[i][breakpoint]=0;
        }
     
    }
    
    if(breaking>=0)
    {
        for(i=0;i<n;i++)
        {
            d[breaking][i]=0;
            d[i][breaking]=0;
        }
    }
    
    for (i=0;i<n;i++)
    {
        root_tree[0]=-1;
        distance[i]=INT_MAX;
        visit[i]=0;
        *(S+i)=s;
    }
    
    distance[s]=0.00000;
    
    for (count=0;count<n-1;count++)
    {
        int u=MIND(distance,visit,n);
        
        visit[u]=1;
        
        for (v=0;v<n;v++)
            if (!visit[v]&&d[u][v]&&distance[u]+d[u][v]<distance[v])
            {
                root_tree[v]=u;
                distance[v]=distance[u]+d[u][v];
            }
    }
    
    store_solution(distance,n,root_tree,dist,path,s);

}