int firstMenu(sf::RenderWindow &window, float scaleMenuX, float scaleMenuY, gameStatus &game){
    if(sf::Mouse::getPosition().x>340*scaleMenuX&&sf::Mouse::getPosition().x<700*scaleMenuX&&
       sf::Mouse::getPosition().y>400*scaleMenuY&&sf::Mouse::getPosition().y<560*scaleMenuY){
           if(sf::Mouse::isButtonPressed(sf::Mouse::Left)&&!game.mouseButtonFromPrev){
                    game.firstMenu=0;
                    game. game=1;
            }

            PlaySprite.setColor(sf::Color::White);

    }else PlaySprite.setColor(sf::Color(255, 255, 255, 200));



    if(sf::Mouse::getPosition().x>1095*scaleMenuX&&sf::Mouse::getPosition().x<1655*scaleMenuX&&
       sf::Mouse::getPosition().y>440*scaleMenuY&&sf::Mouse::getPosition().y<550*scaleMenuY){
           if(sf::Mouse::isButtonPressed(sf::Mouse::Left)&&!game.mouseButtonFromPrev){
                    game.firstMenu=0;
                    game.firstLoad=1;
            }

            LoadGameSprite.setColor(sf::Color::White);
    }else LoadGameSprite.setColor(sf::Color(255, 255, 255, 200));



    if(sf::Mouse::getPosition().x>500*scaleMenuX&&sf::Mouse::getPosition().x<830*scaleMenuX&&
       sf::Mouse::getPosition().y>635*scaleMenuY&&sf::Mouse::getPosition().y<820*scaleMenuY){
           if(sf::Mouse::isButtonPressed(sf::Mouse::Left)&&!game.mouseButtonFromPrev){
            }
            TutorialSprite.setColor(sf::Color::White);
    }else TutorialSprite.setColor(sf::Color(255, 255, 255, 200));


    if(sf::Mouse::getPosition().x>1075*scaleMenuX&&sf::Mouse::getPosition().x<1400*scaleMenuX&&
       sf::Mouse::getPosition().y>635*scaleMenuY&&sf::Mouse::getPosition().y<840*scaleMenuY){
           if(sf::Mouse::isButtonPressed(sf::Mouse::Left)&&!game.mouseButtonFromPrev){
            }
            OptionsSprite.setColor(sf::Color::White);
    }else OptionsSprite.setColor(sf::Color(255, 255, 255, 200));

    if(sf::Mouse::getPosition().x>55*scaleMenuX&&sf::Mouse::getPosition().x<360*scaleMenuX&&
       sf::Mouse::getPosition().y>918*scaleMenuY&&sf::Mouse::getPosition().y<1010*scaleMenuY){
           if(sf::Mouse::isButtonPressed(sf::Mouse::Left)&&!game.mouseButtonFromPrev){
            }
            AutorsSprite.setColor(sf::Color::White);
    }else AutorsSprite.setColor(sf::Color(255, 255, 255, 200));

    if(sf::Mouse::getPosition().x>1680*scaleMenuX&&sf::Mouse::getPosition().x<1855*scaleMenuX&&
       sf::Mouse::getPosition().y>944*scaleMenuY&&sf::Mouse::getPosition().y<1018*scaleMenuY){
           if(sf::Mouse::isButtonPressed(sf::Mouse::Left)&&!game.mouseButtonFromPrev){
                        return 0;
            }
            ExitSprite.setColor(sf::Color::White);
    }else ExitSprite.setColor(sf::Color(255, 255, 255, 200));

    //std::cout<<Kursor.getPosition().x<<"x"<<Kursor.getPosition().y<<"\n";
    window.draw(menu2Sprite);
    window.draw(ARASprite);
    window.draw(OptionsSprite);
    window.draw(ExitSprite);
    window.draw(AutorsSprite);
    window.draw(LoadGameSprite);
    window.draw(PlaySprite);
    window.draw(TutorialSprite);
    drawFirstMenu(window);
    return 1;
}


