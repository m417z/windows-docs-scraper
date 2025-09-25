DNS_STATUS DnsQueryConfig(
  [in]           DNS_CONFIG_TYPE Config,
  [in]           DWORD           Flag,
  [in, optional] PCWSTR          pwsAdapterName,
  [in, optional] PVOID           pReserved,
  [out]          PVOID           pBuffer,
  [in, out]      PDWORD          pBufLen
);