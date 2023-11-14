// card.h
#ifndef CARD_H
#define CARD_H

#include <QPixmap>

class card
{
public:
    enum State { NotFlipped, Flipped };

    card(int id, const QString &imagePath);
    int getId() const;
//    State getState() const;
    bool getState() const;
    void setState(bool status);
    bool isMatched() const;
    void setMatched(bool status);

    void flip();
    bool isMatch(const card &other) const;
    void setPixmap(const QPixmap &pixmap);
    QPixmap getPixmap() const;
    // Overload equality operator
    bool operator==(const card &other) const;

private:
    int id;
    bool state;
    bool matched;

    //    State state;
    QPixmap image;
};

#endif // CARD_H
