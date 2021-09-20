#include <iostream>
#include <SFML/Graphics.hpp>
#include <time.h>

using namespace sf;

int width = 600;
int height = 600;

class Point {
protected:
    float x;
    float y;
    int xSpeed;
    int ySpeed;
    int color[3];
    int radius;

public:
    //конструктор по умолчанию
    Point() {
        x = 0;
        y = 0;
        xSpeed = 1;
        ySpeed = 1;
        color[0] = color[1] = color[2] = 0;
        radius = 3;
    };

    void getRandAll() {
        x = rand() % width;
        y = rand() % height;
        for (int i = 0; i < 3; i++) {
            color[i] = rand() % 255;
        }
        xSpeed = rand() % 10;
        ySpeed = rand() % 10;
    }

    void drawPoint(RenderWindow* window) {
        CircleShape shape1(radius);
        shape1.setPosition(x, y);
        shape1.setFillColor(Color(color[0], color[1], color[2]));
        window->draw(shape1);
    }
    /* старое движение для точек
    void forwardMove() {
        if (x >= width - xSpeed - radius || x <= -xSpeed) {
            xSpeed = -xSpeed;
        }
        if (y >= height - ySpeed - radius || y <= -ySpeed) {
            ySpeed = -ySpeed;
        }
        x += xSpeed;
        y += ySpeed;
    }*/
    void forwardMove() {
        if (x >= width - xSpeed - radius * 2 || x <= -xSpeed) {
            xSpeed = -xSpeed;
        }
        if (y >= height - ySpeed - radius * 2 || y <= -ySpeed) {
            ySpeed = -ySpeed;
        }
        x += xSpeed;
        y += ySpeed;
    }

    void randomMove() {
        if (x >= width - xSpeed || x <= -xSpeed) {
            xSpeed = -xSpeed;
        }
        if (y >= height - ySpeed || y <= -ySpeed) {
            ySpeed = -ySpeed;
        }
        x += xSpeed;
        y += ySpeed;
        int s;
        s = rand() % 50;
        // чем меньше, тем чаще меняется направление
        // и почему-то все скапливаются в углу
        switch (s) {
        case 0: {
            xSpeed = rand() % 10;
            ySpeed = rand() % 10;
            break;
        }
        case 1: {
            xSpeed = rand() % 10;
            break;
        }
        case 2: {
            ySpeed = rand() % 10;
            break;
        }
        case 3: {
            xSpeed = -xSpeed;
            break;
        }
        case 4: {
            ySpeed = -ySpeed;
            break;
        }
        case 5: {
            xSpeed = -xSpeed;
            ySpeed = -ySpeed;
            break;
        }
        default: {
            break;
        }
        }
    }
};

class Circle : public Point {
/*private:
    float x;
    float y;
    int xSpeed;
    int ySpeed;
    int color[3];
    int radius;
*/
public:
    
    void getRandAll() {
        radius = rand() % 30 + 5;
        while ((x <= radius * 2) || (x >= width - radius * 2)) {
            x = rand() % width;
        }
        while ((y <= radius * 2) || (y >= height - radius * 2)) {
            y = rand() % height;
        }
        for (int i = 0; i < 3; i++) {
            color[i] = rand() % 255;
        }
        xSpeed = rand() % 3 + 1;
        ySpeed = rand() % 3 + 1;

    }
    void drawCircle(RenderWindow* window) {

        CircleShape shape(radius);
        shape.setPosition(x, y);
        shape.setOutlineThickness(3);
        shape.setOutlineColor(Color(color[0], color[1], color[2]));
        shape.setFillColor(Color(0, 0, 0, 0));
        // последний 0 == прозрачность
        window->draw(shape);
    }/*
    void forwardMove() {
        if (x >= width - xSpeed - radius * 2 || x <= -xSpeed) {
            xSpeed = -xSpeed;
        }
        if (y >= height - ySpeed - radius * 2 || y <= -ySpeed) {
            ySpeed = -ySpeed;
        }
        x += xSpeed;
        y += ySpeed;
    }*/
};

class Triangle : public Circle {
private:
    int angles = 3;
public:
    void drawCircle(RenderWindow* window) {

        CircleShape shape(radius, angles);
        shape.setPosition(x, y);
        shape.setOutlineThickness(3);
        shape.setOutlineColor(Color(color[0], color[1], color[2]));
        shape.setFillColor(Color(0, 0, 0, 0));
        // последний 0 == прозрачность
        window->draw(shape);
    }

};

int main() {
    srand(time(0));
    RenderWindow window(VideoMode(width, height), "okno");
    //Point one;
    //one.getRandAll();

    Triangle sto[10];
    for (int i = 0; i < 10; i++) {
        //sto[i];
        sto[i].getRandAll();

    }

    //bool mode = 1;

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
        }
        window.clear();
        //if (Keyboard::isKeyPressed(Keyboard::Left)) {
        //    mode = !mode;
        //}
        for (int i = 0; i < 10; i++) {
            //if (mode == 1) {
            sto[i].forwardMove();
            //}
            //else {
            //    sto[i].randomMove();
            //}
            sto[i].drawCircle(&window);
        }
        sleep(seconds(0.05));
        window.display();
    }
    return 0;
}