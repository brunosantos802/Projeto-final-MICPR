# Projeto Final MICPR — Open-Loop DC Motor Speed Control

Final project for the Microprocessadores course at ULO.

## Introduction

We were asked to build an open-loop speed controller for a DC motor using a PIC18F46K22 microcontroller. The system is developed with the MPLAB extension for VS Code and simulated in Proteus VSM.

The motor speed is set either with a potentiometer or with two push buttons (increase/decrease). The microcontroller turns this setpoint into a PWM signal that drives the motor through a power stage. An encoder on the motor shaft measures the actual speed. That speed and the applied duty cycle are shown in real time on a TFT display.

A serial interface lets the user monitor and configure the system. From it the user can choose the active input, set the button step size, limit the maximum speed, and turn the motor off. As an optional extra, the system can keep a log of its operation in an external EEPROM.
