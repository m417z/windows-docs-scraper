DWORD GetCompressedFileSizeTransactedW(
  [in]            LPCWSTR lpFileName,
  [out, optional] LPDWORD lpFileSizeHigh,
  [in]            HANDLE  hTransaction
);