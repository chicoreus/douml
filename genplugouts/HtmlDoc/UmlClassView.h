#ifndef _UMLCLASSVIEW_H
#define _UMLCLASSVIEW_H


#include "UmlBaseClassView.h"


// This class manages 'class view'
//
// You can modify it as you want (except the constructor)
class UmlClassView : public UmlBaseClassView
{
public:
    UmlClassView(void * id, const QByteArray & n) : UmlBaseClassView(id, n) {};

    //returns a string indicating the king of the element
    virtual QByteArray sKind();

    //entry to produce the html code receiving chapter number
    //path, rank in the mother and level in the browser tree
    virtual void html(QByteArray pfix, unsigned int rank, unsigned int level);

    virtual bool chapterp();

};

#endif
