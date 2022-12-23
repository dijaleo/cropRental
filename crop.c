#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

unsigned short count=1;

//dob= date of birth stored like 05082003
typedef struct Customer{
    char* first_name;
    char* last_name;
    Date dob;
    unsigned short id;
}Customer;

//locm= last oil change mileage
typedef struct Car{
    unsigned short id;
    int year;
    int mileage;
    int nbr_seats;
    int locm;
    float cost;
    char* make;
    char* model;
    char* plate;
    char* class;
    char* status;
    bool availability;
}Car;

typedef struct Rent{
    unsigned short id;
    int cus_id;
    int car_id;
    Date date;
    int duration;
}Rent;

typedef struct customer_list{
    Customer cus;
    struct customer_list* previous;
    struct customer_list* next;
}customer_list;

typedef struct fleet{
    Car car;
    struct fleet* previous;
    struct fleet* next;
}fleet;

typedef struct rent_list{
    Rent rent;
    struct rent_list* previous;
    struct rent_list* next;
}rent_list;

typedef struct Date{
    int dd, mm, yyyy;
}Date;

//TODO addCustomer, addCar, addRent

Customer createCustomer(char *fName, char *lName, Date DoB){
    Customer c;
    c.first_name=fName;
    c.last_name=lName;
    c.dob=DoB;
    c.id=count++;
    return c;
}

Car createCar(int yyyy, int miles, int seat_nbr, int oil, float price, char* ma, char* mo, char* pla, char* cla, char* stat, bool avail){
    Car c;
    c.year=yyyy;
    c.mileage=miles;
    c.nbr_seats=seat_nbr;
    c.locm=oil;
    c.cost=price;
    c.make=ma;
    c.model=mo;
    c.plate=pla;
    c.class=cla;
    c.status=stat;
    c.availability=avail;
    c.id=count++;
    return c;
}

Rent createRent(int customerID, int carID, Date d, int dur){
    Rent r;
    r.car_id=carID;
    r.cus_id=customerID;
    r.date=d;
    r.duration=dur;
    r.id=count++;
    return r;
}

customer_list* createCustomerList(Customer c){
    static customer_list *l;
    l->cus=c;
    l->next=NULL;
    l->previous=NULL;
    return l;
}