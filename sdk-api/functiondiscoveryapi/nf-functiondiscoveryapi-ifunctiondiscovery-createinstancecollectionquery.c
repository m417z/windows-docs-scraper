HRESULT CreateInstanceCollectionQuery(
  [in]      const WCHAR                      *pszCategory,
  [in]      const WCHAR                      *pszSubCategory,
  [in]      BOOL                             fIncludeAllSubCategories,
  [in]      IFunctionDiscoveryNotification   *pIFunctionDiscoveryNotification,
  [in, out] FDQUERYCONTEXT                   *pfdqcQueryContext,
  [out]     IFunctionInstanceCollectionQuery **ppIFunctionInstanceCollectionQuery
);