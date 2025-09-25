HRESULT GetInstancesByQueryAsynch(
  LPCWSTR                    query,
  Provider                   *pRequester,
  LPProviderInstanceCallback pCallback,
  LPCWSTR                    pszNamespace,
  MethodContext              *pMethodContext,
  void                       *pUserData
);