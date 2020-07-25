bool canMove(Pole *wsk_to_board, int x, int y, int targetX, int targetY)
{

    Pole board[17][34];

    for(int i = 0; i < 17; i ++)
    {
        for(int j = 0; j < 34; j ++)
        {
            if((i%2==0&&j%2==0)||i%2==1&&j%2==1)
            board[i][j] = wsk_to_board[i * 34 + j];
        }
    }

    //============================trzeba bo AI klika gdzie chce xD========//

    int Owner;
    tura==2?Owner=2:Owner=1;
    if(board[targetX][targetY].owner==Owner)return 0;

    for (int i = 0; i<8;++i)
    {
        for (int j = 0; j<8; ++j)
        {
            if((j-i)>=0)
            {
                if(targetX==i&&targetY==(j-i))return 0;
                if(targetX==i&&targetY==(26+j))return 0;
            }
            else
            {
                if(targetX==(i+9)&&targetY==j)return 0;
                if(targetX==(i+9)&&targetY==32-j)return 0;
            }
        }
    }

    for(int i = 8; i < 17; i ++)
    {
        if(targetX==i&&targetY==33)return 0;
    }


    //========================================//



    if(board[x][y].name=="charge")
    {

        if((y == targetY) && ((targetX - x) == 2) && ( board[x+1][y+1].name=="empty" || board[x+1][y-1].name=="empty" )) return 1;
        if((y == targetY) && ((targetX - x) == -2) && ( board[x-1][y+1].name=="empty" || board[x-1][y+1].name=="empty" ) ) return 1;


        if((y == targetY+1) && (abs(targetX - x) == 1)) return 1;
        if((y == targetY-1) && (abs(targetX - x) == 1)) return 1;
        if(x == targetX)
        {
            bool zascianek=0;
            if(y > targetY)
            {
                for(int i = targetY + 2; i < y; i += 2)
                {
                    if(board[x][i].name == "empty" || board[x][i].owner == board[x][y].owner || board[x][i].name == "notexist")
                    {
                        if(board[x][i].name == "notexist"){
                            return 0; //tu kiedys bedzie latalo
                        }
                        continue;
                    }
                    return 0;
                }
                return 1;
            }
            else
            {
                for(int i = y + 2; i < targetY; i += 2)
                {
                    if(board[x][i].name == "empty" || board[x][i].owner == board[x][y].owner || board[x][i].name == "notexist")
                    {
                        if(board[x][i].name == "notexist"){
                            return 0; //tu kiedys bedzie latalo
                        }
                        continue;
                    }
                    return 0;
                }
                return 1;
            }
        }
    }

    if(board[x][y].name=="tower")
    {
        if(board[targetX][targetY].name!="empty")return 0;
        if(targetX==x)
        {
            if(abs(targetY-y) == 2) return 1;
            if(abs(targetY-y) == 4)
            {
                if(board[x][(targetY + y) / 2].name == "empty") return 1;
                else return 0;
            }
        }
        if(abs(targetX-x)==1 && abs(targetY-y)==1) return 1;
        if(abs(targetX-x)==2 && abs(targetY-y)==2)
        {
            if(board[(x + targetX) / 2][(y + targetY) / 2].name == "empty") return 1;
            else return 0;
        }
        else return 0;
	}

    if(board[x][y].name=="pawn")
    {
        if(board[targetX][targetY].name!="empty")return 0;
        int a;
        if(board[x][y].owner==1) a = 1;
        else a = -1;

        if((targetX == x) && (targetY == y + 2 * a)) return 1;
        else if((targetX == x) && (targetY == y + 4 * a)&&(board[targetX][targetY-(2*a)].name=="empty")) return 1;
        else if((targetX == x) && (targetY == y + 6 * a)&&(board[targetX][targetY-(2*a)].name=="empty")&&(board[targetX][targetY-(4*a)].name=="empty")) return 1;
        else if((targetX == x + 1) && (targetY == y + a)) return 1;
        else if((targetX == x - 1) && (targetY == y + a)) return 1;
        else return 0;
    }

    if(board[x][y].name=="king")
    {
        if((abs(targetX - x) == 1) && (abs(targetY - y) == 1)) return 1;
        else if((targetX == x) && (abs(targetY - y) == 2)) return 1;
        return 0;
    }

    if(board[x][y].name=="ghost")
    {
        //if((abs(targetX - x) == 1) && (abs(targetY - y) == 3)) return 1;
        if((abs(targetX - x) == 3) && (abs(targetY - y) == 3)) return 1;
        if((abs(targetX - x) == 2) && (abs(targetY - y) == 2)) return 1;
        if((targetX == x) && (abs(targetY-y) ==  4)) return 1;
        if((targetX == x) && (abs(targetY-y) ==  6)) return 1;
        return 0;
    }

    //kawaleria
    if(board[x][y].name=="cav")
    {
        if(board[targetX][targetY].name!="empty")return 0;
        int d_x;
        int d_y;
        if(targetX > x) d_x = 1;
        else d_x = -1;
        (targetY > y)?d_y = 1:d_y = -1;

        if(abs(targetX - x) != abs(targetY - y))
        {
            return 0;
        }

        int opponent_owner;
        (board[x][y].owner == 1)?opponent_owner = 2:opponent_owner = 1;


        for(int i = 1; i < abs(targetX - x); i ++)
        {
            if(board[i * d_x + x][i * d_y + y].name == "notexist")
            {
                return 0;
            }
            if(board[i * d_x + x][i * d_y + y].name != "empty")
            {
                if((targetX == i * d_x + d_x + x) && (targetY == i * d_y + d_y + y))
                {
                    return 1;
                }
                if((board[i * d_x + x][i * d_y + y].owner == opponent_owner) &&
                   (board[(i + 1) * d_x + x][(i + 1) * d_y + y].name == "empty") &&
                   (board[(i + 2) * d_x + x][(i + 2) * d_y + y].owner == opponent_owner) &&
                   (targetX == (i + 3) * d_x + x) && (targetY == (i + 3) * d_y + y))
                {
                    return 1;
                }
                else return 0;
            }
        }
        return 1;
    }

    if(board[x][y].name=="mystery")
    {
        int d_x;
        int d_y;
        int changes;

        if(targetX  == x)
        {
            d_x = 0;
            if(targetY > y) d_y = 2;
            else d_y = -2;

            changes = abs((targetY - y) / 2);
            for(int i = 1; i < changes; i ++)
            {
            //kiedy jest figura
                if(board[i * d_x + x][i * d_y + y].name != "empty")
                {
                    return 0;
                }
            }
            return 1;        //
        }
        else if(abs(targetX - x) != abs(targetY - y))
        {
            return 0;
        }else {
            if(targetX > x) d_x = 1;
            else d_x = -1;
            if(targetY > y) d_y = 1;
            else d_y = -1;
            for(int i = 1; i < abs(targetX - x); i ++)
            {
                int opponent_owner;
                (board[x][y].owner == 1)?opponent_owner = 2:opponent_owner = 1;
                if(board[i * d_x + x][i * d_y + y].name == "notexist"||board[i * d_x + x][i * d_y + y].owner==board[x][y].owner||board[i * d_x + x][i * d_y + y].owner==opponent_owner)
                {
                    return 0;
                }
            }
            return 1;
        }




    }
    return 0;
}

