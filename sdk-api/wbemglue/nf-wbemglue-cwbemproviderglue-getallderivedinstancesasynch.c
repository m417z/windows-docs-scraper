HRESULT GetAllDerivedInstancesAsynch(
  LPCWSTR                    pszBaseClassName,
  Provider                   *pRequester,
  LPProviderInstanceCallback pCallback,
  LPCWSTR                    pszNamespace,
  MethodContext              *pMethodContext,
  void                       *pUserData
);