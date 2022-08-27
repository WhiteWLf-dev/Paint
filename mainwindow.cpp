#include "mainwindow.h"
#include <QToolBar>
#include <QTimer>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    MainToolBar=new QToolBar(this);

    type1=MainToolBar->addAction(tr("Figure 1"));
    type2=MainToolBar->addAction(tr("Figure 2"));
    add=MainToolBar->addAction(tr("Add"));
    del=MainToolBar->addAction(tr("Delete"));

    addToolBar(MainToolBar);

    type1->setCheckable(true);
    type2->setCheckable(true);
    add->setDisabled(true);
    del->setDisabled(true);

    connect(type1,SIGNAL(triggered()),this,SLOT(pick1type()));
    connect(type2,SIGNAL(triggered()),this,SLOT(pick2type()));
    connect(add,SIGNAL(triggered()),this,SLOT(addFigure()));
    connect(del,SIGNAL(triggered()),this,SLOT(delFigure()));

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(check_widget()));
    timer->start(500);


}
void MainWindow::check_widget(){
    bool a=0;
    for (size_t i=0;i<f.size();i++){
        if (f[i]->get_pressed()){
            a=1;
        }
    }
    if (a){
        del->setDisabled(false);
    }
    else {
        del->setDisabled(true);
    }
}
MainWindow::~MainWindow()
{
    f.clear();
}

void MainWindow::pick1type(){
    type2->setChecked(false);
    type1->setChecked(true);
    add->setDisabled(false);
    flag=0;
   update();
}
void MainWindow::pick2type(){
    type1->setChecked(false);
    type2->setChecked(true);
    add->setDisabled(false);
    flag=1;
    update();
}
void MainWindow::addFigure(){

    Figure *p = new Figure(this);
    p->set_typeFigure(flag);
    f.push_back(p);
    p->show();
    update();
}
void MainWindow::delFigure(){
for(size_t i=0;i<f.size();i++){
    if (f[i]->get_pressed()==true||f[i]->pls_remove){
        f[i]->close();
        f.remove(i);
    }

}
update();
}
