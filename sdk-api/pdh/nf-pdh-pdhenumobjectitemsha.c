PDH_FUNCTION PdhEnumObjectItemsHA(
  [in]      PDH_HLOG hDataSource,
  [in]      LPCSTR   szMachineName,
  [in]      LPCSTR   szObjectName,
  [out]     PZZSTR   mszCounterList,
  [in, out] LPDWORD  pcchCounterListLength,
  [out]     PZZSTR   mszInstanceList,
  [in, out] LPDWORD  pcchInstanceListLength,
  [in]      DWORD    dwDetailLevel,
  [in]      DWORD    dwFlags
);