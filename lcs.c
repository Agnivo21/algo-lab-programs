#include<stdio.h>
#include<string.h>
int max(int a ,int b)
{
return (a > b ? a : b);
}
int lcs(char *a,char *b,int m,int n)
{
    int l[m+1][n+1];
    for(int i = 0 ; i<=m;i++)
    {
        for(int j =0 ; j<=n;j++)
        {
            if( i == 0 || j == 0)
            l[i][j] = 0;
            else if(a[i-1] == b[j-1])
            l[i][j] =1+l[i-1][j-1];
            else
            l[i][j] = max(l[i-1][j],l[i][j-1]); 
        }
    }
    return l[m][n];
}
int main(){
    char a[]="AGGTAB";
    char b[]="GXTXAYB";
    int m = strlen(a);
    int n = strlen(b);
    int res = lcs(a,b,m,n);
    printf("%d",res);
    return 0;
}