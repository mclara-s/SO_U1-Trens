#include "trem.h"
#include <QtCore>

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
        emit updateGUI(ID, x, y);
        switch(ID){
        case 1:
            if (x < 300 && y == 80)
                x += 10;
            else if (x == 300 && y < 200)
                y += 10;
            else if (y == 200 && x > 70)
                x -= 10;
            else if (x == 70 && y > 80)
                y -= 10;
                break;
        case 2:
           if (x < 530 && y == 80)
              x += 10;
          else if (x == 530 && y < 200)
              y += 10;
          else if (y == 200 && x > 300)
              x -= 10;
          else if (x == 300 && y > 80)
              y -= 10;
            break;

        case 3:
           if (x < 760 && y == 80)
              x += 10;
          else if (x == 760 && y < 200)
              y += 10;
          else if (y == 200 && x > 530)
              x -= 10;
          else if (x == 530 && y > 80)
              y -= 10;
            break;

        case 4:
           if (x < 410 && y == 200)
              x += 10;
          else if (x == 410 && y < 320)
              y += 10;
          else if (y == 320 && x > 180)
              x -= 10;
          else if (x == 180 && y > 200)
              y -= 10;
            break;

        case 5:
           if (x < 640 && y == 200)
              x += 10;
          else if (x == 640 && y < 320)
              y += 10;
          else if (y == 320 && x > 410)
              x -= 10;
          else if (x == 410 && y > 200)
              y -= 10;
            break;

        case 6:
           if (x < 530 && y == 320)
              x += 10;
          else if (x == 530 && y < 440)
              y += 10;
          else if (y == 440 && x > 300)
              x -= 10;
          else if (x == 300 && y > 320)
              y -= 10;
            break;
        default:
            break;
        }
        msleep(velocidade);
    }
}

void Trem::finalizar(){
    stop = true;
}

/*
Trem::~Trem()
{

}
*/
