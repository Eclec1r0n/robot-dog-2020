# Capstone Project: Robot Dog  

Worked on the Electrical and Mechanical Design of a quadruped robot.  
Programmed the Arduino to test the working of gait in open loop configurations.

# Demo Video
## [YouTube Video](https://www.youtube.com/watch?v=NX_BM-pFnvo&ab_channel=ChetasPattir)  

## Block Diagram
![Block Diagram](https://github.com/Eclec1r0n/robot-dog-2020/blob/main/Images/Block-Diagram.png)  

## Circuit Diagram
![Circuit Diagram](https://github.com/Eclec1r0n/robot-dog-2020/blob/main/Images/Circuit.png)

## Robot Dog
![Robot Dog Diagram](https://github.com/Eclec1r0n/robot-dog-2020/blob/main/Images/Robot-Dog.png)

# Detailed Report
## Introduction
---
The project involves developing a working prototype of a small-scale version of a four legged robot taking inspiration from a real biological dog.  
The motive is to make a working mechanical model flexible enough to be experimented with different combinations of algorithms and sensors to record the results and make notes for possible future improvements.
## SCOPE of the Project
---
The primary goal for this project is to prototype a mechanism capable of exhibiting a simple gait in an open loop configuration.
## Technical Overview
---
The project consists of three sections, Mechanical, Electrical, and Software.
### Mechanical:
This part comprises the Body and the Mechanism of the Robot dog. The complete body of the robot was built by using 6mm Acrylic sheets cut into different rectangular shapes and then joined together.  
The mechanism was developed by taking notes from the biological design of an actual dog. Each of the legs consists of two joints. The upper joint is driven by two servo motors and hence has two axes of freedom. The bottom joint consists of a single servo motor and thus has a single axis of freedom. Thus, in total, 12 servo motors have been used to drive this robot.
### Electrical:
The Electrical part consists of servo motors, driving circuits, and Arduino as the microcontroller.  
The Arduino UNO passes on several instructions to the 12 servo motors to perform a physical motion. The driver circuit consists of an I2C based PWM Driver module that acts as a bridge between Servo motors and the Arduino communication and decodes the Arduino serial data instructions into appropriate PWM signals.
### Software:
The software consists of the Arduino code that programmed with different functions to instruct the robot on how it is supposed to move its joint. The current progress contains two different kinds of GAITs programmed into the microcontroller.
- Crawling mode: Increases the stability and balance of the robot.
- Walk mode: This mode represents the usual walking style. It is faster than crawl mode but has lesser stability.  

Together, all these parts form a system that interacts with each other to make the robot perform various walking patterns.

## Conclusion & Future Work
---
With the current progress and results obtained, the project has completed the first two stages. Stage 3 is the future scope for the project. A Closed-loop system consisting of Ultrasonic Sensors, a Gyro, an OLED display, a Camera, and force sensors will be implemented in this 3rd stage. Moreover, the robot will be induced with a certain level of dog-like consciousness such that it will be able to understand and replicate emotions.
