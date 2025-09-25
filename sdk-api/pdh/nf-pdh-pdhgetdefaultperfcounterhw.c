PDH_FUNCTION PdhGetDefaultPerfCounterHW(
  [in]      PDH_HLOG hDataSource,
  [in]      LPCWSTR  szMachineName,
  [in]      LPCWSTR  szObjectName,
  [out]     LPWSTR   szDefaultCounterName,
  [in, out] LPDWORD  pcchBufferSize
);