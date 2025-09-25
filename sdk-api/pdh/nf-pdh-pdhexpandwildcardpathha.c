PDH_FUNCTION PdhExpandWildCardPathHA(
  [in]      PDH_HLOG hDataSource,
  [in]      LPCSTR   szWildCardPath,
  [out]     PZZSTR   mszExpandedPathList,
  [in, out] LPDWORD  pcchPathListLength,
  [in]      DWORD    dwFlags
);