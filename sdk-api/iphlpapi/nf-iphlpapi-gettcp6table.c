IPHLPAPI_DLL_LINKAGE ULONG GetTcp6Table(
  [out]     PMIB_TCP6TABLE TcpTable,
  [in, out] PULONG         SizePointer,
  [in]      BOOL           Order
);