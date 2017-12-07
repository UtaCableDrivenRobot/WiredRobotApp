#ifndef MODEL_H
#define MODEL_H
#include "coordinatestruct.h"
#include <fstream>
#include <iterator>
#include <vector>
#include <QString>
#include "framestruct.h"
#include "endeffector.h"
#include "coordinates.h"
#include <QTime>
class Model
{
public:
    Model();
    const float ROBOT_LENGTH = 1000;
    const float ROBOT_HEIGHT = 1000; // TODO: Measure this out
    const float ROBOT_FRAME_SIZE = 20;
    const float ROBOT_FULL_LENGTH = ROBOT_LENGTH + ROBOT_FRAME_SIZE;
    const float ROBOT_FULL_HEIGHT = ROBOT_LENGTH + 2 * ROBOT_FRAME_SIZE;
    void setCurrentPoint(int index);
    void setEyeRotationX(int x);
    void setEyeRotationY(int y);
    bool pushNewPoint(float x,float y,float z,float yaw,float pitch,float roll,float time);
    bool insertNewPoint(float x, float y, float z, float yaw, float pitch, float roll,float time);
    void writeData(float x, float y, float z, float yaw, float pitch, float roll,float time);
    bool deleteCurrentIdex();
    void emptyWorkingPoints();
    void writeToFile(QString fileName);
    std::vector<frame> getFrame();
    std::vector<std::vector<float>> getAllWireLengths();
    int getSelectedIndex();
    int getDataAmount();
    void updateEndEffector();
    coordinate getSelectedCoordinate();
    EndEffector* getEndEffector();
    std::vector<float> *getEyeRotation();
    std::vector<glm::vec3> *getWireStarts();
    void setPlay();
    void setStop();
private:
    const float ROBOT_AREA_INFILL = 0.37;
    const float ROBOT_X_MIN = (1-ROBOT_AREA_INFILL)/2*ROBOT_FULL_LENGTH;
    const float ROBOT_Y_MIN = (1-ROBOT_AREA_INFILL)/2*ROBOT_FULL_HEIGHT;
    const float ROBOT_Z_MIN = (1-ROBOT_AREA_INFILL)/2*ROBOT_FULL_LENGTH;
    const float ROBOT_X_MAX = ROBOT_FULL_LENGTH - ROBOT_X_MIN;
    const float ROBOT_Y_MAX = ROBOT_FULL_HEIGHT - ROBOT_Y_MIN;
    const float ROBOT_Z_MAX = ROBOT_FULL_LENGTH - ROBOT_Z_MIN;
    // TODO: this needs to be measured
    const float LATERAL_WIRE_OFFSET = 38.0f;
    const float VERTICLE_WIRE_OFFSET = 42.0f;
    const float MAX_ROTATION = 30.1;
    const float END_EFFECTOR = 100;
    bool isPointValid(float x, float y, float z, float yaw, float pitch, float roll);
    std::vector<frame> makeFrame();
    std::vector<glm::vec3> makeWireStarts();
    Coordinates myCoordinates;
    std::vector<frame> robotFrame;
    std::vector<glm::vec3> wireStarts;
    EndEffector myEndEffector;
    int currentPoint = 0;
    enum PlayState{play,stop};
    PlayState playState = stop;
    QTime timer;
    std::vector<float> eyeRotation;
};

#endif // MODEL_H
