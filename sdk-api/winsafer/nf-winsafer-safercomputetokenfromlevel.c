BOOL SaferComputeTokenFromLevel(
  [in]                SAFER_LEVEL_HANDLE LevelHandle,
  [in, optional]      HANDLE             InAccessToken,
  [out]               PHANDLE            OutAccessToken,
  [in]                DWORD              dwFlags,
  [in, out, optional] LPVOID             lpReserved
);