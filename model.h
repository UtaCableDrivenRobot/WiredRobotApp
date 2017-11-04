#ifndef MODEL_H
#define MODEL_H


class Model
{
public:
    Model();
    bool insertNewPoint(double x,double y,double z,double yaw,double pitch,double roll);
    int currentPoint = 0;
};

#endif // MODEL_H
