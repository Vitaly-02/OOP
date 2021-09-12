#include <iostream>
#include <SFML/Graphics.hpp>
#include <time.h>

using namespace sf;

int width = 400;
int height = 400;

class Point {
private:
    float x = 0;
    float y = 0;
    int xSpeed = 1;
    int ySpeed = 1;
    int color[3] = {0, 0, 0};

public:
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
        CircleShape shape1(3);
        shape1.setPosition(x, y);
        shape1.setFillColor(Color(color[0], color[1], color[2]));
        window->draw(shape1);
    }

    void forwardMove() {
        if (x >= width - xSpeed || x <= - xSpeed) {
            xSpeed = -xSpeed;
        }
        if (y >= height - ySpeed || y <= - ySpeed) {
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

int main() {
    srand(time(0));
    RenderWindow window(VideoMode(width, height), "okno");
    Point one;
    one.getRandAll();

    Point sto[100];
    for (int i = 0; i < 100; i++) {
        sto[i].getRandAll();
    }

    bool mode = 1;

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
        }
        window.clear();
        if (Keyboard::isKeyPressed(Keyboard::Left)) {
            mode = !mode;
        }
        for (int i = 0; i < 100; i++) {
            if (mode == 1) {
                sto[i].forwardMove();
            }
            else {
                sto[i].randomMove();
            }
            sto[i].drawPoint(&window);
        }
        sleep(seconds(0.05));
        window.display();
    }
    return 0;
}