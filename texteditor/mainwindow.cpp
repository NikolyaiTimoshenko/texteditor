#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QDebug>
#include <QTextStream>
#include <QMessageBox>
#include <QTextDocumentWriter>


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

void MainWindow::on_downButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Выберите файл", QDir::currentPath(), "*.txt");
    QFile file(fileName);

    if(file.open(QIODevice::ReadOnly))
    {
        qDebug () << "Test";
        QTextStream stream(&file);
        QString str = stream.readAll();
        ui->textEdit->setText(str);
        file.close();
    }
}


void MainWindow::on_savebutton_clicked()
{

    QString fileName = QFileDialog::getSaveFileName(this, tr("Сохранить файл..."),"",tr("Файлы txt (*.txt)"));
    if (fileName.isEmpty()) return;
    if (fileName.isEmpty()) return;
    QTextDocumentWriter writer(fileName);
    bool success;
    success = writer.write(ui->textEdit->document());
    if (success)
    {
        QMessageBox::information(this, "Отлично!", "Экспорт прошел успешно");
    }
    else
    {
        QMessageBox::critical(this, "Ошибка", "При сохранении файла произошла ошибка");
    }

}

