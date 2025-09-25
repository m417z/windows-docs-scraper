BOOL GetFileAttributesTransactedW(
  [in]  LPCWSTR                lpFileName,
  [in]  GET_FILEEX_INFO_LEVELS fInfoLevelId,
  [out] LPVOID                 lpFileInformation,
  [in]  HANDLE                 hTransaction
);