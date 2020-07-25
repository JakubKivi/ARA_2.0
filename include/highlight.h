bool highlight(int x, int y){



    int opponentOwner;
    (front_fields[x* 34 + y].owner == 1)?opponentOwner = 2:opponentOwner = 1;

    //pionek
    if (front_fields[x* 34 + y].name == "pawn"){
                for (int l = y-6; l<= y+6; l++){
                    if(l>=0 && l<34){
                        if((x%2==l%2)&&front_fields[x*34+l].name!="notexist"){

                                if(canAttack(front_fields, x, y, x, l)      &&
                                    front_fields[x*34+l].owner == opponentOwner)
                                        background_fields[x][l].setColor(rColor);
                                else if(canMove(front_fields, x, y, x, l)   &&
                                    front_fields[x*34+l].name == "empty")
                                        background_fields[x][l].setColor(gColor);
                        }
                    }
                }
                int a;
                tura==1?a=1:a=-1;
                if(x>0){
                    if(canAttack(front_fields, x, y, x-1, y+a)      &&
                        front_fields[(x-1)*34+y+a].owner == opponentOwner)
                            background_fields[x-1][y+a].setColor(rColor);
                    else if(canMove(front_fields, x, y, x-1, y+a)   &&
                        front_fields[(x-1)*34+y+a].name == "empty")
                            background_fields[x-1][y+a].setColor(gColor);
                }
                if(x<16){
                    if(canAttack(front_fields, x, y, x+1, y+a)      &&
                        front_fields[(x+1)*34+y+a].owner == opponentOwner)
                            background_fields[x+1][y+a].setColor(rColor);
                    else if(canMove(front_fields, x, y, x+1, y+a)   &&
                        front_fields[(x+1)*34+y+a].name == "empty")
                            background_fields[x+1][y+a].setColor(gColor);
                }
    }

    //duch
    else if(front_fields[x* 34 + y].name == "ghost"){
        for(int k = x-3; k <= x+3; k++){
            for (int l = y - 6; l<= y+6; l++){
                if(k>-1&&k<17&&l>=0&&l<34){
                    if(canAttack(front_fields, x, y, k, l)      &&
                        front_fields[k*34+l].owner == opponentOwner)
                            background_fields[k][l].setColor(rColor);
                    else if(canMove(front_fields, x, y, k, l)   &&
                        front_fields[k*34+l].name == "empty")
                            background_fields[k][l].setColor(gColor);
                }

            }
        }
    }

    //krolik
    else if(front_fields[x* 34 + y].name == "king"){
        for(int k = x-2; k <= x+2; k++){
            for (int l = y-4; l <= y+4; l++){
                if(k>-1&&k<17&&l>=0&&l<34){
                    if(canAttack(front_fields, x, y, k, l)      &&
                         front_fields[k*34+l].owner == opponentOwner)
                            background_fields[k][l].setColor(rColor);
                    else if(canMove(front_fields, x, y, k, l)   &&
                        front_fields[k*34+l].name == "empty")
                            background_fields[k][l].setColor(gColor);
                }
            }
        }
    }

    //wieza
            else if(front_fields[x* 34 + y].name == "tower"){
                for(int k = x-2; k <= x+2; k++){
                    for (int l = y-4; l <= y+4; l++){
                        if(k>=0&&k<17&&l>=0&&l<34){
                            if(canMove(front_fields, x, y, k, l))background_fields[k][l].setColor(gColor);
                        }
                    }
                int nx=x+2;
                int ny=y+2;
                while(nx<17&&ny<34&&nx<x+4){
                    nx++;
                    ny++;
                    if(canAttack(front_fields, x, y, nx, ny))background_fields[nx][ny].setColor(rColor);
                }
                nx=x-2;
                ny=y-2;
                while(nx>0&&ny>0&&nx>x-4){
                    nx--;
                    ny--;
                    if(canAttack(front_fields, x, y, nx, ny))background_fields[nx][ny].setColor(rColor);
                }
                nx=x+2;
                ny=y-2;
                while(nx<17&&ny>0&&nx<x+4){
                    nx++;
                    ny--;
                    if(canAttack(front_fields, x, y, nx, ny))background_fields[nx][ny].setColor(rColor);
                }
                nx=x-2;
                ny=y+2;
                while(nx>0&&ny<34&&nx>x-4){
                    nx--;
                    ny++;
                    if(canAttack(front_fields, x, y, nx, ny))background_fields[nx][ny].setColor(rColor);
                }
                for(int i=y+6; i<=y+8; i+=2){
                    if(canAttack(front_fields, x, y, x, i))background_fields[x][i].setColor(rColor);
                }
                for(int i=y-8; i<=y-6; i+=2){
                    if(canAttack(front_fields, x, y, x, i))background_fields[x][i].setColor(rColor);
                }
                }
            }

    //szarza
    else if(front_fields[x* 34 + y].name == "charge"){
            for (int l = 0; l < 34; l++){
                if(l==y) continue;
                if(l>=0 &&l <34){
                    //podswietla na czerwono swoje figry ktore zabije
                    if(canAttack(front_fields, x, y, x, l)      &&
                        front_fields[x*34+l].owner == opponentOwner)
                            background_fields[x][l].setColor(rColor);
                    else if(canMove(front_fields, x, y, x, l)   &&
                        front_fields[x*34+l].name == "empty")
                            background_fields[x][l].setColor(gColor);
                    else if(canMove(front_fields, x, y, x, l)   &&
                        front_fields[x*34+y].owner == front_fields[x*34+l].owner)
                            background_fields[x][l].setColor(sf::Color(105, 0, 0, 255));

                }
            }
            if(x-2>=0){
                if(canMove(front_fields, x, y, x-2, y)  &&
                    front_fields[(x-2)*34+y].name == "empty")
                        background_fields[x-2][y].setColor(gColor);
            }
            if(x+2<17){
                if(canMove(front_fields, x, y, x+2, y)  &&
                    front_fields[(x+2)*34+y].name == "empty")
                        background_fields[x+2][y].setColor(gColor);
            }
            if(x+1<17 && y+1<34){
                if(canMove(front_fields, x, y, x+1, y+1)  &&
                    front_fields[(x+1)*34+y+1].name == "empty")
                        background_fields[x+1][y+1].setColor(gColor);
            }
            if(x+1<17 && y-1>0){
                if(canMove(front_fields, x, y, x+1, y-1)  &&
                    front_fields[(x+1)*34+y-1].name == "empty")
                        background_fields[x+1][y-1].setColor(gColor);
            }
            if(x-1>=0 && y+1<34){
                if(canMove(front_fields, x, y, x-1, y+1)  &&
                    front_fields[(x-1)*34+y+1].name == "empty")
                        background_fields[x-1][y+1].setColor(gColor);
            }
            if(x-1>=0 && y-1>0){
                if(canMove(front_fields, x, y, x-1, y-1)  &&
                    front_fields[(x-1)*34+y-1].name == "empty")
                        background_fields[x-1][y-1].setColor(gColor);
            }
    }

    //kawaleria
    else if(front_fields[x* 34 + y].name == "cav"){
        int nx=x+1;
        int ny=y+1;
        while(nx<17 && ny<34){
            if(canMove(front_fields, x, y, nx, ny)  &&
                front_fields[nx*34+ny].name == "empty")
                    background_fields[nx][ny].setColor(gColor);
            nx++;
            ny++;
        }
        nx=x-1;
        ny=y-1;
        while(nx>=0 && ny>=0){
            if(canMove(front_fields, x, y, nx, ny)  &&
                front_fields[nx*34+ny].name == "empty")
                    background_fields[nx][ny].setColor(gColor);
            nx--;
            ny--;
        }
        nx=x+1;
        ny=y-1;
        while(nx<17 && ny>=0){
            if(canMove(front_fields, x, y, nx, ny)  &&
                front_fields[nx*34+ny].name == "empty")
                    background_fields[nx][ny].setColor(gColor);
            nx++;
            ny--;
        }
        nx=x-1;
        ny=y+1;
        while(nx>=0 && ny<34){
            if(canMove(front_fields, x, y, nx, ny)  &&
                front_fields[nx*34+ny].name == "empty")
                    background_fields[nx][ny].setColor(gColor);
            nx--;
            ny++;
        }


    //zagadka
    }else if(front_fields[x* 34 + y].name == "mystery"){
        int nx=x+1;
        int ny=y+1;
        while(nx<17 && ny<34){
            if(canAttack(front_fields, x, y, nx, ny)        &&
                front_fields[nx*34+ny].owner == opponentOwner)
                    background_fields[nx][ny].setColor(rColor);
            else if(canMove(front_fields, x, y, nx, ny)     &&
                front_fields[nx*34+ny].name == "empty")
                    background_fields[nx][ny].setColor(gColor);
            nx++;
            ny++;
        }
        nx=x-1;
        ny=y-1;
        while(nx>=0 && ny>=0){
            if(canAttack(front_fields, x, y, nx, ny)        &&
                front_fields[nx*34+ny].owner == opponentOwner)
                    background_fields[nx][ny].setColor(rColor);
            else if(canMove(front_fields, x, y, nx, ny)     &&
                front_fields[nx*34+ny].name == "empty")
                    background_fields[nx][ny].setColor(gColor);
            nx--;
            ny--;
        }
        nx=x+1;
        ny=y-1;
        while(nx<17 && ny>=0){
            if(canAttack(front_fields, x, y, nx, ny)        &&
                front_fields[nx*34+ny].owner == opponentOwner)
                    background_fields[nx][ny].setColor(rColor);
            else if(canMove(front_fields, x, y, nx, ny)     &&
                front_fields[nx*34+ny].name == "empty")
                    background_fields[nx][ny].setColor(gColor);
            nx++;
            ny--;
        }
        nx=x-1;
        ny=y+1;
        while(nx>=0 && ny<34){
            if(canAttack(front_fields, x, y, nx, ny)        &&
                front_fields[nx*34+ny].owner == opponentOwner)
                    background_fields[nx][ny].setColor(rColor);
            else if(canMove(front_fields, x, y, nx, ny)     &&
                front_fields[nx*34+ny].name == "empty")
                    background_fields[nx][ny].setColor(gColor);
            nx--;
            ny++;
        }
        for(int i=0; i<34; i++){
            if(canAttack(front_fields, x, y, x, i)      &&
                front_fields[x*34+i].owner == opponentOwner)
                    background_fields[x][i].setColor(rColor);
            else if(canMove(front_fields, x, y,x, i)        &&
                front_fields[x*34+i].name == "empty")
                    background_fields[x][i].setColor(gColor);
        }


    }
    return 1;
}