bool canAttack(Pole *wsk_to_board, int x, int y, int targetX, int targetY)
{
//============================trzeba bo AI klika gdzie chce xD========\\

    Pole board[17][34];

    for(int i = 0; i < 17; i ++)
    {
        for(int j = 0; j < 34; j ++)
        {
            if((i%2==0&&j%2==0)||i%2==1&&j%2==1)
            board[i][j] = wsk_to_board[i * 34 + j];
        }
    }

    int opponentOwner;
    tura==2?opponentOwner=1:opponentOwner=2;
    if(board[targetX][targetY].owner!=opponentOwner&&board[x][y].name!="cav")return 0;

//======================================================================\\
=======
    //sprawdz w ogole czy jest przeciwnik xD
    //if(wsk_to_board[x * 34 + y].owner == wsk_to_board[targetX * 34 + targetY].owner && wsk_to_board[targetX * 34 + targetY].owner != 0) return 0;


    if(wsk_to_board[x * 34 + y].name == "king")
    {
        if((abs(targetX - x) == 2) && (abs(targetY - y) == 2)) return 1;
        else if((targetX == x) && (abs(targetY - y) == 4)) return 1;
        else if((targetX == x+1) && (abs(targetY - y) == 3)) return 1;
        else if((targetX == x-1) && (abs(targetY - y) == 3)) return 1;
        return 0;
    }
    if(wsk_to_board[x * 34 + y].name == "ghost")
    {
        return canMove(wsk_to_board, x, y, targetX, targetY);
    }
    if(wsk_to_board[x * 34 + y].name == "charge" && targetX-x == 0)
    {
        return canMove(wsk_to_board, x, y, targetX, targetY);
    }else if (wsk_to_board[x * 34 + y].name == "charge") return 0;

    if(wsk_to_board[x * 34 + y].name == "mystery")
    {
        return canMove(wsk_to_board, x, y, targetX, targetY);
    }
    if(wsk_to_board[x * 34 + y].name == "cav")
    {
        return 0;
    }

    if(board[x][y].name=="tower")
    {
        if((x==targetX) && (abs(targetY-y)<=8) && (abs(targetY-y)>=6)) return 1;
        //if((abs(targetX-x)==2) && (abs(y-targetY)==2)) return 1;
        if((abs(targetX-x)==3) && (abs(y-targetY)==3)) return 1;
        if((abs(targetX-x)==4) && (abs(y-targetY)==4)) return 1;
        //if((abs(targetX-x)==5) && (abs(y-targetY)==5)) return 1;
        return 0;
    }
    if(board[x][y].name=="pawn")
    {
        int a;
        if(board[x][y].owner==1) a = 1;
        else a = -1;

        if((targetX == x) && (targetY == y + 2 * a)) return 1;
        else if((targetX == x + 1) && (targetY == y + a)) return 1;
        else if((targetX == x - 1) && (targetY == y + a)) return 1;
        else return 0;

    }
    return 0;
}

