// LzOutWindow.h

#ifndef __LZ_OUT_WINDOW_H
#define __LZ_OUT_WINDOW_H

#include <OutBuffer.h>

#ifndef _NO_EXCEPTIONS
typedef COutBufferException CLzOutWindowException;
#endif

class CLzOutWindow: public COutBuffer
{
public:
  void Init(bool solid = false) throw();
  
  // distance >= 0, len > 0,
  bool CopyBlock(UInt32 distance, UInt32 len)
  {
    UInt32 pos = _pos - distance - 1;
    if (distance >= _pos)
    {
      if (!_overDict || distance >= _bufSize)
        return false;
      pos += _bufSize;
    }
    if (_limitPos - _pos > len && _bufSize - pos > len)
    {
      const Byte *src = _buf + pos;
      Byte *dest = _buf + _pos;
      _pos += len;
      do
        *dest++ = *src++;
      while (--len != 0);
    }
    else do
    {
      UInt32 pos2;
      if (pos == _bufSize)
        pos = 0;
      pos2 = _pos;
      _buf[pos2++] = _buf[pos++];
      _pos = pos2;
      if (pos2 == _limitPos)
        FlushWithCheck();
    }
    while (--len != 0);
    return true;
  }
  
  void PutByte(Byte b)
  {
    UInt32 pos = _pos;
    _buf[pos++] = b;
    _pos = pos;
    if (pos == _limitPos)
      FlushWithCheck();
  }
  
  Byte GetByte(UInt32 distance) const
  {
    UInt32 pos = _pos - distance - 1;
    if (distance >= _pos)
      pos += _bufSize;
    return _buf[pos];
  }
};

#endif
