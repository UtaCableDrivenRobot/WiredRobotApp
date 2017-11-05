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
    coordinateList.push_back(firstPoint);
}

bool Model::insertNewPoint(double x, double y, double z, double yaw, double pitch, double roll){
    return x;
}

bool Model::isPointInArea(double x, double y, double z){
    return true;
}
