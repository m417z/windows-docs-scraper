struct IDxcOptimizer : IUnknown {
  HRESULT GetAvailablePassCount(
    UINT32 *pCount
  );
  HRESULT GetAvailablePass(
    UINT32            index,
    IDxcOptimizerPass **ppResult
  );
  HRESULT RunOptimizer(
    IDxcBlob         *pBlob,
    LPCWSTR          *ppOptions,
    UINT32           optionCount,
    IDxcBlob         **pOutputModule,
    IDxcBlobEncoding **ppOutputText
  );
};