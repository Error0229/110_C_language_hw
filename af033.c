#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TransportationText(TYPE) \
    char name[20];               \
    double speed;                \
    int distance;                \
    int (*price)(struct TYPE*);  \
    double (*time)(struct TYPE*)

typedef struct car_s {
    int oilPrice;
    int parkPrice;
    int tolls;
    TransportationText(car_s);
} car_t;

int CarPrice(car_t* obj)
{
    int k = obj->distance % 100 ? ((obj->distance / 100) + 1) : (obj->distance / 100);
    return k * 10 * obj->oilPrice + k * obj->tolls + obj->parkPrice;
}

double CarTime(car_t* obj)
{
    return (double)obj->distance / (double)obj->speed;
}

void CarCreate(car_t* obj)
{
    strcpy(obj->name, "Car");
    obj->speed = 100;
    obj->price = CarPrice;
    obj->time = CarTime;
}

typedef struct bike_s {
    int rentPrice;
    TransportationText(bike_s);
} bike_t;

int BikePrice(bike_t* obj)
{
    return obj->rentPrice;
}

double BikeTime(bike_t* obj)
{
    return (double)obj->distance / (double)obj->speed;
}

void BikeCreate(bike_t* obj)
{
    strcpy(obj->name, "Bike");
    obj->speed = 20;
    obj->price = BikePrice;
    obj->time = BikeTime;
}

typedef struct bus_s {
    int ticketPrice;
    int extras;
    TransportationText(bus_s);
} bus_t;

int BusPrice(bus_t* obj)
{
    if (obj->distance <= 100)
        return obj->ticketPrice;
    return obj->ticketPrice + obj->extras * ((obj->distance - 100) % 50 ? ((obj->distance - 100) / 50 + 1) : ((obj->distance - 100) / 50));
}
double BusTime(bus_t* obj)
{
    return (double)obj->distance / (double)obj->speed;
}
void BusCreate(bus_t* obj)
{
    strcpy(obj->name, "Intercity Bus");
    obj->speed = 75;
    obj->price = BusPrice;
    obj->time = BusTime;
}

typedef struct scooter_s {
    int oilPrice;
    TransportationText(scooter_s);
} scooter_t;

int ScooterPrice(scooter_t* obj)
{
    return obj->oilPrice * 4 * (int)((int)(obj->distance / 100) * 100 < obj->distance ? (obj->distance / 100 + 1) : (obj->distance / 100));
}
double ScooterTime(scooter_t* obj)
{
    return (double)obj->distance / (double)obj->speed;
}
void ScooterCreate(scooter_t* obj)
{
    strcpy(obj->name, "Scooter");
    obj->speed = 50;
    obj->price = ScooterPrice;
    obj->time = ScooterTime;
}

int main()
{
    int x, y, o, p, t, r;
    car_t* car = (car_t*)malloc(sizeof(car_t));
    bike_t* bike = (bike_t*)malloc(sizeof(bike_t));
    bus_t* bus = (bus_t*)malloc(sizeof(bus_t));
    scooter_t* scooter = (scooter_t*)malloc(sizeof(scooter_t));
    scanf("%d %d", &x, &y);
    scanf("%d %d%d", &o, &p, &t);
    car->oilPrice = o;
    car->parkPrice = p;
    car->tolls = t;
    car->distance = x;
    CarCreate(car);

    scanf("%d", &r);
    bike->rentPrice = r;
    bike->distance = x;
    BikeCreate(bike);

    scanf("%d %d", &o, &p);
    bus->ticketPrice = o;
    bus->extras = p;
    bus->distance = x;
    BusCreate(bus);

    scanf("%d", &o);
    scooter->oilPrice = o;
    scooter->distance = x;
    ScooterCreate(scooter);
    int minPrice = 100000000;
    double min = 100000000;
    char minName[20];
    if (car->price(car) <= y && car->time(car) < min) {
        min = car->time(car);
        minPrice = car->price(car);
        strcpy(minName, car->name);
    }
    if (bike->price(bike) <= y && bike->time(bike) < min) {
        min = bike->time(bike);
        minPrice = bike->price(bike);
        strcpy(minName, bike->name);
    }
    if (bus->price(bus) <= y && bus->time(bus) < min) {
        min = bus->time(bus);
        minPrice = bus->price(bus);
        strcpy(minName, bus->name);
    }
    if (scooter->price(scooter) <= y && scooter->time(scooter) < min) {
        min = scooter->time(scooter);
        minPrice = scooter->price(scooter);
        strcpy(minName, scooter->name);
    }
    if (minPrice == 100000000)
        printf("No Transportation\n");
    else
        printf("%s\n%d\n%.2f", minName, minPrice, min);
}