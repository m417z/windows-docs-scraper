typedef enum _THREAD_WRITE_FLAGS {
  ThreadWriteThread = 0x0001,
  ThreadWriteStack = 0x0002,
  ThreadWriteContext = 0x0004,
  ThreadWriteBackingStore = 0x0008,
  ThreadWriteInstructionWindow = 0x0010,
  ThreadWriteThreadData = 0x0020,
  ThreadWriteThreadInfo = 0x0040
} THREAD_WRITE_FLAGS;