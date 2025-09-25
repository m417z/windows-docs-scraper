typedef struct _DSDISPLAYSPECOPTIONS {
  DWORD dwSize;
  DWORD dwFlags;
  DWORD offsetAttribPrefix;
  DWORD offsetUserName;
  DWORD offsetPassword;
  DWORD offsetServer;
  DWORD offsetServerConfigPath;
} DSDISPLAYSPECOPTIONS, *PDSDISPLAYSPECOPTIONS, *LPDSDISPLAYSPECOPTIONS;