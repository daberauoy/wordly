#ifndef WORD_H
#define WORD_H
#include "letter.h"

class Word : public QWidget
{
Q_OBJECT
public:
    Word(QWidget *parent);
    Letter* letters[5];
    Letter* getLetter(int num);
    void check();
    void setReadOnly(bool);
    bool isReadOnly();
    void setFocus();
    void setFocusOnNextSpare();
    QString getWord();
    void setLetterColor(int i, Letter::colors);

    Word* nextWord = nullptr;
    Word* previousWord = nullptr;

signals:
    void checkRequest(Word *word);

protected:
};

#endif // WORD_H
