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
    int cardsData[sRows][sCols];
    int lastOpenedRowIndex;
    int lastOpenedColIndex;
    QGraphicsPixmapItem flippedCards[sRows][sCols];
    card *Cards[sRows][sCols];
    QGraphicsPixmapItem cardsImages[sRows][sCols];
    QGraphicsTextItem* currCardText;

public:
    GameView();

//    explicit GameView(card (*cards)[6]);

    int checkCardData(int RowIndex, int ColIndex);
    void readDataCards();
    void checkForMatch(int rowIndex,int colIndex);
    void setCardsImages();
    QGraphicsScene* scene;
    QGraphicsView* view;
    void setCardHidden();
    void initalizeCard();
    void changeCardState(int rowIndex, int colIndex);
    card* ReadCardState(int rowIndex, int colIndex);
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
