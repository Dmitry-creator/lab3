#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QFileDialog>
#include <QFile>
#include <QAction>
#include <QRegularExpression>
#include  <QMessageBox>
QString name;
QTextStream cout(stdout);
QTextStream cin(stdin);
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    load_dictionary();
    ui->WordList->addItems(words);

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::load_dictionary()
{
    if (name=="")
     name=":/mueller.dict";
    if (name==":/mueller.dict")
    ui->statusbar->showMessage("Стандартный словарь");
    else
    ui->statusbar->showMessage(name);

    QFile inFile(name);
    if (!inFile.open(QIODevice::ReadOnly)){
        return;
    }
    QTextStream in(&inFile);
    QString line;
    QString word,translation;
    while (!in.atEnd()){
        line = in.readLine();
            if (!line.isEmpty() && !line[0].isSpace()){
                if (!word.isEmpty()){
                   // qDebug() << word << translation;
                    words.append(word);
                    translations.insert(word,translation);
                }
                word=line.simplified();
                translation= word;
            }else{
            translation = translation + QString("\n") + line;
            }
    }
    if (!word.isEmpty()){
      //  qDebug() << word << translation;
        words.append(word);
 ui->WordList->addItems(words);
    }
            inFile.close();
}


void MainWindow::on_WordList_currentTextChanged(const QString &currentText)
{
    ui->translator->setPlainText(translations[currentText]);
}

void MainWindow::on_searchLine_textChanged(const QString &arg1)
{
    QRegularExpression rx(arg1);
    ui->WordList->clear();
    ui->WordList->addItems(words.filter(rx));
    if (name==":/mueller.dict")
    ui->statusbar->showMessage("Стандартный словарь");
    else
    ui->statusbar->showMessage(name);
}



void MainWindow::on_open_2_triggered()
{
    QString file_name = QFileDialog::getOpenFileName(this, "Open a File", "D://");
    name=file_name;
    words.clear();
    ui->WordList->clear();
load_dictionary();
    }

