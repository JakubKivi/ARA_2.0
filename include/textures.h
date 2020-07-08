//-------------------------------Deklaracja tekstur-----------------------------------------------
// frontFields
sf::Texture texture_pawnU;
sf::Texture texture_ghostU;
sf::Texture texture_cavU;
sf::Texture texture_kingU;
sf::Texture texture_towerU;
sf::Texture texture_chargeU;
sf::Texture texture_mysteryU;
sf::Texture texture_pawnD;
sf::Texture texture_ghostD;
sf::Texture texture_cavD;
sf::Texture texture_kingD;
sf::Texture texture_towerD;
sf::Texture texture_chargeD;
sf::Texture texture_mysteryD;
sf::Texture texture_notexist;
sf::Texture texture_nothing;

// beckgroundFields
sf::Texture Background;
sf::Texture Background2;
sf::Texture Background3;
sf::Texture BackgroundBroken;
sf::Texture BackgroundBroken2;
sf::Texture BackgroundBroken3;

//firstMenu
sf::Texture menu1;
sf::Texture menu2PlusSubs;
sf::Texture menu2;
sf::Texture ARA;
sf::Texture Options;
sf::Texture Exit;
sf::Texture Autors;
sf::Texture LoadGame;
sf::Texture Play;
sf::Texture Tutorial;

sf::Sprite menu1Sprite;
sf::Sprite menu2PlusSubsSprite;
sf::Sprite menu2Sprite;
sf::Sprite ARASprite;
sf::Sprite OptionsSprite;
sf::Sprite ExitSprite;
sf::Sprite AutorsSprite;
sf::Sprite LoadGameSprite;
sf::Sprite PlaySprite;
sf::Sprite TutorialSprite;

//saveMenu
sf::Texture saveNoBook;
sf::Texture saveBook;
sf::Texture saveslot1;
sf::Texture saveslot2;
sf::Texture saveslot3;
sf::Texture saveslot4;
sf::Texture saveslot5;
sf::Texture saveslot6;
sf::Texture saveBack;

sf::Sprite saveNoBookSprite;
sf::Sprite saveBookSprite;
sf::Sprite saveslot1Sprite;
sf::Sprite saveslot2Sprite;
sf::Sprite saveslot3Sprite;
sf::Sprite saveslot4Sprite;
sf::Sprite saveslot5Sprite;
sf::Sprite saveslot6Sprite;
sf::Sprite saveBackSprite;

sf::Texture menu;
sf::Texture save;
sf::Sprite Menu;
sf::Sprite Save;
sf::Sprite WinTexture;

//popMenu
sf::Texture popExit;
sf::Texture popResume;
sf::Texture popSettings;
sf::Texture popMenu;
sf::Texture popSave;

sf::Sprite popExitSprite;
sf::Sprite popResumeSprite;
sf::Sprite popSettingsSprite;
sf::Sprite popMenuSprite;
sf::Sprite popSaveSprite;

//kursor
sf::Texture kursor;
sf::Texture kursorClick;
sf::Sprite Kursor;

//t³o
sf::Texture backroundImage;



