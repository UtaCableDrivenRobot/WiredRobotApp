# Wired Robot App


## What This Is
This project contains the source code and files to run the cable driven robot devloped at UTA for the senior design class of fall 2017. This documentation is to help give an overview of what this project does, and how to run/continue development on this project.

![Robot Image](https://i.imgur.com/ZSl4uDV.jpg)

## Tools Used
* GUI was built with [QT Community Open Source](https://www1.qt.io/download-open-source/?hsCtaTracking=f977210e-de67-475f-a32b-65cec207fd03%7Cd62710cd-e1db-46aa-8d4d-2f1c1ffdacea)
* Math Calculation built with [OpenGL Mathematics Library](https://glm.g-truc.net/0.9.8/index.html)
* Video Interface Built with [OpenGL](https://www.opengl.org/)
* Microcontroller Build with [Arduino IDE](https://www.arduino.cc/en/Main/Software) using [Teensyduino](https://www.pjrc.com/teensy/teensyduino.html)



## How to run the robot.
### Setup
Place the calibrator tool in the back left corner of the work area. Set the end effector on top of the pedistal and turn the motors so that each of the wires is fairly taught. Switch the robot's power to on, this will lock the motors into position. Plug in your computer to the USB slot and start the GUI executable. It will auto detect the robot. Enter the file toolbar and click 'Calibrate Form'. This window will let you calibrate the robot and tighten each of the wires. Tighten each wire until it is just before bending the plastic on the corner pieces.
### Running a Path
To run a path enter positions into each of the text fields. The positions entered are floats. The max range for the XYZ positions is currently is around 210-810. Positions past these points have not been tested. **YAW PITCH AND ROLL IS NOT IMPLMENTED IN THIS VERSION.** For these feilds Enter 0. Time should also be entered. The robot can move very quickly and accurately. Times less than 1 second between position is possible, but be warned exceeding speeds can cause the wires to break. This will not damage the robot, but will require you to preform maintainence to re-setup. **For the last step make sure the robot moves back to its original position.** The robot does not keep track of its position once it moves, so make sure it moves back to its starting location if you plan on doing more than one path. Also over time the robot will become slightly uncalibrated. Once all of your points are put in, click file and click export to teensy. This will send the robot all of the information needed, and execute the path.

After running 30-40 paths you may need to recalibrate the endeffector.

The GUI includes loading and saving features, so some paths have already been included in the git project. These paths can be found [here](https://github.com/SeniorDesignTeamE/WiredRobotApp/tree/master/paths). CSV files can also be imported, and some example are also in the path directory.

### Maintenance
The wires used on the robot are plastic and will eventually wear down and break. To fix re attach the wires simply turn off the robot and pull the wires through the robot and tie them back to the end effector. We have tested braided and plastic fishing wire. The braided wire becomes frayed quickly and breaks fast. We **highly** recomend the plastic fishing wire. The weight as of this projects completion is 40lb test.

## Compiling Software
There are three main tools you must download with the source code in order to complile GUI exe and flash the teensy. QT Community 4.4 was used to develop the GUI. The project can be loaded via the .pro file included in this git project. The teensy is flashed using the arduino IDE with the teensyduino extension. Links to these tools is listed under the 'Tools Used' category of this readme.
