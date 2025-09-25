typedef struct _MINIDUMP_THREAD_INFO {
  ULONG32 ThreadId;
  ULONG32 DumpFlags;
  ULONG32 DumpError;
  ULONG32 ExitStatus;
  ULONG64 CreateTime;
  ULONG64 ExitTime;
  ULONG64 KernelTime;
  ULONG64 UserTime;
  ULONG64 StartAddress;
  ULONG64 Affinity;
} MINIDUMP_THREAD_INFO, *PMINIDUMP_THREAD_INFO;