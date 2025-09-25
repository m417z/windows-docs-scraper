typedef struct _DDREGISTERCALLBACK {
  HANDLE              hDirectDraw;
  ULONG               dwEvents;
  LPDD_NOTIFYCALLBACK pfnCallback;
  ULONG_PTR           dwParam1;
  ULONG_PTR           dwParam2;
  PVOID               pContext;
} DDREGISTERCALLBACK, *LPDDREGISTERCALLBACK;