typedef struct _POLICYSETTINGSTATUSINFO {
  LPWSTR        szKey;
  LPWSTR        szEventSource;
  LPWSTR        szEventLogName;
  DWORD         dwEventID;
  DWORD         dwErrorCode;
  SETTINGSTATUS status;
  SYSTEMTIME    timeLogged;
} POLICYSETTINGSTATUSINFO, *LPPOLICYSETTINGSTATUSINFO;