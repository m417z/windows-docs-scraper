NTDSAPI DWORD DsReplicaAddA(
  [in] HANDLE          hDS,
  [in] LPCSTR          NameContext,
  [in] LPCSTR          SourceDsaDn,
  [in] LPCSTR          TransportDn,
  [in] LPCSTR          SourceDsaAddress,
  [in] const PSCHEDULE pSchedule,
  [in] DWORD           Options
);