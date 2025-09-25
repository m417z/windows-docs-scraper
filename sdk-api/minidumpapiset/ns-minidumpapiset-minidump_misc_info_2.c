typedef struct _MINIDUMP_MISC_INFO_2 {
  ULONG32 SizeOfInfo;
  ULONG32 Flags1;
  ULONG32 ProcessId;
  ULONG32 ProcessCreateTime;
  ULONG32 ProcessUserTime;
  ULONG32 ProcessKernelTime;
  ULONG32 ProcessorMaxMhz;
  ULONG32 ProcessorCurrentMhz;
  ULONG32 ProcessorMhzLimit;
  ULONG32 ProcessorMaxIdleState;
  ULONG32 ProcessorCurrentIdleState;
} MINIDUMP_MISC_INFO_2, *PMINIDUMP_MISC_INFO_2;