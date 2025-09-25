HRESULT Advise(
  [in]  IDataObject *pDataObject,
  [in]  FORMATETC   *pFetc,
  [in]  DWORD       advf,
  [in]  IAdviseSink *pAdvise,
  [out] DWORD       *pdwConnection
);