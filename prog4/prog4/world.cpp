//
// world.cpp
//
#include<iostream>
#include<string>
#include "world.h"


//Makes the Static Variable Instance
World World::instance;

// returns <object> with <id>, or NULL if none
WorldObject *World::getById(int id) 
{
    for (size_t i = 0; i < objects.size(); ++i) {
        WorldObject *obj = objects.at(i);
        if (obj->getId() == id) {
            return obj;
        }
    }
    return NULL;
}


//finds the position to erase from the vector by passing in the <WorldObject> to erase
int World::eraseSpot(WorldObject* obj)
{
    for (int oo = 0; oo < objects.size(); oo++)
    {
        if(obj == objects.at(oo))
        {
            return oo;
        }//if
    }//for loop
    return -1;
}



//overloaded destroy deletes the specified obj
WorldObject *World::destroy(WorldObject* obj)
{
    if(obj != NULL){
        
        // WorldObject *obj = this->getById(id);
        int ii = eraseSpot(obj);
        delete obj;
        if(ii > -1)
        {
            objects.erase(objects.begin() + ii);
        }
        return obj;
    }
    //else
    return NULL;

}


//deletes the worldobjects* inside of objects<> and sets nextId to 0
void World::reset()
{
    for(int u = 0; u < objects.size(); u++){
        WorldObject *obj = objects.at(u);

        destroy(obj);
        obj->newid0();
    }
}


//adds a object to the object vector
void World::add(WorldObject *obj)
{
    objects.push_back(obj);
}


//deletes the WorldObjects inside of The vector
World::~World()
{
    for(int ii = 0; ii < objects.size(); ii++)
    {
        delete objects.at(ii);
    }
}

//Gets the size of the Objects array... Just an easier way to call.
int World::getSize()
{
    return objects.size();
}

// factory: creates and returns a WorldObject or derived class, determined by
// <type>. Returns NULL if <type> is not recognized.
WorldObject *World::createObject(const string& type)
{
    if (type.find("ba") == 0)
        return new WorldObject;
    else if (type.find("tr") == 0)
        return new Tracker;
    else if (type.find("wa") == 0)
        return new Wanderer;
    else
        return NULL;
}
