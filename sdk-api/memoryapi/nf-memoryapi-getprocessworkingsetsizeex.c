BOOL GetProcessWorkingSetSizeEx(
  [in]  HANDLE  hProcess,
  [out] PSIZE_T lpMinimumWorkingSetSize,
  [out] PSIZE_T lpMaximumWorkingSetSize,
  [out] PDWORD  Flags
);