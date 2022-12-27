#include "gui.h"

GUI::GUI()
{
    mainWindow = new window;

}

void GUI::showGamingWindow()
{
    mainWindow->show();
}

void GUI::setPlayer(Player *player)
{
    mainWindow->setPlayer(player);
}
