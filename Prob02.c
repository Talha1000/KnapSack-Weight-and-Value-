#include<stdio.h>

int item(int x, int y)
{
    if(x > y)
    {
        return x;
    }
    else
    {
        return y;
    }
}

void product(int W, int n, int v[], int wt[])
{

    int i,w;
    int V[n+1][W+1];
    for(i=0; i<=n; i++)
    {
        for(w=0; w<=W; w++)
        {
            if(i==0 || w==0)
            {
                V[i][w]=0;
            }

            else if(wt[i] <= w)
            {
                V[i][w] = item(V[i-1][w], v[i] + V[i-1][w - wt[i]]);

            }
            else
            {
                V[i][w] = V[i-1][w];
            }
        }
    }


    printf("\nTotal weight : %d\n", V[n][W]);


}
void productpicked(int n, int W, int wm[])
{
    int i = n;
    int j = W;
    int k[n+1][W+1];

    while (i > 0 && j > 0)
    {
        if(k[i][j] != k[i-1][j])
        {
            printf("\nPicked item no. : %d ",i);
            j = j-wm[i];
            i = i-1;
        }
        else
        {
            i = i-1;
        }
    }

}
int main()
{

    int n,W,i;
    printf("Input the number : ");
    scanf("%d",&n);
    printf("Maximum weight : ");
    scanf("%d",&W);

    int v[n],wt[n];

    for(i=1; i<=n; i++)
    {
        printf("Input weight & value of %d : ",i);
        scanf("%d %d",&wt[i],&v[i]);
    }
    product(W, n, v, wt);
    productpicked(n,W,wt);


}
