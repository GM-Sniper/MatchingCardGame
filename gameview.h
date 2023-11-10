#ifndef GAMEVIEW_H
#define GAMEVIEW_H
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include "Users.h"
class CheckMark;
class card;
class GameView
{
private:
    int cardsData[sRows][sCols];
    QGraphicsPixmapItem flippedCards[sRows][sCols];
    QGraphicsPixmapItem cardsImages[sRows][sCols];
    QGraphicsTextItem* currCardText;

public:
    GameView();
    int checkCardData(int RowIndex, int ColIndex);
    void setCardData(int RowIndex, int ColIndex, int data);
    void readDataCards();
    void setCardsImages();
    void writeCardsData();
    void setCardHidden();
    QGraphicsScene* scene;
    QGraphicsView* view;
    CheckMark* checkmark;


};

#endif // GAMEVIEW_H
