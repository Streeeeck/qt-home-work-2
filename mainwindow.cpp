#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);


    //QVector<GItem> qv;
    //qv.push_back(GItem(1,"name","utvar'"));

    //gi3 = new GItem(1,"one","utvar'");
    //listItems.push_back(gi3);
    //listItems.push_back(new GItem(2,"two","aperetiv'"));
    //listItems.push_back(new GItem(3,"three","aperetiv'"));
    //listItems.push_back(new GItem(4,"four","aperetiv'"));
    //listItems.push_back(new GItem(5,"SURNAME","aperetiv'"));
    /*for (int var = 0; var < listItems.count(); ++var) {
        pushItem(listItems.at(var));
    }*/
    /*pushItem(gi);
        pushItem(gi2);
        pushItem(gi3);
        pushItem(gi4);
        pushItem(gi5);*/
    //scene->addLine(0,0,100,100);
    //LinePainter* lp = new LinePainter(listItems.at(1),listItems.at(3),2)l
    //scene->addItem(lp);
    //scene->addItem(new LinePainter(listItems.at(1),listItems.at(3),2));
    //paintLine(listItems.at(1),listItems.at(3));
    //paintLine(listItems.at(2),listItems.at(0));
    //paintLine(listItems.at(2),listItems.at(0));
    //paintLine(listItems.at(1),listItems.at(2));



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::pushItem(GItem *item)
{
    int supWidth=60 + item->width;
    int supHeight=120+ item->height;
    int count = scene->items().size();
    int line = count%2;
    int colomn = count/2;
    item->setX(supWidth*colomn);
    item->setY(supHeight*line);
    scene->addItem(item);
}

int MainWindow::getIndex(int id)
{
    for (int i =0; i< listItems.count();i++)
        if (listItems.at(i)->getId() == id)
            return i;
    return -1;
}


void MainWindow::paintLine(GItem* g1, GItem* g2){
    QPen penBlack(Qt::red);
    auto index1 = getIndex(g1->getId());
    auto index2 =getIndex(g2->getId());
    if (index1 < 0 || index2 < 0)
        return;
    QGraphicsItemGroup   *group = new QGraphicsItemGroup();

    if(index1 %2 == 0 && index2 %2== 0){//up
        group->addToGroup(scene->addLine(g1->width/2+g1->x(),g1->y()-5,g1->width/2+g1->x(),g2->y()-upspacer,penBlack));
        group->addToGroup(scene->addLine(g1->width/2+g1->x(),g1->y()-upspacer,g2->width/2+g2->x(),g2->y()-upspacer,penBlack));
        group->addToGroup(scene->addLine(g2->width/2+g2->x(),g2->y()-5,g2->width/2+g2->x(),g2->y()-upspacer,penBlack));
        upspacer += 15;
    }
    else if(getIndex(g1->getId())%2 == 1 && getIndex(g2->getId())%2 == 1){//down
        group->addToGroup(scene->addLine(g1->width/2+g1->x(),g1->height+g1->y(),g1->width/2+g1->x(),g2->height+g2->y()+downspacer,penBlack));
        group->addToGroup(scene->addLine(g1->width/2+g1->x(),g1->height+g1->y()+downspacer,g2->width/2+g2->x(),g2->height+g2->y()+downspacer,penBlack));
        group->addToGroup(scene->addLine(g2->width/2+g2->x(),g2->height+g2->y(),g2->width/2+g2->x(),g2->height+g2->y()+downspacer,penBlack));
        downspacer += 15;
    }
    else{
        if(getIndex(g1->getId())%2 == 0)//up to down
            group->addToGroup(scene->addLine(g1->width/2+g1->x(),g1->height+g1->y(),g2->width/2+g2->x(),g2->y()-5,penBlack));
        else //down to up
            group->addToGroup(scene->addLine(g1->width/2+g1->x(),g1->y()-5,g2->width/2+g2->x(),g2->height+g2->y(),penBlack));

    }
    scene->addItem(group);
}

void MainWindow::on_pushButton_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this,
                                                           tr("Open XML File"),
                                                           QString(),
                                                           tr("XML (*.xml)"));
    xmlreader = new XMLReader(filename);
    listItems = xmlreader->getItems();
    listTracks = xmlreader->getTracks();
    for (int var = 0; var < listItems.count(); ++var)
            pushItem(listItems.at(var));
    for (int i = 0; i < listTracks.count(); ++i){
        int i1 = getIndex(listTracks[i]->getFirst());
        int i2 = getIndex(listTracks[i]->getLast());
        if (i1 >= listTracks.count() || i2 >= listTracks.count() || i1 < 0 || i2 < 0)
            continue;
        paintLine(listItems[i1],listItems[i2]);
    }
    return;
}

