// BranchMisc.h

#ifndef __COMPRESS_BRANCH_MISC_H
#define __COMPRESS_BRANCH_MISC_H

#include <MyCom.h>

#include <ICoder.h>

EXTERN_C_BEGIN

typedef SizeT (*Func_Bra)(Byte *data, SizeT size, UInt32 ip, int encoding);

EXTERN_C_END

class CBranchCoder:
  public ICompressFilter,
  public CMyUnknownImp
{
  UInt32 _bufferPos;
  int _encode;
  Func_Bra BraFunc;
public:
  MY_UNKNOWN_IMP;
  INTERFACE_ICompressFilter(;)

  CBranchCoder(Func_Bra bra, int encode):  _bufferPos(0), _encode(encode), BraFunc(bra) {}
};

#endif
