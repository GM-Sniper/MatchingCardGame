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
    setCardHidden();
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
    QFile File(":/texts/CardsData (2).txt");
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
    QPixmap Image1(":/images/Images/BB8.png");
    Image1 = Image1.scaledToWidth(40);
    Image1 = Image1.scaledToHeight(40);
    QPixmap Image2(":/images/crab.png");
    Image2 = Image2.scaledToWidth(40);
    Image2 = Image2.scaledToHeight(40);

    QPixmap Image3(":/images/Images/Dragon Ball.png");
    Image3 = Image3.scaledToWidth(40);
    Image3 = Image3.scaledToHeight(40);

    QPixmap Image4(":/images/Images/drone.png");
    Image4 = Image4.scaledToWidth(40);
    Image4 = Image4.scaledToHeight(40);

    QPixmap Image5(":/images/Images/flamingo.png");
    Image5 = Image5.scaledToWidth(40);
    Image5 = Image5.scaledToHeight(40);

    QPixmap Image6(":/images/Images/guitar.png");
    Image6 = Image6.scaledToWidth(40);
    Image6 = Image6.scaledToHeight(40);

    QPixmap Image7(":/images/Images/Gem.png");
    Image7 = Image7.scaledToWidth(40);
    Image7 = Image7.scaledToHeight(40);

    QPixmap Image8(":/images/Images/jellyfish.png");
    Image8 = Image8.scaledToWidth(40);
    Image8 = Image8.scaledToHeight(40);

    QPixmap Image9(":/images/Images/kombucha.png");
    Image9 = Image9.scaledToWidth(40);
    Image9 = Image9.scaledToHeight(40);

    QPixmap Image10(":/images/Images/nanotechnology.png");
    Image10 = Image10.scaledToWidth(40);
    Image10 = Image10.scaledToHeight(40);

    QPixmap Image11(":/images/Images/shaved-ice.png");
    Image11 = Image11.scaledToWidth(40);
    Image11 = Image11.scaledToHeight(40);

    QPixmap Image12(":/images/Images/suitcase.png");
    Image12 = Image12.scaledToWidth(40);
    Image12 = Image12.scaledToHeight(40);

    QPixmap Image13(":/images/Images/tea.png");
    Image13 = Image13.scaledToWidth(40);
    Image13 = Image13.scaledToHeight(40);

    QPixmap Image14(":/images/Images/sunset.png");
    Image14 = Image14.scaledToWidth(40);
    Image14 = Image14.scaledToHeight(40);

    QPixmap Image15(":/images/Images/technology (1).png");
    Image15 = Image15.scaledToWidth(40);
    Image15 = Image15.scaledToHeight(40);

    QPixmap Image16(":/images/Images/technology.png");
    Image16 = Image16.scaledToWidth(40);
    Image16 = Image16.scaledToHeight(40);

    QPixmap Image17("qrc:/images/Images/tropical-fish.png");
    Image17 = Image17.scaledToWidth(40);
    Image17 = Image17.scaledToHeight(40);

    QPixmap Image18(":/images/Images/watermelon.png");
    Image18 = Image18.scaledToWidth(40);
    Image18 = Image18.scaledToHeight(40);

    int xPos=100, yPos=50, xAdd=50,yAdd=50, currX=100;
    for(int i=0; i<sRows;i++)
    {
        for (int j=0;j<sCols;j++)
        {
            if (cardsData[i][j] == 1) {
                cardsImages[i][j].setPixmap(Image1);
            } else if (cardsData[i][j] == 2) {
                cardsImages[i][j].setPixmap(Image2);
            } else if (cardsData[i][j] == 3) {
                cardsImages[i][j].setPixmap(Image3);
            } else if (cardsData[i][j] == 4) {
                cardsImages[i][j].setPixmap(Image4);
            } else if (cardsData[i][j] == 5) {
                cardsImages[i][j].setPixmap(Image5);
            } else if (cardsData[i][j] == 6) {
                cardsImages[i][j].setPixmap(Image6);
            } else if (cardsData[i][j] == 7) {
                cardsImages[i][j].setPixmap(Image7);
            } else if (cardsData[i][j] == 8) {
                cardsImages[i][j].setPixmap(Image8);
            } else if (cardsData[i][j] == 9) {
                cardsImages[i][j].setPixmap(Image9);
            } else if (cardsData[i][j] == 10) {
                cardsImages[i][j].setPixmap(Image10);
            } else if (cardsData[i][j] == 11) {
                cardsImages[i][j].setPixmap(Image11);
            } else if (cardsData[i][j] == 12) {
                cardsImages[i][j].setPixmap(Image12);
            } else if (cardsData[i][j] == 13) {
                cardsImages[i][j].setPixmap(Image13);
            } else if (cardsData[i][j] == 14) {
                cardsImages[i][j].setPixmap(Image14);
            } else if (cardsData[i][j] == 15) {
                cardsImages[i][j].setPixmap(Image15);
            } else if (cardsData[i][j] == 16) {
                cardsImages[i][j].setPixmap(Image16);
            } else if (cardsData[i][j] == 17) {
                cardsImages[i][j].setPixmap(Image17);
            } else if (cardsData[i][j] == 18) {
                cardsImages[i][j].setPixmap(Image18);
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

void GameView::setCardHidden()
{
    QPixmap flippedCard(":/images/available.PNG");
    flippedCard = flippedCard.scaledToWidth(42);
    flippedCard = flippedCard.scaledToHeight(42);
    int xPos=100, yPos=50, xAdd=50,yAdd=50, currX=100;
    for(int i=0; i<sRows;i++)
    {
        for (int j=0;j<sCols;j++)
        {
            flippedCards[i][j].setPixmap(flippedCard);
            flippedCards[i][j].setPos(xPos,yPos);
            scene->addItem(&flippedCards[i][j]);
            xPos+=xAdd;

        }
        xPos=currX;
        yPos+=yAdd;
    }
}
