#ifndef COLLECTION_H
#define COLLECTION_H

#include <QObject>

class Collection: public QObject {
    Q_OBJECT

public:
    Collection();
    Collection(Collection *collection);
    virtual ~Collection();

    int getElementAtIndex(int index);

    void removeElementByIndex(int index);

    void removeAllElementsByValue(int value);

    void addElementByIndex(int index, int value);

    int sumOfElements();

    int sumOfEvenElements();

    void question1();

    int question2();

    void parseCollectionFile(QString pathToFile);

    static void renderCollectionFile(QString text, QString pathToFile);

    QString toText();

    void clear();

    bool validateIndexFromGet(int index);

    bool validateIndexFromAdd(int index);

    bool validateValueContains(int value);

    bool validateEmptyCollection();

private:
    QList<int> *_listOfCollection;
};

#endif // COLLECTION_H
