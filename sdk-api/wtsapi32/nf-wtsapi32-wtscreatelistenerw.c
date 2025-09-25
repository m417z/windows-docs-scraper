BOOL WTSCreateListenerW(
  [in] HANDLE              hServer,
  [in] PVOID               pReserved,
  [in] DWORD               Reserved,
  [in] LPWSTR              pListenerName,
  [in] PWTSLISTENERCONFIGW pBuffer,
  [in] DWORD               flag
);