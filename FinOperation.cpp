#include"FinOperation.h"
#include"LVehicle.h"
#include"WVehicle.h"
#include"Vehicle.h"
#include<iostream>
using namespace std;

FinOperation :: FinOperation(Vehicle** vehicles,int size)
{
    _vehicles=vehicles;
    _size=size;
}
int FinOperation :: RR_request(string type,int passenger)
{
    int min=100000;
    int index=-1;
    for(int i=0;i<_size;i++)
    {
        if (_vehicles[i]->passenger_occupancy()>=passenger && _vehicles[i]->type()==type)
        {
            if(min>=_vehicles[i]->passenger_occupancy())
            {
                min=_vehicles[i]->passenger_occupancy();
                index=i;
            }
        }
    }
    if(index>=0)
    {
        return _vehicles[index]->id();
    }
    else 
    {
        return -1;
    }
}

int FinOperation :: SR_request(string type,int age)
{
   int min=100000000;
    int index=-1;
    for(int i=0;i<_size;i++)
    {
        if (_vehicles[i]->age()>=age && _vehicles[i]->type()==type)
        {
            if(min>=_vehicles[i]->age())
            {
                min=_vehicles[i]->age();
                index=i;
            }
        }
    }

    if(index>=0)
    {
        return _vehicles[index]->id();
    }
    else 
    {
        return -1;
    }
}

float FinOperation :: MT_request(int id)
{
    for(int i=0;i<_size;i++)
    {
        if(_vehicles[i]->id()==id)
        {
            return _vehicles[i]->MT();
        }
    }
}

float FinOperation :: MN_request(int id)
{
    for(int i=0;i<_size;i++)
    {
        if(_vehicles[i]->id()==id)
        {
            return _vehicles[i]->MN();
        }
    }
}

float FinOperation :: income_RR(int id)
{
    for(int i=0;i<_size;i++)
    {
        if(_vehicles[i]->id()==id)
        {
            return _vehicles[i]->RR();
        }
    }
}
float FinOperation :: income_SR(int id)
{
    for(int i=0;i<_size;i++)
    {
        if(_vehicles[i]->id()==id)
        {
            return _vehicles[i]->SR();
        }
    }
}