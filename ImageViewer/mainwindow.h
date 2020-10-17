#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDir>
#include <QFile>
#include <QFileDialog>
#include <QtDebug>
#include <QListWidget>

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
    void on_selectDir_clicked();

    void on_imgList_itemDoubleClicked(QListWidgetItem *item);

    virtual void resizeEvent(QResizeEvent *event);
    void on_next_clicked();

    void on_previous_clicked();

private:
    Ui::MainWindow *ui;
    QString dirName;
    int picIndex;

    void showImage(QString filename);
    double calScale(const QSize &a, const QSize &b);
    void changeImage(bool nextOrPre);

};
#endif // MAINWINDOW_H
