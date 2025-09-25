SNMPAPI_STATUS SNMPAPI_CALL SnmpRecvMsg(
  [in]  HSNMP_SESSION   session,
  [out] LPHSNMP_ENTITY  srcEntity,
  [out] LPHSNMP_ENTITY  dstEntity,
  [out] LPHSNMP_CONTEXT context,
  [out] LPHSNMP_PDU     PDU
);