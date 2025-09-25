NTDSAPI DWORD DsReplicaModifyW(
  [in] HANDLE          hDS,
  [in] LPCWSTR         NameContext,
  [in] const UUID      *pUuidSourceDsa,
  [in] LPCWSTR         TransportDn,
  [in] LPCWSTR         SourceDsaAddress,
  [in] const PSCHEDULE pSchedule,
  [in] DWORD           ReplicaFlags,
  [in] DWORD           ModifyFields,
  [in] DWORD           Options
);