#include "mainwindow.h"
#include "ui_mainwindow.h"

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

void MainWindow::on_selectDir_clicked()
{
    // 打开窗口选择文件见，初始目录为项目根目录
    this->dirName = QFileDialog::getExistingDirectory(this, "选择文件夹", "/");

    // 获取文件夹下的图片(jpg、png)
    QDir dir(this->dirName);
    QStringList nameFilter;
    nameFilter << "*.jpg" << "*.png";
    QStringList entrylist = dir.entryList(nameFilter);

    // 在列表中展示文件夹下的所有图片文件
    ui->imgList->clear();
    QListWidgetItem *item;
    foreach(QString e, entrylist) {
        item = new QListWidgetItem();
        item->setText(e);
        ui->imgList->addItem(item);

        qDebug() << e;
    }

    // 默认选中第一个文件
    ui->imgList->itemAt(0,0)->setSelected(true);

    // 默认展示第一个图片文件
    showImage(entrylist[0]);
    this->picIndex = 0;
}

void MainWindow::on_imgList_itemDoubleClicked(QListWidgetItem *item)
{
    // 选中列表项
    item->setSelected(true);

    // 展示选中的文件
    showImage(item->text());
    this->picIndex = ui->imgList->currentRow();
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    QMainWindow::resizeEvent(event);

    // 获取选中文件的名称，重新展示图片
    QSize widgetSize = ui->widget->size();
    QSize imgSize = ui->img->size();
    double scale = calScale(widgetSize, imgSize);
    ui->img->resize(imgSize * scale);

    // 展示位置
    QRect imgRect = ui->img->geometry();
    QRect widgetRect = ui->widget->geometry();
    qDebug() << imgRect << "  " << widgetRect;
    int x = ((ui->widget->size().width() - ui->img->size().width()) / 2) + widgetRect.x();
    int y = ((ui->widget->size().height() - ui->img->size().height()) / 2) + widgetRect.y();
    imgRect.moveTo(x, y);
    ui->img->setGeometry(imgRect);
    qDebug() << imgRect;
}

void MainWindow::showImage(QString filename)
{
    // 拼接文件绝对路径
    QString absName = this->dirName + "/" + filename;
    qDebug() << "图片名称：" << absName;

    // 获取图片文件
    QImage img(absName);

    // 计算比例尺
    QSize widgetSize = ui->widget->size();
    QSize imgSize = img.size();
    double scale = calScale(widgetSize, imgSize);

    // 缩放图片展示
    ui->img->setPixmap(QPixmap::fromImage(img));
    ui->img->resize(imgSize * scale);
    qDebug() << "scaled Size：" << imgSize * scale;

    // 展示位置
    QRect imgRect = ui->img->geometry();
    QRect widgetRect = ui->widget->geometry();
    qDebug() << imgRect << "  " << widgetRect;
    int x = ((ui->widget->size().width() - ui->img->size().width()) / 2) + widgetRect.x();
    int y = ((ui->widget->size().height() - ui->img->size().height()) / 2) + widgetRect.y();
    imgRect.moveTo(x, y);
    ui->img->setGeometry(imgRect);
    qDebug() << imgRect;
}

double MainWindow::calScale(const QSize &a, const QSize &b)
{
    double scaleW = 1.0 * a.width() / b.width();
    double scaleH = 1.0 * a.height() / b.height();
    double scale = scaleH < scaleW ? scaleH : scaleW;

    qDebug() << "scaleW：" << scaleW;
    qDebug() << "scaleH：" << scaleH;
    qDebug() << "scale：" << scale;

    return scale;
}

void MainWindow::changeImage(bool nextOrPre)
{
    int newPicIndex = 0;
    int total = ui->imgList->count();
    if (total == 0) return;

    if (nextOrPre) {
        newPicIndex = (picIndex + 1) % total;
    } else {
        newPicIndex = (picIndex - 1 + total) % total;
    }

    QListWidgetItem *item = ui->imgList->item(newPicIndex);
    item->setSelected(true);
    showImage(item->text());
    this->picIndex = newPicIndex;
}


void MainWindow::on_next_clicked()
{
    changeImage(true);
}

void MainWindow::on_previous_clicked()
{
    changeImage(false);
}
