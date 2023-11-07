#include "bookingview.h"
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>
#include <QGraphicsTextItem>
#include <QGraphicsPixmapItem>
#include "checkmark.h"

BookingView::BookingView()
{
    scene = new QGraphicsScene;
    view= new QGraphicsView;
    view->setFixedSize(480, 500);
    scene->setSceneRect(0, 0, 480, 500);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setScene(scene);
    view->show();
    readDataSeats();
    setSeatsImages();
    currSeatText =new QGraphicsTextItem;
    currSeatText->setFont(QFont("times", 16));
    currSeatText->setDefaultTextColor(Qt::blue);
    currSeatText->setPos(20, 400);
    scene->addItem(currSeatText);

    checkmark=new CheckMark(this,currSeatText);
    checkmark->setPos(50,50);
    checkmark->setFlag(QGraphicsItem::ItemIsFocusable);
    checkmark->setFocus();
    scene->addItem(checkmark);



}

void BookingView::setSeatData(int RowIndex, int ColIndex, int data)
{
    seatsData[RowIndex][ColIndex]=data;
    if (data == 0)
    {
        QPixmap availablePixmap(":/images/available.PNG");
        availablePixmap = availablePixmap.scaledToWidth(40);
        availablePixmap = availablePixmap.scaledToHeight(40);
        seatsImages[RowIndex][ColIndex].setPixmap(availablePixmap);
    }
    else
    {
        QPixmap bookedPixmap(":/images/booked.PNG");
        bookedPixmap = bookedPixmap.scaledToWidth(40);
        bookedPixmap = bookedPixmap.scaledToHeight(40);
        seatsImages[RowIndex][ColIndex].setPixmap(bookedPixmap);
    }

}

void BookingView::readDataSeats()
{
    QFile File(":/texts/seatsData.txt");
    File.open(QIODevice::ReadOnly);
    QTextStream stream(&File);

    QString input;
    for(int i=0; i<sRows;i++)
    {
        for (int j=0;j<sCols;j++)
        {   stream>>input;
            seatsData[i][j]=input.toInt();
        }
    }
    File.close();
}
void BookingView::setSeatsImages()
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
            if(seatsData[i][j]==0)
            {
                seatsImages[i][j].setPixmap(pixmap1);

            }
            else
            {
                 seatsImages[i][j].setPixmap(pixmap2);
            }
            seatsImages[i][j].setPos(xPos,yPos);
            scene->addItem(&seatsImages[i][j]);
            xPos+=xAdd;

        }
        xPos=currX;
        yPos+=yAdd;
    }

}
int BookingView::checkSeatData(int RowIndex, int ColIndex)
{
    return seatsData[RowIndex][ColIndex];
}
void BookingView:: writeSeatsData()
{
    QFile File("C:/College Work/AUC Study Work/CS2/Lab Work/Cinema Project/CinemaProjectG1/seatsData.txt");
    File.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream stream(&File);

    for(int i=0; i<sRows;i++)
    {
        for (int j=0;j<sCols;j++)
        {
            stream<<QString::number(seatsData[i][j]);
        }
        stream<<"\n";
    }
    File.close();

}
