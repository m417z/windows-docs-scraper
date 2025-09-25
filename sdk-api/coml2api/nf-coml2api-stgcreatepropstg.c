HRESULT StgCreatePropStg(
  [in]  IUnknown         *pUnk,
  [in]  REFFMTID         fmtid,
  [in]  const CLSID      *pclsid,
  [in]  DWORD            grfFlags,
  [in]  DWORD            dwReserved,
  [out] IPropertyStorage **ppPropStg
);