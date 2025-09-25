DWORD WDSBPAPI WdsBpQueryOption(
  [in]  HANDLE hHandle,
  [in]  ULONG  uOption,
  [out] ULONG  uValueLen,
  [out] PVOID  pValue,
  [out] PULONG puBytes
);