void move(Pole *wsk_to_board, int x, int y, int targetX, int targetY)
{
    if((wsk_to_board[x * 34 + y].name == "cav") || (wsk_to_board[x * 34 + y].name == "charge"))
    {
        Pole board[17][34];

        for(int i = 0; i < 17; i ++)
        {
            for(int j = 0; j < 34; j ++)
            {
                board[i][j] = wsk_to_board[i * 34 + j];
            }
        }

        int d_x;
        int d_y;

        if(board[x][y].name == "charge")
        {
            if(targetY != y)
            {
                if(targetY > y) d_y = 1;
                else d_y = -1;

                for(int i = 1; i < abs(targetY - y); i ++)
                {
                    if( wsk_to_board[x * 34 + (i * d_y) + y].name  == "king"    &&
                        wsk_to_board[x * 34 + (i * d_y) + y].owner == wsk_to_board[x * 34 + y].owner){
                        tura==2?tura=1:tura=2;
                        game.win = 1;

                    }

                    wsk_to_board[x * 34 + (i * d_y) + y].name = "empty";
                    wsk_to_board[x * 34 + (i * d_y) + y].owner = 0;
                    wsk_to_board[x * 34 + (i * d_y) + y].setTexture(texture_nothing);
                }
            }
        }
        else if(board[x][y].name == "cav")
        {
            int opponent_owner;
            if(board[x][y].owner == 1) opponent_owner = 2;
            else opponent_owner = 1;

            if(targetX > x) d_x = 1;
            else d_x = -1;

            if(targetY > y) d_y = 1;
            else d_y = -1;

            if(board[targetX - d_x][targetY - d_y].owner == opponent_owner)
            {
                if(board[targetX - d_x][targetY - d_y].name == "king") game.win = 1;
                //background_fields[targetX - d_x][targetY - d_y].setColor(sf::Color::Red);
                wsk_to_board[(targetX - d_x) * 34 + targetY - d_y].name = "empty";
                wsk_to_board[(targetX - d_x) * 34 + targetY - d_y].owner = 0;
                wsk_to_board[(targetX - d_x) * 34 + targetY - d_y].setTexture(texture_nothing);

                if(board[targetX - (2 * d_x)][targetY - (2 * d_y)].name == "empty")
                {
                    if(board[targetX - (3 * d_x)][targetY - (3 * d_y)].owner == opponent_owner)
                    {
                        if(board[targetX - d_x][targetY - d_y].name == "king")         game.win      = 1;
                        wsk_to_board[(targetX - (3 * d_x)) * 34 + targetY - (3 * d_y)].name     = "empty";
                        wsk_to_board[(targetX - (3 * d_x)) * 34 + targetY - (3 * d_y)].owner    = 0;
                        wsk_to_board[(targetX - (3 * d_x)) * 34 + targetY - (3 * d_y)].setTexture(texture_nothing);
                    }
                }
            }
        }
    }

    wsk_to_board[targetX * 34 + targetY].name = wsk_to_board[x * 34 + y].name;
    wsk_to_board[targetX * 34 + targetY].owner = wsk_to_board[x * 34 + y].owner;
    setFigureTexture(&wsk_to_board[targetX * 34 + targetY]);
    wsk_to_board[x * 34 + y].name = "empty";
    wsk_to_board[x * 34 + y].owner = 0;
    wsk_to_board[x * 34 + y].setTexture(Background);
}

