#include "include/header.h"

int main()
{
    srand (time(NULL));

    sf::RenderWindow window(sf::VideoMode(sf::VideoMode::getDesktopMode().width-1, sf::VideoMode::getDesktopMode().height-1), "A.R.A.", sf::Style::None);
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

    saveBookSprite.setOrigin(sf::VideoMode::getDesktopMode().width/2,940);
    saveBookSprite.setPosition(sf::VideoMode::getDesktopMode().width/2,940);
    animation book(saveBookSprite);

    while(true){
        //std::cout<<"x: "<<sf::Mouse::getPosition().x <<"y: "<<sf::Mouse::getPosition().y<<"\n";

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

            if(book.targetAchieved){
                book.targetAchieved=0;
                int a = rand()%201;
                book.targetX= sf::VideoMode::getDesktopMode().width/2 + (a-100);

                a = rand()%201;
                book.targetY= 940 + (a-100);
                std::cout<<"targetX: "<<book.targetX<<" targetY: "<<book.targetY<<"\n";
            }else{
                book.animate(1);
            }

            window.draw(saveBookSprite);
        }

        drawElse(window);
    }
    return 0;
}
