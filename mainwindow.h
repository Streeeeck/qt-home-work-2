#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QFileDialog>


#include "gitem.h"
#include "xmlreader.h"
#include "track.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QGraphicsScene *scene;
    XMLReader *xmlreader;
    void pushItem(GItem *item);
    int getIndex(int id);
    //GItem *gi3;
    //QList<GItem> items;
    void paintLine(GItem* g1, GItem* g2);

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    int supWidth;
    int supHeight;
    QVector<GItem*> listItems;
    QVector<Track*> listTracks;
    int upspacer = 15;
    int downspacer = 15;
};
#endif // MAINWINDOW_H
