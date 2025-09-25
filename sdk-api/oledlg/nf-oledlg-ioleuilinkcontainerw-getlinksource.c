HRESULT GetLinkSource(
  [in]            DWORD  dwLink,
  [out, optional] LPWSTR *lplpszDisplayName,
  [out]           ULONG  *lplenFileName,
  [out, optional] LPWSTR *lplpszFullLinkType,
  [out, optional] LPWSTR *lplpszShortLinkType,
  [out]           BOOL   *lpfSourceAvailable,
  [out]           BOOL   *lpfIsSelected
);