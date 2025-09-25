typedef struct RILCALLWAITINGINFO {
  DWORD              cbSize;
  DWORD              dwParams;
  DWORD              dwExecutor;
  RILCALLTYPE        dwCallType;
  RILREMOTEPARTYINFO rrpiCallerInfo;
} RILCALLWAITINGINFO, *LPRILCALLWAITINGINFO;