#include "Figure.h"
#include "DialogMenu.h"
#include <cmath>
#include <QMouseEvent>
//#include "m_window1.h"
//#include "m_window2.h"
#include <QMessageBox>
#include <QCoreApplication>

Figure::Figure(QWidget *parent) : QWidget(parent) {
    figureMenu=new QMenu;
    actionEdit=figureMenu->addAction("&Change");
    actionDel=figureMenu->addAction("&Delete", this->parentWidget(), SLOT(delFigure()));
    connect(actionEdit, SIGNAL(triggered()), this, SLOT(editFigure()));

}
void Figure::editFigure(){
    DialogMenu edit;
    edit.SetFigure(this);
    edit.exec();
    repaint();
}
void Figure::delFigure(){
    pls_remove=true;
}

void Figure::set_typeFigure(bool a){
    typeFigure =a;
    if (!a){
        W = rand()%375+65;
        H = rand()%(W-65)+65;
        A_X = rand()%(H/3);
        B_R = rand()%(H/3);
        C_X = rand()%(H/3);
        D_R=rand()%(H/3);
        E_P=rand()%(W/4);
        F=0;
        angle = rand()% 360;
         setGeometry(rand() % 750 + 40, rand() % 500 + 40, W*sqrt(2)+1,H*sqrt(2)+1);

    }
    else {
        W1 = rand() % 375 + 65;
        H1 = rand() % (W1 - 65 ) + 65;
        A_R1 = rand()% (H1 / 3),
        B_R1 = rand()% (H1 / 3),
        C_R1 = rand()% (H1 / 3),
        D_R1 = rand()% (H1 / 3),
        E1 = rand()% (W1 / 4),
        F_P1 = rand()% (W1 / 4);
        angle1 = rand()% 360;
         setGeometry(rand() % 750 + 40, rand() % 500 + 40, W1*sqrt(2)+1,H1*sqrt(2)+1);


    }
}
void Figure::set_param(int W_,int  H_, int A_, int B_, int C_, int D_, int E_, int F_, int angle_,int a){

    if (!typeFigure){
    W = W_;
    H = H_;
    A_X = A_;
    B_R = B_;
    C_X = C_;
    D_R=D_;
    E_P=E_;
    F=F_;
    angle = angle_ % 360;
    if (a==0){
        angle=360-angle;
    }
    }
else{
        W1 = W_;
        H1 = H_;
        A_R1 = A_;
        B_R1 = B_;
        C_R1 = C_;
        D_R1 = D_;
        E1 = E_;
        F_P1 = F_;
        angle1 = angle_% 360;
        if (a==0)
            angle1=180-angle1;
    }
}

