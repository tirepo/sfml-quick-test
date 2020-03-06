#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>
#include <string>

struct mainProcess
{
public:
    mainProcess(int x, int y);

    void generateNewTile(const int &posX, const int &posY);
    void getRandom(int &n1, int &n2, int windowSizeX, int windowSizeY);
    bool checkHit(int mPosX, int mPosY, int rPosX, int rPosY);

private:
    sf::RenderWindow window;
    sf::Mouse mouse;
    int score;
    int rand1, rand2;
};