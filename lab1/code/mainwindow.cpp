#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QGridLayout"
#include "QComboBox"
#include "QTextBrowser"
#include "QPlainTextEdit"
#include "QPalette"
#include <QColorDialog>
#include <QColor>
#include <QGraphicsScene>
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QGridLayout* lay = new QGridLayout;
    lay->addWidget(ui->comboBox,2,1);
    lay->addWidget(ui->comboBox_2,2,2);
    lay->addWidget(ui->comboBox_3,2,3);
    lay->addWidget(ui->graphicsView,1,1);
    lay->addWidget(ui->horizontalSlider,1,2);
    scene = new QGraphicsScene;
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setBackgroundBrush(QBrush(color, Qt::SolidPattern));
    lay->addWidget(ui->one_one,5,1);
    lay->addWidget(ui->one_two,6,1);
    lay->addWidget(ui->one_three,7,1);
    lay->addWidget(ui->one_four,8,1);
    lay->addWidget(ui->two_one,5,2);
    lay->addWidget(ui->two_two,6,2);
    lay->addWidget(ui->two_three,7,2);
    lay->addWidget(ui->two_four,8,2);
    lay->addWidget(ui->three_one,5,3);
    lay->addWidget(ui->three_two,6,3);
    lay->addWidget(ui->three_three,7,3);
    lay->addWidget(ui->three_four,8,3);
    lay->addWidget(ui->label,1,3);
    this->centralWidget()->setLayout(lay);
    for(int i = 0; i < types.size(); i++)
    {
        ui->comboBox->addItem(types[i]);
        ui->comboBox_2->addItem(types[i]);
        ui->comboBox_3->addItem(types[i]);
    }
    ui->label->clear();
    changecolor(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changecolor(int i)
{
    ui->graphicsView->setBackgroundBrush(QBrush(color, Qt::SolidPattern));
    if(i != 1)
    {
        first = convert.conv(color,ui->comboBox->currentText());
        colum_one();
    }
    if(i != 2)
    {
    second = convert.conv(color,ui->comboBox_2->currentText());
    colum_two();
    }
    if(i != 3)
    {
    third = convert.conv(color,ui->comboBox_3->currentText());
    colum_three();
    }
}

void MainWindow::colum_one()
{
    ui->one_one->clear();
    ui->one_two->clear();
    ui->one_three->clear();
    ui->one_four->clear();
    ui->one_one->setText(QString::number(first[0]));
    ui->one_two->setText(QString::number(first[1]));
    ui->one_three->setText(QString::number(first[2]));
    ui->one_four->setText(QString::number(first[3]));
}

void MainWindow::colum_two()
{
    ui->two_one->clear();
    ui->two_two->clear();
    ui->two_three->clear();
    ui->two_four->clear();
    ui->two_one->setText(QString::number(second[0]));
    ui->two_two->setText(QString::number(second[1]));
    ui->two_three->setText(QString::number(second[2]));
    ui->two_four->setText(QString::number(second[3]));
}

void MainWindow::colum_three()
{
    ui->three_one->clear();
    ui->three_two->clear();
    ui->three_three->clear();
    ui->three_four->clear();
    ui->three_one->setText(QString::number(third[0]));
    ui->three_two->setText(QString::number(third[1]));
    ui->three_three->setText(QString::number(third[2]));
    ui->three_four->setText(QString::number(third[3]));
}

void MainWindow::warning()
{
    if(ui->comboBox->currentText() == "LAB" || ui->comboBox->currentText() == "XYZ" || ui->comboBox_3->currentText() == "LAB" || ui->comboBox_3->currentText() == "XYZ" || ui->comboBox_2->currentText() == "LAB" || ui->comboBox_2->currentText() == "XYZ")
        ui->label->setText("Data can be lost");
    else
        ui->label->clear();
}
void MainWindow::slide(int row,int column, QString changed)
{
    switch (column) {
    case 1:
        switch(row)
        {
            case 1:
            ui->one_one->setText(changed);
            break;
        case 2:
        ui->one_two->setText(changed);
        break;
        case 3:
        ui->one_three->setText(changed);
        break;
        case 4:
        ui->one_four->setText(changed);
        break;
        }
        break;
    case 2:
        switch(row)
        {
            case 1:
            ui->two_one->setText(changed);
            break;
        case 2:
        ui->two_two->setText(changed);
        break;
        case 3:
        ui->two_three->setText(changed);
        break;
        case 4:
        ui->two_four->setText(changed);
        break;
        }
        break;
    case 3:
        switch(row)
        {
            case 1:
            ui->three_one->setText(changed);
            break;
        case 2:
        ui->three_two->setText(changed);
        break;
        case 3:
        ui->three_three->setText(changed);
        break;
        case 4:
        ui->three_four->setText(changed);
        break;
        }
        break;
    }
    color = callconv(column);
    changecolor(column);
}

QString MainWindow::checkcolor(int row,int column, QString changed)
{
    QString type;
    switch (column) {
    case 1:
        switch(row)
        {
            case 1:
            ui->one_one->setText(changed);
            break;
        case 2:
        ui->one_two->setText(changed);
        break;
        case 3:
        ui->one_three->setText(changed);
        break;
        case 4:
        ui->one_four->setText(changed);
        break;
        }

        type = ui->comboBox->currentText();
        break;
    case 2:
        switch(row)
        {
            case 1:
            ui->two_one->setText(changed);
            break;
        case 2:
        ui->two_two->setText(changed);
        break;
        case 3:
        ui->two_three->setText(changed);
        break;
        case 4:
        ui->two_four->setText(changed);
        break;
        }
        type = ui->comboBox_2->currentText();
        break;
    case 3:
        switch(row)
        {
            case 1:
            ui->three_one->setText(changed);
            break;
        case 2:
        ui->three_two->setText(changed);
        break;
        case 3:
        ui->three_three->setText(changed);
        break;
        case 4:
        ui->three_four->setText(changed);
        break;
        }
        type = ui->comboBox_3->currentText();
        break;
    }
    if(type != "CMYK" && row == 4)
    {
        ui->horizontalSlider->setMinimum(0);
        ui->horizontalSlider->setMaximum(0);
        QMessageBox::about(this,"","Something wrong");
        return 0;
    }
    else
    {
        if(type == "RGB"){
            ui->horizontalSlider->setMinimum(0);
            ui->horizontalSlider->setMaximum(255);
             ui->horizontalSlider->setSliderPosition(changed.toInt());
                if(changed.toInt() > 255 || changed.toInt() < 0)
                {
                    QMessageBox::about(this,"","Something wrong");
                    return 0;
                }
           }
        else if(type == "CMYK"){
            ui->horizontalSlider->setMinimum(0);
            ui->horizontalSlider->setMaximum(255);
            ui->horizontalSlider->setSliderPosition(changed.toInt());
            if(changed.toInt() > 255 || changed.toInt() < 0)
            {
                QMessageBox::about(this,"","Something wrong");
                return 0;
            }
        }
        else if(type == "HLS"){
            if(row == 1)
            {
                ui->horizontalSlider->setMinimum(0);
                ui->horizontalSlider->setMaximum(359);
                ui->horizontalSlider->setSliderPosition(changed.toInt());
                if(changed.toInt() > 359 || changed.toInt() < 0)
                {
                    QMessageBox::about(this,"","Something wrong");
                    return 0;
                }
            }
            else{
            ui->horizontalSlider->setMinimum(0);
            ui->horizontalSlider->setMaximum(255);
            ui->horizontalSlider->setSliderPosition(changed.toInt());
            if(changed.toInt() > 255 || changed.toInt() < 0)
            {
                QMessageBox::about(this,"","Something wrong");
                return 0;
            }
            }
        }
        else if(type == "LAB"){
            if(row == 1)
            {
                ui->horizontalSlider->setMinimum(0);
                ui->horizontalSlider->setMaximum(100);
                ui->horizontalSlider->setSliderPosition(changed.toInt());
                if(changed.toInt() > 100 || changed.toInt() < 0)
                {

                    QMessageBox::about(this,"","Something wrong");
                    return 0;
                }
            }
            else{
                ui->horizontalSlider->setMinimum(-128);
                ui->horizontalSlider->setMaximum(128);
                ui->horizontalSlider->setSliderPosition(changed.toInt());
            if(changed.toInt() > 128 || changed.toInt() < -128)
            {

                QMessageBox::about(this,"","Something wrong");
                return 0;
            }
            }
        }
        else if(type == "HSV"){
            if(row == 1)
            {
                ui->horizontalSlider->setMaximum(359);
                ui->horizontalSlider->setMinimum(0);
                ui->horizontalSlider->setSliderPosition(changed.toInt());
                if(changed.toInt() > 359 || changed.toInt() < 0)
                {

                    QMessageBox::about(this,"","Something wrong");
                    return 0;
                }
            }
            else{
                ui->horizontalSlider->setMinimum(0);
                ui->horizontalSlider->setMaximum(255);
                ui->horizontalSlider->setSliderPosition(changed.toInt());
            if(changed.toInt() > 255 || changed.toInt() < 0)
            {
                QMessageBox::about(this,"","Something wrong");
                return 0;
            }}
            }
        else if(type == "XYZ"){
                switch (row) {
                case 1:
                    ui->horizontalSlider->setMinimum(0);
                    ui->horizontalSlider->setMaximum(95);
                    ui->horizontalSlider->setSliderPosition(changed.toInt());
                    if(changed.toInt() > 95 || changed.toInt() < 0)
                    {
                        QMessageBox::about(this,"","Something wrong");
                        return 0;
                    }
                    break;
                case 2:
                    ui->horizontalSlider->setMinimum(0);
                    ui->horizontalSlider->setMaximum(100);
                    ui->horizontalSlider->setSliderPosition(changed.toInt());
                    if(changed.toInt() > 100 || changed.toInt() < 0)
                    {
                        QMessageBox::about(this,"","Something wrong");
                        return 0;
                    }
                    break;
                case 3:
                    ui->horizontalSlider->setMinimum(0);
                    ui->horizontalSlider->setMaximum(108);
                    ui->horizontalSlider->setSliderPosition(changed.toInt());
                    if(changed.toInt() > 108 || changed.toInt() < 0)
                    {
                        QMessageBox::about(this,"","Something wrong");
                        return 0;
                    }
                    break;
                }
        }
        }
        return changed;
    }

bool MainWindow::checkletter(QString str)
{
    if(glob == 0)
        glob++;
    else
    for(int i = 0; i < str.size();i++)
    {
        if(!str[i].isDigit())
        {
            QMessageBox::about(this,"","Something wrong");
            return false;
        }
    }
    return true;
}

void MainWindow::on_actionOpen_palette_triggered()
{
    color = QColorDialog::getColor(Qt::black,this,"Pick color");
    changecolor(0);
}

void MainWindow::on_comboBox_2_currentIndexChanged(const QString &arg1)
{
    if((arg1 == ui->comboBox->currentText() || arg1 == ui->comboBox_3->currentText() ) && arg1 != "RGB")
    {
        ui->comboBox_2->setCurrentIndex(0);
    }
    else
    {
    second = convert.conv(color,arg1);
    warning();
    colum_two();
    }
}

void MainWindow::on_comboBox_currentIndexChanged(const QString &arg1)
{
    if((arg1 == ui->comboBox_2->currentText() || arg1 == ui->comboBox_3->currentText() ) && arg1 != "RGB")
    {
        ui->comboBox->setCurrentIndex(0);
    }
    else
    {
    first = convert.conv(color,arg1);
    warning();
    colum_one();
    }
}

void MainWindow::on_comboBox_3_currentIndexChanged(const QString &arg1)
{
    if((arg1 == ui->comboBox->currentText() || arg1 == ui->comboBox_2->currentText() ) && arg1 != "RGB")
    {
        ui->comboBox_3->setCurrentIndex(0);
    }
    else
    {
    third = convert.conv(color,arg1);
    warning();
    colum_three();
    }
}

void MainWindow::on_one_one_textEdited(const QString &arg1)
{
    if(checkletter(arg1))
    {
    cellslide = 11;
    ui->one_one->setText(checkcolor(1,1,arg1));
    color = callconv(1);
    changecolor(1);
    }
}

QColor MainWindow::callconv(int i)
{
    switch (i) {
    case 1:
        return convert.input(ui->comboBox->currentText(),ui->one_one->text(),ui->one_two->text(),ui->one_three->text(),ui->one_four->text());
        break;
    case 2:
        return convert.input(ui->comboBox_2->currentText(),ui->two_one->text(),ui->two_two->text(),ui->two_three->text(),ui->two_four->text());
        break;
    case 3:
        return convert.input(ui->comboBox_3->currentText(),ui->three_one->text(),ui->three_two->text(),ui->three_three->text(),ui->three_four->text());
        break;
    default:
        return color;
    }
}

void MainWindow::on_one_two_textEdited(const QString &arg1)
{
    if(checkletter(arg1))
    {
    cellslide = 12;
    ui->one_two->setText(checkcolor(2,1,arg1));
    color = callconv(1);
    changecolor(1);
    }
}

void MainWindow::on_one_three_textEdited(const QString &arg1)
{
    if(checkletter(arg1))
    {
    cellslide = 13;
    ui->one_three->setText(checkcolor(3,1,arg1));
    color = callconv(1);
    changecolor(1);
    }
}

void MainWindow::on_one_four_textEdited(const QString &arg1)
{
    if(checkletter(arg1))
    {
    cellslide = 14;
    ui->one_four->setText(checkcolor(4,1,arg1));
    color = callconv(1);
    changecolor(1);
    }
}

void MainWindow::on_two_one_textEdited(const QString &arg1)
{
    if(checkletter(arg1))
    {
    cellslide = 21;
    ui->two_one->setText(checkcolor(1,1,arg1));
    color = callconv(2);
    changecolor(2);
    }
}

void MainWindow::on_two_two_textEdited(const QString &arg1)
{
    if(checkletter(arg1))
    {
    cellslide = 22;
    ui->two_two->setText(checkcolor(2,2,arg1));
    color = callconv(2);
    changecolor(2);
    }
}

void MainWindow::on_two_three_textEdited(const QString &arg1)
{
    if(checkletter(arg1))
    {
    cellslide = 23;
    ui->two_three->setText(checkcolor(3,2,arg1));
    color = callconv(2);
    changecolor(2);
    }
}

void MainWindow::on_two_four_textEdited(const QString &arg1)
{
    if(checkletter(arg1))
    {
    cellslide = 24;
    ui->two_four->setText(checkcolor(4,2,arg1));
    color = callconv(2);
    changecolor(2);
    }
}

void MainWindow::on_three_one_textEdited(const QString &arg1)
{
    if(checkletter(arg1))
    {
    cellslide = 31;
    ui->three_one->setText(checkcolor(1,3,arg1));
    color = callconv(3);
    changecolor(3);
    }
}

void MainWindow::on_three_two_textEdited(const QString &arg1)
{
    if(checkletter(arg1))
    {
    cellslide = 32;
    ui->three_two->setText(checkcolor(2,3,arg1));
    color =callconv(3);
    changecolor(3);
    }
}

void MainWindow::on_three_three_textEdited(const QString &arg1)
{
    if(checkletter(arg1))
    {
    cellslide = 33;
    ui->three_three->setText(checkcolor(3,3,arg1));
    color = callconv(3);
    changecolor(3);
    }
}

void MainWindow::on_three_four_textEdited(const QString &arg1)
{
    if(checkletter(arg1))
    {
    cellslide = 34;
    ui->three_four->setText(checkcolor(4,3,arg1));
    color = callconv(3);
    changecolor(3);
    }
}

void MainWindow::on_horizontalSlider_sliderMoved(int position)
{
    QString pos = QString::number(position);
    slide(cellslide%10,cellslide/10,pos);
}
