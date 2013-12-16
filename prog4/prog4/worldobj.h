//
// worldobj.h
//

#ifndef WORLDOBJ_H
#define WORLDOBJ_H
#include<iostream>

#include <string>
#include <sstream>
#include <QString>
#include <vector>

using namespace std;

// The ancestor of all objects in the world
class WorldObject {
    int id;
    int x, y;
    string image;
    static int nextId;

protected:
    bool Alive;
    int kills;
public:
    WorldObject(int initX, int initY, string initImg):
        x(initX), y(initY) {
        id = ++nextId;
        image = initImg;
        Alive = true;
        kills;
    }

    void setKills(int in){kills =0;}
    string virtual getType(){return "basic";}

    WorldObject(): x(0), y(0) {
        id = ++nextId;
    }
    ~WorldObject() {}

    // updates entity's position in world
    virtual void updatePosition() { }

    // returns a textual representation of this object
    virtual string toString();

    virtual void Move();
    // accessors

    virtual void Kill(WorldObject*){}

    int getId() { return id; }
    string getImage() { return image; }

    bool virtual isAlive(){return Alive;}
    virtual void setAlive(bool in){
        Alive = true;
    }

    // mutators
    void newid0(){ nextId = 0;}
    void setId(int newId) { id = newId; }
    //Bounds Checking!!! & Other movementy Stuff
    void setX(int newX) { if(newX > 0 && newX < 515){x = newX;} }
    void setY(int newY) {if(newY > 0 && newY < 340){ y = newY;} }
    int getx() {return x;}
    int gety() {return y;}

    void setImage(const string& newImg) { image = newImg; }

};

// An object that moves randomly about the world
class Wanderer : public WorldObject {


public:
    Wanderer(){
        Alive = true;
    }
    //Lame wanderer class that just walks around waiting for certain DOOM!!!
    string toString();
    string getType(){return "wa";}
    void Move();
    void setAlive(bool in){
        Alive = in;
    }

};


// An object which moves towards a target object
class Tracker : public WorldObject {
private:
    vector<Wanderer*> wanderers;

public:
    string toString();
    string getType(){return "tr";}

    //Fun Tracker Methods to find, Follow, and KILL Wanderers.
    void Move();
    Wanderer* getClosestWand();
    void follow(Wanderer*);
    void getWands(vector<WorldObject*>);
    void Kill(Wanderer *);
    void GotKill();

    //Unkillable Trackers
    bool getAlive(){return true;}
};

#endif // WORLDOBJ_H
