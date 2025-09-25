typedef struct RILCALLRTT {
  DWORD            cbSize;
  DWORD            dwParams;
  RILCALLRTTACTION dwRTTAction;
  RILCALLRTTMODE   dwRTTModeOld;
  RILCALLRTTMODE   dwRTTModeNew;
  RILCALLRTTCAP    stRTTCap;
} RILCALLRTT, *LPRILCALLRTT;