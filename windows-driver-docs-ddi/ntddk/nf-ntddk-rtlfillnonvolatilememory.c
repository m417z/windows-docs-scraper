NTSYSAPI NTSTATUS RtlFillNonVolatileMemory(
  PVOID       NvToken,
  VOID        *NvDestination,
  SIZE_T      Size,
  const UCHAR Value,
  ULONG       Flags
);