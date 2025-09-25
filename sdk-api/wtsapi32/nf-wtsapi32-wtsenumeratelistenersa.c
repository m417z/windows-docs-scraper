BOOL WTSEnumerateListenersA(
  [in]            HANDLE            hServer,
  [in]            PVOID             pReserved,
  [in]            DWORD             Reserved,
  [out, optional] PWTSLISTENERNAMEA pListeners,
  [in, out]       DWORD             *pCount
);