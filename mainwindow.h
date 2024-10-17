#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_celsius_editingFinished();

    void on_fahrenheit_editingFinished();

    void on_conversion_submit_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
