//
//  Header.h
//  soft computing project
//
//  Created by Mayank Valluru on 19/03/16.
//  Copyright (c) 2016 Mayank Valluru. All rights reserved.
//

void weight_calculation(float *c,float *d,float *w,int n)
{
    
    int i,j,k;//countor variable
    int entry[n][n];
    
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            *((c+i*n)+j)=0,*((d+i*n)+j)=0,*((w+i*n)+j)=0;
            entry[i][j]=0;
        }
    }
    printf("Enter the capacity of the nodes in nxn-i order\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(entry[i][j]==0)
            {
                scanf("%f",((c+i*n)+j));
                entry[i][j]=1;
            }
        }
        for(k=i+1;k<n;k++)
        {
            *((c+k*n)+i)=*((c+i*n)+k);
            entry[k][i]=1;
        }
        printf("\n");
    }
    
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            entry[i][j]=0;
        }
    }
    
    printf("Enter the distances between the nodes in nxn-i order\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(entry[i][j]==0)
            {
                scanf("%f",((d+i*n)+j));
                entry[i][j]=1;
            }
        }
        for(k=i+1;k<n;k++)
        {
            *((d+k*n)+i)=*((d+i*n)+k);
            entry[k][i]=1;
        }
        printf("\n");
    }
    
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            entry[i][j]=0;
        }
    }
    
    
    
    
    
    //setting up weights
    
    // according to research paper the weights are inversely proportional to distance and propotional to capacity so if we divide we get max value for max number and negagte for the other
    
    float c_change[n][n],d_change[n][n];//changed value indirectly based upon ranking order
    
    // if two values are same than depends on other value
    
    //first max value
    
    int max_c=*c,min_d=9999;//note the key changes according to question
    
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(max_c<*((c+i*n)+j))
            {
                max_c=*((c+i*n)+j);
            }
            
            if(min_d>*((d+i*n)+j)&&*((d+i*n)+j)!=0)
            {
                min_d=*((d+i*n)+j);
            }
        }
    }
    
    //know we have max values
    
    //calculating the changes
    
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            c_change[i][j]=*((c+i*n)+j)/max_c;
            if(*((d+i*n)+j)!=0)
                d_change[i][j]=min_d/(*((d+i*n)+j));
            else
                d_change[i][j]=0;
        }
    }
    
    //to get the weight
    
    
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            *((w+i*n)+j)=(c_change[i][j]+d_change[i][j])/2;
        }
    }
    
    //so we get the weight function according to desire
    
}

