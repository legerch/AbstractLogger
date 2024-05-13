#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "mock/person.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void initUserInterface();

    void uiInitTitle();

private slots:
    void on_btn_registerPerson_clicked();
    void on_btn_clearPerson_clicked();

private:
    Ui::MainWindow *ui;

    libra::Person m_member;
};

#endif // MAINWINDOW_H
