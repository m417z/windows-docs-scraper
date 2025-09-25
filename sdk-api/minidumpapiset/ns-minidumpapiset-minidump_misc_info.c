typedef struct _MINIDUMP_MISC_INFO {
  ULONG32 SizeOfInfo;
  ULONG32 Flags1;
  ULONG32 ProcessId;
  ULONG32 ProcessCreateTime;
  ULONG32 ProcessUserTime;
  ULONG32 ProcessKernelTime;
} MINIDUMP_MISC_INFO, *PMINIDUMP_MISC_INFO;