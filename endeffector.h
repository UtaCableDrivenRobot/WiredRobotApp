#ifndef ENDEFFECTOR_H
#define ENDEFFECTOR_H
#include <glm/vec3.hpp>

class EndEffector
{
public:
    EndEffector();
    glm::vec3 points[8];
    void translatePosition(float xAmount, float yAmount, float zAmount, float yawAngle, float pitchAngle, float rollAngle);
private:
    const float modelOuterWidth=200;
    const float modelOuterHeight=200;
    const float modelOuterDepth=200;
    void initializePoints();
};

#endif // ENDEFFECTOR_H
