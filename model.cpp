#include "model.h"
#include "vector"



//   e-------f        ^Y
//  /|      /|        |
// / |     / |        |
//h--|----g  |        |
//|  a----|--b        |
//| /     | /         |
//d-------c          / --------->X
//                  /
//                 /z
struct coordinates{
    double x;
    double y;
    double z;
    coordinates():x(0),y(0),z(0){}
} coordinates;

model::model()
{

}


class Model{
public:

    Model(){
        coordinates startingPoint;
        startingPoint.x = PULLY_OFFSET_XZ;
        startingPoint.y = PULLY_OFFSET_Y;
        startingPoint.z = PULLY_OFFSET_XZ;
        path = new std::vector<coordinates>;
        path.push_back(startingPoint);
        currentView = 0;
    }



    bool addNewPointInsert(double x,double y, double z,int index){
        //error checking for out of bounds
        //out of bounds return false
        //in bounds add point to path + return true
    }

private:
    static const double ROBOT_WIDTH = 2000;
    // TODO: this isn't the real height.... I forgot it
    static const double ROBOT_HEIGHT = 1500;
    static const double ROBOT_DEPTH = 2000;
    // TODO: measure this
    static const double PULLY_OFFSET_XZ = 30;
    static const double PULLY_OFFSET_Y = 30;


    std::vector<coordinates> path;
    int currentView;


    bool isPointOutOfBounds(double x,double y, double z){

    }




};
