HRESULT CoWaitForMultipleObjects(
  [in]  DWORD        dwFlags,
  [in]  DWORD        dwTimeout,
  [in]  ULONG        cHandles,
  [in]  const HANDLE *pHandles,
  [out] LPDWORD      lpdwindex
);