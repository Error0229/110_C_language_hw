#include "Shape.h"
#include <stdio.h>
int main()
{
    int n;
    char c;
    double perimeter_tot = 0.0L, area_tot = 0.0L, Perimeter, Area;
    scanf("%d", &n);
    while (n--) {
        getchar();
        scanf("%c", &c);
        switch (c) {
        case 'C': {
            double radius;
            scanf("%lf", &radius);
            circle_t* c = circle_new(radius);
            Perimeter = c->perimeter(c);
            Area = c->area(c);
            free(c);
            break;
        }
        case 'R': {
            double width, height;
            scanf("%lf%lf", &width, &height);
            rectangle_t* r = rectangle_new(width, height);
            Perimeter = r->perimeter(r);
            Area = r->area(r);
            free(r);
            break;
        }
        case 'S': {
            double side;
            scanf("%lf", &side);
            square_t* s = square_new(side);
            Perimeter = s->perimeter(s);
            Area = s->area(s);
            free(s);
            break;
        }
        case 'T': {
            double edge_x, edge_y, edge_z;
            scanf("%lf%lf%lf", &edge_x, &edge_y, &edge_z);
            triangle_t* t = triangle_new(edge_x, edge_y, edge_z);
            Perimeter = t->perimeter(t);
            Area = t->area(t);
            free(t);
            break;
        }
        default:
            break;
        }
        printf("%.2f %.2f\n", Perimeter, Area);
        perimeter_tot += Perimeter;
        area_tot += Area;
    }
    printf("%.2f %.2f\n", perimeter_tot, area_tot);
    return 0;
}