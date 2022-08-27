#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMenuBar>
#include <QVector>
#include <QCoreApplication>
#include <QContextMenuEvent>
#include <QMainWindow>
#include <QPainter>
#include <Figure.h>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QToolBar *MainToolBar;
    QAction *type1,*type2,*add,*del;
    QVector <Figure*> f;
    bool flag;

private slots:
    void check_widget();
    void pick1type();
    void pick2type();
    void addFigure();
    void delFigure();

};
#endif // MAINWINDOW_H
