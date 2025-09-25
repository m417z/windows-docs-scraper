typedef struct _MINIDUMP_MEMORY_INFO {
  ULONG64 BaseAddress;
  ULONG64 AllocationBase;
  ULONG32 AllocationProtect;
  ULONG32 __alignment1;
  ULONG64 RegionSize;
  ULONG32 State;
  ULONG32 Protect;
  ULONG32 Type;
  ULONG32 __alignment2;
} MINIDUMP_MEMORY_INFO, *PMINIDUMP_MEMORY_INFO;