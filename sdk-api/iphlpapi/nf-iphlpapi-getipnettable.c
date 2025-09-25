IPHLPAPI_DLL_LINKAGE ULONG GetIpNetTable(
  [out]     PMIB_IPNETTABLE IpNetTable,
  [in, out] PULONG          SizePointer,
  [in]      BOOL            Order
);