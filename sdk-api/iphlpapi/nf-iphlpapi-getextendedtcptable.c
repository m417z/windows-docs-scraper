IPHLPAPI_DLL_LINKAGE DWORD GetExtendedTcpTable(
  [out]     PVOID           pTcpTable,
  [in, out] PDWORD          pdwSize,
  [in]      BOOL            bOrder,
  [in]      ULONG           ulAf,
  [in]      TCP_TABLE_CLASS TableClass,
  [in]      ULONG           Reserved
);