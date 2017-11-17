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
    const float modelOuterWidth=100;
    const float modelOuterHeight=100;
    const float modelOuterDepth=100;
    void initializePoints();
};

#endif // ENDEFFECTOR_H
