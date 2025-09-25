NTDSAPI DWORD DsReplicaModifyA(
  [in] HANDLE          hDS,
  [in] LPCSTR          NameContext,
  [in] const UUID      *pUuidSourceDsa,
  [in] LPCSTR          TransportDn,
  [in] LPCSTR          SourceDsaAddress,
  [in] const PSCHEDULE pSchedule,
  [in] DWORD           ReplicaFlags,
  [in] DWORD           ModifyFields,
  [in] DWORD           Options
);