#include "welcomewindow.h"
#include "ui_welcomewindow.h"
#include "mainwindow.h"
#include "bookingview.h"
WelcomeWindow::WelcomeWindow(QString username,int age, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WelcomeWindow)
{
    ui->setupUi(this);

    QString str = QString :: number (age);
    ui->labelHello->setText("Hello "+ username+" "+ str);

    QPixmap pix ("C:\\Users\\Raram\\Downloads\\welcome2.jpg");
    int w= ui->labelPicture->width();
    int h= ui->labelPicture->height();
    ui->labelPicture->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));


}

WelcomeWindow::~WelcomeWindow()
{
    delete ui;
}

void WelcomeWindow::on_pushButtonLogout_clicked()
{
    hide();
    MainWindow* LoginWindow= new MainWindow(this);
    LoginWindow->show();
}


void WelcomeWindow::on_pushButtonBookSeat_clicked()
{   hide();
    BookingView* booking= new BookingView;
    booking->view->show();

}

