#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "trem.h"
#include "getentry.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void updateInterface(int, int, int, int);
    void updateTrem(int, int, bool);

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    Trem *trem1, *trem2, *trem3, *trem4, *trem5, *trem6;
    getEntry *receberEntrada;
};

#endif // MAINWINDOW_H
