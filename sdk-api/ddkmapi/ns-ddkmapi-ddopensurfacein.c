typedef struct _DDOPENSURFACEIN {
  HANDLE              hDirectDraw;
  ULONG_PTR           dwSurfaceHandle;
  LPDD_NOTIFYCALLBACK pfnSurfaceClose;
  PVOID               pContext;
} DDOPENSURFACEIN, *LPDDOPENSURFACEIN;