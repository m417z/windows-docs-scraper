HRESULT GetObjectInfo(
  [in]            DWORD dwObject,
  [out]           DWORD *lpdwObjSize,
  [out, optional] LPSTR *lplpszLabel,
  [out, optional] LPSTR *lplpszType,
  [out, optional] LPSTR *lplpszShortType,
  [out, optional] LPSTR *lplpszLocation
);