#include <math.h>
#include <stdlib.h>
#define Shape(TYPE)                    \
    double (*perimeter)(struct TYPE*); \
    double (*area)(struct TYPE*);
#define PI 3.14

typedef struct circle_s {
    Shape(circle_s);
    double radius;
} circle_t;
double circle_perimeter(circle_t* cr)
{
    return (double)2.0 * PI * cr->radius;
}
double circle_area(circle_t* cr)
{
    return (double)PI * cr->radius * cr->radius;
}
circle_t* circle_new(double radius)
{
    circle_t* c = (circle_t*)malloc(sizeof(circle_t));
    c->radius = radius;
    c->perimeter = circle_perimeter;
    c->area = circle_area;
    return c;
}

typedef struct rectangle_s {
    Shape(rectangle_s);
    double width;
    double height;
} rectangle_t;
double rectangle_perimeter(rectangle_t* r)
{
    return (double)2 * (r->width + r->height);
}
double rectangle_area(rectangle_t* r)
{
    return (double)r->width * r->height;
}
rectangle_t* rectangle_new(double width, double height)
{
    rectangle_t* r = (rectangle_t*)malloc(sizeof(rectangle_t));
    r->width = width;
    r->height = height;
    r->perimeter = rectangle_perimeter;
    r->area = rectangle_area;
    return r;
}

typedef struct triangle_s {
    Shape(triangle_s);
    double edge_x, edge_y, edge_z;
} triangle_t;
double triangle_perimeter(triangle_t* t)
{
    return (double)t->edge_x + t->edge_y + t->edge_z;
}
double triangle_area(triangle_t* t)
{
    double k = (t->edge_x + t->edge_y + t->edge_z) / 2;
    return sqrt(k * (k - t->edge_x) * (k - t->edge_y) * (k - t->edge_z));
}
triangle_t* triangle_new(double edge_x, double edge_y, double edge_z)
{
    triangle_t* t = (triangle_t*)malloc(sizeof(triangle_t));
    t->edge_x = edge_x;
    t->edge_y = edge_y;
    t->edge_z = edge_z;
    t->perimeter = triangle_perimeter;
    t->area = triangle_area;
    return t;
}

typedef struct square_s {
    Shape(square_s);
    double side;
} square_t;
double square_perimeter(square_t* s)
{
    return (double)4 * s->side;
}
double square_area(square_t* s)
{
    return (double)s->side * s->side;
}
square_t* square_new(double side)
{
    square_t* s = (square_t*)malloc(sizeof(square_t));
    s->side = side;
    s->perimeter = square_perimeter;
    s->area = square_area;
    return s;
}