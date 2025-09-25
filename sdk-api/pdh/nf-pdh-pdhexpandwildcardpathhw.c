PDH_FUNCTION PdhExpandWildCardPathHW(
  [in]      PDH_HLOG hDataSource,
  [in]      LPCWSTR  szWildCardPath,
  [out]     PZZWSTR  mszExpandedPathList,
  [in, out] LPDWORD  pcchPathListLength,
  [in]      DWORD    dwFlags
);