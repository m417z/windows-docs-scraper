typedef struct RILMSGSERVICEINFO {
  DWORD cbSize;
  DWORD dwParams;
  DWORD dwMsgSupport;
  DWORD dwStoreUsed;
  DWORD dwStoreTotal;
} RILMSGSERVICEINFO, *LPRILMSGSERVICEINFO;