void loadTextures(){
    if (!texture_pawnU.loadFromFile("graphics/ikony/peasantRed.png"))
    {
        ms_error(666, "graphics/ikony/peasantRed.png", 1);
    }
    if (!texture_ghostU.loadFromFile("graphics/ikony/ghostRed.png"))
    {
        ms_error(666, "graphics/ikony/ghostRed.png", 1);
    }
    if (!texture_cavU.loadFromFile("graphics/ikony/kawaleriaRed.png"))
    {
        ms_error(666, "graphics/ikony/kawaleriaRed.png", 1);
    }
    if (!texture_kingU.loadFromFile("graphics/ikony/kroolRed.png"))
    {
        ms_error(666, "graphics/ikony/kroolRed.png", 1);
    }
    if (!texture_towerU.loadFromFile("graphics/ikony/towerRed.png"))
    {
        ms_error(666, "graphics/ikony/towerRed.png", 1);
    }
    if (!texture_chargeU.loadFromFile("graphics/ikony/nosekred^^.png"))
    {
        ms_error(666, "graphics/ikony/nosekred^^.png", 1);
    }
    if (!texture_mysteryU.loadFromFile("graphics/ikony/zagadkaRed.png"))
    {
        ms_error(666, "graphics/ikony/zagadkaRed.png", 1);
    }
    if (!texture_notexist.loadFromFile("graphics/ikony/notexist.png"))
    {
        ms_error(666, "graphics/ikony/notexist.png", 1);
    }
    if (!texture_nothing.loadFromFile("graphics/ikony/notexist.png"))
    {
        ms_error(666, "graphics/ikony/notexist.png", 1);
    }
    if (!texture_pawnD.loadFromFile("graphics/ikony/peasantBlue.png"))
    {
        ms_error(666, "graphics/ikony/peasantBlue.png", 1);
    }
    if (!texture_ghostD.loadFromFile("graphics/ikony/ghostBlue.png"))
    {
        ms_error(666, "graphics/ikony/ghostBlue.png", 1);
    }
    if (!texture_cavD.loadFromFile("graphics/ikony/kawaleriaBlue.png"))
    {
        ms_error(666, "graphics/ikony/kawaleriaBlue.png", 1);
    }
    if (!texture_kingD.loadFromFile("graphics/ikony/kroolBlue.png"))
    {
        ms_error(666, "graphics/ikony/kroolBlue.png", 1);
    }
    if (!texture_towerD.loadFromFile("graphics/ikony/towerBlue.png"))
    {
        ms_error(666, "graphics/ikony/towerBlue.png", 1);
    }
    if (!texture_chargeD.loadFromFile("graphics/ikony/nosekblue^^.png"))
    {
        ms_error(666, "graphics/ikony/nosekblue^^.png", 1);
    }
    if (!texture_mysteryD.loadFromFile("graphics/ikony/zagadkaBlue.png"))
    {
        ms_error(666, "graphics/ikony/zagadkaRed.png", 1);
    }
    if (!Background.loadFromFile("graphics/stones/stone3.0.png"))

    {
        ms_error(666, "graphics/stones/stone3.0.png", 1);
    }
    if (!BackgroundBroken.loadFromFile("graphics/stones/stone3.1.png"))
    {
        ms_error(666, "graphics/stones/stone3.1.png", 1);
    }
    if (!Background2.loadFromFile("graphics/stones/stone2.0.png"))

    {
        ms_error(666, "graphics/stones/stone2.0.png", 1);
    }
    if (!BackgroundBroken2.loadFromFile("graphics/stones/stone2.1.png"))
    {
        ms_error(666, "graphics/stones/stone2.1.png", 1);
    }
    if (!Background3.loadFromFile("graphics/stones/stone1.0.png"))

    {
        ms_error(666, "graphics/stones/stone1.0.png", 1);
    }
    if (!BackgroundBroken3.loadFromFile("graphics/stones/stone1.1.png"))
    {
        ms_error(666, "graphics/stones/stone1.1.png", 1);
    }

    if (!Play.loadFromFile("graphics/menu/Sub/Play.png"))
    {
        ms_error(666, "graphics/menu/Sub/Play.png", 1);
    }
    if (!Tutorial.loadFromFile("graphics/menu/Sub/Tutorial.png"))
    {
        ms_error(666, "graphics/menu/Sub/Tutorial.png", 1);
    }
    if (!Options.loadFromFile("graphics/menu/Sub/Options.png"))
    {
        ms_error(666, "graphics/menu/Sub/Options.png", 1);
    }
    if (!LoadGame.loadFromFile("graphics/menu/Sub/LoadGame.png"))
    {
        ms_error(666, "graphics/menu/Sub/LoadGame.png", 1);
    }
    if (!Exit.loadFromFile("graphics/menu/sub/Exit.png"))
    {
        ms_error(666, "graphics/menu/sub/Exit.png", 1);
    }
    if (!Autors.loadFromFile("graphics/menu/sub/Autors.png"))
    {
        ms_error(666, "graphics/menu/sub/Autors.png", 1);
    }
    if (!ARA.loadFromFile("graphics/menu/Sub/ARA.png"))
    {
        ms_error(666, "graphics/menu/sub/ARA.png", 1);
    }
    if (!menu2.loadFromFile("graphics/menu/menu2.png"))
    {
        ms_error(666, "graphics/menu/menu2.png", 1);
    }
    if (!menu2PlusSubs.loadFromFile("graphics/menu/menu2PlusSubs.png"))
    {
        ms_error(666, "graphics/menu/menu2Plus.png", 1);
    }
    if (!popExit.loadFromFile("graphics/popMenu/exit.png"))
    {
        ms_error(666, "graphics/menu/popMenu/exit.png", 1);
    }
    if (!popSettings.loadFromFile("graphics/popMenu/settings.png"))
    {
        ms_error(666, "graphics/menu/popMenu/settings.png", 1);
    }
    if (!popResume.loadFromFile("graphics/popMenu/resume.png"))
    {
        ms_error(666, "graphics/menu/popMenu/resume.png", 1);
    }
    if (!popMenu.loadFromFile("graphics/popMenu/menu.png"))
    {
        ms_error(666, "graphics/menu/popMenu/menu.png", 1);
    }
    if (!popSave.loadFromFile("graphics/popMenu/save.png"))
    {
        ms_error(666, "graphics/menu/popMenu/save.png", 1);
    }

//    if (!font.loadFromFile("fonts/arial.ttf"))
//    {
//        ms_error(666, "fonts/arial.ttf", 1);
//    }
    if (!kursor.loadFromFile("graphics/rzeczy/kursorDuzy.png"))
    {
        ms_error(666, "graphics/rzeczy/kursorDuzy.png", 1);
    }
    if (!kursorClick.loadFromFile("graphics/rzeczy/kursorKlik.png"))
    {
        ms_error(666, "graphics/rzeczy/kursorKlik.png", 1);
    }
    if(!backroundImage.loadFromFile("graphics/rzeczy/tloLight.jpg")){
        ms_error(666, "graphics/rzeczy/tloLight.jpg");
    }
    if(!saveNoBook.loadFromFile("graphics/saveslots/saveNoBook.png")){
        ms_error(666, "graphics/saveslots/saveNoBook.png");
    }
    if(!saveBook.loadFromFile("graphics/saveslots/saveBook.png")){
        ms_error(666, "graphics/saveslots/savePlusSub.png");
    }
    if(!saveBack.loadFromFile("graphics/saveslots/Sub/back.png")){
        ms_error(666, "graphics/saveslots/Sub/back.png");
    }
    if(!saveslot1.loadFromFile("graphics/saveslots/sub/saveslot1.png")){
        ms_error(666, "graphics/saveslots/sub/saveslot1.png");
    }
    if(!saveslot2.loadFromFile("graphics/saveslots/sub/saveslot2.png")){
        ms_error(666, "graphics/saveslots/sub/saveslot2.png");
    }
    if(!saveslot3.loadFromFile("graphics/saveslots/sub/saveslot3.png")){
        ms_error(666, "graphics/saveslots/sub/saveslot3.png");
    }
    if(!saveslot4.loadFromFile("graphics/saveslots/sub/saveslot4.png")){
        ms_error(666, "graphics/saveslots/sub/saveslot4.png");
    }
    if(!saveslot5.loadFromFile("graphics/saveslots/sub/saveslot5.png")){
        ms_error(666, "graphics/saveslots/sub/saveslot5.png");
    }
    if(!saveslot6.loadFromFile("graphics/saveslots/sub/saveslot6.png")){
        ms_error(666, "graphics/saveslots/sub/saveslot6.png");
    }
}

