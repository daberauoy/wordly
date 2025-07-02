#include "word.h"

Word::Word(QWidget *parent) : QWidget(parent) {
    for (int i = 0; i < 5; ++i) {
        this->letters[i] = new Letter(this);
        // this->letters[i]->wordParent = this;
    }
    this->letters[0]->nextLetter = letters[1];
    this->letters[4]->previousLetter = letters[3];
    for (int i = 1; i < 4; ++i) {
        this->letters[i]->previousLetter = letters[i-1];
        this->letters[i]->nextLetter = letters[i+1];
    }
    connect (letters[4], &Letter::enterPressed, this, [this](){emit checkRequest(this);});
}

Letter* Word::getLetter(int num) {
    return this->letters[num];
}

void Word::setReadOnly(bool setter) {
    for (int i = 0; i < 5; ++i) {
        this->letters[i]->setReadOnly(setter);
    }
}

bool Word::isReadOnly() {
    return letters[0]->isReadOnly();
}

void Word::setFocus() {
    letters[0]->setFocus();
}

// void Word::setFocusOnNextSpare()

QString Word::getWord() {
    QString word;
    for (int i = 0; i < 5; ++i) {
        if (this->letters[i]->getLetter() != QChar())
        word.append(this->letters[i]->getLetter());
    }
    return word;
}

void Word::setLetterColor(int i, Letter::colors color) {
    letters[i]->changeColor(color);
}

// void Word::check() {

// }
