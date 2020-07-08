#include "include/header.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height), "A.R.A.", sf::Style::None);
    window.setMouseCursorVisible(false);

    loadingTexture(window);

    loadTextures();
    loadSounds();
    setSprites();

    animateAfterLoading(window);

    Pole background_fields[mapX][mapY];
    gameStatus game;
    Settings settings;

    sf::Event event;


    while(true){
        std::cout<<"x: "<<sf::Mouse::getPosition().x <<"y: "<<sf::Mouse::getPosition().y<<"\n";

        while (window.pollEvent(event))
        {
            switch(event.type){
                case sf::Event::Closed:
                    music.stop();
                    window.close();
                    return 0;
                break;

                case sf::Event::LostFocus:
                    lostFocus=1;
                break;

                case sf::Event::GainedFocus:
                    lostFocus=0;
                break;

                case sf::Event::MouseButtonPressed:
                    if(event.mouseButton.button == sf::Mouse::Left){
                        Kursor.setTexture(kursorClick);
                    }
                break;

                case sf::Event::MouseButtonReleased:
                    if (event.mouseButton.button == sf::Mouse::Left){
                        Kursor.setTexture(kursor);
                        mouseButtonFromPrev=0;
                    }
                break;
                case sf::Event::KeyPressed:
                    if(!game.firstLoad && !game.firstMenu){
                        if (event.key.code == sf::Keyboard::Escape&&game.isMenu)game.isMenu=0;
                        else if(event.key.code == sf::Keyboard::Escape&&game.isSaving){
                            game.isMenu=1;
                            game.isSaving=0;
                        }else if(event.key.code == sf::Keyboard::Escape)game.isMenu=1;
                        else if(event.key.code == sf::Keyboard::S&&game.isSaving){
                            game.isMenu=1;
                            game.isSaving=0;
                        }else if(event.key.code == sf::Keyboard::S&&!game.isSaving){
                            game.isSaving=1;
                            game.isMenu=0;
                        }
                    }
                    break;

                default: break;
            }
        }
        if(game.firstMenu){
            drawFirstMenu(window);
        }
        else if(game.firstLoad){
            drawFirstLoad(window);

                animateBook(window);

            window.draw(saveBookSprite);
        }

        drawElse(window);
    }
    return 0;
}
