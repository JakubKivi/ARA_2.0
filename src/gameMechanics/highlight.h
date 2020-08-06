bool highlight(int x, int y, gameStatus &game){



    int opponentOwner;
    (front_fields[x* 34 + y].owner == 1)?opponentOwner = 2:opponentOwner = 1;

    //pionek
    if (front_fields[x* 34 + y].name == "pawn"){
                for (int l = y-6; l<= y+6; l++){
                    if(l>=0 && l<34){
                        if((x%2==l%2)&&front_fields[x*34+l].name!="notexist"){

                                if(canAttack(front_fields, x, y, x, l, game)      &&
                                    front_fields[x*34+l].owner == opponentOwner)
                                        background_fields[x][l].setColor(atackColor);
                                else if(canMove(front_fields, x, y, x, l, game)   &&
                                    front_fields[x*34+l].name == "empty")
                                        background_fields[x][l].setColor(moveColor);
                        }
                    }
                }
                int a;
                game.tura==1?a=1:a=-1;
                if(x>0){
                    if(canAttack(front_fields, x, y, x-1, y+a, game)      &&
                        front_fields[(x-1)*34+y+a].owner == opponentOwner)
                            background_fields[x-1][y+a].setColor(atackColor);
                    else if(canMove(front_fields, x, y, x-1, y+a, game)   &&
                        front_fields[(x-1)*34+y+a].name == "empty")
                            background_fields[x-1][y+a].setColor(moveColor);
                }
                if(x<16){
                    if(canAttack(front_fields, x, y, x+1, y+a, game)      &&
                        front_fields[(x+1)*34+y+a].owner == opponentOwner)
                            background_fields[x+1][y+a].setColor(atackColor);
                    else if(canMove(front_fields, x, y, x+1, y+a, game)   &&
                        front_fields[(x+1)*34+y+a].name == "empty")
                            background_fields[x+1][y+a].setColor(moveColor);
                }
    }

    //duch
    else if(front_fields[x* 34 + y].name == "ghost"){
        for(int k = x-3; k <= x+3; k++){
            for (int l = y - 6; l<= y+6; l++){
                if(k>-1&&k<17&&l>=0&&l<34){
                    if(canAttack(front_fields, x, y, k, l, game)      &&
                        front_fields[k*34+l].owner == opponentOwner)
                            background_fields[k][l].setColor(atackColor);
                    else if(canMove(front_fields, x, y, k, l, game)   &&
                        front_fields[k*34+l].name == "empty")
                            background_fields[k][l].setColor(moveColor);
                }

            }
        }
    }

    //krolik
    else if(front_fields[x* 34 + y].name == "king"){
        for(int k = x-2; k <= x+2; k++){
            for (int l = y-4; l <= y+4; l++){
                if(k>-1&&k<17&&l>=0&&l<34){
                    if(canAttack(front_fields, x, y, k, l, game)      &&
                         front_fields[k*34+l].owner == opponentOwner)
                            background_fields[k][l].setColor(atackColor);
                    else if(canMove(front_fields, x, y, k, l, game)   &&
                        front_fields[k*34+l].name == "empty")
                            background_fields[k][l].setColor(moveColor);
                }
            }
        }
    }

    //wieza
            else if(front_fields[x* 34 + y].name == "tower"){
                for(int k = x-2; k <= x+2; k++){
                    for (int l = y-4; l <= y+4; l++){
                        if(k>=0&&k<17&&l>=0&&l<34){
                            if(canMove(front_fields, x, y, k, l, game))background_fields[k][l].setColor(moveColor);
                        }
                    }
                int nx=x+2;
                int ny=y+2;
                while(nx<17&&ny<34&&nx<x+4){
                    nx++;
                    ny++;
                    if(canAttack(front_fields, x, y, nx, ny, game))background_fields[nx][ny].setColor(atackColor);
                }
                nx=x-2;
                ny=y-2;
                while(nx>0&&ny>0&&nx>x-4){
                    nx--;
                    ny--;
                    if(canAttack(front_fields, x, y, nx, ny, game))background_fields[nx][ny].setColor(atackColor);
                }
                nx=x+2;
                ny=y-2;
                while(nx<17&&ny>0&&nx<x+4){
                    nx++;
                    ny--;
                    if(canAttack(front_fields, x, y, nx, ny, game))background_fields[nx][ny].setColor(atackColor);
                }
                nx=x-2;
                ny=y+2;
                while(nx>0&&ny<34&&nx>x-4){
                    nx--;
                    ny++;
                    if(canAttack(front_fields, x, y, nx, ny, game))background_fields[nx][ny].setColor(atackColor);
                }
                for(int i=y+6; i<=y+8; i+=2){
                    if(canAttack(front_fields, x, y, x, i, game))background_fields[x][i].setColor(atackColor);
                }
                for(int i=y-8; i<=y-6; i+=2){
                    if(canAttack(front_fields, x, y, x, i, game))background_fields[x][i].setColor(atackColor);
                }
                }
            }

    //szarza
    else if(front_fields[x* 34 + y].name == "charge"){
            for (int l = 0; l < 34; l++){
                if(l==y) continue;
                if(l>=0 &&l <34){
                    //podswietla na czerwono swoje figry ktore zabije
                    if(canAttack(front_fields, x, y, x, l, game)      &&
                        front_fields[x*34+l].owner == opponentOwner)
                            background_fields[x][l].setColor(atackColor);
                    else if(canMove(front_fields, x, y, x, l, game)   &&
                        front_fields[x*34+l].name == "empty")
                            background_fields[x][l].setColor(moveColor);
                    else if(canMove(front_fields, x, y, x, l, game)   &&
                        front_fields[x*34+y].owner == front_fields[x*34+l].owner)
                            background_fields[x][l].setColor(sf::Color(105, 0, 0, 255));

                }
            }
            if(x-2>=0){
                if(canMove(front_fields, x, y, x-2, y, game)  &&
                    front_fields[(x-2)*34+y].name == "empty")
                        background_fields[x-2][y].setColor(moveColor);
            }
            if(x+2<17){
                if(canMove(front_fields, x, y, x+2, y, game)  &&
                    front_fields[(x+2)*34+y].name == "empty")
                        background_fields[x+2][y].setColor(moveColor);
            }
            if(x+1<17 && y+1<34){
                if(canMove(front_fields, x, y, x+1, y+1, game)  &&
                    front_fields[(x+1)*34+y+1].name == "empty")
                        background_fields[x+1][y+1].setColor(moveColor);
            }
            if(x+1<17 && y-1>0){
                if(canMove(front_fields, x, y, x+1, y-1, game)  &&
                    front_fields[(x+1)*34+y-1].name == "empty")
                        background_fields[x+1][y-1].setColor(moveColor);
            }
            if(x-1>=0 && y+1<34){
                if(canMove(front_fields, x, y, x-1, y+1, game)  &&
                    front_fields[(x-1)*34+y+1].name == "empty")
                        background_fields[x-1][y+1].setColor(moveColor);
            }
            if(x-1>=0 && y-1>0){
                if(canMove(front_fields, x, y, x-1, y-1, game)  &&
                    front_fields[(x-1)*34+y-1].name == "empty")
                        background_fields[x-1][y-1].setColor(moveColor);
            }
    }

    //kawaleria
    else if(front_fields[x* 34 + y].name == "cav"){
        int nx=x+1;
        int ny=y+1;
        while(nx<17 && ny<34){
            if(canMove(front_fields, x, y, nx, ny, game)  &&
                front_fields[nx*34+ny].name == "empty")
                    background_fields[nx][ny].setColor(moveColor);
            nx++;
            ny++;
        }
        nx=x-1;
        ny=y-1;
        while(nx>=0 && ny>=0){
            if(canMove(front_fields, x, y, nx, ny, game)  &&
                front_fields[nx*34+ny].name == "empty")
                    background_fields[nx][ny].setColor(moveColor);
            nx--;
            ny--;
        }
        nx=x+1;
        ny=y-1;
        while(nx<17 && ny>=0){
            if(canMove(front_fields, x, y, nx, ny, game)  &&
                front_fields[nx*34+ny].name == "empty")
                    background_fields[nx][ny].setColor(moveColor);
            nx++;
            ny--;
        }
        nx=x-1;
        ny=y+1;
        while(nx>=0 && ny<34){
            if(canMove(front_fields, x, y, nx, ny, game)  &&
                front_fields[nx*34+ny].name == "empty")
                    background_fields[nx][ny].setColor(moveColor);
            nx--;
            ny++;
        }


    //zagadka
    }else if(front_fields[x* 34 + y].name == "mystery"){
        int nx=x+1;
        int ny=y+1;
        while(nx<17 && ny<34){
            if(canAttack(front_fields, x, y, nx, ny, game)        &&
                front_fields[nx*34+ny].owner == opponentOwner)
                    background_fields[nx][ny].setColor(atackColor);
            else if(canMove(front_fields, x, y, nx, ny, game)     &&
                front_fields[nx*34+ny].name == "empty")
                    background_fields[nx][ny].setColor(moveColor);
            nx++;
            ny++;
        }
        nx=x-1;
        ny=y-1;
        while(nx>=0 && ny>=0){
            if(canAttack(front_fields, x, y, nx, ny, game)        &&
                front_fields[nx*34+ny].owner == opponentOwner)
                    background_fields[nx][ny].setColor(atackColor);
            else if(canMove(front_fields, x, y, nx, ny, game)     &&
                front_fields[nx*34+ny].name == "empty")
                    background_fields[nx][ny].setColor(moveColor);
            nx--;
            ny--;
        }
        nx=x+1;
        ny=y-1;
        while(nx<17 && ny>=0){
            if(canAttack(front_fields, x, y, nx, ny, game)        &&
                front_fields[nx*34+ny].owner == opponentOwner)
                    background_fields[nx][ny].setColor(atackColor);
            else if(canMove(front_fields, x, y, nx, ny, game)     &&
                front_fields[nx*34+ny].name == "empty")
                    background_fields[nx][ny].setColor(moveColor);
            nx++;
            ny--;
        }
        nx=x-1;
        ny=y+1;
        while(nx>=0 && ny<34){
            if(canAttack(front_fields, x, y, nx, ny, game)        &&
                front_fields[nx*34+ny].owner == opponentOwner)
                    background_fields[nx][ny].setColor(atackColor);
            else if(canMove(front_fields, x, y, nx, ny, game)     &&
                front_fields[nx*34+ny].name == "empty")
                    background_fields[nx][ny].setColor(moveColor);
            nx--;
            ny++;
        }
        for(int i=0; i<34; i++){
            if(canAttack(front_fields, x, y, x, i, game)      &&
                front_fields[x*34+i].owner == opponentOwner)
                    background_fields[x][i].setColor(atackColor);
            else if(canMove(front_fields, x, y,x, i, game)        &&
                front_fields[x*34+i].name == "empty")
                    background_fields[x][i].setColor(moveColor);
        }


    }
    return 1;
}
