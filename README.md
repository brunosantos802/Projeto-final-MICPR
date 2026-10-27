# Projeto Final MICPR — Open-Loop DC Motor Speed Control

Final project for the Microprocessadores course at ULO.

## Introduction

We were tasked with building an open-loop speed controller for a DC motor using a PIC18F46K22 microcontroller. The system is developed with the MPLAB extension for VS Code and simulated in Proteus VSM.

The motor speed is set either with a potentiometer or with two push buttons (increase/decrease). The microcontroller turns this setpoint into a PWM signal that drives the motor through a power stage. An encoder on the motor shaft measures the actual speed. That speed and the applied duty cycle are shown in real time on a TFT display.

A serial interface lets the user monitor and configure the system. From it the user can choose the active input, set the button step size, limit the maximum speed, and turn the motor off. As an optional extra, the system can keep a log of its operation in an external EEPROM.

## Research

### Driving the motor: low-side switching

The PIC can't power the motor directly, so the motor is switched by an N-channel MOSFET placed on the low side, between the motor and ground. The motor's other terminal goes straight to the supply, and the PWM from CCP1 (RC2) drives the MOSFET's gate. When the gate is high, the MOSFET conducts and current flows through the motor. When it is low, the path to ground opens and the motor stops. The PWM duty cycle therefore sets the motor's average voltage, and with it the speed.

We chose low-side switching because the MOSFET's source sits at ground, so the gate voltage is measured from ground too. That means the PIC's own output can drive it directly. A high-side switch would need the gate pulled above the motor supply, which requires extra driver circuitry.


Source: [Elektor — High-side vs. low-side switching](https://www.elektormagazine.com/articles/high-side-low-side-switching)
