#ifndef CHECKMARK_H
#define CHECKMARK_H
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsTextItem>

class GameView;

class CheckMark: public QGraphicsPixmapItem, public QObject
{

public:
    CheckMark(GameView* inGame, QGraphicsTextItem* inCurrText);

private:

    GameView* gameView;
    QGraphicsTextItem* CurrText;
    int rowIndex, colIndex;
    QGraphicsPixmapItem* previousItem;
public slots:
    void keyPressEvent(QKeyEvent * event);
};

#endif // CHECKMARK_H
