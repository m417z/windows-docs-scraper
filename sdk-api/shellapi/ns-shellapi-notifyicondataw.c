typedef struct _NOTIFYICONDATAW {
  DWORD cbSize;
  HWND  hWnd;
  UINT  uID;
  UINT  uFlags;
  UINT  uCallbackMessage;
  HICON hIcon;
#if ...
  WCHAR szTip[64];
#else
  WCHAR szTip[128];
#endif
  DWORD dwState;
  DWORD dwStateMask;
  WCHAR szInfo[256];
  union {
    UINT uTimeout;
    UINT uVersion;
  } DUMMYUNIONNAME;
  WCHAR szInfoTitle[64];
  DWORD dwInfoFlags;
  GUID  guidItem;
  HICON hBalloonIcon;
} NOTIFYICONDATAW, *PNOTIFYICONDATAW;