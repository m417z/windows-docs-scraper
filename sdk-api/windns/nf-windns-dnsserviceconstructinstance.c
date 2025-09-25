PDNS_SERVICE_INSTANCE DnsServiceConstructInstance(
  PCWSTR       pServiceName,
  PCWSTR       pHostName,
  PIP4_ADDRESS pIp4,
  PIP6_ADDRESS pIp6,
  WORD         wPort,
  WORD         wPriority,
  WORD         wWeight,
  DWORD        dwPropertiesCount,
  PCWSTR       *keys,
  PCWSTR       *values
);