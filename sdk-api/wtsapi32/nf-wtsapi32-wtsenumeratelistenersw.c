BOOL WTSEnumerateListenersW(
  [in]            HANDLE            hServer,
  [in]            PVOID             pReserved,
  [in]            DWORD             Reserved,
  [out, optional] PWTSLISTENERNAMEW pListeners,
  [in, out]       DWORD             *pCount
);