typedef struct _DEBUG_THREAD_BASIC_INFORMATION {
  ULONG   Valid;
  ULONG   ExitStatus;
  ULONG   PriorityClass;
  ULONG   Priority;
  ULONG64 CreateTime;
  ULONG64 ExitTime;
  ULONG64 KernelTime;
  ULONG64 UserTime;
  ULONG64 StartOffset;
  ULONG64 Affinity;
} DEBUG_THREAD_BASIC_INFORMATION, *PDEBUG_THREAD_BASIC_INFORMATION;