//
//  compare.h
//  soft computing project
//
//  Created by Mayank Valluru on 19/04/16.
//  Copyright (c) 2016 Mayank Valluru. All rights reserved.
//

#ifndef soft_computing_project_compare_h
#define soft_computing_project_compare_h


#endif

float com(float a,float b)
{
    if(a<b)
        return a;
    else
        return b;
}

int max_array(float *a,int size)
{
    float max=-90;
    int pos=0;
    int i;
    for(i=0;i<size;i++)
    {
        if(max<*(a))
        {
            max=*(a+i);
            pos=i;
        }
        a++;
    }
    
    return pos;
}
