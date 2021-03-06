#ifndef _UMLARTIFACT_H
#define _UMLARTIFACT_H


#include "UmlBaseArtifact.h"
#include <QByteArray>

class FileOut;

// This class manages 'artifacts'
//
// You can modify it as you want (except the constructor)
class UmlArtifact : public UmlBaseArtifact
{
public:
    UmlArtifact(void * id, const QByteArray & n) : UmlBaseArtifact(id, n) {};

    virtual bool write_if_needed(FileOut & out);

};

#endif
