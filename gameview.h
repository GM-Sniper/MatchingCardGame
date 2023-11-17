#ifndef GAMEVIEW_H
#define GAMEVIEW_H
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include "Users.h"
#include "card.h"

class CheckMark;
//class card;
class GameView
{
private:
    QString x;
    int cardsData[sRows][sCols];
    int lastOpenedRowIndex;
    int lastOpenedColIndex;
    QGraphicsPixmapItem flippedCards[sRows][sCols];
    card *Cards[sRows][sCols];
    QGraphicsPixmapItem cardsImages[sRows][sCols];
    QGraphicsTextItem* currCardText;
    QGraphicsTextItem* currScoreText;
    QGraphicsTextItem* WinStatusText;
    //playerName
    QGraphicsTextItem* playerName;


public:
    GameView(QString x);

//    explicit GameView(card (*cards)[6]);


    int checkForMatch(int rowIndex, int colIndex);
    QGraphicsScene* scene;
    QGraphicsView* view;
    void setCardHidden();
    void clearGame();
    void initalizeCard();
    void FlipAllCards();
    CheckMark* checkmark;
    ~GameView()
    {
        for(int i=0; i<sRows;i++)
        {
            for (int j=0; j<sCols;j++)
            {
                delete Cards[i][j];
            }
        }
    }

};

#endif // GAMEVIEW_H
