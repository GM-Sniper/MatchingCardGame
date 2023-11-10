#ifndef CARD_H
#define CARD_H
#include <QPixmap>
#include <QObject>

class card{
public:
// Enum to represent the state of the card
enum State {Flipped,NotFlipped};

// Constructors
card();
card(int id);
card(int id, const QString& imagePath);

// Getter functions
int getId() const;
State getState() const;

// Function to flip the card
void flip();

// Function to check if two cards match
bool isMatch(const card& other) const;

private:
int id;          // Identifier for matching pairs
State state;     // Current state of the card (flipped or not)
QPixmap image;   // Image/icon for the card
};

#endif // CARD_H
