SNMPAPI SNMP_FUNC_TYPE SnmpMgrRequest(
  [in]      LPSNMP_MGR_SESSION session,
  [in]      BYTE               requestType,
  [in, out] RFC1157VarBindList *variableBindings,
  [out]     AsnInteger         *errorStatus,
  [out]     AsnInteger         *errorIndex
);