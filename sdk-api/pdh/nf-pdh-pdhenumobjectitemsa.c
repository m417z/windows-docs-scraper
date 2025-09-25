PDH_FUNCTION PdhEnumObjectItemsA(
  [in]      LPCSTR  szDataSource,
  [in]      LPCSTR  szMachineName,
  [in]      LPCSTR  szObjectName,
  [out]     PZZSTR  mszCounterList,
  [in, out] LPDWORD pcchCounterListLength,
  [out]     PZZSTR  mszInstanceList,
  [in, out] LPDWORD pcchInstanceListLength,
  [in]      DWORD   dwDetailLevel,
  [in]      DWORD   dwFlags
);