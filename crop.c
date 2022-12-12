#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//dob= date of birth stored like 05082003
typedef struct Customer{
    char* first_name;
    char* last_name;
    Date dob;
    int id;
}Customer;

//locm= last oil change mileage
typedef struct Car{
    int id;
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
    int id;
    int cus_id;
    int car_id;
    Date date;
    int duration;
}Rent;

typedef struct customer_list{
    Customer cus;
    customer_list* previous;
    customer_list* next;
}customer_list;

typedef struct fleet{
    Car car;
    fleet* previous;
    fleet* next;
}fleet;

typedef struct rent_list{
    Rent rent;
    rent_list* previous;
    rent_list* next;
}rent_list;

typedef struct Date{
    int dd, mm, yyyy;
}Date;

//TODO addCustomer, addCar, addRent
