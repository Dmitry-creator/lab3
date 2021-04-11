#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QHash>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_WordList_currentTextChanged(const QString &currentText);
    void on_searchLine_textChanged(const QString &arg1);

    void on_open_triggered();

    void on_open_2_triggered();

private:
    Ui::MainWindow *ui;
    void load_dictionary();
    QStringList words;
    QHash<QString,QString> translations;
};
#endif // MAINWINDOW_H
