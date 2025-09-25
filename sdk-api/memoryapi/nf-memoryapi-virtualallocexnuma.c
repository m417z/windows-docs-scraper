LPVOID VirtualAllocExNuma(
  [in]           HANDLE hProcess,
  [in, optional] LPVOID lpAddress,
  [in]           SIZE_T dwSize,
  [in]           DWORD  flAllocationType,
  [in]           DWORD  flProtect,
  [in]           DWORD  nndPreferred
);