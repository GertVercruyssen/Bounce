#include "Ball.hpp"
#include <iostream>
#include <cmath>

Ball::Ball(int areaWidth, int areaHeight, int velocityX, int velocityY, int positionX, int positionY)
{
    area.first = areaWidth;
    area.second = areaHeight;
    pos.first = positionX;
    pos.second = positionY;
    velocity.first = velocityX;
    velocity.second = velocityY;
}
void Ball::Draw()
{
    std::string text = "";
    
    for(int tellery = 0; tellery< area.second+1; tellery++)
    {
        for(int tellerx = 0; tellerx< area.first+1; tellerx++)
        {
            if(tellerx == static_cast<int>(pos.first) and tellery == static_cast<int>(pos.second))
                text += "o";
            else
                text += " ";
        }
        text += "\n";
    }
    text += "\n";
    std::cout << text;
}
void Ball::Step()
{
    //Update X position, bounce with walls
    pos.first += velocity.first;
    if(pos.first >= area.first)
    {
        pos.first = area.first - (pos.first - area.first);
        velocity.first *= -1;
    }
    if(pos.first <= 0)
    {
        pos.first = pos.first*-1;
        velocity.first *= -1;
    }
    
    //Update Y position, bounce with walls
    pos.second += velocity.second;
    if(pos.second >= area.second)
    {
        pos.second = area.second - (pos.second - area.second);
        velocity.second *= -1* bounciness;
    }
    if(pos.second <= 0)
    {
        pos.second = pos.second*-1;
        velocity.second *= -1;
    }
    
    //Add gravity and rolling friction
    velocity.second += gravity/10;
    if(pos.second > (area.second-1))
        velocity.first *= friction;
}
void Ball::Collide(const Ball& otherBall)
{
    std::pair<float, float> normal {otherBall.pos.first-pos.first,otherBall.pos.second-pos.second};
    float length = sqrt(normal.first*normal.first+normal.second*normal.second);
    normal.first = normal.first/length;
    normal.second = normal.second/length;
    float dotproduct = velocity.first*normal.first+velocity.second+normal.second;
    velocity.first = velocity.first - 2*dotproduct*normal.first;
    velocity.second = velocity.second - 2*dotproduct*normal.second;
}
