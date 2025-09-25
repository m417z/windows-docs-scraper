IPHLPAPI_DLL_LINKAGE DWORD GetIfTable(
  [out]     PMIB_IFTABLE pIfTable,
  [in, out] PULONG       pdwSize,
  [in]      BOOL         bOrder
);