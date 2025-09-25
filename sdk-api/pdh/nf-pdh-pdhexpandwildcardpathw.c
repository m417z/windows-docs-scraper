PDH_FUNCTION PdhExpandWildCardPathW(
  [in]      LPCWSTR szDataSource,
  [in]      LPCWSTR szWildCardPath,
  [out]     PZZWSTR mszExpandedPathList,
  [in, out] LPDWORD pcchPathListLength,
  [in]      DWORD   dwFlags
);