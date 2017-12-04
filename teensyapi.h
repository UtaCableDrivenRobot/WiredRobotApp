#ifndef TEENSYAPI_H
#define TEENSYAPI_H

#include <vector>
#include <QString>

class TeensyAPI
{
public:
    TeensyAPI();
    void sendTeensyCoordinates(std::vector<std::vector<float>> wireLengthMMList);
    bool foundPort();
private:
    QString portName;
};

#endif // TEENSYAPI_H
