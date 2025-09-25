PDH_FUNCTION PdhGetDefaultPerfCounterHA(
  [in]      PDH_HLOG hDataSource,
  [in]      LPCSTR   szMachineName,
  [in]      LPCSTR   szObjectName,
  [out]     LPSTR    szDefaultCounterName,
  [in, out] LPDWORD  pcchBufferSize
);