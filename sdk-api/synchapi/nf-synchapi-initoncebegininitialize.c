BOOL InitOnceBeginInitialize(
  [in, out]       LPINIT_ONCE lpInitOnce,
  [in]            DWORD       dwFlags,
  [out]           PBOOL       fPending,
  [out, optional] LPVOID      *lpContext
);