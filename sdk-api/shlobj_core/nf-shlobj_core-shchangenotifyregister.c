ULONG SHChangeNotifyRegister(
  [in] HWND                      hwnd,
       int                       fSources,
       LONG                      fEvents,
       UINT                      wMsg,
       int                       cEntries,
  [in] const SHChangeNotifyEntry *pshcne
);