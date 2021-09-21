#include <iostream>
#include <SFML/Graphics.hpp>
#include <time.h>

using namespace sf;

int width = 600;
int height = 600;

class Polygon {
protected:
    float x;
    float y;
    int xSpeed;
    int ySpeed;
    int color[3];
    int radius;
    int angles;
    int rotate;

public:
    //конструктор по умолчанию
    Polygon() {
        x = 0;
        y = 0;
        xSpeed = 1;
        ySpeed = 1;
        color[0] = color[1] = color[2] = 0;
        radius = 3;
        angles = 30;
        rotate = 0;
    };
    //конструктор с несколькими параметрами
    Polygon(int a, int b, int c, int d) {
        x = a;
        y = b;
        xSpeed = c;
        ySpeed = d;
        color[0] = color[1] = color[2] = 0;
        radius = 3;
        angles = 30;
        rotate = 0;
    }
    /*virtual*/ void drawPolygon(RenderWindow* window) {
        CircleShape polygon(radius, angles);
        polygon.setPosition(x, y);
        polygon.setOrigin(radius, radius);
        polygon.rotate(rotate);
        polygon.setOutlineThickness(3);
        polygon.setOutlineColor(Color(color[0], color[1], color[2]));
        polygon.setFillColor(Color(0, 0, 0, 0));
        // последний 0 == прозрачность
        window->draw(polygon);
    }
    /*virtual*/ void forwardMove() {
        rotate = 0;
        if (x >= width - xSpeed - radius || x <= -xSpeed + radius) {
            xSpeed = -xSpeed;
        }
        if (y >= height - ySpeed - radius || y <= -ySpeed + radius) {
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
    
    void rotateMove() {
        rotate++;
    }
};

class Triangle : public Polygon {
public:
    //конструктор по умолчанию
    Triangle() {
        radius = rand() % 30 + 5;
        while ((x <= radius * 2) || (x >= width - radius * 2)) {
            x = rand() % width;
        }
        while ((y <= radius * 2) || (y >= height - radius * 2)) {
            y = rand() % height;
        }
        xSpeed = rand() % 3 + 1;
        ySpeed = rand() % 3 + 1;
        for (int i = 0; i < 3; i++) {
            color[i] = rand() % 255;
        }
        angles = 3;
        rotate = 0;
    };
};

class Circle : public Polygon {
public:
    //конструктор по умолчанию
    Circle() {
        radius = rand() % 30 + 5;
        while ((x <= radius * 2) || (x >= width - radius * 2)) {
            x = rand() % width;
        }
        while ((y <= radius * 2) || (y >= height - radius * 2)) {
            y = rand() % height;
        }
        xSpeed = rand() % 3 + 1;
        ySpeed = rand() % 3 + 1;
        for (int i = 0; i < 3; i++) {
            color[i] = rand() % 255;
        }
        angles = 30;
        rotate = 0;
    };
};

class Point : public Circle {
public:
    //конструктор по умолчанию
    Point() {
        radius = 3;
        while ((x <= radius * 2) || (x >= width - radius * 2)) {
            x = rand() % width;
        }
        while ((y <= radius * 2) || (y >= height - radius * 2)) {
            y = rand() % height;
        }
        xSpeed = rand() % 3 + 1;
        ySpeed = rand() % 3 + 1;
        for (int i = 0; i < 3; i++) {
            color[i] = rand() % 255;
        }
        angles = 30;
        rotate = 0;
    };
    /*virtual*/ void drawPolygon(RenderWindow* window) {
        CircleShape polygon(radius, angles);
        polygon.setPosition(x, y);
        polygon.setFillColor(Color(color[0], color[1], color[2]));
        window->draw(polygon);
    }
};
// ромб
class Rhombus : public Polygon {
public:
    //конструктор по умолчанию
    Rhombus() {
        radius = rand() % 30 + 5;
        while ((x <= radius * 2) || (x >= width - radius * 2)) {
            x = rand() % width;
        }
        while ((y <= radius * 2) || (y >= height - radius * 2)) {
            y = rand() % height;
        }
        xSpeed = rand() % 3 + 1;
        ySpeed = rand() % 3 + 1;
        for (int i = 0; i < 3; i++) {
            color[i] = rand() % 255;
        }
        angles = 4;
        rotate = 0;
    };

};
// прямоугольник
class Rectangle : public Polygon {
protected:
    int ox;
    int oy;
public:
    //конструктор по умолчанию
    Rectangle() {
        ox = rand() % 30 + 5;
        oy = rand() % 30 + 5;
        while ((x <= ox * 2) || (x >= width - ox * 2)) {
            x = rand() % width;
        }
        while ((y <= oy * 2) || (y >= height - oy * 2)) {
            y = rand() % height;
        }
        xSpeed = rand() % 3 + 1;
        ySpeed = rand() % 3 + 1;
        for (int i = 0; i < 3; i++) {
            color[i] = rand() % 255;
        }
        angles = 4;
        rotate = 0;
    };
    /*virtual*/ void drawPolygon(RenderWindow* window) {
        RectangleShape polygon(Vector2f(ox, oy));
        polygon.setPosition(x, y);
        polygon.setOrigin(ox / 2, oy / 2);
        polygon.rotate(rotate);
        polygon.setOutlineThickness(3);
        polygon.setOutlineColor(Color(color[0], color[1], color[2]));
        polygon.setFillColor(Color(0, 0, 0, 0));
        // последний 0 == прозрачность
        window->draw(polygon);
    }
    /*virtual*/ void forwardMove() {
        rotate = 0;
        if (x >= width - xSpeed - ox/2 || x <= -xSpeed + ox/2) {
            xSpeed = -xSpeed;
        }
        if (y >= height - ySpeed - oy/2 || y <= -ySpeed + oy/2) {
            ySpeed = -ySpeed;
        }
        x += xSpeed;
        y += ySpeed;
    }

};

class Line : public Rectangle {
public:
    //конструктор по умолчанию
    Line() {
        ox = rand() % 30 + 5;
        oy = 3;
        while ((x <= ox * 2) || (x >= width - ox * 2)) {
            x = rand() % width;
        }
        while ((y <= oy * 2) || (y >= height - oy * 2)) {
            y = rand() % height;
        }
        xSpeed = rand() % 3 + 1;
        ySpeed = rand() % 3 + 1;
        for (int i = 0; i < 3; i++) {
            color[i] = rand() % 255;
        }
        angles = 4;
        rotate = 0;
    };
    /*virtual*/ void drawPolygon(RenderWindow* window) {
        RectangleShape polygon(Vector2f(ox, oy));
        polygon.setPosition(x, y);
        polygon.setOrigin(ox / 2, oy / 2);
        polygon.setFillColor(Color(color[0], color[1], color[2]));
        polygon.rotate(rotate);
        window->draw(polygon);
    }
};

class Ellipse : public Rectangle {
public:
    //конструктор по умолчанию
    Ellipse() {
        radius = rand() % 30 + 5;
        ox = 4 * radius;
        oy = 2 * radius;
        while ((x <= ox * 2) || (x >= width - ox * 2)) {
            x = rand() % width;
        }
        while ((y <= oy * 2) || (y >= height - oy * 2)) {
            y = rand() % height;
        }
        xSpeed = rand() % 3 + 1;
        ySpeed = rand() % 3 + 1;
        for (int i = 0; i < 3; i++) {
            color[i] = rand() % 255;
        }
        angles = 30;
        rotate = 0;
    };
    /*virtual*/ void drawPolygon(RenderWindow* window) {
        CircleShape polygon(radius, angles);
        polygon.setPosition(x, y);
        polygon.setOrigin(radius, radius);
        polygon.rotate(rotate);
        polygon.setOutlineThickness(3);
        polygon.setOutlineColor(Color(color[0], color[1], color[2]));
        polygon.setFillColor(Color(0, 0, 0, 0));
        // последний 0 == прозрачность
        polygon.setScale(2, 1);
        window->draw(polygon);
    }
};

int main() {
    srand(time(0));
    RenderWindow window(VideoMode(width, height), "okno");

    Point sto[10]; 
    bool mode = 1;
    
    //Polygon arr[2];
    //arr[0] = Circle();
    //arr[1] = Rectangle();

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
            if (event.type == Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Enter) {
                    mode = !mode;
                }
            }
        }
        window.clear();
        for (int i = 0; i < 10; i++) {
            if (mode == 1) {
            sto[i].forwardMove();
            sto[i].drawPolygon(&window);
            //
            //arr[i].forwardMove();
            //arr[i].drawPolygon(&window);
            }
            else {
                sto[i].rotateMove();
                //arr[i].rotateMove();
            }
            sto[i].drawPolygon(&window);
            //arr[i].drawPolygon(&window);
        }
        sleep(seconds(0.05));
        window.display();
    }
    return 0;
}