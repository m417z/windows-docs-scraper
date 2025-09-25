NTSYSAPI NTSTATUS RtlWriteNonVolatileMemory(
  PVOID      NvToken,
  VOID       *NvDestination,
  const VOID *Source,
  SIZE_T     Size,
  ULONG      Flags
);