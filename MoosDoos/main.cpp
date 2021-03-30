#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <vector>
#include "Ball.hpp"


const int areaWidth = 45;
const int areaHeight = 16;

void ClearScreen()
{
    std::cout << std::string( 15, '\n' );
}

void Collsion(std::vector<Ball>& ballsArr)
{
    for(int x=0; x<ballsArr.size();++x)
    {
        for(int y=x+1; y<ballsArr.size();++y)
        {
            //compare ballsArr[x] ballsArr[y]
            if( static_cast<int>(ballsArr[x].GetPosition().first) == static_cast<int>(ballsArr[y].GetPosition().first)
               and static_cast<int>(ballsArr[x].GetPosition().second) == static_cast<int>(ballsArr[y].GetPosition().second))
            {
                Ball temp = ballsArr[x];
                ballsArr[x].Collide(ballsArr[y]);
                ballsArr[y].Collide(temp);
            }
        }
    }
}

void Draw(const std::vector<Ball>& ballsArr)
{
    std::string text = "";
    bool occupied = false;
    
    for(int tellery = 0; tellery< areaHeight+1; ++tellery)
    {
        for(int tellerx = 0; tellerx< areaWidth+1; ++tellerx)
        {
            for(auto balleke : ballsArr)
            {
                int xpos = static_cast<int>(balleke.GetPosition().first);
                int ypos = static_cast<int>(balleke.GetPosition().second);
                if(tellerx == xpos and tellery == ypos)
                    occupied = true;
            }
            if(occupied)
                text += "o";
            else
                text += " ";
            occupied = false; //reset
        }
        text += "\n";
    }
    text += "\n";
    ClearScreen();
    std::cout << text;
}

int main(int argc, const char * argv[]) {
    Ball ball1(areaWidth,areaHeight,1,-1,10,1);
    Ball ball2(areaWidth,areaHeight,0,-1, 2 );
    std::vector<Ball> balls {ball1, ball2};
    for(int teller = 0; teller <2000; teller++)
    {
        for(auto& balleke : balls)
        {
            balleke.Step();
        }
        Collsion(balls);
        Draw(balls);
        std::this_thread::sleep_for(std::chrono::milliseconds(25));
    }
    return 0;
}
