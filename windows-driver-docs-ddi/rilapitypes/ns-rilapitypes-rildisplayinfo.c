typedef struct RILDISPLAYINFO {
  DWORD              cbSize;
  DWORD              dwParams;
  DWORD              dwExecutor;
  RILDISPLAYINFOTYPE dwType;
  RILDISPLAYINFOTAG  dwTag;
  DWORD              dwMessageSize;
  BYTE               pbMessage[1];
} RILDISPLAYINFO, *LPRILDISPLAYINFO;