HRESULT GetObjectInfo(
  [in]            DWORD  dwObject,
  [out]           DWORD  *lpdwObjSize,
  [out, optional] LPWSTR *lplpszLabel,
  [out, optional] LPWSTR *lplpszType,
  [out, optional] LPWSTR *lplpszShortType,
  [out, optional] LPWSTR *lplpszLocation
);