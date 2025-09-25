HRESULT AddSourceFilterForMoniker(
  [in]  IMoniker    *pMoniker,
  [in]  IBindCtx    *pCtx,
  [in]  LPCWSTR     lpcwstrFilterName,
  [out] IBaseFilter **ppFilter
);