IPHLPAPI_DLL_LINKAGE ULONG GetPerTcp6ConnectionEStats(
        PMIB_TCP6ROW    Row,
        TCP_ESTATS_TYPE EstatsType,
  [out] PUCHAR          Rw,
        ULONG           RwVersion,
        ULONG           RwSize,
  [out] PUCHAR          Ros,
        ULONG           RosVersion,
        ULONG           RosSize,
  [out] PUCHAR          Rod,
        ULONG           RodVersion,
        ULONG           RodSize
);