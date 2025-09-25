HANDLE FindFirstFileNameTransactedW(
  [in]           LPCWSTR lpFileName,
  [in]           DWORD   dwFlags,
  [in, out]      LPDWORD StringLength,
  [in, out]      PWSTR   LinkName,
  [in, optional] HANDLE  hTransaction
);