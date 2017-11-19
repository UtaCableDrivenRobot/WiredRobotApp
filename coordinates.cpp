#include "coordinates.h"
#include <QDebug>

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
    insertNewCoordinate(x,y,z,yaw,pitch,roll,time,roughCoordinateList.size());
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
    updateFineCoordinateList();
}

void Coordinates::updateFineCoordinateList()
{
    float actualTotalTime = 0;
    float totalTimeElapsedThisFrame=0;
    qDebug() << "inside update fine";
    for(unsigned int i=0;i<roughCoordinateList.size()-1;i++)
    {
        while(totalTimeElapsedThisFrame<roughCoordinateList[i+1].time)
        {
            //Find the weights that each frame should receive
            float firstItemWeight = (roughCoordinateList[i+1].time-totalTimeElapsedThisFrame)/roughCoordinateList[i+1].time;
            float secondItemWeight = 1.0f-firstItemWeight;

            float xAmount = roughCoordinateList[i].x*firstItemWeight + roughCoordinateList[i+1].x*secondItemWeight;
            float yAmount = roughCoordinateList[i].y*firstItemWeight + roughCoordinateList[i+1].y*secondItemWeight;
            float zAmount = roughCoordinateList[i].z*firstItemWeight + roughCoordinateList[i+1].z*secondItemWeight;
            float yawAngle = roughCoordinateList[i].yaw*firstItemWeight + roughCoordinateList[i+1].yaw*secondItemWeight;
            float pitchAngle = roughCoordinateList[i].pitch*firstItemWeight + roughCoordinateList[i+1].pitch*secondItemWeight;
            float rollAngle = roughCoordinateList[i].roll*firstItemWeight + roughCoordinateList[i+1].roll*secondItemWeight;
            coordinate newPoint;
            newPoint.x = xAmount;
            newPoint.y = yAmount;
            newPoint.z = zAmount;
            newPoint.yaw = yawAngle;
            newPoint.pitch = pitchAngle;
            newPoint.roll = rollAngle;
            newPoint.time = actualTotalTime;
            fineCoordinateList.push_back(newPoint);
            qDebug() << fineCoordinateList[fineCoordinateList.size()-1].time;
            totalTimeElapsedThisFrame+=FRAME_FREQ;
            actualTotalTime+=FRAME_FREQ;
        }
        totalTimeElapsedThisFrame-=roughCoordinateList[i+1].time;
    }
}

void Coordinates::deleteIndex(int i)
{
    roughCoordinateList.erase(roughCoordinateList.begin() + i);
}

coordinate Coordinates::getCoordinateAtPosition(int i)
{
    return roughCoordinateList[i];
}

coordinate Coordinates::getFineCoordinate(float time)
{
    qDebug() << time;
    for(coordinate item: fineCoordinateList)
    {
        if(item.time>time)
        {
            return item;
        }
    }
    return fineCoordinateList[fineCoordinateList.size()-1];
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
