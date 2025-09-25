HRESULT GetLinkSource(
  [in]            DWORD dwLink,
  [out, optional] LPSTR *lplpszDisplayName,
  [out]           ULONG *lplenFileName,
  [out, optional] LPSTR *lplpszFullLinkType,
  [out, optional] LPSTR *lplpszShortLinkType,
  [out]           BOOL  *lpfSourceAvailable,
  [out]           BOOL  *lpfIsSelected
);