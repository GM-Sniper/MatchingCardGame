#ifndef CHECKMARK_H
#define CHECKMARK_H
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsTextItem>

class BookingView;

class CheckMark: public QGraphicsPixmapItem, public QObject
{

public:
    CheckMark(BookingView* inBooking, QGraphicsTextItem* inCurrText);

private:

    BookingView* bookingview;
    QGraphicsTextItem* CurrText;
    int rowIndex, colIndex;
    QGraphicsPixmapItem* previousItem;
public slots:
    void keyPressEvent(QKeyEvent * event);
};

#endif // CHECKMARK_H
