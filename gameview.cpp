#include "gameview.h"
#include <QString>
#include <QFile>
#include <QTimer>
#include <QTextStream>
#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>
#include <QGraphicsTextItem>
#include <QGraphicsPixmapItem>
#include "card.h"
#include "checkmark.h"

GameView::GameView() :lastOpenedRowIndex(-1),lastOpenedColIndex(-1) {
    scene = new QGraphicsScene;
    view = new QGraphicsView;
    view->setFixedSize(480, 500);
    scene->setSceneRect(0, 0, 480, 500);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setScene(scene);
    view->show();
//        readDataCards();
    initalizeCard();
//    setCardsImages();  // Uncomment this line
    setCardHidden();
    currCardText = new QGraphicsTextItem;
    currCardText->setFont(QFont("times", 16));
    currCardText->setDefaultTextColor(Qt::blue);
    currCardText->setPos(20, 400);
    scene->addItem(currCardText);

    currScoreText = new QGraphicsTextItem;
    currScoreText->setFont(QFont("times", 16));
    currScoreText->setDefaultTextColor(Qt::red);
    currScoreText->setPos(300, 400);
    scene->addItem(currScoreText);

    QGraphicsTextItem* WinStatusText = new QGraphicsTextItem;
    WinStatusText->setFont(QFont("times", 16));
//    statusText->setDefaultTextColor(Qt::green);
    WinStatusText->setPos(240, 250);
    scene->addItem(WinStatusText);

    checkmark = new CheckMark(this, currCardText,currScoreText,WinStatusText);
    checkmark->setPos(50, 50);
    checkmark->setFlag(QGraphicsItem::ItemIsFocusable);
    checkmark->setFocus();
    scene->addItem(checkmark);
}

void GameView::initalizeCard() {
    // Use a vector to store cards
    std::vector <card*> allCards;

    // Create pairs of cards with the same image
    for (int i = 0; i < 18; i++) {
        QString imagePath = ":/images/Images/image" + QString::number(i + 1) + ".png";
        card *newCard1 = new card(i, imagePath);
        card *newCard2 = new card(i, imagePath);

        allCards.push_back(newCard1);
        allCards.push_back(newCard2);
    }

    // Shuffle the vector to randomize card positions
    std::random_shuffle(allCards.begin(), allCards.end());

    // Assign cards to the grid
    int index = 0;
    int xPos = 100, yPos = 50, xAdd = 50, yAdd = 50, currX = 100;

    for (int i = 0; i < sRows; i++) {
        for (int j = 0; j < sCols; j++) {
            Cards[i][j] = allCards[index++];
            Cards[i][j]->setState(false);
            cardsImages[i][j].setPixmap(Cards[i][j]->getPixmap());
            cardsImages[i][j].setPos(xPos, yPos);
//            qDebug() << "Card [" << i << "][" << j << "] initialized with ID: " << Cards[i][j]->getId();

            scene->addItem(&cardsImages[i][j]);
            xPos += xAdd;
        }
        xPos = currX;
        yPos += yAdd;
    }
}


void GameView::setCardHidden() {
    int xPos = 100, yPos = 50, xAdd = 50, yAdd = 50, currX = 100;

    for (int i = 0; i < sRows; i++) {
        for (int j = 0; j < sCols; j++) {
            QPixmap flippedCard(":/images/available.PNG");
            flippedCard = flippedCard.scaledToWidth(45);
            flippedCard = flippedCard.scaledToHeight(45);
//            Cards[i][j]->setState(false);
            flippedCards[i][j].setPixmap(flippedCard);
            flippedCards[i][j].setPos(xPos, yPos);
            scene->addItem(&flippedCards[i][j]);
            scene->removeItem(&cardsImages[i][j]);

            xPos += xAdd;
        }

        xPos = currX;
        yPos += yAdd;
    }
}

void GameView::FlipAllCards() {
    // Temporarily show flipped cards
    int xPos = 100, yPos = 50, xAdd = 50, yAdd = 50, currX = 100;

    for (int i = 0; i < sRows; i++) {
        for (int j = 0; j < sCols; j++) {
            if (!Cards[i][j]->getState()){
                scene->addItem(&cardsImages[i][j]);
                scene->removeItem(&flippedCards[i][j]);

//                if (!scene->items().contains(&cardsImages[i][j])) {
//                    scene->addItem(&cardsImages[i][j]);
//                }
//                if (scene->items().contains(&flippedCards[i][j]) && flippedCards) {
//                    scene->removeItem(&flippedCards[i][j]);
//                }
            }
            qDebug() << "Card [" << i << "][" << j << "] initialized with State: " << Cards[i][j]->getState();
//            if (Cards[i][j]->getState() == card::NotFlipped) {
//                if (!scene->items().contains(&cardsImages[i][j])) {
//                    scene->addItem(&cardsImages[i][j]);
//                }
//                if (scene->items().contains(&flippedCards[i][j])) {
//                    scene->removeItem(&flippedCards[i][j]);
//                }
//            } else {
//                if (!scene->items().contains(&flippedCards[i][j])) {
//                    scene->addItem(&flippedCards[i][j]);
//                }
//                if (scene->items().contains(&cardsImages[i][j])) {
//                    scene->removeItem(&cardsImages[i][j]);
//                }
//            }

            xPos += xAdd;
        }

        xPos = currX;
        yPos += yAdd;
    }

    xPos = 100, yPos = 50;

    // Wait for a short duration (e.g., 1 second)
    QTimer::singleShot(1000, [this, xPos, yPos]() {
        // After waiting, flip the cards back
        for (int i = 0; i < sRows; i++) {
            for (int j = 0; j < sCols; j++) {
//                if (!scene->items().contains(&flippedCards[i][j])) {
//                    scene->addItem(&flippedCards[i][j]);
//                }
//                if (scene->items().contains(&cardsImages[i][j])) {
//                    scene->removeItem(&cardsImages[i][j]);
//                }

                if (Cards[i][j]->getState() == false) {
                    if (!scene->items().contains(&flippedCards[i][j])) {
                        scene->addItem(&flippedCards[i][j]);
                    }
                    if (scene->items().contains(&cardsImages[i][j])) {
                        scene->removeItem(&cardsImages[i][j]);
                    }
                }

            }
        }
    });
}


