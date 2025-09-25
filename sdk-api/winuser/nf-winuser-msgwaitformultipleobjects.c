DWORD MsgWaitForMultipleObjects(
  [in] DWORD        nCount,
  [in] const HANDLE *pHandles,
  [in] BOOL         fWaitAll,
  [in] DWORD        dwMilliseconds,
  [in] DWORD        dwWakeMask
);