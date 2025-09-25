HRESULT LookupAuthoredNamedEntity(
  [in]  IEntity          *pEntity,
  [in]  LPCWSTR          pszInputString,
  [in]  ITokenCollection *pTokenCollection,
  [in]  ULONG            cTokensBegin,
  [out] ULONG            *pcTokensLength,
  [out] LPWSTR           *ppszValue
);