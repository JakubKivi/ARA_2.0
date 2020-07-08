void baseUp(){
    baseY-=2;
    basey+=2;
}

void baseLeftUp(){
    baseX-=1;
    baseY-=1;
    basex+=1;
    basey+=1;
}

void baseLeftDown(){
    baseX-=1;
    baseY+=1;
    basex+=1;
    basey-=1;
}

void baseDown(){
    baseY+=2;
    basey-=2;
}
void baseJump(){
    int a=nrZmiany2-1;
    baseX=baseX+3*nrZmiany2-a;
    basex=basex-3*nrZmiany2+a;
    baseY+=1;
    basey-=1;
    nrZmiany2++;
}


void algorytmBase(){

    if(nrZmiany==1||nrZmiany==5||nrZmiany==6
        ||nrZmiany==11||nrZmiany==12||nrZmiany==13
        ||nrZmiany==21||nrZmiany==22||nrZmiany==23
        ||nrZmiany==24||nrZmiany==33||nrZmiany==34
        ||nrZmiany==35||nrZmiany==36||nrZmiany==37
        ||nrZmiany==49||nrZmiany==50||nrZmiany==51
        ||nrZmiany==52||nrZmiany==53||nrZmiany==54
        ||nrZmiany==67||nrZmiany==68||nrZmiany==69
        ||nrZmiany==70||nrZmiany==71||nrZmiany==72
        ||nrZmiany==73||nrZmiany==89||nrZmiany==90
        ||nrZmiany==91||nrZmiany==92||nrZmiany==93
        ||nrZmiany==94||nrZmiany==95||nrZmiany==96)baseLeftUp();
    else if(nrZmiany==2||nrZmiany==7||nrZmiany==8
            ||nrZmiany==14||nrZmiany==15||nrZmiany==16
            ||nrZmiany==25||nrZmiany==26||nrZmiany==27
            ||nrZmiany==28||nrZmiany==38||nrZmiany==39
            ||nrZmiany==40||nrZmiany==41||nrZmiany==42
            ||nrZmiany==55||nrZmiany==56||nrZmiany==57
            ||nrZmiany==58||nrZmiany==59||nrZmiany==60
            ||nrZmiany==74||nrZmiany==75||nrZmiany==76
            ||nrZmiany==77||nrZmiany==78||nrZmiany==79
            ||nrZmiany==80||nrZmiany==97||nrZmiany==98
            ||nrZmiany==99||nrZmiany==100||nrZmiany==101
            ||nrZmiany==102||nrZmiany==103||nrZmiany==104)baseLeftDown();
    else if(nrZmiany==3||nrZmiany==9||nrZmiany==18
            ||nrZmiany==30||nrZmiany==45||nrZmiany==63
            ||nrZmiany==84)baseJump();
    else if(nrZmiany==4||nrZmiany==10||nrZmiany==19
            ||nrZmiany==20||nrZmiany==31||nrZmiany==32
            ||nrZmiany==46||nrZmiany==47||nrZmiany==48
            ||nrZmiany==64||nrZmiany==65||nrZmiany==66
            ||nrZmiany==85||nrZmiany==86||nrZmiany==87
            ||nrZmiany==88)baseUp();
    else if(nrZmiany==17||nrZmiany==29||nrZmiany==43
            ||nrZmiany==44||nrZmiany==61||nrZmiany==62
            ||nrZmiany==81||nrZmiany==82||nrZmiany==83
            ||nrZmiany==105||nrZmiany==106||nrZmiany==107)baseDown();

}

