SNMPAPI_STATUS SNMPAPI_CALL SnmpEncodeMsg(
  [in]  HSNMP_SESSION session,
  [in]  HSNMP_ENTITY  srcEntity,
  [in]  HSNMP_ENTITY  dstEntity,
  [in]  HSNMP_CONTEXT context,
  [in]  HSNMP_PDU     pdu,
  [out] smiLPOCTETS   msgBufDesc
);