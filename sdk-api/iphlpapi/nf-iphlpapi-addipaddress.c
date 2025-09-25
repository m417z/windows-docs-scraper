IPHLPAPI_DLL_LINKAGE DWORD AddIPAddress(
  [in]  IPAddr Address,
  [in]  IPMask IpMask,
  [in]  DWORD  IfIndex,
  [out] PULONG NTEContext,
  [out] PULONG NTEInstance
);