typedef struct tagBIND_OPTS2 {
  DWORD        cbStruct;
  DWORD        grfFlags;
  DWORD        grfMode;
  DWORD        dwTickCountDeadline;
  DWORD        dwTrackFlags;
  DWORD        dwClassContext;
  LCID         locale;
  COSERVERINFO *pServerInfo;
} BIND_OPTS2, *LPBIND_OPTS2;