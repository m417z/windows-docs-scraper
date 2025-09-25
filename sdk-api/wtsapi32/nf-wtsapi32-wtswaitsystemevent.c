BOOL WTSWaitSystemEvent(
  [in]  HANDLE hServer,
  [in]  DWORD  EventMask,
  [out] DWORD  *pEventFlags
);