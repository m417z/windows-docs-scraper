BOOL ControlServiceExW(
  [in]      SC_HANDLE hService,
  [in]      DWORD     dwControl,
  [in]      DWORD     dwInfoLevel,
  [in, out] PVOID     pControlParams
);