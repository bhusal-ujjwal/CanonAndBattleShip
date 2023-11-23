#include "ball.h"

ball::ball(QWidget *parent): parent(parent)
{
    // Initialize ball properties
    QRect rct = parent->rect();
    x = rct.width();
    y = rand() % rct.height();

    dx = rand() % 10;
    dy = rand() % 10;

    start(10); // Start the timer with a 10ms interval
}


void ball::draw(QPainter *painter)
{
    // Draw the ball as an ellipse
    painter->drawEllipse(x,y,20,20);
}

void ball::timerEvent(QTimerEvent *e)
{
    QRect rct = parent->rect();

    if( rct.width() ) dx = -7; // Change the direction of horizontal movement
    if(y > rct.height() || y < 0) dy *= -1; // Change the direction of vertical movement when the ball hits the top or bottom of the window

    x += dx; // Update the x-coordinate of the ball
    y += dy; // Update the y-coordinate of the ball

    parent->update(); // Update the parent widget to trigger a paint event
}
