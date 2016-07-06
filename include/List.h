// List.h

#ifndef __LIST_H
#define __LIST_H

#include <Wildcard.h>

#include <LoadCodecs.h>

HRESULT ListArchives(CCodecs *codecs,
    const CObjectVector<COpenType> &types,
    const CIntVector &excludedFormats,
    bool stdInMode,
    UStringVector &archivePaths, UStringVector &archivePathsFull,
    bool processAltStreams, bool showAltStreams,
    const NWildcard::CCensorNode &wildcardCensor,
    bool enableHeaders, bool techMode,
    #ifndef _NO_CRYPTO
    bool &passwordEnabled, UString &password,
    #endif
    #ifndef _SFX
    const CObjectVector<CProperty> *props,
    #endif
    UInt64 &errors,
    UInt64 &numWarnings);

#endif
