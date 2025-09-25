BOOL SNMP_FUNC_TYPE SnmpExtensionTrap(
  [out] AsnObjectIdentifier *pEnterpriseOid,
  [out] AsnInteger32        *pGenericTrapId,
  [out] AsnInteger32        *pSpecificTrapId,
  [out] AsnTimeticks        *pTimeStamp,
  [out] SnmpVarBindList     *pVarBindList
);