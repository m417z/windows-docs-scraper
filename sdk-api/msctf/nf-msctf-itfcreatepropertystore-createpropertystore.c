HRESULT CreatePropertyStore(
  [in]  REFGUID          guidProp,
  [in]  ITfRange         *pRange,
  [in]  ULONG            cb,
  [in]  IStream          *pStream,
  [out] ITfPropertyStore **ppStore
);