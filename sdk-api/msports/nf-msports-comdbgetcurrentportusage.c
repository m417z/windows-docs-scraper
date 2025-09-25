LONG ComDBGetCurrentPortUsage(
  [in]            HCOMDB  HComDB,
  [out, optional] PBYTE   Buffer,
  [in]            DWORD   BufferSize,
  [in]            ULONG   ReportType,
  [out, optional] LPDWORD MaxPortsReported
);