#ifndef OPEN_H
#define OPEN_H

#include <QDialog>

namespace Ui {
class open;
}

class open : public QDialog
{
    Q_OBJECT

public:
    explicit open(QWidget *parent = nullptr);
    ~open();

private slots:
    void on_lineEdit_textChanged(const QString &arg1);

private:
    Ui::open *ui;
};

#endif // OPEN_H
