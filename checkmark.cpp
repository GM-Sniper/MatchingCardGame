#include "checkmark.h"
#include "bookingview.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QList>
#include <QGraphicsItem>
#include <QGraphicsView>
#include "Users.h"

CheckMark::CheckMark(BookingView* inBooking, QGraphicsTextItem* inCurrText)
{
    QPixmap checkmark1(":/images/checkmark.png");
    checkmark1 = checkmark1.scaledToWidth(40);
    checkmark1 = checkmark1.scaledToHeight(40);
    setPixmap(checkmark1);
    rowIndex=0;
    colIndex=-1;
    previousItem=nullptr;
    bookingview=inBooking;
    CurrText=inCurrText;
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
        if(bookingview->checkSeatData(rowIndex,colIndex)==0)
        {
            bookingview->setSeatData(rowIndex,colIndex,1);
            CurrText->setDefaultTextColor(Qt::green);
            CurrText->setPlainText("This Seat has been Booked sucessfully");
            bookingview->writeSeatsData();
        }
        else
        {
            CurrText->setDefaultTextColor(Qt::red);
            CurrText->setPlainText("This Seat is already Booked");
        }
    }


    QList<QGraphicsItem*> colliding_items = collidingItems();

    for(int i = 0; i < colliding_items.size(); i++)
    {

        scene()->removeItem(colliding_items[i]);

        CurrText->setDefaultTextColor(Qt::blue);
        CurrText->setPlainText("Seat: " + seatRowNames[rowIndex]+QString::number(colIndex+1));

    }
    if(colliding_items.size()>0)
        {
            if(previousItem!=nullptr)
            {   //previousItem=(QGraphicsPixmapItem*)colliding_items[0];
                bookingview->scene->addItem(previousItem);
            }
            previousItem=(QGraphicsPixmapItem*)colliding_items[0];
        }

}
