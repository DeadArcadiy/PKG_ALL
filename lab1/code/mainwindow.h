#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QString>
#include <QGraphicsScene>
#include "converter.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    int glob = 0;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QVector <QString> types = {"RGB","XYZ","LAB","CMYK","HLS","HSV"};
    QGraphicsScene* scene;
    QColor color = Qt::black;
    converter convert;
    void changecolor(int i);
    void colum_one();
    void colum_two();
    void colum_three();
    QVector <int> first;
    QVector <int> second;
    QVector <int> third;
    QColor callconv(int i);
    void slide(int row,int column, QString changed);
    QString checkcolor(int row,int column, QString changed);
    int cellslide = 0;
    void warning();
    bool checkletter(QString str);

private slots:
    void on_actionOpen_palette_triggered();

    void on_comboBox_2_currentIndexChanged(const QString &arg1);

    void on_comboBox_currentIndexChanged(const QString &arg1);

    void on_comboBox_3_currentIndexChanged(const QString &arg1);

    void on_one_one_textEdited(const QString &arg1);

    void on_one_two_textEdited(const QString &arg1);

    void on_one_three_textEdited(const QString &arg1);

    void on_one_four_textEdited(const QString &arg1);

    void on_two_one_textEdited(const QString &arg1);

    void on_two_two_textEdited(const QString &arg1);

    void on_two_three_textEdited(const QString &arg1);

    void on_two_four_textEdited(const QString &arg1);

    void on_three_one_textEdited(const QString &arg1);

    void on_three_two_textEdited(const QString &arg1);

    void on_three_three_textEdited(const QString &arg1);

    void on_three_four_textEdited(const QString &arg1);

    void on_horizontalSlider_sliderMoved(int position);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
