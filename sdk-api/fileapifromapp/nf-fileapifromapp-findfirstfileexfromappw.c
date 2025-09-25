WINSTORAGEAPI HANDLE FindFirstFileExFromAppW(
  LPCWSTR            lpFileName,
  FINDEX_INFO_LEVELS fInfoLevelId,
  LPVOID             lpFindFileData,
  FINDEX_SEARCH_OPS  fSearchOp,
  LPVOID             lpSearchFilter,
  DWORD              dwAdditionalFlags
) noexcept;