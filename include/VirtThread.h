// VirtThread.h

#ifndef __VIRT_THREAD_H
#define __VIRT_THREAD_H

#include <Synchronization.h>
#include <Thread.h>

struct CVirtThread
{
  NWindows::NSynchronization::CAutoResetEvent StartEvent;
  NWindows::NSynchronization::CAutoResetEvent FinishedEvent;
  NWindows::CThread Thread;
  bool Exit;

  ~CVirtThread() { WaitThreadFinish(); }
  void WaitThreadFinish(); // call it in destructor of child class !
  WRes Create();
  void Start();
  virtual void Execute() = 0;
  void WaitExecuteFinish() { FinishedEvent.Lock(); }
};

#endif