void setSprites(){
    menu2Sprite.setTexture(menu2);
    menu2PlusSubsSprite.setTexture(menu2PlusSubs);
    ARASprite.setTexture(ARA);
    OptionsSprite.setTexture(Options);
    ExitSprite.setTexture(Exit);
    AutorsSprite.setTexture(Autors);
    LoadGameSprite.setTexture(LoadGame);
    PlaySprite.setTexture(Play);
    TutorialSprite.setTexture(Tutorial);
    saveNoBookSprite.setTexture(saveNoBook);
    saveBookSprite.setTexture(saveBook);
    saveslot1Sprite.setTexture(saveslot1);
    saveslot2Sprite.setTexture(saveslot2);
    saveslot3Sprite.setTexture(saveslot3);
    saveslot4Sprite.setTexture(saveslot4);
    saveslot5Sprite.setTexture(saveslot5);
    saveslot6Sprite.setTexture(saveslot6);
    saveBackSprite.setTexture(saveBack);
    saveBookSprite.setScale(float(sf::VideoMode::getDesktopMode().width)/menu1.getSize().x, float(sf::VideoMode::getDesktopMode().height)/menu1.getSize().y);
    saveNoBookSprite.setScale(float(sf::VideoMode::getDesktopMode().width)/menu1.getSize().x, float(sf::VideoMode::getDesktopMode().height)/menu1.getSize().y);
    saveslot2Sprite.setScale(float(sf::VideoMode::getDesktopMode().width)/menu1.getSize().x, float(sf::VideoMode::getDesktopMode().height)/menu1.getSize().y);
    saveslot3Sprite.setScale(float(sf::VideoMode::getDesktopMode().width)/menu1.getSize().x, float(sf::VideoMode::getDesktopMode().height)/menu1.getSize().y);
    saveslot4Sprite.setScale(float(sf::VideoMode::getDesktopMode().width)/menu1.getSize().x, float(sf::VideoMode::getDesktopMode().height)/menu1.getSize().y);
    saveslot5Sprite.setScale(float(sf::VideoMode::getDesktopMode().width)/menu1.getSize().x, float(sf::VideoMode::getDesktopMode().height)/menu1.getSize().y);
    saveslot6Sprite.setScale(float(sf::VideoMode::getDesktopMode().width)/menu1.getSize().x, float(sf::VideoMode::getDesktopMode().height)/menu1.getSize().y);
    saveBackSprite.setScale(float(sf::VideoMode::getDesktopMode().width)/menu1.getSize().x, float(sf::VideoMode::getDesktopMode().height)/menu1.getSize().y);
    menu1Sprite.setScale(float(sf::VideoMode::getDesktopMode().width)/menu1.getSize().x, float(sf::VideoMode::getDesktopMode().height)/menu1.getSize().y);
    menu2PlusSubsSprite.setScale(float(sf::VideoMode::getDesktopMode().width)/menu1.getSize().x, float(sf::VideoMode::getDesktopMode().height)/menu1.getSize().y);
    menu2Sprite.setScale(float(sf::VideoMode::getDesktopMode().width)/menu1.getSize().x, float(sf::VideoMode::getDesktopMode().height)/menu1.getSize().y);
    ARASprite.setScale(float(sf::VideoMode::getDesktopMode().width)/menu1.getSize().x, float(sf::VideoMode::getDesktopMode().height)/menu1.getSize().y);
    OptionsSprite.setScale(float(sf::VideoMode::getDesktopMode().width)/menu1.getSize().x, float(sf::VideoMode::getDesktopMode().height)/menu1.getSize().y);
    ExitSprite.setScale(float(sf::VideoMode::getDesktopMode().width)/menu1.getSize().x, float(sf::VideoMode::getDesktopMode().height)/menu1.getSize().y);
    AutorsSprite.setScale(float(sf::VideoMode::getDesktopMode().width)/menu1.getSize().x, float(sf::VideoMode::getDesktopMode().height)/menu1.getSize().y);
    LoadGameSprite.setScale(float(sf::VideoMode::getDesktopMode().width)/menu1.getSize().x, float(sf::VideoMode::getDesktopMode().height)/menu1.getSize().y);
    PlaySprite.setScale(float(sf::VideoMode::getDesktopMode().width)/menu1.getSize().x, float(sf::VideoMode::getDesktopMode().height)/menu1.getSize().y);
    TutorialSprite.setScale(float(sf::VideoMode::getDesktopMode().width)/menu1.getSize().x, float(sf::VideoMode::getDesktopMode().height)/menu1.getSize().y);

    Kursor.setTexture(kursor);
    Kursor.setScale(0.5f, 0.5f);
}

