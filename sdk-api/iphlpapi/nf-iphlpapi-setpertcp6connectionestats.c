IPHLPAPI_DLL_LINKAGE ULONG SetPerTcp6ConnectionEStats(
  PMIB_TCP6ROW    Row,
  TCP_ESTATS_TYPE EstatsType,
  PUCHAR          Rw,
  ULONG           RwVersion,
  ULONG           RwSize,
  ULONG           Offset
);