#include "nameinput.h"
#include "ui_nameinput.h"
#include <QBoxLayout>

NameInput::NameInput(QWidget *parent)
    : QDialog(parent), ui(new Ui::NameInput)
{
    ui->setupUi(this);

    setWindowTitle("Вордли!");
    setFixedSize(this->size());
    // resize(300, 100);

    // lineEdit = new QLineEdit(this);
    // label = new QLabel("Введите имя:", this);
    // okButton = new QPushButton("OK", this);
    // okButton->setDefault(true);

    // QVBoxLayout *layout = new QVBoxLayout(this);
    // layout->addWidget(label);
    // layout->addWidget(lineEdit);
    // lineEdit->setFocus();

    // QHBoxLayout *buttonLayout = new QHBoxLayout(this);
    // layout->addWidget(okButton);
    // layout->addLayout(buttonLayout);

    connect(ui->buttonOK, &QPushButton::clicked, this, &QDialog::accept);
    connect(ui->buttonEN, &QPushButton::clicked, this, &NameInput::changeLanguage);
    connect(ui->buttonRU, &QPushButton::clicked, this, &NameInput::changeLanguage);
    ui->buttonOK->setDefault(true);
}

void NameInput::changeLanguage() {
    if (language == "RU") {
        language = "EN";
        ui->buttonRU->setChecked(false);
        ui->buttonEN->setChecked(true);
    } else {
        language = "RU";
        ui->buttonRU->setChecked(true);
        ui->buttonEN->setChecked(false);
    }
}

QString NameInput::getName()
{
    return ui->lineEdit->text();
}
QString NameInput::getLanguage() {
    return language;
}

void NameInput::setLabel(QString text)
{
    ui->label->setText(text);
}

void NameInput::closeEvent(QCloseEvent *event)
{
    if (getName().trimmed().isEmpty()) {
        event->ignore();
        ui->lineEdit->setStyleSheet("border: 1px solid red;");
        setLabel("Введите имя перед закрытием!");
    } else {
        event->accept();
    }
}
