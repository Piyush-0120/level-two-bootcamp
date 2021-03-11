#include<stdio.h>
#include<math.h>
struct set
{
	int a;
	int b;
};
typedef struct set Set;

int input_n_m()
{
    int n;
    scanf("%d",&n);
    return n;
}
void input_matrix(int n,int a[][n])
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
}

int getRelations(int n,int a[][n],Set *s)
{
    int k=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if( a[i][j] == 1)
            {
                s[k].a=i;
                s[k].b=j;
                k++;
            }
        }
    }
    return k;
}
void compute(Set *s,int n,int *x,int *y,int *z)
{
    int i,j,k,p=0,t=0,u=0,v=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(s[j].a==s[i].b)
            {
                for(k=0;k<n;k++)
                {
                    if(s[k].a==s[i].a && s[k].b==s[j].b)
                    {
                        p=1;
                    }     
                }
                if(p!=1)
                {
                    t=s[i].a;
                    u=s[j].a;
                    v=s[j].b;
                }
            }
            p=0;
        }
    }
    *x=t;
    *y=u;
    *z=v;
}
void display(int x,int y,int z)
{
    if(x==0 && y==0 && z==0)
        printf("transitive\n");
    else
        printf("non-transitive: %d %d %d\n",x,y,z);
}

int main()
{
    int n;
    n=input_n_m();
    while(n--)
    {
        int m,k,x=0,y=0,z=0;
        m=input_n_m();
        int a[m][m];
        Set s[m*m];
        input_matrix(m,a);
        k=getRelations(m,a,s);
        compute(s,k,&x,&y,&z);
        display(x,y,z);
    }
    return 0;
}
