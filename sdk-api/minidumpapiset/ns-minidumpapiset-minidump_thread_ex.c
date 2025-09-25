typedef struct _MINIDUMP_THREAD_EX {
  ULONG32                      ThreadId;
  ULONG32                      SuspendCount;
  ULONG32                      PriorityClass;
  ULONG32                      Priority;
  ULONG64                      Teb;
  MINIDUMP_MEMORY_DESCRIPTOR   Stack;
  MINIDUMP_LOCATION_DESCRIPTOR ThreadContext;
  MINIDUMP_MEMORY_DESCRIPTOR   BackingStore;
} MINIDUMP_THREAD_EX, *PMINIDUMP_THREAD_EX;