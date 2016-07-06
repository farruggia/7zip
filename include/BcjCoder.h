// BcjCoder.h

#ifndef __COMPRESS_BCJ_CODER_H
#define __COMPRESS_BCJ_CODER_H

#include <Bra.h>

#include <MyCom.h>

#include <ICoder.h>

class CBcjCoder:
  public ICompressFilter,
  public CMyUnknownImp
{
  UInt32 _bufferPos;
  UInt32 _prevMask;
  int _encode;
public:
  MY_UNKNOWN_IMP;
  INTERFACE_ICompressFilter(;)

  CBcjCoder(int encode): _bufferPos(0), _encode(encode) { x86_Convert_Init(_prevMask); }
};

#endif
