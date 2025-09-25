HANDLE FindFirstFileExW(
  [in]  LPCWSTR            lpFileName,
  [in]  FINDEX_INFO_LEVELS fInfoLevelId,
  [out] LPVOID             lpFindFileData,
  [in]  FINDEX_SEARCH_OPS  fSearchOp,
        LPVOID             lpSearchFilter,
  [in]  DWORD              dwAdditionalFlags
);