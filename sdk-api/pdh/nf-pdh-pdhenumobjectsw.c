PDH_FUNCTION PdhEnumObjectsW(
  [in]      LPCWSTR szDataSource,
  [in]      LPCWSTR szMachineName,
  [out]     PZZWSTR mszObjectList,
  [in, out] LPDWORD pcchBufferSize,
  [in]      DWORD   dwDetailLevel,
  [in]      BOOL    bRefresh
);