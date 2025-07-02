#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLineEdit>
#include <QMessageBox>
#include <QPushButton>
#include <QRandomGenerator>
#include <QFile>
#include <QTextStream>
#include <QDir>
#include "nameinput.h"
#include <QPixmap>
// #include "word.h"
#include <QImageReader>
#include <QSoundEffect>
#include <QAudioOutput>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(this->size());
    this->setWindowTitle("Вордли!");

    connect(ui->newGameButton, &QPushButton::clicked, this, &MainWindow::newGame);
    ui->newGameButton->setAutoDefault(true);

    askUsername();
    getWordsFromFile();
    newGame();

    sound = loadSoundEffect();
}

QString MainWindow::askUsername() {
    NameInput inp(this);
    while (inp.exec() == QDialog::Accepted) {
        QString name = inp.getName();
        language = inp.getLanguage();
        qDebug() << "language: " << language;
        if (!name.isEmpty()) {
            qDebug() << "имя: " << name;
            username = name.toLower();
            return username;
        } else {
            inp.setLabel("Имя не может быть пустым.");
        }
    }
    return "guest";
}

void MainWindow::newGame() {
    getNewWord();
    ui->statusLabel->setText("Новая игра начата!");

    QLayoutItem* item;
    while ((item = ui->grid->takeAt(0)) != nullptr) {
        if (item->widget()) {
            item->widget()->deleteLater(); // Безопасное удаление
        }
        delete item; // Удаляем сам QLayoutItem
    }
    for (int i = 0; i < 6; i++) {
        words[i] = new Word(this);
        connect(words[i], &Word::checkRequest, this, &MainWindow::checkWord);
    }
    for (int i = 1; i < 5; ++i) {
        words[i]->nextWord = words[i+1];
        words[i]->previousWord = words[i-1];
    }
    words[5]->previousWord = words[4];
    words[0]->nextWord = words[1];

    for(int i = 0; i < 6; i++) {
        for (int j = 0; j < 5; j++) {
            ui->grid->addWidget(words[i]->getLetter(j), i+1, j+1);
        }
    }
    words[0]->setReadOnly(false);
    words[0]->setFocus(); //не работает почему-то
    qDebug() << "new game process ended";
}

QString MainWindow::getNewWord() {
    if (specialUsernameList.contains(username) && language == "RU") {
        secretWord = specialWordList.at(QRandomGenerator::global()->bounded(specialWordList.size()));
    } else {
        int size;
        if (language == "RU") {
            size = 654;
        } else /*if (language == "EN")*/ {
            size = 800;
        }
        secretWord = wordList.at(QRandomGenerator::global()->bounded(size));
    }
    secretWord.replace(QString("Ё"), QString("Е"));

    qDebug() << "загаданное слово: " << secretWord;
    return secretWord;
}

void MainWindow::getWordsFromFile() {
    wordList += specialWordList;
    qDebug() << "entered file reading process";
    qDebug() << "рабочая директория:" << QDir::currentPath();
    QString appDir = QCoreApplication::applicationDirPath();
    QString filePath = appDir + "/additionals/words" + language + ".txt";
    qDebug() << "итоговый путь: " << filePath;
    QFile fin(filePath);
    if (!fin.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "ошибка открытия файла";
        return;
    }
    QTextStream instream(&fin);
    QString line;
    while (!instream.atEnd()){
        line = instream.readLine();
        if (line.length() != 5) continue;
        line = line.toUpper();
        if (!wordList.contains(line))
            wordList.push_back(line);
    }
    fin.close();
    //test
    for (auto word : wordList) {
        qDebug() << word;
    }
}

