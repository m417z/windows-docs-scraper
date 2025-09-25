typedef struct _MPR_TRANSPORT_0 {
  DWORD  dwTransportId;
  HANDLE hTransport;
  WCHAR  wszTransportName[MAX_TRANSPORT_NAME_LEN + 1];
} MPR_TRANSPORT_0, *PMPR_TRANSPORT_0;