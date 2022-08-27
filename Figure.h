#ifndef FIGURE_H
#define FIGURE_H
#include <QWidget>
#include <QPainter>
#include <QPainterPath>
#include <QMenu>

class Figure : public QWidget {

    Q_OBJECT

public:
  Figure(QWidget *parent = 0);
  bool pls_remove=false;
  bool get_typeFigure() const;
  double S=0,P=0;
  void set_typeFigure(bool a);
  bool get_pressed();
  void set_pressed(bool);
  void set_param(int, int, int, int, int, int, int, int, int, int);
   bool typeFigure;
   int H, W, A_X, B_R, C_X, D_R, E_P, F, angle = 0;
   int H1, W1, A_R1, B_R1, C_R1, D_R1, E1, F_P1, angle1 = 0;
protected:
  void paintEvent(QPaintEvent *);
  void contextMenuEvent(QContextMenuEvent *event);
  void mouseMoveEvent(QMouseEvent *event);
  void mousePressEvent(QMouseEvent* event);
private:


  bool pressed = false;
  QPoint delta;
  size_t press=0;
  QMenu *figureMenu;
  QAction *actionEdit;
  QAction *actionDel;
private slots:
  void delFigure();
  void editFigure();
};

#endif // FIGURE_H
