#include "mainwindow.h"
#include "ui_mainwindow.h"

/*****************************/
/* Class documentations      */
/*****************************/

/*****************************/
/* Enum documentations       */
/*****************************/

/*****************************/
/* Structure documentations  */
/*****************************/

/*****************************/
/* Signals documentations    */
/*****************************/

/*****************************/
/* Macro definitions         */
/*****************************/

/*****************************/
/* Namespace aliases         */
/*****************************/

/*****************************/
/* Class aliases             */
/*****************************/

/*****************************/
/* Start namespace           */
/*****************************/

/*****************************/
/* Functions implementation  */
/*****************************/

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    /* User interface */
    ui->setupUi(this);

    /* Initialize members variables */
    // No members to initialize

    /* Custom routines */
    initUserInterface();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initUserInterface()
{
    uiInitTitle();
}

void MainWindow::uiInitTitle()
{
    const QString title = QString("%1 - %2").arg(qApp->applicationName(), qApp->applicationVersion());
    setWindowTitle(title);
}

void MainWindow::on_btn_registerPerson_clicked()
{
    m_member = gen::Person("test", 1);
}

void MainWindow::on_btn_clearPerson_clicked()
{
    m_member.clear();
}

