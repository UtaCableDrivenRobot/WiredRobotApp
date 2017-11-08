#ifndef MODEL_H
#define MODEL_H
#include "coordinatestruct.h"
#include <vector>


class Model
{
public:
    Model();
    bool pushNewPoint(double x,double y,double z,double yaw,double pitch,double roll,double time);
    bool insertNewPoint(double x, double y, double z, double yaw, double pitch, double roll,double time);
    int getCurrentPoint();
    int getDataAmount();

private:
    bool isPointInArea(double x,double y,double z);
    std::vector<coordinate> coordinateList;
    int currentPoint = 0;
    const double ROBOT_WIDTH = 2000;
    const double ROBOT_DEPTH = 2000;
    const double ROBOT_HEIGHT = 2100; // TODO: Measure this out
    const double ROBOT_AREA_INFILL = 0.8;
    const double ROBOT_X_MIN = (1-ROBOT_AREA_INFILL)/2*ROBOT_WIDTH;
    const double ROBOT_Y_MIN = (1-ROBOT_AREA_INFILL)/2*ROBOT_HEIGHT;
    const double ROBOT_Z_MIN = (1-ROBOT_AREA_INFILL)/2*ROBOT_DEPTH;
    const double ROBOT_X_MAX = ROBOT_WIDTH - ROBOT_X_MIN;
    const double ROBOT_Y_MAX = ROBOT_HEIGHT - ROBOT_Y_MIN;
    const double ROBOT_Z_MAX = ROBOT_DEPTH - ROBOT_Z_MIN;

};

#endif // MODEL_H
