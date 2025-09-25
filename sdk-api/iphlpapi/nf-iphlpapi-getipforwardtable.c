IPHLPAPI_DLL_LINKAGE DWORD GetIpForwardTable(
  [out]     PMIB_IPFORWARDTABLE pIpForwardTable,
  [in, out] PULONG              pdwSize,
  [in]      BOOL                bOrder
);