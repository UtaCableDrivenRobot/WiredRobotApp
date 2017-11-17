#include "endeffector.h"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
EndEffector::EndEffector()
{
    initializePoints();
}


//Boxes have 8 points
//      6-------7
//    / |      /|
//   /  |     / |
//  2___|____3  |
//  |   |    |  |
//  |   |    |  |
//  |   | ___|_8
//  | /5     |
//  1________4/
//
void EndEffector::initializePoints(){
    points[0] = glm::vec3(-1*modelOuterDepth/2,-1*modelOuterHeight/2,-1*modelOuterWidth/2);
    points[1] = glm::vec3(-1*modelOuterDepth/2,modelOuterHeight/2,-1*modelOuterWidth/2);
    points[2] = glm::vec3(modelOuterDepth/2,modelOuterHeight/2,-1*modelOuterWidth/2);
    points[3] = glm::vec3(modelOuterDepth/2,-1*modelOuterHeight/2,-1*modelOuterWidth/2);
    points[4] = glm::vec3(-1*modelOuterDepth/2,-1*modelOuterHeight/2,modelOuterWidth/2);
    points[5] = glm::vec3(-1*modelOuterDepth/2,modelOuterHeight/2,modelOuterWidth/2);
    points[6] = glm::vec3(modelOuterDepth/2,modelOuterHeight/2,modelOuterWidth/2);
    points[7] = glm::vec3(modelOuterDepth/2,-1*modelOuterHeight/2,modelOuterWidth/2);
}

void EndEffector::translatePosition(float xAmount, float yAmount, float zAmount, float yawAngle, float pitchAngle, float rollAngle){
    initializePoints();
    //rotations have to happen first
    //fuuuu https://math.stackexchange.com/questions/89621/how-to-multiply-vector-3-with-4by4-matrix-more-precisely-position-transformat
    glm::vec3 rollVector(1,0,0);
    glm::vec4 pitchVector4(0,1,0,1);
    glm::vec4 yawVector4(0,0,1,1);
    glm::vec3 translateVector(xAmount,yAmount,zAmount);


    // do roll -> pitch -> yaw
    // https://puu.sh/ynB1D/e552da43e3.png
    // Model = glm::rotate(Model, angle_in_degrees, glm::vec3(x, y, z)); // where x, y, z is axis of rotation (e.g. 0 1 0)
    glm::mat4 rollMatrix;
    rollMatrix = glm::rotate(rollMatrix,rollAngle,rollVector);


    pitchVector4 =rollMatrix * pitchVector4;
    glm::vec3 pitchVector3(pitchVector4[0],pitchVector4[1],pitchVector4[2]);
    yawVector4 =rollMatrix * yawVector4;
    glm::mat4 pitchMatrix;
    pitchMatrix = glm::rotate(pitchMatrix,pitchAngle,pitchVector3);

    yawVector4 = pitchMatrix *  yawVector4;
    glm::mat4 yawMatrix;
    glm::vec3 yawVector3(yawVector4[0],yawVector4[1],yawVector4[2]);

    yawMatrix = glm::rotate(yawMatrix,yawAngle,yawVector3);

    glm::mat4 fullRotate = yawMatrix * pitchMatrix * rollMatrix;
    glm::mat4 translateMatrix;
    glm::translate(translateMatrix,translateVector);

    glm::mat4 fullChange = translateMatrix * fullRotate;

    for(unsigned int i = 0; i < sizeof(points)/sizeof(points[0]); i = i + 1)
    {
        glm::vec4 currPoint(points[i][0],points[i][1],points[i][2],0);
        points[i] =fullChange *  currPoint;
    }
}
