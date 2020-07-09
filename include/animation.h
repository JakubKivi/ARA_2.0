class animation
{
public:
    animation(sf::Sprite &d);
    void setTarget(int a, int b);
    void animate(float a);

    int targetX;
    int targetY;
    float speed;
    sf::Sprite &sprite;
    bool targetAchieved;
};

animation::animation(sf::Sprite &d)
    :targetX(0),
    targetY(0),
    speed(1),
    targetAchieved(true),
    sprite(d)
{
}

void animation::setTarget(int a, int b){
    targetX=a;
    targetY=b;
    targetAchieved=0;
}

void animation::animate(float a){
    int moveX;
    int moveY;

    int aX, aY;
    targetX>sprite.getOrigin().x ? aX=1 : aX =-1;
    targetY>sprite.getOrigin().y ? aY=1 : aY =-1;

    int distanceX = abs(targetX - sprite.getOrigin().x);
    int distanceY = abs(targetY - sprite.getOrigin().y);

    if(distanceX!=0){
        if(distanceX > distanceY){
            moveX = speed*aX;
            moveY = speed * (distanceY/distanceX)*aY;
        }else{
            moveY = speed*aX;
            moveX = speed * (distanceX/distanceY)*aY;
        }
        sprite.move(moveX, moveY);
    }else{
        targetAchieved = 1;
    }
    //std::cout<<"posuwam\n";
}
