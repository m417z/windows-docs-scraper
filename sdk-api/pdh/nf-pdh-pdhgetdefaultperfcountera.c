PDH_FUNCTION PdhGetDefaultPerfCounterA(
  [in]      LPCSTR  szDataSource,
  [in]      LPCSTR  szMachineName,
  [in]      LPCSTR  szObjectName,
  [out]     LPSTR   szDefaultCounterName,
  [in, out] LPDWORD pcchBufferSize
);