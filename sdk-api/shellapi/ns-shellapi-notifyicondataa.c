typedef struct _NOTIFYICONDATAA {
  DWORD cbSize;
  HWND  hWnd;
  UINT  uID;
  UINT  uFlags;
  UINT  uCallbackMessage;
  HICON hIcon;
#if ...
  CHAR  szTip[64];
#else
  CHAR  szTip[128];
#endif
  DWORD dwState;
  DWORD dwStateMask;
  CHAR  szInfo[256];
  union {
    UINT uTimeout;
    UINT uVersion;
  } DUMMYUNIONNAME;
  CHAR  szInfoTitle[64];
  DWORD dwInfoFlags;
  GUID  guidItem;
  HICON hBalloonIcon;
} NOTIFYICONDATAA, *PNOTIFYICONDATAA;