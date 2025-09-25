DWORD IMAGEAPI SymCompareInlineTrace(
  [in] HANDLE  hProcess,
  [in] DWORD64 Address1,
  [in] DWORD   InlineContext1,
  [in] DWORD64 RetAddress1,
  [in] DWORD64 Address2,
  [in] DWORD64 RetAddress2
);