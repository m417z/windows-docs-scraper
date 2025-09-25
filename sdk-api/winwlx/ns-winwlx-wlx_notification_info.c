typedef struct _WLX_NOTIFICATION_INFO {
  ULONG           Size;
  ULONG           Flags;
  PWSTR           UserName;
  PWSTR           Domain;
  PWSTR           WindowStation;
  HANDLE          hToken;
  HDESK           hDesktop;
  PFNMSGECALLBACK pStatusCallback;
} WLX_NOTIFICATION_INFO, *PWLX_NOTIFICATION_INFO;