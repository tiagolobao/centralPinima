#!/bin/bash

cd motor
g++ motor.cpp -c
mv motor.o ../
cd ../

cd ultrassom
g++ ultrassom.cpp -c
mv ultrassom.o ../
cd ../

make
