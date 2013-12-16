//
// world.h
//

#ifndef WORLD_H
#define WORLD_H

#include <string>
#include <vector>

#include "worldobj.h"

using namespace std;

class World {
private:
    vector<WorldObject*> objects;
    World(){}
    
public:
    // World() { }
    int getSize();
    WorldObject *createObject(const string& type);

    // adds <obj> to objects in world
    void add(WorldObject *obj);

    // returns object with <id>, or NULL if none
    WorldObject *getById(int id);
    //finds the spot to erase
    int eraseSpot(WorldObject*);
    //gets teh objects all of them.
    vector<WorldObject*>& getObjects() { return objects; }

    // Removes object with <id> from objects and returns it, or returns NULL if not found
    WorldObject *destroy(int id);
    //overlloaded destroy to destroy an object and it's   place inn the vector directly
    WorldObject *destroy(WorldObject*);
    // Resets world
    void reset();

    // Destroy objects
    ~World();
    
    
    //singlton stuff
private:
    static World instance;
    
    
public:

    static World& getInstance()
    {
        return instance;
    }

};


//extern World world;

#endif // WORLD_H
