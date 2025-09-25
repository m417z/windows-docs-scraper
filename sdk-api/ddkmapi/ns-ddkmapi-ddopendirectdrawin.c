typedef struct _DDOPENDIRECTDRAWIN {
  ULONG_PTR           dwDirectDrawHandle;
  LPDD_NOTIFYCALLBACK pfnDirectDrawClose;
  PVOID               pContext;
} DDOPENDIRECTDRAWIN, *LPDDOPENDIRECTDRAWIN;