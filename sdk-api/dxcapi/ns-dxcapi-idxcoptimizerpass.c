struct IDxcOptimizerPass : IUnknown {
  HRESULT GetOptionName(
    LPWSTR *ppResult
  );
  HRESULT GetDescription(
    LPWSTR *ppResult
  );
  HRESULT GetOptionArgCount(
    UINT32 *pCount
  );
  HRESULT GetOptionArgName(
    UINT32 argIndex,
    LPWSTR *ppResult
  );
  HRESULT GetOptionArgDescription(
    UINT32 argIndex,
    LPWSTR *ppResult
  );
};