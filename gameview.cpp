#include "gameview.h"
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>
#include <QGraphicsTextItem>
#include <QGraphicsPixmapItem>
#include "checkmark.h"

GameView::GameView()
{
    scene = new QGraphicsScene;
    view= new QGraphicsView;
    view->setFixedSize(480, 500);
    scene->setSceneRect(0, 0, 480, 500);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setScene(scene);
    view->show();
    readDataCards();
    setCardsImages();
    currCardText =new QGraphicsTextItem;
    currCardText->setFont(QFont("times", 16));
    currCardText->setDefaultTextColor(Qt::blue);
    currCardText->setPos(20, 400);
    scene->addItem(currCardText);

    checkmark=new CheckMark(this,currCardText);
    checkmark->setPos(50,50);
    checkmark->setFlag(QGraphicsItem::ItemIsFocusable);
    checkmark->setFocus();
    scene->addItem(checkmark);



}

void GameView::setCardData(int RowIndex, int ColIndex, int data)
{
    cardsData[RowIndex][ColIndex]=data;
    if (data == 0)
    {
        QPixmap availablePixmap(":/images/available.PNG");
        availablePixmap = availablePixmap.scaledToWidth(40);
        availablePixmap = availablePixmap.scaledToHeight(40);
        cardsImages[RowIndex][ColIndex].setPixmap(availablePixmap);
    }
    else
    {
        QPixmap bookedPixmap(":/images/booked.PNG");
        bookedPixmap = bookedPixmap.scaledToWidth(40);
        bookedPixmap = bookedPixmap.scaledToHeight(40);
        cardsImages[RowIndex][ColIndex].setPixmap(bookedPixmap);
    }

}

void GameView::readDataCards()
{
    QFile File(":/texts/cardsData.txt");
    File.open(QIODevice::ReadOnly);
    QTextStream stream(&File);

    QString input;
    for(int i=0; i<sRows;i++)
    {
        for (int j=0;j<sCols;j++)
        {   stream>>input;
            cardsData[i][j]=input.toInt();
        }
    }
    File.close();
}
void GameView::setCardsImages()
{
    QPixmap pixmap1(":/images/available.PNG");
    pixmap1 = pixmap1.scaledToWidth(40);
    pixmap1 = pixmap1.scaledToHeight(40);
    QPixmap pixmap2(":/images/booked.PNG");
    pixmap2 = pixmap2.scaledToWidth(40);
    pixmap2 = pixmap2.scaledToHeight(40);

    int xPos=100, yPos=50, xAdd=50,yAdd=50, currX=100;
    for(int i=0; i<sRows;i++)
    {
        for (int j=0;j<sCols;j++)
        {
            if(cardsData[i][j]==0)
            {
                cardsImages[i][j].setPixmap(pixmap1);

            }
            else
            {
                 cardsImages[i][j].setPixmap(pixmap2);
            }
            cardsImages[i][j].setPos(xPos,yPos);
            scene->addItem(&cardsImages[i][j]);
            xPos+=xAdd;

        }
        xPos=currX;
        yPos+=yAdd;
    }

}
int GameView::checkCardData(int RowIndex, int ColIndex)
{
    return cardsData[RowIndex][ColIndex];
}
void GameView:: writeCardsData()
{
    QFile File("C:/College Work/AUC Study Work/CS2/Lab Work/Cinema Project/CinemaProjectG1/cardsData.txt");
    File.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream stream(&File);

    for(int i=0; i<sRows;i++)
    {
        for (int j=0;j<sCols;j++)
        {
            stream<<QString::number(cardsData[i][j]);
        }
        stream<<"\n";
    }
    File.close();

}
