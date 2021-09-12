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
        shape1.setFillColor(sf::Color(color[0], color[1], color[2]));
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
};



int main() {
    srand(time(0));
    sf::RenderWindow window(sf::VideoMode(width, height), "jopa");
    //sf::CircleShape shape1(3);
    //shape1.setPosition(100, 100);
    //shape1.setFillColor(sf::Color(255, 10, 10));
    Point one;
    //one.drawPoint(&window);
    one.getRandAll();


    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        one.forwardMove();
        one.drawPoint(&window);
        sleep(seconds(0.05));
        window.display();
    }


    //sleep(seconds(5));
    return 0;
}