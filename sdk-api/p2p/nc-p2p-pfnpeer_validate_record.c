PFNPEER_VALIDATE_RECORD PfnpeerValidateRecord;

HRESULT PfnpeerValidateRecord(
  [in] HGRAPH hGraph,
  [in] PVOID pvContext,
  [in] PPEER_RECORD pRecord,
  [in] PEER_RECORD_CHANGE_TYPE changeType
)
{...}