HANDLE CreateEventW(
  [in, optional] LPSECURITY_ATTRIBUTES lpEventAttributes,
  [in]           BOOL                  bManualReset,
  [in]           BOOL                  bInitialState,
  [in, optional] LPCWSTR               lpName
);