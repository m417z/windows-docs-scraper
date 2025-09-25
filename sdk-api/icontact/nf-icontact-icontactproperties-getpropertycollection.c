HRESULT GetPropertyCollection(
  [out] IContactPropertyCollection **ppPropertyCollection,
  [in]  DWORD                      dwFlags,
  [in]  LPCWSTR                    pszMultiValueName,
  [in]  DWORD                      dwLabelCount,
  [in]  LPCWSTR []                 ppszLabels,
  [in]  BOOL                       fAnyLabelMatches
);