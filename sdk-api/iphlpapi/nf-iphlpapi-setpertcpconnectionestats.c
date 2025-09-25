IPHLPAPI_DLL_LINKAGE ULONG SetPerTcpConnectionEStats(
  PMIB_TCPROW     Row,
  TCP_ESTATS_TYPE EstatsType,
  PUCHAR          Rw,
  ULONG           RwVersion,
  ULONG           RwSize,
  ULONG           Offset
);