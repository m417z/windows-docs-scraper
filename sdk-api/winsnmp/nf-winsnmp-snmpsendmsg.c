SNMPAPI_STATUS SNMPAPI_CALL SnmpSendMsg(
  [in] HSNMP_SESSION session,
  [in] HSNMP_ENTITY  srcEntity,
  [in] HSNMP_ENTITY  dstEntity,
  [in] HSNMP_CONTEXT context,
  [in] HSNMP_PDU     PDU
);