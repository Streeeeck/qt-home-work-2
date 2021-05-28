#include "xmlreader.h"
#include <QDebug>
XMLReader::XMLReader(QString path)
{
    QFile file(path);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::warning(nullptr,"Ошибка файла",
                             "Не удалось открыть файл",
                             QMessageBox::Ok);
        return;
    }
    QXmlStreamReader xml(&file);
    xml.setDevice(&file);
    int id,f,l;
    QString name, type;
    while(!xml.atEnd())
    {
        auto s =xml.name();
        if (xml.isStartElement())
        {
            if (s == "id"){
                id = xml.readElementText().toInt();
            }
            else if(s == "name"){
                name = xml.readElementText();
            }
            else if(s == "type"){
                type = xml.readElementText();
            }
            else if(s == "first"){
                f = xml.readElementText().toInt();
            }
            else if(s == "last"){
                l = xml.readElementText().toInt();
            }

        }
        else{
            if (s == "item"){
                GItem* gi = new GItem(id,name,type);
                listGitems.append(gi);
                id = 0;
                name = type = "";
            }
            else if (s == "track"){
                auto tr = new Track(f,l);
                tracks.append(tr);
                l = f = 0;

            }

        }
        xml.readNext();
    }


}

QVector<GItem*> XMLReader::getItems()
{
    return listGitems;
}

QVector<Track*> XMLReader::getTracks()
{
    return tracks;
}
