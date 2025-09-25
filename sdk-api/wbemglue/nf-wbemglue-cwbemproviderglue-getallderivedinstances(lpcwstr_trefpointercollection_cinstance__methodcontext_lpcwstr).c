HRESULT GetAllDerivedInstances(
  LPCWSTR                          pszBaseClassName,
  TRefPointerCollection<CInstance> *pList,
  MethodContext                    *pMethodContext,
  LPCWSTR                          pszNamespace
);