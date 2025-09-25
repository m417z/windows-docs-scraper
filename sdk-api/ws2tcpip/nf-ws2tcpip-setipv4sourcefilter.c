int setipv4sourcefilter(
  [in] SOCKET              Socket,
  [in] IN_ADDR             Interface,
  [in] IN_ADDR             Group,
  [in] MULTICAST_MODE_TYPE FilterMode,
  [in] ULONG               SourceCount,
  [in] const IN_ADDR       *SourceList
);