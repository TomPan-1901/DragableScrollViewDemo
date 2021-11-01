#include "mainwindow.h"
#include "dragablescrollarea.h"
#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setWindowTitle("DragableScrollViewDemo");
    this->resize(800, 600);
    QScrollArea *area = new DragableScrollArea(this);
    this->setCentralWidget(area);
    QLabel *label = new QLabel(area);
    area->setWidgetResizable(true);
    area->setWidget(label);
    QImage img = QImage();
    img.load(":/image/l_hires.jpg");
    label->setPixmap(QPixmap::fromImage(img));
    label->show();
}

MainWindow::~MainWindow()
{
}

