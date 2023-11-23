#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ball.h"
#include <QDateTime>
#include <QTime>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void arrowKeyUp(); // Slot for handling the arrow key up event
    void arrowKeyDown(); // Slot for handling the arrow key down event

    void keyPressEvent(QKeyEvent *event); // Override keyPressEvent to handle key events

    void launchBall(); // Slot for launching a ball
    void setCurrentTime(); // Slot for updating the current time label

    void on_button_start_clicked(); // Slot for handling the start button click event


protected:
    void paintEvent(QPaintEvent *event) override; // Override paintEvent to draw objects

private:
    Ui::MainWindow *ui; // Pointer to the UI object
    QList<std::shared_ptr<ball>> ballL; // List of shared pointers to balls
    QTimer *ballTimer; // Timer for launching balls
    QTimer *gameTimer; // Timer for updating the game time
    int score = 0; // Player's score
    int gameSeconds =0; // Current game time in seconds
    int totalGameSeconds = 0; // Total game time in seconds
    QDateTime gameStartTime; // Game start time
    QDateTime gameStopTime; // Game stop time

};

#endif // MAINWINDOW_H
