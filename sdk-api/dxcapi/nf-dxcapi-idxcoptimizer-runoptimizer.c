HRESULT RunOptimizer(
  IDxcBlob         *pBlob,
  LPCWSTR          *ppOptions,
  UINT32           optionCount,
  IDxcBlob         **pOutputModule,
  IDxcBlobEncoding **ppOutputText
);