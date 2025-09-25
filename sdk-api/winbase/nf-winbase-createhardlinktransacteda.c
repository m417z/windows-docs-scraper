BOOL CreateHardLinkTransactedA(
  [in] LPCSTR                lpFileName,
  [in] LPCSTR                lpExistingFileName,
       LPSECURITY_ATTRIBUTES lpSecurityAttributes,
  [in] HANDLE                hTransaction
);