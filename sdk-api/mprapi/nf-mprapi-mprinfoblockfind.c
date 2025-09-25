DWORD MprInfoBlockFind(
  [in]  LPVOID  lpHeader,
  [in]  DWORD   dwInfoType,
  [out] LPDWORD lpdwItemSize,
  [out] LPDWORD lpdwItemCount,
  [out] LPBYTE  *lplpItemData
);