BOOL CreateHardLinkTransactedW(
  [in] LPCWSTR               lpFileName,
  [in] LPCWSTR               lpExistingFileName,
       LPSECURITY_ATTRIBUTES lpSecurityAttributes,
  [in] HANDLE                hTransaction
);