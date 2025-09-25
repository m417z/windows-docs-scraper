SNMPAPI_STATUS SNMPAPI_CALL SnmpSetPduData(
  [in] HSNMP_PDU       PDU,
  [in] const smiINT    *PDU_type,
  [in] const smiINT32  *request_id,
  [in] const smiINT    *non_repeaters,
  [in] const smiINT    *max_repetitions,
  [in] const HSNMP_VBL *varbindlist
);