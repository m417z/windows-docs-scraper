BOOL RegisterWaitForSingleObject(
  [out]          PHANDLE             phNewWaitObject,
  [in]           HANDLE              hObject,
  [in]           WAITORTIMERCALLBACK Callback,
  [in, optional] PVOID               Context,
  [in]           ULONG               dwMilliseconds,
  [in]           ULONG               dwFlags
);