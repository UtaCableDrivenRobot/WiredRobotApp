#ifndef TEENSYAPI_H
#define TEENSYAPI_H

#include <vector>

class TeensyAPI
{
public:
    TeensyAPI();
    void sendTeensyCoordinates(std::vector<std::vector<float>> wireLengthMMList);
};

#endif // TEENSYAPI_H
