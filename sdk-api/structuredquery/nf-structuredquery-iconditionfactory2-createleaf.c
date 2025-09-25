HRESULT CreateLeaf(
  [in]           REFPROPERTYKEY             propkey,
  [in]           CONDITION_OPERATION        cop,
  [in]           REFPROPVARIANT             propvar,
  [in, optional] LPCWSTR                    pszSemanticType,
  [in, optional] LPCWSTR                    pszLocaleName,
  [in, optional] IRichChunk                 *pPropertyNameTerm,
  [in, optional] IRichChunk                 *pOperationTerm,
  [in, optional] IRichChunk                 *pValueTerm,
  [in]           CONDITION_CREATION_OPTIONS cco,
  [in]           REFIID                     riid,
  [out]          void                       **ppv
);