void animateAfterLoading(sf::RenderWindow &window){
    float a=0;
    menu2PlusSubsSprite.setColor(sf::Color(0, 0, 0, 0));
    menu1Sprite.setColor(sf::Color(0, 0, 0, 255));
    while(a<256){
        menu2PlusSubsSprite.setColor(sf::Color(255, 255, 255, int(a)));
        menu1Sprite.setColor(sf::Color(255, 255, 255, 255-int(a)));

        window.draw(menu1Sprite);
        window.draw(menu2PlusSubsSprite);

        Kursor.setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)));
        window.draw(Kursor);
        window.display();
        window.clear();
        a+=szybkoscAnimacjiPoLadowaniu;
    }
}

void loadingTexture(sf::RenderWindow &window){
    if (!menu1.loadFromFile("graphics/menu/menu1.png"))
    {
        ms_error(666, "graphics/menu/menu1.png", 1);
    }
    menu1Sprite.setTexture(menu1);
    menu1Sprite.setScale(float(sf::VideoMode::getDesktopMode().width)/menu1.getSize().x, float(sf::VideoMode::getDesktopMode().height)/menu1.getSize().y);
    window.draw(menu1Sprite);
    window.display();
}

void drawFirstMenu(sf::RenderWindow &window){
    window.draw(menu2Sprite);
    window.draw(ARASprite);
    window.draw(OptionsSprite);
    window.draw(ExitSprite);
    window.draw(AutorsSprite);
    window.draw(LoadGameSprite);
    window.draw(PlaySprite);
    window.draw(TutorialSprite);
}

void drawGame(sf::RenderWindow &window){
    window.draw(backgroundImageSprite);
    for (int i = 0; i<17; ++i)
    {
        for (int j = 0; j<33; ++j)
        {
            window.draw(background_fields[i][j]);
            window.draw(front_fields[i * mapY + j]);
        }
    }
}


void drawKursor(sf::RenderWindow &window){
    Kursor.setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)));
    window.draw(Kursor);
    window.display();
    window.clear();
}

