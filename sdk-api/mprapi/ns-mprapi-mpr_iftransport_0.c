typedef struct _MPR_IFTRANSPORT_0 {
  DWORD  dwTransportId;
  HANDLE hIfTransport;
  WCHAR  wszIfTransportName[MAX_TRANSPORT_NAME_LEN + 1];
} MPR_IFTRANSPORT_0, *PMPR_IFTRANSPORT_0;