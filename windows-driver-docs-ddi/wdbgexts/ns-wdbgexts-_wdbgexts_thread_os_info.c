typedef struct _WDBGEXTS_THREAD_OS_INFO {
  ULONG   ThreadId;
  ULONG   ExitStatus;
  ULONG   PriorityClass;
  ULONG   Priority;
  ULONG64 CreateTime;
  ULONG64 ExitTime;
  ULONG64 KernelTime;
  ULONG64 UserTime;
  ULONG64 StartOffset;
  ULONG64 Affinity;
} WDBGEXTS_THREAD_OS_INFO, *PWDBGEXTS_THREAD_OS_INFO;