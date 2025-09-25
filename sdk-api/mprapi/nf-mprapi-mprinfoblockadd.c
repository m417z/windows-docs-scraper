DWORD MprInfoBlockAdd(
  [in]  LPVOID lpHeader,
  [in]  DWORD  dwInfoType,
  [in]  DWORD  dwItemSize,
  [in]  DWORD  dwItemCount,
  [in]  LPBYTE lpItemData,
  [out] LPVOID *lplpNewHeader
);