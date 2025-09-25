HRESULT CoWaitForMultipleHandles(
  [in]  DWORD    dwFlags,
  [in]  DWORD    dwTimeout,
  [in]  ULONG    cHandles,
  [in]  LPHANDLE pHandles,
  [out] LPDWORD  lpdwindex
);