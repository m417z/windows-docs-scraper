SNMPAPI_STATUS SNMPAPI_CALL SnmpGetPduData(
  [in]  HSNMP_PDU   PDU,
  [out] smiLPINT    PDU_type,
  [out] smiLPINT32  request_id,
  [out] smiLPINT    error_status,
  [out] smiLPINT    error_index,
  [out] LPHSNMP_VBL varbindlist
);