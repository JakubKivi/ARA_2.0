#include "../../include/gameStatus.hpp"

void gameStatus::adjustView(){
    if(sf::VideoMode::getDesktopMode().width>sf::VideoMode::getDesktopMode().height){
        this->scale=0.35*sf::VideoMode::getDesktopMode().height/1080; //uzale¿nic od sizePlanszyPrzed
        posuniecieX=(sf::VideoMode::getDesktopMode().width-((16*texture_kingD.getSize().x*0.79*this->scale)+texture_kingD.getSize().x*this->scale))/2;

        posuniecieY=0;//pawe³ da rade!... wcale nie! asia mi pomog³a bo jest fajniejsza <3
    }else{
        this->scale=0.397*sf::VideoMode::getDesktopMode().width/1080; //uzale¿niæ od size planszzyPrzed
        posuniecieX=0;
        posuniecieY=(sf::VideoMode::getDesktopMode().height-((32*texture_kingD.getSize().y*0.45*this->scale)+texture_kingD.getSize().y*this->scale))/2;
    }
}
