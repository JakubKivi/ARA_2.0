void gameLoop(sf::RenderWindow &window, mapRemoving &mapFall, gameStatus &game){

    int czteresci =texture_kingD.getSize().x*game.scale;
    int dwajscia = czteresci/2;
    int board_size_y=mapY;
    bool mouse_pressed=0;

    sf::Vector2i mouse_position = sf::Mouse::getPosition(window);

     if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        mouse_pressed = 1;
    }

    for(int i = 0; i < 17; i ++)
    {
        for(int j = 0; j < 34; j ++)
        {
            //============================Strefa je¿d¿enia myszk¹ po ekranie========================================//
            if(pow(mouse_position.x - dwajscia - background_fields[i][j].getPosition().x, 2) + pow(mouse_position.y - dwajscia - background_fields[i][j].getPosition().y, 2) < dwajscia*dwajscia)
            {
                if(!game.click){
                    if(front_fields[i*34+j].owner==1)background_fields[i][j].setColor(sf::Color(175,210,255,150));
                    else if (front_fields[i*34+j].owner==2) background_fields[i][j].setColor(sf::Color(255,220,175,140));
                    else background_fields[i][j].setColor(sf::Color(255,255,255,220));
                }
            }else if(front_fields[i * board_size_y + j].name != "empty"){
                if(front_fields[i * board_size_y + j].owner == 1){
                    if(!game.click)background_fields[i][j].setColor(upPlayerColor);
                }else if(front_fields[i * board_size_y + j].owner == 2){
                    if(!game.click)background_fields[i][j].setColor(downPlayerColor);
                }else if(front_fields[i * board_size_y + j].name == "notexist"){     //to mo¿e byæ niepotrzebne i byæ robione lepiej chyba
                    if(!game.click)background_fields[i][j].setTexture(texture_notexist);
                }
            }else{
                background_fields[i][j].setColor(sf::Color(255,255,255,255));

                if(background_fields[mapFall.baseX][mapFall.baseY].typK==1)
                    background_fields[mapFall.baseX][mapFall.baseY].setTexture(BackgroundBroken);
                else if(background_fields[mapFall.baseX][mapFall.baseY].typK==2)
                    background_fields[mapFall.baseX][mapFall.baseY].setTexture(BackgroundBroken2);
                else
                    background_fields[mapFall.baseX][mapFall.baseY].setTexture(BackgroundBroken3);

                if(background_fields[mapFall.basex][mapFall.basey].typK==1)
                    background_fields[mapFall.basex][mapFall.basey].setTexture(BackgroundBroken);
                else if(background_fields[mapFall.basex][mapFall.basey].typK==2)
                    background_fields[mapFall.basex][mapFall.basey].setTexture(BackgroundBroken2);
                else
                    background_fields[mapFall.basex][mapFall.basey].setTexture(BackgroundBroken3);
            }
            //=================================strefa klikania=====================================//
            if(mouse_pressed){
                std::cout<<"kuuuupa";
            }
        }
    }

}
