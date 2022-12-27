#include "window.h"
#include "ui_window.h"

#include <QDebug>

window::window(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::window)
{
    ui->setupUi(this);

    this->resize(650, 650);          /// Задаем размеры виджета, то есть окна
    //this->setFixedSize(650, 650);    /// Фиксируем размеры виджета

    setStyleBars();

    scene = new QGraphicsScene();   /// Инициализируем графическую сцену

    // инициализируем область графики и устанавливаем в нее сцену
    graphicsArea = new graphicsView(this, scene);
    ui->playerWindowLayout->addWidget(graphicsArea);

    updateTimer = new QTimer;
    connect(
            updateTimer, SIGNAL(timeout()),
            this,        SLOT(updateInfoPlayer())
            );
}

void window::setPlayer(Player* player_)
{
    player = player_;

    scene->addItem(player);        /// Добавляем на сцену игрока
    player->setPos(-30, -50);      /// Устанавливаем игрока в центр сцены

    // передается новые координаты относительно графической сцены
    connect(
            graphicsArea, SIGNAL(movePlayer(int, int)),
            player,       SLOT(move(int, int))
            );

    updateTimer->start(50);
}

void window::updateInfoPlayer()
{
    int value, maxValue;

    player->getHP(value, maxValue);
    ui->HPbar->setMaximum(maxValue);
    ui->HPbar->setValue(value);
    ui->HPLabel->setText(QString::number(value) + "/" + QString::number(maxValue));

    player->getMana(value, maxValue);
    ui->manaBar->setMaximum(maxValue);
    ui->manaBar->setValue(value);
    ui->manaLabel->setText(QString::number(value) + "/" + QString::number(maxValue));
}

void window::setStyleBars()
{
    ui->HPbar->setStyleSheet(
                "QProgressBar {"
                "border: 3px solid grey;"
                "border-radius: 5px;"
                "background-color: rgb(230,230,230);"
                "text-align:center;"
                "color:rgb(0,150,0);"
                "}"

                "QProgressBar::chunk {"
                "background-color: rgb(0,255,0);"
                "}"
                             );

    ui->manaBar->setStyleSheet(
                "QProgressBar {"
                "border: 3px solid grey;"
                "border-radius: 5px;"
                "background-color: rgb(230,230,230);"
                "text-align:center;"
                "color:rgb(0,0,150);"
                "}"

                "QProgressBar::chunk {"
                "background-color: rgb(0,0,255);"
                "}"
                             );
}

window::~window()
{
    delete ui;
}
