// Windows/Defs.h

#ifndef __WINDOWS_DEFS_H
#define __WINDOWS_DEFS_H

#include <MyWindows.h>

// #ifdef _WIN32
inline bool LRESULTToBool(LRESULT v) { return (v != FALSE); }
inline bool BOOLToBool(BOOL v) { return (v != FALSE); }
inline BOOL BoolToBOOL(bool v) { return (v ? TRUE: FALSE); }
// #endif

template <class T> inline T MyMin(T a, T b) { return a < b ? a : b; }
template <class T> inline T MyMax(T a, T b) { return a > b ? a : b; }

template <class T> inline int MyCompare(T a, T b)
  { return a == b ? 0 : (a < b ? -1 : 1); }

inline int BoolToInt(bool v) { return (v ? 1 : 0); }
inline bool IntToBool(int v) { return (v != 0); }

inline VARIANT_BOOL BoolToVARIANT_BOOL(bool v) { return (v ? VARIANT_TRUE: VARIANT_FALSE); }
inline bool VARIANT_BOOLToBool(VARIANT_BOOL v) { return (v != VARIANT_FALSE); }

#endif
