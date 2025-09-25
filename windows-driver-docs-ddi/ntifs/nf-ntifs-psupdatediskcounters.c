VOID PsUpdateDiskCounters(
  PEPROCESS Process,
  ULONG64   BytesRead,
  ULONG64   BytesWritten,
  ULONG     ReadOperationCount,
  ULONG     WriteOperationCount,
  ULONG     FlushOperationCount
);