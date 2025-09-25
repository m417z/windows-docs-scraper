BOOL GetThreadWaitChain(
  [in]           HWCT                 WctHandle,
  [in, optional] DWORD_PTR            Context,
  [in]           DWORD                Flags,
  [in]           DWORD                ThreadId,
  [in, out]      LPDWORD              NodeCount,
  [out]          PWAITCHAIN_NODE_INFO NodeInfoArray,
  [out]          LPBOOL               IsCycle
);