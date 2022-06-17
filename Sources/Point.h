#ifndef POINT_H
#define POINT_H
#define round(a) (int)(a + 0.5)

class Point
{
public:
    int x;
    int y;
    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
};

class Point3D
{
public:
    int x;
    int y;
    int z;
    Point3D(int x, int y, int z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }
};

Point *get2Dfrom3D(Point3D *p)
{
    float a = (float)p->x - (float)p->y / sqrt(2);
    float b = (float)p->z - (float)p->y / sqrt(2);
    int ra = round(a);
    int rb = round(b);
    return new Point(ra, rb);
}

#endif