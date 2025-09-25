BOOL CreateDirectoryTransactedW(
  [in, optional] LPCWSTR               lpTemplateDirectory,
  [in]           LPCWSTR               lpNewDirectory,
  [in, optional] LPSECURITY_ATTRIBUTES lpSecurityAttributes,
  [in]           HANDLE                hTransaction
);