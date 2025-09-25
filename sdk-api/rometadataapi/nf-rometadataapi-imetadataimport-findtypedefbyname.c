HRESULT FindTypeDefByName(
  [in]          LPCWSTR   szTypeDef,
  [in]          mdToken   tkEnclosingClass,
  [out, retval] mdTypeDef *ptkTypeDef
);