#ifndef GAMEVIEW_H
#define GAMEVIEW_H
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include "Users.h"
class CheckMark;

class GameView
{
private:
    int seatsData[sRows][sCols];
    QGraphicsPixmapItem seatsImages[sRows][sCols];
    QGraphicsTextItem* currSeatText;

public:
    GameView();
    int checkSeatData(int RowIndex, int ColIndex);
    void setSeatData(int RowIndex, int ColIndex, int data);
    void readDataSeats();
    void setSeatsImages();
    void writeSeatsData();
    QGraphicsScene* scene;
    QGraphicsView* view;
    CheckMark* checkmark;


};

#endif // GAMEVIEW_H
