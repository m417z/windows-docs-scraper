NOT_BUILD_WINDOWS_DEPRECATE HRESULT PeerGraphCreate(
  [in]  PPEER_GRAPH_PROPERTIES   pGraphProperties,
  [in]  PCWSTR                   pwzDatabaseName,
  [in]  PPEER_SECURITY_INTERFACE pSecurityInterface,
  [out] HGRAPH                   *phGraph
);