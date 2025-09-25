BOOL WTSQueryListenerConfigW(
  [in]  HANDLE              hServer,
  [in]  PVOID               pReserved,
  [in]  DWORD               Reserved,
  [in]  LPWSTR              pListenerName,
  [out] PWTSLISTENERCONFIGW pBuffer
);