#ifndef XMLREADER_H
#define XMLREADER_H
#include <QString>
#include <QFile>
#include <QXmlStreamReader>
#include <QMessageBox>
#include <QXmlStreamAttribute>
#include <gitem.h>
#include "track.h"

class XMLReader
{
public:
    XMLReader(QString path);
    QVector<GItem*> listGitems;
    QVector<GItem*> getItems();
    QVector <Track*> tracks;
    QVector <Track*> getTracks();

};

#endif // XMLREADER_H
