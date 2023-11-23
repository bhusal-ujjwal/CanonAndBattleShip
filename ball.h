#ifndef BALL_H
#define BALL_H

#include<QTimer>
#include <QWidget>
#include <QPainter>

class ball: public QTimer // Ball class derived from QTimer
{
public:
    ball(QWidget *parent); // Constructor with a QWidget parent parameter
    void draw(QPainter *painter); // Method for drawing objects (circles)

    // Override the timer event method to customize the behavior
public:
    virtual void timerEvent(QTimerEvent *e)override;

    int x; // x-coordinate of the ball
    int y; // y-coordinate of the ball

    int dx; // Direction of horizontal movement
    int dy; // Direction of vertical movement

    QWidget *parent; // Pointer to the parent widget for accessing its properties
};

#endif // BALL_H
