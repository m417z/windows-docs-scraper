typedef struct _STISUBSCRIBE {
  DWORD  dwSize;
  DWORD  dwFlags;
  DWORD  dwFilter;
  HWND   hWndNotify;
  HANDLE hEvent;
  UINT   uiNotificationMessage;
} STISUBSCRIBE, *LPSTISUBSCRIBE;