void Figure::paintEvent(QPaintEvent *) {

    QPainterPath path;

    QPainter painter(this);
    if(!typeFigure){


    this->resize(sqrt(W*W + H*H) + 1, sqrt(W*W + H*H) + 1);


    if (!pressed){
        QPen pen(Qt::black);
        pen.setWidth(1);
        painter.setPen(pen);
    }
    else{
        QPen pen(Qt::blue);
        pen.setWidth(1);
        painter.setPen(pen);

    }

    painter.translate((sqrt(W*W + H*H) + 1)/2, (sqrt(W*W + H*H) + 1)/2);
    painter.rotate(angle);


    path.moveTo(0+E_P/2,-H/2);
    path.lineTo(W/2 - A_X, -H/2);
    path.lineTo(W/2-A_X, -H/2 + A_X);
    path.lineTo(W/2, -H/2 + A_X);
    path.lineTo(W/2, H/2 - B_R/2);

    path.moveTo(W/2 - B_R,H/2);
    QRectF rectangle( W/2 - B_R,H/2 - B_R ,B_R, B_R);
    path.arcTo(rectangle, 270,90);

    path.moveTo(W/2 - B_R,H/2);
   path.lineTo(0-W/2+C_X,H/2);
    path.lineTo(0-W/2,H/2-C_X);

    path.lineTo(-W/2, -H/2 + D_R/2 );
    path.moveTo(- W/2+ D_R/2 , -H/2);
    QRectF rectangle4(- W/2 , -H/2 , D_R, D_R);
    path.arcTo(rectangle4, 90 ,90);

    path.moveTo(- W/2 + D_R/2, - H/2 );
    path.lineTo(0 - E_P/2,-H/2);
    path.lineTo(-E_P/2, -H/2);
    path.lineTo(-E_P/2, -H/2 + E_P/2);
    path.lineTo(E_P/2, -H/2 + E_P/2);
    path.lineTo(E_P/2, -H/2);
    painter.drawPath(path);
    }
else{
        this->resize(sqrt(W1*W1 + H1*H1) + 1, sqrt(W1*W1 + H1*H1) + 1);


        if (!pressed){
            QPen pen(Qt::black);
            pen.setWidth(1);
            painter.setPen(pen);

        }
        else{
            QPen pen(Qt::blue);
            pen.setWidth(1);
            painter.setPen(pen);
        }
        painter.translate(sqrt(W1*W1 + H1*H1)/2+1, sqrt(W1*W1 + H1*H1)/2+1);
        painter.rotate(angle1);
        path.moveTo(0 + F_P1/2, -H1/2);
        path.lineTo(W1/2 - A_R1/2,-H1/2);
        QRectF rectangle(W1/2 - A_R1/2, -H1/2 - A_R1/2, A_R1, A_R1);
        path.arcTo(rectangle, 180, 90);
        path.moveTo(W1/2, -H1/2 + A_R1/2);
        path.lineTo(W1/2, -H1/2 + A_R1/2);
        path.lineTo(W1/2,H1/2 - B_R1/2);
        path.moveTo(W1/2 - B_R1,H1/2);
        QRectF rectangle9( W1/2 - B_R1,H1/2 - B_R1 ,B_R1, B_R1);
        path.arcTo(rectangle9, 270,90);
        path.moveTo(W1/2 - B_R1,H1/2);
        path.lineTo(0 + F_P1/2,H1/2);
        path.lineTo(0+ F_P1/2,H1/2-F_P1/2);
        path.lineTo(0- F_P1/2,H1/2-F_P1/2);
         path.lineTo(0- F_P1/2,H1/2);
        path.moveTo(0 - F_P1/2, H1/2);
        path.lineTo(-W1/2 + C_R1/2,H1/2);
        QRectF rectangle3( -W1/2 - C_R1/2, H1/2 - C_R1/2 ,C_R1, C_R1);
        path.arcTo(rectangle3, 0,90);
        path.moveTo(-W1/2, H1/2 - C_R1/2);
        path.lineTo(-W1/2, -H1/2 + D_R1/2 );
        QRectF rectangle4(- W1/2-D_R1/2 , -H1/2-D_R1/2, D_R1, D_R1);
        path.arcTo(rectangle4, 270 ,90);
        path.moveTo(- W1/2 + D_R1/2, - H1/2 );
        path.lineTo(-W1/2+ D_R1/2, -H1/2 );
        path.lineTo(W1/2 - A_R1/2,-H1/2);
         painter.drawPath(path);

    }
}

void Figure::set_pressed(bool status){
    pressed = status;
}

bool Figure::get_pressed(){
    return pressed;
}

void Figure::mouseMoveEvent(QMouseEvent *event){

    pressed = true;
    update();
    if (event->buttons() & Qt::LeftButton){
        if (((event->globalPos() - delta).x() + width() > 1500) ||
            ((event->globalPos() - delta).y() + height() > 1000) ||
            ((event->globalPos() - delta).x() <= 0 ) ||
            ((event->globalPos() - delta).y() <= 30))
                delta = event->globalPos() - pos();
        else
            move(event->globalPos() - delta);
    }

}

void Figure::mousePressEvent(QMouseEvent* event){

    if (event->button() & Qt::LeftButton){
        press++;
        if (press % 2 == 0)
            pressed = false;
        else
            pressed = true;
        update();
        delta = event->globalPos() - pos();
    }}

void Figure::contextMenuEvent(QContextMenuEvent *event) {
    if(pressed==true) {
        figureMenu->exec(event->globalPos());
    }
}
