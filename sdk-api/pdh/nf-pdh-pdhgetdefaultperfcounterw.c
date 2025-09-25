PDH_FUNCTION PdhGetDefaultPerfCounterW(
  [in]      LPCWSTR szDataSource,
  [in]      LPCWSTR szMachineName,
  [in]      LPCWSTR szObjectName,
  [out]     LPWSTR  szDefaultCounterName,
  [in, out] LPDWORD pcchBufferSize
);