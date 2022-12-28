#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsScene>

#include <Windows.h>

#include <QTimer>

// класс игроков
class Player : public QObject, public QGraphicsItem
{
    Q_OBJECT
signals:

public slots:
    void move(int x, int y); // Слот, который отвечает за обработку перемещения Игрока

    virtual void Q() = 0;
    virtual void W() = 0;
    virtual void E() = 0;
    virtual void R() = 0;

public:
    explicit Player(QObject *parent = nullptr);

    // взять информацию об здоровье и мане
    void getHP(int& value, int& max);
    void getMana(int& value, int& max);

    QVector <QPixmap*>* getPixAbilites();
    QPixmap* getPixFace();

    static QPixmap* getPixMap(const QString& nameImageJPG);

protected:
    // состояния игрока
    enum conditions{moving, attacking};
    int condition;

    void setPixAbilites(const QStringList& nameFiles);
    void setPixFace(const QString& nameFile);

private slots:
    void tactSpin(); // повернуть на один тик
    void tactRun();

    void regain();

private:
    // здоровье и мана игрока
    int maxHP = 1020;
    double HP = 0;
    double regainHP = 1.4;

    int maxMana = 400;
    double mana = 0;
    double regainMana = 0.8;

    QTimer* regainTimer;

    void spin(double angleA, double angleB);
    QTimer* timerSpin;
    bool vector;

    qreal angle;    // Угол поворота графического объекта
    double newAngle;

    double speedRun;   // Скорость передвижения игрока
    QTimer* timerRun;

    double speedSpin;  // Скорость поворота игрока

    // координаты, в которые идет игрок
    int newX;
    int newY;

    // картинки способностей
    QVector <QPixmap*>* pixAbilites;

    // картинка аватара
    QPixmap* pixFace;

};

#endif // PLAYER_H
