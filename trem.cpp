#include "trem.h"
#include <QtCore>

#include <QMutex>

QMutex semaforo[9];

Trem::Trem(int ID, int x, int y, int vel)
{
    this->ID = ID;  
    this->x = x;
    this->y = y;
    stop = false;
    velocidade = vel;
}

void Trem::run(){
    while(true){
        while(!stop){
        emit updateGUI(ID, x, y, velocidade);
        switch(ID){
            case 1:
                /* ----- lock's nos semaforos ----- */
                if(x == 280 && y == 80){
                    semaforo[0].lock();
                    semaforo[2].lock();

                    //semaforo[2].lock();
                    //semaforo[0].lock();
                }


                if (x < 300 && y == 80)
                    x += 10;
                else if (x == 300 && y < 200)
                    y += 10;
                else if (y == 200 && x > 70)
                    x -= 10;
                else if (x == 70 && y > 80)
                    y -= 10;


                /* ----- unlock's nos semaforos -- */
                if(x == 160 && y == 200){
                    semaforo[2].unlock();
                }
                if(x == 280 && y == 200){
                    semaforo[0].unlock();
                }

                break;
            case 2:
                /* ----- lock's nos semaforos ----- */
                if(x == 510 && y == 80){           
                    semaforo[1].lock();
                    semaforo[4].lock();
                    semaforo[3].lock();
                    semaforo[0].lock();

                    /*semaforo[0].lock();
                    semaforo[3].lock();
                    semaforo[4].lock();
                    semaforo[1].lock();*/
                }

/*                if (x == 430 && y == 200){
                    semaforo[0].lock();
                    semaforo[3].lock();
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
                if(x == 320 && y == 80){
                    semaforo[0].unlock();
                }
                else if(x == 300 && y == 180){
                    semaforo[3].unlock();
                }
                else if(x == 390 && y == 200){
                    semaforo[4].unlock();
                }
                else if(x == 510 && y == 200){
                    semaforo[1].unlock();
                }

                break;

            case 3:
                /* ----- lock's nos semaforos ----- */
                if(x == 660 && y == 200){
                    semaforo[5].lock();
                    semaforo[1].lock();

                    //semaforo[1].lock();
                    //semaforo[5].lock();
                }


                if (x < 760 && y == 80)
                    x += 10;
                else if (x == 760 && y < 200)
                    y += 10;
                else if (y == 200 && x > 530)
                    x -= 10;
                else if (x == 530 && y > 80)
                    y -= 10;
                

                /* ----- unlock's nos semaforos -- */
                if(x == 550 && y == 80){
                    semaforo[1].unlock();
                }
                else if(x == 530 && y == 180){
                    semaforo[5].unlock();
                }

                break;

            case 4:
                /* ----- lock's nos semaforos ----- */
                if(x == 180 && y == 220){
                    semaforo[2].lock();
                    semaforo[3].lock();
                    semaforo[6].lock();
                    semaforo[7].lock();

                    /*semaforo[7].lock();
                    semaforo[6].lock();
                    semaforo[3].lock();
                    semaforo[2].lock();*/
                }

                /*if (x == 390 && y == 200){
                    semaforo[7].lock();
                    semaforo[6].lock();
                }
*/
                if (x < 410 && y == 200)
                    x += 10;
                else if (x == 410 && y < 320)
                    y += 10;
                else if (y == 320 && x > 180)
                    x -= 10;
                else if (x == 180 && y > 200)
                    y -= 10;
                

                /* ----- unlock's nos semaforos -- */
                if(x == 280 && y == 320){
                    semaforo[7].unlock();
                }
                else if(x == 390 && y == 320){
                    semaforo[6].unlock();
                }
                else if(x == 410 && y == 220){
                    semaforo[3].unlock();
                }
                else if(x == 320 && y == 200){
                    semaforo[2].unlock();
                }

                break;

            case 5:
                /* ----- lock's nos semaforos ----- */
                if(x == 550 && y == 320){
                    semaforo[8].lock();
                    semaforo[6].lock();
                    semaforo[4].lock();
                    semaforo[5].lock();

                    /*semaforo[5].lock();
                    semaforo[4].lock();
                    semaforo[6].lock();
                    semaforo[8].lock();*/
                }

                /*if (x == 410 && y == 220){
                    semaforo[5].lock();
                    semaforo[4].lock();
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
                if(x == 640 && y == 220){
                    semaforo[5].unlock();
                }
                else if(x == 550 && y == 200){
                    semaforo[4].unlock();
                }
                else if(x == 430 && y == 200){
                    semaforo[6].unlock();
                }
                else if(x == 410 && y == 300){
                    semaforo[8].unlock();
                }

                break;

            case 6:
                /* ----- lock's nos semaforos ----- */
                if(x == 300 && y == 340){
                    semaforo[7].lock();
                    semaforo[8].lock();

                    //semaforo[8].lock();
                    //semaforo[7].lock();
                }


                if (x < 530 && y == 320)
                    x += 10;
                else if (x == 530 && y < 440)
                    y += 10;
                else if (y == 440 && x > 300)
                    x -= 10;
                else if (x == 300 && y > 320)
                    y -= 10;
                

                /* ----- unlock's nos semaforos -- */
                if(x == 530 && y == 340){
                    semaforo[8].unlock();
                }
                else if(x == 430 && y == 320){
                    semaforo[7].unlock();
                }

                break;

            default:
                break;
        }
        msleep(velocidade);
    }
    }
}

void Trem::parar_retomar(){
    stop = !stop;
}

void Trem::changeSpeed(int speed){
    velocidade = speed;
}

/*
Trem::~Trem()
{

}
*/
