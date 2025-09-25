typedef struct _MINIDUMP_THREAD {
  ULONG32                      ThreadId;
  ULONG32                      SuspendCount;
  ULONG32                      PriorityClass;
  ULONG32                      Priority;
  ULONG64                      Teb;
  MINIDUMP_MEMORY_DESCRIPTOR   Stack;
  MINIDUMP_LOCATION_DESCRIPTOR ThreadContext;
} MINIDUMP_THREAD, *PMINIDUMP_THREAD;