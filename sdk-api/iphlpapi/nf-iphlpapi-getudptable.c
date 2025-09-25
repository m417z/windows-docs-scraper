IPHLPAPI_DLL_LINKAGE ULONG GetUdpTable(
  [out]     PMIB_UDPTABLE UdpTable,
  [in, out] PULONG        SizePointer,
  [in]      BOOL          Order
);