typedef struct _MINIDUMP_THREAD_EX_CALLBACK {
  ULONG   ThreadId;
  HANDLE  ThreadHandle;
  ULONG   Pad;
  CONTEXT Context;
  ULONG   SizeOfContext;
  ULONG64 StackBase;
  ULONG64 StackEnd;
  ULONG64 BackingStoreBase;
  ULONG64 BackingStoreEnd;
} MINIDUMP_THREAD_EX_CALLBACK, *PMINIDUMP_THREAD_EX_CALLBACK;