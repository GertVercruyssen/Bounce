#ifndef Ball_hpp
#define Ball_hpp

#include <stdio.h>
#include <utility>

#endif /* Ball_hpp */
class Ball
{
public:
    Ball(int areaX, int areaY, int velocityX, int velocityY, int positionX=0, int positionY=0);
    void Draw();
    void Step();
    std::pair<float, float> GetPosition() { return pos; };
    void Collide(const Ball& otherBall);
private:
    std::pair<float, float> pos;
    std::pair<int, int> area;
    std::pair<float, float> velocity;
    const float gravity = 0.4905;
    const float friction = 0.995;
    const float bounciness = 0.9;
};
