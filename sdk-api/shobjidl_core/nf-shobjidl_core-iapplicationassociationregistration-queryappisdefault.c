HRESULT QueryAppIsDefault(
  [in]  LPCWSTR          pszQuery,
  [in]  ASSOCIATIONTYPE  atQueryType,
  [in]  ASSOCIATIONLEVEL alQueryLevel,
  [in]  LPCWSTR          pszAppRegistryName,
  [out] BOOL             *pfDefault
);