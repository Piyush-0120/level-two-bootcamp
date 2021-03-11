#include<stdio.h>
#include<math.h>
struct point
{
	float x;
	float y;
};
typedef struct point Point;

int tCases()
{
    int n;
    scanf("%d",&n);
}
Point input()
{
    Point p;
    scanf("%f",&p.x);
    scanf("%f",&p.y);
    return p;
}
void input_3(Point *p)
{
    for(int i=0;i<3;i++)
        p[i]=input();
}
void compute(Point *p,float *r)
{
    float d,d1,d2,d3;
    d1=sqrt(pow(p[1].x - p[0].x,2)+pow(p[1].y - p[0].y,2));
    d2=sqrt(pow(p[2].x - p[0].x,2)+pow(p[2].y - p[0].y,2));
    d3=sqrt(pow(p[1].x - p[2].x,2)+pow(p[1].y - p[2].y,2));
    if(d1>d2 && d1>d3)
        d=d2*d3;
    else if(d2>d1 && d2>d3)
        d=d1*d3;
    else
        d=d1*d2;
    *r=d;
}
void display(Point *p,float *r)
{
    printf("Area of rectangle with vertices (%0.1f,%.1f),(%.1f,%.1f),(%.1f,%.1f) is %.1f\n",p[0].x,p[0].y,p[1].x,p[1].y,p[2].x,p[2].y,*r);
}
int main()
{
    int n;
    n=tCases();
    while(n--)
    {
        Point p[3];
        float r;
        input_3(p);
        compute(p,&r);
        display(p,&r);
    }
    return 0;
}
