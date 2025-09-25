BOOL SNMP_FUNC_TYPE SnmpExtensionQuery(
  [in]      BYTE            bPduType,
  [in, out] SnmpVarBindList *pVarBindList,
  [out]     AsnInteger32    *pErrorStatus,
  [out]     AsnInteger32    *pErrorIndex
);