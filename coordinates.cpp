#include "coordinates.h"

Coordinates::Coordinates()
{
    coordinate firstPoint;
    firstPoint.x = 0;
    firstPoint.y = 0;
    firstPoint.z = 0;
    firstPoint.yaw = 0;
    firstPoint.pitch = 0;
    firstPoint.roll = 0;
    firstPoint.time = 0;
    roughCoordinateList.push_back(firstPoint);
}

Coordinates::Coordinates(float xmin,float ymin, float zmin)
{
    coordinate firstPoint;
    firstPoint.x = xmin;
    firstPoint.y = ymin;
    firstPoint.z = zmin;
    firstPoint.yaw = 0;
    firstPoint.pitch = 0;
    firstPoint.roll = 0;
    firstPoint.time = 0;
    roughCoordinateList.push_back(firstPoint);
}

void Coordinates::pushNewCoordinate(float x, float y, float z, float yaw, float pitch, float roll, float time)
{
    coordinate newPoint;
    newPoint.x = x;
    newPoint.y = y;
    newPoint.z = z;
    newPoint.yaw = yaw;
    newPoint.pitch = pitch;
    newPoint.roll = roll;
    newPoint.time = time;
    roughCoordinateList.push_back(newPoint);
}

void Coordinates::insertNewCoordinate(float x, float y, float z, float yaw, float pitch, float roll, float time,int position)
{
    coordinate newPoint;
    newPoint.x = x;
    newPoint.y = y;
    newPoint.z = z;
    newPoint.yaw = yaw;
    newPoint.pitch = pitch;
    newPoint.roll = roll;
    newPoint.time = time;
    roughCoordinateList.insert(roughCoordinateList.begin()+position,newPoint);
}

void Coordinates::deleteIndex(int i)
{
    roughCoordinateList.erase(roughCoordinateList.begin() + i);
}

coordinate Coordinates::getCoordinateAtPosition(int i)
{
    return roughCoordinateList[i];
}

int Coordinates::getListSize()
{
    return static_cast<int>(roughCoordinateList.size());
}

void Coordinates::clearAllPoints()
{
    roughCoordinateList.erase(roughCoordinateList.begin()+1,roughCoordinateList.end());
}

std::vector<coordinate> Coordinates::getFullRoughCoordinates()
{
    return roughCoordinateList;
}
