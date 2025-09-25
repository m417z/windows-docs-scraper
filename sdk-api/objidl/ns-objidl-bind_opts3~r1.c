typedef struct tagBIND_OPTS3 {
  DWORD        cbStruct;
  DWORD        grfFlags;
  DWORD        grfMode;
  DWORD        dwTickCountDeadline;
  DWORD        dwTrackFlags;
  DWORD        dwClassContext;
  LCID         locale;
  COSERVERINFO *pServerInfo;
  HWND         hwnd;
} BIND_OPTS3, *LPBIND_OPTS3;