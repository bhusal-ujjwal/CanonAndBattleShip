#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QKeyEvent>
#include <QDateTime>

ball *b;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    ui->label_score->setText("Score: 0");

    this->setFocusPolicy(Qt::StrongFocus);
    gameTimer = new QTimer(this);
    connect(gameTimer, &QTimer::timeout, this, &MainWindow::setCurrentTime);
}

void MainWindow::setCurrentTime()
{
    totalGameSeconds++;
    QTime gameTime(0, 0);
    gameTime = gameTime.addSecs(totalGameSeconds);
    ui->label_timer->setText(QString("Game Time: %1").arg(gameTime.toString("mm:ss")));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    painter.fillRect(rect(), QBrush(QColor(Qt::white)));
    painter.setPen(Qt::black);
    painter.setBrush(QBrush(QColor(Qt::green)));

    for(auto sp:ballL){
        sp->draw(&painter);

        if(sp->x == 2){

            if(sp->y >= ui->button_paddle->pos().y() && sp->y <= ui->button_paddle->pos().y() + ui->button_paddle->height()){
                ballL.removeFirst();
                update();
                ballTimer->stop();
                gameTimer->stop();
                gameStopTime = QDateTime::currentDateTime(); // stop the game timer
                int gameDuration = gameStartTime.secsTo(gameStopTime);
                int score = gameDuration;
                ui->label_score->setText(QString("Game Over !!!! You got hit. Score: %1s").arg(score));
                ui->label_timer->setText("Game Over !!!! You got hit");
            } else {
                ballL.removeFirst();
                update();
                int score = gameStartTime.secsTo(QDateTime::currentDateTime());
                ui->label_score->setText(QString("You dodged the ball! Score: %1s").arg(score));
            }
        }
    }
}


void MainWindow::arrowKeyUp()
{

    int a =  ui->button_paddle->pos().y();//10;
    ui->button_paddle->move(0,a+10);

}

void MainWindow::launchBall()
{
    ballL.append(std::shared_ptr<ball> (new ball(this)));
}


void MainWindow::arrowKeyDown()
{
    int a =  ui->button_paddle->pos().y();
    ui->button_paddle->move(0,a-10);


}


void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Up) {
        arrowKeyDown(); // call the moveButton function when the up arrow key is pressed
    } else if(event->key() == Qt::Key_Down){
        arrowKeyUp();
    }else{
        QMainWindow::keyPressEvent(event);
    }
}


void MainWindow::on_button_start_clicked()
{
    ballTimer = new QTimer(this);
    connect(ballTimer, &QTimer::timeout, this, &MainWindow::launchBall);
    ballTimer->start(1200);

    if (gameTimer->isActive()) { // check if game timer is already running
        return;
    }

    if (gameStopTime.isValid()) { // check if game has been played before
        int gameDuration = gameStartTime.secsTo(gameStopTime);
        totalGameSeconds += gameDuration;
    }
    gameStartTime = QDateTime::currentDateTime(); // start the game timer
    gameStopTime = QDateTime(); // reset the game stop time
    gameTimer->start(1000);
    ui->label_timer->setText(QString("Game Time: %1s").arg(gameSeconds));
    ui->label_score->setText(QString("Game started!"));
}
