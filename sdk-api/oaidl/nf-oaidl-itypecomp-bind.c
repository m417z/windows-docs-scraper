HRESULT Bind(
  [in]  LPOLESTR  szName,
  [in]  ULONG     lHashVal,
  [in]  WORD      wFlags,
  [out] ITypeInfo **ppTInfo,
  [out] DESCKIND  *pDescKind,
  [out] BINDPTR   *pBindPtr
);