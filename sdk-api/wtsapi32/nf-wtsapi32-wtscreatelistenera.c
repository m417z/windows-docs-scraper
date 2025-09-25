BOOL WTSCreateListenerA(
  [in] HANDLE              hServer,
  [in] PVOID               pReserved,
  [in] DWORD               Reserved,
  [in] LPSTR               pListenerName,
  [in] PWTSLISTENERCONFIGA pBuffer,
  [in] DWORD               flag
);