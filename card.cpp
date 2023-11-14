// card.cpp
#include "card.h"

card::card(int id, const QString &imagePath) : id(id), state(false)
{
    image = QPixmap(imagePath);
    image = image.scaled(QSize(40, 40), Qt::KeepAspectRatio, Qt::FastTransformation);
//    image.scaledToWidth(40);
}

int card::getId() const
{
    return id;
}

bool card::getState() const
{
    return state;
}
void card::setState(bool status)
{
    state = status;
}

void card::flip()
{
    // Toggle the state of the card
    if (!state) {
        state = true;
    } else {
        state = false;
    }
}

bool card::isMatch(const card &other) const
{
    // Check if two cards have the same id
    return (id == other.id);
}

void card::setPixmap(const QPixmap &pixmap)
{
    image = pixmap;
}

QPixmap card::getPixmap() const
{
    return image;
}
bool card::isMatched() const
{
    return matched;
}

void card::setMatched(bool status)
{
    matched = status;
}

bool card::operator==(const card &other) const
{
    // Check if two cards have the same id

    return (this->id == other.id);
}
