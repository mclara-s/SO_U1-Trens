#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    int id;
    int velocidade;
    bool stop;

    void send();

private slots:
    void on_pushButton_4_pressed();

    void on_pushButton_2_pressed();

    void on_dial_valueChanged(int value);

    void on_pushButton_pressed();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
