#ifndef FRAMESTRUCT_H
#define FRAMESTRUCT_H

#include <glm/vec3.hpp>
struct frame
{
    glm::vec3 point1;
    glm::vec3 point2;
    frame(glm::vec3 p1, glm::vec3 p2): point1(p1), point2(p2){}
};

#endif // FRAMESTRUCT_H
