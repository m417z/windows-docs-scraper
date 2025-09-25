DNS_STATUS DnsModifyRecordsInSet_A(
  [in, optional]      PDNS_RECORD pAddRecords,
  [in, optional]      PDNS_RECORD pDeleteRecords,
  [in]                DWORD       Options,
  [in, optional]      HANDLE      hCredentials,
  [in, out, optional] PVOID       pExtraList,
  [in, out, optional] PVOID       pReserved
);