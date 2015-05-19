#ifndef TREM_H
#define TREM_H

#include <QThread>

class Trem: public QThread{
    Q_OBJECT
    public:
        Trem(int, int, int, int);
        //~Trem();
        void run();
        void parar_retomar();
        void changeSpeed(int);

    signals:
        void updateGUI(int, int, int, int);

    private:
        int x;
        int y;
        int ID;
        int velocidade;
        bool stop;
};

#endif // TREM_H
