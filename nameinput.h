#ifndef NAMEINPUT_H
#define NAMEINPUT_H
#include <QCloseEvent>
#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

namespace Ui {
class NameInput;
}

class NameInput : public QDialog
{
    Q_OBJECT
public:
    NameInput(QWidget *parent);
    QString getName();
    QString getLanguage();
    void setLabel(QString);
    QString language = "RU";

private:
    void closeEvent(QCloseEvent *event) override;
    // QLineEdit *lineEdit;
    // QPushButton *okButton;
    // QLabel *label;
    void changeLanguage();

    Ui::NameInput *ui;
};

#endif // NAMEINPUT_H
