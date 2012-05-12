#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "CamCapture.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void on_pushButton_CaptureStart_clicked();

    void on_pushButton_StartTracking_clicked();

private:
    Ui::MainWindow *ui;
    CamCapture cap;
};

#endif // MAINWINDOW_H
