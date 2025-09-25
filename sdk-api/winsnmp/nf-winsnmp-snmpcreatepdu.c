HSNMP_PDU SNMPAPI_CALL SnmpCreatePdu(
  [in] HSNMP_SESSION session,
  [in] smiINT        PDU_type,
  [in] smiINT32      request_id,
  [in] smiINT        error_status,
  [in] smiINT        error_index,
  [in] HSNMP_VBL     varbindlist
);