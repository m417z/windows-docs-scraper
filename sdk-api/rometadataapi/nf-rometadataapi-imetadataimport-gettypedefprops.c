HRESULT GetTypeDefProps(
  [in]  mdTypeDef tkTypeDef,
  [out] LPWSTR    szTypeDef,
  [in]  ULONG     cchTypeDef,
  [out] ULONG     *pchTypeDef,
  [out] DWORD     *pdwTypeDefFlags,
  [out] mdToken   *ptkExtends
);