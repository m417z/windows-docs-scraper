IPHLPAPI_DLL_LINKAGE DWORD GetExtendedUdpTable(
  [out]     PVOID           pUdpTable,
  [in, out] PDWORD          pdwSize,
  [in]      BOOL            bOrder,
  [in]      ULONG           ulAf,
  [in]      UDP_TABLE_CLASS TableClass,
  [in]      ULONG           Reserved
);