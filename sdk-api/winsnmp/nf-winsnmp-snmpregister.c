SNMPAPI_STATUS SNMPAPI_CALL SnmpRegister(
  [in] HSNMP_SESSION session,
  [in] HSNMP_ENTITY  srcEntity,
  [in] HSNMP_ENTITY  dstEntity,
  [in] HSNMP_CONTEXT context,
  [in] smiLPCOID     notification,
  [in] smiUINT32     state
);