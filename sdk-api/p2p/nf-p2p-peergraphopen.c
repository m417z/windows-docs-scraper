NOT_BUILD_WINDOWS_DEPRECATE HRESULT PeerGraphOpen(
  [in]  PCWSTR                   pwzGraphId,
  [in]  PCWSTR                   pwzPeerId,
  [in]  PCWSTR                   pwzDatabaseName,
  [in]  PPEER_SECURITY_INTERFACE pSecurityInterface,
  [in]  ULONG                    cRecordTypeSyncPrecedence,
  [in]  const GUID               *pRecordTypeSyncPrecedence,
  [out] HGRAPH                   *phGraph
);