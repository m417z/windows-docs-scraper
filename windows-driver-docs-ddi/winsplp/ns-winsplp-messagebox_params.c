typedef struct {
  DWORD  cbSize;
  LPWSTR pTitle;
  LPWSTR pMessage;
  DWORD  Style;
  DWORD  dwTimeout;
  BOOL   bWait;
} MESSAGEBOX_PARAMS, *PMESSAGEBOX_PARAMS;