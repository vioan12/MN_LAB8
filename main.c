#include<stdio.h>
#include<math.h>
int main()
{
    float a[100][100],b[100][100],d[100][100],c[100];
    int k,i,j,n,h;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            scanf("%f",&a[i][j]);
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            if(i==j)
                b[i][j]=1;
            else
                b[i][j]=0;
    for(k=1;k<=n-1;k++){
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++){
                d[i][j]=0;
                for(h=1;h<=n;h++)
                    d[i][j]=d[i][j]+a[i][h]*b[h][j];
            }
        c[k]=0;
        for(i=1;i<=n;i++)
            c[k]=c[k]+d[i][i];
        c[k]=-c[k]/k;
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                if(i==j)
                    b[i][j]=d[i][j]+c[k];
                else
                    b[i][j]=d[i][j];
    }
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++){
            d[i][j]=0;
            for(h=1;h<=n;h++)
                d[i][j]=d[i][j]+a[i][h]*b[h][j];
        }
    c[n]=0;
    for(i=1;i<=n;i++)
        c[n]=c[n]+d[i][i];
    c[n]=-c[n]/n;
    if(c[n]==0)
        printf("Matricea nu este inversabila");
    else{
        printf("Matricea inversa este:");
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                printf("%f ",-b[i][j]/c[n]);
    }
    printf("\nCoeficientii polinomului caracteristic sunt ");
    for(i=1;i<=n;i++)
        printf("%f ",c[i]);
    return 0;
}
