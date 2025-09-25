NTDSAPI DWORD DsReplicaAddW(
  [in] HANDLE          hDS,
  [in] LPCWSTR         NameContext,
  [in] LPCWSTR         SourceDsaDn,
  [in] LPCWSTR         TransportDn,
  [in] LPCWSTR         SourceDsaAddress,
  [in] const PSCHEDULE pSchedule,
  [in] DWORD           Options
);