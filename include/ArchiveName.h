// ArchiveName.h

#ifndef __ARCHIVE_NAME_H
#define __ARCHIVE_NAME_H

#include <MyString.h>

#include <FileFind.h>

UString CreateArchiveName(const UString &path, bool fromPrev, bool keepName);
UString CreateArchiveName(const NWindows::NFile::NFind::CFileInfo &fileInfo, bool keepName);

#endif
