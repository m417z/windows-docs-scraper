DNS_STATUS DnsReplaceRecordSetW(
  [in]                PDNS_RECORD pReplaceSet,
  [in]                DWORD       Options,
  [in, optional]      HANDLE      hContext,
  [in, out, optional] PVOID       pExtraInfo,
  [in, out, optional] PVOID       pReserved
);