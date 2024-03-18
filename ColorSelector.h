#ifndef COLOR_SELECTOR_H
#define COLOR_SELECTOR_H

#include "Rectangle.h"
#include "Circle.h"
#include <iostream>

struct ColorSelector {
private:
    Rectangle area;
    Rectangle resultColor;
    Rectangle redAxis;
    Rectangle greenAxis;
    Rectangle blueAxis;
    
    Circle redButton;
    Circle greenButton;
    Circle blueButton;

    float redDisplayValue;
    float greenDisplayValue;
    float blueDisplayValue;

    float redValue;
    float blueValue;
    float greenValue;

    Color currentColor;

public:
    ColorSelector(){
        area = Rectangle(-0.8f, -0.4f, 1.8f, 0.6f, Color(0.0f, 0.0f, 0.1f));
        resultColor = Rectangle(-0.7f, -0.45f, 1.6f, 0.1f, currentColor);
        redButton = Circle(-0.7f, -0.65f, 0.04f, Color (1.0f, 0.0f, 0.0f));
        greenButton = Circle(-0.7f, -0.80f, 0.04f, Color (0.0f, 1.0f, 0.0f));
        blueButton = Circle(-0.7f, -0.95f, 0.04f, Color (0.0f, 0.0f, 1.0f));
        redAxis = Rectangle(-0.7f, -0.64f, 1.4f, 0.03f, Color(0.7f, 0.7f, 0.7f));
        greenAxis = Rectangle(-0.7f, -0.79f, 1.4f, 0.03f, Color(0.7f, 0.7f, 0.7f));
        blueAxis = Rectangle(-0.7f, -0.94f, 1.4f, 0.03f, Color(0.7f, 0.7f, 0.7f));
    }

    Color getCurrentColor(){
        return currentColor;
    }
    void setCurrentColor(float r, float g, float b){
        currentColor = Color(r, g, b);
    }

    void handleMouseClick(float x, float y){
        // use the x position to determine an rgb value 0.0 - 1.0
        // total length of axis = 1.4
        // y represents the value multiplied to get the rgb value
        // 1.4y = 1.0 
        // y = 0.714 
        // 0.695 * 0.714 + 0.5
        float length = 1.0 / 1.4;
        if (redButton.contains(x,y) && redAxis.contains(x,y)){
            redButton.setX(x);
            redValue = (x * length) + 0.5;
            std::cout << "red value: " << redValue << std::endl;
            setCurrentColor(redValue,greenValue,blueValue);
            resultColor.setColor(currentColor);
        }

        if (greenButton.contains(x,y) && greenAxis.contains(x,y)){
            greenButton.setX(x);
            greenValue = (x * length) + 0.5;
            setCurrentColor(redValue,greenValue,blueValue);
            resultColor.setColor(currentColor);
        }

        if (blueButton.contains(x,y) && blueAxis.contains(x,y)){
            blueButton.setX(x);
            blueValue = (x * length) + 0.5;
            setCurrentColor(redValue,greenValue,blueValue);
            resultColor.setColor(currentColor);
        }
    }

    void draw(){
        area.draw();
        resultColor.draw();
        redAxis.draw();
        greenAxis.draw();
        blueAxis.draw();
        redButton.draw();
        greenButton.draw();
        blueButton.draw();
    }

    bool contains(float x, float y){
        return area.contains(x, y);
    }
};
#endif