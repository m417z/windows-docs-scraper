BOOL StartServiceW(
  [in]           SC_HANDLE hService,
  [in]           DWORD     dwNumServiceArgs,
  [in, optional] LPCWSTR   *lpServiceArgVectors
);