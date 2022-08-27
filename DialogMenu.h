#ifndef DIALOGMENU_H
#define DIALOGMENU_H
#include "Figure.h"
#include <QWidget>
#include <QDialog>
#include <QSpinBox>
#include<QFrame>
#include <QMessageBox>
#include <QGridLayout>

class DialogMenu : public QDialog {
    Q_OBJECT

public:
    DialogMenu(QWidget *p=0);
    void SetFigure(Figure *f);
     double s=0,p=0;
public slots:
    void accept();

private:
    bool type;
    Figure *figure;
    QFrame *frame;
     QGridLayout *fl;
    QSpinBox *Width;
    QSpinBox *Height;
    QSpinBox *A_;
    QSpinBox *B_;
    QSpinBox *C_;
    QSpinBox *D_;
    QSpinBox *E_;
    QSpinBox *F_;
    QSpinBox *Angle;
    QSpinBox *Counterclockwise;
    QMessageBox* messageBox;
};
#endif // DIALOGMENU_H
