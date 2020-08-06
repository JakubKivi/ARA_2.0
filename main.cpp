#include "include/header.hpp"
int main()
{
    int scaleMenuX=1;
    int scaleMenuY=1;

    srand (time(NULL));

    sf::RenderWindow window(sf::VideoMode(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height), "A.R.A.", sf::Style::None);
    window.setMouseCursorVisible(false);

    loadingTexture(window);
    sf::Music music;
    sf::Sound sound;
    audio(music, sound);
    loadTextures();
    setSprites();
    animateAfterLoading(window);
    Settings settings;
    mapRemoving mapFall;
    gameStatus game;
    sf::Event event;
    game.adjustView();
    loadSettings(settings);
    backgroundFields(game);
    frontFields();

    bool doOnce=1;
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
                    game.lostFocus=1;
                break;

                case sf::Event::GainedFocus:
                    game.lostFocus=0;
                break;

                case sf::Event::MouseButtonPressed:
                    if(event.mouseButton.button == sf::Mouse::Left){
                        Kursor.setTexture(kursorClick);
                    }
                break;

                case sf::Event::MouseButtonReleased:
                    if (event.mouseButton.button == sf::Mouse::Left){
                        Kursor.setTexture(kursor);
                        game.mouseButtonFromPrev=0;
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
            if(!firstMenu(window, scaleMenuX, scaleMenuY, game))return 0;
        }
        else if(game.firstLoad){
            firstLoad(window);
            window.draw(saveBookSprite);
        }else if(game.game){
            if(doOnce){
                doOnce=0;
                LoadSave(0, front_fields, mapFall, game);
            }
            gameLoop(window, mapFall, game, sound);



            drawGame(window);

        }

        drawKursor(window);
    }
    return 0;
}
