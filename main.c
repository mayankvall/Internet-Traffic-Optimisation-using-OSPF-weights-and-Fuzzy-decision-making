//
//  main.c
//  soft computing project
//
//  Created by Mayank Valluru on 17/03/16.
//  Copyright (c) 2016 Mayank Valluru. All rights reserved.
//

#include <stdio.h>
#include "weight.h"
#include "shortest_path.h"
#include <math.h> 
#include <limits.h>
#include "compare.h" 

int main()
{
    int n;
    printf("Enter the number of nodes\n");
    scanf("%d",&n);
    float c[n][n];float d[n][n];//capacity and distance between the nodes
    float w[n][n];//weights for each of the links
    
    //float bandwidth[n][n];
    
    //note bandwidth changes so it should be put on nXn order
    
    //calculation of weights
    weight_calculation((float *)c,(float *)d,(float *)w,n);
    
    int i,j,k;//countor variable
    
    
    //test wheather it returns 2D array successfully or not
    /*
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%f",w[i][j]);
        }
    }
    */
    //for testing wheather dijshtra is working or not
    /*
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%f",&d[i][j]);
        }
        printf("\n");
    }
     */
    int source,destination;//

    
    int S[n];
    int D[n];
    float dist[n];
    int path[n][n];
    int path_mod[n][n];
    int lk[n];
    int pos_not_dis;
    float sum_up=0.00;
    float mean,variance=0.00;
    float data_packet;
    float load=0.0000;
    float utilization[n][n];
    int utilization_mod[n][n];
    float result_sub[n][n][n];
    float sum_weight;
    float result_sub_weight[n];
    int breaking=-90;
    int inc_breaking=0;//countor
    //initialization of utilization
    
    
    int q,qw,e;//countor variable
    
    int test=-1;
    int pk=0;
    //calculating the shortest paths and recording them
    printf("Enter node for source\n");
    scanf("%d",&source);
    printf("Enter node for destination\n");
    scanf("%d",&destination);
    printf("Enter the data to be send\n");
    scanf("%f",&data_packet);
    
    // test point
    //initializing is important not getting correct answer
    
    while(test==-1)
    {
        sum_weight=0.00;
        
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            path[i][j]=-9999;
            path_mod[i][j]=-1;
        }
    }
    
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                utilization[i][j]=-9999;
                utilization_mod[i][j]=-9999;
            }
        }
        
    Dijkstra_modified((float *)d,source,destination,n,S,D,dist,(int *)path,breaking);
    
    //reversing the order
    
    
    for(i=0;i<n;i++)
    {
        lk[i]=0;
        path_mod[i][lk[i]]=0;
        lk[i]++;
        for(j=n-1;j>=0;j--)
        {
            if(path[i][j]!=-9999)
            {
                path_mod[i][lk[i]]=path[i][j];
                lk[i]++;
                D[i]=path[i][j];
            }
        }
    }
    
    //test case for proper return
    /*
    for(i=0;i<n;i++)
    {
        printf("%d    ",S[i]);
        printf(" %f   ",dist[i]);
        printf("%d    ",D[i]);
        printf("\n");
        for(j=0;j<lk[i];j++)
        {
            printf("%d    ",path_mod[i][j]);
        }
        printf("\n");
    }
    
    */
        
        for(i=0;i<n;i++)
        {
            for(j=0;j<lk[i];j++)
            {
                if(path_mod[i][j]==destination)
                    pos_not_dis=i;
            }
        }
        
        printf("path \n");
        
        
        
             printf("%d    ",S[pos_not_dis]);
             printf(" %f   ",dist[pos_not_dis]);
             printf("%d    ",D[pos_not_dis]);
             printf("\n");
             for(j=0;j<lk[pos_not_dis];j++)
             {
                 printf("%d    ",path_mod[pos_not_dis][j]);
             }
             printf("\n");
        
        
    //fuzzy decision making
        
    /* notes
        1. shortest paths by removing breakage points
        2. making changes if 
        ie making utilization link l(a)/c(a) to minimal 
            is trying to make maximum but limits
     
      1 0 to 1/3
      2 1/3 to 2/3
     10 2/3 to 9/10
     70 9/10 to 1
     5000 1 to 11/10
     5000 greater than 11/10
     
     so my assumption is 70 better than 10 better than 2 better than 500 and 5000 should be set to zero
     
     second thing bandwidth
     
     mean should be high and sd should be low
     
     and third is weight should be low 
     
     so by using these techniques we should take the best path
     */
        
        // try setting as many breakpoints for checking l(a)/w(a)
        
        //adding bandwidth
        
        //mean and variance
          
               /*
        for(k=0;k<lk[pos_not_dis];k++)
        {
            sum_up=sum_up+bandwidth[pos_not_dis][k];
        }
        
        mean=sum_up/lk[pos_not_dis];
        
        for(k=0;k<lk[pos_not_dis];k++)
        {
            variance=variance+(pow((bandwidth[pos_not_dis][k]-mean),2)/2);
        }
        */
               
        //start the w(a)/l(a)
        //calculating utilisation link
        //path_mod 0 1 2
               
              load=data_packet;
        for(q=0;q<lk[pos_not_dis]-1;q++)
        {
            utilization[path_mod[pos_not_dis][q]][path_mod[pos_not_dis][q+1]]=load/c[path_mod[pos_not_dis][q]][path_mod[pos_not_dis][q+1]];
        }
        
        // modifying utilisation according to 1st page of research paper
        
        for(q=0;q<lk[pos_not_dis]-1;q++)
        {
            if(utilization[path_mod[pos_not_dis][q]][path_mod[pos_not_dis][q+1]]>=0&&utilization[path_mod[pos_not_dis][q]][path_mod[pos_not_dis][q+1]]<0.333333)
            {
                utilization_mod[path_mod[pos_not_dis][q]][path_mod[pos_not_dis][q+1]]=1;
            }
            else if(utilization[path_mod[pos_not_dis][q]][path_mod[pos_not_dis][q+1]]>=0.333333&&utilization[path_mod[pos_not_dis][q]][path_mod[pos_not_dis][q+1]]<0.666666)
            {
                utilization_mod[path_mod[pos_not_dis][q]][path_mod[pos_not_dis][q+1]]=3;
            }
            else if(utilization[path_mod[pos_not_dis][q]][path_mod[pos_not_dis][q+1]]>=0.666666&&utilization[path_mod[pos_not_dis][q]][path_mod[pos_not_dis][q+1]]<0.9)
            {
                utilization_mod[path_mod[pos_not_dis][q]][path_mod[pos_not_dis][q+1]]=10;
            }
            else if(utilization[path_mod[pos_not_dis][q]][path_mod[pos_not_dis][q+1]]>=0.9&&utilization[path_mod[pos_not_dis][q]][path_mod[pos_not_dis][q+1]]<1)
            {
                utilization_mod[path_mod[pos_not_dis][q]][path_mod[pos_not_dis][q+1]]=70;
            }
            else if(utilization[path_mod[pos_not_dis][q]][path_mod[pos_not_dis][q+1]]>=1&&utilization[path_mod[pos_not_dis][q]][path_mod[pos_not_dis][q+1]]<1.1)
            {
                utilization_mod[path_mod[pos_not_dis][q]][path_mod[pos_not_dis][q+1]]=500;
            }
            else if(utilization[path_mod[pos_not_dis][q]][path_mod[pos_not_dis][q+1]]>=1.1)
            {
                utilization_mod[path_mod[pos_not_dis][q]][path_mod[pos_not_dis][q+1]]=5000;
            }
            else if(utilization[path_mod[pos_not_dis][q]][path_mod[pos_not_dis][q+1]]<0)
            {
                utilization_mod[path_mod[pos_not_dis][q]][path_mod[pos_not_dis][q+1]]=-5000;
            }
        }
        
        //taking the wieght of sum
        
        for(q=0;q<lk[pos_not_dis]-1;q++)
        {
            sum_weight=sum_weight+w[path_mod[pos_not_dis][q]][path_mod[pos_not_dis][q+1]];
        }
        
        // storing the result
        
        for(qw=0;qw<n;qw++)
        {
            for(e=0;e<n;e++)
            {
                result_sub[pk][qw][e]=utilization_mod[qw][e];
            }
        }
        
        result_sub_weight[pk]=sum_weight;
        
        
        //know remove each bit par head
        
            if(inc_breaking!=source && inc_breaking!=destination)
                breaking=inc_breaking;
            else
                breaking=-90;
        
        inc_breaking++;
        //testing
        
        pk++;
        if(pk==n)
        {
            test=1;
        
        }
        printf("\nTesting node %d \n",pk);
        
        }
    
    
    //fuzzy decision making
    
    //we have all the results stored
    
    float Fd[pk];
    float min_sum=INT_MAX;
    int po_s;
    int max_pos;
    float sub_weight[pk];
    float sub_uti[pk];
    int yt,uy,io;//countor variables
    int tester=0;
    int leo=0;
    int EX=0,VB=0,B=0,O=0,W=0,BAD=0;
    
    {
        //calculation the values for sum_weight
        
        for(yt=0;yt<pk;yt++)
        {
            if(min_sum>result_sub_weight[yt])
            {
                min_sum=result_sub_weight[yt];
                po_s=yt;
            }
        }
        
        //fuzzy values
        
        for(yt=0;yt<pk;yt++)
        {
            sub_weight[yt]=min_sum/result_sub_weight[yt];
        }
        
        
        //utilization links
        
        //it it contains any 5000 no use
        /* 500 avoid but only one than use compare with pk
            70 best try as many 70 10 
         least preference for 3 and 10
         */
        
        //search
        
        for(yt=0;yt<pk;yt++)
        {
            EX=0,VB=0,B=0,O=0,W=0,BAD=0;
            for(uy=0;uy<n;uy++)
            {
                for(io=0;io<n;io++)
                {
                    if(result_sub[yt][uy][io]==5000)
                    {
                        BAD++;
                    }
                    else if(result_sub[yt][uy][io]==500)
                    {
                        W++;
                    }
                    if(result_sub[yt][uy][io]==70)
                    {
                        EX++;
                    }
                    else if(result_sub[yt][uy][io]==10)
                    {
                        VB++;
                    }
                    if(result_sub[yt][uy][io]==3)
                    {
                        B++;
                    }
                    else if(result_sub[yt][uy][io]==1)
                    {
                        O++;
                    }
                }
                
               
            }
            
            if(tester==0)
            {
                sub_uti[yt]=((EX*1+VB*0.8+B*0.6+O*0.35+W*0.1)/(EX+VB+B+O+W));
                if(BAD>0)
                    sub_uti[yt]=0.0000;
            }
            
            tester=0;
            printf("%f  \n",sub_uti[yt]);
        }
        
        
        //Fd is min of both
        
        for(leo=0;leo<pk;leo++)
        Fd[leo]=com(sub_uti[leo],sub_weight[leo]);
        
        max_pos=max_array(Fd,pk);
        for(leo=0;leo<pk;leo++)
            printf("%f \n",Fd[leo]);
        

    }
    
    
    printf("Correct path is %d ",max_pos+1);
    
    
    
}