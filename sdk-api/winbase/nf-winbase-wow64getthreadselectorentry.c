BOOL Wow64GetThreadSelectorEntry(
  [in]  HANDLE           hThread,
  [in]  DWORD            dwSelector,
  [out] PWOW64_LDT_ENTRY lpSelectorEntry
);