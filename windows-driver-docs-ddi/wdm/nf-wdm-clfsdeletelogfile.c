CLFSUSER_API NTSTATUS ClfsDeleteLogFile(
  [in]           PUNICODE_STRING puszLogFileName,
                 PVOID           pvReserved,
  [in]           ULONG           fLogOptionFlag,
  [in, optional] PVOID           pvContext,
  [in]           ULONG           cbContext
);