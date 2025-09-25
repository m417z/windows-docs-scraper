BOOL SNMP_FUNC_TYPE SnmpMgrCtl(
  [in]  LPSNMP_MGR_SESSION session,
  [in]  DWORD              dwCtlCode,
  [in]  LPVOID             lpvInBuffer,
  [in]  DWORD              cbInBuffer,
  [out] LPVOID             lpvOUTBuffer,
  [out] DWORD              cbOUTBuffer,
  [out] LPDWORD            lpcbBytesReturned
);