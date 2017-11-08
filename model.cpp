#include "model.h"

Model::Model()
{
    coordinate firstPoint;
    firstPoint.x = ROBOT_X_MIN;
    firstPoint.y = ROBOT_Y_MIN;
    firstPoint.z = ROBOT_Z_MIN;
    firstPoint.yaw = 0;
    firstPoint.pitch = 0;
    firstPoint.roll = 0;
    firstPoint.time = 0;
    coordinateList.push_back(firstPoint);
}


// Inserts new point at the end off the list
// Returns false if the point couldn't be added
bool Model::pushNewPoint(double x, double y, double z, double yaw, double pitch, double roll, double time)
{
    // Push point on end
    // Change current point to the last one and then insert
    int saveCurrentPos = currentPoint;
    currentPoint = static_cast<int>(coordinateList.size());
    if(!Model::insertNewPoint(x,y,z,yaw,pitch,roll,time))
    {
        // if adding the point failed...
        currentPoint = saveCurrentPos;
        return false;
    }
    currentPoint = saveCurrentPos + 1;
    return true;
}


// Inserts new point after the current position
// Returns false if the point couldn't be added
bool Model::insertNewPoint(double x, double y, double z, double yaw, double pitch, double roll,double time)
{
    if(!isPointInArea(x,y,z))
    {
        return false;
    }
    coordinate newPoint;
    newPoint.x = x;
    newPoint.y = y;
    newPoint.z = z;
    newPoint.yaw = yaw;
    newPoint.pitch = pitch;
    newPoint.roll = roll;
    newPoint.time = time;
    coordinateList.insert(coordinateList.begin() + currentPoint,newPoint);
    currentPoint += 1;
    return true;
}

void writeData(double x, double y, double z, double yaw, double pitch, double roll,double time)
{
    std::ofstream output_file("./example.txt");


}

// Returns if the point being added is within the bounds of the robot
// TODO:
bool Model::isPointInArea(double x, double y, double z)
{
    return true;
}


// Return how many items there are in the list
int Model::getDataAmount()
{
    return static_cast<int>(coordinateList.size());
}

int Model::getCurrentPoint()
{
    return currentPoint;
}