void attack(Pole *wsk_to_board, int x, int y, int targetX, int targetY)
{
    if(wsk_to_board[x * 34 + y].name == "ghost")
    {
        move(wsk_to_board, x, y, targetX, targetY);
        return;
    }
    if(wsk_to_board[x * 34 + y].name == "king")
    {
        wsk_to_board[targetX*34+targetY].name="empty";
        wsk_to_board[targetX*34+targetY].owner = 0;
        wsk_to_board[targetX*34+targetY].setTexture(Background);
        return;
    }
    if(wsk_to_board[x * 34 + y].name == "charge")
    {
        move(wsk_to_board, x, y, targetX, targetY);
        return;
    }
    if(wsk_to_board[x * 34 + y].name == "mystery")
    {
        move(wsk_to_board, x, y, targetX, targetY);
        return;
    }
    if(wsk_to_board[x * 34 + y].name == "pawn")
    {
        move(wsk_to_board, x, y, targetX, targetY);
        return;
    }

    wsk_to_board[targetX * 34 + targetY].name = "empty";
    wsk_to_board[targetX * 34 + targetY].owner = 0;
    wsk_to_board[targetX * 34 + targetY].setTexture(texture_nothing);
}

bool action(Pole *wsk_to_board, int x, int y, int targetX, int targetY)
{
    if(x==0&&y==0&&targetX==0&&targetY==0){
        std::cout<<"nie podales wsp\n";
    }
    int opponent_owner;
    (wsk_to_board[x * 34 + y].owner == 1)?opponent_owner = 2:opponent_owner = 1;

    if(wsk_to_board[targetX * 34 + targetY].name == "empty")
    {
        if(canMove(wsk_to_board, x, y, targetX, targetY))
        {
            move(wsk_to_board, x, y, targetX, targetY);
            return 1;
        }
    }
    if(wsk_to_board[targetX * 34 + targetY].owner == wsk_to_board[x * 34 + y].owner)
    {
        game.click=0;
        return 0;
    }
    else if(wsk_to_board[targetX * 34 + targetY].owner == opponent_owner)
    {
        if(canAttack(wsk_to_board, x, y, targetX, targetY))
        {
            if(wsk_to_board[targetX * 34 + targetY].name=="king"){
                attack(wsk_to_board, x, y, targetX, targetY);
                game.win=1;
            }

            attack(wsk_to_board, x, y, targetX, targetY);
            return 1;
        }
    }
    //ms_message("Niepoprawne dane!!!");
     game.click=0;
    return 0;
}
