//==== zmienne dotycz¹ce zapadania siê mapy ====//

    int tura;
    int nrTura=1;
    int oldTura =1;
    int nrZmiany=1;
    int nrZmiany2=1;
    int baseX=8;
    int baseY=16;
    int basex=8;
    int basey=16;

    gameStatus game;

    float scale;
    std::string actual_mode = "play";

//===========//


    int opponentOwner;
    bool clickInMenu=1;
    bool clickInSaving=1;
    bool mouseButtonFromPrev=0;

    bool lostFocus=0;

    //=====Pole type======//

    Pole background_fields[17][34];
    Pole *front_fields;

    //=====posuniecie======//

    int posuniecieX = 0;
    int posuniecieY = 0;


