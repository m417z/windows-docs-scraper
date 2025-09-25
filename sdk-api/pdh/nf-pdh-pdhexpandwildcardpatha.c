PDH_FUNCTION PdhExpandWildCardPathA(
  [in]      LPCSTR  szDataSource,
  [in]      LPCSTR  szWildCardPath,
  [out]     PZZSTR  mszExpandedPathList,
  [in, out] LPDWORD pcchPathListLength,
  [in]      DWORD   dwFlags
);