void setFigureTexture(Pole *field){
    if(field->name == "pawn")
    {
        if(field->owner==1)field->setTexture(texture_pawnD);
        else field->setTexture(texture_pawnU);
    }
    else if(field->name == "tower")
    {
        if(field->owner==1)field->setTexture(texture_towerD);
        else field->setTexture(texture_towerU);
    }
    else if(field->name == "ghost")
    {
        if(field->owner==1)field->setTexture(texture_ghostD);
        else field->setTexture(texture_ghostU);
    }
    else if(field->name == "cav")
    {
        if(field->owner==1)field->setTexture(texture_cavD);
        else field->setTexture(texture_cavU);
    }
    else if(field->name == "king")
    {
        if(field->owner==1)field->setTexture(texture_kingD);
        else field->setTexture(texture_kingU);
    }
    else if(field->name == "mystery")
    {
        if(field->owner==1)field->setTexture(texture_mysteryD);
        else field->setTexture(texture_mysteryU);
    }
    else if(field->name == "charge")
    {
        if(field->owner==1)field->setTexture(texture_chargeD);
        else field->setTexture(texture_chargeU);
    }
    else if(field->name == "notexist")
    {
        field->setTexture(texture_notexist);
    }
    else if(field->name == "empty")
    {
        field->setTexture(texture_nothing);
    }
}
