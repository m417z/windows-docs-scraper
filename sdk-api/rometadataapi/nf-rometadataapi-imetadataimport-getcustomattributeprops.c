HRESULT GetCustomAttributeProps(
  [in]  mdCustomAttribute cv,
  [out] mdToken           *ptkObj,
  [out] mdToken           *ptkType,
  [out] const BYTE        **ppBlob,
  [out] ULONG             *pcbBlob
);