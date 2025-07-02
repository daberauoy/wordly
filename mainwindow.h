#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "word.h"
#include <QList>
#include <QSoundEffect>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void showWarning();

private slots:
    void checkWord(Word* word);

private:
    Ui::MainWindow *ui;
    QString secretWord;
    QString username;
    QList<QString> wordList = {"ВЕНОК"};
    QList<QString> specialWordList = {"НЕГРЫ", "ПИДОР", "СУЧКА", "ЧМЫРЬ", "ХУЙНЯ", "ГОВНО", "ЕБАЛО", "НИГГА", "ПЕНИС",
    "ПИЗДА", "ЧМОНЯ", "ГРИША", "БЛЯДЬ", "ВАФЛЯ", "ГОЙДА", "ГНИДА"};
    QList<QString> specialUsernameList =    {"даник", "даниил", "danik", "daniil",
                                            "яша", "яков", "yasha", "yakov", "jacob",
                                            "миша", "михаил", "misha", "mihail"
                                            "артем", "артём", "artem", "artiom",
                                            "маша", "мария", "masha", "maria"
                                            "аня", "анна", "anya", "anna",
                                            "сергей", "серега", "sergei", "serega",
                                            "вера", "vera" };
    QSoundEffect* sound;
    QString language = "RU"; //RU or EN

    QString askUsername();
    void newGame();
    QString getNewWord();
    void getWordsFromFile();
    QSoundEffect* loadSoundEffect();
    void playSoundEffect(QSoundEffect* sound);
    void changeLanguage(QString);

    Word* words[6];
    void win();
    void loose();
};
#endif // MAINWINDOW_H
