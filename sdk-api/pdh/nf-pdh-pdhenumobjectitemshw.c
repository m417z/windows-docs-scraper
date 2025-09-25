PDH_FUNCTION PdhEnumObjectItemsHW(
  [in]      PDH_HLOG hDataSource,
  [in]      LPCWSTR  szMachineName,
  [in]      LPCWSTR  szObjectName,
  [out]     PZZWSTR  mszCounterList,
  [in, out] LPDWORD  pcchCounterListLength,
  [out]     PZZWSTR  mszInstanceList,
  [in, out] LPDWORD  pcchInstanceListLength,
  [in]      DWORD    dwDetailLevel,
  [in]      DWORD    dwFlags
);