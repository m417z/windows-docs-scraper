typedef struct _DDOPENVIDEOPORTIN {
  HANDLE              hDirectDraw;
  ULONG               dwVideoPortHandle;
  LPDD_NOTIFYCALLBACK pfnVideoPortClose;
  PVOID               pContext;
} DDOPENVIDEOPORTIN, *LPDDOPENVIDEOPORTIN;