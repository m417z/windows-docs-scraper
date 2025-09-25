PDH_FUNCTION PdhEnumObjectsA(
  [in]      LPCSTR  szDataSource,
  [in]      LPCSTR  szMachineName,
  [out]     PZZSTR  mszObjectList,
  [in, out] LPDWORD pcchBufferSize,
  [in]      DWORD   dwDetailLevel,
  [in]      BOOL    bRefresh
);