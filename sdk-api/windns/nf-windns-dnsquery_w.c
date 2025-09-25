DNS_STATUS DnsQuery_W(
  [in]                PCWSTR      pszName,
  [in]                WORD        wType,
  [in]                DWORD       Options,
  [in, out, optional] PVOID       pExtra,
  [out, optional]     PDNS_RECORD *ppQueryResults,
  [out, optional]     PVOID       *pReserved
);