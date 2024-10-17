#include "mainwindow.h"
#include "ui_mainwindow.h"
QString celsius;
QString fahrenheit;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_celsius_editingFinished()
{
    celsius = ui->celsius->text();
    if(fahrenheit.isEmpty()){
        fahrenheit = ui->fahrenheit->text();
    } else {
        celsius = ui->celsius->text();
        fahrenheit = "";
    }
}

void MainWindow::on_fahrenheit_editingFinished()
{
    if(celsius.isEmpty()){
        fahrenheit = ui->fahrenheit->text();
    } else {
        celsius = "";
        fahrenheit = ui->fahrenheit->text();
    }
}

void MainWindow::on_conversion_submit_clicked()
{
    bool f_isNumber;
    bool c_isNumber;
    // Convert to celsius
    if(fahrenheit.isEmpty()){
        // Since fahrenheit is empty;
        // Convert celsius to fahrenheit
        // Check if we're dealing with a number
        double c_number = ui->celsius->text().toDouble(&c_isNumber);
        if(c_isNumber){
            fahrenheit = QString::number((c_number * 1.8) + 32);
            ui->fahrenheit->setText(fahrenheit);
            // Empty everything
            celsius = "";
            fahrenheit = "";
        }
    } else if(celsius.isEmpty()) {
        // Since celsius is empty;
        // Convert fahrenheit to celsius
        // Check if we're dealing with a number
        double f_number = ui->fahrenheit->text().toDouble(&f_isNumber);
        if(f_isNumber){
            celsius = QString::number((f_number - 32)*5.0/9);
            ui->celsius->setText(celsius);
            // Empty everything
            celsius = "";
            fahrenheit = "";
        }
    }
}

