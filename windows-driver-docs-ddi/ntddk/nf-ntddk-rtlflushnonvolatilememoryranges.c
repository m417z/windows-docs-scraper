NTSYSAPI NTSTATUS RtlFlushNonVolatileMemoryRanges(
  PVOID            NvToken,
  PNV_MEMORY_RANGE NvRanges,
  SIZE_T           NumRanges,
  ULONG            Flags
);