typedef struct _PORT_DATA_2 {
  WCHAR sztPortName[MAX_PORTNAME_LEN];
  DWORD dwVersion;
  DWORD dwProtocol;
  DWORD cbSize;
  DWORD dwReserved;
  WCHAR sztHostAddress[MAX_NETWORKNAME2_LEN];
  WCHAR sztSNMPCommunity[MAX_SNMP_COMMUNITY_STR_LEN];
  DWORD dwDoubleSpool;
  WCHAR sztQueue[MAX_QUEUENAME_LEN];
  BYTE  Reserved[514];
  DWORD dwPortNumber;
  DWORD dwSNMPEnabled;
  DWORD dwSNMPDevIndex;
  DWORD dwPortMonitorMibIndex;
} PORT_DATA_2, *PPORT_DATA_2;