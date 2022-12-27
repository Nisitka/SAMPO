#ifndef GUI_H
#define GUI_H

#include <QObject>

#include "window.h"

class GUI : public QObject
{

public:
    GUI();

    void showGamingWindow();

    void setPlayer(Player* player);

private:
    window* mainWindow;
};

#endif // GUI_H
