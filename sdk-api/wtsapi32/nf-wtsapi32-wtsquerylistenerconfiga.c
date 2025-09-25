BOOL WTSQueryListenerConfigA(
  [in]  HANDLE              hServer,
  [in]  PVOID               pReserved,
  [in]  DWORD               Reserved,
  [in]  LPSTR               pListenerName,
  [out] PWTSLISTENERCONFIGA pBuffer
);