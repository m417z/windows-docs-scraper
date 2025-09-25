BOOL SetProcessWorkingSetSizeEx(
  [in] HANDLE hProcess,
  [in] SIZE_T dwMinimumWorkingSetSize,
  [in] SIZE_T dwMaximumWorkingSetSize,
  [in] DWORD  Flags
);