void MainWindow::checkWord(Word* word) {
    ui->statusLabel->clear();
    QString guess = word->getWord();

    if (guess.length() < 5) {
        ui->statusLabel->setText("Введите все буквы!");
        return;
    }
    if (!wordList.contains(guess)) {
        ui->statusLabel->setText("Такого слова нет!");
        return;
    }

    guess.replace(QString("Ё"), QString("Е"));

    for (int i = 0; i < 5; ++i) {
        if (secretWord[i] == guess[i]) {
            word->setLetterColor(i, Letter::colors::green);
        } else if (secretWord.contains(guess[i])) {
            word->setLetterColor(i, Letter::colors::yellow);
        }
    }
    if (guess == secretWord) {
        word->setReadOnly(true);
        win();
        return;
    }
    if (!word->nextWord) {
        word->setReadOnly(true);
        loose();
        return;
    }
    word->setReadOnly(true);
    word->nextWord->setFocus();
    word->nextWord->setReadOnly(false);
}

void MainWindow::win() {
    // QMessageBox msg;
    // QPushButton* button = msg.addButton("Новая игра", QMessageBox::AcceptRole);
    // msg.setWindowTitle("Ураа!");
    // msg.setText("Играть снова?");
    // msg.exec();
    // if (msg.clickedButton() == button) {
    //     newGame();
    // } else {
    //     newGame();
    // }

    ui->statusLabel->setText("Ура! Играть снова?");
    ui->newGameButton->setFocus();

    QWidget* prizeImgWindow = new QWidget();
    QVBoxLayout* layout = new QVBoxLayout(prizeImgWindow);
    QLabel* prizeImgLabel = new QLabel(prizeImgWindow);

    QString appDir = QCoreApplication::applicationDirPath();
    QString filePath = appDir + "/additionals/blackmankissing.jpg";
    qDebug() << "итоговый путь: " << filePath;

    QPixmap pixmap(filePath);
    if(pixmap.isNull()) {
        qDebug() << "Ошибка загрузки изображения! Проверьте:";
        qDebug() << "1. Корректность пути:" << filePath;
        qDebug() << "2. Наличие файла в ресурсах";
        qDebug() << "3. Размер файла:" << QFile(filePath).size() << "байт";
    }
    prizeImgLabel->setPixmap(pixmap);
    prizeImgLabel->setScaledContents(true);

    layout->addWidget(prizeImgLabel);
    prizeImgWindow->setLayout(layout);
    prizeImgWindow->setWindowState(Qt::WindowFullScreen);
    playSoundEffect(sound);
    prizeImgWindow->show();
}

void MainWindow::loose() {
    // QMessageBox msg;
    // QPushButton* button = msg.addButton("Новая игра", QMessageBox::AcceptRole);
    // msg.setWindowTitle("лох!");
    // msg.setText(QString("Загаданное слово: ") + secretWord + "\nИграть снова?");
    // msg.exec();
    // if (msg.clickedButton() == button) {
    //     newGame();
    // } else {
    //     newGame();
    // }

    ui->statusLabel->setText(QString("Загаданное слово: ") + secretWord + "\nИграть снова?");
    ui->newGameButton->setFocus();
}


QSoundEffect* MainWindow::loadSoundEffect() {
    QSoundEffect* sound = new QSoundEffect(this);
    QString appDir = QCoreApplication::applicationDirPath();
    QString filePath = appDir + "/additionals/kiss_sf.wav";
    qDebug() << "итоговый путь sfx: " << filePath;
    sound->setSource(QUrl::fromLocalFile(filePath)); // Путь к файлу
    sound->setVolume(0.8f); // Громкость от 0.0 до 1.0
    sound->setLoopCount(0); // Предзагрузка
    qDebug() << "звук загружен!";
    return sound;
}
void MainWindow::playSoundEffect(QSoundEffect* sound) {
    sound->play();
    // Автоудаление после проигрывания
    // connect(sound, &QSoundEffect::playingChanged, [sound]() {
    //     if (!sound->isPlaying()) {
    //         sound->deleteLater();
    //     }
    // });
}

MainWindow::~MainWindow()
{
    delete ui;
}
