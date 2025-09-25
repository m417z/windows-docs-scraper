NTSTATUS KeInitializeCrashDumpHeader(
  [in]            ULONG  DumpType,
  [in]            ULONG  Flags,
  [out]           PVOID  Buffer,
  [in]            ULONG  BufferSize,
  [out, optional] PULONG BufferNeeded
);