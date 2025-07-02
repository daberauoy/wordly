#include "letter.h"
#include <QKeyEvent>
#include <QMessageBox>

Letter::Letter(QWidget *parent) : QLineEdit(parent){
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    QFont font = this->font();
    font.setPointSize(40);
    this->setFont(font);
    this->setAlignment(Qt::AlignCenter);
    setMaxLength(1);
    setReadOnly(true);
}

void Letter::keyPressEvent(QKeyEvent *event) {
    if (this->isReadOnly()) return;

    if (event->key() == Qt::Key_Return && nextLetter) nextLetter->setFocus();
    if (event->key() == Qt::Key_Return && !nextLetter) {
        emit enterPressed();
        return;
    }
    if (event->key() == Qt::Key_Left && previousLetter) previousLetter->setFocus();
    if (event->key() == Qt::Key_Right && nextLetter) nextLetter->setFocus();

    if (event->key() == Qt::Key_Backspace) {
        if (text().isEmpty() && previousLetter) {
            previousLetter->setFocus();
            previousLetter->clear();
        } else QLineEdit::keyPressEvent(event);
    }

    if (event->text().isEmpty() || !event->text().at(0).isLetter()) {
        event->ignore();
        return;
    } else {
        QLineEdit::keyPressEvent(event);
        this->setText(event->text().toUpper());
        if (nextLetter) nextLetter->setFocus();
    }
}

QChar Letter::getLetter() {
    if (this->text().isEmpty()) {
        // QMessageBox* mb = new QMessageBox;
        // mb->setText("uebok vvedi vse bukvi");
        // mb->setIcon(QMessageBox::Warning);
        // mb->show();
        return QChar();
    }
    return QChar(this->text().at(0));
}

void Letter::changeColor(colors color) {
    QPalette palette;
    switch (color) {
        case colors::yellow:
            palette.setColor(QPalette::Base, "#ECB753");
            this->setPalette(palette);
            break;
        case colors::green:
            palette.setColor(QPalette::Base, "#2E6F40");
            this->setPalette(palette);
            break;
        default:
            break;
    }
}
