#include "include/header.h"

int main()
{
    srand (time(NULL));

    sf::RenderWindow window(sf::VideoMode(sf::VideoMode::getDesktopMode().width-1, sf::VideoMode::getDesktopMode().height-1), "A.R.A.", sf::Style::None);
    window.setMouseCursorVisible(false);

    loadingTexture(window);

    audio();

    loadTextures();
    setSprites();

    animateAfterLoading(window);

    Pole background_fields[mapX][mapY];

    Settings settings;

    sf::Event event;

    sf::Color basicColor = background_fields[8][28].getColor();

    saveBookSprite.setOrigin(sf::VideoMode::getDesktopMode().width/2,940);
    saveBookSprite.setPosition(sf::VideoMode::getDesktopMode().width/2,940);
    animation book(saveBookSprite);

    if(sf::VideoMode::getDesktopMode().width>sf::VideoMode::getDesktopMode().height){
        scale=0.35*sf::VideoMode::getDesktopMode().height/1080; //uzale¿nic od sizePlanszyPrzed
        posuniecieX=(sf::VideoMode::getDesktopMode().width-((16*texture_kingD.getSize().x*0.79*scale)+texture_kingD.getSize().x*scale))/2;

        posuniecieY=0;//pawe³ da rade!... wcale nie! asia mi pomog³a bo jest fajniejsza <3
    }else{
        scale=0.397*sf::VideoMode::getDesktopMode().width/1080; //uzale¿niæ od size planszzyPrzed
        posuniecieX=0;
        posuniecieY=(sf::VideoMode::getDesktopMode().height-((32*texture_kingD.getSize().y*0.45*scale)+texture_kingD.getSize().y*scale))/2;
    }


    int scaleMenuX=1;
    int scaleMenuY=1;

    bool doOnce=1;

    loadSettings(settings);
    backgroundFields();
    frontFields();

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
            if(!firstMenu(window, scaleMenuX, scaleMenuY))return 0;
        }
        else if(game.firstLoad){
            firstLoad(window);
            book.animate();
            window.draw(saveBookSprite);
        }else if(game.game){
            if(doOnce){
                doOnce=0;
                LoadSave(0, front_fields);
            }

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

        drawElse(window);
    }
    return 0;
}
