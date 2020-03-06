#include "main.hpp"

mainProcess::mainProcess(int x, int y)
{
    sf::RenderWindow window(sf::VideoMode(x, y), "lmao it compiled", sf::Style::Titlebar | sf::Style::Close);
    sf::RectangleShape rectangle(sf::Vector2f(100, 100));

    sf::Font font;
    font.loadFromFile("font.ttf");

    sf::Text text(std::to_string(score), font);
    text.setPosition(25, y - 50);
    text.setCharacterSize(30);
    text.setStyle(sf::Text::Bold);
    text.setFillColor(sf::Color::White);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::MouseButtonPressed)
            {
                auto rectanglePos = rectangle.getPosition();
                auto mousePos = mouse.getPosition(window);

                if (checkHit(mousePos.x, mousePos.y, rectanglePos.x, rectanglePos.y))
                {
                    score++;
                    text.setFillColor(sf::Color::White);
                    text.setString(std::to_string(score));
                }
                else
                {
                    score--;
                    text.setFillColor(sf::Color::Red);
                    text.setString(std::to_string(score) + ' ' + "MISS");
                }               

                getRandom(rand1, rand2, x, y);
                rectangle.setPosition(sf::Vector2f(rand1, rand2));
            }

            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        window.clear();
        window.draw(rectangle);
        window.draw(text);
        window.display();
    }
}

void mainProcess::getRandom(int &n1, int &n2, int windowSizeX, int windowSizeY)
{
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);

    srand((time_t)ts.tv_nsec);
    n1 = rand() % (windowSizeX - 100);
    n2 = rand() % (windowSizeY - 100);
}

bool mainProcess::checkHit(int mPosX, int mPosY, int rPosX, int rPosY)
{
    return ((mPosX > rPosX && mPosX < rPosX + 100) && (mPosY > rPosY && mPosY < rPosY + 100));
}

int main()
{
    mainProcess window(1920, 1080);
    return 0;
}
