#include "trem.h"
#include <QtCore>

//Construtor
Trem::Trem(int ID, int x, int y){
    this->ID = ID;
    this->x = x;
    this->y = y;
    velocidade = 100;
    this->can_go = true;
}

//Função a ser executada após executar trem->START
void Trem::run(){
    while(true){
        switch(ID){
        case 1:     //Trem 1
            if(can_go){
                if (x < 440 && y == 40)
                    x+=10;
                else if (x == 440 && y < 240)
                    y+=10;
                else if (x > 240 && y == 240)
                    x-=10;
                else y-=10;
            }
            emit updateGUI(ID, x,y);    //Emite um sinal
            break;
        case 2: //Trem 2
            if(can_go){
                if (x < 640 && y == 40)
                    x+=10;
                else if (x == 640 && y < 240)
                    y+=10;
                else if (x > 440 && y == 240)
                    x-=10;
                else
                    y-=10;
            }
            emit updateGUI(ID, x,y);    //Emite um sinal
            break;
        case 3: //Trem 3
            if(can_go){
                if (x < 340 && y == 240)
                    x+=10;
                else if (x == 340 && y < 440)
                    y+=10;
                else if (x > 140 && y == 440)
                    x-=10;
                else
                    y-=10;
            }
            emit updateGUI(ID, x,y);    //Emite um sinal
            break;
        case 4: //Trem 4
            if(can_go){
                if (x < 540 && y == 240)
                    x+=10;
                else if (x == 540 && y < 440)
                    y+=10;
                else if (x > 340 && y == 440)
                    x-=10;
                else
                    y-=10;
            }
            emit updateGUI(ID, x,y);    //Emite um sinal
            break;
        case 5: //Trem 5
            if(can_go){
                if (x < 740 && y == 240)
                    x+=10;
                else if (x == 740 && y < 440)
                    y+=10;
                else if (x > 540 && y == 440)
                    x-=10;
                else
                    y-=10;
            }
            emit updateGUI(ID, x,y);    //Emite um sinal
            break;
        default:
            break;
        }
        msleep(velocidade);
    }
}

int Trem::getX(){
    return x;
}

int Trem::getY(){
    return y;
}

void Trem::run_or_stop(bool b){
    if(this->can_go != b)
        this->can_go = b;
}

void Trem::setSpeed(int s){
    this->velocidade = s;
}



