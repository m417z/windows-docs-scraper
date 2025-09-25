IPHLPAPI_DLL_LINKAGE DWORD SendARP(
  [in]      IPAddr DestIP,
  [in]      IPAddr SrcIP,
  [out]     PVOID  pMacAddr,
  [in, out] PULONG PhyAddrLen
);