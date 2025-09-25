DNS_STATUS DnsQuery_A(
  [in]                PCSTR       pszName,
  [in]                WORD        wType,
  [in]                DWORD       Options,
  [in, out, optional] PVOID       pExtra,
  [out, optional]     PDNS_RECORD *ppQueryResults,
  [out, optional]     PVOID       *pReserved
);