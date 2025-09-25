HRESULT RecognizeNamedEntities(
  [in]      LPCWSTR               pszInputString,
  [in]      LCID                  lcidUserLocale,
  [in]      ITokenCollection      *pTokenCollection,
  [in, out] INamedEntityCollector *pNamedEntities
);