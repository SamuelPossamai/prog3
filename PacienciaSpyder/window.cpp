
#include "window.h"
#include "ui_window.h"

#include <iostream>

GameWindow::GameWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Window),
    ok_button(nullptr),
    label(nullptr)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);

    ui->graphicsView->setScene(scene);

    ui->graphicsView->setSceneRect(this->frameGeometry());
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff );

    game = new OneSuitGame("player", scene);

    game->setEventHandler(this);

    restart_button = new QPushButton("SURRENDER", this);

    //restart_button->setStyleSheet("color: black; background-color: red;");

    restart_button->setGeometry(0, 470, 80, 30);

    restart_button->show();

    QObject::connect(restart_button, SIGNAL (clicked()), this, SLOT (__restart_button_pressed__()));

    ok_button = new QPushButton("ok", this);

    ok_button->setGeometry(335, 230, 30, 30);

    ok_button->hide();

    QObject::connect(ok_button, SIGNAL (clicked()), this, SLOT (__ok_button_pressed__()));

    label = new QLabel("You Won", this);

    label->setGeometry(325, 200, 60, 30);

    label->hide();
}

GameWindow::~GameWindow()
{
    delete ui;

    if(game != nullptr) delete game;
}

void GameWindow::gameover_event(bool won){

    if(won == false) return;

    ok_button->show();
    label->show();

    restart_button->hide();
}

void GameWindow::__ok_button_pressed__(){

    delete game;

    game = new OneSuitGame("player", scene);

    game->setEventHandler(this);

    ok_button->hide();
    label->hide();

    restart_button->show();
}

void GameWindow::__restart_button_pressed__(){

    if(game != nullptr) delete game;

    game = new OneSuitGame("player", scene);

    game->setEventHandler(this);
}




