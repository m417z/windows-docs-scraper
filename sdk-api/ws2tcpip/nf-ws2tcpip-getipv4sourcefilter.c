int getipv4sourcefilter(
  [in]      SOCKET              Socket,
  [in]      IN_ADDR             Interface,
  [in]      IN_ADDR             Group,
  [out]     MULTICAST_MODE_TYPE *FilterMode,
  [in, out] ULONG               *SourceCount,
  [out]     IN_ADDR             *SourceList
);