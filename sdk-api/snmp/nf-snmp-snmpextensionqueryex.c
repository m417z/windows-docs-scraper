BOOL SNMP_FUNC_TYPE SnmpExtensionQueryEx(
  [in]      UINT            nRequestType,
  [in]      UINT            nTransactionId,
  [in, out] SnmpVarBindList *pVarBindList,
  [in, out] AsnOctetString  *pContextInfo,
  [out]     AsnInteger32    *pErrorStatus,
  [out]     AsnInteger32    *pErrorIndex
);