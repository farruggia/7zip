// Windows/Shell.h

#ifndef __WINDOWS_SHELL_H
#define __WINDOWS_SHELL_H

#include <windows.h>
// #include <shlobj.h>

#include <MyString.h>
#include <Defs.h>


namespace NWindows{
namespace NShell{

bool BrowseForFolder(HWND owner, LPCWSTR title, LPCWSTR initialFolder, UString &resultPath);

}}


#endif
