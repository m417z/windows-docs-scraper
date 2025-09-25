IPHLPAPI_DLL_LINKAGE ULONG GetTcpTable(
  [out]     PMIB_TCPTABLE TcpTable,
  [in, out] PULONG        SizePointer,
  [in]      BOOL          Order
);