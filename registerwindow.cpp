#include "registerwindow.h"
#include "ui_registerwindow.h"
#include <QString>
#include "Users.h"
#include "welcomewindow.h"
#include "Exceptions.h"
#include<string>
#include<QMessageBox>
RegisterWindow::RegisterWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegisterWindow)
{
    ui->setupUi(this);
    ui->labelErrorDate->setVisible(false);
    ui->labelErrorFull->setVisible(false);
    ui->labelErrorUser->setVisible(false);
    ui->labelRetypePassError->setVisible(false);

}

RegisterWindow::~RegisterWindow()
{
    delete ui;
}

void RegisterWindow::on_regPushButtonRegister_clicked()
{

    ui->labelErrorDate->setVisible(false);
    ui->labelErrorFull->setVisible(false);
    ui->labelErrorUser->setVisible(false);
    ui->labelRetypePassError->setVisible(false);

    QString Username_Reg=ui->regLineEditUser->text();
    QString Pass_Reg=ui->regLineEditPassword->text();
    QString RePass_Reg=ui->regLineEditPasswordRetype->text();
    QString Month_Reg=ui->comboBoxMonth->currentText();
    QString Day_Reg_Str=ui->lineEditDay->text();
    int Day_Reg=Day_Reg_Str.toInt();
    QString Year_Reg_Str=ui->lineEditYear->text();
    int Year_Reg=Year_Reg_Str.toInt();
    bool male=ui->radioButtonMale->isChecked();
    bool female=ui->radioButtonFemale->isChecked();
    bool admin=ui->radioButtonAdmin->isChecked();
    bool user=ui->radioButtonUser->isChecked();
    bool action=ui->checkBox->isChecked();
    bool comedy=ui->checkBox_2->isChecked();
    bool drama=ui->checkBox_3->isChecked();
    bool horror=ui->checkBox_4->isChecked();
    bool romance=ui->checkBox_5->isChecked();
    bool other=ui->checkBox_6->isChecked();
    int age_reg=2023-Year_Reg;
    bool check=true;
    try{
     if((Username_Reg.isEmpty()||Pass_Reg.isEmpty()||Month_Reg.isEmpty()||RePass_Reg.isEmpty()||Day_Reg_Str.isEmpty()||Year_Reg_Str.isEmpty()||((male||female)==false)||(admin||user==false)||((action||comedy||drama||horror||romance||other)==false))==true)
        {
            throw EmptyText("Fields Empty");
            ui->labelErrorFull->setVisible(true);
            check=false;
        }
    for(int i=0;i<usersCount;i++)
    {
        if(Username_Reg==usernames[i])
        {
            ui->labelErrorUser->setVisible(true);
            check=false;
            throw DuplicateUser("username");
            break;
        }
    }


    if(Day_Reg<1 ||Day_Reg>31)
    {   throw InvalidDay();
        ui->labelErrorDate->setVisible(true);
        check=false;
    }
    if(RePass_Reg!=Pass_Reg)
    {   throw PasswordMismatch();
        ui->labelRetypePassError->setVisible(true);
        check=false;
    }
    if(age_reg<17)
    {   throw InvalidYear();
        ui->labelErrorDate->setVisible(true);
        check=false;
    }


    if(check==true)
    {   usernames[usersCount]=Username_Reg;
        password[usersCount]=Pass_Reg;
        age[usersCount]=age_reg;
        usersCount++;
        hide();
        WelcomeWindow* welcomeWindow= new WelcomeWindow(Username_Reg,age_reg,this);
        welcomeWindow->show();

    }
    }
    catch(EmptyText& e)
    {
        QMessageBox::warning(this,tr("Error!"),tr(e.what()));
    }
    catch(InvalidYear& e)
    {
        QMessageBox::warning(this,tr("Error!"),tr(e.what()));
    }
    catch(PasswordMismatch& e)
    {
        QMessageBox::warning(this,tr("Error!"),tr(e.what()));
    }
    catch(DuplicateUser& e)
    {
        QMessageBox::warning(this,tr("Error!"),tr(e.what()));
    }
    catch(InvalidDay& e)
    {
        QMessageBox::warning(this,tr("Error!"),tr(e.what()));
    }
}
