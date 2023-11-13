#include "checkmark.h"
#include "gameview.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QList>
#include <QGraphicsItem>
#include <QGraphicsView>
#include "card.h"
#include "Users.h"

CheckMark::CheckMark(GameView* inGame, QGraphicsTextItem* inCurrText)
{
    QPixmap clicker(":/images/checkmark.png");
    clicker = clicker.scaledToWidth(40);
    clicker = clicker.scaledToHeight(40);
    setPixmap(clicker);
    rowIndex=0;
    colIndex=-1;
    previousItem=nullptr;
    gameView=inGame;
    CurrText=inCurrText;
    setZValue(1);

}
void CheckMark::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left)
    {   if(x()>100)
        { setPos(x()-50, y());
            colIndex--;}
    }
    else if (event->key() == Qt::Key_Right)
    {   if(x()<350)
        {setPos(x()+50, y());
            colIndex++;}
    }
    else if (event->key() == Qt::Key_Up)
    {   if(y()>50)
        {setPos(x(), y()-50);
            rowIndex--;}
    }
    else if (event->key() == Qt::Key_Down)
    {   if(y()<300)
        {setPos(x(), y()+50);
        rowIndex++;}
    }
    else if(event->key() == Qt::Key_Space)
    {

        // Check for a match
        gameView->checkForMatch(rowIndex, colIndex);
        previousItem=nullptr;

//        gameView->setCardHidden();

    }
    else if(event->key() == Qt::Key_S)
    {
        gameView->FlipAllCards();
        previousItem=nullptr;

    }


    QList<QGraphicsItem*> colliding_items = collidingItems();

//    for(int i = 0; i < colliding_items.size(); i++)
//    {
//
//        scene()->removeItem(colliding_items[i]);
//
//        CurrText->setDefaultTextColor(Qt::blue);
//        CurrText->setPlainText("Card: " + cardRowNames[rowIndex]+QString::number(colIndex+1));
//
//    }
//    if(colliding_items.size()>0)
//        {
//            if(previousItem!=nullptr)
//            {   //previousItem=(QGraphicsPixmapItem*)colliding_items[0];
//                gameView->scene->addItem(previousItem);
//                //gameView->scene->addItem(previousCard);
//            }
//            previousItem=(QGraphicsPixmapItem*)colliding_items[0];
//            //previousCard=(QGraphicsPixmapItem*)colliding_items[1];
//        }

}
