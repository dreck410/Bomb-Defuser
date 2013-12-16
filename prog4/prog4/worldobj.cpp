//
// worldobj.cpp
//


#include "worldobj.h"
#include "world.h"
#include <QPoint>
#include <QList>
#include <QtMath>
int WorldObject::nextId = 0;


string WorldObject::toString()
{
    stringstream sstrm;
    sstrm << "\t" << id << ": " << x << "," << y << " : " << image;
    return sstrm.str();
}

//------------Over Rides The object's toStirng() method. To display it's type after----------------
string Tracker::toString(){
    stringstream out;
    out << WorldObject::toString() << " (Tracker) #Of Kills: "<< kills;
    return out.str();
}

string Wanderer::toString()
{
    stringstream out;
    out << WorldObject::toString() << " (Wanderer)";
    return out.str();
}
//------------Over Ride Move
void WorldObject::Move()
{
    setX(getx());
    setY(gety());
}

void Tracker::GotKill(){
    kills ++;
}

void Tracker::Kill(Wanderer* in){
    double dis = 0;
    int poop = 0;

    if(in != NULL){
        int x1 = in->getx();
        int x2 = getx();
        int y1 = in->gety();
        int y2 = gety();
        poop = (x1-x2)*(x1-x2);
        poop += (y1 - y2)*(y1-y2);

        dis = sqrt(poop);
        if(dis < 3 && dis > -3){
            in->setAlive(false);
            GotKill();
        }
    }
}

//follows the inputed <wand>
void Tracker::follow(Wanderer *wand)
{
    if(wand != NULL){
        int amountX;
        int amountY;
        if(getx() < wand->getx()){

            amountX = random() % 10;

        }else{
            amountX = random() % 8 - 10;
        }
        if(gety() < wand->gety()){

            amountY = random() % 10;

        }else{
            amountY = random() % 8 - 10;
        }

        setX(getx() + amountX);
        setY(gety() + amountY);
    }
}

// Figures out which one was the closest wanderer
Wanderer* Tracker::getClosestWand()
{

    //get a vector of all the distances
    QList<double> distances;
    double dis = 0;
    for(int i = 0; i < wanderers.size(); i ++){
        int x1 = wanderers.at(i)->getx();
        int x2 = getx();
        int y1 = wanderers.at(i)->gety();
        int y2 = gety();
        int poop = 0;
        poop = (x1-x2)*(x1-x2);
        poop += (y1 - y2)*(y1-y2);

        dis = sqrt(poop);
        distances.push_back(dis);
    }

    QList<double> sortedD = distances;
    qSort(sortedD.begin(), sortedD.end());

    int index = distances.indexOf(sortedD.at(0),0);
    if(index > -1){
        return wanderers.at(index);
    }
    return NULL;
}

// gets a list of all the wanderers
void Tracker::getWands(vector<WorldObject*> objs)
{
    for(int i = 0; i < objs.size(); i++)
    {
        if(objs.at(i)->getType() == "wa")
        {
            wanderers.push_back((Wanderer*)objs.at(i));
        }
    }
}

//moves he tracker object
void Tracker::Move()
{
    //FInds all the wanderers and puts them into a vector
    getWands(World::getInstance().getObjects());

    // now have a vector fo wanderers. follow them.
    if(wanderers.size() > 0)
    {
        Wanderer* obj = this->getClosestWand();

        follow(obj);
        Kill(obj);
    }
    for(int i = 0; i < wanderers.size();){

        wanderers.erase(wanderers.begin() + i);
    }
}

//moves teh wanderer object.
void Wanderer::Move()
{
    int amountX = (random() % 15) - 8;
    int amountY = random() % 15 - 7;
    setX(getx() - amountX);
    setY(gety() - amountY);
}
