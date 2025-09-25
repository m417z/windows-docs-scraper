HRESULT FindInterface(
  [in]  const GUID  *pCategory,
  [in]  const GUID  *pType,
  [in]  IBaseFilter *pf,
  [in]  REFIID      riid,
  [out] void        **ppint
);