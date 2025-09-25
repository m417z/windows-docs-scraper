typedef struct RILRTTDATA {
  DWORD cbSize;
  DWORD dwExecutor;
  DWORD dwID;
  DWORD dwRTTRefNum;
  DWORD dwTotalMsgSize;
  DWORD dwCurrentMsgSeqNum;
  DWORD dwHighestMsgSeqNum;
  WCHAR wszRTTData[128];
} RILRTTDATA, *LPRILRTTDATA;