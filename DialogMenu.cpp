#include "DialogMenu.h"
#include <QLabel>
#include <QFrame>
#include <QGridLayout>
#include <QPushButton>
#include <QString>
#include <QLineEdit>


DialogMenu::DialogMenu(QWidget *parent) : QDialog(parent), figure(nullptr) {
    frame=new QFrame(this);
    frame->setFrameStyle(QFrame::Box | QFrame::Raised);


    Width=new QSpinBox(frame);
    Height=new QSpinBox(frame);
    A_=new QSpinBox(frame);
    B_=new QSpinBox(frame);
    C_=new QSpinBox(frame);
    D_=new QSpinBox(frame);
    E_=new QSpinBox(frame);
    F_=new QSpinBox(frame);
    Angle=new QSpinBox(frame);
    Counterclockwise=new QSpinBox(frame);

     Width->setRange(0, 2000);
     Height->setRange(0, 2000);
     A_->setRange(0, 2000);
     B_->setRange(0, 2000);
     C_->setRange(0, 2000);
     D_->setRange(0, 2000);
     E_->setRange(0, 2000);
     F_->setRange(0, 2000);
     Angle->setRange(-180, 180);
     Counterclockwise->setRange(0,1);

    messageBox=new QMessageBox();
    messageBox->setWindowTitle("Warning!");
    messageBox->setText("Wrong input!");
    messageBox->addButton(QMessageBox::Ok);
    QLabel *LWidth=new QLabel("Width ",frame);
    QLabel *LHeight=new QLabel("Height ", frame);
    QLabel *LA=new QLabel("A ", frame);
    QLabel *LB=new QLabel("B ", frame);
    QLabel *LC=new QLabel("C ", frame);
    QLabel *LD=new QLabel("D ", frame);
    QLabel *LE=new QLabel("E ", frame);
    QLabel *LF=new QLabel("F ", frame);
    QLabel *LAngle=new QLabel("Angle ", frame);
    QLabel *LProtive=new QLabel("Counterclockwise ", frame);
    QLabel *LabelS=new QLabel("S ",frame);
    QLabel *LabelP=new QLabel("P ",frame);

    fl=new QGridLayout(frame);
    fl->addWidget(LWidth,0,0);
    fl->addWidget(Width,0,1);

    fl->addWidget(LHeight,1,0);
    fl->addWidget(Height,1,1);

    fl->addWidget(LA,2,0);
    fl->addWidget(A_,2,1);

    fl->addWidget(LB,3,0);
    fl->addWidget(B_,3,1);
    fl->addWidget(LC,4,0);
    fl->addWidget(C_,4,1);

    fl->addWidget(LD,5,0);
    fl->addWidget(D_,5,1);
    fl->addWidget(LE,6,0);
    fl->addWidget(E_,6,1);
    fl->addWidget(LF,7,0);
    fl->addWidget(F_,7,1);
    fl->addWidget(LAngle,8,0);
    fl->addWidget(Angle,8,1);
    fl->addWidget(LProtive,9,0);
    fl->addWidget(Counterclockwise,9,1);
    fl->addWidget(LabelS,10,0);
    fl->addWidget(LabelP,11,0);
    frame->setLayout(fl);

    QPushButton *accbutt=new QPushButton("Accept", this);
    connect(accbutt, SIGNAL(clicked()), this, SLOT(accept()));

    QGridLayout *gl=new QGridLayout(this);
    gl->addWidget(frame,0,0);
    gl->addWidget(accbutt,1,0);
    setLayout(gl);
    setModal(true);
}
void DialogMenu::SetFigure(Figure *f) {

figure=f;
type=figure->typeFigure;
if (!type){
    p=f->H-f->B_R+2*3.14*f->B_R/4+f->W-f->B_R-f->C_X+sqrt(f->A_X)+f->H-f->A_X-f->D_R+2*3.14*f->D_R/4+f->W-f->D_R+f->E_P;
    s=((f->H)*(f->W)) - f->A_X*f->A_X - f->B_R*f->B_R + 3.14*f->B_R*f->B_R/4 - f->D_R*f->D_R + 3.14*f->D_R*f->D_R/4 - f->C_X*f->C_X/2-f->E_P/2*f->E_P;
Width->setValue(f->W);
Height->setValue(f->H);
A_->setValue(f->A_X);
B_->setValue(f->B_R);
C_->setValue(f->C_X);
D_->setValue(f->D_R);
E_->setValue(f->E_P);
F_->setDisabled(true);
Angle->setValue(f->angle);

}
else {
p=f->H1-f->A_R1+2*3.14*f->A_R1/4-f->B_R1+2*3.14*f->B_R1/4+f->W1-f->B_R1+f->F_P1-f->C_R1+2*3.14*f->C_R1/4+f->H1-f->C_R1-f->D_R1+2*3.14*f->D_R1/4+f->W1-f->D_R1-f->A_R1;
s=f->H1*f->W1-3.14*f->A_R1*f->A_R1/4-3.14*f->C_R1*f->C_R1/4-3.14*f->D_R1*f->D_R1/4-f->C_R1*f->C_R1+3.14*f->C_R1*f->C_R1/4-f->F_P1*f->F_P1/2;
}
QLabel *ppp=new QLabel(QString::number(p),frame);
QLabel *sss=new QLabel(QString::number(s),frame);
fl->addWidget(ppp,11,1);
fl->addWidget(sss,10,1);


    }

void DialogMenu::accept() {
    bool flag1=0;

    if (type==0){
        if (Width->value()<700&&Height->value()<500&&Width->value()>Height->value()&&Height->value()>0&&A_->value()>0&&A_->value()<Height->value()/3&&B_->value()>0&&B_->value()<Height->value()/3&&C_->value()>0&&C_->value()<Height->value()/3&&D_->value()>0&&D_->value()<Height->value()/3&&E_->value()>0&&E_->value()<Width->value()/4){
            flag1=0;
        }
        else {
            flag1=1;
            messageBox->open();
        }
    }
    else {
        if (Width->value()<700&&Height->value()<500&&Width->value()>Height->value()&&Height->value()>0&&A_->value()>0&&A_->value()<Height->value()/3&&B_->value()>0&&B_->value()<Height->value()/3&&C_->value()>0&&C_->value()<Height->value()/3&&D_->value()>0&&D_->value()<Height->value()/3&&F_->value()>0&&F_->value()<Width->value()/4){
            flag1=0;
        }
        else {
            flag1=1;
            messageBox->open();
        }
    }
    if (flag1==0){

    figure->set_param(Width->value(),Height->value(),A_->value(),B_->value(),C_->value(),D_->value(),E_->value(),F_->value(),Angle->value(),Counterclockwise->value());
}
    figure->repaint();
    close();
}


