#include "window.h"
#include "ui_window.h"

window::window(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::window)
{
    ui->setupUi(this);

    this->resize(650, 650);          /// Задаем размеры виджета, то есть окна
    this->setFixedSize(650, 650);    /// Фиксируем размеры виджета

    scene = new QGraphicsScene();   /// Инициализируем графическую сцену
    player1 = new Player();         /// Инициализируем игрока

    // инициализируем область графики и устанавливаем в нее сцену
    graphicsArea = new graphicsView(this, scene);
    ui->playerWindowLayout->addWidget(graphicsArea);

    scene->addItem(player1);   /// Добавляем на сцену игрока
    player1->setPos(-30, -50);      /// Устанавливаем игрока в центр сцены

    connect(
            graphicsArea, SIGNAL(movePlayer(int, int)),
            player1,      SLOT(move(int, int))
            );
}

window::~window()
{
    delete ui;
}
