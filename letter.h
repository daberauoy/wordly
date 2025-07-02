#ifndef LETTER_H
#define LETTER_H
#include <QLineEdit>

class Word;

class Letter : public QLineEdit
{
Q_OBJECT
public:
    Letter(QWidget *parent);

    // Word* wordParent;

    Letter* previousLetter = nullptr;
    Letter* nextLetter = nullptr;

    QChar getLetter();

    enum colors {yellow, green};
    void changeColor(colors color);

signals:
    void enterPressed();

protected:
    void keyPressEvent(QKeyEvent *event) override;
};

#endif // LETTER_H
