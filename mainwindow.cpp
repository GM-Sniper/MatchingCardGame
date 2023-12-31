#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Users.h"
#include <stdexcept>
#include "Exceptions.h"
#include "gameview.h"

#include<QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->labelError->setVisible(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButtonLogin_clicked()
{
    QString username_entered= ui->lineEditUser->text();
    QString password_entered= ui->lineEditPassword->text();


    for(int i=0; i<usersCount;i++)
    {
        if(username_entered==usernames[i]&& password_entered==password[i])
        {
            hide();
            GameView* game= new GameView(username_entered);
            game->view->show();
            break;
        }else{
            ui->labelError->setVisible(true);
            ui->labelError->setText("Wrong Username or Password");

        }

    }
    try{
        if(username_entered.isEmpty()&& password_entered.isEmpty())
        {
            throw EmptyText("Username and Password");
            ui->labelError->setVisible(true);
        }
        else if(username_entered.isEmpty())
        {
        throw EmptyText("Username");
        ui->labelError->setVisible(true);
        }
        else if(password_entered.isEmpty())
        {
        throw EmptyText("Pasword");
        ui->labelError->setVisible(true);
        }
    }
    catch(EmptyText& e)
    {
        QMessageBox::warning(this,tr("Error!"),tr(e.what()));
    }
}
