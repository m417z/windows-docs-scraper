HWINEVENTHOOK SetWinEventHook(
  [in] DWORD        eventMin,
  [in] DWORD        eventMax,
  [in] HMODULE      hmodWinEventProc,
  [in] WINEVENTPROC pfnWinEventProc,
  [in] DWORD        idProcess,
  [in] DWORD        idThread,
  [in] DWORD        dwFlags
);