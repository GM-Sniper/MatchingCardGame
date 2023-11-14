#ifndef CHECKMARK_H
#define CHECKMARK_H
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsTextItem>

class GameView;

class CheckMark: public QGraphicsPixmapItem, public QObject
{

public:
    CheckMark(GameView* inGame, QGraphicsTextItem* inCurrText, QGraphicsTextItem* currScoreText, QGraphicsTextItem* inStatusText);
    // Helper function to check if the game is over (either win or lose)


private:

    GameView* gameView;
    QGraphicsTextItem* CurrText;
    QGraphicsTextItem* currScoreText;
    QGraphicsTextItem* statusText;

    int rowIndex, colIndex;
    QGraphicsPixmapItem* previousItem;
    QGraphicsPixmapItem* pointerRead;
    int openingCounter;
    int score;
public slots:
    void keyPressEvent(QKeyEvent * event);
};

#endif // CHECKMARK_H
