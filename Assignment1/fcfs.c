void fcfs()
{
    int i,j,temp, temp1;
    Twt=0;
    Ttt=0;
    Printf("\n\n FIRST COME FIRST SERVED ALGORITHM\n\n");
    for(i=1;i<=n;i++)
    {
        for(j=i+1;j<=n;j++)
        {
            if(A[i]>A[j])
            {
                temp=Bu[i];
                temp1=A[i];
                Bu[i]=Bu[j];
                A[i]=A[j];
                Bu[j]=temp;
                A[j]=temp1;
                strcpy(c[i],pname[i]);
                strcpy(pname[i],pname[j]);
                strcpy(pname[j],c[i]);
            }
        }
    }
    