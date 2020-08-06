void gameLoop(sf::RenderWindow &window, mapRemoving &mapFall, gameStatus &game, sf::Sound &sound){

    int czteresci =texture_kingD.getSize().x*game.scale;
    int dwajscia = czteresci/2;
    int board_size_y=mapY;
    bool mouse_pressed=0;
    int mouseX, mouseY;

    sf::Vector2i mouse_position = sf::Mouse::getPosition(window);

     if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        mouse_pressed = 1;
    }

    for(int i = 0; i < 17; i ++)
    {
        for(int j = 0; j < 34; j ++)
        {
            if(!game.click){
                //============================Strefa je¿d¿enia myszk¹ po ekranie========================================//
                if(pow(mouse_position.x - dwajscia - background_fields[i][j].getPosition().x, 2) + pow(mouse_position.y - dwajscia - background_fields[i][j].getPosition().y, 2) < dwajscia*dwajscia)
                {
                    if(!game.click){
                        if(front_fields[i*34+j].owner==1)background_fields[i][j].setColor(sf::Color(175,210,255,150));
                        else if (front_fields[i*34+j].owner==2) background_fields[i][j].setColor(sf::Color(255,220,175,140));
                        else background_fields[i][j].setColor(sf::Color(255,255,255,220));
                    }
                    mouseX=i;
                    mouseY=j;
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
            }
        }
    }
    if(mouse_pressed){
        if(game.tura==2){
            if((game.figure_x == 0) && (game.figure_y == 0)){
                for(int i = 0; i < mapX; i ++){
                    for(int j = 0; j < mapY; j ++){
                        if(pow(mouse_position.x - dwajscia - background_fields[i][j].getPosition().x, 2) + pow(mouse_position.y - dwajscia - background_fields[i][j].getPosition().y, 2) < pow(dwajscia,2)){
                            game.figure_x = i;
                            game.figure_y = j;
                            front_fields[i*mapY+j].owner==1?background_fields[i][j].setColor(sf::Color(175,210,255,150)):background_fields[i][j].setColor(sf::Color(255,220,175,140));
                            if((front_fields[game.figure_x * mapY + game.figure_y].name == "empty"))
                            {
                                game.figure_x = 0;
                                game.figure_y = 0;
                            }else if(front_fields[game.figure_x*mapY+game.figure_y].owner==game.tura && (game.figure_x!=game.zakazaneX || game.figure_y!=game.zakazaneY)){
                                game.click=1;

                                mouse_position = sf::Mouse::getPosition(window);
                                (front_fields[game.figure_x* mapY + game.figure_y].owner == 1)?game.opponentOwner = 2:game.opponentOwner = 1;
                                //=======================================[highLight]================================
                                if(!highlight(game.figure_x, game.figure_y, game))ms_error(279, "cos poszlo nie tak z highlightem");
                                //========================================highlight=========================================================
                            }
                            else{
                                game.figure_x=0;
                                game.figure_y=0;
                            }
                        }
                    }
                }
            }
            else
            {
                for(int i = 0; i < 17; i ++)
                {
                    for(int j = 0; j < 34; j ++)
                    {
                        if(pow(mouse_position.x - dwajscia - background_fields[i][j].getPosition().x, 2) + pow(mouse_position.y - dwajscia - background_fields[i][j].getPosition().y, 2) < pow(dwajscia,2))
                        {

                            game.target_x = i;
                            game.target_y = j;
                            if(front_fields[mapY*game.figure_x+game.figure_y].owner)
                            {
                                if(action(front_fields, game.figure_x, game.figure_y, game.target_x, game.target_y, game))
                                {

                                    if(game.tura == 1 && game.ruch==0) {
                                        game.tura = 2;
                                        game.ruch=1;
                                        game.nrTura++;
                                        game.zakazaneX=0;
                                        game.zakazaneY=0;
                                    }
                                    else if(game.tura == 1 && game.ruch==1){
                                        game.ruch = 0;
                                        game.zakazaneX=game.target_x;
                                        game.zakazaneY=game.target_y;
                                    }
                                    else if(game.tura == 2 && game.ruch==0){
                                        game.tura = 1;
                                        game.ruch=1;
                                        game.nrTura++;
                                        game.zakazaneX=0;
                                        game.zakazaneY=0;
                                    }
                                    else if(game.tura == 2 && game.ruch==1) {
                                            game.ruch = 0;
                                        game.zakazaneX=game.target_x;
                                        game.zakazaneY=game.target_y;
                                    }
                                    sound.play();
                                    game.click=0;

                                    front_fields[game.target_x*34+game.target_y].setTexture(*front_fields[game.figure_x*34+game.figure_y].getTexture());
                                    front_fields[game.figure_x*34+game.figure_y].setTexture(texture_nothing);

                                    window.draw(front_fields[game.target_x*34+game.target_y]);
                                    window.draw(front_fields[game.figure_x*34+game.figure_y]);
                                }
                            }
                            else std::cout<<"to nie twoja tura dzbanie\n";
                            game.figure_x = 0;
                            game.figure_y = 0;
                        }
                    }
                }
            }
        }else if(!game.win){
            mouse_pressed=0;
            if(game.tura == 1) game.tura = 2;
            else game.tura = 1;
            game.nrTura++;
            sound.play();
            game.click=0;
        }
    }
frontFields();
}
