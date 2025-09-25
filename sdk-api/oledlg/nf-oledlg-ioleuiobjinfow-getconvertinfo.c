HRESULT GetConvertInfo(
  [in]  DWORD   dwObject,
  [out] CLSID   *lpClassID,
  [out] WORD    *lpwFormat,
  [out] CLSID   *lpConvertDefaultClassID,
  [out] LPCLSID *lplpClsidExclude,
  [out] UINT    *lpcClsidExclude
);