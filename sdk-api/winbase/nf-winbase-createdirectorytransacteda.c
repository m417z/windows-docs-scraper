BOOL CreateDirectoryTransactedA(
  [in, optional] LPCSTR                lpTemplateDirectory,
  [in]           LPCSTR                lpNewDirectory,
  [in, optional] LPSECURITY_ATTRIBUTES lpSecurityAttributes,
  [in]           HANDLE                hTransaction
);