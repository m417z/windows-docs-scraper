PDH_FUNCTION PdhEnumObjectsHW(
  [in]      PDH_HLOG hDataSource,
  [in]      LPCWSTR  szMachineName,
  [out]     PZZWSTR  mszObjectList,
  [in, out] LPDWORD  pcchBufferSize,
  [in]      DWORD    dwDetailLevel,
  [in]      BOOL     bRefresh
);