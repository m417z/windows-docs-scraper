HRESULT CreateInstanceQuery(
  [in]      const WCHAR                    *pszFunctionInstanceIdentity,
  [in]      IFunctionDiscoveryNotification *pIFunctionDiscoveryNotification,
  [in, out] FDQUERYCONTEXT                 *pfdqcQueryContext,
  [out]     IFunctionInstanceQuery         **ppIFunctionInstanceQuery
);