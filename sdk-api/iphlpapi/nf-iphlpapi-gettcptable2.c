IPHLPAPI_DLL_LINKAGE ULONG GetTcpTable2(
  [out]     PMIB_TCPTABLE2 TcpTable,
  [in, out] PULONG         SizePointer,
  [in]      BOOL           Order
);