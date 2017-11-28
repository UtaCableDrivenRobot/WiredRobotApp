#ifndef ENDEFFECTOR_H
#define ENDEFFECTOR_H
#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>

class EndEffector
{
public:
    EndEffector();
    glm::vec3 points[8];
    void translatePosition(float xAmount, float yAmount, float zAmount, float yawAngle, float pitchAngle, float rollAngle);
private:
    const float modelOuterWidth=92;
    const float modelOuterHeight=92;
    const float modelOuterDepth=92;
    void initializePoints();
};

#endif // ENDEFFECTOR_H
