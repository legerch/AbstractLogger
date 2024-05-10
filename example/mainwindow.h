#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "base/person.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btn_registerPerson_clicked();

    void on_btn_clearPerson_clicked();

private:
    void initUserInterface();

    void uiInitTitle();

private:
    Ui::MainWindow *ui;

    gen::Person m_member;
};

#endif // MAINWINDOW_H