HRESULT GetAllInstancesAsynch(
  LPCWSTR                    pszClassName,
  Provider                   *pRequester,
  LPProviderInstanceCallback pCallback,
  LPCWSTR                    pszNamespace,
  MethodContext              *pMethodContext,
  void                       *pUserData
);