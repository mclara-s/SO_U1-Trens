#include "trem.h"
#include <QtCore>

#include <QMutex>

QMutex semaforo[9];

Trem::Trem(int ID, int x, int y)
{
    this->ID = ID;  
    this->x = x;
    this->y = y;
    stop = false;
    velocidade = 100;
}

void Trem::run(){
    while(true){
        while(!stop){
        emit updateGUI(ID, x, y);
        switch(ID){
            case 1:
                /* ----- lock's nos semaforos ----- */
                /*if(x == 280 && y == 80){
                    semaforo[2].lock();
                    semaforo[0].lock();
                }*/

                if (x < 300 && y == 80)
                    x += 10;
                else if (x == 300 && y < 200)
                    y += 10;
                else if (y == 200 && x > 70)
                    x -= 10;
                else if (x == 70 && y > 80)
                    y -= 10;


                /* ----- unlock's nos semaforos -- */
                /*if(x == 160 && y = 200){
                    semaforo[2].unlock();
                }
                else if(x = 280 && y == 200){
                    semaforo[0].unlock();
                }*/

                break;
            case 2:
                /* ----- lock's nos semaforos ----- */
                /*if(x ==  && y == ){
                    semaforo[].lock();
                    semaforo[].lock();
                    semaforo[].lock();
                    semaforo[].lock();
                }*/

                if (x < 530 && y == 80)
                    x += 10;
                else if (x == 530 && y < 200)
                    y += 10;
                else if (y == 200 && x > 300)
                    x -= 10;
                else if (x == 300 && y > 80)
                    y -= 10;


                /* ----- unlock's nos semaforos -- */
                /*if(x ==  && y = ){
                    semaforo[].unlock();
                }
                else if(x =  && y == ){
                    semaforo[].unlock();
                }
                else if(x =  && y == ){
                    semaforo[].unlock();
                }
                else if(x =  && y == ){
                    semaforo[].unlock();
                }*/

                break;

            case 3:
                /* ----- lock's nos semaforos ----- */
                /*if(x ==  && y == ){
                    semaforo[].lock();
                    semaforo[].lock();
                }*/

                if (x < 760 && y == 80)
                    x += 10;
                else if (x == 760 && y < 200)
                    y += 10;
                else if (y == 200 && x > 530)
                    x -= 10;
                else if (x == 530 && y > 80)
                    y -= 10;
                

                /* ----- unlock's nos semaforos -- */
                /*if(x ==  && y = ){
                    semaforo[].unlock();
                }
                else if(x =  && y == ){
                    semaforo[].unlock();
                }*/

                break;

            case 4:
                /* ----- lock's nos semaforos ----- */
                /*if(x ==  && y == ){
                    semaforo[].lock();
                    semaforo[].lock();
                    semaforo[].lock();
                    semaforo[].lock();
                }*/

                if (x < 410 && y == 200)
                    x += 10;
                else if (x == 410 && y < 320)
                    y += 10;
                else if (y == 320 && x > 180)
                    x -= 10;
                else if (x == 180 && y > 200)
                    y -= 10;
                

                /* ----- unlock's nos semaforos -- */
                /*if(x ==  && y = ){
                    semaforo[].unlock();
                }
                else if(x =  && y == ){
                    semaforo[].unlock();
                }
                else if(x =  && y == ){
                    semaforo[].unlock();
                }
                else if(x =  && y == ){
                    semaforo[].unlock();
                }*/

                break;

            case 5:
                /* ----- lock's nos semaforos ----- */
                /*if(x ==  && y == ){
                    semaforo[].lock();
                    semaforo[].lock();
                    semaforo[].lock();
                    semaforo[].lock();
                }*/

                if (x < 640 && y == 200)
                    x += 10;
                else if (x == 640 && y < 320)
                    y += 10;
                else if (y == 320 && x > 410)
                    x -= 10;
                else if (x == 410 && y > 200)
                    y -= 10;
                

                /* ----- unlock's nos semaforos -- */
                /*if(x ==  && y = ){
                    semaforo[].unlock();
                }
                else if(x =  && y == ){
                    semaforo[].unlock();
                }
                else if(x =  && y == ){
                    semaforo[].unlock();
                }
                else if(x =  && y == ){
                    semaforo[].unlock();
                }*/

                break;

            case 6:
                /* ----- lock's nos semaforos ----- */
                /*if(x ==  && y == ){
                    semaforo[].lock();
                    semaforo[].lock();
                }*/

                if (x < 530 && y == 320)
                    x += 10;
                else if (x == 530 && y < 440)
                    y += 10;
                else if (y == 440 && x > 300)
                    x -= 10;
                else if (x == 300 && y > 320)
                    y -= 10;
                

                /* ----- unlock's nos semaforos -- */
                /*if(x ==  && y = ){
                    semaforo[].unlock();
                }
                else if(x =  && y == ){
                    semaforo[].unlock();
                }*/

                break;

            default:
                break;
        }
        msleep(velocidade);
    }
    }
}

void Trem::finalizar(){
    stop = true;
}

void Trem::retomar(){
    stop = false;
}

/*
Trem::~Trem()
{

}
*/