bool GameView::checkForMatch(int rowIndex, int colIndex) {
    qDebug() << "Card [" << rowIndex << "][" << colIndex << "] initialized with ID: " << Cards[rowIndex][colIndex]->getId();
    if (!(lastOpenedRowIndex == rowIndex && lastOpenedColIndex == colIndex) && !Cards[rowIndex][colIndex]->isMatched() && !Cards[lastOpenedRowIndex][lastOpenedColIndex]->isMatched()) {
        if (lastOpenedRowIndex != -1 && lastOpenedColIndex != -1 && rowIndex != -1 && colIndex != -1) {
            qDebug() << "Card Match = "
                     << (*Cards[lastOpenedRowIndex][lastOpenedColIndex] == *Cards[rowIndex][colIndex]);

            if (*Cards[lastOpenedRowIndex][lastOpenedColIndex] == *Cards[rowIndex][colIndex]) {
                Cards[lastOpenedRowIndex][lastOpenedColIndex]->flip();
                Cards[rowIndex][colIndex]->flip();
                // Matching condition
                // Flip both cards and set state after a delay
                if (!scene->items().contains(&cardsImages[rowIndex][colIndex])) {
                    scene->addItem(&cardsImages[rowIndex][colIndex]);
                }
                if (scene->items().contains(&flippedCards[rowIndex][colIndex])) {
                    scene->removeItem(&flippedCards[rowIndex][colIndex]);
                }
                QTimer::singleShot(1000, [this, rowIndex, colIndex]() {

                    if (scene->items().contains(&cardsImages[rowIndex][colIndex])) {
                        scene->removeItem(&cardsImages[rowIndex][colIndex]);
                    }
                    if (!scene->items().contains(&flippedCards[rowIndex][colIndex])) {
                        scene->removeItem(&flippedCards[rowIndex][colIndex]);
                    }
                    if (!scene->items().contains(&flippedCards[lastOpenedRowIndex][lastOpenedColIndex])) {
                        scene->removeItem(&flippedCards[lastOpenedRowIndex][lastOpenedColIndex]);
                    }
                    if (scene->items().contains(&cardsImages[lastOpenedRowIndex][lastOpenedColIndex])) {
                        scene->removeItem(&cardsImages[lastOpenedRowIndex][lastOpenedColIndex]);
                    }

//                 Set state for both matching cards
                    Cards[lastOpenedRowIndex][lastOpenedColIndex]->setState(true);
                    Cards[rowIndex][colIndex]->setState(true);
                    Cards[lastOpenedRowIndex][lastOpenedColIndex]->setMatched(true);
                    Cards[rowIndex][colIndex]->setMatched(true);


                    // Reset the last opened indices
                    lastOpenedRowIndex = -1;
                    lastOpenedColIndex = -1;
                });
                return true;
            } else {
                // No match
                // Flip both cards back after a delay
                if (!scene->items().contains(&cardsImages[rowIndex][colIndex])) {
                    scene->addItem(&cardsImages[rowIndex][colIndex]);
                }
                if (scene->items().contains(&flippedCards[rowIndex][colIndex])) {
                    scene->removeItem(&flippedCards[rowIndex][colIndex]);
                }
//            Cards[lastOpenedRowIndex][lastOpenedColIndex]->flip();
                QTimer::singleShot(1000, [this, rowIndex, colIndex]() {
//                Cards[lastOpenedRowIndex][lastOpenedColIndex]->flip();
                    Cards[rowIndex][colIndex]->flip();
                    if (!scene->items().contains(&flippedCards[lastOpenedRowIndex][lastOpenedColIndex])) {
                        scene->addItem(&flippedCards[lastOpenedRowIndex][lastOpenedColIndex]);
                    }
                    if (scene->items().contains(&cardsImages[lastOpenedRowIndex][lastOpenedColIndex])) {
                        scene->removeItem(&cardsImages[lastOpenedRowIndex][lastOpenedColIndex]);
                    }
                    if (!scene->items().contains(&flippedCards[rowIndex][colIndex])) {
                        scene->addItem(&flippedCards[rowIndex][colIndex]);
                    }
                    if (scene->items().contains(&cardsImages[rowIndex][colIndex])) {
                        scene->removeItem(&cardsImages[rowIndex][colIndex]);
                    }
                    Cards[lastOpenedRowIndex][lastOpenedColIndex]->setState(false);
                    Cards[rowIndex][colIndex]->setState(false);
                    // Reset the last opened indices
                    lastOpenedRowIndex = -1;
                    lastOpenedColIndex = -1;

                });
                return false;
            }
        } else {
            Cards[rowIndex][colIndex]->setState(true);
            // Set the current card as the last opened card
            if (!scene->items().contains(&cardsImages[rowIndex][colIndex])) {
                scene->addItem(&cardsImages[rowIndex][colIndex]);
            }
            if (scene->items().contains(&flippedCards[rowIndex][colIndex]) && flippedCards) {
                scene->removeItem(&flippedCards[rowIndex][colIndex]);
            }
            lastOpenedRowIndex = rowIndex;
            lastOpenedColIndex = colIndex;
            return false;
        }
    } else{
        return false;
    }
}



