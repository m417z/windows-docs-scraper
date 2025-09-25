PDH_FUNCTION PdhEnumObjectsHA(
  [in]      PDH_HLOG hDataSource,
  [in]      LPCSTR   szMachineName,
  [out]     PZZSTR   mszObjectList,
  [in, out] LPDWORD  pcchBufferSize,
  [in]      DWORD    dwDetailLevel,
  [in]      BOOL     bRefresh
);