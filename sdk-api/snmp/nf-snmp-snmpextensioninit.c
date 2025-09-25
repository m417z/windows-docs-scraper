BOOL SNMP_FUNC_TYPE SnmpExtensionInit(
  [in]  DWORD               dwUptimeReference,
  [out] HANDLE              *phSubagentTrapEvent,
  [out] AsnObjectIdentifier *pFirstSupportedRegion
);