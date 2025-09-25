IPHLPAPI_DLL_LINKAGE DWORD GetIpAddrTable(
  [out]     PMIB_IPADDRTABLE pIpAddrTable,
  [in, out] PULONG           pdwSize,
  [in]      BOOL             bOrder
);