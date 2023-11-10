#include "card.h"

card::card() : id(-1), state(NotFlipped) {
    // Default constructor with invalid id
}

card::card(int id, const QString& imagePath) : id(id), state(NotFlipped) {
    // Constructor with id and image path
    image = QPixmap(imagePath);
}
card::card(int id) : id(id), state(NotFlipped) {
}

void card::setState(State s)
{
    state=s;
}

int card::getId() const {
    return id;
}

card::State card::getState() const {
    return state;
}

void card::flip() {
    // Toggle the state of the card
    state = (state == Flipped) ? NotFlipped : Flipped;
}

bool card::isMatch(const card& other) const
{
    // Check if two cards have the same id
    return (id == other.id);
}
