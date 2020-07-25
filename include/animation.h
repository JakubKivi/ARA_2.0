class animation
{
public:
    animation(sf::Sprite &d);
    void animate();


    float speed;
    sf::Sprite &sprite;
    bool targetAchieved;
    int targetX, targetY;

private:

};

animation::animation(sf::Sprite &d)
    :speed(0.05),
    targetAchieved(true),
    sprite(d)
{
}

void animation::animate(){
}
