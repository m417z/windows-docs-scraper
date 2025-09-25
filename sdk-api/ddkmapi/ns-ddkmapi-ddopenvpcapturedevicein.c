typedef struct _DDOPENVPCAPTUREDEVICEIN {
  HANDLE              hDirectDraw;
  HANDLE              hVideoPort;
  DWORD               dwStartLine;
  DWORD               dwEndLine;
  DWORD               dwCaptureEveryNFields;
  LPDD_NOTIFYCALLBACK pfnCaptureClose;
  PVOID               pContext;
  DWORD               dwFlags;
} DDOPENVPCAPTUREDEVICEIN, *LPDDOPENVPCAPTUREDEVICEIN;