PFNPEER_SECURE_RECORD PfnpeerSecureRecord;

HRESULT PfnpeerSecureRecord(
  [in]  HGRAPH hGraph,
  [in]  PVOID pvContext,
  [in]  PPEER_RECORD pRecord,
  [in]  PEER_RECORD_CHANGE_TYPE changeType,
  [out] PPEER_DATA *ppSecurityData
)
{...}