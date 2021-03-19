#include<stdio.h>
#include<math.h>
struct point
{
    float x;
    float y;
};
typedef struct point Point;

struct rectangle
{
    int n;
    float r;
    Point p[3];
};
typedef struct rectangle Rect;


Point input_one_point()
{
    Point p;
    scanf("%f", &p.x);
    scanf("%f", &p.y);
    return p;
}
void input_three_points(Point p[])
{
    for (int i = 0; i < 3; i++)
        p[i] = input_one_point();
}
void input_tCases(Rect R[])
{
    scanf("%d", &R[0].n);
    for (int i = 0; i < R[0].n; i++)
    {
        R[i].n = R[0].n; //each rectangle has n
        input_three_points(R[i].p);
    }
}
void compute(Rect R[])
{
    for (int i = 0; i < R[0].n; i++)
    {
        float d, d1, d2, d3;
        d1 = sqrt(pow(R[i].p[1].x - R[i].p[0].x, 2) + pow(R[i].p[1].y - R[i].p[0].y, 2));
        d2 = sqrt(pow(R[i].p[2].x - R[i].p[0].x, 2) + pow(R[i].p[2].y - R[i].p[0].y, 2));
        d3 = sqrt(pow(R[i].p[1].x - R[i].p[2].x, 2) + pow(R[i].p[1].y - R[i].p[2].y, 2));
        if (d1 > d2 && d1 > d3)
            d = d2 * d3;
        else if (d2 > d1 && d2 > d3)
            d = d1 * d3;
        else
            d = d1 * d2;
        R[i].r = d;
    }

}
void display(Rect R[])
{
    for (int i = 0; i < R[0].n; i++)
    {
        printf("Area of rectangle with vertices (%0.1f,%.1f),(%.1f,%.1f),(%.1f,%.1f) is %.1f\n", R[i].p[0].x, R[i].p[0].y, R[i].p[1].x, R[i].p[1].y, R[i].p[2].x, R[i].p[2].y, R[i].r);
    }
}
int main()
{
    Rect R[100];
    input_tCases(R);
    compute(R);
    display(R);
    return 0;
}
